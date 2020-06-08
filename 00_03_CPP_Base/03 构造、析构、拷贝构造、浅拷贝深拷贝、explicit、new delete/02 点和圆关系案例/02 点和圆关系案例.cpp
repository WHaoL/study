#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include "point.h"
#include "circle.h"

/*
判断点和圆关系
*/

//class Point
//{
//public:
//
//	//设置x y
//	void setX(int x)
//	{
//		m_X = x;
//	}
//
//	void setY(int y)
//	{
//		m_Y = y;
//	}
//
//	//获取x y
//	int getX()
//	{
//		return m_X;
//	}
//
//	int getY()
//	{
//		return m_Y;
//	}
//
//private:
//	// x 、 y 坐标
//	int m_X;
//	int m_Y;
//};



////圆类
//class Circle
//{
//public:
//	//设置 半径  圆心
//	void setR(int r)
//	{
//		m_R = r;
//	}
//
//	void setCenter(Point center)
//	{
//		m_Center = center;
//	}
//
//	//获取 半径 圆心
//	int getR()
//	{
//		return m_R;
//	}
//
//	Point getCenter()
//	{
//		return m_Center;
//	}
//
//	//通过成员函数判断点和圆关系
//	void isInCircleByClass(Point &p)
//	{
//		//半径的平方
//		int rDistance = m_R * m_R;
//
//		//两点之间距离的平方
//		int distance = (m_Center.getX() - p.getX()) * (m_Center.getX() - p.getX()) +
//			(m_Center.getY() - p.getY()) * (m_Center.getY() - p.getY());
//
//		if (rDistance == distance)
//		{
//			cout << "成员函数判断：点在圆上" << endl;
//		}
//		else if (rDistance > distance)
//		{
//			cout << "成员函数判断：点在圆内" << endl;
//		}
//		else
//		{
//			cout << "成员函数判断：点在圆外" << endl;
//		}
//	
//	}
//
//private:
//	//半径
//	int m_R;
//	//圆心
//	Point m_Center;
//};


//全局函数判断点和圆关系
void isInCircle(Circle &c , Point &p )
{
	//半径的平方
	int rDistance = c.getR() * c.getR();

	//两点之间距离的平方
	int distance = (c.getCenter().getX() - p.getX()) * (c.getCenter().getX() - p.getX()) +
		(c.getCenter().getY() - p.getY()) * (c.getCenter().getY() - p.getY());

	if (rDistance == distance)
	{
		cout << "点在圆上" << endl;
	}
	else if (rDistance > distance)
	{
		cout << "点在圆内" << endl;
	}
	else
	{
		cout << "点在圆外" << endl;
	}
}

void test01()
{
	//圆对象
	Circle c;
	c.setR(10);

	Point center;
	center.setX(10);
	center.setY(0);

	c.setCenter(center);

	//点对象
	Point p1;
	p1.setX(10);
	p1.setY(10);

	//全局函数测试
	isInCircle(c, p1);


	//成员函数测试
	c.isInCircleByClass(p1);

}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}