#include <iostream>
using namespace std;
#include "calculate.h"
#include <string>
#include <ctime> // 系统时间头文件

void calculate() {
	string line = "------------------------分割线------------------------";
	// 加减乘除余 ，前置++ -- ，后置++ -- ，
	int a = 5;
	int b = 2;
	cout << "a + b = " << a + b << endl;
	cout << "a - b = " << a - b << endl;
	cout << "a / b = " << a / b << endl; // 两个整除相除是整数，两个小数相除是小数
	cout << "a % b = " << a % b << endl;
	cout << "a * b = " << a * b << endl;

	cout << " + a - b = " << +a - b << endl;
	cout << " - a + b = " << -a + b << endl;

	cout << " ++ a + b = " << ++a + b << endl;
	cout << " -- a + b = " << --a + b << endl;

	cout << line << endl;

	// 赋值运算符 += -= *= /= %= 
	// 简单 和 js 一样，不讲了

	// 比较运算符 == != > >= < <=
	cout << "2 == 3 : " << (2 == 3) << endl; // 0
	cout << "2 != 3 : " << (2 != 3) << endl; // 1

	cout << line << endl;

	// 逻辑运算符 ! && ||
	cout << "!2 : " << !2 << endl; // 0
	cout << "2 && 3 " << (2 && 3) << endl; // 1
	cout << "0 || 3 " << (2 && 3) << endl; // 1

	cout << line << endl;

	// 流程语句

	// if
	int score = 0;
	cout << "请输入一个分数：" << endl;
	cin >> score;
	cout << "您输入的分数为：" << score << endl;
	if (score > 600) {
		cout << "恭喜您考上了一本大学" << endl;
		if (score > 650) {
			cout << "清华大学" << endl;
		}
	}
	else if (score > 500) {
		cout << "恭喜您考上了二本大学" << endl;
	}
	else {
		cout << "未考上大学" << endl;
	}

	cout << line << endl;

	// 三目运算符
	const string college = score > 650 ? "清华大学" : score > 550 ? "重点大学" : "一般大学";
	cout << college << endl;

	int c = 5;
	int d = 6;
	// 赋值操作
	(2 > 3) ? c : d = 100;
	cout << "c = " << c << endl;
	cout << "d = " << d << endl;


	cout << line << endl;

	// switch 效率比if高一点
	int fen = 0;
	cout << "请给电影打分：" << endl;
	cin >> fen;
	cout << "您给电影的分数为：" << fen << endl;
	switch (fen) {
	case 10:
		cout << "经典" << endl;
		break;
	case 5:
		cout << "差劲" << endl;
		break;
	case 1:
		cout << "惨不忍赌" << endl;
		break;
	default:
		cout << "没感觉" << endl;
		break;
	}

	cout << line << endl;

	// 循环语句
	// while循环 和 js 语法一样
	// do while 和 js 语法一样
	// 猜数字


	srand((unsigned int)time(NULL));
	int num = rand() % 100 + 1; // 每次都是 42

	cout << num << endl;

	int val = 0;

	while (1) {
		cout << "猜数字：" << endl;
		cin >> val;

		if (val > num) {
			cout << "大了" << endl;
		}
		else if (val < num) {
			cout << "小了" << endl;
		}
		else {
			cout << "猜对了" << endl;
			break;
		}

	}

	// for循环
	// 和 js 类似
	for (int i = 0; i < 10; i++) {
		cout << i << endl;
	}


	// break continue 用法和js一样

	// goto 语句
	// 可以无条件跳转
	// 语法： goto 标记
	// 如果标记的名称不存在，会跳转到标记的位置
	// 不推荐使用，认识就好
	cout << "goto step1" << endl;
	goto STEP5;
	cout << "goto step2" << endl;
	cout << "goto step3" << endl;
	cout << "goto step4" << endl;
STEP5:
	cout << "goto step5" << endl;
}