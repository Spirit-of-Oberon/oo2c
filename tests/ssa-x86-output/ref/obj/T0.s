	.arch athlon
	.p2align 4,,15
.global T0__f
	.type T0__f, @function
T0__f:
	pushl %ebp
	movl %esp, %ebp
	subl $0, %esp
	pushl %edi
	pushl %esi
	pushl %ebx
	movl 8(%ebp), %eax
	popl %ebx
	popl %esi
	popl %edi
	leave 
	ret 
	.size T0__f, .-T0__f
