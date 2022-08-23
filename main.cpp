#include "sqr_solver.hpp"

int main()
{
    double x1 = 0;
    double x2 = 0;

    double a = 0;
    double b = 0;
    double c = 0;

    int count_ans = -1;

    input(&a, &b, &c, count_ans);

    solver(a, b, c, &count_ans, &x1, &x2);

    output(count_ans, &x1, &x2);

    return 0;
}
