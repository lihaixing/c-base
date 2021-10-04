#include "object.h"

class Person3 {

public:
	string name ="lihaixing";
	int age;
	int* height;
	static int borth;

	void func() {
		borth = 2000;
		cout << "普通函数func调用" << endl;
	}
	// 静态成员函数
	// 所有对象共享同一个函数
	// 静态成员函数只能访问静态成员变量
	static void static_func() {
		// name = "good"; // 错误 不能访问非静态变量，因为不知道改的是哪个对象的name
		borth = 1001;
		cout << "静态成员sage = " << borth << endl;
		cout << "静态成员static_func调用" << endl;
	}
private:
	static void static_func2() {
		cout << "static_func2" << endl;
	}
public:
	// 初始化列表操作
	Person3() :name("liahixing"), age(30), height(new int(178)) {

	};
	Person3(string sname, int sage, int sheight) :name(sname), age(sage), height(new int(sheight)) {

	};


	Person3(int sage) {
		cout << "Person3(int sage) 调用了" << endl;
		age = sage;
	};

	Person3(int sage, int sheight) {
		cout << "Person3(int sage ,int sheight) 调用了" << endl;
		height = new int(sheight);
		age = sage;
	};

	// 拷贝构造函数
	Person3(const Person3& p) {
		cout << "Person2(const Person2 &p) 调用了" << endl;
		name = p.name;
		age = p.age;
		// height = p.height; // 编辑器默认操作 这是浅拷贝
		height = new int(*p.height);
		// 这是深拷贝
	};
	~Person3() {
		cout << "~Person3() 调用了" << endl;
		if (height != NULL) {
			delete height;
			height = NULL;
		}
	}
};

int Person3::borth = 100;

void test01() {
	Person3 p1(18);
	//Person3 p2(p1); // 浅拷贝
	//cout << "p1的年龄：" << p1.age << endl;
	//cout << "p2的年龄：" << p2.age << endl;

	Person3 p3(20, 160);
	Person3 p4(p3); // 异常，堆区的重复释放
	cout << "p3的身高：" << *p3.height << endl;
	cout << "p4的身高：" << *p4.height << endl;
	cout << "sizeof p4：" << sizeof p4 << endl; // 36

}
void test02() {
	Person3 p5;
	cout << "p5的身高：" << *p5.height << endl;
	Person3 p6("dangyanzi", 33, 160);
	cout << "p6的身高：" << *p6.height << endl;
}

void test03() {
	Person3 p;
	p.func();

	p.static_func();
	Person3::static_func();

	// p.static_func2(); // 私有静态函数，
	// Person3::static_func2(); // 私有静态函数，
}

void objectCharacteristics2() {
	const string line = "--------------------";
	// 深拷贝 在堆区开辟内存，使用完要手动释放
	test01();

	cout << line << endl;
	// 初始化列表
	test02();

	// 静态成员函数
	test03();
}