#include <OOC/Doc.d>
#include <__oo2c.h>
#include <setjmp.h>

void OOC_Doc__SetPosition(struct OOC_Doc__Position *pos, RT0__Struct pos__tag, OOC_INT32 _char, OOC_INT32 line, OOC_INT32 column) {
  register OOC_INT32 i0;

  i0 = _char;
  *(OOC_INT32*)(OOC_INT32)pos = i0;
  i0 = line;
  *(OOC_INT32*)((OOC_INT32)pos+4) = i0;
  i0 = column;
  *(OOC_INT32*)((OOC_INT32)pos+8) = i0;
  return;
  ;
}

static void OOC_Doc__InitElement(OOC_Doc__Element e) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)e;
  *(OOC_INT32*)(_check_pointer(i0, 6771)) = (-1);
  *(OOC_INT32*)((_check_pointer(i0, 6795))+4) = (-1);
  *(OOC_INT32*)((_check_pointer(i0, 6819))+8) = (-1);
  return;
  ;
}

void OOC_Doc__ElementDesc_NodeName(OOC_Doc__Element e, OOC_CHAR8 name[], OOC_LEN name_0d) {

  return;
  ;
}

void OOC_Doc__ElementDesc_Normalize(OOC_Doc__Element e) {

  return;
  ;
}

void OOC_Doc__ElementDesc_Store(OOC_Doc__Element e, ADT_Storable__Writer w) {

  return;
  ;
}

void OOC_Doc__ElementDesc_Load(OOC_Doc__Element e, ADT_Storable__Reader r) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)e;
  OOC_Doc__InitElement((OOC_Doc__Element)i0);
  return;
  ;
}

void OOC_Doc__MergeInline(OOC_Doc__InlineElement *dest, OOC_Doc__InlineElement src) {
  register OOC_INT32 i0,i1;
  OOC_Doc__InlineElement i;

  i0 = (OOC_INT32)*dest;
  i1 = i0==(OOC_INT32)0;
  if (i1) goto l12;
  i = (OOC_Doc__InlineElement)i0;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7531))+12);
  i1 = i1!=(OOC_INT32)0;
  if (!i1) goto l11;
l6_loop:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7568))+12);
  i = (OOC_Doc__InlineElement)i0;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7531))+12);
  i1 = i1!=(OOC_INT32)0;
  if (i1) goto l6_loop;
l11:
  i1 = (OOC_INT32)src;
  *(OOC_INT32*)((_check_pointer(i0, 7599))+12) = i1;
  goto l13;
l12:
  i0 = (OOC_INT32)src;
  *dest = (OOC_Doc__InlineElement)i0;
l13:
  return;
  ;
}

static void OOC_Doc__InitInlineElement(OOC_Doc__InlineElement e) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)e;
  OOC_Doc__InitElement((OOC_Doc__Element)i0);
  *(OOC_INT32*)((_check_pointer(i0, 7729))+12) = (OOC_INT32)0;
  return;
  ;
}

void OOC_Doc__InlineElementDesc_StripHeadWS(OOC_Doc__InlineElement e) {

  return;
  ;
}

void OOC_Doc__InlineElementDesc_StripTailWS(OOC_Doc__InlineElement e) {

  return;
  ;
}

void OOC_Doc__InlineElementDesc_Store(OOC_Doc__InlineElement e, ADT_Storable__Writer w) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)e;
  OOC_Doc__ElementDesc_Store((OOC_Doc__Element)i1, (ADT_Storable__Writer)i0);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 8021))+12);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8005)))), ADT_Storable__WriterDesc_WriteObject)),ADT_Storable__WriterDesc_WriteObject)((ADT_Storable__Writer)i0, (Object__Object)i1);
  return;
  ;
}

void OOC_Doc__InlineElementDesc_Load(OOC_Doc__InlineElement e, ADT_Storable__Reader r) {
  register OOC_INT32 i0,i1,i2;
  Object__Object obj;

  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)e;
  OOC_Doc__ElementDesc_Load((OOC_Doc__Element)i1, (ADT_Storable__Reader)i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8183)))), ADT_Storable__ReaderDesc_ReadObject)),ADT_Storable__ReaderDesc_ReadObject)((ADT_Storable__Reader)i0, (void*)(OOC_INT32)&obj);
  i0 = (OOC_INT32)obj;
  i2 = i0==(OOC_INT32)0;
  if (i2) goto l3;
  *(OOC_INT32*)((_check_pointer(i1, 8270))+12) = (_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8290)))), &_td_OOC_Doc__InlineElementDesc, 8290));
  goto l4;
l3:
  *(OOC_INT32*)((_check_pointer(i1, 8234))+12) = (OOC_INT32)0;
l4:
  return;
  ;
}

static void OOC_Doc__InitBlockElement(OOC_Doc__BlockElement e, OOC_CHAR8 padAfter) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)e;
  OOC_Doc__InitElement((OOC_Doc__Element)i0);
  *(OOC_INT32*)((_check_pointer(i0, 8427))+12) = (OOC_INT32)0;
  i1 = padAfter;
  *(OOC_UINT8*)((_check_pointer(i0, 8452))+16) = i1;
  return;
  ;
}

void OOC_Doc__BlockElementDesc_Store(OOC_Doc__BlockElement e, ADT_Storable__Writer w) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)e;
  OOC_Doc__ElementDesc_Store((OOC_Doc__Element)i1, (ADT_Storable__Writer)i0);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 8621))+12);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8605)))), ADT_Storable__WriterDesc_WriteObject)),ADT_Storable__WriterDesc_WriteObject)((ADT_Storable__Writer)i0, (Object__Object)i2);
  i1 = *(OOC_UINT8*)((_check_pointer(i1, 8654))+16);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8640)))), IO_BinaryRider__WriterDesc_WriteBool)),IO_BinaryRider__WriterDesc_WriteBool)((IO_BinaryRider__Writer)i0, i1);
  return;
  ;
}

void OOC_Doc__BlockElementDesc_Load(OOC_Doc__BlockElement e, ADT_Storable__Reader r) {
  register OOC_INT32 i0,i1,i2,i3;
  Object__Object obj;

  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)e;
  OOC_Doc__ElementDesc_Load((OOC_Doc__Element)i1, (ADT_Storable__Reader)i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8813)))), ADT_Storable__ReaderDesc_ReadObject)),ADT_Storable__ReaderDesc_ReadObject)((ADT_Storable__Reader)i0, (void*)(OOC_INT32)&obj);
  i2 = (OOC_INT32)obj;
  i3 = i2==(OOC_INT32)0;
  if (i3) goto l3;
  *(OOC_INT32*)((_check_pointer(i1, 8899))+12) = (_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 8918)))), &_td_OOC_Doc__BlockElementDesc, 8918));
  goto l4;
l3:
  *(OOC_INT32*)((_check_pointer(i1, 8864))+12) = (OOC_INT32)0;
l4:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8946)))), IO_BinaryRider__ReaderDesc_ReadBool)),IO_BinaryRider__ReaderDesc_ReadBool)((IO_BinaryRider__Reader)i0, (void*)((_check_pointer(i1, 8959))+16));
  return;
  ;
}

static void OOC_Doc__NormalizeBlockList(OOC_Doc__BlockElement blockList) {
  register OOC_INT32 i0,i1;
  OOC_Doc__BlockElement block;

  i0 = (OOC_INT32)blockList;
  block = (OOC_Doc__BlockElement)i0;
  i1 = i0!=(OOC_INT32)0;
  if (!i1) goto l8;
  
l3_loop:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9265)))), OOC_Doc__ElementDesc_Normalize)),OOC_Doc__ElementDesc_Normalize)((OOC_Doc__Element)i0);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9298))+12);
  block = (OOC_Doc__BlockElement)i0;
  i1 = i0!=(OOC_INT32)0;
  if (i1) goto l3_loop;
l8:
  return;
  ;
}

static void OOC_Doc__NoPadLastElement(OOC_Doc__BlockElement list) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)list;
  i1 = i0!=(OOC_INT32)0;
  if (!i1) goto l12;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9444))+12);
  i1 = i1!=(OOC_INT32)0;
  if (!i1) goto l11;
l6_loop:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9486))+12);
  list = (OOC_Doc__BlockElement)i0;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9444))+12);
  i1 = i1!=(OOC_INT32)0;
  if (i1) goto l6_loop;
l11:
  *(OOC_UINT8*)((_check_pointer(i0, 9519))+16) = 0u;
l12:
  return;
  ;
}

OOC_Doc__InlineList OOC_Doc__NewInlineList(void) {
  register OOC_INT32 i0;
  OOC_Doc__InlineList il;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_Doc__InlineList.baseTypes[0]);
  il = (OOC_Doc__InlineList)i0;
  *(OOC_INT32*)(_check_pointer(i0, 9671)) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 9692))+4) = 0;
  return (OOC_Doc__InlineList)i0;
  ;
}

void OOC_Doc__InlineListDesc_Append(OOC_Doc__InlineList il, OOC_Doc__InlineElement inlineElement) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)inlineElement;
  *(OOC_INT32*)((_check_pointer(i0, 9835))+12) = (OOC_INT32)0;
  i1 = (OOC_INT32)il;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 9866));
  i2 = i2==(OOC_INT32)0;
  if (i2) goto l3;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 9934))+4);
  *(OOC_INT32*)((_check_pointer(i2, 9940))+12) = i0;
  goto l4;
l3:
  *(OOC_INT32*)(_check_pointer(i1, 9893)) = i0;
l4:
  *(OOC_INT32*)((_check_pointer(i1, 9985))+4) = i0;
  return;
  ;
}

OOC_Doc__BlockList OOC_Doc__NewBlockList(void) {
  register OOC_INT32 i0;
  OOC_Doc__BlockList bl;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_Doc__BlockList.baseTypes[0]);
  bl = (OOC_Doc__BlockList)i0;
  *(OOC_INT32*)(_check_pointer(i0, 10116)) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 10137))+4) = 0;
  return (OOC_Doc__BlockList)i0;
  ;
}

void OOC_Doc__BlockListDesc_Append(OOC_Doc__BlockList bl, OOC_Doc__BlockElement inlineElement) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)inlineElement;
  *(OOC_INT32*)((_check_pointer(i0, 10277))+12) = (OOC_INT32)0;
  i1 = (OOC_INT32)bl;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 10307));
  i2 = i2==(OOC_INT32)0;
  if (i2) goto l3;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 10375))+4);
  *(OOC_INT32*)((_check_pointer(i2, 10381))+12) = i0;
  goto l4;
l3:
  *(OOC_INT32*)(_check_pointer(i1, 10334)) = i0;
l4:
  *(OOC_INT32*)((_check_pointer(i1, 10425))+4) = i0;
  return;
  ;
}

static void OOC_Doc__NormalizeInlineList(OOC_Doc__InlineElement *blockList) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_Doc__InlineElement prev;
  OOC_Doc__InlineElement i;

  prev = (OOC_Doc__InlineElement)(OOC_INT32)0;
  i0 = (OOC_INT32)*blockList;
  i = (OOC_Doc__InlineElement)i0;
  i1 = i0!=(OOC_INT32)0;
  if (!i1) goto l19;
  i1=(OOC_INT32)0;i2=1u;
l3_loop:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10636)))), OOC_Doc__ElementDesc_Normalize)),OOC_Doc__ElementDesc_Normalize)((OOC_Doc__Element)i0);
  i3 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10661)))), &_td_OOC_Doc__TextDesc);
  if (i3) goto l6;
  i3=0u;
  goto l8;
l6:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10675)))), &_td_OOC_Doc__TextDesc, 10675)), 10680))+16);
  i3 = (
  _cmp8((const void*)(_check_pointer(i3, 10688)),(const void*)(OOC_CHAR8*)""))==0;
  
l8:
  if (i3) goto l10;
  prev = (OOC_Doc__InlineElement)i0;
  i1 = i0==(OOC_INT32)0;
  i2=i1;i1=i0;
  goto l14;
l10:
  if (i2) goto l12;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11018))+12);
  *(OOC_INT32*)((_check_pointer(i1, 11001))+12) = i3;
  goto l14;
l12:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10961))+12);
  *blockList = (OOC_Doc__InlineElement)i3;
l14:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11095))+12);
  i = (OOC_Doc__InlineElement)i0;
  i3 = i0!=(OOC_INT32)0;
  if (i3) goto l3_loop;
l19:
  return;
  ;
}

static OOC_Doc__InlineElement OOC_Doc__LastInlineElement(OOC_Doc__InlineElement inlineList) {
  register OOC_INT32 i0,i1;
  OOC_Doc__InlineElement last;

  i0 = (OOC_INT32)inlineList;
  last = (OOC_Doc__InlineElement)i0;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11294))+12);
  i1 = i1!=(OOC_INT32)0;
  if (!i1) goto l9;
l4_loop:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11335))+12);
  last = (OOC_Doc__InlineElement)i0;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11294))+12);
  i1 = i1!=(OOC_INT32)0;
  if (i1) goto l4_loop;
l9:
  return (OOC_Doc__InlineElement)i0;
  ;
}

static OOC_Doc__BlockElement OOC_Doc__LastBlockElement(OOC_Doc__BlockElement blockList) {
  register OOC_INT32 i0,i1;
  OOC_Doc__BlockElement last;

  i0 = (OOC_INT32)blockList;
  last = (OOC_Doc__BlockElement)i0;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11543))+12);
  i1 = i1!=(OOC_INT32)0;
  if (!i1) goto l9;
l4_loop:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11583))+12);
  last = (OOC_Doc__BlockElement)i0;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11543))+12);
  i1 = i1!=(OOC_INT32)0;
  if (i1) goto l4_loop;
l9:
  return (OOC_Doc__BlockElement)i0;
  ;
}

static void OOC_Doc__NormalizeArg(OOC_Doc__InlineElement inlineText) {
  register OOC_INT32 i0,i1;
  OOC_Doc__InlineElement last;

  i0 = (OOC_INT32)inlineText;
  i1 = i0!=(OOC_INT32)0;
  if (!i1) goto l4;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11783)))), OOC_Doc__InlineElementDesc_StripHeadWS)),OOC_Doc__InlineElementDesc_StripHeadWS)((OOC_Doc__InlineElement)i0);
  i0 = (OOC_INT32)inlineText;
  i0 = (OOC_INT32)OOC_Doc__LastInlineElement((OOC_Doc__InlineElement)i0);
  last = (OOC_Doc__InlineElement)i0;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11854)))), OOC_Doc__InlineElementDesc_StripTailWS)),OOC_Doc__InlineElementDesc_StripTailWS)((OOC_Doc__InlineElement)i0);
  OOC_Doc__NormalizeInlineList((void*)(OOC_INT32)&inlineText);
l4:
  return;
  ;
}

static void OOC_Doc__StripInlineListWS(OOC_Doc__InlineElement inlineList) {
  register OOC_INT32 i0,i1;
  OOC_Doc__InlineElement last;

  i0 = (OOC_INT32)inlineList;
  i1 = i0!=(OOC_INT32)0;
  if (!i1) goto l4;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12080)))), OOC_Doc__InlineElementDesc_StripHeadWS)),OOC_Doc__InlineElementDesc_StripHeadWS)((OOC_Doc__InlineElement)i0);
  i0 = (OOC_INT32)OOC_Doc__LastInlineElement((OOC_Doc__InlineElement)i0);
  last = (OOC_Doc__InlineElement)i0;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12151)))), OOC_Doc__InlineElementDesc_StripTailWS)),OOC_Doc__InlineElementDesc_StripTailWS)((OOC_Doc__InlineElement)i0);
l4:
  return;
  ;
}

static void OOC_Doc__InitGlyph(OOC_Doc__Glyph glyph, OOC_INT32 glyphCode) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)glyph;
  OOC_Doc__InitInlineElement((OOC_Doc__InlineElement)i0);
  i1 = glyphCode;
  *(OOC_INT32*)((_check_pointer(i0, 12383))+16) = i1;
  return;
  ;
}

OOC_Doc__Glyph OOC_Doc__NewGlyph(OOC_INT32 glyphCode) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_Doc__Glyph.baseTypes[0]);
  i1 = glyphCode;
  OOC_Doc__InitGlyph((OOC_Doc__Glyph)i0, i1);
  return (OOC_Doc__Glyph)i0;
  ;
}

void OOC_Doc__GlyphDesc_NodeName(OOC_Doc__Glyph glyph, OOC_CHAR8 name[], OOC_LEN name_0d) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)glyph;
  i0 = *(OOC_INT32*)((_check_pointer(i0, 12671))+16);
  switch (i0) {
  case 0:
    _copy_8((const void*)(OOC_CHAR8*)"bullet",(void*)(OOC_INT32)name,name_0d);
    goto l10;
  case 1:
    _copy_8((const void*)(OOC_CHAR8*)"dots",(void*)(OOC_INT32)name,name_0d);
    goto l10;
  case 2:
    _copy_8((const void*)(OOC_CHAR8*)"minus",(void*)(OOC_INT32)name,name_0d);
    goto l10;
  case 3:
    _copy_8((const void*)(OOC_CHAR8*)"em-dash",(void*)(OOC_INT32)name,name_0d);
    goto l10;
  case 4:
    _copy_8((const void*)(OOC_CHAR8*)"result",(void*)(OOC_INT32)name,name_0d);
    goto l10;
  case 5:
    _copy_8((const void*)(OOC_CHAR8*)"left-quote",(void*)(OOC_INT32)name,name_0d);
    goto l10;
  case 6:
    _copy_8((const void*)(OOC_CHAR8*)"right-quote",(void*)(OOC_INT32)name,name_0d);
    goto l10;
  default:
    _failed_case(i0, 12661);
    goto l10;
  }
l10:
  return;
  ;
}

void OOC_Doc__GlyphDesc_Normalize(OOC_Doc__Glyph glyph) {

  return;
  ;
}

void OOC_Doc__GlyphDesc_Store(OOC_Doc__Glyph glyph, ADT_Storable__Writer w) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)glyph;
  OOC_Doc__InlineElementDesc_Store((OOC_Doc__InlineElement)i1, (ADT_Storable__Writer)i0);
  i1 = *(OOC_INT32*)((_check_pointer(i1, 13180))+16);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13163)))), IO_BinaryRider__WriterDesc_WriteNum)),IO_BinaryRider__WriterDesc_WriteNum)((IO_BinaryRider__Writer)i0, i1);
  return;
  ;
}

void OOC_Doc__GlyphDesc_Load(OOC_Doc__Glyph glyph, ADT_Storable__Reader r) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)glyph;
  OOC_Doc__InlineElementDesc_Load((OOC_Doc__InlineElement)i1, (ADT_Storable__Reader)i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13306)))), IO_BinaryRider__ReaderDesc_ReadNum)),IO_BinaryRider__ReaderDesc_ReadNum)((IO_BinaryRider__Reader)i0, (void*)((_check_pointer(i1, 13322))+16));
  return;
  ;
}

static void OOC_Doc__InitText(OOC_Doc__Text text, struct OOC_Doc__Position *pos, RT0__Struct pos__tag, OOC_CHAR8 string[], OOC_LEN string_0d) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)text;
  OOC_Doc__InitInlineElement((OOC_Doc__InlineElement)i0);
  _copy_block((OOC_INT32)pos,(_check_pointer(i0, 13469)),12);
  i1 = Strings__Length((void*)(OOC_INT32)string, string_0d);
  *(OOC_INT32*)((_check_pointer(i0, 13496))+16) = ((OOC_INT32)RT0__NewObject(_td_OOC_Scanner_InputBuffer__CharArray.baseTypes[0], (i1+1)));
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13556))+16);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13556))+16);
  i0 = OOC_ARRAY_LENGTH((_check_pointer(i0, 13564)), 0);
  _copy_8((const void*)(OOC_INT32)string,(void*)(_check_pointer(i1, 13564)),i0);
  return;
  ;
}

OOC_Doc__Text OOC_Doc__NewText(OOC_CHAR8 string[], OOC_LEN string_0d, struct OOC_Doc__Position *pos, RT0__Struct pos__tag) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_Doc__Text.baseTypes[0]);
  OOC_Doc__InitText((OOC_Doc__Text)i0, (void*)(OOC_INT32)pos, (RT0__Struct)((OOC_INT32)pos__tag), (void*)(OOC_INT32)string, string_0d);
  return (OOC_Doc__Text)i0;
  ;
}

void OOC_Doc__TextDesc_NodeName(OOC_Doc__Text text, OOC_CHAR8 name[], OOC_LEN name_0d) {

  _copy_8((const void*)(OOC_CHAR8*)"text",(void*)(OOC_INT32)name,name_0d);
  return;
  ;
}

void OOC_Doc__TextDesc_Normalize(OOC_Doc__Text text) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8;
  OOC_Scanner_InputBuffer__CharArray s;
  OOC_INT32 i;
  OOC_INT32 delta;
  OOC_INT32 dotExt;
  OOC_Scanner_InputBuffer__CharArray ns;

  i0 = (OOC_INT32)text;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14160))+16);
  s = (OOC_Scanner_InputBuffer__CharArray)i1;
  i = 0;
  delta = 0;
  dotExt = 0;
  i2 = _check_pointer(i1, 14215);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i2 = *(OOC_UINT8*)(i2+(_check_index(0, i3, OOC_UINT32, 14215)));
  i2 = i2!=0u;
  if (i2) goto l3;
  i2=0;i3=0;i4=0;
  goto l54;
l3:
  i2=0;i3=0;i4=0;
l4_loop:
  i5 = _check_pointer(i1, 14239);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = *(OOC_UINT8*)(i5+(_check_index(i2, i6, OOC_UINT32, 14239)));
  i5 = (OOC_UINT8)i5<=(OOC_UINT8)32u;
  if (i5) goto l31;
  i5 = _check_pointer(i1, 14394);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = *(OOC_UINT8*)(i5+(_check_index(i2, i6, OOC_UINT32, 14394)));
  i5 = i5==46u;
  if (i5) goto l9;
  i5 = _check_pointer(i1, 14889);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i7 = _check_pointer(i1, 14903);
  i8 = OOC_ARRAY_LENGTH(i7, 0);
  i7 = *(OOC_UINT8*)(i7+(_check_index(i2, i8, OOC_UINT32, 14903)));
  *(OOC_UINT8*)(i5+(_check_index((i2-i3), i6, OOC_UINT32, 14889))) = i7;
  i2 = i2+1;
  i = i2;
  
  goto l49;
l9:
  i5 = _check_pointer(i1, 14419);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i7 = _check_pointer(i1, 14433);
  i8 = OOC_ARRAY_LENGTH(i7, 0);
  i7 = *(OOC_UINT8*)(i7+(_check_index(i2, i8, OOC_UINT32, 14433)));
  *(OOC_UINT8*)(i5+(_check_index((i2-i3), i6, OOC_UINT32, 14419))) = i7;
  i2 = i2+1;
  i = i2;
  i5 = _check_pointer(i1, 14460);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = *(OOC_UINT8*)(i5+(_check_index(i2, i6, OOC_UINT32, 14460)));
  i5 = i5!=0u;
  if (i5) goto l12;
  i5=0u;
  goto l14;
l12:
  i5 = _check_pointer(i1, 14474);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = *(OOC_UINT8*)(i5+(_check_index(i2, i6, OOC_UINT32, 14474)));
  i5 = (OOC_UINT8)i5<=(OOC_UINT8)32u;
  
l14:
  if (i5) goto l16;
  i5=0u;
  goto l18;
l16:
  i5 = _check_pointer(i1, 14502);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = *(OOC_UINT8*)(i5+(_check_index((i2+1), i6, OOC_UINT32, 14502)));
  i5 = i5!=0u;
  
l18:
  if (i5) goto l20;
  i5=0u;
  goto l22;
l20:
  i5 = _check_pointer(i1, 14518);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = *(OOC_UINT8*)(i5+(_check_index((i2+1), i6, OOC_UINT32, 14518)));
  i5 = (OOC_UINT8)i5<=(OOC_UINT8)32u;
  
l22:
  if (i5) goto l28;
  i5 = _check_pointer(i1, 14612);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = *(OOC_UINT8*)(i5+(_check_index(i2, i6, OOC_UINT32, 14612)));
  i5 = i5==10u;
  if (!i5) goto l49;
  i5 = _check_pointer(i1, 14818);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  *(OOC_UINT8*)(i5+(_check_index((i2-i3), i6, OOC_UINT32, 14818))) = 1u;
  i2 = i2+1;
  i = i2;
  i4 = i4+1;
  dotExt = i4;
  
  goto l49;
l28:
  i5 = _check_pointer(i1, 14548);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  *(OOC_UINT8*)(i5+(_check_index((i2-i3), i6, OOC_UINT32, 14548))) = 32u;
  i2 = i2+1;
  i = i2;
  
  goto l49;
l31:
  i5 = _check_pointer(i1, 14265);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  *(OOC_UINT8*)(i5+(_check_index((i2-i3), i6, OOC_UINT32, 14265))) = 32u;
  i2 = i2+1;
  i = i2;
  i5 = _check_pointer(i1, 14308);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = *(OOC_UINT8*)(i5+(_check_index(i2, i6, OOC_UINT32, 14308)));
  i5 = i5!=0u;
  if (i5) goto l34;
  i5=0u;
  goto l36;
l34:
  i5 = _check_pointer(i1, 14322);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = *(OOC_UINT8*)(i5+(_check_index(i2, i6, OOC_UINT32, 14322)));
  i5 = (OOC_UINT8)i5<=(OOC_UINT8)32u;
  
l36:
  if (!i5) goto l49;
l39_loop:
  i2 = i2+1;
  i = i2;
  i3 = i3+1;
  delta = i3;
  i5 = _check_pointer(i1, 14308);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = *(OOC_UINT8*)(i5+(_check_index(i2, i6, OOC_UINT32, 14308)));
  i5 = i5!=0u;
  if (i5) goto l42;
  i5=0u;
  goto l44;
l42:
  i5 = _check_pointer(i1, 14322);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = *(OOC_UINT8*)(i5+(_check_index(i2, i6, OOC_UINT32, 14322)));
  i5 = (OOC_UINT8)i5<=(OOC_UINT8)32u;
  
l44:
  if (i5) goto l39_loop;
l49:
  i5 = _check_pointer(i1, 14215);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = *(OOC_UINT8*)(i5+(_check_index(i2, i6, OOC_UINT32, 14215)));
  i5 = i5!=0u;
  if (i5) goto l4_loop;
l54:
  i5 = _check_pointer(i1, 14940);
  i2 = i2-i3;
  i3 = OOC_ARRAY_LENGTH(i5, 0);
  *(OOC_UINT8*)(i5+(_check_index(i2, i3, OOC_UINT32, 14940))) = 0u;
  i = i2;
  i3 = i2+i4;
  i5 = OOC_ARRAY_LENGTH((_check_pointer(i1, 15004)), 0);
  i5 = i3>=i5;
  if (i5) goto l57;
  ns = (OOC_Scanner_InputBuffer__CharArray)i1;
  i0=i1;
  goto l58;
l57:
  i3 = (OOC_INT32)RT0__NewObject(_td_OOC_Scanner_InputBuffer__CharArray.baseTypes[0], (i3+1));
  ns = (OOC_Scanner_InputBuffer__CharArray)i3;
  *(OOC_INT32*)((_check_pointer(i0, 15051))+16) = i3;
  i0=i3;
l58:
  i3 = i2>=0;
  if (!i3) goto l70;
  i3=i4;
l61_loop:
  i4 = _check_pointer(i1, 15131);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = *(OOC_UINT8*)(i4+(_check_index(i2, i5, OOC_UINT32, 15131)));
  i4 = i4==1u;
  if (i4) goto l64;
  i4 = _check_pointer(i0, 15263);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i6 = _check_pointer(i1, 15278);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = *(OOC_UINT8*)(i6+(_check_index(i2, i7, OOC_UINT32, 15278)));
  *(OOC_UINT8*)(i4+(_check_index((i2+i3), i5, OOC_UINT32, 15263))) = i6;
  i2 = i2-1;
  i = i2;
  
  goto l65;
l64:
  i4 = _check_pointer(i0, 15156);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  *(OOC_UINT8*)(i4+(_check_index((i2+i3), i5, OOC_UINT32, 15156))) = 32u;
  i3 = i3-1;
  dotExt = i3;
  i4 = _check_pointer(i0, 15207);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  *(OOC_UINT8*)(i4+(_check_index((i2+i3), i5, OOC_UINT32, 15207))) = 32u;
  i2 = i2-1;
  i = i2;
  
l65:
  i4 = i2>=0;
  if (i4) goto l61_loop;
l70:
  return;
  ;
}

void OOC_Doc__TextDesc_StripHeadWS(OOC_Doc__Text text) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_INT32 i;

  i = 0;
  i0 = (OOC_INT32)text;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15428))+16);
  i1 = _check_pointer(i1, 15436);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i1 = *(OOC_UINT8*)(i1+(_check_index(0, i2, OOC_UINT32, 15436)));
  i1 = i1!=0u;
  if (i1) goto l3;
  i1=0u;
  goto l5;
l3:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15453))+16);
  i1 = _check_pointer(i1, 15461);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i1 = *(OOC_UINT8*)(i1+(_check_index(0, i2, OOC_UINT32, 15461)));
  i1 = (OOC_UINT8)i1<=(OOC_UINT8)32u;
  
l5:
  if (i1) goto l7;
  i1=0;
  goto l17;
l7:
  i1=0;
l8_loop:
  i1 = i1+1;
  i = i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15428))+16);
  i2 = _check_pointer(i2, 15436);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i2 = *(OOC_UINT8*)(i2+(_check_index(i1, i3, OOC_UINT32, 15436)));
  i2 = i2!=0u;
  if (i2) goto l11;
  i2=0u;
  goto l13;
l11:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15453))+16);
  i2 = _check_pointer(i2, 15461);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i2 = *(OOC_UINT8*)(i2+(_check_index(i1, i3, OOC_UINT32, 15461)));
  i2 = (OOC_UINT8)i2<=(OOC_UINT8)32u;
  
l13:
  if (i2) goto l8_loop;
l17:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15523))+16);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15523))+16);
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 15531)), 0);
  Strings__Delete((void*)(_check_pointer(i0, 15531)), i2, 0, i1);
  return;
  ;
}

void OOC_Doc__TextDesc_StripTailWS(OOC_Doc__Text text) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_INT32 i;

  i0 = (OOC_INT32)text;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15663))+16);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15663))+16);
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 15671)), 0);
  i1 = Strings__Length((void*)(_check_pointer(i2, 15671)), i1);
  i = i1;
  i2 = i1!=0;
  if (i2) goto l3;
  i2=0u;
  goto l5;
l3:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15700))+16);
  i2 = _check_pointer(i2, 15708);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i2 = *(OOC_UINT8*)(i2+(_check_index((i1-1), i3, OOC_UINT32, 15708)));
  i2 = (OOC_UINT8)i2<=(OOC_UINT8)32u;
  
l5:
  if (!i2) goto l17;
l8_loop:
  i1 = i1-1;
  i = i1;
  i2 = i1!=0;
  if (i2) goto l11;
  i2=0u;
  goto l13;
l11:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15700))+16);
  i2 = _check_pointer(i2, 15708);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i2 = *(OOC_UINT8*)(i2+(_check_index((i1-1), i3, OOC_UINT32, 15708)));
  i2 = (OOC_UINT8)i2<=(OOC_UINT8)32u;
  
l13:
  if (i2) goto l8_loop;
l17:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15756))+16);
  i0 = _check_pointer(i0, 15764);
  i2 = OOC_ARRAY_LENGTH(i0, 0);
  *(OOC_UINT8*)(i0+(_check_index(i1, i2, OOC_UINT32, 15764))) = 0u;
  return;
  ;
}

void OOC_Doc__TextDesc_Store(OOC_Doc__Text text, ADT_Storable__Writer w) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_INT32 i;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)text;
  OOC_Doc__InlineElementDesc_Store((OOC_Doc__InlineElement)i1, (ADT_Storable__Writer)i0);
  i = 0;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 15941))+16);
  i2 = _check_pointer(i2, 15949);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i2 = *(OOC_UINT8*)(i2+(_check_index(0, i3, OOC_UINT32, 15949)));
  i2 = i2!=0u;
  if (i2) goto l3;
  i2=0;
  goto l9;
l3:
  i2=0;
l4_loop:
  i2 = i2+1;
  i = i2;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 15941))+16);
  i3 = _check_pointer(i3, 15949);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i3 = *(OOC_UINT8*)(i3+(_check_index(i2, i4, OOC_UINT32, 15949)));
  i3 = i3!=0u;
  if (i3) goto l4_loop;
l9:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 15990)))), IO_BinaryRider__WriterDesc_WriteNum)),IO_BinaryRider__WriterDesc_WriteNum)((IO_BinaryRider__Writer)i0, i2);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 16030))+16);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 16030))+16);
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 16038)), 0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 16011)))), IO_BinaryRider__WriterDesc_WriteString)),IO_BinaryRider__WriterDesc_WriteString)((IO_BinaryRider__Writer)i0, (void*)(_check_pointer(i1, 16038)), i2);
  return;
  ;
}

void OOC_Doc__TextDesc_Load(OOC_Doc__Text text, ADT_Storable__Reader r) {
  register OOC_INT32 i0,i1,i2;
  OOC_INT32 len;

  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)text;
  OOC_Doc__InlineElementDesc_Load((OOC_Doc__InlineElement)i1, (ADT_Storable__Reader)i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 16180)))), IO_BinaryRider__ReaderDesc_ReadNum)),IO_BinaryRider__ReaderDesc_ReadNum)((IO_BinaryRider__Reader)i0, (void*)(OOC_INT32)&len);
  i2 = len;
  *(OOC_INT32*)((_check_pointer(i1, 16210))+16) = ((OOC_INT32)RT0__NewObject(_td_OOC_Scanner_InputBuffer__CharArray.baseTypes[0], (i2+1)));
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 16251))+16);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 16251))+16);
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 16259)), 0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 16233)))), IO_BinaryRider__ReaderDesc_ReadString)),IO_BinaryRider__ReaderDesc_ReadString)((IO_BinaryRider__Reader)i0, (void*)(_check_pointer(i1, 16259)), i2);
  return;
  ;
}

static void OOC_Doc__InitMarkedInline(OOC_Doc__MarkedInline mi, OOC_INT32 mark, OOC_Doc__InlineElement inlineText) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)mi;
  OOC_Doc__InitInlineElement((OOC_Doc__InlineElement)i0);
  i1 = mark;
  *(OOC_INT32*)((_check_pointer(i0, 16435))+16) = i1;
  i1 = (OOC_INT32)inlineText;
  *(OOC_INT32*)((_check_pointer(i0, 16457))+20) = i1;
  return;
  ;
}

OOC_Doc__MarkedInline OOC_Doc__NewMarkedInline(OOC_INT32 mark, OOC_Doc__InlineElement inlineText) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_Doc__MarkedInline.baseTypes[0]);
  i1 = (OOC_INT32)inlineText;
  i2 = mark;
  OOC_Doc__InitMarkedInline((OOC_Doc__MarkedInline)i0, i2, (OOC_Doc__InlineElement)i1);
  return (OOC_Doc__MarkedInline)i0;
  ;
}

void OOC_Doc__MarkedInlineDesc_NodeName(OOC_Doc__MarkedInline mi, OOC_CHAR8 name[], OOC_LEN name_0d) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)mi;
  i0 = *(OOC_INT32*)((_check_pointer(i0, 16812))+16);
  switch (i0) {
  case 0:
    _copy_8((const void*)(OOC_CHAR8*)"asis",(void*)(OOC_INT32)name,name_0d);
    goto l22;
  case 1:
    _copy_8((const void*)(OOC_CHAR8*)"cite",(void*)(OOC_INT32)name,name_0d);
    goto l22;
  case 2:
    _copy_8((const void*)(OOC_CHAR8*)"code",(void*)(OOC_INT32)name,name_0d);
    goto l22;
  case 3:
    _copy_8((const void*)(OOC_CHAR8*)"command",(void*)(OOC_INT32)name,name_0d);
    goto l22;
  case 4:
    _copy_8((const void*)(OOC_CHAR8*)"dfn",(void*)(OOC_INT32)name,name_0d);
    goto l22;
  case 5:
    _copy_8((const void*)(OOC_CHAR8*)"emph",(void*)(OOC_INT32)name,name_0d);
    goto l22;
  case 6:
    _copy_8((const void*)(OOC_CHAR8*)"file",(void*)(OOC_INT32)name,name_0d);
    goto l22;
  case 7:
    _copy_8((const void*)(OOC_CHAR8*)"kbd",(void*)(OOC_INT32)name,name_0d);
    goto l22;
  case 8:
    _copy_8((const void*)(OOC_CHAR8*)"samp",(void*)(OOC_INT32)name,name_0d);
    goto l22;
  case 9:
    _copy_8((const void*)(OOC_CHAR8*)"strong",(void*)(OOC_INT32)name,name_0d);
    goto l22;
  case 10:
    _copy_8((const void*)(OOC_CHAR8*)"var",(void*)(OOC_INT32)name,name_0d);
    goto l22;
  case 11:
    _copy_8((const void*)(OOC_CHAR8*)"url",(void*)(OOC_INT32)name,name_0d);
    goto l22;
  case 12:
    _copy_8((const void*)(OOC_CHAR8*)"oberon-module",(void*)(OOC_INT32)name,name_0d);
    goto l22;
  case 13:
    _copy_8((const void*)(OOC_CHAR8*)"oberon-const",(void*)(OOC_INT32)name,name_0d);
    goto l22;
  case 14:
    _copy_8((const void*)(OOC_CHAR8*)"oberon-field",(void*)(OOC_INT32)name,name_0d);
    goto l22;
  case 15:
    _copy_8((const void*)(OOC_CHAR8*)"oberon-param",(void*)(OOC_INT32)name,name_0d);
    goto l22;
  case 16:
    _copy_8((const void*)(OOC_CHAR8*)"oberon-proc",(void*)(OOC_INT32)name,name_0d);
    goto l22;
  case 17:
    _copy_8((const void*)(OOC_CHAR8*)"oberon-type",(void*)(OOC_INT32)name,name_0d);
    goto l22;
  case 18:
    _copy_8((const void*)(OOC_CHAR8*)"oberon-var",(void*)(OOC_INT32)name,name_0d);
    goto l22;
  default:
    _failed_case(i0, 16805);
    goto l22;
  }
l22:
  return;
  ;
}

void OOC_Doc__MarkedInlineDesc_Normalize(OOC_Doc__MarkedInline mi) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)mi;
  OOC_Doc__NormalizeInlineList((void*)((_check_pointer(i0, 17708))+20));
  return;
  ;
}

void OOC_Doc__MarkedInlineDesc_StripHeadWS(OOC_Doc__MarkedInline mi) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)mi;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17796))+20);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17796))+20);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 17808)))), OOC_Doc__InlineElementDesc_StripHeadWS)),OOC_Doc__InlineElementDesc_StripHeadWS)((OOC_Doc__InlineElement)i0);
  return;
  ;
}

void OOC_Doc__MarkedInlineDesc_StripTailWS(OOC_Doc__MarkedInline mi) {
  register OOC_INT32 i0;
  OOC_Doc__InlineElement last;

  i0 = (OOC_INT32)mi;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17956))+20);
  i0 = (OOC_INT32)OOC_Doc__LastInlineElement((OOC_Doc__InlineElement)i0);
  last = (OOC_Doc__InlineElement)i0;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 17979)))), OOC_Doc__InlineElementDesc_StripTailWS)),OOC_Doc__InlineElementDesc_StripTailWS)((OOC_Doc__InlineElement)i0);
  return;
  ;
}

void OOC_Doc__MarkedInlineDesc_Store(OOC_Doc__MarkedInline mi, ADT_Storable__Writer w) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)mi;
  OOC_Doc__InlineElementDesc_Store((OOC_Doc__InlineElement)i1, (ADT_Storable__Writer)i0);
  i2 = *(OOC_INT32*)((_check_pointer(i1, 18134))+16);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 18120)))), IO_BinaryRider__WriterDesc_WriteNum)),IO_BinaryRider__WriterDesc_WriteNum)((IO_BinaryRider__Writer)i0, i2);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 18165))+20);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 18148)))), ADT_Storable__WriterDesc_WriteObject)),ADT_Storable__WriterDesc_WriteObject)((ADT_Storable__Writer)i0, (Object__Object)i1);
  return;
  ;
}

void OOC_Doc__MarkedInlineDesc_Load(OOC_Doc__MarkedInline mi, ADT_Storable__Reader r) {
  register OOC_INT32 i0,i1,i2;
  Object__Object obj;

  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)mi;
  OOC_Doc__InlineElementDesc_Load((OOC_Doc__InlineElement)i1, (ADT_Storable__Reader)i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 18328)))), IO_BinaryRider__ReaderDesc_ReadNum)),IO_BinaryRider__ReaderDesc_ReadNum)((IO_BinaryRider__Reader)i0, (void*)((_check_pointer(i1, 18341))+16));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 18355)))), ADT_Storable__ReaderDesc_ReadObject)),ADT_Storable__ReaderDesc_ReadObject)((ADT_Storable__Reader)i0, (void*)(OOC_INT32)&obj);
  i0 = (OOC_INT32)obj;
  i2 = i0==(OOC_INT32)0;
  if (i2) goto l3;
  *(OOC_INT32*)((_check_pointer(i1, 18444))+20) = (_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 18464)))), &_td_OOC_Doc__InlineElementDesc, 18464));
  goto l4;
l3:
  *(OOC_INT32*)((_check_pointer(i1, 18407))+20) = (OOC_INT32)0;
l4:
  return;
  ;
}

static void OOC_Doc__InitOberonRef(OOC_Doc__OberonRef or, OOC_INT32 mark, OOC_Doc__InlineElement inlineText, ADT_Storable__Object target) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)inlineText;
  i1 = mark;
  i2 = (OOC_INT32)or;
  OOC_Doc__InitMarkedInline((OOC_Doc__MarkedInline)i2, i1, (OOC_Doc__InlineElement)i0);
  i0 = (OOC_INT32)target;
  *(OOC_INT32*)((_check_pointer(i2, 18718))+24) = i0;
  *(OOC_INT32*)((_check_pointer(i2, 18744))+28) = (OOC_INT32)0;
  *(OOC_INT32*)((_check_pointer(i2, 18775))+32) = (OOC_INT32)0;
  return;
  ;
}

OOC_Doc__MarkedInline OOC_Doc__NewOberonRef(OOC_INT32 mark, OOC_Doc__InlineElement inlineText, ADT_Storable__Object target) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_Doc__OberonRef.baseTypes[0]);
  i1 = (OOC_INT32)target;
  i2 = (OOC_INT32)inlineText;
  i3 = mark;
  OOC_Doc__InitOberonRef((OOC_Doc__OberonRef)i0, i3, (OOC_Doc__InlineElement)i2, (ADT_Storable__Object)i1);
  return (OOC_Doc__MarkedInline)i0;
  ;
}

void OOC_Doc__OberonRefDesc_SetTarget(OOC_Doc__OberonRef or, ADT_Storable__Object targetDecl) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)or;
  i1 = (OOC_INT32)targetDecl;
  *(OOC_INT32*)((_check_pointer(i0, 19164))+24) = i1;
  return;
  ;
}

void OOC_Doc__OberonRefDesc_SetExternalTarget(OOC_Doc__OberonRef or, OOC_Scanner_InputBuffer__CharArray module, OOC_Scanner_InputBuffer__CharArray id) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)or;
  i1 = (OOC_INT32)module;
  *(OOC_INT32*)((_check_pointer(i0, 19301))+28) = i1;
  i1 = (OOC_INT32)id;
  *(OOC_INT32*)((_check_pointer(i0, 19335))+32) = i1;
  return;
  ;
}

void OOC_Doc__OberonRefDesc_Store(OOC_Doc__OberonRef or, ADT_Storable__Writer w) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)or;
  OOC_Doc__MarkedInlineDesc_Store((OOC_Doc__MarkedInline)i1, (ADT_Storable__Writer)i0);
  return;
  ;
}

void OOC_Doc__OberonRefDesc_Load(OOC_Doc__OberonRef or, ADT_Storable__Reader r) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)or;
  OOC_Doc__MarkedInlineDesc_Load((OOC_Doc__MarkedInline)i1, (ADT_Storable__Reader)i0);
  *(OOC_INT32*)((_check_pointer(i1, 19656))+24) = (OOC_INT32)0;
  *(OOC_INT32*)((_check_pointer(i1, 19679))+28) = (OOC_INT32)0;
  *(OOC_INT32*)((_check_pointer(i1, 19710))+32) = (OOC_INT32)0;
  return;
  ;
}

static void OOC_Doc__InitEmail(OOC_Doc__Email email, OOC_Doc__InlineElement address, OOC_Doc__InlineElement displayed) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)email;
  OOC_Doc__InitInlineElement((OOC_Doc__InlineElement)i0);
  i1 = (OOC_INT32)address;
  *(OOC_INT32*)((_check_pointer(i0, 19863))+16) = i1;
  i1 = (OOC_INT32)displayed;
  *(OOC_INT32*)((_check_pointer(i0, 19894))+20) = i1;
  return;
  ;
}

OOC_Doc__Email OOC_Doc__NewEmail(OOC_Doc__InlineElement address, OOC_Doc__InlineElement displayed) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_Doc__Email.baseTypes[0]);
  i1 = (OOC_INT32)displayed;
  i2 = (OOC_INT32)address;
  OOC_Doc__InitEmail((OOC_Doc__Email)i0, (OOC_Doc__InlineElement)i2, (OOC_Doc__InlineElement)i1);
  return (OOC_Doc__Email)i0;
  ;
}

void OOC_Doc__EmailDesc_NodeName(OOC_Doc__Email email, OOC_CHAR8 name[], OOC_LEN name_0d) {

  _copy_8((const void*)(OOC_CHAR8*)"email",(void*)(OOC_INT32)name,name_0d);
  return;
  ;
}

void OOC_Doc__EmailDesc_Normalize(OOC_Doc__Email email) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)email;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20307))+16);
  OOC_Doc__NormalizeArg((OOC_Doc__InlineElement)i1);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20342))+20);
  OOC_Doc__NormalizeArg((OOC_Doc__InlineElement)i0);
  return;
  ;
}

void OOC_Doc__EmailDesc_Store(OOC_Doc__Email email, ADT_Storable__Writer w) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)email;
  OOC_Doc__InlineElementDesc_Store((OOC_Doc__InlineElement)i1, (ADT_Storable__Writer)i0);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 20499))+16);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 20479)))), ADT_Storable__WriterDesc_WriteObject)),ADT_Storable__WriterDesc_WriteObject)((ADT_Storable__Writer)i0, (Object__Object)i2);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 20536))+20);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 20516)))), ADT_Storable__WriterDesc_WriteObject)),ADT_Storable__WriterDesc_WriteObject)((ADT_Storable__Writer)i0, (Object__Object)i1);
  return;
  ;
}

void OOC_Doc__EmailDesc_Load(OOC_Doc__Email email, ADT_Storable__Reader r) {
  register OOC_INT32 i0,i1,i2,i3;
  Object__Object obj;

  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)email;
  OOC_Doc__InlineElementDesc_Load((OOC_Doc__InlineElement)i1, (ADT_Storable__Reader)i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 20697)))), ADT_Storable__ReaderDesc_ReadObject)),ADT_Storable__ReaderDesc_ReadObject)((ADT_Storable__Reader)i0, (void*)(OOC_INT32)&obj);
  i2 = (OOC_INT32)obj;
  i3 = i2==(OOC_INT32)0;
  if (i3) goto l3;
  *(OOC_INT32*)((_check_pointer(i1, 20789))+16) = (_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 20806)))), &_td_OOC_Doc__InlineElementDesc, 20806));
  goto l4;
l3:
  *(OOC_INT32*)((_check_pointer(i1, 20752))+16) = (OOC_INT32)0;
l4:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 20835)))), ADT_Storable__ReaderDesc_ReadObject)),ADT_Storable__ReaderDesc_ReadObject)((ADT_Storable__Reader)i0, (void*)(OOC_INT32)&obj);
  i0 = (OOC_INT32)obj;
  i2 = i0==(OOC_INT32)0;
  if (i2) goto l7;
  *(OOC_INT32*)((_check_pointer(i1, 20929))+20) = (_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 20948)))), &_td_OOC_Doc__InlineElementDesc, 20948));
  goto l8;
l7:
  *(OOC_INT32*)((_check_pointer(i1, 20890))+20) = (OOC_INT32)0;
l8:
  return;
  ;
}

static void OOC_Doc__InitUref(OOC_Doc__Uref uref, OOC_Doc__InlineElement url, OOC_Doc__InlineElement text, OOC_Doc__InlineElement replacement) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)uref;
  OOC_Doc__InitInlineElement((OOC_Doc__InlineElement)i0);
  i1 = (OOC_INT32)url;
  *(OOC_INT32*)((_check_pointer(i0, 21103))+16) = i1;
  i1 = (OOC_INT32)text;
  *(OOC_INT32*)((_check_pointer(i0, 21125))+20) = i1;
  i1 = (OOC_INT32)replacement;
  *(OOC_INT32*)((_check_pointer(i0, 21149))+24) = i1;
  return;
  ;
}

OOC_Doc__Uref OOC_Doc__NewUref(OOC_Doc__InlineElement url, OOC_Doc__InlineElement text, OOC_Doc__InlineElement replacement) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_Doc__Uref.baseTypes[0]);
  i1 = (OOC_INT32)replacement;
  i2 = (OOC_INT32)text;
  i3 = (OOC_INT32)url;
  OOC_Doc__InitUref((OOC_Doc__Uref)i0, (OOC_Doc__InlineElement)i3, (OOC_Doc__InlineElement)i2, (OOC_Doc__InlineElement)i1);
  return (OOC_Doc__Uref)i0;
  ;
}

void OOC_Doc__UrefDesc_NodeName(OOC_Doc__Uref uref, OOC_CHAR8 name[], OOC_LEN name_0d) {

  _copy_8((const void*)(OOC_CHAR8*)"uref",(void*)(OOC_INT32)name,name_0d);
  return;
  ;
}

void OOC_Doc__UrefDesc_Normalize(OOC_Doc__Uref uref) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)uref;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21558))+16);
  OOC_Doc__NormalizeArg((OOC_Doc__InlineElement)i1);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21588))+20);
  OOC_Doc__NormalizeArg((OOC_Doc__InlineElement)i1);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21619))+24);
  OOC_Doc__NormalizeArg((OOC_Doc__InlineElement)i0);
  return;
  ;
}

void OOC_Doc__UrefDesc_Store(OOC_Doc__Uref uref, ADT_Storable__Writer w) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)uref;
  OOC_Doc__InlineElementDesc_Store((OOC_Doc__InlineElement)i1, (ADT_Storable__Writer)i0);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 21774))+16);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 21755)))), ADT_Storable__WriterDesc_WriteObject)),ADT_Storable__WriterDesc_WriteObject)((ADT_Storable__Writer)i0, (Object__Object)i2);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 21806))+20);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 21787)))), ADT_Storable__WriterDesc_WriteObject)),ADT_Storable__WriterDesc_WriteObject)((ADT_Storable__Writer)i0, (Object__Object)i2);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 21839))+24);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 21820)))), ADT_Storable__WriterDesc_WriteObject)),ADT_Storable__WriterDesc_WriteObject)((ADT_Storable__Writer)i0, (Object__Object)i1);
  return;
  ;
}

void OOC_Doc__UrefDesc_Load(OOC_Doc__Uref uref, ADT_Storable__Reader r) {
  register OOC_INT32 i0,i1,i2,i3;
  Object__Object obj;

  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)uref;
  OOC_Doc__InlineElementDesc_Load((OOC_Doc__InlineElement)i1, (ADT_Storable__Reader)i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 22000)))), ADT_Storable__ReaderDesc_ReadObject)),ADT_Storable__ReaderDesc_ReadObject)((ADT_Storable__Reader)i0, (void*)(OOC_INT32)&obj);
  i2 = (OOC_INT32)obj;
  i3 = i2==(OOC_INT32)0;
  if (i3) goto l3;
  *(OOC_INT32*)((_check_pointer(i1, 22086))+16) = (_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 22099)))), &_td_OOC_Doc__InlineElementDesc, 22099));
  goto l4;
l3:
  *(OOC_INT32*)((_check_pointer(i1, 22054))+16) = (OOC_INT32)0;
l4:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 22128)))), ADT_Storable__ReaderDesc_ReadObject)),ADT_Storable__ReaderDesc_ReadObject)((ADT_Storable__Reader)i0, (void*)(OOC_INT32)&obj);
  i2 = (OOC_INT32)obj;
  i3 = i2==(OOC_INT32)0;
  if (i3) goto l7;
  *(OOC_INT32*)((_check_pointer(i1, 22215))+20) = (_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 22229)))), &_td_OOC_Doc__InlineElementDesc, 22229));
  goto l8;
l7:
  *(OOC_INT32*)((_check_pointer(i1, 22182))+20) = (OOC_INT32)0;
l8:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 22258)))), ADT_Storable__ReaderDesc_ReadObject)),ADT_Storable__ReaderDesc_ReadObject)((ADT_Storable__Reader)i0, (void*)(OOC_INT32)&obj);
  i0 = (OOC_INT32)obj;
  i2 = i0==(OOC_INT32)0;
  if (i2) goto l11;
  *(OOC_INT32*)((_check_pointer(i1, 22352))+24) = (_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 22373)))), &_td_OOC_Doc__InlineElementDesc, 22373));
  goto l12;
l11:
  *(OOC_INT32*)((_check_pointer(i1, 22312))+24) = (OOC_INT32)0;
l12:
  return;
  ;
}

static void OOC_Doc__InitParagraph(OOC_Doc__Paragraph p, OOC_CHAR8 padAfter, OOC_Doc__InlineElement inlineText, OOC_CHAR8 noIndent) {
  register OOC_INT32 i0,i1;

  i0 = padAfter;
  i1 = (OOC_INT32)p;
  OOC_Doc__InitBlockElement((OOC_Doc__BlockElement)i1, i0);
  i0 = (OOC_INT32)inlineText;
  *(OOC_INT32*)((_check_pointer(i1, 22565))+20) = i0;
  i0 = noIndent;
  *(OOC_UINT8*)((_check_pointer(i1, 22598))+24) = i0;
  return;
  ;
}

OOC_Doc__Paragraph OOC_Doc__NewParagraph(OOC_CHAR8 padAfter, OOC_Doc__InlineElement inlineText, OOC_CHAR8 noIndent) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_Doc__Paragraph.baseTypes[0]);
  i1 = noIndent;
  i2 = (OOC_INT32)inlineText;
  i3 = padAfter;
  OOC_Doc__InitParagraph((OOC_Doc__Paragraph)i0, i3, (OOC_Doc__InlineElement)i2, i1);
  return (OOC_Doc__Paragraph)i0;
  ;
}

void OOC_Doc__ParagraphDesc_NodeName(OOC_Doc__Paragraph p, OOC_CHAR8 name[], OOC_LEN name_0d) {

  _copy_8((const void*)(OOC_CHAR8*)"p",(void*)(OOC_INT32)name,name_0d);
  return;
  ;
}

void OOC_Doc__ParagraphDesc_Normalize(OOC_Doc__Paragraph p) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)p;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23056))+20);
  OOC_Doc__StripInlineListWS((OOC_Doc__InlineElement)i1);
  OOC_Doc__NormalizeInlineList((void*)((_check_pointer(i0, 23097))+20));
  return;
  ;
}

void OOC_Doc__ParagraphDesc_Store(OOC_Doc__Paragraph p, ADT_Storable__Writer w) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)p;
  OOC_Doc__BlockElementDesc_Store((OOC_Doc__BlockElement)i1, (ADT_Storable__Writer)i0);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 23247))+20);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 23231)))), ADT_Storable__WriterDesc_WriteObject)),ADT_Storable__WriterDesc_WriteObject)((ADT_Storable__Writer)i0, (Object__Object)i2);
  i1 = *(OOC_UINT8*)((_check_pointer(i1, 23281))+24);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 23267)))), IO_BinaryRider__WriterDesc_WriteBool)),IO_BinaryRider__WriterDesc_WriteBool)((IO_BinaryRider__Writer)i0, i1);
  return;
  ;
}

void OOC_Doc__ParagraphDesc_Load(OOC_Doc__Paragraph p, ADT_Storable__Reader r) {
  register OOC_INT32 i0,i1,i2,i3;
  Object__Object obj;

  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)p;
  OOC_Doc__BlockElementDesc_Load((OOC_Doc__BlockElement)i1, (ADT_Storable__Reader)i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 23437)))), ADT_Storable__ReaderDesc_ReadObject)),ADT_Storable__ReaderDesc_ReadObject)((ADT_Storable__Reader)i0, (void*)(OOC_INT32)&obj);
  i2 = (OOC_INT32)obj;
  i3 = i2==(OOC_INT32)0;
  if (i3) goto l3;
  *(OOC_INT32*)((_check_pointer(i1, 23524))+20) = (_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 23544)))), &_td_OOC_Doc__InlineElementDesc, 23544));
  goto l4;
l3:
  *(OOC_INT32*)((_check_pointer(i1, 23488))+20) = (OOC_INT32)0;
l4:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 23573)))), IO_BinaryRider__ReaderDesc_ReadBool)),IO_BinaryRider__ReaderDesc_ReadBool)((IO_BinaryRider__Reader)i0, (void*)((_check_pointer(i1, 23586))+24));
  return;
  ;
}

static void OOC_Doc__InitExample(OOC_Doc__Example ex, OOC_CHAR8 padAfter, OOC_Doc__InlineElement inlineText) {
  register OOC_INT32 i0,i1;

  i0 = padAfter;
  i1 = (OOC_INT32)ex;
  OOC_Doc__InitBlockElement((OOC_Doc__BlockElement)i1, i0);
  i0 = (OOC_INT32)inlineText;
  *(OOC_INT32*)((_check_pointer(i1, 23746))+20) = i0;
  return;
  ;
}

OOC_Doc__Example OOC_Doc__NewExample(OOC_CHAR8 padAfter, OOC_Doc__InlineElement inlineText) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_Doc__Example.baseTypes[0]);
  i1 = (OOC_INT32)inlineText;
  i2 = padAfter;
  OOC_Doc__InitExample((OOC_Doc__Example)i0, i2, (OOC_Doc__InlineElement)i1);
  return (OOC_Doc__Example)i0;
  ;
}

void OOC_Doc__ExampleDesc_NodeName(OOC_Doc__Example ex, OOC_CHAR8 name[], OOC_LEN name_0d) {

  _copy_8((const void*)(OOC_CHAR8*)"example",(void*)(OOC_INT32)name,name_0d);
  return;
  ;
}

void OOC_Doc__ExampleDesc_Normalize(OOC_Doc__Example ex) {

  return;
  ;
}

void OOC_Doc__ExampleDesc_Store(OOC_Doc__Example ex, ADT_Storable__Writer w) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)ex;
  OOC_Doc__BlockElementDesc_Store((OOC_Doc__BlockElement)i1, (ADT_Storable__Writer)i0);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 24280))+20);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 24263)))), ADT_Storable__WriterDesc_WriteObject)),ADT_Storable__WriterDesc_WriteObject)((ADT_Storable__Writer)i0, (Object__Object)i1);
  return;
  ;
}

void OOC_Doc__ExampleDesc_Load(OOC_Doc__Example ex, ADT_Storable__Reader r) {
  register OOC_INT32 i0,i1,i2;
  Object__Object obj;

  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)ex;
  OOC_Doc__BlockElementDesc_Load((OOC_Doc__BlockElement)i1, (ADT_Storable__Reader)i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 24438)))), ADT_Storable__ReaderDesc_ReadObject)),ADT_Storable__ReaderDesc_ReadObject)((ADT_Storable__Reader)i0, (void*)(OOC_INT32)&obj);
  i0 = (OOC_INT32)obj;
  i2 = i0==(OOC_INT32)0;
  if (i2) goto l3;
  *(OOC_INT32*)((_check_pointer(i1, 24527))+20) = (_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 24547)))), &_td_OOC_Doc__InlineElementDesc, 24547));
  goto l4;
l3:
  *(OOC_INT32*)((_check_pointer(i1, 24490))+20) = (OOC_INT32)0;
l4:
  return;
  ;
}

static void OOC_Doc__InitPreCond(OOC_Doc__PreCond pc, OOC_CHAR8 padAfter, OOC_Doc__BlockElement blockList) {
  register OOC_INT32 i0,i1;

  i0 = padAfter;
  i1 = (OOC_INT32)pc;
  OOC_Doc__InitBlockElement((OOC_Doc__BlockElement)i1, i0);
  i0 = (OOC_INT32)blockList;
  *(OOC_INT32*)((_check_pointer(i1, 24716))+20) = i0;
  return;
  ;
}

OOC_Doc__PreCond OOC_Doc__NewPreCond(OOC_CHAR8 padAfter, OOC_Doc__BlockElement blockList) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_Doc__PreCond.baseTypes[0]);
  i1 = (OOC_INT32)blockList;
  i2 = padAfter;
  OOC_Doc__InitPreCond((OOC_Doc__PreCond)i0, i2, (OOC_Doc__BlockElement)i1);
  return (OOC_Doc__PreCond)i0;
  ;
}

void OOC_Doc__PreCondDesc_NodeName(OOC_Doc__PreCond pc, OOC_CHAR8 name[], OOC_LEN name_0d) {

  _copy_8((const void*)(OOC_CHAR8*)"pre-cond",(void*)(OOC_INT32)name,name_0d);
  return;
  ;
}

void OOC_Doc__PreCondDesc_Normalize(OOC_Doc__PreCond pc) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)pc;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25143))+20);
  OOC_Doc__NormalizeBlockList((OOC_Doc__BlockElement)i0);
  return;
  ;
}

void OOC_Doc__PreCondDesc_Store(OOC_Doc__PreCond pc, ADT_Storable__Writer w) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)pc;
  OOC_Doc__BlockElementDesc_Store((OOC_Doc__BlockElement)i1, (ADT_Storable__Writer)i0);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 25293))+20);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 25276)))), ADT_Storable__WriterDesc_WriteObject)),ADT_Storable__WriterDesc_WriteObject)((ADT_Storable__Writer)i0, (Object__Object)i1);
  return;
  ;
}

void OOC_Doc__PreCondDesc_Load(OOC_Doc__PreCond pc, ADT_Storable__Reader r) {
  register OOC_INT32 i0,i1,i2;
  Object__Object obj;

  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)pc;
  OOC_Doc__BlockElementDesc_Load((OOC_Doc__BlockElement)i1, (ADT_Storable__Reader)i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 25450)))), ADT_Storable__ReaderDesc_ReadObject)),ADT_Storable__ReaderDesc_ReadObject)((ADT_Storable__Reader)i0, (void*)(OOC_INT32)&obj);
  i0 = (OOC_INT32)obj;
  i2 = i0==(OOC_INT32)0;
  if (i2) goto l3;
  *(OOC_INT32*)((_check_pointer(i1, 25538))+20) = (_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 25557)))), &_td_OOC_Doc__BlockElementDesc, 25557));
  goto l4;
l3:
  *(OOC_INT32*)((_check_pointer(i1, 25502))+20) = (OOC_INT32)0;
l4:
  return;
  ;
}

static void OOC_Doc__InitPostCond(OOC_Doc__PostCond pc, OOC_CHAR8 padAfter, OOC_Doc__BlockElement blockList) {
  register OOC_INT32 i0,i1;

  i0 = padAfter;
  i1 = (OOC_INT32)pc;
  OOC_Doc__InitBlockElement((OOC_Doc__BlockElement)i1, i0);
  i0 = (OOC_INT32)blockList;
  *(OOC_INT32*)((_check_pointer(i1, 25727))+20) = i0;
  return;
  ;
}

OOC_Doc__PostCond OOC_Doc__NewPostCond(OOC_CHAR8 padAfter, OOC_Doc__BlockElement blockList) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_Doc__PostCond.baseTypes[0]);
  i1 = (OOC_INT32)blockList;
  i2 = padAfter;
  OOC_Doc__InitPostCond((OOC_Doc__PostCond)i0, i2, (OOC_Doc__BlockElement)i1);
  return (OOC_Doc__PostCond)i0;
  ;
}

void OOC_Doc__PostCondDesc_NodeName(OOC_Doc__PostCond pc, OOC_CHAR8 name[], OOC_LEN name_0d) {

  _copy_8((const void*)(OOC_CHAR8*)"post-cond",(void*)(OOC_INT32)name,name_0d);
  return;
  ;
}

void OOC_Doc__PostCondDesc_Normalize(OOC_Doc__PostCond pc) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)pc;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 26163))+20);
  OOC_Doc__NormalizeBlockList((OOC_Doc__BlockElement)i0);
  return;
  ;
}

void OOC_Doc__PostCondDesc_Store(OOC_Doc__PostCond pc, ADT_Storable__Writer w) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)pc;
  OOC_Doc__BlockElementDesc_Store((OOC_Doc__BlockElement)i1, (ADT_Storable__Writer)i0);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 26314))+20);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 26297)))), ADT_Storable__WriterDesc_WriteObject)),ADT_Storable__WriterDesc_WriteObject)((ADT_Storable__Writer)i0, (Object__Object)i1);
  return;
  ;
}

void OOC_Doc__PostCondDesc_Load(OOC_Doc__PostCond pc, ADT_Storable__Reader r) {
  register OOC_INT32 i0,i1,i2;
  Object__Object obj;

  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)pc;
  OOC_Doc__BlockElementDesc_Load((OOC_Doc__BlockElement)i1, (ADT_Storable__Reader)i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 26472)))), ADT_Storable__ReaderDesc_ReadObject)),ADT_Storable__ReaderDesc_ReadObject)((ADT_Storable__Reader)i0, (void*)(OOC_INT32)&obj);
  i0 = (OOC_INT32)obj;
  i2 = i0==(OOC_INT32)0;
  if (i2) goto l3;
  *(OOC_INT32*)((_check_pointer(i1, 26560))+20) = (_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 26579)))), &_td_OOC_Doc__BlockElementDesc, 26579));
  goto l4;
l3:
  *(OOC_INT32*)((_check_pointer(i1, 26524))+20) = (OOC_INT32)0;
l4:
  return;
  ;
}

static void OOC_Doc__InitItem(OOC_Doc__Item item, OOC_CHAR8 padAfter, OOC_Doc__BlockElement blockList) {
  register OOC_INT32 i0,i1;

  i0 = padAfter;
  i1 = (OOC_INT32)item;
  OOC_Doc__InitBlockElement((OOC_Doc__BlockElement)i1, i0);
  i0 = (OOC_INT32)blockList;
  *(OOC_INT32*)((_check_pointer(i1, 26747))+20) = i0;
  return;
  ;
}

OOC_Doc__Item OOC_Doc__NewItem(OOC_CHAR8 padAfter, OOC_Doc__BlockElement blockList) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_Doc__Item.baseTypes[0]);
  i1 = (OOC_INT32)blockList;
  i2 = padAfter;
  OOC_Doc__InitItem((OOC_Doc__Item)i0, i2, (OOC_Doc__BlockElement)i1);
  return (OOC_Doc__Item)i0;
  ;
}

void OOC_Doc__ItemDesc_NodeName(OOC_Doc__Item item, OOC_CHAR8 name[], OOC_LEN name_0d) {

  _copy_8((const void*)(OOC_CHAR8*)"item",(void*)(OOC_INT32)name,name_0d);
  return;
  ;
}

void OOC_Doc__ItemDesc_Normalize(OOC_Doc__Item item) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)item;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 27161))+20);
  OOC_Doc__NormalizeBlockList((OOC_Doc__BlockElement)i1);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 27201))+20);
  OOC_Doc__NoPadLastElement((OOC_Doc__BlockElement)i1);
  *(OOC_UINT8*)((_check_pointer(i0, 27223))+16) = 1u;
  return;
  ;
}

void OOC_Doc__ItemDesc_Store(OOC_Doc__Item item, ADT_Storable__Writer w) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)item;
  OOC_Doc__BlockElementDesc_Store((OOC_Doc__BlockElement)i1, (ADT_Storable__Writer)i0);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 27382))+20);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 27363)))), ADT_Storable__WriterDesc_WriteObject)),ADT_Storable__WriterDesc_WriteObject)((ADT_Storable__Writer)i0, (Object__Object)i1);
  return;
  ;
}

void OOC_Doc__ItemDesc_Load(OOC_Doc__Item item, ADT_Storable__Reader r) {
  register OOC_INT32 i0,i1,i2;
  Object__Object obj;

  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)item;
  OOC_Doc__BlockElementDesc_Load((OOC_Doc__BlockElement)i1, (ADT_Storable__Reader)i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 27540)))), ADT_Storable__ReaderDesc_ReadObject)),ADT_Storable__ReaderDesc_ReadObject)((ADT_Storable__Reader)i0, (void*)(OOC_INT32)&obj);
  i0 = (OOC_INT32)obj;
  i2 = i0==(OOC_INT32)0;
  if (i2) goto l3;
  *(OOC_INT32*)((_check_pointer(i1, 27632))+20) = (_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 27651)))), &_td_OOC_Doc__BlockElementDesc, 27651));
  goto l4;
l3:
  *(OOC_INT32*)((_check_pointer(i1, 27594))+20) = (OOC_INT32)0;
l4:
  return;
  ;
}

static void OOC_Doc__InitItemize(OOC_Doc__Itemize i, OOC_CHAR8 padAfter, OOC_Doc__InlineElement mark, OOC_Doc__Item text, OOC_Doc__BlockElement itemList) {
  register OOC_INT32 i0,i1;

  i0 = padAfter;
  i1 = (OOC_INT32)i;
  OOC_Doc__InitBlockElement((OOC_Doc__BlockElement)i1, i0);
  i0 = (OOC_INT32)mark;
  *(OOC_INT32*)((_check_pointer(i1, 27871))+20) = i0;
  i0 = (OOC_INT32)text;
  *(OOC_INT32*)((_check_pointer(i1, 27892))+24) = i0;
  i0 = (OOC_INT32)itemList;
  *(OOC_INT32*)((_check_pointer(i1, 27913))+28) = i0;
  return;
  ;
}

OOC_Doc__Itemize OOC_Doc__NewItemize(OOC_CHAR8 padAfter, OOC_Doc__InlineElement mark, OOC_Doc__Item text, OOC_Doc__BlockElement itemList) {
  register OOC_INT32 i0,i1,i2,i3,i4;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_Doc__Itemize.baseTypes[0]);
  i1 = (OOC_INT32)itemList;
  i2 = (OOC_INT32)text;
  i3 = (OOC_INT32)mark;
  i4 = padAfter;
  OOC_Doc__InitItemize((OOC_Doc__Itemize)i0, i4, (OOC_Doc__InlineElement)i3, (OOC_Doc__Item)i2, (OOC_Doc__BlockElement)i1);
  return (OOC_Doc__Itemize)i0;
  ;
}

void OOC_Doc__ItemizeDesc_NodeName(OOC_Doc__Itemize i, OOC_CHAR8 name[], OOC_LEN name_0d) {

  _copy_8((const void*)(OOC_CHAR8*)"itemize",(void*)(OOC_INT32)name,name_0d);
  return;
  ;
}

void OOC_Doc__ItemizeDesc_Normalize(OOC_Doc__Itemize i) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)i;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 28396))+20);
  OOC_Doc__StripInlineListWS((OOC_Doc__InlineElement)i1);
  OOC_Doc__NormalizeInlineList((void*)((_check_pointer(i0, 28431))+20));
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 28449))+24);
  i1 = i1!=(OOC_INT32)0;
  if (!i1) goto l4;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 28475))+24);
  OOC_Doc__ItemDesc_Normalize((OOC_Doc__Item)i1);
l4:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 28527))+28);
  OOC_Doc__NormalizeBlockList((OOC_Doc__BlockElement)i1);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 28563))+28);
  OOC_Doc__NoPadLastElement((OOC_Doc__BlockElement)i0);
  return;
  ;
}

void OOC_Doc__ItemizeDesc_Store(OOC_Doc__Itemize i, ADT_Storable__Writer w) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)i;
  OOC_Doc__BlockElementDesc_Store((OOC_Doc__BlockElement)i1, (ADT_Storable__Writer)i0);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 28709))+20);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 28693)))), ADT_Storable__WriterDesc_WriteObject)),ADT_Storable__WriterDesc_WriteObject)((ADT_Storable__Writer)i0, (Object__Object)i2);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 28739))+24);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 28723)))), ADT_Storable__WriterDesc_WriteObject)),ADT_Storable__WriterDesc_WriteObject)((ADT_Storable__Writer)i0, (Object__Object)i2);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 28769))+28);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 28753)))), ADT_Storable__WriterDesc_WriteObject)),ADT_Storable__WriterDesc_WriteObject)((ADT_Storable__Writer)i0, (Object__Object)i1);
  return;
  ;
}

void OOC_Doc__ItemizeDesc_Load(OOC_Doc__Itemize i, ADT_Storable__Reader r) {
  register OOC_INT32 i0,i1,i2,i3;
  Object__Object obj;

  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)i;
  OOC_Doc__BlockElementDesc_Load((OOC_Doc__BlockElement)i1, (ADT_Storable__Reader)i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 28923)))), ADT_Storable__ReaderDesc_ReadObject)),ADT_Storable__ReaderDesc_ReadObject)((ADT_Storable__Reader)i0, (void*)(OOC_INT32)&obj);
  i2 = (OOC_INT32)obj;
  i3 = i2==(OOC_INT32)0;
  if (i3) goto l3;
  *(OOC_INT32*)((_check_pointer(i1, 29004))+20) = (_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 29018)))), &_td_OOC_Doc__InlineElementDesc, 29018));
  goto l4;
l3:
  *(OOC_INT32*)((_check_pointer(i1, 28974))+20) = (OOC_INT32)0;
l4:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 29047)))), ADT_Storable__ReaderDesc_ReadObject)),ADT_Storable__ReaderDesc_ReadObject)((ADT_Storable__Reader)i0, (void*)(OOC_INT32)&obj);
  i2 = (OOC_INT32)obj;
  i3 = i2==(OOC_INT32)0;
  if (i3) goto l7;
  *(OOC_INT32*)((_check_pointer(i1, 29128))+24) = (_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 29142)))), &_td_OOC_Doc__ItemDesc, 29142));
  goto l8;
l7:
  *(OOC_INT32*)((_check_pointer(i1, 29098))+24) = (OOC_INT32)0;
l8:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 29162)))), ADT_Storable__ReaderDesc_ReadObject)),ADT_Storable__ReaderDesc_ReadObject)((ADT_Storable__Reader)i0, (void*)(OOC_INT32)&obj);
  i0 = (OOC_INT32)obj;
  i2 = i0==(OOC_INT32)0;
  if (i2) goto l11;
  *(OOC_INT32*)((_check_pointer(i1, 29247))+28) = (_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 29265)))), &_td_OOC_Doc__BlockElementDesc, 29265));
  goto l12;
l11:
  *(OOC_INT32*)((_check_pointer(i1, 29213))+28) = (OOC_INT32)0;
l12:
  return;
  ;
}

static void OOC_Doc__InitEnumerate(OOC_Doc__Enumerate e, OOC_CHAR8 padAfter, OOC_INT8 mode, OOC_INT32 start, OOC_Doc__Item text, OOC_Doc__BlockElement itemList) {
  register OOC_INT32 i0,i1;

  i0 = padAfter;
  i1 = (OOC_INT32)e;
  OOC_Doc__InitBlockElement((OOC_Doc__BlockElement)i1, i0);
  i0 = mode;
  *(OOC_INT8*)((_check_pointer(i1, 29528))+20) = i0;
  i0 = start;
  *(OOC_INT32*)((_check_pointer(i1, 29549))+24) = i0;
  i0 = (OOC_INT32)text;
  *(OOC_INT32*)((_check_pointer(i1, 29572))+28) = i0;
  i0 = (OOC_INT32)itemList;
  *(OOC_INT32*)((_check_pointer(i1, 29593))+32) = i0;
  return;
  ;
}

OOC_Doc__Enumerate OOC_Doc__NewEnumerate(OOC_CHAR8 padAfter, OOC_INT8 mode, OOC_INT32 start, OOC_Doc__Item text, OOC_Doc__BlockElement itemList) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_Doc__Enumerate.baseTypes[0]);
  i1 = (OOC_INT32)itemList;
  i2 = (OOC_INT32)text;
  i3 = start;
  i4 = mode;
  i5 = padAfter;
  OOC_Doc__InitEnumerate((OOC_Doc__Enumerate)i0, i5, i4, i3, (OOC_Doc__Item)i2, (OOC_Doc__BlockElement)i1);
  return (OOC_Doc__Enumerate)i0;
  ;
}

void OOC_Doc__EnumerateDesc_NodeName(OOC_Doc__Enumerate e, OOC_CHAR8 name[], OOC_LEN name_0d) {

  _copy_8((const void*)(OOC_CHAR8*)"enumerate",(void*)(OOC_INT32)name,name_0d);
  return;
  ;
}

void OOC_Doc__EnumerateDesc_Normalize(OOC_Doc__Enumerate e) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)e;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 30100))+28);
  i1 = i1!=(OOC_INT32)0;
  if (!i1) goto l4;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 30126))+28);
  OOC_Doc__ItemDesc_Normalize((OOC_Doc__Item)i1);
l4:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 30178))+32);
  OOC_Doc__NormalizeBlockList((OOC_Doc__BlockElement)i1);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 30214))+32);
  OOC_Doc__NoPadLastElement((OOC_Doc__BlockElement)i0);
  return;
  ;
}

void OOC_Doc__EnumerateDesc_Store(OOC_Doc__Enumerate e, ADT_Storable__Writer w) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)e;
  OOC_Doc__BlockElementDesc_Store((OOC_Doc__BlockElement)i1, (ADT_Storable__Writer)i0);
  i2 = *(OOC_INT8*)((_check_pointer(i1, 30360))+20);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 30346)))), IO_BinaryRider__WriterDesc_WriteSInt)),IO_BinaryRider__WriterDesc_WriteSInt)((IO_BinaryRider__Writer)i0, i2);
  i2 = *(OOC_INT32*)((_check_pointer(i1, 30387))+24);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 30374)))), IO_BinaryRider__WriterDesc_WriteNum)),IO_BinaryRider__WriterDesc_WriteNum)((IO_BinaryRider__Writer)i0, i2);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 30418))+28);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 30402)))), ADT_Storable__WriterDesc_WriteObject)),ADT_Storable__WriterDesc_WriteObject)((ADT_Storable__Writer)i0, (Object__Object)i2);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 30448))+32);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 30432)))), ADT_Storable__WriterDesc_WriteObject)),ADT_Storable__WriterDesc_WriteObject)((ADT_Storable__Writer)i0, (Object__Object)i1);
  return;
  ;
}

void OOC_Doc__EnumerateDesc_Load(OOC_Doc__Enumerate e, ADT_Storable__Reader r) {
  register OOC_INT32 i0,i1,i2,i3;
  Object__Object obj;

  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)e;
  OOC_Doc__BlockElementDesc_Load((OOC_Doc__BlockElement)i1, (ADT_Storable__Reader)i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 30604)))), IO_BinaryRider__ReaderDesc_ReadSInt)),IO_BinaryRider__ReaderDesc_ReadSInt)((IO_BinaryRider__Reader)i0, (void*)((_check_pointer(i1, 30617))+20));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 30631)))), IO_BinaryRider__ReaderDesc_ReadNum)),IO_BinaryRider__ReaderDesc_ReadNum)((IO_BinaryRider__Reader)i0, (void*)((_check_pointer(i1, 30643))+24));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 30658)))), ADT_Storable__ReaderDesc_ReadObject)),ADT_Storable__ReaderDesc_ReadObject)((ADT_Storable__Reader)i0, (void*)(OOC_INT32)&obj);
  i2 = (OOC_INT32)obj;
  i3 = i2==(OOC_INT32)0;
  if (i3) goto l3;
  *(OOC_INT32*)((_check_pointer(i1, 30739))+28) = (_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 30753)))), &_td_OOC_Doc__ItemDesc, 30753));
  goto l4;
l3:
  *(OOC_INT32*)((_check_pointer(i1, 30709))+28) = (OOC_INT32)0;
l4:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 30773)))), ADT_Storable__ReaderDesc_ReadObject)),ADT_Storable__ReaderDesc_ReadObject)((ADT_Storable__Reader)i0, (void*)(OOC_INT32)&obj);
  i0 = (OOC_INT32)obj;
  i2 = i0==(OOC_INT32)0;
  if (i2) goto l7;
  *(OOC_INT32*)((_check_pointer(i1, 30858))+32) = (_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 30876)))), &_td_OOC_Doc__BlockElementDesc, 30876));
  goto l8;
l7:
  *(OOC_INT32*)((_check_pointer(i1, 30824))+32) = (OOC_INT32)0;
l8:
  return;
  ;
}

static void OOC_Doc__InitFirstColumn(OOC_Doc__FirstColumn fc, OOC_CHAR8 padAfter, OOC_Doc__InlineElement inlineText) {
  register OOC_INT32 i0,i1;

  i0 = padAfter;
  i1 = (OOC_INT32)fc;
  OOC_Doc__InitBlockElement((OOC_Doc__BlockElement)i1, i0);
  i0 = (OOC_INT32)inlineText;
  *(OOC_INT32*)((_check_pointer(i1, 31055))+20) = i0;
  return;
  ;
}

OOC_Doc__FirstColumn OOC_Doc__NewFirstColumn(OOC_CHAR8 padAfter, OOC_Doc__InlineElement inlineText) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_Doc__FirstColumn.baseTypes[0]);
  i1 = (OOC_INT32)inlineText;
  i2 = padAfter;
  OOC_Doc__InitFirstColumn((OOC_Doc__FirstColumn)i0, i2, (OOC_Doc__InlineElement)i1);
  return (OOC_Doc__FirstColumn)i0;
  ;
}

void OOC_Doc__FirstColumnDesc_NodeName(OOC_Doc__FirstColumn fc, OOC_CHAR8 name[], OOC_LEN name_0d) {

  _copy_8((const void*)(OOC_CHAR8*)"table-first-column",(void*)(OOC_INT32)name,name_0d);
  return;
  ;
}

void OOC_Doc__FirstColumnDesc_Normalize(OOC_Doc__FirstColumn fc) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)fc;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 31528))+20);
  OOC_Doc__StripInlineListWS((OOC_Doc__InlineElement)i1);
  OOC_Doc__NormalizeInlineList((void*)((_check_pointer(i0, 31570))+20));
  *(OOC_UINT8*)((_check_pointer(i0, 31591))+16) = 0u;
  return;
  ;
}

void OOC_Doc__FirstColumnDesc_Store(OOC_Doc__FirstColumn fc, ADT_Storable__Writer w) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)fc;
  OOC_Doc__BlockElementDesc_Store((OOC_Doc__BlockElement)i1, (ADT_Storable__Writer)i0);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 31752))+20);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 31735)))), ADT_Storable__WriterDesc_WriteObject)),ADT_Storable__WriterDesc_WriteObject)((ADT_Storable__Writer)i0, (Object__Object)i1);
  return;
  ;
}

void OOC_Doc__FirstColumnDesc_Load(OOC_Doc__FirstColumn fc, ADT_Storable__Reader r) {
  register OOC_INT32 i0,i1,i2;
  Object__Object obj;

  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)fc;
  OOC_Doc__BlockElementDesc_Load((OOC_Doc__BlockElement)i1, (ADT_Storable__Reader)i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 31914)))), ADT_Storable__ReaderDesc_ReadObject)),ADT_Storable__ReaderDesc_ReadObject)((ADT_Storable__Reader)i0, (void*)(OOC_INT32)&obj);
  i0 = (OOC_INT32)obj;
  i2 = i0==(OOC_INT32)0;
  if (i2) goto l3;
  *(OOC_INT32*)((_check_pointer(i1, 32003))+20) = (_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 32023)))), &_td_OOC_Doc__InlineElementDesc, 32023));
  goto l4;
l3:
  *(OOC_INT32*)((_check_pointer(i1, 31966))+20) = (OOC_INT32)0;
l4:
  return;
  ;
}

static void OOC_Doc__InitTableRow(OOC_Doc__TableRow tr, OOC_CHAR8 padAfter, OOC_Doc__BlockElement firstColumnList, OOC_Doc__Item item) {
  register OOC_INT32 i0,i1;

  i0 = padAfter;
  i1 = (OOC_INT32)tr;
  OOC_Doc__InitBlockElement((OOC_Doc__BlockElement)i1, i0);
  i0 = (OOC_INT32)firstColumnList;
  *(OOC_INT32*)((_check_pointer(i1, 32236))+20) = i0;
  i0 = (OOC_INT32)item;
  *(OOC_INT32*)((_check_pointer(i1, 32280))+24) = i0;
  return;
  ;
}

OOC_Doc__TableRow OOC_Doc__NewTableRow(OOC_CHAR8 padAfter, OOC_Doc__BlockElement firstColumnList, OOC_Doc__Item item) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_Doc__TableRow.baseTypes[0]);
  i1 = (OOC_INT32)item;
  i2 = (OOC_INT32)firstColumnList;
  i3 = padAfter;
  OOC_Doc__InitTableRow((OOC_Doc__TableRow)i0, i3, (OOC_Doc__BlockElement)i2, (OOC_Doc__Item)i1);
  return (OOC_Doc__TableRow)i0;
  ;
}

void OOC_Doc__TableRowDesc_NodeName(OOC_Doc__TableRow tr, OOC_CHAR8 name[], OOC_LEN name_0d) {

  _copy_8((const void*)(OOC_CHAR8*)"table-row",(void*)(OOC_INT32)name,name_0d);
  return;
  ;
}

void OOC_Doc__TableRowDesc_Normalize(OOC_Doc__TableRow tr) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)tr;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 32762))+20);
  OOC_Doc__NormalizeBlockList((OOC_Doc__BlockElement)i1);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 32788))+24);
  OOC_Doc__ItemDesc_Normalize((OOC_Doc__Item)i1);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 32813))+24);
  *(OOC_UINT8*)((_check_pointer(i1, 32819))+16) = 0u;
  *(OOC_UINT8*)((_check_pointer(i0, 32846))+16) = 1u;
  return;
  ;
}

void OOC_Doc__TableRowDesc_Store(OOC_Doc__TableRow tr, ADT_Storable__Writer w) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)tr;
  OOC_Doc__BlockElementDesc_Store((OOC_Doc__BlockElement)i1, (ADT_Storable__Writer)i0);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 33003))+20);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 32986)))), ADT_Storable__WriterDesc_WriteObject)),ADT_Storable__WriterDesc_WriteObject)((ADT_Storable__Writer)i0, (Object__Object)i2);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 33045))+24);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 33028)))), ADT_Storable__WriterDesc_WriteObject)),ADT_Storable__WriterDesc_WriteObject)((ADT_Storable__Writer)i0, (Object__Object)i1);
  return;
  ;
}

void OOC_Doc__TableRowDesc_Load(OOC_Doc__TableRow tr, ADT_Storable__Reader r) {
  register OOC_INT32 i0,i1,i2,i3;
  Object__Object obj;

  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)tr;
  OOC_Doc__BlockElementDesc_Load((OOC_Doc__BlockElement)i1, (ADT_Storable__Reader)i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 33199)))), ADT_Storable__ReaderDesc_ReadObject)),ADT_Storable__ReaderDesc_ReadObject)((ADT_Storable__Reader)i0, (void*)(OOC_INT32)&obj);
  i2 = (OOC_INT32)obj;
  i3 = i2==(OOC_INT32)0;
  if (i3) goto l3;
  *(OOC_INT32*)((_check_pointer(i1, 33293))+20) = (_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 33318)))), &_td_OOC_Doc__BlockElementDesc, 33318));
  goto l4;
l3:
  *(OOC_INT32*)((_check_pointer(i1, 33251))+20) = (OOC_INT32)0;
l4:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 33346)))), ADT_Storable__ReaderDesc_ReadObject)),ADT_Storable__ReaderDesc_ReadObject)((ADT_Storable__Reader)i0, (void*)(OOC_INT32)&obj);
  i0 = (OOC_INT32)obj;
  i2 = i0==(OOC_INT32)0;
  if (i2) goto l7;
  *(OOC_INT32*)((_check_pointer(i1, 33429))+24) = (_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 33443)))), &_td_OOC_Doc__ItemDesc, 33443));
  goto l8;
l7:
  *(OOC_INT32*)((_check_pointer(i1, 33398))+24) = (OOC_INT32)0;
l8:
  return;
  ;
}

static void OOC_Doc__InitTable(OOC_Doc__Table t, OOC_CHAR8 padAfter, OOC_Doc__BlockElement rowList) {
  register OOC_INT32 i0,i1;

  i0 = padAfter;
  i1 = (OOC_INT32)t;
  OOC_Doc__InitBlockElement((OOC_Doc__BlockElement)i1, i0);
  i0 = (OOC_INT32)rowList;
  *(OOC_INT32*)((_check_pointer(i1, 33595))+20) = i0;
  return;
  ;
}

OOC_Doc__Table OOC_Doc__NewTable(OOC_CHAR8 padAfter, OOC_Doc__BlockElement rowList) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_Doc__Table.baseTypes[0]);
  i1 = (OOC_INT32)rowList;
  i2 = padAfter;
  OOC_Doc__InitTable((OOC_Doc__Table)i0, i2, (OOC_Doc__BlockElement)i1);
  return (OOC_Doc__Table)i0;
  ;
}

void OOC_Doc__TableDesc_NodeName(OOC_Doc__Table t, OOC_CHAR8 name[], OOC_LEN name_0d) {

  _copy_8((const void*)(OOC_CHAR8*)"table",(void*)(OOC_INT32)name,name_0d);
  return;
  ;
}

void OOC_Doc__TableDesc_Normalize(OOC_Doc__Table t) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)t;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 33988))+20);
  OOC_Doc__NormalizeBlockList((OOC_Doc__BlockElement)i1);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 34023))+20);
  OOC_Doc__NoPadLastElement((OOC_Doc__BlockElement)i0);
  return;
  ;
}

void OOC_Doc__TableDesc_Store(OOC_Doc__Table t, ADT_Storable__Writer w) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)t;
  OOC_Doc__BlockElementDesc_Store((OOC_Doc__BlockElement)i1, (ADT_Storable__Writer)i0);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 34166))+20);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 34150)))), ADT_Storable__WriterDesc_WriteObject)),ADT_Storable__WriterDesc_WriteObject)((ADT_Storable__Writer)i0, (Object__Object)i1);
  return;
  ;
}

void OOC_Doc__TableDesc_Load(OOC_Doc__Table t, ADT_Storable__Reader r) {
  register OOC_INT32 i0,i1,i2;
  Object__Object obj;

  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)t;
  OOC_Doc__BlockElementDesc_Load((OOC_Doc__BlockElement)i1, (ADT_Storable__Reader)i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 34317)))), ADT_Storable__ReaderDesc_ReadObject)),ADT_Storable__ReaderDesc_ReadObject)((ADT_Storable__Reader)i0, (void*)(OOC_INT32)&obj);
  i0 = (OOC_INT32)obj;
  i2 = i0==(OOC_INT32)0;
  if (i2) goto l3;
  *(OOC_INT32*)((_check_pointer(i1, 34401))+20) = (_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 34418)))), &_td_OOC_Doc__BlockElementDesc, 34418));
  goto l4;
l3:
  *(OOC_INT32*)((_check_pointer(i1, 34368))+20) = (OOC_INT32)0;
l4:
  return;
  ;
}

static OOC_Doc__InlineElement OOC_Doc__ExtractSummary(OOC_Doc__BlockElement block) {
  register OOC_INT32 i0,i1;
  OOC_CHAR8 done;
  auto OOC_Doc__InlineElement OOC_Doc__ExtractSummary_Extract(OOC_Doc__InlineElement inlineList);
    
    OOC_Doc__InlineElement OOC_Doc__ExtractSummary_Extract(OOC_Doc__InlineElement inlineList) {
      register OOC_INT32 i0,i1,i2,i3,i4;
      OOC_Doc__InlineList resultList;
      OOC_Doc__InlineElement _inline;
      OOC_Doc__Text newText;
      OOC_INT32 i;
      auto OOC_INT32 OOC_Doc__ExtractSummary_Extract_EndOfSummary(OOC_CHAR8 str[], OOC_LEN str_0d);
        
        OOC_INT32 OOC_Doc__ExtractSummary_Extract_EndOfSummary(OOC_CHAR8 str[], OOC_LEN str_0d) {
          register OOC_INT32 i0,i1;

          i = 0;
          i0 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(0, str_0d, OOC_UINT32, 34828)));
          i0 = i0!=0u;
          if (!i0) goto l15;
          i0=0;
l3_loop:
          i1 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, str_0d, OOC_UINT32, 34858)));
          i0 = i0+1;
          i1 = i1==46u;
          if (i1) goto l6;
          i1=0u;
          goto l8;
l6:
          i1 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, str_0d, OOC_UINT32, 34875)));
          i1 = i1==32u;
          
l8:
          if (!i1) goto l10;
          return i0;
l10:
          i = i0;
          i1 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, str_0d, OOC_UINT32, 34828)));
          i1 = i1!=0u;
          if (i1) goto l3_loop;
l15:
          return (-1);
          ;
        }


      i0 = (OOC_INT32)OOC_Doc__NewInlineList();
      resultList = (OOC_Doc__InlineList)i0;
      i0 = (OOC_INT32)inlineList;
      _inline = (OOC_Doc__InlineElement)i0;
      i1 = i0!=(OOC_INT32)0;
      if (i1) goto l3;
      i1=0u;
      goto l5;
l3:
      i1 = done;
      i1 = !i1;
      
l5:
      if (!i1) goto l43;
      i1 = (OOC_INT32)&_td_OOC_Doc__Position;
      
l7_loop:
      i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 35141)))), &_td_OOC_Doc__GlyphDesc);
      if (i2) goto l33;
      i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 35223)))), &_td_OOC_Doc__TextDesc);
      if (i2) goto l28;
      i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 35502)))), &_td_OOC_Doc__OberonRefDesc);
      if (i2) goto l26;
      i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 35785)))), &_td_OOC_Doc__MarkedInlineDesc);
      if (i2) goto l24;
      i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 35958)))), &_td_OOC_Doc__EmailDesc);
      if (i2) goto l22;
      i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 36062)))), &_td_OOC_Doc__UrefDesc);
      if (i2) goto l20;
      _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 36054)))), 36054);
      goto l34;
l20:
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 36183))+24);
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 36130))+20);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 36117))+16);
      i0 = (OOC_INT32)OOC_Doc__NewUref((OOC_Doc__InlineElement)i0, (OOC_Doc__InlineElement)i3, (OOC_Doc__InlineElement)i2);
      i2 = (OOC_INT32)resultList;
      OOC_Doc__InlineListDesc_Append((OOC_Doc__InlineList)i2, (OOC_Doc__InlineElement)i0);
      goto l34;
l22:
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 36032))+20);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 36015))+16);
      i0 = (OOC_INT32)OOC_Doc__NewEmail((OOC_Doc__InlineElement)i0, (OOC_Doc__InlineElement)i2);
      i2 = (OOC_INT32)resultList;
      OOC_Doc__InlineListDesc_Append((OOC_Doc__InlineList)i2, (OOC_Doc__InlineElement)i0);
      goto l34;
l24:
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 35926))+20);
      i2 = (OOC_INT32)OOC_Doc__ExtractSummary_Extract((OOC_Doc__InlineElement)i2);
      i0 = *(OOC_INT32*)((_check_pointer(i0, 35856))+16);
      i0 = (OOC_INT32)OOC_Doc__NewMarkedInline(i0, (OOC_Doc__InlineElement)i2);
      i2 = (OOC_INT32)resultList;
      OOC_Doc__InlineListDesc_Append((OOC_Doc__InlineList)i2, (OOC_Doc__InlineElement)i0);
      goto l34;
l26:
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 35699))+24);
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 35634))+20);
      i3 = (OOC_INT32)OOC_Doc__ExtractSummary_Extract((OOC_Doc__InlineElement)i3);
      i4 = *(OOC_INT32*)((_check_pointer(i0, 35567))+16);
      i2 = (OOC_INT32)OOC_Doc__NewOberonRef(i4, (OOC_Doc__InlineElement)i3, (ADT_Storable__Object)i2);
      i3 = (OOC_INT32)resultList;
      OOC_Doc__InlineListDesc_Append((OOC_Doc__InlineList)i3, (OOC_Doc__InlineElement)i2);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 35731))+4);
      _copy_block((_check_pointer(i0, 35763)),(_check_pointer((_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 35738)))), &_td_OOC_Doc__OberonRefDesc, 35738)), 35748)),12);
      goto l34;
l28:
      i2 = _check_pointer(i0, 35286);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 35269))+16);
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 35269))+16);
      i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 35277)), 0);
      i0 = (OOC_INT32)OOC_Doc__NewText((void*)(_check_pointer(i3, 35277)), i2, (void*)(_check_pointer(i0, 35286)), (RT0__Struct)i1);
      newText = (OOC_Doc__Text)i0;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 35330))+16);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 35330))+16);
      i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 35338)), 0);
      i0 = OOC_Doc__ExtractSummary_Extract_EndOfSummary((void*)(_check_pointer(i0, 35338)), i2);
      i = i0;
      i2 = i0>=0;
      if (!i2) goto l31;
      i2 = (OOC_INT32)newText;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 35388))+16);
      i2 = _check_pointer(i2, 35396);
      i3 = OOC_ARRAY_LENGTH(i2, 0);
      *(OOC_UINT8*)(i2+(_check_index(i0, i3, OOC_UINT32, 35396))) = 0u;
      done = 1u;
l31:
      i0 = (OOC_INT32)newText;
      i2 = (OOC_INT32)resultList;
      OOC_Doc__InlineListDesc_Append((OOC_Doc__InlineList)i2, (OOC_Doc__InlineElement)i0);
      goto l34;
l33:
      i0 = *(OOC_INT32*)((_check_pointer(i0, 35198))+16);
      i0 = (OOC_INT32)OOC_Doc__NewGlyph(i0);
      i2 = (OOC_INT32)resultList;
      OOC_Doc__InlineListDesc_Append((OOC_Doc__InlineList)i2, (OOC_Doc__InlineElement)i0);
l34:
      i0 = (OOC_INT32)_inline;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 36236))+12);
      _inline = (OOC_Doc__InlineElement)i0;
      i2 = i0!=(OOC_INT32)0;
      if (i2) goto l37;
      i2=0u;
      goto l39;
l37:
      i2 = done;
      i2 = !i2;
      
l39:
      if (i2) goto l7_loop;
l43:
      i0 = (OOC_INT32)resultList;
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 36283));
      return (OOC_Doc__InlineElement)i0;
      ;
    }


  i0 = (OOC_INT32)block;
  i1 = i0!=(OOC_INT32)0;
  if (i1) goto l3;
  i1=0u;
  goto l5;
l3:
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 36348)))), &_td_OOC_Doc__ParagraphDesc);
  
l5:
  if (i1) goto l7;
  return (OOC_Doc__InlineElement)(OOC_INT32)0;
  goto l8;
l7:
  done = 0u;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 36416)))), &_td_OOC_Doc__ParagraphDesc, 36416)), 36426))+20);
  i0 = (OOC_INT32)OOC_Doc__ExtractSummary_Extract((OOC_Doc__InlineElement)i0);
  return (OOC_Doc__InlineElement)i0;
l8:
  _failed_function(34464); return 0;
  ;
}

OOC_Doc__Document OOC_Doc__NewDocument(OOC_Doc__BlockElement blockList, OOC_Doc_Decoration__Decoration decoration, OOC_INT32 firstColumn) {
  register OOC_INT32 i0,i1;
  OOC_Doc__Document d;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_Doc__Document.baseTypes[0]);
  d = (OOC_Doc__Document)i0;
  i1 = (OOC_INT32)blockList;
  *(OOC_INT32*)(_check_pointer(i0, 36712)) = i1;
  *(OOC_INT32*)((_check_pointer(i0, 36743))+4) = 0;
  i1 = (OOC_INT32)decoration;
  *(OOC_INT32*)((_check_pointer(i0, 36766))+8) = i1;
  i1 = firstColumn;
  *(OOC_INT32*)((_check_pointer(i0, 36799))+12) = i1;
  *(OOC_INT32*)((_check_pointer(i0, 36834))+16) = 0;
  return (OOC_Doc__Document)i0;
  ;
}

void OOC_Doc__DocumentDesc_AddUsedImport(OOC_Doc__Document d, ADT_Storable__Object importDecl) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  OOC_INT32 i;

  i0 = (OOC_INT32)d;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 37002))+16);
  i1 = i1==(OOC_INT32)0;
  if (!i1) goto l3;
  i1 = (OOC_INT32)ADT_ArrayList__New(2);
  *(OOC_INT32*)((_check_pointer(i0, 37039))+16) = i1;
l3:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 37106))+16);
  i = 0;
  i1 = *(OOC_INT32*)((_check_pointer(i1, 37123))+4);
  i2 = (OOC_INT32)importDecl;
  i3 = 0<i1;
  if (!i3) goto l14;
  i3=0;
l6_loop:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 37146))+16);
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 37163));
  i4 = _check_pointer(i4, 37170);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 37170))*4);
  i4 = i4==i2;
  if (!i4) goto l9;
  return;
l9:
  i3 = i3+1;
  i = i3;
  i4 = i3<i1;
  if (i4) goto l6_loop;
l14:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 37232))+16);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 37232))+16);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 37249)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i0, (Object__Object)i2);
  return;
  ;
}

void OOC_Doc__DocumentDesc_Store(OOC_Doc__Document d, ADT_Storable__Writer w) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)d;
  i1 = (OOC_INT32)w;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 37391));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 37375)))), ADT_Storable__WriterDesc_WriteObject)),ADT_Storable__WriterDesc_WriteObject)((ADT_Storable__Writer)i1, (Object__Object)i2);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 37426))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 37410)))), ADT_Storable__WriterDesc_WriteObject)),ADT_Storable__WriterDesc_WriteObject)((ADT_Storable__Writer)i1, (Object__Object)i0);
  return;
  ;
}

void OOC_Doc__DocumentDesc_Load(OOC_Doc__Document d, ADT_Storable__Reader r) {
  register OOC_INT32 i0,i1,i2;
  Object__Object obj;

  i0 = (OOC_INT32)r;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 37629)))), ADT_Storable__ReaderDesc_ReadObject)),ADT_Storable__ReaderDesc_ReadObject)((ADT_Storable__Reader)i0, (void*)(OOC_INT32)&obj);
  i1 = (OOC_INT32)obj;
  i2 = i1==(OOC_INT32)0;
  if (i2) goto l3;
  i2 = (OOC_INT32)d;
  *(OOC_INT32*)(_check_pointer(i2, 37715)) = (_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 37734)))), &_td_OOC_Doc__BlockElementDesc, 37734));
  i1=i2;
  goto l4;
l3:
  i1 = (OOC_INT32)d;
  *(OOC_INT32*)(_check_pointer(i1, 37680)) = (OOC_INT32)0;
  
l4:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 37762)))), ADT_Storable__ReaderDesc_ReadObject)),ADT_Storable__ReaderDesc_ReadObject)((ADT_Storable__Reader)i0, (void*)(OOC_INT32)&obj);
  i0 = (OOC_INT32)obj;
  i2 = i0==(OOC_INT32)0;
  if (i2) goto l7;
  *(OOC_INT32*)((_check_pointer(i1, 37846))+4) = (_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 37863)))), &_td_OOC_Doc__InlineElementDesc, 37863));
  goto l8;
l7:
  *(OOC_INT32*)((_check_pointer(i1, 37813))+4) = (OOC_INT32)0;
l8:
  *(OOC_INT32*)((_check_pointer(i1, 37892))+8) = (OOC_INT32)0;
  *(OOC_INT32*)((_check_pointer(i1, 37918))+12) = 0;
  *(OOC_INT32*)((_check_pointer(i1, 37943))+16) = (OOC_INT32)0;
  return;
  ;
}

void OOC_Doc__DocumentDesc_Normalize(OOC_Doc__Document doc) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)doc;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 38055));
  OOC_Doc__NormalizeBlockList((OOC_Doc__BlockElement)i1);
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 38108));
  i1 = (OOC_INT32)OOC_Doc__ExtractSummary((OOC_Doc__BlockElement)i1);
  *(OOC_INT32*)((_check_pointer(i0, 38076))+4) = i1;
  return;
  ;
}

void OOC_Doc__DocumentDesc_Merge(OOC_Doc__Document doc, OOC_Doc__Document source) {
  register OOC_INT32 i0,i1;
  OOC_Doc__BlockElement last;

  i0 = (OOC_INT32)doc;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 38241));
  i1 = i1==0;
  if (i1) goto l3;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 38351));
  i0 = (OOC_INT32)OOC_Doc__LastBlockElement((OOC_Doc__BlockElement)i0);
  last = (OOC_Doc__BlockElement)i0;
  i1 = (OOC_INT32)source;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 38396));
  *(OOC_INT32*)((_check_pointer(i0, 38375))+12) = i1;
  goto l4;
l3:
  i1 = (OOC_INT32)source;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 38295));
  *(OOC_INT32*)(_check_pointer(i0, 38274)) = i1;
l4:
  return;
  ;
}

void OOC_OOC_Doc_init(void) {

  return;
  ;
}

void OOC_OOC_Doc_destroy(void) {
}

/* --- */
