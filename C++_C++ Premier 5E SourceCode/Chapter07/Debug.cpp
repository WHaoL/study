#include "Version_test.h"

#include "Debug.h"
// only implementation for the Debug classes are definitions
// for static members named enable 
#ifdef CONSTEXPR_CTORS
constexpr Debug HW_Subsystem::enable;
constexpr Debug IO_Subsystem::enable;
#else
const Debug HW_Subsystem::enable(true, false, false);
const Debug IO_Subsystem::enable(true, false, true);
#endif
