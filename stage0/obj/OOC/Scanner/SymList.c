#include <OOC/Scanner/SymList.d>
#include <__oo2c.h>
#include <setjmp.h>

void OOC_Scanner_SymList__Init(OOC_Scanner_SymList__Builder b, OOC_Scanner_InputBuffer__Buffer buffer, OOC_CHAR8 includeDocComments) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)b;
  i1 = (OOC_INT32)buffer;
  *(OOC_INT32*)(_check_pointer(i0, 3116)) = i1;
  *(OOC_INT32*)((_check_pointer(i0, 3146))+4) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 3175))+8) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 3195))+12) = 0;
  i1 = includeDocComments;
  *(OOC_UINT8*)((_check_pointer(i0, 3215))+16) = i1;
  return;
  ;
}

OOC_Scanner_SymList__Builder OOC_Scanner_SymList__New(OOC_Scanner_InputBuffer__Buffer buffer, OOC_CHAR8 includeDocComments) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_Scanner_SymList__Builder.baseTypes[0]);
  i1 = (OOC_INT32)buffer;
  i2 = includeDocComments;
  OOC_Scanner_SymList__Init((OOC_Scanner_SymList__Builder)i0, (OOC_Scanner_InputBuffer__Buffer)i1, i2);
  return (OOC_Scanner_SymList__Builder)i0;
  ;
}

OOC_Scanner_SymList__Symbol OOC_Scanner_SymList__NewSymbol(OOC_Scanner_InputBuffer__CharArray str, OOC_INT32 len) {
  register OOC_INT32 i0,i1;
  OOC_Scanner_SymList__Symbol sym;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_Scanner_SymList__Symbol.baseTypes[0]);
  sym = (OOC_Scanner_SymList__Symbol)i0;
  *(OOC_INT32*)(_check_pointer(i0, 3590)) = 0;
  *(OOC_INT8*)((_check_pointer(i0, 3612))+4) = (-1);
  i1 = (OOC_INT32)str;
  *(OOC_INT32*)((_check_pointer(i0, 3631))+8) = i1;
  i1 = len;
  *(OOC_INT32*)((_check_pointer(i0, 3652))+12) = i1;
  *(OOC_INT32*)((_check_pointer(i0, 3673))+16) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 3692))+20) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 3712))+24) = 0;
  return (OOC_Scanner_SymList__Symbol)i0;
  ;
}

OOC_Scanner_SymList__Symbol OOC_Scanner_SymList__CloneSymbol(OOC_Scanner_SymList__Symbol old, const OOC_CHAR8 str__ref[], OOC_LEN str_0d) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_ALLOCATE_VPAR(str,OOC_CHAR8 ,str_0d)
  OOC_Scanner_SymList__Symbol sym;

  OOC_INITIALIZE_VPAR(str__ref,str,OOC_CHAR8 ,str_0d)
  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_Scanner_SymList__Symbol.baseTypes[0]);
  sym = (OOC_Scanner_SymList__Symbol)i0;
  *(OOC_INT32*)(_check_pointer(i0, 3891)) = 0;
  i1 = (OOC_INT32)old;
  i2 = *(OOC_INT8*)((_check_pointer(i1, 3924))+4);
  *(OOC_INT8*)((_check_pointer(i0, 3913))+4) = i2;
  i2 = Strings__Length((void*)(OOC_INT32)str, str_0d);
  *(OOC_INT32*)((_check_pointer(i0, 3937))+12) = i2;
  i2 = *(OOC_INT32*)((_check_pointer(i0, 3990))+12);
  *(OOC_INT32*)((_check_pointer(i0, 3980))+8) = ((OOC_INT32)RT0__NewObject(_td_OOC_Scanner_InputBuffer__CharArray.baseTypes[0], (i2+1)));
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4018))+8);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4018))+8);
  i3 = OOC_ARRAY_LENGTH((_check_pointer(i3, 4023)), 0);
  _copy_8((const void*)(OOC_INT32)str,(void*)(_check_pointer(i2, 4023)),i3);
  i2 = *(OOC_INT32*)((_check_pointer(i1, 4046))+16);
  *(OOC_INT32*)((_check_pointer(i0, 4034))+16) = i2;
  i2 = *(OOC_INT32*)((_check_pointer(i1, 4073))+20);
  *(OOC_INT32*)((_check_pointer(i0, 4060))+20) = i2;
  i1 = *(OOC_INT32*)((_check_pointer(i1, 4103))+24);
  *(OOC_INT32*)((_check_pointer(i0, 4088))+24) = i1;
  return (OOC_Scanner_SymList__Symbol)i0;
  ;
}

void OOC_Scanner_SymList__BuilderDesc_Clear(OOC_Scanner_SymList__Builder b) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)b;
  *(OOC_INT32*)((_check_pointer(i0, 4192))+8) = (OOC_INT32)0;
  *(OOC_INT32*)((_check_pointer(i0, 4212))+12) = (OOC_INT32)0;
  return;
  ;
}

void OOC_Scanner_SymList__BuilderDesc_AddSymbol(OOC_Scanner_SymList__Builder b, OOC_INT8 id, OOC_INT32 cstart, OOC_INT32 cend, OOC_INT32 line, OOC_INT32 column) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_Scanner_SymList__Symbol sym;
  OOC_INT32 len;

  i0 = id;
  i1 = i0<77;
  if (i1) goto l3;
  i1 = i0>80;
  
  goto l5;
l3:
  i1=1u;
l5:
  if (i1) goto l11;
  i1 = i0==78;
  if (i1) goto l9;
  i1=0u;
  goto l13;
l9:
  i1 = (OOC_INT32)b;
  i1 = *(OOC_UINT8*)((_check_pointer(i1, 5172))+16);
  
  goto l13;
l11:
  i1=1u;
l13:
  if (!i1) goto l19;
  i1 = (OOC_INT32)RT0__NewObject(_td_OOC_Scanner_SymList__Symbol.baseTypes[0]);
  sym = (OOC_Scanner_SymList__Symbol)i1;
  *(OOC_INT32*)(_check_pointer(i1, 5224)) = 0;
  *(OOC_INT8*)((_check_pointer(i1, 5248))+4) = i0;
  i0 = (OOC_INT32)b;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 5279));
  i2 = *(OOC_INT32*)((_check_pointer(i2, 5292))+8);
  i3 = cstart;
  *(OOC_INT32*)((_check_pointer(i1, 5269))+16) = (i2+i3);
  i2 = line;
  *(OOC_INT32*)((_check_pointer(i1, 5326))+20) = i2;
  i2 = column;
  i4 = cend;
  *(OOC_INT32*)((_check_pointer(i1, 5351))+24) = i2;
  i2 = i4-i3;
  len = i2;
  *(OOC_INT32*)((_check_pointer(i1, 5411))+8) = ((OOC_INT32)RT0__NewObject(_td_OOC_Scanner_InputBuffer__CharArray.baseTypes[0], (i2+1)));
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 5458));
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5471))+4);
  i0 = _check_pointer(i0, 5478);
  i4 = OOC_ARRAY_LENGTH(i0, 0);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 5523))+8);
  _move_block((i0+(_check_index(i3, i4, OOC_UINT32, 5478))),(_check_pointer(i1, 5528)),i2);
  i0 = (OOC_INT32)sym;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5547))+8);
  i1 = _check_pointer(i1, 5552);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i3 = len;
  *(OOC_UINT8*)(i1+(_check_index(i3, i2, OOC_UINT32, 5552))) = 0u;
  *(OOC_INT32*)((_check_pointer(i0, 5574))+12) = i3;
  i1 = (OOC_INT32)b;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 5606))+12);
  i2 = i2==0;
  if (i2) goto l17;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 5668))+12);
  *(OOC_INT32*)(_check_pointer(i2, 5674)) = i0;
  goto l18;
l17:
  *(OOC_INT32*)((_check_pointer(i1, 5634))+8) = i0;
l18:
  *(OOC_INT32*)((_check_pointer(i1, 5706))+12) = i0;
l19:
  return;
  ;
}

void OOC_Scanner_SymList__BuilderDesc_SetPragmaHistory(OOC_Scanner_SymList__Builder b, OOC_Config_Pragmas__History pragmaHistory) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)b;
  i1 = (OOC_INT32)pragmaHistory;
  *(OOC_INT32*)((_check_pointer(i0, 5878))+4) = i1;
  return;
  ;
}

void OOC_OOC_Scanner_SymList_init(void) {

  return;
  ;
}

/* --- */
