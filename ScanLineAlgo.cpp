#include <stdio.h>
#include <conio.h>
#include <graphics.h>

int main() {
    int n, i, j, k, gd = DETECT, gm, dy, dx;
    int x, y, temp;
    int a[20][2], xi[20];
    float slope[20];

    // Clear screen
    clrscr();

    // Input the number of edges
    printf("\nEnter the number of edges of the polygon: ");
    scanf("%d", &n);

    // Input the coordinates of the polygon vertices
    printf("\nEnter the coordinates of the polygon:\n");
    for (i = 0; i < n; i++) {
        printf("Vertex %d (x, y): ", i + 1);
        scanf("%d%d", &a[i][0], &a[i][1]);
    }

    // Close the polygon by setting the last point equal to the first
    a[n][0] = a[0][0];
    a[n][1] = a[0][1];

    // Initialize graphics mode
    initgraph(&gd, &gm, "");

    // Draw the polygon edges
    for (i = 0; i < n; i++) {
        line(a[i][0], a[i][1], a[i + 1][0], a[i + 1][1]);
    }

    // Calculate slopes of each edge
    for (i = 0; i < n; i++) {
        dy = a[i + 1][1] - a[i][1];
        dx = a[i + 1][0] - a[i][0];

        if (dy == 0) {
            slope[i] = 1.0;
        } else if (dx == 0) {
            slope[i] = 0.0;
        } else {
            slope[i] = (float) dx / dy;
        }
    }

    // Apply scanline fill
    for (y = 0; y < getmaxy(); y++) {
        k = 0;

        // Find intersections with the current scanline
        for (i = 0; i < n; i++) {
            if (((a[i][1] <= y) && (a[i + 1][1] > y)) ||
                ((a[i][1] > y) && (a[i + 1][1] <= y))) {
                xi[k] = (int)(a[i][0] + slope[i] * (y - a[i][1]));
                k++;
            }
        }

        // Sort intersection points
        for (j = 0; j < k - 1; j++) {
            for (i = 0; i < k - 1; i++) {
                if (xi[i] > xi[i + 1]) {
                    temp = xi[i];
                    xi[i] = xi[i + 1];
                    xi[i + 1] = temp;
                }
            }
        }

        // Draw horizontal lines between pairs of intersections
        for (i = 0; i < k; i += 2) {
            line(xi[i], y, xi[i + 1], y);
        }
    }

    getch();
    closegraph();
    return 0;
}
