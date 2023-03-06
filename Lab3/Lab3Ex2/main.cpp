#include "Canvas.h"

int main() {
    Canvas canvas(30, 20);

    canvas.DrawLine(1, 1, 28, 18, '*');
    canvas.DrawCircle(15, 10, 6, '+');
    canvas.FillCircle(15, 10, 4, '-');
    canvas.DrawRect(3, 5, 27, 15, '#');
    canvas.FillRect(5, 7, 25, 13, '@');

    canvas.Print();
    canvas.Clear();
    return 0;
}
