#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
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
	//cin.get(ch); //��һ���ַ�
	//cout << "ch = " << ch << endl;
		
	//cin.get(��������) //���Զ��ַ���
	//���з��������ڻ�������
	char buf[1024] = { 0 };

	cin.get(buf, 1024);

	char ch = cin.get();
	if (ch == '\n')
	{
		cout << "���з������ڻ�������" << endl;
	}

	cout << "buf = " << buf << endl;
}

void test03()
{
	//cin.getline()
	char buf[1024] = { 0 };

	//���з������ڻ������У�����ֱ���ӵ�
	cin.getline(buf, 1024);

	char ch = cin.get();
	if (ch == '\n')
	{
		cout << "���з������ڻ�������" << endl;
	}

	cout << "buf = " << buf << endl;
}


//cin.ignore() ����
void test04()
{
	cin.ignore(2); //Ĭ�ϻ����һ���ַ������Դ�int��������������ַ�����
	char ch = cin.get();

	cout << "ch = " << ch << endl;
}


//cin.peek()
void test05()
{
	char ch = cin.peek(); //͵����һ�β鿴��������һ���ַ�
	cout << "ch = " << ch << endl;

	ch = cin.get();
	cout << "ch = " << ch << endl;
}

//cin.putback()
void test06()
{
	char ch = cin.get();

	cin.putback(ch); //�Żص�ԭ����λ��

	char buf[1024] = { 0 };
	cin.getline(buf, 1024);
	cout << "buf = " << buf << endl;

}

//����1 �� �û������ַ��� ���� ���� �������ж�
void test07()
{
	cout << "������һ�����ֻ����ַ���" << endl;
	char ch = cin.peek();

	if (ch >='0' && ch <='9')
	{
		int num;
		cin >> num;
		cout << "������������֣� " << num << endl;
	}
	else
	{
		char buf[1024] = { 0 };
		cin >> buf;
		cout << "����������ַ����� " << buf << endl;
	}
}

//����2�����û�����һ����������� 1 ~ 10 �����䣬���������ȷ����֤�ɹ�������ʧ�ܣ���������
void test08()
{
	int num = 0;

	cout << "������1~10֮�������" << endl;


	while (true)
	{
		cin >> num;

		if (num >= 1 && num <= 10)
		{
			cout << "������ȷ�� " << num << endl;
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

}

int main(){

	test08();

	system("pause");
	return EXIT_SUCCESS;
}