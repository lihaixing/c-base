#include "objectCharacteristics.h"

// 对象的初始化和清理
// 构造函数/析造函数
// 默认就有，只不过是空实现，写了就会覆盖这个空实现
class Person2 {
	string name;
	int age;

public:

	string getName() {
		return name;
	}
	//1 构造函数
	//没有返回值，不用写void
	//函数名和类名相同
	//可以有参数，可以发生重载
	//创建对象时，构造函数会自动调用，且只调用一次

	//构造函数 普通构造 拷贝构造
	Person2() {
		cout << "Person() 调用了" << endl;
		name = "lihaixing";
		age = 32;
	};
	Person2(string sname) {
		cout << "Person(string sname) 调用了" << endl;
		name = sname;
	};

	Person2(int sage) {
		cout << "Person2(int sage) 调用了" << endl;
		age = sage;
	};
	Person2(string sname, int sage) {
		cout << "Person(string sname, int sage) 调用了" << endl;
		name = sname;
		age = sage;
	};

	// 拷贝构造函数
	Person2(const Person2& p) {
		cout << "Person2(const Person2 &p) 调用了" << endl;
		name = p.name;
		age = p.age;
	};


	// 2 析造函数 进行清理的操作
	//没有返回值，不用写void
	//函数名和类名相同,在名称前加~
	//不可以有参数，不可以发生重载
	//对象在销毁时，会自动调用，且只执行一次
	~Person2() {
		cout << "~Person2() 调用了" << endl;
	}
};

void doWork(Person2 p) { // 调用的时候，相当于先 Person2 p = p9

}

Person2 doWork2() {
	Person2 p;
	return p;
}

void objectCharacteristics() {
	const string line = "--------------------";
	// 一、构造函数调用
	//1. 括号法
	Person2 p1; //注意事项: 不要加（），否则编译器会认为是一个函数声明
	Person2 p2("lihaixing");
	Person2 p3(p2);
	cout << "p1的name：" << p1.getName() << endl;

	cout << line << endl;

	//2. 显示法
	Person2 p4 = Person2();
	Person2 p5 = Person2("dangyanzi");
	Person2 p6 = Person2(p5);

	cout << line << endl;
	Person2(); // 注意事项: 匿名函数调用 执行完后，立即释放内存，而不会等objectCharacteristics整个函数
	cout << "aaaaaa" << endl;

	// Person2(p5); // 注意事项: 不能用匿名函数调用拷贝构造函数 编译器会认为 Person2 p5

	// 3. 隐式转换法
	Person2 p7 = 20; // 相当于 p7 = Person2(20);
	// Person2 p8 = "abs"; // 不知道原因，会报错
	Person2 p9 = p6; // 拷贝构造

	cout << line << endl;

	doWork(p9); // 注意事项: 此代码会调用拷贝构造函数

	cout << line << endl;

	Person2 p10 = doWork2(); // 注意事项: 此代码会调用拷贝构造函数

	cout << line << endl;

	// 二、构造函数调用规则
	 
	//默认情况下，c++编译器会提供三个函数
	//1. 默认构造函数（无参，函数体为空）
	//2. 默认析造函数（无参，函数体为空）
	//3. 默认拷贝构造函数，对属性进行值拷贝

	//调用规则：
	//1. 若用户提供有参构造函数，c++不再提供默认无参构造，但是会提供默认拷贝构造
	//2. 若用户提供拷贝构造函数，c++不会提供其他构造函数




}