#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

////Javaҳ��
//class Java
//{
//public:
//
//	//������ͷ
//	void header()
//	{
//		cout << "������ͷ��" << endl;
//	}
//
//	//�����ײ�
//	void footer()
//	{
//		cout << "�����ĵײ�" << endl;
//	}
//
//	//�����ķ����б�
//	void list()
//	{
//		cout << "������ѧ�Ʒ����б�" << endl;
//	}
//
//	//��ʾ����̳�
//	void content()
//	{
//		cout << "Java�̳�" << endl;
//	}
//
//};
//
////Pythonҳ��
//class Python
//{
//public:
//
//	//������ͷ
//	void header()
//	{
//		cout << "������ͷ��" << endl;
//	}
//
//	//�����ײ�
//	void footer()
//	{
//		cout << "�����ĵײ�" << endl;
//	}
//
//	//�����ķ����б�
//	void list()
//	{
//		cout << "������ѧ�Ʒ����б�" << endl;
//	}
//
//	//��ʾ����̳�
//	void content()
//	{
//		cout << "Python�̳�" << endl;
//	}
//};
////CPP
//class CPP
//{
//public:
//	//������ͷ
//	void header()
//	{
//		cout << "������ͷ��" << endl;
//	}
//
//	//�����ײ�
//	void footer()
//	{
//		cout << "�����ĵײ�" << endl;
//	}
//
//	//�����ķ����б�
//	void list()
//	{
//		cout << "������ѧ�Ʒ����б�" << endl;
//	}
//
//	//��ʾ����̳�
//	void content()
//	{
//		cout << "C++�̳�" << endl;
//	}
//};


//���ü̳�ʵ��ҳ��
//����ҳ��

//�̳еĺô��� �����ظ�����

class BasePage
{
public:
	//������ͷ
	void header()
	{
		cout << "������ͷ��" << endl;
	}
	
	//�����ײ�
	void footer()
	{
		cout << "�����ĵײ�" << endl;
	}
	
	//�����ķ����б�
	void list()
	{
		cout << "������ѧ�Ʒ����б�" << endl;
	}
};

//�﷨��class ���� : �̳з�ʽ  ����
//���� --- ������
//���� --- ����

//Javaҳ��
class Java : public BasePage
{
public:
	//��ʾ����̳�
	void content()
	{
		cout << "Java�̳�" << endl;
	}
};

//Pythonҳ��
class Python :public BasePage
{
public:
	//��ʾ����̳�
	void content()
	{
		cout << "Python�̳�" << endl;
	}
};
//CPPҳ��
class CPP :public BasePage
{
public:
	//��ʾ����̳�
	void content()
	{
		cout << "CPP�̳�" << endl;
	}
};

void test01()
{
	cout << "Java��ҳ���������£� " << endl;
	Java ja;
	ja.header();
	ja.footer();
	ja.list();
	ja.content();
	cout << "-----------------------" << endl;


	cout << "Python��ҳ���������£� " << endl;
	Python py;
	py.header();
	py.footer();
	py.list();
	py.content();

	cout << "-----------------------" << endl;
	cout << "CPP��ҳ���������£� " << endl;
	CPP cpp;
	cpp.header();
	cpp.footer();
	cpp.list();
	cpp.content();
}


int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}