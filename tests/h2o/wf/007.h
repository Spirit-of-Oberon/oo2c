/* Test undefinition */
#define foo 1
begin
foo
#undef foo
foo
end
