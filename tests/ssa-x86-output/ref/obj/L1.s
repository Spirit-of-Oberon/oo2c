	.arch athlon
	.p2align 4,,15
.global L1__f
	.type L1__f, @function
L1__f:
	pushl %ebp
	movl %esp, %ebp
	subl $4, %esp
	pushl %edi
	pushl %esi
	pushl %ebx
	mov $0, %edx
.L1:
	movl %edx, %eax
	movl 8(%ebp), %ecx
	cmpb $0, (%ecx,%eax)
	je .L3
.L2:
	incl %edx
	jmp .L1
.L3:
	movl %edx, %eax
	popl %ebx
	popl %esi
	popl %edi
	leave 
	ret 
	.size L1__f, .-L1__f
	.p2align 4,,15
	.type OOC_L1_init, @function
OOC_L1_init:
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
	.size OOC_L1_init, .-OOC_L1_init
.global OOC_L1_init0
	.type OOC_L1_init0, @function
OOC_L1_init0:
	call OOC_L1_init
	ret
	.size OOC_L1_init0, .-OOC_L1_init0
