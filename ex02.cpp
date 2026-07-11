#include <iostream>
using namespace std;

class Adder {
protected:
	int add(int a, int b) { return a + b; }
};

class Subtractor {
protected:
	int minus(int a, int b) { return a - b; }
};

class Multiplier {
protected:
	int mul(int a, int b) { return a * b; }
};

class Divider {
protected:
	int div(int a, int b) { return a / b; }
};

class Calculator : public Adder, public Subtractor, public Multiplier, public Divider {
public:
	int calc(int& res, char op, int a, int b);
};

int Calculator::calc(int& res, char op, int a, int b) {
	switch (op) {
	case '+':
		res = add(a, b); break;
	case '-':
		res = minus(a, b); break;
	case '*':
		res = mul(a, b); break;
	case '/':
		if (b == 0) cout << "0으로 나눌 수 없습니다." << endl; return 0;
		res = div(a, b); break;
	default:
		cout << "연산자가 잘못 입력 되었습니다." << endl; return 0;
	}
	return 1;
}

int cint(string msg = "") {
	cout << msg << " 입력: ";
	int cint;
	cin >> cint;
	return cint;
}

char cins(string msg = "") {
	cout << msg << " 입력: ";
	char cins;
	cin >> cins;
	return cins;
}

int main() {
	Calculator c;
	int result;
	int flag;
	int op1;
	int op2;
	string oper;
	do {
		op1 = cint("피연산자1");
		op2 = cint("피연산자2");
		flag = c.calc(result, cins("연산자"), op1, op2);
	} while (flag == 0);
	cout << "입력 값: " << op1 << ", " << op2 << " 결과는 " << result << "입니다." << endl;
}
