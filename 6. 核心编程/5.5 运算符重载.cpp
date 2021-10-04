#include "objectCharacteristics4.h";
// ���������

// һ���Ӻ������
class PersonA {
public:
	int a;
	int b;
	// ��Ա��������
	/*PersonA operator+(PersonA& p) {
		PersonA temp;
		temp.a = this->a + p.a;
		temp.b = this->b + p.b;
		return temp;
	}*/

	// һ�㲻���ó�Ա��������������������޷�ʵ�� cout�����
	//void operator<<() {}
};

// ȫ�ֺ�������
PersonA operator+(PersonA& p1, PersonA& p2) {
	PersonA temp;
	temp.a = p1.a + p2.a;
	temp.b = p1.b + p2.b;
	return temp;
}
// ����
PersonA operator+(PersonA& p1, int x) {
	PersonA temp;
	temp.a = p1.a + x;
	temp.b = p1.b + x;
	return temp;
}

void PersonATest01() {
	PersonA p1;
	p1.a = 10;
	p1.b = 20;
	PersonA p2;
	p2.a = 15;
	p2.b = 25;

	// �൱�� p3 = p1.operator+(p2) ���� p3 = operator+(p1,p2)
	PersonA p3 = p1 + p2;
	PersonA p4 = p1 + 10;

	cout << "p3.a = " << p3.a << endl;
	cout << "p3.b = " << p3.b << endl;

	cout << "p4.a = " << p4.a << endl;
	cout << "p4.b = " << p4.b << endl;
}

//ֻ������ȫ�ֺ���������������� ,��д cout << p
// �������˽�����ԣ����Խ���ӵ���Ԫ��
ostream& operator <<(ostream& out, PersonA& p) {
	out << "a = " << p.a << endl;
	out << "b = " << p.b << endl;
	return out; // ������ʽ���
}
// ���������
void  PersonATest02() {
	PersonA p5;
	p5.a = 10;
	p5.b = 20;
	cout << p5 << endl;
}


class MyInt {
	friend ostream& operator <<(ostream& out, MyInt& myInt);
public:
	MyInt() {
		num = 0;
	}
	// ǰ��++����
	MyInt& operator ++() {
		num++;
		return *this;
	}
	// ����++���� int��ռλ��������������ǰ�ú���
	MyInt operator ++(int) { // ���� �Ǳ�������Ϊcurr�Ǿֲ�����ִ�����Сʱ
		MyInt curr = *this;
		num++;
		return curr;
	}
private:
	int num;
};

ostream& operator <<(ostream& out, MyInt& myInt) {

	out << myInt.num;
	return out; // ������ʽ���
}
void PersonATest03() {
	MyInt a;
	cout << "a = " << ++(++a) << endl;

	MyInt b;
	// TODO ��֪��ԭ��
	// cout << "b = " << b++ << endl;
	cout << "b = " << b << endl;
}

// ��ֵ�����
class PersonB {
public:
	PersonB() {
		age = new int(10);
	}
	PersonB(int sage) {
		age = new int(sage);
	}

	int* age;
	~PersonB() {
		cout << "~PersonB" << endl;
		if (age != NULL) {
			delete age;
			age = NULL;
		}
	}
	// ��ֵ�����
	PersonB& operator=(PersonB& p) {
		if (age != NULL) {
			delete age;
			age = NULL;
		}
		age = new int(*p.age);
		return *this;
	}
	// �������� == !=
	bool operator==(PersonB& p) {
		if (*this->age == *p.age) {
			return true;
		}
		return false;
	}
	// ������������� ()  �º���
	void operator()(string str) {
		cout << str << endl;
	}
};

void PersonATest04() {
	PersonB p1(10);
	PersonB p2(20);
	PersonB p3(20);
	p3 = p1 = p2;
	cout << "p1�����䣺" << *p1.age << endl;
	cout << "p2�����䣺" << *p2.age << endl; // �����ڴ��ͷź�ͷ��ʲ�����
	cout << "p3�����䣺" << *p3.age << endl; // �����ڴ��ͷź�ͷ��ʲ�����
	//��������
	PersonB p4(30);
	cout << "p1 == p2 : " << (p1 == p2) << endl;
	cout << "p1 == p4 : " << (p1 == p4) << endl;
	//������������� �º���
	p4("abcd");
	//������������
	PersonB()("abcd");
}

void objectCharacteristics4() {
	// һ���Ӻ������
	PersonATest01();
	// ���������
	PersonATest02();

	// ++�����
	PersonATest03();

	// ��ֵ�����
	PersonATest04();

}