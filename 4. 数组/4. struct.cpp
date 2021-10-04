#include <iostream>
using namespace std;
#include "struct.h"
#include <string>

// 结构体
// 语法： struct 结构体名 {结构体成员里诶包}

// 创建学生数据类型
struct Student {
	string name;
	int age;
	int score;
};

void printStudent(Student s) {
	s.age = 100;
	cout << "打印此学生的姓名：" << s.name << endl;
}

void printStudent2(Student * p) {
	p->age = 99;
	cout << "通过指针打印此学生的姓名：" << p->name << endl;
}

void printStudent3(const Student* p) {
	// p->age = 99; // 不能修改了
	cout << "通过指针打印此学生的姓名：" << p->name << endl;
}

void funStruct() {

	// 一、通过类型创建学生三种方式
	// 1. struct Student s1

	struct Student s1;
	s1.name = "张三";
	s1.age = 30;
	s1.score = 100;

	// cout << "s1 = " << s1 << endl;
	cout << "s1的姓名 = " << s1.name << endl;

	// 2. struct Student s1 = {}
	struct Student s2 = {
		"lisi",31,90
	};

	cout << "s2的姓名 = " << s2.name << endl;

	// 3. 定义类型的时候顺便 创建
	struct Student2 {
		string name;
		int age;
		int score;
	}s3;
	s3.name = "wangwu";
	s3.age = 33;
	s3.score = 80;
	cout << "s3的姓名 = " << s3.name << endl;

	// struct关键词 创建的时候可以省略, 定义结构体的时候不能省略
	Student2 my = { "lisi",31,90 };

	// 二、结构体数组
	Student2 my2[2] = { {"张三",30,100},{"lisi",31,90} };
	// 赋值
	my2[1].age = 35;

	cout << "sizeof my2[0] = " << sizeof my2[0] << endl; // 36
	int my2Length = (sizeof my2) / (sizeof my2[0]);
	for (int i = 0; i < my2Length; i++) {
		cout << "my2[" << i << "]的年龄 = " << my2[i].age << endl;
	}

	// 三、结构体指针
	// 通过指针访问结构体中的成员
	Student my3 = { "lihaixing",32,100 };

	Student* p = &my3;
	cout << "p = " << p << endl; // 012FFB8C
	// 访问属性
	cout << "my3的name = " << p->name << endl;
	cout << "my3的name = " << (*p).name << endl;

	// 四、结构体嵌套
	struct Teacher {
		int id;
		string name;
		int age;
		struct Student student;
	};

	Teacher t;
	t.age = 60;
	t.id = 101;
	t.name = "Mr Wang";
	t.student.age = 30;
	t.student.name = "haixing";
	t.student.score = 80;

	// 五、结构体做函数参数
	// 1.值传递
	printStudent(my3);
	cout << "my3的age = "<< my3.age << endl; // 32
	// 2.地址传递
	printStudent2(&my3);
	cout << "my3的age = " << my3.age << endl; // 99 


	// 六、结构体中的const
	// 使用场景：用指针传参可减少内存开销，只占4个字节
	Student my4 = { "zhangsan",20,89 };


}