	.arch athlon
	.p2align 4,,15
.global T6__f
	.type T6__f, @function
T6__f:
	pushl %ebp
	movl %esp, %ebp
	pushl %edi
	pushl %esi
	pushl %ebx
	subl $0, %esp
	cmpb $0, 8(%ebp)
	je .L3
.L1:
	cmpb $0, 12(%ebp)
	je .L3
.L2:
	movl $9, %eax
	jmp .L4
.L3:
	movl $-9, %eax
.L4:
	addl $0, %esp
	popl %ebx
	popl %esi
	popl %edi
	leave 
	ret 
	.size T6__f, .-T6__f
	.p2align 4,,15
	.type OOC_T6_init, @function
OOC_T6_init:
	pushl %ebp
	movl %esp, %ebp
	pushl %edi
	pushl %esi
	pushl %ebx
	subl $0, %esp
	addl $0, %esp
	popl %ebx
	popl %esi
	popl %edi
	leave 
	ret 
	.size OOC_T6_init, .-OOC_T6_init
.global OOC_T6_init0
	.type OOC_T6_init0, @function
OOC_T6_init0:
	call OOC_T6_init
	ret
	.size OOC_T6_init0, .-OOC_T6_init0
	.data
	.align 4
	.type _mid_name, @object
	.size _mid_name, 3
_mid_name:
	.string "T6"
	.align 4
	.type _mid_tdlist, @object
	.size _mid_tdlist, 4
_mid_tdlist:
	.long 0
	.type _mid, @object
	.size _mid, 8
_mid:
	.long _mid_name
	.long _mid_tdlist
