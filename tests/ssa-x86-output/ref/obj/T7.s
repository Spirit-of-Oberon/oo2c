	.arch athlon
	.p2align 4,,15
.global T7__f
	.type T7__f, @function
T7__f:
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
	jmp .L4
.L3:
	movl $9, %eax
.L4:
	popl %ebx
	popl %esi
	popl %edi
	leave 
	ret 
	.size T7__f, .-T7__f
	.p2align 4,,15
	.type OOC_T7_init, @function
OOC_T7_init:
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
	.size OOC_T7_init, .-OOC_T7_init
.global OOC_T7_init0
	.type OOC_T7_init0, @function
OOC_T7_init0:
	call OOC_T7_init
	ret
	.size OOC_T7_init0, .-OOC_T7_init0