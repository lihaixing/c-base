#include <iostream>
using namespace std;
#include "dataType.h"
#include <string>

void dataType() {
	// 数据类型：必须指定数据类型，否则无法给变量分配内存

	// 分隔符
	string line = "-----------------------------------------------------";

	// 整型
	short num1 = 10;
	int num2 = 10;
	long num3 = 10;
	long long num4 = 10;
	cout << "num1 = " << num1 << endl;
	cout << "num2 = " << num2 << endl;
	cout << "num3 = " << num3 << endl;
	cout << "num4 = " << num4 << endl;

	// sizeof 
	// 作用：统计数据所占内存大小
	// 语法：sizeof(数据类型/变量)
	cout << "short类型所占内存空间大小：" << sizeof(short) << "字节" << endl;
	cout << "int类型所占内存空间大小：" << sizeof(int) << "字节" << endl;
	cout << "long类型所占内存空间大小：" << sizeof(long) << "字节" << endl;
	cout << "long long类型所占内存空间大小：" << sizeof(long long) << "字节" << endl;

	cout << "num1类型所占内存空间大小：" << sizeof(num1) << "字节" << endl;

	cout << line << endl;

	// 实型（浮点型）
	// 单精度	float	4字节	7位有效数字
	// 双精度	double	8字节	15~16位有效数字
	// 默认 输出一个小数 会显示6位有效数字
	float f1 = 3.14f;
	double d1 = 3.14;
	float f2 = 3e2f; // 科学技术法 3 * 10 ^ 2
	float f3 = 3e-2f; // 3 * 0.1 ^ 2

	// 字符型
	// 用于显示单个字符
	// 语法： char ch = 'a'
	// 占用1个字节
	// 字符型是将对应的ASCII码存储在内存中
	char ch = 'a'; // 只能用单引号
	cout << "ch = " << ch << endl;
	// a => 97 A => 65
	cout << "ch的ASCII = " << (int)ch << endl;

	cout << line << endl;

	// 转义字符
	// 用于表示不能显示出来的ASCII码
	// 常用 \n \\ \t
	cout << "换行符：AAA\nBBB" << endl;
	cout << "反斜杠：\\" << endl;
	// \t 代表以8个字符为结束  可用于对齐后面输出的内容
	cout << "水平制表符：aa\tbbb" << endl;
	cout << "aa\tbbb\tcccc" << endl;

	cout << line << endl;

	// 字符串 
	// 只能用双引号
	// c风格的字符串
	char str[] = "hello world";
	cout << "c风格字符串：" << str << endl;
	// c++风格的字符串 必须包含 string 头部
	string str2 = "Hello World";
	cout << "c++风格字符串：" << str2 << endl;

	cout << line << endl;

	// bool类型 
	// 占1个字节
	bool isTrue = true; // ==> 1  非0的值都是1
	bool isFalse = false; // ==>0 
	cout << "isTrue：" << isTrue << endl;
	cout << "isFalse：" << isFalse << endl;

	cout << line << endl;

	// 数据的输入
	// 用于从键盘获取数据
	// 语法：cin >> 变量
	int cc = 0;
	cout << "请给整型变量cc赋值：" << endl;
	cin >> cc;
	cout << "整型变量 cc = " << cc << endl;
}