	.arch athlon
	.p2align 4,,15
.global T7b__f
	.type T7b__f, @function
T7b__f:
	pushl %ebp
	movl %esp, %ebp
	subl $0, %esp
	pushl %edi
	pushl %esi
	pushl %ebx
	cmpb $0, 8(%ebp)
	jne .L4
.L1:
	cmpb $0, 12(%ebp)
	jne .L4
.L2:
	cmpb $0, 16(%ebp)
	jne .L4
.L3:
	movl $-9, %eax
	jmp .L5
.L4:
	movl $9, %eax
.L5:
	popl %ebx
	popl %esi
	popl %edi
	leave 
	ret 
	.size T7b__f, .-T7b__f
