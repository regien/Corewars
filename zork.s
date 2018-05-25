.name "zork"
.comment "I'M ALIIIIVE"
        

 l2:		aff r5 #whatvs
live %:live
		zjmp %5
		and r1, %2, r4
#blessed
		lldi %4, %5, r4
		ld 4, r5
live:	live %:l2

   
