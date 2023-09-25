#include "s21_math.h"

long double s21_acos(double x) {
  long double result = 0;
  if (ISNAN(x) || ISINF_NEG(x) || ISINF_POS(x) || x > 1 || x < -1)
    result = S21_NAN;
  else if (x == 1)
    result = 0;
  else if (x == -1)
    result = MI_PI;
  else
    result = MI_PI / 2 - s21_asin(x);
  return result;
}