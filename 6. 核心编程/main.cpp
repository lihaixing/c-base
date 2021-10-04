#include <iostream>
using namespace std;
#include <string>
#include "global.h";
#include "stack.h";
#include "quote.h";
#include "advanced_fun.h";
#include "classAndObject.h";
#include "objectCharacteristics.h";
#include "object.h";
#include "objectCharacteristics3.h";
#include "objectCharacteristics4.h";
#include "extend.h";

void main() {
	goto FLAG;
	// 全局区
	global();

	// 栈区和堆区
	stack();

	// 别名
	quote();

	// 函数高级
	advanced_fun();

	// 类和对象
	classAndObject();

	// 类和对象 - 对象特性 - 构造、析造函数
	objectCharacteristics();

	// 类和对象 - 对象特性 - 深拷贝 初始化 静态成员
	objectCharacteristics2();

	// 类和对象 - 对象特性 - this
	objectCharacteristics3();

	// 类和对象 - 对象特性 - 运算符重载
	objectCharacteristics4();

FLAG:
	// 类和对象 - 对象特性 - 继承
	classExtend();

	system("pause");
	return;
}