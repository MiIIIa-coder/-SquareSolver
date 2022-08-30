/*!
  @file io.cpp
  @brief Inputs coefficients and outputs roots.
*/

#include "sqr_solver.hpp"
#include "io.hpp"
#include "compare.hpp"

const char too_long[] = "Too long!\n";

void show_greetings()
{
    printf("Square equation solver!\n"
           "Misha Matvienko 2022, MIPT_SUMMER_SCHOOL\n");
    printf("Select the program operation mode:\n"
           "\"t\" - test   mode  \n"
           "\"m\" - manual mode  \n"
           "\"c\" - close program\n");
}

bool get_test_file_name(char test_file_name[], int lim)
{
    int i = 0;
    int c = 0;

    printf("Enter the name of the test file\n");

    for (i = 0; isspace(c = getchar()); ++i)
        {}

    test_file_name[0] = (char)c;

    for(i = 1; (c = getchar()) != EOF && c != '\n';) {
        if (i >= lim - 1) {
            printf("too_long long!\n");
            return false;
        }

        if (isspace(c))
            break;

        test_file_name[i++] = (char)c;
    }
    test_file_name[i] = '\0';

    return true;
}

bool get_input(char input_line[], int lim)
{
    int i = 0;
    int c = 0;

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
  
    for (i = 0; isspace(line[i])  ||
                isdigit(line[i])  ||
                line[i] == '.'    ||
                line[i] == '-'    ||
                line[i] == '+'; (i++))
    {}

    return !(i < (strlen(line) - 1));
}


// return mode;
char check_selected_mode(char input_line[], int input_len)
{
    int i = 0;
    int j = 0;

    for (i = 0; isspace(input_line[i]); i++)
        {}

    i++;
    j = i;   // here index of symbol
    for (; isspace(input_line[i]) && i < input_len; i++)
        {}
    if (i == input_len)
        return input_line[j-1];

    return 0;
}

bool check_format(char input_line[], double *a, double *b, double *c)
{
    if (sscanf(input_line, "%lg %lg %lg", a, b, c) == 3)
        return true;
    return false;
}

bool check_count_coeff(char input_line[])
{
    char* beginnig_line = input_line;
    char* end_line = NULL;

    int n_coeffs = 0;

    double coeff = 0;

    while (true) {
        end_line = beginnig_line;
        coeff = strtod(beginnig_line, &beginnig_line);
        if (is_null(coeff) && end_line == beginnig_line) break;
        ++n_coeffs;
        if (n_coeffs > 3)
            return false;
    }

    return true;
}

void input(double *a, double *b, double *c)
{
    ASSERT(a != NULL);
    ASSERT(b != NULL);
    ASSERT(c != NULL);

    const int MAX_LEN = 100;

    printf("Enter the coefficients a, b, c separated by a space "
           "for equations of the form a*x^2 + b*x + c = 0\n");

    char input_line[MAX_LEN] = {0};

    get_input(input_line, MAX_LEN);

    while (!((checking(input_line))          &&
           check_format(input_line, a, b, c) &&
           check_count_coeff(input_line)))    {

        printf("Wrong data format entered!!\n");
        while (!(get_input(input_line, MAX_LEN))) {
            printf("%s", too_long);
            while (getchar() != '\n')
                {}
        }
    }
}

void output(int n_roots, double *x1, double *x2)
{
    ASSERT(x1 != NULL);
    ASSERT(x2 != NULL);
    ASSERT(x1 != x2);

    switch (n_roots)
    {
        case ZERO_ROOT:
            printf("No roots.\n");
            break;
        case ONE_ROOT:
            printf("x = %.4lg.\n", *x1);
            break;
        case TWO_ROOT:
            printf("x1 = %.4lg, x2 = %.4lg.\n", *x1, *x2);
            break;
        case INFINITY_ROOT:
            printf("The root of the equation is any number.\n");
            break;
        default:
            printf("Wrong data format entered!\n");
            break;
    }
}
