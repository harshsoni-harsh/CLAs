#include <avr/io.h>
 
.global main
 
.org 0
.text
main:
    ldi r24, 0xFF
    OUT _SFR_IO_ADDR(DDRD), R24
l6: ldi ZL, lo8(arr)
    ldi ZH, hi8(arr)
    ldi r25, 10
 
 
loop:   lpm r24, Z+
        out _SFR_IO_ADDR(PORTD), r24
        call delay
        dec r25
        brne loop
        rjmp l6
 
stop: rjmp stop
 
delay:  ldi r17, 25
l2:     ldi r18, 255
l3:     ldi r19, 255
l4:     nop
        nop
        dec r19
        brne l4
 
        dec r18
        brne l3
 
        dec r17
        brne l2
        ret
 
.org 0x500
arr:    .byte 0x3F, 0x6, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x7, 0x7F, 0x6F