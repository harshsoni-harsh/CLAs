.data
    n: .word 3
    mat: .word 1, 4, 3, 7, 5, 4, 9, 0, 6
    cols: .byte 0, 0, 0
    prompt: .asciiz "Determinant is "
    new_line: .asciiz "\n"
.text
.globl main
    main:
        lw $t0, n
        li $s0, 1
        la $t1, mat
        la $t2, cols
        move $a0, $t0
        li $a1, 0
        li $a2, 0
        li $t4, 1
        li $t5, -1
        jal det

        li $v0, 4
        la $a0, prompt
        syscall

        li $v0, 1
        move $a0, $t3
        syscall

        li $v0, 4
        la $a0, new_line
        syscall

        li $v0, 10
        syscall

    det:
        li $a2, 0
        bgt $a0, $s0, recurse
        loop:
            add $t2, $t2, $a2
            lb $t6, 0($t2)
            la $t2, cols
            beq $t6, $s0, next
            mul $t7, $a1, $t0
            add $t7, $t7, $a2
            mul $t7, $t7, 4
            add $t1, $t1, $t7
            lw $t3, 0($t1)
            la $t1, mat
            b ret
        next:
            addi $a2, $a2, 1
            blt $a2, $t0, loop
        ret:
            jr $ra
        recurse:
            li $t3, 0
            li $t4, 1
            addi $sp, $sp, -28
            sw $ra, 0($sp)
            sw $a0, 4($sp)
            sw $a1, 8($sp)
        for:
            add $t2, $t2, $a2
            lb $t6, 0($t2)
            la $t2, cols
            beq $t6, $s0, skip
            add $t2, $t2, $a2
            li $t6, 1
            sb $t6, 0($t2)
            la $t2, cols
            mul $t7, $a1, $t0
            add $t7, $t7, $a2
            mul $t7, $t7, 4
            add $t1, $t1, $t7
            lw $t7, 0($t1)
            la $t1, mat
            mul $t8, $t4, $t7
            sw $a2, 12($sp)
            sw $t3, 16($sp)
            sw $t4, 20($sp)
            sw $t8, 24($sp)
            addi $a0, $a0, -1
            addi $a1, $a1, 1
            jal det

            lw $t8, 24($sp)
            lw $t4, 20($sp)
            lw $a2, 12($sp)
            lw $a1, 8($sp)
            lw $a0, 4($sp)
            mul $t8, $t8, $t3
            lw $t3, 16($sp)
            add $t3, $t3, $t8
            add $t2, $t2, $a2
            li $t6, 0
            sb $t6, 0($t2)
            la $t2, cols
            mul $t4, $t4, $t5
        skip:
            addi $a2, $a2, 1
            blt $a2, $t0, for
            lw $ra, 0($sp)
            addi $sp, $sp, 28
            jr $ra