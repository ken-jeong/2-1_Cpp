#ifndef LINE_H
#define LINE_H
#include "Shape.h"

class Line : public Shape {
    int length;
public:
    Line(int l = 1);
protected:
    virtual void draw() override;
};

#endif