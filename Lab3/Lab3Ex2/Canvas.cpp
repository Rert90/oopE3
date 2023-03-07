#include "Canvas.h"
#include <iostream>

using namespace std;

Canvas::Canvas(int width, int height)
{
    this->width = width;
    this->height = height;
    matrix = new char*[height];
    for (int i = 0; i < height; i++)
    {
        matrix[i] = new char[width];
        for (int j = 0; j < width; j++)
        {
            matrix[i][j] = ' ';
        }
    }
}

void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
    int cx = ray;
    int cy = 0;
    int d = 1 - ray;

    while (cx >= cy)
    {
        SetPoint(x + cx, y + cy, ch);
        SetPoint(x - cx, y + cy, ch);
        SetPoint(x + cx, y - cy, ch);
        SetPoint(x - cx, y - cy, ch);
        SetPoint(x + cy, y + cx, ch);
        SetPoint(x - cy, y + cx, ch);
        SetPoint(x + cy, y - cx, ch);
        SetPoint(x - cy, y - cx, ch);

        cy++;
        if (d < 0)
        {
            d += 2 * cy + 1;
        }
        else
        {
            cx--;
            d += 2 * (cy - cx) + 1;
        }
    }
}


void Canvas::FillCircle(int x, int y, int ray, char ch)
{
    for (int i = y - ray; i <= y + ray; i++)
    {
        for (int j = x - ray; j <= x + ray; j++)
        {
            if ((i - y) * (i - y) + (j - x) * (j - x) <= ray * ray)
            {
                SetPoint(j, i, ch);
            }
        }
    }
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
    for (int i = top; i <= bottom; i++)
    {
        for (int j = left; j <= right; j++)
        {
            if ((i == top || i == bottom) && j >= left && j <= right)
            {
                SetPoint(j, i, ch);
            }
            else if ((j == left || j == right) && i >= top && i <= bottom)
            {
                SetPoint(j, i, ch);
            }
        }
    }
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
    for (int i = top; i <= bottom; i++)
    {
        for (int j = left; j <= right; j++)
        {
            SetPoint(j, i, ch);
        }
    }
}

void Canvas::SetPoint(int x, int y, char ch)
{
    if (y >= 0 && y < height && x >= 0 && x < width)
    {
        matrix[y][x] = ch;
    }
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    float xIncrement = dx / (float)steps;
    float yIncrement = dy / (float)steps;
    float x = x1, y = y1;
    for (int i = 0; i <= steps; i++)
    {
        SetPoint((int)x, (int)y, ch);
        x += xIncrement;
        y += yIncrement;
    }
}

void Canvas::Print() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cout << matrix[i][j];
        }
        cout << endl;
    }

}void Canvas::Clear()
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            matrix[i][j] = ' ';
        }
    }
}

Canvas::~Canvas()
{
    for (int i = 0; i < height; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}
