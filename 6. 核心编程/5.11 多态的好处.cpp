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
多态好处
1. 组织结构清晰
2. 可读性强
3. 可扩展性强（对修改关闭，对扩展开放）
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