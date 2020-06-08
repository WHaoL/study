#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <stack>

/*
3.4.3.1 stack���캯��
stack<T> stkT;//stack����ģ����ʵ�֣� stack�����Ĭ�Ϲ�����ʽ��
stack(const stack &stk);//�������캯��
3.4.3.2 stack��ֵ����
stack& operator=(const stack &stk);//���صȺŲ�����
3.4.3.3 stack���ݴ�ȡ����
push(elem);//��ջ�����Ԫ��
pop();//��ջ���Ƴ���һ��Ԫ��
top();//����ջ��Ԫ��
3.4.3.4 stack��С����
empty();//�ж϶�ջ�Ƿ�Ϊ��
size();//���ض�ջ�Ĵ�С
*/

void test01()
{
	stack<int>s; //ջ����

	//��ջ
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);

	cout << "Ԫ�ظ����� " << s.size() << endl;

	//ֻҪջ��Ϊ�գ��鿴ջ�������ҳ�ջ
	while (!s.empty())
	{
		//ջ��Ԫ��
		cout << s.top() << endl;

		//��ջ
		s.pop();
	}

	cout << "Ԫ�ظ����� " << s.size() << endl;

}



int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}