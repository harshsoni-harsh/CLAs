.include "/usr/avr/include/avr/io.h"

.global main
.text
.org 0

main:
    ldi r18, 1/5;
stop: rjmp stop