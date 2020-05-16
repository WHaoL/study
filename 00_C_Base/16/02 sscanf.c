#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//sscanf
//1、%*s或%*d	跳过数据
void test01()
{
	char * str = "12345abcde";

	char buf[1024] = { 0 };

	sscanf(str, "%*d%s", buf);

	printf("buf:%s\n", buf);
}

void test02()
{
	char * str = "abcde12345"; //遇到空格或者遇到\t 结束忽略 

	char buf[1024] = { 0 };

	//sscanf(str, "%*s%s", buf);

	sscanf(str, "%*[a-z]%s", buf);

	printf("buf:%s\n", buf);
}


//2、%[width]s	读指定宽度的数据
void test03()
{
	char * str = "12345abcde";

	char buf[1024] = { 0 };

	sscanf(str, "%6s", buf);

	printf("buf:%s\n", buf);
}

//3、%[a-z]	匹配a到z中任意字符(尽可能多的匹配)
void test04()
{
	char * str = "12345abcde";

	char buf[1024] = { 0 };
	//如果匹配失败，就不在向后进行匹配
	sscanf(str, "%*d%[a-z]", buf);

	printf("buf:%s\n", buf);
}

//4、%[aBc]	匹配a、B、c中一员，贪婪性
void test05()
{
	char * str = "aaBbcde12345";

	char buf[1024] = { 0 };

	sscanf(str, "%[abc]", buf);

	printf("buf:%s\n", buf);
}

//5、%[^a] 	匹配非a的任意字符，贪婪性  
//%[^a-z]	表示读取除a-z以外的所有字符
void test06()
{
	char * str = "aaBbcde12345";

	char buf[1024] = { 0 };

	sscanf(str, "%[^0-9]", buf);

	printf("buf:%s\n", buf);

}

//案例1 ：有ip地址  127.0.0.1 将这个字符串中的每个数字分别放到num1 ~ num4中
void test07()
{
	char * ip = "127.0.0.1";

	int num1 = 0;
	int num2 = 0;
	int num3 = 0;
	int num4 = 0;

	sscanf(ip, "%d.%d.%d.%d", &num1, &num2, &num3, &num4);

	printf("num1 = %d\n", num1);
	printf("num2 = %d\n", num2);
	printf("num3 = %d\n", num3);
	printf("num4 = %d\n", num4);
}

//案例2 截取有效信息
void test08()
{
	char * str = "abcde#zhangtao@12345;aldkj";

	char buf[1024] = { 0 };

	sscanf(str, "%*[^#]#%[^@]",buf);

	printf("buf = %s\n", buf);

}

//案例3 已给定字符串为: helloworld@itcast.cn,请编码实现helloworld输出和itcast.cn输出
void test09()
{
	char * str = "helloworld@itcast.cn";

	char buf1[1024] = { 0 };
	char buf2[1024] = { 0 };

	sscanf(str, "%[a-z]%*[@]%s", buf1, buf2);

	printf("%s\n", buf1);
	printf("%s\n", buf2);
}

int main(){
	test09();


	system("pause");
	return EXIT_SUCCESS;
}