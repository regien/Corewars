.name "ld"
.comment "ld: short for load, this operation takes two arguments, it loads the
value of the first argument into the second argument which is always a registry
(the first argument can be a direct or indirect and the second value is always
a registry)."

# test positive direct, and indirect, and negative indirect. registers bounds.


loadval:
	ld 0, r2
#	ld 8184, r2
#	ld %513, r2
#	ld %-514, r2


display:
	st r2, -2

jump:
	and r3, %0, r3
	zjmp %:jump
