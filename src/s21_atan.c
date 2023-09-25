#include "s21_math.h"

long double s21_atan(double x) {
  long double result = 0;
  if (ISNAN(x))
    result = S21_NAN;
  else if (ISINF_POS(x))
    result = MI_PI / 2;
  else if (ISINF_NEG(x))
    result = -MI_PI / 2;
  else if (x == 0)
    result = 0;
  else if (x == 1 || x == -1)
    result = MI_PI / 4 * x;
  else if (s21_fabs(x) < 1) {
    for (int i = 0; i < 1000; i++) {
      result += s21_pow(-1, i) * s21_pow(x, 1 + 2 * i) / (1 + 2 * i);
    }
  } else {
    for (int i = 0; i < 1000; i++) {
      result += s21_pow(-1, i) * s21_pow(x, -1 - 2 * i) / (1 + 2 * i);
    }
    result = MI_PI * s21_fabs(x) / (2 * x) - result;
  }
  return result;
}
