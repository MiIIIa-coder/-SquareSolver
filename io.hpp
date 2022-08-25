/*!
  @file io.hpp
  @brief Functions for greeting, inputing and outputing.
*/

#ifndef IO_HPP_INCLUDED
#define IO_HPP_INCLUDED

/*!
  @brief function greetings user.
*/
void greetings(void);

/*!
  @brief the function asks coefficients a, b, c. Until the correct format is entered, the function will call to the function 'output' to display a message about invalidity of the entered data.
     @param [in, out]  a           a - coefficient x^2
     @param [in, out]  b           b - coefficient x^1
     @param [in, out]  c           c - coefficient x^0
     @param [in, out]  count_ans   count_ans - count of roots
*/
void input(double *a, double *b, double *c, int count_ans);

/*!
  @brief function displays roots of the equation.
     @param [in, out]  x1          x1 - pointer to the first root
     @param [in, out]  x2          x2 - pointer to the second root
     @param [in]       count_ans   count_ans - count of roots
*/
void output(int count_ans, double *x1, double *x2);


#endif // IO_HPP_INCLUDED
