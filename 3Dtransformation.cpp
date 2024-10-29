#include <iostream>
#include <graphics.h>
#include <math.h>
#include <conio.h>

using namespace std;

struct Point3D {
    float x, y, z;
};

// Function to project 3D points to 2D
Point3D project(Point3D p, float d = 500) {
    Point3D proj;
    proj.x = d * (p.x / (d + p.z));
    proj.y = d * (p.y / (d + p.z));
    proj.z = 0;  // z is not needed in 2D projection
    return proj;
}

void drawCube(Point3D points[8]) {
    // Draw edges of the cube by connecting projected points
    for (int i = 0; i < 4; i++) {
        // Front face
        line(points[i].x, points[i].y, points[(i+1) % 4].x, points[(i+1) % 4].y);
        // Back face
        line(points[i+4].x, points[i+4].y, points[((i+1) % 4) + 4].x, points[((i+1) % 4) + 4].y);
        // Connecting front and back faces
        line(points[i].x, points[i].y, points[i+4].x, points[i+4].y);
    }
}

int main() {
    int gd = DETECT, gm, ch;
    initgraph(&gd, &gm, "");

    Point3D points[8] = {
        {100, 100, 100}, {200, 100, 100}, {200, 200, 100}, {100, 200, 100},  // Front face
        {100, 100, 200}, {200, 100, 200}, {200, 200, 200}, {100, 200, 200}   // Back face
    };

    cout << "3D Transformations:\n"
         << "\t1. Translation\n"
         << "\t2. Rotation\n"
         << "\t3. Scaling\n";
    cout << "Enter your choice: ";
    cin >> ch;

    switch (ch) {
        case 1: {
            // Translation
            int tx, ty, tz;
            cout << "Enter translation amounts (tx, ty, tz): ";
            cin >> tx >> ty >> tz;
            for (int i = 0; i < 8; i++) {
                points[i].x += tx;
                points[i].y += ty;
                points[i].z += tz;
            }
            break;
        }
        case 2: {
            // Rotation
            int thetaX, thetaY, thetaZ;
            cout << "Enter rotation angles for x, y, and z axes (in degrees): ";
            cin >> thetaX >> thetaY >> thetaZ;

            float radX = thetaX * 3.14159 / 180;
            float radY = thetaY * 3.14159 / 180;
            float radZ = thetaZ * 3.14159 / 180;

            for (int i = 0; i < 8; i++) {
                // Rotate around X-axis
                float y = points[i].y * cos(radX) - points[i].z * sin(radX);
                float z = points[i].y * sin(radX) + points[i].z * cos(radX);
                points[i].y = y;
                points[i].z = z;

                // Rotate around Y-axis
                float x = points[i].x * cos(radY) + points[i].z * sin(radY);
                z = -points[i].x * sin(radY) + points[i].z * cos(radY);
                points[i].x = x;
                points[i].z = z;

                // Rotate around Z-axis
                x = points[i].x * cos(radZ) - points[i].y * sin(radZ);
                y = points[i].x * sin(radZ) + points[i].y * cos(radZ);
                points[i].x = x;
                points[i].y = y;
            }
            break;
        }
        case 3: {
            // Scaling
            float sx, sy, sz;
            cout << "Enter scaling factors (sx, sy, sz): ";
            cin >> sx >> sy >> sz;

            for (int i = 0; i < 8; i++) {
                points[i].x *= sx;
                points[i].y *= sy;
                points[i].z *= sz;
            }
            break;
        }
        default: {
            cout << "Invalid choice." << endl;
            closegraph();
            return 0;
        }
    }

    // Project and draw the transformed cube
    Point3D projectedPoints[8];
    for (int i = 0; i < 8; i++) {
        projectedPoints[i] = project(points[i]);
    }
    drawCube(projectedPoints);

    getch();
    closegraph();
    return 0;
}
