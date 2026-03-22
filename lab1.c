#include <stdio.h>
#include <math.h>

int main()
{
    int x0, y0, x1, y1;
    float x, y, dx, dy, steps, x_inc, y_inc;
    int i;

    printf("Soham Thapaliya\n");

    printf("Enter x0 and y0 = ");
    scanf("%d %d", &x0, &y0);

    printf("Enter x1 and y1 = ");
    scanf("%d %d", &x1, &y1);

    dx = x1 - x0;
    dy = y1 - y0;

    if (fabs(dx) > fabs(dy))
        steps = fabs(dx);
    else
        steps = fabs(dy);

    x_inc = dx / steps;
    y_inc = dy / steps;

    x = x0;
    y = y0;

    printf("\nPoints on the line:\n");

    for (i = 0; i <= steps; i++)
    {
        printf("(%.0f, %.0f)\n", x, y);
        x += x_inc;
        y += y_inc;
    }

    return 0;
}