	.arch athlon
	.p2align 4,,15
.global T3__f
	.type T3__f, @function
T3__f:
	pushl %ebp
	movl %esp, %ebp
	pushl %edi
	pushl %esi
	pushl %ebx
	subl $8, %esp
	cmpb $0, 8(%ebp)
	je .L2
.L1:
	movl 12(%ebp), %eax
	addl 16(%ebp), %eax
	jmp .LE_T3__f
	jmp .L3
.L2:
	movl 12(%ebp), %eax
	subl 16(%ebp), %eax
	jmp .LE_T3__f
.L3:
	movl $_mid, 0(%esp)
	movl $22, 4(%esp)
	call RT0__ErrorFailedFunction
.LE_T3__f:
	lea -12(%ebp), %esp
	popl %ebx
	popl %esi
	popl %edi
	leave 
	ret 
	.size T3__f, .-T3__f
	.p2align 4,,15
	.type OOC_T3_init, @function
OOC_T3_init:
	pushl %ebp
	movl %esp, %ebp
	pushl %edi
	pushl %esi
	pushl %ebx
	subl $0, %esp
.LE_OOC_T3_init:
	lea -12(%ebp), %esp
	popl %ebx
	popl %esi
	popl %edi
	leave 
	ret 
	.size OOC_T3_init, .-OOC_T3_init
.global OOC_T3_init0
	.type OOC_T3_init0, @function
OOC_T3_init0:
	call OOC_T3_init
	ret
	.size OOC_T3_init0, .-OOC_T3_init0
	.data
	.align 4
	.type _mid_name, @object
	.size _mid_name, 3
_mid_name:
	.string "T3"
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
