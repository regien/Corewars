.name "zork"
.comment "I'M ALIIIIVE"


 l2:		aff r5 #whatvs
live %:live
		zjmp %:live
		and r1, %2, r4
		lldi %4, %5, r4
		ld 4, r5
live:	live %:l2
		zjmp %:live

   
