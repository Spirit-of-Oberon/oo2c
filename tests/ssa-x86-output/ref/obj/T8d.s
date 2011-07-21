	.arch pentium4
	.p2align 4,,15
.global T8d__f
	.type T8d__f, @function
T8d__f:
	pushl %ebp
	movl %esp, %ebp
	pushl %edi
	pushl %esi
	pushl %ebx
	subl $8, %esp
	cmpb $0, 8(%ebp)
	jne .L4
.L1:
	cmpb $0, 12(%ebp)
	je .L3
.L2:
	cmpb $0, 16(%ebp)
	jne .L4
.L3:
	movl $-9, %eax
	jmp .LE_T8d__f
	jmp .L5
.L4:
	movl $9, %eax
	jmp .LE_T8d__f
.L5:
	movl $_mid, 0(%esp)
	movl $23, 4(%esp)
	call RT0__ErrorFailedFunction
.LE_T8d__f:
	lea -12(%ebp), %esp
	popl %ebx
	popl %esi
	popl %edi
	leave 
	ret 
	.size T8d__f, .-T8d__f
	.p2align 4,,15
	.type OOC_T8d_init, @function
OOC_T8d_init:
	pushl %ebp
	movl %esp, %ebp
	pushl %edi
	pushl %esi
	pushl %ebx
	subl $0, %esp
.LE_OOC_T8d_init:
	lea -12(%ebp), %esp
	popl %ebx
	popl %esi
	popl %edi
	leave 
	ret 
	.size OOC_T8d_init, .-OOC_T8d_init
.global OOC_T8d_init0
	.type OOC_T8d_init0, @function
OOC_T8d_init0:
	call OOC_T8d_init
	ret
	.size OOC_T8d_init0, .-OOC_T8d_init0
	.data
	.align 4
	.type _mid_name, @object
	.size _mid_name, 4
_mid_name:
	.string "T8d"
	.type _mid_tdlist, @object
	.size _mid_tdlist, 4
_mid_tdlist:
	.long 0
	.type _mid, @object
	.size _mid, 8
_mid:
	.long _mid_name
	.long _mid_tdlist
