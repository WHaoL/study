#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Point
{
public:
	//����x y
	void setX(int x);
	void setY(int y);
	//��ȡx y
	int getX();
	int getY();
private:
	// x �� y ����
	int m_X;
	int m_Y;
};
