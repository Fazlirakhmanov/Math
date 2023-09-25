#include "s21_math.h"

long double s21_tan(double x) {
  long double result = 0;
  if (ISNAN(x) || ISINF_POS(x) || ISINF_NEG(x))
    result = S21_NAN;
  else
    result = s21_sin(x) / s21_cos(x);
  return result;
}