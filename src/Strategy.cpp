#include "Strategy.h"

/*
 * Implement your search strategy.
 */
void searchStrategy(z3::expr_vector &OldVec)
{ /* Add your code here */
    int size = OldVec.size();
    OldVec[size-1] = not(OldVec[size-1]);
}
