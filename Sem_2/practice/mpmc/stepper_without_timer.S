#include <avr/io.h>

.global main
.text

.org 0
main:  ldi r20, hi8(RAMEND)
       out _SFR_IO_ADDR(SPH), r20 
       ldi r20, lo8(RAMEND)
       out _SFR_IO_ADDR(SPL), r20
       ldi r20, 0xff
       out _SFR_IO_ADDR(DDRD), r20

       ldi r20, 0x6
l1:    out _SFR_IO_ADDR(PORTD), r20
       lsr r20
       brcc l2
       ori r20, 0x8
l2:    rcall delay
       rjmp l1
stop: rjmp main

delay: ldi r17, 20
d_l2:  ldi r16, 230
d_l1:  nop
       nop
       dec r16
       brne d_l1
       dec r17
       brne d_l2
       ret
