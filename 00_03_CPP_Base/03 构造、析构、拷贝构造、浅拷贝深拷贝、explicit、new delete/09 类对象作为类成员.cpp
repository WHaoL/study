#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <string>

//�ֻ���
class Phone
{
public:
	
	Phone(string pName)
	{
		cout << "Phone�вι��캯������" << endl;
		m_PhoneName = pName;
	}

	~Phone()
	{
		cout << "Phone��������������" << endl;
	}

	string m_PhoneName; //�ֻ�����
};

//��Ϸ��
class Game
{
public:

	Game(string gName)
	{
		cout << "Game�вι��캯������" << endl;
		m_GameName = gName;
	}

	~Game()
	{
		cout << "Game��������������" << endl;
	}

	string m_GameName; //��Ϸ����
};

class Person
{
public:
	//��ʼ���б��﷨ ��ʼ��3������
	Person(string name, string phone, string game) :m_Name(name), m_Phone(phone), m_Game(game)
	{
		cout << "Person���вι��캯������" << endl;
	}

	void playGame()
	{
		cout << "������ " << m_Name << "����<< " << m_Phone.m_PhoneName << " >> �Ƶ��ֻ�������<< " << m_Game.m_GameName << " >>!" << endl;
	}

	~Person()
	{
		cout << "Person��������������" << endl;
	}

	string m_Name; //����
	Phone m_Phone; //�ֻ�
	Game  m_Game;  //��Ϸ
};

//����������Ϊ�����Ա���ȹ�������������ٹ�������������˳���빹���෴
void test01()
{
	Person p1("����", "ƻ��", "LOL");
	p1.playGame();

	Person p2("����", "��Ϊ", "����ũҩ");
	p2.playGame();

}

int main(){
	test01();


	system("pause");
	return EXIT_SUCCESS;
}