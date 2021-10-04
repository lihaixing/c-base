#include <iostream>
using namespace std;
#include <string>
#include "quote.h";

// 别名参数
void swap(int &a,int &b) {
	int temp = a;
	a = b;
	b = temp;
}

// 别名返回值
int& test01() {
	int a = 10;
		return a;
}

// 别名返回值
int& test02() {
	static int a = 10; // 静态变量放到全局区，程序运行完才会释放
	return a;
}

void quote() {
	// 引用：给变量起别名
	// 语法：&别名 = 原名

	// a和b指向的是同一块内存
	int a = 10; 
	int& b = a;
	int c = a;
	cout << "a = " << a << endl; // 10
	cout << "b = " << b << endl; // 10
	cout << "c = " << c << endl; // 10

	cout << "a的地址 = " << &a << endl; // 001BF9F0
	cout << "b的地址 = " << &b << endl; // 001BF9F0
	cout << "c的地址 = " << &c << endl; // 001BF9D8

	b = 11;
	cout << "a = " << a << endl; // 11
	cout << "b = " << b << endl; // 11
	cout << "c = " << c << endl; // 10

	// 引用注意事项
	 
	// 引用必须初始化
	// int& c; // 错误的，必须赋值

	// 初始化后不可以更改
	int e = 20;
	int& d = a;
	d = e; // 这是赋值操作，不是更改别名，相当于把c的值给了d, 也就是给了e
	cout << "a = " << a << endl; // 20 

	// 引用做函数参数
	// 可以让形参修饰实参，不需要用指针了
	int a1 = 10;
	int b1 = 20;
	swap(a1, b1);
	cout << "a1 = " << a1 << endl;
	cout << "b1 = " << b1 << endl;

	// 引用做函数返回值
	// 1. 不要返回局部变量的引用
	int c1 = test01();
	cout << "c1 = " << c1 << endl; // 10
	cout << "c1 = " << c1 << endl; // 10

	int& c2 = test01(); // 23456543
	cout << "&c2 = " << c2 << endl; // 10
	cout << "&c2 = " << c2 << endl; // 2059831688 因为值会被释放

	// 2. 函数的调用可以作为左值，只要返回的是引用
	int& c3 = test02(); // 23456543
	cout << "&c3 = " << c3 << endl; // 10
	cout << "&c3 = " << c3 << endl; // 10 静态变量放到全局区域，不会被释放

	test02() = 1000; // 相当于 &x = 1000  x是a的别名
	cout << "&c3 = " << c3 << endl; // 1000
	cout << "&c3 = " << c3 << endl; // 1000

	// 引用的本质
	// 引用的本质在c++内部实现是一个指针常量, 因为初始化后不能更改
	// 指针常量：指向不能修改，但指向的值可以修改

	int* const a2 = &a; // 指针常量
	int& b2 = a;
	cout << "a2 = " << *a2 << endl; // 20
	cout << "b2 = " << b2 << endl; // 20

	// a2 = &a; // 报错
	// b2 = a  // 这是赋值，不是别名修改

	*a2 = 21;
	b2 = 21;
	cout << "a2 = " << *a2 << endl; // 21
	cout << "b2 = " << b2 << endl; // 21

	// 引用使用场景
	// 引用必须是一块合法的内存空间
	 
	// int& a3 = 10; // 错误 10是常量
	 
	// 加上const后，编辑器将代码修改为 
	// int temp =10; const int & a3 =temp
	const int& a3 = 10;
	// a3 = 20  // 错误，不可修改了	
}