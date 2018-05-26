.name "hello"
.comment "world"

st 		r1, 500
ld 		500, r1
ld 		%67108864, r2
st 		r2, 100
lldi	%3, %2, r3
st 		r3, 500
ld 		%42, r4
aff 	r4
aff 	r4
aff 	r4
aff 	r4
aff 	r4
ld 		%0, r5
zjmp 	%-30
