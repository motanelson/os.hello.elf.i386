/* hello.c - Linux i386, sem libc */
//gcc -m32 -nostdlib -fno-pie -no-pie hello.c -o hello
typedef unsigned int uint;

/* ---------------------------
   strlen manual
   --------------------------- */
uint len(const char *s) {
    uint n = 0;
    while (s[n] != 0)
        n++;
    return n;
}

/* ---------------------------
   syscall write (int 0x80)
   eax = 4
   ebx = fd
   ecx = buffer
   edx = size
   --------------------------- */
void sys_write(int fd, const char *buf, uint size) {
    __asm__ __volatile__ (
        "int $0x80"
        :
        : "a"(4), "b"(fd), "c"(buf), "d"(size)
        : "memory"
    );
}

/* ---------------------------
   sputs: escreve string
   --------------------------- */
void sputs(const char *s) {
    sys_write(1, s, len(s));
}

/* ---------------------------
   syscall exit (int 0x80)
   eax = 1
   ebx = status
   --------------------------- */
void exits(int code) {
    __asm__ __volatile__ (
        "int $0x80"
        :
        : "a"(1), "b"(code)
        : "memory"
    );
}

/* ---------------------------
   Entry point real
   --------------------------- */
void _start(void) {
    sputs("Hello from gcc -nostdlib i386\n");
    exits(0);
}

