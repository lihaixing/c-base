#include <iostream>
using namespace std;
#include <string>
class Base1 {
public:
	int a;
	Base1() {
		a = 1;
	}
};

class Base2 {
public:
	int b;
	int a;
	Base2() {
		b = 2;
		a = 0;
	}
};

class Son : public Base1, public Base2 {
public:
	int c;
	int d;
	int b;
	Son() {
		b = 5;
		c = 3;
		d = 4;
	}
};
void test001() {
	Son s;
	cout << "sizeof s = " << sizeof s << endl; // 20
	// cout << "s.a = " << s.a << endl; // error a不知道是哪个base
	cout << "s.a = " << s.Base1::a << endl;
	cout << "s.b = " << s.b << endl;
}

void main() {
	test001();
	system("pause");
	return;
}