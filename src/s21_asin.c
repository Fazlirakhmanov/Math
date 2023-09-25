#include "s21_math.h"

long double s21_asin(double x) {
  long double result = 0;
  if (ISNAN(x) || ISINF_NEG(x) || ISINF_POS(x) || x > 1 || x < -1)
    result = S21_NAN;
  else if (x == 0)
    result = 0;
  else
    result = s21_atan(x / s21_sqrt(1 - x * x));
  return result;
}