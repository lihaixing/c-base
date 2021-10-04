#include <iostream>
using namespace std;
#include <string>
#include "array.h" 
#include "function.h" // 引用swap函数
#include "pointer.h" 
#include "struct.h"
#include "structDemo.h"
#include "helloworld.h"
#include "dataType.h"
#include "calculate.h"

int main() {

	string line = "-----------------分割线-----------------";

	cout << line << endl;

	goto START;
	// hello world
	helloworld();
	
	cout << line << endl;


	// 数据类型
	dataType();

	cout << line << endl;

START:
	// 运算符 流程 循环
	calculate();

	goto FLAG;

	cout << line << endl;
	// 数组
	Array();

	cout << line << endl;

	// 函数调用
	cout << "1 + 2 = " << add(1, 2) << endl; // 1 2 是实参

	// 函数的分文件编写
	// 1. 创建.h后缀名的头文件
	// 2. 创建.cpp后缀名的源文件
	// 3. 在头文件中写函数的声明
	// 4. 在源文件中写函数的定义 并include 头文件
	// 5. 在主体文件中 include .h头文件，就可以调用了
	swap(12, 10);

	cout << line << endl;

	// 指针方法调用 
	pointer();

	cout << line << endl;

	// 结构体
	funStruct();

	// 结构体案例
	structDemo();

	cout << line << endl;

FLAG:

	system("pause");

	return 0;
}