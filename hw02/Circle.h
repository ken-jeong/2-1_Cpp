#ifndef CIRCLE_H
#define CIRCLE_H
#include "Shape.h"

class Circle : public Shape {
    int radius;
public:
    Circle(int r = 1);
protected:
    virtual void draw() override;
};

#endif