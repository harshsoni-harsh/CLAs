#include <avr/io.h>

;#define _SFR_OFFSET 0

.global main
.text


.org 0x4
jmp ex_isr

main:  ldi r20, (1<<INT1)
       out _SFR_IO_ADDR(EIMSK), r20
       ldi r20, 0x08
       sts EICRA, r20
       
       ldi r20, (1<<3)
       out _SFR_IO_ADDR(PORTD), r20
            ;cbi _SFR_IO_ADDR(DDRD), 2
       sbi _SFR_IO_ADDR(PORTD), PD3
       sbi _SFR_IO_ADDR(DDRB), PB5

       sei

loop:   rjmp loop

ex_isr: in r20, _SFR_IO_ADDR(PORTB)
        ldi r21, (1<<5)
        eor r20, r21
        out _SFR_IO_ADDR(PORTB), r20
        reti

ex0_isr: in r20, _SFR_IO_ADDR(PORTB)
        ldi r21, (1<<5)
        eor r20, r21
        out _SFR_IO_ADDR(PORTB), r20
        reti