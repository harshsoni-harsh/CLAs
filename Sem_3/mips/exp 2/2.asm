.data
    ask: .asciiz "Enter a binary number: "
    gcd: .asciiz "GCD is "
.text
    main:
        li $v0, 4
        la $a0, ask
        syscall

        li $v0, 5
        syscall
        move $t0, $v0
        move $t3, $t0

        li $v0, 4
        la $a0, ask
        syscall

        li $v0, 5
        syscall
        move $t1, $v0
        move $t4, $t1

    convert_in_decimal:
        li $s3, 10                   
        li $s4, 1                   #for index
        loop1:
            div $t0, $s3
            mfhi $s1                #modulo
            mflo $t0                #quotient
            mul $s1, $s1, $s4
            add $s2, $s1, $s2
            sll $s4,$s4, 1
            bne $t0, 0, loop1
        move $t0, $s2
        li $s4, 1
        li $s2, 0
        loop2:
            div $t1, $s3
            mfhi $s1                #modulo
            mflo $t1                #quotient
            mul $s1, $s1, $s4
            add $s2, $s1, $s2
            sll $s4,$s4, 1
            bne $t1, 0, loop2
        move $t1, $s2

        beq $t1, $t0, print
        bgt $t1, $t0, method_1

    loop:
        div $t0, $t1
        mfhi $t2                #t0%t1
        mflo $t3                #t0/t1 = in the final, it will be gcd
        move $t4, $t1
        move $t0, $t1
        move $t1, $t2
        beq $t2, 0, print
        j loop
    method_1:
        div $t1, $t0
        mfhi $t2                #t1%t0
        mflo $t3                #t1/t0 = in the final, it will be gcd
        move $t4, $t0
        move $t1, $t0
        move $t0, $t2
        beq $t2, 0, print
        j method_1

    print:
        li $v0, 4
        la $a0, gcd
        syscall

        move $t5, $t4
        move $a0, $t4
        li $v0, 1
        syscall
    exit:
        li $v0, 10
        syscall