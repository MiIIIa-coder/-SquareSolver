#include <TXLib.h>
#include <stdio.h>
#include <math.h>

int main()
{
    float a, b, c;
    double D;
    
    /* Ввод a, b, c */
    printf("Введите коэфф. а\n");
    if (!(scanf("%f", &a))) {
        printf("Введён неправильный формат данных\n");
        return 1;
    }
    printf("Введите коэфф. b\n");
    if (!(scanf("%f", &b))) {
        printf("Введён неправильный формат данных\n");
        return 1;
    }
    printf("Введите коэфф. c\n");
    if (!(scanf("%f", &c))) {
        printf("Введён неправильный формат данных\n");
        return 1;
    }
    
    /* случаи */
    if (a >= 0 && a <= 0 && b >= 0 && b <= 0 && c >= 0 && c <= 0) {
        printf("Корнем ур-я является любое число");
        return 0;
    }
    else if (a >= 0 && a <= 0 && (b > 0 || b < 0)) { /* линейный случай */
        printf("Корень ур-я = %.5f\n", -c/b);
        return 0;
    }
    else if (a >= 0 && a <= 0 && b >= 0 && b <= 0) {
        printf("Корней нет\n");
        return 0;
    }

    D = (double)pow(b, 2) - 4*a*c; /* дискриминант */
    if (D > 0)
        printf("x1 = %.4f, x2 = %.4f\n", ((-b + (double)sqrt(D))/(2*a)), ((-b - (double)sqrt(D))/(2*a)));
    else if (D >= 0 && D <= 0)
        printf("x1 = x2 = %.4f\n", (-b/(2*a)));
    else
        printf("Корней нет\n");

    return 0;
}

