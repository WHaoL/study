#include <iostream>
using std::cin; using std::cout; using std::endl;

int main()
{
	freopen("./data/readme", "r", stdin);//以“只读访问”方式，将标准输入重定向到 “./data/readme 文件
	
    char ch;
    // initialize counters for each vowel
    unsigned vowelCnt = 0;
    unsigned otherCnt = 0;  // count anything that isn't a vowel

    while (cin >> ch) {
        // if ch is a vowel, increment the appropriate counter
        switch (ch) {
			case 'a': 
			case 'e': 
			case 'i': 
			case 'o': 
			case 'u':
				++vowelCnt;
				break;
            default:
                ++otherCnt;
                break;
        }
    }
    // print results
    cout << "Number of vowels: \t" << vowelCnt << '\n'
         << "Total non-vowels : \t" << otherCnt << '\n';

    return 0;
}
