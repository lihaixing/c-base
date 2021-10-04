#include "./classAndObject.h";

const double PI = 3.14;

// 设计一个圆类，求圆的周长
class Circle {
	// 访问权限
public:

	// 属性
	int r;

	// 行为
	double caculateZC() {
		return 2 * PI * r;
	}
};

class Student {
public:
	string name;
	int number;
	void showStudent() {
		cout << "姓名 = " << name << "\t";
		cout << "学号 = " << number << endl;
	}

	void setStudent(string sname, int snumber) {
		name = sname;
		number = snumber;
	}
};

// 公共权限
// public 公共：类内类外都能访问
// protected 保护：类内（包括子类的类内）能访问，类外不能访问
// private 私有：自己所在的类内能访问，类外以及子类的类内内不能访问
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

// struct和class区别
// 1. 默认的访问权限不同：struct默认公共，class默认私有



// 实战 立方体
class Cube {
private:
	int L;
	int W;
	int H;
public:
	//长
	void setL(int l) {
		L = l;
	}
	int getL() {
		return L;
	}
	//宽
	void setW(int w) {
		W = w;
	}
	int getW() {
		return W;
	}
	//高
	void setH(int h) {
		H = h;
	}
	int getH() {
		return H;
	}

	// 面积
	int calculateS() {
		return 2 * W * L + 2 * W * H + 2 * L * H;
	}

	// 体积
	int calculateV() {
		return L * W * H;
	}

	bool isSameCube(Cube& c) {
		return getW() == c.getW()
			&& getH() == c.getH()
			&& getL() == c.getL();
	}
};

// 点和圆的关系
// 类的头文件写法

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
		cout << "点在圆外部" << endl;
	}
	else if (distance < rqrt) {
		cout << "点在圆内部" << endl;
	}
	else {
		cout << "点在圆上" << endl;
	}
}

void classAndObject() {
	// 对象 实例化
	Circle c1;
	c1.r = 10;
	cout << "圆c1的周长 = " << c1.caculateZC() << endl;

	Student c2;
	c2.name = "lihaixing";
	c2.number = 32;
	c2.showStudent();


	Student c3;
	c3.setStudent("dangyanzi", 33);
	c3.showStudent();

	// 访问权限
	Person p1;
	p1.name = "lihaixing";
	//p1.car = "benchi"; // 错误
	//p1.password = "xxxx"; // 错误
	p1.func("lihaixing");


	// 立方体
	Cube cube;
	cube.setL(10);
	cube.setW(10);
	cube.setH(10);

	cout << "cube的面积：" << cube.calculateS() << endl;
	cout << "cube的体积：" << cube.calculateV() << endl;

	Cube cube2;
	cube2.setL(10);
	cube2.setW(10);
	cube2.setH(10);
	cout << "cube 和 cube2 是否相等：" << cube.isSameCube(cube2) << endl; // 1

	// 点和圆的关系
	Point p;
	p.setPoint(10, 10);
	Point center;
	center.setPoint(15, 20);
	Circle2 cir;
	cir.setCenter(center);
	cir.setR(20);

	cir.relation(p);








}