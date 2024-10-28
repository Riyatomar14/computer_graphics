#include <iostream.h>
#include <graphics.h>
#include <conio.h>
#include <dos.h>
#include <math.h>

void main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm," ");  

    int x1, y1, x2, y2, dx, dy, steps,xinc, yinc;
    
    cout << "Enter the starting point (x1, y1): ";
    cin >> x1 >> y1;
    cout << "Enter the ending point (x2, y2): ";
    cin >> x2 >> y2;

    dx = x2 - x1;
    dy = y2 - y1;

    if(abs(dx)>abs(dy)){
       steps=abs(dx);
    }
    else{
        steps=abs(dy);
    }

    xinc = dx / steps;
    yinc = dy / steps;

    for (int i = 0; i <= steps; i++) {
        putpixel(x1, y1, 3);  
        x1 += xinc;
        y1 += yinc;
            
    }
    getch();
    closegraph();
}
