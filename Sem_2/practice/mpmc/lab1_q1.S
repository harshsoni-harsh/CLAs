#include <avr/io.h>

.global main
.text
.org 0x00
main:   ldi r30, lo8(pArr)
        ldi r31, hi8(pArr)
        ldi r16, 0
        ldi r18, 0
        ldi r19, 10

l1:     lpm r16, Z+
        add r18, r16
        dec r19
        brne l1

        ldi r26, lo8(0x200)
        ldi r27, hi8(0x200)
        st X, r18

stop:   rjmp stop

.org 0x500
pArr:   .byte 9,8,7,6,5,4,3,2,1,10