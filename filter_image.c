#include"filter_image.h"

int read_P3_ppm_color_bitmap(const char *filename, PPM_Image_Buffer **buf)
{
         char a[16];
         
         FILE *fp;
         int c, rgb_comp_color;
         //open PPM file for reading
         fp = fopen(filename, "r");
         if (!fp) {
              fprintf(stderr, "Unable to open file '%s'\n", filename);
              return -1;
         }

         //read image format
        fgets(a, sizeof(a), fp);

    //check the image format
    if (a[0] != 'P' || a[1] != '3') {
         fprintf(stderr, "Invalid image format (must be 'P3')\n");
         return -1;
    }

    //alloc memory form image
    *buf = (PPM_Image_Buffer *)malloc(sizeof(PPM_Image_Buffer));

    //check for comments
    c = getc(fp);
    while (c == '#') {
    while (getc(fp) != '\n') ;
         c = getc(fp);
    }

    ungetc(c, fp);
    //read image size information
    fscanf(fp, "%d %d", &(*buf)->rown, &(*buf)->coln);
    
    //read rgb component
    fscanf(fp, "%d", &rgb_comp_color);


    while (fgetc(fp) != '\n') ;
    //memory allocation for pixel data
    (*buf)->data = (Pixel_Data*)malloc((*buf)->rown * (*buf)->coln * sizeof(Pixel_Data));

    if (!(*buf)) {
         fprintf(stderr, "Unable to allocate memory\n");
         return -1;
    }

    //read pixel data from file
    fread((*buf)->data, 3 * (*buf)->rown, (*buf)->coln, fp);

    fclose(fp);
    return 0;
}

int read_P6_ppm_color_bitmap(const char *filename, PPM_Image_Buffer **buf)
{
         char a[16];
         
         FILE *fp;
         int c, rgb_comp_color;
         //open PPM file for reading
         fp = fopen(filename, "rb");
         if (!fp) {
              fprintf(stderr, "Unable to open file '%s'\n", filename);
              return -1;
         }

         //read image format
        fgets(a, sizeof(a), fp);

    //check the image format
    if (a[0] != 'P' || a[1] != '6') {
         fprintf(stderr, "Invalid image format (must be 'P6')\n");
         return -1;
    }

    //alloc memory form image
    *buf = (PPM_Image_Buffer *)malloc(sizeof(PPM_Image_Buffer));

    //check for comments
    c = getc(fp);
    while (c == '#') {
    while (getc(fp) != '\n') ;
         c = getc(fp);
    }

    ungetc(c, fp);
    //read image size information
    fscanf(fp, "%d %d", &(*buf)->rown, &(*buf)->coln);
    
    //read rgb component
    fscanf(fp, "%d", &rgb_comp_color);


    while (fgetc(fp) != '\n') ;
    //memory allocation for pixel data
    (*buf)->data = (Pixel_Data*)malloc((*buf)->rown * (*buf)->coln * sizeof(Pixel_Data));

    if (!(*buf)) {
         fprintf(stderr, "Unable to allocate memory\n");
         return -1;
    }

    //read pixel data from file
    fread((*buf)->data, 3 * (*buf)->rown, (*buf)->coln, fp);

    fclose(fp);
    return 0;
}


int write_ppm_color_bitmap(char *filename, PPM_Image_Buffer *buf){
    FILE *fp;
    //open file for output
    fp = fopen(filename, "wb");
    if (!fp) {
         fprintf(stderr, "Unable to open file '%s'\n", filename);
         exit(1);
    }

    //write the header file
    //image format
    fprintf(fp, "P6\n");

    //comments
    fprintf(fp, "# Created by Valentin\n");

    //image size
    fprintf(fp, "%d %d\n",buf->rown,buf->coln);

    // rgb component depth
    fprintf(fp, "%d\n",255);

    // pixel data
    fwrite(buf->data, 3 * buf->rown, buf->coln, fp);
    fclose(fp);
    return 0;
}

//set pixels colors 
void filter_color_component(PPM_Image_Buffer* buf, unsigned int rgb_mask){
int i;
    if(buf){

         for(i=0;i < buf->rown*buf->coln; i++){
            //modify red pixels
              buf->data[i].red=buf->data[i].red*!!(rgb_mask&1);
            //modify green pixels
              buf->data[i].green=buf->data[i].green*!!(rgb_mask&(1<<1));
            //modify blue pixels
              buf->data[i].blue=buf->data[i].blue*!!(rgb_mask&(1<<2));
         }
    }

}

//set pixels colors to grey 
void convert_to_grayscale(PPM_Image_Buffer* buf){
    int i;
    if(buf){
        for(int i=0; i< buf->coln*buf->rown;i++){
            buf->data[i].red=buf->data[i+1].red*0.3 +buf->data[i+2].green*0.59+buf->data[i+3].blue*0.11;
            buf->data[i].green=buf->data[i+1].red*0.3 +buf->data[i+2].green*0.59+buf->data[i+3].blue*0.11;
            buf->data[i].blue=buf->data[i+1].red*0.3 +buf->data[i+2].green*0.59+buf->data[i+3].blue*0.11;
        }

    }
}
