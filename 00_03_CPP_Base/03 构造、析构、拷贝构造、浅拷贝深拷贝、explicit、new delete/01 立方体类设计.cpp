#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

/*
设计立方体类(Cube)，求出立方体的面积( 2*a*b + 2*a*c + 2*b*c )和体积( a * b * c)，
分别用全局函数和成员函数判断两个立方体是否相等。
*/

class Cube
{
public:

	//设置 长 宽 高
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
	//获取 长 宽 高
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

	//获取面积
	int getS()
	{
		return 2 * m_L * m_W + 2 * m_W *m_H + 2 * m_L * m_H;
	}

	//获取体积
	int getV()
	{
		return m_L * m_W * m_H;
	}

	//利用成员函数判断两个立方体是否相等
	bool compareCubeByClass(Cube & c)
	{
		if ( m_L == c.getL() && m_W == c.getW() && m_H == c.getH())
		{
			return true;
		}
		return false;
	}

private:
	//属性  长宽高
	int m_L;  //长

	int m_W;  //宽

	int m_H;  //高
};


//利用全局函数判断两个立方体是否相等
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
	//创建第一个立方体
	Cube c1;
	c1.setL(10);
	c1.setW(10);
	c1.setH(10);

	cout << "C1的面积为： " << c1.getS() << endl; //600
	cout << "C1的体积为： " << c1.getV() << endl; //1000


	Cube c2;
	c2.setL(10);
	c2.setW(10);
	c2.setH(10);

	//利用全局函数测试
	bool ret = compareCube(c1, c2);

	if (ret)
	{
		cout << "全局函数判断：c1和c2是相等" << endl;
	}
	else
	{
		cout << "全局函数判断：c1和c2是不相等" << endl;
	}

	//利用成员函数测试
	//ret = c1.compareCubeByClass(c2);
	ret = c2.compareCubeByClass(c1);
	if (ret)
	{
		cout << "成员函数判断：c1和c2是相等" << endl;
	}
	else
	{
		cout << "成员函数判断：c1和c2是不相等" << endl;
	}
	

}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}