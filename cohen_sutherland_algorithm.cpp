#include <graphics.h>
#include <conio.h>
#include <iostream>

using namespace std;

static const int LEFT = 1, RIGHT = 2, BOTTOM = 4, TOP = 8;
int xmin, ymin, xmax, ymax;

// Function to get the region code of a point (x, y)
int getcode(int x, int y) {
    int code = 0;
    if (y > ymax) code |= TOP;
    if (y < ymin) code |= BOTTOM;
    if (x < xmin) code |= LEFT;
    if (x > xmax) code |= RIGHT;
    return code;
}

void cohenSutherlandClip(int &x1, int &y1, int &x2, int &y2) {
    int outcode1 = getcode(x1, y1);
    int outcode2 = getcode(x2, y2);
    bool accept = false;

    while (true) {
        if (outcode1 == 0 && outcode2 == 0) {
            // Both endpoints lie within the rectangle
            accept = true;
            break;
        } else if ((outcode1 & outcode2) != 0) {
            // Both endpoints are outside the rectangle in the same region
            break;
        } else {
            // Clipping required
            int x, y;
            int temp = (outcode1 != 0) ? outcode1 : outcode2;
            float m = (x2 - x1 != 0) ? (float)(y2 - y1) / (x2 - x1) : 0;  // Avoid division by zero

            if (temp & TOP) {
                x = x1 + (ymax - y1) / m;
                y = ymax;
            } else if (temp & BOTTOM) {
                x = x1 + (ymin - y1) / m;
                y = ymin;
            } else if (temp & LEFT) {
                x = xmin;
                y = y1 + m * (xmin - x1);
            } else if (temp & RIGHT) {
                x = xmax;
                y = y1 + m * (xmax - x1);
            }

            // Replace point outside rectangle with intersection point
            if (temp == outcode1) {
                x1 = x;
                y1 = y;
                outcode1 = getcode(x1, y1);
            } else {
                x2 = x;
                y2 = y;
                outcode2 = getcode(x2, y2);
            }
        }
    }

    // Draw clipped line if accepted
    if (accept) {
        cleardevice();
        rectangle(xmin, ymin, xmax, ymax);
        setcolor(RED);
        line(x1, y1, x2, y2);
    } else {
        cout << "Line is outside the clipping window.\n";
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");  // Graphics initialization

    cout << "Enter window minimum (xmin, ymin) and maximum (xmax, ymax) values: ";
    cin >> xmin >> ymin >> xmax >> ymax;
    rectangle(xmin, ymin, xmax, ymax);

    int x1, y1, x2, y2;
    cout << "Enter the endpoints of the line (x1, y1) and (x2, y2): ";
    cin >> x1 >> y1 >> x2 >> y2;
    line(x1, y1, x2, y2);

    cohenSutherlandClip(x1, y1, x2, y2);

    getch();
    closegraph();  // Close the graphics window
    return 0;
}

