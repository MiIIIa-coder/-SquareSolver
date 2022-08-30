/*!
  @file sqr_solver.hpp
  @brief Functions for square solver.
*/

#ifndef SQR_SOLVER_H_INCLUDED
#define SQR_SOLVER_H_INCLUDED

// #include <TXLib.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>

/*!
  @brief macro, which warns about error and displays line, function and file of it.

*/
#define ASSERT(condition) if(!(condition)){                                    \
        printf("Error in %s in line %d\n in function %s\n in file %s\n",       \
        #condition, __LINE__, __PRETTY_FUNCTION__, __FILE__); }                \

/*!
  @brief lists constants numerically equal to the possible number of roots of the equation (here infinity = 3)
*/
enum Amount_Root {
    ZERO_ROOT     = 0,
    ONE_ROOT      = 1,
    TWO_ROOT      = 2,
    INFINITY_ROOT = 3
};

/*!
  @brief function solves the equation, if it has linear kind or kind is 'const = 0' or kind of the equation is 0 = 0.

     @param [in] b    b - coefficient x^1
     @param [in] c    c - coefficient x^0
     @param [in, out] x1 - pointer to the first root
*/
Amount_Root solve_linear_equation(double b, double c, double *x1);

/*!
  @brief function solves equation, if coefficients: b = 0, a != 0.

     @param [in]  a           a - coefficient x^2
     @param [in]  c           c - coefficient x^0
     @param [in, out]         x1 - pointer to the first root
     @param [in, out]         x2 - pointer to the second root
*/
Amount_Root solve_b_null(double a, double c, double *x1, double *x2);

/*!
  @brief function solves equation, if coefficients: c = 0, a != 0.

     @param [in]  a           a - coefficient x^2
     @param [in]  b           b - coefficient x^1
     @param [in, out]         x1 - pointer to the first root
     @param [in, out]         x2 - pointer to the second root
*/
Amount_Root solve_c_null(double a, double b, double *x1, double *x2);

/*!
  @brief function solves equation, if its kind is square.

     @param [in]  a           a - coefficient x^2
     @param [in]  b           b - coefficient x^1
     @param [in]  c           c - coefficient x^0
     @param [in, out]         x1 - pointer to the first root
     @param [in, out]         x2 - pointer to the second root
*/
Amount_Root solve_sqr(double a, double b, double c, double *x1, double *x2);

/*!
  @brief function asks to other functions (line_equation, b_null, c_null, sqr_solve) to solve equation.

     @param [in]  a                a - coefficient x^2
     @param [in]  b                b - coefficient x^1
     @param [in]  c                c - coefficient x^0
     @param [in, out]  x1          x1 - pointer to the first root
     @param [in, out]  x2          x2 - pointer to the second root
     @param [in, out]  count_ans   count_ans - count of roots
*/
void solve(double a, double b, double c, int *n_roots, double *x1, double *x2);

#endif // SQR_SOLVER_H_INCLUDED
