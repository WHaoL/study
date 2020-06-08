#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void test01()
{
	system("cls");
	printf("     `;-.          ___,\n");
	printf("       `.`\\_...._/`.-\"`\n");
	printf("         \\        /      ,\n");
	printf("         /()   () \\    .' `-._\n");
	printf("        |)  .    ()\\  /   _.'\n");
	printf("        \\  -'-     ,; '. <\n");
	printf("         ;.__     ,;|   > \n");
	printf("        / ,    / ,  |.-'.-'\n");
	printf("       (_/    (_/ ,;|.<`\n");
	printf("         \\    ,     ;-`\n");
	printf("          >   \\    /\n");
	printf("         (_,-'`> .'\n");
	printf("              (_,' \n");


	system("pause");
	system("cls");
}

void test02()
{
	system("cls");
	printf("                       .::::.\n");
	printf("                     .::::::::.	\n");
	printf("                    :::::::::::	\n");
	printf("                 ..:::::::::::'\n");
	printf("              '::::::::::::'\n");
	printf("                .::::::::::\n");
	printf("           '::::::::::::::..\n");
	printf("                ..::::::::::::.\n");
	printf("              ``::::::::::::::::\n");
	printf("               ::::``:::::::::'        .:::.\n");
	printf("              ::::'   ':::::'       .::::::::.\n");
	printf("            .::::'      ::::     .:::::::'::::.\n");
	printf("           .:::'       :::::  .:::::::::' ':::::.\n");
	printf("          .::'        :::::.:::::::::'      ':::::.\n");
	printf("         .::'         ::::::::::::::'         ``::::.\n");
	printf("     ...:::           ::::::::::::'              ``::.\n");
	printf("    ```` ':.          ':::::::::'                  ::::..\n");
	printf("                       '.:::::'                    ':'````..\n");

	system("pause");
	system("cls");
}

void test03()
{
	system("cls");
	printf("                       _ooOoo_ \n");
	printf("                      o8888888o	\n");
	printf("                      88\" . \"88\n");
	printf("                      (| -_- |)	\n");
	printf("                      O\\  =  /O	\n");
	printf("                   ____/`---'\\____\n");
	printf("                 .'  \\\\|     |//  `.\n");
	printf("                /  \\\\|||  :  |||//  \\\n");
	printf("               /  _||||| -:- |||||-  \\\n");
	printf("               |   | \\\\\\  -  /// |   |\n");
	printf("               | \\_|  ''\\---/''  |   |\n");
	printf("               \\  .-\\__  `-`  ___/-. /\n");
	printf("             ___`. .'  /--.--\\  `. . __\n");
	printf("          ."" '<  `.___\\_<|>_/___.'  >'"".\n");
	printf("         | | :  `- \\`.;`\\ _ /`;.`/ - ` : | |\n");
	printf("         \\  \\ `-.   \\_ __\\ /__ _/   .-` /  /\n");
	printf("    ======`-.____`-.___\\_____/___.-`____.-'======\n");
	printf("                       `=---='					\n");
	printf("   ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
	printf("                 佛祖保佑       永无BUG			\n");
	system("pause");
	system("cls");
}

void test04()
{
	system("cls");
	printf("    ┏┓　 ┏┓\n");
	printf("  ┏┛┻ ━┛┻━┓\n");
	printf("  ┃　　　　　　 ┃\n");
	printf("  ┃　　━　　   ┃\n");
	printf("  ┃┳┛　┗┳　 ┃\n");
	printf("  ┃　　　　　　 ┃\n");
	printf("  ┃　  ┻　　　 ┃\n");
	printf("  ┃　　　　　　 ┃\n");
	printf("  ┗━┓   ┏━━┛\n");
	printf("      ┃　　　┃   神兽保佑\n");
	printf("      ┃　　　┃   代码无BUG！\n");
	printf("      ┃　　　┗━━━━━┓\n");
	printf("      ┃　　　　　　　    ┣┓\n");
	printf("      ┃　　　　        ┏┛\n");
	printf("      ┗━┓┓┏━┳┓┏┛\n");
	printf("          ┃┫┫  ┃┫┫\n");
	printf("          ┗┻┛  ┗┻┛\n");

	system("pause");
	system("cls");
}






void show_Menu()
{
	printf("********************************************\n");
	printf("*************      C语言画画   *************\n");
	printf("*************      1.皮卡丘    *************\n");
	printf("*************      2.美女      *************\n");
	printf("*************      3.佛祖      *************\n");
	printf("*************      4.神兽      *************\n");
	printf("*************      0.退出      *************\n");
	printf("********************************************\n");
	printf("\n");
}


int main(){

	int choice = 0; //用来存储用户的选项

	while (1)
	{
		show_Menu();

		printf("请输入您的选择：\n");
		scanf("%d", &choice);
		

		switch (choice)
		{
		case 1: 
			test01();
			break;
		case 2:  
			test02();
			break;
		case 3: 
			test03();
			break;
		case 4:  
			test04();
			break;
		case 0:
			exit(0);
			break;
		default:
			system("cls"); //清屏
			break;
		}
	}


	system("pause");
	return EXIT_SUCCESS;
}