#include <iostream>
#include<string>
using namespace std;
int c = 20;
void f1() {

}
int f2() {
	return 1;
}
int main() {
	int a = 10;
	int b = a + 1;

	int& b1 = b;
	int c = b1;

	 const long& b2 = b;

	int* e = &b;
	int d = *e;

	f1();
	int f = f2();
	__asm {
		mov ax, 10 // aֻ�Ƿ��ţ����ǻ���в�����ڷ��ţ����ǵ�ַ��ֵ
		mov eax, 11223344H
	}
	getchar();
	return 0;
}