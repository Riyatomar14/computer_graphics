#include <graphics.h>
#include <conio.h>
#include <iostream.h>
#include <math.h>


void drawHermiteCurve(int x0, int y0, int x1, int y1, int rx0, int ry0, int rx1, int ry1) {
    for (float t = 0.0; t <= 1.0; t += 0.001) {
        float h1 = 2*t*t*t - 3*t*t + 1; // Hermite basis functions
        float h2 = -2*t*t*t + 3*t*t;
        float h3 = t*t*t - 2*t*t + t;
        float h4 = t*t*t - t*t;
        
        int x = h1*x0 + h2*x1 + h3*rx0 + h4*rx1;
        int y = h1*y0 + h2*y1 + h3*ry0 + h4*ry1;
        
        putpixel(x, y, WHITE);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*) "");

    int x0 = 100, y0 = 400;  // Start point
    int x1 = 500, y1 = 100;  // End point
    int rx0 = 150, ry0 = -200; // Tangent at the start
    int rx1 = -150, ry1 = 200; // Tangent at the end

    drawHermiteCurve(x0, y0, x1, y1, rx0, ry0, rx1, ry1);

    getch();
    closegraph();
    return 0;
}
