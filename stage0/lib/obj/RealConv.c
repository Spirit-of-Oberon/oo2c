#include <RealConv.d>
#include <__oo2c.h>
#include <setjmp.h>

void RealConv__ScanReal(OOC_CHAR8 inputCh, OOC_INT8 *chClass, ConvTypes__ScanState *nextState) {
  register OOC_INT32 i0;

  i0 = inputCh;
  Real0__ScanReal(i0, (void*)(OOC_INT32)chClass, (void*)(OOC_INT32)nextState);
  return;
  ;
}

OOC_INT8 RealConv__FormatReal(const OOC_CHAR8 str__ref[], OOC_LEN str_0d) {
  register OOC_INT32 i0;
  OOC_ALLOCATE_VPAR(str,OOC_CHAR8 ,str_0d)

  OOC_INITIALIZE_VPAR(str__ref,str,OOC_CHAR8 ,str_0d)
  i0 = Real0__FormatReal((void*)(OOC_INT32)str, str_0d, 38, (OOC_CHAR8*)"340282347", 10);
  return i0;
  ;
}

OOC_REAL32 RealConv__ValueReal(const OOC_CHAR8 str__ref[], OOC_LEN str_0d) {
  register OOC_INT32 i0,i1;
  register OOC_REAL32 f0;
  OOC_ALLOCATE_VPAR(str,OOC_CHAR8 ,str_0d)
  OOC_REAL32 value;

  OOC_INITIALIZE_VPAR(str__ref,str,OOC_CHAR8 ,str_0d)
  i0 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(0, str_0d, OOC_UINT32, 2407)));
  i0 = CharClass__IsWhiteSpace(i0);
  if (i0) goto l3;
  i0=0;
  goto l9;
l3:
  i0=0;
l4_loop:
  i0 = i0+1;
  i1 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, str_0d, OOC_UINT32, 2407)));
  i1 = CharClass__IsWhiteSpace(i1);
  if (i1) goto l4_loop;
l9:
  i0 = sscanf(((OOC_INT32)str+(_check_index(i0, str_0d, OOC_UINT32, 2518))), (OOC_CHAR8*)"%f", (OOC_INT32)&value);
  i0 = i0==1;
  if (i0) goto l12;
  return 0.0000000000000000f;
  goto l13;
l12:
  f0 = value;
  return f0;
l13:
  _failed_function(2215); return 0;
  ;
}

OOC_INT16 RealConv__LengthFloatReal(OOC_REAL32 real, OOC_INT16 sigFigs) {

  _assert(0u, 127, 2859);
  _failed_function(2763); 
  ;
}

OOC_INT16 RealConv__LengthEngReal(OOC_REAL32 real, OOC_INT16 sigFigs) {

  _assert(0u, 127, 3012);
  _failed_function(2918); 
  ;
}

OOC_INT16 RealConv__LengthFixedReal(OOC_REAL32 real, OOC_INT16 place) {

  _assert(0u, 127, 3163);
  _failed_function(3069); 
  ;
}

void OOC_RealConv_init(void) {

  return;
  ;
}

void OOC_RealConv_destroy(void) {
}

/* --- */
