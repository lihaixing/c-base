#include <iostream>
using namespace std;
#include <string>
#include "stack.h";

// ��Ҫ����һ���ֲ�������ַ����Ϊ���ͷ�
int* func() {
	int a = 1;
	return &a;
}

int* func2() {
	// ��new���ڴ濪�ٵ�����
	// a��ַ��ջ�ϣ���ַ�ϵ�ֵ�ڶ���
	int *a = new int(1);
	return a;
}

void func3() {
	// �ڶ�����������
	int* arr = new int[10];
	for (int i = 0; i < 10; i++) {
		arr[i] = i+100;
	}
	// �ͷ�����
	delete[] arr;
}

void stack() {
	int *p= func();
	cout << "ͨ��*p�鿴 a = " << *p << endl; // a = 1 ������ֻ����һ�α���
	cout << "ͨ��*p�ٴβ鿴 a = " << *p << endl; // a = 2065271176

	int* p2 = func2();
	cout << "ͨ��*p2�鿴 a = " << *p2 << endl; // 1
	cout << "ͨ��*p2�ٴβ鿴 a = " << *p2 << endl; // 1  // ���������ݲ����Զ��ͷ�

	// �ͷŶ����ڴ�
	delete p2;
	// cout << "�ͷ�*p2�ٴβ鿴 a = " << *p2 << endl; // ����
	
	// �ڶ�����������
	func3();
}