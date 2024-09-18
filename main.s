	.file	"main.c"
 # GNU C17 (x86_64-posix-seh-rev0, Built by MinGW-W64 project) version 8.1.0 (x86_64-w64-mingw32)
 #	compiled by GNU C version 8.1.0, GMP version 6.1.2, MPFR version 4.0.1, MPC version 1.1.0, isl version isl-0.18-GMP

 # GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
 # options passed: 
 # -iprefix C:/Program Files/Mingw64/bin/../lib/gcc/x86_64-w64-mingw32/8.1.0/
 # -D_REENTRANT .\main.c -mtune=core2 -march=nocona -fverbose-asm
 # options enabled:  -faggressive-loop-optimizations
 # -fasynchronous-unwind-tables -fauto-inc-dec -fchkp-check-incomplete-type
 # -fchkp-check-read -fchkp-check-write -fchkp-instrument-calls
 # -fchkp-narrow-bounds -fchkp-optimize -fchkp-store-bounds
 # -fchkp-use-static-bounds -fchkp-use-static-const-bounds
 # -fchkp-use-wrappers -fcommon -fdelete-null-pointer-checks
 # -fdwarf2-cfi-asm -fearly-inlining -feliminate-unused-debug-types
 # -ffp-int-builtin-inexact -ffunction-cse -fgcse-lm -fgnu-runtime
 # -fgnu-unique -fident -finline-atomics -fira-hoist-pressure
 # -fira-share-save-slots -fira-share-spill-slots -fivopts
 # -fkeep-inline-dllexport -fkeep-static-consts -fleading-underscore
 # -flifetime-dse -flto-odr-type-merging -fmath-errno -fmerge-debug-strings
 # -fpeephole -fpic -fplt -fprefetch-loop-arrays -freg-struct-return
 # -fsched-critical-path-heuristic -fsched-dep-count-heuristic
 # -fsched-group-heuristic -fsched-interblock -fsched-last-insn-heuristic
 # -fsched-rank-heuristic -fsched-spec -fsched-spec-insn-heuristic
 # -fsched-stalled-insns-dep -fschedule-fusion -fsemantic-interposition
 # -fset-stack-executable -fshow-column -fshrink-wrap-separate
 # -fsigned-zeros -fsplit-ivs-in-unroller -fssa-backprop -fstdarg-opt
 # -fstrict-volatile-bitfields -fsync-libcalls -ftrapping-math
 # -ftree-cselim -ftree-forwprop -ftree-loop-if-convert -ftree-loop-im
 # -ftree-loop-ivcanon -ftree-loop-optimize -ftree-parallelize-loops=
 # -ftree-phiprop -ftree-reassoc -ftree-scev-cprop -funit-at-a-time
 # -funwind-tables -fverbose-asm -fzero-initialized-in-bss
 # -m128bit-long-double -m64 -m80387 -maccumulate-outgoing-args
 # -malign-double -malign-stringops -mcx16 -mfancy-math-387 -mfentry
 # -mfp-ret-in-387 -mfxsr -mieee-fp -mlong-double-80 -mmmx -mms-bitfields
 # -mno-sse4 -mpush-args -mred-zone -msse -msse2 -msse3 -mstack-arg-probe
 # -mstackrealign -mvzeroupper

	.text
	.globl	calc_average
	.def	calc_average;	.scl	2;	.type	32;	.endef
	.seh_proc	calc_average
calc_average:
	pushq	%rbp	 #
	.seh_pushreg	%rbp
	movq	%rsp, %rbp	 #,
	.seh_setframe	%rbp, 0
	subq	$16, %rsp	 #,
	.seh_stackalloc	16
	.seh_endprologue
	movq	%rcx, 16(%rbp)	 # student, student
	movl	%edx, 24(%rbp)	 # num_students, num_students
 # .\main.c:19:     for (i = 0; i < num_students; ++i)
	movl	$0, -4(%rbp)	 #, i
 # .\main.c:19:     for (i = 0; i < num_students; ++i)
	jmp	.L2	 #
.L3:
 # .\main.c:21:         student[i].average = (student[i].score[0] + student[i].score[1] + student[i].score[2]) / Num_Students;
	movl	-4(%rbp), %eax	 # i, tmp105
	movslq	%eax, %rdx	 # tmp105, _1
	movq	%rdx, %rax	 # _1, tmp106
	salq	$3, %rax	 #, tmp106
	addq	%rdx, %rax	 # _1, tmp106
	salq	$3, %rax	 #, tmp107
	movq	%rax, %rdx	 # tmp106, _2
	movq	16(%rbp), %rax	 # student, tmp108
	addq	%rdx, %rax	 # _2, _3
 # .\main.c:21:         student[i].average = (student[i].score[0] + student[i].score[1] + student[i].score[2]) / Num_Students;
	movss	56(%rax), %xmm1	 # _3->score, _4
 # .\main.c:21:         student[i].average = (student[i].score[0] + student[i].score[1] + student[i].score[2]) / Num_Students;
	movl	-4(%rbp), %eax	 # i, tmp109
	movslq	%eax, %rdx	 # tmp109, _5
	movq	%rdx, %rax	 # _5, tmp110
	salq	$3, %rax	 #, tmp110
	addq	%rdx, %rax	 # _5, tmp110
	salq	$3, %rax	 #, tmp111
	movq	%rax, %rdx	 # tmp110, _6
	movq	16(%rbp), %rax	 # student, tmp112
	addq	%rdx, %rax	 # _6, _7
 # .\main.c:21:         student[i].average = (student[i].score[0] + student[i].score[1] + student[i].score[2]) / Num_Students;
	movss	60(%rax), %xmm0	 # _7->score, _8
 # .\main.c:21:         student[i].average = (student[i].score[0] + student[i].score[1] + student[i].score[2]) / Num_Students;
	addss	%xmm0, %xmm1	 # _8, _9
 # .\main.c:21:         student[i].average = (student[i].score[0] + student[i].score[1] + student[i].score[2]) / Num_Students;
	movl	-4(%rbp), %eax	 # i, tmp113
	movslq	%eax, %rdx	 # tmp113, _10
	movq	%rdx, %rax	 # _10, tmp114
	salq	$3, %rax	 #, tmp114
	addq	%rdx, %rax	 # _10, tmp114
	salq	$3, %rax	 #, tmp115
	movq	%rax, %rdx	 # tmp114, _11
	movq	16(%rbp), %rax	 # student, tmp116
	addq	%rdx, %rax	 # _11, _12
 # .\main.c:21:         student[i].average = (student[i].score[0] + student[i].score[1] + student[i].score[2]) / Num_Students;
	movss	64(%rax), %xmm0	 # _12->score, _13
 # .\main.c:21:         student[i].average = (student[i].score[0] + student[i].score[1] + student[i].score[2]) / Num_Students;
	addss	%xmm1, %xmm0	 # _9, _14
 # .\main.c:21:         student[i].average = (student[i].score[0] + student[i].score[1] + student[i].score[2]) / Num_Students;
	movl	-4(%rbp), %eax	 # i, tmp117
	movslq	%eax, %rdx	 # tmp117, _15
	movq	%rdx, %rax	 # _15, tmp118
	salq	$3, %rax	 #, tmp118
	addq	%rdx, %rax	 # _15, tmp118
	salq	$3, %rax	 #, tmp119
	movq	%rax, %rdx	 # tmp118, _16
	movq	16(%rbp), %rax	 # student, tmp120
	addq	%rdx, %rax	 # _16, _17
 # .\main.c:21:         student[i].average = (student[i].score[0] + student[i].score[1] + student[i].score[2]) / Num_Students;
	movss	.LC0(%rip), %xmm1	 #, tmp121
	divss	%xmm1, %xmm0	 # tmp121, _18
 # .\main.c:21:         student[i].average = (student[i].score[0] + student[i].score[1] + student[i].score[2]) / Num_Students;
	movss	%xmm0, 68(%rax)	 # _18, _17->average
 # .\main.c:19:     for (i = 0; i < num_students; ++i)
	addl	$1, -4(%rbp)	 #, i
.L2:
 # .\main.c:19:     for (i = 0; i < num_students; ++i)
	movl	-4(%rbp), %eax	 # i, tmp122
	cmpl	24(%rbp), %eax	 # num_students, tmp122
	jl	.L3	 #,
 # .\main.c:23: }
	nop	
	addq	$16, %rsp	 #,
	popq	%rbp	 #
	ret	
	.seh_endproc
	.section .rdata,"dr"
.LC2:
	.ascii "Top Student\0"
.LC3:
	.ascii "Name: %s\12\0"
.LC4:
	.ascii "Average score: %.2f\12\0"
	.text
	.globl	find_highest_score
	.def	find_highest_score;	.scl	2;	.type	32;	.endef
	.seh_proc	find_highest_score
find_highest_score:
	pushq	%rbp	 #
	.seh_pushreg	%rbp
	movq	%rsp, %rbp	 #,
	.seh_setframe	%rbp, 0
	subq	$112, %rsp	 #,
	.seh_stackalloc	112
	.seh_endprologue
	movq	%rcx, 16(%rbp)	 # student, student
	movl	%edx, 24(%rbp)	 # num_students, num_students
 # .\main.c:28:     float highest_score = -1;
	movss	.LC1(%rip), %xmm0	 #, tmp99
	movss	%xmm0, -8(%rbp)	 # tmp99, highest_score
 # .\main.c:30:     for (i = 0; i < num_students; ++i)
	movl	$0, -4(%rbp)	 #, i
 # .\main.c:30:     for (i = 0; i < num_students; ++i)
	jmp	.L5	 #
.L8:
 # .\main.c:32:         if (student[i].average > highest_score)
	movl	-4(%rbp), %eax	 # i, tmp100
	movslq	%eax, %rdx	 # tmp100, _1
	movq	%rdx, %rax	 # _1, tmp101
	salq	$3, %rax	 #, tmp101
	addq	%rdx, %rax	 # _1, tmp101
	salq	$3, %rax	 #, tmp102
	movq	%rax, %rdx	 # tmp101, _2
	movq	16(%rbp), %rax	 # student, tmp103
	addq	%rdx, %rax	 # _2, _3
 # .\main.c:32:         if (student[i].average > highest_score)
	movss	68(%rax), %xmm0	 # _3->average, _4
 # .\main.c:32:         if (student[i].average > highest_score)
	comiss	-8(%rbp), %xmm0	 # highest_score, _4
	jbe	.L6	 #,
 # .\main.c:34:             highest_score = student[i].average;
	movl	-4(%rbp), %eax	 # i, tmp104
	movslq	%eax, %rdx	 # tmp104, _5
	movq	%rdx, %rax	 # _5, tmp105
	salq	$3, %rax	 #, tmp105
	addq	%rdx, %rax	 # _5, tmp105
	salq	$3, %rax	 #, tmp106
	movq	%rax, %rdx	 # tmp105, _6
	movq	16(%rbp), %rax	 # student, tmp107
	addq	%rdx, %rax	 # _6, _7
 # .\main.c:34:             highest_score = student[i].average;
	movss	68(%rax), %xmm0	 # _7->average, tmp108
	movss	%xmm0, -8(%rbp)	 # tmp108, highest_score
 # .\main.c:35:             top_student = student[i];
	movl	-4(%rbp), %eax	 # i, tmp109
	movslq	%eax, %rdx	 # tmp109, _8
	movq	%rdx, %rax	 # _8, tmp110
	salq	$3, %rax	 #, tmp110
	addq	%rdx, %rax	 # _8, tmp110
	salq	$3, %rax	 #, tmp111
	movq	%rax, %rdx	 # tmp110, _9
	movq	16(%rbp), %rax	 # student, tmp112
	addq	%rdx, %rax	 # _9, _10
 # .\main.c:35:             top_student = student[i];
	movq	(%rax), %rdx	 # *_10, tmp113
	movq	%rdx, -80(%rbp)	 # tmp113, top_student
	movq	8(%rax), %rdx	 # *_10, tmp114
	movq	%rdx, -72(%rbp)	 # tmp114, top_student
	movq	16(%rax), %rdx	 # *_10, tmp115
	movq	%rdx, -64(%rbp)	 # tmp115, top_student
	movq	24(%rax), %rdx	 # *_10, tmp116
	movq	%rdx, -56(%rbp)	 # tmp116, top_student
	movq	32(%rax), %rdx	 # *_10, tmp117
	movq	%rdx, -48(%rbp)	 # tmp117, top_student
	movq	40(%rax), %rdx	 # *_10, tmp118
	movq	%rdx, -40(%rbp)	 # tmp118, top_student
	movq	48(%rax), %rdx	 # *_10, tmp119
	movq	%rdx, -32(%rbp)	 # tmp119, top_student
	movq	56(%rax), %rdx	 # *_10, tmp120
	movq	%rdx, -24(%rbp)	 # tmp120, top_student
	movq	64(%rax), %rax	 # *_10, tmp121
	movq	%rax, -16(%rbp)	 # tmp121, top_student
.L6:
 # .\main.c:30:     for (i = 0; i < num_students; ++i)
	addl	$1, -4(%rbp)	 #, i
.L5:
 # .\main.c:30:     for (i = 0; i < num_students; ++i)
	movl	-4(%rbp), %eax	 # i, tmp122
	cmpl	24(%rbp), %eax	 # num_students, tmp122
	jl	.L8	 #,
 # .\main.c:38:     printf("Top Student\n");
	leaq	.LC2(%rip), %rcx	 #,
	call	puts	 #
 # .\main.c:39:     printf("Name: %s\n", top_student.name);
	leaq	-80(%rbp), %rax	 #, tmp123
	addq	$4, %rax	 #, tmp124
	movq	%rax, %rdx	 # tmp124,
	leaq	.LC3(%rip), %rcx	 #,
	call	printf	 #
 # .\main.c:40:     printf("Average score: %.2f\n", top_student.average);
	movss	-12(%rbp), %xmm0	 # top_student.average, _11
 # .\main.c:40:     printf("Average score: %.2f\n", top_student.average);
	cvtss2sd	%xmm0, %xmm0	 # _11, _12
	movq	%xmm0, %rax	 # _12, tmp125
	movq	%rax, %rdx	 # tmp125, tmp126
	movq	%rdx, %xmm1	 # tmp128,
	movq	%rax, %rdx	 # tmp129,
	leaq	.LC4(%rip), %rcx	 #,
	call	printf	 #
 # .\main.c:41: }
	nop	
	addq	$112, %rsp	 #,
	popq	%rbp	 #
	ret	
	.seh_endproc
	.section .rdata,"dr"
.LC6:
	.ascii "Low Student\0"
	.text
	.globl	find_lowest_score
	.def	find_lowest_score;	.scl	2;	.type	32;	.endef
	.seh_proc	find_lowest_score
find_lowest_score:
	pushq	%rbp	 #
	.seh_pushreg	%rbp
	movq	%rsp, %rbp	 #,
	.seh_setframe	%rbp, 0
	subq	$112, %rsp	 #,
	.seh_stackalloc	112
	.seh_endprologue
	movq	%rcx, 16(%rbp)	 # student, student
	movl	%edx, 24(%rbp)	 # num_students, num_students
 # .\main.c:46:     float lowest_score = 1000;
	movss	.LC5(%rip), %xmm0	 #, tmp99
	movss	%xmm0, -8(%rbp)	 # tmp99, lowest_score
 # .\main.c:48:     for (i = 0; i < num_students; ++i)
	movl	$0, -4(%rbp)	 #, i
 # .\main.c:48:     for (i = 0; i < num_students; ++i)
	jmp	.L11	 #
.L14:
 # .\main.c:50:         if (student[i].average < lowest_score)
	movl	-4(%rbp), %eax	 # i, tmp100
	movslq	%eax, %rdx	 # tmp100, _1
	movq	%rdx, %rax	 # _1, tmp101
	salq	$3, %rax	 #, tmp101
	addq	%rdx, %rax	 # _1, tmp101
	salq	$3, %rax	 #, tmp102
	movq	%rax, %rdx	 # tmp101, _2
	movq	16(%rbp), %rax	 # student, tmp103
	addq	%rdx, %rax	 # _2, _3
 # .\main.c:50:         if (student[i].average < lowest_score)
	movss	68(%rax), %xmm1	 # _3->average, _4
 # .\main.c:50:         if (student[i].average < lowest_score)
	movss	-8(%rbp), %xmm0	 # lowest_score, tmp104
	comiss	%xmm1, %xmm0	 # _4, tmp104
	jbe	.L12	 #,
 # .\main.c:52:             lowest_score = student[i].average;
	movl	-4(%rbp), %eax	 # i, tmp105
	movslq	%eax, %rdx	 # tmp105, _5
	movq	%rdx, %rax	 # _5, tmp106
	salq	$3, %rax	 #, tmp106
	addq	%rdx, %rax	 # _5, tmp106
	salq	$3, %rax	 #, tmp107
	movq	%rax, %rdx	 # tmp106, _6
	movq	16(%rbp), %rax	 # student, tmp108
	addq	%rdx, %rax	 # _6, _7
 # .\main.c:52:             lowest_score = student[i].average;
	movss	68(%rax), %xmm0	 # _7->average, tmp109
	movss	%xmm0, -8(%rbp)	 # tmp109, lowest_score
 # .\main.c:53:             low_student = student[i];
	movl	-4(%rbp), %eax	 # i, tmp110
	movslq	%eax, %rdx	 # tmp110, _8
	movq	%rdx, %rax	 # _8, tmp111
	salq	$3, %rax	 #, tmp111
	addq	%rdx, %rax	 # _8, tmp111
	salq	$3, %rax	 #, tmp112
	movq	%rax, %rdx	 # tmp111, _9
	movq	16(%rbp), %rax	 # student, tmp113
	addq	%rdx, %rax	 # _9, _10
 # .\main.c:53:             low_student = student[i];
	movq	(%rax), %rdx	 # *_10, tmp114
	movq	%rdx, -80(%rbp)	 # tmp114, low_student
	movq	8(%rax), %rdx	 # *_10, tmp115
	movq	%rdx, -72(%rbp)	 # tmp115, low_student
	movq	16(%rax), %rdx	 # *_10, tmp116
	movq	%rdx, -64(%rbp)	 # tmp116, low_student
	movq	24(%rax), %rdx	 # *_10, tmp117
	movq	%rdx, -56(%rbp)	 # tmp117, low_student
	movq	32(%rax), %rdx	 # *_10, tmp118
	movq	%rdx, -48(%rbp)	 # tmp118, low_student
	movq	40(%rax), %rdx	 # *_10, tmp119
	movq	%rdx, -40(%rbp)	 # tmp119, low_student
	movq	48(%rax), %rdx	 # *_10, tmp120
	movq	%rdx, -32(%rbp)	 # tmp120, low_student
	movq	56(%rax), %rdx	 # *_10, tmp121
	movq	%rdx, -24(%rbp)	 # tmp121, low_student
	movq	64(%rax), %rax	 # *_10, tmp122
	movq	%rax, -16(%rbp)	 # tmp122, low_student
.L12:
 # .\main.c:48:     for (i = 0; i < num_students; ++i)
	addl	$1, -4(%rbp)	 #, i
.L11:
 # .\main.c:48:     for (i = 0; i < num_students; ++i)
	movl	-4(%rbp), %eax	 # i, tmp123
	cmpl	24(%rbp), %eax	 # num_students, tmp123
	jl	.L14	 #,
 # .\main.c:56:     printf("Low Student\n");
	leaq	.LC6(%rip), %rcx	 #,
	call	puts	 #
 # .\main.c:57:     printf("Name: %s\n", low_student.name);
	leaq	-80(%rbp), %rax	 #, tmp124
	addq	$4, %rax	 #, tmp125
	movq	%rax, %rdx	 # tmp125,
	leaq	.LC3(%rip), %rcx	 #,
	call	printf	 #
 # .\main.c:58:     printf("Average score: %.2f\n", low_student.average);
	movss	-12(%rbp), %xmm0	 # low_student.average, _11
 # .\main.c:58:     printf("Average score: %.2f\n", low_student.average);
	cvtss2sd	%xmm0, %xmm0	 # _11, _12
	movq	%xmm0, %rax	 # _12, tmp126
	movq	%rax, %rdx	 # tmp126, tmp127
	movq	%rdx, %xmm1	 # tmp129,
	movq	%rax, %rdx	 # tmp130,
	leaq	.LC4(%rip), %rcx	 #,
	call	printf	 #
 # .\main.c:59: }
	nop	
	addq	$112, %rsp	 #,
	popq	%rbp	 #
	ret	
	.seh_endproc
	.section .rdata,"dr"
.LC8:
	.ascii "total Average Score\0"
.LC9:
	.ascii "Average: %.2f\12\0"
	.text
	.globl	calc_total_average_score
	.def	calc_total_average_score;	.scl	2;	.type	32;	.endef
	.seh_proc	calc_total_average_score
calc_total_average_score:
	pushq	%rbp	 #
	.seh_pushreg	%rbp
	movq	%rsp, %rbp	 #,
	.seh_setframe	%rbp, 0
	subq	$48, %rsp	 #,
	.seh_stackalloc	48
	.seh_endprologue
	movq	%rcx, 16(%rbp)	 # student, student
	movl	%edx, 24(%rbp)	 # num_students, num_students
 # .\main.c:63:     float total_average = 0;
	pxor	%xmm0, %xmm0	 # tmp92
	movss	%xmm0, -8(%rbp)	 # tmp92, total_average
 # .\main.c:64:     for (i = 0; i < num_students; ++i)
	movl	$0, -4(%rbp)	 #, i
 # .\main.c:64:     for (i = 0; i < num_students; ++i)
	jmp	.L17	 #
.L18:
 # .\main.c:66:         total_average = total_average + student[i].average;
	movl	-4(%rbp), %eax	 # i, tmp93
	movslq	%eax, %rdx	 # tmp93, _1
	movq	%rdx, %rax	 # _1, tmp94
	salq	$3, %rax	 #, tmp94
	addq	%rdx, %rax	 # _1, tmp94
	salq	$3, %rax	 #, tmp95
	movq	%rax, %rdx	 # tmp94, _2
	movq	16(%rbp), %rax	 # student, tmp96
	addq	%rdx, %rax	 # _2, _3
 # .\main.c:66:         total_average = total_average + student[i].average;
	movss	68(%rax), %xmm0	 # _3->average, _4
 # .\main.c:66:         total_average = total_average + student[i].average;
	movss	-8(%rbp), %xmm1	 # total_average, tmp98
	addss	%xmm1, %xmm0	 # tmp98, tmp97
	movss	%xmm0, -8(%rbp)	 # tmp97, total_average
 # .\main.c:64:     for (i = 0; i < num_students; ++i)
	addl	$1, -4(%rbp)	 #, i
.L17:
 # .\main.c:64:     for (i = 0; i < num_students; ++i)
	movl	-4(%rbp), %eax	 # i, tmp99
	cmpl	24(%rbp), %eax	 # num_students, tmp99
	jl	.L18	 #,
 # .\main.c:68:     total_average = total_average / Num_Students;
	movss	-8(%rbp), %xmm0	 # total_average, tmp101
	movss	.LC0(%rip), %xmm1	 #, tmp102
	divss	%xmm1, %xmm0	 # tmp102, tmp100
	movss	%xmm0, -8(%rbp)	 # tmp100, total_average
 # .\main.c:69:     printf("total Average Score\n");
	leaq	.LC8(%rip), %rcx	 #,
	call	puts	 #
 # .\main.c:70:     printf("Average: %.2f\n", total_average);
	cvtss2sd	-8(%rbp), %xmm0	 # total_average, _5
	movq	%xmm0, %rax	 # _5, tmp103
	movq	%rax, %rdx	 # tmp103, tmp104
	movq	%rdx, %xmm1	 # tmp106,
	movq	%rax, %rdx	 # tmp107,
	leaq	.LC9(%rip), %rcx	 #,
	call	printf	 #
 # .\main.c:71: }
	nop	
	addq	$48, %rsp	 #,
	popq	%rbp	 #
	ret	
	.seh_endproc
	.globl	beauty_print
	.def	beauty_print;	.scl	2;	.type	32;	.endef
	.seh_proc	beauty_print
beauty_print:
	pushq	%rbp	 #
	.seh_pushreg	%rbp
	pushq	%rdi	 #
	.seh_pushreg	%rdi
	subq	$136, %rsp	 #,
	.seh_stackalloc	136
	leaq	128(%rsp), %rbp	 #,
	.seh_setframe	%rbp, 128
	.seh_endprologue
 # .\main.c:74:     char line[81] = "";
	movq	$0, -96(%rbp)	 #, line
	leaq	-88(%rbp), %rdx	 #, tmp87
	movl	$0, %eax	 #, tmp88
	movl	$9, %ecx	 #, tmp89
	movq	%rdx, %rdi	 # tmp87, tmp87
	rep stosq
	movq	%rdi, %rdx	 # tmp87, tmp87
	movb	%al, (%rdx)	 # tmp88, line
	addq	$1, %rdx	 #, tmp87
 # .\main.c:75:     for(int i = 0; i < 80; i++)
	movl	$0, -4(%rbp)	 #, i
 # .\main.c:75:     for(int i = 0; i < 80; i++)
	jmp	.L20	 #
.L21:
 # .\main.c:77:         line[i] = '*';
	movl	-4(%rbp), %eax	 # i, tmp91
	cltq
	movb	$42, -96(%rbp,%rax)	 #, line
 # .\main.c:75:     for(int i = 0; i < 80; i++)
	addl	$1, -4(%rbp)	 #, i
.L20:
 # .\main.c:75:     for(int i = 0; i < 80; i++)
	cmpl	$79, -4(%rbp)	 #, i
	jle	.L21	 #,
 # .\main.c:79:     printf("%s\n", line);
	leaq	-96(%rbp), %rax	 #, tmp92
	movq	%rax, %rcx	 # tmp92,
	call	puts	 #
 # .\main.c:80: }
	nop	
	addq	$136, %rsp	 #,
	popq	%rdi	 #
	popq	%rbp	 #
	ret	
	.seh_endproc
	.section .rdata,"dr"
.LC10:
	.ascii "student  %d\12\0"
.LC11:
	.ascii "Score 1: %.2f\12\0"
.LC12:
	.ascii "Score 2: %.2f\12\0"
.LC13:
	.ascii "Score 3: %.2f\12\0"
	.text
	.globl	print_student
	.def	print_student;	.scl	2;	.type	32;	.endef
	.seh_proc	print_student
print_student:
	pushq	%rbp	 #
	.seh_pushreg	%rbp
	movq	%rsp, %rbp	 #,
	.seh_setframe	%rbp, 0
	subq	$48, %rsp	 #,
	.seh_stackalloc	48
	.seh_endprologue
	movq	%rcx, 16(%rbp)	 # student, student
	movl	%edx, 24(%rbp)	 # num_students, num_students
 # .\main.c:85:     for (i = 0; i < num_students; ++i)
	movl	$0, -4(%rbp)	 #, i
 # .\main.c:85:     for (i = 0; i < num_students; ++i)
	jmp	.L23	 #
.L24:
 # .\main.c:87:         beauty_print();
	call	beauty_print	 #
 # .\main.c:88:         printf("student  %d\n", student[i].id);
	movl	-4(%rbp), %eax	 # i, tmp115
	movslq	%eax, %rdx	 # tmp115, _1
	movq	%rdx, %rax	 # _1, tmp116
	salq	$3, %rax	 #, tmp116
	addq	%rdx, %rax	 # _1, tmp116
	salq	$3, %rax	 #, tmp117
	movq	%rax, %rdx	 # tmp116, _2
	movq	16(%rbp), %rax	 # student, tmp118
	addq	%rdx, %rax	 # _2, _3
 # .\main.c:88:         printf("student  %d\n", student[i].id);
	movl	(%rax), %eax	 # _3->id, _4
	movl	%eax, %edx	 # _4,
	leaq	.LC10(%rip), %rcx	 #,
	call	printf	 #
 # .\main.c:89:         printf("Name: %s\n", student[i].name);
	movl	-4(%rbp), %eax	 # i, tmp119
	movslq	%eax, %rdx	 # tmp119, _5
	movq	%rdx, %rax	 # _5, tmp120
	salq	$3, %rax	 #, tmp120
	addq	%rdx, %rax	 # _5, tmp120
	salq	$3, %rax	 #, tmp121
	movq	%rax, %rdx	 # tmp120, _6
	movq	16(%rbp), %rax	 # student, tmp122
	addq	%rdx, %rax	 # _6, _7
 # .\main.c:89:         printf("Name: %s\n", student[i].name);
	addq	$4, %rax	 #, _8
 # .\main.c:89:         printf("Name: %s\n", student[i].name);
	movq	%rax, %rdx	 # _8,
	leaq	.LC3(%rip), %rcx	 #,
	call	printf	 #
 # .\main.c:90:         printf("Score 1: %.2f\n", student[i].score[0]);
	movl	-4(%rbp), %eax	 # i, tmp123
	movslq	%eax, %rdx	 # tmp123, _9
	movq	%rdx, %rax	 # _9, tmp124
	salq	$3, %rax	 #, tmp124
	addq	%rdx, %rax	 # _9, tmp124
	salq	$3, %rax	 #, tmp125
	movq	%rax, %rdx	 # tmp124, _10
	movq	16(%rbp), %rax	 # student, tmp126
	addq	%rdx, %rax	 # _10, _11
 # .\main.c:90:         printf("Score 1: %.2f\n", student[i].score[0]);
	movss	56(%rax), %xmm0	 # _11->score, _12
 # .\main.c:90:         printf("Score 1: %.2f\n", student[i].score[0]);
	cvtss2sd	%xmm0, %xmm0	 # _12, _13
	movq	%xmm0, %rax	 # _13, tmp127
	movq	%rax, %rdx	 # tmp127, tmp128
	movq	%rdx, %xmm1	 # tmp130,
	movq	%rax, %rdx	 # tmp131,
	leaq	.LC11(%rip), %rcx	 #,
	call	printf	 #
 # .\main.c:91:         printf("Score 2: %.2f\n", student[i].score[1]);
	movl	-4(%rbp), %eax	 # i, tmp132
	movslq	%eax, %rdx	 # tmp132, _14
	movq	%rdx, %rax	 # _14, tmp133
	salq	$3, %rax	 #, tmp133
	addq	%rdx, %rax	 # _14, tmp133
	salq	$3, %rax	 #, tmp134
	movq	%rax, %rdx	 # tmp133, _15
	movq	16(%rbp), %rax	 # student, tmp135
	addq	%rdx, %rax	 # _15, _16
 # .\main.c:91:         printf("Score 2: %.2f\n", student[i].score[1]);
	movss	60(%rax), %xmm0	 # _16->score, _17
 # .\main.c:91:         printf("Score 2: %.2f\n", student[i].score[1]);
	cvtss2sd	%xmm0, %xmm0	 # _17, _18
	movq	%xmm0, %rax	 # _18, tmp136
	movq	%rax, %rdx	 # tmp136, tmp137
	movq	%rdx, %xmm1	 # tmp139,
	movq	%rax, %rdx	 # tmp140,
	leaq	.LC12(%rip), %rcx	 #,
	call	printf	 #
 # .\main.c:92:         printf("Score 3: %.2f\n", student[i].score[2]);
	movl	-4(%rbp), %eax	 # i, tmp141
	movslq	%eax, %rdx	 # tmp141, _19
	movq	%rdx, %rax	 # _19, tmp142
	salq	$3, %rax	 #, tmp142
	addq	%rdx, %rax	 # _19, tmp142
	salq	$3, %rax	 #, tmp143
	movq	%rax, %rdx	 # tmp142, _20
	movq	16(%rbp), %rax	 # student, tmp144
	addq	%rdx, %rax	 # _20, _21
 # .\main.c:92:         printf("Score 3: %.2f\n", student[i].score[2]);
	movss	64(%rax), %xmm0	 # _21->score, _22
 # .\main.c:92:         printf("Score 3: %.2f\n", student[i].score[2]);
	cvtss2sd	%xmm0, %xmm0	 # _22, _23
	movq	%xmm0, %rax	 # _23, tmp145
	movq	%rax, %rdx	 # tmp145, tmp146
	movq	%rdx, %xmm1	 # tmp148,
	movq	%rax, %rdx	 # tmp149,
	leaq	.LC13(%rip), %rcx	 #,
	call	printf	 #
 # .\main.c:93:         printf("Average: %.2f\n", student[i].average);
	movl	-4(%rbp), %eax	 # i, tmp150
	movslq	%eax, %rdx	 # tmp150, _24
	movq	%rdx, %rax	 # _24, tmp151
	salq	$3, %rax	 #, tmp151
	addq	%rdx, %rax	 # _24, tmp151
	salq	$3, %rax	 #, tmp152
	movq	%rax, %rdx	 # tmp151, _25
	movq	16(%rbp), %rax	 # student, tmp153
	addq	%rdx, %rax	 # _25, _26
 # .\main.c:93:         printf("Average: %.2f\n", student[i].average);
	movss	68(%rax), %xmm0	 # _26->average, _27
 # .\main.c:93:         printf("Average: %.2f\n", student[i].average);
	cvtss2sd	%xmm0, %xmm0	 # _27, _28
	movq	%xmm0, %rax	 # _28, tmp154
	movq	%rax, %rdx	 # tmp154, tmp155
	movq	%rdx, %xmm1	 # tmp157,
	movq	%rax, %rdx	 # tmp158,
	leaq	.LC9(%rip), %rcx	 #,
	call	printf	 #
 # .\main.c:94:         beauty_print();
	call	beauty_print	 #
 # .\main.c:85:     for (i = 0; i < num_students; ++i)
	addl	$1, -4(%rbp)	 #, i
.L23:
 # .\main.c:85:     for (i = 0; i < num_students; ++i)
	movl	-4(%rbp), %eax	 # i, tmp159
	cmpl	24(%rbp), %eax	 # num_students, tmp159
	jl	.L24	 #,
 # .\main.c:96: }
	nop	
	addq	$48, %rsp	 #,
	popq	%rbp	 #
	ret	
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC14:
	.ascii "\344\270\255\346\226\207\0"
.LC15:
	.ascii "Enter student %d id: \0"
.LC16:
	.ascii "%d\0"
.LC17:
	.ascii "Invalid input Student_id \0"
.LC18:
	.ascii "Enter student %d name: \0"
.LC19:
	.ascii "%s\0"
.LC20:
	.ascii " \0"
.LC21:
	.ascii "Invalid input Student_name \0"
.LC22:
	.ascii "Enter student %d score 1: \0"
.LC23:
	.ascii "%f\0"
.LC25:
	.ascii "Invalid input Student_score \0"
.LC26:
	.ascii "Enter student %d score 2: \0"
.LC27:
	.ascii "Enter student %d score 3: \0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rbp	 #
	.seh_pushreg	%rbp
	subq	$256, %rsp	 #,
	.seh_stackalloc	256
	leaq	128(%rsp), %rbp	 #,
	.seh_setframe	%rbp, 128
	.seh_endprologue
 # .\main.c:99: {
	call	__main	 #
 # .\main.c:100:     SetConsoleOutputCP(CP_UTF8);
	movl	$65001, %ecx	 #,
	movq	__imp_SetConsoleOutputCP(%rip), %rax	 #, tmp105
	call	*%rax	 # tmp105
 # .\main.c:101:     printf("中文\n");
	leaq	.LC14(%rip), %rcx	 #,
	call	puts	 #
 # .\main.c:104:     for (i = 0; i < Num_Students; ++i)
	movl	$0, 124(%rbp)	 #, i
 # .\main.c:104:     for (i = 0; i < Num_Students; ++i)
	jmp	.L26	 #
.L34:
 # .\main.c:107:         printf("Enter student %d id: ", i + 1);
	movl	124(%rbp), %eax	 # i, tmp106
	addl	$1, %eax	 #, _1
	movl	%eax, %edx	 # _1,
	leaq	.LC15(%rip), %rcx	 #,
	call	printf	 #
 # .\main.c:108:         scanf("%d", &student[i].id);
	leaq	-96(%rbp), %rcx	 #, tmp107
	movl	124(%rbp), %eax	 # i, tmp109
	movslq	%eax, %rdx	 # tmp109, tmp108
	movq	%rdx, %rax	 # tmp108, tmp110
	salq	$3, %rax	 #, tmp110
	addq	%rdx, %rax	 # tmp108, tmp110
	salq	$3, %rax	 #, tmp111
	addq	%rcx, %rax	 # tmp107, _2
	movq	%rax, %rdx	 # _2,
	leaq	.LC16(%rip), %rcx	 #,
	call	scanf	 #
 # .\main.c:109:         if (student[i].id < 0 || student[i].id > Num_Students)
	movl	124(%rbp), %eax	 # i, tmp113
	movslq	%eax, %rdx	 # tmp113, tmp112
	movq	%rdx, %rax	 # tmp112, tmp114
	salq	$3, %rax	 #, tmp114
	addq	%rdx, %rax	 # tmp112, tmp114
	salq	$3, %rax	 #, tmp115
	leaq	128(%rbp), %rcx	 #, tmp182
	addq	%rcx, %rax	 # tmp182, tmp116
	subq	$224, %rax	 #, tmp117
	movl	(%rax), %eax	 # student[i_17].id, _3
 # .\main.c:109:         if (student[i].id < 0 || student[i].id > Num_Students)
	testl	%eax, %eax	 # _3
	js	.L27	 #,
 # .\main.c:109:         if (student[i].id < 0 || student[i].id > Num_Students)
	movl	124(%rbp), %eax	 # i, tmp119
	movslq	%eax, %rdx	 # tmp119, tmp118
	movq	%rdx, %rax	 # tmp118, tmp120
	salq	$3, %rax	 #, tmp120
	addq	%rdx, %rax	 # tmp118, tmp120
	salq	$3, %rax	 #, tmp121
	leaq	128(%rbp), %rcx	 #, tmp183
	addq	%rcx, %rax	 # tmp183, tmp122
	subq	$224, %rax	 #, tmp123
	movl	(%rax), %eax	 # student[i_17].id, _4
 # .\main.c:109:         if (student[i].id < 0 || student[i].id > Num_Students)
	cmpl	$3, %eax	 #, _4
	jle	.L28	 #,
.L27:
 # .\main.c:111:             printf("Invalid input Student_id \n");
	leaq	.LC17(%rip), %rcx	 #,
	call	puts	 #
 # .\main.c:112:             exit(1);
	movl	$1, %ecx	 #,
	call	exit	 #
.L28:
 # .\main.c:114:         printf("Enter student %d name: ", i + 1);
	movl	124(%rbp), %eax	 # i, tmp124
	addl	$1, %eax	 #, _5
	movl	%eax, %edx	 # _5,
	leaq	.LC18(%rip), %rcx	 #,
	call	printf	 #
 # .\main.c:115:         scanf("%s", student[i].name);
	leaq	-96(%rbp), %rcx	 #, tmp125
	movl	124(%rbp), %eax	 # i, tmp127
	movslq	%eax, %rdx	 # tmp127, tmp126
	movq	%rdx, %rax	 # tmp126, tmp128
	salq	$3, %rax	 #, tmp128
	addq	%rdx, %rax	 # tmp126, tmp128
	salq	$3, %rax	 #, tmp129
	addq	%rcx, %rax	 # tmp125, tmp130
	addq	$4, %rax	 #, _6
 # .\main.c:115:         scanf("%s", student[i].name);
	movq	%rax, %rdx	 # _6,
	leaq	.LC19(%rip), %rcx	 #,
	call	scanf	 #
 # .\main.c:116:         if (strlen(student[i].name) == 0 || strcmp(student[i].name, " ") == 0)
	leaq	-96(%rbp), %rcx	 #, tmp131
	movl	124(%rbp), %eax	 # i, tmp133
	movslq	%eax, %rdx	 # tmp133, tmp132
	movq	%rdx, %rax	 # tmp132, tmp134
	salq	$3, %rax	 #, tmp134
	addq	%rdx, %rax	 # tmp132, tmp134
	salq	$3, %rax	 #, tmp135
	addq	%rcx, %rax	 # tmp131, tmp136
	addq	$4, %rax	 #, _7
 # .\main.c:116:         if (strlen(student[i].name) == 0 || strcmp(student[i].name, " ") == 0)
	movzbl	(%rax), %eax	 # MEM[(const char *)_7], _8
 # .\main.c:116:         if (strlen(student[i].name) == 0 || strcmp(student[i].name, " ") == 0)
	testb	%al, %al	 # _8
	je	.L29	 #,
 # .\main.c:116:         if (strlen(student[i].name) == 0 || strcmp(student[i].name, " ") == 0)
	leaq	-96(%rbp), %rcx	 #, tmp137
	movl	124(%rbp), %eax	 # i, tmp139
	movslq	%eax, %rdx	 # tmp139, tmp138
	movq	%rdx, %rax	 # tmp138, tmp140
	salq	$3, %rax	 #, tmp140
	addq	%rdx, %rax	 # tmp138, tmp140
	salq	$3, %rax	 #, tmp141
	addq	%rcx, %rax	 # tmp137, tmp142
	addq	$4, %rax	 #, _9
 # .\main.c:116:         if (strlen(student[i].name) == 0 || strcmp(student[i].name, " ") == 0)
	leaq	.LC20(%rip), %rdx	 #,
	movq	%rax, %rcx	 # _9,
	call	strcmp	 #
 # .\main.c:116:         if (strlen(student[i].name) == 0 || strcmp(student[i].name, " ") == 0)
	testl	%eax, %eax	 # _10
	jne	.L30	 #,
.L29:
 # .\main.c:118:             printf("Invalid input Student_name \n");
	leaq	.LC21(%rip), %rcx	 #,
	call	puts	 #
 # .\main.c:119:             exit(1);
	movl	$1, %ecx	 #,
	call	exit	 #
.L30:
 # .\main.c:121:         printf("Enter student %d score 1: ", i + 1);
	movl	124(%rbp), %eax	 # i, tmp143
	addl	$1, %eax	 #, _11
	movl	%eax, %edx	 # _11,
	leaq	.LC22(%rip), %rcx	 #,
	call	printf	 #
 # .\main.c:122:         scanf("%f", &student[i].score[0]);
	leaq	-96(%rbp), %rcx	 #, tmp144
	movl	124(%rbp), %eax	 # i, tmp146
	movslq	%eax, %rdx	 # tmp146, tmp145
	movq	%rdx, %rax	 # tmp145, tmp147
	salq	$3, %rax	 #, tmp147
	addq	%rdx, %rax	 # tmp145, tmp147
	salq	$3, %rax	 #, tmp148
	addq	$48, %rax	 #, tmp149
	addq	%rcx, %rax	 # tmp144, tmp150
	addq	$8, %rax	 #, _12
	movq	%rax, %rdx	 # _12,
	leaq	.LC23(%rip), %rcx	 #,
	call	scanf	 #
 # .\main.c:123:         float x = student[i].score[0];
	movl	124(%rbp), %eax	 # i, tmp152
	movslq	%eax, %rdx	 # tmp152, tmp151
	movq	%rdx, %rax	 # tmp151, tmp153
	salq	$3, %rax	 #, tmp153
	addq	%rdx, %rax	 # tmp151, tmp153
	salq	$3, %rax	 #, tmp154
	leaq	128(%rbp), %rcx	 #, tmp184
	addq	%rcx, %rax	 # tmp184, tmp155
	subq	$168, %rax	 #, tmp156
	movss	(%rax), %xmm0	 # student[i_17].score, tmp157
	movss	%xmm0, 120(%rbp)	 # tmp157, x
 # .\main.c:124:         if (x < 0 || x > 200)
	pxor	%xmm0, %xmm0	 # tmp158
	comiss	120(%rbp), %xmm0	 # x, tmp158
	ja	.L31	 #,
 # .\main.c:124:         if (x < 0 || x > 200)
	movss	120(%rbp), %xmm0	 # x, tmp159
	comiss	.LC24(%rip), %xmm0	 #, tmp159
	jbe	.L36	 #,
.L31:
 # .\main.c:126:             printf("Invalid input Student_score \n");
	leaq	.LC25(%rip), %rcx	 #,
	call	puts	 #
 # .\main.c:127:             exit(1);
	movl	$1, %ecx	 #,
	call	exit	 #
.L36:
 # .\main.c:130:         printf("Enter student %d score 2: ", i + 1);
	movl	124(%rbp), %eax	 # i, tmp160
	addl	$1, %eax	 #, _13
	movl	%eax, %edx	 # _13,
	leaq	.LC26(%rip), %rcx	 #,
	call	printf	 #
 # .\main.c:131:         scanf("%f", &student[i].score[1]);
	leaq	-96(%rbp), %rcx	 #, tmp161
	movl	124(%rbp), %eax	 # i, tmp163
	movslq	%eax, %rdx	 # tmp163, tmp162
	movq	%rdx, %rax	 # tmp162, tmp164
	salq	$3, %rax	 #, tmp164
	addq	%rdx, %rax	 # tmp162, tmp164
	salq	$3, %rax	 #, tmp165
	addq	$52, %rax	 #, tmp166
	addq	%rcx, %rax	 # tmp161, tmp167
	addq	$8, %rax	 #, _14
	movq	%rax, %rdx	 # _14,
	leaq	.LC23(%rip), %rcx	 #,
	call	scanf	 #
 # .\main.c:132:         printf("Enter student %d score 3: ", i + 1);
	movl	124(%rbp), %eax	 # i, tmp168
	addl	$1, %eax	 #, _15
	movl	%eax, %edx	 # _15,
	leaq	.LC27(%rip), %rcx	 #,
	call	printf	 #
 # .\main.c:133:         scanf("%f", &student[i].score[2]);
	leaq	-96(%rbp), %rcx	 #, tmp169
	movl	124(%rbp), %eax	 # i, tmp171
	movslq	%eax, %rdx	 # tmp171, tmp170
	movq	%rdx, %rax	 # tmp170, tmp172
	salq	$3, %rax	 #, tmp172
	addq	%rdx, %rax	 # tmp170, tmp172
	salq	$3, %rax	 #, tmp173
	addq	$56, %rax	 #, tmp174
	addq	%rcx, %rax	 # tmp169, tmp175
	addq	$8, %rax	 #, _16
	movq	%rax, %rdx	 # _16,
	leaq	.LC23(%rip), %rcx	 #,
	call	scanf	 #
 # .\main.c:104:     for (i = 0; i < Num_Students; ++i)
	addl	$1, 124(%rbp)	 #, i
.L26:
 # .\main.c:104:     for (i = 0; i < Num_Students; ++i)
	cmpl	$2, 124(%rbp)	 #, i
	jle	.L34	 #,
 # .\main.c:135:     beauty_print();
	call	beauty_print	 #
 # .\main.c:136:     calc_average(student, Num_Students);
	leaq	-96(%rbp), %rax	 #, tmp176
	movl	$3, %edx	 #,
	movq	%rax, %rcx	 # tmp176,
	call	calc_average	 #
 # .\main.c:137:     print_student(student, Num_Students);
	leaq	-96(%rbp), %rax	 #, tmp177
	movl	$3, %edx	 #,
	movq	%rax, %rcx	 # tmp177,
	call	print_student	 #
 # .\main.c:139:     beauty_print();
	call	beauty_print	 #
 # .\main.c:140:     find_highest_score(student, Num_Students);
	leaq	-96(%rbp), %rax	 #, tmp178
	movl	$3, %edx	 #,
	movq	%rax, %rcx	 # tmp178,
	call	find_highest_score	 #
 # .\main.c:141:     beauty_print();
	call	beauty_print	 #
 # .\main.c:142:     find_lowest_score(student, Num_Students);
	leaq	-96(%rbp), %rax	 #, tmp179
	movl	$3, %edx	 #,
	movq	%rax, %rcx	 # tmp179,
	call	find_lowest_score	 #
 # .\main.c:143:     beauty_print();
	call	beauty_print	 #
 # .\main.c:144:     calc_total_average_score(student, Num_Students);
	leaq	-96(%rbp), %rax	 #, tmp180
	movl	$3, %edx	 #,
	movq	%rax, %rcx	 # tmp180,
	call	calc_total_average_score	 #
	movl	$0, %eax	 #, _51
 # .\main.c:146: }
	addq	$256, %rsp	 #,
	popq	%rbp	 #
	ret	
	.seh_endproc
	.section .rdata,"dr"
	.align 4
.LC0:
	.long	1077936128
	.align 4
.LC1:
	.long	-1082130432
	.align 4
.LC5:
	.long	1148846080
	.align 4
.LC24:
	.long	1128792064
	.ident	"GCC: (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 8.1.0"
	.def	puts;	.scl	2;	.type	32;	.endef
	.def	printf;	.scl	2;	.type	32;	.endef
	.def	scanf;	.scl	2;	.type	32;	.endef
	.def	exit;	.scl	2;	.type	32;	.endef
	.def	strcmp;	.scl	2;	.type	32;	.endef
