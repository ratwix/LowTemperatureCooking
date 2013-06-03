#ifndef _TEMPERATURE_H_
#define _TEMPERATURE_H_

#define MAX_MENU1  8
#define MAX_MENU2  23
#define MAX_MENU3  4

#define SCREEN_NB_LINE_MENU    6    //Display max 6 lines
#define SCREEN_NB_COLUMN_MENU  14   //Display max 14 columns
#define SCREEN_CHAR_LENGTH  6   //Display max 14 columns

char g_current_menu = 0;
int g_current_menu_1 = 0;
int g_current_menu_2 = 0;
int g_current_menu_3 = 0;

typedef struct {
  char                label[14];  //dish
  char                temp;       //target temperature
  boolean             suggest;    //Best cooking
  int                 minutes;
} s_menu_3;  
typedef struct  {
  char         label[20];
  s_menu_3     menu3[MAX_MENU3];
} s_menu_2;

typedef struct  { //First menu level
   char        label[17];
   s_menu_2    menu2[MAX_MENU2]; //Max nb menu 2
} s_menu_1;

static const s_menu_1  temperature[] = 
  {
    {"Viande Tendre", {
                  {"Agneau Carre", 
                    {
                      {"Saignant", 54, false},
                      {"A point",  57, true},
                      {"Rose",  59, true},
                      {"Cuit", 62, false}
                    }
                  },
                  {"Agneau Gigot", 
                    {
                      {"Saignant", 54, false},
                      {"A point",  57, false},
                      {"Rose",  60, true},
                      {"Cuit", 65, false}
                    }
                  },
                  {"Boeuf Aloyau", 
                    {
                      {"Saignant", 52, false},
                      {"A point",  54, true},
                      {"Rose",  58, false},
                      {"Cuit", 60, false}
                    }
                  },
                  {"Boeuf Cotes", 
                    {
                      {"Saignant", 54, false},
                      {"A point",  56, true},
                      {"Rose",  58, false},
                      {"Cuit", 60, false}
                    }
                  },
                  {"Boeuf Filet Mignon", 
                    {
                      {"Saignant", 50, true},
                      {"A point",  53, false},
                      {"Rose",  56, false},
                      {"Cuit", 62, false}
                    }
                  },
                  {"Boeuf Flanche", 
                    {
                      {"Saignant", 54, false},
                      {"A point",  56, true},
                      {"Rose",  59, false},
                      {"Cuit", 62, false}
                    }
                  },
                  {"Boeuf Onglet", 
                    {
                      {"Saignant", 51, false},
                      {"A point",  54, false},
                      {"Rose",  58, true},
                      {"Cuit", 60, false}
                    }
                  },
                  {"Chevreuil Longue", 
                    {
                      {"Saignant", 50, true},
                      {"A point",  53, true},
                      {"Rose",  58, false},
                      {"Cuit", 60, false}
                    }
                  },
                  {"Cochon de lait", 
                    {
                      {"A point",  56, true},
                      {"Rose",  58, true},
                      {"Cuit", 60, true}
                    }
                  },
                  {"Lapin Filet", 
                    {
                      {"A point",  56, false},
                      {"Rose",  59, true},
                      {"Cuit", 62, false}
                    }
                  },
                  {"Porc Filet", 
                    {
                      {"A point",  56, false},
                      {"Rose",  59, true},
                      {"Cuit", 61, false}
                    }
                  },
                  {"Porc Longe", 
                    {
                      {"A point",  58, false},
                      {"Rose",  60, true},
                      {"Cuit", 62, false}
                    }
                  },
                  {"Porc Palette", 
                    {
                      {"A point",  58, false},
                      {"Rose",  60, true},
                      {"Cuit", 64, false}
                    }
                  },
                  {"Veau Longe", 
                    {
                      {"Saignant", 52, true},
                      {"A point",  54, true},
                      {"Rose",  56, true},
                      {"Cuit", 60, true}
                    }
                  }
                }
    },
    {"Viande Ferme", {
                        {"Agneau epaule", 
                          {
                            {"Ferme (steak)", 56, true, 48 * 60},
                            {"Tendre souple",  62, false, 48 * 60},
                            {"Tendre defait",  65, true, 24  * 60},
                            {"Tres defait",  85, false, 5 * 60}
                          }
                        },
                        {"Agneau jaret", 
                          {
                            {"Ferme (steak)", 58, false, 48 * 60},
                            {"Tendre souple",  62, true, 48 * 60},
                            {"Tendre defait",  85, false, 5  * 60},
                            {"Tres defait",  88, false, 5 * 60}
                          }
                        },
                        {"Boeuf bavette", 
                          {
                            {"Ferme (steak)", 50, false, 3 * 60},
                            {"Tendre souple",  55, true, 12 * 60},
                            {"Tendre defait",  62, false, 36  * 60},
                            {"Tres defait",  88, false, 7 * 60}
                          }
                        },
                        {"Boeuf cotes avec os", 
                          {
                            {"Ferme (steak)", 56, false, 72 * 60},
                            {"Tendre souple",  58, false, 72 * 60},
                            {"Tendre defait",  60, true, 72  * 60},
                            {"Tres defait",  88, false, 7 * 60}
                          }
                        },
                        {"Boeuf joue", 
                          {
                            {"Ferme (steak)", 58, false, 72 * 60},
                            {"Tendre souple",  62, true, 72 * 60},
                            {"Tendre defait",  68, false, 36  * 60},
                            {"Tres defait",  80, false, 12 * 60}
                          }
                        },
                        {"Boeuf onglet", 
                          {
                            {"Ferme (steak)", 50, true, 2 * 60},
                            {"Tendre souple",  55, false, 12 * 60},
                            {"Tendre defait",  62, false, 36  * 60},
                            {"Tres defait",  88, false, 6 * 60}
                          }
                        },
                        {"Boeuf palette", 
                          {
                            {"Ferme (steak)", 52, false, 24 * 60},
                            {"Tendre souple",  55, true, 12 * 60},
                            {"Tendre defait",  62, false, 48  * 60},
                            {"Tres defait",  88, false, 5 * 60}
                          }
                        },
                        {"Boeuf poitrine", 
                          {
                            {"Ferme (steak)", 58, false, 72 * 60},
                            {"Tendre souple",  60, false, 72 * 60},
                            {"Tendre defait",  63, true, 72  * 12},
                            {"Tres defait",  70, false, 72 * 60}
                          }
                        },
                        {"Boeuf queue", 
                          {
                            {"Tendre souple",  60, true, 100 * 60},
                            {"Tendre defait",  65, false, 48  * 60},
                            {"Tres defait",  70, false, 24 * 60}
                          }
                        },
                        {"Cochon lait cuisse", 
                          {
                            {"Tendre souple",  60, false, 36 * 60},
                            {"Tendre defait",  65, true, 24  * 60},
                            {"Tres defait",  80, false, 8 * 60}
                          }
                        },
                        {"Lapin epaule", 
                          {
                            {"Tendre souple",  60, false, 4 * 60},
                            {"Tendre defait",  66, true, 1  * 60},
                            {"Tres defait",  85, false, 1 * 60}
                          }
                        },
                        {"Porc cotes", 
                          {
                            {"Tendre souple",  60, true, 48 * 60},
                            {"Tendre defait",  65, false, 48  * 60},
                            {"Tres defait",  75, false, 7 * 60}
                          }
                        },
                        {"Porc epaule jambon", 
                          {
                            {"Ferme (steak)", 54, false, 48 * 60},
                            {"Tendre souple",  60, false, 72 * 60},
                            {"Tendre defait",  65, true, 36  * 60},
                            {"Tres defait",  84, false, 4 * 60}
                          }
                        },
                        {"Porc jarret pied", 
                          {
                            {"Tres defait",  85, false, 85 * 60}
                          }
                        },
                        {"Porc joue", 
                          {
                            {"Tendre souple",  65, true, 38 * 60},
                            {"Tendre defait",  68, false, 48  * 60},
                            {"Tres defait",  85, false, 5 * 60}
                          }
                        },
                        {"Porc poitrine", 
                          {
                            {"Ferme (steak)", 60, true, 72 * 60},
                            {"Tendre souple",  65, true, 36 * 60},
                            {"Tendre defait",  70, false, 18  * 60},
                            {"Tres defait",  88, false, 8 * 60}
                          }
                        },
                        {"Veau jarret", 
                          {
                            {"Tendre souple",  60, false, 72 * 60},
                            {"Tendre defait",  66, true, 72  * 60},
                            {"Tres defait",  85, false, 8 * 60}
                          }
                        },
                        {"Veau poitrine", 
                          {
                            {"Ferme (steak)", 54, true},
                            {"Tendre souple",  62, false, 5 * 60},
                            {"Tendre defait",  68, false, 24  * 60},
                            {"Tres defait",  85, false, 6 * 60}
                          }
                        }
                  }
    },
    {"Volailles", {
                        {"Autruche Filet", 
                          {
                            {"Saignant", 50, true},
                            {"A Point",  54, false, 137},
                            {"Rose",  58, false, 30}
                          }
                        },
                        {"Caille Cuisse", 
                          {
                            {"Tendre", 60, true, 720},
                            {"Defaut",  68, false, 180}
                          }
                        },
                        {"Caille Filet", 
                          {
                            {"A point", 50, true, 720},
                            {"Rosé",  52, false, 315},
                            {"Cuit",  54, false, 137}
                          }
                        },
                        {"Canard Cuisse", 
                          {
                            {"Tendre", 62, true, 720},
                            {"Defaut",  68, false, 480}
                          }
                        },
                        {"Canard Filet", 
                          {
                            {"Saignant", 52, false, 315},
                            {"A Point",  54, true, 137},
                            {"Rose",  58, false, 30}
                          }
                        },
                        {"Canard Langue", 
                          {
                            {"Tendre", 88, true, 300}
                          }
                        },
                        {"Coq Filet", 
                          {
                            {"Saignant", 50, true},
                            {"A Point",  52, false, 315},
                            {"Rose",  58, false, 30}
                          }
                        },
                         {"Dinde Aile", 
                          {
                            {"Tendre", 58, true, 720},
                            {"Defaut",  62, false, 1080}
                          }
                        },
                        {"Dinde Cuisse", 
                          {
                            {"Tendre", 62, true, 480},
                            {"Defaut",  65, false, 120}
                          }
                        },
                        {"Dinde Filet", 
                          {
                            {"A point", 54, false, 137},
                            {"Rosé",  56, true, 35},
                            {"Cuit",  58, false, 30}
                          }
                        },
                        {"Faisan Filet", 
                          {
                            {"A point", 54, false, 35},
                            {"Rosé",  56, true, 217},
                            {"Cuit",  58, false, 30}
                          }
                        },
                        {"Oie Filet", 
                          {
                            {"Saignant", 50, false},
                            {"A Point",  52, true, 315},
                            {"Rose",  55, false, 40}
                          }
                        },      
                        {"Pigeon Cuisse", 
                          {
                            {"Tendre", 65, true, 180},
                            {"Defaut",  68, false, 420}
                          }
                        },
                        {"Pigeon Filet", 
                          {
                            {"Saignant", 52, false, 315},
                            {"A Point",  54, true, 137},
                            {"Rose",  58, false, 30}
                          }
                        },
                        {"Pintade Cuisse", 
                          {
                            {"Tendre", 60, true, 240},
                          }
                        },
                        {"Pintade Filet", 
                          {
                            {"A point", 52, false, 315},
                            {"Rosé",  54, true, 137},
                            {"Cuit",  58, false, 30}
                          }
                        },
                        {"Poulet", 
                          {
                            {"Tendre", 64, true, 90},
                            {"Defaut",  45, false, 180}
                          }
                        },
                        {"Poulet Ailes", 
                          {
                            {"Tendre", 62, true, 720},
                            {"Defaut",  72, false, 480}
                          }
                        },
                        {"Poulet Filet", 
                          {
                            {"A point", 58, true, 30},
                            {"Rosé",  61, true, 13},
                            {"Cuit",  65, false, 2}
                          }
                        }                        
                      }
    },
    {"Poisson", {
                  {"Anguille", 
                    {
                      {"Ferme",  54, false},
                      {"Defait", 59, true}
                    }
                  },
                  {"Bar", 
                    {
                      {"Tendre",  45, true},
                      {"Ferme",  48, false},
                      {"Defait", 50, false}
                    }
                  },
                  {"Colin", 
                    {
                      {"Tendre",  44, true},
                      {"Ferme",  50, false},
                      {"Defait", 54, false}
                    }
                  },
                  {"Escolier Noir", 
                    {
                      {"A peine cuit", 38, false},
                      {"Tendre",  41, false},
                      {"Ferme",  46, true},
                      {"Defait", 50, false}
                    }
                  },
                  {"Esturgeon", 
                    {
                      {"A peine cuit", 46, false},
                      {"Tendre",  50, false},
                      {"Ferme",  54, true}
                    }
                  },
                  {"Fletan", 
                    {
                      {"A peine cuit", 40, false},
                      {"Tendre",  42, false},
                      {"Ferme",  45, true},
                      {"Defait", 50, false}
                    }
                  },
                  {"Fletan Joues", 
                    {
                      {"Tendre",  45, false},
                      {"Ferme",  48, true},
                      {"Defait", 52, false}
                    }
                  },
                  {"Hamachi", 
                    {
                      {"A peine cuit", 34, true},
                      {"Tendre",  38, false},
                      {"Ferme",  40, false},
                      {"Defait", 46, false}
                    }
                  },
                  {"Lotte", 
                    {
                      {"A peine cuit", 42, false},
                      {"Tendre",  45, false},
                      {"Ferme",  48, true},
                      {"Defait", 50, false}
                    }
                  },
                  {"Maquereau", 
                    {
                      {"A peine cuit", 40, false},
                      {"Tendre",  42, false},
                      {"Ferme",  46, true},
                      {"Defait", 48, false}
                    }
                  },
                  {"Morue", 
                    {
                      {"A peine cuit", 38, false},
                      {"Tendre",  41, true},
                      {"Ferme",  45, false},
                      {"Defait", 49, false}
                    }
                  },
                  {"Morue Charbon", 
                    {
                      {"A peine cuit", 40, false},
                      {"Tendre",  45, true},
                      {"Ferme",  48, true},
                      {"Defait", 52, true}
                    }
                  },
                  {"Raie", 
                    {
                      {"Tendre",  48, false},
                      {"Ferme",  52, true},
                      {"Defait", 54, false}
                    }
                  },
                  {"Rascasse", 
                    {
                      {"Tendre",  44, false},
                      {"Ferme",  48, false},
                      {"Defait", 52, true}
                    }
                  },
                  {"Rouget", 
                    {
                      {"Tendre",  48, false},
                      {"Ferme",  50, true},
                      {"Defait", 52, false}
                    }
                  },
                  {"Saint-Pierre", 
                    {
                      {"Tendre",  45, false},
                      {"Ferme",  48, true},
                      {"Defait", 50, false}
                    }
                  },
                  {"Saumon", 
                    {
                      {"A peine cuit", 38, true},
                      {"Tendre",  41, false},
                      {"Ferme",  43, true},
                      {"Defait", 46, false}
                    }
                  },
                  {"Sardine", 
                    {
                      {"A peine cuit", 34, true},
                      {"Tendre",  38, true},
                      {"Ferme",  42, false},
                      {"Defait", 46, false}
                    }
                  },
                  
                  
                  
                  {"Sole", 
                    {
                      {"Tendre",  42, true},
                      {"Ferme",  45, false},
                      {"Defait", 50, false}
                    }
                  },
                  {"Thon Longe", 
                    {
                      {"A peine cuit", 38, true},
                      {"Tendre",  42, true},
                      {"Ferme",  45, false},
                      {"Defait", 58, false}
                    }
                  },
                  {"Thon Ventreche", 
                    {
                      {"A peine cuit", 38, false},
                      {"Tendre",  43, true},
                      {"Ferme",  48, false},
                      {"Defait", 50, false}
                    }
                  },
                  {"Truite", 
                    {
                      {"A peine cuit", 37, true},
                      {"Tendre",  40, false},
                      {"Ferme",  46, false},
                      {"Defait", 48, false}
                    }
                  },
                  {"Turbot", 
                    {
                      {"Tendre",  44, false},
                      {"Ferme",  49, true},
                      {"Defait", 52, false}
                    }
                  }
                }
    },
    {"Fruit de mer", {
                       {"Bigorneau", 
                          {
                            {"Ferme",  65, false, 15},
                            {"Tendre Braise", 88, true, 300}
                          }
                        },
                        {"Calamar Seiche", 
                          {
                            {"A peine cuit",  50, false, 10},
                            {"Ferme",  65, true, 5},
                            {"Tendre Braise", 64, false, 240}
                          }
                        },
                        {"Coque Palourdes", 
                          {
                            {"A peine cuit",  48, false, 10},
                            {"Tendre",  56, true, 8},
                            {"Ferme", 65, false, 5}
                          }
                        },
                        {"Couteaux", 
                          {
                            {"A peine cuit",  45, false, 10},
                            {"Tendre",  60, true, 10},
                            {"Ferme", 65, false, 5}
                          }
                        },
                        {"Crevettes", 
                          {
                            {"A peine cuit",  48, true},
                            {"Tendre",  60, true},
                            {"Ferme", 80, false, 4}
                          }
                        },
                        {"Homard Pinces", 
                          {
                            {"A peine cuit",  54, true},
                            {"Tendre",  60, true},
                            {"Ferme", 65, false}
                          }
                        },
                        {"Huitres", 
                          {
                            {"A peine cuit",  45, true, 10},
                            {"Tendre",  48, false, 10},
                            {"Ferme", 52, false, 7}
                          }
                        },
                        {"Langoustine", 
                          {
                            {"A peine cuit",  48, false, 15},
                            {"Tendre",  56, true, 12},
                            {"Ferme", 70, false, 6}
                          }
                        },
                        
                        
                        {"Moules", 
                          {
                            {"A peine cuit",  62, false, 10},
                            {"Tendre",  65, true, 10},
                            {"Ferme", 68, false, 7}
                          }
                        },
                        {"Ormeau", 
                          {
                            {"A peine cuit",  45, false, 15},
                            {"Ferme",  88, false, 480},
                            {"Tendre Braise", 98, true, 720}
                          }
                        },
                        {"Palourde", 
                          {
                            {"A peine cuit",  50, true, 30},
                            {"Ferme",  65, false, 7},
                            {"Tendre Braise", 88, false, 90}
                          }
                        },
                        {"Poulpe", 
                          {
                            {"Ferme",  80, false, 180},
                            {"Tendre Braise", 85, true, 240}
                          }
                        },
                        
                        {"Saint-Jacques", 
                          {
                            {"A peine cuit",  42, false},
                            {"Tendre",  50, true},
                            {"Ferme", 54, false}
                          }
                        }
                     }
    },
    {"Abats et Viceres", {
                       {"Coeur Veau", 
                          {
                            {"Braisee",  80, true, 300}
                          }
                       },
                       {"Crete de coq", 
                          {
                            {"Braisee",  85, true, 120}
                          }
                       },
                       {"Foie gras canard", 
                          {
                            {"Saignant", 50, true},
                            {"Rose",  56, true},
                            {"A Point",  60, false},
                          }
                        },
                       {"Foie veau", 
                          {
                            {"Saignant", 58, false},
                            {"Rose",  62, true},
                            {"A Point",  65, false},
                          }
                        },
                       {"Foie volailles", 
                          {
                            {"Saignant", 52, false},
                            {"Rose",  56, true},
                            {"A Point",  60, false},
                          }
                        },
                        {"Gesier Poulet", 
                          {
                            {"Braisee",  60, true, 720}
                          }
                        },                        
                        {"Langue Boeuf Veau", 
                          {
                            {"Tendre,juteux", 68, true, 720},
                            {"Braisee",  67, false, 2880}
                          }
                        },
                        {"Langue Canard", 
                          {
                            {"Tendre,juteux", 70, false, 480},
                            {"Braisee",  88, true, 300}
                          }
                        },
                        {"Ris d'agneau", 
                          {
                            {"Rose",  55, false, 120},
                            {"A Point",  65, true, 60},
                          }
                        },
                        {"Ris de veau", 
                          {
                            {"Rose",  60, false, 60},
                            {"A Point",  67, true, 60},
                          }
                        },
                        {"Rognons", 
                          {
                            {"Rose",  56, true},
                            {"A Point",  60, false, 60}
                            
                          }
                        }, 
                        {"Rognons coq", 
                          {
                            {"Rose",  70, true, 20}
                          }
                        },
                        {"Tripes", 
                          {
                            {"Braisee",  88, true, 120}
                          }
                        }                     
                  }
    }
  }
;


void init_menu() {
  g_current_menu_1 = 0;
  g_current_menu_2 = 0;
  g_current_menu_3 = 0;
}

int get_menu1_size() {  
  return sizeof(temperature) /  sizeof(temperature[0]);
}

int get_menu2_size(int i) {
  int result = 0;
  
  while ((result < MAX_MENU2) && (temperature[i].menu2[result].label[0] != '\0')) {
    result++;
  }
  
  return result;
}

int get_menu3_size(int i, int j) {
  int result = 0;
  
  while ((result < MAX_MENU3) && (temperature[i].menu2[j].menu3[result].label[0] != '\0')) {
    result++;
  }
  
  return result;
}

#endif
