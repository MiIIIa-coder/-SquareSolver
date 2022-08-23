#ifndef SQR_SOLVER_H_INCLUDED
#define SQR_SOLVER_H_INCLUDED

#include <TXLib.h>
#include <stdio.h>
#include <math.h>

enum AMOUNT_ROOT {ZERO_ROOT, ONE_ROOT, TWO_ROOT, INFINITY_ROOT};             // кол-во корней

bool is_null(double comp_digit);                                             // сравнение с 0, True <=> равен
void input(double *a, double *b, double *c, int count_ans);                  // ввод коэффициентов
AMOUNT_ROOT line_equation(double b, double c, double *x1);                   // если не квадратное
AMOUNT_ROOT b_null(double a, double c, double *x1, double *x2);              // b == 0
AMOUNT_ROOT c_null(double a, double b, double *x1, double *x2);              // c == 0
AMOUNT_ROOT sqr_solve(double a, double b, double c, double *x1, double *x2); // решение квадратного
void solver(int a, int b, int c, int *count_ans, double *x1, double *x2);    // вызывает функцию решения для данного случая
void output(int count_ans, double *x1, double *x2);                          // вывод ответа

#endif // SQR_SOLVER_H_INCLUDED
