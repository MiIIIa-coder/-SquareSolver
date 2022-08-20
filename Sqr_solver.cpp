#include <TXLib.h>
#include <stdio.h>
#include <math.h>

bool comparing(double x);  // сравнение с 0, True <=> равен
void input(double *a, double *b, double *c);  //ввод коэффициентов
void not_sqr(double *b, double *c); // если не квадратное
void sqr_solve(double *a, double *b, double *c); //решение квадратного

int main()
{
    double a = 0, b = 0, c = 0;

    input(&a, &b, &c);

    if (comparing(a)) {  // если не квадратное
        not_sqr(&b, &c);
        return 0;
    }

    sqr_solve(&a, &b, &c); //решение квадратного

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

void not_sqr(double *b, double *c)
{
    if (comparing(*b) && comparing(*c)) // все нули
        printf("Корнем ур-я является любое число");
    else if (!(comparing(*b)))         // линейный случай
        printf("Корень ур-я = %.5lg\n", -(*c)/(*b));
    else if (comparing(*b))            // const = 0, где const != 0
        printf("Корней нет\n");
}


void sqr_solve(double *a, double *b, double *c)
{
    double D = 0, sqrt_D = 0, a_2 = 0;

    D = (*b)*(*b) - 4.0*(*a)*(*c); // дискриминант
    a_2 = 2.0 * (*a);

    if (D > 0) {
        sqrt_D = sqrt(D);
        printf("x1 = %.4lg, x2 = %.4lg\n", ((-(*b) + sqrt_D)/(a_2)), ((-(*b) - sqrt_D)/(a_2)));
    }
    else if (comparing(D))
        printf("x1 = x2 = %.4lg\n", (-(*b)/(a_2)));
    else
        printf("Корней нет\n");
}













