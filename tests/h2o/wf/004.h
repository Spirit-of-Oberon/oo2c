/* Test nested substitution with parameters */
#define add(x,y) (x+y)
begin
add(add(1,2),add(3,4))
end
