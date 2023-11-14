// r0,r1 = nums
// r3, r2 = product
// r4,r5 = constants
// r6 = loop

.global _start
_start:
	mov r0, #32
	mov r1, #2
	mov r3, #0
	mov r2, r0
	mov r4, r1
	mov r5, #0		// for for loop
	// mov r6, #1		// and 1
	// r7 = temp
	for:
		cmp r5, #32
		beq break
		add r5, r5, #1
		and r7, r2, #1
		cmp r7, #1
		bne shift
		
		if_outer:
			cmp r5, #32
			beq else

			if:
				add r3, r3, r1
				bal shift

			else:
				sub r3, r3, r1

		shift:
			and r7, r3, #1
			asr r3, #1
			lsr r2, #1
			ror r7, #1
			add r2, r7, r2
			bal for
	break:
		
		mov pc, lr