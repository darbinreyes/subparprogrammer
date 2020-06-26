CC = cc
MY_C_FILE = p0.c
FILES = $(MY_C_FILE)
OUT_EXE = p0

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

# Step-wise compilation notes.
# cc -O0 p0.c # Generates executable file a.out.
# is equivalent to
# cc -O0 p0.c -S # Generates assembly file p0.s.
# as p0.s # Generates object code file a.out. This NOT an executable file.
# ld a.out -lSystem # Generates executable file.
# Without -l argument this error occurs "ld: dynamic main executables must link with libSystem.dylib for architecture x86_64"

clean:
	rm -Rf $(OUT_EXE) $(OUT_EXE).dSYM/

rebuild: clean build

run:
	./$(OUT_EXE)