#include <URI/CharClass.d>
#include <__oo2c.h>
#include <setjmp.h>

OOC_CHAR8 URI_CharClass__IsAlpha(OOC_CHAR8 ch) {
  register OOC_INT32 i0,i1;

  i0 = ch;
  i0 = _cap(i0);
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

OOC_CHAR8 URI_CharClass__SkipAlpha(const OOC_CHAR8 str[], OOC_LEN str_0d, OOC_INT16 *pos) {
  register OOC_INT32 i0,i1;

  i0 = *pos;
  i1 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, str_0d, OOC_UINT16, 2211)));
  i1 = (OOC_UINT8)65u<=(OOC_UINT8)(_cap(i1));
  if (i1) goto l3;
  i1=0u;
  goto l5;
l3:
  i1 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, str_0d, OOC_UINT16, 2230)));
  i1 = (OOC_UINT8)(_cap(i1))<=(OOC_UINT8)90u;
  
l5:
  if (i1) goto l7;
  return 0u;
  goto l8;
l7:
  *pos = (i0+1);
  return 1u;
l8:
  _failed_function(2111); return 0;
  ;
}

OOC_CHAR8 URI_CharClass__IsDigit(OOC_CHAR8 ch) {
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

OOC_CHAR8 URI_CharClass__SkipDigit(const OOC_CHAR8 str[], OOC_LEN str_0d, OOC_INT16 *pos) {
  register OOC_INT32 i0,i1;

  i0 = *pos;
  i1 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, str_0d, OOC_UINT16, 2545)));
  i1 = (OOC_UINT8)48u<=(OOC_UINT8)i1;
  if (i1) goto l3;
  i1=0u;
  goto l5;
l3:
  i1 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, str_0d, OOC_UINT16, 2558)));
  i1 = (OOC_UINT8)i1<=(OOC_UINT8)57u;
  
l5:
  if (i1) goto l7;
  return 0u;
  goto l8;
l7:
  *pos = (i0+1);
  return 1u;
l8:
  _failed_function(2450); return 0;
  ;
}

OOC_CHAR8 URI_CharClass__IsAlphaNum(OOC_CHAR8 ch) {
  register OOC_INT32 i0,i1;

  i0 = ch;
  i1 = URI_CharClass__IsAlpha(i0);
  if (i1) goto l3;
  i0 = URI_CharClass__IsDigit(i0);
  
  goto l4;
l3:
  i0=1u;
l4:
  return i0;
  ;
}

OOC_CHAR8 URI_CharClass__SkipAlphaNum(const OOC_CHAR8 str[], OOC_LEN str_0d, OOC_INT16 *pos) {
  register OOC_INT32 i0;

  i0 = URI_CharClass__SkipAlpha((void*)(OOC_INT32)str, str_0d, (void*)(OOC_INT32)pos);
  if (i0) goto l3;
  i0 = URI_CharClass__SkipDigit((void*)(OOC_INT32)str, str_0d, (void*)(OOC_INT32)pos);
  
  goto l4;
l3:
  i0=1u;
l4:
  return i0;
  ;
}

OOC_CHAR8 URI_CharClass__IsMember(OOC_CHAR8 ch, const OOC_CHAR8 set__ref[], OOC_LEN set_0d) {
  register OOC_INT32 i0,i1,i2;
  OOC_ALLOCATE_VPAR(set,OOC_CHAR8 ,set_0d)

  OOC_INITIALIZE_VPAR(set__ref,set,OOC_CHAR8 ,set_0d)
  i0 = *(OOC_UINT8*)((OOC_INT32)set+(_check_index(0, set_0d, OOC_UINT16, 3060)));
  i0 = i0!=0u;
  if (i0) goto l3;
  i0=0u;
  goto l5;
l3:
  i0 = *(OOC_UINT8*)((OOC_INT32)set+(_check_index(0, set_0d, OOC_UINT16, 3076)));
  i1 = ch;
  i0 = i0!=i1;
  
l5:
  if (i0) goto l7;
  i0=0;
  goto l17;
l7:
  i0 = ch;
  i1=0;
l8_loop:
  i1 = i1+1;
  i2 = *(OOC_UINT8*)((OOC_INT32)set+(_check_index(i1, set_0d, OOC_UINT16, 3060)));
  i2 = i2!=0u;
  if (i2) goto l11;
  i2=0u;
  goto l13;
l11:
  i2 = *(OOC_UINT8*)((OOC_INT32)set+(_check_index(i1, set_0d, OOC_UINT16, 3076)));
  i2 = i2!=i0;
  
l13:
  if (i2) goto l8_loop;
l16:
  i0=i1;
l17:
  i0 = *(OOC_UINT8*)((OOC_INT32)set+(_check_index(i0, set_0d, OOC_UINT16, 3127)));
  return (i0!=0u);
  ;
}

OOC_CHAR8 URI_CharClass__IsReserved(OOC_CHAR8 ch) {
  register OOC_INT32 i0;

  i0 = ch;
  i0 = URI_CharClass__IsMember(i0, ";/?:@&=+$,[]", 13);
  return i0;
  ;
}

OOC_CHAR8 URI_CharClass__SkipReserved(const OOC_CHAR8 str[], OOC_LEN str_0d, OOC_INT16 *pos) {
  register OOC_INT32 i0,i1;

  i0 = *pos;
  i1 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, str_0d, OOC_UINT16, 3369)));
  i1 = URI_CharClass__IsMember(i1, ";/?:@&=+$,[]", 13);
  if (i1) goto l3;
  return 0u;
  goto l4;
l3:
  *pos = (i0+1);
  return 1u;
l4:
  _failed_function(3269); return 0;
  ;
}

OOC_CHAR8 URI_CharClass__IsMark(OOC_CHAR8 ch) {
  register OOC_INT32 i0;

  i0 = ch;
  switch (i0) {
  case 45u:
  case 95u:
  case 46u:
  case 33u:
  case 126u:
  case 42u:
  case 39u:
  case 40u:
  case 41u:
    return 1u;
    goto l4;
  default:
    return 0u;
    goto l4;
  }
l4:
  _failed_function(3493); return 0;
  ;
}

OOC_CHAR8 URI_CharClass__SkipMark(const OOC_CHAR8 str[], OOC_LEN str_0d, OOC_INT16 *pos) {
  register OOC_INT32 i0,i1;

  i0 = *pos;
  i1 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, str_0d, OOC_UINT16, 3769)));
  i1 = URI_CharClass__IsMark(i1);
  if (i1) goto l3;
  return 0u;
  goto l4;
l3:
  *pos = (i0+1);
  return 1u;
l4:
  _failed_function(3675); return 0;
  ;
}

OOC_CHAR8 URI_CharClass__IsUnreserved(OOC_CHAR8 ch) {
  register OOC_INT32 i0,i1;

  i0 = ch;
  i1 = URI_CharClass__IsAlphaNum(i0);
  if (i1) goto l3;
  i0 = URI_CharClass__IsMark(i0);
  
  goto l4;
l3:
  i0=1u;
l4:
  return i0;
  ;
}

OOC_CHAR8 URI_CharClass__SkipUnreserved(const OOC_CHAR8 str[], OOC_LEN str_0d, OOC_INT16 *pos) {
  register OOC_INT32 i0;

  i0 = URI_CharClass__SkipAlphaNum((void*)(OOC_INT32)str, str_0d, (void*)(OOC_INT32)pos);
  if (i0) goto l3;
  i0 = URI_CharClass__SkipMark((void*)(OOC_INT32)str, str_0d, (void*)(OOC_INT32)pos);
  
  goto l4;
l3:
  i0=1u;
l4:
  return i0;
  ;
}

OOC_CHAR8 URI_CharClass__SkipEscaped(const OOC_CHAR8 str[], OOC_LEN str_0d, OOC_INT16 *pos) {
  register OOC_INT32 i0,i1;
  auto OOC_CHAR8 URI_CharClass__SkipEscaped_SkipHex(OOC_CHAR8 ch);
    
    OOC_CHAR8 URI_CharClass__SkipEscaped_SkipHex(OOC_CHAR8 ch) {
      register OOC_INT32 i0,i1;

      i0 = ch;
      i1 = (OOC_UINT8)48u<=(OOC_UINT8)i0;
      if (i1) goto l3;
      i1=0u;
      goto l5;
l3:
      i1 = (OOC_UINT8)i0<=(OOC_UINT8)57u;
      
l5:
      if (i1) goto l11;
      i0 = _cap(i0);
      i1 = (OOC_UINT8)65u<=(OOC_UINT8)i0;
      if (i1) goto l9;
      i0=0u;
      goto l12;
l9:
      i0 = (OOC_UINT8)i0<=(OOC_UINT8)70u;
      
      goto l12;
l11:
      i0=1u;
l12:
      return i0;
      ;
    }


  i0 = *pos;
  i1 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, str_0d, OOC_UINT16, 4405)));
  i1 = i1==37u;
  if (i1) goto l3;
  i1=0u;
  goto l5;
l3:
  i1 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index((i0+1), str_0d, OOC_UINT16, 4432)));
  i1 = URI_CharClass__SkipEscaped_SkipHex(i1);
  
l5:
  if (i1) goto l7;
  i1=0u;
  goto l9;
l7:
  i1 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index((i0+2), str_0d, OOC_UINT16, 4455)));
  i1 = URI_CharClass__SkipEscaped_SkipHex(i1);
  
l9:
  if (i1) goto l11;
  return 0u;
  goto l12;
l11:
  *pos = (i0+3);
  return 1u;
l12:
  _failed_function(4168); return 0;
  ;
}

OOC_CHAR8 URI_CharClass__SkipPChar(const OOC_CHAR8 str[], OOC_LEN str_0d, OOC_INT16 *pos) {
  register OOC_INT32 i0,i1;

  i0 = *pos;
  i1 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, str_0d, OOC_UINT16, 4670)));
  i1 = URI_CharClass__IsMember(i1, ":@&=+$,", 8);
  if (i1) goto l7;
  i0 = URI_CharClass__SkipUnreserved((void*)(OOC_INT32)str, str_0d, (void*)(OOC_INT32)pos);
  if (i0) goto l5;
  i0 = URI_CharClass__SkipEscaped((void*)(OOC_INT32)str, str_0d, (void*)(OOC_INT32)pos);
  
  goto l6;
l5:
  i0=1u;
l6:
  return i0;
  goto l8;
l7:
  *pos = (i0+1);
  return 1u;
l8:
  _failed_function(4573); return 0;
  ;
}

OOC_CHAR8 URI_CharClass__SkipURIC(const OOC_CHAR8 str[], OOC_LEN str_0d, OOC_INT16 *pos) {
  register OOC_INT32 i0;

  i0 = URI_CharClass__SkipUnreserved((void*)(OOC_INT32)str, str_0d, (void*)(OOC_INT32)pos);
  if (i0) goto l3;
  i0 = URI_CharClass__SkipReserved((void*)(OOC_INT32)str, str_0d, (void*)(OOC_INT32)pos);
  
  goto l5;
l3:
  i0=1u;
l5:
  if (i0) goto l7;
  i0 = URI_CharClass__SkipEscaped((void*)(OOC_INT32)str, str_0d, (void*)(OOC_INT32)pos);
  
  goto l8;
l7:
  i0=1u;
l8:
  return i0;
  ;
}

OOC_CHAR8 URI_CharClass__SkipMember(const OOC_CHAR8 str[], OOC_LEN str_0d, OOC_INT16 *pos, const OOC_CHAR8 set__ref[], OOC_LEN set_0d) {
  register OOC_INT32 i0,i1;
  OOC_ALLOCATE_VPAR(set,OOC_CHAR8 ,set_0d)

  OOC_INITIALIZE_VPAR(set__ref,set,OOC_CHAR8 ,set_0d)
  i0 = *pos;
  i1 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, str_0d, OOC_UINT16, 5200)));
  i1 = URI_CharClass__IsMember(i1, (void*)(OOC_INT32)set, set_0d);
  if (i1) goto l3;
  return 0u;
  goto l4;
l3:
  *pos = (i0+1);
  return 1u;
l4:
  _failed_function(5059); return 0;
  ;
}

OOC_CHAR8 URI_CharClass__SkipAuthChar(const OOC_CHAR8 str[], OOC_LEN str_0d, OOC_INT16 *pos) {
  register OOC_INT32 i0;

  i0 = URI_CharClass__SkipUnreserved((void*)(OOC_INT32)str, str_0d, (void*)(OOC_INT32)pos);
  if (i0) goto l3;
  i0 = URI_CharClass__SkipEscaped((void*)(OOC_INT32)str, str_0d, (void*)(OOC_INT32)pos);
  
  goto l5;
l3:
  i0=1u;
l5:
  if (i0) goto l7;
  i0 = URI_CharClass__SkipMember((void*)(OOC_INT32)str, str_0d, (void*)(OOC_INT32)pos, "$,;:@&=+", 9);
  
  goto l8;
l7:
  i0=1u;
l8:
  return i0;
  ;
}

void OOC_URI_CharClass_init(void) {

  return;
  ;
}

void OOC_URI_CharClass_destroy(void) {
}

/* --- */
