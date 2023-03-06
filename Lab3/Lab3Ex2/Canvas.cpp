#include "Canvas.h"
#include <iostream>
#include <cmath>

Canvas::Canvas(int width, int height)
        : width_(width), height_(height), pixels_(height, std::vector<char>(width, ' ')) {}

void Canvas::DrawCircle(int x, int y, int ray, char ch) {

}

void Canvas::FillCircle(int x, int y, int ray, char ch) {

}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch) {
    for (int i = left; i <= right; ++i) {
        SetPoint(i, top, ch);
        SetPoint(i, bottom, ch);
    }
    for (int i = top; i <= bottom; ++i) {
        SetPoint(left, i, ch);
        SetPoint(right, i, ch);
    }
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch) {
    for (int i = top; i <= bottom; ++i) {
        for (int j = left; j <= right; ++j) {
            SetPoint(j, i, ch);
        }
    }
}

void Canvas::SetPoint(int x, int y, char ch) {
    if (x >= 0 && x < width_ && y >= 0 && y < height_) {
        pixels_[y][x] = ch;
    }
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch) {
    // Bresenham's line algorithm
    const bool steep = std::abs(y2 - y1) > std::abs(x2 - x1);
    if (steep) {
        std::swap(x1, y1);
        std::swap(x2, y2);
    }
    if (x1 > x2) {
        std::swap(x1, x2);
        std::swap(y1, y2);
    }
    const float dx = x2 - x1;
    const float dy = std::abs(y2 - y1);
    float error = dx / 2.0f;
    const int ystep = (y1 < y2) ? 1 : -1;
    int y = static_cast<int>(y1);
    const int maxX = static_cast<int>(x2);
    for (int x = static_cast<int>(x1); x <= maxX; x++) {
        if (steep) {
            SetPoint(y, x, ch);
        } else {
            SetPoint(x, y, ch);
            error -= dy;
            if (error < 0) {
                y += ystep;
                error += dx;
            }
        }
    }

    void Canvas::Print() const {
        for (int i = 0; i < height_; ++i) {
            for (int j = 0; j < width_; ++j) {
                std::cout << pixels_[i][j];
            }
            std::cout << '\n';
        }
    }

    void Canvas::Clear() {
        for (int i = 0; i < height_; ++i) {
            for (int j = 0; j < width_; ++j) {
                pixels_[i][j] = ' ';
            }
        }
    }
}