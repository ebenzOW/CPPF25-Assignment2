#include "bmp.hpp"
#include <iostream>
#include <cmath>

using namespace std;

struct Point{
    int x;
    int y;
};

void draw_rectangle_gradient(BMP &bmp, int startX, int startY, int l, int h, color c1, color c2)
{

    if(l <= 0 || h <= 0 || l >bmp.get_width() || h > bmp.get_height()) return;
    int ratio;
    uint8_t r,g,b;

    for(int y=0; y<=h; y++){
        ratio = ((y - startY)*255/(h - startY));
        r = c1.r + ((c2.r - c1.r)*ratio);
        g = c1.g + ((c2.g - c1.g)*ratio);
        b = c1.b + ((c2.b - c1.b)*ratio); 

        for(int x= 0; x<=l; x++)
        {
            bmp.set_pixel(startX + x, startY + y, r, g, b);
        }
    }

}

void draw_line(BMP &bmp , Point p1, Point p2)
{
    /* Naive approach
    float slope = (p2.y - p1.y)/(p2.x - p1.x);
    float intercept = p1.y - slope*(p1.x);
    float y;

    for(int x = p1.x; x <= p2.x; x++)
    {
        y = slope*x + intercept;

        bmp.set_pixel(x, int(round(y)), 0, 0, 0);
    }
    #endif
    */

    int abs_dx = abs(p1.x - p2.x);
    int abs_dy = abs(p1.y - p2.y);

    int x_step = 1;
    int y_step = 1;



    if(p2.x < p1.x) x_step = -1;
    if(p2.y < p1.y) y_step = -1;

    int err = abs_dx - abs_dy;

    bmp.set_pixel(p1.x, p1.y, 0 , 0, 0);
    int x_count = p1.x;
    int y_count = p1.y;

    while(true)
    {
        
        if (2* err >  (abs_dy*(-1)) )
        {
            x_count += x_step;
            bmp.set_pixel(x_count, y_count, 0, 0, 0);
            err = err - abs_dy;
        }
        if(2 * err  < abs_dx)
        {
            y_count += y_step;
            bmp.set_pixel(x_count, y_count, 0, 0, 0);
            //abs_dy = abs(y_count - p2.y);
            err = err + abs_dx;
        } 
        if(x_count == p2.x && y_count == p2.y ) break;      
    }
    

}

int main() {
    
    BMP bmp(500, 500); 
    
    draw_rectangle_gradient(bmp,1,1,500,500, color{255,0,0}, color{0,0,255});
    draw_line(bmp, Point{5, 5}, Point{275,400});
  
    bmp.write("epic_gradient.bmp"); // Save the image to a file

    return 0;
}

