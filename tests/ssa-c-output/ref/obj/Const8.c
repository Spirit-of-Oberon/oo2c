#include <Const8.d>
#include <__oo2c.h>
#include <setjmp.h>

static void Const8__Tand(OOC_CHAR8 b) {
  register OOC_INT32 i0;

  i0 = b;
  if (i0) goto l3;
  Out0__String("FALSE ", 7);
  goto l4;
l3:
  Out0__String("TRUE ", 6);
l4:
  return;
  ;
}

static void Const8__Fand(OOC_CHAR8 b) {

  Out0__String("FALSE ", 7);
  return;
  ;
}

static void Const8__Tor(OOC_CHAR8 b) {

  Out0__String("TRUE ", 6);
  return;
  ;
}

static void Const8__For(OOC_CHAR8 b) {
  register OOC_INT32 i0;

  i0 = b;
  if (i0) goto l3;
  Out0__String("FALSE ", 7);
  goto l4;
l3:
  Out0__String("TRUE ", 6);
l4:
  return;
  ;
}

void Const8__Test() {

  Const8__Tand(1u);
  Const8__Tand(0u);
  Out0__Ln();
  Const8__Fand(1u);
  Const8__Fand(0u);
  Out0__Ln();
  Const8__Tor(1u);
  Const8__Tor(0u);
  Out0__Ln();
  Const8__For(1u);
  Const8__For(0u);
  Out0__Ln();
  return;
  ;
}

void OOC_Const8_init(void) {

  return;
  ;
}

/* --- */
