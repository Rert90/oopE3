#include "Canvas.h"

int main()
{
    Canvas canvas(30, 20);

    // Draw a circle
    canvas.DrawCircle(10, 10, 5, '*');
    canvas.Print();
    canvas.Clear();

    // Fill a circle
    canvas.FillCircle(20, 5, 3, '+');
    canvas.Print();
    canvas.Clear();

    // Draw a rectangle
    canvas.DrawRect(5, 5, 20, 15, '-');
    canvas.Print();
    canvas.Clear();

    // Fill a rectangle
    canvas.FillRect(8, 8, 18, 12, '=');
    canvas.Print();
    canvas.Clear();

    // Draw a line
    canvas.DrawLine(5, 5, 25, 15, '#');
    canvas.Print();
    canvas.Clear();

    return 0;
}
