BITS 32	;32 bits operating system

section		.text
	align	4
	dd			0x1BADB002
	dd 		0x00
	dd			-(0x1BADB002+0X00)

global start
extern kmain	;function included in kernel.c
start:
	cli			;clear interrupt
	call kmain	;send processor to continue in kmain in kernel.c
	hlt			;halt processor
