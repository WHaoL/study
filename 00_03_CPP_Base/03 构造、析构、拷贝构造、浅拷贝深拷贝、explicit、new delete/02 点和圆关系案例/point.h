#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Point
{
public:
	//设置x y
	void setX(int x);
	void setY(int y);
	//获取x y
	int getX();
	int getY();
private:
	// x 、 y 坐标
	int m_X;
	int m_Y;
};
