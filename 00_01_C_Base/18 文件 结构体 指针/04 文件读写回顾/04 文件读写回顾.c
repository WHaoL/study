#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//1�����ַ���д
void test01()
{
	//д�ļ�
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


	//���ļ�
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


//���ж�д�ļ�
void test02()
{
	//д�ļ�
	FILE * f_write = fopen("test2.txt", "w");
	if (f_write == NULL)
	{
		return;
	}

	char * buf[] = {
		"�����յ���\n",
		"���κ�����\n",
		"˭֪���в�\n",
		"����������\n",
	};

	for (int i = 0; i < 4;i++)
	{
		fputs(buf[i], f_write);
	}

	fclose(f_write);


	//���ļ�
	FILE * f_read = fopen("test2.txt", "r");
	if (f_read == NULL)
	{
		return;
	}

	//feof����
	while (!feof(f_read))
	{
		char temp[1024] = { 0 };
		fgets(temp, 1024, f_read);
		printf("%s", temp);
	}

	fclose(f_read);
}


//3�������д
struct Hero
{
	char name[64];
	int age;
};

void test03()
{
	//д�ļ�
	FILE * f_write =fopen("test3.txt", "wb"); //������ д
	if (f_write == NULL)
	{
		return;
	}

	struct Hero heros[4] =
	{
		{ "����", 18 },
		{ "����", 19 },
		{ "�ŷ�", 20 },
		{ "����", 21 },
	};
	
	for (int i = 0; i < 4;i++)
	{
		//��д
		fwrite(&heros[i], sizeof(struct Hero), 1, f_write);
	}

	//�ر��ļ�
	fclose(f_write);


	//���ļ�
	FILE * f_read = fopen("test3.txt", "rb"); //������ д
	if (f_read == NULL)
	{
		return;
	}

	struct Hero temp[4];
	//���ļ������ݶ��ص�������
	fread(temp, sizeof(struct Hero), 4, f_read);

	for (int i = 0; i < 4;i++)
	{
		printf("������%s  ����:%d\n", temp[i].name, temp[i].age);
	}

	fclose(f_read);
}

//4����ʽ����д
void test04()
{
	//д�ļ�
	FILE * f_write = fopen("test4.txt", "w");
	if (f_write == NULL)
	{
		return;
	}
	fprintf(f_write, "hello world %d", 111);

	fclose(f_write);

	//���ļ�
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


//���λ�ö�д
void test05()
{
	//д�ļ�
	FILE * f_write = fopen("test5.txt", "wb"); //������ д
	if (f_write == NULL)
	{
		return;
	}

	struct Hero heros[4] =
	{
		{ "����", 18 },
		{ "����", 19 },
		{ "�ŷ�", 20 },
		{ "����", 21 },
	};

	for (int i = 0; i < 4; i++)
	{
		//��д
		fwrite(&heros[i], sizeof(struct Hero), 1, f_write);
	}

	//�ر��ļ�
	fclose(f_write);



	//���λ�ö�
	FILE * f_read = fopen("test5.txt", "rb");
	if (f_read == NULL)
	{
		perror("fopen error"); // errno ��
		return;
	}

	struct Hero temp; //������ʱ�ṹ��  ��ȡ�ŷ�����
	//�ƶ��ļ�ָ��
	//fseek(f_read,2*sizeof(struct Hero) , SEEK_SET);

	fseek(f_read, - (long )sizeof(struct Hero) * 2, SEEK_END);

	rewind(f_read); //�ļ��������

	fread(&temp, sizeof(struct Hero), 1, f_read);

	printf("����:%s ����:%d\n", temp.name, temp.age);

	fclose(f_read);

}

int main(){

	test05();

	system("pause");
	return EXIT_SUCCESS;
}