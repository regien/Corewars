.name "lldi"
.comment "lldi: Short for Long Load index, this operation takes three arguments,
it adds the first two arguments and saves the value at the address of that sum
(four bytes starting from the sum) into a registry (the first argumet can be
anything, the second argument can be either a direct or a registry, the third
argument is always a registry)(is not affected by IND_MOD, change values to see
this in effect)."

setregs:
	sti r1, %:live, %1
	ld %1, r2
	ld %0, r3

lldi:
	# lldi r2, r3, r4
	# lldi r2, %1, r4
	lldi -4, r3, r4

display:
	st r4, 22
	
prep4zjmp:
	and r5, %1111638594, r5

live:
	live %42
	zjmp %:live
