.global _start
_start:
	mov r5, #0 		@result
	mov r4, #0		@counter
	mov r2, r3		@prev
	loop:
		cmp r4, #31
		beq break
		ror r2, r2, #1
		add r4, r4, #1
		cmp r2, r3
		bne next
		add r5, r5, #1
		next:
			bal loop
	break:
		mov pc, lr