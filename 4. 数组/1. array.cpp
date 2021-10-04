#include <iostream>
using namespace std;
#include "array.h"
#include <string>

void Array() {
	string line = "-----------------分割线-----------------";
	// 数组 一个集合，里面放相同类型的元素
	// 由连续的内存位置组成的

	// 一维数组定义方式 三种
	// 1. 数据类型 数组名[数组长度]
	// 2. 数据类型 数组名[数组长度] = {值1,值2,...}
	// 3. 数据类型 数组名[] = {值1,值2,...}
	int arr[3];
	arr[0] = 1;
	arr[1] = 2;
	// cout << arr[2] << endl; // 类似于 -83223525
	arr[2] = 3;
	cout << "arr[2] = " << arr[2] << endl;

	int arr2[] = { 1,2,3,4,5 };

	cout << line << endl;

	// 一维数组数组名
	// 用途：
	// 1. 统计整个数组在内存中的长度
	// 2. 获取数组在内存中的首地址  可用int转成10进制
	cout << "arr2占用内存大小 = " << (sizeof arr2) << endl; // 20
	cout << "arr2的首地址 = \t\t" << arr2 << " , " << (int)arr2 << endl; // 默认16进制 004FFD10, 5242128
	cout << "arr2[0]的首地址 = \t\t" << &arr2[0] << " , " << (int)&arr2[0] << endl; // 16进制 004FFD10, 5242128
	cout << "arr2[1]的首地址 = \t\t" << &arr2[1] << " , " << (int)&arr2[1] << endl; // 16进制 004FFD14, 5242132

	cout << "arr2元素个数：" << (sizeof arr2) / (sizeof arr2[0]) << endl;

	cout << line << endl;

	// 二维数组 4种表示方式
	// 1. 数据类型 数组名[行数][列数];
	// 2. 数据类型 数组名[行数][列数] = {{1,2,3},{4,5,6}};
	// 3. 数据类型 数组名[行数][列数] = {1,2,3,4,5,6};
	// 4. 数据类型 数组名[][列数] = {1,2,3,4,5,6};

	// 2行3列
	int arr3[2][3];
	arr3[0][0] = 1;
	arr3[0][1] = 2;
	arr3[0][2] = 3;
	arr3[1][0] = 4;
	arr3[1][1] = 5;
	arr3[1][2] = 6;

	int arr4[2][3] = { {1,2,3},{4,5,6} };
	int arr5[2][3] = { 1,2,3,4,5,6 };  // 系统自己能猜出来
	int arr6[][3] = { 1,2,3,4,5,6 };  // 系统自己能猜出来
	cout << arr5 << endl;

	cout << line << endl;

	// 二维数组数组名
	// 用途：
	// 1. 统计整个数组在内存中的长度
	// 2. 获取数组在内存中的首地址  可用int转成10进制

	cout << "arr6占用内存大小 = " << (sizeof arr6) << endl; // 24 = 4 * 6 
	cout << "arr6[0]占用内存大小 = " << (sizeof arr6[0]) << endl; // 12 
	cout << "arr6[0][0]占用内存大小 = " << (sizeof arr6[0][0]) << endl; // 4
	cout << "arr6的首地址 = \t\t" << arr6 << " , " << (int)arr6 << endl; // 默认16进制 005BF9BC, 6027708
	cout << "arr6[0]的首地址 = \t\t" << arr6[0] << " , " << (int)arr6[0] << endl; // 16进制 005BF9BC, 6027708
	cout << "arr6[0][0]的首地址 = \t\t" << &arr6[0][0] << " , " << (int)&arr6[0][0] << endl; // 16进制 005BF9BC, 6027708
	cout << "arr6[1]的首地址 = \t\t" << arr6[1] << " , " << (int)arr6[1] << endl; // 16进制 005BF9C8, 6027720

	cout << "arr6的行数 = " << (sizeof arr6) / (sizeof arr6[0]) << endl;
	cout << "arr6的列数 = " << (sizeof arr6[0]) / (sizeof arr6[0][0]) << endl;
}