#include "Canvas.h"
#include <iostream>
#include <valarray>

Canvas::Canvas(int width, int height) {
    this->width = width;
    this->height = height;
    for (int i = 0; i < width; i++)
        for (int j = 0; j < height; j++)
            canvas[i][j] = ' ';
}


void Canvas::DrawCircle(int x, int y, int ray, char ch) {
    int thickness = 1;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++)
            if ((pow(x - i, 2) + pow(y - j, 2) <= ray * ray) &&
                ((pow(x - i + thickness, 2) + pow(y - j + thickness, 2) >= ray * ray) ||
                 (pow(x - i - thickness, 2) + pow(y - j - thickness, 2) >= ray * ray) ||
                 (pow(x - i + thickness, 2) + pow(y - j - thickness, 2) >= ray * ray) ||
                 (pow(x - i - thickness, 2) + pow(y - j + thickness, 2) >= ray * ray)) )
                canvas[i][j] = ch;
    }

}



void Canvas::FillCircle(int x, int y, int ray, char ch){

    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++)
            if (pow(x-i, 2) + pow(y-j, 2) <= ray*ray)
                canvas[i][j] = ch;
    }

}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch){
    for (int i = left; i < right; i++) {
        canvas[top][i] = ch;
        canvas[bottom][i] = ch;
    }

    for (int i = top; i <= bottom; i++) {
        canvas[i][right] = ch;
        canvas[i][left] = ch;
    }
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch){
    for (int i = top; i <= bottom; i++)
        for (int j = left; j <= right; j++)
            canvas[i][j] = ch;
}

void Canvas::SetPoint(int x, int y, char ch){
    canvas[x][y] = ch;
}

void Canvas::DrawLine(int x0, int y0, int x1, int y1, char ch){
    int dx = abs(x1 - x0);
    int sx = x0 < x1 ? 1 : -1;
    int dy = -abs(y1 - y0);
    int sy = y0 < y1 ? 1 : -1;
    int error = dx + dy;

    while (true) {
        canvas[x0][y0] = ch;
        if (x0 == x1 && y0 == y1) break;
        int e2 = 2 * error;
        if (e2 >= dy) {
            if (x0 == x1) break;
            error = error + dy;
            x0 = x0 + sx;
        }
        if (e2 <= dx) {
            if (y0 == y1) break;
            error = error + dx;
            y0 = y0 + sy;
        }
    }
}


void Canvas::Print() {

    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++)
            std::cout << canvas[i][j] << " ";
        std::cout << std::endl;
    }
}

void Canvas::Clear(){
    for (int i = 0; i < width; i++)
        for (int j = 0; j < height; j++)
            canvas[i][j] = ' ';
}

