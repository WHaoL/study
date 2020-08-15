#include <cstdlib>
/* EXIT_FAILURE and EXIT_SUCCESS are preprocessor variables
 *       such variables are not in the std namespace, 
 *       hence, no using declaration and no std:: when we use these names
*/
int main()
{
    bool some_failure = false;
    if (some_failure)
        return EXIT_FAILURE;  // defined in cstdlib
    else
        return EXIT_SUCCESS;  // defined in cstdlib
}
