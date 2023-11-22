// r0 = a, r1 = b, r2 = result, r3 = x, r4 = y, r5 = p, r6 = q, r7 = w, r9 = e, r10 = s, r8 = temp, r12 = 1(underflow), r12 = 2(overflow)

.data 
A: .word 0b01000001001001101110000101001000 
B: .word 0b11000000100011100001010001111011 
 
.text 
.global _start
_start:
 	ldr r0, =A
	ldr r0, [r0]
	ldr r1, =B
	ldr r1, [r1]
	
	cmp r0, #0
	beq bracket1
	b if2
 
	bracket1:
		mov r2, r1
		b exit
	if2:
		cmp r1, #0
		beq bracket2
		b next1
	bracket2:
		mov r2, r0
		b exit
	next1:						//exponent
		mov r3, r0
		lsl r3, #1
		lsr r3, #24
		mov r4, r1
		lsl r4, #1
		lsr r4, #24
 
	cmp r4, r3
	bgt bracket3
	b next2
	bracket3:
		mov r5, r1
		mov r1, r0
		mov r0, r5
 
		mov r5, r3
		mov r3, r4
		mov r4, r5
	next2:
		mov r8, #1
		lsl r8, #23
 									//mantissa
		mov r5, r0
		lsl r5, #9
		lsr r5, #9
		add r5, r8
 
		mov r6, r1
		lsl r6, #9
		lsr r6, #9
		add r6, r8
 
		mov r7, r6
 
		mov r9, r3
		mov r10, r0
		lsr r10, #31
 
		mov r8, r1
		lsr r8, #31
		cmp r10, r8
		bne bracket4
		b next3
	bracket4:					// check opposite signs
		mvn r7, r7
		add r7, r7, #1
	next3:
		sub r8, r3, r4
		asr r7, r8
		
		add r7, r7, r5
		cmp r7, #0
		blt bracket5
		b next4
	bracket5:					//if w < 0
		mvn r7, r7
		add r7, r7, #1
		mvn r10, r10
		lsl r10, #31
		lsr r10, #31
	next4:						//normalise, check if > 2
		mov r8, r7
		lsr r8, #23
		cmp r8, #2
		blt next5
		asr r7, #1
		add r9, r9, #1
		b next4 
 
 	next5:						//normalise, check if < 1
		mov r8, r7
		cmp r8, #0
		beq next6
		lsr r8, #23
		cmp r8, #1
		beq next6
		lsl r7, #1
		sub r9, r9, #1
		b next5
		
	next6:
		cmp r9, #1
		blt underflow
		cmp r9, #254
		bgt overflow
		mov r12, #0
		b exit
	underflow:
		mov r12, #1
		b exit
	overflow:
		mov r12, #2
		b exit
		
	exit:
		mov r2, r10
		lsl r2, #31
		mov r8, r9
		lsl r8, #23
		add r2, r2, r8
		mov r8, r7
		lsl r8, #9
		lsr r8, #9
		add r2, r2, r8
		mov pc, lr
