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
	printf("                 ���汣��       ����BUG			\n");
	system("pause");
	system("cls");
}

void test04()
{
	system("cls");
	printf("    ������ ����\n");
	printf("  ������ �����ߩ���\n");
	printf("  �������������� ��\n");
	printf("  ������������   ��\n");
	printf("  ���ש������ס� ��\n");
	printf("  �������������� ��\n");
	printf("  ����  �ߡ����� ��\n");
	printf("  �������������� ��\n");
	printf("  ������   ��������\n");
	printf("      ����������   ���ޱ���\n");
	printf("      ����������   ������BUG��\n");
	printf("      ����������������������\n");
	printf("      ����������������    �ǩ�\n");
	printf("      ����������        ����\n");
	printf("      �������������ש�����\n");
	printf("          ���ϩ�  ���ϩ�\n");
	printf("          ���ߩ�  ���ߩ�\n");

	system("pause");
	system("cls");
}






void show_Menu()
{
	printf("********************************************\n");
	printf("*************      C���Ի���   *************\n");
	printf("*************      1.Ƥ����    *************\n");
	printf("*************      2.��Ů      *************\n");
	printf("*************      3.����      *************\n");
	printf("*************      4.����      *************\n");
	printf("*************      0.�˳�      *************\n");
	printf("********************************************\n");
	printf("\n");
}


int main(){

	int choice = 0; //�����洢�û���ѡ��

	while (1)
	{
		show_Menu();

		printf("����������ѡ��\n");
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
			system("cls"); //����
			break;
		}
	}


	system("pause");
	return EXIT_SUCCESS;
}