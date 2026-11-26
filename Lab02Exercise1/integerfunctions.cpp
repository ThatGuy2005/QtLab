#include "integerfunctions.h"
#include <math.h>

int MyFunctions::lnko(int lhs, int rhs)
{
    return int(lhs*rhs/lkkt(lhs,rhs));
}

int MyFunctions::lkkt(int lhs, int rhs)
{
    lhs = abs(lhs);
    rhs = abs(rhs);

    if (lhs == 0 && rhs == 0) {
        throw "Undefined";
    }

    while (rhs != 0) {
        int temp = rhs;
        rhs = lhs % rhs;
        lhs = temp;
    }

    return lhs;
}