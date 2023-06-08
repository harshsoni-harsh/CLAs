#include <avr/io.h>
        .global main
        .text
        .org 0x0000
main:   ld r18, -z
        push r16
        sts 0x99, r16


loop: rjmp loop 