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
	movl	$5, -20(%rbp)
	movl	$7, -24(%rbp)
	movl	$0, -28(%rbp)
	movl	-20(%rbp), %eax
	addl	-24(%rbp), %eax
	movl	%eax, -28(%rbp)
	movl	$16, %edi
	callq	_malloc
	movq	%rax, -40(%rbp)
	movq	-40(%rbp), %rax
	movl	$2, (%rax)
	movq	-40(%rbp), %rax
	movl	$3, 4(%rax)
	movq	-40(%rbp), %rax
	movl	$5, 8(%rax)
	movq	-40(%rbp), %rax
	movl	$7, 12(%rax)
	movl	$16, %edi
	callq	_malloc
	xorl	%ecx, %ecx
	movq	%rax, -48(%rbp)
	movq	-48(%rbp), %rax
	movl	$10, (%rax)
	movq	-48(%rbp), %rax
	movl	$11, 4(%rax)
	movq	-48(%rbp), %rax
	movl	$12, 8(%rax)
	movq	-48(%rbp), %rax
	movl	$13, 12(%rax)
	movl	%ecx, %eax
	addq	$48, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"Hello Edsger Dijkstra."

	.section	__DATA,__data
	.globl	_str                    ## @str
	.p2align	3
_str:
	.quad	L_.str

	.globl	_len                    ## @len
	.p2align	2
_len:
	.long	7                       ## 0x7

	.globl	_si                     ## @si
	.p2align	1
_si:
	.short	3                       ## 0x3

	.globl	_c                      ## @c
_c:
	.byte	5                       ## 0x5


.subsections_via_symbols
