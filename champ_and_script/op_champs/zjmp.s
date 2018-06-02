.name "zjmp"
.comment "zjmp jumps the argument's value distance from the current process if
carry is zero (its only argument is a direct)"

jump:
	and r1, %0, r1
	zjmp %0
