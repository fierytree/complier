	.text
	.section	.rodata	
.STR0:
	.string	"%d\n"
	.text	
	.globl	func1
	.type	func1, @function
func1:
	endbr32
	pushl	%ebp
	movl	%esp, %ebp
	subl	$4, %esp
	movl	$1, -4(%ebp)
	movl	$1, %eax
	movl	-4(%ebp), %eax
	addl	$4, %esp
	popl	%ebp
	ret
	.text	
	.globl	func2
	.type	func2, @function
func2:
	endbr32
	pushl	%ebp
	movl	%esp, %ebp
	subl	$4, %esp
	movl	$2, -4(%ebp)
	movl	$2, %eax
	movl	-4(%ebp), %eax
	addl	$4, %esp
	popl	%ebp
	ret
	.text	
	.globl	func3
	.type	func3, @function
func3:
	endbr32
	pushl	%ebp
	movl	%esp, %ebp
	subl	$4, %esp
	movl	$4, -4(%ebp)
	movl	$4, %eax
	movl	-4(%ebp), %eax
	addl	$4, %esp
	popl	%ebp
	ret
	.text	
	.globl	func4
	.type	func4, @function
func4:
	endbr32
	pushl	%ebp
	movl	%esp, %ebp
	subl	$12, %esp
	movl	$8, -8(%ebp)
	movl	$8, %eax
	pushl	%eax
	movl	-8(%ebp), %eax
	movl	%eax, -4(%ebp)
	popl	%eax
	movl	-8(%ebp), %eax
	movl	$16, -12(%ebp)
	movl	$16, %eax
	movl	-4(%ebp), %eax
	addl	-12(%ebp), %eax
	movl	%eax, -4(%ebp)
	movl	-4(%ebp), %eax
	addl	$12, %esp
	popl	%ebp
	ret
	.text	
	.globl	main
	.type	main, @function
main:
	endbr32
	pushl	%ebp
	movl	%esp, %ebp
	subl	$12, %esp
	movl	$32, -4(%ebp)
	movl	$32, %eax
	movl	$32, -8(%ebp)
	movl	$32, %eax
	movl	$32, -12(%ebp)
	movl	$32, %eax
	call	func1
	movl	%eax, %ecx
	addl	$0, %esp
	call	func2
	movl	%eax, %edx
	addl	$0, %esp
	addl	%edx, %ecx
	call	func3
	movl	%eax, %edx
	addl	$0, %esp
	addl	%edx, %ecx
	call	func4
	movl	%eax, %edx
	addl	$0, %esp
	addl	%edx, %ecx
	addl	-4(%ebp), %ecx
	addl	-8(%ebp), %ecx
	addl	-12(%ebp), %ecx
	pushl	%ecx
	pushl	$.STR0
	call	printf
	addl	$8, %esp
	movl	$0, %eax
	addl	$12, %esp
	popl	%ebp
	ret
	.section	.note.GNU-stack,"",@progbits
