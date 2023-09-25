#include "s21_math.h"

long double s21_fmod(double x, double y) {
  long double result = 0;
  if (ISNAN(x) || ISNAN(y) || ISINF_POS(x) || ISINF_NEG(x) || y == 0)
    result = S21_NAN;
  else if (x == 0)
    result = 0;
  else if (ISINF_POS(y) || ISINF_NEG(y))
    result = x;
  else
    result = x - (long long int)(x / y) * y;
  return result;
}