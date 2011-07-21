#include <OOC/SymbolTable.d>
#include <__oo2c.h>
#include <setjmp.h>

void OOC_SymbolTable__WriterDesc_INIT(OOC_SymbolTable__Writer w, IO__ByteChannel ch, IO__ByteChannel chDoc) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)chDoc;
  _assert((i0!=(OOC_INT32)0), 127, 45175);
  i1 = (OOC_INT32)w;
  i2 = (OOC_INT32)ch;
  ADT_Object_Storage__WriterDesc_INIT((ADT_Object_Storage__Writer)i1, (IO__ByteChannel)i2);
  i0 = (OOC_INT32)ADT_Object_Storage__ConnectWriter((IO__ByteChannel)i0);
  *(OOC_INT32*)((_check_pointer(i1, 45218))+280) = i0;
  return;
  ;
}

void OOC_SymbolTable__ReaderDesc_INIT(OOC_SymbolTable__Reader r, IO__ByteChannel ch, IO__ByteChannel chDoc) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)ch;
  i1 = (OOC_INT32)r;
  ADT_Object_Storage__ReaderDesc_INIT((ADT_Object_Storage__Reader)i1, (IO__ByteChannel)i0);
  i0 = (OOC_INT32)chDoc;
  i2 = i0==(OOC_INT32)0;
  if (i2) goto l3;
  i0 = (OOC_INT32)ADT_Object_Storage__ConnectReader((IO__ByteChannel)i0);
  *(OOC_INT32*)((_check_pointer(i1, 45424))+280) = i0;
  goto l4;
l3:
  *(OOC_INT32*)((_check_pointer(i1, 45389))+280) = (OOC_INT32)0;
l4:
  return;
  ;
}

void OOC_SymbolTable__InitNamespace(OOC_SymbolTable__Namespace ns) {

  return;
  ;
}

OOC_SymbolTable__Declaration OOC_SymbolTable__NamespaceDesc_IdentifyLocal2(OOC_SymbolTable__Namespace ns, OOC_SymbolTable__Item sourceContext, OOC_SymbolTable__Name name, OOC_CHAR8 ignorePosition, OOC_CHAR8 *baseNotExported) {

  _failed_function(45600); return 0;
  ;
}

OOC_SymbolTable__Declaration OOC_SymbolTable__NamespaceDesc_IdentifyLocal(OOC_SymbolTable__Namespace ns, OOC_SymbolTable__Item sourceContext, OOC_SymbolTable__Name name, OOC_CHAR8 ignorePosition) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_CHAR8 baseNotExported;

  baseNotExported = 0u;
  i0 = (OOC_INT32)ns;
  i1 = (OOC_INT32)sourceContext;
  i2 = (OOC_INT32)name;
  i3 = ignorePosition;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 47502)))), OOC_SymbolTable__NamespaceDesc_IdentifyLocal2)),OOC_SymbolTable__NamespaceDesc_IdentifyLocal2)((OOC_SymbolTable__Namespace)i0, (OOC_SymbolTable__Item)i1, (OOC_SymbolTable__Name)i2, i3, (void*)(OOC_INT32)&baseNotExported);
  return (OOC_SymbolTable__Declaration)i0;
  ;
}

OOC_SymbolTable__Declaration OOC_SymbolTable__NamespaceDesc_Identify2(OOC_SymbolTable__Namespace ns, OOC_SymbolTable__Item sourceContext, OOC_SymbolTable__Name name, OOC_CHAR8 ignorePosition, OOC_CHAR8 *baseNotExported) {

  _failed_function(47632); return 0;
  ;
}

OOC_SymbolTable__Declaration OOC_SymbolTable__NamespaceDesc_Identify(OOC_SymbolTable__Namespace ns, OOC_SymbolTable__Item sourceContext, OOC_SymbolTable__Name name, OOC_CHAR8 ignorePosition) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_CHAR8 baseNotExported;

  baseNotExported = 0u;
  i0 = (OOC_INT32)ns;
  i1 = (OOC_INT32)sourceContext;
  i2 = (OOC_INT32)name;
  i3 = ignorePosition;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 48556)))), OOC_SymbolTable__NamespaceDesc_Identify2)),OOC_SymbolTable__NamespaceDesc_Identify2)((OOC_SymbolTable__Namespace)i0, (OOC_SymbolTable__Item)i1, (OOC_SymbolTable__Name)i2, i3, (void*)(OOC_INT32)&baseNotExported);
  return (OOC_SymbolTable__Declaration)i0;
  ;
}

OOC_SymbolTable__ProcDecl OOC_SymbolTable__NamespaceDesc_GetSuperProcByIndex(OOC_SymbolTable__Namespace ns, OOC_INT32 index) {

  _assert(0u, 127, 48824);
  _failed_function(48665); return 0;
  ;
}

static void OOC_SymbolTable__WriteType(ADT_Storable__Writer w, OOC_SymbolTable__Type type, OOC_SymbolTable__Type srcCodeType) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)srcCodeType;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 48963)))), ADT_Storable__WriterDesc_WriteObject)),ADT_Storable__WriterDesc_WriteObject)((ADT_Storable__Writer)i0, (Object__Object)i1);
  return;
  ;
}

static void OOC_SymbolTable__ReadType(ADT_Storable__Reader r, OOC_SymbolTable__Type *type, OOC_SymbolTable__Type *srcCodeType) {
  register OOC_INT32 i0,i1;
  Object__Object obj;

  i0 = (OOC_INT32)r;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 49136)))), ADT_Storable__ReaderDesc_ReadObject)),ADT_Storable__ReaderDesc_ReadObject)((ADT_Storable__Reader)i0, (void*)(OOC_INT32)&obj);
  i0 = (OOC_INT32)obj;
  i1 = i0==(OOC_INT32)0;
  if (i1) goto l3;
  i0 = _type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 49257)))), &_td_OOC_SymbolTable__TypeDesc, 49257);
  *srcCodeType = (OOC_SymbolTable__Type)i0;
  *type = (OOC_SymbolTable__Type)i0;
  goto l4;
l3:
  *srcCodeType = (OOC_SymbolTable__Type)(OOC_INT32)0;
  *type = (OOC_SymbolTable__Type)(OOC_INT32)0;
l4:
  return;
  ;
}

void OOC_SymbolTable__InitPosition(OOC_SymbolTable__Position position, OOC_INT32 pos, OOC_INT32 line, OOC_INT32 column) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)position;
  i1 = pos;
  *(OOC_INT32*)(_check_pointer(i0, 49464)) = i1;
  i1 = line;
  *(OOC_INT32*)((_check_pointer(i0, 49490))+4) = i1;
  i1 = column;
  *(OOC_INT32*)((_check_pointer(i0, 49518))+8) = i1;
  return;
  ;
}

void OOC_SymbolTable__PositionDesc_Store(OOC_SymbolTable__Position position, ADT_Storable__Writer w) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)position;
  i1 = (OOC_INT32)w;
  i2 = *(OOC_INT32*)(_check_pointer(i0, 49723));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 49703)))), IO_BinaryRider__WriterDesc_WriteNum)),IO_BinaryRider__WriterDesc_WriteNum)((IO_BinaryRider__Writer)i1, i2);
  i2 = *(OOC_INT32*)((_check_pointer(i0, 49756))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 49736)))), IO_BinaryRider__WriterDesc_WriteNum)),IO_BinaryRider__WriterDesc_WriteNum)((IO_BinaryRider__Writer)i1, i2);
  i0 = *(OOC_INT32*)((_check_pointer(i0, 49790))+8);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 49770)))), IO_BinaryRider__WriterDesc_WriteNum)),IO_BinaryRider__WriterDesc_WriteNum)((IO_BinaryRider__Writer)i1, i0);
  return;
  ;
}

void OOC_SymbolTable__PositionDesc_Load(OOC_SymbolTable__Position position, ADT_Storable__Reader r) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)position;
  i1 = (OOC_INT32)r;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 49958)))), IO_BinaryRider__ReaderDesc_ReadNum)),IO_BinaryRider__ReaderDesc_ReadNum)((IO_BinaryRider__Reader)i1, (void*)(_check_pointer(i0, 49977)));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 49990)))), IO_BinaryRider__ReaderDesc_ReadNum)),IO_BinaryRider__ReaderDesc_ReadNum)((IO_BinaryRider__Reader)i1, (void*)((_check_pointer(i0, 50009))+4));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 50023)))), IO_BinaryRider__ReaderDesc_ReadNum)),IO_BinaryRider__ReaderDesc_ReadNum)((IO_BinaryRider__Reader)i1, (void*)((_check_pointer(i0, 50042))+8));
  return;
  ;
}

void OOC_SymbolTable__InitName(OOC_SymbolTable__Name name, OOC_Scanner_InputBuffer__CharArray str, OOC_INT32 pos, OOC_INT32 line, OOC_INT32 column) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = column;
  i1 = line;
  i2 = pos;
  i3 = (OOC_INT32)name;
  OOC_SymbolTable__InitPosition((OOC_SymbolTable__Position)i3, i2, i1, i0);
  i0 = (OOC_INT32)str;
  *(OOC_INT32*)((_check_pointer(i3, 50255))+12) = i0;
  return;
  ;
}

void OOC_SymbolTable__NameDesc_Store(OOC_SymbolTable__Name name, ADT_Storable__Writer w) {
  register OOC_INT32 i0,i1,i2;
  OOC_INT32 len;

  i0 = (OOC_INT32)name;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 50479))+12);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 50479))+12);
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 50484)), 0);
  i1 = Strings__Length((void*)(_check_pointer(i2, 50484)), i1);
  len = i1;
  i2 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 50493)))), IO_BinaryRider__WriterDesc_WriteNum)),IO_BinaryRider__WriterDesc_WriteNum)((IO_BinaryRider__Writer)i2, i1);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 50534))+12);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 50516)))), IO_BinaryRider__WriterDesc_WriteBytes)),IO_BinaryRider__WriterDesc_WriteBytes)((IO_BinaryRider__Writer)i2, (void*)(_check_pointer(i0, 50539)), (-1), 0, i1);
  return;
  ;
}

void OOC_SymbolTable__NameDesc_Load(OOC_SymbolTable__Name name, ADT_Storable__Reader r) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  OOC_INT32 len;
  OOC_Scanner_InputBuffer__CharArray str;

  i0 = (OOC_INT32)name;
  OOC_SymbolTable__InitPosition((OOC_SymbolTable__Position)i0, (-2), (-1), (-1));
  i1 = (OOC_INT32)r;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 50807)))), IO_BinaryRider__ReaderDesc_ReadNum)),IO_BinaryRider__ReaderDesc_ReadNum)((IO_BinaryRider__Reader)i1, (void*)(OOC_INT32)&len);
  i2 = len;
  i3 = (OOC_INT32)RT0__NewObject(_td_OOC_Scanner_InputBuffer__CharArray.baseTypes[0], (i2+1));
  str = (OOC_Scanner_InputBuffer__CharArray)i3;
  i4 = _check_pointer(i3, 50853);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  *(OOC_UINT8*)(i4+(_check_index(i2, i5, OOC_UINT32, 50853))) = 0u;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 50871)))), IO_BinaryRider__ReaderDesc_ReadBytes)),IO_BinaryRider__ReaderDesc_ReadBytes)((IO_BinaryRider__Reader)i1, (void*)(_check_pointer(i3, 50887)), (-1), 0, i2);
  *(OOC_INT32*)((_check_pointer(i0, 50907))+12) = i3;
  return;
  ;
}

void OOC_SymbolTable__InitItem(OOC_SymbolTable__Item item, OOC_SymbolTable__Item parent) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)item;
  *(OOC_INT32*)(_check_pointer(i0, 50999)) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 51028))+8) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 51058))+12) = 0;
  i1 = (OOC_INT32)parent;
  *(OOC_INT32*)((_check_pointer(i0, 51092))+4) = i1;
  *(OOC_INT32*)((_check_pointer(i0, 51120))+16) = 0;
  i2 = i1!=0;
  if (!i2) goto l23;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 51189)))), &_td_OOC_SymbolTable__ModuleDesc);
  if (i2) goto l5;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 51226)))), &_td_OOC_SymbolTable__ProcDeclDesc);
  
  goto l7;
l5:
  i2=1u;
l7:
  if (i2) goto l9;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 51265)))), &_td_OOC_SymbolTable__RecordDesc);
  
  goto l11;
l9:
  i2=1u;
l11:
  if (i2) goto l13;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 51302)))), &_td_OOC_SymbolTable__FormalParsDesc);
  
  goto l15;
l13:
  i2=1u;
l15:
  if (i2) goto l17;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 51343)))), &_td_OOC_SymbolTable__TypeParsDesc);
  
  goto l18;
l17:
  i2=1u;
l18:
  _assert(i2, 127, 51172);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 51374))+8);
  i2 = i2==0;
  if (i2) goto l21;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 51459))+12);
  *(OOC_INT32*)(_check_pointer(i2, 51475)) = i0;
  goto l22;
l21:
  *(OOC_INT32*)((_check_pointer(i1, 51412))+8) = i0;
l22:
  *(OOC_INT32*)((_check_pointer(i1, 51519))+12) = i0;
l23:
  return;
  ;
}

static void OOC_SymbolTable__WriteItemList(ADT_Storable__Writer w, OOC_SymbolTable__Item item) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)item;
  i1 = (OOC_INT32)w;
  i2 = i0!=(OOC_INT32)0;
  if (!i2) goto l8;
  
l3_loop:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 51682)))), ADT_Storable__WriterDesc_WriteObject)),ADT_Storable__WriterDesc_WriteObject)((ADT_Storable__Writer)i1, (Object__Object)i0);
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 51721));
  item = (OOC_SymbolTable__Item)i0;
  i2 = i0!=(OOC_INT32)0;
  if (i2) goto l3_loop;
l8:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 51748)))), ADT_Storable__WriterDesc_WriteObject)),ADT_Storable__WriterDesc_WriteObject)((ADT_Storable__Writer)i1, (Object__Object)(OOC_INT32)0);
  return;
  ;
}

static void OOC_SymbolTable__ReadItemList(ADT_Storable__Reader r, OOC_SymbolTable__Item *list, OOC_SymbolTable__Item *last) {
  register OOC_INT32 i0,i1,i2,i3;
  Object__Object obj;

  *list = (OOC_SymbolTable__Item)(OOC_INT32)0;
  *last = (OOC_SymbolTable__Item)(OOC_INT32)0;
  i0 = (OOC_INT32)r;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 51970)))), ADT_Storable__ReaderDesc_ReadObject)),ADT_Storable__ReaderDesc_ReadObject)((ADT_Storable__Reader)i0, (void*)(OOC_INT32)&obj);
  i1 = (OOC_INT32)obj;
  i2 = i1!=(OOC_INT32)0;
  if (!i2) goto l16;
  i2=(OOC_INT32)0;
l3_loop:
  i3 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 52027)))), &_td_OOC_SymbolTable__ItemDesc);
  if (i3) goto l6;
  _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 52018)))), 52018);
  i1=i2;
  goto l11;
l6:
  i3 = i2!=(OOC_INT32)0;
  if (i3) goto l9;
  *list = (OOC_SymbolTable__Item)i1;
  goto l10;
l9:
  *(OOC_INT32*)(_check_pointer(i2, 52078)) = i1;
l10:
  *last = (OOC_SymbolTable__Item)i1;
  
l11:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 52183)))), ADT_Storable__ReaderDesc_ReadObject)),ADT_Storable__ReaderDesc_ReadObject)((ADT_Storable__Reader)i0, (void*)(OOC_INT32)&obj);
  i2 = (OOC_INT32)obj;
  i3 = i2!=(OOC_INT32)0;
  if (!i3) goto l16;
  {register OOC_INT32 h0=i1;i1=i2;i2=h0;}
  goto l3_loop;
l16:
  return;
  ;
}

void OOC_SymbolTable__ItemDesc_Store(OOC_SymbolTable__Item item, ADT_Storable__Writer w) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)item;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 52331))+8);
  i2 = (OOC_INT32)w;
  OOC_SymbolTable__WriteItemList((ADT_Storable__Writer)i2, (OOC_SymbolTable__Item)i1);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 52370))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 52351)))), ADT_Storable__WriterDesc_WriteObject)),ADT_Storable__WriterDesc_WriteObject)((ADT_Storable__Writer)i2, (Object__Object)i0);
  return;
  ;
}

void OOC_SymbolTable__ItemDesc_Load(OOC_SymbolTable__Item item, ADT_Storable__Reader r) {
  register OOC_INT32 i0,i1,i2;
  Object__Object obj;

  i0 = (OOC_INT32)item;
  *(OOC_INT32*)(_check_pointer(i0, 52546)) = 0;
  i1 = (OOC_INT32)r;
  OOC_SymbolTable__ReadItemList((ADT_Storable__Reader)i1, (void*)((_check_pointer(i0, 52591))+8), (void*)((_check_pointer(i0, 52610))+12));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 52635)))), ADT_Storable__ReaderDesc_ReadObject)),ADT_Storable__ReaderDesc_ReadObject)((ADT_Storable__Reader)i1, (void*)(OOC_INT32)&obj);
  i1 = (OOC_INT32)obj;
  i2 = i1==0;
  if (i2) goto l3;
  *(OOC_INT32*)((_check_pointer(i0, 52724))+4) = (_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 52740)))), &_td_OOC_SymbolTable__ItemDesc, 52740));
  goto l4;
l3:
  *(OOC_INT32*)((_check_pointer(i0, 52689))+4) = 0;
l4:
  *(OOC_INT32*)((_check_pointer(i0, 52763))+16) = 0;
  return;
  ;
}

OOC_SymbolTable__Module OOC_SymbolTable__ItemDesc_Module(OOC_SymbolTable__Item item) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)item;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 53249))+4);
  i1 = i1==(OOC_INT32)0;
  if (i1) goto l3;
  i1=0u;
  goto l5;
l3:
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 53272)))), &_td_OOC_SymbolTable__TypeDesc);
  
l5:
  if (!i1) goto l8;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 53305)))), &_td_OOC_SymbolTable__TypeDesc, 53305)), 53310)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 53305)))), &_td_OOC_SymbolTable__TypeDesc, 53305)));
  item = (OOC_SymbolTable__Item)i0;
  
l8:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 53384))+4);
  i1 = i1!=(OOC_INT32)0;
  if (!i1) goto l25;
l12_loop:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 53420))+4);
  item = (OOC_SymbolTable__Item)i0;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 53443))+4);
  i1 = i1==(OOC_INT32)0;
  if (i1) goto l15;
  i1=0u;
  goto l17;
l15:
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 53466)))), &_td_OOC_SymbolTable__TypeDesc);
  
l17:
  if (!i1) goto l20;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 53501)))), &_td_OOC_SymbolTable__TypeDesc, 53501)), 53506)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 53501)))), &_td_OOC_SymbolTable__TypeDesc, 53501)));
  item = (OOC_SymbolTable__Item)i0;
  
l20:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 53384))+4);
  i1 = i1!=(OOC_INT32)0;
  if (i1) goto l12_loop;
l25:
  return (OOC_SymbolTable__Module)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 53593)))), &_td_OOC_SymbolTable__ModuleDesc, 53593));
  ;
}

OOC_CHAR8 OOC_SymbolTable__ItemDesc_InStandardModule(OOC_SymbolTable__Item item) {
  register OOC_INT32 i0,i1;
  OOC_SymbolTable__Module module;

  i0 = (OOC_INT32)item;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 53865))+4);
  i1 = i1==(OOC_INT32)0;
  if (i1) goto l3;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 53968)))), OOC_SymbolTable__ItemDesc_Module)),OOC_SymbolTable__ItemDesc_Module)((OOC_SymbolTable__Item)i0);
  module = (OOC_SymbolTable__Module)i0;
  i0 = *(OOC_INT8*)((_check_pointer(i0, 53999))+52);
  return (i0==0);
  goto l4;
l3:
  return 1u;
l4:
  _failed_function(53639); return 0;
  ;
}

OOC_SymbolTable__ProcDecl OOC_SymbolTable__ItemDesc_Procedure(OOC_SymbolTable__Item item) {
  register OOC_INT32 i0,i1,i2;

l1_loop:
  i0 = (OOC_INT32)item;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 54284))+4);
  item = (OOC_SymbolTable__Item)i0;
  i1 = i0==(OOC_INT32)0;
  if (i1) goto l4;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 54325)))), &_td_OOC_SymbolTable__ProcDeclDesc);
  
  goto l6;
l4:
  i2=1u;
l6:
  if (!i2) goto l1_loop;
l10:
  if (i1) goto l12;
  return (OOC_SymbolTable__ProcDecl)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 54408)))), &_td_OOC_SymbolTable__ProcDeclDesc, 54408));
  goto l13;
l12:
  return (OOC_SymbolTable__ProcDecl)(OOC_INT32)0;
l13:
  _failed_function(54080); return 0;
  ;
}

void OOC_SymbolTable__ItemDesc_AddFlag(OOC_SymbolTable__Item item, OOC_SymbolTable__Name name) {
  register OOC_INT32 i0,i1,i2;
  OOC_INT16 id;
  OOC_SymbolTable__Flag fl;
  auto void OOC_SymbolTable__ItemDesc_AddFlag_Append(OOC_SymbolTable__Flag *list);
    
    void OOC_SymbolTable__ItemDesc_AddFlag_Append(OOC_SymbolTable__Flag *list) {
      register OOC_INT32 i0,i1;

      i0 = (OOC_INT32)*list;
      i1 = i0==(OOC_INT32)0;
      if (i1) goto l3;
      OOC_SymbolTable__ItemDesc_AddFlag_Append((void*)(_check_pointer(i0, 54847)));
      goto l4;
l3:
      i0 = (OOC_INT32)fl;
      *(OOC_INT32*)(_check_pointer(i0, 54779)) = (OOC_INT32)0;
      *list = (OOC_SymbolTable__Flag)i0;
l4:
      return;
      ;
    }


  i0 = (OOC_INT32)name;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 54909))+12);
  i1 = (
  _cmp8((const void*)(_check_pointer(i1, 54913)),(const void*)"NO_COPY"))==0;
  if (i1) goto l75;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 54972))+12);
  i1 = (
  _cmp8((const void*)(_check_pointer(i1, 54976)),(const void*)"ABSTRACT"))==0;
  if (i1) goto l73;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 55038))+12);
  i1 = (
  _cmp8((const void*)(_check_pointer(i1, 55042)),(const void*)"NO_LENGTH_INFO"))==0;
  if (i1) goto l71;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 55114))+12);
  i1 = (
  _cmp8((const void*)(_check_pointer(i1, 55118)),(const void*)"NO_DESCRIPTOR"))==0;
  if (i1) goto l69;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 55189))+12);
  i1 = (
  _cmp8((const void*)(_check_pointer(i1, 55193)),(const void*)"NOT_EXTENSIBLE"))==0;
  if (i1) goto l67;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 55340))+12);
  i1 = (
  _cmp8((const void*)(_check_pointer(i1, 55344)),(const void*)"UNCHECKED_EXCEPTION"))==0;
  if (i1) goto l65;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 55427))+12);
  i1 = (
  _cmp8((const void*)(_check_pointer(i1, 55431)),(const void*)"CSTRING"))==0;
  if (i1) goto l63;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 55491))+12);
  i1 = (
  _cmp8((const void*)(_check_pointer(i1, 55495)),(const void*)"NIL_COMPAT"))==0;
  if (i1) goto l61;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 55560))+12);
  i1 = (
  _cmp8((const void*)(_check_pointer(i1, 55564)),(const void*)"UNION"))==0;
  if (i1) goto l59;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 55620))+12);
  i1 = (
  _cmp8((const void*)(_check_pointer(i1, 55624)),(const void*)"READ_ONLY"))==0;
  if (i1) goto l57;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 55687))+12);
  i1 = (
  _cmp8((const void*)(_check_pointer(i1, 55691)),(const void*)"NO_RETURN"))==0;
  if (i1) goto l55;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 55754))+12);
  i1 = (
  _cmp8((const void*)(_check_pointer(i1, 55758)),(const void*)"DEPRECATED"))==0;
  if (i1) goto l53;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 55824))+12);
  i1 = (
  _cmp8((const void*)(_check_pointer(i1, 55828)),(const void*)"OOC_EXTENSIONS"))==0;
  if (i1) goto l51;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 55901))+12);
  i1 = (
  _cmp8((const void*)(_check_pointer(i1, 55905)),(const void*)"ALIGN1"))==0;
  if (i1) goto l49;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 55963))+12);
  i1 = (
  _cmp8((const void*)(_check_pointer(i1, 55967)),(const void*)"ALIGN2"))==0;
  if (i1) goto l47;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 56025))+12);
  i1 = (
  _cmp8((const void*)(_check_pointer(i1, 56029)),(const void*)"ALIGN4"))==0;
  if (i1) goto l45;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 56087))+12);
  i1 = (
  _cmp8((const void*)(_check_pointer(i1, 56091)),(const void*)"ALIGN8"))==0;
  if (i1) goto l43;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 56149))+12);
  i1 = (
  _cmp8((const void*)(_check_pointer(i1, 56153)),(const void*)"VTABLE"))==0;
  if (i1) goto l41;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 56211))+12);
  i1 = (
  _cmp8((const void*)(_check_pointer(i1, 56215)),(const void*)"NO_TRACED_POINTERS"))==0;
  if (i1) goto l39;
  id = (-1);
  i1=(-1);
  goto l76;
l39:
  id = 19;
  i1=19;
  goto l76;
l41:
  id = 17;
  i1=17;
  goto l76;
l43:
  id = 16;
  i1=16;
  goto l76;
l45:
  id = 15;
  i1=15;
  goto l76;
l47:
  id = 14;
  i1=14;
  goto l76;
l49:
  id = 13;
  i1=13;
  goto l76;
l51:
  id = 11;
  i1=11;
  goto l76;
l53:
  id = 10;
  i1=10;
  goto l76;
l55:
  id = 9;
  i1=9;
  goto l76;
l57:
  id = 8;
  i1=8;
  goto l76;
l59:
  id = 7;
  i1=7;
  goto l76;
l61:
  id = 6;
  i1=6;
  goto l76;
l63:
  id = 5;
  i1=5;
  goto l76;
l65:
  id = 18;
  i1=18;
  goto l76;
l67:
  id = 4;
  i1=4;
  goto l76;
l69:
  id = 3;
  i1=3;
  goto l76;
l71:
  id = 2;
  i1=2;
  goto l76;
l73:
  id = 1;
  i1=1;
  goto l76;
l75:
  id = 0;
  i1=0;
l76:
  i2 = (OOC_INT32)RT0__NewObject(_td_OOC_SymbolTable__Flag.baseTypes[0]);
  fl = (OOC_SymbolTable__Flag)i2;
  *(OOC_INT16*)((_check_pointer(i2, 56337))+4) = i1;
  *(OOC_INT32*)((_check_pointer(i2, 56354))+8) = i0;
  i0 = (OOC_INT32)item;
  OOC_SymbolTable__ItemDesc_AddFlag_Append((void*)((_check_pointer(i0, 56383))+16));
  return;
  ;
}

void OOC_SymbolTable__InitDeclaration(OOC_SymbolTable__Declaration decl, OOC_SymbolTable__Item parent, OOC_SymbolTable__Name name, OOC_INT32 visibleFrom, OOC_INT8 exportMark, OOC_Doc__Document docString) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)parent;
  i1 = (OOC_INT32)decl;
  OOC_SymbolTable__InitItem((OOC_SymbolTable__Item)i1, (OOC_SymbolTable__Item)i0);
  i0 = (OOC_INT32)name;
  *(OOC_INT32*)((_check_pointer(i1, 56659))+20) = i0;
  i0 = visibleFrom;
  *(OOC_INT32*)((_check_pointer(i1, 56683))+24) = i0;
  i0 = exportMark;
  *(OOC_INT8*)((_check_pointer(i1, 56721))+28) = i0;
  i0 = (OOC_INT32)docString;
  *(OOC_INT32*)((_check_pointer(i1, 56757))+32) = i0;
  *(OOC_UINT8*)((_check_pointer(i1, 56791))+36) = 0u;
  *(OOC_INT32*)((_check_pointer(i1, 56822))+40) = (OOC_INT32)0;
  *(OOC_INT32*)((_check_pointer(i1, 56849))+44) = 0;
  return;
  ;
}

void OOC_SymbolTable__DeclarationDesc_Store(OOC_SymbolTable__Declaration decl, ADT_Storable__Writer w) {
  register OOC_INT32 i0,i1,i2,i3,i4;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)decl;
  OOC_SymbolTable__ItemDesc_Store((OOC_SymbolTable__Item)i1, (ADT_Storable__Writer)i0);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 57021))+20);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 57002)))), ADT_Storable__WriterDesc_WriteObject)),ADT_Storable__WriterDesc_WriteObject)((ADT_Storable__Writer)i0, (Object__Object)i2);
  i2 = *(OOC_INT8*)((_check_pointer(i1, 57092))+28);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 57076)))), IO_BinaryRider__WriterDesc_WriteNum)),IO_BinaryRider__WriterDesc_WriteNum)((IO_BinaryRider__Writer)i0, i2);
  i2 = *(OOC_INT8*)((_check_pointer(i1, 57119))+28);
  i2 = i2!=0;
  if (i2) goto l3;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 57230)))), &_td_OOC_SymbolTable__WriterDesc, 57230)), 57237))+280);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 57230)))), &_td_OOC_SymbolTable__WriterDesc, 57230)), 57237))+280);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 57247)))), ADT_Object_Storage__WriterDesc_WriteObject)),ADT_Object_Storage__WriterDesc_WriteObject)((ADT_Object_Storage__Writer)i3, (Object__Object)(OOC_INT32)0);
  goto l4;
l3:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 57164)))), &_td_OOC_SymbolTable__WriterDesc, 57164)), 57171))+280);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 57198))+32);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 57164)))), &_td_OOC_SymbolTable__WriterDesc, 57164)), 57171))+280);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 57181)))), ADT_Object_Storage__WriterDesc_WriteObject)),ADT_Object_Storage__WriterDesc_WriteObject)((ADT_Object_Storage__Writer)i4, (Object__Object)i3);
l4:
  i1 = *(OOC_UINT8*)((_check_pointer(i1, 57297))+36);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 57280)))), IO_BinaryRider__WriterDesc_WriteBool)),IO_BinaryRider__WriterDesc_WriteBool)((IO_BinaryRider__Writer)i0, i1);
  return;
  ;
}

void OOC_SymbolTable__DeclarationDesc_Load(OOC_SymbolTable__Declaration decl, ADT_Storable__Reader r) {
  register OOC_INT32 i0,i1,i2,i3;
  Object__Object obj;
  OOC_INT32 i;

  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)decl;
  OOC_SymbolTable__ItemDesc_Load((OOC_SymbolTable__Item)i1, (ADT_Storable__Reader)i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 57479)))), ADT_Storable__ReaderDesc_ReadObject)),ADT_Storable__ReaderDesc_ReadObject)((ADT_Storable__Reader)i0, (void*)(OOC_INT32)&obj);
  i2 = (OOC_INT32)obj;
  *(OOC_INT32*)((_check_pointer(i1, 57507))+20) = (_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 57521)))), &_td_OOC_SymbolTable__NameDesc, 57521));
  *(OOC_INT32*)((_check_pointer(i1, 57690))+24) = (-3);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 57904)))), IO_BinaryRider__ReaderDesc_ReadNum)),IO_BinaryRider__ReaderDesc_ReadNum)((IO_BinaryRider__Reader)i0, (void*)(OOC_INT32)&i);
  i2 = i;
  *(OOC_INT8*)((_check_pointer(i1, 57923))+28) = i2;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 58046)))), &_td_OOC_SymbolTable__ReaderDesc, 58046)), 58053))+280);
  i2 = i2!=(OOC_INT32)0;
  if (i2) goto l3;
  *(OOC_INT32*)((_check_pointer(i1, 58266))+32) = (OOC_INT32)0;
  goto l8;
l3:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 58084)))), &_td_OOC_SymbolTable__ReaderDesc, 58084)), 58091))+280);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 58084)))), &_td_OOC_SymbolTable__ReaderDesc, 58084)), 58091))+280);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 58101)))), ADT_Object_Storage__ReaderDesc_ReadObject)),ADT_Object_Storage__ReaderDesc_ReadObject)((ADT_Object_Storage__Reader)i3, (void*)(OOC_INT32)&obj);
  i2 = (OOC_INT32)obj;
  i3 = i2==(OOC_INT32)0;
  if (i3) goto l6;
  *(OOC_INT32*)((_check_pointer(i1, 58203))+32) = (_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 58225)))), &_td_OOC_Doc__DocumentDesc, 58225));
  goto l8;
l6:
  *(OOC_INT32*)((_check_pointer(i1, 58159))+32) = (OOC_INT32)0;
l8:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 58304)))), IO_BinaryRider__ReaderDesc_ReadBool)),IO_BinaryRider__ReaderDesc_ReadBool)((IO_BinaryRider__Reader)i0, (void*)((_check_pointer(i1, 58320))+36));
  *(OOC_INT32*)((_check_pointer(i1, 58342))+40) = (OOC_INT32)0;
  *(OOC_INT32*)((_check_pointer(i1, 58369))+44) = 0;
  return;
  ;
}

Object__String OOC_SymbolTable__DeclarationDesc_Name(OOC_SymbolTable__Declaration decl) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)decl;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 58628))+20);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 58633))+12);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 58628))+20);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 58633))+12);
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 58637)), 0);
  i0 = (OOC_INT32)Object__NewLatin1((void*)(_check_pointer(i0, 58637)), i1);
  return (Object__String)i0;
  ;
}

void OOC_SymbolTable__DeclarationDesc_IncrUsageCounter(OOC_SymbolTable__Declaration decl) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)decl;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 58723))+44);
  *(OOC_INT32*)((_check_pointer(i0, 58723))+44) = (i1+1);
  return;
  ;
}

static OOC_CHAR8 OOC_SymbolTable__ExportTypePosition(OOC_SymbolTable__Type type) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)type;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 59143)))), &_td_OOC_SymbolTable__PointerDesc);
  if (i1) goto l3;
  i0=0u;
  goto l4;
l3:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 59162))+24);
  i0 = i0==(OOC_INT32)0;
  
l4:
  return i0;
  ;
}

void OOC_SymbolTable__InitType(OOC_SymbolTable__Type type, OOC_SymbolTable__Item parent, OOC_SymbolTable__Position position) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)parent;
  i1 = (OOC_INT32)type;
  OOC_SymbolTable__InitItem((OOC_SymbolTable__Item)i1, (OOC_SymbolTable__Item)i0);
  i0 = (OOC_INT32)position;
  *(OOC_INT32*)((_check_pointer(i1, 59323))+20) = i0;
  *(OOC_INT32*)((_check_pointer(i1, 59355))+24) = (OOC_INT32)0;
  *(OOC_INT32*)((_check_pointer(i1, 59384))+28) = (OOC_INT32)0;
  *(OOC_INT32*)((_check_pointer(i1, 59411))+32) = (-2);
  *(OOC_INT16*)((_check_pointer(i1, 59442))+36) = 1;
  *(OOC_UINT8*)((_check_pointer(i1, 59464))+38) = 1u;
  return;
  ;
}

OOC_CHAR8 OOC_SymbolTable__TypeDesc_PreciousTypePars(OOC_SymbolTable__Type type) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)type;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 59822))+28);
  i1 = i1!=(OOC_INT32)0;
  if (i1) goto l3;
  i0=0u;
  goto l4;
l3:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 59846))+28);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 59855))+8);
  i0 = i0!=(OOC_INT32)0;
  
l4:
  return i0;
  ;
}

OOC_CHAR8 OOC_SymbolTable__TypeDesc_IsCheckedException(OOC_SymbolTable__Type type) {
  register OOC_INT32 i0,i1;
  OOC_SymbolTable__Type ptr;

  i0 = (OOC_INT32)type;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 59998)))), &_td_OOC_SymbolTable__PointerDesc);
  if (i1) goto l3;
  return 1u;
  goto l8;
l3:
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 60032)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
  ptr = (OOC_SymbolTable__Type)i0;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 60061)))), &_td_OOC_SymbolTable__PointerDesc, 60061)), 60069))+40);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 60061)))), &_td_OOC_SymbolTable__PointerDesc, 60061)), 60069))+40);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 60078)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
  ptr = (OOC_SymbolTable__Type)i0;
  i1 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 60109)))), &_td_OOC_SymbolTable__RecordDesc));
  if (i1) goto l6;
  i0 = *(OOC_UINT8*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 60128)))), &_td_OOC_SymbolTable__RecordDesc, 60128)), 60135))+59);
  i0 = !i0;
  
  goto l7;
l6:
  i0=1u;
l7:
  return i0;
l8:
  _failed_function(59924); return 0;
  ;
}

void OOC_SymbolTable__TypeDesc_Store(OOC_SymbolTable__Type type, ADT_Storable__Writer w) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)type;
  OOC_SymbolTable__ItemDesc_Store((OOC_SymbolTable__Item)i1, (ADT_Storable__Writer)i0);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 60344))+24);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 60325)))), ADT_Storable__WriterDesc_WriteObject)),ADT_Storable__WriterDesc_WriteObject)((ADT_Storable__Writer)i0, (Object__Object)i2);
  i2 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 60370)))), OOC_SymbolTable__TypeDesc_PreciousTypePars)),OOC_SymbolTable__TypeDesc_PreciousTypePars)((OOC_SymbolTable__Type)i1);
  if (i2) goto l3;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 60447)))), ADT_Storable__WriterDesc_WriteObject)),ADT_Storable__WriterDesc_WriteObject)((ADT_Storable__Writer)i0, (Object__Object)(OOC_INT32)0);
  goto l4;
l3:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 60419))+28);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 60402)))), ADT_Storable__WriterDesc_WriteObject)),ADT_Storable__WriterDesc_WriteObject)((ADT_Storable__Writer)i0, (Object__Object)i2);
l4:
  i2 = OOC_SymbolTable__ExportTypePosition((OOC_SymbolTable__Type)i1);
  if (!i2) goto l7;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 60539))+20);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 60520)))), ADT_Storable__WriterDesc_WriteObject)),ADT_Storable__WriterDesc_WriteObject)((ADT_Storable__Writer)i0, (Object__Object)i2);
l7:
  i2 = *(OOC_INT32*)((_check_pointer(i1, 60582))+32);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 60566)))), IO_BinaryRider__WriterDesc_WriteNum)),IO_BinaryRider__WriterDesc_WriteNum)((IO_BinaryRider__Writer)i0, i2);
  i2 = *(OOC_INT16*)((_check_pointer(i1, 60612))+36);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 60596)))), IO_BinaryRider__WriterDesc_WriteNum)),IO_BinaryRider__WriterDesc_WriteNum)((IO_BinaryRider__Writer)i0, i2);
  i1 = *(OOC_UINT8*)((_check_pointer(i1, 60644))+38);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 60627)))), IO_BinaryRider__WriterDesc_WriteBool)),IO_BinaryRider__WriterDesc_WriteBool)((IO_BinaryRider__Writer)i0, i1);
  return;
  ;
}

void OOC_SymbolTable__TypeDesc_Load(OOC_SymbolTable__Type type, ADT_Storable__Reader r) {
  register OOC_INT32 i0,i1,i2,i3;
  Object__Object obj;
  OOC_INT32 i;

  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)type;
  OOC_SymbolTable__ItemDesc_Load((OOC_SymbolTable__Item)i1, (ADT_Storable__Reader)i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 60823)))), ADT_Storable__ReaderDesc_ReadObject)),ADT_Storable__ReaderDesc_ReadObject)((ADT_Storable__Reader)i0, (void*)(OOC_INT32)&obj);
  i2 = (OOC_INT32)obj;
  i3 = i2==(OOC_INT32)0;
  if (i3) goto l3;
  *(OOC_INT32*)((_check_pointer(i1, 60916))+24) = (_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 60936)))), &_td_OOC_SymbolTable__TypeDeclDesc, 60936));
  goto l4;
l3:
  *(OOC_INT32*)((_check_pointer(i1, 60877))+24) = (OOC_INT32)0;
l4:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 60960)))), ADT_Storable__ReaderDesc_ReadObject)),ADT_Storable__ReaderDesc_ReadObject)((ADT_Storable__Reader)i0, (void*)(OOC_INT32)&obj);
  i2 = (OOC_INT32)obj;
  i3 = i2==(OOC_INT32)0;
  if (i3) goto l7;
  *(OOC_INT32*)((_check_pointer(i1, 61051))+28) = (_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 61069)))), &_td_OOC_SymbolTable__TypeParsDesc, 61069));
  goto l8;
l7:
  *(OOC_INT32*)((_check_pointer(i1, 61014))+28) = (OOC_INT32)0;
l8:
  i2 = OOC_SymbolTable__ExportTypePosition((OOC_SymbolTable__Type)i1);
  if (i2) goto l11;
  i2 = (OOC_INT32)OOC_SymbolTable__importPosition;
  *(OOC_INT32*)((_check_pointer(i1, 61211))+20) = i2;
  goto l12;
l11:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 61133)))), ADT_Storable__ReaderDesc_ReadObject)),ADT_Storable__ReaderDesc_ReadObject)((ADT_Storable__Reader)i0, (void*)(OOC_INT32)&obj);
  i2 = (OOC_INT32)obj;
  *(OOC_INT32*)((_check_pointer(i1, 61163))+20) = (_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 61181)))), &_td_OOC_SymbolTable__PositionDesc, 61181));
l12:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 61255)))), IO_BinaryRider__ReaderDesc_ReadNum)),IO_BinaryRider__ReaderDesc_ReadNum)((IO_BinaryRider__Reader)i0, (void*)((_check_pointer(i1, 61270))+32));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 61284)))), IO_BinaryRider__ReaderDesc_ReadNum)),IO_BinaryRider__ReaderDesc_ReadNum)((IO_BinaryRider__Reader)i0, (void*)(OOC_INT32)&i);
  i2 = i;
  *(OOC_INT16*)((_check_pointer(i1, 61307))+36) = i2;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 61334)))), IO_BinaryRider__ReaderDesc_ReadBool)),IO_BinaryRider__ReaderDesc_ReadBool)((IO_BinaryRider__Reader)i0, (void*)((_check_pointer(i1, 61350))+38));
  return;
  ;
}

void OOC_SymbolTable__TypeDesc_SetNamingDecl(OOC_SymbolTable__Type type, OOC_SymbolTable__TypeDecl namingDecl) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)type;
  i1 = (OOC_INT32)namingDecl;
  *(OOC_INT32*)((_check_pointer(i0, 61547))+24) = i1;
  return;
  ;
}

void OOC_SymbolTable__TypeDesc_SetTypePars(OOC_SymbolTable__Type type, OOC_SymbolTable__TypePars typePars) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)type;
  i1 = (OOC_INT32)typePars;
  *(OOC_INT32*)((_check_pointer(i0, 61737))+28) = i1;
  return;
  ;
}

void OOC_SymbolTable__TypeDesc_SetSize(OOC_SymbolTable__Type type, OOC_INT32 size, OOC_INT16 align) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)type;
  i1 = size;
  *(OOC_INT32*)((_check_pointer(i0, 61862))+32) = i1;
  i1 = align;
  *(OOC_INT16*)((_check_pointer(i0, 61886))+36) = i1;
  return;
  ;
}

OOC_INT32 OOC_SymbolTable__TypeDesc_ArrayDimensions(OOC_SymbolTable__Type type) {
  register OOC_INT32 i0,i1,i2;
  OOC_INT32 dim;

  dim = 0;
  i0 = (OOC_INT32)type;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 62150)))), &_td_OOC_SymbolTable__ArrayDesc);
  if (i1) goto l3;
  i0=0;
  goto l9;
l3:
  i1=i0;i0=0;
l4_loop:
  i0 = i0+1;
  dim = i0;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 62199)))), &_td_OOC_SymbolTable__ArrayDesc, 62199)), 62205))+44);
  type = (OOC_SymbolTable__Type)i1;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 62150)))), &_td_OOC_SymbolTable__ArrayDesc);
  if (i2) goto l4_loop;
l9:
  return i0;
  ;
}

OOC_SymbolTable__Type OOC_SymbolTable__TypeDesc_Deparam(OOC_SymbolTable__Type type) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)type;
  return (OOC_SymbolTable__Type)i0;
  ;
}

OOC_SymbolTable__Type OOC_SymbolTable__TypeDesc_Bound(OOC_SymbolTable__Type type) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)type;
  return (OOC_SymbolTable__Type)i0;
  ;
}

OOC_SymbolTable__Type OOC_SymbolTable__TypeDesc_Closure(OOC_SymbolTable__Type type, OOC_SymbolTable__Type subType) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)subType;
  i0 = (OOC_INT32)OOC_SymbolTable__Expand((OOC_SymbolTable__Type)i0);
  return (OOC_SymbolTable__Type)i0;
  ;
}

static void OOC_SymbolTable__InitLinkDirective(OOC_SymbolTable__LinkDirective l) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)l;
  *(OOC_INT32*)(_check_pointer(i0, 63237)) = 0;
  return;
  ;
}

void OOC_SymbolTable__LinkDirectiveDesc_Store(OOC_SymbolTable__LinkDirective l, ADT_Storable__Writer w) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)l;
  i1 = (OOC_INT32)w;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 63381));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 63365)))), ADT_Storable__WriterDesc_WriteObject)),ADT_Storable__WriterDesc_WriteObject)((ADT_Storable__Writer)i1, (Object__Object)i0);
  return;
  ;
}

void OOC_SymbolTable__LinkDirectiveDesc_Load(OOC_SymbolTable__LinkDirective l, ADT_Storable__Reader r) {
  register OOC_INT32 i0,i1;
  Object__Object obj;

  i0 = (OOC_INT32)r;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 63519)))), ADT_Storable__ReaderDesc_ReadObject)),ADT_Storable__ReaderDesc_ReadObject)((ADT_Storable__Reader)i0, (void*)(OOC_INT32)&obj);
  i0 = (OOC_INT32)obj;
  i1 = i0==(OOC_INT32)0;
  if (i1) goto l3;
  i1 = (OOC_INT32)l;
  *(OOC_INT32*)(_check_pointer(i1, 63600)) = (_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 63614)))), &_td_OOC_SymbolTable__LinkDirectiveDesc, 63614));
  goto l4;
l3:
  i0 = (OOC_INT32)l;
  *(OOC_INT32*)(_check_pointer(i0, 63570)) = (OOC_INT32)0;
l4:
  return;
  ;
}

void OOC_SymbolTable__LinkFileDesc_Store(OOC_SymbolTable__LinkFile l, ADT_Storable__Writer w) {
  register OOC_INT32 i0,i1,i2;
  auto void OOC_SymbolTable__LinkFileDesc_Store_WriteURI(ADT_Storable__Writer w, URI__HierarchicalURI uri);
    
    void OOC_SymbolTable__LinkFileDesc_Store_WriteURI(ADT_Storable__Writer w, URI__HierarchicalURI uri) {
      register OOC_INT32 i0,i1,i2;
      Object__String8 str8;
      Object__CharsLatin1 chars;

      i0 = (OOC_INT32)uri;
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 63902)))), URI__URIDesc_ToString)),URI__URIDesc_ToString)((URI__URI)i0);
      str8 = (Object__String8)i0;
      i0 = (OOC_INT32)Object__String8Desc_CharsLatin1((Object__String8)i0);
      chars = (Object__CharsLatin1)i0;
      i1 = (OOC_INT32)w;
      i2 = OOC_ARRAY_LENGTH((_check_pointer(i0, 63975)), 0);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 63957)))), IO_BinaryRider__WriterDesc_WriteString)),IO_BinaryRider__WriterDesc_WriteString)((IO_BinaryRider__Writer)i1, (void*)(_check_pointer(i0, 63975)), i2);
      return;
      ;
    }


  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)l;
  OOC_SymbolTable__LinkDirectiveDesc_Store((OOC_SymbolTable__LinkDirective)i1, (ADT_Storable__Writer)i0);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 64045))+4);
  OOC_SymbolTable__LinkFileDesc_Store_WriteURI((ADT_Storable__Writer)i0, (URI__HierarchicalURI)i1);
  i0 = (OOC_INT32)l;
  i1 = (OOC_INT32)w;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 64072))+8);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 64059)))), IO_BinaryRider__WriterDesc_WriteStr)),IO_BinaryRider__WriterDesc_WriteStr)((IO_BinaryRider__Writer)i1, (Object__String)i2);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 64107))+12);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 64094)))), IO_BinaryRider__WriterDesc_WriteStr)),IO_BinaryRider__WriterDesc_WriteStr)((IO_BinaryRider__Writer)i1, (Object__String)i0);
  return;
  ;
}

static Object__String OOC_SymbolTable__ReadString8(ADT_Storable__Reader r) {
  register OOC_INT32 i0,i1;
  Object__String str;

  i0 = (OOC_INT32)r;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 64241)))), IO_BinaryRider__ReaderDesc_ReadStr)),IO_BinaryRider__ReaderDesc_ReadStr)((IO_BinaryRider__Reader)i0, (void*)(OOC_INT32)&str);
  i0 = (OOC_INT32)str;
  i1 = i0==(OOC_INT32)0;
  if (i1) goto l3;
  return (Object__String)i0;
  goto l4;
l3:
  return (Object__String)(OOC_INT32)0;
l4:
  _failed_function(64148); return 0;
  ;
}

void OOC_SymbolTable__LinkFileDesc_Load(OOC_SymbolTable__LinkFile l, ADT_Storable__Reader r) {
  register OOC_INT32 i0,i1,i2;
  auto void OOC_SymbolTable__LinkFileDesc_Load_ReadURI(volatile ADT_Storable__Reader r, volatile URI__HierarchicalURI *uri);
    
    void OOC_SymbolTable__LinkFileDesc_Load_ReadURI(volatile ADT_Storable__Reader r, volatile URI__HierarchicalURI *uri) {
      register OOC_INT32 i0,i1;
      volatile OOC_CHAR8 b[1024];
      volatile URI__URI u;
      jmp_buf _target0;
      Exception__Context _context0;

      i0 = (OOC_INT32)r;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 64584)))), IO_BinaryRider__ReaderDesc_ReadString)),IO_BinaryRider__ReaderDesc_ReadString)((IO_BinaryRider__Reader)i0, (void*)(OOC_INT32)b, 1024);
      {
        Exception__PushContext(&_context0, &_target0);
        if (!setjmp(_target0)) goto l7;
        Exception__PopContext(1);
        i0 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG(((OOC_INT32)Exception__Current()))), &_td_Exception__ParseErrorDesc);
        if (i0) goto l5;
        Exception__ActivateContext();
        goto l6;
l5:
        _assert(0u, 127, 64815);
l6:
        Exception__Clear();
        goto l8;
l7:
        i0 = (OOC_INT32)OOC_SymbolTable__emptyBaseURI;
        i0 = (OOC_INT32)URI_Parser__NewURILatin1((void*)(OOC_INT32)b, 1024, (URI__HierarchicalURI)i0);
        u = (URI__URI)i0;
        Exception__PopContext(1);
l8:;
      }
      i0 = (OOC_INT32)u;
      i1 = (OOC_INT32)OOC_SymbolTable__emptyBaseURI;
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 64937)))), &_td_URI__HierarchicalURIDesc, 64937)), 64953)))), URI__HierarchicalURIDesc_MakeRelative)),URI__HierarchicalURIDesc_MakeRelative)((URI__HierarchicalURI)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 64937)))), &_td_URI__HierarchicalURIDesc, 64937)), (URI__HierarchicalURI)i1);
      u = (URI__URI)i0;
      *uri = (URI__HierarchicalURI)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 65003)))), &_td_URI__HierarchicalURIDesc, 65003));
      return;
      ;
    }


  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)l;
  OOC_SymbolTable__LinkDirectiveDesc_Load((OOC_SymbolTable__LinkDirective)i1, (ADT_Storable__Reader)i0);
  OOC_SymbolTable__LinkFileDesc_Load_ReadURI((ADT_Storable__Reader)i0, (void*)((_check_pointer(i1, 65084))+4));
  i0 = (OOC_INT32)l;
  i1 = (OOC_INT32)r;
  i2 = (OOC_INT32)OOC_SymbolTable__ReadString8((ADT_Storable__Reader)i1);
  *(OOC_INT32*)((_check_pointer(i0, 65098))+8) = i2;
  i1 = (OOC_INT32)OOC_SymbolTable__ReadString8((ADT_Storable__Reader)i1);
  *(OOC_INT32*)((_check_pointer(i0, 65136))+12) = i1;
  return;
  ;
}

void OOC_SymbolTable__LinkLibDesc_Store(OOC_SymbolTable__LinkLib l, ADT_Storable__Writer w) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  OOC_INT32 i;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)l;
  OOC_SymbolTable__LinkDirectiveDesc_Store((OOC_SymbolTable__LinkDirective)i1, (ADT_Storable__Writer)i0);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 65318))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 65305)))), IO_BinaryRider__WriterDesc_WriteStr)),IO_BinaryRider__WriterDesc_WriteStr)((IO_BinaryRider__Writer)i0, (Object__String)i2);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 65352))+12);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 65339)))), IO_BinaryRider__WriterDesc_WriteStr)),IO_BinaryRider__WriterDesc_WriteStr)((IO_BinaryRider__Writer)i0, (Object__String)i2);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 65387))+16);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 65374)))), IO_BinaryRider__WriterDesc_WriteStr)),IO_BinaryRider__WriterDesc_WriteStr)((IO_BinaryRider__Writer)i0, (Object__String)i2);
  i2 = *(OOC_INT32*)((_check_pointer(i1, 65422))+20);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 65409)))), IO_BinaryRider__WriterDesc_WriteNum)),IO_BinaryRider__WriterDesc_WriteNum)((IO_BinaryRider__Writer)i0, i2);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 65454))+8);
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 65468)), 0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 65436)))), IO_BinaryRider__WriterDesc_WriteNum)),IO_BinaryRider__WriterDesc_WriteNum)((IO_BinaryRider__Writer)i0, i2);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 65497))+8);
  i = 0;
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 65511)), 0);
  i3 = 0<i2;
  if (!i3) goto l8;
  i3=0;
l3_loop:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 65539))+8);
  i4 = _check_pointer(i4, 65553);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 65553))*4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 65526)))), IO_BinaryRider__WriterDesc_WriteStr)),IO_BinaryRider__WriterDesc_WriteStr)((IO_BinaryRider__Writer)i0, (Object__String)i4);
  i3 = i3+1;
  i = i3;
  i4 = i3<i2;
  if (i4) goto l3_loop;
l8:
  return;
  ;
}

void OOC_SymbolTable__LinkLibDesc_Load(OOC_SymbolTable__LinkLib l, ADT_Storable__Reader r) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
  OOC_INT32 len;
  OOC_INT32 i;

  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)l;
  OOC_SymbolTable__LinkDirectiveDesc_Load((OOC_SymbolTable__LinkDirective)i1, (ADT_Storable__Reader)i0);
  i2 = (OOC_INT32)OOC_SymbolTable__ReadString8((ADT_Storable__Reader)i0);
  *(OOC_INT32*)((_check_pointer(i1, 65705))+4) = i2;
  i2 = (OOC_INT32)OOC_SymbolTable__ReadString8((ADT_Storable__Reader)i0);
  *(OOC_INT32*)((_check_pointer(i1, 65742))+12) = i2;
  i2 = (OOC_INT32)OOC_SymbolTable__ReadString8((ADT_Storable__Reader)i0);
  *(OOC_INT32*)((_check_pointer(i1, 65780))+16) = i2;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 65818)))), IO_BinaryRider__ReaderDesc_ReadNum)),IO_BinaryRider__ReaderDesc_ReadNum)((IO_BinaryRider__Reader)i0, (void*)((_check_pointer(i1, 65830))+20));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 65843)))), IO_BinaryRider__ReaderDesc_ReadNum)),IO_BinaryRider__ReaderDesc_ReadNum)((IO_BinaryRider__Reader)i0, (void*)(OOC_INT32)&len);
  i2 = len;
  *(OOC_INT32*)((_check_pointer(i1, 65870))+8) = ((OOC_INT32)RT0__NewObject(_td_Object__StringArrayPtr.baseTypes[0], i2));
  i = 0;
  i3 = 0<i2;
  if (!i3) goto l8;
  i3=0;
l3_loop:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 65926))+8);
  i4 = _check_pointer(i4, 65940);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i6 = (OOC_INT32)OOC_SymbolTable__ReadString8((ADT_Storable__Reader)i0);
  *(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 65940))*4) = i6;
  i3 = i3+1;
  i = i3;
  i4 = i3<i2;
  if (i4) goto l3_loop;
l8:
  return;
  ;
}

void OOC_SymbolTable__InitModule(OOC_SymbolTable__Module mod, OOC_SymbolTable__Name name, OOC_Doc__Document docString, OOC_INT8 _class, OOC_INT8 callConv, OOC_AST__Node moduleAST, OOC_SymbolTable__ProcDecl bodyDecl) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)docString;
  i1 = (OOC_INT32)name;
  i2 = (OOC_INT32)mod;
  OOC_SymbolTable__InitDeclaration((OOC_SymbolTable__Declaration)i2, (OOC_SymbolTable__Item)(OOC_INT32)0, (OOC_SymbolTable__Name)i1, 0, 1, (OOC_Doc__Document)i0);
  *(OOC_INT32*)((_check_pointer(i2, 66268))+48) = (OOC_INT32)0;
  i0 = _class;
  *(OOC_INT8*)((_check_pointer(i2, 66288))+52) = i0;
  *(OOC_INT32*)((_check_pointer(i2, 66313))+56) = (OOC_INT32)0;
  i0 = callConv;
  *(OOC_INT8*)((_check_pointer(i2, 66342))+60) = i0;
  *(OOC_INT32*)((_check_pointer(i2, 66373))+64) = (OOC_INT32)0;
  *(OOC_INT32*)((_check_pointer(i2, 66405))+68) = 0;
  *(OOC_INT32*)((_check_pointer(i2, 66432))+72) = (OOC_INT32)0;
  i0 = (OOC_INT32)moduleAST;
  *(OOC_INT32*)((_check_pointer(i2, 66463))+76) = i0;
  i0 = (OOC_INT32)bodyDecl;
  *(OOC_INT32*)((_check_pointer(i2, 66496))+80) = i0;
  return;
  ;
}

void OOC_SymbolTable__ModuleDesc_Store(OOC_SymbolTable__Module mod, ADT_Storable__Writer w) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)mod;
  OOC_SymbolTable__DeclarationDesc_Store((OOC_SymbolTable__Declaration)i1, (ADT_Storable__Writer)i0);
  i2 = *(OOC_INT8*)((_check_pointer(i1, 66686))+52);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 66670)))), IO_BinaryRider__WriterDesc_WriteSInt)),IO_BinaryRider__WriterDesc_WriteSInt)((IO_BinaryRider__Writer)i0, i2);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 66716))+56);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 66701)))), IO_BinaryRider__WriterDesc_WriteStr)),IO_BinaryRider__WriterDesc_WriteStr)((IO_BinaryRider__Writer)i0, (Object__String)i2);
  i2 = *(OOC_INT8*)((_check_pointer(i1, 66752))+60);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 66736)))), IO_BinaryRider__WriterDesc_WriteSInt)),IO_BinaryRider__WriterDesc_WriteSInt)((IO_BinaryRider__Writer)i0, i2);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 66788))+64);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 66770)))), ADT_Storable__WriterDesc_WriteObject)),ADT_Storable__WriterDesc_WriteObject)((ADT_Storable__Writer)i0, (Object__Object)i1);
  return;
  ;
}

void OOC_SymbolTable__ModuleDesc_Load(OOC_SymbolTable__Module mod, ADT_Storable__Reader r) {
  register OOC_INT32 i0,i1,i2;
  Object__Object obj;

  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)mod;
  OOC_SymbolTable__DeclarationDesc_Load((OOC_SymbolTable__Declaration)i1, (ADT_Storable__Reader)i0);
  *(OOC_INT32*)((_check_pointer(i1, 66953))+48) = (OOC_INT32)0;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 66971)))), IO_BinaryRider__ReaderDesc_ReadSInt)),IO_BinaryRider__ReaderDesc_ReadSInt)((IO_BinaryRider__Reader)i0, (void*)((_check_pointer(i1, 66986))+52));
  i2 = (OOC_INT32)OOC_SymbolTable__ReadString8((ADT_Storable__Reader)i0);
  *(OOC_INT32*)((_check_pointer(i1, 67003))+56) = i2;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 67040)))), IO_BinaryRider__ReaderDesc_ReadSInt)),IO_BinaryRider__ReaderDesc_ReadSInt)((IO_BinaryRider__Reader)i0, (void*)((_check_pointer(i1, 67055))+60));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 67073)))), ADT_Storable__ReaderDesc_ReadObject)),ADT_Storable__ReaderDesc_ReadObject)((ADT_Storable__Reader)i0, (void*)(OOC_INT32)&obj);
  i0 = (OOC_INT32)obj;
  i2 = i0==(OOC_INT32)0;
  if (i2) goto l3;
  *(OOC_INT32*)((_check_pointer(i1, 67168))+64) = (_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 67192)))), &_td_OOC_SymbolTable__LinkDirectiveDesc, 67192));
  goto l4;
l3:
  *(OOC_INT32*)((_check_pointer(i1, 67126))+64) = (OOC_INT32)0;
l4:
  *(OOC_INT32*)((_check_pointer(i1, 67223))+72) = (OOC_INT32)0;
  *(OOC_INT32*)((_check_pointer(i1, 67254))+76) = (OOC_INT32)0;
  return;
  ;
}

void OOC_SymbolTable__ModuleDesc_SetNamespace(OOC_SymbolTable__Module mod, OOC_SymbolTable__Namespace ns) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)mod;
  i1 = (OOC_INT32)ns;
  *(OOC_INT32*)((_check_pointer(i0, 67430))+48) = i1;
  return;
  ;
}

void OOC_SymbolTable__ModuleDesc_SetLibraryName(OOC_SymbolTable__Module mod, Object__String name) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)mod;
  i1 = (OOC_INT32)name;
  *(OOC_INT32*)((_check_pointer(i0, 67534))+56) = i1;
  return;
  ;
}

Object__String OOC_SymbolTable__ModuleDesc_ClassToString(OOC_SymbolTable__Module mod) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)mod;
  i0 = *(OOC_INT8*)((_check_pointer(i0, 67649))+52);
  switch (i0) {
  case 0:
    return (Object__String)((OOC_INT32)_c0);
    goto l7;
  case 1:
    return (Object__String)((OOC_INT32)_c1);
    goto l7;
  case 2:
    return (Object__String)((OOC_INT32)_c2);
    goto l7;
  case 3:
    return (Object__String)((OOC_INT32)_c3);
    goto l7;
  default:
    _failed_case(i0, 67641);
    goto l7;
  }
l7:
  _failed_function(67603); return 0;
  ;
}

Object__String OOC_SymbolTable__ModuleDesc_CallConvToString(OOC_SymbolTable__Module mod) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)mod;
  i0 = *(OOC_INT8*)((_check_pointer(i0, 67911))+60);
  switch (i0) {
  case (-1):
    return (Object__String)((OOC_INT32)_c4);
    goto l9;
  case 0:
    return (Object__String)((OOC_INT32)_c5);
    goto l9;
  case 1:
    return (Object__String)((OOC_INT32)_c6);
    goto l9;
  case 2:
    return (Object__String)((OOC_INT32)_c7);
    goto l9;
  case 3:
    return (Object__String)((OOC_INT32)_c8);
    goto l9;
  case 4:
    return (Object__String)((OOC_INT32)_c9);
    goto l9;
  default:
    _failed_case(i0, 67903);
    goto l9;
  }
l9:
  _failed_function(67862); return 0;
  ;
}

static OOC_SymbolTable__LinkFile OOC_SymbolTable__NewLinkFile(URI__HierarchicalURI file, Object__String prefixOption, Object__String suffixOption) {
  register OOC_INT32 i0,i1;
  OOC_SymbolTable__LinkFile l;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_SymbolTable__LinkFile.baseTypes[0]);
  l = (OOC_SymbolTable__LinkFile)i0;
  OOC_SymbolTable__InitLinkDirective((OOC_SymbolTable__LinkDirective)i0);
  i1 = (OOC_INT32)file;
  *(OOC_INT32*)((_check_pointer(i0, 68401))+4) = i1;
  i1 = (OOC_INT32)prefixOption;
  *(OOC_INT32*)((_check_pointer(i0, 68422))+8) = i1;
  i1 = (OOC_INT32)suffixOption;
  *(OOC_INT32*)((_check_pointer(i0, 68459))+12) = i1;
  return (OOC_SymbolTable__LinkFile)i0;
  ;
}

static OOC_SymbolTable__LinkLib OOC_SymbolTable__NewLinkLib(Object__String libraryName, Object__StringArrayPtr dependencies, Object__String prefixOption, Object__String suffixOption, OOC_INT32 type) {
  register OOC_INT32 i0,i1;
  OOC_SymbolTable__LinkLib l;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_SymbolTable__LinkLib.baseTypes[0]);
  l = (OOC_SymbolTable__LinkLib)i0;
  OOC_SymbolTable__InitLinkDirective((OOC_SymbolTable__LinkDirective)i0);
  i1 = (OOC_INT32)libraryName;
  *(OOC_INT32*)((_check_pointer(i0, 68806))+4) = i1;
  i1 = (OOC_INT32)dependencies;
  *(OOC_INT32*)((_check_pointer(i0, 68841))+8) = i1;
  i1 = (OOC_INT32)prefixOption;
  *(OOC_INT32*)((_check_pointer(i0, 68878))+12) = i1;
  i1 = (OOC_INT32)suffixOption;
  *(OOC_INT32*)((_check_pointer(i0, 68915))+16) = i1;
  i1 = type;
  *(OOC_INT32*)((_check_pointer(i0, 68952))+20) = i1;
  return (OOC_SymbolTable__LinkLib)i0;
  ;
}

static void OOC_SymbolTable__AddLinkDirective(OOC_SymbolTable__LinkDirective *list, OOC_SymbolTable__LinkDirective l) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)*list;
  i1 = i0==(OOC_INT32)0;
  if (i1) goto l3;
  i1 = (OOC_INT32)l;
  OOC_SymbolTable__AddLinkDirective((void*)(_check_pointer(i0, 69180)), (OOC_SymbolTable__LinkDirective)i1);
  goto l4;
l3:
  i0 = (OOC_INT32)l;
  *(OOC_INT32*)(_check_pointer(i0, 69112)) = (OOC_INT32)0;
  *list = (OOC_SymbolTable__LinkDirective)i0;
l4:
  return;
  ;
}

void OOC_SymbolTable__ModuleDesc_AddLinkFile(OOC_SymbolTable__Module mod, URI__HierarchicalURI file, Object__String prefixOption, Object__String suffixOption) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)file;
  _assert((i0!=(OOC_INT32)0), 127, 69374);
  i1 = (OOC_INT32)prefixOption;
  i2 = (OOC_INT32)suffixOption;
  i0 = (OOC_INT32)OOC_SymbolTable__NewLinkFile((URI__HierarchicalURI)i0, (Object__String)i1, (Object__String)i2);
  i1 = (OOC_INT32)mod;
  OOC_SymbolTable__AddLinkDirective((void*)((_check_pointer(i1, 69420))+64), (OOC_SymbolTable__LinkDirective)i0);
  return;
  ;
}

void OOC_SymbolTable__ModuleDesc_AddLinkLib(OOC_SymbolTable__Module mod, Object__String libraryName, Object__StringArrayPtr dependencies, Object__String prefixOption, Object__String suffixOption, OOC_INT32 type) {
  register OOC_INT32 i0,i1,i2,i3,i4;

  i0 = (OOC_INT32)libraryName;
  _assert((i0!=(OOC_INT32)0), 127, 69798);
  i1 = (OOC_INT32)dependencies;
  i2 = (OOC_INT32)prefixOption;
  i3 = (OOC_INT32)suffixOption;
  i4 = type;
  i0 = (OOC_INT32)OOC_SymbolTable__NewLinkLib((Object__String)i0, (Object__StringArrayPtr)i1, (Object__String)i2, (Object__String)i3, i4);
  i1 = (OOC_INT32)mod;
  OOC_SymbolTable__AddLinkDirective((void*)((_check_pointer(i1, 69851))+64), (OOC_SymbolTable__LinkDirective)i0);
  return;
  ;
}

OOC_CHAR8 OOC_SymbolTable__ModuleDesc_NoObjectFile(OOC_SymbolTable__Module mod) {
  register OOC_INT32 i0,i1;
  OOC_SymbolTable__LinkDirective l;

  i0 = (OOC_INT32)mod;
  i1 = *(OOC_INT8*)((_check_pointer(i0, 70510))+52);
  i1 = i1==3;
  if (i1) goto l3;
  i1 = *(OOC_INT8*)((_check_pointer(i0, 70539))+52);
  i1 = i1==2;
  
  goto l5;
l3:
  i1=1u;
l5:
  if (i1) goto l7;
  return 0u;
  goto l25;
l7:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 70578))+64);
  l = (OOC_SymbolTable__LinkDirective)i0;
  i1 = i0!=(OOC_INT32)0;
  if (i1) goto l10;
  i1=0u;
  goto l12;
l10:
  i1 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 70623)))), &_td_OOC_SymbolTable__LinkFileDesc));
  
l12:
  if (!i1) goto l24;
l15_loop:
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 70653));
  l = (OOC_SymbolTable__LinkDirective)i0;
  i1 = i0!=(OOC_INT32)0;
  if (i1) goto l18;
  i1=0u;
  goto l20;
l18:
  i1 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 70623)))), &_td_OOC_SymbolTable__LinkFileDesc));
  
l20:
  if (i1) goto l15_loop;
l24:
  return (i0==(OOC_INT32)0);
l25:
  _failed_function(70042); return 0;
  ;
}

URI__HierarchicalURI OOC_SymbolTable__ModuleDesc_GetExternalSource(OOC_SymbolTable__Module mod, URI__HierarchicalURI rootURI) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_SymbolTable__LinkDirective l;

  i0 = (OOC_INT32)mod;
  i1 = *(OOC_INT8*)((_check_pointer(i0, 71183))+52);
  i1 = i1==2;
  if (i1) goto l3;
  i1 = *(OOC_INT8*)((_check_pointer(i0, 71211))+52);
  i1 = i1==3;
  
  goto l4;
l3:
  i1=1u;
l4:
  _assert(i1, 127, 71171);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 71248))+64);
  l = (OOC_SymbolTable__LinkDirective)i0;
  i1 = i0!=(OOC_INT32)0;
  if (i1) goto l7;
  i1=0u;
  goto l9;
l7:
  i1 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 71292)))), &_td_OOC_SymbolTable__LinkFileDesc));
  
l9:
  if (!i1) goto l21;
l12_loop:
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 71320));
  l = (OOC_SymbolTable__LinkDirective)i0;
  i1 = i0!=(OOC_INT32)0;
  if (i1) goto l15;
  i1=0u;
  goto l17;
l15:
  i1 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 71292)))), &_td_OOC_SymbolTable__LinkFileDesc));
  
l17:
  if (i1) goto l12_loop;
l21:
  i1 = i0==(OOC_INT32)0;
  if (i1) goto l24;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 71401)))), &_td_OOC_SymbolTable__LinkFileDesc, 71401)), 71410))+4);
  _assert((i1!=(OOC_INT32)0), 127, 71391);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 71433)))), &_td_OOC_SymbolTable__LinkFileDesc, 71433)), 71442))+4);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 71433)))), &_td_OOC_SymbolTable__LinkFileDesc, 71433)), 71442))+4);
  i3 = (OOC_INT32)rootURI;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 71448)))), URI__HierarchicalURIDesc_ResolveRelative)),URI__HierarchicalURIDesc_ResolveRelative)((URI__HierarchicalURI)i2, (URI__HierarchicalURI)i3);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 71492)))), &_td_OOC_SymbolTable__LinkFileDesc, 71492)), 71501))+4);
  return (URI__HierarchicalURI)i0;
  goto l25;
l24:
  return (URI__HierarchicalURI)(OOC_INT32)0;
l25:
  _failed_function(70777); return 0;
  ;
}

OOC_INT8 OOC_SymbolTable__StringToCallConv(Object__String str) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)str;
  i1 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 71614)))), Object__StringDesc_Equals)),Object__StringDesc_Equals)((Object__String)i0, (Object__Object)((OOC_INT32)_c10));
  if (i1) goto l11;
  i1 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 71668)))), Object__StringDesc_Equals)),Object__StringDesc_Equals)((Object__String)i0, (Object__Object)((OOC_INT32)_c11));
  if (i1) goto l9;
  i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 71732)))), Object__StringDesc_Equals)),Object__StringDesc_Equals)((Object__String)i0, (Object__Object)((OOC_INT32)_c12));
  if (i0) goto l7;
  return (-1);
  goto l12;
l7:
  return 4;
  goto l12;
l9:
  return 3;
  goto l12;
l11:
  return 2;
l12:
  _failed_function(71554); return 0;
  ;
}

void OOC_SymbolTable__InitImport(OOC_SymbolTable__Import import, OOC_SymbolTable__Item parent, OOC_SymbolTable__Name name, OOC_INT32 visibleFrom, OOC_Doc__Document docString, OOC_SymbolTable__Name moduleName) {
  register OOC_INT32 i0,i1,i2,i3,i4;

  i0 = (OOC_INT32)docString;
  i1 = visibleFrom;
  i2 = (OOC_INT32)name;
  i3 = (OOC_INT32)parent;
  i4 = (OOC_INT32)import;
  OOC_SymbolTable__InitDeclaration((OOC_SymbolTable__Declaration)i4, (OOC_SymbolTable__Item)i3, (OOC_SymbolTable__Name)i2, i1, 0, (OOC_Doc__Document)i0);
  i0 = (OOC_INT32)moduleName;
  *(OOC_INT32*)((_check_pointer(i4, 72140))+48) = i0;
  *(OOC_INT32*)((_check_pointer(i4, 72178))+52) = (OOC_INT32)0;
  return;
  ;
}

void OOC_SymbolTable__ImportDesc_SetExternalSymTab(OOC_SymbolTable__Import import, OOC_SymbolTable__Module symTab) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)import;
  i1 = (OOC_INT32)symTab;
  *(OOC_INT32*)((_check_pointer(i0, 72304))+52) = i1;
  i1 = *(OOC_INT32*)((_check_pointer(i1, 72365))+68);
  *(OOC_INT32*)((_check_pointer(i0, 72342))+56) = i1;
  return;
  ;
}

OOC_CHAR8 OOC_SymbolTable__ImportDesc_IsInternalImport(OOC_SymbolTable__Import import) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)import;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 72630))+48);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 72642))+12);
  return ((
  _cmp8((const void*)(_check_pointer(i0, 72647)),(const void*)"SYSTEM"))==0);
  ;
}

void OOC_SymbolTable__ImportDesc_Store(OOC_SymbolTable__Import import, ADT_Storable__Writer w) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)import;
  OOC_SymbolTable__DeclarationDesc_Store((OOC_SymbolTable__Declaration)i1, (ADT_Storable__Writer)i0);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 72818))+48);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 72797)))), ADT_Storable__WriterDesc_WriteObject)),ADT_Storable__WriterDesc_WriteObject)((ADT_Storable__Writer)i0, (Object__Object)i2);
  i1 = *(OOC_INT32*)((_check_pointer(i1, 72857))+56);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 72838)))), IO_BinaryRider__WriterDesc_WriteLInt)),IO_BinaryRider__WriterDesc_WriteLInt)((IO_BinaryRider__Writer)i0, i1);
  return;
  ;
}

void OOC_SymbolTable__ImportDesc_Load(OOC_SymbolTable__Import import, ADT_Storable__Reader r) {
  register OOC_INT32 i0,i1,i2;
  Object__Object obj;

  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)import;
  OOC_SymbolTable__DeclarationDesc_Load((OOC_SymbolTable__Declaration)i1, (ADT_Storable__Reader)i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 73024)))), ADT_Storable__ReaderDesc_ReadObject)),ADT_Storable__ReaderDesc_ReadObject)((ADT_Storable__Reader)i0, (void*)(OOC_INT32)&obj);
  i2 = (OOC_INT32)obj;
  *(OOC_INT32*)((_check_pointer(i1, 73054))+48) = (_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 73074)))), &_td_OOC_SymbolTable__NameDesc, 73074));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 73086)))), IO_BinaryRider__ReaderDesc_ReadLInt)),IO_BinaryRider__ReaderDesc_ReadLInt)((IO_BinaryRider__Reader)i0, (void*)((_check_pointer(i1, 73104))+56));
  return;
  ;
}

void OOC_SymbolTable__InitConstDecl(OOC_SymbolTable__ConstDecl constDecl, OOC_SymbolTable__Item parent, OOC_SymbolTable__Name name, OOC_INT32 visibleFrom, OOC_INT8 exportMark, OOC_Doc__Document docString, Object_Boxed__Object value, OOC_SymbolTable__PredefType type, OOC_AST__Node constExpr) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;

  i0 = (OOC_INT32)docString;
  i1 = exportMark;
  i2 = visibleFrom;
  i3 = (OOC_INT32)name;
  i4 = (OOC_INT32)parent;
  i5 = (OOC_INT32)constDecl;
  OOC_SymbolTable__InitDeclaration((OOC_SymbolTable__Declaration)i5, (OOC_SymbolTable__Item)i4, (OOC_SymbolTable__Name)i3, i2, i1, (OOC_Doc__Document)i0);
  i0 = (OOC_INT32)value;
  *(OOC_INT32*)((_check_pointer(i5, 73571))+48) = i0;
  i0 = (OOC_INT32)type;
  *(OOC_INT32*)((_check_pointer(i5, 73602))+52) = i0;
  i0 = (OOC_INT32)constExpr;
  *(OOC_INT32*)((_check_pointer(i5, 73631))+56) = i0;
  return;
  ;
}

void OOC_SymbolTable__ConstDeclDesc_SetValueType(OOC_SymbolTable__ConstDecl constDecl, Object_Boxed__Object value, OOC_SymbolTable__PredefType type) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)constDecl;
  i1 = (OOC_INT32)value;
  *(OOC_INT32*)((_check_pointer(i0, 73790))+48) = i1;
  i1 = (OOC_INT32)type;
  *(OOC_INT32*)((_check_pointer(i0, 73820))+52) = i1;
  return;
  ;
}

void OOC_SymbolTable__ConstDeclDesc_Store(OOC_SymbolTable__ConstDecl constDecl, ADT_Storable__Writer w) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)constDecl;
  OOC_SymbolTable__DeclarationDesc_Store((OOC_SymbolTable__Declaration)i1, (ADT_Storable__Writer)i0);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 73998))+48);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 73974)))), ADT_Storable__WriterDesc_WriteObject)),ADT_Storable__WriterDesc_WriteObject)((ADT_Storable__Writer)i0, (Object__Object)i2);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 74025))+52);
  i2 = i2==(OOC_INT32)0;
  if (i2) goto l3;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 74257))+52);
  i1 = *(OOC_INT16*)((_check_pointer(i1, 74263))+40);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 74236)))), IO_BinaryRider__WriterDesc_WriteNum)),IO_BinaryRider__WriterDesc_WriteNum)((IO_BinaryRider__Writer)i0, i1);
  goto l4;
l3:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 74204)))), IO_BinaryRider__WriterDesc_WriteNum)),IO_BinaryRider__WriterDesc_WriteNum)((IO_BinaryRider__Writer)i0, (-1));
l4:
  return;
  ;
}

void OOC_SymbolTable__ConstDeclDesc_Load(OOC_SymbolTable__ConstDecl constDecl, ADT_Storable__Reader r) {
  register OOC_INT32 i0,i1,i2,i3;
  Object__Object obj;
  OOC_INT32 id;

  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)constDecl;
  OOC_SymbolTable__DeclarationDesc_Load((OOC_SymbolTable__Declaration)i1, (ADT_Storable__Reader)i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 74454)))), ADT_Storable__ReaderDesc_ReadObject)),ADT_Storable__ReaderDesc_ReadObject)((ADT_Storable__Reader)i0, (void*)(OOC_INT32)&obj);
  i2 = (OOC_INT32)obj;
  i3 = i2==(OOC_INT32)0;
  if (i3) goto l3;
  *(OOC_INT32*)((_check_pointer(i1, 74552))+48) = (_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 74573)))), &_td_Object_Boxed__ObjectDesc, 74573));
  goto l4;
l3:
  *(OOC_INT32*)((_check_pointer(i1, 74513))+48) = (OOC_INT32)0;
l4:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 74595)))), IO_BinaryRider__ReaderDesc_ReadNum)),IO_BinaryRider__ReaderDesc_ReadNum)((IO_BinaryRider__Reader)i0, (void*)(OOC_INT32)&id);
  i0 = id;
  i2 = i0==(-1);
  if (i2) goto l7;
  i2 = (OOC_INT32)OOC_SymbolTable__predefIdToType;
  i2 = _check_pointer(i2, 74765);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i0 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(i0, i3, OOC_UINT32, 74765))*4);
  *(OOC_INT32*)((_check_pointer(i1, 74741))+52) = i0;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 74794))+52);
  _assert((i0!=(OOC_INT32)0), 127, 74777);
  goto l8;
l7:
  *(OOC_INT32*)((_check_pointer(i1, 74702))+52) = (OOC_INT32)0;
l8:
  *(OOC_INT32*)((_check_pointer(i1, 74830))+56) = (OOC_INT32)0;
  return;
  ;
}

void OOC_SymbolTable__InitExceptionName(OOC_SymbolTable__ExceptionName exceptionName, OOC_SymbolTable__Item parent, OOC_SymbolTable__Type type) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)parent;
  i1 = (OOC_INT32)exceptionName;
  OOC_SymbolTable__InitItem((OOC_SymbolTable__Item)i1, (OOC_SymbolTable__Item)i0);
  i0 = (OOC_INT32)type;
  *(OOC_INT32*)((_check_pointer(i1, 75043))+24) = i0;
  *(OOC_INT32*)((_check_pointer(i1, 75083))+20) = i0;
  return;
  ;
}

void OOC_SymbolTable__ExceptionNameDesc_Store(OOC_SymbolTable__ExceptionName exceptionName, ADT_Storable__Writer w) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)exceptionName;
  OOC_SymbolTable__ItemDesc_Store((OOC_SymbolTable__Item)i1, (ADT_Storable__Writer)i0);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 75346))+24);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 75326))+20);
  OOC_SymbolTable__WriteType((ADT_Storable__Writer)i0, (OOC_SymbolTable__Type)i1, (OOC_SymbolTable__Type)i2);
  return;
  ;
}

void OOC_SymbolTable__ExceptionNameDesc_Load(OOC_SymbolTable__ExceptionName exceptionName, ADT_Storable__Reader r) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)exceptionName;
  OOC_SymbolTable__ItemDesc_Load((OOC_SymbolTable__Item)i1, (ADT_Storable__Reader)i0);
  OOC_SymbolTable__ReadType((ADT_Storable__Reader)i0, (void*)((_check_pointer(i1, 75527))+20), (void*)((_check_pointer(i1, 75547))+24));
  return;
  ;
}

void OOC_SymbolTable__VarDeclDesc_SetType(OOC_SymbolTable__VarDecl varDecl, OOC_SymbolTable__Type type) {
  register OOC_INT32 i0,i1,i2,i3;
  auto OOC_CHAR8 OOC_SymbolTable__VarDeclDesc_SetType_PassPerReference(OOC_SymbolTable__Type type);
    
    OOC_CHAR8 OOC_SymbolTable__VarDeclDesc_SetType_PassPerReference(OOC_SymbolTable__Type type) {
      register OOC_INT32 i0,i1;

      i0 = (OOC_INT32)type;
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 75708)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
      type = (OOC_SymbolTable__Type)i0;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 75739)))), &_td_OOC_SymbolTable__ArrayDesc);
      if (i1) goto l3;
      i0 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 75758)))), &_td_OOC_SymbolTable__RecordDesc);
      
      goto l4;
l3:
      i0=1u;
l4:
      return i0;
      ;
    }


  i0 = (OOC_INT32)varDecl;
  i1 = (OOC_INT32)type;
  *(OOC_INT32*)((_check_pointer(i0, 75817))+48) = i1;
  i2 = _check_pointer(i0, 75844);
  i3 = *(OOC_UINT8*)((_check_pointer(i0, 75883))+56);
  if (i3) goto l3;
  i0=0u;
  goto l8;
l3:
  i0 = *(OOC_UINT8*)((_check_pointer(i0, 75915))+59);
  if (i0) goto l6;
  i0 = OOC_SymbolTable__VarDeclDesc_SetType_PassPerReference((OOC_SymbolTable__Type)i1);
  
  goto l8;
l6:
  i0=1u;
l8:
  *(OOC_UINT8*)(i2+60) = i0;
  i0 = (OOC_INT32)varDecl;
  i1 = _check_pointer(i0, 75968);
  i2 = *(OOC_UINT8*)((_check_pointer(i0, 76001))+56);
  if (i2) goto l11;
  i0=0u;
  goto l13;
l11:
  i0 = *(OOC_UINT8*)((_check_pointer(i0, 76033))+59);
  i0 = !i0;
  
l13:
  if (i0) goto l15;
  i0=0u;
  goto l16;
l15:
  i0 = (OOC_INT32)type;
  i0 = OOC_SymbolTable__VarDeclDesc_SetType_PassPerReference((OOC_SymbolTable__Type)i0);
  
l16:
  *(OOC_UINT8*)(i1+61) = i0;
  i0 = (OOC_INT32)varDecl;
  i1 = _check_pointer(i0, 76092);
  i2 = *(OOC_UINT8*)((_check_pointer(i0, 76123))+60);
  if (i2) goto l19;
  i2=0u;
  goto l21;
l19:
  i2 = *(OOC_UINT8*)((_check_pointer(i0, 76162))+59);
  i2 = !i2;
  
l21:
  if (i2) goto l23;
  i0=0u;
  goto l24;
l23:
  i0 = *(OOC_UINT8*)((_check_pointer(i0, 76193))+61);
  i0 = !i0;
  
l24:
  *(OOC_UINT8*)(i1+62) = i0;
  return;
  ;
}

void OOC_SymbolTable__InitVarDecl(OOC_SymbolTable__VarDecl varDecl, OOC_SymbolTable__Item parent, OOC_SymbolTable__Name name, OOC_INT32 visibleFrom, OOC_INT8 exportMark, OOC_Doc__Document docString, OOC_CHAR8 isParameter, OOC_CHAR8 isReceiver, OOC_CHAR8 isVarParam, OOC_SymbolTable__Type type) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;

  i0 = (OOC_INT32)docString;
  i1 = exportMark;
  i2 = visibleFrom;
  i3 = (OOC_INT32)name;
  i4 = (OOC_INT32)parent;
  i5 = (OOC_INT32)varDecl;
  OOC_SymbolTable__InitDeclaration((OOC_SymbolTable__Declaration)i5, (OOC_SymbolTable__Item)i4, (OOC_SymbolTable__Name)i3, i2, i1, (OOC_Doc__Document)i0);
  i0 = (OOC_INT32)type;
  *(OOC_INT32*)((_check_pointer(i5, 76621))+52) = i0;
  i1 = isParameter;
  *(OOC_UINT8*)((_check_pointer(i5, 76655))+56) = i1;
  i1 = isReceiver;
  *(OOC_UINT8*)((_check_pointer(i5, 76696))+57) = i1;
  *(OOC_UINT8*)((_check_pointer(i5, 76735))+58) = 0u;
  i2 = isVarParam;
  *(OOC_UINT8*)((_check_pointer(i5, 76771))+59) = i2;
  *(OOC_UINT8*)((_check_pointer(i5, 76810))+63) = 0u;
  *(OOC_UINT8*)((_check_pointer(i5, 76851))+64) = 1u;
  if (!i1) goto l3;
  *(OOC_INT32*)((_check_pointer((_type_guard(i4, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 76913)))), &_td_OOC_SymbolTable__FormalParsDesc, 76913)), 76924))+40) = i5;
l3:
  OOC_SymbolTable__VarDeclDesc_SetType((OOC_SymbolTable__VarDecl)i5, (OOC_SymbolTable__Type)i0);
  return;
  ;
}

void OOC_SymbolTable__VarDeclDesc_Store(OOC_SymbolTable__VarDecl varDecl, ADT_Storable__Writer w) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)varDecl;
  OOC_SymbolTable__DeclarationDesc_Store((OOC_SymbolTable__Declaration)i1, (ADT_Storable__Writer)i0);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 77149))+52);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 77135))+48);
  OOC_SymbolTable__WriteType((ADT_Storable__Writer)i0, (OOC_SymbolTable__Type)i3, (OOC_SymbolTable__Type)i2);
  i2 = *(OOC_UINT8*)((_check_pointer(i1, 77189))+56);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 77169)))), IO_BinaryRider__WriterDesc_WriteBool)),IO_BinaryRider__WriterDesc_WriteBool)((IO_BinaryRider__Writer)i0, i2);
  i2 = *(OOC_UINT8*)((_check_pointer(i1, 77230))+57);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 77210)))), IO_BinaryRider__WriterDesc_WriteBool)),IO_BinaryRider__WriterDesc_WriteBool)((IO_BinaryRider__Writer)i0, i2);
  i2 = *(OOC_UINT8*)((_check_pointer(i1, 77270))+58);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 77250)))), IO_BinaryRider__WriterDesc_WriteBool)),IO_BinaryRider__WriterDesc_WriteBool)((IO_BinaryRider__Writer)i0, i2);
  i2 = *(OOC_UINT8*)((_check_pointer(i1, 77312))+59);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 77292)))), IO_BinaryRider__WriterDesc_WriteBool)),IO_BinaryRider__WriterDesc_WriteBool)((IO_BinaryRider__Writer)i0, i2);
  i2 = *(OOC_UINT8*)((_check_pointer(i1, 77352))+60);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 77332)))), IO_BinaryRider__WriterDesc_WriteBool)),IO_BinaryRider__WriterDesc_WriteBool)((IO_BinaryRider__Writer)i0, i2);
  i2 = *(OOC_UINT8*)((_check_pointer(i1, 77400))+61);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 77380)))), IO_BinaryRider__WriterDesc_WriteBool)),IO_BinaryRider__WriterDesc_WriteBool)((IO_BinaryRider__Writer)i0, i2);
  i2 = *(OOC_UINT8*)((_check_pointer(i1, 77442))+62);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 77422)))), IO_BinaryRider__WriterDesc_WriteBool)),IO_BinaryRider__WriterDesc_WriteBool)((IO_BinaryRider__Writer)i0, i2);
  i2 = *(OOC_UINT8*)((_check_pointer(i1, 77482))+63);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 77462)))), IO_BinaryRider__WriterDesc_WriteBool)),IO_BinaryRider__WriterDesc_WriteBool)((IO_BinaryRider__Writer)i0, i2);
  i1 = *(OOC_UINT8*)((_check_pointer(i1, 77529))+64);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 77509)))), IO_BinaryRider__WriterDesc_WriteBool)),IO_BinaryRider__WriterDesc_WriteBool)((IO_BinaryRider__Writer)i0, i1);
  return;
  ;
}

void OOC_SymbolTable__VarDeclDesc_Load(OOC_SymbolTable__VarDecl varDecl, ADT_Storable__Reader r) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)varDecl;
  OOC_SymbolTable__DeclarationDesc_Load((OOC_SymbolTable__Declaration)i1, (ADT_Storable__Reader)i0);
  OOC_SymbolTable__ReadType((ADT_Storable__Reader)i0, (void*)((_check_pointer(i1, 77690))+48), (void*)((_check_pointer(i1, 77704))+52));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 77724)))), IO_BinaryRider__ReaderDesc_ReadBool)),IO_BinaryRider__ReaderDesc_ReadBool)((IO_BinaryRider__Reader)i0, (void*)((_check_pointer(i1, 77743))+56));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 77764)))), IO_BinaryRider__ReaderDesc_ReadBool)),IO_BinaryRider__ReaderDesc_ReadBool)((IO_BinaryRider__Reader)i0, (void*)((_check_pointer(i1, 77783))+57));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 77803)))), IO_BinaryRider__ReaderDesc_ReadBool)),IO_BinaryRider__ReaderDesc_ReadBool)((IO_BinaryRider__Reader)i0, (void*)((_check_pointer(i1, 77822))+58));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 77844)))), IO_BinaryRider__ReaderDesc_ReadBool)),IO_BinaryRider__ReaderDesc_ReadBool)((IO_BinaryRider__Reader)i0, (void*)((_check_pointer(i1, 77863))+59));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 77883)))), IO_BinaryRider__ReaderDesc_ReadBool)),IO_BinaryRider__ReaderDesc_ReadBool)((IO_BinaryRider__Reader)i0, (void*)((_check_pointer(i1, 77902))+60));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 77930)))), IO_BinaryRider__ReaderDesc_ReadBool)),IO_BinaryRider__ReaderDesc_ReadBool)((IO_BinaryRider__Reader)i0, (void*)((_check_pointer(i1, 77949))+61));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 77971)))), IO_BinaryRider__ReaderDesc_ReadBool)),IO_BinaryRider__ReaderDesc_ReadBool)((IO_BinaryRider__Reader)i0, (void*)((_check_pointer(i1, 77990))+62));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 78010)))), IO_BinaryRider__ReaderDesc_ReadBool)),IO_BinaryRider__ReaderDesc_ReadBool)((IO_BinaryRider__Reader)i0, (void*)((_check_pointer(i1, 78029))+63));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 78056)))), IO_BinaryRider__ReaderDesc_ReadBool)),IO_BinaryRider__ReaderDesc_ReadBool)((IO_BinaryRider__Reader)i0, (void*)((_check_pointer(i1, 78075))+64));
  i0 = *(OOC_UINT8*)((_check_pointer(i1, 78113))+56);
  if (!i0) goto l4;
  *(OOC_INT32*)((_check_pointer(i1, 78225))+24) = (-1);
l4:
  return;
  ;
}

void OOC_SymbolTable__InitTypeDecl(OOC_SymbolTable__TypeDecl typeDecl, OOC_SymbolTable__Item parent, OOC_SymbolTable__Name name, OOC_INT32 visibleFrom, OOC_INT8 exportMark, OOC_Doc__Document docString, OOC_SymbolTable__Type type, OOC_CHAR8 isTypeParameter) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;

  i0 = (OOC_INT32)docString;
  i1 = exportMark;
  i2 = visibleFrom;
  i3 = (OOC_INT32)name;
  i4 = (OOC_INT32)parent;
  i5 = (OOC_INT32)typeDecl;
  OOC_SymbolTable__InitDeclaration((OOC_SymbolTable__Declaration)i5, (OOC_SymbolTable__Item)i4, (OOC_SymbolTable__Name)i3, i2, i1, (OOC_Doc__Document)i0);
  i0 = (OOC_INT32)type;
  *(OOC_INT32*)((_check_pointer(i5, 78654))+48) = i0;
  *(OOC_INT32*)((_check_pointer(i5, 78682))+52) = i0;
  i0 = isTypeParameter;
  *(OOC_UINT8*)((_check_pointer(i5, 78717))+56) = i0;
  return;
  ;
}

void OOC_SymbolTable__TypeDeclDesc_Store(OOC_SymbolTable__TypeDecl typeDecl, ADT_Storable__Writer w) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)typeDecl;
  OOC_SymbolTable__DeclarationDesc_Store((OOC_SymbolTable__Declaration)i1, (ADT_Storable__Writer)i0);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 78926))+52);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 78911))+48);
  OOC_SymbolTable__WriteType((ADT_Storable__Writer)i0, (OOC_SymbolTable__Type)i3, (OOC_SymbolTable__Type)i2);
  i1 = *(OOC_UINT8*)((_check_pointer(i1, 78967))+56);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 78946)))), IO_BinaryRider__WriterDesc_WriteBool)),IO_BinaryRider__WriterDesc_WriteBool)((IO_BinaryRider__Writer)i0, i1);
  return;
  ;
}

void OOC_SymbolTable__TypeDeclDesc_Load(OOC_SymbolTable__TypeDecl typeDecl, ADT_Storable__Reader r) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)typeDecl;
  OOC_SymbolTable__DeclarationDesc_Load((OOC_SymbolTable__Declaration)i1, (ADT_Storable__Reader)i0);
  OOC_SymbolTable__ReadType((ADT_Storable__Reader)i0, (void*)((_check_pointer(i1, 79133))+48), (void*)((_check_pointer(i1, 79148))+52));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 79168)))), IO_BinaryRider__ReaderDesc_ReadBool)),IO_BinaryRider__ReaderDesc_ReadBool)((IO_BinaryRider__Reader)i0, (void*)((_check_pointer(i1, 79188))+56));
  return;
  ;
}

OOC_CHAR8 OOC_SymbolTable__TypeDeclDesc_HasTypeParameters(OOC_SymbolTable__TypeDecl typeDecl) {
  register OOC_INT32 i0,i1,i2;
  OOC_SymbolTable__TypePars typePars;

  i0 = (OOC_INT32)typeDecl;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 79345))+48);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 79350))+28);
  typePars = (OOC_SymbolTable__TypePars)i1;
  i2 = i1!=(OOC_INT32)0;
  if (i2) goto l3;
  i0=0u;
  goto l4;
l3:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 79400))+48);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 79405))+4);
  i0 = i0==i1;
  
l4:
  return i0;
  ;
}

OOC_CHAR8 OOC_SymbolTable__TypeDeclDesc_IsTypeParameter(OOC_SymbolTable__TypeDecl typeDecl) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)typeDecl;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 79540))+4);
  return (OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 79548)))), &_td_OOC_SymbolTable__TypeParsDesc));
  ;
}

OOC_SymbolTable__TypeDecl OOC_SymbolTable__TypeDeclDesc_ParametricType(OOC_SymbolTable__TypeDecl typeDecl) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_SymbolTable__Item ptr;

  i0 = (OOC_INT32)typeDecl;
  i1 = OOC_SymbolTable__TypeDeclDesc_IsTypeParameter((OOC_SymbolTable__TypeDecl)i0);
  _assert(i1, 127, 79771);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 79826))+4);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 79833))+4);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 79840))+8);
  ptr = (OOC_SymbolTable__Item)i1;
  i2 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 79870)))), &_td_OOC_SymbolTable__TypeDeclDesc));
  if (i2) goto l3;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 79901)))), &_td_OOC_SymbolTable__TypeDeclDesc, 79901)), 79910))+48);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 79915))+4);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 79933))+4);
  i2 = i2!=i3;
  
  goto l5;
l3:
  i2=1u;
l5:
  if (i2) goto l8_loop;
  i0=i1;
  goto l17;
l8_loop:
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 79961));
  ptr = (OOC_SymbolTable__Item)i1;
  i2 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 79870)))), &_td_OOC_SymbolTable__TypeDeclDesc));
  if (i2) goto l11;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 79901)))), &_td_OOC_SymbolTable__TypeDeclDesc, 79901)), 79910))+48);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 79915))+4);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 79933))+4);
  i2 = i2!=i3;
  
  goto l13;
l11:
  i2=1u;
l13:
  if (i2) goto l8_loop;
l16:
  i0=i1;
l17:
  return (OOC_SymbolTable__TypeDecl)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 79998)))), &_td_OOC_SymbolTable__TypeDeclDesc, 79998));
  ;
}

void OOC_SymbolTable__InitRedirect(OOC_SymbolTable__Redirect redir, OOC_SymbolTable__Item parent, OOC_SymbolTable__Name name, OOC_SymbolTable__Name module, OOC_SymbolTable__Name ident) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)name;
  i1 = (OOC_INT32)parent;
  i2 = (OOC_INT32)redir;
  OOC_SymbolTable__InitDeclaration((OOC_SymbolTable__Declaration)i2, (OOC_SymbolTable__Item)i1, (OOC_SymbolTable__Name)i0, 0, 1, (OOC_Doc__Document)(OOC_INT32)0);
  i0 = (OOC_INT32)module;
  *(OOC_INT32*)((_check_pointer(i2, 80230))+48) = i0;
  i0 = (OOC_INT32)ident;
  *(OOC_INT32*)((_check_pointer(i2, 80259))+52) = i0;
  return;
  ;
}

void OOC_SymbolTable__RedirectDesc_Store(OOC_SymbolTable__Redirect redir, ADT_Storable__Writer w) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)redir;
  OOC_SymbolTable__DeclarationDesc_Store((OOC_SymbolTable__Declaration)i1, (ADT_Storable__Writer)i0);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 80427))+48);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 80407)))), ADT_Storable__WriterDesc_WriteObject)),ADT_Storable__WriterDesc_WriteObject)((ADT_Storable__Writer)i0, (Object__Object)i2);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 80463))+52);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 80443)))), ADT_Storable__WriterDesc_WriteObject)),ADT_Storable__WriterDesc_WriteObject)((ADT_Storable__Writer)i0, (Object__Object)i1);
  return;
  ;
}

void OOC_SymbolTable__RedirectDesc_Load(OOC_SymbolTable__Redirect redir, ADT_Storable__Reader r) {
  register OOC_INT32 i0,i1,i2;
  Object__Object obj;

  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)redir;
  OOC_SymbolTable__DeclarationDesc_Load((OOC_SymbolTable__Declaration)i1, (ADT_Storable__Reader)i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 80624)))), ADT_Storable__ReaderDesc_ReadObject)),ADT_Storable__ReaderDesc_ReadObject)((ADT_Storable__Reader)i0, (void*)(OOC_INT32)&obj);
  i2 = (OOC_INT32)obj;
  *(OOC_INT32*)((_check_pointer(i1, 80653))+48) = (_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 80669)))), &_td_OOC_SymbolTable__NameDesc, 80669));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 80681)))), ADT_Storable__ReaderDesc_ReadObject)),ADT_Storable__ReaderDesc_ReadObject)((ADT_Storable__Reader)i0, (void*)(OOC_INT32)&obj);
  i0 = (OOC_INT32)obj;
  *(OOC_INT32*)((_check_pointer(i1, 80710))+52) = (_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 80725)))), &_td_OOC_SymbolTable__NameDesc, 80725));
  return;
  ;
}

void OOC_SymbolTable__InitFieldDecl(OOC_SymbolTable__FieldDecl fieldDecl, OOC_SymbolTable__Item parent, OOC_SymbolTable__Name name, OOC_INT32 visibleFrom, OOC_INT8 exportMark, OOC_Doc__Document docString, OOC_SymbolTable__Type type) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;

  i0 = (OOC_INT32)docString;
  i1 = exportMark;
  i2 = visibleFrom;
  i3 = (OOC_INT32)name;
  i4 = (OOC_INT32)parent;
  i5 = (OOC_INT32)fieldDecl;
  OOC_SymbolTable__InitDeclaration((OOC_SymbolTable__Declaration)i5, (OOC_SymbolTable__Item)i4, (OOC_SymbolTable__Name)i3, i2, i1, (OOC_Doc__Document)i0);
  i0 = (OOC_INT32)type;
  *(OOC_INT32*)((_check_pointer(i5, 81058))+48) = i0;
  *(OOC_INT32*)((_check_pointer(i5, 81087))+52) = i0;
  *(OOC_INT32*)((_check_pointer(i5, 81123))+56) = (-1);
  *(OOC_UINT8*)((_check_pointer(i5, 81152))+60) = 0u;
  return;
  ;
}

void OOC_SymbolTable__FieldDeclDesc_Store(OOC_SymbolTable__FieldDecl fieldDecl, ADT_Storable__Writer w) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)fieldDecl;
  OOC_SymbolTable__DeclarationDesc_Store((OOC_SymbolTable__Declaration)i1, (ADT_Storable__Writer)i0);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 81360))+52);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 81344))+48);
  OOC_SymbolTable__WriteType((ADT_Storable__Writer)i0, (OOC_SymbolTable__Type)i3, (OOC_SymbolTable__Type)i2);
  i2 = *(OOC_INT32*)((_check_pointer(i1, 81401))+56);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 81380)))), IO_BinaryRider__WriterDesc_WriteNum)),IO_BinaryRider__WriterDesc_WriteNum)((IO_BinaryRider__Writer)i0, i2);
  i1 = *(OOC_UINT8*)((_check_pointer(i1, 81439))+60);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 81417)))), IO_BinaryRider__WriterDesc_WriteBool)),IO_BinaryRider__WriterDesc_WriteBool)((IO_BinaryRider__Writer)i0, i1);
  return;
  ;
}

void OOC_SymbolTable__FieldDeclDesc_Load(OOC_SymbolTable__FieldDecl fieldDecl, ADT_Storable__Reader r) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)fieldDecl;
  OOC_SymbolTable__DeclarationDesc_Load((OOC_SymbolTable__Declaration)i1, (ADT_Storable__Reader)i0);
  OOC_SymbolTable__ReadType((ADT_Storable__Reader)i0, (void*)((_check_pointer(i1, 81612))+48), (void*)((_check_pointer(i1, 81628))+52));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 81648)))), IO_BinaryRider__ReaderDesc_ReadNum)),IO_BinaryRider__ReaderDesc_ReadNum)((IO_BinaryRider__Reader)i0, (void*)((_check_pointer(i1, 81668))+56));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 81684)))), IO_BinaryRider__ReaderDesc_ReadBool)),IO_BinaryRider__ReaderDesc_ReadBool)((IO_BinaryRider__Reader)i0, (void*)((_check_pointer(i1, 81705))+60));
  return;
  ;
}

void OOC_SymbolTable__FieldDeclDesc_SetOffset(OOC_SymbolTable__FieldDecl fieldDecl, OOC_INT32 offset) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)fieldDecl;
  i1 = offset;
  *(OOC_INT32*)((_check_pointer(i0, 81825))+56) = i1;
  return;
  ;
}

void OOC_SymbolTable__InitPredefProc(OOC_SymbolTable__PredefProc proc, OOC_SymbolTable__Item parent, OOC_SymbolTable__Name name, OOC_INT16 id, OOC_INT16 minArgs, OOC_INT16 maxArgs) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)name;
  i1 = (OOC_INT32)parent;
  i2 = (OOC_INT32)proc;
  OOC_SymbolTable__InitDeclaration((OOC_SymbolTable__Declaration)i2, (OOC_SymbolTable__Item)i1, (OOC_SymbolTable__Name)i0, 0, 1, (OOC_Doc__Document)(OOC_INT32)0);
  i0 = id;
  *(OOC_INT16*)((_check_pointer(i2, 82084))+48) = i0;
  i0 = minArgs;
  *(OOC_INT16*)((_check_pointer(i2, 82104))+50) = i0;
  i0 = maxArgs;
  *(OOC_INT16*)((_check_pointer(i2, 82134))+52) = i0;
  return;
  ;
}

void OOC_SymbolTable__PredefProcDesc_Store(OOC_SymbolTable__PredefProc proc, ADT_Storable__Writer w) {

  _assert(0u, 127, 82265);
  
  ;
}

void OOC_SymbolTable__PredefProcDesc_Load(OOC_SymbolTable__PredefProc proc, ADT_Storable__Reader r) {

  _assert(0u, 127, 82379);
  
  ;
}

void OOC_SymbolTable__InitProcDecl(OOC_SymbolTable__ProcDecl procDecl, OOC_SymbolTable__Item parent, OOC_SymbolTable__Name name, OOC_INT32 visibleFrom, OOC_INT8 exportMark, OOC_Doc__Document docString, OOC_INT8 procClass, OOC_CHAR8 isForwardDecl, OOC_AST__Node procAST) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;

  i0 = (OOC_INT32)docString;
  i1 = exportMark;
  i2 = visibleFrom;
  i3 = (OOC_INT32)name;
  i4 = (OOC_INT32)parent;
  i5 = (OOC_INT32)procDecl;
  OOC_SymbolTable__InitDeclaration((OOC_SymbolTable__Declaration)i5, (OOC_SymbolTable__Item)i4, (OOC_SymbolTable__Name)i3, i2, i1, (OOC_Doc__Document)i0);
  i0 = procClass;
  *(OOC_INT8*)((_check_pointer(i5, 82819))+48) = i0;
  i0 = isForwardDecl;
  *(OOC_UINT8*)((_check_pointer(i5, 82857))+49) = i0;
  *(OOC_UINT8*)((_check_pointer(i5, 82903))+50) = 0u;
  *(OOC_UINT8*)((_check_pointer(i5, 82938))+51) = 0u;
  *(OOC_UINT8*)((_check_pointer(i5, 82975))+52) = 1u;
  *(OOC_INT32*)((_check_pointer(i5, 83013))+56) = (-1);
  *(OOC_INT32*)((_check_pointer(i5, 83046))+60) = (OOC_INT32)0;
  *(OOC_INT32*)((_check_pointer(i5, 83071))+64) = (OOC_INT32)0;
  *(OOC_INT32*)((_check_pointer(i5, 83104))+68) = (OOC_INT32)0;
  i0 = (OOC_INT32)procAST;
  *(OOC_INT32*)((_check_pointer(i5, 83135))+72) = i0;
  *(OOC_UINT8*)((_check_pointer(i5, 83169))+76) = 0u;
  return;
  ;
}

void OOC_SymbolTable__ProcDeclDesc_Store(OOC_SymbolTable__ProcDecl procDecl, ADT_Storable__Writer w) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)procDecl;
  OOC_SymbolTable__DeclarationDesc_Store((OOC_SymbolTable__Declaration)i1, (ADT_Storable__Writer)i0);
  i2 = *(OOC_INT8*)((_check_pointer(i1, 83350))+48);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 83329)))), IO_BinaryRider__WriterDesc_WriteSInt)),IO_BinaryRider__WriterDesc_WriteSInt)((IO_BinaryRider__Writer)i0, i2);
  i2 = *(OOC_UINT8*)((_check_pointer(i1, 83390))+49);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 83369)))), IO_BinaryRider__WriterDesc_WriteBool)),IO_BinaryRider__WriterDesc_WriteBool)((IO_BinaryRider__Writer)i0, i2);
  i2 = *(OOC_UINT8*)((_check_pointer(i1, 83434))+50);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 83413)))), IO_BinaryRider__WriterDesc_WriteBool)),IO_BinaryRider__WriterDesc_WriteBool)((IO_BinaryRider__Writer)i0, i2);
  i2 = *(OOC_UINT8*)((_check_pointer(i1, 83475))+51);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 83454)))), IO_BinaryRider__WriterDesc_WriteBool)),IO_BinaryRider__WriterDesc_WriteBool)((IO_BinaryRider__Writer)i0, i2);
  i2 = *(OOC_UINT8*)((_check_pointer(i1, 83518))+52);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 83497)))), IO_BinaryRider__WriterDesc_WriteBool)),IO_BinaryRider__WriterDesc_WriteBool)((IO_BinaryRider__Writer)i0, i2);
  i2 = *(OOC_INT32*)((_check_pointer(i1, 83562))+56);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 83542)))), IO_BinaryRider__WriterDesc_WriteNum)),IO_BinaryRider__WriterDesc_WriteNum)((IO_BinaryRider__Writer)i0, i2);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 83606))+64);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 83583)))), ADT_Storable__WriterDesc_WriteObject)),ADT_Storable__WriterDesc_WriteObject)((ADT_Storable__Writer)i0, (Object__Object)i2);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 83646))+68);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 83626)))), IO_BinaryRider__WriterDesc_WriteStr)),IO_BinaryRider__WriterDesc_WriteStr)((IO_BinaryRider__Writer)i0, (Object__String)i1);
  return;
  ;
}

void OOC_SymbolTable__ProcDeclDesc_Load(OOC_SymbolTable__ProcDecl procDecl, ADT_Storable__Reader r) {
  register OOC_INT32 i0,i1,i2,i3;
  Object__Object obj;

  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)procDecl;
  OOC_SymbolTable__DeclarationDesc_Load((OOC_SymbolTable__Declaration)i1, (ADT_Storable__Reader)i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 83856)))), IO_BinaryRider__ReaderDesc_ReadSInt)),IO_BinaryRider__ReaderDesc_ReadSInt)((IO_BinaryRider__Reader)i0, (void*)((_check_pointer(i1, 83876))+48));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 83895)))), IO_BinaryRider__ReaderDesc_ReadBool)),IO_BinaryRider__ReaderDesc_ReadBool)((IO_BinaryRider__Reader)i0, (void*)((_check_pointer(i1, 83915))+49));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 83938)))), IO_BinaryRider__ReaderDesc_ReadBool)),IO_BinaryRider__ReaderDesc_ReadBool)((IO_BinaryRider__Reader)i0, (void*)((_check_pointer(i1, 83958))+50));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 83978)))), IO_BinaryRider__ReaderDesc_ReadBool)),IO_BinaryRider__ReaderDesc_ReadBool)((IO_BinaryRider__Reader)i0, (void*)((_check_pointer(i1, 83998))+51));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 84020)))), IO_BinaryRider__ReaderDesc_ReadBool)),IO_BinaryRider__ReaderDesc_ReadBool)((IO_BinaryRider__Reader)i0, (void*)((_check_pointer(i1, 84040))+52));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 84064)))), IO_BinaryRider__ReaderDesc_ReadNum)),IO_BinaryRider__ReaderDesc_ReadNum)((IO_BinaryRider__Reader)i0, (void*)((_check_pointer(i1, 84083))+56));
  *(OOC_INT32*)((_check_pointer(i1, 84111))+60) = (OOC_INT32)0;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 84129)))), ADT_Storable__ReaderDesc_ReadObject)),ADT_Storable__ReaderDesc_ReadObject)((ADT_Storable__Reader)i0, (void*)(OOC_INT32)&obj);
  i2 = (OOC_INT32)obj;
  i3 = i2==(OOC_INT32)0;
  if (i3) goto l3;
  *(OOC_INT32*)((_check_pointer(i1, 84230))+64) = (_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 84250)))), &_td_OOC_SymbolTable__FormalParsDesc, 84250));
  goto l4;
l3:
  *(OOC_INT32*)((_check_pointer(i1, 84187))+64) = (OOC_INT32)0;
l4:
  i0 = (OOC_INT32)OOC_SymbolTable__ReadString8((ADT_Storable__Reader)i0);
  *(OOC_INT32*)((_check_pointer(i1, 84283))+68) = i0;
  *(OOC_INT32*)((_check_pointer(i1, 84324))+72) = (OOC_INT32)0;
  *(OOC_UINT8*)((_check_pointer(i1, 84354))+76) = 0u;
  return;
  ;
}

void OOC_SymbolTable__ProcDeclDesc_SetNamespace(OOC_SymbolTable__ProcDecl procDecl, OOC_SymbolTable__Namespace ns) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)procDecl;
  i1 = (OOC_INT32)ns;
  *(OOC_INT32*)((_check_pointer(i0, 84553))+60) = i1;
  return;
  ;
}

void OOC_SymbolTable__ProcDeclDesc_SetLinkName(OOC_SymbolTable__ProcDecl procDecl, Object__String name) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)procDecl;
  i1 = (OOC_INT32)name;
  *(OOC_INT32*)((_check_pointer(i0, 84666))+68) = i1;
  return;
  ;
}

void OOC_SymbolTable__ProcDeclDesc_CopyTBProcIndex(OOC_SymbolTable__ProcDecl procDecl, OOC_SymbolTable__ProcDecl redefinition) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)redefinition;
  i1 = (OOC_INT32)procDecl;
  i1 = *(OOC_INT32*)((_check_pointer(i1, 85035))+56);
  *(OOC_INT32*)((_check_pointer(i0, 85010))+56) = i1;
  return;
  ;
}

OOC_CHAR8 OOC_SymbolTable__ProcDeclDesc_IsTypeBound(OOC_SymbolTable__ProcDecl procDecl) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)procDecl;
  i0 = *(OOC_INT8*)((_check_pointer(i0, 85157))+48);
  return (i0!=0);
  ;
}

OOC_SymbolTable__Record OOC_SymbolTable__ProcDeclDesc_Class(OOC_SymbolTable__ProcDecl procDecl) {
  register OOC_INT32 i0,i1;
  OOC_SymbolTable__Item _class;

  i0 = (OOC_INT32)procDecl;
  i1 = OOC_SymbolTable__ProcDeclDesc_IsTypeBound((OOC_SymbolTable__ProcDecl)i0);
  if (i1) goto l3;
  return (OOC_SymbolTable__Record)(OOC_INT32)0;
  goto l12;
l3:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 85536))+64);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 85547))+40);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 85536))+64);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 85547))+40);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 85556))+48);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 85556))+48);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 85561)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i1);
  _class = (OOC_SymbolTable__Item)i0;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 85589)))), &_td_OOC_SymbolTable__PointerDesc);
  if (!i1) goto l7;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 85629)))), &_td_OOC_SymbolTable__PointerDesc, 85629)), 85637))+40);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 85629)))), &_td_OOC_SymbolTable__PointerDesc, 85629)), 85637))+40);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 85646)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
  _class = (OOC_SymbolTable__Item)i0;
  
l7:
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 85685)))), &_td_OOC_SymbolTable__RecordDesc);
  if (i1) goto l10;
  return (OOC_SymbolTable__Record)(OOC_INT32)0;
  goto l12;
l10:
  return (OOC_SymbolTable__Record)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 85722)))), &_td_OOC_SymbolTable__RecordDesc, 85722));
l12:
  _failed_function(85236); return 0;
  ;
}

void OOC_SymbolTable__ProcDeclDesc_RegisterForwardDecl(OOC_SymbolTable__ProcDecl procDecl, OOC_SymbolTable__ProcDecl forward) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)procDecl;
  i1 = (OOC_INT32)forward;
  i1 = *(OOC_INT32*)((_check_pointer(i1, 86078))+24);
  *(OOC_INT32*)((_check_pointer(i0, 86054))+24) = i1;
  return;
  ;
}

OOC_CHAR8 OOC_SymbolTable__ProcDeclDesc_IsModuleBody(OOC_SymbolTable__ProcDecl procDecl) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)procDecl;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 86293))+4);
  return (i0==(OOC_INT32)0);
  ;
}

void OOC_SymbolTable__InitPredefType(OOC_SymbolTable__PredefType ptype, OOC_SymbolTable__Item parent, OOC_INT16 id) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)parent;
  i1 = (OOC_INT32)ptype;
  OOC_SymbolTable__InitType((OOC_SymbolTable__Type)i1, (OOC_SymbolTable__Item)i0, (OOC_SymbolTable__Position)(OOC_INT32)0);
  i0 = id;
  *(OOC_INT16*)((_check_pointer(i1, 86458))+40) = i0;
  return;
  ;
}

void OOC_SymbolTable__PredefTypeDesc_Store(OOC_SymbolTable__PredefType tname, ADT_Storable__Writer w) {

  _assert(0u, 127, 86580);
  return;
  ;
}

void OOC_SymbolTable__PredefTypeDesc_Load(OOC_SymbolTable__PredefType tname, ADT_Storable__Reader r) {

  _assert(0u, 127, 86695);
  return;
  ;
}

void OOC_SymbolTable__InitTypeName(OOC_SymbolTable__TypeName tname, OOC_SymbolTable__Item parent, OOC_SymbolTable__Position position, OOC_SymbolTable__Name module, OOC_SymbolTable__Name ident) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)position;
  i1 = (OOC_INT32)parent;
  i2 = (OOC_INT32)tname;
  OOC_SymbolTable__InitType((OOC_SymbolTable__Type)i2, (OOC_SymbolTable__Item)i1, (OOC_SymbolTable__Position)i0);
  i0 = (OOC_INT32)module;
  *(OOC_INT32*)((_check_pointer(i2, 86904))+40) = i0;
  i0 = (OOC_INT32)ident;
  *(OOC_INT32*)((_check_pointer(i2, 86933))+44) = i0;
  return;
  ;
}

OOC_CHAR8 OOC_SymbolTable__TypeNameDesc_IsPredefReference(OOC_SymbolTable__TypeName tname) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)tname;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 87055))+40);
  i1 = i1!=(OOC_INT32)0;
  if (i1) goto l3;
  i0=0u;
  goto l4;
l3:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 87078))+40);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 87085))+12);
  i0 = _check_pointer(i0, 87089);
  i1 = OOC_ARRAY_LENGTH(i0, 0);
  i0 = *(OOC_UINT8*)(i0+(_check_index(0, i1, OOC_UINT8, 87089)));
  i0 = i0==0u;
  
l4:
  return i0;
  ;
}

void OOC_SymbolTable__TypeNameDesc_MarkAsPredefReference(OOC_SymbolTable__TypeName tname) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)tname;
  i1 = (OOC_INT32)OOC_SymbolTable__predefName;
  *(OOC_INT32*)((_check_pointer(i0, 87197))+40) = i1;
  return;
  ;
}

void OOC_SymbolTable__TypeNameDesc_Store(OOC_SymbolTable__TypeName tname, ADT_Storable__Writer w) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)tname;
  OOC_SymbolTable__TypeDesc_Store((OOC_SymbolTable__Type)i1, (ADT_Storable__Writer)i0);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 87379))+40);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 87359)))), ADT_Storable__WriterDesc_WriteObject)),ADT_Storable__WriterDesc_WriteObject)((ADT_Storable__Writer)i0, (Object__Object)i2);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 87415))+44);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 87395)))), ADT_Storable__WriterDesc_WriteObject)),ADT_Storable__WriterDesc_WriteObject)((ADT_Storable__Writer)i0, (Object__Object)i1);
  return;
  ;
}

void OOC_SymbolTable__TypeNameDesc_Load(OOC_SymbolTable__TypeName tname, ADT_Storable__Reader r) {
  register OOC_INT32 i0,i1,i2,i3;
  Object__Object obj;

  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)tname;
  OOC_SymbolTable__TypeDesc_Load((OOC_SymbolTable__Type)i1, (ADT_Storable__Reader)i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 87575)))), ADT_Storable__ReaderDesc_ReadObject)),ADT_Storable__ReaderDesc_ReadObject)((ADT_Storable__Reader)i0, (void*)(OOC_INT32)&obj);
  i2 = (OOC_INT32)obj;
  i3 = i2==(OOC_INT32)0;
  if (i3) goto l3;
  *(OOC_INT32*)((_check_pointer(i1, 87666))+40) = (_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 87682)))), &_td_OOC_SymbolTable__NameDesc, 87682));
  goto l4;
l3:
  *(OOC_INT32*)((_check_pointer(i1, 87630))+40) = (OOC_INT32)0;
l4:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 87702)))), ADT_Storable__ReaderDesc_ReadObject)),ADT_Storable__ReaderDesc_ReadObject)((ADT_Storable__Reader)i0, (void*)(OOC_INT32)&obj);
  i0 = (OOC_INT32)obj;
  *(OOC_INT32*)((_check_pointer(i1, 87731))+44) = (_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 87746)))), &_td_OOC_SymbolTable__NameDesc, 87746));
  return;
  ;
}

OOC_SymbolTable__Import OOC_SymbolTable__TypeNameDesc_GetImport(OOC_SymbolTable__TypeName tname) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_SymbolTable__Module module;
  OOC_SymbolTable__Declaration decl;

  i0 = (OOC_INT32)tname;
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 87892)))), OOC_SymbolTable__ItemDesc_Module)),OOC_SymbolTable__ItemDesc_Module)((OOC_SymbolTable__Item)i0);
  module = (OOC_SymbolTable__Module)i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 87922))+48);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 87956))+40);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 87922))+48);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 87926)))), OOC_SymbolTable__NamespaceDesc_IdentifyLocal)),OOC_SymbolTable__NamespaceDesc_IdentifyLocal)((OOC_SymbolTable__Namespace)i3, (OOC_SymbolTable__Item)i1, (OOC_SymbolTable__Name)i0, 0u);
  decl = (OOC_SymbolTable__Declaration)i0;
  return (OOC_SymbolTable__Import)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 87990)))), &_td_OOC_SymbolTable__ImportDesc, 87990));
  ;
}

void OOC_SymbolTable__InitRecord(OOC_SymbolTable__Record record, OOC_SymbolTable__Item parent, OOC_SymbolTable__Position position, OOC_SymbolTable__Type baseType) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)position;
  i1 = (OOC_INT32)parent;
  i2 = (OOC_INT32)record;
  OOC_SymbolTable__InitType((OOC_SymbolTable__Type)i2, (OOC_SymbolTable__Item)i1, (OOC_SymbolTable__Position)i0);
  i0 = (OOC_INT32)baseType;
  *(OOC_INT32*)((_check_pointer(i2, 88189))+40) = i0;
  *(OOC_INT32*)((_check_pointer(i2, 88223))+44) = i0;
  *(OOC_INT32*)((_check_pointer(i2, 88264))+48) = (-1);
  *(OOC_INT32*)((_check_pointer(i2, 88342))+52) = (OOC_INT32)0;
  *(OOC_UINT8*)((_check_pointer(i2, 88365))+56) = 0u;
  *(OOC_UINT8*)((_check_pointer(i2, 88395))+57) = 0u;
  *(OOC_UINT8*)((_check_pointer(i2, 88428))+58) = 1u;
  *(OOC_UINT8*)((_check_pointer(i2, 88462))+59) = 0u;
  *(OOC_UINT8*)((_check_pointer(i2, 88505))+60) = 0u;
  *(OOC_UINT8*)((_check_pointer(i2, 88536))+61) = 0u;
  *(OOC_INT16*)((_check_pointer(i2, 88567))+62) = 0;
  *(OOC_INT32*)((_check_pointer(i2, 88596))+64) = (OOC_INT32)0;
  return;
  ;
}

void OOC_SymbolTable__RecordDesc_Store(OOC_SymbolTable__Record record, ADT_Storable__Writer w) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)record;
  OOC_SymbolTable__TypeDesc_Store((OOC_SymbolTable__Type)i1, (ADT_Storable__Writer)i0);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 88778))+44);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 88761))+40);
  OOC_SymbolTable__WriteType((ADT_Storable__Writer)i0, (OOC_SymbolTable__Type)i3, (OOC_SymbolTable__Type)i2);
  i2 = *(OOC_INT32*)((_check_pointer(i1, 88820))+48);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 88802)))), IO_BinaryRider__WriterDesc_WriteNum)),IO_BinaryRider__WriterDesc_WriteNum)((IO_BinaryRider__Writer)i0, i2);
  i2 = *(OOC_UINT8*)((_check_pointer(i1, 88860))+56);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 88841)))), IO_BinaryRider__WriterDesc_WriteBool)),IO_BinaryRider__WriterDesc_WriteBool)((IO_BinaryRider__Writer)i0, i2);
  i2 = *(OOC_UINT8*)((_check_pointer(i1, 88896))+57);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 88877)))), IO_BinaryRider__WriterDesc_WriteBool)),IO_BinaryRider__WriterDesc_WriteBool)((IO_BinaryRider__Writer)i0, i2);
  i2 = *(OOC_UINT8*)((_check_pointer(i1, 88935))+58);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 88916)))), IO_BinaryRider__WriterDesc_WriteBool)),IO_BinaryRider__WriterDesc_WriteBool)((IO_BinaryRider__Writer)i0, i2);
  i2 = *(OOC_UINT8*)((_check_pointer(i1, 88976))+59);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 88957)))), IO_BinaryRider__WriterDesc_WriteBool)),IO_BinaryRider__WriterDesc_WriteBool)((IO_BinaryRider__Writer)i0, i2);
  i2 = *(OOC_UINT8*)((_check_pointer(i1, 89025))+60);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 89006)))), IO_BinaryRider__WriterDesc_WriteBool)),IO_BinaryRider__WriterDesc_WriteBool)((IO_BinaryRider__Writer)i0, i2);
  i2 = *(OOC_UINT8*)((_check_pointer(i1, 89062))+61);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 89043)))), IO_BinaryRider__WriterDesc_WriteBool)),IO_BinaryRider__WriterDesc_WriteBool)((IO_BinaryRider__Writer)i0, i2);
  i2 = *(OOC_INT16*)((_check_pointer(i1, 89098))+62);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 89080)))), IO_BinaryRider__WriterDesc_WriteInt)),IO_BinaryRider__WriterDesc_WriteInt)((IO_BinaryRider__Writer)i0, i2);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 89139))+64);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 89118)))), ADT_Storable__WriterDesc_WriteObject)),ADT_Storable__WriterDesc_WriteObject)((ADT_Storable__Writer)i0, (Object__Object)i1);
  return;
  ;
}

void OOC_SymbolTable__RecordDesc_Load(OOC_SymbolTable__Record record, ADT_Storable__Reader r) {
  register OOC_INT32 i0,i1,i2;
  Object__Object obj;

  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)record;
  OOC_SymbolTable__TypeDesc_Load((OOC_SymbolTable__Type)i1, (ADT_Storable__Reader)i0);
  OOC_SymbolTable__ReadType((ADT_Storable__Reader)i0, (void*)((_check_pointer(i1, 89349))+40), (void*)((_check_pointer(i1, 89366))+44));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 89390)))), IO_BinaryRider__ReaderDesc_ReadNum)),IO_BinaryRider__ReaderDesc_ReadNum)((IO_BinaryRider__Reader)i0, (void*)((_check_pointer(i1, 89407))+48));
  *(OOC_INT32*)((_check_pointer(i1, 89433))+52) = (OOC_INT32)0;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 89451)))), IO_BinaryRider__ReaderDesc_ReadBool)),IO_BinaryRider__ReaderDesc_ReadBool)((IO_BinaryRider__Reader)i0, (void*)((_check_pointer(i1, 89469))+56));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 89486)))), IO_BinaryRider__ReaderDesc_ReadBool)),IO_BinaryRider__ReaderDesc_ReadBool)((IO_BinaryRider__Reader)i0, (void*)((_check_pointer(i1, 89504))+57));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 89524)))), IO_BinaryRider__ReaderDesc_ReadBool)),IO_BinaryRider__ReaderDesc_ReadBool)((IO_BinaryRider__Reader)i0, (void*)((_check_pointer(i1, 89542))+58));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 89564)))), IO_BinaryRider__ReaderDesc_ReadBool)),IO_BinaryRider__ReaderDesc_ReadBool)((IO_BinaryRider__Reader)i0, (void*)((_check_pointer(i1, 89582))+59));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 89612)))), IO_BinaryRider__ReaderDesc_ReadBool)),IO_BinaryRider__ReaderDesc_ReadBool)((IO_BinaryRider__Reader)i0, (void*)((_check_pointer(i1, 89630))+60));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 89648)))), IO_BinaryRider__ReaderDesc_ReadBool)),IO_BinaryRider__ReaderDesc_ReadBool)((IO_BinaryRider__Reader)i0, (void*)((_check_pointer(i1, 89666))+61));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 89684)))), IO_BinaryRider__ReaderDesc_ReadInt)),IO_BinaryRider__ReaderDesc_ReadInt)((IO_BinaryRider__Reader)i0, (void*)((_check_pointer(i1, 89701))+62));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 89721)))), ADT_Storable__ReaderDesc_ReadObject)),ADT_Storable__ReaderDesc_ReadObject)((ADT_Storable__Reader)i0, (void*)(OOC_INT32)&obj);
  i0 = (OOC_INT32)obj;
  i2 = i0==(OOC_INT32)0;
  if (i2) goto l3;
  *(OOC_INT32*)((_check_pointer(i1, 89817))+64) = (_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 89836)))), &_td_OOC_SymbolTable__NameDesc, 89836));
  goto l4;
l3:
  *(OOC_INT32*)((_check_pointer(i1, 89777))+64) = (OOC_INT32)0;
l4:
  return;
  ;
}

void OOC_SymbolTable__RecordDesc_SetNamespace(OOC_SymbolTable__Record record, OOC_SymbolTable__Namespace ns) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)record;
  i1 = (OOC_INT32)ns;
  *(OOC_INT32*)((_check_pointer(i0, 90016))+52) = i1;
  return;
  ;
}

void OOC_SymbolTable__RecordDesc_AssignTBProcIndex(OOC_SymbolTable__Record record, OOC_SymbolTable__ProcDecl procDecl) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)procDecl;
  i1 = (OOC_INT32)record;
  i2 = *(OOC_INT32*)((_check_pointer(i1, 90340))+48);
  *(OOC_INT32*)((_check_pointer(i0, 90317))+56) = i2;
  i0 = *(OOC_INT32*)((_check_pointer(i1, 90370))+48);
  *(OOC_INT32*)((_check_pointer(i1, 90370))+48) = (i0+1);
  return;
  ;
}

OOC_INT32 OOC_SymbolTable__RecordDesc_ExtensionLevel(OOC_SymbolTable__Record record) {
  register OOC_INT32 i0,i1,i2;
  OOC_INT32 level;

  level = 0;
  i0 = (OOC_INT32)record;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 90650))+40);
  i1 = i1!=(OOC_INT32)0;
  if (i1) goto l3;
  i0=0;
  goto l9;
l3:
  i1=0;
l4_loop:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 90692))+40);
  i0 = _type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 90702)))), &_td_OOC_SymbolTable__RecordDesc, 90702);
  record = (OOC_SymbolTable__Record)i0;
  i1 = i1+1;
  level = i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 90650))+40);
  i2 = i2!=(OOC_INT32)0;
  if (i2) goto l4_loop;
l8:
  i0=i1;
l9:
  return i0;
  ;
}

void OOC_SymbolTable__InitTypeVar(OOC_SymbolTable__TypeVar typeVar, OOC_SymbolTable__Item parent, OOC_SymbolTable__Position position, OOC_SymbolTable__Type bound) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)position;
  i1 = (OOC_INT32)parent;
  i2 = (OOC_INT32)typeVar;
  OOC_SymbolTable__InitType((OOC_SymbolTable__Type)i2, (OOC_SymbolTable__Item)i1, (OOC_SymbolTable__Position)i0);
  i0 = (OOC_INT32)bound;
  *(OOC_INT32*)((_check_pointer(i2, 90954))+40) = i0;
  *(OOC_INT32*)((_check_pointer(i2, 90982))+44) = i0;
  return;
  ;
}

void OOC_SymbolTable__TypeVarDesc_Store(OOC_SymbolTable__TypeVar typeVar, ADT_Storable__Writer w) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)typeVar;
  OOC_SymbolTable__TypeDesc_Store((OOC_SymbolTable__Type)i1, (ADT_Storable__Writer)i0);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 91170))+44);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 91155))+40);
  OOC_SymbolTable__WriteType((ADT_Storable__Writer)i0, (OOC_SymbolTable__Type)i1, (OOC_SymbolTable__Type)i2);
  return;
  ;
}

void OOC_SymbolTable__TypeVarDesc_Load(OOC_SymbolTable__TypeVar typeVar, ADT_Storable__Reader r) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)typeVar;
  OOC_SymbolTable__TypeDesc_Load((OOC_SymbolTable__Type)i1, (ADT_Storable__Reader)i0);
  OOC_SymbolTable__ReadType((ADT_Storable__Reader)i0, (void*)((_check_pointer(i1, 91326))+40), (void*)((_check_pointer(i1, 91341))+44));
  return;
  ;
}

OOC_SymbolTable__Type OOC_SymbolTable__TypeVarDesc_Bound(OOC_SymbolTable__TypeVar typeVar) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)typeVar;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 91441))+40);
  return (OOC_SymbolTable__Type)i0;
  ;
}

void OOC_SymbolTable__InitTypePars(OOC_SymbolTable__TypePars typePars, OOC_SymbolTable__Item parent) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)parent;
  i1 = (OOC_INT32)typePars;
  OOC_SymbolTable__InitItem((OOC_SymbolTable__Item)i1, (OOC_SymbolTable__Item)i0);
  *(OOC_INT32*)((_check_pointer(i1, 91576))+20) = (OOC_INT32)0;
  *(OOC_INT32*)((_check_pointer(i1, 91604))+24) = (OOC_INT32)0;
  return;
  ;
}

void OOC_SymbolTable__TypeParsDesc_Store(OOC_SymbolTable__TypePars typePars, ADT_Storable__Writer w) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)typePars;
  OOC_SymbolTable__ItemDesc_Store((OOC_SymbolTable__Item)i1, (ADT_Storable__Writer)i0);
  return;
  ;
}

void OOC_SymbolTable__TypeParsDesc_Load(OOC_SymbolTable__TypePars typePars, ADT_Storable__Reader r) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)typePars;
  OOC_SymbolTable__ItemDesc_Load((OOC_SymbolTable__Item)i1, (ADT_Storable__Reader)i0);
  *(OOC_INT32*)((_check_pointer(i1, 91918))+20) = (OOC_INT32)0;
  *(OOC_INT32*)((_check_pointer(i1, 91946))+24) = (OOC_INT32)0;
  return;
  ;
}

void OOC_SymbolTable__TypeParsDesc_SetNamespace(OOC_SymbolTable__TypePars typePars, OOC_SymbolTable__Namespace ns) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)typePars;
  i1 = (OOC_INT32)ns;
  *(OOC_INT32*)((_check_pointer(i0, 92131))+24) = i1;
  return;
  ;
}

void OOC_SymbolTable__InitTypeRef(struct OOC_SymbolTable__TypeRef *typeRef, RT0__Struct typeRef__tag, OOC_SymbolTable__Type type) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)type;
  *(OOC_INT32*)(OOC_INT32)typeRef = i0;
  *(OOC_INT32*)((OOC_INT32)typeRef+4) = i0;
  return;
  ;
}

static void OOC_SymbolTable__StoreTypeRef(ADT_Storable__Writer w, struct OOC_SymbolTable__TypeRef *typeRef, RT0__Struct typeRef__tag) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)*(OOC_INT32*)((OOC_INT32)typeRef+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 92427)))), ADT_Storable__WriterDesc_WriteObject)),ADT_Storable__WriterDesc_WriteObject)((ADT_Storable__Writer)i0, (Object__Object)i1);
  return;
  ;
}

static void OOC_SymbolTable__LoadTypeRef(ADT_Storable__Reader r, struct OOC_SymbolTable__TypeRef *typeRef, RT0__Struct typeRef__tag) {
  register OOC_INT32 i0;
  Object__Object obj;

  i0 = (OOC_INT32)r;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 92631)))), ADT_Storable__ReaderDesc_ReadObject)),ADT_Storable__ReaderDesc_ReadObject)((ADT_Storable__Reader)i0, (void*)(OOC_INT32)&obj);
  i0 = (OOC_INT32)obj;
  *(OOC_INT32*)((OOC_INT32)typeRef+4) = (_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 92682)))), &_td_OOC_SymbolTable__TypeDesc, 92682));
  *(OOC_INT32*)(OOC_INT32)typeRef = (_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 92713)))), &_td_OOC_SymbolTable__TypeDesc, 92713));
  return;
  ;
}

void OOC_SymbolTable__InitQualType(OOC_SymbolTable__QualType qualType, OOC_SymbolTable__Item parent, OOC_SymbolTable__Position position, OOC_SymbolTable__Type baseType, OOC_SymbolTable__TypeRefArray arguments) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)position;
  i1 = (OOC_INT32)parent;
  i2 = (OOC_INT32)qualType;
  OOC_SymbolTable__InitType((OOC_SymbolTable__Type)i2, (OOC_SymbolTable__Item)i1, (OOC_SymbolTable__Position)i0);
  i0 = (OOC_INT32)baseType;
  *(OOC_INT32*)((_check_pointer(i2, 92974))+40) = i0;
  *(OOC_INT32*)((_check_pointer(i2, 93009))+44) = i0;
  i0 = (OOC_INT32)arguments;
  *(OOC_INT32*)((_check_pointer(i2, 93051))+48) = i0;
  return;
  ;
}

OOC_SymbolTable__QualType OOC_SymbolTable__NewQualType(OOC_SymbolTable__Item parent, OOC_SymbolTable__Position position, OOC_SymbolTable__Type baseType, OOC_SymbolTable__TypeRefArray arguments) {
  register OOC_INT32 i0,i1,i2,i3,i4;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_SymbolTable__QualType.baseTypes[0]);
  i1 = (OOC_INT32)arguments;
  i2 = (OOC_INT32)baseType;
  i3 = (OOC_INT32)position;
  i4 = (OOC_INT32)parent;
  OOC_SymbolTable__InitQualType((OOC_SymbolTable__QualType)i0, (OOC_SymbolTable__Item)i4, (OOC_SymbolTable__Position)i3, (OOC_SymbolTable__Type)i2, (OOC_SymbolTable__TypeRefArray)i1);
  return (OOC_SymbolTable__QualType)i0;
  ;
}

void OOC_SymbolTable__QualTypeDesc_Store(OOC_SymbolTable__QualType qualType, ADT_Storable__Writer w) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
  OOC_INT32 i;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)qualType;
  OOC_SymbolTable__TypeDesc_Store((OOC_SymbolTable__Type)i1, (ADT_Storable__Writer)i0);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 93568))+44);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 93549))+40);
  OOC_SymbolTable__WriteType((ADT_Storable__Writer)i0, (OOC_SymbolTable__Type)i3, (OOC_SymbolTable__Type)i2);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 93614))+48);
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 93624)), 0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 93592)))), IO_BinaryRider__WriterDesc_WriteNum)),IO_BinaryRider__WriterDesc_WriteNum)((IO_BinaryRider__Writer)i0, i2);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 93659))+48);
  i = 0;
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 93669)), 0);
  i3 = 0<i2;
  if (!i3) goto l8;
  i3 = (OOC_INT32)&_td_OOC_SymbolTable__TypeRef;
  i4=0;
l3_loop:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 93707))+48);
  i5 = OOC_ARRAY_LENGTH((_check_pointer(i5, 93717)), 0);
  i5 = _check_index(i4, i5, OOC_UINT32, 93717);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 93707))+48);
  i5 = _check_pointer(i5, 93717);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  OOC_SymbolTable__StoreTypeRef((ADT_Storable__Writer)i0, (void*)(i5+(_check_index(i4, i6, OOC_UINT32, 93717))*8), (RT0__Struct)i3);
  i4 = i4+1;
  i = i4;
  i5 = i4<i2;
  if (i5) goto l3_loop;
l8:
  return;
  ;
}

void OOC_SymbolTable__QualTypeDesc_Load(OOC_SymbolTable__QualType qualType, ADT_Storable__Reader r) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
  OOC_INT32 len;
  OOC_INT32 i;

  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)qualType;
  OOC_SymbolTable__TypeDesc_Load((OOC_SymbolTable__Type)i1, (ADT_Storable__Reader)i0);
  OOC_SymbolTable__ReadType((ADT_Storable__Reader)i0, (void*)((_check_pointer(i1, 93903))+40), (void*)((_check_pointer(i1, 93922))+44));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 93946)))), IO_BinaryRider__ReaderDesc_ReadNum)),IO_BinaryRider__ReaderDesc_ReadNum)((IO_BinaryRider__Reader)i0, (void*)(OOC_INT32)&len);
  i2 = len;
  *(OOC_INT32*)((_check_pointer(i1, 93977))+48) = ((OOC_INT32)RT0__NewObject(_td_OOC_SymbolTable__TypeRefArray.baseTypes[0], i2));
  i = 0;
  i3 = 0<i2;
  if (!i3) goto l8;
  i3 = (OOC_INT32)&_td_OOC_SymbolTable__TypeRef;
  i4=0;
l3_loop:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 94051))+48);
  i5 = OOC_ARRAY_LENGTH((_check_pointer(i5, 94061)), 0);
  i5 = _check_index(i4, i5, OOC_UINT32, 94061);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 94051))+48);
  i5 = _check_pointer(i5, 94061);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  OOC_SymbolTable__LoadTypeRef((ADT_Storable__Reader)i0, (void*)(i5+(_check_index(i4, i6, OOC_UINT32, 94061))*8), (RT0__Struct)i3);
  i4 = i4+1;
  i = i4;
  i5 = i4<i2;
  if (i5) goto l3_loop;
l8:
  return;
  ;
}

OOC_SymbolTable__Type OOC_SymbolTable__QualTypeDesc_Deparam(OOC_SymbolTable__QualType qualType) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)qualType;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 94165))+40);
  return (OOC_SymbolTable__Type)i0;
  ;
}

void OOC_SymbolTable__InitPointer(OOC_SymbolTable__Pointer pointer, OOC_SymbolTable__Item parent, OOC_SymbolTable__Position position, OOC_SymbolTable__Type baseType) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)position;
  i1 = (OOC_INT32)parent;
  i2 = (OOC_INT32)pointer;
  OOC_SymbolTable__InitType((OOC_SymbolTable__Type)i2, (OOC_SymbolTable__Item)i1, (OOC_SymbolTable__Position)i0);
  i0 = (OOC_INT32)baseType;
  *(OOC_INT32*)((_check_pointer(i2, 94371))+40) = i0;
  *(OOC_INT32*)((_check_pointer(i2, 94406))+44) = i0;
  *(OOC_UINT8*)((_check_pointer(i2, 94448))+48) = 0u;
  *(OOC_UINT8*)((_check_pointer(i2, 94490))+49) = 0u;
  return;
  ;
}

void OOC_SymbolTable__PointerDesc_Store(OOC_SymbolTable__Pointer pointer, ADT_Storable__Writer w) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)pointer;
  OOC_SymbolTable__TypeDesc_Store((OOC_SymbolTable__Type)i1, (ADT_Storable__Writer)i0);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 94680))+44);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 94662))+40);
  OOC_SymbolTable__WriteType((ADT_Storable__Writer)i0, (OOC_SymbolTable__Type)i3, (OOC_SymbolTable__Type)i2);
  i2 = *(OOC_UINT8*)((_check_pointer(i1, 94724))+48);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 94704)))), IO_BinaryRider__WriterDesc_WriteBool)),IO_BinaryRider__WriterDesc_WriteBool)((IO_BinaryRider__Writer)i0, i2);
  i1 = *(OOC_UINT8*)((_check_pointer(i1, 94772))+49);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 94752)))), IO_BinaryRider__WriterDesc_WriteBool)),IO_BinaryRider__WriterDesc_WriteBool)((IO_BinaryRider__Writer)i0, i1);
  return;
  ;
}

void OOC_SymbolTable__PointerDesc_Load(OOC_SymbolTable__Pointer pointer, ADT_Storable__Reader r) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)pointer;
  OOC_SymbolTable__TypeDesc_Load((OOC_SymbolTable__Type)i1, (ADT_Storable__Reader)i0);
  OOC_SymbolTable__ReadType((ADT_Storable__Reader)i0, (void*)((_check_pointer(i1, 94927))+40), (void*)((_check_pointer(i1, 94945))+44));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 94969)))), IO_BinaryRider__ReaderDesc_ReadBool)),IO_BinaryRider__ReaderDesc_ReadBool)((IO_BinaryRider__Reader)i0, (void*)((_check_pointer(i1, 94988))+48));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 95016)))), IO_BinaryRider__ReaderDesc_ReadBool)),IO_BinaryRider__ReaderDesc_ReadBool)((IO_BinaryRider__Reader)i0, (void*)((_check_pointer(i1, 95035))+49));
  return;
  ;
}

void OOC_SymbolTable__InitArray(OOC_SymbolTable__Array array, OOC_SymbolTable__Item parent, OOC_SymbolTable__Position position, OOC_CHAR8 isOpenArray, OOC_SymbolTable__Type elementType, OOC_AST__Node lengthExpr) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)position;
  i1 = (OOC_INT32)parent;
  i2 = (OOC_INT32)array;
  OOC_SymbolTable__InitType((OOC_SymbolTable__Type)i2, (OOC_SymbolTable__Item)i1, (OOC_SymbolTable__Position)i0);
  i0 = isOpenArray;
  *(OOC_UINT8*)((_check_pointer(i2, 95297))+40) = i0;
  *(OOC_UINT8*)((_check_pointer(i2, 95336))+41) = 1u;
  *(OOC_UINT8*)((_check_pointer(i2, 95370))+42) = 0u;
  i0 = (OOC_INT32)elementType;
  *(OOC_INT32*)((_check_pointer(i2, 95406))+44) = i0;
  *(OOC_INT32*)((_check_pointer(i2, 95445))+48) = i0;
  *(OOC_INT32*)((_check_pointer(i2, 95491))+52) = (-1);
  i0 = (OOC_INT32)lengthExpr;
  *(OOC_INT32*)((_check_pointer(i2, 95516))+56) = i0;
  *(OOC_UINT8*)((_check_pointer(i2, 95553))+60) = 0u;
  return;
  ;
}

void OOC_SymbolTable__ArrayDesc_Store(OOC_SymbolTable__Array array, ADT_Storable__Writer w) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)array;
  OOC_SymbolTable__TypeDesc_Store((OOC_SymbolTable__Type)i1, (ADT_Storable__Writer)i0);
  i2 = *(OOC_UINT8*)((_check_pointer(i1, 95716))+40);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 95698)))), IO_BinaryRider__WriterDesc_WriteBool)),IO_BinaryRider__WriterDesc_WriteBool)((IO_BinaryRider__Writer)i0, i2);
  i2 = *(OOC_UINT8*)((_check_pointer(i1, 95755))+41);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 95737)))), IO_BinaryRider__WriterDesc_WriteBool)),IO_BinaryRider__WriterDesc_WriteBool)((IO_BinaryRider__Writer)i0, i2);
  i2 = *(OOC_UINT8*)((_check_pointer(i1, 95796))+42);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 95778)))), IO_BinaryRider__WriterDesc_WriteBool)),IO_BinaryRider__WriterDesc_WriteBool)((IO_BinaryRider__Writer)i0, i2);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 95837))+44);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 95856))+48);
  OOC_SymbolTable__WriteType((ADT_Storable__Writer)i0, (OOC_SymbolTable__Type)i2, (OOC_SymbolTable__Type)i3);
  i2 = *(OOC_INT32*)((_check_pointer(i1, 95900))+52);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 95883)))), IO_BinaryRider__WriterDesc_WriteNum)),IO_BinaryRider__WriterDesc_WriteNum)((IO_BinaryRider__Writer)i0, i2);
  i1 = *(OOC_UINT8*)((_check_pointer(i1, 95938))+60);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 95920)))), IO_BinaryRider__WriterDesc_WriteBool)),IO_BinaryRider__WriterDesc_WriteBool)((IO_BinaryRider__Writer)i0, i1);
  return;
  ;
}

void OOC_SymbolTable__ArrayDesc_Load(OOC_SymbolTable__Array array, ADT_Storable__Reader r) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)array;
  OOC_SymbolTable__TypeDesc_Load((OOC_SymbolTable__Type)i1, (ADT_Storable__Reader)i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 96069)))), IO_BinaryRider__ReaderDesc_ReadBool)),IO_BinaryRider__ReaderDesc_ReadBool)((IO_BinaryRider__Reader)i0, (void*)((_check_pointer(i1, 96086))+40));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 96107)))), IO_BinaryRider__ReaderDesc_ReadBool)),IO_BinaryRider__ReaderDesc_ReadBool)((IO_BinaryRider__Reader)i0, (void*)((_check_pointer(i1, 96124))+41));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 96147)))), IO_BinaryRider__ReaderDesc_ReadBool)),IO_BinaryRider__ReaderDesc_ReadBool)((IO_BinaryRider__Reader)i0, (void*)((_check_pointer(i1, 96164))+42));
  OOC_SymbolTable__ReadType((ADT_Storable__Reader)i0, (void*)((_check_pointer(i1, 96204))+44), (void*)((_check_pointer(i1, 96223))+48));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 96250)))), IO_BinaryRider__ReaderDesc_ReadNum)),IO_BinaryRider__ReaderDesc_ReadNum)((IO_BinaryRider__Reader)i0, (void*)((_check_pointer(i1, 96266))+52));
  *(OOC_INT32*)((_check_pointer(i1, 96286))+56) = (OOC_INT32)0;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 96312)))), IO_BinaryRider__ReaderDesc_ReadBool)),IO_BinaryRider__ReaderDesc_ReadBool)((IO_BinaryRider__Reader)i0, (void*)((_check_pointer(i1, 96329))+60));
  return;
  ;
}

void OOC_SymbolTable__ArrayDesc_SetLength(OOC_SymbolTable__Array array, OOC_INT32 length) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)array;
  i1 = length;
  *(OOC_INT32*)((_check_pointer(i0, 96427))+52) = i1;
  return;
  ;
}

OOC_INT32 OOC_SymbolTable__ArrayDesc_GetOpenDimensions(OOC_SymbolTable__Array array) {
  register OOC_INT32 i0,i1,i2;
  OOC_INT32 dim;
  OOC_SymbolTable__Type type;

  dim = 0;
  i0 = (OOC_INT32)array;
  type = (OOC_SymbolTable__Type)i0;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 96749)))), &_td_OOC_SymbolTable__ArrayDesc);
  if (i1) goto l3;
  i1=0u;
  goto l5;
l3:
  i1 = *(OOC_UINT8*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 96766)))), &_td_OOC_SymbolTable__ArrayDesc, 96766)), 96772))+40);
  
l5:
  if (i1) goto l7;
  i0=0;
  goto l17;
l7:
  i1=i0;i0=0;
l8_loop:
  i0 = i0+1;
  dim = i0;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 96824)))), &_td_OOC_SymbolTable__ArrayDesc, 96824)), 96830))+44);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 96824)))), &_td_OOC_SymbolTable__ArrayDesc, 96824)), 96830))+44);
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 96842)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i1);
  type = (OOC_SymbolTable__Type)i1;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 96749)))), &_td_OOC_SymbolTable__ArrayDesc);
  if (i2) goto l11;
  i2=0u;
  goto l13;
l11:
  i2 = *(OOC_UINT8*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 96766)))), &_td_OOC_SymbolTable__ArrayDesc, 96766)), 96772))+40);
  
l13:
  if (i2) goto l8_loop;
l17:
  return i0;
  ;
}

OOC_SymbolTable__Type OOC_SymbolTable__ArrayDesc_GetNonOpenElementType(OOC_SymbolTable__Array array) {
  register OOC_INT32 i0,i1;
  OOC_SymbolTable__Type type;

  i0 = (OOC_INT32)array;
  type = (OOC_SymbolTable__Type)i0;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 97110)))), &_td_OOC_SymbolTable__ArrayDesc);
  if (i1) goto l3;
  i1=0u;
  goto l5;
l3:
  i1 = *(OOC_UINT8*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 97127)))), &_td_OOC_SymbolTable__ArrayDesc, 97127)), 97133))+40);
  
l5:
  if (!i1) goto l17;
l8_loop:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 97168)))), &_td_OOC_SymbolTable__ArrayDesc, 97168)), 97174))+44);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 97168)))), &_td_OOC_SymbolTable__ArrayDesc, 97168)), 97174))+44);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 97186)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
  type = (OOC_SymbolTable__Type)i0;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 97110)))), &_td_OOC_SymbolTable__ArrayDesc);
  if (i1) goto l11;
  i1=0u;
  goto l13;
l11:
  i1 = *(OOC_UINT8*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 97127)))), &_td_OOC_SymbolTable__ArrayDesc, 97127)), 97133))+40);
  
l13:
  if (i1) goto l8_loop;
l17:
  return (OOC_SymbolTable__Type)i0;
  ;
}

OOC_SymbolTable__Type OOC_SymbolTable__ArrayDesc_GetInnermostElementType(OOC_SymbolTable__Array array) {
  register OOC_INT32 i0,i1;
  OOC_SymbolTable__Type type;

  i0 = (OOC_INT32)array;
  type = (OOC_SymbolTable__Type)i0;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 97456)))), &_td_OOC_SymbolTable__ArrayDesc);
  if (!i1) goto l9;
  
l4_loop:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 97488)))), &_td_OOC_SymbolTable__ArrayDesc, 97488)), 97494))+44);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 97488)))), &_td_OOC_SymbolTable__ArrayDesc, 97488)), 97494))+44);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 97506)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
  type = (OOC_SymbolTable__Type)i0;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 97456)))), &_td_OOC_SymbolTable__ArrayDesc);
  if (i1) goto l4_loop;
l9:
  return (OOC_SymbolTable__Type)i0;
  ;
}

OOC_SymbolTable__Type OOC_SymbolTable__ArrayDesc_GetNthElementType(OOC_SymbolTable__Array array, OOC_INT32 dim) {
  register OOC_INT32 i0,i1,i2;
  OOC_SymbolTable__Type type;

  i0 = (OOC_INT32)array;
  type = (OOC_SymbolTable__Type)i0;
  i1 = dim;
  i2 = i1>0;
  if (!i2) goto l9;
  
l4_loop:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 97867)))), &_td_OOC_SymbolTable__ArrayDesc, 97867)), 97873))+44);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 97867)))), &_td_OOC_SymbolTable__ArrayDesc, 97867)), 97873))+44);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 97885)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
  type = (OOC_SymbolTable__Type)i0;
  i1 = i1-1;
  dim = i1;
  i2 = i1>0;
  if (i2) goto l4_loop;
l9:
  return (OOC_SymbolTable__Type)i0;
  ;
}

void OOC_SymbolTable__InitFormalPars(OOC_SymbolTable__FormalPars formalPars, OOC_SymbolTable__Item parent, OOC_SymbolTable__Position position) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)position;
  i1 = (OOC_INT32)parent;
  i2 = (OOC_INT32)formalPars;
  OOC_SymbolTable__InitType((OOC_SymbolTable__Type)i2, (OOC_SymbolTable__Item)i1, (OOC_SymbolTable__Position)i0);
  *(OOC_INT32*)((_check_pointer(i2, 98147))+40) = (OOC_INT32)0;
  *(OOC_INT32*)((_check_pointer(i2, 98180))+44) = (OOC_INT32)0;
  *(OOC_INT32*)((_check_pointer(i2, 98215))+48) = (OOC_INT32)0;
  *(OOC_INT32*)((_check_pointer(i2, 98257))+52) = (OOC_INT32)0;
  *(OOC_UINT8*)((_check_pointer(i2, 98288))+56) = 0u;
  *(OOC_UINT8*)((_check_pointer(i2, 98332))+57) = 0u;
  *(OOC_INT8*)((_check_pointer(i2, 98367))+58) = 0;
  *(OOC_INT32*)((_check_pointer(i2, 98412))+60) = (OOC_INT32)0;
  *(OOC_INT32*)((_check_pointer(i2, 98443))+64) = (OOC_INT32)0;
  return;
  ;
}

void OOC_SymbolTable__FormalParsDesc_EnableRestParameters(OOC_SymbolTable__FormalPars formalPars) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)formalPars;
  *(OOC_UINT8*)((_check_pointer(i0, 98661))+56) = 1u;
  return;
  ;
}

void OOC_SymbolTable__FormalParsDesc_SetResultType(OOC_SymbolTable__FormalPars formalPars, OOC_SymbolTable__Type resultType) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)formalPars;
  i1 = (OOC_INT32)resultType;
  *(OOC_INT32*)((_check_pointer(i0, 98809))+44) = i1;
  *(OOC_INT32*)((_check_pointer(i0, 98850))+48) = i1;
  return;
  ;
}

void OOC_SymbolTable__FormalParsDesc_SetNamespace(OOC_SymbolTable__FormalPars formalPars, OOC_SymbolTable__Namespace ns) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)formalPars;
  i1 = (OOC_INT32)ns;
  *(OOC_INT32*)((_check_pointer(i0, 99081))+64) = i1;
  return;
  ;
}

void OOC_SymbolTable__FormalParsDesc_Store(OOC_SymbolTable__FormalPars formalPars, ADT_Storable__Writer w) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  OOC_INT32 i;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)formalPars;
  OOC_SymbolTable__TypeDesc_Store((OOC_SymbolTable__Type)i1, (ADT_Storable__Writer)i0);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 99282))+40);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 99257)))), ADT_Storable__WriterDesc_WriteObject)),ADT_Storable__WriterDesc_WriteObject)((ADT_Storable__Writer)i0, (Object__Object)i2);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 99322))+44);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 99345))+48);
  OOC_SymbolTable__WriteType((ADT_Storable__Writer)i0, (OOC_SymbolTable__Type)i2, (OOC_SymbolTable__Type)i3);
  i2 = *(OOC_UINT8*)((_check_pointer(i1, 99394))+56);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 99371)))), IO_BinaryRider__WriterDesc_WriteBool)),IO_BinaryRider__WriterDesc_WriteBool)((IO_BinaryRider__Writer)i0, i2);
  i2 = *(OOC_UINT8*)((_check_pointer(i1, 99444))+57);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 99421)))), IO_BinaryRider__WriterDesc_WriteBool)),IO_BinaryRider__WriterDesc_WriteBool)((IO_BinaryRider__Writer)i0, i2);
  i2 = *(OOC_INT8*)((_check_pointer(i1, 99485))+58);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 99462)))), IO_BinaryRider__WriterDesc_WriteSInt)),IO_BinaryRider__WriterDesc_WriteSInt)((IO_BinaryRider__Writer)i0, i2);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 99516))+60);
  i2 = i2==(OOC_INT32)0;
  if (i2) goto l11;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 99603))+60);
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 99611)), 0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 99576)))), IO_BinaryRider__WriterDesc_WriteNum)),IO_BinaryRider__WriterDesc_WriteNum)((IO_BinaryRider__Writer)i0, i2);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 99651))+60);
  i = 0;
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 99659)), 0);
  i3 = 0<i2;
  if (!i3) goto l12;
  i3=0;
l5_loop:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 99701))+60);
  i4 = _check_pointer(i4, 99709);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 99709))*4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 99676)))), ADT_Storable__WriterDesc_WriteObject)),ADT_Storable__WriterDesc_WriteObject)((ADT_Storable__Writer)i0, (Object__Object)i4);
  i3 = i3+1;
  i = i3;
  i4 = i3<i2;
  if (i4) goto l5_loop;
  goto l12;
l11:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 99544)))), IO_BinaryRider__WriterDesc_WriteNum)),IO_BinaryRider__WriterDesc_WriteNum)((IO_BinaryRider__Writer)i0, (-1));
l12:
  return;
  ;
}

void OOC_SymbolTable__FormalParsDesc_Load(OOC_SymbolTable__FormalPars formalPars, ADT_Storable__Reader r) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
  Object__Object obj;
  OOC_INT32 len;
  OOC_INT32 i;

  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)formalPars;
  OOC_SymbolTable__TypeDesc_Load((OOC_SymbolTable__Type)i1, (ADT_Storable__Reader)i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 99945)))), ADT_Storable__ReaderDesc_ReadObject)),ADT_Storable__ReaderDesc_ReadObject)((ADT_Storable__Reader)i0, (void*)(OOC_INT32)&obj);
  i2 = (OOC_INT32)obj;
  i3 = i2==(OOC_INT32)0;
  if (i3) goto l3;
  *(OOC_INT32*)((_check_pointer(i1, 100048))+40) = (_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 100066)))), &_td_OOC_SymbolTable__VarDeclDesc, 100066));
  goto l4;
l3:
  *(OOC_INT32*)((_check_pointer(i1, 100005))+40) = (OOC_INT32)0;
l4:
  OOC_SymbolTable__ReadType((ADT_Storable__Reader)i0, (void*)((_check_pointer(i1, 100110))+44), (void*)((_check_pointer(i1, 100133))+48));
  *(OOC_INT32*)((_check_pointer(i1, 100168))+52) = (OOC_INT32)0;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 100190)))), IO_BinaryRider__ReaderDesc_ReadBool)),IO_BinaryRider__ReaderDesc_ReadBool)((IO_BinaryRider__Reader)i0, (void*)((_check_pointer(i1, 100212))+56));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 100239)))), IO_BinaryRider__ReaderDesc_ReadBool)),IO_BinaryRider__ReaderDesc_ReadBool)((IO_BinaryRider__Reader)i0, (void*)((_check_pointer(i1, 100261))+57));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 100279)))), IO_BinaryRider__ReaderDesc_ReadSInt)),IO_BinaryRider__ReaderDesc_ReadSInt)((IO_BinaryRider__Reader)i0, (void*)((_check_pointer(i1, 100301))+58));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 100324)))), IO_BinaryRider__ReaderDesc_ReadNum)),IO_BinaryRider__ReaderDesc_ReadNum)((IO_BinaryRider__Reader)i0, (void*)(OOC_INT32)&len);
  i2 = len;
  i3 = i2<0;
  if (i3) goto l15;
  *(OOC_INT32*)((_check_pointer(i1, 100425))+60) = ((OOC_INT32)RT0__NewObject(_td_OOC_SymbolTable__ExceptionNameArray.baseTypes[0], i2));
  i = 0;
  i3 = 0<i2;
  if (!i3) goto l16;
  i3=0;
l9_loop:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 100479)))), ADT_Storable__ReaderDesc_ReadObject)),ADT_Storable__ReaderDesc_ReadObject)((ADT_Storable__Reader)i0, (void*)(OOC_INT32)&obj);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 100517))+60);
  i4 = _check_pointer(i4, 100525);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i6 = (OOC_INT32)obj;
  *(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 100525))*4) = (_type_guard(i6, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 100536)))), &_td_OOC_SymbolTable__ExceptionNameDesc, 100536));
  i3 = i3+1;
  i = i3;
  i4 = i3<i2;
  if (i4) goto l9_loop;
  goto l16;
l15:
  *(OOC_INT32*)((_check_pointer(i1, 100379))+60) = (OOC_INT32)0;
l16:
  *(OOC_INT32*)((_check_pointer(i1, 100584))+64) = (OOC_INT32)0;
  return;
  ;
}

static void OOC_SymbolTable__InitTypeClosure(OOC_SymbolTable__TypeClosure tc, OOC_SymbolTable__Position position, OOC_SymbolTable__Type baseType, OOC_SymbolTable__TypeVarArray params, OOC_SymbolTable__TypeRefArray arguments) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)params;
  i1 = (OOC_INT32)arguments;
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i0, 100845)), 0);
  i3 = OOC_ARRAY_LENGTH((_check_pointer(i1, 100863)), 0);
  _assert((i2==i3), 127, 100828);
  i2 = (OOC_INT32)tc;
  i3 = (OOC_INT32)position;
  OOC_SymbolTable__InitType((OOC_SymbolTable__Type)i2, (OOC_SymbolTable__Item)(OOC_INT32)0, (OOC_SymbolTable__Position)i3);
  i3 = (OOC_INT32)baseType;
  *(OOC_INT32*)((_check_pointer(i2, 100907))+40) = i3;
  *(OOC_INT32*)((_check_pointer(i2, 100936))+44) = i0;
  *(OOC_INT32*)((_check_pointer(i2, 100961))+48) = i1;
  i0 = i3!=(OOC_INT32)0;
  if (i0) goto l3;
  *(OOC_INT32*)((_check_pointer(i2, 101098))+32) = (-1);
  *(OOC_INT16*)((_check_pointer(i2, 101119))+36) = (-1);
  goto l4;
l3:
  i0 = *(OOC_INT32*)((_check_pointer(i3, 101040))+32);
  *(OOC_INT32*)((_check_pointer(i2, 101023))+32) = i0;
  i0 = *(OOC_INT16*)((_check_pointer(i3, 101073))+36);
  *(OOC_INT16*)((_check_pointer(i2, 101055))+36) = i0;
l4:
  return;
  ;
}

OOC_SymbolTable__TypeClosure OOC_SymbolTable__NewTypeClosure(OOC_SymbolTable__Position position, OOC_SymbolTable__Type baseType, OOC_SymbolTable__TypeVarArray params, OOC_SymbolTable__TypeRefArray arguments) {
  register OOC_INT32 i0,i1,i2,i3,i4;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_SymbolTable__TypeClosure.baseTypes[0]);
  i1 = (OOC_INT32)arguments;
  i2 = (OOC_INT32)params;
  i3 = (OOC_INT32)baseType;
  i4 = (OOC_INT32)position;
  OOC_SymbolTable__InitTypeClosure((OOC_SymbolTable__TypeClosure)i0, (OOC_SymbolTable__Position)i4, (OOC_SymbolTable__Type)i3, (OOC_SymbolTable__TypeVarArray)i2, (OOC_SymbolTable__TypeRefArray)i1);
  return (OOC_SymbolTable__TypeClosure)i0;
  ;
}

OOC_SymbolTable__Type OOC_SymbolTable__TypeClosureDesc_Deparam(OOC_SymbolTable__TypeClosure typeClosure) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)typeClosure;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 101576))+40);
  return (OOC_SymbolTable__Type)i0;
  ;
}

OOC_SymbolTable__Type OOC_SymbolTable__TypeClosureDesc_Lookup(OOC_SymbolTable__TypeClosure typeClosure, OOC_SymbolTable__TypeVar tv, OOC_SymbolTable__TypeVar _default) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_INT32 i;

  i0 = (OOC_INT32)typeClosure;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 101867))+44);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 101894))+48);
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 101874)), 0);
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 101904)), 0);
  _assert((i1==i2), 127, 101845);
  i = 0;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 101951))+44);
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 101958)), 0);
  i1 = 0!=i1;
  if (i1) goto l3;
  i1=0u;
  goto l5;
l3:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 101976))+44);
  i1 = _check_pointer(i1, 101983);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT32, 101983))*4);
  i2 = (OOC_INT32)tv;
  i1 = i1!=i2;
  
l5:
  if (i1) goto l7;
  i1=0;
  goto l17;
l7:
  i1 = (OOC_INT32)tv;
  i2=0;
l8_loop:
  i2 = i2+1;
  i = i2;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 101951))+44);
  i3 = OOC_ARRAY_LENGTH((_check_pointer(i3, 101958)), 0);
  i3 = i2!=i3;
  if (i3) goto l11;
  i3=0u;
  goto l13;
l11:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 101976))+44);
  i3 = _check_pointer(i3, 101983);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i2, i4, OOC_UINT32, 101983))*4);
  i3 = i3!=i1;
  
l13:
  if (i3) goto l8_loop;
l16:
  i1=i2;
l17:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 102047))+44);
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 102054)), 0);
  i2 = i1==i2;
  if (i2) goto l20;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 102312))+48);
  i0 = _check_pointer(i0, 102322);
  i2 = OOC_ARRAY_LENGTH(i0, 0);
  i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(i1, i2, OOC_UINT32, 102322))*8);
  return (OOC_SymbolTable__Type)i0;
  goto l21;
l20:
  i0 = (OOC_INT32)_default;
  return (OOC_SymbolTable__Type)i0;
l21:
  _failed_function(101640); return 0;
  ;
}

OOC_SymbolTable__Type OOC_SymbolTable__TypeClosureDesc_Closure(OOC_SymbolTable__TypeClosure closure, OOC_SymbolTable__Type type) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8;
  OOC_SymbolTable__TypeRefArray args;
  OOC_INT32 i;
  OOC_SymbolTable__Type nextType;

  i0 = (OOC_INT32)type;
  i1 = i0==(OOC_INT32)0;
  if (!i1) goto l3;
  return (OOC_SymbolTable__Type)(OOC_INT32)0;
l3:
  i1 = (OOC_INT32)&_td_OOC_SymbolTable__TypeRef;
  
l4_loop:
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 102652)))), &_td_OOC_SymbolTable__QualTypeDesc);
  if (i2) goto l19;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 103104)))), &_td_OOC_SymbolTable__TypeVarDesc);
  if (i2) goto l13;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 103317))+28);
  i2 = i2==(OOC_INT32)0;
  if (!i2) goto l29;
  return (OOC_SymbolTable__Type)i0;
  goto l28;
l13:
  i2 = (OOC_INT32)closure;
  i2 = (OOC_INT32)OOC_SymbolTable__TypeClosureDesc_Lookup((OOC_SymbolTable__TypeClosure)i2, (OOC_SymbolTable__TypeVar)i0, (OOC_SymbolTable__TypeVar)(OOC_INT32)0);
  nextType = (OOC_SymbolTable__Type)i2;
  i2 = i2==(OOC_INT32)0;
  if (i2) goto l16;
  i0 = (OOC_INT32)OOC_SymbolTable__emptyClosure;
  closure = (OOC_SymbolTable__TypeClosure)i0;
  goto l28;
l16:
  return (OOC_SymbolTable__Type)i0;
  goto l28;
l19:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 102689))+48);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 102712))+40);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 102721))+28);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 102730))+20);
  i3 = OOC_ARRAY_LENGTH((_check_pointer(i3, 102737)), 0);
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 102699)), 0);
  _assert((i2==i3), 127, 102674);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 102768))+40);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 102777))+28);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 102786))+20);
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 102793)), 0);
  i2 = (OOC_INT32)RT0__NewObject(_td_OOC_SymbolTable__TypeRefArray.baseTypes[0], i2);
  args = (OOC_SymbolTable__TypeRefArray)i2;
  i = 0;
  i3 = OOC_ARRAY_LENGTH((_check_pointer(i2, 102828)), 0);
  i4 = 0<i3;
  if (!i4) goto l27;
  i4 = (OOC_INT32)closure;
  i5=0;
l22_loop:
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 102887))+48);
  i6 = _check_pointer(i6, 102897);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)(i6+(_check_index(i5, i7, OOC_UINT32, 102897))*8);
  i6 = (OOC_INT32)OOC_SymbolTable__TypeClosureDesc_Closure((OOC_SymbolTable__TypeClosure)i4, (OOC_SymbolTable__Type)i6);
  i7 = OOC_ARRAY_LENGTH((_check_pointer(i2, 102862)), 0);
  i7 = _check_index(i5, i7, OOC_UINT32, 102862);
  i7 = _check_pointer(i2, 102862);
  i8 = OOC_ARRAY_LENGTH(i7, 0);
  OOC_SymbolTable__InitTypeRef((void*)(i7+(_check_index(i5, i8, OOC_UINT32, 102862))*8), (RT0__Struct)i1, (OOC_SymbolTable__Type)i6);
  i5 = i5+1;
  i = i5;
  i6 = i5<i3;
  if (i6) goto l22_loop;
l27:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 103014))+40);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 103023))+28);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 103032))+20);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 102960))+20);
  i2 = (OOC_INT32)OOC_SymbolTable__NewTypeClosure((OOC_SymbolTable__Position)i4, (OOC_SymbolTable__Type)(OOC_INT32)0, (OOC_SymbolTable__TypeVarArray)i3, (OOC_SymbolTable__TypeRefArray)i2);
  closure = (OOC_SymbolTable__TypeClosure)i2;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 103072))+40);
  nextType = (OOC_SymbolTable__Type)i0;
l28:
  i0 = (OOC_INT32)nextType;
  type = (OOC_SymbolTable__Type)i0;
  
  goto l4_loop;
l29:
  i1 = (OOC_INT32)closure;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 103626))+48);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 103610))+44);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 103560))+20);
  i0 = (OOC_INT32)OOC_SymbolTable__NewTypeClosure((OOC_SymbolTable__Position)i1, (OOC_SymbolTable__Type)i0, (OOC_SymbolTable__TypeVarArray)i3, (OOC_SymbolTable__TypeRefArray)i2);
  return (OOC_SymbolTable__Type)i0;
  ;
}

OOC_CHAR8 OOC_SymbolTable__TypeClosureDesc_ArgumentsInduced(OOC_SymbolTable__TypeClosure closure, OOC_SymbolTable__Type type) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8;
  OOC_INT32 i;
  OOC_INT32 j;

  i0 = (OOC_INT32)type;
  i1 = i0==(OOC_INT32)0;
  if (i1) goto l35;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 104144)))), &_td_OOC_SymbolTable__QualTypeDesc);
  if (i1) goto l5;
  i0 = (OOC_INT32)closure;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 104526))+48);
  i0 = OOC_ARRAY_LENGTH((_check_pointer(i0, 104536)), 0);
  return (i0==0);
  goto l36;
l5:
  i1 = (OOC_INT32)closure;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 104191))+44);
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 104198)), 0);
  i = 0;
  i3 = 0<i2;
  if (!i3) goto l33;
  i3=0;
l8_loop:
  j = 0;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 104253))+48);
  i4 = OOC_ARRAY_LENGTH((_check_pointer(i4, 104263)), 0);
  i4 = 0!=i4;
  if (i4) goto l11;
  i4=0u;
  goto l13;
l11:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 104290))+48);
  i4 = _check_pointer(i4, 104300);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 104318))+44);
  i6 = _check_pointer(i6, 104325);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(0, i5, OOC_UINT32, 104300))*8);
  i5 = (OOC_INT32)*(OOC_INT32*)(i6+(_check_index(i3, i7, OOC_UINT32, 104325))*4);
  i4 = i4!=i5;
  
l13:
  if (i4) goto l15;
  i4=0;
  goto l25;
l15:
  i4=0;
l16_loop:
  i4 = i4+1;
  j = i4;
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 104253))+48);
  i5 = OOC_ARRAY_LENGTH((_check_pointer(i5, 104263)), 0);
  i5 = i4!=i5;
  if (i5) goto l19;
  i5=0u;
  goto l21;
l19:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 104290))+48);
  i5 = _check_pointer(i5, 104300);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 104318))+44);
  i7 = _check_pointer(i7, 104325);
  i8 = OOC_ARRAY_LENGTH(i7, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 104300))*8);
  i6 = (OOC_INT32)*(OOC_INT32*)(i7+(_check_index(i3, i8, OOC_UINT32, 104325))*4);
  i5 = i5!=i6;
  
l21:
  if (i5) goto l16_loop;
l25:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 104394))+48);
  i5 = OOC_ARRAY_LENGTH((_check_pointer(i5, 104404)), 0);
  i4 = i4==i5;
  if (!i4) goto l28;
  return 0u;
l28:
  i3 = i3+1;
  i = i3;
  i4 = i3<i2;
  if (i4) goto l8_loop;
l33:
  return 1u;
  goto l36;
l35:
  i0 = (OOC_INT32)closure;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 104101))+48);
  i0 = OOC_ARRAY_LENGTH((_check_pointer(i0, 104111)), 0);
  return (i0==0);
l36:
  _failed_function(103688); return 0;
  ;
}

OOC_SymbolTable__Type OOC_SymbolTable__Expand(OOC_SymbolTable__Type type) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)type;
  i1 = (OOC_INT32)OOC_SymbolTable__emptyClosure;
  i0 = (OOC_INT32)OOC_SymbolTable__TypeClosureDesc_Closure((OOC_SymbolTable__TypeClosure)i1, (OOC_SymbolTable__Type)i0);
  return (OOC_SymbolTable__Type)i0;
  ;
}

OOC_SymbolTable__Namespace OOC_SymbolTable__ItemDesc_Namespace(OOC_SymbolTable__Item item) {

  return (OOC_SymbolTable__Namespace)(OOC_INT32)0;
  ;
}

OOC_SymbolTable__Namespace OOC_SymbolTable__ModuleDesc_Namespace(OOC_SymbolTable__Module item) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)item;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 106183))+48);
  return (OOC_SymbolTable__Namespace)i0;
  ;
}

OOC_SymbolTable__Namespace OOC_SymbolTable__ProcDeclDesc_Namespace(OOC_SymbolTable__ProcDecl item) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)item;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 106282))+60);
  return (OOC_SymbolTable__Namespace)i0;
  ;
}

OOC_SymbolTable__Namespace OOC_SymbolTable__FormalParsDesc_Namespace(OOC_SymbolTable__FormalPars item) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)item;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 106383))+64);
  return (OOC_SymbolTable__Namespace)i0;
  ;
}

OOC_SymbolTable__Namespace OOC_SymbolTable__RecordDesc_Namespace(OOC_SymbolTable__Record item) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)item;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 106480))+52);
  return (OOC_SymbolTable__Namespace)i0;
  ;
}

OOC_SymbolTable__Namespace OOC_SymbolTable__TypeParsDesc_Namespace(OOC_SymbolTable__TypePars item) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)item;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 106579))+24);
  return (OOC_SymbolTable__Namespace)i0;
  ;
}

OOC_SymbolTable__Namespace OOC_SymbolTable__QualTypeDesc_Namespace(OOC_SymbolTable__QualType item) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)item;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 106678))+40);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 106678))+40);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 106687)))), OOC_SymbolTable__ItemDesc_Namespace)),OOC_SymbolTable__ItemDesc_Namespace)((OOC_SymbolTable__Item)i0);
  return (OOC_SymbolTable__Namespace)i0;
  ;
}

void OOC_SymbolTable__Prune(OOC_SymbolTable__Module root, ADT_Dictionary_AddressKey__Dictionary keep) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
  ADT_ArrayList__ArrayList prunedImports;
  OOC_INT32 i;
  OOC_SymbolTable__Import import;
  OOC_SymbolTable__ModuleRef mr;
  auto void OOC_SymbolTable__Prune_PruneList(OOC_SymbolTable__Item *list, OOC_SymbolTable__Item *last);
    
    void OOC_SymbolTable__Prune_PruneList(OOC_SymbolTable__Item *list, OOC_SymbolTable__Item *last) {
      register OOC_INT32 i0,i1,i2;
      OOC_SymbolTable__Item _this;

      i0 = (OOC_INT32)*list;
      _this = (OOC_SymbolTable__Item)i0;
      *last = (OOC_SymbolTable__Item)(OOC_INT32)0;
      *list = (OOC_SymbolTable__Item)(OOC_INT32)0;
      i1 = i0!=(OOC_INT32)0;
      if (!i1) goto l23;
l3_loop:
      i1 = (OOC_INT32)keep;
      i1 = ADT_Dictionary_AddressKey__DictionaryDesc_HasKey((ADT_Dictionary_AddressKey__Dictionary)i1, (Object__Object)i0);
      if (i1) goto l13;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 107529)))), &_td_OOC_SymbolTable__ImportDesc);
      if (i1) goto l8;
      i1=0u;
      goto l10;
l8:
      i1 = OOC_SymbolTable__ImportDesc_IsInternalImport((OOC_SymbolTable__Import)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 107548)))), &_td_OOC_SymbolTable__ImportDesc, 107548)));
      i1 = !i1;
      
l10:
      if (!i1) goto l18;
      i1 = (OOC_INT32)prunedImports;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 107605)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i1, (Object__Object)i0);
      goto l18;
l13:
      OOC_SymbolTable__Prune_PruneList((void*)((_check_pointer(i0, 107265))+8), (void*)((_check_pointer(i0, 107284))+12));
      i1 = (OOC_INT32)*last;
      i2 = i1==(OOC_INT32)0;
      if (i2) goto l16;
      *(OOC_INT32*)(_check_pointer(i1, 107437)) = i0;
      goto l17;
l16:
      *list = (OOC_SymbolTable__Item)i0;
l17:
      *last = (OOC_SymbolTable__Item)i0;
l18:
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 107668));
      _this = (OOC_SymbolTable__Item)i0;
      i1 = i0!=(OOC_INT32)0;
      if (i1) goto l3_loop;
l23:
      i0 = (OOC_INT32)*last;
      i1 = i0!=(OOC_INT32)0;
      if (!i1) goto l26;
      *(OOC_INT32*)(_check_pointer(i0, 107752)) = (OOC_INT32)0;
l26:
      return;
      ;
    }


  i0 = (OOC_INT32)ADT_ArrayList__New(8);
  prunedImports = (ADT_ArrayList__ArrayList)i0;
  i0 = (OOC_INT32)root;
  OOC_SymbolTable__Prune_PruneList((void*)((_check_pointer(i0, 107864))+8), (void*)((_check_pointer(i0, 107883))+12));
  i0 = (OOC_INT32)root;
  i1 = (OOC_INT32)prunedImports;
  i2 = *(OOC_INT32*)((_check_pointer(i1, 107944))+4);
  *(OOC_INT32*)((_check_pointer(i0, 107915))+72) = ((OOC_INT32)RT0__NewObject(_td_OOC_SymbolTable__ModuleRefArray.baseTypes[0], i2));
  i = 0;
  i2 = *(OOC_INT32*)((_check_pointer(i1, 107983))+4);
  i3 = 0<i2;
  if (!i3) goto l8;
  i3=0;
l3_loop:
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 108023));
  i4 = _check_pointer(i4, 108029);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 108029))*4);
  i4 = _type_guard(i4, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 108033)))), &_td_OOC_SymbolTable__ImportDesc, 108033);
  import = (OOC_SymbolTable__Import)i4;
  i5 = (OOC_INT32)RT0__NewObject(_td_OOC_SymbolTable__ModuleRef.baseTypes[0]);
  mr = (OOC_SymbolTable__ModuleRef)i5;
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 108080))+48);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i6, 108091))+12);
  *(OOC_INT32*)(_check_pointer(i5, 108065)) = i6;
  i4 = *(OOC_INT32*)((_check_pointer(i4, 108127))+56);
  *(OOC_INT32*)((_check_pointer(i5, 108105))+4) = i4;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 108151))+72);
  i4 = _check_pointer(i4, 108165);
  i6 = OOC_ARRAY_LENGTH(i4, 0);
  *(OOC_INT32*)(i4+(_check_index(i3, i6, OOC_UINT32, 108165))*4) = i5;
  i3 = i3+1;
  i = i3;
  i4 = i3<i2;
  if (i4) goto l3_loop;
l8:
  return;
  ;
}

OOC_Scanner_InputBuffer__CharArray OOC_SymbolTable__DeclarationDesc_GetId(OOC_SymbolTable__Declaration decl) {
  register OOC_INT32 i0,i1,i2;
  OOC_Scanner_InputBuffer__CharArray id;
  OOC_SymbolTable__Declaration declWithType;
  OOC_SymbolTable__Item ptr;
  OOC_SymbolTable__Item parent;
  auto OOC_SymbolTable__Declaration OOC_SymbolTable__DeclarationDesc_GetId_GetContainer(OOC_SymbolTable__Type type);
  auto OOC_Scanner_InputBuffer__CharArray OOC_SymbolTable__DeclarationDesc_GetId_Concat(OOC_Scanner_InputBuffer__CharArray a, OOC_Scanner_InputBuffer__CharArray b);
    
    OOC_SymbolTable__Declaration OOC_SymbolTable__DeclarationDesc_GetId_GetContainer(OOC_SymbolTable__Type type) {
      register OOC_INT32 i0,i1;
      OOC_SymbolTable__Item ptr;
      OOC_CHAR8 found;
      auto OOC_CHAR8 OOC_SymbolTable__DeclarationDesc_GetId_GetContainer_Contains(OOC_SymbolTable__Item ptr, OOC_SymbolTable__Item type);
        
        OOC_CHAR8 OOC_SymbolTable__DeclarationDesc_GetId_GetContainer_Contains(OOC_SymbolTable__Item ptr, OOC_SymbolTable__Item type) {
          register OOC_INT32 i0,i1,i2;

          i0 = (OOC_INT32)ptr;
          i1 = (OOC_INT32)type;
          i2 = i0==i1;
          if (i2) goto l11;
          i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 108915)))), &_td_OOC_SymbolTable__PointerDesc);
          if (i2) goto l9;
          i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 109000)))), &_td_OOC_SymbolTable__ArrayDesc);
          if (i2) goto l7;
          return 0u;
          goto l12;
l7:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 109043))+48);
          i0 = OOC_SymbolTable__DeclarationDesc_GetId_GetContainer_Contains((OOC_SymbolTable__Item)i0, (OOC_SymbolTable__Item)i1);
          return i0;
          goto l12;
l9:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 108960))+44);
          i0 = OOC_SymbolTable__DeclarationDesc_GetId_GetContainer_Contains((OOC_SymbolTable__Item)i0, (OOC_SymbolTable__Item)i1);
          return i0;
          goto l12;
l11:
          return 1u;
l12:
          _failed_function(108784); return 0;
          ;
        }


      i0 = (OOC_INT32)type;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 109192)))), &_td_OOC_SymbolTable__RecordDesc);
      if (i1) goto l3;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 109212)))), &_td_OOC_SymbolTable__FormalParsDesc);
      
      goto l4;
l3:
      i1=1u;
l4:
      _assert(i1, 127, 109178);
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 109244)))), &_td_OOC_SymbolTable__FormalParsDesc);
      if (i1) goto l7;
      i1=0u;
      goto l9;
l7:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 109266))+4);
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 109275)))), &_td_OOC_SymbolTable__ProcDeclDesc);
      
l9:
      if (i1) goto l15;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 109361))+4);
      ptr = (OOC_SymbolTable__Item)i0;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 109387)))), &_td_OOC_SymbolTable__TypeParsDesc);
      if (!i1) goto l16;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 109425))+4);
      ptr = (OOC_SymbolTable__Item)i0;
      
      goto l16;
l15:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 109312))+4);
      return (OOC_SymbolTable__Declaration)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 109321)))), &_td_OOC_SymbolTable__ProcDeclDesc, 109321));
l16:
      i0 = (OOC_INT32)ptr;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 109477)))), &_td_OOC_SymbolTable__ModuleDesc);
      if (i1) goto l19;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 109510)))), &_td_OOC_SymbolTable__ProcDeclDesc);
      
      goto l21;
l19:
      i1=1u;
l21:
      if (i1) goto l23;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 109545)))), &_td_OOC_SymbolTable__RecordDesc);
      
      goto l25;
l23:
      i1=1u;
l25:
      if (i1) goto l27;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 109578)))), &_td_OOC_SymbolTable__FormalParsDesc);
      
      goto l28;
l27:
      i1=1u;
l28:
      _assert(i1, 127, 109464);
      found = 0u;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 109633))+8);
      ptr = (OOC_SymbolTable__Item)i0;
      i1 = i0!=(OOC_INT32)0;
      if (!i1) goto l55;
l31_loop:
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 109691)))), &_td_OOC_SymbolTable__VarDeclDesc);
      if (i1) goto l46;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 109770)))), &_td_OOC_SymbolTable__TypeDeclDesc);
      if (i1) goto l44;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 109850)))), &_td_OOC_SymbolTable__ProcDeclDesc);
      if (i1) goto l42;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 109929)))), &_td_OOC_SymbolTable__FieldDeclDesc);
      if (i1) goto l40;
      found = 0u;
      i0=0u;
      goto l47;
l40:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 109976))+52);
      i1 = (OOC_INT32)type;
      i0 = OOC_SymbolTable__DeclarationDesc_GetId_GetContainer_Contains((OOC_SymbolTable__Item)i0, (OOC_SymbolTable__Item)i1);
      found = i0;
      
      goto l47;
l42:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 109896))+64);
      i1 = (OOC_INT32)type;
      i0 = OOC_SymbolTable__DeclarationDesc_GetId_GetContainer_Contains((OOC_SymbolTable__Item)i0, (OOC_SymbolTable__Item)i1);
      found = i0;
      
      goto l47;
l44:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 109816))+52);
      i1 = (OOC_INT32)type;
      i0 = OOC_SymbolTable__DeclarationDesc_GetId_GetContainer_Contains((OOC_SymbolTable__Item)i0, (OOC_SymbolTable__Item)i1);
      found = i0;
      
      goto l47;
l46:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 109736))+52);
      i1 = (OOC_INT32)type;
      i0 = OOC_SymbolTable__DeclarationDesc_GetId_GetContainer_Contains((OOC_SymbolTable__Item)i0, (OOC_SymbolTable__Item)i1);
      found = i0;
      
l47:
      i1 = (OOC_INT32)ptr;
      if (!i0) goto l50;
      return (OOC_SymbolTable__Declaration)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 110091)))), &_td_OOC_SymbolTable__DeclarationDesc, 110091));
l50:
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 110135));
      ptr = (OOC_SymbolTable__Item)i0;
      i1 = i0!=(OOC_INT32)0;
      if (i1) goto l31_loop;
l55:
      _assert(0u, 127, 110165);
      _failed_function(108678); return 0;
      ;
    }

    
    OOC_Scanner_InputBuffer__CharArray OOC_SymbolTable__DeclarationDesc_GetId_Concat(OOC_Scanner_InputBuffer__CharArray a, OOC_Scanner_InputBuffer__CharArray b) {
      register OOC_INT32 i0,i1,i2,i3;
      OOC_Scanner_InputBuffer__CharArray n;

      i0 = (OOC_INT32)a;
      i1 = (
      _cmp8((const void*)(_check_pointer(i0, 110306)),(const void*)""))==0;
      if (i1) goto l3;
      i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 110380)), 0);
      i1 = Strings__Length((void*)(_check_pointer(i0, 110380)), i1);
      i2 = (OOC_INT32)b;
      i3 = OOC_ARRAY_LENGTH((_check_pointer(i2, 110400)), 0);
      i3 = Strings__Length((void*)(_check_pointer(i2, 110400)), i3);
      i1 = (OOC_INT32)RT0__NewObject(_td_OOC_Scanner_InputBuffer__CharArray.baseTypes[0], ((i1+i3)+2));
      n = (OOC_Scanner_InputBuffer__CharArray)i1;
      i3 = OOC_ARRAY_LENGTH((_check_pointer(i1, 110426)), 0);
      _copy_8((const void*)(_check_pointer(i0, 110422)),(void*)(_check_pointer(i1, 110426)),i3);
      i0 = OOC_ARRAY_LENGTH((_check_pointer(i1, 110460)), 0);
      Strings__Append(".", 2, (void*)(_check_pointer(i1, 110460)), i0);
      i0 = OOC_ARRAY_LENGTH((_check_pointer(i2, 110489)), 0);
      i3 = OOC_ARRAY_LENGTH((_check_pointer(i1, 110493)), 0);
      Strings__Append((void*)(_check_pointer(i2, 110489)), i0, (void*)(_check_pointer(i1, 110493)), i3);
      return (OOC_Scanner_InputBuffer__CharArray)i1;
      goto l4;
l3:
      i0 = (OOC_INT32)b;
      return (OOC_Scanner_InputBuffer__CharArray)i0;
l4:
      _failed_function(110217); return 0;
      ;
    }


  i0 = (OOC_INT32)decl;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 110563))+40);
  i1 = i1!=(OOC_INT32)0;
  if (i1) goto l44;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 110638)))), &_td_OOC_SymbolTable__ModuleDesc);
  if (i1) goto l42;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 110759)))), &_td_OOC_SymbolTable__ProcDeclDesc);
  if (i1) goto l7;
  i1=0u;
  goto l9;
l7:
  i1 = OOC_SymbolTable__ProcDeclDesc_IsTypeBound((OOC_SymbolTable__ProcDecl)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 110779)))), &_td_OOC_SymbolTable__ProcDeclDesc, 110779)));
  
l9:
  if (i1) goto l40;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 111078)))), &_td_OOC_SymbolTable__FieldDeclDesc);
  if (i1) goto l38;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 111354)))), &_td_OOC_SymbolTable__VarDeclDesc);
  if (i1) goto l15;
  i1=0u;
  goto l17;
l15:
  i1 = *(OOC_UINT8*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 111373)))), &_td_OOC_SymbolTable__VarDeclDesc, 111373)), 111381))+56);
  
l17:
  if (i1) goto l36;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 111663)))), &_td_OOC_SymbolTable__TypeDeclDesc);
  if (i1) goto l21;
  i1=0u;
  goto l23;
l21:
  i1 = OOC_SymbolTable__TypeDeclDesc_IsTypeParameter((OOC_SymbolTable__TypeDecl)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 111683)))), &_td_OOC_SymbolTable__TypeDeclDesc, 111683)));
  
l23:
  if (i1) goto l34;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 111987))+4);
  parent = (OOC_SymbolTable__Item)i1;
  i2 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 112019)))), &_td_OOC_SymbolTable__DeclarationDesc));
  if (!i2) goto l33;
l28_loop:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 112064))+4);
  parent = (OOC_SymbolTable__Item)i1;
  i2 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 112019)))), &_td_OOC_SymbolTable__DeclarationDesc));
  if (i2) goto l28_loop;
l33:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 112141))+20);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 112146))+12);
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 112115)))), &_td_OOC_SymbolTable__DeclarationDesc, 112115)), 112127)))), OOC_SymbolTable__DeclarationDesc_GetId)),OOC_SymbolTable__DeclarationDesc_GetId)((OOC_SymbolTable__Declaration)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 112115)))), &_td_OOC_SymbolTable__DeclarationDesc, 112115)));
  i0 = (OOC_INT32)OOC_SymbolTable__DeclarationDesc_GetId_Concat((OOC_Scanner_InputBuffer__CharArray)i1, (OOC_Scanner_InputBuffer__CharArray)i0);
  id = (OOC_Scanner_InputBuffer__CharArray)i0;
  
  goto l43;
l34:
  i1 = (OOC_INT32)OOC_SymbolTable__TypeDeclDesc_ParametricType((OOC_SymbolTable__TypeDecl)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 111866)))), &_td_OOC_SymbolTable__TypeDeclDesc, 111866)));
  ptr = (OOC_SymbolTable__Item)i1;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 111942))+20);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 111947))+12);
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 111919)))), &_td_OOC_SymbolTable__TypeDeclDesc, 111919)), 111928)))), OOC_SymbolTable__DeclarationDesc_GetId)),OOC_SymbolTable__DeclarationDesc_GetId)((OOC_SymbolTable__Declaration)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 111919)))), &_td_OOC_SymbolTable__TypeDeclDesc, 111919)));
  i0 = (OOC_INT32)OOC_SymbolTable__DeclarationDesc_GetId_Concat((OOC_Scanner_InputBuffer__CharArray)i1, (OOC_Scanner_InputBuffer__CharArray)i0);
  id = (OOC_Scanner_InputBuffer__CharArray)i0;
  
  goto l43;
l36:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 111552)))), &_td_OOC_SymbolTable__VarDeclDesc, 111552)), 111560))+4);
  i0 = (OOC_INT32)OOC_SymbolTable__DeclarationDesc_GetId_GetContainer((OOC_SymbolTable__Type)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 111569)))), &_td_OOC_SymbolTable__FormalParsDesc, 111569)));
  declWithType = (OOC_SymbolTable__Declaration)i0;
  i1 = (OOC_INT32)decl;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 111632))+20);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 111638))+12);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 111617)))), OOC_SymbolTable__DeclarationDesc_GetId)),OOC_SymbolTable__DeclarationDesc_GetId)((OOC_SymbolTable__Declaration)i0);
  i0 = (OOC_INT32)OOC_SymbolTable__DeclarationDesc_GetId_Concat((OOC_Scanner_InputBuffer__CharArray)i0, (OOC_Scanner_InputBuffer__CharArray)i1);
  id = (OOC_Scanner_InputBuffer__CharArray)i0;
  
  goto l43;
l38:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 111245)))), &_td_OOC_SymbolTable__FieldDeclDesc, 111245)), 111255))+4);
  i0 = (OOC_INT32)OOC_SymbolTable__DeclarationDesc_GetId_GetContainer((OOC_SymbolTable__Type)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 111264)))), &_td_OOC_SymbolTable__RecordDesc, 111264)));
  declWithType = (OOC_SymbolTable__Declaration)i0;
  i1 = (OOC_INT32)decl;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 111323))+20);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 111329))+12);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 111308)))), OOC_SymbolTable__DeclarationDesc_GetId)),OOC_SymbolTable__DeclarationDesc_GetId)((OOC_SymbolTable__Declaration)i0);
  i0 = (OOC_INT32)OOC_SymbolTable__DeclarationDesc_GetId_Concat((OOC_Scanner_InputBuffer__CharArray)i0, (OOC_Scanner_InputBuffer__CharArray)i1);
  id = (OOC_Scanner_InputBuffer__CharArray)i0;
  
  goto l43;
l40:
  i0 = (OOC_INT32)OOC_SymbolTable__ProcDeclDesc_Class((OOC_SymbolTable__ProcDecl)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 110977)))), &_td_OOC_SymbolTable__ProcDeclDesc, 110977)));
  i0 = (OOC_INT32)OOC_SymbolTable__DeclarationDesc_GetId_GetContainer((OOC_SymbolTable__Type)i0);
  declWithType = (OOC_SymbolTable__Declaration)i0;
  i1 = (OOC_INT32)decl;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 111047))+20);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 111053))+12);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 111032)))), OOC_SymbolTable__DeclarationDesc_GetId)),OOC_SymbolTable__DeclarationDesc_GetId)((OOC_SymbolTable__Declaration)i0);
  i0 = (OOC_INT32)OOC_SymbolTable__DeclarationDesc_GetId_Concat((OOC_Scanner_InputBuffer__CharArray)i0, (OOC_Scanner_InputBuffer__CharArray)i1);
  id = (OOC_Scanner_InputBuffer__CharArray)i0;
  
  goto l43;
l42:
  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_Scanner_InputBuffer__CharArray.baseTypes[0], 1);
  id = (OOC_Scanner_InputBuffer__CharArray)i0;
  i1 = _check_pointer(i0, 110731);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  *(OOC_UINT8*)(i1+(_check_index(0, i2, OOC_UINT8, 110731))) = 0u;
  
l43:
  i1 = (OOC_INT32)decl;
  *(OOC_INT32*)((_check_pointer(i1, 112174))+40) = i0;
  return (OOC_Scanner_InputBuffer__CharArray)i0;
  goto l45;
l44:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 110603))+40);
  return (OOC_Scanner_InputBuffer__CharArray)i0;
l45:
  _failed_function(108229); return 0;
  ;
}

OOC_SymbolTable__Namespace OOC_SymbolTable__DeclarationDesc_GetEmbeddedNamespace(OOC_SymbolTable__Declaration decl, OOC_CHAR8 followTypeNames) {
  register OOC_INT32 i0,i1;
  auto OOC_SymbolTable__Namespace OOC_SymbolTable__DeclarationDesc_GetEmbeddedNamespace_NamespaceOfType(OOC_SymbolTable__Type type, OOC_SymbolTable__Type srcType);
    
    OOC_SymbolTable__Namespace OOC_SymbolTable__DeclarationDesc_GetEmbeddedNamespace_NamespaceOfType(OOC_SymbolTable__Type type, OOC_SymbolTable__Type srcType) {
      register OOC_INT32 i0,i1;

      i0 = followTypeNames;
      i0 = !i0;
      if (i0) goto l3;
      i0=0u;
      goto l5;
l3:
      i0 = (OOC_INT32)srcType;
      i0 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 112623)))), &_td_OOC_SymbolTable__TypeNameDesc);
      
l5:
      if (i0) goto l39;
      i0 = (OOC_INT32)type;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 112811)))), &_td_OOC_SymbolTable__PredefTypeDesc);
      if (i1) goto l37;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 112862)))), &_td_OOC_SymbolTable__TypeNameDesc);
      if (i1) goto l35;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 112961)))), &_td_OOC_SymbolTable__PointerDesc);
      if (i1) goto l33;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 113061)))), &_td_OOC_SymbolTable__FormalParsDesc);
      if (i1) goto l31;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 113171)))), &_td_OOC_SymbolTable__ArrayDesc);
      if (i1) goto l29;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 113275)))), &_td_OOC_SymbolTable__RecordDesc);
      if (i1) goto l27;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 113327)))), &_td_OOC_SymbolTable__TypeVarDesc);
      if (i1) goto l25;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 113410)))), &_td_OOC_SymbolTable__QualTypeDesc);
      if (i1) goto l23;
      _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 113404)))), 113404);
      goto l40;
l23:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 113478))+44);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 113462))+40);
      i0 = (OOC_INT32)OOC_SymbolTable__DeclarationDesc_GetEmbeddedNamespace_NamespaceOfType((OOC_SymbolTable__Type)i0, (OOC_SymbolTable__Type)i1);
      return (OOC_SymbolTable__Namespace)i0;
      goto l40;
l25:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 113378))+40);
      i1 = (OOC_INT32)srcType;
      i0 = (OOC_INT32)OOC_SymbolTable__DeclarationDesc_GetEmbeddedNamespace_NamespaceOfType((OOC_SymbolTable__Type)i0, (OOC_SymbolTable__Type)i1);
      return (OOC_SymbolTable__Namespace)i0;
      goto l40;
l27:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 113308))+52);
      return (OOC_SymbolTable__Namespace)i0;
      goto l40;
l29:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 113239))+48);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 113220))+44);
      i0 = (OOC_INT32)OOC_SymbolTable__DeclarationDesc_GetEmbeddedNamespace_NamespaceOfType((OOC_SymbolTable__Type)i0, (OOC_SymbolTable__Type)i1);
      return (OOC_SymbolTable__Namespace)i0;
      goto l40;
l31:
      return (OOC_SymbolTable__Namespace)(OOC_INT32)0;
      goto l40;
l33:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 113028))+44);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 113012))+40);
      i0 = (OOC_INT32)OOC_SymbolTable__DeclarationDesc_GetEmbeddedNamespace_NamespaceOfType((OOC_SymbolTable__Type)i0, (OOC_SymbolTable__Type)i1);
      return (OOC_SymbolTable__Namespace)i0;
      goto l40;
l35:
      return (OOC_SymbolTable__Namespace)(OOC_INT32)0;
      goto l40;
l37:
      return (OOC_SymbolTable__Namespace)(OOC_INT32)0;
      goto l40;
l39:
      return (OOC_SymbolTable__Namespace)(OOC_INT32)0;
l40:
      _failed_function(112526); return 0;
      ;
    }


  i0 = (OOC_INT32)decl;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 113568)))), &_td_OOC_SymbolTable__ModuleDesc);
  if (i1) goto l35;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 113612)))), &_td_OOC_SymbolTable__ImportDesc);
  if (i1) goto l33;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 113672)))), &_td_OOC_SymbolTable__ProcDeclDesc);
  if (i1) goto l31;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 113718)))), &_td_OOC_SymbolTable__ConstDeclDesc);
  if (i1) goto l29;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 113760)))), &_td_OOC_SymbolTable__PredefProcDesc);
  if (i1) goto l27;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 113803)))), &_td_OOC_SymbolTable__VarDeclDesc);
  if (i1) goto l25;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 113887)))), &_td_OOC_SymbolTable__FieldDeclDesc);
  if (i1) goto l23;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 113973)))), &_td_OOC_SymbolTable__TypeDeclDesc);
  if (i1) goto l21;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 114058)))), &_td_OOC_SymbolTable__RedirectDesc);
  if (i1) goto l19;
  _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 114052)))), 114052);
  goto l36;
l19:
  return (OOC_SymbolTable__Namespace)(OOC_INT32)0;
  goto l36;
l21:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 114033))+52);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 114021))+48);
  i0 = (OOC_INT32)OOC_SymbolTable__DeclarationDesc_GetEmbeddedNamespace_NamespaceOfType((OOC_SymbolTable__Type)i0, (OOC_SymbolTable__Type)i1);
  return (OOC_SymbolTable__Namespace)i0;
  goto l36;
l23:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 113948))+52);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 113936))+48);
  i0 = (OOC_INT32)OOC_SymbolTable__DeclarationDesc_GetEmbeddedNamespace_NamespaceOfType((OOC_SymbolTable__Type)i0, (OOC_SymbolTable__Type)i1);
  return (OOC_SymbolTable__Namespace)i0;
  goto l36;
l25:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 113862))+52);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 113850))+48);
  i0 = (OOC_INT32)OOC_SymbolTable__DeclarationDesc_GetEmbeddedNamespace_NamespaceOfType((OOC_SymbolTable__Type)i0, (OOC_SymbolTable__Type)i1);
  return (OOC_SymbolTable__Namespace)i0;
  goto l36;
l27:
  return (OOC_SymbolTable__Namespace)(OOC_INT32)0;
  goto l36;
l29:
  return (OOC_SymbolTable__Namespace)(OOC_INT32)0;
  goto l36;
l31:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 113703))+60);
  return (OOC_SymbolTable__Namespace)i0;
  goto l36;
l33:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 113641))+52);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 113657))+48);
  return (OOC_SymbolTable__Namespace)i0;
  goto l36;
l35:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 113597))+48);
  return (OOC_SymbolTable__Namespace)i0;
l36:
  _failed_function(112260); return 0;
  ;
}

static void OOC_SymbolTable__Init(void) {
  register OOC_INT32 i0,i1,i2;
  OOC_SymbolTable__TypeVarArray params;
  OOC_SymbolTable__TypeRefArray arguments;
  OOC_Scanner_InputBuffer__CharArray nameString;

  i0 = (OOC_INT32)URI_Scheme_File__NewPrototype();
  URI__RegisterScheme((URI__URI)i0);
  OOC_SymbolTable__predefIdToType = (void*)(OOC_INT32)0;
  i0 = (OOC_INT32)URI_Scheme_File__ToURI("/", 2);
  OOC_SymbolTable__emptyBaseURI = (URI__HierarchicalURI)i0;
  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_SymbolTable__Position.baseTypes[0]);
  OOC_SymbolTable__importPosition = (OOC_SymbolTable__Position)i0;
  OOC_SymbolTable__InitPosition((OOC_SymbolTable__Position)i0, (-2), (-1), (-1));
  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_SymbolTable__TypeVarArray.baseTypes[0], 0);
  params = (OOC_SymbolTable__TypeVarArray)i0;
  i1 = (OOC_INT32)RT0__NewObject(_td_OOC_SymbolTable__TypeRefArray.baseTypes[0], 0);
  arguments = (OOC_SymbolTable__TypeRefArray)i1;
  i2 = (OOC_INT32)RT0__NewObject(_td_OOC_SymbolTable__TypeClosure.baseTypes[0]);
  OOC_SymbolTable__emptyClosure = (OOC_SymbolTable__TypeClosure)i2;
  OOC_SymbolTable__InitTypeClosure((OOC_SymbolTable__TypeClosure)i2, (OOC_SymbolTable__Position)(OOC_INT32)0, (OOC_SymbolTable__Type)(OOC_INT32)0, (OOC_SymbolTable__TypeVarArray)i0, (OOC_SymbolTable__TypeRefArray)i1);
  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_Scanner_InputBuffer__CharArray.baseTypes[0], 1);
  nameString = (OOC_Scanner_InputBuffer__CharArray)i0;
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 114624)), 0);
  _copy_8((const void*)"",(void*)(_check_pointer(i0, 114624)),i1);
  i1 = (OOC_INT32)RT0__NewObject(_td_OOC_SymbolTable__Name.baseTypes[0]);
  OOC_SymbolTable__predefName = (OOC_SymbolTable__Name)i1;
  OOC_SymbolTable__InitName((OOC_SymbolTable__Name)i1, (OOC_Scanner_InputBuffer__CharArray)i0, 0, 0, 0);
  return;
  ;
}

void OOC_OOC_SymbolTable_init(void) {
  _c0 = Object__NewLatin1Region("standard", 9, 0, 8);
  _c1 = Object__NewLatin1Region("internal", 9, 0, 8);
  _c2 = Object__NewLatin1Region("foreign", 8, 0, 7);
  _c3 = Object__NewLatin1Region("interface", 10, 0, 9);
  _c4 = Object__NewLatin1Region("--invalid--", 12, 0, 11);
  _c5 = Object__NewLatin1Region("default", 8, 0, 7);
  _c6 = Object__NewLatin1Region("internal", 9, 0, 8);
  _c7 = Object__NewLatin1Char(67u);
  _c8 = Object__NewLatin1Region("Pascal", 7, 0, 6);
  _c9 = Object__NewLatin1Region("Fastcall", 9, 0, 8);
  _c10 = Object__NewLatin1Char(67u);
  _c11 = Object__NewLatin1Region("Pascal", 7, 0, 6);
  _c12 = Object__NewLatin1Region("Fastcall", 9, 0, 8);

  OOC_SymbolTable__Init();
  return;
  ;
}

/* --- */
