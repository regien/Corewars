.name "st"
.comment "st: short for store, this operation take in two arguments, it stores
the value in the first argument, which is always a registry, into the second
argument, which can be a registry or indirect (the first argument is always a
registry, the second argument can be a registry or a indirect)."

stplayernum:
	st r1, 17

jump:
	and r2, %0, r2
	zjmp %:jump
