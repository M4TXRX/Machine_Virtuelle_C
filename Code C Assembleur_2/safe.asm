	pushi 1
	push	0	0
	eq
	push	4	2
	and
	pushi	128
	push	5	0
	gt
	and
	jz	suite0
	pushi	0
	pop	0
	pushi	1
	pop	1
suite0:
	pushi	1
	push	1	0
	eq
	push	4	2
	and
	pushi	128
	push	5	0
	lt
	and
	jz	suite1
	pushi	0
	pop	1
	pushi	1
	pop	2
suite1:
	pushi	1
	push	2	0
	eq
	push	4	2
	and
	pushi	128
	push	5	0
	gt
	and
	jz	suite2
	pushi	0
	pop	2
	pushi	1
	pop	3
suite2:
	pushi	1
	push	3	0
	eq
	push	4	2
	and
	pushi	128
	push	5	0
	lt
	and
	jz	suite3
	pushi	0
	pop	3
	pushi	1
	pop	0
suite3:
	halt
	end
