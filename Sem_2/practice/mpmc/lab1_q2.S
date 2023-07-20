#include <avr/io.h>

.global main
.equ num, 10

.data
.org 0x200
sArr:   .byte num

.text
.org 0x00
main:   ldi r16, hi8(RAMEND)
        out _SFR_IO_ADDR(SPH), r16
        ldi r16, lo8(RAMEND)
        out _SFR_IO_ADDR(SPL), r16
        ldi r21, num

        ldi XL, lo8(sArr)
        ldi XH, hi8(sArr)
        ldi ZL, lo8(pArr)
        ldi ZH, hi8(pArr)
        ldi r20, num

store:  lpm r25, Z+
        st X+, r25
        dec r20
        brne store
outer:  ldi r20, num
        ldi XL, lo8(sArr)
        ldi XH, hi8(sArr)
inner:  dec r20
        cpi r20, -1
        breq nextLp
        
        ld r16, X+
        ld r17, X
        cp r17, r16
        brge inner
        push r16
        push r17
        pop r16
        pop r17
        dec XL
        st X+, r16
        st X, r17
        rjmp inner

nextLp: dec r21
        brne outer

stop:   rjmp stop

.org 0x500
pArr:   .byte 9,3,7,1,5,2,4,6,8,10