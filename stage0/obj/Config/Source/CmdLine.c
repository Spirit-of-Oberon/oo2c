#include <Config/Source/CmdLine.d>
#include <__oo2c.h>
#include <setjmp.h>

void Config_Source_CmdLine__ErrorContextDesc_GetTemplate(Config_Source_CmdLine__ErrorContext context, Msg__Msg msg, Msg__LString templ, OOC_LEN templ_0d) {
  register OOC_INT32 i0;
  OOC_CHAR16 t[128];

  i0 = (OOC_INT32)msg;
  i0 = *(OOC_INT32*)((_check_pointer(i0, 4239))+8);
  switch (i0) {
  case 1:
    _copy_16((const void*)((OOC_CHAR16[]){70,97,105,108,101,100,32,116,111,32,99,111,110,110,101,99,116,32,114,101,97,100,101,114,32,116,111,32,112,114,111,103,114,97,109,32,97,114,103,117,109,101,110,116,115,0}),(void*)(OOC_INT32)t,128);
    goto l9;
  case 2:
    _copy_16((const void*)((OOC_CHAR16[]){74,117,110,107,32,97,102,116,101,114,32,108,97,115,116,32,99,111,109,109,97,110,100,32,108,105,110,101,32,97,114,103,117,109,101,110,116,0}),(void*)(OOC_INT32)t,128);
    goto l9;
  case 3:
    _copy_16((const void*)((OOC_CHAR16[]){69,114,114,111,114,32,119,104,105,108,101,32,114,101,97,100,105,110,103,32,99,111,109,109,97,110,100,32,108,105,110,101,32,97,114,103,117,109,101,110,116,115,0}),(void*)(OOC_INT32)t,128);
    LongStrings__Append(((OOC_CHAR16[]){10,0}), 2, (void*)(OOC_INT32)t, 128);
    LongStrings__Append(((OOC_CHAR16[]){32,32,82,101,97,115,111,110,58,32,36,123,114,101,97,115,111,110,125,0}), 20, (void*)(OOC_INT32)t, 128);
    goto l9;
  case 4:
    _copy_16((const void*)((OOC_CHAR16[]){85,110,107,110,111,119,110,32,99,111,109,109,97,110,100,32,108,105,110,101,32,111,112,116,105,111,110,32,96,36,123,115,116,114,105,110,103,125,39,0}),(void*)(OOC_INT32)t,128);
    goto l9;
  case 5:
    _copy_16((const void*)((OOC_CHAR16[]){79,112,116,105,111,110,32,96,36,123,115,116,114,105,110,103,125,39,32,110,101,101,100,115,32,36,123,110,117,109,98,101,114,125,32,97,114,103,117,109,101,110,116,40,115,41,32,97,110,100,32,109,117,115,116,32,115,116,97,110,100,32,102,111,114,32,105,116,115,32,111,119,110,0}),(void*)(OOC_INT32)t,128);
    goto l9;
  case 6:
    _copy_16((const void*)((OOC_CHAR16[]){79,112,116,105,111,110,32,96,36,123,115,116,114,105,110,103,125,39,32,114,101,113,117,105,114,101,115,32,36,123,110,117,109,98,101,114,125,32,112,97,114,97,109,101,116,101,114,40,115,41,0}),(void*)(OOC_INT32)t,128);
    goto l9;
  default:
    _failed_case(i0, 4231);
    goto l9;
  }
l9:
  _copy_16((const void*)(OOC_INT32)t,(void*)(OOC_INT32)templ,templ_0d);
  return;
  ;
}

static Msg__Msg Config_Source_CmdLine__Error(OOC_INT32 code) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)Config_Source_CmdLine__cmdLineContext;
  i1 = code;
  i0 = (OOC_INT32)Msg__New((Msg__Context)i0, i1);
  return (Msg__Msg)i0;
  ;
}

static Msg__Msg Config_Source_CmdLine__ErrorReason(OOC_INT32 code, Msg__Msg reason) {
  register OOC_INT32 i0,i1;
  Msg__Msg err;

  i0 = (OOC_INT32)Config_Source_CmdLine__cmdLineContext;
  i1 = code;
  i0 = (OOC_INT32)Msg__New((Msg__Context)i0, i1);
  err = (Msg__Msg)i0;
  i1 = (OOC_INT32)reason;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5189)))), Msg__MsgDesc_SetMsgAttrib)),Msg__MsgDesc_SetMsgAttrib)((Msg__Msg)i0, "reason", 7, (Msg__Msg)i1);
  return (Msg__Msg)i0;
  ;
}

static Msg__Msg Config_Source_CmdLine__ErrorString(OOC_INT32 code, Object__String8 string) {
  register OOC_INT32 i0,i1,i2;
  Msg__Msg err;
  Object__CharsLatin1 chars;

  i0 = (OOC_INT32)Config_Source_CmdLine__cmdLineContext;
  i1 = code;
  i0 = (OOC_INT32)Msg__New((Msg__Context)i0, i1);
  err = (Msg__Msg)i0;
  i1 = (OOC_INT32)string;
  i1 = (OOC_INT32)Object__String8Desc_CharsLatin1((Object__String8)i1);
  chars = (Object__CharsLatin1)i1;
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i1, 5532)), 0);
  i1 = (OOC_INT32)Msg__GetStringPtr((void*)(_check_pointer(i1, 5532)), i2);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5480)))), Msg__MsgDesc_SetStringAttrib)),Msg__MsgDesc_SetStringAttrib)((Msg__Msg)i0, "string", 7, (Msg__StringPtr)i1);
  return (Msg__Msg)i0;
  ;
}

static Msg__Msg Config_Source_CmdLine__ErrorStringNum(OOC_INT32 code, Object__String8 string, OOC_INT32 number) {
  register OOC_INT32 i0,i1,i2;
  Msg__Msg err;
  Object__CharsLatin1 chars;

  i0 = (OOC_INT32)Config_Source_CmdLine__cmdLineContext;
  i1 = code;
  i0 = (OOC_INT32)Msg__New((Msg__Context)i0, i1);
  err = (Msg__Msg)i0;
  i1 = (OOC_INT32)string;
  i1 = (OOC_INT32)Object__String8Desc_CharsLatin1((Object__String8)i1);
  chars = (Object__CharsLatin1)i1;
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i1, 5891)), 0);
  i1 = (OOC_INT32)Msg__GetStringPtr((void*)(_check_pointer(i1, 5891)), i2);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5839)))), Msg__MsgDesc_SetStringAttrib)),Msg__MsgDesc_SetStringAttrib)((Msg__Msg)i0, "string", 7, (Msg__StringPtr)i1);
  i1 = number;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5903)))), Msg__MsgDesc_SetIntAttrib)),Msg__MsgDesc_SetIntAttrib)((Msg__Msg)i0, "number", 7, i1);
  return (Msg__Msg)i0;
  ;
}

void Config_Source_CmdLine__CommandDesc_DoNotWrite(Config_Source_CmdLine__Command command) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)command;
  *(OOC_UINT8*)((_check_pointer(i0, 6126))+12) = 1u;
  return;
  ;
}

static void Config_Source_CmdLine__Init(Config_Source_CmdLine__CmdLine cmdLine) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)cmdLine;
  Config_Source__Init((Config_Source__Source)i0);
  *(OOC_INT32*)(_check_pointer(i0, 6248)) = 0;
  *(OOC_UINT8*)((_check_pointer(i0, 6285))+4) = 1u;
  *(OOC_UINT8*)((_check_pointer(i0, 6322))+5) = 1u;
  *(OOC_UINT8*)((_check_pointer(i0, 6363))+6) = 1u;
  *(OOC_INT32*)((_check_pointer(i0, 6411))+8) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 6444))+12) = 0;
  return;
  ;
}

Config_Source_CmdLine__CmdLine Config_Source_CmdLine__New(void) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)RT0__NewObject(_td_Config_Source_CmdLine__CmdLine.baseTypes[0]);
  Config_Source_CmdLine__Init((Config_Source_CmdLine__CmdLine)i0);
  return (Config_Source_CmdLine__CmdLine)i0;
  ;
}

Config_Source_CmdLine__OptionTemplate Config_Source_CmdLine__CmdLineDesc_AddOptionTemplate(Config_Source_CmdLine__CmdLine cmdLine, const OOC_CHAR8 names__ref[], OOC_LEN names_0d, const OOC_CHAR8 transformation__ref[], OOC_LEN transformation_0d) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
  OOC_ALLOCATE_VPAR(names,OOC_CHAR8 ,names_0d)
  OOC_ALLOCATE_VPAR(transformation,OOC_CHAR8 ,transformation_0d)
  Config_Source_CmdLine__OptionTemplate opt;
  OOC_INT16 i;
  OOC_INT32 num;
  Config_Source_CmdLine__NameArray nameArray;
  auto void Config_Source_CmdLine__CmdLineDesc_AddOptionTemplate_Append(Config_Source_CmdLine__OptionTemplate *list);
    
    void Config_Source_CmdLine__CmdLineDesc_AddOptionTemplate_Append(Config_Source_CmdLine__OptionTemplate *list) {
      register OOC_INT32 i0,i1;

      i0 = (OOC_INT32)*list;
      i1 = i0==(OOC_INT32)0;
      if (i1) goto l3;
      Config_Source_CmdLine__CmdLineDesc_AddOptionTemplate_Append((void*)(_check_pointer(i0, 8900)));
      goto l4;
l3:
      i0 = (OOC_INT32)opt;
      *list = (Config_Source_CmdLine__OptionTemplate)i0;
l4:
      return;
      ;
    }


  OOC_INITIALIZE_VPAR(names__ref,names,OOC_CHAR8 ,names_0d)
  OOC_INITIALIZE_VPAR(transformation__ref,transformation,OOC_CHAR8 ,transformation_0d)
  i0 = (OOC_INT32)RT0__NewObject(_td_Config_Source_CmdLine__OptionTemplate.baseTypes[0]);
  opt = (Config_Source_CmdLine__OptionTemplate)i0;
  *(OOC_INT32*)(_check_pointer(i0, 8965)) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 8987))+4) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 9010))+8) = 0;
  i1 = (OOC_INT32)Object__NewLatin1((void*)(OOC_INT32)transformation, transformation_0d);
  *(OOC_INT32*)((_check_pointer(i0, 9035))+12) = i1;
  i = 0;
  i1 = *(OOC_UINT8*)((OOC_INT32)transformation+(_check_index(0, transformation_0d, OOC_UINT16, 9202)));
  i1 = i1!=0u;
  if (!i1) goto l27;
  i1=0;
l3_loop:
  i2 = *(OOC_UINT8*)((OOC_INT32)transformation+(_check_index(i1, transformation_0d, OOC_UINT16, 9239)));
  i2 = i2==36u;
  if (i2) goto l6;
  i2=0u;
  goto l8;
l6:
  i2 = *(OOC_UINT8*)((OOC_INT32)transformation+(_check_index((i1+1), transformation_0d, OOC_UINT16, 9284)));
  i2 = (OOC_UINT8)49u<=(OOC_UINT8)i2;
  
l8:
  if (i2) goto l10;
  i2=0u;
  goto l12;
l10:
  i2 = *(OOC_UINT8*)((OOC_INT32)transformation+(_check_index((i1+1), transformation_0d, OOC_UINT16, 9308)));
  i2 = (OOC_UINT8)i2<=(OOC_UINT8)57u;
  
l12:
  if (i2) goto l14;
  i1 = i1+1;
  i = i1;
  
  goto l22;
l14:
  i2 = *(OOC_UINT8*)((OOC_INT32)transformation+(_check_index((i1+1), transformation_0d, OOC_UINT16, 9361)));
  i2 = i2-48;
  num = i2;
  i3 = i2>0;
  if (i3) goto l17;
  i3=0u;
  goto l19;
l17:
  i3 = *(OOC_INT32*)((_check_pointer(i0, 9412))+8);
  i3 = i2>i3;
  
l19:
  if (!i3) goto l21;
  *(OOC_INT32*)((_check_pointer(i0, 9443))+8) = i2;
l21:
  i1 = i1+2;
  i = i1;
  
l22:
  i2 = *(OOC_UINT8*)((OOC_INT32)transformation+(_check_index(i1, transformation_0d, OOC_UINT16, 9202)));
  i2 = i2!=0u;
  if (i2) goto l3_loop;
l27:
  i = 0;
  i1 = *(OOC_UINT8*)((OOC_INT32)names+(_check_index(0, names_0d, OOC_UINT16, 9705)));
  i1 = i1!=0u;
  if (i1) goto l30;
  i1=1;
  goto l40;
l30:
  i1=0;i2=1;
l31_loop:
  i3 = *(OOC_UINT8*)((OOC_INT32)names+(_check_index(i1, names_0d, OOC_UINT16, 9733)));
  i3 = i3==44u;
  if (!i3) goto l35;
  i2 = i2+1;
  
l35:
  i1 = i1+1;
  i = i1;
  i3 = *(OOC_UINT8*)((OOC_INT32)names+(_check_index(i1, names_0d, OOC_UINT16, 9705)));
  i3 = i3!=0u;
  if (i3) goto l31_loop;
l39:
  i1=i2;
l40:
  i1 = (OOC_INT32)RT0__NewObject(_td_Config_Source_CmdLine__NameArray.baseTypes[0], i1);
  nameArray = (Config_Source_CmdLine__NameArray)i1;
  num = 0;
  i2 = (
  _cmp8((const void*)(OOC_INT32)names,(const void*)""))!=0;
  if (!i2) goto l69;
  i2=0;
l43_loop:
  i = 0;
  i3 = *(OOC_UINT8*)((OOC_INT32)names+(_check_index(0, names_0d, OOC_UINT16, 9904)));
  i3 = i3!=0u;
  if (i3) goto l46;
  i3=0u;
  goto l48;
l46:
  i3 = *(OOC_UINT8*)((OOC_INT32)names+(_check_index(0, names_0d, OOC_UINT16, 9922)));
  i3 = i3!=44u;
  
l48:
  if (i3) goto l50;
  i3=0;
  goto l60;
l50:
  i3=0;
l51_loop:
  i3 = i3+1;
  i = i3;
  i4 = *(OOC_UINT8*)((OOC_INT32)names+(_check_index(i3, names_0d, OOC_UINT16, 9904)));
  i4 = i4!=0u;
  if (i4) goto l54;
  i4=0u;
  goto l56;
l54:
  i4 = *(OOC_UINT8*)((OOC_INT32)names+(_check_index(i3, names_0d, OOC_UINT16, 9922)));
  i4 = i4!=44u;
  
l56:
  if (i4) goto l51_loop;
l60:
  i4 = *(OOC_UINT8*)((OOC_INT32)names+(_check_index(i3, names_0d, OOC_UINT16, 9978)));
  i4 = i4==0u;
  if (i4) goto l63;
  *(OOC_UINT8*)((OOC_INT32)names+(_check_index(i3, names_0d, OOC_UINT16, 10091))) = 0u;
  i4 = _check_pointer(i1, 10119);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i6 = (OOC_INT32)Object__NewLatin1((void*)(OOC_INT32)names, names_0d);
  *(OOC_INT32*)(i4+(_check_index(i2, i5, OOC_UINT32, 10119))*4) = i6;
  *(OOC_UINT8*)((OOC_INT32)names+(_check_index(i3, names_0d, OOC_UINT16, 10166))) = 44u;
  Strings__Delete((void*)(OOC_INT32)names, names_0d, 0, (i3+1));
  goto l64;
l63:
  i3 = _check_pointer(i1, 10010);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i5 = (OOC_INT32)Object__NewLatin1((void*)(OOC_INT32)names, names_0d);
  *(OOC_INT32*)(i3+(_check_index(i2, i4, OOC_UINT32, 10010))*4) = i5;
  *(OOC_UINT8*)((OOC_INT32)names+(_check_index(0, names_0d, OOC_UINT8, 10057))) = 0u;
l64:
  i2 = i2+1;
  num = i2;
  i3 = (
  _cmp8((const void*)(OOC_INT32)names,(const void*)""))!=0;
  if (i3) goto l43_loop;
l69:
  *(OOC_INT32*)((_check_pointer(i0, 10260))+4) = i1;
  i0 = (OOC_INT32)cmdLine;
  Config_Source_CmdLine__CmdLineDesc_AddOptionTemplate_Append((void*)(_check_pointer(i0, 10301)));
  i0 = (OOC_INT32)opt;
  return (Config_Source_CmdLine__OptionTemplate)i0;
  ;
}

void Config_Source_CmdLine__CmdLineDesc_EnableDashDash(Config_Source_CmdLine__CmdLine cmdLine, OOC_CHAR8 enable) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)cmdLine;
  i1 = enable;
  *(OOC_UINT8*)((_check_pointer(i0, 10774))+4) = i1;
  return;
  ;
}

void Config_Source_CmdLine__CmdLineDesc_EnableExpandToSingleChar(Config_Source_CmdLine__CmdLine cmdLine, OOC_CHAR8 enable) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)cmdLine;
  i1 = enable;
  *(OOC_UINT8*)((_check_pointer(i0, 11187))+5) = i1;
  return;
  ;
}

void Config_Source_CmdLine__CmdLineDesc_OptionsStartWithDash(Config_Source_CmdLine__CmdLine cmdLine, OOC_CHAR8 enable) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)cmdLine;
  i1 = enable;
  *(OOC_UINT8*)((_check_pointer(i0, 11687))+6) = i1;
  return;
  ;
}

Msg__Msg Config_Source_CmdLine__CmdLineDesc_Parse(Config_Source_CmdLine__CmdLine cmdLine, Channel__Channel ch) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8;
  OOC_INT32 numArgs;
  Config_Source_CmdLine__ArgList argList;
  TextRider__Reader r;
  OOC_CHAR8 argString[2048];
  OOC_INT32 restArg;
  OOC_INT32 i;
  Object__String8 arg;
  Config_Source_CmdLine__OptionTemplate cmd;
  Msg__Msg msg;
  OOC_CHAR8 singleCharCmd[3];
  Object__CharsLatin1 chars;
  OOC_INT32 j;
  Object__String8 singleOption;
  auto void Config_Source_CmdLine__CmdLineDesc_Parse_Append(OOC_CHAR8 arg[], OOC_LEN arg_0d);
  auto Config_Source_CmdLine__OptionTemplate Config_Source_CmdLine__CmdLineDesc_Parse_FindOptionTemplate(Object__String8 name);
  auto Msg__Msg Config_Source_CmdLine__CmdLineDesc_Parse_EvalOption(Object__String8 argString, Config_Source_CmdLine__OptionTemplate cmd, OOC_INT32 *optIndex);
    
    void Config_Source_CmdLine__CmdLineDesc_Parse_Append(OOC_CHAR8 arg[], OOC_LEN arg_0d) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8;
      Config_Source_CmdLine__ArgList newList;
      OOC_INT32 i;

      i0 = (OOC_INT32)argList;
      i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 13847)), 0);
      i2 = numArgs;
      i1 = i2==i1;
      if (!i1) goto l20;
      i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 13890)), 0);
      i1 = (OOC_INT32)RT0__NewObject(_td_Config_Source_CmdLine__ArgList.baseTypes[0], (i1*2));
      newList = (Config_Source_CmdLine__ArgList)i1;
      i = 0;
      i3 = OOC_ARRAY_LENGTH((_check_pointer(i0, 13931)), 0);
      i4 = 0<i3;
      if (!i4) goto l11;
      i4=0;
l6_loop:
      i5 = _check_pointer(i1, 13956);
      i6 = OOC_ARRAY_LENGTH(i5, 0);
      i7 = _check_pointer(i0, 13970);
      i8 = OOC_ARRAY_LENGTH(i7, 0);
      i7 = (OOC_INT32)*(OOC_INT32*)(i7+(_check_index(i4, i8, OOC_UINT32, 13970))*4);
      *(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 13956))*4) = i7;
      i4 = i4+1;
      i = i4;
      i5 = i4<i3;
      if (i5) goto l6_loop;
l11:
      i3 = OOC_ARRAY_LENGTH((_check_pointer(i0, 14016)), 0);
      i0 = OOC_ARRAY_LENGTH((_check_pointer(i0, 14034)), 0);
      i = i3;
      i0 = i0*2;
      i4 = i3<i0;
      if (!i4) goto l19;
l14_loop:
      i4 = _check_pointer(i1, 14061);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      *(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 14061))*4) = (OOC_INT32)0;
      i3 = i3+1;
      i = i3;
      i4 = i3<i0;
      if (i4) goto l14_loop;
l19:
      argList = (Config_Source_CmdLine__ArgList)i1;
      i0=i1;
l20:
      i0 = _check_pointer(i0, 14137);
      i1 = OOC_ARRAY_LENGTH(i0, 0);
      i3 = (OOC_INT32)Object__NewLatin1((void*)(OOC_INT32)arg, arg_0d);
      i4 = numArgs;
      *(OOC_INT32*)(i0+(_check_index(i2, i1, OOC_UINT32, 14137))*4) = i3;
      numArgs = (i4+1);
      return;
      ;
    }

    
    Config_Source_CmdLine__OptionTemplate Config_Source_CmdLine__CmdLineDesc_Parse_FindOptionTemplate(Object__String8 name) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5;
      Config_Source_CmdLine__OptionTemplate o;
      OOC_INT32 i;

      i0 = (OOC_INT32)cmdLine;
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 14362));
      o = (Config_Source_CmdLine__OptionTemplate)i0;
      i1 = i0!=0;
      if (!i1) goto l19;
      i1 = (OOC_INT32)name;
      
l3_loop:
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14434))+4);
      i = 0;
      i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 14441)), 0);
      i3 = 0<i2;
      if (!i3) goto l14;
      i3=0;
l6_loop:
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14463))+4);
      i4 = _check_pointer(i4, 14469);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 14469))*4);
      i4 = Object__String8Desc_Equals((Object__String8)i4, (Object__Object)i1);
      if (!i4) goto l9;
      return (Config_Source_CmdLine__OptionTemplate)i0;
l9:
      i3 = i3+1;
      i = i3;
      i4 = i3<i2;
      if (i4) goto l6_loop;
l14:
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 14553));
      o = (Config_Source_CmdLine__OptionTemplate)i0;
      i2 = i0!=0;
      if (i2) goto l3_loop;
l19:
      return (Config_Source_CmdLine__OptionTemplate)0;
      ;
    }

    
    Msg__Msg Config_Source_CmdLine__CmdLineDesc_Parse_EvalOption(Object__String8 argString, Config_Source_CmdLine__OptionTemplate cmd, OOC_INT32 *optIndex) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8,i9,i10;
      Config_Source_CmdLine__Command command;
      OOC_INT32 i;
      auto void Config_Source_CmdLine__CmdLineDesc_Parse_EvalOption_Append(Config_Source_CmdLine__Command *list);
        
        void Config_Source_CmdLine__CmdLineDesc_Parse_EvalOption_Append(Config_Source_CmdLine__Command *list) {
          register OOC_INT32 i0,i1;

          i0 = (OOC_INT32)*list;
          i1 = i0==(OOC_INT32)0;
          if (i1) goto l3;
          Config_Source_CmdLine__CmdLineDesc_Parse_EvalOption_Append((void*)(_check_pointer(i0, 14947)));
          goto l4;
l3:
          i0 = (OOC_INT32)command;
          *list = (Config_Source_CmdLine__Command)i0;
l4:
          return;
          ;
        }


      i0 = (OOC_INT32)cmd;
      i1 = *(OOC_INT32*)((_check_pointer(i0, 15029))+8);
      i2 = *optIndex;
      i3 = numArgs;
      i1 = (i2+i1)>=i3;
      if (i1) goto l11;
      i1 = (OOC_INT32)RT0__NewObject(_td_Config_Source_CmdLine__Command.baseTypes[0]);
      command = (Config_Source_CmdLine__Command)i1;
      *(OOC_INT32*)(_check_pointer(i1, 15182)) = 0;
      *(OOC_INT32*)((_check_pointer(i1, 15219))+4) = i0;
      *(OOC_UINT8*)((_check_pointer(i1, 15253))+12) = 0u;
      i3 = *(OOC_INT32*)((_check_pointer(i0, 15310))+8);
      *(OOC_INT32*)((_check_pointer(i1, 15296))+8) = ((OOC_INT32)RT0__NewObject(_td_Config_Source_CmdLine__ArgList.baseTypes[0], i3));
      i = 0;
      i3 = *(OOC_INT32*)((_check_pointer(i0, 15349))+8);
      i4 = 0<i3;
      if (!i4) goto l10;
      i4 = (OOC_INT32)argList;
      i5 = i2+1;
      i6=i5;i5=0;
l5_loop:
      i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 15383))+8);
      i7 = _check_pointer(i7, 15392);
      i8 = OOC_ARRAY_LENGTH(i7, 0);
      i9 = _check_pointer(i4, 15406);
      i10 = OOC_ARRAY_LENGTH(i9, 0);
      i9 = (OOC_INT32)*(OOC_INT32*)(i9+(_check_index(i6, i10, OOC_UINT32, 15406))*4);
      *(OOC_INT32*)(i7+(_check_index(i5, i8, OOC_UINT32, 15392))*4) = i9;
      i5 = i5+1;
      i = i5;
      i6 = i6+1;
      i7 = i5<i3;
      if (i7) goto l5_loop;
l10:
      i0 = *(OOC_INT32*)((_check_pointer(i0, 15460))+8);
      *optIndex = (i2+i0);
      i0 = (OOC_INT32)cmdLine;
      Config_Source_CmdLine__CmdLineDesc_Parse_EvalOption_Append((void*)((_check_pointer(i0, 15497))+8));
      return (Msg__Msg)0;
      goto l12;
l11:
      i0 = *(OOC_INT32*)((_check_pointer(i0, 15120))+8);
      i1 = (OOC_INT32)argString;
      i0 = (OOC_INT32)Config_Source_CmdLine__ErrorStringNum(6, (Object__String8)i1, i0);
      return (Msg__Msg)i0;
l12:
      _failed_function(14631); return 0;
      ;
    }


  numArgs = 0;
  argList = (Config_Source_CmdLine__ArgList)((OOC_INT32)RT0__NewObject(_td_Config_Source_CmdLine__ArgList.baseTypes[0], 8));
  i0 = (OOC_INT32)ch;
  i0 = (OOC_INT32)TextRider__ConnectReader((Channel__Channel)i0);
  r = (TextRider__Reader)i0;
  i1 = i0==(OOC_INT32)0;
  if (i1) goto l25;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 15800));
  i0 = i0==(OOC_INT32)0;
  if (!i0) goto l13;
l5_loop:
  i0 = (OOC_INT32)r;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 15834)))), TextRider__ReaderDesc_ReadLine)),TextRider__ReaderDesc_ReadLine)((TextRider__Reader)i0, (void*)(OOC_INT32)argString, 2048);
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 15871));
  i0 = i0==(OOC_INT32)0;
  if (!i0) goto l8;
  Config_Source_CmdLine__CmdLineDesc_Parse_Append((void*)(OOC_INT32)argString, 2048);
l8:
  i0 = (OOC_INT32)r;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 15800));
  i0 = i0==(OOC_INT32)0;
  if (i0) goto l5_loop;
l13:
  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 15961));
  i1 = *(OOC_INT32*)((_check_pointer(i1, 15966))+8);
  i1 = i1==5;
  if (i1) goto l16;
  i1=0u;
  goto l18;
l16:
  i1 = *(OOC_UINT8*)((OOC_INT32)argString+(_check_index(0, 2048, OOC_UINT8, 16009)));
  i1 = i1!=0u;
  
l18:
  if (i1) goto l23;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 16074));
  i1 = *(OOC_INT32*)((_check_pointer(i1, 16079))+8);
  i1 = i1!=5;
  if (!i1) goto l26;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 16155));
  i0 = (OOC_INT32)Config_Source_CmdLine__ErrorReason(3, (Msg__Msg)i0);
  return (Msg__Msg)i0;
  goto l26;
l23:
  i0 = (OOC_INT32)Config_Source_CmdLine__Error(2);
  return (Msg__Msg)i0;
  goto l26;
l25:
  i0 = (OOC_INT32)Config_Source_CmdLine__Error(1);
  return (Msg__Msg)i0;
l26:
  restArg = (-1);
  i = 1;
  i0 = numArgs;
  i0 = 1<i0;
  if (i0) goto l29;
  i0=0u;
  goto l31;
l29:
  i0=1u;
l31:
  if (!i0) goto l96;
  i0 = (OOC_INT32)_c0;
  i1=1;
l33_loop:
  i2 = (OOC_INT32)argList;
  i2 = _check_pointer(i2, 16379);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i1 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(i1, i3, OOC_UINT32, 16379))*4);
  arg = (Object__String8)i1;
  i1 = (OOC_INT32)Config_Source_CmdLine__CmdLineDesc_Parse_FindOptionTemplate((Object__String8)i1);
  cmd = (Config_Source_CmdLine__OptionTemplate)i1;
  i2 = i1!=(OOC_INT32)0;
  if (i2) goto l83;
  i1 = (OOC_INT32)cmdLine;
  i2 = *(OOC_UINT8*)((_check_pointer(i1, 16652))+4);
  if (i2) goto l38;
  i2=0u;
  goto l40;
l38:
  i2 = (OOC_INT32)arg;
  i2 = Object__String8Desc_Equals((Object__String8)i2, (Object__Object)i0);
  
l40:
  if (i2) goto l81;
  i2 = *(OOC_UINT8*)((_check_pointer(i1, 16757))+5);
  if (i2) goto l44;
  i2=0u;
  goto l46;
l44:
  i2 = (OOC_INT32)arg;
  i2 = Object__String8Desc_CharAt((Object__String8)i2, 0);
  i2 = i2==45u;
  
l46:
  if (i2) goto l48;
  i2=0u;
  goto l50;
l48:
  i2 = (OOC_INT32)arg;
  i2 = Object__String8Desc_CharAt((Object__String8)i2, 1);
  i2 = i2!=45u;
  
l50:
  if (i2) goto l60;
  i1 = *(OOC_UINT8*)((_check_pointer(i1, 17671))+6);
  if (i1) goto l54;
  i1=0u;
  goto l56;
l54:
  i1 = (OOC_INT32)arg;
  i1 = Object__String8Desc_CharAt((Object__String8)i1, 0);
  i1 = i1==45u;
  
l56:
  if (i1) goto l58;
  i1 = i;
  restArg = i1;
  goto l87;
l58:
  i1 = (OOC_INT32)arg;
  i1 = (OOC_INT32)Config_Source_CmdLine__ErrorString(4, (Object__String8)i1);
  return (Msg__Msg)i1;
  goto l87;
l60:
  _copy_8((const void*)"-?",(void*)(OOC_INT32)singleCharCmd,3);
  i1 = (OOC_INT32)arg;
  i1 = (OOC_INT32)Object__String8Desc_CharsLatin1((Object__String8)i1);
  chars = (Object__CharsLatin1)i1;
  j = 1;
  i1 = _check_pointer(i1, 17049);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i1 = *(OOC_UINT8*)(i1+(_check_index(1, i2, OOC_UINT32, 17049)));
  i1 = i1!=0u;
  if (!i1) goto l87;
  i1=1;
l63_loop:
  i2 = (OOC_INT32)chars;
  i2 = _check_pointer(i2, 17097);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i1 = *(OOC_UINT8*)(i2+(_check_index(i1, i3, OOC_UINT32, 17097)));
  *(OOC_UINT8*)((OOC_INT32)singleCharCmd+(_check_index(1, 3, OOC_UINT8, 17085))) = i1;
  i1 = (OOC_INT32)Object__NewLatin1((void*)(OOC_INT32)singleCharCmd, 3);
  singleOption = (Object__String8)i1;
  i1 = (OOC_INT32)Config_Source_CmdLine__CmdLineDesc_Parse_FindOptionTemplate((Object__String8)i1);
  cmd = (Config_Source_CmdLine__OptionTemplate)i1;
  i2 = i1==(OOC_INT32)0;
  if (i2) goto l73;
  i2 = *(OOC_INT32*)((_check_pointer(i1, 17323))+8);
  i2 = i2!=0;
  if (i2) goto l71;
  i2 = (OOC_INT32)singleOption;
  i1 = (OOC_INT32)Config_Source_CmdLine__CmdLineDesc_Parse_EvalOption((Object__String8)i2, (Config_Source_CmdLine__OptionTemplate)i1, (void*)(OOC_INT32)&i);
  msg = (Msg__Msg)i1;
  i2 = i1!=(OOC_INT32)0;
  if (!i2) goto l74;
  return (Msg__Msg)i1;
  goto l74;
l71:
  i1 = *(OOC_INT32*)((_check_pointer(i1, 17452))+8);
  i2 = (OOC_INT32)singleOption;
  i1 = (OOC_INT32)Config_Source_CmdLine__ErrorStringNum(5, (Object__String8)i2, i1);
  return (Msg__Msg)i1;
  goto l74;
l73:
  i1 = (OOC_INT32)singleOption;
  i1 = (OOC_INT32)Config_Source_CmdLine__ErrorString(4, (Object__String8)i1);
  return (Msg__Msg)i1;
l74:
  i1 = j;
  i1 = i1+1;
  j = i1;
  i2 = (OOC_INT32)chars;
  i2 = _check_pointer(i2, 17049);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i2 = *(OOC_UINT8*)(i2+(_check_index(i1, i3, OOC_UINT32, 17049)));
  i2 = i2!=0u;
  if (i2) goto l63_loop;
  goto l87;
l81:
  i1 = i;
  restArg = (i1+1);
  goto l87;
l83:
  i2 = (OOC_INT32)arg;
  i1 = (OOC_INT32)Config_Source_CmdLine__CmdLineDesc_Parse_EvalOption((Object__String8)i2, (Config_Source_CmdLine__OptionTemplate)i1, (void*)(OOC_INT32)&i);
  msg = (Msg__Msg)i1;
  i2 = i1!=(OOC_INT32)0;
  if (!i2) goto l87;
  return (Msg__Msg)i1;
l87:
  i1 = i;
  i1 = i1+1;
  i = i1;
  i2 = numArgs;
  i2 = i1<i2;
  if (i2) goto l90;
  i2=0u;
  goto l92;
l90:
  i2 = restArg;
  i2 = i2<0;
  
l92:
  if (i2) goto l33_loop;
l96:
  i0 = restArg;
  i1 = numArgs;
  i0 = i0<0;
  if (!i0) goto l99;
  restArg = i1;
l99:
  i0 = restArg;
  i2 = (OOC_INT32)cmdLine;
  *(OOC_INT32*)((_check_pointer(i2, 18035))+12) = ((OOC_INT32)RT0__NewObject(_td_Config_Source_CmdLine__ArgList.baseTypes[0], (i1-i0)));
  i = i0;
  i3 = i0<i1;
  if (!i3) goto l107;
  i3 = (OOC_INT32)argList;
  i4 = (i0*(-1))+i0;
  
l102_loop:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 18119))+12);
  i5 = _check_pointer(i5, 18133);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i7 = _check_pointer(i3, 18155);
  i8 = OOC_ARRAY_LENGTH(i7, 0);
  i7 = (OOC_INT32)*(OOC_INT32*)(i7+(_check_index(i0, i8, OOC_UINT32, 18155))*4);
  *(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 18133))*4) = i7;
  i0 = i0+1;
  i = i0;
  i4 = i4+1;
  i5 = i0<i1;
  if (i5) goto l102_loop;
l107:
  return (Msg__Msg)(OOC_INT32)0;
  ;
}

void Config_Source_CmdLine__CmdLineDesc_Write(Config_Source_CmdLine__CmdLine cmdLine, IO__ByteChannel ch, const Config_Parser__String rootTag__ref, OOC_LEN rootTag_0d) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  OOC_ALLOCATE_VPAR(rootTag,OOC_CHAR16 ,rootTag_0d)
  IO_TextRider__Writer w;
  OOC_CHAR8 root8[1024];
  Config_Source_CmdLine__Command command;
  Object__String8 pattern;
  Object__CharsLatin1 chars;
  OOC_INT32 i;
  OOC_INT32 j;
  auto void Config_Source_CmdLine__CmdLineDesc_Write_WriteQuoted(IO_TextRider__Writer w, Object__String8 str);
    
    void Config_Source_CmdLine__CmdLineDesc_Write_WriteQuoted(IO_TextRider__Writer w, Object__String8 str) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
      Object__CharsLatin1 chars;
      OOC_INT32 s;
      OOC_INT32 e;
      OOC_INT32 last;

      i0 = (OOC_INT32)str;
      i1 = (OOC_INT32)Object__String8Desc_CharsLatin1((Object__String8)i0);
      chars = (Object__CharsLatin1)i1;
      s = 0;
      i0 = *(OOC_INT32*)(_check_pointer(i0, 20138));
      e = i0;
      i2 = 0!=i0;
      if (!i2) goto l69;
      i3 = (OOC_INT32)w;
      i4=i2;i2=0;
l3_loop:
      last = i2;
      if (i4) goto l6;
      i4=0u;
      goto l8;
l6:
      i4 = _check_pointer(i1, 20219);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      i4 = *(OOC_UINT8*)(i4+(_check_index(i2, i5, OOC_UINT32, 20219)));
      i4 = i4!=38u;
      
l8:
      if (i4) goto l10;
      i4=0u;
      goto l12;
l10:
      i4 = _check_pointer(i1, 20252);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      i4 = *(OOC_UINT8*)(i4+(_check_index(i2, i5, OOC_UINT32, 20252)));
      i4 = i4!=60u;
      
l12:
      if (i4) goto l14;
      i4=0u;
      goto l16;
l14:
      i4 = _check_pointer(i1, 20271);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      i4 = *(OOC_UINT8*)(i4+(_check_index(i2, i5, OOC_UINT32, 20271)));
      i4 = i4!=62u;
      
l16:
      if (i4) goto l18;
      i4=0u;
      goto l20;
l18:
      i4 = _check_pointer(i1, 20304);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      i4 = *(OOC_UINT8*)(i4+(_check_index(i2, i5, OOC_UINT32, 20304)));
      i4 = i4!=39u;
      
l20:
      if (i4) goto l22;
      i4=0u;
      goto l24;
l22:
      i4 = _check_pointer(i1, 20323);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      i4 = *(OOC_UINT8*)(i4+(_check_index(i2, i5, OOC_UINT32, 20323)));
      i4 = i4!=34u;
      
l24:
      if (i4) goto l26;
      i4=i2;
      goto l52;
l26:
      i4=i2;
l27_loop:
      i4 = i4+1;
      s = i4;
      i5 = i4!=i0;
      if (i5) goto l30;
      i5=0u;
      goto l32;
l30:
      i5 = _check_pointer(i1, 20219);
      i6 = OOC_ARRAY_LENGTH(i5, 0);
      i5 = *(OOC_UINT8*)(i5+(_check_index(i4, i6, OOC_UINT32, 20219)));
      i5 = i5!=38u;
      
l32:
      if (i5) goto l34;
      i5=0u;
      goto l36;
l34:
      i5 = _check_pointer(i1, 20252);
      i6 = OOC_ARRAY_LENGTH(i5, 0);
      i5 = *(OOC_UINT8*)(i5+(_check_index(i4, i6, OOC_UINT32, 20252)));
      i5 = i5!=60u;
      
l36:
      if (i5) goto l38;
      i5=0u;
      goto l40;
l38:
      i5 = _check_pointer(i1, 20271);
      i6 = OOC_ARRAY_LENGTH(i5, 0);
      i5 = *(OOC_UINT8*)(i5+(_check_index(i4, i6, OOC_UINT32, 20271)));
      i5 = i5!=62u;
      
l40:
      if (i5) goto l42;
      i5=0u;
      goto l44;
l42:
      i5 = _check_pointer(i1, 20304);
      i6 = OOC_ARRAY_LENGTH(i5, 0);
      i5 = *(OOC_UINT8*)(i5+(_check_index(i4, i6, OOC_UINT32, 20304)));
      i5 = i5!=39u;
      
l44:
      if (i5) goto l46;
      i5=0u;
      goto l48;
l46:
      i5 = _check_pointer(i1, 20323);
      i6 = OOC_ARRAY_LENGTH(i5, 0);
      i5 = *(OOC_UINT8*)(i5+(_check_index(i4, i6, OOC_UINT32, 20323)));
      i5 = i5!=34u;
      
l48:
      if (i5) goto l27_loop;
l52:
      i5 = OOC_ARRAY_LENGTH((_check_pointer(i1, 20403)), 0);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 20377)))), IO_TextRider__WriterDesc_WriteStringRegion)),IO_TextRider__WriterDesc_WriteStringRegion)((IO_TextRider__Writer)i3, (void*)(_check_pointer(i1, 20403)), i5, i2, i4);
      i2 = i4!=i0;
      if (i2) goto l55;
      i2=i4;
      goto l64;
l55:
      i2 = _check_pointer(i1, 20460);
      i5 = OOC_ARRAY_LENGTH(i2, 0);
      i2 = *(OOC_UINT8*)(i2+(_check_index(i4, i5, OOC_UINT32, 20460)));
      switch (i2) {
      case 38u:
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 20485)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i3, "&amp;", 6);
        goto l63;
      case 60u:
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 20527)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i3, "&lt;", 5);
        goto l63;
      case 62u:
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 20568)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i3, "&gt;", 5);
        goto l63;
      case 39u:
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 20609)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i3, "&apos;", 7);
        goto l63;
      case 34u:
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 20652)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i3, "&quot;", 7);
        goto l63;
      default:
        _failed_case(i2, 20450);
        goto l63;
      }
l63:
      i2 = i4+1;
      s = i2;
      
l64:
      i4 = i2!=i0;
      if (i4) goto l3_loop;
l69:
      return;
      ;
    }


  OOC_INITIALIZE_VPAR(rootTag__ref,rootTag,OOC_CHAR16 ,(rootTag_0d*2))
  i0 = (OOC_INT32)ch;
  i0 = (OOC_INT32)IO_TextRider__ConnectWriter((IO__ByteChannel)i0);
  w = (IO_TextRider__Writer)i0;
  i1 = (
  _cmp16((const void*)(OOC_INT32)rootTag,(const void*)((OOC_CHAR16[]){0})))!=0;
  if (!i1) goto l3;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 20911)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, "<?xml version=\0471.0\047 encoding=\047ISO-8859-1\047 standalone=\047yes\047?>", 61);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 20998)))), IO_TextRider__WriterDesc_WriteLn)),IO_TextRider__WriterDesc_WriteLn)((IO_TextRider__Writer)i0);
  LongStrings__Short((void*)(OOC_INT32)rootTag, rootTag_0d, 63u, (void*)(OOC_INT32)root8, 1024);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 21063)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, "<", 2);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 21091)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, (void*)(OOC_INT32)root8, 1024);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 21121)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, ">", 2);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 21149)))), IO_TextRider__WriterDesc_WriteLn)),IO_TextRider__WriterDesc_WriteLn)((IO_TextRider__Writer)i0);
l3:
  i0 = (OOC_INT32)cmdLine;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21195))+8);
  command = (Config_Source_CmdLine__Command)i0;
  i1 = i0!=(OOC_INT32)0;
  if (!i1) goto l51;
l6_loop:
  i1 = *(OOC_UINT8*)((_check_pointer(i0, 21256))+12);
  i1 = !i1;
  if (!i1) goto l46;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21300))+4);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21310))+12);
  pattern = (Object__String8)i0;
  i0 = (OOC_INT32)Object__String8Desc_CharsLatin1((Object__String8)i0);
  chars = (Object__CharsLatin1)i0;
  i = 0;
  i0 = _check_pointer(i0, 21397);
  i1 = OOC_ARRAY_LENGTH(i0, 0);
  i0 = *(OOC_UINT8*)(i0+(_check_index(0, i1, OOC_UINT32, 21397)));
  i0 = i0!=0u;
  if (!i0) goto l45;
  i0=0;
l11_loop:
  j = i0;
  i1 = (OOC_INT32)chars;
  i2 = _check_pointer(i1, 21450);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i2 = *(OOC_UINT8*)(i2+(_check_index(i0, i3, OOC_UINT32, 21450)));
  i2 = i2!=0u;
  if (i2) goto l14;
  i2=0u;
  goto l16;
l14:
  i2 = _check_pointer(i1, 21468);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i2 = *(OOC_UINT8*)(i2+(_check_index(i0, i3, OOC_UINT32, 21468)));
  i2 = i2!=36u;
  
l16:
  if (i2) goto l18;
  i2=i0;
  goto l28;
l18:
  i2=i0;
l19_loop:
  i2 = i2+1;
  i = i2;
  i3 = _check_pointer(i1, 21450);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i3 = *(OOC_UINT8*)(i3+(_check_index(i2, i4, OOC_UINT32, 21450)));
  i3 = i3!=0u;
  if (i3) goto l22;
  i3=0u;
  goto l24;
l22:
  i3 = _check_pointer(i1, 21468);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i3 = *(OOC_UINT8*)(i3+(_check_index(i2, i4, OOC_UINT32, 21468)));
  i3 = i3!=36u;
  
l24:
  if (i3) goto l19_loop;
l28:
  i3 = _check_pointer(i1, 21537);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i3 = *(OOC_UINT8*)(i3+(_check_index(i2, i4, OOC_UINT32, 21537)));
  i3 = i3==36u;
  if (i3) goto l31;
  i3 = (OOC_INT32)w;
  i4 = OOC_ARRAY_LENGTH((_check_pointer(i1, 21924)), 0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 21899)))), IO_TextRider__WriterDesc_WriteStringRegion)),IO_TextRider__WriterDesc_WriteStringRegion)((IO_TextRider__Writer)i3, (void*)(_check_pointer(i1, 21924)), i4, i0, i2);
  i0=i2;
  goto l40;
l31:
  i3 = _check_pointer(i1, 21581);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i5 = i2+1;
  i3 = *(OOC_UINT8*)(i3+(_check_index(i5, i4, OOC_UINT32, 21581)));
  i3 = (OOC_UINT8)49u<=(OOC_UINT8)i3;
  if (i3) goto l34;
  i3=0u;
  goto l36;
l34:
  i3 = _check_pointer(i1, 21596);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i3 = *(OOC_UINT8*)(i3+(_check_index(i5, i4, OOC_UINT32, 21596)));
  i3 = (OOC_UINT8)i3<=(OOC_UINT8)57u;
  
l36:
  if (i3) goto l38;
  i = i5;
  i2 = (OOC_INT32)w;
  i3 = OOC_ARRAY_LENGTH((_check_pointer(i1, 21846)), 0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 21821)))), IO_TextRider__WriterDesc_WriteStringRegion)),IO_TextRider__WriterDesc_WriteStringRegion)((IO_TextRider__Writer)i2, (void*)(_check_pointer(i1, 21846)), i3, i0, i5);
  i0=i5;
  goto l40;
l38:
  i3 = (OOC_INT32)w;
  i4 = OOC_ARRAY_LENGTH((_check_pointer(i1, 21655)), 0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 21630)))), IO_TextRider__WriterDesc_WriteStringRegion)),IO_TextRider__WriterDesc_WriteStringRegion)((IO_TextRider__Writer)i3, (void*)(_check_pointer(i1, 21655)), i4, i0, i2);
  i0 = (OOC_INT32)command;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21702))+8);
  i0 = _check_pointer(i0, 21711);
  i1 = _check_pointer(i1, 21722);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i1 = *(OOC_UINT8*)(i1+(_check_index(i5, i2, OOC_UINT32, 21722)));
  i2 = OOC_ARRAY_LENGTH(i0, 0);
  i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index((i1-49), i2, OOC_UINT16, 21711))*4);
  Config_Source_CmdLine__CmdLineDesc_Write_WriteQuoted((IO_TextRider__Writer)i3, (Object__String8)i0);
  i0 = i;
  i0 = i0+2;
  i = i0;
  
l40:
  i1 = (OOC_INT32)chars;
  i1 = _check_pointer(i1, 21397);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i1 = *(OOC_UINT8*)(i1+(_check_index(i0, i2, OOC_UINT32, 21397)));
  i1 = i1!=0u;
  if (i1) goto l11_loop;
l45:
  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 21969)))), IO_TextRider__WriterDesc_WriteLn)),IO_TextRider__WriterDesc_WriteLn)((IO_TextRider__Writer)i0);
l46:
  i0 = (OOC_INT32)command;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 22014));
  command = (Config_Source_CmdLine__Command)i0;
  i1 = i0!=(OOC_INT32)0;
  if (i1) goto l6_loop;
l51:
  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 22047)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, "<arguments>", 12);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 22083)))), IO_TextRider__WriterDesc_WriteLn)),IO_TextRider__WriterDesc_WriteLn)((IO_TextRider__Writer)i0);
  i0 = (OOC_INT32)cmdLine;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22109))+12);
  i1 = i1!=(OOC_INT32)0;
  if (!i1) goto l62;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22168))+12);
  i = 0;
  i0 = OOC_ARRAY_LENGTH((_check_pointer(i0, 22182)), 0);
  i1 = 0<i0;
  if (!i1) goto l62;
  i1=0;
l56_loop:
  i2 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 22199)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i2, "  <arg>", 8);
  i3 = (OOC_INT32)cmdLine;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 22257))+12);
  i3 = _check_pointer(i3, 22271);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i1 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i1, i4, OOC_UINT32, 22271))*4);
  Config_Source_CmdLine__CmdLineDesc_Write_WriteQuoted((IO_TextRider__Writer)i2, (Object__String8)i1);
  i1 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 22286)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i1, "</arg>", 7);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 22321)))), IO_TextRider__WriterDesc_WriteLn)),IO_TextRider__WriterDesc_WriteLn)((IO_TextRider__Writer)i1);
  i1 = i;
  i1 = i1+1;
  i = i1;
  i2 = i1<i0;
  if (i2) goto l56_loop;
l62:
  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 22355)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, "</arguments>", 13);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 22392)))), IO_TextRider__WriterDesc_WriteLn)),IO_TextRider__WriterDesc_WriteLn)((IO_TextRider__Writer)i0);
  i1 = (
  _cmp16((const void*)(OOC_INT32)rootTag,(const void*)((OOC_CHAR16[]){0})))!=0;
  if (!i1) goto l65;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 22442)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, "</", 3);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 22471)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, (void*)(OOC_INT32)root8, 1024);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 22501)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, ">", 2);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 22529)))), IO_TextRider__WriterDesc_WriteLn)),IO_TextRider__WriterDesc_WriteLn)((IO_TextRider__Writer)i0);
l65:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22558))+4);
  i1 = i1!=(OOC_INT32)0;
  if (!i1) goto l68;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22590))+4);
  Exception__Raise((void*)i0);
l68:
  return;
  ;
}

void OOC_Config_Source_CmdLine_init(void) {
  register OOC_INT32 i0;
  _c0 = Object__NewLatin1Region("--", 3, 0, 2);

  i0 = (OOC_INT32)RT0__NewObject(_td_Config_Source_CmdLine__ErrorContext.baseTypes[0]);
  Config_Source_CmdLine__cmdLineContext = (Config_Source_CmdLine__ErrorContext)i0;
  Msg__InitContext((Msg__Context)i0, "Config:Source:CmdLine", 22);
  return;
  ;
}

/* --- */
