const i = r3
const j = r4
const ptr1 = r5
const ptr2 = r6

input:
	in r1
	add ptr1, i, memory
	store_8 [ptr1], r1
	add i, i, 1
	cmp i, 16
	jne input
	
mov i, 0
add j, i, 1
		
sort:
	add ptr1, i, memory
	add ptr2, j, memory
	load_8 r1, [ptr1]
	load_8 r2, [ptr2]
	cmp r1, r2
	jb swap_end
	
swap:
	store_8 [ptr1], r2
	store_8 [ptr2], r1
	
swap_end:
	add j, j, 1
	cmp j, 16
	jb sort
	add i, i, 1
	add j, i, 1
	cmp i, 15
	jb sort
	mov i, 0
	
output:
	add ptr1, i, memory
	load_8 r1, [ptr1]
	out r1
	add i, i, 1
	cmp i, 16
	jne output
	
memory: