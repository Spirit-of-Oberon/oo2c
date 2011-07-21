#include <URI/Scheme/Hierarchical.d>
#include <__oo2c.h>
#include <setjmp.h>

void URI_Scheme_Hierarchical__InitParameter(URI_Scheme_Hierarchical__Parameter param, Object__String string) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)param;
  *(OOC_INT32*)(_check_pointer(i0, 2587)) = 0;
  i1 = (OOC_INT32)string;
  *(OOC_INT32*)((_check_pointer(i0, 2611))+4) = i1;
  return;
  ;
}

URI_Scheme_Hierarchical__Parameter URI_Scheme_Hierarchical__NewParameter(Object__String string) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)RT0__NewObject(_td_URI_Scheme_Hierarchical__Parameter.baseTypes[0]);
  i1 = (OOC_INT32)string;
  URI_Scheme_Hierarchical__InitParameter((URI_Scheme_Hierarchical__Parameter)i0, (Object__String)i1);
  return (URI_Scheme_Hierarchical__Parameter)i0;
  ;
}

void URI_Scheme_Hierarchical__ParameterDesc_Copy(URI_Scheme_Hierarchical__Parameter param, URI_Scheme_Hierarchical__Parameter dest) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)dest;
  *(OOC_INT32*)(_check_pointer(i0, 2901)) = 0;
  i1 = (OOC_INT32)param;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 2941))+4);
  *(OOC_INT32*)((_check_pointer(i0, 2924))+4) = i1;
  return;
  ;
}

URI_Scheme_Hierarchical__Parameter URI_Scheme_Hierarchical__ParameterDesc_Clone(URI_Scheme_Hierarchical__Parameter param) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)RT0__NewObject(_td_URI_Scheme_Hierarchical__Parameter.baseTypes[0]);
  i1 = (OOC_INT32)param;
  URI_Scheme_Hierarchical__ParameterDesc_Copy((URI_Scheme_Hierarchical__Parameter)i1, (URI_Scheme_Hierarchical__Parameter)i0);
  return (URI_Scheme_Hierarchical__Parameter)i0;
  ;
}

void URI_Scheme_Hierarchical__ParameterDesc_WriteXML(URI_Scheme_Hierarchical__Parameter param, TextRider__Writer w) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3194)))), TextRider__WriterDesc_WriteString)),TextRider__WriterDesc_WriteString)((TextRider__Writer)i0, (OOC_CHAR8*)"\012<parameter>", 13);
  i1 = (OOC_INT32)param;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 3257))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3237)))), TextRider__WriterDesc_WriteObject)),TextRider__WriterDesc_WriteObject)((TextRider__Writer)i0, (Object__Object)i1);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3273)))), TextRider__WriterDesc_WriteString)),TextRider__WriterDesc_WriteString)((TextRider__Writer)i0, (OOC_CHAR8*)"</parameter>", 13);
  return;
  ;
}

void URI_Scheme_Hierarchical__ParameterDesc_Append(URI_Scheme_Hierarchical__Parameter param, ADT_StringBuffer__StringBuffer sb) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)param;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3428))+4);
  i1 = (OOC_INT32)sb;
  URI_String__AppendEscaped((Object__String)i0, (OOC_CHAR8*)":@&=+$,", 8, (ADT_StringBuffer__StringBuffer)i1);
  return;
  ;
}

void URI_Scheme_Hierarchical__InitSegment(URI_Scheme_Hierarchical__Segment segm, Object__String string) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)segm;
  *(OOC_INT32*)(_check_pointer(i0, 3656)) = 0;
  i1 = (OOC_INT32)string;
  *(OOC_INT32*)((_check_pointer(i0, 3679))+4) = i1;
  *(OOC_INT32*)((_check_pointer(i0, 3707))+12) = 0;
  *(OOC_UINT8*)((_check_pointer(i0, 3735))+8) = 0u;
  return;
  ;
}

URI_Scheme_Hierarchical__Segment URI_Scheme_Hierarchical__NewSegment(Object__String string) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)RT0__NewObject(_td_URI_Scheme_Hierarchical__Segment.baseTypes[0]);
  i1 = (OOC_INT32)string;
  URI_Scheme_Hierarchical__InitSegment((URI_Scheme_Hierarchical__Segment)i0, (Object__String)i1);
  return (URI_Scheme_Hierarchical__Segment)i0;
  ;
}

void URI_Scheme_Hierarchical__SegmentDesc_AppendParameter(URI_Scheme_Hierarchical__Segment segm, URI_Scheme_Hierarchical__Parameter param) {
  register OOC_INT32 i0;
  auto void URI_Scheme_Hierarchical__SegmentDesc_AppendParameter_Append(URI_Scheme_Hierarchical__Parameter *list);
    
    void URI_Scheme_Hierarchical__SegmentDesc_AppendParameter_Append(URI_Scheme_Hierarchical__Parameter *list) {
      register OOC_INT32 i0,i1;

      i0 = (OOC_INT32)*list;
      i1 = i0==(OOC_INT32)0;
      if (i1) goto l3;
      URI_Scheme_Hierarchical__SegmentDesc_AppendParameter_Append((void*)(_check_pointer(i0, 4137)));
      goto l4;
l3:
      i0 = (OOC_INT32)param;
      *list = (URI_Scheme_Hierarchical__Parameter)i0;
l4:
      return;
      ;
    }


  i0 = (OOC_INT32)param;
  *(OOC_INT32*)(_check_pointer(i0, 4191)) = 0;
  i0 = (OOC_INT32)segm;
  URI_Scheme_Hierarchical__SegmentDesc_AppendParameter_Append((void*)((_check_pointer(i0, 4222))+12));
  return;
  ;
}

void URI_Scheme_Hierarchical__SegmentDesc_Copy(URI_Scheme_Hierarchical__Segment segm, URI_Scheme_Hierarchical__Segment dest) {
  register OOC_INT32 i0,i1,i2;
  URI_Scheme_Hierarchical__Parameter param;

  i0 = (OOC_INT32)dest;
  i1 = (OOC_INT32)segm;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 4366));
  *(OOC_INT32*)(_check_pointer(i0, 4352)) = i2;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 4398))+4);
  *(OOC_INT32*)((_check_pointer(i0, 4382))+4) = i2;
  *(OOC_INT32*)((_check_pointer(i0, 4416))+12) = 0;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 4453))+12);
  param = (URI_Scheme_Hierarchical__Parameter)i1;
  i2 = i1!=0;
  if (!i2) goto l8;
l3_loop:
  i2 = (OOC_INT32)URI_Scheme_Hierarchical__ParameterDesc_Clone((URI_Scheme_Hierarchical__Parameter)i1);
  URI_Scheme_Hierarchical__SegmentDesc_AppendParameter((URI_Scheme_Hierarchical__Segment)i0, (URI_Scheme_Hierarchical__Parameter)i2);
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 4559));
  param = (URI_Scheme_Hierarchical__Parameter)i1;
  i2 = i1!=0;
  if (i2) goto l3_loop;
l8:
  return;
  ;
}

URI_Scheme_Hierarchical__Segment URI_Scheme_Hierarchical__SegmentDesc_Clone(URI_Scheme_Hierarchical__Segment segm) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)RT0__NewObject(_td_URI_Scheme_Hierarchical__Segment.baseTypes[0]);
  i1 = (OOC_INT32)segm;
  URI_Scheme_Hierarchical__SegmentDesc_Copy((URI_Scheme_Hierarchical__Segment)i1, (URI_Scheme_Hierarchical__Segment)i0);
  return (URI_Scheme_Hierarchical__Segment)i0;
  ;
}

void URI_Scheme_Hierarchical__SegmentDesc_WriteXML(URI_Scheme_Hierarchical__Segment segm, TextRider__Writer w) {
  register OOC_INT32 i0,i1,i2;
  URI_Scheme_Hierarchical__Parameter param;

  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4835)))), TextRider__WriterDesc_WriteString)),TextRider__WriterDesc_WriteString)((TextRider__Writer)i0, (OOC_CHAR8*)"\012<segment>", 11);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4876)))), TextRider__WriterDesc_WriteString)),TextRider__WriterDesc_WriteString)((TextRider__Writer)i0, (OOC_CHAR8*)"\012<value>", 9);
  i1 = (OOC_INT32)segm;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 4934))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4915)))), TextRider__WriterDesc_WriteObject)),TextRider__WriterDesc_WriteObject)((TextRider__Writer)i0, (Object__Object)i2);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4950)))), TextRider__WriterDesc_WriteString)),TextRider__WriterDesc_WriteString)((TextRider__Writer)i0, (OOC_CHAR8*)"</value>", 9);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 4995))+12);
  param = (URI_Scheme_Hierarchical__Parameter)i1;
  i2 = i1!=(OOC_INT32)0;
  if (!i2) goto l8;
l3_loop:
  URI_Scheme_Hierarchical__ParameterDesc_WriteXML((URI_Scheme_Hierarchical__Parameter)i1, (TextRider__Writer)i0);
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 5082));
  param = (URI_Scheme_Hierarchical__Parameter)i1;
  i2 = i1!=(OOC_INT32)0;
  if (i2) goto l3_loop;
l8:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5103)))), TextRider__WriterDesc_WriteString)),TextRider__WriterDesc_WriteString)((TextRider__Writer)i0, (OOC_CHAR8*)"\012</segment>", 12);
  return;
  ;
}

void URI_Scheme_Hierarchical__SegmentDesc_Append(URI_Scheme_Hierarchical__Segment segm, ADT_StringBuffer__StringBuffer sb) {
  register OOC_INT32 i0,i1,i2,i3;
  URI_Scheme_Hierarchical__Parameter param;

  i0 = (OOC_INT32)segm;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5287))+4);
  i2 = (OOC_INT32)sb;
  URI_String__AppendEscaped((Object__String)i1, (OOC_CHAR8*)":@&=+$,", 8, (ADT_StringBuffer__StringBuffer)i2);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5346))+12);
  param = (URI_Scheme_Hierarchical__Parameter)i0;
  i1 = i0!=(OOC_INT32)0;
  if (!i1) goto l8;
  i1 = (OOC_INT32)_c0;
  
l3_loop:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 5394)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i2, (Object__Object)i1);
  URI_Scheme_Hierarchical__ParameterDesc_Append((URI_Scheme_Hierarchical__Parameter)i0, (ADT_StringBuffer__StringBuffer)i2);
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 5454));
  param = (URI_Scheme_Hierarchical__Parameter)i0;
  i3 = i0!=(OOC_INT32)0;
  if (i3) goto l3_loop;
l8:
  return;
  ;
}

void URI_Scheme_Hierarchical__Init(URI_Scheme_Hierarchical__Generic uri, Object__String schemeId, URI__Authority authority, URI__Query query) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)query;
  i1 = (OOC_INT32)authority;
  i2 = (OOC_INT32)schemeId;
  i3 = (OOC_INT32)uri;
  URI__InitHierarchicalURI((URI__HierarchicalURI)i3, (Object__String)i2, (URI__Authority)i1, (URI__Query)i0);
  *(OOC_INT32*)((_check_pointer(i3, 5811))+12) = (OOC_INT32)0;
  *(OOC_UINT8*)((_check_pointer(i3, 5837))+16) = 1u;
  return;
  ;
}

URI_Scheme_Hierarchical__Generic URI_Scheme_Hierarchical__New(Object__String schemeId, URI__Authority authority, URI__Query query) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)RT0__NewObject(_td_URI_Scheme_Hierarchical__Generic.baseTypes[0]);
  i1 = (OOC_INT32)query;
  i2 = (OOC_INT32)authority;
  i3 = (OOC_INT32)schemeId;
  URI_Scheme_Hierarchical__Init((URI_Scheme_Hierarchical__Generic)i0, (Object__String)i3, (URI__Authority)i2, (URI__Query)i1);
  return (URI_Scheme_Hierarchical__Generic)i0;
  ;
}

void URI_Scheme_Hierarchical__GenericDesc_AppendSegment(URI_Scheme_Hierarchical__Generic uri, URI_Scheme_Hierarchical__Segment segm) {
  register OOC_INT32 i0;
  auto void URI_Scheme_Hierarchical__GenericDesc_AppendSegment_Append(URI_Scheme_Hierarchical__Segment *list);
    
    void URI_Scheme_Hierarchical__GenericDesc_AppendSegment_Append(URI_Scheme_Hierarchical__Segment *list) {
      register OOC_INT32 i0,i1;

      i0 = (OOC_INT32)*list;
      i1 = i0==(OOC_INT32)0;
      if (i1) goto l3;
      URI_Scheme_Hierarchical__GenericDesc_AppendSegment_Append((void*)(_check_pointer(i0, 6493)));
      goto l4;
l3:
      i0 = (OOC_INT32)segm;
      *list = (URI_Scheme_Hierarchical__Segment)i0;
l4:
      return;
      ;
    }


  i0 = (OOC_INT32)segm;
  *(OOC_INT32*)(_check_pointer(i0, 6546)) = 0;
  i0 = (OOC_INT32)uri;
  URI_Scheme_Hierarchical__GenericDesc_AppendSegment_Append((void*)((_check_pointer(i0, 6576))+12));
  return;
  ;
}

void URI_Scheme_Hierarchical__GenericDesc_RemoveSegment(URI_Scheme_Hierarchical__Generic uri, URI_Scheme_Hierarchical__Segment segm) {
  register OOC_INT32 i0,i1,i2;
  URI_Scheme_Hierarchical__Segment ptr;

  i0 = (OOC_INT32)uri;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6872))+12);
  i2 = (OOC_INT32)segm;
  i1 = i1==i2;
  if (i1) goto l12;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6955))+12);
  ptr = (URI_Scheme_Hierarchical__Segment)i0;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 6983));
  i1 = i1!=i2;
  if (!i1) goto l11;
l6_loop:
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 7019));
  ptr = (URI_Scheme_Hierarchical__Segment)i0;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 6983));
  i1 = i1!=i2;
  if (i1) goto l6_loop;
l11:
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 7060));
  *(OOC_INT32*)(_check_pointer(i0, 7046)) = i1;
  goto l13;
l12:
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 6923));
  *(OOC_INT32*)((_check_pointer(i0, 6905))+12) = i1;
l13:
  return;
  ;
}

void URI_Scheme_Hierarchical__GenericDesc_StripSegments(URI_Scheme_Hierarchical__Generic uri, OOC_INT32 n) {
  register OOC_INT32 i0,i1;
  auto OOC_INT32 URI_Scheme_Hierarchical__GenericDesc_StripSegments_Strip(URI_Scheme_Hierarchical__Segment *list, OOC_INT32 n);
    
    OOC_INT32 URI_Scheme_Hierarchical__GenericDesc_StripSegments_Strip(URI_Scheme_Hierarchical__Segment *list, OOC_INT32 n) {
      register OOC_INT32 i0,i1;

      i0 = (OOC_INT32)*list;
      i1 = i0==(OOC_INT32)0;
      if (i1) goto l6;
      i1 = n;
      i0 = URI_Scheme_Hierarchical__GenericDesc_StripSegments_Strip((void*)(_check_pointer(i0, 7488)), i1);
      i1 = i0>0;
      if (!i1) goto l5;
      *list = (URI_Scheme_Hierarchical__Segment)(OOC_INT32)0;
l5:
      return (i0-1);
      goto l7;
l6:
      i0 = n;
      return i0;
l7:
      _failed_function(7325); return 0;
      ;
    }


  i0 = (OOC_INT32)uri;
  i1 = n;
  i0 = URI_Scheme_Hierarchical__GenericDesc_StripSegments_Strip((void*)((_check_pointer(i0, 7637))+12), i1);
  return;
  ;
}

URI_Scheme_Hierarchical__Generic URI_Scheme_Hierarchical__GenericDesc_Clone(URI_Scheme_Hierarchical__Generic uri) {
  register OOC_INT32 i0,i1;
  URI_Scheme_Hierarchical__Generic copy;

  i0 = (OOC_INT32)RT0__NewObject(_td_URI_Scheme_Hierarchical__Generic.baseTypes[0]);
  copy = (URI_Scheme_Hierarchical__Generic)i0;
  i1 = (OOC_INT32)uri;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 7775)))), URI__HierarchicalURIDesc_Copy)),URI__HierarchicalURIDesc_Copy)((URI__HierarchicalURI)i1, (URI__URI)i0);
  return (URI_Scheme_Hierarchical__Generic)i0;
  ;
}

void URI_Scheme_Hierarchical__GenericDesc_Copy(URI_Scheme_Hierarchical__Generic uri, URI__URI dest) {
  register OOC_INT32 i0,i1,i2;
  URI_Scheme_Hierarchical__Segment segm;

  i0 = (OOC_INT32)dest;
  i1 = (OOC_INT32)uri;
  URI__HierarchicalURIDesc_Copy((URI__HierarchicalURI)i1, (URI__URI)i0);
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7937)))), &_td_URI_Scheme_Hierarchical__GenericDesc);
  if (i2) goto l3;
  _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7928)))), 7928);
  goto l12;
l3:
  *(OOC_INT32*)((_check_pointer(i0, 7960))+12) = (OOC_INT32)0;
  i2 = *(OOC_UINT8*)((_check_pointer(i1, 8010))+16);
  *(OOC_UINT8*)((_check_pointer(i0, 7989))+16) = i2;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 8043))+12);
  segm = (URI_Scheme_Hierarchical__Segment)i1;
  i2 = i1!=(OOC_INT32)0;
  if (!i2) goto l12;
l6_loop:
  i2 = (OOC_INT32)URI_Scheme_Hierarchical__SegmentDesc_Clone((URI_Scheme_Hierarchical__Segment)i1);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8095)))), URI_Scheme_Hierarchical__GenericDesc_AppendSegment)),URI_Scheme_Hierarchical__GenericDesc_AppendSegment)((URI_Scheme_Hierarchical__Generic)i0, (URI_Scheme_Hierarchical__Segment)i2);
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 8148));
  segm = (URI_Scheme_Hierarchical__Segment)i1;
  i2 = i1!=(OOC_INT32)0;
  if (i2) goto l6_loop;
l12:
  return;
  ;
}

void URI_Scheme_Hierarchical__GenericDesc_ClearPath(URI_Scheme_Hierarchical__Generic uri) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)uri;
  *(OOC_INT32*)((_check_pointer(i0, 8238))+12) = (OOC_INT32)0;
  *(OOC_UINT8*)((_check_pointer(i0, 8264))+16) = 1u;
  return;
  ;
}

URI__Authority URI_Scheme_Hierarchical__GenericDesc_NewAuthority(URI_Scheme_Hierarchical__Generic uri) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)URI_Authority_Unparsed__New((Object__String)((OOC_INT32)_c1));
  return (URI__Authority)i0;
  ;
}

URI__Query URI_Scheme_Hierarchical__GenericDesc_NewQuery(URI_Scheme_Hierarchical__Generic uri) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)URI_Query_Unparsed__New((Object__String)((OOC_INT32)_c2));
  return (URI__Query)i0;
  ;
}

void URI_Scheme_Hierarchical__GenericDesc_ParsePath(URI_Scheme_Hierarchical__Generic uri, Object__CharsLatin1 str, OOC_CHAR8 absolute, OOC_INT16 offset) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8,i9;
  URI_Scheme_Hierarchical__Segment oldPathList;
  OOC_CHAR8 absToggle;
  OOC_INT16 i;
  OOC_INT16 start;
  Object__String substr;
  URI_Scheme_Hierarchical__Segment segment;

  i0 = (OOC_INT32)uri;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8842))+12);
  oldPathList = (URI_Scheme_Hierarchical__Segment)i1;
  i2 = absolute;
  absToggle = i2;
  *(OOC_INT32*)((_check_pointer(i0, 8888))+12) = (OOC_INT32)0;
  i3 = (OOC_INT32)str;
  i = 0;
  i5=i2;i4=0;
l1_loop:
  start = i4;
  if (i5) goto l4;
  i6 = _check_pointer(i3, 8976);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = *(OOC_UINT8*)(i6+(_check_index(i4, i7, OOC_UINT16, 8976)));
  i6 = i6!=58u;
  
  goto l6;
l4:
  i6=1u;
l6:
  if (i6) goto l8;
  i6=0u;
  goto l10;
l8:
  i6 = OOC_ARRAY_LENGTH((_check_pointer(i3, 9014)), 0);
  i6 = URI_CharClass__SkipPChar((void*)(_check_pointer(i3, 9014)), i6, (void*)(OOC_INT32)&i);
  
l10:
  if (!i6) goto l24;
l11_loop:
  if (i5) goto l14;
  i6 = _check_pointer(i3, 8976);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i8 = i;
  i6 = *(OOC_UINT8*)(i6+(_check_index(i8, i7, OOC_UINT16, 8976)));
  i6 = i6!=58u;
  
  goto l16;
l14:
  i6=1u;
l16:
  if (i6) goto l18;
  i6=0u;
  goto l20;
l18:
  i6 = OOC_ARRAY_LENGTH((_check_pointer(i3, 9014)), 0);
  i6 = URI_CharClass__SkipPChar((void*)(_check_pointer(i3, 9014)), i6, (void*)(OOC_INT32)&i);
  
l20:
  if (i6) goto l11_loop;
l24:
  i6 = OOC_ARRAY_LENGTH((_check_pointer(i3, 9076)), 0);
  i7 = i;
  i4 = (OOC_INT32)Object__NewLatin1Region((void*)(_check_pointer(i3, 9076)), i6, i4, i7);
  substr = (Object__String)i4;
  i6 = (OOC_INT32)URI_String__Unescape((Object__String)i4);
  i6 = (OOC_INT32)URI_Scheme_Hierarchical__NewSegment((Object__String)i6);
  segment = (URI_Scheme_Hierarchical__Segment)i6;
  i4 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 9177)))), Object__StringDesc_IndexOf)),Object__StringDesc_IndexOf)((Object__String)i4, 37u, 0);
  *(OOC_UINT8*)((_check_pointer(i6, 9154))+8) = (i4>=0);
  i4 = _check_pointer(i3, 9218);
  i7 = OOC_ARRAY_LENGTH(i4, 0);
  i8 = i;
  i4 = *(OOC_UINT8*)(i4+(_check_index(i8, i7, OOC_UINT16, 9218)));
  i4 = i4==59u;
  if (!i4) goto l55;
  i4=i8;
l27_loop:
  i4 = i4+1;
  i = i4;
  start = i4;
  if (i5) goto l30;
  i7 = _check_pointer(i3, 9301);
  i8 = OOC_ARRAY_LENGTH(i7, 0);
  i7 = *(OOC_UINT8*)(i7+(_check_index(i4, i8, OOC_UINT16, 9301)));
  i7 = i7!=58u;
  
  goto l32;
l30:
  i7=1u;
l32:
  if (i7) goto l34;
  i7=0u;
  goto l36;
l34:
  i7 = OOC_ARRAY_LENGTH((_check_pointer(i3, 9339)), 0);
  i7 = URI_CharClass__SkipPChar((void*)(_check_pointer(i3, 9339)), i7, (void*)(OOC_INT32)&i);
  
l36:
  if (!i7) goto l50;
l37_loop:
  if (i5) goto l40;
  i7 = _check_pointer(i3, 9301);
  i8 = OOC_ARRAY_LENGTH(i7, 0);
  i9 = i;
  i7 = *(OOC_UINT8*)(i7+(_check_index(i9, i8, OOC_UINT16, 9301)));
  i7 = i7!=58u;
  
  goto l42;
l40:
  i7=1u;
l42:
  if (i7) goto l44;
  i7=0u;
  goto l46;
l44:
  i7 = OOC_ARRAY_LENGTH((_check_pointer(i3, 9339)), 0);
  i7 = URI_CharClass__SkipPChar((void*)(_check_pointer(i3, 9339)), i7, (void*)(OOC_INT32)&i);
  
l46:
  if (i7) goto l37_loop;
l50:
  i7 = OOC_ARRAY_LENGTH((_check_pointer(i3, 9459)), 0);
  i8 = i;
  i4 = (OOC_INT32)Object__NewLatin1Region((void*)(_check_pointer(i3, 9459)), i7, i4, i8);
  i4 = (OOC_INT32)URI_String__Unescape((Object__String)i4);
  i4 = (OOC_INT32)URI_Scheme_Hierarchical__NewParameter((Object__String)i4);
  URI_Scheme_Hierarchical__SegmentDesc_AppendParameter((URI_Scheme_Hierarchical__Segment)i6, (URI_Scheme_Hierarchical__Parameter)i4);
  i4 = _check_pointer(i3, 9218);
  i7 = OOC_ARRAY_LENGTH(i4, 0);
  i8 = i;
  i4 = *(OOC_UINT8*)(i4+(_check_index(i8, i7, OOC_UINT16, 9218)));
  i4 = i4==59u;
  if (!i4) goto l55;
  i4=i8;
  goto l27_loop;
l55:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9496)))), URI_Scheme_Hierarchical__GenericDesc_AppendSegment)),URI_Scheme_Hierarchical__GenericDesc_AppendSegment)((URI_Scheme_Hierarchical__Generic)i0, (URI_Scheme_Hierarchical__Segment)i6);
  absToggle = 1u;
  i4 = _check_pointer(i3, 9561);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i6 = i;
  i4 = *(OOC_UINT8*)(i4+(_check_index(i6, i5, OOC_UINT16, 9561)));
  i4 = i4==47u;
  if (!i4) goto l60;
  i4 = i6+1;
  i = i4;
  
  i5=1u;
  goto l1_loop;
l60:
  i3 = _check_pointer(i3, 9647);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i3 = *(OOC_UINT8*)(i3+(_check_index(i6, i4, OOC_UINT16, 9647)));
  i3 = i3!=0u;
  if (i3) goto l63;
  *(OOC_UINT8*)((_check_pointer(i0, 9832))+16) = i2;
  goto l64;
l63:
  *(OOC_INT32*)((_check_pointer(i0, 9671))+12) = i1;
  i0 = offset;
  i1 = (OOC_INT32)RT0__NewObject(_td_Exception__ParseError.baseTypes[0]);
  Exception__ParseErrorDesc_INIT((Exception__ParseError)i1, (Object__String)((OOC_INT32)_c3), (i6+i0));
  Exception__Raise((void*)i1);
l64:
  return;
  ;
}

void URI_Scheme_Hierarchical__GenericDesc_ResolveRelative(URI_Scheme_Hierarchical__Generic uri, URI__HierarchicalURI baseURI) {
  register OOC_INT32 i0,i1,i2,i3;
  URI__URI copy;
  URI_Scheme_Hierarchical__Segment ptr;
  URI_Scheme_Hierarchical__Segment next;
  auto void URI_Scheme_Hierarchical__GenericDesc_ResolveRelative_RemoveDot(URI_Scheme_Hierarchical__Segment *segm);
  auto OOC_CHAR8 URI_Scheme_Hierarchical__GenericDesc_ResolveRelative_RemoveDotDot(URI_Scheme_Hierarchical__Segment *segm);
    
    void URI_Scheme_Hierarchical__GenericDesc_ResolveRelative_RemoveDot(URI_Scheme_Hierarchical__Segment *segm) {
      register OOC_INT32 i0,i1,i2,i3;

      i0 = (OOC_INT32)*segm;
      i1 = i0!=(OOC_INT32)0;
      if (i1) goto l3;
      i1=0u;
      goto l5;
l3:
      i1 = *(OOC_UINT8*)((_check_pointer(i0, 10096))+8);
      i1 = !i1;
      
l5:
      if (i1) goto l7;
      i0=0u;
      goto l9;
l7:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10115))+4);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10115))+4);
      i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 10122)))), Object__StringDesc_Equals)),Object__StringDesc_Equals)((Object__String)i0, (Object__Object)((OOC_INT32)_c4));
      
l9:
      if (!i0) goto l28;
      i0 = (OOC_INT32)_c5;
      i1 = (OOC_INT32)_c6;
l11_loop:
      i2 = (OOC_INT32)*segm;
      i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 10154));
      i3 = i3==(OOC_INT32)0;
      if (i3) goto l14;
      i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 10237));
      *segm = (URI_Scheme_Hierarchical__Segment)i2;
      goto l15;
l14:
      *(OOC_INT32*)((_check_pointer(i2, 10187))+4) = i0;
l15:
      i2 = (OOC_INT32)*segm;
      i3 = i2!=(OOC_INT32)0;
      if (i3) goto l18;
      i3=0u;
      goto l20;
l18:
      i3 = *(OOC_UINT8*)((_check_pointer(i2, 10096))+8);
      i3 = !i3;
      
l20:
      if (i3) goto l22;
      i2=0u;
      goto l24;
l22:
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 10115))+4);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 10115))+4);
      i2 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 10122)))), Object__StringDesc_Equals)),Object__StringDesc_Equals)((Object__String)i2, (Object__Object)i1);
      
l24:
      if (i2) goto l11_loop;
l28:
      i0 = (OOC_INT32)*segm;
      i1 = i0!=(OOC_INT32)0;
      if (!i1) goto l31;
      URI_Scheme_Hierarchical__GenericDesc_ResolveRelative_RemoveDot((void*)(_check_pointer(i0, 10317)));
l31:
      return;
      ;
    }

    
    OOC_CHAR8 URI_Scheme_Hierarchical__GenericDesc_ResolveRelative_RemoveDotDot(URI_Scheme_Hierarchical__Segment *segm) {
      register OOC_INT32 i0,i1,i2;

      i0 = (OOC_INT32)*segm;
      i1 = i0!=(OOC_INT32)0;
      if (i1) goto l3;
      return 0u;
      goto l32;
l3:
      if (i1) goto l6;
      i1=0u;
      goto l12;
l6:
      i1 = *(OOC_UINT8*)((_check_pointer(i0, 10491))+8);
      if (i1) goto l9;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10511))+4);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10511))+4);
      i1 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 10518)))), Object__StringDesc_Equals)),Object__StringDesc_Equals)((Object__String)i2, (Object__Object)((OOC_INT32)_c7));
      i1 = !i1;
      
      goto l12;
l9:
      i1=1u;
l12:
      if (i1) goto l14;
      i1=0u;
      goto l16;
l14:
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 10551));
      i1 = i1!=(OOC_INT32)0;
      
l16:
      if (i1) goto l18;
      i1=0u;
      goto l20;
l18:
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 10581));
      i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 10581));
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 10586))+4);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 10586))+4);
      i1 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 10593)))), Object__StringDesc_Equals)),Object__StringDesc_Equals)((Object__String)i1, (Object__Object)((OOC_INT32)_c8));
      
l20:
      if (i1) goto l22;
      i1=0u;
      goto l24;
l22:
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 10625));
      i1 = *(OOC_UINT8*)((_check_pointer(i1, 10630))+8);
      i1 = !i1;
      
l24:
      if (i1) goto l26;
      i0 = URI_Scheme_Hierarchical__GenericDesc_ResolveRelative_RemoveDotDot((void*)(_check_pointer(i0, 10889)));
      return i0;
      goto l32;
l26:
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 10665));
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 10671));
      i1 = i1==(OOC_INT32)0;
      if (i1) goto l29;
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 10791));
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 10797));
      *segm = (URI_Scheme_Hierarchical__Segment)i0;
      goto l30;
l29:
      *(OOC_INT32*)((_check_pointer(i0, 10706))+4) = ((OOC_INT32)_c9);
      i0 = (OOC_INT32)*segm;
      *(OOC_INT32*)(_check_pointer(i0, 10738)) = (OOC_INT32)0;
l30:
      return 1u;
l32:
      _failed_function(10369); return 0;
      ;
    }


  i0 = (OOC_INT32)baseURI;
  i1 = (OOC_INT32)uri;
  URI__HierarchicalURIDesc_ResolveRelative((URI__HierarchicalURI)i1, (URI__HierarchicalURI)i0);
  i2 = *(OOC_UINT8*)((_check_pointer(i1, 11032))+16);
  i2 = !i2;
  if (!i2) goto l34;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11073)))), URI__URIDesc_Clone)),URI__URIDesc_Clone)((URI__URI)i0);
  copy = (URI__URI)i0;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11148)))), &_td_URI_Scheme_Hierarchical__GenericDesc, 11148)), 11156))+12);
  i2 = i2!=(OOC_INT32)0;
  if (!i2) goto l18;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11196)))), &_td_URI_Scheme_Hierarchical__GenericDesc, 11196)), 11204))+12);
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 11214));
  i2 = i2==(OOC_INT32)0;
  if (i2) goto l16;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11309)))), &_td_URI_Scheme_Hierarchical__GenericDesc, 11309)), 11317))+12);
  ptr = (URI_Scheme_Hierarchical__Segment)i2;
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 11349));
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 11355));
  i3 = i3!=(OOC_INT32)0;
  if (!i3) goto l15;
l10_loop:
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 11394));
  ptr = (URI_Scheme_Hierarchical__Segment)i2;
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 11349));
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 11355));
  i3 = i3!=(OOC_INT32)0;
  if (i3) goto l10_loop;
l15:
  *(OOC_INT32*)(_check_pointer(i2, 11429)) = (OOC_INT32)0;
  goto l18;
l16:
  *(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11248)))), &_td_URI_Scheme_Hierarchical__GenericDesc, 11248)), 11256))+12) = (OOC_INT32)0;
l18:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 11529))+12);
  ptr = (URI_Scheme_Hierarchical__Segment)i2;
  i3 = i2!=(OOC_INT32)0;
  if (!i3) goto l26;
l21_loop:
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 11587));
  next = (URI_Scheme_Hierarchical__Segment)i3;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11608)))), &_td_URI_Scheme_Hierarchical__GenericDesc, 11608)), 11616)))), URI_Scheme_Hierarchical__GenericDesc_AppendSegment)),URI_Scheme_Hierarchical__GenericDesc_AppendSegment)((URI_Scheme_Hierarchical__Generic)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11608)))), &_td_URI_Scheme_Hierarchical__GenericDesc, 11608)), (URI_Scheme_Hierarchical__Segment)i2);
  ptr = (URI_Scheme_Hierarchical__Segment)i3;
  i2 = i3!=(OOC_INT32)0;
  if (!i2) goto l26;
  i2=i3;
  goto l21_loop;
l26:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11698)))), &_td_URI_Scheme_Hierarchical__GenericDesc, 11698)), 11706))+12);
  *(OOC_INT32*)((_check_pointer(i1, 11679))+12) = i0;
  URI_Scheme_Hierarchical__GenericDesc_ResolveRelative_RemoveDot((void*)((_check_pointer(i1, 11745))+12));
  i0 = (OOC_INT32)uri;
  i0 = URI_Scheme_Hierarchical__GenericDesc_ResolveRelative_RemoveDotDot((void*)((_check_pointer(i0, 11787))+12));
  if (!i0) goto l33;
l28_loop:
  i0 = (OOC_INT32)uri;
  i0 = URI_Scheme_Hierarchical__GenericDesc_ResolveRelative_RemoveDotDot((void*)((_check_pointer(i0, 11787))+12));
  if (i0) goto l28_loop;
l33:
  i0 = (OOC_INT32)uri;
  i1 = (OOC_INT32)copy;
  i1 = *(OOC_UINT8*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 11839)))), &_td_URI_Scheme_Hierarchical__GenericDesc, 11839)), 11847))+16);
  *(OOC_UINT8*)((_check_pointer(i0, 11816))+16) = i1;
l34:
  return;
  ;
}

URI_Scheme_Hierarchical__Generic URI_Scheme_Hierarchical__GenericDesc_MakeRelative(URI_Scheme_Hierarchical__Generic uri, URI__HierarchicalURI baseURI) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  URI__URI super;
  URI_Scheme_Hierarchical__Generic relURI;
  URI_Scheme_Hierarchical__Segment suffixBase;
  URI_Scheme_Hierarchical__Segment suffixRel;
  URI_Scheme_Hierarchical__Segment ptr;

  i0 = (OOC_INT32)baseURI;
  i1 = i0==(OOC_INT32)0;
  if (i1) goto l59;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12147)))), &_td_URI_Scheme_Hierarchical__GenericDesc);
  if (i1) goto l5;
  i0 = (OOC_INT32)uri;
  return (URI_Scheme_Hierarchical__Generic)i0;
  goto l60;
l5:
  i1 = (OOC_INT32)uri;
  i2 = (OOC_INT32)URI__HierarchicalURIDesc_MakeRelative((URI__HierarchicalURI)i1, (URI__HierarchicalURI)i0);
  super = (URI__URI)i2;
  i3 = i2!=i1;
  if (i3) goto l8;
  return (URI_Scheme_Hierarchical__Generic)i1;
  goto l60;
l8:
  i2 = _type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 12263)))), &_td_URI_Scheme_Hierarchical__GenericDesc, 12263);
  relURI = (URI_Scheme_Hierarchical__Generic)i2;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12466))+12);
  i3 = i3!=(OOC_INT32)0;
  if (!i3) goto l56;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 12508))+12);
  i3 = i3==(OOC_INT32)0;
  if (i3) goto l38;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12906))+12);
  suffixBase = (URI_Scheme_Hierarchical__Segment)i0;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 12948))+12);
  suffixRel = (URI_Scheme_Hierarchical__Segment)i1;
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 12991));
  i3 = i3!=(OOC_INT32)0;
  if (i3) goto l15;
  i3=0u;
  goto l17;
l15:
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 13017));
  i3 = i3!=(OOC_INT32)0;
  
l17:
  if (i3) goto l19;
  i3=0u;
  goto l21;
l19:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13063))+4);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 13087))+4);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13063))+4);
  i3 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 13070)))), Object__StringDesc_Equals)),Object__StringDesc_Equals)((Object__String)i5, (Object__Object)i4);
  
l21:
  if (!i3) goto l39;
l24_loop:
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 13139));
  suffixBase = (URI_Scheme_Hierarchical__Segment)i0;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 13185));
  suffixRel = (URI_Scheme_Hierarchical__Segment)i1;
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 12991));
  i3 = i3!=(OOC_INT32)0;
  if (i3) goto l27;
  i3=0u;
  goto l29;
l27:
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 13017));
  i3 = i3!=(OOC_INT32)0;
  
l29:
  if (i3) goto l31;
  i3=0u;
  goto l33;
l31:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13063))+4);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 13087))+4);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13063))+4);
  i3 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 13070)))), Object__StringDesc_Equals)),Object__StringDesc_Equals)((Object__String)i5, (Object__Object)i4);
  
l33:
  if (i3) goto l24_loop;
  goto l39;
l38:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12704))+12);
  suffixBase = (URI_Scheme_Hierarchical__Segment)i0;
  suffixRel = (URI_Scheme_Hierarchical__Segment)(OOC_INT32)0;
  i1=(OOC_INT32)0;
l39:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 13372)))), URI_Scheme_Hierarchical__GenericDesc_ClearPath)),URI_Scheme_Hierarchical__GenericDesc_ClearPath)((URI_Scheme_Hierarchical__Generic)i2);
  ptr = (URI_Scheme_Hierarchical__Segment)i0;
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 13438));
  i3 = i3!=(OOC_INT32)0;
  if (!i3) goto l47;
  i3 = (OOC_INT32)_c10;
  
l42_loop:
  i4 = (OOC_INT32)URI_Scheme_Hierarchical__NewSegment((Object__String)i3);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 13475)))), URI_Scheme_Hierarchical__GenericDesc_AppendSegment)),URI_Scheme_Hierarchical__GenericDesc_AppendSegment)((URI_Scheme_Hierarchical__Generic)i2, (URI_Scheme_Hierarchical__Segment)i4);
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 13534));
  ptr = (URI_Scheme_Hierarchical__Segment)i0;
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 13438));
  i4 = i4!=(OOC_INT32)0;
  if (i4) goto l42_loop;
l47:
  ptr = (URI_Scheme_Hierarchical__Segment)i1;
  i0 = i1!=(OOC_INT32)0;
  if (!i0) goto l56;
  i0=i1;
l50_loop:
  i1 = (OOC_INT32)URI_Scheme_Hierarchical__SegmentDesc_Clone((URI_Scheme_Hierarchical__Segment)i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 13641)))), URI_Scheme_Hierarchical__GenericDesc_AppendSegment)),URI_Scheme_Hierarchical__GenericDesc_AppendSegment)((URI_Scheme_Hierarchical__Generic)i2, (URI_Scheme_Hierarchical__Segment)i1);
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 13697));
  ptr = (URI_Scheme_Hierarchical__Segment)i0;
  i1 = i0!=(OOC_INT32)0;
  if (i1) goto l50_loop;
l56:
  *(OOC_UINT8*)((_check_pointer(i2, 13751))+16) = 0u;
  return (URI_Scheme_Hierarchical__Generic)i2;
  goto l60;
l59:
  i0 = (OOC_INT32)uri;
  return (URI_Scheme_Hierarchical__Generic)i0;
l60:
  _failed_function(11924); return 0;
  ;
}

void URI_Scheme_Hierarchical__GenericDesc_WriteXML(URI_Scheme_Hierarchical__Generic uri, TextRider__Writer w) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_CHAR8 pathTag[32];
  URI_Scheme_Hierarchical__Segment segm;

  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14044)))), TextRider__WriterDesc_WriteString)),TextRider__WriterDesc_WriteString)((TextRider__Writer)i0, (OOC_CHAR8*)"\012<hierarchical-uri>", 20);
  i1 = (OOC_INT32)uri;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 14100));
  i2 = i2!=0;
  if (!i2) goto l3;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14130)))), TextRider__WriterDesc_WriteString)),TextRider__WriterDesc_WriteString)((TextRider__Writer)i0, (OOC_CHAR8*)"\012<scheme>", 10);
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 14190));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14172)))), TextRider__WriterDesc_WriteObject)),TextRider__WriterDesc_WriteObject)((TextRider__Writer)i0, (Object__Object)i2);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14210)))), TextRider__WriterDesc_WriteString)),TextRider__WriterDesc_WriteString)((TextRider__Writer)i0, (OOC_CHAR8*)"</scheme>", 10);
l3:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 14259))+4);
  i2 = i2!=0;
  if (!i2) goto l6;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 14292))+4);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 14292))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 14303)))), URI__AuthorityDesc_WriteXML)),URI__AuthorityDesc_WriteXML)((URI__Authority)i3, (TextRider__Writer)i0);
l6:
  i2 = *(OOC_UINT8*)((_check_pointer(i1, 14337))+16);
  if (i2) goto l9;
  _copy_8((const void*)(OOC_CHAR8*)"\012<relative-path>",(void*)(OOC_INT32)pathTag,32);
  goto l10;
l9:
  _copy_8((const void*)(OOC_CHAR8*)"\012<absolute-path>",(void*)(OOC_INT32)pathTag,32);
l10:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14464)))), TextRider__WriterDesc_WriteString)),TextRider__WriterDesc_WriteString)((TextRider__Writer)i0, (void*)(OOC_INT32)pathTag, 32);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 14504))+12);
  segm = (URI_Scheme_Hierarchical__Segment)i2;
  i3 = i2!=0;
  if (!i3) goto l18;
l13_loop:
  URI_Scheme_Hierarchical__SegmentDesc_WriteXML((URI_Scheme_Hierarchical__Segment)i2, (TextRider__Writer)i0);
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 14586));
  segm = (URI_Scheme_Hierarchical__Segment)i2;
  i3 = i2!=0;
  if (i3) goto l13_loop;
l18:
  i2 = *(OOC_UINT8*)((_check_pointer(i1, 14612))+16);
  if (i2) goto l21;
  _copy_8((const void*)(OOC_CHAR8*)"\012</relative-path>",(void*)(OOC_INT32)pathTag,32);
  goto l22;
l21:
  _copy_8((const void*)(OOC_CHAR8*)"\012</absolute-path>",(void*)(OOC_INT32)pathTag,32);
l22:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14741)))), TextRider__WriterDesc_WriteString)),TextRider__WriterDesc_WriteString)((TextRider__Writer)i0, (void*)(OOC_INT32)pathTag, 32);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 14777))+8);
  i2 = i2!=0;
  if (!i2) goto l25;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 14806))+8);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 14806))+8);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 14813)))), URI__QueryDesc_WriteXML)),URI__QueryDesc_WriteXML)((URI__Query)i1, (TextRider__Writer)i0);
l25:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14842)))), TextRider__WriterDesc_WriteString)),TextRider__WriterDesc_WriteString)((TextRider__Writer)i0, (OOC_CHAR8*)"\012</hierarchical-uri>", 21);
  return;
  ;
}

void URI_Scheme_Hierarchical__GenericDesc_AppendPath(URI_Scheme_Hierarchical__Generic uri, ADT_StringBuffer__StringBuffer sb) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  URI_Scheme_Hierarchical__Segment segm;

  i0 = (OOC_INT32)uri;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15019))+12);
  i1 = i1!=(OOC_INT32)0;
  if (!i1) goto l17;
  i1 = *(OOC_UINT8*)((_check_pointer(i0, 15054))+16);
  if (!i1) goto l5;
  i1 = (OOC_INT32)sb;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 15084)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i1, (Object__Object)((OOC_INT32)_c11));
l5:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15127))+12);
  segm = (URI_Scheme_Hierarchical__Segment)i1;
  i2 = i1!=(OOC_INT32)0;
  if (!i2) goto l17;
  i2 = (OOC_INT32)_c12;
  i3 = (OOC_INT32)sb;
  
l8_loop:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15189))+12);
  i4 = i1!=i4;
  if (!i4) goto l11;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 15218)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i3, (Object__Object)i2);
l11:
  URI_Scheme_Hierarchical__SegmentDesc_Append((URI_Scheme_Hierarchical__Segment)i1, (ADT_StringBuffer__StringBuffer)i3);
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 15292));
  segm = (URI_Scheme_Hierarchical__Segment)i1;
  i4 = i1!=(OOC_INT32)0;
  if (i4) goto l8_loop;
l17:
  return;
  ;
}

Object__String8 URI_Scheme_Hierarchical__GenericDesc_ToString(URI_Scheme_Hierarchical__Generic uri) {
  register OOC_INT32 i0,i1,i2,i3;
  ADT_StringBuffer__StringBuffer sb;
  Object__String str;

  i0 = (OOC_INT32)ADT_StringBuffer__New((Object__String)((OOC_INT32)_c13));
  sb = (ADT_StringBuffer__StringBuffer)i0;
  i1 = (OOC_INT32)uri;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 15495)))), URI__URIDesc_AppendScheme)),URI__URIDesc_AppendScheme)((URI__URI)i1, (ADT_StringBuffer__StringBuffer)i0);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 15527))+4);
  i2 = i2!=(OOC_INT32)0;
  if (i2) goto l10;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 15600));
  i2 = i2!=(OOC_INT32)0;
  if (i2) goto l5;
  i2=0u;
  goto l7;
l5:
  i2 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 15622)))), URI__HierarchicalURIDesc_AuthorityMandatory)),URI__HierarchicalURIDesc_AuthorityMandatory)((URI__HierarchicalURI)i1);
  
l7:
  if (!i2) goto l11;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 15657)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)((OOC_INT32)_c14));
  goto l11;
l10:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 15560))+4);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 15560))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 15571)))), URI__AuthorityDesc_Append)),URI__AuthorityDesc_Append)((URI__Authority)i3, (ADT_StringBuffer__StringBuffer)i0);
l11:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 15688)))), URI_Scheme_Hierarchical__GenericDesc_AppendPath)),URI_Scheme_Hierarchical__GenericDesc_AppendPath)((URI_Scheme_Hierarchical__Generic)i1, (ADT_StringBuffer__StringBuffer)i0);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 15718))+8);
  i2 = i2!=(OOC_INT32)0;
  if (!i2) goto l14;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 15747))+8);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 15747))+8);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 15754)))), URI__QueryDesc_Append)),URI__QueryDesc_Append)((URI__Query)i1, (ADT_StringBuffer__StringBuffer)i0);
l14:
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 15790)))), ADT_StringBuffer__StringBufferDesc_ToString)),ADT_StringBuffer__StringBufferDesc_ToString)((ADT_StringBuffer__StringBuffer)i0);
  str = (Object__String)i0;
  return (Object__String8)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 15825)))), &_td_Object__String8Desc, 15825));
  ;
}

void OOC_URI_Scheme_Hierarchical_init(void) {
  _c0 = Object__NewLatin1Char(59u);
  _c1 = Object__NewLatin1Region((OOC_CHAR8*)"", 1, 0, 0);
  _c2 = Object__NewLatin1Region((OOC_CHAR8*)"", 1, 0, 0);
  _c3 = Object__NewLatin1Region((OOC_CHAR8*)"Illegal character in path component of the URI", 47, 0, 46);
  _c4 = Object__NewLatin1Char(46u);
  _c5 = Object__NewLatin1Region((OOC_CHAR8*)"", 1, 0, 0);
  _c6 = Object__NewLatin1Char(46u);
  _c7 = Object__NewLatin1Region((OOC_CHAR8*)"..", 3, 0, 2);
  _c8 = Object__NewLatin1Region((OOC_CHAR8*)"..", 3, 0, 2);
  _c9 = Object__NewLatin1Region((OOC_CHAR8*)"", 1, 0, 0);
  _c10 = Object__NewLatin1Region((OOC_CHAR8*)"..", 3, 0, 2);
  _c11 = Object__NewLatin1Char(47u);
  _c12 = Object__NewLatin1Char(47u);
  _c13 = Object__NewLatin1Region((OOC_CHAR8*)"", 1, 0, 0);
  _c14 = Object__NewLatin1Region((OOC_CHAR8*)"//", 3, 0, 2);

  return;
  ;
}

void OOC_URI_Scheme_Hierarchical_destroy(void) {
}

/* --- */
