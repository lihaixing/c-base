#include <iostream>
using namespace std;
#include <string>
#include "array.h" 
#include "function.h" // ����swap����
#include "pointer.h" 
#include "struct.h"
#include "structDemo.h"
#include "helloworld.h"
#include "dataType.h"
#include "calculate.h"

int main() {

	string line = "-----------------�ָ���-----------------";

	cout << line << endl;

	goto START;
	// hello world
	helloworld();
	
	cout << line << endl;


	// ��������
	dataType();

	cout << line << endl;

START:
	// ����� ���� ѭ��
	calculate();

	goto FLAG;

	cout << line << endl;
	// ����
	Array();

	cout << line << endl;

	// ��������
	cout << "1 + 2 = " << add(1, 2) << endl; // 1 2 ��ʵ��

	// �����ķ��ļ���д
	// 1. ����.h��׺����ͷ�ļ�
	// 2. ����.cpp��׺����Դ�ļ�
	// 3. ��ͷ�ļ���д����������
	// 4. ��Դ�ļ���д�����Ķ��� ��include ͷ�ļ�
	// 5. �������ļ��� include .hͷ�ļ����Ϳ��Ե�����
	swap(12, 10);

	cout << line << endl;

	// ָ�뷽������ 
	pointer();

	cout << line << endl;

	// �ṹ��
	funStruct();

	// �ṹ�尸��
	structDemo();

	cout << line << endl;

FLAG:

	system("pause");

	return 0;
}