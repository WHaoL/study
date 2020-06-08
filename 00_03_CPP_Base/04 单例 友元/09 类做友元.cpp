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

	void visit();

	Building * building;

};

class Building
{
	//告诉编译器 goodGay类是本类的好朋友，可以访问本类中私有成员
	friend class goodGay;
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
	cout << "好基友类 正在访问" << this->building->m_SittingRoom << endl;

	cout << "好基友类 正在访问" << this->building->m_BedRoom << endl;
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

}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}