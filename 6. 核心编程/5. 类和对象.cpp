#include "./classAndObject.h";

const double PI = 3.14;

// ���һ��Բ�࣬��Բ���ܳ�
class Circle {
	// ����Ȩ��
public:

	// ����
	int r;

	// ��Ϊ
	double caculateZC() {
		return 2 * PI * r;
	}
};

class Student {
public:
	string name;
	int number;
	void showStudent() {
		cout << "���� = " << name << "\t";
		cout << "ѧ�� = " << number << endl;
	}

	void setStudent(string sname, int snumber) {
		name = sname;
		number = snumber;
	}
};

// ����Ȩ��
// public �������������ⶼ�ܷ���
// protected ���������ڣ�������������ڣ��ܷ��ʣ����ⲻ�ܷ���
// private ˽�У��Լ����ڵ������ܷ��ʣ������Լ�����������ڲ��ܷ���
class Person {
public:
	string name;

protected:
	string car;

private:
	string password;
public:
	void func(string sname) {
		name = sname;
	}
};

// struct��class����
// 1. Ĭ�ϵķ���Ȩ�޲�ͬ��structĬ�Ϲ�����classĬ��˽��



// ʵս ������
class Cube {
private:
	int L;
	int W;
	int H;
public:
	//��
	void setL(int l) {
		L = l;
	}
	int getL() {
		return L;
	}
	//��
	void setW(int w) {
		W = w;
	}
	int getW() {
		return W;
	}
	//��
	void setH(int h) {
		H = h;
	}
	int getH() {
		return H;
	}

	// ���
	int calculateS() {
		return 2 * W * L + 2 * W * H + 2 * L * H;
	}

	// ���
	int calculateV() {
		return L * W * H;
	}

	bool isSameCube(Cube& c) {
		return getW() == c.getW()
			&& getH() == c.getH()
			&& getL() == c.getL();
	}
};

// ���Բ�Ĺ�ϵ
// ���ͷ�ļ�д��

int Circle2::getR() {
	return r;
}
Point Circle2::getCenter() {
	return center;
}

void Circle2::setR(int R) {
	r = R;
}
void Circle2::setCenter(Point& c) {
	center = c;
}

void Circle2::relation(Point& p) {
	int cx = center.getCoodx();
	int cy = center.getCoody();
	int px = p.getCoodx();
	int py = p.getCoody();
	int distance = (cx - px) * (cx - px)
		+ (cy - py) * (cy - py);
	int rqrt = r * r;
	if (distance > rqrt) {
		cout << "����Բ�ⲿ" << endl;
	}
	else if (distance < rqrt) {
		cout << "����Բ�ڲ�" << endl;
	}
	else {
		cout << "����Բ��" << endl;
	}
}

void classAndObject() {
	// ���� ʵ����
	Circle c1;
	c1.r = 10;
	cout << "Բc1���ܳ� = " << c1.caculateZC() << endl;

	Student c2;
	c2.name = "lihaixing";
	c2.number = 32;
	c2.showStudent();


	Student c3;
	c3.setStudent("dangyanzi", 33);
	c3.showStudent();

	// ����Ȩ��
	Person p1;
	p1.name = "lihaixing";
	//p1.car = "benchi"; // ����
	//p1.password = "xxxx"; // ����
	p1.func("lihaixing");


	// ������
	Cube cube;
	cube.setL(10);
	cube.setW(10);
	cube.setH(10);

	cout << "cube�������" << cube.calculateS() << endl;
	cout << "cube�������" << cube.calculateV() << endl;

	Cube cube2;
	cube2.setL(10);
	cube2.setW(10);
	cube2.setH(10);
	cout << "cube �� cube2 �Ƿ���ȣ�" << cube.isSameCube(cube2) << endl; // 1

	// ���Բ�Ĺ�ϵ
	Point p;
	p.setPoint(10, 10);
	Point center;
	center.setPoint(15, 20);
	Circle2 cir;
	cir.setCenter(center);
	cir.setR(20);

	cir.relation(p);








}