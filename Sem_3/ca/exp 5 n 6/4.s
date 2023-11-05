.global _start
_start:
	mov r0, #1
	lsl r0, #31
	mov r2, r3
	mov r5, #0
	while:
		cmp r3, #0
		beq end
		
		and r8, r3, r0
		lsl r3, r3, #1
		
		and r9, r3, r0
		lsl r3, r3, #1
		
		cmp r8, r9
		beq err
		
		cmp r8, r0
		beq one
		lsl r4, r4, #1
		bal while
		
		one:
			lsl r4, r4, #1
			add r4, r4, #1
			bal while
	
	err:
		mov r5, #1
	end:
		mov pc, lr

@testcase = r3-0x5556595a, r4-0x123, r5-0