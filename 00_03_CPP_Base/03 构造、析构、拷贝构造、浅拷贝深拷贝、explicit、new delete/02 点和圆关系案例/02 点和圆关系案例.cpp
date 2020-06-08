#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include "point.h"
#include "circle.h"

/*
�жϵ��Բ��ϵ
*/

//class Point
//{
//public:
//
//	//����x y
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
//	//��ȡx y
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
//	// x �� y ����
//	int m_X;
//	int m_Y;
//};



////Բ��
//class Circle
//{
//public:
//	//���� �뾶  Բ��
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
//	//��ȡ �뾶 Բ��
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
//	//ͨ����Ա�����жϵ��Բ��ϵ
//	void isInCircleByClass(Point &p)
//	{
//		//�뾶��ƽ��
//		int rDistance = m_R * m_R;
//
//		//����֮������ƽ��
//		int distance = (m_Center.getX() - p.getX()) * (m_Center.getX() - p.getX()) +
//			(m_Center.getY() - p.getY()) * (m_Center.getY() - p.getY());
//
//		if (rDistance == distance)
//		{
//			cout << "��Ա�����жϣ�����Բ��" << endl;
//		}
//		else if (rDistance > distance)
//		{
//			cout << "��Ա�����жϣ�����Բ��" << endl;
//		}
//		else
//		{
//			cout << "��Ա�����жϣ�����Բ��" << endl;
//		}
//	
//	}
//
//private:
//	//�뾶
//	int m_R;
//	//Բ��
//	Point m_Center;
//};


//ȫ�ֺ����жϵ��Բ��ϵ
void isInCircle(Circle &c , Point &p )
{
	//�뾶��ƽ��
	int rDistance = c.getR() * c.getR();

	//����֮������ƽ��
	int distance = (c.getCenter().getX() - p.getX()) * (c.getCenter().getX() - p.getX()) +
		(c.getCenter().getY() - p.getY()) * (c.getCenter().getY() - p.getY());

	if (rDistance == distance)
	{
		cout << "����Բ��" << endl;
	}
	else if (rDistance > distance)
	{
		cout << "����Բ��" << endl;
	}
	else
	{
		cout << "����Բ��" << endl;
	}
}

void test01()
{
	//Բ����
	Circle c;
	c.setR(10);

	Point center;
	center.setX(10);
	center.setY(0);

	c.setCenter(center);

	//�����
	Point p1;
	p1.setX(10);
	p1.setY(10);

	//ȫ�ֺ�������
	isInCircle(c, p1);


	//��Ա��������
	c.isInCircleByClass(p1);

}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}