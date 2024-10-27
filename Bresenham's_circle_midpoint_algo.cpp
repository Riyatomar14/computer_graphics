#include <graphics.h> 
#include <conio.h>
#include <iostream>

using namespace std;

void drawCircleBresenham(int h, int k, int r) {
    int x = 0, y = r;
    int d = 1 - r;

    do {
        putpixel(h + x, k + y, 4);  // Draw 8 symmetric points
        putpixel(h + x, k - y, 4);
        putpixel(h - x, k + y, 4);
        putpixel(h - x, k - y, 4);
        putpixel(h + y, k + x, 4);
        putpixel(h + y, k - x, 4);
        putpixel(h - y, k + x, 4);
        putpixel(h - y, k - x, 4);

        if (d < 0) {
            x++;
            d += 2 * x + 3;
        } else {
            x++;
            y--;
            d += 2 * (x - y) + 5;
        }
    } while (x < y);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");  // Graphics initialization

    int h, k, r;
    cout << "Enter the center coordinates (h, k): ";
    cin >> h >> k;
    cout << "Enter the radius: ";
    cin >> r;

    drawCircleBresenham(h, k, r);  // Call function to draw the circle

    getch();
    closegraph();  // Close the graphics window
    return 0;
}

}while(x<y);
getch();
closegraph();
}
