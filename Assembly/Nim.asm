core_strategy:
	; Check number of cards
	in r1 ; num cards
	cmp r1, 12
	je game_start ; if 12 cards, take 3
	
	mov r2, 5 ; 5 in register 2
	cmp r1, r2 ; compare card number to 5
	ja mid_game; if above 5, take down to 5
	
	; at this point the opponent should have done their 5 turn
	; meaning they could leave 1, 2, or 3 cards aside from the joker
	jmp winning_move
	
game_start:
	out 3
	jmp core_strategy

mid_game:
	sub r3, r1, r2 ; subtract 5 from card count and store in r3
	out r3 ; output the difference as the move, opponent will now have 5
	jmp core_strategy
	
winning_move:
	sub r2, r1, 1 ; subtract the joker
	out r2 ; output remaining cards