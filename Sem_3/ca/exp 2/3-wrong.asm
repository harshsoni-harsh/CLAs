.data
    ask: .asciiz "Enter a binary number: "
    result: .asciiz "number of sequences: "
.text
    main:
        li $v0, 4
        la $a0, ask
        syscall

        li $v0, 5
        syscall
        move $t0, $v0

    li $s2, 0                   #prev
    li $s3, 1                   #sample
    li $s0, 2
    li $s4, 0                   #count
        div $t0, $s0
        mfhi $s1
        beq $s1, 0, continue
        addi $s4, $s4, 1
        j continue
    loop:
        div $t0, $s0
        mfhi $s1                #modulo
        beq $s1, $s2, continue
        beq $s1, 0, continue
        addi $s4, $s4, 1
    continue:
        mfhi $s2
        mflo $t0
        bne $t0, 0, loop

    print:
        li $v0, 4
        la $a0, result
        syscall

        move $a0, $s4
        li $v0, 1
        syscall
    exit:
        li $v0, 10
        syscall