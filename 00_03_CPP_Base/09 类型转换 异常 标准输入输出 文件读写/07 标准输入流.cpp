//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

/*
cin.get() //һ��ֻ�ܶ�ȡһ���ַ�
cin.get(һ������) //��һ���ַ�
cin.get(��������) //���Զ��ַ���
cin.getline()
cin.ignore()
cin.peek()
cin.putback()
*/

void test01()
{
	char ch = cin.get();
	cout << "ch = " << ch << endl;

	ch = cin.get();
	cout << "ch = " << ch << endl;

	ch = cin.get();
	cout << "ch = " << ch << endl;

	ch = cin.get();
	cout << "ch = " << ch << endl;
	//����as����һ�����a���ڶ���s�������� ���� ���Ĵεȴ��´�����
}

void test02()
{
	//char ch;
	//cin.get(ch);
	//��һ���ַ�
	//cout << "ch = " << ch << endl;

	//cin.get(��������)
	//���Զ��ַ���
	//���ǻ��з��������ڻ�������
	char buf[1024] = {0};
	cin.get(buf, 1024);
	cout << "test02()��buf = " << buf << endl;

	char ch = cin.get();
	if (ch == '\n')
	{
		cout << "ch == \\n"
			 << endl;
		cout << "���з������ڻ�������" << endl;
		cout << ch;
		cout << "���з������ڻ�������" << endl;
	}
}

void test03()
{
	//cin.getline()   ע�⣺���з������ڻ������У�����ֱ���ӵ�
	char buf[1024] = {0};
	cin.getline(buf, 1024);
	cout << "test03()��buf = " << buf << endl;

	char ch = cin.get(); //'\n'�Ѿ����ӵ��ˣ�������Ҫ�ٴ�����cin.get()���ܶ���һ���ַ�
	do
	{
		if (ch == '\n')
		{
			cout << "���з������ڻ�������" << endl;
			break;
		}
		cout << "test03()��ch = " << ch << endl;
	} while (0);

	cout << "test03()��buf = " << buf << endl;
}

//cin.ignore() ����
void test04()
{
	cin.ignore(2); //Ĭ�ϻ����һ���ַ������Դ�int��������������ַ�����
	char ch = cin.get();

	cout << "test04()��ch = " << ch << endl;
}

//cin.peek()
void test05()
{
	char ch = cin.peek(); //��ǰ�鿴һ���ַ�(�����ߣ�ֻ�鿴)��һ�β鿴��������һ���ַ�
	cout << "test05()��cin.peek() ch = " << ch << endl;

	ch = cin.get();
	cout << "test05()��cin.get() ch = " << ch << endl;
}

//cin.putback()
void test06()
{
	char ch = cin.get();

	cin.putback(ch); //�Żص�ԭ����λ��

	char buf[1024] = {0};
	cin.getline(buf, 1024);
	cout << "buf = " << buf << endl;
}

//����1 �� �û������ַ��� ���� ���� �������ж�
void test07()
{
	cout << "test07()����ʼ" << endl;
	cout << "������һ�����ֻ����ַ���" << endl; // һ���������������������
	char ch = cin.peek();

	if (ch >= '0' && ch <= '9')
	{
		int num;
		cin >> num; //��
		cout << "test07()��������������֣� " << num << endl;
	}
	else
	{
		char buf[1024] = {0};
		cin >> buf;
		cout << "test07()������������ַ����� " << buf << endl;
	}

	//cin.getline()   ע�⣺���з������ڻ������У�����ֱ���ӵ�
	char buf[1024] = {0};
	cin.getline(buf, 1024); // Ӧ����ֻ������һ�� '\n'
	cout << "test07()��buf = " << buf << endl;
	cout << "test07()������" << endl;
}

//����2�����û�����һ����������� 1 ~ 10 �����䣬���������ȷ����֤�ɹ�������ʧ�ܣ���������
void test08()
{
	cout << "test08()����ʼ" << endl;
	int num = 0;

	cout << "������1~10֮�������" << endl;

	while (true)
	{
		cin >> num;

		if (num >= 1 && num <= 10)
		{
			cout << "������ȷ�� " << num << endl;
			cout << "��־λ�� " << cin.fail() << endl;
			break;
		}
		//cout << "������������������" << endl;

		//���ñ�־λ
		cin.clear();
		//ˢ�»�����
		cin.sync(); //vs�߼��汾ʧЧ������getline��������������ȫ��ȡ��

		//��־λ ���� 0  �쳣  1
		cout << "��־λ�� " << cin.fail() << endl;
	}

	cout << "test08()������" << endl;
}

int main()
{
	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	//test06();
	//test07();
	test08();

	//system("pause");
	return EXIT_SUCCESS;
}