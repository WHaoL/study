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

#ifndef SALES_DATA_H
#define SALES_DATA_H

#include "Version_test.h"

#include <string>

struct Sales_data 
{
	std::string bookNo;
#ifdef IN_CLASS_INITS
	unsigned units_sold = 0;
	double revenue = 0.0;
#else
	unsigned units_sold;  
	double revenue;
#endif
};
#endif
