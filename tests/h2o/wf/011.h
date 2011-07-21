/* Test expression evaluation */
#if 1+2*3-10/2 == 2
true
#else
false
#endif
#if 1 && 2
true
#else
false
#endif
#if 1 || foo
true
#else
false
#endif
#if !defined(foo)
true
#else
false
#endif
#define foo
#if defined foo
true
#else
false
#endif
