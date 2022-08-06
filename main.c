#include"filter_image.h"

PPM_Image_Buffer *fp;

int main(int argc, char *argv[]){

    read_P3_ppm_color_bitmap(argv[1],&fp);
    
    //check the third element on the command line
    if(strcmp(argv[3],"-g") == 0){
        convert_to_grayscale(fp);
        write_ppm_color_bitmap(argv[2],fp);
    }
    
    if(strcmp(argv[3],"-f") == 0){
       
       //check the 4th command line's element 
       if(strcmp(argv[4],"r") == 0){
            filter_color_component(fp,1);
            write_ppm_color_bitmap(argv[2],fp);
        }
        if(strcmp(argv[4],"rb") == 0){
            filter_color_component(fp,5);
            write_ppm_color_bitmap(argv[2],fp);
        }
        if(strcmp(argv[4],"rg")== 0){
            filter_color_component(fp,3);
            write_ppm_color_bitmap(argv[2],fp);
        }
        if(strcmp(argv[4],"g") == 0){
            filter_color_component(fp,2);
            write_ppm_color_bitmap(argv[2],fp);
        }
        if(strcmp(argv[4],"gb") == 0){
            filter_color_component(fp,6);
            write_ppm_color_bitmap(argv[2],fp);
        }   
        if(strcmp(argv[4],"b") == 0){
            filter_color_component(fp,4);
            write_ppm_color_bitmap(argv[2],fp);
        }
        
        
    }
    

    return 0;
}