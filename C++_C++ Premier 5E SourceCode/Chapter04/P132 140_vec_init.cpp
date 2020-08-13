
#include <cstddef>
using std::size_t;

#include <vector>
using std::vector;

#include <iostream>
using std::cout; using std::endl;

int main()
{
    
    vector<int> ivec;                // empty vector
    int cnt = 10;
    // add elements 10 . . . 1 to ivec
    while (cnt > 0)
        ivec.push_back(cnt--);       // int postfix decrement

	// P132
    auto iter = ivec.begin();
    // prints 10 9 8 . . . 1 
    while (iter != ivec.end())
        cout << *iter++ << endl; // iterator postfix increment

	// P140
	vector<int> vec2(10, 0);  // ten elements initially all 0
    cnt = vec2.size();
    // assign values from size . . . 1 to the elements in vec2
    for(vector<int>::size_type ix = 0; 
                    ix != vec2.size(); ++ix, --cnt)   
        vec2[ix] = cnt;

    iter = vec2.begin();
    // prints 10 9 8 . . . 1 
    while (iter != vec2.end())
        cout << *iter++ << endl; // iterator postfix increment

    return 0;
}
