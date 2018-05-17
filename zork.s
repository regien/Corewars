.name "zork"
.comment "I'M ALIIIIVE"

	
l2:		aff r5
		live %2
		and r1, %2, r3	
		lldi %4, %5, r4
live:	live %1
		zjmp %:live
