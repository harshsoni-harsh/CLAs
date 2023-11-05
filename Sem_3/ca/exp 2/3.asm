.text
.globl main
main:
    li $t0, 0x0000f0f0
    li $t1, 1
    li $t2, 0
    li $t3, 32
    loop:
        and $t4, $t0, $t1
        srl $t0, $t0, 1
        addi $t3, $t3, -1
        bne $t4, $t1, l1
        addi $t2, $t2, 1
    l1:
        bne $t4, $t1, skip
        and $t4, $t0, $t1
        srl $t0, $t0, 1
        addi $t3, $t3, -1
        j l1
    skip:
        bne $t3, $zero, loop
    li $v0, 10
    syscall