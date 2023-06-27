#include<avr/io.h>
 
	.global main
 
	.text 
	.org 0x0000
 
main: ldi r16, 0xff
		OUT _SFR_IO_ADDR(DDRD), r16
		ldi r16, 0
		OUT _SFR_IO_ADDR(PORTD), r16
 
		ldi r16, ~0b11000000	; 0
		ldi r17, ~0b11111001 	; 1
		ldi r18, ~0b10100100 	; 2
		ldi r19, ~0b10110000	; 3
		ldi r20, ~0b10011001	; 4
		ldi r21, ~0b10010010	; 5
		ldi r22, ~0b10000010	; 6
		ldi r23, ~0b11111000	; 7
		ldi r24, ~0b10000000 	; 8
		ldi r25, ~0b10010000 	; 9
 
loop: OUT _SFR_IO_ADDR(PORTD), r16 ; 0
		call DELAY
		OUT _SFR_IO_ADDR(PORTD), r17	;1
		call DELAY
		OUT _SFR_IO_ADDR(PORTD), r18	;2
		call DELAY	
		OUT _SFR_IO_ADDR(PORTD), r19	;3
		call DELAY
		OUT _SFR_IO_ADDR(PORTD), r20	;4
		call DELAY
		OUT _SFR_IO_ADDR(PORTD), r21	;5
		call DELAY
		OUT _SFR_IO_ADDR(PORTD), r22	;6
		call DELAY
		OUT _SFR_IO_ADDR(PORTD), r23	;7
		call DELAY
		OUT _SFR_IO_ADDR(PORTD), r24	;8
		call DELAY
		OUT _SFR_IO_ADDR(PORTD), r25	;9
		call DELAY
 
		rjmp loop
 
 
DELAY: ldi r27, 5
l1: ldi r28, 0xff
l2:ldi r29, 0xff
l3:dec r29
	brne l3
	dec r28
	brne l2
	dec r27
	brne l1
	ret