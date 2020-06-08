#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//1、按字符读写
void test01()
{
	//写文件
	FILE * f_write = fopen("test1.txt", "w");

	if (f_write == NULL)
	{
		return;
	}

	char buf[1024] = "hello world";

	for (int i = 0; i < strlen(buf);i++)
	{
		fputc(buf[i], f_write);
	}
	fclose(f_write);


	//读文件
	FILE * f_read = fopen("test1.txt", "r");
	if (f_read == NULL)
	{
		return;
	}

	char ch;
	while ( (ch =fgetc(f_read)) != EOF ) // EOF   end of file
	{
		printf("%c", ch);
	}
	fclose(f_read);

}


//按行读写文件
void test02()
{
	//写文件
	FILE * f_write = fopen("test2.txt", "w");
	if (f_write == NULL)
	{
		return;
	}

	char * buf[] = {
		"锄禾日当午\n",
		"汗滴禾下土\n",
		"谁知盘中餐\n",
		"粒粒皆辛苦\n",
	};

	for (int i = 0; i < 4;i++)
	{
		fputs(buf[i], f_write);
	}

	fclose(f_write);


	//读文件
	FILE * f_read = fopen("test2.txt", "r");
	if (f_read == NULL)
	{
		return;
	}

	//feof函数
	while (!feof(f_read))
	{
		char temp[1024] = { 0 };
		fgets(temp, 1024, f_read);
		printf("%s", temp);
	}

	fclose(f_read);
}


//3、按块读写
struct Hero
{
	char name[64];
	int age;
};

void test03()
{
	//写文件
	FILE * f_write =fopen("test3.txt", "wb"); //二进制 写
	if (f_write == NULL)
	{
		return;
	}

	struct Hero heros[4] =
	{
		{ "刘备", 18 },
		{ "关羽", 19 },
		{ "张飞", 20 },
		{ "赵云", 21 },
	};
	
	for (int i = 0; i < 4;i++)
	{
		//块写
		fwrite(&heros[i], sizeof(struct Hero), 1, f_write);
	}

	//关闭文件
	fclose(f_write);


	//读文件
	FILE * f_read = fopen("test3.txt", "rb"); //二进制 写
	if (f_read == NULL)
	{
		return;
	}

	struct Hero temp[4];
	//将文件中数据读回到数组中
	fread(temp, sizeof(struct Hero), 4, f_read);

	for (int i = 0; i < 4;i++)
	{
		printf("姓名：%s  年龄:%d\n", temp[i].name, temp[i].age);
	}

	fclose(f_read);
}

//4、格式化读写
void test04()
{
	//写文件
	FILE * f_write = fopen("test4.txt", "w");
	if (f_write == NULL)
	{
		return;
	}
	fprintf(f_write, "hello world %d", 111);

	fclose(f_write);

	//读文件
	FILE * f_read = fopen("test4.txt", "r");
	if (f_read == NULL)
	{
		return;
	}
	char buf[1024] = { 0 };

	while (!feof(f_read))
	{
		fscanf(f_read, "%s", buf);
		printf("%s\n", buf);
	}
	fclose(f_read);
}


//随机位置读写
void test05()
{
	//写文件
	FILE * f_write = fopen("test5.txt", "wb"); //二进制 写
	if (f_write == NULL)
	{
		return;
	}

	struct Hero heros[4] =
	{
		{ "刘备", 18 },
		{ "关羽", 19 },
		{ "张飞", 20 },
		{ "赵云", 21 },
	};

	for (int i = 0; i < 4; i++)
	{
		//块写
		fwrite(&heros[i], sizeof(struct Hero), 1, f_write);
	}

	//关闭文件
	fclose(f_write);



	//随机位置读
	FILE * f_read = fopen("test5.txt", "rb");
	if (f_read == NULL)
	{
		perror("fopen error"); // errno 宏
		return;
	}

	struct Hero temp; //创建临时结构体  读取张飞数据
	//移动文件指针
	//fseek(f_read,2*sizeof(struct Hero) , SEEK_SET);

	fseek(f_read, - (long )sizeof(struct Hero) * 2, SEEK_END);

	rewind(f_read); //文件光标置首

	fread(&temp, sizeof(struct Hero), 1, f_read);

	printf("姓名:%s 年龄:%d\n", temp.name, temp.age);

	fclose(f_read);

}

int main(){

	test05();

	system("pause");
	return EXIT_SUCCESS;
}