#include "circle.h"

//Բ��
//���� �뾶  Բ��
void Circle::setR(int r)
{
	m_R = r;
}

void Circle::setCenter(Point center)
{
	m_Center = center;
}

//��ȡ �뾶 Բ��
int Circle::getR()
{
	return m_R;
}

Point Circle::getCenter()
{
	return m_Center;
}

//ͨ����Ա�����жϵ��Բ��ϵ
void Circle::isInCircleByClass(Point &p)
{
	//�뾶��ƽ��
	int rDistance = m_R * m_R;

	//����֮������ƽ��
	int distance = (m_Center.getX() - p.getX()) * (m_Center.getX() - p.getX()) +
		(m_Center.getY() - p.getY()) * (m_Center.getY() - p.getY());

	if (rDistance == distance)
	{
		cout << "��Ա�����жϣ�����Բ��" << endl;
	}
	else if (rDistance > distance)
	{
		cout << "��Ա�����жϣ�����Բ��" << endl;
	}
	else
	{
		cout << "��Ա�����жϣ�����Բ��" << endl;
	}

}

