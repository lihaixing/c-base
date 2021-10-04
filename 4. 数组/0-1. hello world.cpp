#include <iostream>
using namespace std;
#include "helloworld.h"
#include <string>

// 单行注释
/* 多行注释 */

#define day 7

void helloworld() {
	// 屏幕中输出hello world
	cout << "Hello world" << endl;

	/*
	* 变量
	* 作用：给内存空间起名，方便操作内存
	* 语法：数据类型 变量名 = 初始值
	*/
	int a = 10;
	a = 12;
	cout << "a = " << a << endl;

	/*
	* 常量
	* 作用：记录程序不能更改的数据
	* 1 宏常量：#define 常量名 常量值
	*		通常在文件上方定义，表示一个常量
	* 2 const修饰：const 数据类型 常量名 = 常量值
	*		通常在变量定义前加const，修饰该变量为常量，不可修改
	*/
	cout << "一周总共有" << day << "天" << endl;

	const int month = 12;

	cout << "一年总共有" << month << "月" << endl;

	/*
	* 关键字（标识符）
	* 定义变量和常量的时候，不要用关键字
	*/

	/*标识符（变量常量）命名规则
	1 不能是关键字
	2 只能由字母、数字、下划线组成
	3 第一个字符必须是字母或下划线
	4 标识符中字母区分大小写
	*/
}