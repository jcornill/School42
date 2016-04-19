.name "zork"
.comment "I'M ALIIIIVE"

l2:
	sti		r1, %:live, %1
	and		r1, %0, r1

live:
	live	%1
	ld		%10, r2
	st		r2, -31
	ld		%0, r2
	st		r2, -48
	ld		%0, r2
	st		r2, -65
	ld		%0, r2
	st		r2, -82
	ld		%0, r2
	st		r2, -99
	ld		%0, r3
	st		r3, 8
	zjmp	%:live
