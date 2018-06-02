.name "fork"
.comment "fork creates a new process at the value given (relative to the
current position)(the only argument is a direct)"

setregs:
	sti r1, %:live, %1

live:
	live %42

prep4zjmp:
	and r4, %0, r4

fork:
	fork %:live
	zjmp %:live
