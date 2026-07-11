#include <iostream>
using namespace std;

class Circle {
protected:
	int radius;
public:
	Circle(int r);
	double getArea();
	int getRadius();
	void setRadius(int r);
	void circleShow();
};

Circle::Circle(int r=1) {
	radius = r;
	cout << "반지름 " << radius << " 원 생성" << endl;
}

double Circle::getArea() {
	return 3.14 * radius * radius;
}

int Circle::getRadius() {
	return radius;
}

void Circle::setRadius(int r) {
	radius = r;
}

void Circle::circleShow() {
	cout << "원의 면적: " << getRadius() << endl;
}

class ColorCircle : public Circle {
	string color;
public:
	string getColor();
	void setColor(string c);
	void colorCircleShow();
};

string ColorCircle::getColor() {
	return color;
}

void ColorCircle::setColor(string c) {
	color = c;
}

void ColorCircle::colorCircleShow() {
	cout << "원의 색: " << getColor() << ", ";
	circleShow();
}

bool equals(ColorCircle c1, ColorCircle c2) {
	if (c1.getRadius() == c2.getRadius()) {
		if (c1.getColor() == c2.getColor()) {
			return true;
		}
	}
	return false;
}

int cint(string msg = "") {
	int tmp;
	do {
		cout << msg << " 입력: ";
		cin >> tmp;
	} while (tmp <= 0);
	return tmp;
}

string cins(string msg = "") {
	cout << msg << " 입력: ";
	string tmp;
	cin >> tmp;
	return tmp;
}

int main() {
	ColorCircle arr[2];

	arr[0].setRadius(cint("arr[0]'s Radius"));
	arr[0].setColor(cins("arr[0]'s Color"));

	arr[1].setRadius(cint("arr[1]'s Radius"));
	arr[0].setColor(cins("arr[1]'s Color"));

	arr[0].circleShow();
	arr[1].circleShow();

	if (equals(arr[0], arr[1])) {
		cout << "두 개의 ColorCircle이 같습니다." << endl;
	}
	else {
		cout << "두 개의 ColorCircle이 같지 않습니다." << endl;
	}
}
