#ifndef SQR_SOLVER_H_INCLUDED
#define SQR_SOLVER_H_INCLUDED

#include <TXLib.h>
#include <stdio.h>
#include <math.h>

bool comparing(double comp_digit);  /* сравнение с 0, True <=> равен */
void input(double *a, double *b, double *c, int *count_ans);  /* ввод коэффициентов */
void line(double b, double c, double *x1, int *count_ans); /* если не квадратное */
void b_null(double a, double c, double *x1, double *x2, int *count_ans); // b == 0
void c_null(double a, double b, double *x1, double *x2, int *count_ans); // c == 0
void sqr_solve(double a, double b, double c, double *x1, double *x2, int *count_ans); /* решение квадратного */
void output(int *count_ans, double *x1, double *x2); /* вывод ответа */

enum amount {ZERO, ONE, TWO, INFINITY_}; //кол-во корней

#endif // SQR_SOLVER_H_INCLUDED
