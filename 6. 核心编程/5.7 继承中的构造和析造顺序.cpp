#include <iostream>
using namespace std;
#include <string>
class Base {
public:
	Base() {
		a = 1;
		cout << "Base 构造函数" << endl;
	}
	~Base() {
		cout << "~Base 析造函数" << endl;
	}

	void func() {
		cout << "Base func" << endl;
	}
	void func(int num) {
		cout << "Base func " << num << endl;
	}

	static void sfunc() {
		cout << "static base func" << endl;
	}
	int a;
	static int b;
};

int Base::b = 2;

class Son :public Base {
public:
	Son() {
		a = 2;
		cout << "Son 构造函数" << endl;
	}
	~Son() {
		cout << "~Son 析造函数" << endl;
	}

	void func() {
		cout << "Son func" << endl;
	}
	static void sfunc() {
		cout << "static Son func" << endl;
	}
	int a;
	static int b;
};

int Son::b = 4;

void test001() {
	//Base b;

	/*
	Base 构造函数
	Son 构造函数
	~Son 析造函数
	~Base 析造函数
	*/
	Son s;
	cout << "子类中的属性 s.a = " << s.a << endl; // 2
	cout << "父类中的属性 s.a = " << s.Base::a << endl; // 2
	s.func(); // Son func
	s.Base::func(); // Base func
	// s.func(100); // error 会隐藏父类中的同名的属性和方法，必须加作用域才能执行
	s.Base::func(100); // Base func


	// 静态属性
	Son s2;
	cout << "s2.b = " << s2.b << endl; // 4
	cout << "s2.Base::b  = " << s2.Base::b << endl; // 2
	cout << "Base::b = " << Base::b << endl; // 2
	cout << "Son::Base::b = " << Son::Base::b << endl; // 2  Son下的base下的b
	cout << "Son::b = " << Son::b << endl; // 4

	s2.sfunc();
	s2.Base::sfunc();
	Base::sfunc();
	Son::Base::sfunc();
	Son::sfunc();
}
int main() {
	test001();

	system("pause");
	return 1;

}