/*!
  @file io.hpp
  @brief Functions for greeting, inputing and outputing.
*/

#ifndef IO_HPP_INCLUDED
#define IO_HPP_INCLUDED

#include <string.h>
#include <stdlib.h>

/*!
  @brief function greetings user.
*/
void greetings(void);

/*!
  @brief function gets test file.

     @param [in] name_test_file  name_test_file - name of test file
     @param [in] lim             lim            - name's of test file max length
*/
bool get_name_test_file(char *name_test_file, int lim);

/*!
  @brief function сhecks the input for the presence of letters.

     @param [in] name_test_file  name_test_file - name of test file

*/
bool checking(char line[]);

/*!
  @brief function gets entered coefficients.

     @param [in] input_line[]      input_line[] - entered data
     @param [in]  a                a            - coefficient x^2
     @param [in]  b                b            - coefficient x^1
     @param [in]  c                c            - coefficient x^0
*/
bool check_format(char input_line[], double *a, double *b, double *c);

/*!
  @brief function determines the number of coefficients entered.

     @param [in] input_line[]  input_line[] - entered data

*/
bool check_count_coeff(char input_line[]);

/*!
  @brief function determines selected mod of program.

     @param [in] c                  c                 - symbol of mod
     @param [in] input_line[]       input_line[]      - entered data
     @param [in] len_of_input_line  len_of_input_line - length of entered data

*/
bool check_selected_mod(char c, char input_line[], int len_of_input_line);

/*!
  @brief function gets line.

     @param [in] input_line[]  input_line[] - entered data
     @param [in] lim           lim          - max length

*/
bool get_input(char input_line[], int lim);

/*!
  @brief function asks coefficients a, b, c. Until the correct format is entered,
         the function will call to the function 'output' to display a message
         about invalidity of the entered data.

     @param [in, out]  a           a - coefficient x^2
     @param [in, out]  b           b - coefficient x^1
     @param [in, out]  c           c - coefficient x^0
     //@param [in, out]  count_ans   count_ans - count of roots
*/
void input(double *a, double *b, double *c);

/*!
  @brief function displays roots of the equation.
     @param [in, out]  x1          x1 - pointer to the first root
     @param [in, out]  x2          x2 - pointer to the second root
     @param [in]       count_ans   count_ans - count of roots
*/
void output(int count_ans, double *x1, double *x2);

#endif // IO_HPP_INCLUDED
