.name "lld"
.comment "lld: short for long load, this operation takes two arguments, it loads the
value of the first argument into the second argument which is always a registry
this function however is not affected by IND_MOD (the first argument can be a
direct or indirect and the second value is always a registry)(run with another
champion to see how it copies the first two bytes)."

loadval:
	lld 2048, r2

display:
	st r2, 17

jump:
	and r3, %0, r3
	zjmp %:jump
