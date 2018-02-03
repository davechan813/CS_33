#include <unistd.h>
#include <sys/syscall.h>
#include <sys/types.h>

void deTarget(){
	asm("\
		movq $0x57, %rax\n\
		movq $0x7fffffffcea5, %rdi\n\
		syscall\n\
	");
}