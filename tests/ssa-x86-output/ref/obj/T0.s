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
	.p2align 4,,15
	.type OOC_T0_init, @function
OOC_T0_init:
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
	.size OOC_T0_init, .-OOC_T0_init
.global OOC_T0_init0
	.type OOC_T0_init0, @function
OOC_T0_init0:
	call OOC_T0_init
	ret
	.size OOC_T0_init0, .-OOC_T0_init0
