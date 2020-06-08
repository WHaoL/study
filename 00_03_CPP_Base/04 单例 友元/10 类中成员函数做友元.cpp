#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <string>

//好基友类
class Building;
class goodGay
{
public:

	goodGay();

	void visit();  //可以访问Building的私有成员

	void visit2(); //不可以访问Building的私有成员

	Building * building;

};

class Building
{
	
	//goodGay类中的成员函数visit作为本类的好朋友，可以访问类中私有成员
    friend void goodGay::visit();

public:
	Building();
public:
	string m_SittingRoom;  //客厅
private:
	string m_BedRoom; //卧室
};

//构造函数
goodGay::goodGay()
{
	this->building = new Building;
}

//参观函数
void goodGay::visit()
{
	cout << "好基友visit成员函数 正在访问" << this->building->m_SittingRoom << endl;

	cout << "好基友visit成员函数 正在访问" << this->building->m_BedRoom << endl;
}

void goodGay::visit2()
{
	cout << "好基友visit2成员函数 正在访问" << this->building->m_SittingRoom << endl;

	//cout << "好基友visit2成员函数 正在访问" << this->building->m_BedRoom << endl;
	//不可以访问类中私有成员
}

Building::Building()
{
	this->m_SittingRoom = "客厅";
	this->m_BedRoom = "卧室";
}

void test01()
{
	goodGay gg;
	gg.visit();

	gg.visit2();
}

int main(){

	
	test01();

	system("pause");
	return EXIT_SUCCESS;
}