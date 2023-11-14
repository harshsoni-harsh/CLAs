.global _start
_start:
	mov r2, #0
	mov r3, r1
	mov r5, #32
	mvn r6, r0
	add r6, r6, #1
	mov r4, #0
	for:
		and r7, r3, #1
		cmp r7, r4
		beq shift
		
		cmp r4, #1
		bne next
		add r2, r2, r0
		b shift
		
		next:
			add r2, r2, r6
			beq shift
		
		shift:
			and r4, r3, #1
			lsr r3, #1
			
			and r7, r2, #1
			ror r7, #1
			add r3, r3, r7
			
			asr r2, #1
			
		sub r5, r5, #1
		cmp r5, #0
		bne for
	mov pc, lr