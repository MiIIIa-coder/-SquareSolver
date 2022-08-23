#include "sqr_solver.hpp"

bool is_null(double comp_digit)
{
    double small_compare_digit = 0.00001;
    if (fabs(comp_digit - 0.0) <= small_compare_digit)
        return true;
    return false;
}
