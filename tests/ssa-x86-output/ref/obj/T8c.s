	.arch athlon
	.p2align 4,,15
.global T8c__f
	.type T8c__f, @function
T8c__f:
	pushl %ebp
	movl %esp, %ebp
	subl $0, %esp
	pushl %edi
	pushl %esi
	pushl %ebx
	cmpb $0, 8(%ebp)
	jne .L3
.L1:
	cmpb $0, 12(%ebp)
	jne .L3
.L2:
	movl $-9, %eax
	jmp .L5
.L3:
	cmpb $0, 16(%ebp)
	je .L2
.L4:
	movl $9, %eax
.L5:
	popl %ebx
	popl %esi
	popl %edi
	leave 
	ret 
	.size T8c__f, .-T8c__f
