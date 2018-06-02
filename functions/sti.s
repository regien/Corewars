.name "sti"
.comment "sti: Short for Store index, this operation takes three arguments,
stores the contents of the first argument at the address of the sum of the
of the sum of the second and third arguments (relative to the current
position)(the first argument is always a registry, the second argument can be
anything, and the third argument can be either a direct or a registry)."

setregs:
	sti r1, %:live, %1
	ld %52, r2
	ld %1, r3

sti:
	sti r2, r3, %22
	
prep4zjmp:
	and r5, %1111638594, r5

live:
	live %42
	zjmp %:live
