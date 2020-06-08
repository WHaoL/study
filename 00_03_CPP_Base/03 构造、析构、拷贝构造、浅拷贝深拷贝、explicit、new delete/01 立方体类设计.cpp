#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

/*
�����������(Cube)���������������( 2*a*b + 2*a*c + 2*b*c )�����( a * b * c)��
�ֱ���ȫ�ֺ����ͳ�Ա�����ж������������Ƿ���ȡ�
*/

class Cube
{
public:

	//���� �� �� ��
	void setL(int l)
	{
		m_L = l;
	}
	void setW(int w)
	{
		m_W = w;
	}
	void setH(int h)
	{
		m_H = h;
	}
	//��ȡ �� �� ��
	int getL()
	{
		return m_L;
	}
	int getW()
	{
		return m_W;
	}
	int getH()
	{
		return m_H;
	}

	//��ȡ���
	int getS()
	{
		return 2 * m_L * m_W + 2 * m_W *m_H + 2 * m_L * m_H;
	}

	//��ȡ���
	int getV()
	{
		return m_L * m_W * m_H;
	}

	//���ó�Ա�����ж������������Ƿ����
	bool compareCubeByClass(Cube & c)
	{
		if ( m_L == c.getL() && m_W == c.getW() && m_H == c.getH())
		{
			return true;
		}
		return false;
	}

private:
	//����  �����
	int m_L;  //��

	int m_W;  //��

	int m_H;  //��
};


//����ȫ�ֺ����ж������������Ƿ����
bool compareCube(Cube &c1, Cube &c2)
{
	if (c1.getL() == c2.getL() && c1.getW() == c2.getW() && c1.getH() == c2.getH())
	{
		return true;
	}
	return false;
}

void test01()
{
	//������һ��������
	Cube c1;
	c1.setL(10);
	c1.setW(10);
	c1.setH(10);

	cout << "C1�����Ϊ�� " << c1.getS() << endl; //600
	cout << "C1�����Ϊ�� " << c1.getV() << endl; //1000


	Cube c2;
	c2.setL(10);
	c2.setW(10);
	c2.setH(10);

	//����ȫ�ֺ�������
	bool ret = compareCube(c1, c2);

	if (ret)
	{
		cout << "ȫ�ֺ����жϣ�c1��c2�����" << endl;
	}
	else
	{
		cout << "ȫ�ֺ����жϣ�c1��c2�ǲ����" << endl;
	}

	//���ó�Ա��������
	//ret = c1.compareCubeByClass(c2);
	ret = c2.compareCubeByClass(c1);
	if (ret)
	{
		cout << "��Ա�����жϣ�c1��c2�����" << endl;
	}
	else
	{
		cout << "��Ա�����жϣ�c1��c2�ǲ����" << endl;
	}
	

}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}