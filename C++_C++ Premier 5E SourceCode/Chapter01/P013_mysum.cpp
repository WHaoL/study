#include <iostream> 

int main() 
{
    //以“只读访问”方式，将标准输入重定向到 “./data/mysum” 文件
    freopen("./data/mysum", "r", stdin);
	
	int sum = 0, value = 0;

	// read until end-of-file, calculating a running total of all values read
	while (std::cin >> value) 
		sum += value; // equivalent to sum = sum + value

	std::cout << "Sum is: " << sum << std::endl;
	return 0;
}
