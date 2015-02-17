typedef unsigned int uint32;

uint32 strlen(char* buf) {
    uint32 count = 0;
    while (*buf != '\0') {
        buf++;
        count++;
    }
    return count;
}

void print(char* buf) {
    uint32 length = strlen(buf);
    // syscall number for write
    asm("movl $4, %eax");
    // ebx stores the fd to use, 1 corresponds to stdout
    asm("movl $1, %ebx");
    // ecx stores the buffer pointer
    asm("movl %0, %%ecx"
        :
        : "m"(buf)
       );
    // edx stores the amount of bytes to write
    asm("movl %0, %%edx"
        :
        : "m"(length)
       );
    // call the syscall
    asm("int $0x80");
}

int main() {
    print("Hello, world!\n\0");
    return 0;
}
