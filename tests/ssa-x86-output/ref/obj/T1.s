	.arch athlon
	.p2align 4,,15
.global T1__f
	.type T1__f, @function
T1__f:
	pushl %ebp
	movl %esp, %ebp
	pushl %edi
	pushl %esi
	pushl %ebx
	subl $8, %esp
	movl 8(%ebp), %eax
	negl %eax
	jmp .LE_T1__f
	movl $_mid, 0(%esp)
	movl $22, 4(%esp)
	call RT0__ErrorFailedFunction
.LE_T1__f:
	lea -12(%ebp), %esp
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
	pushl %edi
	pushl %esi
	pushl %ebx
	subl $0, %esp
.LE_OOC_T1_init:
	lea -12(%ebp), %esp
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
	.data
	.align 4
	.type _mid_name, @object
	.size _mid_name, 3
_mid_name:
	.string "T1"
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
