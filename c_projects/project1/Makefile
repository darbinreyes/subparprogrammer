# Build the kernel binary.
# $^ = all target dependency files.
# $< = first target dependency file.
# $@ = target file.
kernel.bin: kernel_entry.o kernel.o
	i386-elf-ld -o $@ -Ttext 0x1000 $^ --oformat binary

# Build the kernel object file.
kernel.o: kernel/kernel.c
	i386-elf-gcc -ffreestanding -c $< -o $@

# Build the kernel entry object file.
kernel_entry.o: kernel/kernel_entry.asm
	nasm $< -f elf -o $@
