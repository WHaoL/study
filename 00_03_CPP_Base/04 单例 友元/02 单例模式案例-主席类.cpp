#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//单例模式 -- 一个类只能实例化唯一的一个对象，共享同一个对象

//主席类
class chairman
{
public:
    //getInstance获取单例的唯一实例
    static chairman *getInstance()
    {
        return singleMan;
    }

private:
    chairman(){
        //cout << "主席的构造函数调用" << endl;
    };
    chairman(const chairman &){};

    //public:

private:
    //静态成员变量
    static chairman *singleMan;
};

chairman *chairman::singleMan = new chairman;

void test01()
{
    //chairman c1;
    //chairman c2;
    //chairman * c3 = new chairman;

    //chairman * c1 = chairman::singleMan;
    //chairman * c2 = chairman::singleMan;

    chairman *c1 = chairman::getInstance();
    chairman *c2 = chairman::getInstance();

    //chairman * c3 = new chairman(*c1);

    if (c1 == c2)
    {
        cout << "c1和c2是相等的" << endl;
    }
    else
    {
        cout << "c1和c2是不相等的" << endl;
    }

    /*if (c1 == c3)
	{
	cout << "c1和c3是相等的" << endl;
	}
	else
	{
	cout << "c1和c3是不相等的" << endl;
	}*/
}

int main()
{
    //cout << "main函数调用" << endl;

    test01();

    system("pause");
    return EXIT_SUCCESS;
}