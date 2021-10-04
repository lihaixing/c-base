#include <iostream>
using namespace std;
#include <string>;
// 纯虚函数和抽象类
class Base { // 只要有一个纯虚函数，这个类就是抽象类

// 抽象类特点：
	// 无法实例化对象
	// 子类如果没有重写纯虚函数，也是抽象类，也不能实例化对象

public:
	// = 0 这就是纯虚函数
	virtual void func() = 0;
};

class Son :public Base {

};
class Son2 :public Base {
public:
	void func() {
		cout << "son2 func" << endl;
	}
};

void test512() {
	// Base a; // eror 无法实例化对象
	// Son b; // error 子类如果没有重写纯虚函数，也是抽象类，也不能实例化对象
	Base* c = new Son2;
	c->func();
}
// 实战

class AbstractDrinking {
public:
	// 煮水
	virtual void boil() = 0;
	// 冲泡
	virtual void blew() = 0;
	// 倒入杯中
	virtual void pourInCup() = 0;
	// 加入作料
	virtual void putSomething() = 0;

	// 制作饮品
	void makeDrink() {
		boil();
		blew();
		pourInCup();
		putSomething();
	}
};

class Coffee :public AbstractDrinking {
	// 煮水
	void boil() {
		cout << "煮农夫山泉" << endl;
	}
	// 冲泡
	void blew() {
		cout << "冲泡咖啡" << endl;
	}
	// 倒入杯中
	void pourInCup() {
		cout << "倒入杯中" << endl;
	}
	// 加入作料
	void putSomething() {
		cout << "加入牛奶和糖" << endl;
	}
};

class Tea :public AbstractDrinking {
	// 煮水
	void boil() {
		cout << "煮扩泉水" << endl;
	}
	// 冲泡
	void blew() {
		cout << "冲泡茶叶" << endl;
	}
	// 倒入杯中
	void pourInCup() {
		cout << "倒入杯中" << endl;
	}
	// 加入作料
	void putSomething() {
		cout << "加入柠檬" << endl;
	}
};

void doWork(AbstractDrinking * abs) {
	abs->makeDrink();
	delete abs;
}

void test513() {
	doWork(new Coffee);

	Tea t;
	AbstractDrinking& d = t;
	d.makeDrink();
}
int main() {
	test512();
	test513();
	system("pause");
	return 0;
}