	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 15	sdk_version 10, 15, 4
	.globl	_main                   ## -- Begin function main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	movl	$0, -4(%rbp)
	movl	%edi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movl	$5, -28(%rbp)
	movl	$7, -32(%rbp)
	movl	$0, -36(%rbp)
	movl	-28(%rbp), %eax
	addl	-32(%rbp), %eax
	movl	%eax, -36(%rbp)
	movl	$16, %edi
	callq	_malloc
	xorl	%ecx, %ecx
	movq	%rax, -24(%rbp)
	movq	-24(%rbp), %rax
	movl	$2, (%rax)
	movq	-24(%rbp), %rax
	movl	$3, 4(%rax)
	movq	-24(%rbp), %rax
	movl	$5, 8(%rax)
	movq	-24(%rbp), %rax
	movl	$7, 12(%rax)
	movl	%ecx, %eax
	addq	$48, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"Hello Edsgar Dijkstra."

	.section	__DATA,__data
	.globl	_str                    ## @str
	.p2align	3
_str:
	.quad	L_.str


.subsections_via_symbols
