#include "objectCharacteristics3.h";

class Person4 {

};
class Person41 {
	int mA;
};
class Person42 {
	int mA;
	static int mB;
	static void func() {};
};

int Person42::mB = 0;

class Person43 {
	int mA;
	static int mB;
	void func() {}
};

class Person44 {
public:
	int age;
	Person44(int age) {
		// this 作用
		// 1. 解决命名冲突
		this->age = age;
	}
	// 用别名 表示返回的还是原来的对象，而不是创建一个新的对象
	Person44& personAddAge(Person44& p) {
		this->age += p.age;
		return *this;
	}
	void func1() {
		cout << "func1 空函数" << endl;
	}
	void func2() {
		cout << "func2 age = " << age << endl; // this.age
	}
};

void person4Test01() {
	Person4 p;
	// c++会给每个空对象分配1个内存空间，是为了区分空对象的内存位置，每个空对象应该有独一无二的内存空间
	cout << "sizeof p = " << sizeof p << endl; // 1

	Person41 p2;
	cout << "sizeof p2 = " << sizeof p2 << endl; // 4

	Person42 p3;
	cout << "sizeof p3 = " << sizeof p3 << endl; // 4 静态不属于对象

	Person43 p4;
	cout << "sizeof p4 = " << sizeof p4 << endl; // 4 成员变量和成员函数是分开存储的
}

void person4Test02() {
	Person44 p1(18);

	cout << "p1年龄：" << p1.age << endl;

	Person44 p2(20);
	p2.personAddAge(p1).personAddAge(p1);

	cout << "p2年龄：" << p2.age << endl;

	// 空指针
	Person44* p3 = NULL;
	p3->func1();
	// p3->func2(); // 奔了 无法访问 NULL -> age
}

// 常函数
class Person45 {
public:
	int age;
	mutable int age2; // 表示这是个特殊的值，常函数和常对象中可以修改
	// this指针的本质是指针常量，指向不能修改，指向的值可以修改 相当于  Person45 * cont this
	void showPerson() const // 常函数  相当于 const Person45 * cont this, 指针指向的值不能修改
	{
		// age = 100; // const Person45
		// this = NULL; // const this

		this->age2 = 100; // 因为有了mutable
	}

	void showPerson2() {
		this->age = 100;
		this->age2 = 200;
	}
};

void person4Test03() {
	// 常对象
	const Person45 p;
	// p.age = 1000; // 报错 不能修改 因为p是常对象
	p.age2 = 2000; // 可以修改，因为age2有mutable修饰

	p.showPerson();
	// p.showPerson2(); // 报错 常对象只能调用常函数
}

// 友元
class Building {
	// 此类下的visit2是我的好朋友，可以访问我的卧室（private属性）
	//friend void HASFriend::visit2();
	// 此方法是我的好朋友，可以访问我的卧室（private属性）
	friend void goodFriend(Building& building);
	// 此类是我的好朋友，可以访问我的卧室（private属性）
	friend class GoodFriends;
	
public:
	Building() :sittingRoom("客厅"), bedRoom("卧室") {

	}
	string sittingRoom; // 客厅
private:
	string bedRoom; // 卧室
};

// 全局函数做友元
void goodFriend(Building& building) {
	cout << "朋友goodFriend访问：" << building.sittingRoom << endl;
	cout << "朋友goodFriend访问：" << building.bedRoom << endl; // 好朋友可以访问
}

// 类做友元
class GoodFriends {
public:
	GoodFriends() {
		building = new Building; // 在堆区创建对象
	}
	void visit() {
		cout << "好朋友GoodFriends访问：" << building->sittingRoom << endl;
		cout << "好朋友GoodFriends访问：" << building->bedRoom << endl;
	}
	Building* building;
};

// 成员函数做友元
class HASFriend {
public:
	HASFriend() {
		building = new Building; // 在堆区创建对象
	}

	void visit() {
		cout << "好朋友HasFriend访问：" << building->sittingRoom << endl;
		// cout << "好朋友访问：" << building->bedRoom << endl; 不能访问
	}
	void visit2() {
		cout << "好朋友HasFriend访问：" << building->sittingRoom << endl;
		// 发现这是VC6.0的一个经典BUG，是VC6.0对友元函数的支持不够，同时跟namespace也有关系。 
		// cout << "好朋友HasFriend访问：" << building->bedRoom << endl;
	}
	Building* building;
};
void person4Test04() {
	Building b;
	goodFriend(b);

	GoodFriends fr;
	fr.visit();

	HASFriend hfr;
	hfr.visit();
	hfr.visit2();
}


void objectCharacteristics3() {
	person4Test01();
	person4Test02();
	person4Test03();
	person4Test04();



}