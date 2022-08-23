#include "sqr_solver.hpp"

void solver(int a, int b, int c, int *count_ans, double *x1, double *x2)
{
    if (is_null(a))
        *count_ans = line_equation(b, c, x1);    // a == 0
    else if (is_null(b) && c <= 0)
        *count_ans = b_null(a, c, x1, x2);       // b == 0
    else if (is_null(c))
        *count_ans = c_null(a, b, x1, x2);       // c == 0
    else
        *count_ans = sqr_solve(a, b, c, x1, x2); // решение квадратного
}

AMOUNT_ROOT line_equation(double b, double c, double *x1)
{
    assert(x1 != NULL);

    if (is_null(b) && is_null(c))    // все нули
        return INFINITY_ROOT;

    else if (!is_null(b)) {          // линейный случай
        *x1 = -c/b;
        return ONE_ROOT;
    }

    else if (!is_null(c))
        return ZERO_ROOT;
}

AMOUNT_ROOT b_null(double a, double c, double *x1, double *x2)
{
    double root = sqrt(-c/a);

    assert(x1 != NULL);
    assert(x2 != NULL);
    assert(x1 != x2);

    *x1 = root;
    *x2 = (-1)*root;

    return TWO_ROOT;
}

AMOUNT_ROOT c_null(double a, double b, double *x1, double *x2)
{
    assert(x1 != NULL);
    assert(x2 != NULL);
    assert(x1 != x2);

    *x1 = 0;
    *x2 = (-1)*b/a;

    return TWO_ROOT;
}

AMOUNT_ROOT sqr_solve(double a, double b, double c, double *x1, double *x2)
{
    assert(x1 != NULL);
    assert(x2 != NULL);
    assert(x1 != x2);

    double D = 0, sqrt_D = 0, a_2 = 0;

    D = b*b - 4*a*c;  // дискриминант
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

