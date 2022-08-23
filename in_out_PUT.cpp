#include "sqr_solver.hpp"

void input(double *a, double *b, double *c, int *count_ans)
{
    assert(a != 0);
    assert(b != 0);
    assert(c != 0);
    assert(count_ans != 0);

    int ch_input = 0;

    printf("Введите коэффициенты а, b, c для уравнений вида a*x^2 + b*x + c = 0\n");

    ch_input = scanf("%lg %lg %lg", a, b, c);

    while (ch_input != 3) {
        while (getchar() != '\n') {}
        output(count_ans, a, b);
        ch_input = scanf("%lg %lg %lg", a, b, c);
    }
}

void output(int *count_ans, double *x1, double *x2)
{
    assert(count_ans != 0);
    assert(x1 != NULL);
    assert(x2 != NULL);
    assert(x1 != x2);

    switch (*count_ans)
    {
        case ZERO:
            printf("Êîðíåé íåò\n");
            break;
        case ONE:
            printf("x = %.4lg\n", *x1); /*  âûâîäèò êîðåíü */
            break;
        case TWO:
            printf("x1 = %.4lg, x2 = %.4lg\n", *x1, *x2); /*  âûâîäèò êîðíè */
            break;
        case INFINITY_:
            printf("Êîðíåì óð-ÿ ÿâëÿåòñÿ ëþáîå ÷èñëî");
            break;
        default:
            printf("Ââåä¸í íåâåðíûé ôîðìàò äàííûõ\n");
            break;
    }
}
