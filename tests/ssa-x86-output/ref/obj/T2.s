	.arch pentium4
	.p2align 4,,15
.global T2__f
	.type T2__f, @function
T2__f:
	pushl %ebp
	movl %esp, %ebp
	pushl %edi
	pushl %esi
	pushl %ebx
	subl $8, %esp
	movl 8(%ebp), %eax
	subl 12(%ebp), %eax
	jmp .LE_T2__f
	movl $_mid, 0(%esp)
	movl $22, 4(%esp)
	call RT0__ErrorFailedFunction
.LE_T2__f:
	lea -12(%ebp), %esp
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
	pushl %edi
	pushl %esi
	pushl %ebx
	subl $0, %esp
.LE_OOC_T2_init:
	lea -12(%ebp), %esp
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
	.data
	.align 4
	.type _mid_name, @object
	.size _mid_name, 3
_mid_name:
	.string "T2"
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
