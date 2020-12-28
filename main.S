	.text
	.section	.rodata	
.STR0:
	.string	"%d "
.STR1:
	.string	"%d\n"
	.text	
	.globl	main
	.type	main, @function
main:
	endbr32
	pushl	%ebp
	movl	%esp, %ebp
	subl	$12, %esp
	movl	$0, -4(%ebp)
	movl	$0, %eax
	jmp	.L0
.L1:
	movl	-4(%ebp), %ecx
	imull	$2, %ecx
	movl	%ecx, -12(%ebp)
	movl	%ecx, %eax
	pushl	%eax
	movl	-4(%ebp), %eax
	movl	%eax, -8(%ebp)
	popl	%eax
	movl	-4(%ebp), %eax
	pushl	-12(%ebp)
	pushl	$.STR0
	call	printf
	addl	$8, %esp
	pushl	-8(%ebp)
	pushl	$.STR1
	call	printf
	addl	$8, %esp
	movl	-4(%ebp), %eax
	addl	$1, %eax
	movl	%eax, -4(%ebp)
.L0:
	movl	$10, %eax
	cmpl	%eax, -4(%ebp)
	setl	%al
	movzbl %al, %eax
	cmpl	$1, %eax
	je	.L1
	movl	$0, %eax
	addl	$12, %esp
	popl	%ebp
	ret
	.section	.note.GNU-stack,"",@progbits
