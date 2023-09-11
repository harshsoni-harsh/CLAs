.text
    main:
        li $t3, 0x80018000              #input
        li $t1, 2                       #for considering modulo

        li $s2, 31
        
        move $t5, $t3
        reverse:
            beq $s2, 0, compare         #looping for 31 times
            andi $s1, $t3, 1           #getting bit
            add $s3, $s3, $s1
            sll $s3, $s3, 1

            addi $s2, $s2, -1           
            srl $t3, $t3, 1
            j reverse

        compare:            
            andi $s1, $t3, 1           #getting bit
            add $s3, $s3, $s1
            bne $t5, $s3, exit

        li $t4, 1
        exit:
            li $v0, 10
            syscall

