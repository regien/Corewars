.name "aff"
.comment "aff: print argument's value to stdout when called, only prints if the
aff option is on"

setup:
	ld %70, r1
	ld %117, r2
	ld %99, r3
	ld %107, r4
	ld %32, r5
	ld %116, r6
	ld %104, r7
	ld %105, r8
	ld %115, r9
	ld %121, r10
	ld %111, r11
	ld %33, r13

hmm:
	aff r1
	aff r2
	aff r3
	aff r4
	aff r5
	aff r6
	aff r7
	aff r8
	aff r9
	aff r5
	aff r1
	aff r2
	aff r3
	aff r4
	aff r5
	aff r10
	aff r11
	aff r2
	aff r13
