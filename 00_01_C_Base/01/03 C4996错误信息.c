//#define  _CRT_SECURE_NO_WARNINGS //加入宏 防止C4996的错误警告
//#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h> //system函数的头文件

int main()
{
	//在vs中 不建议使用传统的C库函数 scanf  sprintf  使用就报错，为了防止错误，需要引入一个宏

	//解决方式1  加入宏 #define  _CRT_SECURE_NO_WARNINGS   推荐！！！
	//解决方式2  #pragma warning(disable:4996)
	//解决方式3  属性里的预处理器，预处理定义中添加 宏 _CRT_SECURE_NO_WARNINGS

	char buf[1024] = { 0 };
	sprintf(buf, "%s", "helloworld");
	printf("%s\n", buf);
	

	system("pause");
	return 0;
}