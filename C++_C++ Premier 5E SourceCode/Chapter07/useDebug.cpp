#include "Version_test.h"

#include <iostream>
using std::cerr; using std::endl;

#include "Debug.h"

int main()
{
#ifdef CONSTEXPR_VARS
	constexpr Debug io_sub(false, true, false);  // debugging IO    
#else
	const     Debug io_sub(false, true, false);  // debugging IO    
#endif
	if (io_sub.any())  // equivalent to if(true)
		cerr << "print appropriate error messages" << endl;

#ifdef CONSTEXPR_VARS
	constexpr Debug prod(false); // no debugging during production
#else
	const     Debug prod(false); // no debugging during production
#endif
	if (prod.any())    // equivalent to if(false)
		cerr << "print an error message" << endl;

	IO_Subsystem ioErrs;        // by default, don't print any debugging
	// no debugging here
	if (ioErrs.default_debug()) // if (false || debug.any())
		cerr << "print message 3" << endl;
	ioErrs.set_debug(true);     // turn on debugging
	if (ioErrs.default_debug()) // if (false || debug.any())
		cerr << "print message 4" << endl;
	ioErrs.set_debug(false);    // okay, debugging section complete

	HW_Subsystem hw;
	hw.set_debug(true);
	if (ioErrs.default_debug() || hw.default_debug()) // if (false || debug.any())
		cerr << "print message 5" << endl;
}
