/*!
  @file main.cpp
  @brief main file!
*/

#include "sqr_solver.hpp"
#include "io.hpp"
#include "test_SqrEq.hpp"
#include "choice_selection.hpp"

#define MAX_LEN 100


int main()
{
    double x1 = 0;
    double x2 = 0;

    double a = 0;
    double b = 0;
    double c = 0;

    int len_of_input_line = 0;

    char input_line[MAX_LEN] = {};

    int count_ans = -1;

    static bool check = false;

    greetings();

    while (!check) {

        while (!(get_input(input_line, MAX_LEN))) {
            printf("Too long! Try again.\n");
            while (getchar() != '\n') {}
        }

        len_of_input_line = strlen(input_line);

        if (check_selected_mod('m', input_line, len_of_input_line)) {
            input(&a, &b, &c);
            solver(a, b, c, &count_ans, &x1, &x2);
            output(count_ans, &x1, &x2);
            check = true;
        }

        else if (check_selected_mod('t', input_line, len_of_input_line)) {
            if(test_SqrEq()) {
                printf("Test aborted!!!\n");
                return 1;
            }
            check = true;
        }
        else if (check_selected_mod('c', input_line, len_of_input_line)) {
            check = true;
        }

        else {
            printf("Wrong data format entered!\n");
        }

    }

    return 0;
}

