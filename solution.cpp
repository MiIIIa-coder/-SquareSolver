/*!
  @file solution.cpp
  @brief Includes functions for all cases of equation.
*/

#include "sqr_solver.hpp"
#include "compare.hpp"

void solver(double a, double b, double c, int *count_ans, double *x1, double *x2)
{
    ASSERT(x1 != 0);
    ASSERT(x2 != 0);
    ASSERT(count_ans != 0);
    ASSERT(a != INFINITY);
    ASSERT(b != INFINITY);
    ASSERT(c != INFINITY);

    if (is_null(a))
        *count_ans = line_equation(b, c, x1);    // a == 0
    else if (is_null(b) && c <= 0)
        *count_ans = b_null(a, c, x1, x2);       // b == 0
    else if (is_null(c))
        *count_ans = c_null(a, b, x1, x2);       // c == 0
    else
        *count_ans = sqr_solve(a, b, c, x1, x2); // solving sqr equation
}

Amount_Root line_equation(double b, double c, double *x1)
{
    ASSERT(x1 != NULL);
    ASSERT(b != INFINITY);
    ASSERT(c != INFINITY);

    if (is_null(b) && is_null(c))    // all zeros
        return INFINITY_ROOT;

    else if (!is_null(b)) {          // linear kind
        *x1 = -c/b;
        return ONE_ROOT;
    }

    return ZERO_ROOT;
}

Amount_Root b_null(double a, double c, double *x1, double *x2)
{
    double root = 0;

    ASSERT(x1 != NULL);
    ASSERT(x2 != NULL);
    ASSERT(x1 != x2);
    ASSERT(a != INFINITY);
    ASSERT(c != INFINITY);

    if (is_null(c)) {
        *x1 = 0;
        return ONE_ROOT;
    }
    else {
    root = sqrt(-c/a);
    *x1 = root;
    *x2 = (-1)*root;

    return TWO_ROOT;
    }
}

Amount_Root c_null(double a, double b, double *x1, double *x2)
{
    ASSERT(x1 != NULL);
    ASSERT(x2 != NULL);
    ASSERT(x1 != x2);
    ASSERT(a != INFINITY);
    ASSERT(b != INFINITY);

    *x1 = 0;
    *x2 = (-1)*b/a;

    return TWO_ROOT;
}

Amount_Root sqr_solve(double a, double b, double c, double *x1, double *x2)
{
    ASSERT(x1 != NULL);
    ASSERT(x2 != NULL);
    ASSERT(x1 != x2);
    ASSERT(a != INFINITY);
    ASSERT(b != INFINITY);
    ASSERT(c != INFINITY);

    double D = 0, sqrt_D = 0, a_2 = 0;

    D = b*b - 4*a*c;  // discriminant
    a_2 = 2 * a;

    if (D > 0) {
        sqrt_D = sqrt(D);
        *x1 = (-b + sqrt_D)/a_2;
        *x2 = (-b - sqrt_D)/a_2;
        return TWO_ROOT;
    }
    else if (is_null(D)) {
        *x1 = -b/a_2;
        return ONE_ROOT;
    }
    return ZERO_ROOT; // D < 0
}

