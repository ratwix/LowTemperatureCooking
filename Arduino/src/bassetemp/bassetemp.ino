#include <OneWire.h> // Inclusion de la librairie OneWire
#include <Time.h>
#include <Encoder.h> //Rotary encoder
#include <Bounce.h> //Button management
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>

#include "menu.h"

/**
  *  Ecran
  */

#define DELAY_REFRESH_TEMP  100

#define PIN_SCREEN_LED    18
#define PIN_SCREEN_SCLK   19
#define PIN_SCREEN_DIN    20
#define PIN_SCREEN_DC     21
#define PIN_SCREEN_CS     22
#define PIN_SCREEN_RST    23
#define DELAY_REFRESH_SCREEN  100
#define DELAY_MENU_TIMEOUT    20000
#define DELAY_SCROLL          200
#define DELAY_SCROLL_DELAY    4

Adafruit_PCD8544 display = Adafruit_PCD8544(PIN_SCREEN_SCLK, PIN_SCREEN_DIN, PIN_SCREEN_DC, PIN_SCREEN_CS, PIN_SCREEN_RST);

elapsedMillis time_refreshTemperature;
elapsedMillis time_refreshScreen;
elapsedMillis time_menuTimeout;
elapsedMillis time_menuScroll;

int scroll_poss = 0;
int scroll_max = 0;

/**
  * Temperature
  */

#define DS18B20     0x28     // Adresse 1-Wire du DS18B20
#define PIN_DS18B20 16       // Pin used for temp 1-Wire
#define PIN_HEAT    3        // Pin connected to HEAT system (PWM)

OneWire ds(PIN_DS18B20);

float   g_target_temp   = 40.0;
float   g_current_temp  = 12.4;

boolean  g_heat = false; //Heat if true

/**
  * Chronometre
  */
  
time_t g_chrono_time = now();

/**
  * Rotary Encoder
  */
#define PIN_ROTARY1         14
#define PIN_ROTARY2         15
#define ENCODER_STEP        0.1 //Add 0.1° each step
#define ENCODER_MENU_STEP   2   //Increment menu each 4 tick
Encoder g_rotaryEncoder(PIN_ROTARY1, PIN_ROTARY2);

/**
  * Button
  */
  
#define  PIN_BUTTON_RESET_TIMER  12
#define  PIN_BUTTON_MENU         11

Bounce buttonResetTimer = Bounce(PIN_BUTTON_RESET_TIMER, 10);
Bounce buttonMenu = Bounce(PIN_BUTTON_MENU, 10);

/************************************************************************************
  ******
  ******  Refresh temperature
  ******
  ***********************************************************************************/

void setup()   {
  Serial.begin(9600);
  
  pinMode(PIN_HEAT, OUTPUT);
  
  pinMode(PIN_BUTTON_RESET_TIMER, INPUT_PULLUP);
  pinMode(PIN_BUTTON_MENU, INPUT_PULLUP);

  //Switch screen led on
  pinMode(PIN_SCREEN_LED, OUTPUT);
  
  digitalWrite(PIN_SCREEN_LED, HIGH);
  
  //Initialise Screen
  display.begin();
  display.setContrast(51);

  display.display(); // show splashscreen
  delay(2000);
  display.clearDisplay();   // clears the screen and buffer
  display.setTextWrap(false); // Do not wrap text (for scrolling effect)
  
  g_rotaryEncoder.write(0);
  

}

void loop() {
  testControl();
  refreshTemp();
  refreshScreen();
  menuTimeout();
}

/************************************************************************************
  ******
  ******  Control management
  ******
  ***********************************************************************************/

/**
 * Test all controls
 */

void testControl() {
  testButtonReset();
  testButtonMenu();
  readRotaryEncoder();
}

/**
 * Test Reset / Back button
 */

void testButtonReset() {
  if (buttonResetTimer.update()) {
     if (buttonResetTimer.fallingEdge()) {
        time_menuTimeout = 0;
        scroll_poss = DELAY_SCROLL_DELAY;
        if (g_current_menu == 0) {
          g_chrono_time = now();
        } else if (g_current_menu == 1) {
          g_current_menu = 0;
        } else if (g_current_menu == 2) {
          g_current_menu = 1;
        } else if (g_current_menu == 3) {
          g_current_menu = 2;
        } else {
          g_current_menu = 0;
        }
     } 
  }
}

/**
  * Test Menu / Validate button
  */
  
void testButtonMenu() {
  if (buttonMenu.update()) {
     if (buttonMenu.fallingEdge()) {
        time_menuTimeout = 0;
        scroll_poss = DELAY_SCROLL_DELAY;
        if (g_current_menu == 0) {
           init_menu(); //Put current menu item at 0
           g_current_menu = 1; 
        } else if (g_current_menu == 1) { //Goto menu 2
           g_current_menu_2 = 0;
           g_current_menu_3 = 0;
           g_current_menu = 2; 
        } else if (g_current_menu == 2) { //Goto menu 3
           g_current_menu_3 = 0;
           g_current_menu = 3; 
        } else if (g_current_menu == 3) { //Assign temperature
           char tmp = temperature[g_current_menu_1].menu2[g_current_menu_2].menu3[g_current_menu_3].temp;
           if (tmp > 0) {
               g_target_temp = tmp + 1;
           }
           g_current_menu = 0; 
        } else {
           g_current_menu = 0; 
        }
     } 
  }
}

/**
  * Read roatry encoder (left / right
  * If main screen : change target temperature
  * If menu : navigate throw items
  */

void readRotaryEncoder() {
  static int nbTic = 0;
  long newPosition = g_rotaryEncoder.read();
  
  if (newPosition != 0) {
      time_menuTimeout = 0;
      scroll_poss = DELAY_SCROLL_DELAY;
      if (g_current_menu == 0) { //In main screen, directly change temperature
        g_target_temp += newPosition * ENCODER_STEP;
      } else  { //Navigate throw menu
        nbTic += newPosition;
        if (nbTic % ENCODER_MENU_STEP == 0) { //Increment calculator
           if (g_current_menu == 1) {
             int menu_size = get_menu1_size();
             g_current_menu_1 += nbTic > 0 ? 1 : -1; //Increment menu
             if (g_current_menu_1 < 0) { g_current_menu_1 = 0; } //manage menu size
             if (g_current_menu_1 >= menu_size) { g_current_menu_1 = menu_size - 1; }
           } else if (g_current_menu == 2) { 
             int menu_size = get_menu2_size(g_current_menu_1);
             g_current_menu_2 += nbTic > 0 ? 1 : -1; //Increment menu
             if (g_current_menu_2 < 0) { g_current_menu_2 = 0; } //manage menu size
             if (g_current_menu_2 >= menu_size) { g_current_menu_2 = menu_size - 1; }
           } else if (g_current_menu == 3) {
             int menu_size = get_menu3_size(g_current_menu_1, g_current_menu_2);
             g_current_menu_3 += nbTic > 0 ? 1 : -1; //Increment menu
             if (g_current_menu_3 < 0) { g_current_menu_3 = 0; } //manage menu size
             if (g_current_menu_3 >= menu_size) { g_current_menu_3 = menu_size - 1; }
           }
           nbTic = 0; 
        }
      }
      g_rotaryEncoder.write(0);  
  }
}



/************************************************************************************
  ******
  ******  Temperature capture management
  ******
  ***********************************************************************************/

/**
  * Read Temperature.
  * If temperature < target, heat, else stno
  */

void refreshTemp() {
  if (time_refreshTemperature > DELAY_REFRESH_TEMP) {
      time_refreshTemperature -= DELAY_REFRESH_TEMP;
      getTemperature(&g_current_temp);
      if (g_current_temp < g_target_temp) {
        digitalWrite(PIN_HEAT, HIGH);        //TURN HEAT ON
      } else {
        digitalWrite(PIN_HEAT, LOW);         //TURN HEAT OFF
      }
  }
}

/**
  * Get current temperature in Celcius
  */

boolean getTemperature(float *temp){
  byte data[9], addr[8];
  // data : Données lues depuis le scratchpad
  // addr : adresse du module 1-Wire détecté
  

  if (!ds.search(addr)) { // Recherche un module 1-Wire
    ds.reset_search();    // Réinitialise la recherche de module
    return false;         // Retourne une erreur
  }
  
  if (OneWire::crc8(addr, 7) != addr[7]) // Vérifie que l'adresse a été correctement reçue
    return false;                        // Si le message est corrompu on retourne une erreur

  if (addr[0] != DS18B20) // Vérifie qu'il s'agit bien d'un DS18B20
    return false;         // Si ce n'est pas le cas on retourne une erreur

  ds.reset();             // On reset le bus 1-Wire
  ds.select(addr);        // On sélectionne le DS18B20
  
  ds.write(0x44, 1);      // On lance une prise de mesure de température
  //delay(400);             // Et on attend la fin de la mesure
  
  ds.reset();             // On reset le bus 1-Wire
  ds.select(addr);        // On sélectionne le DS18B20
  ds.write(0xBE);         // On envoie une demande de lecture du scratchpad

  for (byte i = 0; i < 9; i++) // On lit le scratchpad
    data[i] = ds.read();       // Et on stock les octets reçus
  
  // Calcul de la température en degré Celsius
  *temp = ((data[1] << 8) | data[0]) * 0.0625; 
  
  // Pas d'erreur
  return true;
}

/************************************************************************************
  ******
  ******  SCREEN MANAGEMENT
  ******
  ***********************************************************************************/

/**
 * Choose what to display on screen
 */

void refreshScreen() {
  menuScroll(); 
  if (time_refreshScreen > DELAY_REFRESH_SCREEN) {
       time_refreshScreen -= DELAY_REFRESH_SCREEN;
       
       if (g_current_menu == 1) { //On est dans le premier menu : choix du type d'ingrédient
         screen_display_menu1();
       } else if (g_current_menu == 2) { //On est dans le premier menu : choix du type d'ingrédient
         screen_display_menu2();
       } else if (g_current_menu == 3) { //On est dans le premier menu : choix du type d'ingrédient
         screen_display_menu3();
       } else {
         screen_display_temp();
       }
   }
}

void menuTimeout() {
   if (time_menuTimeout > DELAY_MENU_TIMEOUT) {
      time_menuTimeout = 0;
      g_current_menu = 0;
  }
}

void menuScroll() {
    if (time_menuScroll > DELAY_SCROLL) {
      time_menuScroll -= DELAY_SCROLL;
      scroll_poss--;
      if (scroll_poss < scroll_max) {
          scroll_poss = DELAY_SCROLL_DELAY;
      }
  }
}

int getMenuScroll() {
  return scroll_poss > 0 ? 0 : scroll_poss;
}

/**
  * Display temperature screen
  */
  
void screen_display_temp() {
  char target_temp[5];
  char current_temp[5];
  time_t currentTime = now() - g_chrono_time; //Le chrono actuel
  char chrono[8];
  
  
  sprintf(chrono, "%02d:%02d:%02d", hour(currentTime), minute(currentTime), second(currentTime));
  sprintf(target_temp, "%.1f", g_target_temp); //Display target temperature
  sprintf(current_temp, "%.1f", g_current_temp); //Display current temperature
  

  display.clearDisplay();
  display.setTextColor(BLACK);
  display.setCursor(0,0);
  //Display elapse time
  display.setTextSize(1);
  display.println(chrono);
  //Display Target temperature
  display.setTextSize(2);
  display.println(target_temp);
  //Display current temperature
  display.setTextSize(3);
  display.println(current_temp);
  display.display();
}

void scroll_text(const char* label) {
  int label_size = 0;
  while (label[label_size] != '\0') {
      label_size++;
  }
  Serial.print(label_size);
  Serial.print(':');
  if (label_size > SCREEN_NB_COLUMN_MENU) {
    scroll_max = -((label_size - SCREEN_NB_COLUMN_MENU) * (SCREEN_CHAR_LENGTH + 2));
    Serial.print(getMenuScroll());
    Serial.print(':');
    Serial.println(scroll_max);
    display.setCursor(display.getCursorX() + getMenuScroll(), display.getCursorY());
  }  
}

/**
  * Display menu 1 : Dish type
  */
void screen_display_menu1() {
    int menu_size = get_menu1_size();
    int start_item;
    int end_item;
    display.clearDisplay();
    display.setCursor(0,0);
    display.setTextSize(1);
    
    // Select start & end elements
    if (menu_size <= SCREEN_NB_LINE_MENU) {
      start_item = 0;
      end_item = menu_size;
    } else {
      start_item = g_current_menu_1 - (SCREEN_NB_LINE_MENU / 2 - 1);
      if (start_item < 0) {
        start_item = 0;
      }
      
      end_item = start_item + SCREEN_NB_LINE_MENU;
      if (end_item > menu_size) {
         start_item -= end_item - menu_size;
         end_item = menu_size;
      }
    }
    
    //Display items
    for (int i = start_item; i < end_item; i++) {
      if (i == g_current_menu_1) { //If select item, highlight it
          display.setTextColor(WHITE, BLACK);
          scroll_text(temperature[i].label);
        } else {
          display.setTextColor(BLACK);
        }
        display.println(temperature[i].label); 
    }
    
    //Display target temp
    
    display.display();
}

/**
  * Display menu 2 : Dish
  */
void screen_display_menu2() {
    int menu_size = get_menu2_size(g_current_menu_1);
    int start_item;
    int end_item;
    
    display.clearDisplay();
    display.setCursor(0,0);
    display.setTextSize(1);
    
    // Select start & end elements
    if (menu_size <= SCREEN_NB_LINE_MENU) {
      start_item = 0;
      end_item = menu_size;
    } else {
      start_item = g_current_menu_2 - (SCREEN_NB_LINE_MENU / 2 - 1);
      if (start_item < 0) {
        start_item = 0;
      }
      
      end_item = start_item + SCREEN_NB_LINE_MENU;
      if (end_item > menu_size) {
         start_item -= end_item - menu_size;
         end_item = menu_size;
      }
    }
    
    for (int i = start_item; i < end_item; i++) {
      if (i == g_current_menu_2) { //If select item, highlight it
          display.setTextColor(WHITE, BLACK);
          scroll_text(temperature[g_current_menu_1].menu2[i].label);
        } else {
          display.setTextColor(BLACK);
        }
        display.println(temperature[g_current_menu_1].menu2[i].label);
    }
    
    display.display();
}

/**
  * Display menu 4 : Cook
  */
void screen_display_menu3() {
int menu_size = get_menu3_size(g_current_menu_1, g_current_menu_2);
    display.clearDisplay();
    display.setCursor(0,0);
    display.setTextSize(1);
    
    int start_item;
    int end_item;
    
    // Select start & end elements
    if (menu_size <= SCREEN_NB_LINE_MENU) {
      start_item = 0;
      end_item = menu_size;
    } else {
      start_item = g_current_menu_3 - (SCREEN_NB_LINE_MENU / 2 - 1);
      if (start_item < 0) {
        start_item = 0;
      }
      
      end_item = menu_size > SCREEN_NB_LINE_MENU ? start_item + SCREEN_NB_LINE_MENU : menu_size;
      if (end_item > menu_size) {
         start_item -= end_item - menu_size;
         end_item = menu_size;
      }
    }
    //Display item
    for (int i = start_item; i < end_item; i++) {
      if (i == g_current_menu_3) { //If select item, highlight it
          display.setTextColor(WHITE, BLACK);
          scroll_text(temperature[g_current_menu_1].menu2[g_current_menu_2].menu3[i].label);
        } else {
          display.setTextColor(BLACK);
        }
        if (temperature[g_current_menu_1].menu2[g_current_menu_2].menu3[i].suggest) {
          display.print(temperature[g_current_menu_1].menu2[g_current_menu_2].menu3[i].label);
          display.println("*"); //Add a * for favorite cooking
        } else {
          display.println(temperature[g_current_menu_1].menu2[g_current_menu_2].menu3[i].label);
        }
    }
    //Display target temp
    char t[4];
    sprintf(t, "%02dC", temperature[g_current_menu_1].menu2[g_current_menu_2].menu3[g_current_menu_3].temp);
    display.setCursor(45,33);
    display.setTextColor(BLACK);
    display.setTextSize(2);
    display.println(t);
    //Display cooking time
    int m = temperature[g_current_menu_1].menu2[g_current_menu_2].menu3[g_current_menu_3].minutes;
    if (m != 0) {
      char t2[8];
      int tm = m % 60;
      int th = m / 60;
      
      if (th > 0) {
        if (tm > 0) {
          sprintf(t2, "%dh%dm", th, tm); 
        } else {
          sprintf(t2, "%dh", th); 
        }
      } else {
        sprintf(t2, "%dmin", tm); 
      }
      display.setCursor(0, 40);
      display.setTextSize(1);
      display.print(t2);
    }
    
    
    display.display();
}
