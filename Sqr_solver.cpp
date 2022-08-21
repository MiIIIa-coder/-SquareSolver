#include <TXLib.h>
#include <stdio.h>
#include <math.h>

bool comparing(double x);  /* ñðàâíåíèå ñ 0, True <=> ðàâåí */
void input(double *a, double *b, double *c);  /* ââîä êîýôôèöèåíòîâ */
void not_sqr(double *b, double *c); /* åñëè íå êâàäðàòíîå */
void sqr_solve(double *a, double *b, double *c); /* ðåøåíèå êâàäðàòíîãî */

int main()
{
    double a = 0, b = 0, c = 0;

    input(&a, &b, &c);

    if (comparing(a)) {  // åñëè íå êâàäðàòíîå
        not_sqr(&b, &c);
        return 0;
    }

    sqr_solve(&a, &b, &c); //ðåøåíèå êâàäðàòíîãî

    return 0;
}


void input(double *a, double *b, double *c)
{
    int ch_input = 0;

    printf("Ââåäèòå êîýôôèöèåíòû à, b, c\n");
    ch_input = scanf("%lg %lg %lg", a, b, c);
    while (ch_input != 3) {
        printf("Ââåä¸í íåïðàâèëüíûé ôîðìàò äàííûõ\n");
        fflush(stdin);  //î÷èùàåò ïîòîê ââîäà
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
    if (comparing(*b) && comparing(*c)) // âñå íóëè
        printf("Êîðíåì óð-ÿ ÿâëÿåòñÿ ëþáîå ÷èñëî");
    else if (!(comparing(*b)))         // ëèíåéíûé ñëó÷àé
        printf("Êîðåíü óð-ÿ = %.5lg\n", -(*c)/(*b));
    else if (comparing(*b))            // const = 0, ãäå const != 0
        printf("Êîðíåé íåò\n");
}


void sqr_solve(double *a, double *b, double *c)
{
    double D = 0, sqrt_D = 0, a_2 = 0;

    D = (*b)*(*b) - 4.0*(*a)*(*c); // äèñêðèìèíàíò
    a_2 = 2.0 * (*a);

    if (D > 0) {
        sqrt_D = sqrt(D);
        printf("x1 = %.4lg, x2 = %.4lg\n", ((-(*b) + sqrt_D)/(a_2)), ((-(*b) - sqrt_D)/(a_2)));
    }
    else if (comparing(D))
        printf("x1 = x2 = %.4lg\n", (-(*b)/(a_2)));
    else
        printf("Êîðíåé íåò\n");
}













