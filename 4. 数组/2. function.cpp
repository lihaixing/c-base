#include <iostream>
#include "function.h" // 与头文件关联起来
using namespace std;


void swap(int a, int b) {
	int temp;
	temp = a;
	a = b;
	b = temp;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
}


/* 函数
* 语法：
*
* 返回值类型 函数名 (参数列表)
* {
*	函数体语句
*	return 表达式
* }
*/
int add(int num1, int num2) // num1 num2 形参
{
	int total = num1 + num2;
	return total;
}

// 值传递
// 实现两个数字交换
// 没有返回值 就是void
void swapString(string str1, string str2) {
	string temp;
	temp = str1;
	str1 = str2;
	str2 = temp;
}


/*
函数声明：告诉编译器函数名称以及如何调用函数，函数的主体可以单独定义
函数声明可以多次，但是函数的定义只能一次
*/
int max(int a, int b); // 函数的声明

int max(int a, int b) { // 函数的定义
	return a > b ? a : b;
}