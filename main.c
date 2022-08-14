#include"filter_image.h"

PPM_Image_Buffer *fp;

int main(int argc, char *argv[]){

    if(!strcmp(argv[3],"-t")){
    read_P3_ppm_color_bitmap(argv[1],&fp);
    }
    if(!strcmp(argv[3],"-b")){
    read_P6_ppm_color_bitmap(argv[1],&fp);
    }

    
    //check the third element on the command line
    if(strcmp(argv[4],"-g") == 0){
        convert_to_grayscale(fp);
        write_ppm_color_bitmap(argv[2],fp);
    }
    
    if(strcmp(argv[4],"-f") == 0){
       
       //check the 4th command line's element 
       if(strcmp(argv[5],"r") == 0){
            filter_color_component(fp,1);
            write_ppm_color_bitmap(argv[2],fp);
        }
        if(strcmp(argv[5],"rb") == 0){
            filter_color_component(fp,5);
            write_ppm_color_bitmap(argv[2],fp);
        }
        if(strcmp(argv[5],"rg")== 0){
            filter_color_component(fp,3);
            write_ppm_color_bitmap(argv[2],fp);
        }
        if(strcmp(argv[5],"g") == 0){
            filter_color_component(fp,2);
            write_ppm_color_bitmap(argv[2],fp);
        }
        if(strcmp(argv[5],"gb") == 0){
            filter_color_component(fp,6);
            write_ppm_color_bitmap(argv[2],fp);
        }   
        if(strcmp(argv[5],"b") == 0){
            filter_color_component(fp,4);
            write_ppm_color_bitmap(argv[2],fp);
        }
        
        
    }
    

    return 0;
}