	.arch athlon
	.p2align 4,,15
.global T3__f
	.type T3__f, @function
T3__f:
	pushl %ebp
	movl %esp, %ebp
	subl $0, %esp
	pushl %edi
	pushl %esi
	pushl %ebx
	cmpb $0, 8(%ebp)
	je .L2
.L1:
	movl 12(%ebp), %eax
	addl 16(%ebp), %eax
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
	.size T3__f, .-T3__f
