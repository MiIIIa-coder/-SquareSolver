#include "sqr_solver.hpp"

bool comparing(double comp_digit)
{
    if (fabs(comp_digit - 0.0) <= 0.00001)
        return true;
    else
        return false;
}
