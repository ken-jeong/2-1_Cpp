#include <iostream>
#include "Rect.h"
using namespace std;

Rect::Rect(int w, int h) : width(w), height(h) {}

void Rect::draw() {
    Shape::draw();
    cout << "Rect (width: " << width << ", height: " << height << ")" << endl;
}