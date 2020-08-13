/* This file uses list initialization, which is a feature that the
 * MS compiler may not yet support.  This file (and other source files)
 * uses preprocessor facilities to conditionally compile code that uses
 * list initialization or that uses a workaround instead.  
 *
 * Briefly, conditional compilation uses preprocessor variables
 * and #ifdef directives (see Section 2.6.3) to decide which code
 * to compile:
 *
 *     #ifdef VARIABLE_NAME
 *          code1
 *     #else
 *          code2
 *     #endif
 *
 * If there is a #define for VARIABLE_NAME then code1 will be compiled
 * and code2 is skipped.  Otherwise code1 is skipped and code2 is compiled.
 *
 * Depending on the version of the compiler that you are running,
 * the file ..\Version_test.h will either contain a #define for LIST_INIT
 * or not.  If it does #define LIST_INIT then the code that uses list
 * initialization will be compiled.  Otherwise, the workaround will be used.
 *
 * Section 6.5.3 covers conditional compilation in more detail. 
*/

#include "Version_test.h"  

#include "Sales_item.h"
#include <iostream>
#include <string>

int main() {

	int v1(1024);    // direct-initialization, functional form
#ifdef LIST_INIT
	int v2{1024};    // direct-initialization, list initializer form
#else
	int v2(1024);    // use parens if list-initialization not yet supported
#endif
	int v3 = 1024;   // copy-initialization
#ifdef LIST_INIT
	int v4 = {1024}; // copy-initialization, list initializer form
#else
    int v4 = 1024;
#endif

	// alternative ways to initialize string from a character string literal
	std::string titleA = "C++ Primer, 5th Ed.";
	std::string titleB("C++ Primer, 5th Ed.");
	std::string all_nines(10, '9');  // all_nines = "9999999999"

	return 0;
}
