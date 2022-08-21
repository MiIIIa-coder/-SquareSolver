#include <TXLib.h>
#include <stdio.h>
#include <math.h>

bool comparing(double x);  /* сравнение с 0, True <=> равен */
void input(double *a, double *b, double *c);  /* ввод коэффициентов */
void line(double b, double c); /* если не квадратное */
void sqr_solve(double a, double b, double c); /* решение квадратного */
void output(int c); /* вывод ответа */

double x1 = 0, x2 = 0;
int count_ans = -1;

int main()
{
    double a = 0, b = 0, c = 0;

    input(&a, &b, &c);

    if (comparing(a))
        line(b, c);         // если не квадратное
    else
        sqr_solve(a, b, c); //решение квадратного

    output(count_ans);

    return 0;
}


void input(double *a, double *b, double *c)
{
    int ch_input = 0;

    printf("Введите коэффициенты а, b, c\n");
    ch_input = scanf("%lg %lg %lg", a, b, c);
    while (ch_input != 3) {
        printf("Введён неправильный формат данных\n");
        fflush(stdin);  //очищает поток ввода
        ch_input = scanf("%lg %lg %lg", a, b, c);
    }
}


bool comparing(double x)
{
    if (fabs(x - 0.0) <= pow(10, -5))
        return true;
    else
        return false;
}


void line(double b, double c)
{
    extern double x1;
    extern int count_ans;

    if (!(comparing(b))) {         // линейный случай
        x1 = -c/b;
        count_ans = 1;
    }
    else if (!(comparing(c)))      // const = 0, где const != 0
        count_ans = 0;
}


void sqr_solve(double a, double b, double c)
{
    extern double x1, x2;
    extern int count_ans;
    double D = 0, sqrt_D = 0, a_2 = 0;

    D = b*b - 4.0*a*c; // дискриминант
    a_2 = 2.0 * a;

    if (D > 0) {
        sqrt_D = sqrt(D);
        x1 = (-b + sqrt_D)/a_2;
        x2 = (-b - sqrt_D)/a_2;
        count_ans = 2;
    }
    else if (comparing(D)) {
        x1 = -b/a_2;
        count_ans = 1;
    }
    else
        count_ans = 0;
}


void output(int c)
{
    extern double x1, x2;

    switch (c)
    {
        case 0:
            printf("Корней нет\n");
            break;
        case 1:
            printf("x1 = %.4lg\n", x1); /*  выводит корень */
            break;
        case 2:
            printf("x1 = %.4lg, x2 = %.4lg\n", x1, x2); /*  выводит корни */
            break;
        default:
            printf("Корнем ур-я является любое число");
            break;
    }
}
