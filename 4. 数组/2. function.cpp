#include <iostream>
#include "function.h" // ��ͷ�ļ���������
using namespace std;


void swap(int a, int b) {
	int temp;
	temp = a;
	a = b;
	b = temp;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
}


/* ����
* �﷨��
*
* ����ֵ���� ������ (�����б�)
* {
*	���������
*	return ���ʽ
* }
*/
int add(int num1, int num2) // num1 num2 �β�
{
	int total = num1 + num2;
	return total;
}

// ֵ����
// ʵ���������ֽ���
// û�з���ֵ ����void
void swapString(string str1, string str2) {
	string temp;
	temp = str1;
	str1 = str2;
	str2 = temp;
}


/*
�������������߱��������������Լ���ε��ú�����������������Ե�������
�����������Զ�Σ����Ǻ����Ķ���ֻ��һ��
*/
int max(int a, int b); // ����������

int max(int a, int b) { // �����Ķ���
	return a > b ? a : b;
}