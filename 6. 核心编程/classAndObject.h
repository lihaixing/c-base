#pragma once; // ��ֹͷ�ļ����°���
#include <iostream>
using namespace std;
#include <string>
#include "point.h";
void classAndObject();

// ���Բ�Ĺ�ϵ

class Circle2 {
private:
	int r;
	Point center;
public:
	int getR();
	Point getCenter();
	void setR(int R);
	void setCenter(Point& c);
	void relation(Point& p);
};