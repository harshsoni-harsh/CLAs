#include <avr/io.h>

#define _SFR_OFFSET 0
.global main

main:   ldi r25, 0xFF
        out _SFR_IO_ADDR(DDRB), r25
    
loop:   sbi _SFR_IO_ADDR(PORTB), 5
        call DELAY
        cbi _SFR_IO_ADDR(PORTB), 5
        call DELAY
        rjmp loop

DELAY:  ldi r17, 25
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