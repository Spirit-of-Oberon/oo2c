	.arch athlon
	.p2align 4,,15
.global T6__f
	.type T6__f, @function
T6__f:
	pushl %ebp
	movl %esp, %ebp
	subl $0, %esp
	pushl %edi
	pushl %esi
	pushl %ebx
	cmpb $0, 8(%ebp)
	je .L3
.L1:
	cmpb $0, 12(%ebp)
	je .L3
.L2:
	movl $9, %eax
	jmp .L4
.L3:
	movl $-9, %eax
.L4:
	popl %ebx
	popl %esi
	popl %edi
	leave 
	ret 
	.size T6__f, .-T6__f
