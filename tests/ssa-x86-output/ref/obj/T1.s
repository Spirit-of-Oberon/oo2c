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
	.p2align 4,,15
	.type OOC_T1_init, @function
OOC_T1_init:
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
	.size OOC_T1_init, .-OOC_T1_init
.global OOC_T1_init0
	.type OOC_T1_init0, @function
OOC_T1_init0:
	call OOC_T1_init
	ret
	.size OOC_T1_init0, .-OOC_T1_init0
