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

	void visit();  //���Է���Building��˽�г�Ա

	void visit2(); //�����Է���Building��˽�г�Ա

	Building * building;

};

class Building
{
	
	//goodGay���еĳ�Ա����visit��Ϊ����ĺ����ѣ����Է�������˽�г�Ա
    friend void goodGay::visit();

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
	cout << "�û���visit��Ա���� ���ڷ���" << this->building->m_SittingRoom << endl;

	cout << "�û���visit��Ա���� ���ڷ���" << this->building->m_BedRoom << endl;
}

void goodGay::visit2()
{
	cout << "�û���visit2��Ա���� ���ڷ���" << this->building->m_SittingRoom << endl;

	//cout << "�û���visit2��Ա���� ���ڷ���" << this->building->m_BedRoom << endl;
	//�����Է�������˽�г�Ա
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

	gg.visit2();
}

int main(){

	
	test01();

	system("pause");
	return EXIT_SUCCESS;
}