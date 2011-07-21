/* Test redefinition */
#define foo 1
begin
foo
#define foo 2
foo
#define foo foo
foo
#define foo
foo
end
