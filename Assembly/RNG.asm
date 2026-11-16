const seed = r1
const temp1 = r3
const temp2 = r4
const result = r5

in r1

loop:
	lsr r2, seed, 13
	xor temp1, r1, r2
	lsl r2, r3, 17
	xor temp2, r2, r3
	lsr r2, r4, 5
	xor seed, r2, r4
	xor result, r2, r4
	out result
	jmp loop	
