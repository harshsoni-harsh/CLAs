.data
    ask: .asciiz "Enter lenght of matrix: "
    left_side: .asciiz "mat["
    right_side: .asciiz "] = "
    comma: .asciiz ", "
    print_det: .asciiz "Determinant is "

.text
.globl main
    main:
        li $v0, 4
        la $a0, ask
        syscall
        li $v0, 5
        syscall
        move $t0, $v0

        li $a0, 4
        mul $a0, $t0, $a0
        mul $a0, $t0, $a0
        li $v0, 9
        syscall
        move $t1, $v0
        move $t2, $v0

        li $t3, -1
        input_loop:
            li $t4, 0
            addi $t3, $t3, 1
            blt $t3, $t0, input_inner_loop
            j next
            input_inner_loop;
                beq $t4, $t0, input_loop

                li $v0, 4
                la $a0, left_side
                syscall
                li $v0, 1
                move $a0, $t3
                syscall
                li $v0, 4
                la $a0, comma
                syscall
                li $v0, 1
                move $a0, $t4
                syscall
                li $v0, 4
                la $a0, right_side
                syscall
                li $v0, 5
                syscall
                sw $v0, 0($t2)
                addi $t2, $t2, 4
                addi $t4, $t4, 1
                j input_inner_loop
        next:
            move $t2, $t1
            addi $sp, $sp, -16
            li $t4, 0
            sw $t4, 0($sp)          #determinant
            sw $t2, 4($sp)          #matrix address
            sw $t2, 8($sp)          #columns
            sw $ra, 12($sp)         #return address
            jal determinant
        exit:
            li $v0, 4
            la $a0, print_det
            syscall
            li $v0, 1
            lw $a0, 0($sp)
            syscall
        
        determinant:
            lw $s0, 0($sp)          #determinant
            lw $s1, 4($sp)          #matrix address
            lw $s2, 8($sp)          #columns
            lw $s3, 12($sp)         #return address
            li $s4, 1
            bne $s2, $s4, continue
            lw $s4, 0($s2)
            addi $s0, $s0, $s4
            move $ra, $s3
            jr $ra

            continue:
                li $t0, 0               #for determinant
                li $t1, -1              #for outer loop
                for_1:
                    addi $t1, $t1, 1
                    beq $t1, $s2, return
                    
                    move $t2, $s2
                    addi $t2, $t2, -1
                    li $a0, 4
                    mul $a0, $a0, $t2
                    mul $a0, $a0, $t2
                    li $v0, 9
                    syscall
                    move $s4, $v0       #temp_matrix
                    
                    li $t3, -1          #for inner loop
                    for_2:
                        addi $t3, $t3, -1
                        move $s5, $s4       #temp_matrix_copy
                        li $s6, 4
                        mul $s6, $a0, $s6
                        mul $s6, $t3, $s6
                        add $s5, $s5, $s6
                        beq $t3, $s2, for_1
                        li $t4, 0
                        li $t5, -1
                        for_3:
                            addi $t5, $t5, 1
                            beq $t5, $t1, for_4