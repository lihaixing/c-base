#include <iostream>
using namespace std;
#include "struct.h"
#include <string>

// �ṹ��
// �﷨�� struct �ṹ���� {�ṹ���Ա������}

// ����ѧ����������
struct Student {
	string name;
	int age;
	int score;
};

void printStudent(Student s) {
	s.age = 100;
	cout << "��ӡ��ѧ����������" << s.name << endl;
}

void printStudent2(Student * p) {
	p->age = 99;
	cout << "ͨ��ָ���ӡ��ѧ����������" << p->name << endl;
}

void printStudent3(const Student* p) {
	// p->age = 99; // �����޸���
	cout << "ͨ��ָ���ӡ��ѧ����������" << p->name << endl;
}

void funStruct() {

	// һ��ͨ�����ʹ���ѧ�����ַ�ʽ
	// 1. struct Student s1

	struct Student s1;
	s1.name = "����";
	s1.age = 30;
	s1.score = 100;

	// cout << "s1 = " << s1 << endl;
	cout << "s1������ = " << s1.name << endl;

	// 2. struct Student s1 = {}
	struct Student s2 = {
		"lisi",31,90
	};

	cout << "s2������ = " << s2.name << endl;

	// 3. �������͵�ʱ��˳�� ����
	struct Student2 {
		string name;
		int age;
		int score;
	}s3;
	s3.name = "wangwu";
	s3.age = 33;
	s3.score = 80;
	cout << "s3������ = " << s3.name << endl;

	// struct�ؼ��� ������ʱ�����ʡ��, ����ṹ���ʱ����ʡ��
	Student2 my = { "lisi",31,90 };

	// �����ṹ������
	Student2 my2[2] = { {"����",30,100},{"lisi",31,90} };
	// ��ֵ
	my2[1].age = 35;

	cout << "sizeof my2[0] = " << sizeof my2[0] << endl; // 36
	int my2Length = (sizeof my2) / (sizeof my2[0]);
	for (int i = 0; i < my2Length; i++) {
		cout << "my2[" << i << "]������ = " << my2[i].age << endl;
	}

	// �����ṹ��ָ��
	// ͨ��ָ����ʽṹ���еĳ�Ա
	Student my3 = { "lihaixing",32,100 };

	Student* p = &my3;
	cout << "p = " << p << endl; // 012FFB8C
	// ��������
	cout << "my3��name = " << p->name << endl;
	cout << "my3��name = " << (*p).name << endl;

	// �ġ��ṹ��Ƕ��
	struct Teacher {
		int id;
		string name;
		int age;
		struct Student student;
	};

	Teacher t;
	t.age = 60;
	t.id = 101;
	t.name = "Mr Wang";
	t.student.age = 30;
	t.student.name = "haixing";
	t.student.score = 80;

	// �塢�ṹ������������
	// 1.ֵ����
	printStudent(my3);
	cout << "my3��age = "<< my3.age << endl; // 32
	// 2.��ַ����
	printStudent2(&my3);
	cout << "my3��age = " << my3.age << endl; // 99 


	// �����ṹ���е�const
	// ʹ�ó�������ָ�봫�οɼ����ڴ濪����ֻռ4���ֽ�
	Student my4 = { "zhangsan",20,89 };


}