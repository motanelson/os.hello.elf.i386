//as -32 ashello.asm -o hello.o
//gcc -m32 -nostdlib -fno-pie -no-pie hello.c -o hello
extern void putss (char *c);
extern void exitss (int c);

int main(){
    char *c="hello................................\n";
    putss(c);
    exitss(0);
    return 0;
}