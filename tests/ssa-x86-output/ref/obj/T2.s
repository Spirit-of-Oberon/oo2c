	.arch athlon
	.p2align 4,,15
.global T2__f
	.type T2__f, @function
T2__f:
	pushl %ebp
	movl %esp, %ebp
	subl $0, %esp
	pushl %edi
	pushl %esi
	pushl %ebx
	movl 8(%ebp), %eax
	subl 12(%ebp), %eax
	popl %ebx
	popl %esi
	popl %edi
	leave 
	ret 
	.size T2__f, .-T2__f
