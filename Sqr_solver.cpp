#include <TXLib.h>
#include <stdio.h>
#include <math.h>

int main()
{
    float a, b, c;
    double D;

    printf("������� �����. �\n");
    if (!(scanf("%f", &a))) {
        printf("����� ������������ ������ ������\n");
        return 1;
    }
    printf("������� �����. b\n");
    if (!(scanf("%f", &b))) {
        printf("����� ������������ ������ ������\n");
        return 1;
    }
    printf("������� �����. c\n");
    if (!(scanf("%f", &c))) {
        printf("����� ������������ ������ ������\n");
        return 1;
    }

    if (a == 0 && b == 0 && c == 0) {
        printf("������ ��-� �������� ����� �����");
        return 0;
    }
    else if (a == 0 && b != 0) {
        printf("������ ��-� = %.5f\n", -c/b);
        return 0;
    }
    else if (a == 0 && b == 0) {
        printf("������ ���\n");
        return 0;
    }

    D = (double)pow(b, 2) - 4*a*c;
    if (D > 0)
        printf("x1 = %.4f, x2 = %.4f\n", ((-b + (double)sqrt(D))/(2*a)), ((-b - (double)sqrt(D))/(2*a)));
    else if (D == 0)
        printf("x1 = x2 = %.4f\n", (-b/(2*a)));
    else
        printf("������ ���\n");

    return 0;
}

