#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <string>

class Building
{
	//告诉编译器 goodGay全局函数 作为本类的好朋友，可以访问类中私有成员
	friend void goodGay(Building * building);
public:
	Building()
	{
		this->m_SittingRoom = "客厅";
		this->m_BedRoom = "卧室";
	}

public:
	//客厅
	string m_SittingRoom;
private:
	//卧室
	string m_BedRoom;
};

//全局函数 访问类中的属性
void goodGay( Building * building)
{
	cout << "好基友的全局函数 正在访问" << building->m_SittingRoom << endl;

	cout << "好基友的全局函数 正在访问" << building->m_BedRoom << endl;
}

void test01()
{
	Building * building = new Building;
	goodGay(building);
}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}