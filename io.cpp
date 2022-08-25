/*!
  @file io.cpp
  @brief Inputs coefficients and outputs roots.
*/

#include "sqr_solver.hpp"
#include "io.hpp"

void greetings(void)
{
    printf("Square equation solver\n"
           "Misha Matvienko 2022, MIPT_SUMMER_SCHOOL\n");
    printf("Select the program operation mode:\n"
           "\"t\" - test   mode \n"
           "\"m\" - manual mode \n"
           "\"c\" - close program\n");
}

void input(double *a, double *b, double *c, int count_ans)
{
    ASSERT(a != 0);
    ASSERT(b != 0);
    ASSERT(c != 0);

    int ch_input = 0;

    printf("Enter the coefficients a, b, c separated by a space for equations of the form a*x^2 + b*x + c = 0\n");

    ch_input = scanf("%lg %lg %lg", a, b, c);

    while (ch_input != 3) {
        while (getchar() != '\n') {}
        output(count_ans, a, b);
        ch_input = scanf("%lg %lg %lg", a, b, c);
    }
}

void output(int count_ans, double *x1, double *x2)
{
    ASSERT(x1 != NULL);
    ASSERT(x2 != NULL);
    ASSERT(x1 != x2);

    switch (count_ans)
    {
        case ZERO_ROOT:
            printf("No roots\n");
            break;
        case ONE_ROOT:
            printf("x = %.4lg\n", *x1);
            break;
        case TWO_ROOT:
            printf("x1 = %.4lg, x2 = %.4lg\n", *x1, *x2);
            break;
        case INFINITY_ROOT:
            printf("The root of the equation is any number\n");
            break;
        default:
            printf("Wrong data format entered!\n");
            break;
    }
}
