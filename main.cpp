#include "sqr_solver.hpp"

int main()
{
    double x1 = 0, x2 = 0;
    double a = 0, b = 0, c = 0;
    int count_ans = -1;

    input(&a, &b, &c, &count_ans);

    if (comparing(a))
        line(b, c, &x1, &count_ans);        //a == 0
    else if (comparing(b) && c <= 0)
        b_null(a, c, &x1, &x2, &count_ans); //b == 0
    else if (comparing(c))
        c_null(a, b, &x1, &x2, &count_ans); //c == 0
    else
        sqr_solve(a, b, c, &x1, &x2, &count_ans); //решение квадратного

    output(&count_ans, &x1, &x2);

    return 0;
}



