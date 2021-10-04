#include <iostream>
using namespace std;
#include <string>;
// ���麯���ͳ�����
class Base { // ֻҪ��һ�����麯�����������ǳ�����

// �������ص㣺
	// �޷�ʵ��������
	// �������û����д���麯����Ҳ�ǳ����࣬Ҳ����ʵ��������

public:
	// = 0 ����Ǵ��麯��
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
	// Base a; // eror �޷�ʵ��������
	// Son b; // error �������û����д���麯����Ҳ�ǳ����࣬Ҳ����ʵ��������
	Base* c = new Son2;
	c->func();
}
// ʵս

class AbstractDrinking {
public:
	// ��ˮ
	virtual void boil() = 0;
	// ����
	virtual void blew() = 0;
	// ���뱭��
	virtual void pourInCup() = 0;
	// ��������
	virtual void putSomething() = 0;

	// ������Ʒ
	void makeDrink() {
		boil();
		blew();
		pourInCup();
		putSomething();
	}
};

class Coffee :public AbstractDrinking {
	// ��ˮ
	void boil() {
		cout << "��ũ��ɽȪ" << endl;
	}
	// ����
	void blew() {
		cout << "���ݿ���" << endl;
	}
	// ���뱭��
	void pourInCup() {
		cout << "���뱭��" << endl;
	}
	// ��������
	void putSomething() {
		cout << "����ţ�̺���" << endl;
	}
};

class Tea :public AbstractDrinking {
	// ��ˮ
	void boil() {
		cout << "����Ȫˮ" << endl;
	}
	// ����
	void blew() {
		cout << "���ݲ�Ҷ" << endl;
	}
	// ���뱭��
	void pourInCup() {
		cout << "���뱭��" << endl;
	}
	// ��������
	void putSomething() {
		cout << "��������" << endl;
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