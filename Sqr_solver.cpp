#include <TXLib.h>
#include <stdio.h>
#include <math.h>

bool comparing(double comp_digit);  /* сравнение с 0, True <=> равен */
void input(double *a, double *b, double *c, int *count_ans);  /* ввод коэффициентов */
void line(double b, double c, double *x1, int *count_ans); /* если не квадратное */
void sqr_solve(double a, double b, double c, double *x1, double *x2, int *count_ans); /* решение квадратного */
void output(int *count_ans, double *x1, double *x2); /* вывод ответа */

enum amount {ZERO, ONE, TWO, INFINITY_}; //кол-во корней

int main()
{
    double x1 = 0, x2 = 0;
    double a = 0, b = 0, c = 0;
    int count_ans = -1;

    input(&a, &b, &c, &count_ans);

    if (comparing(a))
        line(b, c, &x1, &count_ans);  // если не квадратное
    else
        sqr_solve(a, b, c, &x1, &x2, &count_ans); //решение квадратного

    output(&count_ans, &x1, &x2);

    return 0;
}


void input(double *a, double *b, double *c, int *count_ans)
{
    int ch_input = 0;

    printf("Введите коэффициенты а, b, c\n");
    ch_input = scanf("%lg %lg %lg", a, b, c);
    while (ch_input != 3) {
        output(count_ans, a, b);
        while (getchar() != '\n') {}
        ch_input = scanf("%lg %lg %lg", a, b, c);
    }
}

bool comparing(double comp_digit)
{
    if (fabs(comp_digit - 0.0) <= 0.00001)
        return true;
    else
        return false;
}

void line(double b, double c, double *x1, int *count_ans)
{
    if (comparing(b) && (comparing(c)))  //все нули
        *count_ans = INFINITY_;
    if (!(comparing(b))) {         // линейный случай
        *x1 = -c/b;
        *count_ans = ONE;
    }
    else if (!(comparing(c)))      // const = 0, где const != 0
        *count_ans = ZERO;
}


void sqr_solve(double a, double b, double c, double *x1, double *x2, int *count_ans)
{
    double D = 0, sqrt_D = 0, a_2 = 0;

    D = b*b - 4.0*a*c; // дискриминант
    a_2 = 2.0 * a;

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

void output(int *count_ans, double *x1, double *x2)
{
    switch (*count_ans)
    {
        case ZERO:
            printf("Корней нет\n");
            break;
        case ONE:
            printf("x1 = %.4lg\n", *x1); /*  выводит корень */
            break;
        case TWO:
            printf("x1 = %.4lg, x2 = %.4lg\n", *x1, *x2); /*  выводит корни */
            break;
        case INFINITY_:
            printf("Корнем ур-я является любое число");
            break;
        default:
            printf("Введён неверный формат данных\n");
            break;
    }
}
