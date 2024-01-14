// r0 = a, r1 = b, r3 = s, r4 = e, r5 = w, r12 = 1(underflow), r12 = 2(overflow)
 
.data
A: .word 0xc1b80000
B: .word 0xc5568000

.text 
.global _start
_start:
	ldr r0, =A
	ldr r0, [r0]
	ldr r1, =B
	ldr r1, [r1]
 	
	mov r12, #0
	cmp r0, #0
	beq bracket1
	b if2
 
	bracket1:
		mov r2, #0
		b exit
	if2:
		cmp r1, #0
		beq bracket2
		b next1
	bracket2:
		mov r2, #0
		b exit
	next1:
	mov r3, r0
	lsr r3, #31
	mov r8, r1
	lsr r8, #31
	eor r3, r3, r8				//setting sign bit
	
	mov r4, r0
	lsl r4, #1
	lsr r4, #24
	mov r8, r1
	lsl r8, #1
	lsr r8, #24
	add r4, r4, r8
	sub r4, r4, #127			//setting exponent
	
	cmp r4, #1
	blt underflow
	cmp r4, #254
	bgt overflow
	b next
	
	underflow:
		mov r12, #1
		b exit
	overflow:
		mov r12, #2
		b exit
	next:
		mov r5, r0
		lsl r5, #9
		lsr r5, #9
		mov r6, r1
		lsl r6, #9
		lsr r6, #9
		mov r8, #1
		lsl r8, #23
		add r5, r5, r8
		add r6, r6, r8
		umull r8, r9, r6, r5			// mantissa
		mov r7, #9
	shift:
		cmp r7, #0
		beq copy
		lsl r9, #1
		mov r10, r8
		lsr r10, #31
		add r9, r9, r10
		sub r7, r7, #1
		b shift
	copy:
		mov r5, r9
		mov r8, #2
		lsl r8, #23
	normalize:					// > 2
		cmp r5, r8
		blt normalize2
		add r4, r4, #1
		lsr r5, #1
		b normalize
	normalize2:					// < 1
		cmp r5, #0
		beq next2
		mov r8, r5
		lsr r8, #23
		cmp r8, #1
		bge next2
		sub r4, r4, #1
		lsl r5, #1
		b normalize2
	next2:
		cmp r4, #1
		blt underflow2
		cmp r4, #254
		bgt overflow2
		b next3

		underflow2:
			mov r12, #1
			b exit
		overflow2:
			mov r12, #2
			b exit
	next3:
		lsl r5, #9
		lsr r5, #9
		mov r2, r5
		lsl r4, #23
		add r2, r2, r4
		mov r8, r3
		lsl r8, #31
		add r2, r2, r8

	exit:
		mov pc, lr
