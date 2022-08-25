/*!
  @file choice_selection.cpp
  @brief here user choice selection of work
*/

#include "sqr_solver.hpp"
#include "io.hpp"
#include "test_SqrEq.hpp"
#include "choice_selection.hpp"

int start_function(void) {

    double x1 = 0;
    double x2 = 0;

    double a = 0;
    double b = 0;
    double c = 0;

    int count_ans = -1;

    static bool check = false;

    int choice = 0;

    greetings();

    while (!check) {

        choice = getchar();

        if (choice == 'm') {
            input(&a, &b, &c, count_ans);
            solver(a, b, c, &count_ans, &x1, &x2);
            output(count_ans, &x1, &x2);
            check = true;
        }

        else if (choice == 't') {
            if(test_SqrEq()){
                printf("Test aborted!!!\n");
                return 1;
            }
            check = true;
        }
        else if (choice == 'c')
            check = true;

        else
            printf("Wrong data format entered!\n");

        while (getchar() != '\n') {}
    }

    return 0;
}




