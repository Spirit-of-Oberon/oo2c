	.arch athlon
	.p2align 4,,15
.global T1__f
	.type T1__f, @function
T1__f:
	pushl %ebp
	movl %esp, %ebp
	subl $0, %esp
	pushl %edi
	pushl %esi
	pushl %ebx
	movl 8(%ebp), %eax
	negl %eax
	popl %ebx
	popl %esi
	popl %edi
	leave 
	ret 
	.size T1__f, .-T1__f
