#include <iostream>
using namespace std;
#include <string>
#include "stack.h";

// 不要返回一个局部变量地址，因为会释放
int* func() {
	int a = 1;
	return &a;
}

int* func2() {
	// 用new将内存开辟到堆区
	// a地址在栈上，地址上的值在堆区
	int *a = new int(1);
	return a;
}

void func3() {
	// 在堆区开辟数组
	int* arr = new int[10];
	for (int i = 0; i < 10; i++) {
		arr[i] = i+100;
	}
	// 释放数组
	delete[] arr;
}

void stack() {
	int *p= func();
	cout << "通过*p查看 a = " << *p << endl; // a = 1 编译器只做了一次保留
	cout << "通过*p再次查看 a = " << *p << endl; // a = 2065271176

	int* p2 = func2();
	cout << "通过*p2查看 a = " << *p2 << endl; // 1
	cout << "通过*p2再次查看 a = " << *p2 << endl; // 1  // 堆区的数据不能自动释放

	// 释放堆区内存
	delete p2;
	// cout << "释放*p2再次查看 a = " << *p2 << endl; // 报错
	
	// 在堆区开辟数组
	func3();
}