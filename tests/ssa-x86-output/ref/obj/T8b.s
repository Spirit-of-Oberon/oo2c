	.arch athlon
	.p2align 4,,15
.global T8b__f
	.type T8b__f, @function
T8b__f:
	pushl %ebp
	movl %esp, %ebp
	subl $0, %esp
	pushl %edi
	pushl %esi
	pushl %ebx
	cmpb $0, 8(%ebp)
	je .L4
.L1:
	cmpb $0, 12(%ebp)
	jne .L3
.L2:
	cmpb $0, 16(%ebp)
	je .L4
.L3:
	movl $9, %eax
	jmp .L5
.L4:
	movl $-9, %eax
.L5:
	popl %ebx
	popl %esi
	popl %edi
	leave 
	ret 
	.size T8b__f, .-T8b__f
	.p2align 4,,15
	.type OOC_T8b_init, @function
OOC_T8b_init:
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
	.size OOC_T8b_init, .-OOC_T8b_init
.global OOC_T8b_init0
	.type OOC_T8b_init0, @function
OOC_T8b_init0:
	call OOC_T8b_init
	ret
	.size OOC_T8b_init0, .-OOC_T8b_init0
	.data
	.align 4
	.type _mid_name, @object
	.size _mid_name, 4
_mid_name:
	.string "T8b"
	.type _mid_tdlist, @object
	.size _mid_tdlist, 4
_mid_tdlist:
	.long 0
	.type _mid, @object
	.size _mid, 8
_mid:
	.long _mid_name
	.long _mid_tdlist
