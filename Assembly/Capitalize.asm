mov r2, 32

; caps first letter of sentence
in r1
sub r3, r1, 32
out r3

; Receive input
loop:
	in r1
	cmp r1, r2 ; If value is 32, turn on flag
	je space
	out r1
	jmp loop

; On next iteration, subtract 32 from the input and turn flag off.
space: 
	out r1
	in r1
	sub r3, r1, 32
	out r3
	jmp loop