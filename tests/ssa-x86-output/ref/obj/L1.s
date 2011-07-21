	.arch pentium4
	.p2align 4,,15
.global L1__f
	.type L1__f, @function
L1__f:
	pushl %ebp
	movl %esp, %ebp
	pushl %edi
	pushl %esi
	pushl %ebx
	subl $12, %esp
	movl $0, %edx
.L1:
	movl %edx, %eax
	movl 8(%ebp), %ecx
	cmpb $0, (%ecx,%eax)
	jne .L3
.L2:
	movl %edx, %eax
	jmp .L4
.L3:
	incl %edx
	jmp .L1
.L4:
	jmp .LE_L1__f
	movl $_mid, 0(%esp)
	movl $22, 4(%esp)
	call RT0__ErrorFailedFunction
.LE_L1__f:
	lea -12(%ebp), %esp
	popl %ebx
	popl %esi
	popl %edi
	leave 
	ret 
	.size L1__f, .-L1__f
	.p2align 4,,15
	.type OOC_L1_init, @function
OOC_L1_init:
	pushl %ebp
	movl %esp, %ebp
	pushl %edi
	pushl %esi
	pushl %ebx
	subl $0, %esp
.LE_OOC_L1_init:
	lea -12(%ebp), %esp
	popl %ebx
	popl %esi
	popl %edi
	leave 
	ret 
	.size OOC_L1_init, .-OOC_L1_init
.global OOC_L1_open
	.type OOC_L1_open, @function
OOC_L1_open:
	call OOC_L1_init
	ret
	.size OOC_L1_open, .-OOC_L1_open
	.data
	.align 4
	.type _td_L1__34_base_types, @object
	.size _td_L1__34_base_types, 4
_td_L1__34_base_types:
	.long RT0__char
	.type _td_L1__34, @object
	.size _td_L1__34, 36
_td_L1__34:
	.long _td_L1__34_base_types
	.long 0
	.long 0
	.long _mid
	.long 0
	.long 1
	.long 1
	.long 1
	.byte -2
	.zero 3
	.type _mid_name, @object
	.size _mid_name, 3
_mid_name:
	.string "L1"
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
