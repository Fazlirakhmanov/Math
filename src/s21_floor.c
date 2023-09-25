#include "s21_math.h"

long double s21_floor(double x) {
  long double result = (long long int)(x);
  if (ISNAN(x))
    result = S21_NAN;
  else if (ISINF_POS(x))
    result = INF_POS;
  else if (ISINF_NEG(x))
    result = INF_NEG;
  else if (x == 0)
    result = 0;
  else if (x < 0 && x != result)
    result -= 1;
  return result;
}