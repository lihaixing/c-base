#pragma once; // 防止头文件重新包含
#include <iostream>
using namespace std;
#include <string>
#include "point.h";
void classAndObject();

// 点和圆的关系

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