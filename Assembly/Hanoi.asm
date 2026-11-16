; First four inputs:
;	- disk_nr: highest number in pile
;	- source: what pile to start from
;	- destination: what pile to move to
;	- spare: the third spot

; Output Controls:
;	- 0: move magnet to 0
;	- 1: move magnet to 1
;	- 2: move magnet to 2
;	- 5: toggle pickup/drop

const disk_nr = r1
const src = r2
const dest = r3
const spare = r4

in disk_nr
in src
in dest
in spare

call move

done:
	jmp done

; func move(disk_nr, source, dest, spare) {
move:
	; if disk_nr is 0 {
	cmp disk_nr, 0
	je src_to_dest_0
	; } else {

	; move(disk_nr - 1, source, spare, dest)
	push disk_nr
	push src
	push dest
	push spare
		sub disk_nr, disk_nr, 1
		mov r5, dest
		mov dest, spare
		mov spare, r5
		call move
	pop spare
	pop dest
	pop src
	pop disk_nr
	
	; move disk from source to dest
	out src
	out 5
	out dest
	out 5
	
	; move(disk_nr - 1, spare, dest, source)
	push disk_nr
	push src
	push dest
	push spare
		sub disk_nr, disk_nr, 1
		mov r5, src
		mov src, spare
		mov spare, r5
		call move
	pop spare
	pop dest
	pop src
	pop disk_nr

	ret

;		move disk from source to dest
src_to_dest_0:
	out src
	out 5
	out dest
	out 5
	ret