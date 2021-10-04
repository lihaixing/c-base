#include <iostream>
using namespace std;
#include <string>
// ��̳�

class Animal { // �����
public:
	void speak() {
		cout << "������˵��" << endl;
	}
	virtual void walk() {
		cout << "�������߲�" << endl;
	}
};

class Cat : public Animal { // �����
public:
	void speak() {
		cout << "è��˵��" << endl;
	}
	void walk() {
		cout << "è���߲�" << endl;
	}
};

// ��ַ����ˣ���Ȼ��cat ���� ��ַ�ڱ���׶ξ�ȷ����
// ���ǵ�ַ��󶨣���virtual �麯�������е�ʱ����ȷ����ַ
void doSpeak(Animal& animal) {
	animal.speak();  // ������˵��
}

void doWalk(Animal& animal) {
	animal.walk();  // è���߲�
}

// ��̬��̬
/*
* 1. �м̳й�ϵ
* 2. ��д������麯��������virtual��д�ɲ�д
*/

void test001() {

	// sizeof

	cout << "sizeof Animal = " << sizeof Animal << endl;  // ������1�� ���������麯������4
	Cat cat;  // Cat���� ���� Animal���� ������֮���������ת��
	doSpeak(cat); // ������˵��
	cat.speak(); // è��˵��

	doWalk(cat); // è���߲�

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