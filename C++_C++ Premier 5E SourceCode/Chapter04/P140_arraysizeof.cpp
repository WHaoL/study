 

#include "Version_test.h"

#include <iostream>
using std::cout; using std::endl;

#include <cstddef>
using std::size_t;

int ia[] = {0,1,2,3,4,5,6,7,8,9};

int main()
{
#ifdef CONSTEXPR_VARS
   // sizeof(ia)/sizeof(*ia) returns the number of elements in ia
   constexpr size_t sz = sizeof(ia)/sizeof(*ia);
#else
   const     size_t sz = sizeof(ia)/sizeof(*ia);
#endif

   int arr2[sz];  // ok sizeof returns a constant expression 

   cout << "ia size: " << sz << endl;

   return 0;
}
