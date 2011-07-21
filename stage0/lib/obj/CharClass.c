#include <CharClass.d>
#include <__oo2c.h>
#include <setjmp.h>

OOC_CHAR8 CharClass__IsNumeric(OOC_CHAR8 ch) {
  register OOC_INT32 i0,i1;

  i0 = ch;
  i1 = (OOC_UINT8)48u<=(OOC_UINT8)i0;
  if (i1) goto l3;
  i0=0u;
  goto l4;
l3:
  i0 = (OOC_UINT8)i0<=(OOC_UINT8)57u;
  
l4:
  return i0;
  ;
}

OOC_CHAR8 CharClass__IsLetter(OOC_CHAR8 ch) {
  register OOC_INT32 i0,i1;

  i0 = ch;
  i1 = (OOC_UINT8)97u<=(OOC_UINT8)i0;
  if (i1) goto l3;
  i1=0u;
  goto l5;
l3:
  i1 = (OOC_UINT8)i0<=(OOC_UINT8)122u;
  
l5:
  if (i1) goto l11;
  i1 = (OOC_UINT8)65u<=(OOC_UINT8)i0;
  if (i1) goto l9;
  i0=0u;
  goto l12;
l9:
  i0 = (OOC_UINT8)i0<=(OOC_UINT8)90u;
  
  goto l12;
l11:
  i0=1u;
l12:
  return i0;
  ;
}

OOC_CHAR8 CharClass__IsUpper(OOC_CHAR8 ch) {
  register OOC_INT32 i0,i1;

  i0 = ch;
  i1 = (OOC_UINT8)65u<=(OOC_UINT8)i0;
  if (i1) goto l3;
  i0=0u;
  goto l4;
l3:
  i0 = (OOC_UINT8)i0<=(OOC_UINT8)90u;
  
l4:
  return i0;
  ;
}

OOC_CHAR8 CharClass__IsLower(OOC_CHAR8 ch) {
  register OOC_INT32 i0,i1;

  i0 = ch;
  i1 = (OOC_UINT8)97u<=(OOC_UINT8)i0;
  if (i1) goto l3;
  i0=0u;
  goto l4;
l3:
  i0 = (OOC_UINT8)i0<=(OOC_UINT8)122u;
  
l4:
  return i0;
  ;
}

OOC_CHAR8 CharClass__IsControl(OOC_CHAR8 ch) {
  register OOC_INT32 i0;

  i0 = ch;
  return ((OOC_UINT8)i0<(OOC_UINT8)32u);
  ;
}

OOC_CHAR8 CharClass__IsWhiteSpace(OOC_CHAR8 ch) {
  register OOC_INT32 i0,i1;

  i0 = ch;
  i1 = i0==32u;
  if (i1) goto l3;
  i1 = i0==12u;
  
  goto l5;
l3:
  i1=1u;
l5:
  if (i1) goto l7;
  i1 = i0==10u;
  
  goto l9;
l7:
  i1=1u;
l9:
  if (i1) goto l11;
  i1 = i0==13u;
  
  goto l13;
l11:
  i1=1u;
l13:
  if (i1) goto l15;
  i1 = i0==9u;
  
  goto l17;
l15:
  i1=1u;
l17:
  if (i1) goto l19;
  i0 = i0==11u;
  
  goto l20;
l19:
  i0=1u;
l20:
  return i0;
  ;
}

OOC_CHAR8 CharClass__IsEol(OOC_CHAR8 ch) {
  register OOC_INT32 i0;

  i0 = ch;
  return (i0==10u);
  ;
}

void OOC_CharClass_init(void) {

  *(OOC_UINT8*)((OOC_INT32)CharClass__systemEol+(_check_index(0, 3, OOC_UINT8, 2971))) = 10u;
  *(OOC_UINT8*)((OOC_INT32)CharClass__systemEol+(_check_index(1, 3, OOC_UINT8, 2997))) = 0u;
  return;
  ;
}

/* --- */
