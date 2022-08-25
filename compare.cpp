/*!
  @file compare.cpp
  @brief Compares number with zero (equal or not).
*/

#include "sqr_solver.hpp"
#include "compare.hpp"

static const double eps = 0.00001;

bool is_null(double value)
{
    if (fabs(value - 0.0) <= eps)
        return true;
    return false;
}

bool is_equal(double n1, double n2)
{
    if (fabs(n1 - n2) <= eps)
        return true;
    return false;
}
