.global _start
_start:
	mov r0, #3 // divisor = d
	mov r1, #7 // dividend = n
	mov r2, #0 // u = remainder
	mov r3, r1 // v = quotient
	
	mov r4, #0 // i
	for:
		cmp r4, #32
		beq break
		add r4, r4, #1
		
		shift:
			mov r5, #1
			ror r5, #1
			and r5, r5, r3
			lsl r2, #1
			lsl r3, #1
			
			cmp r5, #0
			addne r2, r2, #1

		sub r2, r2, r0
		
		cmp r2, #0
		blt else
		
		mov r5, #1 // q
		b next
		
		else:
			add r2, r2, r0
			mov r5, #0
			b next
			
		next:
			lsr r3, #1
			lsl r3, #1
			add r3, r3, r5
		b for
	break:
		mov pc, lr