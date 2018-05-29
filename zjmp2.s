.name "name"
.comment "comment"

live:	live %1
		zjmp %:live

ld:		ld	%0, r2
		zjmp %:ld

ld:		ld	%1, r3
		zjmp %:ld

st:		st	r2, %-500
		zjmp %:st

st:		st	r3, %-500
		zjmp %:st

add:	add	r2, r3, r4
		zjmp %:add

add:	add	r5, r6, r7
		zjmp %:add

sub:	sub r2, r3, r5
		zjmp %:sub

and:	and 1, 1, r6
		zjmp %:and
		
or:		or	2, 1, r7
		zjmp %:or

xor:	xor 1, 2, r8
		zjmp %:xor

zjmp:	zjmp %0
		zjmp %:zjmp

ldi:	ldi %1
		zjmp %:ldi

sti:	sti %1
		zjmp %:sti

fork:	fork %1
		zjmp %:fork

lld:	lld %1
		zjmp %:lld

lldi:	lldi %1
		zjmp %:lldi

lfork:	lfork %1
		zjmp %:lfork

aff:	aff	 %1
		zjmp %:aff


