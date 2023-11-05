.global _start
_start:
	add r10, r4, r7	
	adc r9, r3, r6
	adc r8, r2, r5
	
	mov pc, lr
