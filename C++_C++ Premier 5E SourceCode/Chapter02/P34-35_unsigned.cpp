#include <iostream>

int main() //if 32-bit ints
{
    // P35 2.3
    unsigned u = 10, u2 = 42, u3 = -1;
    std::cout << u3 << std::endl;     // 4294967295
    std::cout << -u2 << std::endl;    // 4294967254 : 42取反-->4294967253   加1-->4294967254
    std::cout << u2 - u << std::endl; // 32
    std::cout << u - u2 << std::endl; // 4294967264 : 4294967254+10-->4294967264

    // P35 2.4
    int i = 10, i2 = 42;
    std::cout << i2 - i << std::endl; // 32
    std::cout << i - i2 << std::endl; // -32

    u = 42;
    i = 10;
    std::cout << i - u << std::endl; // 4294967264 ：10 + 4294967254
    std::cout << u - i << std::endl; // 32

    u = 10;
    i = -42;
    std::cout << i + i << std::endl; // prints -84
    std::cout << u + i << std::endl; // if 32-bit ints, prints 4294967264

    // P34
    i = 10;
    std::cout << "good" << std::endl;
    while (i >= 0)
    {
        std::cout << i << std::endl;
        --i;
    }
    // P34
    for (int i = 10; i >= 0; --i)
        std::cout << i << std::endl;
    // P34
    for (unsigned u = 0; u <= 10; ++u)
        std::cout << u << std::endl; // prints 0 . . . 10

    /* NOTE: the condition in the following loop 
         will run indefinitely
	// WRONG: u can never be less than 0; the condition will always succeed
	for (unsigned u = 10; u >= 0; --u)
    	std::cout << u << std::endl;
    */
    // P34
    u = 11; // start the loop one past the first element we want to print
    while (u > 0)
    {
        --u; // decrement first, so that the last iteration will print 0
        std::cout << u << std::endl;
    }

    // be wary of comparing ints and unsigned
    u = 10;
    i = -42;
    if (i < u) // false: i is converted to unsigned
        std::cout << "i = " << i << std::endl;
    else
        std::cout << "u = " << u << std::endl; // prints 10

    u = 42;
    u2 = 10;
    std::cout << u - u2 << std::endl; // ok: result is 32
    std::cout << u2 - u << std::endl; // ok: but the result will wrap around // 4294967264
}
