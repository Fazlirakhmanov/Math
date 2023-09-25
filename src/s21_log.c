#include "s21_math.h"

long double s21_log(double x) {
  long double result = 0, interim_result = 0;
  if (ISNAN(x))
    result = S21_NAN;
  else if (x == 1)
    result = 0;
  else if (x == 0)
    result = INF_NEG;
  else if (ISINF_POS(x))
    result = INF_POS;
  else if (x < 0 || ISINF_NEG(x))
    result = S21_NAN;
  else {
    int counter = 0;
    while (x > S21_EXP) {
      x /= S21_EXP;
      counter++;
    }
    for (int n = 0; n < 200; n++) {
      result = interim_result + 2 * (x - s21_exp(interim_result)) /
                                    (x + s21_exp(interim_result));
      interim_result = result;
    }
    result += counter;
  }
  return result;
}