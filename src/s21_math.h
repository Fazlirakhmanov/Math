#include <stdbool.h>

#define MI_PI 3.14159265358979323846264338327950288
#define ACCURACY 13
#define ACCURACY_LOG 10000
#define S21_EPS 1e-30
#define S21_EXP 2.71828182845904523536028747135266250

#define S21_DBL_MAX 1.79769313486231470e+308
#define S21_DBL_MIN -1.79769313486231470e+308
#define S21_NAN (__builtin_nanf(""))
#define INF_POS 1.0 / 0.0
#define INF_NEG -1.0 / 0.0
#define ISNAN(x) (x != x)
#define ISINF_POS(x) (x == INF_POS)
#define ISINF_NEG(x) (x == INF_NEG)

int s21_abs(int x);
long double s21_acos(double x);
long double s21_asin(double x);
long double s21_atan(double x);
long double s21_ceil(double x);
long double s21_cos(double x);
long double s21_exp(double x);
long double s21_fabs(double x);
long double s21_floor(double x);
long double s21_fmod(double x, double y);
long double s21_log(double x);
long double s21_pow(double x, double y);
long double s21_sin(double x);
long double s21_sqrt(double x);

long double s21_tan(double x);
long double s21_int_pow(long double x, long double n);

long double factorial(int x);
