#include <iostream>
#include <graphics.h>  
#include <conio.h>

using namespace std;

void drawLineBresenham(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int p = 2 * dy - dx;
    
    putpixel(x1, y1, 10);  // Draw the starting pixel
    
    while (x1 <= x2) {
        x1++;
        
        if (p < 0) {
            p += 2 * dy;
        } else {
            y1++;
            p += 2 * (dy - dx);
        }
        
        putpixel(x1, y1, 10);  // Draw each pixel
        delay(10);  // Optional delay for animation effect
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");  // Graphics initialization

    int x1, y1, x2, y2;
    cout << "Enter the coordinates of the starting point (x1, y1): ";
    cin >> x1 >> y1;
    cout << "Enter the coordinates of the ending point (x2, y2): ";
    cin >> x2 >> y2;

    drawLineBresenham(x1, y1, x2, y2);  // Call the Bresenham line function

    getch();
    closegraph();  // Close the graphics window
    return 0;
}
