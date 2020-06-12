CC = gcc
MY_C_FILE = project0.c
SEATEST_SRC_PATH = ../../../../../../c_projects/seatest/src
FILES = $(MY_C_FILE)
OUT_EXE = proj0

build: $(FILES)
	$(CC) -o $(OUT_EXE) $(FILES)

build_dbg: $(FILES)
	$(CC) -O0 -g -o $(OUT_EXE) $(FILES)

clean:
	rm -Rf proj0 proj0.dSYM/

rebuild: clean build

run:
	./$(OUT_EXE)