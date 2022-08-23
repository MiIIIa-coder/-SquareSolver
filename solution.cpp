#include "sqr_solver.hpp"

void line(double b, double c, double *x1, int *count_ans)
{
    assert(x1 != NULL);
    assert(count_ans != 0);

    if (comparing(b) && (comparing(c)))  //все нули
        *count_ans = INFINITY_;
    else if (!(comparing(b))) {         // линейный случай
        *x1 = -c/b;
        *count_ans = ONE;
    }
    else if (!(comparing(c)))      // const = 0, где const != 0
        *count_ans = ZERO;
}

void b_null(double a, double c, double *x1, double *x2, int *count_ans)
{
    double root = sqrt(-c/a);

    assert(count_ans != 0);
    assert(x1 != NULL);
    assert(x2 != NULL);
    assert(x1 != x2);

    *count_ans = TWO;
    *x1 = root;
    *x2 = -1*root;
}

void c_null(double a, double b, double *x1, double *x2, int *count_ans)
{
    assert(count_ans != 0);
    assert(x1 != NULL);
    assert(x2 != NULL);
    assert(x1 != x2);

    *count_ans = TWO;
    *x1 = 0;
    *x2 = -1*b/a;
}

void sqr_solve(double a, double b, double c, double *x1, double *x2, int *count_ans)
{
    assert(count_ans != 0);
    assert(x1 != NULL);
    assert(x2 != NULL);
    assert(x1 != x2);

    double D = 0, sqrt_D = 0, a_2 = 0;

    D = b*b - 4*a*c; // дискриминант
    a_2 = 2 * a;

    if (D > 0) {
        sqrt_D = sqrt(D);
        *x1 = (-b + sqrt_D)/a_2;
        *x2 = (-b - sqrt_D)/a_2;
        *count_ans = TWO;
    }
    else if (comparing(D)) {
        *x1 = -b/a_2;
        *count_ans = ONE;
    }
    else
        *count_ans = ZERO;
}
