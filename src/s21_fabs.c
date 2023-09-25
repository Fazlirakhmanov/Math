#include "s21_math.h"

long double s21_fabs(double x) {
  long double result = 0;
  if (ISNAN(x))
    result = S21_NAN;
  else if (ISINF_POS(x) || ISINF_NEG(x))
    result = INF_POS;
  else
    result = x < 0 ? -x : x;
  return result;
}