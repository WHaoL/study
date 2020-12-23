#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//字符数组定义方式
void test01()
{
    char ch[5]; //声明字符数组 ，每个元素是 char类型，一共有5个元素
    printf("sizeof = %d\n", sizeof(ch));
}

//操作字符数组
void test02()
{
    //逐个初始化字符数组
    //char arr[5] = { 'h', 'e', 'l', 'l', 'o' }; //error 因为没有\0 输出乱码
    //char arr[6] = { 'h', 'e', 'l', 'l', 'o','\0' }; // '\0' 本质就是0

    char arr[] = "hello"; //自带 \0

    //遍历字符数组
    //for (int i = 0; i < sizeof(arr) / sizeof(char); i++)
    //{
    //	printf("%c", arr[i]);
    //}
    //printf("\n");

    printf("%s\n", arr); //%s 从开始 arr  到结束 \0
}

//字符串统计
void test03()
{
    char buf1[32] = "hello world";

    printf("%d\n", strlen(buf1)); //strlen(字符数组名) 统计字符串长度  不统计\0
    printf("%d\n", sizeof(buf1)); //统计数组占用内存空间大小

    char buf2[] = "hello world";
    printf("buf2 strlen = %d\n", strlen(buf2)); //11
    printf("buf2 sizeof = %d\n", sizeof(buf2)); //12

    char buf3[] = "hello\0world";
    printf("buf3 strlen = %d\n", strlen(buf3)); //5  统计到\0结束
    printf("buf3 sizeof = %d\n", sizeof(buf3)); //12

    //  / / \\ 1 \123 a b c \xac h e h e
    char buf4[] = "//\\1\123abc\xachehe";

    printf("buf4 strlen = %d\n", strlen(buf4)); //13
    printf("buf4 sizeof = %d\n", sizeof(buf4)); //13 + 1 = 14
}

//字符数组输入
void test04()
{
    //创建字符数组并且初始化为空
    //char buf[16] = "";
    char buf[16] = {0};

    scanf("%s", buf); //遇到空格 结束输入
    printf("%s\n", buf);
}

//gets 不推荐
void test05()
{
    char buf[16] = {0};
    gets(buf);
    //可以输入空格在字符数组中
    //不会检测数据是否溢出，一旦溢出（越界）非常操作内存，程序终止
    printf("%s\n", buf);
}

//fgets() 推荐
void test06()
{
    char buf[16] = {0};
    fgets(buf, sizeof(buf), stdin); //stdin标准输入设备 代表键盘
    printf("%s\n", buf);
}

//字符串输出 puts  fputs
void test07()
{
    char buf[16] = "hello world";

    printf("%s\n", buf); //常用
    puts(buf);           //自带换行
    fputs(buf, stdout);  //stdout代表标准输出设备 屏幕   不带换行
}

int main()
{

    test07();

    system("pause");
    return EXIT_SUCCESS;
}