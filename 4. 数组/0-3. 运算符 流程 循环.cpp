#include <iostream>
using namespace std;
#include "calculate.h"
#include <string>
#include <ctime> // ϵͳʱ��ͷ�ļ�

void calculate() {
	string line = "------------------------�ָ���------------------------";
	// �Ӽ��˳��� ��ǰ��++ -- ������++ -- ��
	int a = 5;
	int b = 2;
	cout << "a + b = " << a + b << endl;
	cout << "a - b = " << a - b << endl;
	cout << "a / b = " << a / b << endl; // �����������������������С�������С��
	cout << "a % b = " << a % b << endl;
	cout << "a * b = " << a * b << endl;

	cout << " + a - b = " << +a - b << endl;
	cout << " - a + b = " << -a + b << endl;

	cout << " ++ a + b = " << ++a + b << endl;
	cout << " -- a + b = " << --a + b << endl;

	cout << line << endl;

	// ��ֵ����� += -= *= /= %= 
	// �� �� js һ����������

	// �Ƚ������ == != > >= < <=
	cout << "2 == 3 : " << (2 == 3) << endl; // 0
	cout << "2 != 3 : " << (2 != 3) << endl; // 1

	cout << line << endl;

	// �߼������ ! && ||
	cout << "!2 : " << !2 << endl; // 0
	cout << "2 && 3 " << (2 && 3) << endl; // 1
	cout << "0 || 3 " << (2 && 3) << endl; // 1

	cout << line << endl;

	// �������

	// if
	int score = 0;
	cout << "������һ��������" << endl;
	cin >> score;
	cout << "������ķ���Ϊ��" << score << endl;
	if (score > 600) {
		cout << "��ϲ��������һ����ѧ" << endl;
		if (score > 650) {
			cout << "�廪��ѧ" << endl;
		}
	}
	else if (score > 500) {
		cout << "��ϲ�������˶�����ѧ" << endl;
	}
	else {
		cout << "δ���ϴ�ѧ" << endl;
	}

	cout << line << endl;

	// ��Ŀ�����
	const string college = score > 650 ? "�廪��ѧ" : score > 550 ? "�ص��ѧ" : "һ���ѧ";
	cout << college << endl;

	int c = 5;
	int d = 6;
	// ��ֵ����
	(2 > 3) ? c : d = 100;
	cout << "c = " << c << endl;
	cout << "d = " << d << endl;


	cout << line << endl;

	// switch Ч�ʱ�if��һ��
	int fen = 0;
	cout << "�����Ӱ��֣�" << endl;
	cin >> fen;
	cout << "������Ӱ�ķ���Ϊ��" << fen << endl;
	switch (fen) {
	case 10:
		cout << "����" << endl;
		break;
	case 5:
		cout << "�" << endl;
		break;
	case 1:
		cout << "�Ҳ��̶�" << endl;
		break;
	default:
		cout << "û�о�" << endl;
		break;
	}

	cout << line << endl;

	// ѭ�����
	// whileѭ�� �� js �﷨һ��
	// do while �� js �﷨һ��
	// ������


	srand((unsigned int)time(NULL));
	int num = rand() % 100 + 1; // ÿ�ζ��� 42

	cout << num << endl;

	int val = 0;

	while (1) {
		cout << "�����֣�" << endl;
		cin >> val;

		if (val > num) {
			cout << "����" << endl;
		}
		else if (val < num) {
			cout << "С��" << endl;
		}
		else {
			cout << "�¶���" << endl;
			break;
		}

	}

	// forѭ��
	// �� js ����
	for (int i = 0; i < 10; i++) {
		cout << i << endl;
	}


	// break continue �÷���jsһ��

	// goto ���
	// ������������ת
	// �﷨�� goto ���
	// �����ǵ����Ʋ����ڣ�����ת����ǵ�λ��
	// ���Ƽ�ʹ�ã���ʶ�ͺ�
	cout << "goto step1" << endl;
	goto STEP5;
	cout << "goto step2" << endl;
	cout << "goto step3" << endl;
	cout << "goto step4" << endl;
STEP5:
	cout << "goto step5" << endl;
}