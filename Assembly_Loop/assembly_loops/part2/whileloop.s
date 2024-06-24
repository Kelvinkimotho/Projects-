	.file	"whileloop.c"
	.text
.globl _sum_with_while
	.def	_sum_with_while;	.scl	2;	.type	32;	.endef
_sum_with_while:
	pushl	%ebp
	movl	%esp, %ebp
	movl	8(%ebp), %edx
	movl	12(%ebp), %ecx
	cmpl	%ecx, %edx
	jle	L2
	movl	$0, %eax
	jmp	L3
L2:
	movl	$0, %eax
L4:
	addl	%edx, %eax
	incl	%edx
	cmpl	%edx, %ecx
	jge	L4
L3:
	leave
	ret
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
	.align 4
LC0:
	.ascii "Sum of numbers from %d to %d is: %d\12\0"
	.text
.globl _main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
	pushl	%ebp
	movl	%esp, %ebp
	andl	$-16, %esp
	subl	$16, %esp
	call	___main
	movl	$10, 4(%esp)
	movl	$1, (%esp)
	call	_sum_with_while
	movl	%eax, 12(%esp)
	movl	$10, 8(%esp)
	movl	$1, 4(%esp)
	movl	$LC0, (%esp)
	call	_printf
	movl	$0, %eax
	leave
	ret
	.def	_printf;	.scl	2;	.type	32;	.endef
