#include <avr/io.h>

.global main
.text

.global TIMER0_OVF_vect

main:   ldi r16, 0xff
        out _SFR_IO_ADDR(DDRB), r16
        ldi r16, (1<<TOIE0)
        sts TIMSK0, r16
        ldi r16, 1
        out _SFR_IO_ADDR(TCCR0A), r16
        ldi r16, 5
        out _SFR_IO_ADDR(TCCR0B), r16
        sei

stop:   rjmp stop

TIMER0_OVF_vect:
        ldi r16, 0
        out _SFR_IO_ADDR(TIFR0), r16
        in r16, _SFR_IO_ADDR(PORTB)
        ldi r17, (1<<5)
        eor r16, r17
        out _SFR_IO_ADDR(PORTB), r16
        reti