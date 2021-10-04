#include "objectCharacteristics4.h";
// 运算符重载

// 一、加号运算符
class PersonA {
public:
	int a;
	int b;
	// 成员函数重载
	/*PersonA operator+(PersonA& p) {
		PersonA temp;
		temp.a = this->a + p.a;
		temp.b = this->b + p.b;
		return temp;
	}*/

	// 一般不会用成员函数重载左移运算符，无法实现 cout在左侧
	//void operator<<() {}
};

// 全局函数重载
PersonA operator+(PersonA& p1, PersonA& p2) {
	PersonA temp;
	temp.a = p1.a + p2.a;
	temp.b = p1.b + p2.b;
	return temp;
}
// 重载
PersonA operator+(PersonA& p1, int x) {
	PersonA temp;
	temp.a = p1.a + x;
	temp.b = p1.b + x;
	return temp;
}

void PersonATest01() {
	PersonA p1;
	p1.a = 10;
	p1.b = 20;
	PersonA p2;
	p2.a = 15;
	p2.b = 25;

	// 相当于 p3 = p1.operator+(p2) 或者 p3 = operator+(p1,p2)
	PersonA p3 = p1 + p2;
	PersonA p4 = p1 + 10;

	cout << "p3.a = " << p3.a << endl;
	cout << "p3.b = " << p3.b << endl;

	cout << "p4.a = " << p4.a << endl;
	cout << "p4.b = " << p4.b << endl;
}

//只能利用全局函数重载左移运算符 ,简写 cout << p
// 如果访问私有属性，可以将其加到友元中
ostream& operator <<(ostream& out, PersonA& p) {
	out << "a = " << p.a << endl;
	out << "b = " << p.b << endl;
	return out; // 可以链式输出
}
// 左移运算符
void  PersonATest02() {
	PersonA p5;
	p5.a = 10;
	p5.b = 20;
	cout << p5 << endl;
}


class MyInt {
	friend ostream& operator <<(ostream& out, MyInt& myInt);
public:
	MyInt() {
		num = 0;
	}
	// 前置++重载
	MyInt& operator ++() {
		num++;
		return *this;
	}
	// 后置++重载 int是占位参数，用于区分前置后置
	MyInt operator ++(int) { // 不能 是别名，因为curr是局部对象，执行完会小时
		MyInt curr = *this;
		num++;
		return curr;
	}
private:
	int num;
};

ostream& operator <<(ostream& out, MyInt& myInt) {

	out << myInt.num;
	return out; // 可以链式输出
}
void PersonATest03() {
	MyInt a;
	cout << "a = " << ++(++a) << endl;

	MyInt b;
	// TODO 不知道原因
	// cout << "b = " << b++ << endl;
	cout << "b = " << b << endl;
}

// 赋值运算符
class PersonB {
public:
	PersonB() {
		age = new int(10);
	}
	PersonB(int sage) {
		age = new int(sage);
	}

	int* age;
	~PersonB() {
		cout << "~PersonB" << endl;
		if (age != NULL) {
			delete age;
			age = NULL;
		}
	}
	// 赋值运算符
	PersonB& operator=(PersonB& p) {
		if (age != NULL) {
			delete age;
			age = NULL;
		}
		age = new int(*p.age);
		return *this;
	}
	// 相等运算符 == !=
	bool operator==(PersonB& p) {
		if (*this->age == *p.age) {
			return true;
		}
		return false;
	}
	// 函数调用运算符 ()  仿函数
	void operator()(string str) {
		cout << str << endl;
	}
};

void PersonATest04() {
	PersonB p1(10);
	PersonB p2(20);
	PersonB p3(20);
	p3 = p1 = p2;
	cout << "p1的年龄：" << *p1.age << endl;
	cout << "p2的年龄：" << *p2.age << endl; // 堆区内存释放后就访问不到了
	cout << "p3的年龄：" << *p3.age << endl; // 堆区内存释放后就访问不到了
	//相等运算符
	PersonB p4(30);
	cout << "p1 == p2 : " << (p1 == p2) << endl;
	cout << "p1 == p4 : " << (p1 == p4) << endl;
	//函数调用运算符 仿函数
	p4("abcd");
	//匿名函数对象
	PersonB()("abcd");
}

void objectCharacteristics4() {
	// 一、加号运算符
	PersonATest01();
	// 左移运算符
	PersonATest02();

	// ++运算符
	PersonATest03();

	// 赋值运算符
	PersonATest04();

}