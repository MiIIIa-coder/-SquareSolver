/*!
  @file solution.cpp
  @brief Includes functions for all cases of equation.
*/

#include "sqr_solver.hpp"
#include "compare.hpp"

void solve(double a, double b, double c, int *n_roots, double *x1, double *x2)
{
    ASSERT(x1 != NULL);
    ASSERT(x2 != NULL);
    ASSERT(n_roots != NULL);
    ASSERT(a != INFINITY);
    ASSERT(b != INFINITY);
    ASSERT(c != INFINITY);

    if (is_null(a))
        *n_roots = solve_linear_equation(b, c, x1);    // a == 0
    else if (is_null(b) && c <= 0)
        *n_roots = solve_b_null(a, c, x1, x2);         // b == 0
    else if (is_null(c))
        *n_roots = solve_c_null(a, b, x1, x2);         // c == 0
    else
        *n_roots = solve_sqr(a, b, c, x1, x2);         // solves sqr equation
}

Amount_Root solve_linear_equation(double b, double c, double *x1)
{
    ASSERT(x1 != NULL);
    ASSERT(b  != INFINITY);
    ASSERT(c  != INFINITY);

    if (is_null(b) && is_null(c))    // all zeros
        return INFINITY_ROOT;

    else if (!is_null(b)) {          // linear kind
        *x1 = -c/b;
        return ONE_ROOT;
    }

    return ZERO_ROOT;
}

Amount_Root solve_b_null(double a, double c, double *x1, double *x2)
{
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
        double root = sqrt(-c/a);
        *x1 =  root;
        *x2 = -root;

        return TWO_ROOT;
    }
}

Amount_Root solve_c_null(double a, double b, double *x1, double *x2)
{
    ASSERT(x1 != NULL);
    ASSERT(x2 != NULL);
    ASSERT(x1 != x2);
    ASSERT(a != INFINITY);
    ASSERT(b != INFINITY);

    *x1 = 0;
    *x2 = -b/a;

    return TWO_ROOT;
}

Amount_Root solve_sqr(double a, double b, double c, double *x1, double *x2)
{
    ASSERT(x1 != NULL);
    ASSERT(x2 != NULL);
    ASSERT(x1 != x2);
    ASSERT(a  != INFINITY);
    ASSERT(b  != INFINITY);
    ASSERT(c  != INFINITY);

    double discr = b*b - 4*a*c;

    if (discr > 0) {
        double sqrt_discr = sqrt(discr);
        *x1 = (-b + sqrt_discr)/(2*a);
        *x2 = (-b - sqrt_discr)/(2*a);
        return TWO_ROOT;
    }
    else if (is_null(discr)) {
        *x1 = -b/(2*a);
        return ONE_ROOT;
    }

    return ZERO_ROOT; // discriminant < 0
}

