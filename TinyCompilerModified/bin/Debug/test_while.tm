* TINY Compilation to TM Code
* File: test_while.tm
* Standard prelude:
  0:     LD  6,0(0) 	load maxaddress from location 0
  1:     ST  0,0(0) 	clear location 0
* End of standard prelude.
  2:     IN  0,0,0 	read integer value
  3:     ST  0,0(5) 	read: store value
* -> assign
* -> Const
  4:    LDC  0,0(0) 	load const
* <- Const
  5:     ST  0,1(5) 	assign: store value
* <- assign
* -> assign
* -> Const
  6:    LDC  0,0(0) 	load const
* <- Const
  7:     ST  0,2(5) 	assign: store value
* <- assign
* while ->
* -> Op
* -> Id
  8:     LD  0,1(5) 	load id value
* <- Id
  9:     ST  0,0(6) 	op: push left
* -> Id
 10:     LD  0,0(5) 	load id value
* <- Id
 11:     LD  1,0(6) 	op: load left
 12:    SUB  0,1,0 	op <
 13:    JLT  0,2(7) 	br if true
 14:    LDC  0,0(0) 	false case
 15:    LDA  7,1(7) 	unconditional jmp
 16:    LDC  0,1(0) 	true case
* <- Op
* -> assign
* -> Op
* -> Id
 17:     LD  0,2(5) 	load id value
* <- Id
 18:     ST  0,0(6) 	op: push left
* -> Const
 19:    LDC  0,1(0) 	load const
* <- Const
 20:     LD  1,0(6) 	op: load left
 21:    ADD  0,1,0 	op +
* <- Op
 22:     ST  0,2(5) 	assign: store value
* <- assign
 23:    JEQ  0,-16(7) 	jquet: jmp back to body
* -> Id
 24:     LD  0,2(5) 	load id value
* <- Id
 25:    OUT  0,0,0 	write ac
* End of execution.
 26:   HALT  0,0,0 	
