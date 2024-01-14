// r0 = result, r1 = num, r2 = tempResult, r12 = 1(underflow), r12 = 2(overflow)
 
.data
A: .word 0x41b80000
B: .word 0x45568000

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
        bl reciprocal           // r0 = 1/r0

        mov r5, r0
        bl multiply             // r2 = r2*r0

        mov r0, r2
        b iterate__start
	
    exit__start:
        mov pc, lr

reciprocal:
    stmfd sp!, {r0,r1,r2,r3,r4,r6,r7,r8,lr}
    mov r0, r5
    mov r1, r0

    lsl r1, #1
    lsr r1, #24
    rsb r1, r1, #252
    lsl r1, #23                 // exponent
    
    mov r7, r0
    lsr r7, #31
    lsl r7, #31                 // sign bit

    lsl r0, #9
    lsr r0, #9                  // mantissa
    
    cmp r0, #0
    beq exit__reciprocal
	
	mov r8, #1
	lsl r8, #31					// for negation

    mov r3, #127
    lsl r3, #23					// 1.0
	
	mov r2, r0
	lsl r2, #9	
	lsr r2, #9
	add r2, r2, r3
	eor r2, r2, r8				// -(1+x)
	
	lsr r3, #23
	add r3, r3, #1
	lsl r3, #23
	mov r5, r3
	bl add						// 2-(1+x)
    
	mov r5, #126
	lsl r5, #23
	bl multiply
	mov r8, r2                  // Y
	mov r9, r8

    mov r6, #127
    lsl r6, #23                  // accumulator
	
    mov r4, #32
    
    iterate__reciprocal:

        cmp r4, #0
        beq normalize__reciprocal
        sub r4, r4, #1
        
        mov r2, r6
		mov r5, r8
        bl add
        mov r6, r2

        mov r2, r8
		mov r5, r9
        bl multiply
        mov r8, r2

        b iterate__reciprocal

    normalize__reciprocal:					// > 2
		cmp r6, r3
		blt normalize2__reciprocal
		add r1, r1, #1
		lsr r6, #1
		b normalize__reciprocal
	normalize2__reciprocal:					// < 1
		cmp r6, #0
		beq exit__reciprocal
		mov r8, r6
		lsr r8, #23
		cmp r8, #1
		bge exit__reciprocal
		sub r1, r1, #1
		lsl r6, #1
		b normalize2__reciprocal

    exit__reciprocal:
        mov r2, r6
        lsl r2, #9
        lsr r2, #9
        add r2, r2, r1
        add r2, r2, r7
		
		mov r5, r2
        ldmfd sp!, {r0,r1,r2,r3,r4,r6,r7,r8,lr}
		mov r0, r5
        bx lr

add:
    stmfd sp!, {r0,r1,r3,r4,r5,r6,r7,r8,r9,lr}
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

        ldmfd sp!, {r0,r1,r3,r4,r5,r6,r7,r8,r9,lr}
		bx lr
	
multiply:
    stmfd sp!, {r0,r1,r3,r4,r5,r6,r7,r8,r9,lr}
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
        ldmfd sp!, {r0,r1,r3,r4,r5,r6,r7,r8,r9,lr}
		bx lr
