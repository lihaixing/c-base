#include <iostream>
using namespace std;
#include <string>
#include "advanced_fun.h";

int func(int a = 10, int b = 12) {
	return a + b;
}
// b有默认参数 c也得必须有,后面都得有
int func1(int a, int b = 12, int c = 2) {
	return a + b + c;
}
// 如果函数声明有了默认参数，函数的实现就不能有默认参数了
// 声明和实现只能一个有默认参数
int func3(int a, int b = 1, int c = 2);
int func3(int a, int b, int c) {
	return a + b + c;
}

// 函数的占位参数
// 语法：返回值类型 函数名（数据类型）{}
void func4(int a, int) {
	cout << "a = " << a << endl;
}

// 占位参数可以有默认参数 只能从右到左
void func5(int a, int = 10) {
	cout << "a = " << a << endl;
}


// 函数重载：函数名可以相同，提高可复用性
// 满足条件：
// 1. 同一个作用域下
// 2. 函数名称相同
 //3. 函数参数类型不同，或者个数不同，或者顺序不同
 //注意：函数返回值不能作为重载的条件
// 编译时c++可能对函数名改变  func6_int_int、func6_string_int
int func6(int a, int b) {
	return a + b;
}
int func6(string a, int b) {
	return b;
}
int func6(string a, int b, int c) {
	//cout << b + c << endl;
	return b + c;
}
int func6(int c, string a, int b) {
	return b;
}

// 函数重载注意事项
// 以下类型不一样，也可以
void func7(int& a) {  // int& a = a 合法, int& a = 10 不合法
	cout << "func7(int& a)" << endl;
}
void func7(const int& a) { // const int& a = 10 合法
	cout << "func7(const int& a)" << endl;
}

void myTest(int a) {
	cout << "myTest: " << a << endl;
}
// 参数中传函数
void func8(int a, void(*p)(int) = myTest) {
	p(a);
}


void advanced_fun() {
	// 函数默认参数
	int b = func();
	int c = func(1, 2);
	cout << "b = " << b << endl; // 22
	cout << "c = " << c << endl; // 3

	int c3 = func3(1, 2, 3);
	cout << "c3 = " << c3 << endl; // 3

	// 函数的占位参数
	func4(5, 6);

	// 函数的占位参数有默认参数，占位参数就可以不用传了
	func5(5);

	// 函数重载
	int c4 = func6(1, 2);
	int c5 = func6("abc", 2);
	int c6 = func6("abc", 2, 4);
	int c7 = func6(2, "abc", 4);
	cout << c4 << c5 << c6 << c7 << endl; // 3264

	int c8 = 10;
	func7(c8); // func7(int& a)
	func7(10); // func7(const int& a)

	func8(9);
	func8(9, myTest);
}




