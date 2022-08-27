/*!
  @file test_SqrEq.hpp
  @brief Functions for test of program.
*/

#ifndef TEST_SQREQ_HPP_INCLUDED
#define TEST_SQREQ_HPP_INCLUDED

/*!
  @brief test - function.
*/
int test_SqrEq(void);

/*!
  @brief function tests received roots.

     @param [in]  a           a - coefficient x^2
     @param [in]  b           b - coefficient x^1
     @param [in]  c           c - coefficient x^0
     @param [in]  x1          x1 - pointer to the first root
     @param [in]  x2          x2 - pointer to the second root
     @param [in]  count_ans   count_ans - count of roots
     @param [in]  right_count right_count - number of roots from file
     @param [in]  root1       root1 - first root from file
     @param [in]  root2       root2 - second root from file
*/
void test_compare(double a, double b, double c,
                 int count_ans, double x1, double x2,
                 int right_count, double root1, double root2);

#endif // TEST_SQREQ_HPP_INCLUDED
