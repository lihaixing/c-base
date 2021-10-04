#include <iostream>
using namespace std;
#include <string>
#include "global.h"

// ȫ�ֱ���
int g_a = 1;
int g_b = 2;

// const���ε�ȫ�ֱ���
const int c_g_a = 1;
const int c_g_b = 2;

void global() {
	// �ֲ�����
	int a = 1;
	int b = 2;

	cout << "�ֲ�����a�ĵ�ַ��" << (int)&a << endl;
	cout << "�ֲ�����b�ĵ�ַ��" << (int)&b << endl;

	cout << "ȫ�ֱ���g_a�ĵ�ַ��" << (int)&g_a << endl;
	cout << "ȫ�ֱ���g_b�ĵ�ַ��" << (int)&g_b << endl;

	// ��̬����
	static int s_a = 1;
	static int s_b = 2;
	cout << "��̬����s_a�ĵ�ַ��" << (int)&s_a << endl;
	cout << "��̬����s_b�ĵ�ַ��" << (int)&s_b << endl;

	// ����

	// const���εľֲ�����
	const int c_a = 1;
	const int c_b = 2;

	// �ַ�������
	cout << "�ַ�������abc�ĵ�ַ��" << (int)&"abc" << endl;
	cout << "constȫ�ֱ���c_g_a�ĵ�ַ��" << (int)&c_g_a << endl;
	cout << "constȫ�ֱ���c_g_b�ĵ�ַ��" << (int)&c_g_b << endl;
	cout << "const�ֲ�����c_a�ĵ�ַ��" << (int)&c_a << endl;
	cout << "const�ֲ�����c_b�ĵ�ַ��" << (int)&c_b << endl;

	// ���Կ���ȫ�ֱ�����ַ�;ֲ�������ַ���Զ������һ���ط�
	/*
	�ֲ�����a�ĵ�ַ��4192304
	�ֲ�����b�ĵ�ַ��4192292
	const�ֲ�����c_a�ĵ�ַ��4192280
	const�ֲ�����c_b�ĵ�ַ��4192268

	ȫ�ֱ���g_a�ĵ�ַ��10731572
	ȫ�ֱ���g_b�ĵ�ַ��10731576
	��̬����s_a�ĵ�ַ��10731588
	��̬����s_b�ĵ�ַ��10731592
	�ַ�������abc�ĵ�ַ��10722920
	constȫ�ֱ���c_g_a�ĵ�ַ��10731580
	constȫ�ֱ���c_g_b�ĵ�ַ��10731584

	*/
}