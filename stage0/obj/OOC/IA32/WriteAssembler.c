#include <OOC/IA32/WriteAssembler.d>
#include <__oo2c.h>
#include <setjmp.h>

static void OOC_IA32_WriteAssembler__WriteInstrList(OOC_IA32_Writer__Writer w, OOC_SSA_Schedule__Block b) {
  register OOC_INT32 i0,i1;
  OOC_SSA_Schedule__InstrProxy proxy;
  OOC_SSA__Instr instr;
  auto void OOC_IA32_WriteAssembler__WriteInstrList_Value(OOC_SSA__Opnd opnd, OOC_CHAR8 str[], OOC_LEN str_0d);
  auto void OOC_IA32_WriteAssembler__WriteInstrList_Push(OOC_SSA__Opnd opnd);
  auto OOC_INT32 OOC_IA32_WriteAssembler__WriteInstrList_PushList(OOC_SSA__Opnd opnd, OOC_INT8 _class);
  auto void OOC_IA32_WriteAssembler__WriteInstrList_Assert(OOC_SSA__Instr assert);
  auto void OOC_IA32_WriteAssembler__WriteInstrList_Call(OOC_SSA__Instr call);
    
    void OOC_IA32_WriteAssembler__WriteInstrList_Value(OOC_SSA__Opnd opnd, OOC_CHAR8 str[], OOC_LEN str_0d) {
      register OOC_INT32 i0,i1;
      OOC_SSA__Result arg;
      Object__String s;
      Object__CharsLatin1 chars;
      auto void OOC_IA32_WriteAssembler__WriteInstrList_Value_Const(Object_Boxed__Object value, OOC_SymbolTable__Type stringType);
        
        void OOC_IA32_WriteAssembler__WriteInstrList_Value_Const(Object_Boxed__Object value, OOC_SymbolTable__Type stringType) {
          register OOC_INT32 i0,i1;
          Object__String s;
          Object__CharsLatin1 chars;
          Object__String string;

          i0 = (OOC_INT32)value;
          i1 = i0==(OOC_INT32)0;
          if (i1) goto l31;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2627)))), &_td_Object_Boxed__BooleanDesc);
          if (i1) goto l25;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2793)))), &_td_Object_Boxed__StringDesc);
          if (i1) goto l19;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3142)))), &_td_Object_Boxed__LongRealDesc);
          if (i1) goto l17;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3207)))), &_td_Object_BigInt__BigIntDesc);
          if (i1) goto l15;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3415)))), &_td_Object_Boxed__SetDesc);
          if (i1) goto l13;
          _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3408)))), 3408);
          goto l32;
l13:
          _assert(0u, 127, 3442);
          goto l32;
l15:
          i0 = (OOC_INT32)Object_BigInt__BigIntDesc_ToString((Object_BigInt__BigInt)i0);
          string = (Object__String)i0;
          i0 = (OOC_INT32)Object__String8Desc_CharsLatin1((Object__String8)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3301)))), &_td_Object__String8Desc, 3301)));
          chars = (Object__CharsLatin1)i0;
          _copy_8((const void*)(_check_pointer(i0, 3347)),(void*)(OOC_INT32)str,str_0d);
          Strings__Insert("$", 2, 0, (void*)(OOC_INT32)str, str_0d);
          goto l32;
l17:
          _assert(0u, 127, 3174);
          goto l32;
l19:
          i1 = (OOC_INT32)stringType;
          i1 = i1==(OOC_INT32)0;
          if (i1) goto l22;
          i1 = (OOC_INT32)w;
          i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 2951)))), OOC_IA32_Writer__WriterDesc_GetStringLabel)),OOC_IA32_Writer__WriterDesc_GetStringLabel)((OOC_IA32_Writer__Writer)i1, (Object_Boxed__String)i0);
          s = (Object__String)i0;
          i0 = (OOC_INT32)Object__String8Desc_CharsLatin1((Object__String8)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3009)))), &_td_Object__String8Desc, 3009)));
          chars = (Object__CharsLatin1)i0;
          _copy_8((const void*)(_check_pointer(i0, 3057)),(void*)(OOC_INT32)str,str_0d);
          goto l23;
l22:
          i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 2889));
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 2889));
          i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 2895)))), Object__StringDesc_CharAt)),Object__StringDesc_CharAt)((Object__String)i0, 0);
          IntStr__IntToStr(i0, (void*)(OOC_INT32)str, str_0d);
l23:
          Strings__Insert("$", 2, 0, (void*)(OOC_INT32)str, str_0d);
          goto l32;
l25:
          i0 = *(OOC_UINT8*)(_check_pointer(i0, 2666));
          if (i0) goto l28;
          _copy_8((const void*)"$0",(void*)(OOC_INT32)str,str_0d);
          goto l32;
l28:
          _copy_8((const void*)"$1",(void*)(OOC_INT32)str,str_0d);
          goto l32;
l31:
          _copy_8((const void*)"$0",(void*)(OOC_INT32)str,str_0d);
l32:
          return;
          ;
        }


      i0 = (OOC_INT32)opnd;
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 3535));
      arg = (OOC_SSA__Result)i0;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3556)))), &_td_OOC_SSA__ConstDesc);
      if (i1) goto l11;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3636)))), &_td_OOC_SSA__AddressDesc);
      if (i1) goto l9;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3809))+8);
      i1 = *(OOC_INT8*)((_check_pointer(i1, 3816))+36);
      switch (i1) {
      case 12:
        i0 = (OOC_INT32)w;
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3922)))), OOC_IA32_Writer__WriterDesc_Instr)),OOC_IA32_Writer__WriterDesc_Instr)((OOC_IA32_Writer__Writer)i0, "movswl 8(%ebp),%ebx", 20);
        _copy_8((const void*)"%ebx",(void*)(OOC_INT32)str,str_0d);
        goto l12;
      default:
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4034))+8);
        Log__Type("arg.instr", 10, (void*)i1);
        i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4057))+8);
        OOC_SSA__InstrDesc_LogOpcode((OOC_SSA__Instr)i0, "opcode", 7);
        _assert(0u, 127, 4098);
        goto l12;
      }
l9:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3695))+44);
      i0 = (OOC_INT32)OOC_C_Naming__NameOfDeclaration((OOC_SymbolTable__Declaration)i0);
      s = (Object__String)i0;
      i0 = (OOC_INT32)Object__String8Desc_CharsLatin1((Object__String8)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3730)))), &_td_Object__String8Desc, 3730)));
      chars = (Object__CharsLatin1)i0;
      _copy_8((const void*)(_check_pointer(i0, 3772)),(void*)(OOC_INT32)str,str_0d);
      goto l12;
l11:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3589))+44);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3601))+48);
      OOC_IA32_WriteAssembler__WriteInstrList_Value_Const((Object_Boxed__Object)i1, (OOC_SymbolTable__Type)i0);
l12:
      return;
      ;
    }

    
    void OOC_IA32_WriteAssembler__WriteInstrList_Push(OOC_SSA__Opnd opnd) {
      register OOC_INT32 i0;
      OOC_IA32_WriteAssembler__Buffer str;

      i0 = (OOC_INT32)opnd;
      OOC_IA32_WriteAssembler__WriteInstrList_Value((OOC_SSA__Opnd)i0, (void*)(OOC_INT32)str, 256);
      Strings__Insert("pushl ", 7, 0, (void*)(OOC_INT32)str, 256);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4301)))), OOC_IA32_Writer__WriterDesc_Instr)),OOC_IA32_Writer__WriterDesc_Instr)((OOC_IA32_Writer__Writer)i0, (void*)(OOC_INT32)str, 256);
      return;
      ;
    }

    
    OOC_INT32 OOC_IA32_WriteAssembler__WriteInstrList_PushList(OOC_SSA__Opnd opnd, OOC_INT8 _class) {
      register OOC_INT32 i0,i1,i2;

      i0 = (OOC_INT32)opnd;
      i1 = *(OOC_INT8*)((_check_pointer(i0, 4450))+4);
      i2 = _class;
      i1 = i1==i2;
      if (i1) goto l3;
      return 0;
      goto l4;
l3:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4501))+8);
      i1 = OOC_IA32_WriteAssembler__WriteInstrList_PushList((OOC_SSA__Opnd)i1, i2);
      OOC_IA32_WriteAssembler__WriteInstrList_Push((OOC_SSA__Opnd)i0);
      return (i1+1);
l4:
      _failed_function(4343); return 0;
      ;
    }

    
    void OOC_IA32_WriteAssembler__WriteInstrList_Assert(OOC_SSA__Instr assert) {
      register OOC_INT32 i0,i1;

      i0 = (OOC_INT32)assert;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4751))+24);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 4761))+8);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 4771))+8);
      OOC_IA32_WriteAssembler__WriteInstrList_Push((OOC_SSA__Opnd)i1);
      i1 = (OOC_INT32)w;
      i0 = *(OOC_INT32*)((_check_pointer(i0, 4808))+40);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 4791)))), OOC_IA32_Writer__WriterDesc_PushInt)),OOC_IA32_Writer__WriterDesc_PushInt)((OOC_IA32_Writer__Writer)i1, i0);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4823)))), OOC_IA32_Writer__WriterDesc_PushLabel)),OOC_IA32_Writer__WriterDesc_PushLabel)((OOC_IA32_Writer__Writer)i0, "_mid", 5);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4852)))), OOC_IA32_Writer__WriterDesc_Instr)),OOC_IA32_Writer__WriterDesc_Instr)((OOC_IA32_Writer__Writer)i0, "call RT0__ErrorAssertionFailed", 31);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4903)))), OOC_IA32_Writer__WriterDesc_PopBytes)),OOC_IA32_Writer__WriterDesc_PopBytes)((OOC_IA32_Writer__Writer)i0, 12);
      return;
      ;
    }

    
    void OOC_IA32_WriteAssembler__WriteInstrList_Call(OOC_SSA__Instr call) {
      register OOC_INT32 i0,i1;
      OOC_INT32 len;
      OOC_IA32_WriteAssembler__Buffer str;

      i0 = (OOC_INT32)call;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5057))+24);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 5067))+8);
      i1 = OOC_IA32_WriteAssembler__WriteInstrList_PushList((OOC_SSA__Opnd)i1, 1);
      len = i1;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5107))+24);
      OOC_IA32_WriteAssembler__WriteInstrList_Value((OOC_SSA__Opnd)i0, (void*)(OOC_INT32)str, 256);
      Strings__Insert("call ", 6, 0, (void*)(OOC_INT32)str, 256);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5172)))), OOC_IA32_Writer__WriterDesc_Instr)),OOC_IA32_Writer__WriterDesc_Instr)((OOC_IA32_Writer__Writer)i0, (void*)(OOC_INT32)str, 256);
      i0 = i1!=0;
      if (!i0) goto l4;
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5220)))), OOC_IA32_Writer__WriterDesc_PopBytes)),OOC_IA32_Writer__WriterDesc_PopBytes)((OOC_IA32_Writer__Writer)i0, (i1*4));
l4:
      return;
      ;
    }


  i0 = (OOC_INT32)b;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5290))+8);
  proxy = (OOC_SSA_Schedule__InstrProxy)i0;
  i1 = i0!=(OOC_INT32)0;
  if (!i1) goto l26;
l3_loop:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5350))+12);
  instr = (OOC_SSA__Instr)i0;
  i1 = *(OOC_INT8*)((_check_pointer(i0, 5376))+36);
  switch (i1) {
  case 0:
    goto l21;
  case 1:
    goto l21;
  case 2:
    goto l21;
  case 3:
    goto l21;
  case 12:
    goto l21;
  case 4:
    goto l21;
  case 5:
    goto l21;
  case 82:
    goto l21;
  case 22:
    goto l21;
  case 57:
    goto l21;
  case 58:
    goto l21;
  case 7:
    goto l21;
  case 8:
    goto l21;
  case 64:
    OOC_IA32_WriteAssembler__WriteInstrList_Assert((OOC_SSA__Instr)i0);
    goto l21;
  case 55:
    OOC_IA32_WriteAssembler__WriteInstrList_Call((OOC_SSA__Instr)i0);
    goto l21;
  default:
    _failed_case(i1, 5366);
    goto l21;
  }
l21:
  i0 = (OOC_INT32)proxy;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 6228));
  proxy = (OOC_SSA_Schedule__InstrProxy)i0;
  i1 = i0!=(OOC_INT32)0;
  if (i1) goto l3_loop;
l26:
  return;
  ;
}

static void OOC_IA32_WriteAssembler__WriteBlocks(OOC_IA32_Writer__Writer w, OOC_SSA_Schedule__Block domRoot) {
  register OOC_INT32 i0;
  auto void OOC_IA32_WriteAssembler__WriteBlocks_WriteBlock(OOC_SSA_Schedule__Block b);
    
    void OOC_IA32_WriteAssembler__WriteBlocks_WriteBlock(OOC_SSA_Schedule__Block b) {
      register OOC_INT32 i0,i1;

      i0 = (OOC_INT32)b;
      i1 = *(OOC_INT32*)((_check_pointer(i0, 6404))+36);
      i1 = i1!=0;
      if (!i1) goto l4;
      i1 = (OOC_INT32)w;
      OOC_IA32_WriteAssembler__WriteInstrList((OOC_IA32_Writer__Writer)i1, (OOC_SSA_Schedule__Block)i0);
l4:
      return;
      ;
    }


  i0 = (OOC_INT32)domRoot;
  OOC_IA32_WriteAssembler__WriteBlocks_WriteBlock((OOC_SSA_Schedule__Block)i0);
  return;
  ;
}

void OOC_IA32_WriteAssembler__TranslatorDesc_WriteProcBody(volatile OOC_IA32_WriteAssembler__Translator t, volatile OOC_IR__Procedure proc) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  volatile OOC_SSA__ProcBlock pb;
  volatile OOC_CHAR8 writeProc;
  volatile OOC_SSA__Instr enter;
  volatile OOC_SSA__Result s;
  volatile OOC_SSA_Destore__State destore;
  volatile OOC_SSA__Instr instr;
  volatile OOC_SSA__Instr next;
  volatile OOC_SSA_Schedule__Block domRoot;
  volatile OOC_IA32_Writer__Writer w;
  volatile Object__String name;
  volatile OOC_CHAR8 lfe[32];
  auto void OOC_IA32_WriteAssembler__TranslatorDesc_WriteProcBody_Write(const OOC_CHAR8 pre__ref[], volatile OOC_LEN pre_0d, const OOC_CHAR8 post__ref[], volatile OOC_LEN post_0d);
  jmp_buf _target0;
  Exception__Context _context0;
    
    void OOC_IA32_WriteAssembler__TranslatorDesc_WriteProcBody_Write(const OOC_CHAR8 pre__ref[], volatile OOC_LEN pre_0d, const OOC_CHAR8 post__ref[], volatile OOC_LEN post_0d) {
      register OOC_INT32 i0,i1;
      OOC_ALLOCATE_VPAR(pre,OOC_CHAR8 ,pre_0d)
      OOC_ALLOCATE_VPAR(post,OOC_CHAR8 ,post_0d)
      jmp_buf _target0;
      Exception__Context _context0;

      OOC_INITIALIZE_VPAR(pre__ref,pre,OOC_CHAR8 ,pre_0d)
      OOC_INITIALIZE_VPAR(post__ref,post,OOC_CHAR8 ,post_0d)
      i0 = writeProc;
      if (i0) goto l3;
      i0=0u;
      goto l9;
l3:
      i0 = (OOC_INT32)t;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6943))+24);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6943))+24);
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 6957)))), StringSearch__MatcherDesc_MatchChars)),StringSearch__MatcherDesc_MatchChars)((StringSearch__Matcher)i0, (void*)(OOC_INT32)pre, pre_0d, 0, (-1));
      i0 = i0!=(OOC_INT32)0;
      if (i0) goto l6;
      i0 = (OOC_INT32)t;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7005))+24);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7005))+24);
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 7019)))), StringSearch__MatcherDesc_MatchChars)),StringSearch__MatcherDesc_MatchChars)((StringSearch__Matcher)i0, (void*)(OOC_INT32)post, post_0d, 0, (-1));
      i0 = i0!=(OOC_INT32)0;
      
      goto l9;
l6:
      i0=1u;
l9:
      if (!i0) goto l18;
      Out__String("PROCEDURE ", 11);
      i0 = (OOC_INT32)pb;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7116))+20);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 7126))+20);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 7132))+12);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7116))+20);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7126))+20);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7132))+12);
      i0 = OOC_ARRAY_LENGTH((_check_pointer(i0, 7137)), 0);
      Out__String((void*)(_check_pointer(i1, 7137)), i0);
      Out__String("/", 2);
      Out__String((void*)(OOC_INT32)pre, pre_0d);
      Out__String("/", 2);
      Out__String((void*)(OOC_INT32)post, post_0d);
      Out__String(":", 2);
      Out__Ln();
      Out__Flush();
      {
        Exception__PushContext(&_context0, &_target0);
        if (!setjmp(_target0)) goto l16;
        Exception__PopContext(1);
        i0 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG(((OOC_INT32)Exception__Current()))), &_td_IO__ErrorDesc);
        if (i0) goto l15;
        Exception__ActivateContext();
l15:
        Exception__Clear();
        goto l17;
l16:
        i0 = (OOC_INT32)IO_StdChannels__stdout;
        i1 = (OOC_INT32)pb;
        OOC_SSA_XML__Write((IO__ByteChannel)i0, (OOC_SSA__ProcBlock)i1, 1u);
        Exception__PopContext(1);
l17:;
      }
      Out__Flush();
l18:
      return;
      ;
    }


  i0 = (OOC_INT32)proc;
  i1 = (OOC_INT32)OOC_SSA__NewProcBlock((OOC_IR__Procedure)i0);
  pb = (OOC_SSA__ProcBlock)i1;
  i2 = (OOC_INT32)t;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 7575))+20);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7606))+4);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 7612))+20);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 7618))+12);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7606))+4);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 7612))+20);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 7618))+12);
  i5 = OOC_ARRAY_LENGTH((_check_pointer(i5, 7623)), 0);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 7575))+20);
  i2 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 7588)))), StringSearch__MatcherDesc_MatchChars)),StringSearch__MatcherDesc_MatchChars)((StringSearch__Matcher)i2, (void*)(_check_pointer(i4, 7623)), i5, 0, (-1));
  writeProc = (i2!=(OOC_INT32)0);
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 7656));
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 7670))+24);
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 7680));
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 7685))+8);
  enter = (OOC_SSA__Instr)i2;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 7730));
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7775))+8);
  i0 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq((OOC_SSA__ProcBlock)i1, (OOC_SSA__Result)i2, (OOC_IR__StatementSeq)i0);
  s = (OOC_SSA__Result)i0;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 7794));
  OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i1, (OOC_SSA__Result)i0, 2);
  OOC_IA32_WriteAssembler__TranslatorDesc_WriteProcBody_Write("initial", 8, "dce-pre", 8);
  i0 = (OOC_INT32)pb;
  OOC_SSA_DeadCodeElimination__Transform((OOC_SSA__ProcBlock)i0);
  OOC_IA32_WriteAssembler__TranslatorDesc_WriteProcBody_Write("dce-post", 9, "destore-pre", 12);
  i0 = (OOC_INT32)pb;
  i0 = (OOC_INT32)OOC_SSA_Destore__New((OOC_SSA__ProcBlock)i0);
  destore = (OOC_SSA_Destore__State)i0;
  OOC_SSA_Destore__StateDesc_Transform((OOC_SSA_Destore__State)i0);
  OOC_IA32_WriteAssembler__TranslatorDesc_WriteProcBody_Write("destore-post", 13, "dce-pre", 8);
  i0 = (OOC_INT32)pb;
  OOC_SSA_DeadCodeElimination__Transform((OOC_SSA__ProcBlock)i0);
  OOC_IA32_WriteAssembler__TranslatorDesc_WriteProcBody_Write("dce-post", 9, "final", 6);
  i0 = (OOC_INT32)pb;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8265))+12);
  instr = (OOC_SSA__Instr)i1;
  i2 = i1!=(OOC_INT32)0;
  if (!i2) goto l12;
l3_loop:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 8324))+28);
  next = (OOC_SSA__Instr)i2;
  i3 = *(OOC_INT8*)((_check_pointer(i1, 8352))+36);
  switch (i3) {
  case 42:
    i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 8420))+24);
    i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 8429));
    OOC_SSA__ResultDesc_ReplaceUses((OOC_SSA__Result)i1, (OOC_SSA__Result)i3);
    OOC_SSA__ProcBlockDesc_DeleteInstr((OOC_SSA__ProcBlock)i0, (OOC_SSA__Instr)i1);
    goto l7;
  default:
    goto l7;
  }
l7:
  instr = (OOC_SSA__Instr)i2;
  i1 = i2!=(OOC_INT32)0;
  if (!i1) goto l12;
  i1=i2;
  goto l3_loop;
l12:
  i0 = (OOC_INT32)OOC_SSA_Schedule__Schedule((OOC_SSA__ProcBlock)i0);
  domRoot = (OOC_SSA_Schedule__Block)i0;
  i1 = writeProc;
  if (!i1) goto l25;
  i1 = (OOC_INT32)t;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 8616))+24);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 8616))+24);
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 8630)))), StringSearch__MatcherDesc_MatchChars)),StringSearch__MatcherDesc_MatchChars)((StringSearch__Matcher)i1, "schedule", 9, 0, (-1));
  i1 = i1!=(OOC_INT32)0;
  if (!i1) goto l25;
  {
    Exception__PushContext(&_context0, &_target0);
    if (!setjmp(_target0)) goto l22;
    Exception__PopContext(1);
    i0 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG(((OOC_INT32)Exception__Current()))), &_td_IO__ErrorDesc);
    if (i0) goto l21;
    Exception__ActivateContext();
l21:
    Exception__Clear();
    goto l23;
l22:
    i1 = (OOC_INT32)IO_StdChannels__stdout;
    OOC_SSA_XML__WriteSchedule((IO__ByteChannel)i1, (OOC_SSA_Schedule__Block)i0);
    Exception__PopContext(1);
l23:;
  }
  Out__Flush();
l25:
  i0 = (OOC_INT32)t;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 8885));
  w = (OOC_IA32_Writer__Writer)i1;
  i2 = (OOC_INT32)proc;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 8902))+4);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 8908))+4);
  i3 = i3==(OOC_INT32)0;
  if (i3) goto l28;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 9045))+4);
  i2 = (OOC_INT32)OOC_C_Naming__NameOfDeclaration((OOC_SymbolTable__Declaration)i2);
  name = (Object__String)i2;
  
  goto l29;
l28:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8969))+8);
  i2 = (OOC_INT32)OOC_C_Naming__NameOfModuleInit((OOC_SymbolTable__Module)i2, 1u);
  name = (Object__String)i2;
  
l29:
  i3 = *(OOC_INT32*)((_check_pointer(i0, 9085))+28);
  IntStr__IntToStr(i3, (void*)(OOC_INT32)lfe, 32);
  Strings__Insert(".Lfe", 5, 0, (void*)(OOC_INT32)lfe, 32);
  i3 = *(OOC_INT32*)((_check_pointer(i0, 9150))+28);
  *(OOC_INT32*)((_check_pointer(i0, 9150))+28) = (i3+1);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 9173)))), OOC_IA32_Writer__WriterDesc_Instr)),OOC_IA32_Writer__WriterDesc_Instr)((OOC_IA32_Writer__Writer)i1, ".align 4", 9);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 9200)))), OOC_IA32_Writer__WriterDesc_Write)),OOC_IA32_Writer__WriterDesc_Write)((OOC_IA32_Writer__Writer)i1, ".globl ", 8);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 9222)))), OOC_IA32_Writer__WriterDesc_WriteObject)),OOC_IA32_Writer__WriterDesc_WriteObject)((OOC_IA32_Writer__Writer)i1, (Object__String)i2);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 9245)))), OOC_IA32_Writer__WriterDesc_Newline)),OOC_IA32_Writer__WriterDesc_Newline)((OOC_IA32_Writer__Writer)i1);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 9261)))), OOC_IA32_Writer__WriterDesc_Write)),OOC_IA32_Writer__WriterDesc_Write)((OOC_IA32_Writer__Writer)i1, "\011.type ", 8);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 9291)))), OOC_IA32_Writer__WriterDesc_WriteObject)),OOC_IA32_Writer__WriterDesc_WriteObject)((OOC_IA32_Writer__Writer)i1, (Object__String)i2);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 9318)))), OOC_IA32_Writer__WriterDesc_Write)),OOC_IA32_Writer__WriterDesc_Write)((OOC_IA32_Writer__Writer)i1, ",@function", 11);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 9343)))), OOC_IA32_Writer__WriterDesc_Newline)),OOC_IA32_Writer__WriterDesc_Newline)((OOC_IA32_Writer__Writer)i1);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 9359)))), OOC_IA32_Writer__WriterDesc_Label)),OOC_IA32_Writer__WriterDesc_Label)((OOC_IA32_Writer__Writer)i1, (Object__String)i2);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 9380)))), OOC_IA32_Writer__WriterDesc_Instr)),OOC_IA32_Writer__WriterDesc_Instr)((OOC_IA32_Writer__Writer)i1, "pushl %ebp", 11);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 9409)))), OOC_IA32_Writer__WriterDesc_Instr)),OOC_IA32_Writer__WriterDesc_Instr)((OOC_IA32_Writer__Writer)i1, "movl %esp,%ebp", 15);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 9442)))), OOC_IA32_Writer__WriterDesc_Instr)),OOC_IA32_Writer__WriterDesc_Instr)((OOC_IA32_Writer__Writer)i1, "pushl %ebx", 11);
  i0 = (OOC_INT32)domRoot;
  OOC_IA32_WriteAssembler__WriteBlocks((OOC_IA32_Writer__Writer)i1, (OOC_SSA_Schedule__Block)i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 9543)))), OOC_IA32_Writer__WriterDesc_Instr)),OOC_IA32_Writer__WriterDesc_Instr)((OOC_IA32_Writer__Writer)i1, "pop %ebx", 9);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 9607)))), OOC_IA32_Writer__WriterDesc_Instr)),OOC_IA32_Writer__WriterDesc_Instr)((OOC_IA32_Writer__Writer)i1, "leave", 6);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 9631)))), OOC_IA32_Writer__WriterDesc_Instr)),OOC_IA32_Writer__WriterDesc_Instr)((OOC_IA32_Writer__Writer)i1, "ret", 4);
  i0 = (OOC_INT32)Object__NewLatin1((void*)(OOC_INT32)lfe, 32);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 9653)))), OOC_IA32_Writer__WriterDesc_Label)),OOC_IA32_Writer__WriterDesc_Label)((OOC_IA32_Writer__Writer)i1, (Object__String)i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 9691)))), OOC_IA32_Writer__WriterDesc_Write)),OOC_IA32_Writer__WriterDesc_Write)((OOC_IA32_Writer__Writer)i1, "\011.size ", 8);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 9721)))), OOC_IA32_Writer__WriterDesc_WriteObject)),OOC_IA32_Writer__WriterDesc_WriteObject)((OOC_IA32_Writer__Writer)i1, (Object__String)i2);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 9744)))), OOC_IA32_Writer__WriterDesc_Write)),OOC_IA32_Writer__WriterDesc_Write)((OOC_IA32_Writer__Writer)i1, ",", 2);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 9764)))), OOC_IA32_Writer__WriterDesc_Write)),OOC_IA32_Writer__WriterDesc_Write)((OOC_IA32_Writer__Writer)i1, (void*)(OOC_INT32)lfe, 32);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 9780)))), OOC_IA32_Writer__WriterDesc_Write)),OOC_IA32_Writer__WriterDesc_Write)((OOC_IA32_Writer__Writer)i1, "-", 2);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 9796)))), OOC_IA32_Writer__WriterDesc_WriteObject)),OOC_IA32_Writer__WriterDesc_WriteObject)((OOC_IA32_Writer__Writer)i1, (Object__String)i2);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 9819)))), OOC_IA32_Writer__WriterDesc_Newline)),OOC_IA32_Writer__WriterDesc_Newline)((OOC_IA32_Writer__Writer)i1);
  return;
  ;
}

void OOC_IA32_WriteAssembler__InitTranslator(OOC_IA32_WriteAssembler__Translator t, OOC_Repository__Module module, StringSearch__Matcher inspectProc, StringSearch__Matcher inspectStage) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)t;
  i1 = (OOC_INT32)module;
  OOC_Make_TranslateToIA32__InitTranslator((OOC_Make_TranslateToIA32__Translator)i0, (OOC_Repository__Module)i1);
  i1 = (OOC_INT32)inspectProc;
  *(OOC_INT32*)((_check_pointer(i0, 10053))+20) = i1;
  i1 = (OOC_INT32)inspectStage;
  *(OOC_INT32*)((_check_pointer(i0, 10088))+24) = i1;
  *(OOC_INT32*)((_check_pointer(i0, 10125))+28) = 1;
  return;
  ;
}

OOC_IA32_WriteAssembler__Translator OOC_IA32_WriteAssembler__NewTranslator(OOC_Repository__Module module, StringSearch__Matcher inspectProc, StringSearch__Matcher inspectStage) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_IA32_WriteAssembler__Translator.baseTypes[0]);
  i1 = (OOC_INT32)module;
  i2 = (OOC_INT32)inspectProc;
  i3 = (OOC_INT32)inspectStage;
  OOC_IA32_WriteAssembler__InitTranslator((OOC_IA32_WriteAssembler__Translator)i0, (OOC_Repository__Module)i1, (StringSearch__Matcher)i2, (StringSearch__Matcher)i3);
  return (OOC_IA32_WriteAssembler__Translator)i0;
  ;
}

void OOC_OOC_IA32_WriteAssembler_init(void) {

  return;
  ;
}

/* --- */
