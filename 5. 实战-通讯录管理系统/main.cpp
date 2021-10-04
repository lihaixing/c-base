#include <iostream>
using namespace std;
#include <string>

// 菜单界面
void showMenu() {
	cout << "        通讯录管理系统        " << endl;
	cout << "****************************" << endl;
	cout << "*****   1. 添加联系人   *****" << endl;
	cout << "*****   2. 显示联系人   *****" << endl;
	cout << "*****   3. 删除联系人   *****" << endl;
	cout << "*****   4. 查找联系人   *****" << endl;
	cout << "*****   5. 修改联系人   *****" << endl;
	cout << "*****   6. 清空联系人   *****" << endl;
	cout << "*****   0. 退出通讯录   *****" << endl;
	cout << "****************************" << endl;
}

// 联系人结构体
struct Person {
	string name;
	int sex;
	int age;
	string phone;
	string addr;
};

#define MAX 1000
// 通讯录结构体
struct AddressBook {
	// 通讯录中联系人数组
	Person personArr[MAX];
	// 当前联系人个数
	int size = 0;
};


void addPerson(AddressBook* abs) {
	if (abs->size >= MAX) {
		cout << "通讯录已满，无法添加！" << endl;
		return;
	}
	else {
		cout << "请输入姓名：" << endl;
		string name = "";
		cin >> name;
		abs->personArr[abs->size].name = name;

		cout << "请输入性别：" << endl;
		cout << "1 -- 男" << endl;
		cout << "2 -- 女" << endl;
		int sex = 0;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArr[abs->size].sex = sex;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}


		cout << "请输入年龄：" << endl;
		int age = 0;
		cin >> age;
		abs->personArr[abs->size].age = age;

		cout << "请输入电话：" << endl;
		string phone;
		cin >> phone;
		abs->personArr[abs->size].phone = phone;

		cout << "请输入地址：" << endl;
		string addr;
		cin >> addr;
		abs->personArr[abs->size].addr = addr;

		abs->size++;

		cout << "联系人添加成功！" << endl;
	}
	
	system("pause"); // 按任意键继续
	system("cls"); // 清屏操作
}

void showPersons(AddressBook* abs) {
	if (abs->size == 0) {
		cout << "当前记录为空" << endl;
	}
	else {
		for (int i = 0; i < abs->size; i++) {
			int sex = abs->personArr[i].sex;
			cout << "姓名：" << abs->personArr[i].name << "\t";
			cout << "性别：" << (sex == 1?"男":"女") << "\t";
			cout << "年龄：" << abs->personArr[i].age << "\t";
			cout << "电话：" << abs->personArr[i].phone << "\t";
			cout << "地址：" << abs->personArr[i].addr << endl;
		}
	}
	system("pause");
	system("cls");	
}

// 检查是否存在，并返回位置
int isExist(AddressBook* abs,string name) {
	for (int i = 0; i < abs->size; i++) {
		if (abs->personArr[i].name == name) {
			return i;
		}
	}
	return -1;
}

void deletePerson(AddressBook* abs) {
	cout << "请输入要删除的联系人姓名：" << endl;
	string name;
	cin >> name;
	int index = isExist(abs, name);
	if (index == -1) {
		cout << "查无此人" << endl;
	}
	else {
		for (int i = index; i < abs->size-1; i++) {
			abs->personArr[i] = abs->personArr[i + 1];
		}
		abs->size--;
		cout << "删除成功！" << endl;
	}
	system("pause");
	system("cls");
}

void findPerson(AddressBook* abs) {
	cout << "请输入要查找的联系人：" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret == -1) {
		cout << "查无此人" << endl;
	}
	else {
		int sex = abs->personArr[ret].sex;
		cout << "姓名：" << abs->personArr[ret].name << "\t";
		cout << "性别：" << (sex == 1 ? "男" : "女") << "\t";
		cout << "年龄：" << abs->personArr[ret].age << "\t";
		cout << "电话：" << abs->personArr[ret].phone << "\t";
		cout << "地址：" << abs->personArr[ret].addr << endl;
	}
	system("pause");
	system("cls");
}

void modifyPerson(AddressBook* abs) {
	cout << "请输入要修改的联系人：" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret == -1) {
		cout << "查无此人" << endl;
	}
	else {
		cout << "请输入姓名：" << endl;
		string name = "";
		cin >> name;
		abs->personArr[ret].name = name;

		cout << "请输入性别：" << endl;
		cout << "1 -- 男" << endl;
		cout << "2 -- 女" << endl;
		int sex = 0;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArr[ret].sex = sex;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}


		cout << "请输入年龄：" << endl;
		int age = 0;
		cin >> age;
		abs->personArr[ret].age = age;

		cout << "请输入电话：" << endl;
		string phone;
		cin >> phone;
		abs->personArr[ret].phone = phone;

		cout << "请输入地址：" << endl;
		string addr;
		cin >> addr;
		abs->personArr[ret].addr = addr;

		cout << "修改成功！" << endl;
	}
	system("pause");
	system("cls");
}

void clearPerson(AddressBook * abs) {
	abs->size = 0;
	cout << "清空完成！" << endl;
	system("pause");
	system("cls");

}


void main() {
	AddressBook ads;

	int select = 0;
	
	while (true) {
		showMenu();
		cin >> select;
		switch (select) 
		{
			// 添加联系人
			case 1:
				addPerson(&ads);
				break;
			case 2:
				showPersons(&ads);
				break;
			case 3:
				deletePerson(&ads);
				break;
			case 4:
				findPerson(&ads);
				break;
			case 5:
				modifyPerson(&ads);
				break;
			case 6:
				clearPerson(&ads);
				break;
			case 0:
				cout << "欢迎下次使用!" << endl;
				system("pause");
				return;
				break;
			default:
				break;
		}
	}
		
}