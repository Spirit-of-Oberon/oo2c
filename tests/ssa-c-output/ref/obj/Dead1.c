#include <Dead1.d>
#include <__oo2c.h>
#include <setjmp.h>

static void Dead1__P(void) {
  register OOC_INT32 i0,i1;

  i0=0;
l1_loop:
  i0 = i0+1;
  i1 = i0<=9;
  if (i1) goto l1_loop;
l5:
  return;
  ;
}

void OOC_Dead1_init(void) {

  return;
  ;
}

/* --- */
