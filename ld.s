.name "ld"
.comment "ld: short for load, this operation takes two arguments, it loads the
value of the first argument into the second argument which is always a registry
(the first argument can be a direct or indirect and the second value is always
a registry)."

# test positive direct, and indirect, and negative indirect. registers bounds.


loadval:
	ld 1, r2
	ld 8192, r3
	ld %513, r4
	ld %-514, r5


display:
	st r2, 200
	st r3, 300
	st r4, 400
	st r5, 500
	st r5, r6
	st r6, -500

jump:
	and r3, %0, r3
	zjmp %:jump
