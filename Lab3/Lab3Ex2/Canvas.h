
#ifndef LAB3EX2_CANVAS_H
#define LAB3EX2_CANVAS_H
#pragma once

#include <vector>

class Canvas {
private:
    int width_;
    int height_;
    std::vector<std::vector<char>> pixels_;
public:
    Canvas(int width, int height);
    void DrawCircle(int x, int y, int ray, char ch);
    void FillCircle(int x, int y, int ray, char ch);
    void DrawRect(int left, int top, int right, int bottom, char ch);
    void FillRect(int left, int top, int right, int bottom, char ch);
    void SetPoint(int x, int y, char ch);
    void DrawLine(int x1, int y1, int x2, int y2, char ch);
    void Print();
    void Clear();
};

#endif //LAB3EX2_CANVAS_H
