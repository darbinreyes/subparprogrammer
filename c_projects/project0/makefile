CC = cc
MY_C_FILE = p0.c
SEATEST_SRC_PATH = ../../../../../../c_projects/seatest/src
FILES = $(MY_C_FILE)
OUT_EXE = p0

build: $(FILES)
	$(CC) -o $(OUT_EXE) $(FILES)

build_dbg: $(FILES)
	$(CC) -O0 -g -o $(OUT_EXE) $(FILES)

clean:
	rm -Rf $(OUT_EXE) $(OUT_EXE).dSYM/

rebuild: clean build

run:
	./$(OUT_EXE)