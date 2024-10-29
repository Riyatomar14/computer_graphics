#include <iostream.h>
#include <graphics.h>
#include <math.h>
#include<conio.h>

int main() {
    int gd = DETECT, gm, ch, tx, ty, theta, sx, sy;
    initgraph(&gd, &gm, "");

    cout << "Transformations are:\n"
         << "\t1. Translation\n"
         << "\t2. Rotation\n"
         << "\t3. Scaling\n";
    cout << "Enter your choice: ";
    cin >> ch;

    switch (ch) {
        case 1: {
            cout << "It's Translation" << endl;
            rectangle(200, 200, 300, 300);

            cout << "Enter translation amounts (tx and ty): ";
            cin >> tx >> ty;

            rectangle(200 + tx, 200 + ty, 300 + tx, 300 + ty);
            break;
        }
        case 2: {
            cout << "It's Rotation" << endl;
            rectangle(200, 200, 300, 300);

            cout << "Enter the angle of rotation: ";
            cin >> theta;

            float radian = (theta * 3.14) / 180;  // Convert angle to radians

            int x_new = 200 + (300 - 200) * cos(radian) - (300 - 200) * sin(radian);
            int y_new = 200 + (300 - 200) * sin(radian) + (300 - 200) * cos(radian);

            rectangle(200, 200, x_new, y_new);
            break;
        }
        case 3: {
            cout << "It's Scaling" << endl;
            rectangle(200, 200, 300, 300);

            cout << "Enter scaling factors (sx and sy): ";
            cin >> sx >> sy;

            rectangle(200, 200, 200 + (100 * sx), 200 + (100 * sy));
            break;
        }
        default: {
            cout << "Wrong choice" << endl;
            break;
        }
    }

    cin.get(); // Pause the screen
    closegraph();

    return 0;
}
