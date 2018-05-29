.name "lds"
.comment "que que que"

hi:	ld	%42, r2
zjmp	%:hi

bye: ld %1, r3
zjmp	%:bye

ld %-1, r4
#forsure: ld %0, r4

adddd:	add r3, r4, r7

hola:	st r2, 42
zjmp %:adddd

adios: st r3, 42
zjmp %:adios

#zjmp %:forsure
