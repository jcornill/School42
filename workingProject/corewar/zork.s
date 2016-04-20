.name "zork"
.comment "I'M ALIIIIVE"

init:
	sti		r1, %:live, %1
	and		r2, %0, r2
	ld		%57671680, r2
	st		r2, 38
	and		r3, %0, r3
	ld		%196617, r3
	and		r4, %0, r4

live:
	live	%1
	st		r3, 7
#	st		r2, 15
#	zjmp	%:live

#	live	%1
#	zjmp	%:live
