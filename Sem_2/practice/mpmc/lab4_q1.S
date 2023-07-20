#include <avr/io.h>

.global main
.text

.org 0x300
pArr:   .byte 8,4,2,1
.org 0x320
bArr:   .byte 1,2,4,8

.org 0x600
main:   ldi r16, 240
        ldi r17, 0xFF
        out _SFR_IO_ADDR(DDRD), r17

l2:     ldi ZL, lo8(pArr)
        ldi ZH, hi8(pArr)
        ldi r17, 4
l1:     lpm r19, Z+
        out _SFR_IO_ADDR(PORTD), r19
        call delay
        dec r17
        brne l1
        dec r16
        brne l2
        ldi r16, 120

l3:     ldi ZL, lo8(bArr)
        ldi ZH, hi8(bArr)
        ldi r17, 4
l4:     lpm r19, Z+
        out _SFR_IO_ADDR(PORTD), r19
        call delay
        dec r17
        brne l4
        dec r16
        brne l3

loop:   rjmp loop

delay:  ldi r20, lo8(-0x100F)
        sts TCNT1L, r20
        ldi r20, hi8(-0x100F)
        sts TCT1H, r20
        ldi r20, 0
        sts TCCR1A, r20
        ldi r20, 0x03
        sts TCCR1B, r20

t1:     sbis _SFR_IO_ADDR(TIFR1), TOV1
        rjmp t1
        ldi r20, (1<<TOV1)
        out _SFR_IO_ADDR(TIFR1), r20
        ldi r20, 0
        sts TCCR1A, r20
        sts TCCR1B, r20
        ret
        