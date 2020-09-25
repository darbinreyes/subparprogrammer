# Build the kernel binary.
# $^ = all target dependency files.
# $< = first target dependency file.
# $@ = target file.
# THE FIRST TARGET = THE DEFAULT TARGET.
all: os-image

run: all
	qemu-system-i386 -drive file=os-image,if=floppy,format=raw

# This is the actual disk image that the computer loads,
# which is the combination of our compiled boot sector and kernel.
os-image: boot_sect.bin kernel.bin
	cat $^ > $@

# Assemble the boot sector to raw machine code
#	The -I option tells nasm where to find our useful assembly
#	routines that we include in boot_sect.asm.
boot_sect.bin: boot/boot_sect.asm
	nasm $< -I 'boot/' -f bin -o $@

kernel.bin: kernel_entry.o kernel.o
	i386-elf-ld -o $@ -Ttext 0x1000 $^ --oformat binary

# Build the kernel object file.
kernel.o: kernel/kernel.c
	i386-elf-gcc -ffreestanding -c $< -o $@

# Build the kernel entry object file.
kernel_entry.o: kernel/kernel_entry.asm
	nasm $< -f elf -o $@

# Disassemble our kernel - might be useful for debugging.
kernel.dis: kernel.bin
	ndisasm -b 32 $< > $@

clean:
	rm -Rf *.bin *.o os-image
