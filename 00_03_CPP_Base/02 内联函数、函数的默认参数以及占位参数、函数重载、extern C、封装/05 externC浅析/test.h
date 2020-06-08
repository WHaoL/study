#ifdef __cplusplus  // __ 两个下划线  c  plus  plus
extern "C" {
#endif

// extern "C"的主要作用就是为了实现c++代码能够调用其他c语言代码。
// 加上extern "C"后，这部分代码编译器按c语言的方式进行编译和链接，而不是按c++的方式。




#pragma  once 
#include <stdio.h>

	void show();






#ifdef __cplusplus
}
#endif