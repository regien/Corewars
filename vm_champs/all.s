.name "all"
.comment ""

one:	live %1
two:	ld %:one, r1
three:	st r1, 500
four:	add r1, r2, r3
	st r3, 500
five:	sub r4, r1, r2
	st r4, 500
six:	and r1, r3, r5
	st r5, 500
seven:	or r1, r3, r6
	st r6, 500
eight:	xor r1, r3, r7
	st r7, 500
nine:	add r7, r2, r8

ten:	zjmp %:one
eleven:	ldi %:one, %:two , r11
twelve:	fork %500
thirteen:	lld %:one, r9
fourteen:	lldi %:one, %:two, r10
fifteen:	lfork %:one
sixteen:	aff r1
	
