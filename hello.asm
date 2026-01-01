; hello.asm
;nasm -f elf32 -o hello.o hello.asm
;ld -m elf_i386 hello.o -o hello
BITS 32
global _start

section .text
_start:
    mov eax, 4      ; sys_write
    mov ebx, 1      ; stdout
    mov ecx, msg
    mov edx, msglen
    int 0x80

    mov eax, 1      ; sys_exit
    xor ebx, ebx
    int 0x80

section .data
msg db 27,"[40;37m",10,"Hello world.....", 10
msglen equ $ - msg