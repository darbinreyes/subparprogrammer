CC = cc
MY_C_FILE = p1.c
FILES = $(MY_C_FILE)
OUT_EXE = p1

# Standard compilation
build: $(FILES)
	$(CC) -o $(OUT_EXE).out $(FILES)
# Compile with no optimizations, generate debug info.
build_dbg: $(FILES)
	$(CC) -O0 -g -o $(OUT_EXE).dbg.out $(FILES)
# Produce assembly file, with no optimizations.
build_asm: $(FILES)
	$(CC) -O0 -o $(OUT_EXE).s -S $(FILES)
# Produce assembly file, with no optimizations, generate debug info.
build_dbg_asm: $(FILES)
	$(CC) -O0 -g -o $(OUT_EXE).dbg.s -S $(FILES)

clean:
	rm -Rf $(OUT_EXE) $(OUT_EXE).dSYM/

rebuild: clean build

run:
	./$(OUT_EXE)