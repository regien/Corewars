.name "sub"
.comment "sub: this operation takes three arguments, it subtracts the second
value from the first argument and saves the result in the third argument (all
three arguments are registries)."

setup:
	ld %3, r2
	ld %2, r3

addregs:
	sub r2, r3, r4

displayvals:
	st r2, 27
	st r3, 28
	st r4, 29

jump:
	and r5, %0, r5
	zjmp %:jump
