#include "s21_math.h"

long double s21_sqrt(double x) {
  long double result = 0;
  if (ISNAN(x) || x < 0)
    result = S21_NAN;
  else if (x == 0)
    result = 0;
  else if (ISINF_POS(x))
    result = INF_POS;
  else
    result = s21_pow(x, 0.5);
  return result;
}