#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <string>

//手机类
class Phone
{
public:
	
	Phone(string pName)
	{
		cout << "Phone有参构造函数调用" << endl;
		m_PhoneName = pName;
	}

	~Phone()
	{
		cout << "Phone的析构函数调用" << endl;
	}

	string m_PhoneName; //手机名称
};

//游戏类
class Game
{
public:

	Game(string gName)
	{
		cout << "Game有参构造函数调用" << endl;
		m_GameName = gName;
	}

	~Game()
	{
		cout << "Game的析构函数调用" << endl;
	}

	string m_GameName; //游戏名称
};

class Person
{
public:
	//初始化列表语法 初始化3个属性
	Person(string name, string phone, string game) :m_Name(name), m_Phone(phone), m_Game(game)
	{
		cout << "Person的有参构造函数调用" << endl;
	}

	void playGame()
	{
		cout << "姓名： " << m_Name << "拿着<< " << m_Phone.m_PhoneName << " >> 牌的手机，玩着<< " << m_Game.m_GameName << " >>!" << endl;
	}

	~Person()
	{
		cout << "Person的析构函数调用" << endl;
	}

	string m_Name; //姓名
	Phone m_Phone; //手机
	Game  m_Game;  //游戏
};

//当其他类作为本类成员，先构造其他类对象，再构造自身，析构的顺序与构造相反
void test01()
{
	Person p1("张三", "苹果", "LOL");
	p1.playGame();

	Person p2("李四", "华为", "王者农药");
	p2.playGame();

}

int main(){
	test01();


	system("pause");
	return EXIT_SUCCESS;
}