/*!
  @file testing.cpp
  @brief Tests received roots.
*/

#include "sqr_solver.hpp"
#include "compare.hpp"
#include "test_SqrEq.hpp"

int test_SqrEq(void)
{
    double x1 = 0;
    double x2 = 0;

    double a = 0;
    double b = 0;
    double c = 0;

    int right_count = 0;
    int test_num = 0;
    double root1 = 0;
    double root2 = 0;

    int count_ans = -1;

    FILE *test_file;
    if ((test_file = fopen("Test_digits.txt", "r")) == NULL) {
        printf("ERROR: failed to open file \"Test_digits.txt\"\n");
        return 1;
    }

    printf("Function \"solver\" test starts now!\n");


    while (fscanf(test_file, "%lg %lg %lg %d", &a, &b, &c, &right_count) != EOF) {

        switch(right_count)
        {
            case INFINITY_ROOT:
                break;

            case TWO_ROOT:
                if (fscanf(test_file, "%lg %lg", &root1, &root2) == EOF) {
                    printf("ERROR: an error occurred while trying to get file data.");
                    return 1;
                }
                break;

            case ONE_ROOT:
                if (fscanf(test_file, "%lg", &root1) == EOF) {
                    printf("ERROR: an error occurred while trying to get file data.");
                    return 1;
                }
                break;
            case ZERO_ROOT:
                break;

            default:
                printf("Incorrect amount of roots in testing\n");
                break;
        }

        printf("Test #%d\n", ++test_num);

        solver(a, b, c, &count_ans, &x1, &x2);

        test_compare(a, b, c, count_ans, x1, x2, right_count, root1, root2);

    }

    if (fclose(test_file) == EOF) {
        printf("ERROR: failed to close file \"Test_digits.txt\"\n");
        return 1;
    }

    // include                   // *
    // errno
    // perror

    return 0;
}



void test_compare(double a, double b, double c, int count_ans, double x1, double x2, int right_count, double root1, double root2)
{

    if(!(count_ans == right_count && is_equal(x1, root1) && is_equal(x2, root2))) {
                printf("Received coefficients: a = %lg b = %lg c = %lg\n", a, b, c);
                printf("FAILED:   count_ans = %d, x1 = %lg, x2 = %lg\n"
                       "EXPECTED: count_ans = %d, x1 = %lg, x2 = %lg\n",
                        count_ans, x1, x2, right_count, root1, root2);
    }
    else
        printf("SUCCESS!\n");

/*
    switch(right_count)
    {
        case INFINITY_ROOT:
            if (count_ans == INFINITY_ROOT)
                printf("The equation is correct!\n");
                printf("FAILED:   count_ans = %d, x1 = %lg, x2 = %lg\n"
                       "EXPECTED: count_ans = %d, x1 = %lg, x2 = %lg\n",
                        count_ans, x1, x2, right_count, root1, root2);
            else {
                printf("Received coefficients: a = %lg b = %lg c = %lg\n", a, b, c);
            }
            break;

        case TWO_ROOT:
            if(!(count_ans == right_count && is_equal(x1, root1) && is_equal(x2, root2))) {
                printf("Received coefficients: a = %lg b = %lg c = %lg\n", a, b, c);
                printf("FAILED:   count_ans = %d, x1 = %lg, x2 = %lg\n"
                       "EXPECTED: count_ans = %d, x1 = %lg, x2 = %lg\n",
                        count_ans, x1, x2, right_count, root1, root2);
            }
            else
                printf("The equation is correct!\n");
            break;

        case ONE_ROOT:
            if (!(count_ans == right_count && is_equal(x1, root1))) {
                printf("Received coefficients: a = %lg b = %lg c = %lg\n", a, b, c);
                printf("FAILED:   count_ans = %d, x1 = %lg\n"
                       "EXPECTED: count_ans = %d, x1 = %lg\n",
                        count_ans, x1, right_count, root1);
            }
            else
                printf("The equation is correct!\n");

        case ZERO_ROOT:
            if (count_ans == ZERO_ROOT)
                printf("The equation is correct!\n");
            else {
                printf("FAILED:   count_ans = %d, x1 = %lg\n"
                       "EXPECTED: count_ans = %d, x1 = %lg\n",
                        count_ans, x1, right_count, root1);
            }
            break;

        default:
            printf("Incorrect amount of roots in testing\n");
            break;
    }
    */
    printf("\n");
}
