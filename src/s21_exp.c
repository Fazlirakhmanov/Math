#include "s21_math.h"

long double s21_exp(double x) {
  long double result = 1, delta = 1;
  int n = 1, xIsNeg = false;
  if (ISNAN(x))
    result = S21_NAN;
  else if (ISINF_POS(x))
    result = INF_POS;
  else if (ISINF_NEG(x))
    result = 0;
  else {
    if (x < 0) {
      x = -x;
      xIsNeg = true;
    }
    while (s21_fabs(delta) > S21_EPS) {
      delta = 1.0 * s21_int_pow(x, n) / factorial(n);
      result += delta;
      n++;
      if (result > S21_DBL_MAX) {
        result = INF_POS;
        break;
      }
    }
  }
  if (xIsNeg) result = 1 / result;
  return result;
}