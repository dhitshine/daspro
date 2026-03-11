	.file	"Soal-9.c"
	.intel_syntax noprefix
	.text
	.globl	cases
	.type	cases, @function
cases:
.LFB0:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 16
	mov	DWORD PTR -4[rbp], edi
	pxor	xmm1, xmm1
	cvtsi2sd	xmm1, DWORD PTR -4[rbp]
	movsd	xmm0, QWORD PTR .LC0[rip]
	mulsd	xmm1, xmm0
	movq	rax, xmm1
	movq	xmm0, rax
	call	exp@PLT
	movsd	xmm1, QWORD PTR .LC1[rip]
	mulsd	xmm1, xmm0
	movsd	xmm0, QWORD PTR .LC2[rip]
	addsd	xmm1, xmm0
	movsd	xmm0, QWORD PTR .LC3[rip]
	divsd	xmm0, xmm1
	cvttsd2si	eax, xmm0
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	cases, .-cases
	.section	.rodata
.LC4:
	.string	"Enter day number>> "
.LC5:
	.string	"%d"
	.align 8
.LC6:
	.string	"By day %d, model predicts %d cases total\n\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 16
	mov	rax, QWORD PTR fs:40
	mov	QWORD PTR -8[rbp], rax
	xor	eax, eax
	lea	rax, .LC4[rip]
	mov	rdi, rax
	mov	eax, 0
	call	printf@PLT
	lea	rax, -16[rbp]
	lea	rdx, .LC5[rip]
	mov	rsi, rax
	mov	rdi, rdx
	mov	eax, 0
	call	__isoc23_scanf@PLT
	mov	eax, DWORD PTR -16[rbp]
	mov	edi, eax
	call	cases
	mov	DWORD PTR -12[rbp], eax
	mov	eax, DWORD PTR -16[rbp]
	mov	edx, DWORD PTR -12[rbp]
	lea	rcx, .LC6[rip]
	mov	esi, eax
	mov	rdi, rcx
	mov	eax, 0
	call	printf@PLT
	lea	rax, .LC4[rip]
	mov	rdi, rax
	mov	eax, 0
	call	printf@PLT
	lea	rax, -16[rbp]
	lea	rdx, .LC5[rip]
	mov	rsi, rax
	mov	rdi, rdx
	mov	eax, 0
	call	__isoc23_scanf@PLT
	mov	eax, DWORD PTR -16[rbp]
	mov	edi, eax
	call	cases
	mov	DWORD PTR -12[rbp], eax
	mov	eax, DWORD PTR -16[rbp]
	mov	edx, DWORD PTR -12[rbp]
	lea	rcx, .LC6[rip]
	mov	esi, eax
	mov	rdi, rcx
	mov	eax, 0
	call	printf@PLT
	lea	rax, .LC4[rip]
	mov	rdi, rax
	mov	eax, 0
	call	printf@PLT
	lea	rax, -16[rbp]
	lea	rdx, .LC5[rip]
	mov	rsi, rax
	mov	rdi, rdx
	mov	eax, 0
	call	__isoc23_scanf@PLT
	mov	eax, DWORD PTR -16[rbp]
	mov	edi, eax
	call	cases
	mov	DWORD PTR -12[rbp], eax
	mov	eax, DWORD PTR -16[rbp]
	mov	edx, DWORD PTR -12[rbp]
	lea	rcx, .LC6[rip]
	mov	esi, eax
	mov	rdi, rcx
	mov	eax, 0
	call	printf@PLT
	mov	eax, 0
	mov	rdx, QWORD PTR -8[rbp]
	sub	rdx, QWORD PTR fs:40
	je	.L5
	call	__stack_chk_fail@PLT
.L5:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.section	.rodata
	.align 8
.LC0:
	.long	1462350465
	.long	-1076914312
	.align 8
.LC1:
	.long	0
	.long	1088653280
	.align 8
.LC2:
	.long	0
	.long	1072693248
	.align 8
.LC3:
	.long	0
	.long	1088653312
	.ident	"GCC: (GNU) 15.2.1 20250813"
	.section	.note.GNU-stack,"",@progbits
