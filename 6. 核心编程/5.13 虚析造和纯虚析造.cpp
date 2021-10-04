#include <iostream>
using namespace std;
#include <string>;



class Animal { // �����
public:
	Animal() {
		cout << "Animal����" << endl;
	}

	virtual void walk() {
		cout << "�������߲�" << endl;
	}
	string* name;

	//virtual ~Animal() { // ����virtual���������������
	//	cout << "Animal����" << endl;
	//}
	virtual ~Animal() = 0; // ������
};

Animal::~Animal(){
	cout << "Animal������" << endl;
}

class Cat : public Animal { // �����
public:

	Cat(string m_name) {
		cout << "Cat���캯��" << endl;
		name = new string(m_name);
	}

	void walk() {
		cout << *name << "è���߲�" << endl;
	}
	// ��Ϊanimal��Animal���ͣ����Բ����ߵ�����
	~Cat() {
		if (name != NULL) {
			cout << "Cat���캯��" << endl;
			delete name;
			name = NULL;
		}
	}
};

void test001() {
	/*Animal����
	Cat���캯��
	TOMè���߲�
	Animal����*/
	Animal* animal = new Cat("TOM");
	animal->walk();
	delete animal;
}

void main() {
	test001();
	system("pause");
	return;
}