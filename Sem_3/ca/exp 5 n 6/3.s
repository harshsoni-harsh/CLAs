.global _start
_start:
	loop:
		cmp r3, #0
		beq skip
		cmp r3, r4
		beq skip
		
	mod:
		mov r1, #0
		mov r2, #0
		
		mult:
			add r1, r1, #1
			mul r8, r3, r1
			subs r2, r4, r8
			bpl mult
			sub r1, r1, #1
			mul r8, r3, r1
			subs r2, r4, r8
			
			mov r4, r3
			mov r3, r2
			bal loop
			
	skip:
		mov r5, r4
		mov pc, lr
