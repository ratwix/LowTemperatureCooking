
/*******************************************************************************
* image
* filename: unsaved
* name: logo
*
* preset name: Monochrome
* data block size: 8 bit(s), uint8_t
* RLE compression enabled: no
* conversion type: Monochrome, Diffuse Dither 128
* bits per pixel: 1
*
* preprocess:
*  main scan direction: top_to_bottom
*  line scan direction: backward
*  inverse: no
*******************************************************************************/

/*
 typedef struct {
     const uint8_t *data;
     uint16_t width;
     uint16_t height;
     } tImage;
*/
#include <stdint.h>



static const uint8_t image_data_logo[517] = {
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 
    0xff, 0xff, 0xff, 0xff, 0xfe, 0xdf, 0xff, 0xff, 0xff, 0xff, 0x80, 
    0xff, 0xff, 0xff, 0xff, 0xfd, 0xef, 0xff, 0xff, 0xff, 0xff, 0x80, 
    0xff, 0xff, 0xff, 0xff, 0xeb, 0xfb, 0xff, 0xff, 0xff, 0xff, 0x80, 
    0xff, 0xff, 0xff, 0xff, 0xdf, 0xfe, 0xff, 0xff, 0xff, 0xff, 0x80, 
    0xff, 0xff, 0xff, 0xff, 0xbf, 0xff, 0x7f, 0xff, 0xff, 0xff, 0x80, 
    0xff, 0xff, 0xff, 0xff, 0xbf, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xff, 0xff, 0xff, 0xff, 0x80, 
    0xff, 0xff, 0xff, 0xff, 0xdf, 0xf9, 0xff, 0xff, 0xff, 0xff, 0x80, 
    0xff, 0xff, 0xff, 0xff, 0xe7, 0xfb, 0xff, 0xff, 0xff, 0xff, 0x80, 
    0xff, 0xff, 0xff, 0xff, 0xfd, 0x5b, 0xff, 0xff, 0xff, 0xff, 0x80, 
    0xff, 0xff, 0xff, 0xff, 0xdd, 0x6b, 0xff, 0xff, 0xff, 0xff, 0x80, 
    0xff, 0xff, 0xff, 0xff, 0xed, 0xfd, 0xff, 0xff, 0xff, 0xff, 0x80, 
    0xff, 0xff, 0xff, 0xff, 0xd6, 0x95, 0xff, 0xff, 0xff, 0xff, 0x80, 
    0xff, 0xff, 0xff, 0xff, 0xde, 0xde, 0xff, 0xff, 0xff, 0xff, 0x80, 
    0xff, 0xff, 0xff, 0xff, 0xde, 0xfe, 0xff, 0xff, 0xff, 0xff, 0x80, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xff, 0xff, 0xff, 0xff, 0x80, 
    0xff, 0xff, 0xff, 0xff, 0xd8, 0xc0, 0xff, 0xff, 0xff, 0xff, 0x80, 
    0xff, 0xff, 0xff, 0xff, 0xc0, 0x81, 0xff, 0xff, 0xff, 0xff, 0x80, 
    0xff, 0xff, 0xff, 0xff, 0xc1, 0xe1, 0xff, 0xff, 0xff, 0xff, 0x80, 
    0xff, 0xff, 0xff, 0xff, 0x2f, 0xae, 0x7f, 0xff, 0xff, 0xff, 0x80, 
    0xff, 0xff, 0xff, 0xfe, 0xf6, 0xf7, 0xbf, 0xff, 0xff, 0xff, 0x80, 
    0xff, 0xff, 0xff, 0xc2, 0xfc, 0x0f, 0xdf, 0xff, 0xff, 0xff, 0x80, 
    0xff, 0xff, 0xff, 0x3c, 0xf8, 0x9d, 0xef, 0xff, 0xff, 0xff, 0x80, 
    0xff, 0xff, 0xfd, 0xff, 0xb8, 0x8e, 0xef, 0xff, 0xff, 0xff, 0x80, 
    0xff, 0xff, 0xfd, 0xff, 0xd9, 0x8c, 0xf7, 0xff, 0xff, 0xff, 0x80, 
    0xff, 0xff, 0xfb, 0xff, 0xef, 0xfe, 0xf7, 0xff, 0xff, 0xff, 0x80, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xfb, 0xff, 0xff, 0xff, 0x80, 
    0xff, 0xff, 0xf7, 0xff, 0xef, 0xff, 0xfb, 0xff, 0xff, 0xff, 0x80, 
    0xff, 0xff, 0xf7, 0xff, 0xe0, 0x01, 0x23, 0xff, 0xff, 0xff, 0x80, 
    0xff, 0xff, 0xf2, 0xa9, 0x27, 0xfe, 0xdb, 0xff, 0xff, 0xff, 0x80, 
    0xff, 0xff, 0xed, 0x56, 0xd7, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 
    0xff, 0xff, 0x7f, 0xff, 0xff, 0x5f, 0xff, 0xef, 0xff, 0xff, 0x80, 
    0xff, 0xfc, 0x1f, 0xff, 0xce, 0x1f, 0xff, 0xcf, 0xff, 0xff, 0x80, 
    0xff, 0xf9, 0xff, 0xff, 0xdc, 0xff, 0xff, 0xef, 0xff, 0xff, 0x80, 
    0xff, 0xf9, 0xf8, 0x70, 0xcc, 0xfc, 0x38, 0xcd, 0xff, 0xff, 0x80, 
    0xff, 0xf9, 0xf9, 0x24, 0x6d, 0xf8, 0xb0, 0x49, 0xff, 0xff, 0x80, 
    0xff, 0xf9, 0xf3, 0xa7, 0x59, 0xf3, 0x87, 0x43, 0xff, 0xff, 0x80, 
    0xff, 0xf9, 0xf3, 0xae, 0x4d, 0xfb, 0x97, 0x23, 0xff, 0xff, 0x80, 
    0xff, 0xf9, 0xfb, 0x26, 0x6d, 0xf9, 0x87, 0x49, 0xff, 0xff, 0x80, 
    0xff, 0xfc, 0x91, 0x24, 0xcc, 0x49, 0x32, 0x4d, 0xff, 0xff, 0x80, 
    0xff, 0xfc, 0x1c, 0x70, 0xee, 0x1c, 0x70, 0xec, 0xff, 0xff, 0x80, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80
};
const tImage logo = { image_data_logo, 81, 47};

