	.arch pentium4
	.p2align 4,,15
.global T5__f
	.type T5__f, @function
T5__f:
	pushl %ebp
	movl %esp, %ebp
	pushl %edi
	pushl %esi
	pushl %ebx
	subl $12, %esp
	movl 12(%ebp), %eax
	movl 8(%ebp), %ecx
	cmpl %ecx, 12(%ebp)
	jle .L2
.L1:
	xchgl %eax, %ecx
.L2:
	subl %eax, %ecx
	movl %ecx, %eax
	jmp .LE_T5__f
	movl $_mid, 0(%esp)
	movl $22, 4(%esp)
	call RT0__ErrorFailedFunction
.LE_T5__f:
	lea -12(%ebp), %esp
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
.LE_OOC_T5_init:
	lea -12(%ebp), %esp
	popl %ebx
	popl %esi
	popl %edi
	leave 
	ret 
	.size OOC_T5_init, .-OOC_T5_init
.global OOC_T5_open
	.type OOC_T5_open, @function
OOC_T5_open:
	call OOC_T5_init
	ret
	.size OOC_T5_open, .-OOC_T5_open
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
