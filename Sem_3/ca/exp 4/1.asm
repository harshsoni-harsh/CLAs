.data
    matrix: .space 36
    matrix2: .space 36
    mat_add: .space 36
    mat_sub: .space 36
    mat_mul: .space 36
    mat_det: .space 36
    newline: .asciiz "\n"
    space: .asciiz " "
    print_matrix1: .asciiz "\nMatrix 1"
    print_matrix2: .asciiz "\nMatrix 2"
    print_addition: .asciiz "\nAddition"
    print_subtraction: .asciiz "\nSubtraction"
    print_multiplication: .asciiz "\nMultiplication"
.text
    main:
        li $t0, 1
        la $t1, matrix
        li $t2, 0
        while:
            sw $t0, 0($t1)
            addi $t1, $t1, 4
            addi $t0, $t0, 1
            addi $t2, $t2, 1
            bne $t2, 9, while
        
        li $v0, 4
        la $a0, print_matrix1
        syscall
        la $s4, matrix
        li $s5, 3
        li $s6, 3
        jal print_mat

        li $t0, 10
        la $t1, matrix2
        li $t2, 0
        while2:
            sw $t0, 0($t1)
            addi $t1, $t1, 4
            addi $t0, $t0, 1
            addi $t2, $t2, 1
            bne $t2, 9, while2
        
        li $v0, 4
        la $a0, print_matrix2
        syscall
        la $s4, matrix2
        li $s5, 3
        li $s6, 3
        jal print_mat

        addition:
            la $t1, matrix
            la $t3, matrix2
            la $t4, mat_add
            li $t2, 0
            while3:
                lw $s0, 0($t1)
                lw $s1, 0($t3)
                add $s0, $s0, $s1
                sw $s0, 0($t4)
                addi $t1, $t1, 4
                addi $t3, $t3, 4
                addi $t4, $t4, 4
                addi $t2, $t2, 1
                bne $t2, 9, while3

        li $v0, 4
        la $a0, print_addition
        syscall
        la $s4, mat_add
        li $s5, 3
        li $s6, 3
        jal print_mat
        

        subtraction:
            la $t1, matrix
            la $t3, matrix2
            la $t4, mat_sub
            li $t2, 0
            while4:
                lw $s0, 0($t1)
                lw $s1, 0($t3)
                sub $s0, $s0, $s1
                sw $s0, 0($t4)
                addi $t1, $t1, 4
                addi $t3, $t3, 4
                addi $t4, $t4, 4
                addi $t2, $t2, 1
                bne $t2, 9, while4
        
        li $v0, 4
        la $a0, print_subtraction
        syscall
        la $s4, mat_sub
        li $s5, 3
        li $s6, 3
        jal print_mat

        multiplication:
            la $t3, matrix
            la $t4, matrix2
            la $t1, mat_mul
            li $t5, 0
            loop1:
                li $t6, 0
                loop2:
                    li $s3, 0
                    lw $s0, 0($t3)
                    lw $s1, 0($t4)
                    mul $s2, $s0, $s1
                    add $s3, $s3, $s2
                    lw $s0, 4($t3)
                    lw $s1, 12($t4)
                    mul $s2, $s0, $s1
                    add $s3, $s3, $s2
                    lw $s0, 8($t3)
                    lw $s1, 24($t4)
                    mul $s2, $s0, $s1
                    add $s3, $s3, $s2
                    sw $s3, 0($t1)
                    addi $t4, $t4, 4
                    addi $t1, $t1, 4
                    addi $t6, $t6, 1
                    bne $t6, 3, loop2
                addi $t4, $t4, -12
                addi $t3, $t3, 12
                addi $t5, $t5, 1
                bne $t5, 3, loop1
        
        li $v0, 4
        la $a0, print_multiplication
        syscall
        la $s4, mat_mul
        li $s5, 3
        li $s6, 3
        jal print_mat   

        exit:
            li $v0, 10
            syscall

        print_mat:
            move $s3, $s6
            outer_loop:
                li $v0, 4
                la $a0, newline
                syscall
                beq $s5, 0, skip
                addi $s5, $s5, -1
                move $s6, $s3
                inner_loop:
                    beq $s6, 0, outer_loop
                    li $v0, 1
                    lw $a0, 0($s4)
                    syscall
                    li $v0, 4
                    la $a0, space
                    syscall
                    addi $s6, $s6, -1
                    addi $s4, $s4, 4
                    j inner_loop
            skip:
                jr $ra