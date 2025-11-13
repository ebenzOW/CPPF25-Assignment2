#include "bmp.hpp"
#include <iostream>
#include <time.h>
void draw_rectangle(BMP &bmp,int x, int y, int l, int h, int b, color c ){
    for(int i=0;i<=l;i++){
        for(int ii=0;ii<=b;ii++){
        bmp.set_pixel(i+x, y+ii, c.r,c.g,c.b);
        bmp.set_pixel(i+x, y+h-ii, c.r, c.g,c.b);
        }
    }
    for(int j=0;j<=h;j++){
        for(int ii=0;ii<=b;ii++){
            bmp.set_pixel(x+ii, y+j, c.r,c.g,c.b);
            bmp.set_pixel(x+l-ii, y+j,c.r, c.g,c.b);
        }
    }
}
void draw_rectangle_gradient(BMP &bmp, int startX, int startY, int l, int h, color c1, color c2)
{

    if(l <= 0 || h <= 0) return;
    float ratio;
    uint8_t r,g,b;

    for(int y=0; y<=h; y++){
        ratio = ((y - startY)/(h - startY));
        r = c1.r + ((c2.r - c1.r)*ratio);
        g = c1.g + ((c2.g - c1.g)*ratio);
        b = c1.b + ((c2.b - c1.b)*ratio); 

        for(int x= 0; x<=l; x++)
        {
            bmp.set_pixel(startX + x, startY + y, r, g, b);
        }
    }

}

int main() {
    
    BMP bmp(1000, 1000); 
    
    draw_rectangle_gradient(bmp,1,1,1000,1000, color{255,192,203}, color{0,0,255});
  
    bmp.write("epic_gradient.bmp"); // Save the image to a file

    return 0;
}


//triangle
//line formula using slope
//(y = mx + b)