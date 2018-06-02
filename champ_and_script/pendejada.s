.name "pendejada"
.comment "taco slayer"

startup:
	sti r1, %:live, %1
	sti r1, %:northwall, %1
	sti r1, %:southwall, %1
	sti r1, %:startup2, %1
	sti r1, %:startup3, %1
	ld %84, r3
	ld %97, r4
	ld %99, r5
	ld %111, r6
	ld %0, r2
	fork %:live

startup2:
	live %66
	lfork %1970

startup3:
	live %66
	fork %:southwall


northwall:
	live %66
	st r3, -155
	st r4, -155
	st r5, -155
	st r6, -155
	st r3, -155
	st r4, -155
	st r5, -155
	st r6, -155
	st r3, -155
	st r4, -155
	st r5, -155
	st r6, -155
	zjmp %:northwall

live:
	live %66
	aff r3
	aff r4
	aff r5
	aff r6
	zjmp %:live

southwall:
	live %66
	st r3, 77
	st r4, 77
	st r5, 77
	st r6, 77
	st r3, 77
	st r4, 77
	st r5, 77
	st r6, 77
	st r3, 77
	st r4, 77
	st r5, 77
	st r6, 77
	zjmp %:southwall
