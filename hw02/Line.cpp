#include <iostream>
#include "Line.h"
using namespace std;

Line::Line(int l) : length(l) {}

void Line::draw() {
    Shape::draw();
    cout << "Line (length: " << length << ")" << endl;
}