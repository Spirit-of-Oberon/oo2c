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
	.p2align 4,,15
	.type OOC_T2_init, @function
OOC_T2_init:
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
	.size OOC_T2_init, .-OOC_T2_init
.global OOC_T2_init0
	.type OOC_T2_init0, @function
OOC_T2_init0:
	call OOC_T2_init
	ret
	.size OOC_T2_init0, .-OOC_T2_init0
