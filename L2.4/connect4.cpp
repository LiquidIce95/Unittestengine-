#include "/home/Dave/Desktop/headers_modules/CImg-master/CImg.h"


using namespace cimg_library;
//Basic Colors
const unsigned char
white[]  = { 255, 255, 255 }, black[] = { 0, 0, 0 }, red[] = { 120, 50, 80 },
yellow[] = { 200, 155, 0 }, green[] = { 30, 200, 70 }, purple[] = { 175, 32, 186 },
blue[] = { 55, 140, 185 }, grey[] = { 127, 127, 127 }, darkblue[] = {20,100,120},
darkgrey[] = {60,60,60}, darkpurple[] = {54,21,59};


int main(){

    CImg<unsigned char> img(1920,1080,1,3,0);
    img.draw_rectangle(40,80,100,70,red,1);
    CImgDisplay mai(img,"connect4");
    

    while(true){
        // img.display(mai);
        mai.show();
    }

    return 0;
}