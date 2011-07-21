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
  i0 = *(OOC_INT8*)((_check_pointer(i0, 70720))+52);
  return (i0==1);
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
  i1 = *(OOC_INT8*)((_check_pointer(i0, 71202))+52);
  i1 = i1==2;
  if (i1) goto l3;
  i1 = *(OOC_INT8*)((_check_pointer(i0, 71230))+52);
  i1 = i1==3;
  
  goto l4;
l3:
  i1=1u;
l4:
  _assert(i1, 127, 71190);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 71267))+64);
  l = (OOC_SymbolTable__LinkDirective)i0;
  i1 = i0!=(OOC_INT32)0;
  if (i1) goto l7;
  i1=0u;
  goto l9;
l7:
  i1 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 71311)))), &_td_OOC_SymbolTable__LinkFileDesc));
  
l9:
  if (!i1) goto l21;
l12_loop:
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 71339));
  l = (OOC_SymbolTable__LinkDirective)i0;
  i1 = i0!=(OOC_INT32)0;
  if (i1) goto l15;
  i1=0u;
  goto l17;
l15:
  i1 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 71311)))), &_td_OOC_SymbolTable__LinkFileDesc));
  
l17:
  if (i1) goto l12_loop;
l21:
  i1 = i0==(OOC_INT32)0;
  if (i1) goto l24;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 71420)))), &_td_OOC_SymbolTable__LinkFileDesc, 71420)), 71429))+4);
  _assert((i1!=(OOC_INT32)0), 127, 71410);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 71452)))), &_td_OOC_SymbolTable__LinkFileDesc, 71452)), 71461))+4);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 71452)))), &_td_OOC_SymbolTable__LinkFileDesc, 71452)), 71461))+4);
  i3 = (OOC_INT32)rootURI;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 71467)))), URI__HierarchicalURIDesc_ResolveRelative)),URI__HierarchicalURIDesc_ResolveRelative)((URI__HierarchicalURI)i2, (URI__HierarchicalURI)i3);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 71511)))), &_td_OOC_SymbolTable__LinkFileDesc, 71511)), 71520))+4);
  return (URI__HierarchicalURI)i0;
  goto l25;
l24:
  return (URI__HierarchicalURI)(OOC_INT32)0;
l25:
  _failed_function(70796); return 0;
  ;
}

OOC_INT8 OOC_SymbolTable__StringToCallConv(Object__String str) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)str;
  i1 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 71633)))), Object__StringDesc_Equals)),Object__StringDesc_Equals)((Object__String)i0, (Object__Object)((OOC_INT32)_c10));
  if (i1) goto l11;
  i1 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 71687)))), Object__StringDesc_Equals)),Object__StringDesc_Equals)((Object__String)i0, (Object__Object)((OOC_INT32)_c11));
  if (i1) goto l9;
  i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 71751)))), Object__StringDesc_Equals)),Object__StringDesc_Equals)((Object__String)i0, (Object__Object)((OOC_INT32)_c12));
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
  _failed_function(71573); return 0;
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
  *(OOC_INT32*)((_check_pointer(i4, 72159))+48) = i0;
  *(OOC_INT32*)((_check_pointer(i4, 72197))+52) = (OOC_INT32)0;
  return;
  ;
}

void OOC_SymbolTable__ImportDesc_SetExternalSymTab(OOC_SymbolTable__Import import, OOC_SymbolTable__Module symTab) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)import;
  i1 = (OOC_INT32)symTab;
  *(OOC_INT32*)((_check_pointer(i0, 72323))+52) = i1;
  i1 = *(OOC_INT32*)((_check_pointer(i1, 72384))+68);
  *(OOC_INT32*)((_check_pointer(i0, 72361))+56) = i1;
  return;
  ;
}

OOC_CHAR8 OOC_SymbolTable__ImportDesc_IsInternalImport(OOC_SymbolTable__Import import) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)import;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 72649))+48);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 72661))+12);
  return ((
  _cmp8((const void*)(_check_pointer(i0, 72666)),(const void*)"SYSTEM"))==0);
  ;
}

void OOC_SymbolTable__ImportDesc_Store(OOC_SymbolTable__Import import, ADT_Storable__Writer w) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)import;
  OOC_SymbolTable__DeclarationDesc_Store((OOC_SymbolTable__Declaration)i1, (ADT_Storable__Writer)i0);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 72837))+48);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 72816)))), ADT_Storable__WriterDesc_WriteObject)),ADT_Storable__WriterDesc_WriteObject)((ADT_Storable__Writer)i0, (Object__Object)i2);
  i1 = *(OOC_INT32*)((_check_pointer(i1, 72876))+56);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 72857)))), IO_BinaryRider__WriterDesc_WriteLInt)),IO_BinaryRider__WriterDesc_WriteLInt)((IO_BinaryRider__Writer)i0, i1);
  return;
  ;
}

void OOC_SymbolTable__ImportDesc_Load(OOC_SymbolTable__Import import, ADT_Storable__Reader r) {
  register OOC_INT32 i0,i1,i2;
  Object__Object obj;

  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)import;
  OOC_SymbolTable__DeclarationDesc_Load((OOC_SymbolTable__Declaration)i1, (ADT_Storable__Reader)i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 73043)))), ADT_Storable__ReaderDesc_ReadObject)),ADT_Storable__ReaderDesc_ReadObject)((ADT_Storable__Reader)i0, (void*)(OOC_INT32)&obj);
  i2 = (OOC_INT32)obj;
  *(OOC_INT32*)((_check_pointer(i1, 73073))+48) = (_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 73093)))), &_td_OOC_SymbolTable__NameDesc, 73093));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 73105)))), IO_BinaryRider__ReaderDesc_ReadLInt)),IO_BinaryRider__ReaderDesc_ReadLInt)((IO_BinaryRider__Reader)i0, (void*)((_check_pointer(i1, 73123))+56));
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
  *(OOC_INT32*)((_check_pointer(i5, 73590))+48) = i0;
  i0 = (OOC_INT32)type;
  *(OOC_INT32*)((_check_pointer(i5, 73621))+52) = i0;
  i0 = (OOC_INT32)constExpr;
  *(OOC_INT32*)((_check_pointer(i5, 73650))+56) = i0;
  return;
  ;
}

void OOC_SymbolTable__ConstDeclDesc_SetValueType(OOC_SymbolTable__ConstDecl constDecl, Object_Boxed__Object value, OOC_SymbolTable__PredefType type) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)constDecl;
  i1 = (OOC_INT32)value;
  *(OOC_INT32*)((_check_pointer(i0, 73809))+48) = i1;
  i1 = (OOC_INT32)type;
  *(OOC_INT32*)((_check_pointer(i0, 73839))+52) = i1;
  return;
  ;
}

void OOC_SymbolTable__ConstDeclDesc_Store(OOC_SymbolTable__ConstDecl constDecl, ADT_Storable__Writer w) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)constDecl;
  OOC_SymbolTable__DeclarationDesc_Store((OOC_SymbolTable__Declaration)i1, (ADT_Storable__Writer)i0);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 74017))+48);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 73993)))), ADT_Storable__WriterDesc_WriteObject)),ADT_Storable__WriterDesc_WriteObject)((ADT_Storable__Writer)i0, (Object__Object)i2);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 74044))+52);
  i2 = i2==(OOC_INT32)0;
  if (i2) goto l3;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 74276))+52);
  i1 = *(OOC_INT16*)((_check_pointer(i1, 74282))+40);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 74255)))), IO_BinaryRider__WriterDesc_WriteNum)),IO_BinaryRider__WriterDesc_WriteNum)((IO_BinaryRider__Writer)i0, i1);
  goto l4;
l3:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 74223)))), IO_BinaryRider__WriterDesc_WriteNum)),IO_BinaryRider__WriterDesc_WriteNum)((IO_BinaryRider__Writer)i0, (-1));
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 74473)))), ADT_Storable__ReaderDesc_ReadObject)),ADT_Storable__ReaderDesc_ReadObject)((ADT_Storable__Reader)i0, (void*)(OOC_INT32)&obj);
  i2 = (OOC_INT32)obj;
  i3 = i2==(OOC_INT32)0;
  if (i3) goto l3;
  *(OOC_INT32*)((_check_pointer(i1, 74571))+48) = (_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 74592)))), &_td_Object_Boxed__ObjectDesc, 74592));
  goto l4;
l3:
  *(OOC_INT32*)((_check_pointer(i1, 74532))+48) = (OOC_INT32)0;
l4:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 74614)))), IO_BinaryRider__ReaderDesc_ReadNum)),IO_BinaryRider__ReaderDesc_ReadNum)((IO_BinaryRider__Reader)i0, (void*)(OOC_INT32)&id);
  i0 = id;
  i2 = i0==(-1);
  if (i2) goto l7;
  i2 = (OOC_INT32)OOC_SymbolTable__predefIdToType;
  i2 = _check_pointer(i2, 74784);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i0 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(i0, i3, OOC_UINT32, 74784))*4);
  *(OOC_INT32*)((_check_pointer(i1, 74760))+52) = i0;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 74813))+52);
  _assert((i0!=(OOC_INT32)0), 127, 74796);
  goto l8;
l7:
  *(OOC_INT32*)((_check_pointer(i1, 74721))+52) = (OOC_INT32)0;
l8:
  *(OOC_INT32*)((_check_pointer(i1, 74849))+56) = (OOC_INT32)0;
  return;
  ;
}

void OOC_SymbolTable__InitExceptionName(OOC_SymbolTable__ExceptionName exceptionName, OOC_SymbolTable__Item parent, OOC_SymbolTable__Type type) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)parent;
  i1 = (OOC_INT32)exceptionName;
  OOC_SymbolTable__InitItem((OOC_SymbolTable__Item)i1, (OOC_SymbolTable__Item)i0);
  i0 = (OOC_INT32)type;
  *(OOC_INT32*)((_check_pointer(i1, 75062))+24) = i0;
  *(OOC_INT32*)((_check_pointer(i1, 75102))+20) = i0;
  return;
  ;
}

void OOC_SymbolTable__ExceptionNameDesc_Store(OOC_SymbolTable__ExceptionName exceptionName, ADT_Storable__Writer w) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)exceptionName;
  OOC_SymbolTable__ItemDesc_Store((OOC_SymbolTable__Item)i1, (ADT_Storable__Writer)i0);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 75365))+24);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 75345))+20);
  OOC_SymbolTable__WriteType((ADT_Storable__Writer)i0, (OOC_SymbolTable__Type)i1, (OOC_SymbolTable__Type)i2);
  return;
  ;
}

void OOC_SymbolTable__ExceptionNameDesc_Load(OOC_SymbolTable__ExceptionName exceptionName, ADT_Storable__Reader r) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)exceptionName;
  OOC_SymbolTable__ItemDesc_Load((OOC_SymbolTable__Item)i1, (ADT_Storable__Reader)i0);
  OOC_SymbolTable__ReadType((ADT_Storable__Reader)i0, (void*)((_check_pointer(i1, 75546))+20), (void*)((_check_pointer(i1, 75566))+24));
  return;
  ;
}

void OOC_SymbolTable__VarDeclDesc_SetType(OOC_SymbolTable__VarDecl varDecl, OOC_SymbolTable__Type type) {
  register OOC_INT32 i0,i1,i2,i3;
  auto OOC_CHAR8 OOC_SymbolTable__VarDeclDesc_SetType_PassPerReference(OOC_SymbolTable__Type type);
    
    OOC_CHAR8 OOC_SymbolTable__VarDeclDesc_SetType_PassPerReference(OOC_SymbolTable__Type type) {
      register OOC_INT32 i0,i1;

      i0 = (OOC_INT32)type;
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 75727)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
      type = (OOC_SymbolTable__Type)i0;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 75758)))), &_td_OOC_SymbolTable__ArrayDesc);
      if (i1) goto l3;
      i0 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 75777)))), &_td_OOC_SymbolTable__RecordDesc);
      
      goto l4;
l3:
      i0=1u;
l4:
      return i0;
      ;
    }


  i0 = (OOC_INT32)varDecl;
  i1 = (OOC_INT32)type;
  *(OOC_INT32*)((_check_pointer(i0, 75836))+48) = i1;
  i2 = _check_pointer(i0, 75863);
  i3 = *(OOC_UINT8*)((_check_pointer(i0, 75902))+56);
  if (i3) goto l3;
  i0=0u;
  goto l8;
l3:
  i0 = *(OOC_UINT8*)((_check_pointer(i0, 75934))+59);
  if (i0) goto l6;
  i0 = OOC_SymbolTable__VarDeclDesc_SetType_PassPerReference((OOC_SymbolTable__Type)i1);
  
  goto l8;
l6:
  i0=1u;
l8:
  *(OOC_UINT8*)(i2+60) = i0;
  i0 = (OOC_INT32)varDecl;
  i1 = _check_pointer(i0, 75987);
  i2 = *(OOC_UINT8*)((_check_pointer(i0, 76020))+56);
  if (i2) goto l11;
  i0=0u;
  goto l13;
l11:
  i0 = *(OOC_UINT8*)((_check_pointer(i0, 76052))+59);
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
  i1 = _check_pointer(i0, 76111);
  i2 = *(OOC_UINT8*)((_check_pointer(i0, 76142))+60);
  if (i2) goto l19;
  i2=0u;
  goto l21;
l19:
  i2 = *(OOC_UINT8*)((_check_pointer(i0, 76181))+59);
  i2 = !i2;
  
l21:
  if (i2) goto l23;
  i0=0u;
  goto l24;
l23:
  i0 = *(OOC_UINT8*)((_check_pointer(i0, 76212))+61);
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
  *(OOC_INT32*)((_check_pointer(i5, 76640))+52) = i0;
  i1 = isParameter;
  *(OOC_UINT8*)((_check_pointer(i5, 76674))+56) = i1;
  i1 = isReceiver;
  *(OOC_UINT8*)((_check_pointer(i5, 76715))+57) = i1;
  *(OOC_UINT8*)((_check_pointer(i5, 76754))+58) = 0u;
  i2 = isVarParam;
  *(OOC_UINT8*)((_check_pointer(i5, 76790))+59) = i2;
  *(OOC_UINT8*)((_check_pointer(i5, 76829))+63) = 0u;
  *(OOC_UINT8*)((_check_pointer(i5, 76870))+64) = 1u;
  if (!i1) goto l3;
  *(OOC_INT32*)((_check_pointer((_type_guard(i4, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 76932)))), &_td_OOC_SymbolTable__FormalParsDesc, 76932)), 76943))+40) = i5;
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
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 77168))+52);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 77154))+48);
  OOC_SymbolTable__WriteType((ADT_Storable__Writer)i0, (OOC_SymbolTable__Type)i3, (OOC_SymbolTable__Type)i2);
  i2 = *(OOC_UINT8*)((_check_pointer(i1, 77208))+56);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 77188)))), IO_BinaryRider__WriterDesc_WriteBool)),IO_BinaryRider__WriterDesc_WriteBool)((IO_BinaryRider__Writer)i0, i2);
  i2 = *(OOC_UINT8*)((_check_pointer(i1, 77249))+57);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 77229)))), IO_BinaryRider__WriterDesc_WriteBool)),IO_BinaryRider__WriterDesc_WriteBool)((IO_BinaryRider__Writer)i0, i2);
  i2 = *(OOC_UINT8*)((_check_pointer(i1, 77289))+58);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 77269)))), IO_BinaryRider__WriterDesc_WriteBool)),IO_BinaryRider__WriterDesc_WriteBool)((IO_BinaryRider__Writer)i0, i2);
  i2 = *(OOC_UINT8*)((_check_pointer(i1, 77331))+59);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 77311)))), IO_BinaryRider__WriterDesc_WriteBool)),IO_BinaryRider__WriterDesc_WriteBool)((IO_BinaryRider__Writer)i0, i2);
  i2 = *(OOC_UINT8*)((_check_pointer(i1, 77371))+60);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 77351)))), IO_BinaryRider__WriterDesc_WriteBool)),IO_BinaryRider__WriterDesc_WriteBool)((IO_BinaryRider__Writer)i0, i2);
  i2 = *(OOC_UINT8*)((_check_pointer(i1, 77419))+61);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 77399)))), IO_BinaryRider__WriterDesc_WriteBool)),IO_BinaryRider__WriterDesc_WriteBool)((IO_BinaryRider__Writer)i0, i2);
  i2 = *(OOC_UINT8*)((_check_pointer(i1, 77461))+62);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 77441)))), IO_BinaryRider__WriterDesc_WriteBool)),IO_BinaryRider__WriterDesc_WriteBool)((IO_BinaryRider__Writer)i0, i2);
  i2 = *(OOC_UINT8*)((_check_pointer(i1, 77501))+63);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 77481)))), IO_BinaryRider__WriterDesc_WriteBool)),IO_BinaryRider__WriterDesc_WriteBool)((IO_BinaryRider__Writer)i0, i2);
  i1 = *(OOC_UINT8*)((_check_pointer(i1, 77548))+64);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 77528)))), IO_BinaryRider__WriterDesc_WriteBool)),IO_BinaryRider__WriterDesc_WriteBool)((IO_BinaryRider__Writer)i0, i1);
  return;
  ;
}

void OOC_SymbolTable__VarDeclDesc_Load(OOC_SymbolTable__VarDecl varDecl, ADT_Storable__Reader r) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)varDecl;
  OOC_SymbolTable__DeclarationDesc_Load((OOC_SymbolTable__Declaration)i1, (ADT_Storable__Reader)i0);
  OOC_SymbolTable__ReadType((ADT_Storable__Reader)i0, (void*)((_check_pointer(i1, 77709))+48), (void*)((_check_pointer(i1, 77723))+52));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 77743)))), IO_BinaryRider__ReaderDesc_ReadBool)),IO_BinaryRider__ReaderDesc_ReadBool)((IO_BinaryRider__Reader)i0, (void*)((_check_pointer(i1, 77762))+56));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 77783)))), IO_BinaryRider__ReaderDesc_ReadBool)),IO_BinaryRider__ReaderDesc_ReadBool)((IO_BinaryRider__Reader)i0, (void*)((_check_pointer(i1, 77802))+57));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 77822)))), IO_BinaryRider__ReaderDesc_ReadBool)),IO_BinaryRider__ReaderDesc_ReadBool)((IO_BinaryRider__Reader)i0, (void*)((_check_pointer(i1, 77841))+58));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 77863)))), IO_BinaryRider__ReaderDesc_ReadBool)),IO_BinaryRider__ReaderDesc_ReadBool)((IO_BinaryRider__Reader)i0, (void*)((_check_pointer(i1, 77882))+59));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 77902)))), IO_BinaryRider__ReaderDesc_ReadBool)),IO_BinaryRider__ReaderDesc_ReadBool)((IO_BinaryRider__Reader)i0, (void*)((_check_pointer(i1, 77921))+60));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 77949)))), IO_BinaryRider__ReaderDesc_ReadBool)),IO_BinaryRider__ReaderDesc_ReadBool)((IO_BinaryRider__Reader)i0, (void*)((_check_pointer(i1, 77968))+61));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 77990)))), IO_BinaryRider__ReaderDesc_ReadBool)),IO_BinaryRider__ReaderDesc_ReadBool)((IO_BinaryRider__Reader)i0, (void*)((_check_pointer(i1, 78009))+62));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 78029)))), IO_BinaryRider__ReaderDesc_ReadBool)),IO_BinaryRider__ReaderDesc_ReadBool)((IO_BinaryRider__Reader)i0, (void*)((_check_pointer(i1, 78048))+63));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 78075)))), IO_BinaryRider__ReaderDesc_ReadBool)),IO_BinaryRider__ReaderDesc_ReadBool)((IO_BinaryRider__Reader)i0, (void*)((_check_pointer(i1, 78094))+64));
  i0 = *(OOC_UINT8*)((_check_pointer(i1, 78132))+56);
  if (!i0) goto l4;
  *(OOC_INT32*)((_check_pointer(i1, 78244))+24) = (-1);
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
  *(OOC_INT32*)((_check_pointer(i5, 78673))+48) = i0;
  *(OOC_INT32*)((_check_pointer(i5, 78701))+52) = i0;
  i0 = isTypeParameter;
  *(OOC_UINT8*)((_check_pointer(i5, 78736))+56) = i0;
  return;
  ;
}

void OOC_SymbolTable__TypeDeclDesc_Store(OOC_SymbolTable__TypeDecl typeDecl, ADT_Storable__Writer w) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)typeDecl;
  OOC_SymbolTable__DeclarationDesc_Store((OOC_SymbolTable__Declaration)i1, (ADT_Storable__Writer)i0);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 78945))+52);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 78930))+48);
  OOC_SymbolTable__WriteType((ADT_Storable__Writer)i0, (OOC_SymbolTable__Type)i3, (OOC_SymbolTable__Type)i2);
  i1 = *(OOC_UINT8*)((_check_pointer(i1, 78986))+56);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 78965)))), IO_BinaryRider__WriterDesc_WriteBool)),IO_BinaryRider__WriterDesc_WriteBool)((IO_BinaryRider__Writer)i0, i1);
  return;
  ;
}

void OOC_SymbolTable__TypeDeclDesc_Load(OOC_SymbolTable__TypeDecl typeDecl, ADT_Storable__Reader r) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)typeDecl;
  OOC_SymbolTable__DeclarationDesc_Load((OOC_SymbolTable__Declaration)i1, (ADT_Storable__Reader)i0);
  OOC_SymbolTable__ReadType((ADT_Storable__Reader)i0, (void*)((_check_pointer(i1, 79152))+48), (void*)((_check_pointer(i1, 79167))+52));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 79187)))), IO_BinaryRider__ReaderDesc_ReadBool)),IO_BinaryRider__ReaderDesc_ReadBool)((IO_BinaryRider__Reader)i0, (void*)((_check_pointer(i1, 79207))+56));
  return;
  ;
}

OOC_CHAR8 OOC_SymbolTable__TypeDeclDesc_HasTypeParameters(OOC_SymbolTable__TypeDecl typeDecl) {
  register OOC_INT32 i0,i1,i2;
  OOC_SymbolTable__TypePars typePars;

  i0 = (OOC_INT32)typeDecl;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 79364))+48);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 79369))+28);
  typePars = (OOC_SymbolTable__TypePars)i1;
  i2 = i1!=(OOC_INT32)0;
  if (i2) goto l3;
  i0=0u;
  goto l4;
l3:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 79419))+48);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 79424))+4);
  i0 = i0==i1;
  
l4:
  return i0;
  ;
}

OOC_CHAR8 OOC_SymbolTable__TypeDeclDesc_IsTypeParameter(OOC_SymbolTable__TypeDecl typeDecl) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)typeDecl;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 79559))+4);
  return (OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 79567)))), &_td_OOC_SymbolTable__TypeParsDesc));
  ;
}

OOC_SymbolTable__TypeDecl OOC_SymbolTable__TypeDeclDesc_ParametricType(OOC_SymbolTable__TypeDecl typeDecl) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_SymbolTable__Item ptr;

  i0 = (OOC_INT32)typeDecl;
  i1 = OOC_SymbolTable__TypeDeclDesc_IsTypeParameter((OOC_SymbolTable__TypeDecl)i0);
  _assert(i1, 127, 79790);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 79845))+4);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 79852))+4);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 79859))+8);
  ptr = (OOC_SymbolTable__Item)i1;
  i2 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 79889)))), &_td_OOC_SymbolTable__TypeDeclDesc));
  if (i2) goto l3;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 79920)))), &_td_OOC_SymbolTable__TypeDeclDesc, 79920)), 79929))+48);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 79934))+4);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 79952))+4);
  i2 = i2!=i3;
  
  goto l5;
l3:
  i2=1u;
l5:
  if (i2) goto l8_loop;
  i0=i1;
  goto l17;
l8_loop:
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 79980));
  ptr = (OOC_SymbolTable__Item)i1;
  i2 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 79889)))), &_td_OOC_SymbolTable__TypeDeclDesc));
  if (i2) goto l11;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 79920)))), &_td_OOC_SymbolTable__TypeDeclDesc, 79920)), 79929))+48);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 79934))+4);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 79952))+4);
  i2 = i2!=i3;
  
  goto l13;
l11:
  i2=1u;
l13:
  if (i2) goto l8_loop;
l16:
  i0=i1;
l17:
  return (OOC_SymbolTable__TypeDecl)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 80017)))), &_td_OOC_SymbolTable__TypeDeclDesc, 80017));
  ;
}

void OOC_SymbolTable__InitRedirect(OOC_SymbolTable__Redirect redir, OOC_SymbolTable__Item parent, OOC_SymbolTable__Name name, OOC_SymbolTable__Name module, OOC_SymbolTable__Name ident) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)name;
  i1 = (OOC_INT32)parent;
  i2 = (OOC_INT32)redir;
  OOC_SymbolTable__InitDeclaration((OOC_SymbolTable__Declaration)i2, (OOC_SymbolTable__Item)i1, (OOC_SymbolTable__Name)i0, 0, 1, (OOC_Doc__Document)(OOC_INT32)0);
  i0 = (OOC_INT32)module;
  *(OOC_INT32*)((_check_pointer(i2, 80249))+48) = i0;
  i0 = (OOC_INT32)ident;
  *(OOC_INT32*)((_check_pointer(i2, 80278))+52) = i0;
  return;
  ;
}

void OOC_SymbolTable__RedirectDesc_Store(OOC_SymbolTable__Redirect redir, ADT_Storable__Writer w) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)redir;
  OOC_SymbolTable__DeclarationDesc_Store((OOC_SymbolTable__Declaration)i1, (ADT_Storable__Writer)i0);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 80446))+48);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 80426)))), ADT_Storable__WriterDesc_WriteObject)),ADT_Storable__WriterDesc_WriteObject)((ADT_Storable__Writer)i0, (Object__Object)i2);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 80482))+52);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 80462)))), ADT_Storable__WriterDesc_WriteObject)),ADT_Storable__WriterDesc_WriteObject)((ADT_Storable__Writer)i0, (Object__Object)i1);
  return;
  ;
}

void OOC_SymbolTable__RedirectDesc_Load(OOC_SymbolTable__Redirect redir, ADT_Storable__Reader r) {
  register OOC_INT32 i0,i1,i2;
  Object__Object obj;

  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)redir;
  OOC_SymbolTable__DeclarationDesc_Load((OOC_SymbolTable__Declaration)i1, (ADT_Storable__Reader)i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 80643)))), ADT_Storable__ReaderDesc_ReadObject)),ADT_Storable__ReaderDesc_ReadObject)((ADT_Storable__Reader)i0, (void*)(OOC_INT32)&obj);
  i2 = (OOC_INT32)obj;
  *(OOC_INT32*)((_check_pointer(i1, 80672))+48) = (_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 80688)))), &_td_OOC_SymbolTable__NameDesc, 80688));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 80700)))), ADT_Storable__ReaderDesc_ReadObject)),ADT_Storable__ReaderDesc_ReadObject)((ADT_Storable__Reader)i0, (void*)(OOC_INT32)&obj);
  i0 = (OOC_INT32)obj;
  *(OOC_INT32*)((_check_pointer(i1, 80729))+52) = (_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 80744)))), &_td_OOC_SymbolTable__NameDesc, 80744));
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
  *(OOC_INT32*)((_check_pointer(i5, 81077))+48) = i0;
  *(OOC_INT32*)((_check_pointer(i5, 81106))+52) = i0;
  *(OOC_INT32*)((_check_pointer(i5, 81142))+56) = (-1);
  *(OOC_UINT8*)((_check_pointer(i5, 81171))+60) = 0u;
  return;
  ;
}

void OOC_SymbolTable__FieldDeclDesc_Store(OOC_SymbolTable__FieldDecl fieldDecl, ADT_Storable__Writer w) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)fieldDecl;
  OOC_SymbolTable__DeclarationDesc_Store((OOC_SymbolTable__Declaration)i1, (ADT_Storable__Writer)i0);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 81379))+52);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 81363))+48);
  OOC_SymbolTable__WriteType((ADT_Storable__Writer)i0, (OOC_SymbolTable__Type)i3, (OOC_SymbolTable__Type)i2);
  i2 = *(OOC_INT32*)((_check_pointer(i1, 81420))+56);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 81399)))), IO_BinaryRider__WriterDesc_WriteNum)),IO_BinaryRider__WriterDesc_WriteNum)((IO_BinaryRider__Writer)i0, i2);
  i1 = *(OOC_UINT8*)((_check_pointer(i1, 81458))+60);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 81436)))), IO_BinaryRider__WriterDesc_WriteBool)),IO_BinaryRider__WriterDesc_WriteBool)((IO_BinaryRider__Writer)i0, i1);
  return;
  ;
}

void OOC_SymbolTable__FieldDeclDesc_Load(OOC_SymbolTable__FieldDecl fieldDecl, ADT_Storable__Reader r) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)fieldDecl;
  OOC_SymbolTable__DeclarationDesc_Load((OOC_SymbolTable__Declaration)i1, (ADT_Storable__Reader)i0);
  OOC_SymbolTable__ReadType((ADT_Storable__Reader)i0, (void*)((_check_pointer(i1, 81631))+48), (void*)((_check_pointer(i1, 81647))+52));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 81667)))), IO_BinaryRider__ReaderDesc_ReadNum)),IO_BinaryRider__ReaderDesc_ReadNum)((IO_BinaryRider__Reader)i0, (void*)((_check_pointer(i1, 81687))+56));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 81703)))), IO_BinaryRider__ReaderDesc_ReadBool)),IO_BinaryRider__ReaderDesc_ReadBool)((IO_BinaryRider__Reader)i0, (void*)((_check_pointer(i1, 81724))+60));
  return;
  ;
}

void OOC_SymbolTable__FieldDeclDesc_SetOffset(OOC_SymbolTable__FieldDecl fieldDecl, OOC_INT32 offset) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)fieldDecl;
  i1 = offset;
  *(OOC_INT32*)((_check_pointer(i0, 81844))+56) = i1;
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
  *(OOC_INT16*)((_check_pointer(i2, 82103))+48) = i0;
  i0 = minArgs;
  *(OOC_INT16*)((_check_pointer(i2, 82123))+50) = i0;
  i0 = maxArgs;
  *(OOC_INT16*)((_check_pointer(i2, 82153))+52) = i0;
  return;
  ;
}

void OOC_SymbolTable__PredefProcDesc_Store(OOC_SymbolTable__PredefProc proc, ADT_Storable__Writer w) {

  _assert(0u, 127, 82284);
  
  ;
}

void OOC_SymbolTable__PredefProcDesc_Load(OOC_SymbolTable__PredefProc proc, ADT_Storable__Reader r) {

  _assert(0u, 127, 82398);
  
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
  *(OOC_INT8*)((_check_pointer(i5, 82838))+48) = i0;
  i0 = isForwardDecl;
  *(OOC_UINT8*)((_check_pointer(i5, 82876))+49) = i0;
  *(OOC_UINT8*)((_check_pointer(i5, 82922))+50) = 0u;
  *(OOC_UINT8*)((_check_pointer(i5, 82957))+51) = 0u;
  *(OOC_UINT8*)((_check_pointer(i5, 82994))+52) = 1u;
  *(OOC_INT32*)((_check_pointer(i5, 83032))+56) = (-1);
  *(OOC_INT32*)((_check_pointer(i5, 83065))+60) = (OOC_INT32)0;
  *(OOC_INT32*)((_check_pointer(i5, 83090))+64) = (OOC_INT32)0;
  *(OOC_INT32*)((_check_pointer(i5, 83123))+68) = (OOC_INT32)0;
  i0 = (OOC_INT32)procAST;
  *(OOC_INT32*)((_check_pointer(i5, 83154))+72) = i0;
  *(OOC_UINT8*)((_check_pointer(i5, 83188))+76) = 0u;
  return;
  ;
}

void OOC_SymbolTable__ProcDeclDesc_Store(OOC_SymbolTable__ProcDecl procDecl, ADT_Storable__Writer w) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)procDecl;
  OOC_SymbolTable__DeclarationDesc_Store((OOC_SymbolTable__Declaration)i1, (ADT_Storable__Writer)i0);
  i2 = *(OOC_INT8*)((_check_pointer(i1, 83369))+48);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 83348)))), IO_BinaryRider__WriterDesc_WriteSInt)),IO_BinaryRider__WriterDesc_WriteSInt)((IO_BinaryRider__Writer)i0, i2);
  i2 = *(OOC_UINT8*)((_check_pointer(i1, 83409))+49);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 83388)))), IO_BinaryRider__WriterDesc_WriteBool)),IO_BinaryRider__WriterDesc_WriteBool)((IO_BinaryRider__Writer)i0, i2);
  i2 = *(OOC_UINT8*)((_check_pointer(i1, 83453))+50);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 83432)))), IO_BinaryRider__WriterDesc_WriteBool)),IO_BinaryRider__WriterDesc_WriteBool)((IO_BinaryRider__Writer)i0, i2);
  i2 = *(OOC_UINT8*)((_check_pointer(i1, 83494))+51);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 83473)))), IO_BinaryRider__WriterDesc_WriteBool)),IO_BinaryRider__WriterDesc_WriteBool)((IO_BinaryRider__Writer)i0, i2);
  i2 = *(OOC_UINT8*)((_check_pointer(i1, 83537))+52);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 83516)))), IO_BinaryRider__WriterDesc_WriteBool)),IO_BinaryRider__WriterDesc_WriteBool)((IO_BinaryRider__Writer)i0, i2);
  i2 = *(OOC_INT32*)((_check_pointer(i1, 83581))+56);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 83561)))), IO_BinaryRider__WriterDesc_WriteNum)),IO_BinaryRider__WriterDesc_WriteNum)((IO_BinaryRider__Writer)i0, i2);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 83625))+64);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 83602)))), ADT_Storable__WriterDesc_WriteObject)),ADT_Storable__WriterDesc_WriteObject)((ADT_Storable__Writer)i0, (Object__Object)i2);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 83665))+68);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 83645)))), IO_BinaryRider__WriterDesc_WriteStr)),IO_BinaryRider__WriterDesc_WriteStr)((IO_BinaryRider__Writer)i0, (Object__String)i1);
  return;
  ;
}

void OOC_SymbolTable__ProcDeclDesc_Load(OOC_SymbolTable__ProcDecl procDecl, ADT_Storable__Reader r) {
  register OOC_INT32 i0,i1,i2,i3;
  Object__Object obj;

  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)procDecl;
  OOC_SymbolTable__DeclarationDesc_Load((OOC_SymbolTable__Declaration)i1, (ADT_Storable__Reader)i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 83875)))), IO_BinaryRider__ReaderDesc_ReadSInt)),IO_BinaryRider__ReaderDesc_ReadSInt)((IO_BinaryRider__Reader)i0, (void*)((_check_pointer(i1, 83895))+48));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 83914)))), IO_BinaryRider__ReaderDesc_ReadBool)),IO_BinaryRider__ReaderDesc_ReadBool)((IO_BinaryRider__Reader)i0, (void*)((_check_pointer(i1, 83934))+49));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 83957)))), IO_BinaryRider__ReaderDesc_ReadBool)),IO_BinaryRider__ReaderDesc_ReadBool)((IO_BinaryRider__Reader)i0, (void*)((_check_pointer(i1, 83977))+50));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 83997)))), IO_BinaryRider__ReaderDesc_ReadBool)),IO_BinaryRider__ReaderDesc_ReadBool)((IO_BinaryRider__Reader)i0, (void*)((_check_pointer(i1, 84017))+51));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 84039)))), IO_BinaryRider__ReaderDesc_ReadBool)),IO_BinaryRider__ReaderDesc_ReadBool)((IO_BinaryRider__Reader)i0, (void*)((_check_pointer(i1, 84059))+52));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 84083)))), IO_BinaryRider__ReaderDesc_ReadNum)),IO_BinaryRider__ReaderDesc_ReadNum)((IO_BinaryRider__Reader)i0, (void*)((_check_pointer(i1, 84102))+56));
  *(OOC_INT32*)((_check_pointer(i1, 84130))+60) = (OOC_INT32)0;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 84148)))), ADT_Storable__ReaderDesc_ReadObject)),ADT_Storable__ReaderDesc_ReadObject)((ADT_Storable__Reader)i0, (void*)(OOC_INT32)&obj);
  i2 = (OOC_INT32)obj;
  i3 = i2==(OOC_INT32)0;
  if (i3) goto l3;
  *(OOC_INT32*)((_check_pointer(i1, 84249))+64) = (_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 84269)))), &_td_OOC_SymbolTable__FormalParsDesc, 84269));
  goto l4;
l3:
  *(OOC_INT32*)((_check_pointer(i1, 84206))+64) = (OOC_INT32)0;
l4:
  i0 = (OOC_INT32)OOC_SymbolTable__ReadString8((ADT_Storable__Reader)i0);
  *(OOC_INT32*)((_check_pointer(i1, 84302))+68) = i0;
  *(OOC_INT32*)((_check_pointer(i1, 84343))+72) = (OOC_INT32)0;
  *(OOC_UINT8*)((_check_pointer(i1, 84373))+76) = 0u;
  return;
  ;
}

void OOC_SymbolTable__ProcDeclDesc_SetNamespace(OOC_SymbolTable__ProcDecl procDecl, OOC_SymbolTable__Namespace ns) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)procDecl;
  i1 = (OOC_INT32)ns;
  *(OOC_INT32*)((_check_pointer(i0, 84572))+60) = i1;
  return;
  ;
}

void OOC_SymbolTable__ProcDeclDesc_SetLinkName(OOC_SymbolTable__ProcDecl procDecl, Object__String name) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)procDecl;
  i1 = (OOC_INT32)name;
  *(OOC_INT32*)((_check_pointer(i0, 84685))+68) = i1;
  return;
  ;
}

void OOC_SymbolTable__ProcDeclDesc_CopyTBProcIndex(OOC_SymbolTable__ProcDecl procDecl, OOC_SymbolTable__ProcDecl redefinition) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)redefinition;
  i1 = (OOC_INT32)procDecl;
  i1 = *(OOC_INT32*)((_check_pointer(i1, 85054))+56);
  *(OOC_INT32*)((_check_pointer(i0, 85029))+56) = i1;
  return;
  ;
}

OOC_CHAR8 OOC_SymbolTable__ProcDeclDesc_IsTypeBound(OOC_SymbolTable__ProcDecl procDecl) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)procDecl;
  i0 = *(OOC_INT8*)((_check_pointer(i0, 85176))+48);
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
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 85555))+64);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 85566))+40);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 85555))+64);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 85566))+40);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 85575))+48);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 85575))+48);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 85580)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i1);
  _class = (OOC_SymbolTable__Item)i0;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 85608)))), &_td_OOC_SymbolTable__PointerDesc);
  if (!i1) goto l7;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 85648)))), &_td_OOC_SymbolTable__PointerDesc, 85648)), 85656))+40);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 85648)))), &_td_OOC_SymbolTable__PointerDesc, 85648)), 85656))+40);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 85665)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
  _class = (OOC_SymbolTable__Item)i0;
  
l7:
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 85704)))), &_td_OOC_SymbolTable__RecordDesc);
  if (i1) goto l10;
  return (OOC_SymbolTable__Record)(OOC_INT32)0;
  goto l12;
l10:
  return (OOC_SymbolTable__Record)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 85741)))), &_td_OOC_SymbolTable__RecordDesc, 85741));
l12:
  _failed_function(85255); return 0;
  ;
}

void OOC_SymbolTable__ProcDeclDesc_RegisterForwardDecl(OOC_SymbolTable__ProcDecl procDecl, OOC_SymbolTable__ProcDecl forward) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)procDecl;
  i1 = (OOC_INT32)forward;
  i1 = *(OOC_INT32*)((_check_pointer(i1, 86097))+24);
  *(OOC_INT32*)((_check_pointer(i0, 86073))+24) = i1;
  return;
  ;
}

OOC_CHAR8 OOC_SymbolTable__ProcDeclDesc_IsModuleBody(OOC_SymbolTable__ProcDecl procDecl) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)procDecl;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 86312))+4);
  return (i0==(OOC_INT32)0);
  ;
}

void OOC_SymbolTable__InitPredefType(OOC_SymbolTable__PredefType ptype, OOC_SymbolTable__Item parent, OOC_INT16 id) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)parent;
  i1 = (OOC_INT32)ptype;
  OOC_SymbolTable__InitType((OOC_SymbolTable__Type)i1, (OOC_SymbolTable__Item)i0, (OOC_SymbolTable__Position)(OOC_INT32)0);
  i0 = id;
  *(OOC_INT16*)((_check_pointer(i1, 86477))+40) = i0;
  return;
  ;
}

void OOC_SymbolTable__PredefTypeDesc_Store(OOC_SymbolTable__PredefType tname, ADT_Storable__Writer w) {

  _assert(0u, 127, 86599);
  return;
  ;
}

void OOC_SymbolTable__PredefTypeDesc_Load(OOC_SymbolTable__PredefType tname, ADT_Storable__Reader r) {

  _assert(0u, 127, 86714);
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
  *(OOC_INT32*)((_check_pointer(i2, 86923))+40) = i0;
  i0 = (OOC_INT32)ident;
  *(OOC_INT32*)((_check_pointer(i2, 86952))+44) = i0;
  return;
  ;
}

OOC_CHAR8 OOC_SymbolTable__TypeNameDesc_IsPredefReference(OOC_SymbolTable__TypeName tname) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)tname;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 87074))+40);
  i1 = i1!=(OOC_INT32)0;
  if (i1) goto l3;
  i0=0u;
  goto l4;
l3:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 87097))+40);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 87104))+12);
  i0 = _check_pointer(i0, 87108);
  i1 = OOC_ARRAY_LENGTH(i0, 0);
  i0 = *(OOC_UINT8*)(i0+(_check_index(0, i1, OOC_UINT8, 87108)));
  i0 = i0==0u;
  
l4:
  return i0;
  ;
}

void OOC_SymbolTable__TypeNameDesc_MarkAsPredefReference(OOC_SymbolTable__TypeName tname) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)tname;
  i1 = (OOC_INT32)OOC_SymbolTable__predefName;
  *(OOC_INT32*)((_check_pointer(i0, 87216))+40) = i1;
  return;
  ;
}

void OOC_SymbolTable__TypeNameDesc_Store(OOC_SymbolTable__TypeName tname, ADT_Storable__Writer w) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)tname;
  OOC_SymbolTable__TypeDesc_Store((OOC_SymbolTable__Type)i1, (ADT_Storable__Writer)i0);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 87398))+40);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 87378)))), ADT_Storable__WriterDesc_WriteObject)),ADT_Storable__WriterDesc_WriteObject)((ADT_Storable__Writer)i0, (Object__Object)i2);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 87434))+44);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 87414)))), ADT_Storable__WriterDesc_WriteObject)),ADT_Storable__WriterDesc_WriteObject)((ADT_Storable__Writer)i0, (Object__Object)i1);
  return;
  ;
}

void OOC_SymbolTable__TypeNameDesc_Load(OOC_SymbolTable__TypeName tname, ADT_Storable__Reader r) {
  register OOC_INT32 i0,i1,i2,i3;
  Object__Object obj;

  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)tname;
  OOC_SymbolTable__TypeDesc_Load((OOC_SymbolTable__Type)i1, (ADT_Storable__Reader)i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 87594)))), ADT_Storable__ReaderDesc_ReadObject)),ADT_Storable__ReaderDesc_ReadObject)((ADT_Storable__Reader)i0, (void*)(OOC_INT32)&obj);
  i2 = (OOC_INT32)obj;
  i3 = i2==(OOC_INT32)0;
  if (i3) goto l3;
  *(OOC_INT32*)((_check_pointer(i1, 87685))+40) = (_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 87701)))), &_td_OOC_SymbolTable__NameDesc, 87701));
  goto l4;
l3:
  *(OOC_INT32*)((_check_pointer(i1, 87649))+40) = (OOC_INT32)0;
l4:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 87721)))), ADT_Storable__ReaderDesc_ReadObject)),ADT_Storable__ReaderDesc_ReadObject)((ADT_Storable__Reader)i0, (void*)(OOC_INT32)&obj);
  i0 = (OOC_INT32)obj;
  *(OOC_INT32*)((_check_pointer(i1, 87750))+44) = (_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 87765)))), &_td_OOC_SymbolTable__NameDesc, 87765));
  return;
  ;
}

OOC_SymbolTable__Import OOC_SymbolTable__TypeNameDesc_GetImport(OOC_SymbolTable__TypeName tname) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_SymbolTable__Module module;
  OOC_SymbolTable__Declaration decl;

  i0 = (OOC_INT32)tname;
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 87911)))), OOC_SymbolTable__ItemDesc_Module)),OOC_SymbolTable__ItemDesc_Module)((OOC_SymbolTable__Item)i0);
  module = (OOC_SymbolTable__Module)i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 87941))+48);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 87975))+40);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 87941))+48);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 87945)))), OOC_SymbolTable__NamespaceDesc_IdentifyLocal)),OOC_SymbolTable__NamespaceDesc_IdentifyLocal)((OOC_SymbolTable__Namespace)i3, (OOC_SymbolTable__Item)i1, (OOC_SymbolTable__Name)i0, 0u);
  decl = (OOC_SymbolTable__Declaration)i0;
  return (OOC_SymbolTable__Import)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 88009)))), &_td_OOC_SymbolTable__ImportDesc, 88009));
  ;
}

void OOC_SymbolTable__InitRecord(OOC_SymbolTable__Record record, OOC_SymbolTable__Item parent, OOC_SymbolTable__Position position, OOC_SymbolTable__Type baseType) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)position;
  i1 = (OOC_INT32)parent;
  i2 = (OOC_INT32)record;
  OOC_SymbolTable__InitType((OOC_SymbolTable__Type)i2, (OOC_SymbolTable__Item)i1, (OOC_SymbolTable__Position)i0);
  i0 = (OOC_INT32)baseType;
  *(OOC_INT32*)((_check_pointer(i2, 88208))+40) = i0;
  *(OOC_INT32*)((_check_pointer(i2, 88242))+44) = i0;
  *(OOC_INT32*)((_check_pointer(i2, 88283))+48) = (-1);
  *(OOC_INT32*)((_check_pointer(i2, 88361))+52) = (OOC_INT32)0;
  *(OOC_UINT8*)((_check_pointer(i2, 88384))+56) = 0u;
  *(OOC_UINT8*)((_check_pointer(i2, 88414))+57) = 0u;
  *(OOC_UINT8*)((_check_pointer(i2, 88447))+58) = 1u;
  *(OOC_UINT8*)((_check_pointer(i2, 88481))+59) = 0u;
  *(OOC_UINT8*)((_check_pointer(i2, 88524))+60) = 0u;
  *(OOC_UINT8*)((_check_pointer(i2, 88555))+61) = 0u;
  *(OOC_INT16*)((_check_pointer(i2, 88586))+62) = 0;
  *(OOC_INT32*)((_check_pointer(i2, 88615))+64) = (OOC_INT32)0;
  return;
  ;
}

void OOC_SymbolTable__RecordDesc_Store(OOC_SymbolTable__Record record, ADT_Storable__Writer w) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)record;
  OOC_SymbolTable__TypeDesc_Store((OOC_SymbolTable__Type)i1, (ADT_Storable__Writer)i0);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 88797))+44);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 88780))+40);
  OOC_SymbolTable__WriteType((ADT_Storable__Writer)i0, (OOC_SymbolTable__Type)i3, (OOC_SymbolTable__Type)i2);
  i2 = *(OOC_INT32*)((_check_pointer(i1, 88839))+48);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 88821)))), IO_BinaryRider__WriterDesc_WriteNum)),IO_BinaryRider__WriterDesc_WriteNum)((IO_BinaryRider__Writer)i0, i2);
  i2 = *(OOC_UINT8*)((_check_pointer(i1, 88879))+56);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 88860)))), IO_BinaryRider__WriterDesc_WriteBool)),IO_BinaryRider__WriterDesc_WriteBool)((IO_BinaryRider__Writer)i0, i2);
  i2 = *(OOC_UINT8*)((_check_pointer(i1, 88915))+57);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 88896)))), IO_BinaryRider__WriterDesc_WriteBool)),IO_BinaryRider__WriterDesc_WriteBool)((IO_BinaryRider__Writer)i0, i2);
  i2 = *(OOC_UINT8*)((_check_pointer(i1, 88954))+58);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 88935)))), IO_BinaryRider__WriterDesc_WriteBool)),IO_BinaryRider__WriterDesc_WriteBool)((IO_BinaryRider__Writer)i0, i2);
  i2 = *(OOC_UINT8*)((_check_pointer(i1, 88995))+59);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 88976)))), IO_BinaryRider__WriterDesc_WriteBool)),IO_BinaryRider__WriterDesc_WriteBool)((IO_BinaryRider__Writer)i0, i2);
  i2 = *(OOC_UINT8*)((_check_pointer(i1, 89044))+60);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 89025)))), IO_BinaryRider__WriterDesc_WriteBool)),IO_BinaryRider__WriterDesc_WriteBool)((IO_BinaryRider__Writer)i0, i2);
  i2 = *(OOC_UINT8*)((_check_pointer(i1, 89081))+61);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 89062)))), IO_BinaryRider__WriterDesc_WriteBool)),IO_BinaryRider__WriterDesc_WriteBool)((IO_BinaryRider__Writer)i0, i2);
  i2 = *(OOC_INT16*)((_check_pointer(i1, 89117))+62);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 89099)))), IO_BinaryRider__WriterDesc_WriteInt)),IO_BinaryRider__WriterDesc_WriteInt)((IO_BinaryRider__Writer)i0, i2);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 89158))+64);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 89137)))), ADT_Storable__WriterDesc_WriteObject)),ADT_Storable__WriterDesc_WriteObject)((ADT_Storable__Writer)i0, (Object__Object)i1);
  return;
  ;
}

void OOC_SymbolTable__RecordDesc_Load(OOC_SymbolTable__Record record, ADT_Storable__Reader r) {
  register OOC_INT32 i0,i1,i2;
  Object__Object obj;

  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)record;
  OOC_SymbolTable__TypeDesc_Load((OOC_SymbolTable__Type)i1, (ADT_Storable__Reader)i0);
  OOC_SymbolTable__ReadType((ADT_Storable__Reader)i0, (void*)((_check_pointer(i1, 89368))+40), (void*)((_check_pointer(i1, 89385))+44));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 89409)))), IO_BinaryRider__ReaderDesc_ReadNum)),IO_BinaryRider__ReaderDesc_ReadNum)((IO_BinaryRider__Reader)i0, (void*)((_check_pointer(i1, 89426))+48));
  *(OOC_INT32*)((_check_pointer(i1, 89452))+52) = (OOC_INT32)0;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 89470)))), IO_BinaryRider__ReaderDesc_ReadBool)),IO_BinaryRider__ReaderDesc_ReadBool)((IO_BinaryRider__Reader)i0, (void*)((_check_pointer(i1, 89488))+56));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 89505)))), IO_BinaryRider__ReaderDesc_ReadBool)),IO_BinaryRider__ReaderDesc_ReadBool)((IO_BinaryRider__Reader)i0, (void*)((_check_pointer(i1, 89523))+57));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 89543)))), IO_BinaryRider__ReaderDesc_ReadBool)),IO_BinaryRider__ReaderDesc_ReadBool)((IO_BinaryRider__Reader)i0, (void*)((_check_pointer(i1, 89561))+58));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 89583)))), IO_BinaryRider__ReaderDesc_ReadBool)),IO_BinaryRider__ReaderDesc_ReadBool)((IO_BinaryRider__Reader)i0, (void*)((_check_pointer(i1, 89601))+59));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 89631)))), IO_BinaryRider__ReaderDesc_ReadBool)),IO_BinaryRider__ReaderDesc_ReadBool)((IO_BinaryRider__Reader)i0, (void*)((_check_pointer(i1, 89649))+60));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 89667)))), IO_BinaryRider__ReaderDesc_ReadBool)),IO_BinaryRider__ReaderDesc_ReadBool)((IO_BinaryRider__Reader)i0, (void*)((_check_pointer(i1, 89685))+61));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 89703)))), IO_BinaryRider__ReaderDesc_ReadInt)),IO_BinaryRider__ReaderDesc_ReadInt)((IO_BinaryRider__Reader)i0, (void*)((_check_pointer(i1, 89720))+62));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 89740)))), ADT_Storable__ReaderDesc_ReadObject)),ADT_Storable__ReaderDesc_ReadObject)((ADT_Storable__Reader)i0, (void*)(OOC_INT32)&obj);
  i0 = (OOC_INT32)obj;
  i2 = i0==(OOC_INT32)0;
  if (i2) goto l3;
  *(OOC_INT32*)((_check_pointer(i1, 89836))+64) = (_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 89855)))), &_td_OOC_SymbolTable__NameDesc, 89855));
  goto l4;
l3:
  *(OOC_INT32*)((_check_pointer(i1, 89796))+64) = (OOC_INT32)0;
l4:
  return;
  ;
}

void OOC_SymbolTable__RecordDesc_SetNamespace(OOC_SymbolTable__Record record, OOC_SymbolTable__Namespace ns) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)record;
  i1 = (OOC_INT32)ns;
  *(OOC_INT32*)((_check_pointer(i0, 90035))+52) = i1;
  return;
  ;
}

void OOC_SymbolTable__RecordDesc_AssignTBProcIndex(OOC_SymbolTable__Record record, OOC_SymbolTable__ProcDecl procDecl) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)procDecl;
  i1 = (OOC_INT32)record;
  i2 = *(OOC_INT32*)((_check_pointer(i1, 90359))+48);
  *(OOC_INT32*)((_check_pointer(i0, 90336))+56) = i2;
  i0 = *(OOC_INT32*)((_check_pointer(i1, 90389))+48);
  *(OOC_INT32*)((_check_pointer(i1, 90389))+48) = (i0+1);
  return;
  ;
}

OOC_INT32 OOC_SymbolTable__RecordDesc_ExtensionLevel(OOC_SymbolTable__Record record) {
  register OOC_INT32 i0,i1,i2;
  OOC_INT32 level;

  level = 0;
  i0 = (OOC_INT32)record;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 90669))+40);
  i1 = i1!=(OOC_INT32)0;
  if (i1) goto l3;
  i0=0;
  goto l9;
l3:
  i1=0;
l4_loop:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 90711))+40);
  i0 = _type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 90721)))), &_td_OOC_SymbolTable__RecordDesc, 90721);
  record = (OOC_SymbolTable__Record)i0;
  i1 = i1+1;
  level = i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 90669))+40);
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
  *(OOC_INT32*)((_check_pointer(i2, 90973))+40) = i0;
  *(OOC_INT32*)((_check_pointer(i2, 91001))+44) = i0;
  return;
  ;
}

void OOC_SymbolTable__TypeVarDesc_Store(OOC_SymbolTable__TypeVar typeVar, ADT_Storable__Writer w) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)typeVar;
  OOC_SymbolTable__TypeDesc_Store((OOC_SymbolTable__Type)i1, (ADT_Storable__Writer)i0);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 91189))+44);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 91174))+40);
  OOC_SymbolTable__WriteType((ADT_Storable__Writer)i0, (OOC_SymbolTable__Type)i1, (OOC_SymbolTable__Type)i2);
  return;
  ;
}

void OOC_SymbolTable__TypeVarDesc_Load(OOC_SymbolTable__TypeVar typeVar, ADT_Storable__Reader r) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)typeVar;
  OOC_SymbolTable__TypeDesc_Load((OOC_SymbolTable__Type)i1, (ADT_Storable__Reader)i0);
  OOC_SymbolTable__ReadType((ADT_Storable__Reader)i0, (void*)((_check_pointer(i1, 91345))+40), (void*)((_check_pointer(i1, 91360))+44));
  return;
  ;
}

OOC_SymbolTable__Type OOC_SymbolTable__TypeVarDesc_Bound(OOC_SymbolTable__TypeVar typeVar) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)typeVar;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 91460))+40);
  return (OOC_SymbolTable__Type)i0;
  ;
}

void OOC_SymbolTable__InitTypePars(OOC_SymbolTable__TypePars typePars, OOC_SymbolTable__Item parent) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)parent;
  i1 = (OOC_INT32)typePars;
  OOC_SymbolTable__InitItem((OOC_SymbolTable__Item)i1, (OOC_SymbolTable__Item)i0);
  *(OOC_INT32*)((_check_pointer(i1, 91595))+20) = (OOC_INT32)0;
  *(OOC_INT32*)((_check_pointer(i1, 91623))+24) = (OOC_INT32)0;
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
  *(OOC_INT32*)((_check_pointer(i1, 91937))+20) = (OOC_INT32)0;
  *(OOC_INT32*)((_check_pointer(i1, 91965))+24) = (OOC_INT32)0;
  return;
  ;
}

void OOC_SymbolTable__TypeParsDesc_SetNamespace(OOC_SymbolTable__TypePars typePars, OOC_SymbolTable__Namespace ns) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)typePars;
  i1 = (OOC_INT32)ns;
  *(OOC_INT32*)((_check_pointer(i0, 92150))+24) = i1;
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 92446)))), ADT_Storable__WriterDesc_WriteObject)),ADT_Storable__WriterDesc_WriteObject)((ADT_Storable__Writer)i0, (Object__Object)i1);
  return;
  ;
}

static void OOC_SymbolTable__LoadTypeRef(ADT_Storable__Reader r, struct OOC_SymbolTable__TypeRef *typeRef, RT0__Struct typeRef__tag) {
  register OOC_INT32 i0;
  Object__Object obj;

  i0 = (OOC_INT32)r;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 92650)))), ADT_Storable__ReaderDesc_ReadObject)),ADT_Storable__ReaderDesc_ReadObject)((ADT_Storable__Reader)i0, (void*)(OOC_INT32)&obj);
  i0 = (OOC_INT32)obj;
  *(OOC_INT32*)((OOC_INT32)typeRef+4) = (_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 92701)))), &_td_OOC_SymbolTable__TypeDesc, 92701));
  *(OOC_INT32*)(OOC_INT32)typeRef = (_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 92732)))), &_td_OOC_SymbolTable__TypeDesc, 92732));
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
  *(OOC_INT32*)((_check_pointer(i2, 92993))+40) = i0;
  *(OOC_INT32*)((_check_pointer(i2, 93028))+44) = i0;
  i0 = (OOC_INT32)arguments;
  *(OOC_INT32*)((_check_pointer(i2, 93070))+48) = i0;
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
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 93587))+44);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 93568))+40);
  OOC_SymbolTable__WriteType((ADT_Storable__Writer)i0, (OOC_SymbolTable__Type)i3, (OOC_SymbolTable__Type)i2);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 93633))+48);
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 93643)), 0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 93611)))), IO_BinaryRider__WriterDesc_WriteNum)),IO_BinaryRider__WriterDesc_WriteNum)((IO_BinaryRider__Writer)i0, i2);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 93678))+48);
  i = 0;
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 93688)), 0);
  i3 = 0<i2;
  if (!i3) goto l8;
  i3 = (OOC_INT32)&_td_OOC_SymbolTable__TypeRef;
  i4=0;
l3_loop:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 93726))+48);
  i5 = OOC_ARRAY_LENGTH((_check_pointer(i5, 93736)), 0);
  i5 = _check_index(i4, i5, OOC_UINT32, 93736);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 93726))+48);
  i5 = _check_pointer(i5, 93736);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  OOC_SymbolTable__StoreTypeRef((ADT_Storable__Writer)i0, (void*)(i5+(_check_index(i4, i6, OOC_UINT32, 93736))*8), (RT0__Struct)i3);
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
  OOC_SymbolTable__ReadType((ADT_Storable__Reader)i0, (void*)((_check_pointer(i1, 93922))+40), (void*)((_check_pointer(i1, 93941))+44));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 93965)))), IO_BinaryRider__ReaderDesc_ReadNum)),IO_BinaryRider__ReaderDesc_ReadNum)((IO_BinaryRider__Reader)i0, (void*)(OOC_INT32)&len);
  i2 = len;
  *(OOC_INT32*)((_check_pointer(i1, 93996))+48) = ((OOC_INT32)RT0__NewObject(_td_OOC_SymbolTable__TypeRefArray.baseTypes[0], i2));
  i = 0;
  i3 = 0<i2;
  if (!i3) goto l8;
  i3 = (OOC_INT32)&_td_OOC_SymbolTable__TypeRef;
  i4=0;
l3_loop:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 94070))+48);
  i5 = OOC_ARRAY_LENGTH((_check_pointer(i5, 94080)), 0);
  i5 = _check_index(i4, i5, OOC_UINT32, 94080);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 94070))+48);
  i5 = _check_pointer(i5, 94080);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  OOC_SymbolTable__LoadTypeRef((ADT_Storable__Reader)i0, (void*)(i5+(_check_index(i4, i6, OOC_UINT32, 94080))*8), (RT0__Struct)i3);
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
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 94184))+40);
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
  *(OOC_INT32*)((_check_pointer(i2, 94390))+40) = i0;
  *(OOC_INT32*)((_check_pointer(i2, 94425))+44) = i0;
  *(OOC_UINT8*)((_check_pointer(i2, 94467))+48) = 0u;
  *(OOC_UINT8*)((_check_pointer(i2, 94509))+49) = 0u;
  return;
  ;
}

void OOC_SymbolTable__PointerDesc_Store(OOC_SymbolTable__Pointer pointer, ADT_Storable__Writer w) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)pointer;
  OOC_SymbolTable__TypeDesc_Store((OOC_SymbolTable__Type)i1, (ADT_Storable__Writer)i0);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 94699))+44);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 94681))+40);
  OOC_SymbolTable__WriteType((ADT_Storable__Writer)i0, (OOC_SymbolTable__Type)i3, (OOC_SymbolTable__Type)i2);
  i2 = *(OOC_UINT8*)((_check_pointer(i1, 94743))+48);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 94723)))), IO_BinaryRider__WriterDesc_WriteBool)),IO_BinaryRider__WriterDesc_WriteBool)((IO_BinaryRider__Writer)i0, i2);
  i1 = *(OOC_UINT8*)((_check_pointer(i1, 94791))+49);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 94771)))), IO_BinaryRider__WriterDesc_WriteBool)),IO_BinaryRider__WriterDesc_WriteBool)((IO_BinaryRider__Writer)i0, i1);
  return;
  ;
}

void OOC_SymbolTable__PointerDesc_Load(OOC_SymbolTable__Pointer pointer, ADT_Storable__Reader r) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)pointer;
  OOC_SymbolTable__TypeDesc_Load((OOC_SymbolTable__Type)i1, (ADT_Storable__Reader)i0);
  OOC_SymbolTable__ReadType((ADT_Storable__Reader)i0, (void*)((_check_pointer(i1, 94946))+40), (void*)((_check_pointer(i1, 94964))+44));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 94988)))), IO_BinaryRider__ReaderDesc_ReadBool)),IO_BinaryRider__ReaderDesc_ReadBool)((IO_BinaryRider__Reader)i0, (void*)((_check_pointer(i1, 95007))+48));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 95035)))), IO_BinaryRider__ReaderDesc_ReadBool)),IO_BinaryRider__ReaderDesc_ReadBool)((IO_BinaryRider__Reader)i0, (void*)((_check_pointer(i1, 95054))+49));
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
  *(OOC_UINT8*)((_check_pointer(i2, 95316))+40) = i0;
  *(OOC_UINT8*)((_check_pointer(i2, 95355))+41) = 1u;
  *(OOC_UINT8*)((_check_pointer(i2, 95389))+42) = 0u;
  i0 = (OOC_INT32)elementType;
  *(OOC_INT32*)((_check_pointer(i2, 95425))+44) = i0;
  *(OOC_INT32*)((_check_pointer(i2, 95464))+48) = i0;
  *(OOC_INT32*)((_check_pointer(i2, 95510))+52) = (-1);
  i0 = (OOC_INT32)lengthExpr;
  *(OOC_INT32*)((_check_pointer(i2, 95535))+56) = i0;
  *(OOC_UINT8*)((_check_pointer(i2, 95572))+60) = 0u;
  return;
  ;
}

void OOC_SymbolTable__ArrayDesc_Store(OOC_SymbolTable__Array array, ADT_Storable__Writer w) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)array;
  OOC_SymbolTable__TypeDesc_Store((OOC_SymbolTable__Type)i1, (ADT_Storable__Writer)i0);
  i2 = *(OOC_UINT8*)((_check_pointer(i1, 95735))+40);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 95717)))), IO_BinaryRider__WriterDesc_WriteBool)),IO_BinaryRider__WriterDesc_WriteBool)((IO_BinaryRider__Writer)i0, i2);
  i2 = *(OOC_UINT8*)((_check_pointer(i1, 95774))+41);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 95756)))), IO_BinaryRider__WriterDesc_WriteBool)),IO_BinaryRider__WriterDesc_WriteBool)((IO_BinaryRider__Writer)i0, i2);
  i2 = *(OOC_UINT8*)((_check_pointer(i1, 95815))+42);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 95797)))), IO_BinaryRider__WriterDesc_WriteBool)),IO_BinaryRider__WriterDesc_WriteBool)((IO_BinaryRider__Writer)i0, i2);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 95856))+44);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 95875))+48);
  OOC_SymbolTable__WriteType((ADT_Storable__Writer)i0, (OOC_SymbolTable__Type)i2, (OOC_SymbolTable__Type)i3);
  i2 = *(OOC_INT32*)((_check_pointer(i1, 95919))+52);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 95902)))), IO_BinaryRider__WriterDesc_WriteNum)),IO_BinaryRider__WriterDesc_WriteNum)((IO_BinaryRider__Writer)i0, i2);
  i1 = *(OOC_UINT8*)((_check_pointer(i1, 95957))+60);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 95939)))), IO_BinaryRider__WriterDesc_WriteBool)),IO_BinaryRider__WriterDesc_WriteBool)((IO_BinaryRider__Writer)i0, i1);
  return;
  ;
}

void OOC_SymbolTable__ArrayDesc_Load(OOC_SymbolTable__Array array, ADT_Storable__Reader r) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)array;
  OOC_SymbolTable__TypeDesc_Load((OOC_SymbolTable__Type)i1, (ADT_Storable__Reader)i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 96088)))), IO_BinaryRider__ReaderDesc_ReadBool)),IO_BinaryRider__ReaderDesc_ReadBool)((IO_BinaryRider__Reader)i0, (void*)((_check_pointer(i1, 96105))+40));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 96126)))), IO_BinaryRider__ReaderDesc_ReadBool)),IO_BinaryRider__ReaderDesc_ReadBool)((IO_BinaryRider__Reader)i0, (void*)((_check_pointer(i1, 96143))+41));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 96166)))), IO_BinaryRider__ReaderDesc_ReadBool)),IO_BinaryRider__ReaderDesc_ReadBool)((IO_BinaryRider__Reader)i0, (void*)((_check_pointer(i1, 96183))+42));
  OOC_SymbolTable__ReadType((ADT_Storable__Reader)i0, (void*)((_check_pointer(i1, 96223))+44), (void*)((_check_pointer(i1, 96242))+48));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 96269)))), IO_BinaryRider__ReaderDesc_ReadNum)),IO_BinaryRider__ReaderDesc_ReadNum)((IO_BinaryRider__Reader)i0, (void*)((_check_pointer(i1, 96285))+52));
  *(OOC_INT32*)((_check_pointer(i1, 96305))+56) = (OOC_INT32)0;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 96331)))), IO_BinaryRider__ReaderDesc_ReadBool)),IO_BinaryRider__ReaderDesc_ReadBool)((IO_BinaryRider__Reader)i0, (void*)((_check_pointer(i1, 96348))+60));
  return;
  ;
}

void OOC_SymbolTable__ArrayDesc_SetLength(OOC_SymbolTable__Array array, OOC_INT32 length) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)array;
  i1 = length;
  *(OOC_INT32*)((_check_pointer(i0, 96446))+52) = i1;
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
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 96768)))), &_td_OOC_SymbolTable__ArrayDesc);
  if (i1) goto l3;
  i1=0u;
  goto l5;
l3:
  i1 = *(OOC_UINT8*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 96785)))), &_td_OOC_SymbolTable__ArrayDesc, 96785)), 96791))+40);
  
l5:
  if (i1) goto l7;
  i0=0;
  goto l17;
l7:
  i1=i0;i0=0;
l8_loop:
  i0 = i0+1;
  dim = i0;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 96843)))), &_td_OOC_SymbolTable__ArrayDesc, 96843)), 96849))+44);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 96843)))), &_td_OOC_SymbolTable__ArrayDesc, 96843)), 96849))+44);
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 96861)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i1);
  type = (OOC_SymbolTable__Type)i1;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 96768)))), &_td_OOC_SymbolTable__ArrayDesc);
  if (i2) goto l11;
  i2=0u;
  goto l13;
l11:
  i2 = *(OOC_UINT8*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 96785)))), &_td_OOC_SymbolTable__ArrayDesc, 96785)), 96791))+40);
  
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
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 97129)))), &_td_OOC_SymbolTable__ArrayDesc);
  if (i1) goto l3;
  i1=0u;
  goto l5;
l3:
  i1 = *(OOC_UINT8*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 97146)))), &_td_OOC_SymbolTable__ArrayDesc, 97146)), 97152))+40);
  
l5:
  if (!i1) goto l17;
l8_loop:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 97187)))), &_td_OOC_SymbolTable__ArrayDesc, 97187)), 97193))+44);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 97187)))), &_td_OOC_SymbolTable__ArrayDesc, 97187)), 97193))+44);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 97205)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
  type = (OOC_SymbolTable__Type)i0;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 97129)))), &_td_OOC_SymbolTable__ArrayDesc);
  if (i1) goto l11;
  i1=0u;
  goto l13;
l11:
  i1 = *(OOC_UINT8*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 97146)))), &_td_OOC_SymbolTable__ArrayDesc, 97146)), 97152))+40);
  
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
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 97475)))), &_td_OOC_SymbolTable__ArrayDesc);
  if (!i1) goto l9;
  
l4_loop:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 97507)))), &_td_OOC_SymbolTable__ArrayDesc, 97507)), 97513))+44);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 97507)))), &_td_OOC_SymbolTable__ArrayDesc, 97507)), 97513))+44);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 97525)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
  type = (OOC_SymbolTable__Type)i0;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 97475)))), &_td_OOC_SymbolTable__ArrayDesc);
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
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 97886)))), &_td_OOC_SymbolTable__ArrayDesc, 97886)), 97892))+44);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 97886)))), &_td_OOC_SymbolTable__ArrayDesc, 97886)), 97892))+44);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 97904)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
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
  *(OOC_INT32*)((_check_pointer(i2, 98166))+40) = (OOC_INT32)0;
  *(OOC_INT32*)((_check_pointer(i2, 98199))+44) = (OOC_INT32)0;
  *(OOC_INT32*)((_check_pointer(i2, 98234))+48) = (OOC_INT32)0;
  *(OOC_INT32*)((_check_pointer(i2, 98276))+52) = (OOC_INT32)0;
  *(OOC_UINT8*)((_check_pointer(i2, 98307))+56) = 0u;
  *(OOC_UINT8*)((_check_pointer(i2, 98351))+57) = 0u;
  *(OOC_INT8*)((_check_pointer(i2, 98386))+58) = 0;
  *(OOC_INT32*)((_check_pointer(i2, 98431))+60) = (OOC_INT32)0;
  *(OOC_INT32*)((_check_pointer(i2, 98462))+64) = (OOC_INT32)0;
  return;
  ;
}

void OOC_SymbolTable__FormalParsDesc_EnableRestParameters(OOC_SymbolTable__FormalPars formalPars) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)formalPars;
  *(OOC_UINT8*)((_check_pointer(i0, 98680))+56) = 1u;
  return;
  ;
}

void OOC_SymbolTable__FormalParsDesc_SetResultType(OOC_SymbolTable__FormalPars formalPars, OOC_SymbolTable__Type resultType) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)formalPars;
  i1 = (OOC_INT32)resultType;
  *(OOC_INT32*)((_check_pointer(i0, 98828))+44) = i1;
  *(OOC_INT32*)((_check_pointer(i0, 98869))+48) = i1;
  return;
  ;
}

void OOC_SymbolTable__FormalParsDesc_SetNamespace(OOC_SymbolTable__FormalPars formalPars, OOC_SymbolTable__Namespace ns) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)formalPars;
  i1 = (OOC_INT32)ns;
  *(OOC_INT32*)((_check_pointer(i0, 99100))+64) = i1;
  return;
  ;
}

void OOC_SymbolTable__FormalParsDesc_Store(OOC_SymbolTable__FormalPars formalPars, ADT_Storable__Writer w) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  OOC_INT32 i;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)formalPars;
  OOC_SymbolTable__TypeDesc_Store((OOC_SymbolTable__Type)i1, (ADT_Storable__Writer)i0);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 99301))+40);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 99276)))), ADT_Storable__WriterDesc_WriteObject)),ADT_Storable__WriterDesc_WriteObject)((ADT_Storable__Writer)i0, (Object__Object)i2);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 99341))+44);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 99364))+48);
  OOC_SymbolTable__WriteType((ADT_Storable__Writer)i0, (OOC_SymbolTable__Type)i2, (OOC_SymbolTable__Type)i3);
  i2 = *(OOC_UINT8*)((_check_pointer(i1, 99413))+56);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 99390)))), IO_BinaryRider__WriterDesc_WriteBool)),IO_BinaryRider__WriterDesc_WriteBool)((IO_BinaryRider__Writer)i0, i2);
  i2 = *(OOC_UINT8*)((_check_pointer(i1, 99463))+57);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 99440)))), IO_BinaryRider__WriterDesc_WriteBool)),IO_BinaryRider__WriterDesc_WriteBool)((IO_BinaryRider__Writer)i0, i2);
  i2 = *(OOC_INT8*)((_check_pointer(i1, 99504))+58);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 99481)))), IO_BinaryRider__WriterDesc_WriteSInt)),IO_BinaryRider__WriterDesc_WriteSInt)((IO_BinaryRider__Writer)i0, i2);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 99535))+60);
  i2 = i2==(OOC_INT32)0;
  if (i2) goto l11;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 99622))+60);
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 99630)), 0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 99595)))), IO_BinaryRider__WriterDesc_WriteNum)),IO_BinaryRider__WriterDesc_WriteNum)((IO_BinaryRider__Writer)i0, i2);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 99670))+60);
  i = 0;
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 99678)), 0);
  i3 = 0<i2;
  if (!i3) goto l12;
  i3=0;
l5_loop:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 99720))+60);
  i4 = _check_pointer(i4, 99728);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 99728))*4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 99695)))), ADT_Storable__WriterDesc_WriteObject)),ADT_Storable__WriterDesc_WriteObject)((ADT_Storable__Writer)i0, (Object__Object)i4);
  i3 = i3+1;
  i = i3;
  i4 = i3<i2;
  if (i4) goto l5_loop;
  goto l12;
l11:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 99563)))), IO_BinaryRider__WriterDesc_WriteNum)),IO_BinaryRider__WriterDesc_WriteNum)((IO_BinaryRider__Writer)i0, (-1));
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 99964)))), ADT_Storable__ReaderDesc_ReadObject)),ADT_Storable__ReaderDesc_ReadObject)((ADT_Storable__Reader)i0, (void*)(OOC_INT32)&obj);
  i2 = (OOC_INT32)obj;
  i3 = i2==(OOC_INT32)0;
  if (i3) goto l3;
  *(OOC_INT32*)((_check_pointer(i1, 100067))+40) = (_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 100085)))), &_td_OOC_SymbolTable__VarDeclDesc, 100085));
  goto l4;
l3:
  *(OOC_INT32*)((_check_pointer(i1, 100024))+40) = (OOC_INT32)0;
l4:
  OOC_SymbolTable__ReadType((ADT_Storable__Reader)i0, (void*)((_check_pointer(i1, 100129))+44), (void*)((_check_pointer(i1, 100152))+48));
  *(OOC_INT32*)((_check_pointer(i1, 100187))+52) = (OOC_INT32)0;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 100209)))), IO_BinaryRider__ReaderDesc_ReadBool)),IO_BinaryRider__ReaderDesc_ReadBool)((IO_BinaryRider__Reader)i0, (void*)((_check_pointer(i1, 100231))+56));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 100258)))), IO_BinaryRider__ReaderDesc_ReadBool)),IO_BinaryRider__ReaderDesc_ReadBool)((IO_BinaryRider__Reader)i0, (void*)((_check_pointer(i1, 100280))+57));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 100298)))), IO_BinaryRider__ReaderDesc_ReadSInt)),IO_BinaryRider__ReaderDesc_ReadSInt)((IO_BinaryRider__Reader)i0, (void*)((_check_pointer(i1, 100320))+58));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 100343)))), IO_BinaryRider__ReaderDesc_ReadNum)),IO_BinaryRider__ReaderDesc_ReadNum)((IO_BinaryRider__Reader)i0, (void*)(OOC_INT32)&len);
  i2 = len;
  i3 = i2<0;
  if (i3) goto l15;
  *(OOC_INT32*)((_check_pointer(i1, 100444))+60) = ((OOC_INT32)RT0__NewObject(_td_OOC_SymbolTable__ExceptionNameArray.baseTypes[0], i2));
  i = 0;
  i3 = 0<i2;
  if (!i3) goto l16;
  i3=0;
l9_loop:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 100498)))), ADT_Storable__ReaderDesc_ReadObject)),ADT_Storable__ReaderDesc_ReadObject)((ADT_Storable__Reader)i0, (void*)(OOC_INT32)&obj);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 100536))+60);
  i4 = _check_pointer(i4, 100544);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i6 = (OOC_INT32)obj;
  *(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 100544))*4) = (_type_guard(i6, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 100555)))), &_td_OOC_SymbolTable__ExceptionNameDesc, 100555));
  i3 = i3+1;
  i = i3;
  i4 = i3<i2;
  if (i4) goto l9_loop;
  goto l16;
l15:
  *(OOC_INT32*)((_check_pointer(i1, 100398))+60) = (OOC_INT32)0;
l16:
  *(OOC_INT32*)((_check_pointer(i1, 100603))+64) = (OOC_INT32)0;
  return;
  ;
}

static void OOC_SymbolTable__InitTypeClosure(OOC_SymbolTable__TypeClosure tc, OOC_SymbolTable__Position position, OOC_SymbolTable__Type baseType, OOC_SymbolTable__TypeVarArray params, OOC_SymbolTable__TypeRefArray arguments) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)params;
  i1 = (OOC_INT32)arguments;
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i0, 100864)), 0);
  i3 = OOC_ARRAY_LENGTH((_check_pointer(i1, 100882)), 0);
  _assert((i2==i3), 127, 100847);
  i2 = (OOC_INT32)tc;
  i3 = (OOC_INT32)position;
  OOC_SymbolTable__InitType((OOC_SymbolTable__Type)i2, (OOC_SymbolTable__Item)(OOC_INT32)0, (OOC_SymbolTable__Position)i3);
  i3 = (OOC_INT32)baseType;
  *(OOC_INT32*)((_check_pointer(i2, 100926))+40) = i3;
  *(OOC_INT32*)((_check_pointer(i2, 100955))+44) = i0;
  *(OOC_INT32*)((_check_pointer(i2, 100980))+48) = i1;
  i0 = i3!=(OOC_INT32)0;
  if (i0) goto l3;
  *(OOC_INT32*)((_check_pointer(i2, 101117))+32) = (-1);
  *(OOC_INT16*)((_check_pointer(i2, 101138))+36) = (-1);
  goto l4;
l3:
  i0 = *(OOC_INT32*)((_check_pointer(i3, 101059))+32);
  *(OOC_INT32*)((_check_pointer(i2, 101042))+32) = i0;
  i0 = *(OOC_INT16*)((_check_pointer(i3, 101092))+36);
  *(OOC_INT16*)((_check_pointer(i2, 101074))+36) = i0;
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
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 101595))+40);
  return (OOC_SymbolTable__Type)i0;
  ;
}

OOC_SymbolTable__Type OOC_SymbolTable__TypeClosureDesc_Lookup(OOC_SymbolTable__TypeClosure typeClosure, OOC_SymbolTable__TypeVar tv, OOC_SymbolTable__TypeVar _default) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_INT32 i;

  i0 = (OOC_INT32)typeClosure;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 101886))+44);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 101913))+48);
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 101893)), 0);
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 101923)), 0);
  _assert((i1==i2), 127, 101864);
  i = 0;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 101970))+44);
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 101977)), 0);
  i1 = 0!=i1;
  if (i1) goto l3;
  i1=0u;
  goto l5;
l3:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 101995))+44);
  i1 = _check_pointer(i1, 102002);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT32, 102002))*4);
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
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 101970))+44);
  i3 = OOC_ARRAY_LENGTH((_check_pointer(i3, 101977)), 0);
  i3 = i2!=i3;
  if (i3) goto l11;
  i3=0u;
  goto l13;
l11:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 101995))+44);
  i3 = _check_pointer(i3, 102002);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i2, i4, OOC_UINT32, 102002))*4);
  i3 = i3!=i1;
  
l13:
  if (i3) goto l8_loop;
l16:
  i1=i2;
l17:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 102066))+44);
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 102073)), 0);
  i2 = i1==i2;
  if (i2) goto l20;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 102331))+48);
  i0 = _check_pointer(i0, 102341);
  i2 = OOC_ARRAY_LENGTH(i0, 0);
  i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(i1, i2, OOC_UINT32, 102341))*8);
  return (OOC_SymbolTable__Type)i0;
  goto l21;
l20:
  i0 = (OOC_INT32)_default;
  return (OOC_SymbolTable__Type)i0;
l21:
  _failed_function(101659); return 0;
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
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 102671)))), &_td_OOC_SymbolTable__QualTypeDesc);
  if (i2) goto l19;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 103123)))), &_td_OOC_SymbolTable__TypeVarDesc);
  if (i2) goto l13;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 103336))+28);
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
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 102708))+48);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 102731))+40);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 102740))+28);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 102749))+20);
  i3 = OOC_ARRAY_LENGTH((_check_pointer(i3, 102756)), 0);
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 102718)), 0);
  _assert((i2==i3), 127, 102693);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 102787))+40);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 102796))+28);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 102805))+20);
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 102812)), 0);
  i2 = (OOC_INT32)RT0__NewObject(_td_OOC_SymbolTable__TypeRefArray.baseTypes[0], i2);
  args = (OOC_SymbolTable__TypeRefArray)i2;
  i = 0;
  i3 = OOC_ARRAY_LENGTH((_check_pointer(i2, 102847)), 0);
  i4 = 0<i3;
  if (!i4) goto l27;
  i4 = (OOC_INT32)closure;
  i5=0;
l22_loop:
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 102906))+48);
  i6 = _check_pointer(i6, 102916);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)(i6+(_check_index(i5, i7, OOC_UINT32, 102916))*8);
  i6 = (OOC_INT32)OOC_SymbolTable__TypeClosureDesc_Closure((OOC_SymbolTable__TypeClosure)i4, (OOC_SymbolTable__Type)i6);
  i7 = OOC_ARRAY_LENGTH((_check_pointer(i2, 102881)), 0);
  i7 = _check_index(i5, i7, OOC_UINT32, 102881);
  i7 = _check_pointer(i2, 102881);
  i8 = OOC_ARRAY_LENGTH(i7, 0);
  OOC_SymbolTable__InitTypeRef((void*)(i7+(_check_index(i5, i8, OOC_UINT32, 102881))*8), (RT0__Struct)i1, (OOC_SymbolTable__Type)i6);
  i5 = i5+1;
  i = i5;
  i6 = i5<i3;
  if (i6) goto l22_loop;
l27:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 103033))+40);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 103042))+28);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 103051))+20);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 102979))+20);
  i2 = (OOC_INT32)OOC_SymbolTable__NewTypeClosure((OOC_SymbolTable__Position)i4, (OOC_SymbolTable__Type)(OOC_INT32)0, (OOC_SymbolTable__TypeVarArray)i3, (OOC_SymbolTable__TypeRefArray)i2);
  closure = (OOC_SymbolTable__TypeClosure)i2;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 103091))+40);
  nextType = (OOC_SymbolTable__Type)i0;
l28:
  i0 = (OOC_INT32)nextType;
  type = (OOC_SymbolTable__Type)i0;
  
  goto l4_loop;
l29:
  i1 = (OOC_INT32)closure;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 103645))+48);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 103629))+44);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 103579))+20);
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
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 104163)))), &_td_OOC_SymbolTable__QualTypeDesc);
  if (i1) goto l5;
  i0 = (OOC_INT32)closure;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 104545))+48);
  i0 = OOC_ARRAY_LENGTH((_check_pointer(i0, 104555)), 0);
  return (i0==0);
  goto l36;
l5:
  i1 = (OOC_INT32)closure;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 104210))+44);
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 104217)), 0);
  i = 0;
  i3 = 0<i2;
  if (!i3) goto l33;
  i3=0;
l8_loop:
  j = 0;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 104272))+48);
  i4 = OOC_ARRAY_LENGTH((_check_pointer(i4, 104282)), 0);
  i4 = 0!=i4;
  if (i4) goto l11;
  i4=0u;
  goto l13;
l11:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 104309))+48);
  i4 = _check_pointer(i4, 104319);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 104337))+44);
  i6 = _check_pointer(i6, 104344);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(0, i5, OOC_UINT32, 104319))*8);
  i5 = (OOC_INT32)*(OOC_INT32*)(i6+(_check_index(i3, i7, OOC_UINT32, 104344))*4);
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
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 104272))+48);
  i5 = OOC_ARRAY_LENGTH((_check_pointer(i5, 104282)), 0);
  i5 = i4!=i5;
  if (i5) goto l19;
  i5=0u;
  goto l21;
l19:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 104309))+48);
  i5 = _check_pointer(i5, 104319);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 104337))+44);
  i7 = _check_pointer(i7, 104344);
  i8 = OOC_ARRAY_LENGTH(i7, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 104319))*8);
  i6 = (OOC_INT32)*(OOC_INT32*)(i7+(_check_index(i3, i8, OOC_UINT32, 104344))*4);
  i5 = i5!=i6;
  
l21:
  if (i5) goto l16_loop;
l25:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 104413))+48);
  i5 = OOC_ARRAY_LENGTH((_check_pointer(i5, 104423)), 0);
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
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 104120))+48);
  i0 = OOC_ARRAY_LENGTH((_check_pointer(i0, 104130)), 0);
  return (i0==0);
l36:
  _failed_function(103707); return 0;
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
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 106202))+48);
  return (OOC_SymbolTable__Namespace)i0;
  ;
}

OOC_SymbolTable__Namespace OOC_SymbolTable__ProcDeclDesc_Namespace(OOC_SymbolTable__ProcDecl item) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)item;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 106301))+60);
  return (OOC_SymbolTable__Namespace)i0;
  ;
}

OOC_SymbolTable__Namespace OOC_SymbolTable__FormalParsDesc_Namespace(OOC_SymbolTable__FormalPars item) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)item;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 106402))+64);
  return (OOC_SymbolTable__Namespace)i0;
  ;
}

OOC_SymbolTable__Namespace OOC_SymbolTable__RecordDesc_Namespace(OOC_SymbolTable__Record item) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)item;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 106499))+52);
  return (OOC_SymbolTable__Namespace)i0;
  ;
}

OOC_SymbolTable__Namespace OOC_SymbolTable__TypeParsDesc_Namespace(OOC_SymbolTable__TypePars item) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)item;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 106598))+24);
  return (OOC_SymbolTable__Namespace)i0;
  ;
}

OOC_SymbolTable__Namespace OOC_SymbolTable__QualTypeDesc_Namespace(OOC_SymbolTable__QualType item) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)item;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 106697))+40);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 106697))+40);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 106706)))), OOC_SymbolTable__ItemDesc_Namespace)),OOC_SymbolTable__ItemDesc_Namespace)((OOC_SymbolTable__Item)i0);
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
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 107548)))), &_td_OOC_SymbolTable__ImportDesc);
      if (i1) goto l8;
      i1=0u;
      goto l10;
l8:
      i1 = OOC_SymbolTable__ImportDesc_IsInternalImport((OOC_SymbolTable__Import)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 107567)))), &_td_OOC_SymbolTable__ImportDesc, 107567)));
      i1 = !i1;
      
l10:
      if (!i1) goto l18;
      i1 = (OOC_INT32)prunedImports;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 107624)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i1, (Object__Object)i0);
      goto l18;
l13:
      OOC_SymbolTable__Prune_PruneList((void*)((_check_pointer(i0, 107284))+8), (void*)((_check_pointer(i0, 107303))+12));
      i1 = (OOC_INT32)*last;
      i2 = i1==(OOC_INT32)0;
      if (i2) goto l16;
      *(OOC_INT32*)(_check_pointer(i1, 107456)) = i0;
      goto l17;
l16:
      *list = (OOC_SymbolTable__Item)i0;
l17:
      *last = (OOC_SymbolTable__Item)i0;
l18:
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 107687));
      _this = (OOC_SymbolTable__Item)i0;
      i1 = i0!=(OOC_INT32)0;
      if (i1) goto l3_loop;
l23:
      i0 = (OOC_INT32)*last;
      i1 = i0!=(OOC_INT32)0;
      if (!i1) goto l26;
      *(OOC_INT32*)(_check_pointer(i0, 107771)) = (OOC_INT32)0;
l26:
      return;
      ;
    }


  i0 = (OOC_INT32)ADT_ArrayList__New(8);
  prunedImports = (ADT_ArrayList__ArrayList)i0;
  i0 = (OOC_INT32)root;
  OOC_SymbolTable__Prune_PruneList((void*)((_check_pointer(i0, 107883))+8), (void*)((_check_pointer(i0, 107902))+12));
  i0 = (OOC_INT32)root;
  i1 = (OOC_INT32)prunedImports;
  i2 = *(OOC_INT32*)((_check_pointer(i1, 107963))+4);
  *(OOC_INT32*)((_check_pointer(i0, 107934))+72) = ((OOC_INT32)RT0__NewObject(_td_OOC_SymbolTable__ModuleRefArray.baseTypes[0], i2));
  i = 0;
  i2 = *(OOC_INT32*)((_check_pointer(i1, 108002))+4);
  i3 = 0<i2;
  if (!i3) goto l8;
  i3=0;
l3_loop:
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 108042));
  i4 = _check_pointer(i4, 108048);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 108048))*4);
  i4 = _type_guard(i4, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 108052)))), &_td_OOC_SymbolTable__ImportDesc, 108052);
  import = (OOC_SymbolTable__Import)i4;
  i5 = (OOC_INT32)RT0__NewObject(_td_OOC_SymbolTable__ModuleRef.baseTypes[0]);
  mr = (OOC_SymbolTable__ModuleRef)i5;
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 108099))+48);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i6, 108110))+12);
  *(OOC_INT32*)(_check_pointer(i5, 108084)) = i6;
  i4 = *(OOC_INT32*)((_check_pointer(i4, 108146))+56);
  *(OOC_INT32*)((_check_pointer(i5, 108124))+4) = i4;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 108170))+72);
  i4 = _check_pointer(i4, 108184);
  i6 = OOC_ARRAY_LENGTH(i4, 0);
  *(OOC_INT32*)(i4+(_check_index(i3, i6, OOC_UINT32, 108184))*4) = i5;
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
          i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 108934)))), &_td_OOC_SymbolTable__PointerDesc);
          if (i2) goto l9;
          i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 109019)))), &_td_OOC_SymbolTable__ArrayDesc);
          if (i2) goto l7;
          return 0u;
          goto l12;
l7:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 109062))+48);
          i0 = OOC_SymbolTable__DeclarationDesc_GetId_GetContainer_Contains((OOC_SymbolTable__Item)i0, (OOC_SymbolTable__Item)i1);
          return i0;
          goto l12;
l9:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 108979))+44);
          i0 = OOC_SymbolTable__DeclarationDesc_GetId_GetContainer_Contains((OOC_SymbolTable__Item)i0, (OOC_SymbolTable__Item)i1);
          return i0;
          goto l12;
l11:
          return 1u;
l12:
          _failed_function(108803); return 0;
          ;
        }


      i0 = (OOC_INT32)type;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 109211)))), &_td_OOC_SymbolTable__RecordDesc);
      if (i1) goto l3;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 109231)))), &_td_OOC_SymbolTable__FormalParsDesc);
      
      goto l4;
l3:
      i1=1u;
l4:
      _assert(i1, 127, 109197);
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 109263)))), &_td_OOC_SymbolTable__FormalParsDesc);
      if (i1) goto l7;
      i1=0u;
      goto l9;
l7:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 109285))+4);
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 109294)))), &_td_OOC_SymbolTable__ProcDeclDesc);
      
l9:
      if (i1) goto l15;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 109380))+4);
      ptr = (OOC_SymbolTable__Item)i0;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 109406)))), &_td_OOC_SymbolTable__TypeParsDesc);
      if (!i1) goto l16;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 109444))+4);
      ptr = (OOC_SymbolTable__Item)i0;
      
      goto l16;
l15:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 109331))+4);
      return (OOC_SymbolTable__Declaration)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 109340)))), &_td_OOC_SymbolTable__ProcDeclDesc, 109340));
l16:
      i0 = (OOC_INT32)ptr;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 109496)))), &_td_OOC_SymbolTable__ModuleDesc);
      if (i1) goto l19;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 109529)))), &_td_OOC_SymbolTable__ProcDeclDesc);
      
      goto l21;
l19:
      i1=1u;
l21:
      if (i1) goto l23;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 109564)))), &_td_OOC_SymbolTable__RecordDesc);
      
      goto l25;
l23:
      i1=1u;
l25:
      if (i1) goto l27;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 109597)))), &_td_OOC_SymbolTable__FormalParsDesc);
      
      goto l28;
l27:
      i1=1u;
l28:
      _assert(i1, 127, 109483);
      found = 0u;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 109652))+8);
      ptr = (OOC_SymbolTable__Item)i0;
      i1 = i0!=(OOC_INT32)0;
      if (!i1) goto l55;
l31_loop:
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 109710)))), &_td_OOC_SymbolTable__VarDeclDesc);
      if (i1) goto l46;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 109789)))), &_td_OOC_SymbolTable__TypeDeclDesc);
      if (i1) goto l44;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 109869)))), &_td_OOC_SymbolTable__ProcDeclDesc);
      if (i1) goto l42;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 109948)))), &_td_OOC_SymbolTable__FieldDeclDesc);
      if (i1) goto l40;
      found = 0u;
      i0=0u;
      goto l47;
l40:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 109995))+52);
      i1 = (OOC_INT32)type;
      i0 = OOC_SymbolTable__DeclarationDesc_GetId_GetContainer_Contains((OOC_SymbolTable__Item)i0, (OOC_SymbolTable__Item)i1);
      found = i0;
      
      goto l47;
l42:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 109915))+64);
      i1 = (OOC_INT32)type;
      i0 = OOC_SymbolTable__DeclarationDesc_GetId_GetContainer_Contains((OOC_SymbolTable__Item)i0, (OOC_SymbolTable__Item)i1);
      found = i0;
      
      goto l47;
l44:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 109835))+52);
      i1 = (OOC_INT32)type;
      i0 = OOC_SymbolTable__DeclarationDesc_GetId_GetContainer_Contains((OOC_SymbolTable__Item)i0, (OOC_SymbolTable__Item)i1);
      found = i0;
      
      goto l47;
l46:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 109755))+52);
      i1 = (OOC_INT32)type;
      i0 = OOC_SymbolTable__DeclarationDesc_GetId_GetContainer_Contains((OOC_SymbolTable__Item)i0, (OOC_SymbolTable__Item)i1);
      found = i0;
      
l47:
      i1 = (OOC_INT32)ptr;
      if (!i0) goto l50;
      return (OOC_SymbolTable__Declaration)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 110110)))), &_td_OOC_SymbolTable__DeclarationDesc, 110110));
l50:
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 110154));
      ptr = (OOC_SymbolTable__Item)i0;
      i1 = i0!=(OOC_INT32)0;
      if (i1) goto l31_loop;
l55:
      _assert(0u, 127, 110184);
      _failed_function(108697); return 0;
      ;
    }

    
    OOC_Scanner_InputBuffer__CharArray OOC_SymbolTable__DeclarationDesc_GetId_Concat(OOC_Scanner_InputBuffer__CharArray a, OOC_Scanner_InputBuffer__CharArray b) {
      register OOC_INT32 i0,i1,i2,i3;
      OOC_Scanner_InputBuffer__CharArray n;

      i0 = (OOC_INT32)a;
      i1 = (
      _cmp8((const void*)(_check_pointer(i0, 110325)),(const void*)""))==0;
      if (i1) goto l3;
      i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 110399)), 0);
      i1 = Strings__Length((void*)(_check_pointer(i0, 110399)), i1);
      i2 = (OOC_INT32)b;
      i3 = OOC_ARRAY_LENGTH((_check_pointer(i2, 110419)), 0);
      i3 = Strings__Length((void*)(_check_pointer(i2, 110419)), i3);
      i1 = (OOC_INT32)RT0__NewObject(_td_OOC_Scanner_InputBuffer__CharArray.baseTypes[0], ((i1+i3)+2));
      n = (OOC_Scanner_InputBuffer__CharArray)i1;
      i3 = OOC_ARRAY_LENGTH((_check_pointer(i1, 110445)), 0);
      _copy_8((const void*)(_check_pointer(i0, 110441)),(void*)(_check_pointer(i1, 110445)),i3);
      i0 = OOC_ARRAY_LENGTH((_check_pointer(i1, 110479)), 0);
      Strings__Append(".", 2, (void*)(_check_pointer(i1, 110479)), i0);
      i0 = OOC_ARRAY_LENGTH((_check_pointer(i2, 110508)), 0);
      i3 = OOC_ARRAY_LENGTH((_check_pointer(i1, 110512)), 0);
      Strings__Append((void*)(_check_pointer(i2, 110508)), i0, (void*)(_check_pointer(i1, 110512)), i3);
      return (OOC_Scanner_InputBuffer__CharArray)i1;
      goto l4;
l3:
      i0 = (OOC_INT32)b;
      return (OOC_Scanner_InputBuffer__CharArray)i0;
l4:
      _failed_function(110236); return 0;
      ;
    }


  i0 = (OOC_INT32)decl;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 110582))+40);
  i1 = i1!=(OOC_INT32)0;
  if (i1) goto l44;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 110657)))), &_td_OOC_SymbolTable__ModuleDesc);
  if (i1) goto l42;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 110778)))), &_td_OOC_SymbolTable__ProcDeclDesc);
  if (i1) goto l7;
  i1=0u;
  goto l9;
l7:
  i1 = OOC_SymbolTable__ProcDeclDesc_IsTypeBound((OOC_SymbolTable__ProcDecl)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 110798)))), &_td_OOC_SymbolTable__ProcDeclDesc, 110798)));
  
l9:
  if (i1) goto l40;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 111097)))), &_td_OOC_SymbolTable__FieldDeclDesc);
  if (i1) goto l38;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 111373)))), &_td_OOC_SymbolTable__VarDeclDesc);
  if (i1) goto l15;
  i1=0u;
  goto l17;
l15:
  i1 = *(OOC_UINT8*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 111392)))), &_td_OOC_SymbolTable__VarDeclDesc, 111392)), 111400))+56);
  
l17:
  if (i1) goto l36;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 111682)))), &_td_OOC_SymbolTable__TypeDeclDesc);
  if (i1) goto l21;
  i1=0u;
  goto l23;
l21:
  i1 = OOC_SymbolTable__TypeDeclDesc_IsTypeParameter((OOC_SymbolTable__TypeDecl)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 111702)))), &_td_OOC_SymbolTable__TypeDeclDesc, 111702)));
  
l23:
  if (i1) goto l34;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 112006))+4);
  parent = (OOC_SymbolTable__Item)i1;
  i2 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 112038)))), &_td_OOC_SymbolTable__DeclarationDesc));
  if (!i2) goto l33;
l28_loop:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 112083))+4);
  parent = (OOC_SymbolTable__Item)i1;
  i2 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 112038)))), &_td_OOC_SymbolTable__DeclarationDesc));
  if (i2) goto l28_loop;
l33:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 112160))+20);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 112165))+12);
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 112134)))), &_td_OOC_SymbolTable__DeclarationDesc, 112134)), 112146)))), OOC_SymbolTable__DeclarationDesc_GetId)),OOC_SymbolTable__DeclarationDesc_GetId)((OOC_SymbolTable__Declaration)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 112134)))), &_td_OOC_SymbolTable__DeclarationDesc, 112134)));
  i0 = (OOC_INT32)OOC_SymbolTable__DeclarationDesc_GetId_Concat((OOC_Scanner_InputBuffer__CharArray)i1, (OOC_Scanner_InputBuffer__CharArray)i0);
  id = (OOC_Scanner_InputBuffer__CharArray)i0;
  
  goto l43;
l34:
  i1 = (OOC_INT32)OOC_SymbolTable__TypeDeclDesc_ParametricType((OOC_SymbolTable__TypeDecl)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 111885)))), &_td_OOC_SymbolTable__TypeDeclDesc, 111885)));
  ptr = (OOC_SymbolTable__Item)i1;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 111961))+20);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 111966))+12);
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 111938)))), &_td_OOC_SymbolTable__TypeDeclDesc, 111938)), 111947)))), OOC_SymbolTable__DeclarationDesc_GetId)),OOC_SymbolTable__DeclarationDesc_GetId)((OOC_SymbolTable__Declaration)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 111938)))), &_td_OOC_SymbolTable__TypeDeclDesc, 111938)));
  i0 = (OOC_INT32)OOC_SymbolTable__DeclarationDesc_GetId_Concat((OOC_Scanner_InputBuffer__CharArray)i1, (OOC_Scanner_InputBuffer__CharArray)i0);
  id = (OOC_Scanner_InputBuffer__CharArray)i0;
  
  goto l43;
l36:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 111571)))), &_td_OOC_SymbolTable__VarDeclDesc, 111571)), 111579))+4);
  i0 = (OOC_INT32)OOC_SymbolTable__DeclarationDesc_GetId_GetContainer((OOC_SymbolTable__Type)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 111588)))), &_td_OOC_SymbolTable__FormalParsDesc, 111588)));
  declWithType = (OOC_SymbolTable__Declaration)i0;
  i1 = (OOC_INT32)decl;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 111651))+20);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 111657))+12);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 111636)))), OOC_SymbolTable__DeclarationDesc_GetId)),OOC_SymbolTable__DeclarationDesc_GetId)((OOC_SymbolTable__Declaration)i0);
  i0 = (OOC_INT32)OOC_SymbolTable__DeclarationDesc_GetId_Concat((OOC_Scanner_InputBuffer__CharArray)i0, (OOC_Scanner_InputBuffer__CharArray)i1);
  id = (OOC_Scanner_InputBuffer__CharArray)i0;
  
  goto l43;
l38:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 111264)))), &_td_OOC_SymbolTable__FieldDeclDesc, 111264)), 111274))+4);
  i0 = (OOC_INT32)OOC_SymbolTable__DeclarationDesc_GetId_GetContainer((OOC_SymbolTable__Type)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 111283)))), &_td_OOC_SymbolTable__RecordDesc, 111283)));
  declWithType = (OOC_SymbolTable__Declaration)i0;
  i1 = (OOC_INT32)decl;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 111342))+20);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 111348))+12);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 111327)))), OOC_SymbolTable__DeclarationDesc_GetId)),OOC_SymbolTable__DeclarationDesc_GetId)((OOC_SymbolTable__Declaration)i0);
  i0 = (OOC_INT32)OOC_SymbolTable__DeclarationDesc_GetId_Concat((OOC_Scanner_InputBuffer__CharArray)i0, (OOC_Scanner_InputBuffer__CharArray)i1);
  id = (OOC_Scanner_InputBuffer__CharArray)i0;
  
  goto l43;
l40:
  i0 = (OOC_INT32)OOC_SymbolTable__ProcDeclDesc_Class((OOC_SymbolTable__ProcDecl)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 110996)))), &_td_OOC_SymbolTable__ProcDeclDesc, 110996)));
  i0 = (OOC_INT32)OOC_SymbolTable__DeclarationDesc_GetId_GetContainer((OOC_SymbolTable__Type)i0);
  declWithType = (OOC_SymbolTable__Declaration)i0;
  i1 = (OOC_INT32)decl;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 111066))+20);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 111072))+12);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 111051)))), OOC_SymbolTable__DeclarationDesc_GetId)),OOC_SymbolTable__DeclarationDesc_GetId)((OOC_SymbolTable__Declaration)i0);
  i0 = (OOC_INT32)OOC_SymbolTable__DeclarationDesc_GetId_Concat((OOC_Scanner_InputBuffer__CharArray)i0, (OOC_Scanner_InputBuffer__CharArray)i1);
  id = (OOC_Scanner_InputBuffer__CharArray)i0;
  
  goto l43;
l42:
  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_Scanner_InputBuffer__CharArray.baseTypes[0], 1);
  id = (OOC_Scanner_InputBuffer__CharArray)i0;
  i1 = _check_pointer(i0, 110750);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  *(OOC_UINT8*)(i1+(_check_index(0, i2, OOC_UINT8, 110750))) = 0u;
  
l43:
  i1 = (OOC_INT32)decl;
  *(OOC_INT32*)((_check_pointer(i1, 112193))+40) = i0;
  return (OOC_Scanner_InputBuffer__CharArray)i0;
  goto l45;
l44:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 110622))+40);
  return (OOC_Scanner_InputBuffer__CharArray)i0;
l45:
  _failed_function(108248); return 0;
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
      i0 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 112642)))), &_td_OOC_SymbolTable__TypeNameDesc);
      
l5:
      if (i0) goto l39;
      i0 = (OOC_INT32)type;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 112830)))), &_td_OOC_SymbolTable__PredefTypeDesc);
      if (i1) goto l37;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 112881)))), &_td_OOC_SymbolTable__TypeNameDesc);
      if (i1) goto l35;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 112980)))), &_td_OOC_SymbolTable__PointerDesc);
      if (i1) goto l33;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 113080)))), &_td_OOC_SymbolTable__FormalParsDesc);
      if (i1) goto l31;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 113190)))), &_td_OOC_SymbolTable__ArrayDesc);
      if (i1) goto l29;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 113294)))), &_td_OOC_SymbolTable__RecordDesc);
      if (i1) goto l27;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 113346)))), &_td_OOC_SymbolTable__TypeVarDesc);
      if (i1) goto l25;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 113429)))), &_td_OOC_SymbolTable__QualTypeDesc);
      if (i1) goto l23;
      _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 113423)))), 113423);
      goto l40;
l23:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 113497))+44);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 113481))+40);
      i0 = (OOC_INT32)OOC_SymbolTable__DeclarationDesc_GetEmbeddedNamespace_NamespaceOfType((OOC_SymbolTable__Type)i0, (OOC_SymbolTable__Type)i1);
      return (OOC_SymbolTable__Namespace)i0;
      goto l40;
l25:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 113397))+40);
      i1 = (OOC_INT32)srcType;
      i0 = (OOC_INT32)OOC_SymbolTable__DeclarationDesc_GetEmbeddedNamespace_NamespaceOfType((OOC_SymbolTable__Type)i0, (OOC_SymbolTable__Type)i1);
      return (OOC_SymbolTable__Namespace)i0;
      goto l40;
l27:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 113327))+52);
      return (OOC_SymbolTable__Namespace)i0;
      goto l40;
l29:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 113258))+48);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 113239))+44);
      i0 = (OOC_INT32)OOC_SymbolTable__DeclarationDesc_GetEmbeddedNamespace_NamespaceOfType((OOC_SymbolTable__Type)i0, (OOC_SymbolTable__Type)i1);
      return (OOC_SymbolTable__Namespace)i0;
      goto l40;
l31:
      return (OOC_SymbolTable__Namespace)(OOC_INT32)0;
      goto l40;
l33:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 113047))+44);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 113031))+40);
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
      _failed_function(112545); return 0;
      ;
    }


  i0 = (OOC_INT32)decl;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 113587)))), &_td_OOC_SymbolTable__ModuleDesc);
  if (i1) goto l35;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 113631)))), &_td_OOC_SymbolTable__ImportDesc);
  if (i1) goto l33;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 113691)))), &_td_OOC_SymbolTable__ProcDeclDesc);
  if (i1) goto l31;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 113737)))), &_td_OOC_SymbolTable__ConstDeclDesc);
  if (i1) goto l29;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 113779)))), &_td_OOC_SymbolTable__PredefProcDesc);
  if (i1) goto l27;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 113822)))), &_td_OOC_SymbolTable__VarDeclDesc);
  if (i1) goto l25;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 113906)))), &_td_OOC_SymbolTable__FieldDeclDesc);
  if (i1) goto l23;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 113992)))), &_td_OOC_SymbolTable__TypeDeclDesc);
  if (i1) goto l21;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 114077)))), &_td_OOC_SymbolTable__RedirectDesc);
  if (i1) goto l19;
  _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 114071)))), 114071);
  goto l36;
l19:
  return (OOC_SymbolTable__Namespace)(OOC_INT32)0;
  goto l36;
l21:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 114052))+52);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 114040))+48);
  i0 = (OOC_INT32)OOC_SymbolTable__DeclarationDesc_GetEmbeddedNamespace_NamespaceOfType((OOC_SymbolTable__Type)i0, (OOC_SymbolTable__Type)i1);
  return (OOC_SymbolTable__Namespace)i0;
  goto l36;
l23:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 113967))+52);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 113955))+48);
  i0 = (OOC_INT32)OOC_SymbolTable__DeclarationDesc_GetEmbeddedNamespace_NamespaceOfType((OOC_SymbolTable__Type)i0, (OOC_SymbolTable__Type)i1);
  return (OOC_SymbolTable__Namespace)i0;
  goto l36;
l25:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 113881))+52);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 113869))+48);
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
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 113722))+60);
  return (OOC_SymbolTable__Namespace)i0;
  goto l36;
l33:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 113660))+52);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 113676))+48);
  return (OOC_SymbolTable__Namespace)i0;
  goto l36;
l35:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 113616))+48);
  return (OOC_SymbolTable__Namespace)i0;
l36:
  _failed_function(112279); return 0;
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
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 114643)), 0);
  _copy_8((const void*)"",(void*)(_check_pointer(i0, 114643)),i1);
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

void OOC_OOC_SymbolTable_destroy(void) {
}

/* --- */
