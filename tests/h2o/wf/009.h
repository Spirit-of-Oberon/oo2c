/* Test conditional macros */
#define ONE
#define YES
#ifdef ONE
1
#ifdef YES
yes
#else
no
#endif
#else
0
#ifdef YES
yes
#else
no
#endif
#endif
#undef ONE
#ifdef ONE
1
#ifdef YES
yes
#else
no
#endif
#else
0
#ifdef YES
yes
#else
no
#endif
#endif
