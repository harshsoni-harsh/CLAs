.data
    val1: .float 3.1, 4.9, 5.4, 6.1, 7.5
    val2: .float 4.3, 9.3, 6.4, 2.5, 1.8
    val3: .float 0.0, 0.0, 0.0, 0.0, 0.0 
    space: .ascii " "

.text

    main:
        li $t5, 0
        la $t1, val1            #index1
        la $t4, val3            #index3
        la $t2, val2            #index2
        outer_loop:
            beq $t5, 5, exit
            addi $t5, $t5, 1
            l.s $f0, 0($t1)
            l.s $f1, 0($t2)
            addi $t1, $t1, 4
            addi $t1, $t1, 4
            mul.s $f0, $f0, $f0
            mul.s $f1, $f1, $f1
            add.s $f0, $f0, $f1

            li.s $f1, 9.0           #guess
            li $t3, 20          #times
            jal func
           
            s.s $f1, 0($t4)
            addi $t4, $t4, 4
            j outer_loop
        
        exit:
            jal print
            li $v0, 10		
            syscall
        
        print:
            li $t0, 5
            la $t4, val3            #index3
            print_loop:
                beq $t0, 0, e

                li $v0, 4
                la $a0, space
                syscall

                li		$v0, 2		# system call #2 - print float
                l.s		$f12, 0($t4)
                syscall						# execute

                addi $t4, $t4, 4
                addi $t0, $t0, -1
                j print_loop
            e:
                jr $ra

            func:
                bgt $t3, 0, recurse
                jr $ra

            recurse:
                addi $sp, $sp, -4       #for storing ra
                sw $ra, 0($sp)
                
                li.s $f4, 0.5
                mov.s $f2, $f1  #f1=xn
                div.s $f1, $f0, $f2  #a=f0
                add.s $f1, $f1, $f2
                mul.s $f1, $f1, $f4  #a=f0

                addi $t3, $t3, -1
                jal func
            
            exit_in:
                lw $ra, 0($sp)
                addi $sp, $sp, 4
                jr $ra
            