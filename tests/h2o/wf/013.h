#define paste2(x, y) x ## y
#define paste3(x, y, z) x ## y ## z
paste2(one,two)
paste3(one,two,three)
paste2(paste2(one,two),paste2(three,four))
