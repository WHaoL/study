#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//����ģʽ -- һ����ֻ��ʵ����Ψһ��һ�����󣬹���ͬһ������

//��ϯ��
class chairman
{
public:
    //getInstance��ȡ������Ψһʵ��
    static chairman *getInstance()
    {
        return singleMan;
    }

private:
    chairman(){
        //cout << "��ϯ�Ĺ��캯������" << endl;
    };
    chairman(const chairman &){};

    //public:

private:
    //��̬��Ա����
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
        cout << "c1��c2����ȵ�" << endl;
    }
    else
    {
        cout << "c1��c2�ǲ���ȵ�" << endl;
    }

    /*if (c1 == c3)
	{
	cout << "c1��c3����ȵ�" << endl;
	}
	else
	{
	cout << "c1��c3�ǲ���ȵ�" << endl;
	}*/
}

int main()
{
    //cout << "main��������" << endl;

    test01();

    system("pause");
    return EXIT_SUCCESS;
}