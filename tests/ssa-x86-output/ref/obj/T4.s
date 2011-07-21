	.arch pentium4
	.p2align 4,,15
.global T4__f
	.type T4__f, @function
T4__f:
	pushl %ebp
	movl %esp, %ebp
	pushl %edi
	pushl %esi
	pushl %ebx
	subl $12, %esp
	cmpb $0, 8(%ebp)
	je .L2
.L1:
	movl 12(%ebp), %eax
	addl 16(%ebp), %eax
	jmp .L3
.L2:
	movl 12(%ebp), %eax
	subl 16(%ebp), %eax
.L3:
	jmp .LE_T4__f
	movl $_mid, 0(%esp)
	movl $22, 4(%esp)
	call RT0__ErrorFailedFunction
.LE_T4__f:
	lea -12(%ebp), %esp
	popl %ebx
	popl %esi
	popl %edi
	leave 
	ret 
	.size T4__f, .-T4__f
	.p2align 4,,15
	.type OOC_T4_init, @function
OOC_T4_init:
	pushl %ebp
	movl %esp, %ebp
	pushl %edi
	pushl %esi
	pushl %ebx
	subl $0, %esp
.LE_OOC_T4_init:
	lea -12(%ebp), %esp
	popl %ebx
	popl %esi
	popl %edi
	leave 
	ret 
	.size OOC_T4_init, .-OOC_T4_init
.global OOC_T4_open
	.type OOC_T4_open, @function
OOC_T4_open:
	call OOC_T4_init
	ret
	.size OOC_T4_open, .-OOC_T4_open
	.data
	.align 4
	.type _mid_name, @object
	.size _mid_name, 3
_mid_name:
	.string "T4"
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
