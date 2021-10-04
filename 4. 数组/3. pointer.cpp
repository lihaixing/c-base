#include <iostream>
#include "pointer.h" // 与头文件关联起来
using namespace std;

void swapp(int* p1, int* p2) {
	int temp;
	temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

void pointer() {
	// 1. 指针：通过指针可以间接访问内存
	// 指针就是一个地址，把地址当变量
	// 语法：数据类型 * 指针变量名

	int a = 10;
	int* p; // 定义指针
	p = &a; // 用p记录变量a的地址

	cout << "a的地址 = " << &a << endl;
	cout << "指针p = " << p << endl;

	// 2. 使用指针：通过解引用的方式找到指针指向的内存
	// 	   找到了内存中的值，也可以修改
	// 语法 *p
	*p = 1000;
	cout << "a的值发生了改变：a = " << a << endl;

	// 3. 指针占用空间  32bit操作系统占用4个字节 64位占8个字节
	
	cout << "指针p占用空间 = " << sizeof p << endl;
	cout << "指针占用空间 = " << sizeof (int *) << endl;
	cout << "指针占用空间 = " << sizeof(float*) << endl;
	cout << "指针占用空间 = " << sizeof(double*) << endl;
	cout << "指针占用空间 = " << sizeof(char*) << endl;

	// 4. 空指针：指针变量指向内存中编号为0的空间
	// 用途：初始化指针变量，
	// 注意：空指针指向的内存是不能访问的

	// int* p2 = NULL;

	// *p2 = 200; // 异常 0-255之间的内存编号是系统占用的，因此不可以访问

	// 5. 野指针：指针变量指向的非法的内存空间

	 int* p3 = (int*)0x1100;  
	 cout << p3 << endl;
	 // cout << *p3 << endl; // 随便找个地址，没有权利操作此空间

	 // 6. const修饰指针
	 // const修饰指针 -- 常量指针
	 // const修饰常量 -- 指针常量
	 // const既修饰指针，也修饰常量

	 // 常量指针
	 // 特点：指针的指向可以修改，但指针指向的值不可以修改
	 int a1 = 10;
	 int b1 = 20;
	 const int* p4 = &a1;

	 // *p4 = 20; // 错误 指针指向的值不可以修改
	 p4 = &b1; // 正确 指针的指向可以修改

	 // 指针常量
	 // 特点: 指针的指向不可以修改，但指针指向的值可以修改
	 int* const p5 = &a1;
	 *p5 = 30; // 正确 指针指向的值可以修改
	 // p5 = &b1; // 错误 指针的指向不可以修改
	 cout << "a1 = " << a1 << endl;

	 // 既修饰指针，也修饰常量
	 // 特点：都不可以修改
	 const int* const p6 = &a1;
	 // *p6 = 30; // 错误 指针指向的值不可以修改
	 // p6 = &b1; // 错误 指针的指向不可以修改

	 // 指针和数组
	 // 利用指针访问数组中的元素
	 int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };
	 cout << "第一个元素：" << arr[0] << endl;
	 int* p7 = arr; // arr就是首地址
	 cout << "利用指针访问第一个元素：" << *p7 << endl;
	 p7++; // 让指针偏移4个字节
	 cout << "利用指针访问第二个元素：" << *p7 << endl;

	 int* p8 = arr;
	 for (int i = 0; i < 10; i++) {
		 cout << "遍历：" << *p8 << endl;
		 p8++;
	 }

	 // 指针和函数
	 // 地址传递
	 int a2 = 10;
	 int b2 = 20;
	 swapp(&a2, &b2);
	 cout << "a2 = " << a2 << endl;
	 cout << "b2 = " << b2 << endl;

}