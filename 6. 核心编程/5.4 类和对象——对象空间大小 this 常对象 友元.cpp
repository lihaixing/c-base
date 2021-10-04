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
		// this ����
		// 1. ���������ͻ
		this->age = age;
	}
	// �ñ��� ��ʾ���صĻ���ԭ���Ķ��󣬶����Ǵ���һ���µĶ���
	Person44& personAddAge(Person44& p) {
		this->age += p.age;
		return *this;
	}
	void func1() {
		cout << "func1 �պ���" << endl;
	}
	void func2() {
		cout << "func2 age = " << age << endl; // this.age
	}
};

void person4Test01() {
	Person4 p;
	// c++���ÿ���ն������1���ڴ�ռ䣬��Ϊ�����ֿն�����ڴ�λ�ã�ÿ���ն���Ӧ���ж�һ�޶����ڴ�ռ�
	cout << "sizeof p = " << sizeof p << endl; // 1

	Person41 p2;
	cout << "sizeof p2 = " << sizeof p2 << endl; // 4

	Person42 p3;
	cout << "sizeof p3 = " << sizeof p3 << endl; // 4 ��̬�����ڶ���

	Person43 p4;
	cout << "sizeof p4 = " << sizeof p4 << endl; // 4 ��Ա�����ͳ�Ա�����Ƿֿ��洢��
}

void person4Test02() {
	Person44 p1(18);

	cout << "p1���䣺" << p1.age << endl;

	Person44 p2(20);
	p2.personAddAge(p1).personAddAge(p1);

	cout << "p2���䣺" << p2.age << endl;

	// ��ָ��
	Person44* p3 = NULL;
	p3->func1();
	// p3->func2(); // ���� �޷����� NULL -> age
}

// ������
class Person45 {
public:
	int age;
	mutable int age2; // ��ʾ���Ǹ������ֵ���������ͳ������п����޸�
	// thisָ��ı�����ָ�볣����ָ�����޸ģ�ָ���ֵ�����޸� �൱��  Person45 * cont this
	void showPerson() const // ������  �൱�� const Person45 * cont this, ָ��ָ���ֵ�����޸�
	{
		// age = 100; // const Person45
		// this = NULL; // const this

		this->age2 = 100; // ��Ϊ����mutable
	}

	void showPerson2() {
		this->age = 100;
		this->age2 = 200;
	}
};

void person4Test03() {
	// ������
	const Person45 p;
	// p.age = 1000; // ���� �����޸� ��Ϊp�ǳ�����
	p.age2 = 2000; // �����޸ģ���Ϊage2��mutable����

	p.showPerson();
	// p.showPerson2(); // ���� ������ֻ�ܵ��ó�����
}

// ��Ԫ
class Building {
	// �����µ�visit2���ҵĺ����ѣ����Է����ҵ����ң�private���ԣ�
	//friend void HASFriend::visit2();
	// �˷������ҵĺ����ѣ����Է����ҵ����ң�private���ԣ�
	friend void goodFriend(Building& building);
	// �������ҵĺ����ѣ����Է����ҵ����ң�private���ԣ�
	friend class GoodFriends;
	
public:
	Building() :sittingRoom("����"), bedRoom("����") {

	}
	string sittingRoom; // ����
private:
	string bedRoom; // ����
};

// ȫ�ֺ�������Ԫ
void goodFriend(Building& building) {
	cout << "����goodFriend���ʣ�" << building.sittingRoom << endl;
	cout << "����goodFriend���ʣ�" << building.bedRoom << endl; // �����ѿ��Է���
}

// ������Ԫ
class GoodFriends {
public:
	GoodFriends() {
		building = new Building; // �ڶ�����������
	}
	void visit() {
		cout << "������GoodFriends���ʣ�" << building->sittingRoom << endl;
		cout << "������GoodFriends���ʣ�" << building->bedRoom << endl;
	}
	Building* building;
};

// ��Ա��������Ԫ
class HASFriend {
public:
	HASFriend() {
		building = new Building; // �ڶ�����������
	}

	void visit() {
		cout << "������HasFriend���ʣ�" << building->sittingRoom << endl;
		// cout << "�����ѷ��ʣ�" << building->bedRoom << endl; ���ܷ���
	}
	void visit2() {
		cout << "������HasFriend���ʣ�" << building->sittingRoom << endl;
		// ��������VC6.0��һ������BUG����VC6.0����Ԫ������֧�ֲ�����ͬʱ��namespaceҲ�й�ϵ�� 
		// cout << "������HasFriend���ʣ�" << building->bedRoom << endl;
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