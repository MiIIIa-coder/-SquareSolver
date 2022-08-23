#ifndef SQR_SOLVER_H_INCLUDED
#define SQR_SOLVER_H_INCLUDED

#include <TXLib.h>
#include <stdio.h>
#include <math.h>

bool comparing(double comp_digit);  /* ��������� � 0, True <=> ����� */
void input(double *a, double *b, double *c, int *count_ans);  /* ���� ������������� */
void line(double b, double c, double *x1, int *count_ans); /* ���� �� ���������� */
void b_null(double a, double c, double *x1, double *x2, int *count_ans); // b == 0
void c_null(double a, double b, double *x1, double *x2, int *count_ans); // c == 0
void sqr_solve(double a, double b, double c, double *x1, double *x2, int *count_ans); /* ������� ����������� */
void output(int *count_ans, double *x1, double *x2); /* ����� ������ */

enum amount {ZERO, ONE, TWO, INFINITY_}; //���-�� ������

#endif // SQR_SOLVER_H_INCLUDED
