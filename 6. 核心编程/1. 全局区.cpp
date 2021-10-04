#include <iostream>
using namespace std;
#include <string>
#include "global.h"

// 全局变量
int g_a = 1;
int g_b = 2;

// const修饰的全局变量
const int c_g_a = 1;
const int c_g_b = 2;

void global() {
	// 局部变量
	int a = 1;
	int b = 2;

	cout << "局部变量a的地址：" << (int)&a << endl;
	cout << "局部变量b的地址：" << (int)&b << endl;

	cout << "全局变量g_a的地址：" << (int)&g_a << endl;
	cout << "全局变量g_b的地址：" << (int)&g_b << endl;

	// 静态变量
	static int s_a = 1;
	static int s_b = 2;
	cout << "静态变量s_a的地址：" << (int)&s_a << endl;
	cout << "静态变量s_b的地址：" << (int)&s_b << endl;

	// 常量

	// const修饰的局部变量
	const int c_a = 1;
	const int c_b = 2;

	// 字符串常量
	cout << "字符串常量abc的地址：" << (int)&"abc" << endl;
	cout << "const全局变量c_g_a的地址：" << (int)&c_g_a << endl;
	cout << "const全局变量c_g_b的地址：" << (int)&c_g_b << endl;
	cout << "const局部变量c_a的地址：" << (int)&c_a << endl;
	cout << "const局部变量c_b的地址：" << (int)&c_b << endl;

	// 可以看出全局变量地址和局部变量地址差很远，不在一个地方
	/*
	局部变量a的地址：4192304
	局部变量b的地址：4192292
	const局部变量c_a的地址：4192280
	const局部变量c_b的地址：4192268

	全局变量g_a的地址：10731572
	全局变量g_b的地址：10731576
	静态变量s_a的地址：10731588
	静态变量s_b的地址：10731592
	字符串常量abc的地址：10722920
	const全局变量c_g_a的地址：10731580
	const全局变量c_g_b的地址：10731584

	*/
}