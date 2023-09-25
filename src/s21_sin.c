#include "s21_math.h"

long double s21_sin(double x) {
  long double result = 0;
  if (ISNAN(x) || ISINF_POS(x) || ISINF_NEG(x))
    result = S21_NAN;
  else {
    while (s21_fabs(x) > MI_PI)
      (x > MI_PI) ? (x -= 2 * MI_PI) : (x += 2 * MI_PI);
    for (int n = 0; n < 200; n++) {
      result += (s21_pow(-1, n) * s21_pow(x, 2 * n + 1)) / factorial(2 * n + 1);
    }
  }
  return result;
}