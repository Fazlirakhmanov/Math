#include <check.h>
#include <limits.h>
#include <math.h>
#include <stdlib.h>

#include "../s21_math.h"

#define S21_EPS_TEST 1e-09

START_TEST(test_s21_abs) {
  int tests[20] = {INT_MIN, -10e5, -10000000, -1, 0, 1, 10e5, INT_MAX};
  for (int i = 0; i < 20; i++) {
    int result = s21_abs(tests[i]);
    ck_assert_int_eq(result, abs(tests[i]));
  }
}
END_TEST

START_TEST(test_s21_acos) {
  for (double i = -1; i <= 1; i += 0.25) {
    ck_assert_ldouble_eq_tol(s21_acos(i), acos(i), S21_EPS_TEST);
  }
  ck_assert_ldouble_nan(s21_acos(NAN));
  ck_assert_ldouble_nan(s21_acos(INFINITY));
  ck_assert_ldouble_nan(s21_acos(-INFINITY));
  ck_assert_ldouble_nan(s21_acos(MI_PI));
}
END_TEST

START_TEST(test_s21_asin) {
  for (double i = -1; i <= 1; i += 0.25) {
    ck_assert_ldouble_eq_tol(s21_asin(i), asin(i), S21_EPS_TEST);
  }
  ck_assert_ldouble_nan(s21_asin(NAN));
  ck_assert_ldouble_nan(s21_asin(INFINITY));
  ck_assert_ldouble_nan(s21_asin(-INFINITY));
  ck_assert_ldouble_nan(s21_asin(MI_PI));
  ck_assert_ldouble_nan(s21_asin(-MI_PI));
}
END_TEST

START_TEST(test_s21_atan) {
  for (double i = -sqrt(3); i <= sqrt(3); i += 1 / sqrt(9)) {
    ck_assert_ldouble_eq_tol(s21_atan(i), atan(i), S21_EPS_TEST);
  }
  ck_assert_ldouble_nan(s21_atan(NAN));
  ck_assert_ldouble_eq_tol(s21_atan(MI_PI), atan(MI_PI), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(s21_atan(-MI_PI), atan(-MI_PI), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(s21_atan(INFINITY), atan(INFINITY), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(s21_atan(-INFINITY), atan(-INFINITY), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(s21_atan(0), atan(0), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(s21_atan(-1), atan(-1), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(s21_atan(1), atan(1), S21_EPS_TEST);
}
END_TEST

START_TEST(test_s21_ceil) {
  for (double i = -10; i < 10; i += 0.1) {
    long double result = s21_ceil(i);
    ck_assert_ldouble_eq(result, ceil(i));
  }
  ck_assert_ldouble_infinite(s21_ceil(-INFINITY));
  ck_assert_ldouble_infinite(s21_ceil(INFINITY));
  ck_assert_ldouble_nan(s21_ceil(NAN));
  ck_assert_ldouble_eq(s21_ceil(0), ceil(0));
}
END_TEST

START_TEST(test_s21_cos) {
  for (double i = -4 * MI_PI; i <= 4 * MI_PI; i += MI_PI / 6) {
    ck_assert_ldouble_eq_tol(s21_cos(i), cos(i), S21_EPS_TEST);
  }
  ck_assert_ldouble_nan(s21_cos(NAN));
  ck_assert_ldouble_nan(s21_cos(INFINITY));
  ck_assert_ldouble_nan(s21_cos(-INFINITY));
}
END_TEST

START_TEST(test_s21_exp) {
  double tests[20] = {-10e10, -1.5, -1, -0.5, -10e-10, 0,
                      10e-10, 0.5,  1,  1.5,  10};
  for (int i = 0; i < 20; i++) {
    long double result = s21_exp(tests[i]);
    ck_assert_ldouble_eq_tol(result, exp(tests[i]), S21_EPS_TEST);
  }
  ck_assert_ldouble_nan(s21_exp(NAN));
  ck_assert_ldouble_infinite(s21_exp(INF_POS));
  ck_assert_ldouble_eq(s21_exp(INF_NEG), exp(INF_NEG));
}
END_TEST

START_TEST(test_s21_fabs) {
  double tests[20] = {-10e10, -1.5, -1, -0.5, -10e-10, 0,
                      10e-10, 0.5,  1,  1.5,  10e10};
  for (int i = 0; i < 20; i++) {
    long double result = s21_fabs(tests[i]);
    ck_assert_ldouble_eq(result, fabs(tests[i]));
  }
  ck_assert_ldouble_nan(s21_fabs(NAN));
  ck_assert_ldouble_infinite(s21_fabs(INF_POS));
  ck_assert_ldouble_infinite(s21_fabs(INF_NEG));
}
END_TEST

START_TEST(test_s21_floor) {
  for (double i = -10; i < 10; i += 0.1) {
    long double result = s21_floor(i);
    ck_assert_ldouble_eq(result, floor(i));
  }
  ck_assert_ldouble_infinite(s21_floor(-INFINITY));
  ck_assert_ldouble_infinite(s21_floor(INFINITY));
  ck_assert_ldouble_nan(s21_floor(NAN));
  ck_assert_ldouble_eq(s21_floor(0), floor(0));
}
END_TEST

START_TEST(test_s21_fmod) {
  for (double i = -10; i <= 10; i += 0.05) {
    for (double j = -10; j <= 10; j += 0.05) {
      long double result = s21_fmod(i, j);
      ck_assert_ldouble_eq_tol(result, fmod(i, j), S21_EPS_TEST);
    }
  }
  ck_assert_ldouble_nan(s21_fmod(INF_POS, 1));
  ck_assert_ldouble_nan(s21_fmod(INF_NEG, 1));
  ck_assert_ldouble_nan(s21_fmod(NAN, 1));
  ck_assert_ldouble_nan(s21_fmod(1, NAN));
  ck_assert_ldouble_nan(s21_fmod(1, 0));
  ck_assert_ldouble_eq(s21_fmod(1, INF_NEG), fmod(1, INF_NEG));
  ck_assert_ldouble_eq(s21_fmod(1, INF_POS), fmod(1, INF_POS));

  for (double j = -2; j <= 2; j += 0.05)
    ck_assert_ldouble_eq_tol(s21_fmod(0, j), fmod(0, j), S21_EPS_TEST);
}
END_TEST

START_TEST(test_s21_log) {
  long double tests[20] = {-INFINITY, -10e10, -1.5, -1,    -0.5,
                           -10e-10,   -NAN,   0,    NAN,   10e-10,
                           0.5,       1,      1.5,  10e10, INFINITY};
  for (int i = 0; i < 20; i++) {
    long double result = s21_log(tests[i]);
    ck_assert_int_eq(result, log(tests[i]));
  }
}
END_TEST

START_TEST(test_s21_pow) {
  for (double i = 0.5; i <= 1.5; i += 0.5) {
    for (double j = 0.5; j <= 1.5; j += 0.5) {
      long double result = s21_pow(i, j);
      ck_assert_ldouble_eq_tol(result, pow(i, j), S21_EPS_TEST);
    }
  }
  ck_assert_ldouble_nan(s21_pow(S21_NAN, S21_NAN));
  ck_assert_ldouble_eq(s21_pow(INF_NEG, INF_NEG), pow(INF_NEG, INF_NEG));
  ck_assert_ldouble_eq(s21_pow(INF_NEG, INF_POS), pow(INF_NEG, INF_POS));
  ck_assert_ldouble_eq(s21_pow(INF_POS, INF_NEG), pow(INF_POS, INF_NEG));
  ck_assert_ldouble_eq(s21_pow(INF_POS, INF_POS), pow(INF_POS, INF_POS));
  ck_assert_ldouble_eq(s21_pow(INF_NEG, 2), pow(INF_NEG, 2));
  ck_assert_ldouble_eq(s21_pow(INF_NEG, 3), pow(INF_NEG, 3));
  ck_assert_ldouble_eq(s21_pow(-1, INF_POS), pow(-1, INF_POS));
  ck_assert_ldouble_eq(s21_pow(-1, INF_NEG), pow(-1, INF_NEG));
  ck_assert_ldouble_eq(s21_pow(2, INF_NEG), pow(2, INF_NEG));
  ck_assert_ldouble_eq(s21_pow(0.5, INF_POS), pow(0.5, INF_POS));
  ck_assert_ldouble_eq(s21_pow(2, INF_POS), pow(2, INF_POS));
  ck_assert_ldouble_eq_tol(s21_pow(-2, 2), pow(-2, 2), S21_EPS_TEST);
  ck_assert_ldouble_nan(s21_pow(-2, 2.5));
  ck_assert_ldouble_eq_tol(s21_pow(-2, 3), pow(-2, 3), S21_EPS_TEST);
  ck_assert_ldouble_nan(s21_pow(-1, -2.34));
  ck_assert_ldouble_nan(s21_pow(-1, 2.34));
  ck_assert_ldouble_eq_tol(s21_pow(0, 0), pow(0, 0), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(s21_pow(0, 1), pow(0, 1), S21_EPS_TEST);
  ck_assert_ldouble_infinite(s21_pow(0.5, INF_NEG));
  ck_assert_ldouble_eq(s21_pow(1, INF_NEG), pow(1, INF_NEG));
  ck_assert_ldouble_eq(s21_pow(1, INF_POS), pow(1, INF_POS));
  ck_assert_ldouble_eq_tol(s21_pow(1, S21_NAN), pow(1, S21_NAN), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(s21_pow(5, 1), pow(5, 1), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(s21_pow(5, -1), pow(5, -1), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(s21_pow(5, 0), pow(5, 0), S21_EPS_TEST);
  ck_assert_ldouble_nan(s21_pow(-2, 2.5));
}
END_TEST

START_TEST(test_s21_sin) {
  for (double i = -4 * MI_PI; i <= 4 * MI_PI; i += MI_PI / 6) {
    ck_assert_ldouble_eq_tol(s21_sin(i), sin(i), S21_EPS_TEST);
  }
  ck_assert_ldouble_nan(s21_sin(NAN));
  ck_assert_ldouble_nan(s21_sin(INFINITY));
  ck_assert_ldouble_nan(s21_sin(-INFINITY));
}
END_TEST

START_TEST(test_s21_sqrt) {
  for (double i = 0.1; i <= 5; i += 0.1) {
    long double result = s21_sqrt(i);
    ck_assert_ldouble_eq_tol(result, sqrt(i), S21_EPS_TEST);
  }
  ck_assert_ldouble_nan(s21_sqrt(S21_NAN));
  ck_assert_ldouble_nan(s21_sqrt(-5));
  ck_assert_ldouble_nan(s21_sqrt(-5.1));
  ck_assert_ldouble_eq(s21_sqrt(0), sqrt(0));
  ck_assert_ldouble_infinite(s21_sqrt(INF_POS));
}
END_TEST

START_TEST(test_s21_tan) {
  for (double i = -4 * MI_PI; i <= 4 * MI_PI; i += 0.5) {
    ck_assert_ldouble_eq_tol(s21_tan(i), tan(i), S21_EPS_TEST);
  }
  ck_assert_ldouble_nan(s21_tan(NAN));
  ck_assert_ldouble_nan(s21_tan(INFINITY));
  ck_assert_ldouble_nan(s21_tan(-INFINITY));
}
END_TEST

Suite *test_suite() {
  Suite *s;
  TCase *tc_core;

  s = suite_create("test_s21_math.h");

  // Создаем тестовый сценарий и добавляем его в набор
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_s21_abs);
  tcase_add_test(tc_core, test_s21_acos);
  tcase_add_test(tc_core, test_s21_asin);
  tcase_add_test(tc_core, test_s21_atan);
  tcase_add_test(tc_core, test_s21_ceil);
  tcase_add_test(tc_core, test_s21_cos);
  tcase_add_test(tc_core, test_s21_exp);
  tcase_add_test(tc_core, test_s21_fabs);
  tcase_add_test(tc_core, test_s21_floor);
  tcase_add_test(tc_core, test_s21_fmod);
  tcase_add_test(tc_core, test_s21_log);
  tcase_add_test(tc_core, test_s21_pow);
  tcase_add_test(tc_core, test_s21_sin);
  tcase_add_test(tc_core, test_s21_sqrt);
  tcase_add_test(tc_core, test_s21_tan);

  suite_add_tcase(s, tc_core);

  return s;
}

int main(void) {
  int number_failed;
  Suite *s;
  SRunner *sr;

  s = test_suite();
  sr = srunner_create(s);

  // Запускаем тесты
  srunner_run_all(sr, CK_NORMAL);

  // Получаем количество неудачных тестов
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  // Возвращаем ненулевое значение, если были неудачные тесты
  return (number_failed == 0) ? 0 : 1;
}
