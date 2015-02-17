.globl _start

_start:
    call main
    movl $1, %eax   #syscall number for SYS_exit
    xorl %ebx, %ebx #argument to SYS_exit is 0
    int $0x80
