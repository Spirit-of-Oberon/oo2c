	.arch athlon
	.p2align 4,,15
.global T8a__f
	.type T8a__f, @function
T8a__f:
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
	jmp .L5
.L3:
	cmpb $0, 16(%ebp)
	jne .L2
.L4:
	movl $-9, %eax
.L5:
	popl %ebx
	popl %esi
	popl %edi
	leave 
	ret 
	.size T8a__f, .-T8a__f
	.p2align 4,,15
	.type OOC_T8a_init, @function
OOC_T8a_init:
	pushl %ebp
	movl %esp, %ebp
	subl $0, %esp
	pushl %edi
	pushl %esi
	pushl %ebx
	popl %ebx
	popl %esi
	popl %edi
	leave 
	ret 
	.size OOC_T8a_init, .-OOC_T8a_init
.global OOC_T8a_init0
	.type OOC_T8a_init0, @function
OOC_T8a_init0:
	call OOC_T8a_init
	ret
	.size OOC_T8a_init0, .-OOC_T8a_init0
