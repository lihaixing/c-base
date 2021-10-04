#include <iostream>
#include <fstream>
using namespace std;
#include <string>

//char a = '0000'; // 只占一个字节，取值范围为 -128 ~ +127（-2^7~2^7-1）
//int b = 1;
//long c = 2;
//cout << sizeof a << endl; // 1
//cout << sizeof b << endl; // 4
//cout << sizeof c << endl; // 4

// 文件打开方式
// ios::in 为读文件打开文件
// out 为写文件打开文件
// ate 初始位置：文件尾
// app 追加方式写文件
// trunc 如果文件存在，先删除再创建文件
// binary 二进制方式

void writeFile() {
	// 文本文件写操作
	// 1 包含头文件 fstream
	// 2 创建流对象
	ofstream ofs;
	// 3 指定打开方式
	ofs.open("test01.txt", ios::out);
	// 4 写内容
	ofs << "姓名：张三" << endl;
	ofs << "性别：男" << endl;
	ofs << "年龄：20" << endl;
	// 5 关闭文件
	ofs.close();
}

void readFile() {
	// 文本文件读操作
	// 1 包含头文件 fstream
	// 2 创建流对象
	ifstream ifs;
	// 3 指定打开方式, 并且判断是否打开成功
	ifs.open("test01.txt", ios::in);
	if (!ifs.is_open()) {
		cout << "文件打开失败" << endl;
		return;
	}
	// 4 读数据 4种方式
	// 第一种
	//char buf[1024] = { 0 };
	//while (ifs >> buf) {
	//	cout << buf << endl;
	//}

	// 第二种
	//char buf[1024] = { 0 };
	//while (ifs.getline(buf, sizeof buf)) {
	//	cout << buf << endl;
	//}

	// 第三种
	//string buf;
	//while (getline(ifs,buf)) {
	//	cout << buf << endl;
	//}

	//cout << sizeof buf << endl;

	// 第四种 不推荐使用
	//char c;
	//while ((c = ifs.get()) != EOF) { // EOF 文件的尾部
	//	cout << c << endl;
	//}

	// 5 关闭文件
	ifs.close();
}

class Person {
public:
	char m_name[64];
	int m_age;
};

void binaryWriteFile() {
	// 二进制写文件
	// 1 包含头文件 fstream
	// 2 创建流对象
	ofstream ofs;
	// ofstream ofs("person.txt", ios::out | ios::binary); // 2 3合成一步的方法
	// 3 打开文件
	ofs.open("person.txt", ios::out | ios::binary);
	// 4 写文件
	Person p = { "zhangsan",18 };
	ofs.write((const char*)&p, sizeof Person);

}

void binaryReadFile() {
	// 二进制读文件
	// 1 包含头文件 fstream
	// 2 创建流对象
	ifstream ifs;
	// 3 打开文件
	ifs.open("person.txt", ios::in | ios::binary);
	// 4 读文件
	Person p;
	if (!ifs.is_open()) {
		cout << "文件打开失败" << endl;
		return;
	}
	ifs.read((char*)&p, sizeof Person);
	cout << "姓名：" << p.m_name << endl;
	ifs.close();
}


int main() {
	// 文件操作
	// 1. 文件文件 将文本的ASCLL码存到文件中
	// 2. 二进制文件 将二进制形式010101等存到文件


	// 三大类
	/*
	1.ofstream 写
	2.ifstream 读
	3.fstream 读写
	*/
	cout << "000" << endl;

	writeFile();
	readFile();
	binaryWriteFile();
	binaryReadFile();
	//system("pause");
	getchar(); // 等待键盘输入
	return 0;
}