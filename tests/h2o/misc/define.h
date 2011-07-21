#define one 1
#define two (one + one) 
#define add(a,b) (a + b)
#define foo foo
#define bar bar
#undef bar
#define bar
"one"
one
"two"
two
"add(1,2)"
add(1,2)
"add(one,one)"
add(one,one)
"add(two,two)"
add(two,two)
"bar"
bar
"finish"
