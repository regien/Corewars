.name "live"
.comment "live: takes one argument, it reports a value (its only argument) as
alive to the vm, it must be called by a process within CYCLES_TO_DIE cycles to
not be killed off (its only argument is a direct)"

putplayerval:
	sti r1, %:live, %1

setupzjmp:
	and r2, %0, r2

live:
	live %1111638594

jump:
	zjmp %:live
