	.arch athlon
	.p2align 4,,15
.global T7a__f
	.type T7a__f, @function
T7a__f:
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
	.size T7a__f, .-T7a__f
	.p2align 4,,15
	.type OOC_T7a_init, @function
OOC_T7a_init:
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
	.size OOC_T7a_init, .-OOC_T7a_init
.global OOC_T7a_init0
	.type OOC_T7a_init0, @function
OOC_T7a_init0:
	call OOC_T7a_init
	ret
	.size OOC_T7a_init0, .-OOC_T7a_init0
