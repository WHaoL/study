#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <string>

class Building
{
	//���߱����� goodGayȫ�ֺ��� ��Ϊ����ĺ����ѣ����Է�������˽�г�Ա
	friend void goodGay(Building * building);
public:
	Building()
	{
		this->m_SittingRoom = "����";
		this->m_BedRoom = "����";
	}

public:
	//����
	string m_SittingRoom;
private:
	//����
	string m_BedRoom;
};

//ȫ�ֺ��� �������е�����
void goodGay( Building * building)
{
	cout << "�û��ѵ�ȫ�ֺ��� ���ڷ���" << building->m_SittingRoom << endl;

	cout << "�û��ѵ�ȫ�ֺ��� ���ڷ���" << building->m_BedRoom << endl;
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