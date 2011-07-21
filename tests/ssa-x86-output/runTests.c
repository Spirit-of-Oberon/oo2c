#include <assert.h>
#include <stdio.h>

extern T0__f(int a);
extern T1__f(int a);
extern T2__f(int a, int b);
extern T3__f(unsigned char select, int a, int b);

int main(void) {
  char *str;
  
  /* T0__f: identity */
  assert(T0__f(0) == 0);
  assert(T0__f(1) == 1);
  assert(T0__f(-123) == -123);
  
  /* T1__f: negation */
  assert(T1__f(0) == 0);
  assert(T1__f(1) == -1);
  assert(T1__f(-123) == 123);
  
  /* T2__f: a - b */
  assert(T2__f(0, 0) == 0);
  assert(T2__f(1, 0) == 1);
  assert(T2__f(0, 1) == -1);
  assert(T2__f(12, -123) == 135);
  
  /* T3__f: select ? a+b : a - b */
  assert(T3__f(1, 0, 0) == 0);
  assert(T3__f(1, 1, 0) == 1);
  assert(T3__f(1, 0, 1) == 1);
  assert(T3__f(1, 12, -123) == -111);
  assert(T3__f(0, 0, 0) == 0);
  assert(T3__f(0, 1, 0) == 1);
  assert(T3__f(0, 0, 1) == -1);
  assert(T3__f(0, 12, -123) == 135);
  
  /* T4__f: as T3__f() */
  assert(T4__f(1, 0, 0) == 0);
  assert(T4__f(1, 1, 0) == 1);
  assert(T4__f(1, 0, 1) == 1);
  assert(T4__f(1, 12, -123) == -111);
  assert(T4__f(0, 0, 0) == 0);
  assert(T4__f(0, 1, 0) == 1);
  assert(T4__f(0, 0, 1) == -1);
  assert(T4__f(0, 12, -123) == 135);
  
  /* T5__f: |a-b| */
  assert(T5__f(5, 3) == 2);
  assert(T5__f(3, 5) == 2);
  
  /* T6__f: a & b */
  assert(T6__f(0, 0) == -9);
  assert(T6__f(0, 1) == -9);
  assert(T6__f(1, 0) == -9);
  assert(T6__f(1, 1) == 9);
  /* T6a__f: (a & b) & c */
  assert(T6a__f(0, 0, 0) == -9);
  assert(T6a__f(0, 0, 1) == -9);
  assert(T6a__f(0, 1, 0) == -9);
  assert(T6a__f(0, 1, 1) == -9);
  assert(T6a__f(1, 0, 0) == -9);
  assert(T6a__f(1, 0, 1) == -9);
  assert(T6a__f(1, 1, 0) == -9);
  assert(T6a__f(1, 1, 1) == 9);
  /* T6b__f: a & (b & c) */
  assert(T6b__f(0, 0, 0) == -9);
  assert(T6b__f(0, 0, 1) == -9);
  assert(T6b__f(0, 1, 0) == -9);
  assert(T6b__f(0, 1, 1) == -9);
  assert(T6b__f(1, 0, 0) == -9);
  assert(T6b__f(1, 0, 1) == -9);
  assert(T6b__f(1, 1, 0) == -9);
  assert(T6b__f(1, 1, 1) == 9);
  
  /* T7__f: a OR b */
  assert(T7__f(0, 0) == -9);
  assert(T7__f(0, 1) == 9);
  assert(T7__f(1, 0) == 9);
  assert(T7__f(1, 1) == 9);
  /* T7a__f: (a OR b) OR c */
  assert(T7a__f(0, 0, 0) == -9);
  assert(T7a__f(0, 0, 1) == 9);
  assert(T7a__f(0, 1, 0) == 9);
  assert(T7a__f(0, 1, 1) == 9);
  assert(T7a__f(1, 0, 0) == 9);
  assert(T7a__f(1, 0, 1) == 9);
  assert(T7a__f(1, 1, 0) == 9);
  assert(T7a__f(1, 1, 1) == 9);
  /* T7b__f: a OR (b OR c) */
  assert(T7b__f(0, 0, 0) == -9);
  assert(T7b__f(0, 0, 1) == 9);
  assert(T7b__f(0, 1, 0) == 9);
  assert(T7b__f(0, 1, 1) == 9);
  assert(T7b__f(1, 0, 0) == 9);
  assert(T7b__f(1, 0, 1) == 9);
  assert(T7b__f(1, 1, 0) == 9);
  assert(T7b__f(1, 1, 1) == 9);
  
  /* T8a__f: (a & b) OR c */
  assert(T8a__f(0, 0, 0) == -9);
  assert(T8a__f(0, 0, 1) == 9);
  assert(T8a__f(0, 1, 0) == -9);
  assert(T8a__f(0, 1, 1) == 9);
  assert(T8a__f(1, 0, 0) == -9);
  assert(T8a__f(1, 0, 1) == 9);
  assert(T8a__f(1, 1, 0) == 9);
  assert(T8a__f(1, 1, 1) == 9);
  /* T8b__f: a & (b OR c) */
  assert(T8b__f(0, 0, 0) == -9);
  assert(T8b__f(0, 0, 1) == -9);
  assert(T8b__f(0, 1, 0) == -9);
  assert(T8b__f(0, 1, 1) == -9);
  assert(T8b__f(1, 0, 0) == -9);
  assert(T8b__f(1, 0, 1) == 9);
  assert(T8b__f(1, 1, 0) == 9);
  assert(T8b__f(1, 1, 1) == 9);
  /* T8c__f: (a OR b) & c */
  assert(T8c__f(0, 0, 0) == -9);
  assert(T8c__f(0, 0, 1) == -9);
  assert(T8c__f(0, 1, 0) == -9);
  assert(T8c__f(0, 1, 1) == 9);
  assert(T8c__f(1, 0, 0) == -9);
  assert(T8c__f(1, 0, 1) == 9);
  assert(T8c__f(1, 1, 0) == -9);
  assert(T8c__f(1, 1, 1) == 9);
  /* T8d__f: a OR (b & c) */
  assert(T8d__f(0, 0, 0) == -9);
  assert(T8d__f(0, 0, 1) == -9);
  assert(T8d__f(0, 1, 0) == -9);
  assert(T8d__f(0, 1, 1) == 9);
  assert(T8d__f(1, 0, 0) == 9);
  assert(T8d__f(1, 0, 1) == 9);
  assert(T8d__f(1, 1, 0) == 9);
  assert(T8d__f(1, 1, 1) == 9);
  
  
  /* L1__f: len(str) */
  str = strdup(""); assert(L1__f(str, strlen(str)) == 0);
  str = strdup("a"); assert(L1__f(str, strlen(str)) == 1);
  str = strdup("ab"); assert(L1__f(str, strlen(str)) == 2);
  str = strdup("12345"); assert(L1__f(str, strlen(str)) == 5);
  
  /* C1__f: a-b */
  assert(C1__f(5, 3) == 2);
  
  printf("### All tests successful.\n");
  return 0;
}
