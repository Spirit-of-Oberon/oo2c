	.arch athlon
	.p2align 4,,15
.global T4__f
	.type T4__f, @function
T4__f:
	pushl %ebp
	movl %esp, %ebp
	subl $4, %esp
	pushl %edi
	pushl %esi
	pushl %ebx
	cmpb $0, 8(%ebp)
	je .L2
.L1:
	movl 12(%ebp), %ecx
	addl 16(%ebp), %ecx
	mov %ecx, %eax
	jmp .L3
.L2:
	movl 12(%ebp), %eax
	subl 16(%ebp), %eax
.L3:
	popl %ebx
	popl %esi
	popl %edi
	leave 
	ret 
	.size T4__f, .-T4__f
