/*!
  @file io.cpp
  @brief Inputs coefficients and outputs roots.
*/

#include "sqr_solver.hpp"
#include "io.hpp"
#include "compare.hpp"

#define MAX_LEN 100

void greetings(void)
{
    printf("Square equation solver!\n"
           "Misha Matvienko 2022, MIPT_SUMMER_SCHOOL\n");
    printf("Select the program operation mode:\n"
           "\"t\" - test   mode  \n"
           "\"m\" - manual mode  \n"
           "\"c\" - close program\n");
}

void get_name_test_file(char name_test_file[], int lim)
{
    int i;
    int c;

    printf("Enter the name of the test file\n");
  
    for(i = 0; i < (lim - 1) && (c = getchar()) != EOF && c != '\n';) {
        name_test_file[i++] = (char)c;
    }
    name_test_file[i] = '\0';
}

bool get_input(char input_line[], int lim)
{
    int i;
    int c;
    for(i = 0; i < (lim - 1) && (c = getchar()) != EOF && c != '\n';) {
        input_line[i++] = (char)c;
    }

    if (i == lim - 1)
        return false;

    if (c == '\n')
        input_line[i++] = (char)c;
    input_line[i] = '\0';

    return true;
}

bool checking(char line[])
{
    unsigned int i = 0;
    for (i = 0; isspace(line[i]) || isdigit(line[i]) || line[i] == '.' || line[i] == '-' || line[i] == '+'; ++i)
        {}
    return not(i < (strlen(line) - 1));
}

bool check_format(char line[], double *a, double *b, double *c)
{
    if (sscanf(line, "%lg %lg %lg", a, b, c) == 3)
        return true;
    return false;
}

bool check_count_coeff(char input_line[])
{
    char* nstr = input_line;
    char* tstr;

    int count_coeff = 0;

    double d = 0;

    while(1) {
        tstr = nstr;
        d = strtod(nstr, &nstr);
        if (is_null(d) && tstr==nstr) break;
        ++count_coeff;
        if (count_coeff > 3)
            return false;
    }

    return true;
}

void input(double *a, double *b, double *c)
{
    ASSERT(a != NULL);
    ASSERT(b != NULL);
    ASSERT(c != NULL);

    printf("Enter the coefficients a, b, c separated by a space "
           "for equations of the form a*x^2 + b*x + c = 0\n");

    char input_line[MAX_LEN];

    get_input(input_line, MAX_LEN);

    while (!((checking(input_line)) && check_format(input_line, a, b, c) && check_count_coeff(input_line))) {
        printf("Wrong data format entered!!\n");
        while (!(get_input(input_line, MAX_LEN))) {
            printf("Too long! Try again.\n");
            while (getchar() != '\n') {}
        }
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
            printf("Wrong data format entered!!\n");
            break;
    }
}
