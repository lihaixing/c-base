#include <iostream>
using namespace std;
#include "dataType.h"
#include <string>

void dataType() {
	// �������ͣ�����ָ���������ͣ������޷������������ڴ�

	// �ָ���
	string line = "-----------------------------------------------------";

	// ����
	short num1 = 10;
	int num2 = 10;
	long num3 = 10;
	long long num4 = 10;
	cout << "num1 = " << num1 << endl;
	cout << "num2 = " << num2 << endl;
	cout << "num3 = " << num3 << endl;
	cout << "num4 = " << num4 << endl;

	// sizeof 
	// ���ã�ͳ��������ռ�ڴ��С
	// �﷨��sizeof(��������/����)
	cout << "short������ռ�ڴ�ռ��С��" << sizeof(short) << "�ֽ�" << endl;
	cout << "int������ռ�ڴ�ռ��С��" << sizeof(int) << "�ֽ�" << endl;
	cout << "long������ռ�ڴ�ռ��С��" << sizeof(long) << "�ֽ�" << endl;
	cout << "long long������ռ�ڴ�ռ��С��" << sizeof(long long) << "�ֽ�" << endl;

	cout << "num1������ռ�ڴ�ռ��С��" << sizeof(num1) << "�ֽ�" << endl;

	cout << line << endl;

	// ʵ�ͣ������ͣ�
	// ������	float	4�ֽ�	7λ��Ч����
	// ˫����	double	8�ֽ�	15~16λ��Ч����
	// Ĭ�� ���һ��С�� ����ʾ6λ��Ч����
	float f1 = 3.14f;
	double d1 = 3.14;
	float f2 = 3e2f; // ��ѧ������ 3 * 10 ^ 2
	float f3 = 3e-2f; // 3 * 0.1 ^ 2

	// �ַ���
	// ������ʾ�����ַ�
	// �﷨�� char ch = 'a'
	// ռ��1���ֽ�
	// �ַ����ǽ���Ӧ��ASCII��洢���ڴ���
	char ch = 'a'; // ֻ���õ�����
	cout << "ch = " << ch << endl;
	// a => 97 A => 65
	cout << "ch��ASCII = " << (int)ch << endl;

	cout << line << endl;

	// ת���ַ�
	// ���ڱ�ʾ������ʾ������ASCII��
	// ���� \n \\ \t
	cout << "���з���AAA\nBBB" << endl;
	cout << "��б�ܣ�\\" << endl;
	// \t ������8���ַ�Ϊ����  �����ڶ���������������
	cout << "ˮƽ�Ʊ����aa\tbbb" << endl;
	cout << "aa\tbbb\tcccc" << endl;

	cout << line << endl;

	// �ַ��� 
	// ֻ����˫����
	// c�����ַ���
	char str[] = "hello world";
	cout << "c����ַ�����" << str << endl;
	// c++�����ַ��� ������� string ͷ��
	string str2 = "Hello World";
	cout << "c++����ַ�����" << str2 << endl;

	cout << line << endl;

	// bool���� 
	// ռ1���ֽ�
	bool isTrue = true; // ==> 1  ��0��ֵ����1
	bool isFalse = false; // ==>0 
	cout << "isTrue��" << isTrue << endl;
	cout << "isFalse��" << isFalse << endl;

	cout << line << endl;

	// ���ݵ�����
	// ���ڴӼ��̻�ȡ����
	// �﷨��cin >> ����
	int cc = 0;
	cout << "������ͱ���cc��ֵ��" << endl;
	cin >> cc;
	cout << "���ͱ��� cc = " << cc << endl;
}