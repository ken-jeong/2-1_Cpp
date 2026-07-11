#ifndef RECT_H
#define RECT_H
#include "Shape.h"

class Rect : public Shape {
    int width, height;
public:
    Rect(int w = 1, int h = 1);
protected:
    virtual void draw() override;
};

#endif