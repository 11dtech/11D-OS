#compile kernel entry assembly to kasm.o
nasm -f elf32 source/kernel.asm -o object/kasm.o
#compile kernel function written in c to kc.o
gcc -m32 -c kernel.c -o object/kc.o	-ffreestanding
#compile include c files
gcc -m32 -c include/idt.c -o object/idt.o -ffreestanding
gcc -m32 -c include/isr.c -o object/isr.o -ffreestanding
gcc -m32 -c include/kb.c -o object/kb.o -ffreestanding
gcc -m32 -c include/screen.c -o object/screen.o -ffreestanding
gcc -m32 -c include/string.c -o object/string.o -ffreestanding
gcc -m32 -c include/system.c -o object/system.o -ffreestanding
gcc -m32 -c include/util.c -o object/util.o -ffreestanding
gcc -m32 -c include/shell.c -o object/shell.o -ffreestanding
#use link.ld to link kernel entry(kasm.o) and kernel function(kc.o)
ld -m elf_i386 -T source/link.ld -o kernel.bin object/kasm.o object/kc.o object/isr.o object/system.o object/string.o object/screen.o object/kb.o object/idt.o object/util.o object/shell.o
#copy compiled kernel(kernel.bin) to disk image folder
cp kernel.bin 11D/boot/kernel.bin
#launch kernel in qemu emulator
qemu-system-i386 -kernel kernel.bin
#create disk image with grub bootloader
grub-mkrescue -o 11DOS.iso 11D/

#error prevention
read a
