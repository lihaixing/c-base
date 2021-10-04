#include <iostream>
using namespace std;
#include <string>
// Ðé¼Ì³Ð

class Animal { // Ðé»ùÀà

};

class Sheep : virtual public Animal {
public:
	int age;
};
class Tuo : virtual public Animal {
public:
	int age;
};

class SheepTuo :virtual public Sheep, virtual public Tuo {

};

void test001() {
	SheepTuo st;
	// st.age =18
	st.Sheep::age = 18;
	st.Tuo::age = 28;
	cout << "st.age = " << st.Sheep::age << endl;
	cout << "st.age = " << st.Tuo::age << endl;
	// cout << "st.age = " << st.age << endl;
}

void main() {
	test001();
	system("pause");
	return;
}