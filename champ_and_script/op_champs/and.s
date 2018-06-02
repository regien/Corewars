.name "and"
.comment "preforms a binary 'and' between the first two arguments and stores the
result in the third argument (the first two arguments can be anything, the
third argument is always a registry)"

setup:
	ld %5, r2
	ld %3, r3

andregs:
	and r2, r3, r4

displayvals:
	st r2, 27
	st r3, 28
	st r4, 29

jump:
	and r5, %0, r5
	zjmp %:jump