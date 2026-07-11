#include <iostream>
#include "Circle.h"
using namespace std;

Circle::Circle(int r) : radius(r) {}

void Circle::draw() {
    Shape::draw();
    cout << "Circle (radius: " << radius << ")" << endl;
}