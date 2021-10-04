#include <iostream>
using namespace std;
#include "structDemo.h"
#include <string>
#include <ctime>


struct Student {
	string name;
	int score;
};

struct Teacher {
	string tname;
	Student sArr[5];
};

void allocateSpace(Teacher tArr[], int len) {
	srand((unsigned int) time(NULL));
	string nameSeed = "ABCDE";
	for (int i = 0; i < len; i++) {
		tArr[i].tname = "Teacher_";
		tArr[i].tname += nameSeed[i];
		for (int j = 0; j < 5; j++) {
			tArr[i].sArr[j].name = "Student_";
			tArr[i].sArr[j].name += nameSeed[j];
			tArr[i].sArr[j].score = rand() % 61+40;
		}
	}
}

void printInfo(Teacher tArr[], int len) {
	for (int i = 0; i < len; i++) {
		cout << "��ʦ������" << tArr[i].tname << endl;
		for (int j = 0; j < 5; j++) {
			cout << "\tѧ��������" << tArr[i].sArr[j].name << ", ������"<< tArr[i].sArr[j].score << endl;
		}
	}
}

struct Hero {
	string name;
	int age;
	string sex;
};

void printHero(Hero hArr[],int len) {
	for (int i = 0; i < len; i++) {
		cout << "������" << hArr[i].name
			<< "���䣺" << hArr[i].age
			<< "�Ա�" << hArr[i].sex
			<< endl;
	}
}

void bubleSort(Hero hArr[],int len) {
	int max = 0;
	while (len > 1) {
		for (int i = 0; i < len - 1; i++) {
			if (hArr[i].age > hArr[i + 1].age) {
				Hero temp = hArr[i];
				hArr[i] = hArr[i + 1];
				hArr[i + 1] = temp;
			}
		}
		len--;
	}
	

}

void structDemo() {
	Teacher tArr[3];
	int len = sizeof tArr / sizeof tArr[0];
	allocateSpace(tArr, len);
	printInfo(tArr, len);

	Hero hArr[5] = {
		{"liubei",23,"��"},
		{"guanyu",22,"��"},
		{"zhangfei",20,"��"},
		{"zhaoyun",21,"��"},
		{"diaochan",19,"Ů"},
	};
	int hArrLen = sizeof hArr / sizeof hArr[0];

	bubleSort(hArr, hArrLen);
	printHero(hArr, hArrLen);

}