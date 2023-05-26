#include<avr/io.h>
    .global main
    .equ    numB,20

    .data 
    .org    0x0100
sArr: .BYTE numB

    .text
    .org    0x0000

main:ldi r26, lo8(sArr)
     ldi r27,hi8(sArr)

    ldi   r30, lo8(pArr)
    ldi   r31, hi8(pArr)

    ldi   r17, numB

arrLp:lpm r0,Z+
    st  X+,r0
    dec r17
    brne    arrLp

loop: rjmp  loop
    .org   0x0030

pArr: .byte 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19