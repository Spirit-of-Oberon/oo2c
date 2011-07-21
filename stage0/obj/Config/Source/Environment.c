#include <Config/Source/Environment.d>
#include <__oo2c.h>
#include <setjmp.h>

static void Config_Source_Environment__Init(Config_Source_Environment__Environment env) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)env;
  Config_Source__Init((Config_Source__Source)i0);
  return;
  ;
}

Config_Source_Environment__Environment Config_Source_Environment__New(void) {
  register OOC_INT32 i0;
  Config_Source_Environment__Environment env;

  i0 = (OOC_INT32)RT0__NewObject(_td_Config_Source_Environment__Environment.baseTypes[0]);
  env = (Config_Source_Environment__Environment)i0;
  Config_Source_Environment__Init((Config_Source_Environment__Environment)i0);
  *(OOC_INT32*)(_check_pointer(i0, 1772)) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 1807))+4) = 0;
  return (Config_Source_Environment__Environment)i0;
  ;
}

void Config_Source_Environment__CommandDesc_DoNotWrite(Config_Source_Environment__Command command) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)command;
  *(OOC_UINT8*)((_check_pointer(i0, 2009))+12) = 1u;
  return;
  ;
}

void Config_Source_Environment__VariableTemplateDesc_INIT(Config_Source_Environment__VariableTemplate t, Object__String8 name, Object__String8 transformation, OOC_CHAR8 isList, OOC_CHAR8 listSep) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)t;
  *(OOC_INT32*)(_check_pointer(i0, 2210)) = 0;
  i1 = (OOC_INT32)name;
  *(OOC_INT32*)((_check_pointer(i0, 2229))+4) = i1;
  i1 = (OOC_INT32)transformation;
  *(OOC_INT32*)((_check_pointer(i0, 2249))+8) = i1;
  i1 = isList;
  *(OOC_UINT8*)((_check_pointer(i0, 2282))+12) = i1;
  i1 = listSep;
  *(OOC_UINT8*)((_check_pointer(i0, 2306))+13) = i1;
  return;
  ;
}

static void Config_Source_Environment__Append(Config_Source_Environment__VariableTemplate *list, Config_Source_Environment__VariableTemplate t) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)*list;
  i1 = i0==(OOC_INT32)0;
  if (i1) goto l3;
  i1 = (OOC_INT32)t;
  Config_Source_Environment__Append((void*)(_check_pointer(i0, 2484)), (Config_Source_Environment__VariableTemplate)i1);
  goto l4;
l3:
  i0 = (OOC_INT32)t;
  *list = (Config_Source_Environment__VariableTemplate)i0;
l4:
  return;
  ;
}

Config_Source_Environment__VariableTemplate Config_Source_Environment__EnvironmentDesc_AddVariableTemplate(Config_Source_Environment__Environment env, Object__String8 name, Object__String8 transformation) {
  register OOC_INT32 i0,i1,i2;
  Config_Source_Environment__VariableTemplate t;

  i0 = (OOC_INT32)RT0__NewObject(_td_Config_Source_Environment__VariableTemplate.baseTypes[0]);
  i1 = (OOC_INT32)transformation;
  i2 = (OOC_INT32)name;
  Config_Source_Environment__VariableTemplateDesc_INIT((Config_Source_Environment__VariableTemplate)i0, (Object__String8)i2, (Object__String8)i1, 0u, 0u);
  t = (Config_Source_Environment__VariableTemplate)i0;
  i1 = (OOC_INT32)env;
  Config_Source_Environment__Append((void*)(_check_pointer(i1, 2894)), (Config_Source_Environment__VariableTemplate)i0);
  return (Config_Source_Environment__VariableTemplate)i0;
  ;
}

Config_Source_Environment__VariableTemplate Config_Source_Environment__EnvironmentDesc_AddListTemplate(Config_Source_Environment__Environment env, Object__String8 name, Object__String8 transformation, OOC_CHAR8 listSep) {
  register OOC_INT32 i0,i1,i2,i3;
  Config_Source_Environment__VariableTemplate t;

  i0 = (OOC_INT32)RT0__NewObject(_td_Config_Source_Environment__VariableTemplate.baseTypes[0]);
  i1 = listSep;
  i2 = (OOC_INT32)transformation;
  i3 = (OOC_INT32)name;
  Config_Source_Environment__VariableTemplateDesc_INIT((Config_Source_Environment__VariableTemplate)i0, (Object__String8)i3, (Object__String8)i2, 1u, i1);
  t = (Config_Source_Environment__VariableTemplate)i0;
  i1 = (OOC_INT32)env;
  Config_Source_Environment__Append((void*)(_check_pointer(i1, 3297)), (Config_Source_Environment__VariableTemplate)i0);
  return (Config_Source_Environment__VariableTemplate)i0;
  ;
}

Msg__Msg Config_Source_Environment__EnvironmentDesc_Parse(Config_Source_Environment__Environment env) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  Config_Source_Environment__VariableTemplate t;
  Object__String value;
  OOC_INT32 i;
  OOC_INT32 j;
  Object__String entry;
  auto void Config_Source_Environment__EnvironmentDesc_Parse_AddCommand(Config_Source_Environment__VariableTemplate t, Object__String value);
    
    void Config_Source_Environment__EnvironmentDesc_Parse_AddCommand(Config_Source_Environment__VariableTemplate t, Object__String value) {
      register OOC_INT32 i0,i1;
      Config_Source_Environment__Command cmd;
      auto void Config_Source_Environment__EnvironmentDesc_Parse_AddCommand_Append(Config_Source_Environment__Command *list);
        
        void Config_Source_Environment__EnvironmentDesc_Parse_AddCommand_Append(Config_Source_Environment__Command *list) {
          register OOC_INT32 i0,i1;

          i0 = (OOC_INT32)*list;
          i1 = i0==(OOC_INT32)0;
          if (i1) goto l3;
          Config_Source_Environment__EnvironmentDesc_Parse_AddCommand_Append((void*)(_check_pointer(i0, 3723)));
          goto l4;
l3:
          i0 = (OOC_INT32)cmd;
          *list = (Config_Source_Environment__Command)i0;
l4:
          return;
          ;
        }


      i0 = (OOC_INT32)RT0__NewObject(_td_Config_Source_Environment__Command.baseTypes[0]);
      cmd = (Config_Source_Environment__Command)i0;
      *(OOC_INT32*)(_check_pointer(i0, 3809)) = 0;
      i1 = (OOC_INT32)t;
      *(OOC_INT32*)((_check_pointer(i0, 3840))+4) = i1;
      i1 = (OOC_INT32)value;
      *(OOC_INT32*)((_check_pointer(i0, 3866))+8) = (_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3893)))), &_td_Object__String8Desc, 3893));
      *(OOC_UINT8*)((_check_pointer(i0, 3912))+12) = 0u;
      i0 = (OOC_INT32)env;
      Config_Source_Environment__EnvironmentDesc_Parse_AddCommand_Append((void*)((_check_pointer(i0, 3952))+4));
      return;
      ;
    }


  i0 = (OOC_INT32)env;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 4010));
  t = (Config_Source_Environment__VariableTemplate)i0;
  i1 = i0!=0;
  if (!i1) goto l27;
l3_loop:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4095))+4);
  i1 = (OOC_INT32)OS_ProcessParameters__GetEnv((Object__String)i1);
  value = (Object__String)i1;
  i2 = i1!=0;
  if (!i2) goto l22;
  i2 = *(OOC_UINT8*)((_check_pointer(i0, 4143))+12);
  if (i2) goto l8;
  Config_Source_Environment__EnvironmentDesc_Parse_AddCommand((Config_Source_Environment__VariableTemplate)i0, (Object__String)i1);
  goto l22;
l8:
  i = 0;
l9_loop:
  i0 = (OOC_INT32)t;
  i1 = (OOC_INT32)value;
  i2 = *(OOC_UINT8*)((_check_pointer(i0, 4234))+13);
  i3 = i;
  i2 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 4224)))), Object__StringDesc_IndexOf)),Object__StringDesc_IndexOf)((Object__String)i1, i2, i3);
  j = i2;
  i4 = i2<0;
  if (i4) goto l12;
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 4400)))), Object__StringDesc_Substring)),Object__StringDesc_Substring)((Object__String)i1, i3, i2);
  entry = (Object__String)i1;
  i = (i2+1);
  
  goto l13;
l12:
  i4 = *(OOC_INT32*)(_check_pointer(i1, 4323));
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 4304)))), Object__StringDesc_Substring)),Object__StringDesc_Substring)((Object__String)i1, i3, i4);
  entry = (Object__String)i1;
  i = i2;
  
l13:
  i2 = *(OOC_INT32*)(_check_pointer(i1, 4502));
  i2 = i2>0;
  if (!i2) goto l16;
  Config_Source_Environment__EnvironmentDesc_Parse_AddCommand((Config_Source_Environment__VariableTemplate)i0, (Object__String)i1);
l16:
  i0 = i;
  i0 = i0>=0;
  if (i0) goto l9_loop;
l22:
  i0 = (OOC_INT32)t;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 4699));
  t = (Config_Source_Environment__VariableTemplate)i0;
  i1 = i0!=0;
  if (i1) goto l3_loop;
l27:
  return (Msg__Msg)0;
  ;
}

void Config_Source_Environment__EnvironmentDesc_Write(Config_Source_Environment__Environment env, IO__ByteChannel ch, const Config_Parser__String rootTag__ref, OOC_LEN rootTag_0d) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_ALLOCATE_VPAR(rootTag,OOC_CHAR16 ,rootTag_0d)
  IO_TextRider__Writer w;
  OOC_CHAR8 root8[1024];
  Config_Source_Environment__Command command;
  Object__String8 pattern;
  Object__CharsLatin1 chars;
  OOC_INT32 i;
  OOC_INT32 j;
  auto void Config_Source_Environment__EnvironmentDesc_Write_WriteQuoted(IO_TextRider__Writer w, Object__String8 str);
    
    void Config_Source_Environment__EnvironmentDesc_Write_WriteQuoted(IO_TextRider__Writer w, Object__String8 str) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
      Object__CharsLatin1 chars;
      OOC_INT32 s;
      OOC_INT32 e;
      OOC_INT32 last;

      i0 = (OOC_INT32)str;
      i1 = (OOC_INT32)Object__String8Desc_CharsLatin1((Object__String8)i0);
      chars = (Object__CharsLatin1)i1;
      s = 0;
      i0 = *(OOC_INT32*)(_check_pointer(i0, 5233));
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
      i4 = _check_pointer(i1, 5314);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      i4 = *(OOC_UINT8*)(i4+(_check_index(i2, i5, OOC_UINT32, 5314)));
      i4 = i4!=38u;
      
l8:
      if (i4) goto l10;
      i4=0u;
      goto l12;
l10:
      i4 = _check_pointer(i1, 5347);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      i4 = *(OOC_UINT8*)(i4+(_check_index(i2, i5, OOC_UINT32, 5347)));
      i4 = i4!=60u;
      
l12:
      if (i4) goto l14;
      i4=0u;
      goto l16;
l14:
      i4 = _check_pointer(i1, 5366);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      i4 = *(OOC_UINT8*)(i4+(_check_index(i2, i5, OOC_UINT32, 5366)));
      i4 = i4!=62u;
      
l16:
      if (i4) goto l18;
      i4=0u;
      goto l20;
l18:
      i4 = _check_pointer(i1, 5399);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      i4 = *(OOC_UINT8*)(i4+(_check_index(i2, i5, OOC_UINT32, 5399)));
      i4 = i4!=39u;
      
l20:
      if (i4) goto l22;
      i4=0u;
      goto l24;
l22:
      i4 = _check_pointer(i1, 5418);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      i4 = *(OOC_UINT8*)(i4+(_check_index(i2, i5, OOC_UINT32, 5418)));
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
      i5 = _check_pointer(i1, 5314);
      i6 = OOC_ARRAY_LENGTH(i5, 0);
      i5 = *(OOC_UINT8*)(i5+(_check_index(i4, i6, OOC_UINT32, 5314)));
      i5 = i5!=38u;
      
l32:
      if (i5) goto l34;
      i5=0u;
      goto l36;
l34:
      i5 = _check_pointer(i1, 5347);
      i6 = OOC_ARRAY_LENGTH(i5, 0);
      i5 = *(OOC_UINT8*)(i5+(_check_index(i4, i6, OOC_UINT32, 5347)));
      i5 = i5!=60u;
      
l36:
      if (i5) goto l38;
      i5=0u;
      goto l40;
l38:
      i5 = _check_pointer(i1, 5366);
      i6 = OOC_ARRAY_LENGTH(i5, 0);
      i5 = *(OOC_UINT8*)(i5+(_check_index(i4, i6, OOC_UINT32, 5366)));
      i5 = i5!=62u;
      
l40:
      if (i5) goto l42;
      i5=0u;
      goto l44;
l42:
      i5 = _check_pointer(i1, 5399);
      i6 = OOC_ARRAY_LENGTH(i5, 0);
      i5 = *(OOC_UINT8*)(i5+(_check_index(i4, i6, OOC_UINT32, 5399)));
      i5 = i5!=39u;
      
l44:
      if (i5) goto l46;
      i5=0u;
      goto l48;
l46:
      i5 = _check_pointer(i1, 5418);
      i6 = OOC_ARRAY_LENGTH(i5, 0);
      i5 = *(OOC_UINT8*)(i5+(_check_index(i4, i6, OOC_UINT32, 5418)));
      i5 = i5!=34u;
      
l48:
      if (i5) goto l27_loop;
l52:
      i5 = OOC_ARRAY_LENGTH((_check_pointer(i1, 5498)), 0);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 5472)))), IO_TextRider__WriterDesc_WriteStringRegion)),IO_TextRider__WriterDesc_WriteStringRegion)((IO_TextRider__Writer)i3, (void*)(_check_pointer(i1, 5498)), i5, i2, i4);
      i2 = i4!=i0;
      if (i2) goto l55;
      i2=i4;
      goto l64;
l55:
      i2 = _check_pointer(i1, 5555);
      i5 = OOC_ARRAY_LENGTH(i2, 0);
      i2 = *(OOC_UINT8*)(i2+(_check_index(i4, i5, OOC_UINT32, 5555)));
      switch (i2) {
      case 38u:
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 5580)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i3, "&amp;", 6);
        goto l63;
      case 60u:
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 5622)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i3, "&lt;", 5);
        goto l63;
      case 62u:
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 5663)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i3, "&gt;", 5);
        goto l63;
      case 39u:
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 5704)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i3, "&apos;", 7);
        goto l63;
      case 34u:
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 5747)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i3, "&quot;", 7);
        goto l63;
      default:
        _failed_case(i2, 5545);
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6007)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, "<?xml version=\0471.0\047 encoding=\047ISO-8859-1\047 standalone=\047yes\047?>", 61);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6094)))), IO_TextRider__WriterDesc_WriteLn)),IO_TextRider__WriterDesc_WriteLn)((IO_TextRider__Writer)i0);
  LongStrings__Short((void*)(OOC_INT32)rootTag, rootTag_0d, 63u, (void*)(OOC_INT32)root8, 1024);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6159)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, "<", 2);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6187)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, (void*)(OOC_INT32)root8, 1024);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6217)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, ">", 2);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6245)))), IO_TextRider__WriterDesc_WriteLn)),IO_TextRider__WriterDesc_WriteLn)((IO_TextRider__Writer)i0);
l3:
  i0 = (OOC_INT32)env;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6287))+4);
  command = (Config_Source_Environment__Command)i0;
  i1 = i0!=(OOC_INT32)0;
  if (!i1) goto l47;
l6_loop:
  i1 = *(OOC_UINT8*)((_check_pointer(i0, 6348))+12);
  i1 = !i1;
  if (!i1) goto l42;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6392))+4);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6402))+8);
  pattern = (Object__String8)i0;
  i0 = (OOC_INT32)Object__String8Desc_CharsLatin1((Object__String8)i0);
  chars = (Object__CharsLatin1)i0;
  i = 0;
  i0 = _check_pointer(i0, 6489);
  i1 = OOC_ARRAY_LENGTH(i0, 0);
  i0 = *(OOC_UINT8*)(i0+(_check_index(0, i1, OOC_UINT32, 6489)));
  i0 = i0!=0u;
  if (!i0) goto l41;
  i0=0;
l11_loop:
  j = i0;
  i1 = (OOC_INT32)chars;
  i2 = _check_pointer(i1, 6542);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i2 = *(OOC_UINT8*)(i2+(_check_index(i0, i3, OOC_UINT32, 6542)));
  i2 = i2!=0u;
  if (i2) goto l14;
  i2=0u;
  goto l16;
l14:
  i2 = _check_pointer(i1, 6560);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i2 = *(OOC_UINT8*)(i2+(_check_index(i0, i3, OOC_UINT32, 6560)));
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
  i3 = _check_pointer(i1, 6542);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i3 = *(OOC_UINT8*)(i3+(_check_index(i2, i4, OOC_UINT32, 6542)));
  i3 = i3!=0u;
  if (i3) goto l22;
  i3=0u;
  goto l24;
l22:
  i3 = _check_pointer(i1, 6560);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i3 = *(OOC_UINT8*)(i3+(_check_index(i2, i4, OOC_UINT32, 6560)));
  i3 = i3!=36u;
  
l24:
  if (i3) goto l19_loop;
l28:
  i3 = _check_pointer(i1, 6629);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i3 = *(OOC_UINT8*)(i3+(_check_index(i2, i4, OOC_UINT32, 6629)));
  i3 = i3==36u;
  if (i3) goto l31;
  i3=0u;
  goto l33;
l31:
  i3 = _check_pointer(i1, 6648);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i3 = *(OOC_UINT8*)(i3+(_check_index((i2+1), i4, OOC_UINT32, 6648)));
  i3 = i3==49u;
  
l33:
  if (i3) goto l35;
  i3 = (OOC_INT32)w;
  i4 = OOC_ARRAY_LENGTH((_check_pointer(i1, 6840)), 0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 6814)))), IO_TextRider__WriterDesc_WriteStringRegion)),IO_TextRider__WriterDesc_WriteStringRegion)((IO_TextRider__Writer)i3, (void*)(_check_pointer(i1, 6840)), i4, i0, i2);
  i0=i2;
  goto l36;
l35:
  i3 = (OOC_INT32)w;
  i4 = OOC_ARRAY_LENGTH((_check_pointer(i1, 6705)), 0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 6679)))), IO_TextRider__WriterDesc_WriteStringRegion)),IO_TextRider__WriterDesc_WriteStringRegion)((IO_TextRider__Writer)i3, (void*)(_check_pointer(i1, 6705)), i4, i0, i2);
  i0 = (OOC_INT32)command;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6750))+8);
  Config_Source_Environment__EnvironmentDesc_Write_WriteQuoted((IO_TextRider__Writer)i3, (Object__String8)i0);
  i0 = i;
  i0 = i0+2;
  i = i0;
  
l36:
  i1 = (OOC_INT32)chars;
  i1 = _check_pointer(i1, 6489);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i1 = *(OOC_UINT8*)(i1+(_check_index(i0, i2, OOC_UINT32, 6489)));
  i1 = i1!=0u;
  if (i1) goto l11_loop;
l41:
  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6885)))), IO_TextRider__WriterDesc_WriteLn)),IO_TextRider__WriterDesc_WriteLn)((IO_TextRider__Writer)i0);
l42:
  i0 = (OOC_INT32)command;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 6930));
  command = (Config_Source_Environment__Command)i0;
  i1 = i0!=(OOC_INT32)0;
  if (i1) goto l6_loop;
l47:
  i0 = (
  _cmp16((const void*)(OOC_INT32)rootTag,(const void*)((OOC_CHAR16[]){0})))!=0;
  if (!i0) goto l50;
  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6992)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, "</", 3);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7021)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, (void*)(OOC_INT32)root8, 1024);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7051)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, ">", 2);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7079)))), IO_TextRider__WriterDesc_WriteLn)),IO_TextRider__WriterDesc_WriteLn)((IO_TextRider__Writer)i0);
l50:
  return;
  ;
}

void OOC_Config_Source_Environment_init(void) {

  return;
  ;
}

void OOC_Config_Source_Environment_destroy(void) {
}

/* --- */
