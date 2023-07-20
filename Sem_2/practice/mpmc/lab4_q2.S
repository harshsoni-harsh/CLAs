#include <avr/io.h>

.global main
.text

.org 0x200
clock:  .byte 8,4,2,1

.org 0x600
main:   ldi r17, 0xFF
        out _SFR_IO_ADDR(DDRD), r17

loop:   ldi ZL, lo8(clock)
        ldi ZH, hi8(clock)
        ldi r17, 4
l1:     lpm r19, Z+
        out _SFR_IO_ADDR(PORTD), r19
        call delay
        dec r17
        brne l1
        rjmp loop

delay:  ldi r22, lo8(-0x4C4)
        sts TCNT1L, r22
        ldi r22, hi8(-0x4C4)
        sts TCNT1H, r22
        ldi r22, 0
        sts TCCR1A, r22
        ldi r22, 0x03
        sts TCCR1B, r22
wait:   sbis _SFR_IO_ADDR(TIFR1), TOV1
        rjmp wait
        ldi r22, (1<<TOV1)
        out _SFR_IO_ADDR(TIFR1), r22
        ldi r22, 0
        sts TCCR1A, r22
        sts TCCR1B, r22
        ret