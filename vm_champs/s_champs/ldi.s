.name "tacos"
.comment "forever ese"

#first params: REG | DIR | IND 
#second params: DIR | REG
#third param: REG
pendejada:	
			ld %5, r2
			ldi r1, %-1, r2
			ldi	r1, r9, r3
			
			ldi %-2, %2, r4
			ldi %-4097, r10, r5

			ldi -9, %512, r6
#			4245686019  -4519
			ldi -4135, r16, r7

			st r2,	500
			st r3,	500
			st r4,	500
			st r5,	500
			st r6,	500
			st r7,	500

#storing:	sti r2,
#			sti r3
#			sti r4
#			sti r5
#			sti r6
#			sti r7
