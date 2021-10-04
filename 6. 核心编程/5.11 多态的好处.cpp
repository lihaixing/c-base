#include <iostream>
using namespace std;
#include <string>

class AbstractCalculator {
public:
	virtual int getResult() {
		return 0;
	};
	int num1;
	int num2;
};

class AddCalculator :public AbstractCalculator {
public:
	AddCalculator(int x, int y) {
		num1 = x;
		num2 = y;
	}
	int getResult() {
		return num1 + num2;
	}
};
class PlusCalculator :public AbstractCalculator {

public:
	PlusCalculator(int x, int y) {
		num1 = x;
		num2 = y;
	}
	int getResult() {
		return num1 * num2;
	}
};

/*
��̬�ô�
1. ��֯�ṹ����
2. �ɶ���ǿ
3. ����չ��ǿ�����޸Ĺرգ�����չ���ţ�
*/

void test511() {
	AbstractCalculator* add = new AddCalculator(2, 3);
	cout << "2 + 3 = " << add->getResult() << endl;
	delete add;
	PlusCalculator myPlus(2, 3);
	AbstractCalculator& plus = myPlus;
	cout << "2 * 3 = " << plus.getResult() << endl;

}
int main() {
	test511();
	system("pause");
	return 0;
}