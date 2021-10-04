#include <iostream>
#include <fstream>
using namespace std;
#include <string>

//char a = '0000'; // ֻռһ���ֽڣ�ȡֵ��ΧΪ -128 ~ +127��-2^7~2^7-1��
//int b = 1;
//long c = 2;
//cout << sizeof a << endl; // 1
//cout << sizeof b << endl; // 4
//cout << sizeof c << endl; // 4

// �ļ��򿪷�ʽ
// ios::in Ϊ���ļ����ļ�
// out Ϊд�ļ����ļ�
// ate ��ʼλ�ã��ļ�β
// app ׷�ӷ�ʽд�ļ�
// trunc ����ļ����ڣ���ɾ���ٴ����ļ�
// binary �����Ʒ�ʽ

void writeFile() {
	// �ı��ļ�д����
	// 1 ����ͷ�ļ� fstream
	// 2 ����������
	ofstream ofs;
	// 3 ָ���򿪷�ʽ
	ofs.open("test01.txt", ios::out);
	// 4 д����
	ofs << "����������" << endl;
	ofs << "�Ա���" << endl;
	ofs << "���䣺20" << endl;
	// 5 �ر��ļ�
	ofs.close();
}

void readFile() {
	// �ı��ļ�������
	// 1 ����ͷ�ļ� fstream
	// 2 ����������
	ifstream ifs;
	// 3 ָ���򿪷�ʽ, �����ж��Ƿ�򿪳ɹ�
	ifs.open("test01.txt", ios::in);
	if (!ifs.is_open()) {
		cout << "�ļ���ʧ��" << endl;
		return;
	}
	// 4 ������ 4�ַ�ʽ
	// ��һ��
	//char buf[1024] = { 0 };
	//while (ifs >> buf) {
	//	cout << buf << endl;
	//}

	// �ڶ���
	//char buf[1024] = { 0 };
	//while (ifs.getline(buf, sizeof buf)) {
	//	cout << buf << endl;
	//}

	// ������
	//string buf;
	//while (getline(ifs,buf)) {
	//	cout << buf << endl;
	//}

	//cout << sizeof buf << endl;

	// ������ ���Ƽ�ʹ��
	//char c;
	//while ((c = ifs.get()) != EOF) { // EOF �ļ���β��
	//	cout << c << endl;
	//}

	// 5 �ر��ļ�
	ifs.close();
}

class Person {
public:
	char m_name[64];
	int m_age;
};

void binaryWriteFile() {
	// ������д�ļ�
	// 1 ����ͷ�ļ� fstream
	// 2 ����������
	ofstream ofs;
	// ofstream ofs("person.txt", ios::out | ios::binary); // 2 3�ϳ�һ���ķ���
	// 3 ���ļ�
	ofs.open("person.txt", ios::out | ios::binary);
	// 4 д�ļ�
	Person p = { "zhangsan",18 };
	ofs.write((const char*)&p, sizeof Person);

}

void binaryReadFile() {
	// �����ƶ��ļ�
	// 1 ����ͷ�ļ� fstream
	// 2 ����������
	ifstream ifs;
	// 3 ���ļ�
	ifs.open("person.txt", ios::in | ios::binary);
	// 4 ���ļ�
	Person p;
	if (!ifs.is_open()) {
		cout << "�ļ���ʧ��" << endl;
		return;
	}
	ifs.read((char*)&p, sizeof Person);
	cout << "������" << p.m_name << endl;
	ifs.close();
}


int main() {
	// �ļ�����
	// 1. �ļ��ļ� ���ı���ASCLL��浽�ļ���
	// 2. �������ļ� ����������ʽ010101�ȴ浽�ļ�


	// ������
	/*
	1.ofstream д
	2.ifstream ��
	3.fstream ��д
	*/
	cout << "000" << endl;

	writeFile();
	readFile();
	binaryWriteFile();
	binaryReadFile();
	//system("pause");
	getchar(); // �ȴ���������
	return 0;
}