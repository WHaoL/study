
// 减法，实现两个int类型数字相减，返回结果
// 默认是内部函数，只能在本库项目使用
//__declspec(dllexport) 特殊声明（ 动态库 导出函数 /外部函数） 
__declspec(dllexport) int mySub(int a, int b);

// 动态库中的.lib 和 静态库中的不同，动态库中的.lib存放的是.h中的变量的声明、导出函数的声明
//具体是实现放在.dll中
