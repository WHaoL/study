#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <iomanip>  //���Ʒ���ͷ�ļ�

/*
cout.put() //�򻺳���д�ַ�
cout.write() //��buffer��дnum���ֽڵ���ǰ������С�
*/

void test01()
{
	//cout.put('h').put('e').put('l');

	//char buf[] = "hello world";

	//cout.write(buf, strlen(buf));

	cout << "hello world" << endl;
}

//1ͨ������Ա����
void test02(){

	int number = 99;
	cout.width(5);  //���ÿ��
	cout.fill('*');  //���
	cout.setf(ios::left);  //�����
	cout.unsetf(ios::dec); //ж��ʮ����
	cout.setf(ios::hex); //����ʮ������
	cout.setf(ios::showbase);  //��ʾ����
	cout.unsetf(ios::hex);
	cout.setf(ios::oct);  //���ð˽���
	cout << number << endl;
}

//2 ͨ�����Ʒ�
void test03(){

	int number = 99;
	cout << setw(20)  //���ÿ��
		 << setfill('~')  //�������
		 << setiosflags(ios::showbase)  //��ʾ����
		 << setiosflags(ios::left) //���������
		 << hex   //ʮ������
		 << number
		 << endl;

}



int main(){

	test03();

	system("pause");
	return EXIT_SUCCESS;
}