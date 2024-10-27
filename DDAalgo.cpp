#include <graphics.h>  
#include <conio.h>
#include <iostream.h>
#include <math.h>  // For abs() and round() functions

using namespace std;

void drawLineDDA(int x1, int y1, int x2, int y2) {
    
    int dx = x2 - x1;
    int dy = y2 - y1;

    // Calculate the number of steps needed for generating pixels
    int steps = max(abs(dx), abs(dy));

    // Calculate the increment in x & y for each step
    float xInc = dx / (float) steps;
    float yInc = dy / (float) steps;

    // Initialize starting point
    float x = x1;
    float y = y1;

    // Put pixels for each step
    for (int i = 0; i <= steps; i++) {
        putpixel(round(x), round(y), WHITE);  // Draw pixel at the current point
        x += xInc;  // Increment x
        y += yInc;  // Increment y
        delay(10);  // Optional delay for visualization
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");  // Initialize graphics mode

    int x1, y1, x2, y2;
    cout << "Enter the starting point (x1, y1): ";
    cin >> x1 >> y1;
    cout << "Enter the ending point (x2, y2): ";
    cin >> x2 >> y2;

    drawLineDDA(x1, y1, x2, y2);  // Call the DDA line drawing function

    getch();  
    closegraph();  // Close the graphics window
    return 0;
}
