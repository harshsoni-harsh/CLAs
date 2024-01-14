// r0 = result, r1 = num, r2 = tempResult, r12 = 1(underflow), r12 = 2(overflow)
 
.data
A: .word 0x41b80000		// guessed root
B: .word 0x45568000		// find root of this
C: .word 0x3a83126f		// approximated reciprocal

.text 
.global _start
_start:
	ldr r0, =A
	ldr r0, [r0]
    mov r2, r0
	
	ldr r1, =B
	ldr r1, [r1]
 	
	mov r3, #20
	iterate__start:
		cmp r3, #0
		beq exit__start
		sub r3, r3, #1
		mov r2, r0

        mov r5, r2
		bl multiply             // r2 = r2*r2

        mov r5, r1
		bl add                  // r2 += r1

        mov r5, r0
        bl reciprocal           // r0 = 1/(2*r0)

        mov r5, r0
        bl multiply             // r2 = r2*r0

        mov r0, r2
        b iterate__start
	
    exit__start:
        mov pc, lr

reciprocal:
    stmfd sp!, {r0,r1,r2,r3,r4,r6,r7,r8,r10,lr}

	// r0 = x_0, r1 = b

	ldr r0, =C
	ldr r0, [r0]
	mov r1, r5

	mov r8, r1
	lsr r8, #31
	lsl r8, #31			// sign bit

	mov r10, #1
	lsl r10, #31		// for negation

	mov r6, #1
	lsl r6, #23

	mov r3, #1
	mov r11, #12
	iterate__reciprocal:
		mov r3, r0
		lsl r3, #9
		lsr r3, #9
		mov r9, r0
		lsl r9, #1
		lsr r9, #24
		add r9, r9, #1
		lsl r9, #23
		add r3, r3, r9			// 2 * x_0
		
		mov r5, r0
		mov r2, r1
		bl multiply
		bl multiply

		eor r2, r2, r10

		mov r5, r3
		bl add
		mov r0, r2			// x_1
		
		sub r11, r11, #1
		cmp r11, #0
		bne iterate__reciprocal
	
	mov r9, r2
	lsl r9, #1
	lsr r9, #24
	sub r9, r9, #1
	lsl r9, #23
	
	lsl r2, #9
	lsr r2, #9
	add r2, r2, r9
	add r2, r2, r8
	
	mov r5, r2 
	ldmfd sp!, {r0,r1,r2,r3,r4,r6,r7,r8,r10,lr}
	mov r0, r5				// 2*x_n - b*x_n^2
	bx lr

add:
    stmfd sp!, {r0,r1,r3,r4,r5,r6,r7,r8,r10,lr}
    mov r0, r2
    mov r1, r5
	cmp r0, #0
	beq bracket1__add
	b if2__add
 
	bracket1__add:
		mov r2, r1
		b exit__add
	if2__add:
		cmp r1, #0
		beq bracket2__add
		b next1__add
	bracket2__add:
		mov r2, r0
		b exit__add
	next1__add:						//exponent
		mov r3, r0
		lsl r3, #1
		lsr r3, #24
		mov r4, r1
		lsl r4, #1
		lsr r4, #24
 
	cmp r4, r3
	bgt bracket3__add
	b next2__add
	bracket3__add:
		mov r5, r1
		mov r1, r0
		mov r0, r5
 
		mov r5, r3
		mov r3, r4
		mov r4, r5
	next2__add:
		mov r8, #1
		lsl r8, #23				//mantissa
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
		bne bracket4__add
		b next3__add
	bracket4__add:					// check opposite signs
		mvn r7, r7
		add r7, r7, #1
	next3__add:
		sub r8, r3, r4
		asr r7, r8
		
		add r7, r7, r5
		cmp r7, #0
		blt bracket5__add
		b next4__add
	bracket5__add:					//if w < 0
		mvn r7, r7
		add r7, r7, #1
		mvn r10, r10
		lsl r10, #31
		lsr r10, #31
	next4__add:						//normalise, check if > 2
		mov r8, r7
		lsr r8, #23
		cmp r8, #2
		blt next5__add
		asr r7, #1
		add r9, r9, #1
		b next4__add 
 
 	next5__add:						//normalise, check if < 1
		mov r8, r7
		cmp r8, #0
		beq next6__add
		lsr r8, #23
		cmp r8, #1
		beq next6__add
		lsl r7, #1
		sub r9, r9, #1
		b next5__add
		
	next6__add:
		cmp r9, #1
		blt underflow__add
		cmp r9, #254
		bgt overflow__add
		mov r12, #0
		b exit__add
	underflow__add:
		mov r12, #1
		b exit__add
	overflow__add:
		mov r12, #2
		b exit__add
		
	exit__add:
		mov r2, r10
		lsl r2, #31
		mov r8, r9
		lsl r8, #23
		add r2, r2, r8
		mov r8, r7
		lsl r8, #9
		lsr r8, #9
		add r2, r2, r8

        ldmfd sp!, {r0,r1,r3,r4,r5,r6,r7,r8,r10,lr}
		bx lr
	
multiply:
    stmfd sp!, {r0,r1,r3,r4,r5,r6,r7,r8,r10,lr}
    mov r0, r2
    mov r1, r5
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
        ldmfd sp!, {r0,r1,r3,r4,r5,r6,r7,r8,r10,lr}
		bx lr
