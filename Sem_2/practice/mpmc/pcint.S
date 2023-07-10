#define _SFR_OFFSET 0
#include<avr/io.h>
    .global  main
    .text

    .org 0x000A
    jmp  isr_pcint

    .org 0x100

delay: 

    ldi r21,40
l1: ldi r22, 255
l2: ldi r23,255
l3: dec r23
    brne l3
    dec r22
    brne l2
    dec R21
    brne l1
      
    ret

main:;ldi r20, lo8(0x2000) ; initialise stack pointer
     
    ;out _SFR_IO_ADDR(SPL),r20
    ;ldi r20, hi8(0x2000)
    ;OUT _SFR_IO_ADDR(SPH),r20

    ldi r21, 6
    STS PCMSK2, r21               ;set pins that can interrupt 
    ldi r21, (1<<PCIE2)              
    STS PCICR,r21                ;enable pc interrupt for portD 
    SEI                ; set global interrupt
    SBI _SFR_IO_ADDR(DDRB),5
    SBI _SFR_IO_ADDR(DDRD),0
    CBI _SFR_IO_ADDR(DDRD),1
    CBI _SFR_IO_ADDR(DDRD),2
     SBI _SFR_IO_ADDR(PORTD),2
      SBI _SFR_IO_ADDR(PORTD),1
    SBI _SFR_IO_ADDR(PORTB),5

loop:CBI _SFR_IO_ADDR(PORTD),0                 ;do main task
    call delay
    SBI _SFR_IO_ADDR(PORTD),0
    call delay
    rjmp loop

isr_pcint:
 
    IN r24,_SFR_IO_ADDR(PORTB)  ;toggle pin PB5
    ldi r25, (1<<5)
    EOR r24,r25
    OUT _SFR_IO_ADDR(PORTB),r24
    ;call delay
reti
