	.arch athlon
	.p2align 4,,15
	.type C1__Sub, @function
C1__Sub:
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
	.size C1__Sub, .-C1__Sub
	.p2align 4,,15
.global C1__f
	.type C1__f, @function
C1__f:
	pushl %ebp
	movl %esp, %ebp
	subl $8, %esp
	pushl %edi
	pushl %esi
	pushl %ebx
	movl 12(%ebp), %eax
	movl 8(%ebp), %ecx
	movl %ecx, 0(%esp)
	movl %eax, 4(%esp)
	call C1__Sub
	popl %ebx
	popl %esi
	popl %edi
	leave 
	ret 
	.size C1__f, .-C1__f
	.p2align 4,,15
	.type OOC_C1_init, @function
OOC_C1_init:
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
	.size OOC_C1_init, .-OOC_C1_init
.global OOC_C1_init0
	.type OOC_C1_init0, @function
OOC_C1_init0:
	call OOC_C1_init
	ret
	.size OOC_C1_init0, .-OOC_C1_init0
