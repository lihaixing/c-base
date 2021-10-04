#include <iostream>
using namespace std;
#include <string>
#include "quote.h";

// ��������
void swap(int &a,int &b) {
	int temp = a;
	a = b;
	b = temp;
}

// ��������ֵ
int& test01() {
	int a = 10;
		return a;
}

// ��������ֵ
int& test02() {
	static int a = 10; // ��̬�����ŵ�ȫ����������������Ż��ͷ�
	return a;
}

void quote() {
	// ���ã������������
	// �﷨��&���� = ԭ��

	// a��bָ�����ͬһ���ڴ�
	int a = 10; 
	int& b = a;
	int c = a;
	cout << "a = " << a << endl; // 10
	cout << "b = " << b << endl; // 10
	cout << "c = " << c << endl; // 10

	cout << "a�ĵ�ַ = " << &a << endl; // 001BF9F0
	cout << "b�ĵ�ַ = " << &b << endl; // 001BF9F0
	cout << "c�ĵ�ַ = " << &c << endl; // 001BF9D8

	b = 11;
	cout << "a = " << a << endl; // 11
	cout << "b = " << b << endl; // 11
	cout << "c = " << c << endl; // 10

	// ����ע������
	 
	// ���ñ����ʼ��
	// int& c; // ����ģ����븳ֵ

	// ��ʼ���󲻿��Ը���
	int e = 20;
	int& d = a;
	d = e; // ���Ǹ�ֵ���������Ǹ��ı������൱�ڰ�c��ֵ����d, Ҳ���Ǹ���e
	cout << "a = " << a << endl; // 20 

	// ��������������
	// �������β�����ʵ�Σ�����Ҫ��ָ����
	int a1 = 10;
	int b1 = 20;
	swap(a1, b1);
	cout << "a1 = " << a1 << endl;
	cout << "b1 = " << b1 << endl;

	// ��������������ֵ
	// 1. ��Ҫ���ؾֲ�����������
	int c1 = test01();
	cout << "c1 = " << c1 << endl; // 10
	cout << "c1 = " << c1 << endl; // 10

	int& c2 = test01(); // 23456543
	cout << "&c2 = " << c2 << endl; // 10
	cout << "&c2 = " << c2 << endl; // 2059831688 ��Ϊֵ�ᱻ�ͷ�

	// 2. �����ĵ��ÿ�����Ϊ��ֵ��ֻҪ���ص�������
	int& c3 = test02(); // 23456543
	cout << "&c3 = " << c3 << endl; // 10
	cout << "&c3 = " << c3 << endl; // 10 ��̬�����ŵ�ȫ�����򣬲��ᱻ�ͷ�

	test02() = 1000; // �൱�� &x = 1000  x��a�ı���
	cout << "&c3 = " << c3 << endl; // 1000
	cout << "&c3 = " << c3 << endl; // 1000

	// ���õı���
	// ���õı�����c++�ڲ�ʵ����һ��ָ�볣��, ��Ϊ��ʼ�����ܸ���
	// ָ�볣����ָ�����޸ģ���ָ���ֵ�����޸�

	int* const a2 = &a; // ָ�볣��
	int& b2 = a;
	cout << "a2 = " << *a2 << endl; // 20
	cout << "b2 = " << b2 << endl; // 20

	// a2 = &a; // ����
	// b2 = a  // ���Ǹ�ֵ�����Ǳ����޸�

	*a2 = 21;
	b2 = 21;
	cout << "a2 = " << *a2 << endl; // 21
	cout << "b2 = " << b2 << endl; // 21

	// ����ʹ�ó���
	// ���ñ�����һ��Ϸ����ڴ�ռ�
	 
	// int& a3 = 10; // ���� 10�ǳ���
	 
	// ����const�󣬱༭���������޸�Ϊ 
	// int temp =10; const int & a3 =temp
	const int& a3 = 10;
	// a3 = 20  // ���󣬲����޸���	
}