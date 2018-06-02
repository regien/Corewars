.name "add"
.comment "add: this operation takes three arguments, it adds the value of the
first two arguments and saves the result in the third argument (all three 
arguments are registries)."

setup:
	ld %2, r2
	ld %3, r3

addregs:
	add r2, r3, r4

displayvals:
	st r2, 27
	st r3, 28
	st r4, 29

jump:
	and r5, %0, r5
	zjmp %:jump
