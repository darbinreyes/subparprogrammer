CC = cc
MY_C_FILE = p1.c
FILES = $(MY_C_FILE)
OUT_EXE = p1

build: $(FILES)
	$(CC) -o $(OUT_EXE) $(FILES)

build_dbg: $(FILES)
	$(CC) -O0 -g -o $(OUT_EXE) $(FILES)

build_dbg_asm: $(FILES)
	$(CC) -O0 -S $(FILES)

clean:
	rm -Rf $(OUT_EXE) $(OUT_EXE).dSYM/

rebuild: clean build

run:
	./$(OUT_EXE)