#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <string>

//�û�����
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
	//���߱����� goodGay���Ǳ���ĺ����ѣ����Է��ʱ�����˽�г�Ա
	friend class goodGay;
public:
	Building();
public:
	string m_SittingRoom;  //����
private:
	string m_BedRoom; //����
};

//���캯��
goodGay::goodGay()
{
	this->building = new Building;
}

//�ιۺ���
void goodGay::visit()
{
	cout << "�û����� ���ڷ���" << this->building->m_SittingRoom << endl;

	cout << "�û����� ���ڷ���" << this->building->m_BedRoom << endl;
}

Building::Building()
{
	this->m_SittingRoom = "����";
	this->m_BedRoom = "����";
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