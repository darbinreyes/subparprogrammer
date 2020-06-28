AS = as
LD = ld
ASM_NAME = hello_assembly

build: $(FILES)
	$(AS) $(ASM_NAME).s -o $(ASM_NAME).o
# -e argument specifies the name of the entry point function.
	$(LD) $(ASM_NAME).o -lSystem -e _main -o $(ASM_NAME).out

# Step-wise compilation notes.
# cc -O0 p0.c # Generates executable file a.out.
# is equivalent to
# cc -O0 p0.c -S # Generates assembly file p0.s.
# as p0.s # Generates object code file a.out. This NOT an executable file.
# ld a.out -lSystem # Generates executable file.
# Without -l argument this error occurs "ld: dynamic main executables must link with libSystem.dylib for architecture x86_64"