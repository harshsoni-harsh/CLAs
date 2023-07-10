#include <avr/io.h>

.global main

    .text
    .org 0x300
pArr: .byte 9, 12, 6, 3

    .org 0x600

main:
    ldi r16,128
    ldi r17, 0xFF
    OUT _SFR_IO_ADDR(DDRD), r17

l2: ldi ZL, lo8(pArr)
    ldi ZH, hi8(pArr)

    ldi r17, 4
l1: lpm r19, Z+
    OUT _SFR_IO_ADDR(PORTD), r19 
    call delay
    dec r17
    brne l1
    dec r16
    brne l2
loop: rjmp loop

delay:
    ldi r20, lo8(-0x900F)
    sts TCNT1L, r20 
    ldi r20, hi8(-0x100F)
    sts TCNT1H, r20 
    
    ldi r20 ,0x0
    sts TCCR1A, r20
    ldi r20, 0x03
    sts TCCR1B, r20

t1: SBIS _SFR_IO_ADDR(TIFR1), TOV1
    rjmp t1
    LDI r20, (1<<TOV1)
    OUT _SFR_IO_ADDR(TIFR1), r20
    ldi r20, 0
    STS TCCR1A, r20
    STS TCCR1B, r20
    ret


