#include "Canvas.h"
#include <iostream>

int main() {

    Canvas* c = new Canvas(25, 60);

    c->DrawCircle(7, 8, 6, 'x');
    c->DrawRect(30, 17, 45, 24, '+');
    c->DrawLine(24, 0, 0, 49, '#');
    c->Print();

    std::cin.get();
    c->Clear();

    c->FillRect(30, 17, 45, 24, '+');
    c->FillCircle(10, 30, 8, 'o');
    c->DrawLine(24, 11, 0, 16, '/');

    c->Print();

    std::cin.get();
    c->Clear();

    c->Print();
}