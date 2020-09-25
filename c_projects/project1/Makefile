# Build the kernel binary.
kernel.bin: kernel_entry.o kernel.o
	i386-elf-ld -o kernel.bin -Ttext 0x1000 kernel_entry.o kernel.o --oformat binary

# Build the kernel object file.
kernel.o: kernel/kernel.c
	i386-elf-gcc -ffreestanding -c kernel/kernel.c -o kernel.o

# Build the kernel entry object file.
kernel_entry.o: kernel/kernel_entry.asm
	nasm kernel/kernel_entry.asm -f elf -o kernel_entry.o
