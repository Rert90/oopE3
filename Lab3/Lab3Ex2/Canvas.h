//
// Created by Olariu Robert on 06.03.2023.
//

#ifndef LAB3EX2_CANVAS_H
#define LAB3EX2_CANVAS_H
#pragma once

class Canvas
{
    int witdh;
    int height;
    int x,y,x1,x2,y1,y2;
    int ray;
    char ch;
    int bottom,right,left,top;
public:
    Canvas(int width,int height);
    void DrawCircle(int x, int y, int ray, char ch);
    void FillCircle(int x, int y, int ray, char ch);
    void DrawRect(int left, int top, int right, int bottom, char ch);
    void FillRect(int left, int top, int right, int bottom, char ch);
    void SetPoint(int x, int y, char ch);
    void DrawLine(int x1, int y1, int x2, int y2, char ch);
    void Print(); // shows what was printed
    void Clear(); // clears the canvas
};


#endif //LAB3EX2_CANVAS_H
