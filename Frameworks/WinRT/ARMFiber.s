	EXPORT WOCSetJmp
	EXPORT WOCLongJmp

	AREA     ARMFiber, CODE, READONLY, THUMB
	ALIGN 4
WOCSetJmp proc
	stmia r0!, {r4, r5, r6, r7, r8, r9, r10, fp}
	str sp, [r0]
	str lr, [r0, #4]
	; Store current stack top/bottom from TEB
	mrc p15, 0, r1, c13, c0, 2
	ldr r2, [r1, #4]
	str r2, [r0, #8]
	ldr r2, [r1, #8]
	str r2, [r0, #12]
	mov r0, 0
	bx lr
	endp

	ALIGN 4
WOCLongJmp proc
	ldmia r0!, {r4, r5, r6, r7, r8, r9, r10, fp}
	ldr sp, [r0]
	ldr lr, [r0, #4]
	; Restore current stack top/bottom from TEB
	mrc p15, 0, r1, c13, c0, 2
	ldr r2, [r0, #8]
	str r2, [r1, #4]
	ldr r2, [r0, #12]
	str r2, [r1, #8]
	mov r0, 1
	bx lr
	endp
	END

