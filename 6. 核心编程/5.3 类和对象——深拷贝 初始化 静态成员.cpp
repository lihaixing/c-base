#include "object.h"

class Person3 {

public:
	string name ="lihaixing";
	int age;
	int* height;
	static int borth;

	void func() {
		borth = 2000;
		cout << "��ͨ����func����" << endl;
	}
	// ��̬��Ա����
	// ���ж�����ͬһ������
	// ��̬��Ա����ֻ�ܷ��ʾ�̬��Ա����
	static void static_func() {
		// name = "good"; // ���� ���ܷ��ʷǾ�̬��������Ϊ��֪���ĵ����ĸ������name
		borth = 1001;
		cout << "��̬��Աsage = " << borth << endl;
		cout << "��̬��Աstatic_func����" << endl;
	}
private:
	static void static_func2() {
		cout << "static_func2" << endl;
	}
public:
	// ��ʼ���б����
	Person3() :name("liahixing"), age(30), height(new int(178)) {

	};
	Person3(string sname, int sage, int sheight) :name(sname), age(sage), height(new int(sheight)) {

	};


	Person3(int sage) {
		cout << "Person3(int sage) ������" << endl;
		age = sage;
	};

	Person3(int sage, int sheight) {
		cout << "Person3(int sage ,int sheight) ������" << endl;
		height = new int(sheight);
		age = sage;
	};

	// �������캯��
	Person3(const Person3& p) {
		cout << "Person2(const Person2 &p) ������" << endl;
		name = p.name;
		age = p.age;
		// height = p.height; // �༭��Ĭ�ϲ��� ����ǳ����
		height = new int(*p.height);
		// �������
	};
	~Person3() {
		cout << "~Person3() ������" << endl;
		if (height != NULL) {
			delete height;
			height = NULL;
		}
	}
};

int Person3::borth = 100;

void test01() {
	Person3 p1(18);
	//Person3 p2(p1); // ǳ����
	//cout << "p1�����䣺" << p1.age << endl;
	//cout << "p2�����䣺" << p2.age << endl;

	Person3 p3(20, 160);
	Person3 p4(p3); // �쳣���������ظ��ͷ�
	cout << "p3����ߣ�" << *p3.height << endl;
	cout << "p4����ߣ�" << *p4.height << endl;
	cout << "sizeof p4��" << sizeof p4 << endl; // 36

}
void test02() {
	Person3 p5;
	cout << "p5����ߣ�" << *p5.height << endl;
	Person3 p6("dangyanzi", 33, 160);
	cout << "p6����ߣ�" << *p6.height << endl;
}

void test03() {
	Person3 p;
	p.func();

	p.static_func();
	Person3::static_func();

	// p.static_func2(); // ˽�о�̬������
	// Person3::static_func2(); // ˽�о�̬������
}

void objectCharacteristics2() {
	const string line = "--------------------";
	// ��� �ڶ��������ڴ棬ʹ����Ҫ�ֶ��ͷ�
	test01();

	cout << line << endl;
	// ��ʼ���б�
	test02();

	// ��̬��Ա����
	test03();
}