#include <iostream>
using namespace std;
#include <string>;



class Animal { // 虚基类
public:
	Animal() {
		cout << "Animal构造" << endl;
	}

	virtual void walk() {
		cout << "动物在走步" << endl;
	}
	string* name;

	//virtual ~Animal() { // 加了virtual，子类就走析造了
	//	cout << "Animal析造" << endl;
	//}
	virtual ~Animal() = 0; // 纯虚析
};

Animal::~Animal(){
	cout << "Animal纯析造" << endl;
}

class Cat : public Animal { // 虚基类
public:

	Cat(string m_name) {
		cout << "Cat构造函数" << endl;
		name = new string(m_name);
	}

	void walk() {
		cout << *name << "猫在走步" << endl;
	}
	// 因为animal是Animal类型，所以不会走到这里
	~Cat() {
		if (name != NULL) {
			cout << "Cat析造函数" << endl;
			delete name;
			name = NULL;
		}
	}
};

void test001() {
	/*Animal构造
	Cat构造函数
	TOM猫在走步
	Animal析造*/
	Animal* animal = new Cat("TOM");
	animal->walk();
	delete animal;
}

void main() {
	test001();
	system("pause");
	return;
}