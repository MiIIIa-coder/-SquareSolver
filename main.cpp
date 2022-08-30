/*!
  @file main.cpp
  @brief main file!
*/

#include "sqr_solver.hpp"
#include "io.hpp"
#include "test_SqrEq.hpp"
#include "choice_selection.hpp"

int main()
{
    const int MAX_LEN = 100;

    double x1 = 0;
    double x2 = 0;

    double a = 0;
    double b = 0;
    double c = 0;

    int n_roots = 0;

    int  input_len = 0;
    char input_line[MAX_LEN] = {};

    show_greetings();

    char mode = 0;

    while (!mode) {

        while (!(get_input(input_line, MAX_LEN))) {
            printf("Too long! Try again.\n");
            while (getchar() != '\n')
                {}
        }

        input_len = strlen(input_line);

        mode = check_selected_mode(input_line, input_len);

        switch (mode)
        {
            case 'm':
                input(&a, &b, &c);
                solve(a, b, c, &n_roots, &x1, &x2);
                output(n_roots, &x1, &x2);
                break;
            case 't':
                if(test_sqr_eq())
                    printf("Test aborted!!!\n");
                break;
            case 'c':
                break;
            default:
                printf("Wrong data format entered!\n");
                break;
        }

    }

    return 0;
}

