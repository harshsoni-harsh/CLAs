#include <avr/io.h>

#define F_CPU 0x16000000

.global main

.text
.org 0
main:   ldi r17, 200
        ldi r16, 45
        ldi r18, -1
        ldi ZH, hi8(nums)
        ldi r20, 0xff
        OUT _SFR_IO_ADDR(DDRD), r20
        ldi ZL, lo8(nums)

l1:     inc r18
        sub r17, r16
        brpl l1
        
        add ZL, r18
        out _SFR_IO_ADDR(PORTD), r21
        spm z+


stop: rjmp stop


.org 0x300
nums:   .byte 0X3F, 0X6, 0X5B, 0X4F, 0X66, 0X6D, 0X7D, 0X7, 0X7F, 0X6F