CHECK_LINK=$(shell pkg-config --libs --cflags check)
CC=gcc
STD_FLAGS=-Wall -Werror -Wextra
TEST_FILES=tests/s21_test_main.c tests/s21_string_test.c tests/s21_sprintf_test.c tests/s21_sharp_test.c 
GCOV_FLAGS=-fprofile-arcs -ftest-coverage
ifeq ($(OS),Windows_NT)
	PD=$(cd ,)
else
	PD=$(PWD)
endif

all: s21_string.a test 

r: clean all

#s21_string.a

s21_string.a:
		$(CC) $(STD_FLAGS) -c s21_string.c 
		$(CC) $(STD_FLAGS) -c s21_sprintf.c
		$(CC) $(STD_FLAGS) -c s21_sharp.c
		ar rc s21_string.a s21_sprintf.o s21_string.o s21_sharp.o
		ranlib s21_string.a

#s21_string_test

test: tBuild1 tRun

tBuild1: s21_string.a 
	$(CC) $(STD_FLAGS) $(TEST_FILES) $(CHECK_LINK) s21_string.a -o s21_string_test

tRun:
	./s21_string_test

#gcov_report

gcov_report: s21_stringGR grBuild grRun icov htmlGen open

s21_stringGR:
		$(CC) $(STD_FLAGS) $(GCOV_FLAGS) -c s21_string.c -o report/s21_string.o
		$(CC) $(STD_FLAGS) $(GCOV_FLAGS) -c s21_sprintf.c -o report/s21_sprintf.o 
		$(CC) $(STD_FLAGS) $(GCOV_FLAGS) -c s21_sharp.c -o report/s21_sharp.o 
		ar rc report/s21_string.a report/s21_sprintf.o report/s21_string.o report/s21_sharp.o
		ranlib report/s21_string.a
	
grBuild:
	$(CC) $(STD_FLAGS) $(GCOV_FLAGS) $(TEST_FILES) $(CHECK_LINK) report/s21_string.a -o report/icovOutput

grRun:
	report/./icovOutput

icov: 
	lcov -t "test" -o report/icovOutput.info -c -d ./report

htmlGen:
	genhtml -o report report/icovOutput.info

open:
	open ./report/index.html

# clean

clean:
	rm -f *.o *.a
	rm -f s21_string_test
	rm -f icovOutput
	rm -f icovOutput.info
	rm -rf report/*
	rm -f *.gcno *.gcda
	rm -f s21_string_Valtest

# docker

dBuild:
	docker build . -t s21_string --platform linux/amd64

d:
	docker run -v $(PD):/project/src s21_string 

docker: dBuild d

# valgrind

val: s21_stringVal valTBuild1 valRun

valRun:
	valgrind --leak-check=summary --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind_result.txt ./s21_string_Valtest

s21_stringVal:
		$(CC) $(STD_FLAGS) -g -c s21_string.c 
		$(CC) $(STD_FLAGS) -g -c s21_sprintf.c
		$(CC) $(STD_FLAGS) -g -c s21_sharp.c
		ar rc s21_string.a s21_sprintf.o s21_string.o s21_sharp.o
		ranlib s21_string.a

valTBuild1: s21_string.a 
	$(CC) $(STD_FLAGS) $(TEST_FILES) $(CHECK_LINK) s21_string.a -o s21_string_Valtest