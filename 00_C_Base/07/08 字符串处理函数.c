#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//1、strcpy  字符串拷贝
void test01()
{
	char buf[64] = {0};

	//buf = "hello world";  //error

	////字符串赋值
	strcpy(buf, "hello world");
	printf("buf = %s\n", buf);

	//strcpy遇到\0结束拷贝
	//strcpy(buf, "hello\0world");
	//printf("buf = %s\n", buf);


	//如果目标空间不足，程序出现异常终止
	char buf2[10] = { 0 };
	//strcpy(buf2, "hello world"); //error 目标空间不足
	//printf("buf = %s\n", buf2);
}

//2、strncpy
void test02()
{
	char buf[64] = {0};
	strncpy(buf, "hello world", 8);
	printf("buf = %s\n", buf); //hello wo

	char buf2[64] = { 0 };
	strncpy(buf2, "hello\0world", 8);
	printf("buf2 = %s\n", buf2);  //hello

}

//3、strcat  strncat 字符串拼接
void test03()
{
	char buf1[64] = "hello";  //hello world\0
	char buf2[64] = " world";

	strcat(buf1, buf2);
	printf("%s\n", buf1); //hello world

	strncat(buf1, buf2, 3);
	printf("%s\n", buf1);  //hello world wo
}


//4、strcmp  字符串对比
void test04()
{
	char buf1[64] = "hello";
	printf("%s\n", buf1);

	printf("请输入一个字符串\n");
	char buf2[64] = "";

	fgets(buf2, sizeof(buf2), stdin);

	//hello\n 将\n改为\0
	buf2[strlen(buf2) - 1] = '\0';

	if ( strcmp(buf1,buf2) ==0) //使用比较多
	{
		printf("buf1 == buf2\n");
	}
	else if (strcmp(buf1, buf2) == 1)  //本质返回的是1
	{
		printf("buf1 > buf2\n");
	}
	else if (strcmp(buf1, buf2) == -1) //本质返回-1
	{
		printf("buf1 < buf2\n");
	}
}

//5、 strncmp 字符串对比
void test05()
{
	printf("请输入一个季节 spring summer autumn winter\n");
	char buf[64] = { 0 };
	fgets(buf, 64, stdin);
	buf[strlen(buf) - 1] = '\0';

	if (strncmp(buf, "spring", 6) == 0)
	{
		printf("春天\n");
	}
	else if (strncmp(buf, "summer", 6) == 0)
	{
		printf("夏天\n");
	}
	else if (strncmp(buf, "autumn", 6) == 0)
	{
		printf("秋天\n");
	}
	else if (strncmp(buf, "winter", 6) == 0)
	{
		printf("冬天\n");
	}

}


//sprintf
void test06()
{
	char buf[64] = { 0 };

	//格式化输出到字符串中
	//sprintf(buf, "今天是%d 年 %d月 %d日", 2019, 5, 20);
	sprintf(buf, "hello world");
	printf("buf = %s\n", buf);
}

//sscanf 字符串拆分
void test07()
{
	char msg[1024] = "phone:13690000000;2019/5/20;该还钱了";

	unsigned long long phone = 0;
	int year = 0;
	int month = 0;
	int day = 0;
	char content[64] = { 0 };

	sscanf(msg, "phone:%llu;%d/%d/%d;%s", &phone, &year, &month, &day, content);

	printf("%llu\n", phone);
	printf("%d\n", year);
	printf("%d\n", month);
	printf("%d\n", day);
	printf("%s\n", content);
}

//strchr 字符查找
void test08()
{
	char buf[1024] = "zhangtao@sina.com";

	char * ret = strchr(buf, '@');

	if (ret == NULL)
	{
		printf("没有@字符\n");
	}
	else
	{
		printf("有@字符\n");
		printf("位置在 %d\n", ret - buf);
	}
}
//strstr 字符串查找
void test09()
{
	char src[] = "ddddabcd123abcd333abcd";
	//参数1  源字符串   参数2  查找的字符串    
	//返回值 在源字符串中出现目标字符串的首字母的地址
	char *p = strstr(src, "abcd");
	if (p == NULL)
	{
		printf("没有找到目标字符串\n");
	}
	else
	{
		printf("找到了目标字符串\n");
		printf("p = %s\n", p);
	}
}

//字符串查找案例
void test10()
{
	/*
	"sb上单 sb sb"
	"**上单 ** **"
	*/

	char buf[1024] = { 0 };
	fgets(buf, sizeof(buf), stdin);
	buf[strlen(buf) - 1] = '\0';

	char * p = buf;
	while (1)
	{
		//"sb上单 sb sb abcde"  
		// p
		char * ret = strstr(p, "sb"); 

		if (ret != NULL) //找到了sb禁语
		{
			strncpy(ret, "**", 2);
			p = ret + 2;
		}
		else
		{
			break; //没有禁语 退出循环
		}

	}
	printf("%s\n", buf);
}

//strtok 字符串分割
void test11()
{
	//char buf[1024] = "张三丰:李四:王五:赵六:哈哈:呵呵";

	//char* names[64] = { 0 };//将buf中的信息按照:分割，放入到字符串数组names中

	//int i = 0;
	//names[i] = strtok(buf, ":");

	//while ( names[i] != NULL)
	//{
	//	i++;
	//	names[i] = strtok(NULL, ":");
	//}

	////遍历字符串数组
	//i = 0;
	//while (names[i] != NULL)
	//{
	//	printf("%s\n", names[i++]);
	//}


	//提高 优化代码
	char buf[1024] = "张三丰:李四:王五:赵六:哈哈:呵呵";

	char* names[64] = { buf,NULL };//将buf中的信息按照:分割，放入到字符串数组names中

	int i = 0;
	while ( (names[i++]= strtok(names[i],":")) != NULL)
	{
		//i++;
	}

	//遍历字符串数组
	i = 0;
	while (names[i] != NULL)
	{
		printf("%s\n", names[i++]);
	}

}

void test12()
{
	char buf[1024] = "张三丰:李四!王五#赵六******哈哈@@@@呵呵";

	char* names[64] = { buf, NULL };

	int i = 0;
	while ((names[i++] = strtok(names[i], ":!#*@")) != NULL)
	{
		//i++;
	}

	//遍历字符串数组
	i = 0;
	while (names[i] != NULL)
	{
		printf("%s\n", names[i++]);
	}

}

//atoi 将字符串转为int
void test13()
{
	char buf[1024] = "123abc";

	int num = 0;

	num = atoi(buf);

	printf("%d\n", num);


	//还有一个函数也可以做到 将字符串转为int


	int num1 = 0;
	int num2 = 0;

	sscanf("456 789", "%d %d", &num1,&num2);
	printf("num1 = %d\n", num1);
	printf("num2 = %d\n", num2);

}

int main(){

	test13();

	system("pause");
	return EXIT_SUCCESS;
}