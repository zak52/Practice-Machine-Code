.data

array1: .space 40  # make an empty 10 element array
NewLine: .asciiz "\n"

.text
addi $t0, $zero, 0
li $t1, 23 
sw $t1, array1($t0) 
addi $t0, $t0, 4
li $t1, 15 
sw $t1, array1($t0)
addi $t0, $t0, 4
li $t1, 7 
sw $t1, array1($t0)
addi $t0, $t0, 4
li $t1, 10
sw $t1, array1($t0)
addi $t0, $t0, 4
li $t1, 18
sw $t1, array1($t0)
addi $t0, $t0, 4
li $t1, 13
sw $t1, array1($t0)
addi $t0, $t0, 4
li $t1, 20
sw $t1, array1($t0)
addi $t0, $t0, 4
li $t1, 53
sw $t1, array1($t0)
addi $t0, $t0, 4
li $t1, 22
sw $t1, array1($t0)
addi $t0, $t0, 4
li $t1, 42
sw $t1, array1($t0)
addi $t0, $t0, 4
li $t0, 0


addi $t0, $zero, 0

main:
	jal print
	jal sort
	jal print
	
	li $v0, 10 # code for 'exit'
	syscall
	
print:
	while:
		beq $t0, 40, exit
	
		lw $t6, array1($t0)
	
		addi $t0, $t0, 4
	
		# Prints the number.
		li $v0, 1
		move $a0, $t6
		syscall
	
		# Prints a new line.
		li $v0, 4
		la $a0, NewLine
		syscall
	
	
		j while
	
	exit:
	
	li $v0, 4
	la $a0, NewLine
	syscall
	
	jr $ra
	
sort:
	addi $t0, $zero, 0 # counter for array
	addi $t3, $zero, 0
	addi $t3, $t3, 4
	addi, $t2, $zero, 0 # 1 = true or 0 = false 
	
	sortloop:
		beq $t3, 40, reset
		lw $t5, array1($t0)
		lw $t6, array1($t3)
	
	
		blt $t6, $t5, swap
		addi $t0, $t0, 4
		addi $t3, $t3, 4
		j sortloop

	reset:
		beq $t2, 0, finalExit
		addi $t0, $zero, 0 # counter for array
		addi $t3, $zero, 0
		addi $t3, $t3, 4
		addi $t2, $zero, 0 # 1 = true or 0 = false 

		j sortloop


	swap:
		sw $t6, array1($t0)
		sw $t5, array1($t3) 
		addi $t2, $zero, 0
		addi $t2, $t2, 1
		addi $t0, $t0, 4
		addi $t3, $t3, 4
		j sortloop

	finalExit:
	addi $t0, $zero, 0
	jr $ra