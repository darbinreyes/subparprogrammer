CC = gcc
FILES = example_project.c test_suite_one.c test_suite_two.c euclid.c ./seatest/src/seatest.c
OUT_EXE = example

build: $(FILES)
	$(CC) -o $(OUT_EXE) $(FILES) -I ./seatest/src

abort_if_failed:
	$(CC) -D ABORT_TEST_IF_ASSERT_FAIL -o $(OUT_EXE) $(FILES) -I ./seatest/src
	
clean:
	rm -f *.o core

rebuild: clean build
