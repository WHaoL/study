#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void test01()
{
	//给电影评分
	//10 ~ 9  经典
	//8 ~ 7  非常好
	//6 ~ 5  一般
	//5以下   烂片

	int score = 0;
	printf("请给电影打分：\n");

	scanf("%d", &score);
	printf("您给的分数是：%d\n", score);

	switch (score) //switch中的表达式类型，只能是整型或者字符型
	{
	case 10:
		//printf("经典\n");
		//break;  //利用break结束分支
	case  9:
		printf("经典\n");
		break;
	case  8:
		//printf("非常好\n");
		//break;
	case  7:
		printf("非常好\n");
		break;
	case  6:
		//printf("一般\n");
		//break;
	case  5:
		printf("一般\n");
		break;
	default: //默认的分支
		printf("烂片\n");
		break;
	}
	//总结：与if语句比较，对于多条件判断时候，switch结构比较清晰，执行效率高， 缺点判断区间不方便
}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}