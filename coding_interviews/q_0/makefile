CC = gcc
MY_C_FILE = demoq1.c
SEATEST_SRC_PATH = ../../c_projects/seatest/src
FILES = seatest_project.c test_suite_one.c $(MY_C_FILE) $(SEATEST_SRC_PATH)/seatest.c
OUT_EXE = seatest_project

build: $(FILES)
	$(CC) -O0 -g -o $(OUT_EXE) $(FILES) -I $(SEATEST_SRC_PATH)

abort_if_failed:
	$(CC) -D ABORT_TEST_IF_ASSERT_FAIL -o $(OUT_EXE) $(FILES) -I $(SEATEST_SRC_PATH)

clean:
	rm -f *.o core

rebuild: clean build
