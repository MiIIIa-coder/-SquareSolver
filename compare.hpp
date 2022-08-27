/*!
  @file compare.hpp
  @brief Functions for comparing.
*/

#ifndef COMPARE_HPP_INCLUDED
#define COMPARE_HPP_INCLUDED


/*!
  @brief  the function compares received number with 0, returns true, if it equals 0, otherwise returns false.

     @param [in] comp_digit    comp_digit - compared number

  @return true
  @return false
*/
bool is_null(double comp_digit);

/*!
  @brief  the function compares received numbers, returns true, if they are equal, otherwise returns false.

     @param [in] n1    n1 - compared number
     @param [in] n2    n2 - compared number

  @return true
  @return false
*/
bool is_equal(double n1, double n2);


#endif // COMPARE_HPP_INCLUDED
