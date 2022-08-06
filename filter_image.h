#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define RGB_COMPONENT_COLOR 255

typedef struct Pixel_Data
{
    unsigned char red,green,blue;

}Pixel_Data;

typedef struct PPM_Image_Buffer {
    Pixel_Data* data;
    int rown, coln;
}PPM_Image_Buffer;



int read_P3_ppm_color_bitmap(const char *filename, PPM_Image_Buffer **buf);
int read_P6_ppm_color_bitmap(const char *filename, PPM_Image_Buffer **buf);
int write_ppm_color_bitmap(char *filename, PPM_Image_Buffer *buf);
void filter_color_component(PPM_Image_Buffer* buf, unsigned int rgb_mask);
void convert_to_grayscale(PPM_Image_Buffer* buf);