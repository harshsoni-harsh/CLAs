.global _start
_start:
	mov r10, #0
	f1:
		add r10, r10, #1
		lsr r9, #1
		cmp r9, #0
		bne f1
	mov pc, lr
