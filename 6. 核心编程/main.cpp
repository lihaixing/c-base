#include <iostream>
using namespace std;
#include <string>
#include "global.h";
#include "stack.h";
#include "quote.h";
#include "advanced_fun.h";
#include "classAndObject.h";
#include "objectCharacteristics.h";
#include "object.h";
#include "objectCharacteristics3.h";
#include "objectCharacteristics4.h";
#include "extend.h";

void main() {
	goto FLAG;
	// ȫ����
	global();

	// ջ���Ͷ���
	stack();

	// ����
	quote();

	// �����߼�
	advanced_fun();

	// ��Ͷ���
	classAndObject();

	// ��Ͷ��� - �������� - ���졢���캯��
	objectCharacteristics();

	// ��Ͷ��� - �������� - ��� ��ʼ�� ��̬��Ա
	objectCharacteristics2();

	// ��Ͷ��� - �������� - this
	objectCharacteristics3();

	// ��Ͷ��� - �������� - ���������
	objectCharacteristics4();

FLAG:
	// ��Ͷ��� - �������� - �̳�
	classExtend();

	system("pause");
	return;
}