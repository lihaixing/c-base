#include <iostream>
using namespace std;
#include <string>

// �˵�����
void showMenu() {
	cout << "        ͨѶ¼����ϵͳ        " << endl;
	cout << "****************************" << endl;
	cout << "*****   1. �����ϵ��   *****" << endl;
	cout << "*****   2. ��ʾ��ϵ��   *****" << endl;
	cout << "*****   3. ɾ����ϵ��   *****" << endl;
	cout << "*****   4. ������ϵ��   *****" << endl;
	cout << "*****   5. �޸���ϵ��   *****" << endl;
	cout << "*****   6. �����ϵ��   *****" << endl;
	cout << "*****   0. �˳�ͨѶ¼   *****" << endl;
	cout << "****************************" << endl;
}

// ��ϵ�˽ṹ��
struct Person {
	string name;
	int sex;
	int age;
	string phone;
	string addr;
};

#define MAX 1000
// ͨѶ¼�ṹ��
struct AddressBook {
	// ͨѶ¼����ϵ������
	Person personArr[MAX];
	// ��ǰ��ϵ�˸���
	int size = 0;
};


void addPerson(AddressBook* abs) {
	if (abs->size >= MAX) {
		cout << "ͨѶ¼�������޷���ӣ�" << endl;
		return;
	}
	else {
		cout << "������������" << endl;
		string name = "";
		cin >> name;
		abs->personArr[abs->size].name = name;

		cout << "�������Ա�" << endl;
		cout << "1 -- ��" << endl;
		cout << "2 -- Ů" << endl;
		int sex = 0;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArr[abs->size].sex = sex;
				break;
			}
			cout << "������������������" << endl;
		}


		cout << "���������䣺" << endl;
		int age = 0;
		cin >> age;
		abs->personArr[abs->size].age = age;

		cout << "������绰��" << endl;
		string phone;
		cin >> phone;
		abs->personArr[abs->size].phone = phone;

		cout << "�������ַ��" << endl;
		string addr;
		cin >> addr;
		abs->personArr[abs->size].addr = addr;

		abs->size++;

		cout << "��ϵ����ӳɹ���" << endl;
	}
	
	system("pause"); // �����������
	system("cls"); // ��������
}

void showPersons(AddressBook* abs) {
	if (abs->size == 0) {
		cout << "��ǰ��¼Ϊ��" << endl;
	}
	else {
		for (int i = 0; i < abs->size; i++) {
			int sex = abs->personArr[i].sex;
			cout << "������" << abs->personArr[i].name << "\t";
			cout << "�Ա�" << (sex == 1?"��":"Ů") << "\t";
			cout << "���䣺" << abs->personArr[i].age << "\t";
			cout << "�绰��" << abs->personArr[i].phone << "\t";
			cout << "��ַ��" << abs->personArr[i].addr << endl;
		}
	}
	system("pause");
	system("cls");	
}

// ����Ƿ���ڣ�������λ��
int isExist(AddressBook* abs,string name) {
	for (int i = 0; i < abs->size; i++) {
		if (abs->personArr[i].name == name) {
			return i;
		}
	}
	return -1;
}

void deletePerson(AddressBook* abs) {
	cout << "������Ҫɾ������ϵ��������" << endl;
	string name;
	cin >> name;
	int index = isExist(abs, name);
	if (index == -1) {
		cout << "���޴���" << endl;
	}
	else {
		for (int i = index; i < abs->size-1; i++) {
			abs->personArr[i] = abs->personArr[i + 1];
		}
		abs->size--;
		cout << "ɾ���ɹ���" << endl;
	}
	system("pause");
	system("cls");
}

void findPerson(AddressBook* abs) {
	cout << "������Ҫ���ҵ���ϵ�ˣ�" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret == -1) {
		cout << "���޴���" << endl;
	}
	else {
		int sex = abs->personArr[ret].sex;
		cout << "������" << abs->personArr[ret].name << "\t";
		cout << "�Ա�" << (sex == 1 ? "��" : "Ů") << "\t";
		cout << "���䣺" << abs->personArr[ret].age << "\t";
		cout << "�绰��" << abs->personArr[ret].phone << "\t";
		cout << "��ַ��" << abs->personArr[ret].addr << endl;
	}
	system("pause");
	system("cls");
}

void modifyPerson(AddressBook* abs) {
	cout << "������Ҫ�޸ĵ���ϵ�ˣ�" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret == -1) {
		cout << "���޴���" << endl;
	}
	else {
		cout << "������������" << endl;
		string name = "";
		cin >> name;
		abs->personArr[ret].name = name;

		cout << "�������Ա�" << endl;
		cout << "1 -- ��" << endl;
		cout << "2 -- Ů" << endl;
		int sex = 0;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArr[ret].sex = sex;
				break;
			}
			cout << "������������������" << endl;
		}


		cout << "���������䣺" << endl;
		int age = 0;
		cin >> age;
		abs->personArr[ret].age = age;

		cout << "������绰��" << endl;
		string phone;
		cin >> phone;
		abs->personArr[ret].phone = phone;

		cout << "�������ַ��" << endl;
		string addr;
		cin >> addr;
		abs->personArr[ret].addr = addr;

		cout << "�޸ĳɹ���" << endl;
	}
	system("pause");
	system("cls");
}

void clearPerson(AddressBook * abs) {
	abs->size = 0;
	cout << "�����ɣ�" << endl;
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
			// �����ϵ��
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
				cout << "��ӭ�´�ʹ��!" << endl;
				system("pause");
				return;
				break;
			default:
				break;
		}
	}
		
}