#include <URI/Parser.d>
#include <__oo2c.h>
#include <setjmp.h>

URI__URI URI_Parser__NewURILatin1(const OOC_CHAR8 str__ref[], OOC_LEN str_0d, URI__HierarchicalURI baseURI) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_ALLOCATE_VPAR(str,OOC_CHAR8 ,str_0d)
  Object__String8 schemeId;
  URI__URI protoURI;
  OOC_INT16 i;
  OOC_INT16 endOfScheme;
  URI__URI uri;
  URI__HierarchicalURI hierURI;
  OOC_INT16 start;
  Object__String8 substr;
  auto void URI_Parser__NewURILatin1_Path(OOC_CHAR8 absolute);
    
    void URI_Parser__NewURILatin1_Path(OOC_CHAR8 absolute) {
      register OOC_INT32 i0,i1,i2,i3;
      OOC_INT16 start;
      Object__String8 substr;

      i0 = absolute;
      if (!i0) goto l3;
      i1 = i;
      i = (i1+1);
l3:
      i1 = i;
      start = i1;
      i2 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i1, str_0d, OOC_UINT16, 2002)));
      i2 = i2!=63u;
      if (i2) goto l6;
      i2=0u;
      goto l8;
l6:
      i2 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i1, str_0d, OOC_UINT16, 2019)));
      i2 = i2!=35u;
      
l8:
      if (i2) goto l10;
      i2=0u;
      goto l12;
l10:
      i2 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i1, str_0d, OOC_UINT16, 2036)));
      i2 = i2!=0u;
      
l12:
      if (!i2) goto l26;
l13_loop:
      i2 = i;
      i2 = i2+1;
      i = i2;
      i3 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i2, str_0d, OOC_UINT16, 2002)));
      i3 = i3!=63u;
      if (i3) goto l16;
      i3=0u;
      goto l18;
l16:
      i3 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i2, str_0d, OOC_UINT16, 2019)));
      i3 = i3!=35u;
      
l18:
      if (i3) goto l20;
      i2=0u;
      goto l22;
l20:
      i2 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i2, str_0d, OOC_UINT16, 2036)));
      i2 = i2!=0u;
      
l22:
      if (i2) goto l13_loop;
l26:
      i2 = i;
      i2 = (OOC_INT32)Object__NewLatin1Region((void*)(OOC_INT32)str, str_0d, i1, i2);
      substr = (Object__String8)i2;
      i2 = (OOC_INT32)Object__String8Desc_CharsLatin1((Object__String8)i2);
      i3 = (OOC_INT32)hierURI;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 2144)))), URI__HierarchicalURIDesc_ParsePath)),URI__HierarchicalURIDesc_ParsePath)((URI__HierarchicalURI)i3, (Object__CharsLatin1)i2, i0, i1);
      return;
      ;
    }


  OOC_INITIALIZE_VPAR(str__ref,str,OOC_CHAR8 ,str_0d)
  i0 = (
  _cmp8((const void*)(OOC_INT32)str,(const void*)""))==0;
  if (!i0) goto l3;
  i0 = (OOC_INT32)URI_Scheme_CurrentDoc__New();
  return (URI__URI)i0;
l3:
  schemeId = (Object__String8)(OOC_INT32)0;
  protoURI = (URI__URI)(OOC_INT32)0;
  i0 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(0, str_0d, OOC_UINT16, 2393)));
  i0 = i0!=58u;
  if (i0) goto l6;
  i0=0u;
  goto l8;
l6:
  i0 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(0, str_0d, OOC_UINT16, 2410)));
  i0 = i0!=47u;
  
l8:
  if (i0) goto l10;
  i0=0u;
  goto l12;
l10:
  i0 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(0, str_0d, OOC_UINT16, 2437)));
  i0 = i0!=63u;
  
l12:
  if (i0) goto l14;
  i0=0u;
  goto l16;
l14:
  i0 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(0, str_0d, OOC_UINT16, 2454)));
  i0 = i0!=35u;
  
l16:
  if (i0) goto l18;
  i0=0u;
  goto l20;
l18:
  i0 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(0, str_0d, OOC_UINT16, 2471)));
  i0 = i0!=0u;
  
l20:
  if (i0) goto l22;
  i0=0;
  goto l44;
l22:
  i0=0;
l23_loop:
  i0 = i0+1;
  i1 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, str_0d, OOC_UINT16, 2393)));
  i1 = i1!=58u;
  if (i1) goto l26;
  i1=0u;
  goto l28;
l26:
  i1 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, str_0d, OOC_UINT16, 2410)));
  i1 = i1!=47u;
  
l28:
  if (i1) goto l30;
  i1=0u;
  goto l32;
l30:
  i1 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, str_0d, OOC_UINT16, 2437)));
  i1 = i1!=63u;
  
l32:
  if (i1) goto l34;
  i1=0u;
  goto l36;
l34:
  i1 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, str_0d, OOC_UINT16, 2454)));
  i1 = i1!=35u;
  
l36:
  if (i1) goto l38;
  i1=0u;
  goto l40;
l38:
  i1 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, str_0d, OOC_UINT16, 2471)));
  i1 = i1!=0u;
  
l40:
  if (i1) goto l23_loop;
l44:
  i1 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, str_0d, OOC_UINT16, 2518)));
  i1 = i1==58u;
  if (i1) goto l47;
  i1=0u;
  goto l49;
l47:
  i1 = i0!=0;
  
l49:
  if (i1) goto l51;
  i = 0;
  i0=(OOC_INT32)0;i1=(OOC_INT32)0;
  goto l75;
l51:
  endOfScheme = i0;
  i = 0;
  i1 = URI_CharClass__SkipAlpha((void*)(OOC_INT32)str, str_0d, (void*)(OOC_INT32)&i);
  if (!i1) goto l70;
  i1 = URI_CharClass__SkipAlphaNum((void*)(OOC_INT32)str, str_0d, (void*)(OOC_INT32)&i);
  if (i1) goto l56;
  i1 = URI_CharClass__SkipMember((void*)(OOC_INT32)str, str_0d, (void*)(OOC_INT32)&i, "+-.", 4);
  
  goto l58;
l56:
  i1=1u;
l58:
  if (!i1) goto l70;
l60_loop:
  i1 = URI_CharClass__SkipAlphaNum((void*)(OOC_INT32)str, str_0d, (void*)(OOC_INT32)&i);
  if (i1) goto l63;
  i1 = URI_CharClass__SkipMember((void*)(OOC_INT32)str, str_0d, (void*)(OOC_INT32)&i, "+-.", 4);
  
  goto l65;
l63:
  i1=1u;
l65:
  if (i1) goto l60_loop;
l70:
  i1 = i;
  i0 = i1==i0;
  if (i0) goto l73;
  i0 = (OOC_INT32)RT0__NewObject(_td_Exception__ParseError.baseTypes[0]);
  Exception__ParseErrorDesc_INIT((Exception__ParseError)i0, (Object__String)((OOC_INT32)_c0), i1);
  Exception__Raise((void*)i0);
  i0=(OOC_INT32)0;i1=(OOC_INT32)0;
  goto l75;
l73:
  i0 = (OOC_INT32)Object__NewLatin1Region((void*)(OOC_INT32)str, str_0d, 0, i1);
  i1 = i;
  schemeId = (Object__String8)i0;
  i = (i1+1);
  i1 = (OOC_INT32)URI__GetScheme((Object__String)i0);
  protoURI = (URI__URI)i1;
  
l75:
  i2 = i0==(OOC_INT32)0;
  if (!i2) goto l83;
  i3 = (OOC_INT32)baseURI;
  i4 = i3==(OOC_INT32)0;
  if (i4) goto l81;
  protoURI = (URI__URI)i3;
  i1=i3;
  goto l83;
l81:
  i3 = (OOC_INT32)RT0__NewObject(_td_Exception__ParseError.baseTypes[0]);
  i4 = i;
  Exception__ParseErrorDesc_INIT((Exception__ParseError)i3, (Object__String)((OOC_INT32)_c1), i4);
  Exception__Raise((void*)i3);
  
l83:
  uri = (URI__URI)(OOC_INT32)0;
  hierURI = (URI__HierarchicalURI)(OOC_INT32)0;
  if (i2) goto l86;
  i2 = i;
  i2 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i2, str_0d, OOC_UINT16, 3638)));
  i2 = i2==47u;
  
  goto l88;
l86:
  i2=1u;
l88:
  if (i2) goto l94;
  i2 = i1!=(OOC_INT32)0;
  if (i2) goto l92;
  i2=0u;
  goto l96;
l92:
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3688)))), &_td_URI__HierarchicalURIDesc);
  
  goto l96;
l94:
  i2=1u;
l96:
  if (i2) goto l108;
  i2 = i;
  i3 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i2, str_0d, OOC_UINT16, 6465)));
  i3 = i3==0u;
  if (!i3) goto l100;
  i3 = (OOC_INT32)RT0__NewObject(_td_Exception__ParseError.baseTypes[0]);
  Exception__ParseErrorDesc_INIT((Exception__ParseError)i3, (Object__String)((OOC_INT32)_c2), i2);
  Exception__Raise((void*)i3);
l100:
  i2 = i1==(OOC_INT32)0;
  if (i2) goto l106;
  i2 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 6690)))), &_td_URI__OpaqueURIDesc));
  if (!i2) goto l107;
  i2 = (OOC_INT32)RT0__NewObject(_td_Exception__ParseError.baseTypes[0]);
  i3 = i;
  Exception__ParseErrorDesc_INIT((Exception__ParseError)i2, (Object__String)((OOC_INT32)_c3), i3);
  Exception__Raise((void*)i2);
  goto l107;
l106:
  i1 = (OOC_INT32)URI_Parser__defaultOpaque;
  protoURI = (URI__URI)i1;
  
l107:
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 6865)))), URI__URIDesc_Clone)),URI__URIDesc_Clone)((URI__URI)i1);
  uri = (URI__URI)i1;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 6885)))), URI__URIDesc_SetSchemeId)),URI__URIDesc_SetSchemeId)((URI__URI)i1, (Object__String)i0);
  i0 = Strings__Length((void*)(OOC_INT32)str, str_0d);
  i2 = i;
  i0 = (OOC_INT32)Object__NewLatin1Region((void*)(OOC_INT32)str, str_0d, i2, i0);
  substr = (Object__String8)i0;
  i0 = (OOC_INT32)Object__String8Desc_CharsLatin1((Object__String8)i0);
  i2 = i;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 6994)))), &_td_URI__OpaqueURIDesc, 6994)), 7004)))), URI__OpaqueURIDesc_ParseOpaquePart)),URI__OpaqueURIDesc_ParseOpaquePart)((URI__OpaqueURI)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 6994)))), &_td_URI__OpaqueURIDesc, 6994)), (Object__CharsLatin1)i0, i2);
  i0 = Strings__Length((void*)(OOC_INT32)str, str_0d);
  i = i0;
  goto l207;
l108:
  i2 = i1==(OOC_INT32)0;
  if (i2) goto l114;
  i2 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3872)))), &_td_URI__HierarchicalURIDesc));
  if (!i2) goto l115;
  i2 = (OOC_INT32)RT0__NewObject(_td_Exception__ParseError.baseTypes[0]);
  i3 = i;
  Exception__ParseErrorDesc_INIT((Exception__ParseError)i2, (Object__String)((OOC_INT32)_c4), i3);
  Exception__Raise((void*)i2);
  goto l115;
l114:
  i1 = (OOC_INT32)URI_Parser__defaultHierarchical;
  protoURI = (URI__URI)i1;
  
l115:
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 4075)))), URI__URIDesc_Clone)),URI__URIDesc_Clone)((URI__URI)i1);
  uri = (URI__URI)i1;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 4095)))), URI__URIDesc_SetSchemeId)),URI__URIDesc_SetSchemeId)((URI__URI)i1, (Object__String)i0);
  i1 = _type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 4146)))), &_td_URI__HierarchicalURIDesc, 4146);
  hierURI = (URI__HierarchicalURI)i1;
  i2 = i;
  i3 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i2, str_0d, OOC_UINT16, 4177)));
  i3 = i3==47u;
  if (i3) goto l118;
  i2=0u;
  goto l120;
l118:
  i2 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index((i2+1), str_0d, OOC_UINT16, 4194)));
  i2 = i2==47u;
  
l120:
  if (i2) goto l136;
  i0 = i0!=(OOC_INT32)0;
  if (i0) goto l124;
  i2=0u;
  goto l126;
l124:
  i2 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5135)))), URI__HierarchicalURIDesc_AuthorityMandatory)),URI__HierarchicalURIDesc_AuthorityMandatory)((URI__HierarchicalURI)i1);
  
l126:
  if (!i2) goto l128;
  i2 = (OOC_INT32)RT0__NewObject(_td_Exception__ParseError.baseTypes[0]);
  i3 = i;
  Exception__ParseErrorDesc_INIT((Exception__ParseError)i2, (Object__String)((OOC_INT32)_c5), i3);
  Exception__Raise((void*)i2);
l128:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5309)))), URI__HierarchicalURIDesc_SetAuthority)),URI__HierarchicalURIDesc_SetAuthority)((URI__HierarchicalURI)i1, (URI__Authority)(OOC_INT32)0);
  i1 = i;
  i2 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i1, str_0d, OOC_UINT16, 5346)));
  i2 = i2==47u;
  if (i2) goto l134;
  if (i0) goto l132;
  URI_Parser__NewURILatin1_Path(0u);
  goto l178;
l132:
  i0 = (OOC_INT32)RT0__NewObject(_td_Exception__ParseError.baseTypes[0]);
  Exception__ParseErrorDesc_INIT((Exception__ParseError)i0, (Object__String)((OOC_INT32)_c6), i1);
  Exception__Raise((void*)i0);
  goto l178;
l134:
  URI_Parser__NewURILatin1_Path(1u);
  goto l178;
l136:
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 4250)))), URI__HierarchicalURIDesc_NewAuthority)),URI__HierarchicalURIDesc_NewAuthority)((URI__HierarchicalURI)i1);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 4227)))), URI__HierarchicalURIDesc_SetAuthority)),URI__HierarchicalURIDesc_SetAuthority)((URI__HierarchicalURI)i1, (URI__Authority)i0);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 4288))+4);
  i0 = i0==(OOC_INT32)0;
  if (i0) goto l176;
  i0 = i;
  i0 = i0+2;
  i = i0;
  start = i0;
  i2 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, str_0d, OOC_UINT16, 4700)));
  i2 = i2!=47u;
  if (i2) goto l141;
  i2=0u;
  goto l143;
l141:
  i2 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, str_0d, OOC_UINT16, 4717)));
  i2 = i2!=63u;
  
l143:
  if (i2) goto l145;
  i2=0u;
  goto l147;
l145:
  i2 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, str_0d, OOC_UINT16, 4750)));
  i2 = i2!=35u;
  
l147:
  if (i2) goto l149;
  i2=0u;
  goto l151;
l149:
  i2 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, str_0d, OOC_UINT16, 4767)));
  i2 = i2!=0u;
  
l151:
  if (i2) goto l153;
  i2=i0;
  goto l171;
l153:
  i2=i0;
l154_loop:
  i2 = i2+1;
  i = i2;
  i3 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i2, str_0d, OOC_UINT16, 4700)));
  i3 = i3!=47u;
  if (i3) goto l157;
  i3=0u;
  goto l159;
l157:
  i3 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i2, str_0d, OOC_UINT16, 4717)));
  i3 = i3!=63u;
  
l159:
  if (i3) goto l161;
  i3=0u;
  goto l163;
l161:
  i3 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i2, str_0d, OOC_UINT16, 4750)));
  i3 = i3!=35u;
  
l163:
  if (i3) goto l165;
  i3=0u;
  goto l167;
l165:
  i3 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i2, str_0d, OOC_UINT16, 4767)));
  i3 = i3!=0u;
  
l167:
  if (i3) goto l154_loop;
l171:
  i2 = (OOC_INT32)Object__NewLatin1Region((void*)(OOC_INT32)str, str_0d, i0, i2);
  substr = (Object__String8)i2;
  i2 = (OOC_INT32)Object__String8Desc_CharsLatin1((Object__String8)i2);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 4891))+4);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 4891))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 4901)))), URI__AuthorityDesc_ParseAuthority)),URI__AuthorityDesc_ParseAuthority)((URI__Authority)i4, (Object__CharsLatin1)i2, i0);
  i0 = i;
  i0 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, str_0d, OOC_UINT16, 4975)));
  i0 = i0==47u;
  if (i0) goto l174;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5049)))), URI__HierarchicalURIDesc_ClearPath)),URI__HierarchicalURIDesc_ClearPath)((URI__HierarchicalURI)i1);
  goto l178;
l174:
  URI_Parser__NewURILatin1_Path(1u);
  goto l178;
l176:
  i0 = (OOC_INT32)RT0__NewObject(_td_Exception__ParseError.baseTypes[0]);
  i1 = i;
  Exception__ParseErrorDesc_INIT((Exception__ParseError)i0, (Object__String)((OOC_INT32)_c7), i1);
  Exception__Raise((void*)i0);
l178:
  i0 = i;
  i0 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, str_0d, OOC_UINT16, 5706)));
  i0 = i0==63u;
  if (i0) goto l181;
  i0 = (OOC_INT32)hierURI;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6231)))), URI__HierarchicalURIDesc_SetQuery)),URI__HierarchicalURIDesc_SetQuery)((URI__HierarchicalURI)i0, (URI__Query)(OOC_INT32)0);
  goto l203;
l181:
  i0 = (OOC_INT32)hierURI;
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5756)))), URI__HierarchicalURIDesc_NewQuery)),URI__HierarchicalURIDesc_NewQuery)((URI__HierarchicalURI)i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5737)))), URI__HierarchicalURIDesc_SetQuery)),URI__HierarchicalURIDesc_SetQuery)((URI__HierarchicalURI)i0, (URI__Query)i1);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5790))+8);
  i1 = i1==(OOC_INT32)0;
  if (i1) goto l201;
  i1 = i;
  i1 = i1+1;
  i = i1;
  start = i1;
  i2 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i1, str_0d, OOC_UINT16, 6005)));
  i2 = i2!=35u;
  if (i2) goto l186;
  i2=0u;
  goto l188;
l186:
  i2 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i1, str_0d, OOC_UINT16, 6022)));
  i2 = i2!=0u;
  
l188:
  if (i2) goto l190;
  i2=i1;
  goto l200;
l190:
  i2=i1;
l191_loop:
  i2 = i2+1;
  i = i2;
  i3 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i2, str_0d, OOC_UINT16, 6005)));
  i3 = i3!=35u;
  if (i3) goto l194;
  i3=0u;
  goto l196;
l194:
  i3 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i2, str_0d, OOC_UINT16, 6022)));
  i3 = i3!=0u;
  
l196:
  if (i3) goto l191_loop;
l200:
  i2 = (OOC_INT32)Object__NewLatin1Region((void*)(OOC_INT32)str, str_0d, i1, i2);
  substr = (Object__String8)i2;
  i2 = (OOC_INT32)Object__String8Desc_CharsLatin1((Object__String8)i2);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6146))+8);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6146))+8);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 6152)))), URI__QueryDesc_ParseQuery)),URI__QueryDesc_ParseQuery)((URI__Query)i0, (Object__CharsLatin1)i2, i1);
  goto l203;
l201:
  i0 = (OOC_INT32)RT0__NewObject(_td_Exception__ParseError.baseTypes[0]);
  i1 = i;
  Exception__ParseErrorDesc_INIT((Exception__ParseError)i0, (Object__String)((OOC_INT32)_c8), i1);
  Exception__Raise((void*)i0);
l203:
  i0 = (OOC_INT32)schemeId;
  i0 = i0==(OOC_INT32)0;
  if (!i0) goto l207;
  i0 = (OOC_INT32)hierURI;
  i1 = (OOC_INT32)baseURI;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6312)))), URI__HierarchicalURIDesc_ResolveRelative)),URI__HierarchicalURIDesc_ResolveRelative)((URI__HierarchicalURI)i0, (URI__HierarchicalURI)i1);
l207:
  i0 = i;
  i1 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, str_0d, OOC_UINT16, 7105)));
  i1 = i1!=0u;
  if (!i1) goto l210;
  i1 = (OOC_INT32)RT0__NewObject(_td_Exception__ParseError.baseTypes[0]);
  Exception__ParseErrorDesc_INIT((Exception__ParseError)i1, (Object__String)((OOC_INT32)_c9), i0);
  Exception__Raise((void*)i1);
l210:
  i0 = (OOC_INT32)uri;
  return (URI__URI)i0;
  ;
}

URI__URI URI_Parser__NewURI(Object__String8 str, URI__HierarchicalURI baseURI) {
  register OOC_INT32 i0,i1,i2;
  Object__CharsLatin1 chars;

  i0 = (OOC_INT32)str;
  i0 = (OOC_INT32)Object__String8Desc_CharsLatin1((Object__String8)i0);
  chars = (Object__CharsLatin1)i0;
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 7458)), 0);
  i2 = (OOC_INT32)baseURI;
  i0 = (OOC_INT32)URI_Parser__NewURILatin1((void*)(_check_pointer(i0, 7458)), i1, (URI__HierarchicalURI)i2);
  return (URI__URI)i0;
  ;
}

URI__Reference URI_Parser__NewReferenceLatin1(const OOC_CHAR8 str__ref[], OOC_LEN str_0d, URI__HierarchicalURI baseURI, URI__Fragment fragmentPrototype) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_ALLOCATE_VPAR(str,OOC_CHAR8 ,str_0d)
  OOC_INT16 i;
  OOC_CHAR8 ch;
  URI__URI uri;
  URI__Fragment fragment;
  Object__String8 substr;

  OOC_INITIALIZE_VPAR(str__ref,str,OOC_CHAR8 ,str_0d)
  i = 0;
  i0 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(0, str_0d, OOC_UINT16, 8262)));
  i0 = i0!=0u;
  if (i0) goto l3;
  i0=0u;
  goto l5;
l3:
  i0 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(0, str_0d, OOC_UINT16, 8278)));
  i0 = i0!=35u;
  
l5:
  if (i0) goto l7;
  i0=0;
  goto l17;
l7:
  i0=0;
l8_loop:
  i0 = i0+1;
  i = i0;
  i1 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, str_0d, OOC_UINT16, 8262)));
  i1 = i1!=0u;
  if (i1) goto l11;
  i1=0u;
  goto l13;
l11:
  i1 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, str_0d, OOC_UINT16, 8278)));
  i1 = i1!=35u;
  
l13:
  if (i1) goto l8_loop;
l17:
  i1 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, str_0d, OOC_UINT16, 8333)));
  ch = i1;
  *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, str_0d, OOC_UINT16, 8345))) = 0u;
  i2 = (OOC_INT32)baseURI;
  i2 = (OOC_INT32)URI_Parser__NewURILatin1((void*)(OOC_INT32)str, str_0d, (URI__HierarchicalURI)i2);
  uri = (URI__URI)i2;
  *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, str_0d, OOC_UINT16, 8402))) = i1;
  i1 = i1==0u;
  if (i1) goto l20;
  i1 = (OOC_INT32)fragmentPrototype;
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 8571)))), URI__FragmentDesc_Clone)),URI__FragmentDesc_Clone)((URI__Fragment)i1);
  fragment = (URI__Fragment)i1;
  i3 = Strings__Length((void*)(OOC_INT32)str, str_0d);
  i0 = i0+1;
  i3 = (OOC_INT32)Object__NewLatin1Region((void*)(OOC_INT32)str, str_0d, i0, i3);
  substr = (Object__String8)i3;
  i3 = (OOC_INT32)Object__String8Desc_CharsLatin1((Object__String8)i3);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 8667)))), URI__FragmentDesc_ParseFragment)),URI__FragmentDesc_ParseFragment)((URI__Fragment)i1, (Object__CharsLatin1)i3, i0);
  i0 = (OOC_INT32)URI__NewReference((URI__URI)i2, (URI__Fragment)i1);
  return (URI__Reference)i0;
  goto l21;
l20:
  i0 = (OOC_INT32)URI__NewReference((URI__URI)i2, (URI__Fragment)(OOC_INT32)0);
  return (URI__Reference)i0;
l21:
  _failed_function(7496); return 0;
  ;
}

URI__Reference URI_Parser__NewReference(Object__String8 str, URI__HierarchicalURI baseURI, URI__Fragment fragmentPrototype) {
  register OOC_INT32 i0,i1,i2,i3;
  Object__CharsLatin1 chars;

  i0 = (OOC_INT32)str;
  i0 = (OOC_INT32)Object__String8Desc_CharsLatin1((Object__String8)i0);
  chars = (Object__CharsLatin1)i0;
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 9104)), 0);
  i2 = (OOC_INT32)baseURI;
  i3 = (OOC_INT32)fragmentPrototype;
  i0 = (OOC_INT32)URI_Parser__NewReferenceLatin1((void*)(_check_pointer(i0, 9104)), i1, (URI__HierarchicalURI)i2, (URI__Fragment)i3);
  return (URI__Reference)i0;
  ;
}

void OOC_URI_Parser_init(void) {
  register OOC_INT32 i0;
  _c0 = Object__NewLatin1Region("Illegal character in scheme component", 38, 0, 37);
  _c1 = Object__NewLatin1Region("Cannot resolve relative URI reference without known base URI", 61, 0, 60);
  _c2 = Object__NewLatin1Region("The opaque part of an URI must not be empty", 44, 0, 43);
  _c3 = Object__NewLatin1Region("Expected opaque URI component, not a slash `/\047", 47, 0, 46);
  _c4 = Object__NewLatin1Region("Expected absolute or net path beginning with a slash `/\047", 57, 0, 56);
  _c5 = Object__NewLatin1Region("The URI does must include an authority component", 49, 0, 48);
  _c6 = Object__NewLatin1Region("The URI scheme name must be followed by a slash `/\047", 52, 0, 51);
  _c7 = Object__NewLatin1Region("This URI scheme does not support an authority component", 56, 0, 55);
  _c8 = Object__NewLatin1Region("This URI scheme does not support a query component", 51, 0, 50);
  _c9 = Object__NewLatin1Region("Junk after URI", 15, 0, 14);
  _c10 = Object__NewLatin1Region("", 1, 0, 0);

  i0 = (OOC_INT32)URI_Scheme_Hierarchical__New((Object__String)(OOC_INT32)0, (URI__Authority)(OOC_INT32)0, (URI__Query)(OOC_INT32)0);
  URI_Parser__defaultHierarchical = (URI__HierarchicalURI)i0;
  i0 = (OOC_INT32)URI_Scheme_Opaque__New((Object__String)(OOC_INT32)0, (Object__String)((OOC_INT32)_c10));
  URI_Parser__defaultOpaque = (URI__OpaqueURI)i0;
  return;
  ;
}

/* --- */
