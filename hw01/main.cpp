#include <iostream>
using namespace std;

class Shape {
public:
    virtual void draw() {
        cout << "--Shape--";
    }
};

class Circle : public Shape {
private:
    int radius;
public:
    Circle(int r = 1) : radius(r) {}
    virtual void draw() override {
        Shape::draw();
        cout << "Circle (radius: " << radius << ")" << endl;
    }
};

class Rect : public Shape {
private:
    int width, height;
public:
    Rect(int w = 1, int h = 1) : width(w), height(h) {}
    virtual void draw() override {
        Shape::draw();
        cout << "Rect (width: " << width << ", height: " << height << ")" << endl;
    }
};

int main() {
    int radius, width, height;

    do {
        cout << "radius: ";
        cin >> radius;
    } while (radius <= 0);
    Circle circle(radius);

    do {
        cout << "width: ";
        cin >> width;
    } while (width <= 0);
    do {
        cout << "height: ";
        cin >> height;
    } while (height <= 0);
    Rect rect(width, height);

    Shape* pShape = &circle;
    pShape->draw();

    pShape = &rect;
    pShape->draw();

    return 0;
}
