#include "s21_math.h"

long double factorial(int x) {
  long double result = 1;
  for (; x > 1; x--) result *= x;
  return result;
}

long double s21_int_pow(long double x, long double n) {
  long double result = 1;
  if (x == 1 || n == 0)
    result = 1;
  else if (x == 0)
    result = 0;
  else {
    for (; n > 0; n--) {
      result *= x;
      if (result > S21_DBL_MAX) {
        result = INF_POS;
        break;
      }
    }
  }
  return result;
}