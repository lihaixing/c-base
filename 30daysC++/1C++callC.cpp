#include <iostream>
#include<string>
using namespace std;
#include "1.h"
// 按c语言编译 
// 如果是声明，可以只给声明加
// 应用：第三方库可能是c语言写的
extern "C" int func(int a, int b =2) {
	return a + b;
}

extern "C" void  other();

int main() {
	func(1);
	func(1, 2);
	func(3, 4);
	other();
	// c/c++混用
	cout << sum(10, 11) << endl;
	cout << delta(10, 11) << endl;

	getchar();
	return 0;
}