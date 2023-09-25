#include "s21_math.h"

long double s21_pow(double base, double exp) {
  long double result = 0;
  if (ISINF_NEG(base) && ISINF_POS(exp))
    result = INF_POS;
  else if (ISINF_NEG(base) && exp < 0)
    result = 0;
  else if (ISINF_NEG(base) && exp > 0 && s21_fmod(exp, 2) != 0)
    result = INF_NEG;
  else if (ISINF_NEG(base) && exp > 0 && s21_fmod(exp, 2) == 0)
    result = INF_POS;
  else if (ISINF_POS(base) && exp < 0)
    result = 0;
  else if (ISINF_POS(base) && exp > 0)
    result = INF_POS;
  else if (base == -1 && ISINF_POS(exp))
    result = 1;
  else if (base == -1 && ISINF_NEG(exp))
    result = 1;
  else if (s21_fabs(base) < 1 && ISINF_NEG(exp) && !ISNAN(base))
    result = INF_POS;
  else if (s21_fabs(base) > 1 && ISINF_NEG(exp))
    result = 0;
  else if (s21_fabs(base) < 1 && ISINF_POS(exp) && !ISNAN(base))
    result = 0;
  else if (s21_fabs(base) > 1 && ISINF_POS(exp))
    result = INF_POS;

  else if (base == 1 || exp == 0)
    result = 1;
  else if (ISNAN(base) || ISNAN(exp) || (base < 0 && exp != (long long int)exp))
    result = S21_NAN;
  else if (base == 0 && exp > 0)
    result = 0;
  else if (base < 0) {
    double base_copy = -base;
    if (exp > 0)
      result = s21_int_pow(base_copy, exp);
    else
      result = 1 / s21_int_pow(base_copy, -exp);
    if (s21_fmod(s21_fabs(exp), 2) != 0) result = -result;
  } else {
    if (exp == (long long int)exp && exp > 0)
      result = s21_int_pow(base, exp);
    else if (exp == (long long int)exp && exp < 0)
      result = 1 / s21_int_pow(base, -exp);
    else
      result = s21_exp(s21_log(base) * exp);
  }
  return result;
}