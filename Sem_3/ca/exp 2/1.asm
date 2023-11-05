.data
    msg1: .asciiz "Enter the Number"
    msg2: .asciiz "The number is "
.globl main
.text
    main:
    #i = 1
    li $t1, 1
    #var = 2
    li $t2, 2
    for_i:
    #j = 1
    li $t3, 1 # $t3 =1
    #flag = 0
    li $t0, 0
    for_j:
    #k = j
    move $t4, $t3 # $t4 = $t3
    for_k:
    # a= j * j * j
    #a = $t5
    mul $t5, $t3, $t3
    #if a > i break la $a0, msg2
    bgt $t5, $t1, brk
    mul $t5, $t5, $t3
    #if a > i break
    bgt $t5, $t1, brk
    #b = k * k * k
    #b = $t6
    mul $t6, $t4, $t4
    #if a > i break
    bgt $t6, $t1, brk
    mul $t6, $t6, $t4
    #if a > i break
    bgt $t6, $t1, brk#a = a + b
    add $t5, $t5, $t6
    #if a > i break
    bgt $t5, $t1, brk
    #if a == i flag ++
    bne $t5, $t1, skip
    addi $t0, $t0, 1 # $t0 = $t1 + 0
    skip:
    beq $t0, $t2, exit
    #k++
    addi $t4, $t4, 1
    #k < i
    ble $t4, $t1, for_k
    brk:
    #j++
    addi $t3, $t3, 1
    #k < i
    ble $t3, $t1, for_j
    #i++
    addi $t1, $t1, 1
    jal for_i # jump to for_i
    exit:
    li $v0, 4
    la $a0, msg2
    syscall
    li $v0, 1
    move $a0, $t1
    syscall
    li $v0, 10
    syscall