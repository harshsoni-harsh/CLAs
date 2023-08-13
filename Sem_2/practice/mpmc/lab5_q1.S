#include <avr/io.h>

.global main
.text

.global TIMER1_OVF_vect

main:   ldi r16, 0xff
        out _SFR_IO_ADDR(DDRB), r16
        ldi r16, (1<<TOIE1)
        sts TIMSK1, r16
        ldi r16, 0
        sts (TCCR1A), r16
        ldi r16, 3
        sts (TCCR1B), r16
        sei

stop:   rjmp stop

TIMER1_OVF_vect:
        ldi r16, 0
        sts TIFR1, r16
        in r16, _SFR_IO_ADDR(PORTB)
        ldi r17, (1<<5)
        eor r16, r17
        out _SFR_IO_ADDR(PORTB), r16
        reti