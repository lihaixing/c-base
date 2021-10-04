#include "objectCharacteristics.h"

// ����ĳ�ʼ��������
// ���캯��/���캯��
// Ĭ�Ͼ��У�ֻ�����ǿ�ʵ�֣�д�˾ͻḲ�������ʵ��
class Person2 {
	string name;
	int age;

public:

	string getName() {
		return name;
	}
	//1 ���캯��
	//û�з���ֵ������дvoid
	//��������������ͬ
	//�����в��������Է�������
	//��������ʱ�����캯�����Զ����ã���ֻ����һ��

	//���캯�� ��ͨ���� ��������
	Person2() {
		cout << "Person() ������" << endl;
		name = "lihaixing";
		age = 32;
	};
	Person2(string sname) {
		cout << "Person(string sname) ������" << endl;
		name = sname;
	};

	Person2(int sage) {
		cout << "Person2(int sage) ������" << endl;
		age = sage;
	};
	Person2(string sname, int sage) {
		cout << "Person(string sname, int sage) ������" << endl;
		name = sname;
		age = sage;
	};

	// �������캯��
	Person2(const Person2& p) {
		cout << "Person2(const Person2 &p) ������" << endl;
		name = p.name;
		age = p.age;
	};


	// 2 ���캯�� ��������Ĳ���
	//û�з���ֵ������дvoid
	//��������������ͬ,������ǰ��~
	//�������в����������Է�������
	//����������ʱ�����Զ����ã���ִֻ��һ��
	~Person2() {
		cout << "~Person2() ������" << endl;
	}
};

void doWork(Person2 p) { // ���õ�ʱ���൱���� Person2 p = p9

}

Person2 doWork2() {
	Person2 p;
	return p;
}

void objectCharacteristics() {
	const string line = "--------------------";
	// һ�����캯������
	//1. ���ŷ�
	Person2 p1; //ע������: ��Ҫ�ӣ������������������Ϊ��һ����������
	Person2 p2("lihaixing");
	Person2 p3(p2);
	cout << "p1��name��" << p1.getName() << endl;

	cout << line << endl;

	//2. ��ʾ��
	Person2 p4 = Person2();
	Person2 p5 = Person2("dangyanzi");
	Person2 p6 = Person2(p5);

	cout << line << endl;
	Person2(); // ע������: ������������ ִ����������ͷ��ڴ棬�������objectCharacteristics��������
	cout << "aaaaaa" << endl;

	// Person2(p5); // ע������: �����������������ÿ������캯�� ����������Ϊ Person2 p5

	// 3. ��ʽת����
	Person2 p7 = 20; // �൱�� p7 = Person2(20);
	// Person2 p8 = "abs"; // ��֪��ԭ�򣬻ᱨ��
	Person2 p9 = p6; // ��������

	cout << line << endl;

	doWork(p9); // ע������: �˴������ÿ������캯��

	cout << line << endl;

	Person2 p10 = doWork2(); // ע������: �˴������ÿ������캯��

	cout << line << endl;

	// �������캯�����ù���
	 
	//Ĭ������£�c++���������ṩ��������
	//1. Ĭ�Ϲ��캯�����޲Σ�������Ϊ�գ�
	//2. Ĭ�����캯�����޲Σ�������Ϊ�գ�
	//3. Ĭ�Ͽ������캯���������Խ���ֵ����

	//���ù���
	//1. ���û��ṩ�вι��캯����c++�����ṩĬ���޲ι��죬���ǻ��ṩĬ�Ͽ�������
	//2. ���û��ṩ�������캯����c++�����ṩ�������캯��




}