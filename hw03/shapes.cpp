#include <iostream>
#include <fstream>
#include <limits>
#include <string>

using namespace std;

class Shape {
protected:
    Shape* next;
public:
    Shape() : next(nullptr) {}
    virtual ~Shape() = default;

    void setNext(Shape* n) { next = n; }
    Shape* getNext() const { return next; }

    virtual void print(ostream& os) const = 0;
};
inline ostream& operator<<(ostream& os, const Shape& s) {
    s.print(os);
    return os;
}

class Line : public Shape {
    int length;
public:
    Line(int l) : length(l) {}
    void print(ostream& os) const override {
        os << "Line (length: " << length << ")";
    }
};
class Circle : public Shape {
    int radius;
public:
    Circle(int r) : radius(r) {}
    void print(ostream& os) const override {
        os << "Circle (radius: " << radius << ")";
    }
};
class Rectangle : public Shape {
    int width, height;
public:
    Rectangle(int w, int h) : width(w), height(h) {}
    void print(ostream& os) const override {
        os << "Rectangle (width: " << width << ", height: " << height << ")";
    }
};

int getInt(const string& prompt, int min = numeric_limits<int>::min(), int max = numeric_limits<int>::max()) {
    int value;
    while (true) {
        cout << prompt;
        if (cin >> value && value >= min && value <= max) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "[Error] 올바른 범위 내의 정수로 다시 입력하세요.\n";
    }
}

int main() {
    Shape* head = nullptr;
    Shape* tail = nullptr;

    while (true) {
        cout << "\n[Menu]\n" << "1. Line\n2. Circle\n3. Rect\n4. 종료\n";
        int choice = getInt("번호를 선택하세요: ", 1, 4);
        if (choice == 4) break;

        Shape* newShape = nullptr;
        switch (choice) {
        case 1: {
            int len = getInt("길이를 입력하세요: ", 1);
            newShape = new Line(len);
            break;
        }
        case 2: {
            int r = getInt("반지름을 입력하세요: ", 1);
            newShape = new Circle(r);
            break;
        }
        case 3: {
            int w = getInt("너비를 입력하세요: ", 1);
            int h = getInt("높이를 입력하세요: ", 1);
            newShape = new Rectangle(w, h);
            break;
        }
        }

        // 리스트에 추가
        if (!head) head = tail = newShape;
        else { tail->setNext(newShape); tail = newShape; }
    }

    // 파일 저장
    ofstream ofs("objects.txt");
    for (Shape* cur = head; cur; cur = cur->getNext()) ofs << *cur << '\n';
    ofs.close();

    // 파일 읽어서 화면 출력
    ifstream ifs("objects.txt");
    string line;
    cout << "\n[objects.txt]\n";
    while (getline(ifs, line)) cout << line << '\n';

    // 메모리 해제
    while (head) {
        Shape* tmp = head;
        head = head->getNext();
        delete tmp;
    }
    return 0;
}
