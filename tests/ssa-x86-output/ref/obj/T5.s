	.arch athlon
	.p2align 4,,15
.global T5__f
	.type T5__f, @function
T5__f:
	pushl %ebp
	movl %esp, %ebp
	pushl %edi
	pushl %esi
	pushl %ebx
	subl $4, %esp
	movl 12(%ebp), %eax
	movl 8(%ebp), %ecx
	cmpl %ecx, 12(%ebp)
	jle .L2
.L1:
	xchgl %eax, %ecx
.L2:
	subl %eax, %ecx
	movl %ecx, %eax
	addl $4, %esp
	popl %ebx
	popl %esi
	popl %edi
	leave 
	ret 
	.size T5__f, .-T5__f
	.p2align 4,,15
	.type OOC_T5_init, @function
OOC_T5_init:
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
	.size OOC_T5_init, .-OOC_T5_init
.global OOC_T5_init0
	.type OOC_T5_init0, @function
OOC_T5_init0:
	call OOC_T5_init
	ret
	.size OOC_T5_init0, .-OOC_T5_init0
	.data
	.align 4
	.type _mid_name, @object
	.size _mid_name, 3
_mid_name:
	.string "T5"
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
