#include <iostream>
using namespace std;
#include <string>
#include "advanced_fun.h";

int func(int a = 10, int b = 12) {
	return a + b;
}
// b��Ĭ�ϲ��� cҲ�ñ�����,���涼����
int func1(int a, int b = 12, int c = 2) {
	return a + b + c;
}
// ���������������Ĭ�ϲ�����������ʵ�־Ͳ�����Ĭ�ϲ�����
// ������ʵ��ֻ��һ����Ĭ�ϲ���
int func3(int a, int b = 1, int c = 2);
int func3(int a, int b, int c) {
	return a + b + c;
}

// ������ռλ����
// �﷨������ֵ���� ���������������ͣ�{}
void func4(int a, int) {
	cout << "a = " << a << endl;
}

// ռλ����������Ĭ�ϲ��� ֻ�ܴ��ҵ���
void func5(int a, int = 10) {
	cout << "a = " << a << endl;
}


// �������أ�������������ͬ����߿ɸ�����
// ����������
// 1. ͬһ����������
// 2. ����������ͬ
 //3. �����������Ͳ�ͬ�����߸�����ͬ������˳��ͬ
 //ע�⣺��������ֵ������Ϊ���ص�����
// ����ʱc++���ܶԺ������ı�  func6_int_int��func6_string_int
int func6(int a, int b) {
	return a + b;
}
int func6(string a, int b) {
	return b;
}
int func6(string a, int b, int c) {
	//cout << b + c << endl;
	return b + c;
}
int func6(int c, string a, int b) {
	return b;
}

// ��������ע������
// �������Ͳ�һ����Ҳ����
void func7(int& a) {  // int& a = a �Ϸ�, int& a = 10 ���Ϸ�
	cout << "func7(int& a)" << endl;
}
void func7(const int& a) { // const int& a = 10 �Ϸ�
	cout << "func7(const int& a)" << endl;
}

void myTest(int a) {
	cout << "myTest: " << a << endl;
}
// �����д�����
void func8(int a, void(*p)(int) = myTest) {
	p(a);
}


void advanced_fun() {
	// ����Ĭ�ϲ���
	int b = func();
	int c = func(1, 2);
	cout << "b = " << b << endl; // 22
	cout << "c = " << c << endl; // 3

	int c3 = func3(1, 2, 3);
	cout << "c3 = " << c3 << endl; // 3

	// ������ռλ����
	func4(5, 6);

	// ������ռλ������Ĭ�ϲ�����ռλ�����Ϳ��Բ��ô���
	func5(5);

	// ��������
	int c4 = func6(1, 2);
	int c5 = func6("abc", 2);
	int c6 = func6("abc", 2, 4);
	int c7 = func6(2, "abc", 4);
	cout << c4 << c5 << c6 << c7 << endl; // 3264

	int c8 = 10;
	func7(c8); // func7(int& a)
	func7(10); // func7(const int& a)

	func8(9);
	func8(9, myTest);
}




