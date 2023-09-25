GCC=gcc
STD_FLAGS=-Wall -Werror -Wextra -std=c11
LIB=-lcheck
GCOV_FLAGS=-fprofile-arcs -ftest-coverage
LIB_NAME = s21_math.a
UNIT_TEST=-o unit_test
GCOV_TEST=-o gcov_test

ifeq ($(shell uname), Linux)
 LIB +=-lpthread -lrt -lsubunit -lm
endif


all: clean s21_math.a test gcov_report

s21_math.a:
	${GCC} ${STD_FLAGS} -c ${wildcard *.c}
	ar rc ${LIB_NAME} *.o
	ranlib ${LIB_NAME}
	rm *.o

clean: 
	rm -rf report a.out unit_test gcov_test *.gcda *.gcno *.info ${LIB_NAME} *.o

test: ${LIB_NAME}
	${GCC} ${STD_FLAGS} ${UNIT_TEST} ${wildcard test_folder/*.c} ${LIB_NAME} ${LIB}
	./unit_test
	rm ${LIB_NAME}
	rm unit_test


gcov_report: 
	${GCC} ${STD_FLAGS} ${GCOV_FLAGS} --coverage ${wildcard *.c} ${GCOV_TEST} ${wildcard test_folder/*.c}  ${LIB}
	./gcov_test
	lcov -t "stest" -o s21_test.info -c -d . -no-external
	genhtml -o report s21_test.info
	open ./report/index.html
	rm gcov_test
		rm -rf *.info *.gcno *.gcda gcov_report test *.a
		
clang_n:
	clang-format -n *.c *.h
	
clang_i:
	clang-format -i *.c *.h


