	.file	"test6.c"
	.text
	.globl	func1
	.type	func1, @function
func1:
	endbr32
	pushl	%ebp
	movl	%esp, %ebp
	subl	$16, %esp
	movl	$1, -4(%ebp)
	movl	-4(%ebp), %eax
	leave
	ret
	.globl	func2
	.type	func2, @function
func2:
	endbr32
	pushl	%ebp
	movl	%esp, %ebp
	subl	$16, %esp
	movl	$2, -4(%ebp)
	movl	-4(%ebp), %eax
	leave
	ret
	.globl	func3
	.type	func3, @function
func3:
	endbr32
	pushl	%ebp
	movl	%esp, %ebp
	subl	$16, %esp
	movl	$4, -4(%ebp)
	movl	-4(%ebp), %eax
	leave
	ret
	.globl	func4
	.type	func4, @function
func4:
	endbr32
	pushl	%ebp
	movl	%esp, %ebp
	subl	$16, %esp
	movl	$8, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, -8(%ebp)
	movl	$16, -4(%ebp)
	movl	-4(%ebp), %eax
	addl	%eax, -8(%ebp)
	movl	-8(%ebp), %eax
	leave
	ret
	.section	.rodata
.LC0:
	.string	"%d\n"
	.text
	.globl	main
	.type	main, @function
main:
	endbr32
	leal	4(%esp), %ecx
	andl	$-16, %esp
	pushl	-4(%ecx)
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ebx
	pushl	%ecx
	subl	$16, %esp
	movl	$32, -20(%ebp)
	movl	$32, -16(%ebp)
	movl	$32, -12(%ebp)
	call	func1
	movl	%eax, %ebx
	call	func2
	addl	%eax, %ebx
	call	func3
	addl	%eax, %ebx
	call	func4
	leal	(%ebx,%eax), %edx
	movl	-20(%ebp), %eax
	addl	%eax, %edx
	movl	-16(%ebp), %eax
	addl	%eax, %edx
	movl	-12(%ebp), %eax
	addl	%edx, %eax
	subl	$8, %esp
	pushl	%eax
	pushl	$.LC0
	call	printf
	addl	$16, %esp
	movl	$0, %eax
	leal	-8(%ebp), %esp
	popl	%ecx
	popl	%ebx
	popl	%ebp
	leal	-4(%ecx), %esp
	ret
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 4
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 4
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 4
4:
