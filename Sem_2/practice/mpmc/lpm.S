#include <avr/io.h>

.global main
.text
.org 0
main:
    ldi r20, 0xFF
    out DDRB, r20
    ldi r30, lo8(mydata)
    ldi r31, hi8(mydata)
    lpm r20, Z
    out PORTB, r20
    inc ZL
    lpm r20,Z
    out PORTB, r20
    inc ZL
    lpm r20,Z
    out PORTB, r20
here: rjmp here

.org 500
mydata: .string "USA"