/*!
  @file compare.cpp
  @brief Compares number with zero (equal or not).
*/

#include "sqr_solver.hpp"
#include "compare.hpp"

static const double EPS = 0.00001;

bool is_null(double value)
{
    return (fabs(value - 0.0) <= EPS);
}

bool is_equal(double n1, double n2)
{
    return (fabs(n1 - n2) <= EPS);
}
