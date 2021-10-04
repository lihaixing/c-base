#include <iostream>
using namespace std;
#include <string>
// 虚继承

class Animal { // 虚基类
public:
	void speak() {
		cout << "动物在说话" << endl;
	}
	virtual void walk() {
		cout << "动物在走步" << endl;
	}
};

class Cat : public Animal { // 虚基类
public:
	void speak() {
		cout << "猫在说话" << endl;
	}
	void walk() {
		cout << "猫在走步" << endl;
	}
};

// 地址早绑定了，虽然是cat 但是 地址在编译阶段就确定了
// 除非地址晚绑定，用virtual 虚函数，运行的时候再确定地址
void doSpeak(Animal& animal) {
	animal.speak();  // 动物在说话
}

void doWalk(Animal& animal) {
	animal.walk();  // 猫在走不
}

// 动态多态
/*
* 1. 有继承关系
* 2. 重写父类的虚函数，子类virtual可写可不写
*/

void test001() {

	// sizeof

	cout << "sizeof Animal = " << sizeof Animal << endl;  // 本来是1， 但是有了虚函数成了4
	Cat cat;  // Cat类型 赋给 Animal类型 ，父子之间可以类型转换
	doSpeak(cat); // 动物在说话
	cat.speak(); // 猫在说话

	doWalk(cat); // 猫在走不

/*
class Animal    size(4) :
+-- -
0 | {vfptr}
+ -- -

Animal::$vftable@ :
| &Animal_meta
| 0
0 | &Animal::walk
*/

/*
class Cat       size(4):
		+---
 0      | +--- (base class Animal)
 0      | | {vfptr}
		| +---
		+---

Cat::$vftable@:
		| &Cat_meta
		|  0
 0      | &Cat::walk
*/
}

void main() {
	test001();
	system("pause");
	return;
}