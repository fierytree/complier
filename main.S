	.section	.rodata	
.STR0:
	.string	"%d"
	.text
	.globl	main
	.type	main, @function
main:
	endbr32
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	movl	$10, -4(%ebp)
	movl	-4(%ebp), %eax
	imull	$111, %eax
	movl	-4(%ebp), %ecx
	addl	$1, %ecx
	imull	-4(%ebp), %ecx
	notl	%ecx
	addl	%ecx, %eax
	movl	%eax, -8(%ebp)
	pushl	-8(%ebp)
	pushl	$.STR0
	call	printf
	addl	$8, %esp
	movl	$0, %eax
	addl	$8, %esp
	popl	%ebp
	ret
	.section	.note.GNU-stack,"",@progbits
