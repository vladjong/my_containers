CC = g++
GCOVFLAGS = -fprofile-arcs -ftest-coverage
FILES = s21_vector.h s21_vector.cpp test.cpp
FLAGS = -lgtest -lstdc++ -std=c++20
WCHECK = -Werror -Wall -Wextra
S = --suppress=

all: clean test

test:
	g++ test.cpp $(FLAGS) $(WCHECK) -o test
	./test

clean:
	rm -rf *.o *.out *.a *.gcda *.gcno *.info test
	rm -rf ./report/

gcov_report: 
	@$(CC) -lgtest --coverage test.cpp $(FLAGS) $(WCHECK) -o test
	@./test
	lcov -t "test" -o test.info -c -d ./
	genhtml -o report test.info
	open report/index.html

cpplint:
	python3 ../materials/linters/cpplint.py --extensions=inl *.inl
	python3 ../materials/linters/cpplint.py --extensions=cpp *.cpp *.h tests/*.cpp

cppcheck:
	cppcheck --enable=all $(S)constParameter $(S)useStlAlgorithm $(S)missingIncludeSystem $(S)noCopyConstructor $(S)noOperatorEq $(S)noExplicitConstructor $(S)negativeIndex $(S)missingReturn ../src/


valgrind:
	valgrind --leak-check=full --show-leak-kinds=all -v --log-file=valgrind-out.txt ./test

leaks:
	leaks -atExit -- ./test

.PHONY: all clean test gcov_report
