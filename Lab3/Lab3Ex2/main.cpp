#include "Canvas.h"

int main()
{
    Canvas canvas(50, 50);

    // Draw a circle
    canvas.DrawCircle(10, 10, 10, '.');
    canvas.FillCircle(10,10,10,'.');
    canvas.Print();
    canvas.Clear();

    // Draw a rectangle
    canvas.DrawRect(7, 7, 19, 13, '+');
    canvas.FillRect(8, 8, 18, 12, '=');
    canvas.Print();
    canvas.Clear();

    // Draw a line
    canvas.DrawLine(5, 5, 24, 15, '(');
    canvas.Print();
    canvas.Clear();

    return 0;
}
