#include <graphics.h>
#include <conio.h>
#include <iostream.h>
#include <math.h>



void drawBezierCurve(int x0, int y0, int x1, int y1, int x2, int y2, int x3, int y3) {
    for (float t = 0; t <= 1; t += 0.001) {
        float xt = pow(1 - t, 3) * x0 + 3 * t * pow(1 - t, 2) * x1 + 3 * pow(t, 2) * (1 - t) * x2 + pow(t, 3) * x3;
        float yt = pow(1 - t, 3) * y0 + 3 * t * pow(1 - t, 2) * y1 + 3 * pow(t, 2) * (1 - t) * y2 + pow(t, 3) * y3;

        putpixel(xt, yt, WHITE);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*) "");

    int x0 = 100, y0 = 400; // Start point
    int x1 = 200, y1 = 100; // Control point 1
    int x2 = 400, y2 = 100; // Control point 2
    int x3 = 500, y3 = 400; // End point

    drawBezierCurve(x0, y0, x1, y1, x2, y2, x3, y3);
    getch();
    closegraph;
}

