#include <OOC/SSA/Allocator.d>
#include <__oo2c.h>
#include <setjmp.h>

static OOC_SSA_Allocator__RegisterFile OOC_SSA_Allocator__NewRegisterFile(OOC_INT8 registerType) {
  register OOC_INT32 i0,i1;
  OOC_SSA_Allocator__RegisterFile rf;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_SSA_Allocator__RegisterFile.baseTypes[0]);
  rf = (OOC_SSA_Allocator__RegisterFile)i0;
  OOC_SSA__InitNode((OOC_SSA__Node)i0);
  i1 = registerType;
  *(OOC_INT8*)(_check_pointer(i0, 3446)) = i1;
  i1 = (OOC_INT32)ADT_ArrayList__New(16);
  *(OOC_INT32*)((_check_pointer(i0, 3484))+4) = i1;
  i1 = (OOC_INT32)ADT_ArrayList__New(16);
  *(OOC_INT32*)((_check_pointer(i0, 3526))+8) = i1;
  *(OOC_INT32*)((_check_pointer(i0, 3567))+12) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 3590))+16) = (-1);
  *(OOC_INT32*)((_check_pointer(i0, 3614))+20) = 0;
  return (OOC_SSA_Allocator__RegisterFile)i0;
  ;
}

static OOC_SSA_Allocator__LiveData OOC_SSA_Allocator__NewLiveData(OOC_SSA_IGraph__Graph g, OOC_INT32 outgoingJumps) {
  register OOC_INT32 i0,i1;
  OOC_SSA_Allocator__LiveData ld;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_SSA_Allocator__LiveData.baseTypes[0]);
  ld = (OOC_SSA_Allocator__LiveData)i0;
  OOC_SSA_Schedule__InitInfo((OOC_SSA_Schedule__Info)i0);
  i1 = outgoingJumps;
  *(OOC_INT32*)(_check_pointer(i0, 3823)) = i1;
  *(OOC_INT32*)((_check_pointer(i0, 3863))+4) = 0;
  i1 = (OOC_INT32)g;
  i1 = (OOC_INT32)OOC_SSA_IGraph__GraphDesc_NewVector((OOC_SSA_IGraph__Graph)i1);
  *(OOC_INT32*)((_check_pointer(i0, 3888))+8) = i1;
  return (OOC_SSA_Allocator__LiveData)i0;
  ;
}

static OOC_SSA_Allocator__BlockList OOC_SSA_Allocator__GetBlockList(OOC_SSA_Schedule__Block enterBlock, OOC_SSA_Schedule__Block exitBlock) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7;
  OOC_SSA_Schedule__Info mark;
  ADT_ArrayList__ArrayList al;
  OOC_SSA_Allocator__BlockList bl;
  OOC_INT32 i;
  auto void OOC_SSA_Allocator__GetBlockList_ScanBlock(OOC_SSA_Schedule__Block b);
    
    void OOC_SSA_Allocator__GetBlockList_ScanBlock(OOC_SSA_Schedule__Block b) {
      register OOC_INT32 i0,i1,i2,i3,i4;
      OOC_INT32 i;

      i0 = (OOC_INT32)b;
      i1 = i0!=(OOC_INT32)0;
      if (i1) goto l3;
      i1=0u;
      goto l5;
l3:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4506))+44);
      i2 = (OOC_INT32)mark;
      i1 = i1!=i2;
      
l5:
      if (!i1) goto l33;
      i1 = (OOC_INT32)mark;
      *(OOC_INT32*)((_check_pointer(i0, 4535))+44) = i1;
      i1 = (OOC_INT32)al;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 4562)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i1, (Object__Object)i0);
      i1 = (OOC_INT32)exitBlock;
      i1 = i0!=i1;
      if (!i1) goto l33;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4625)))), &_td_OOC_SSA_Schedule__BranchBlockDesc);
      if (i1) goto l30;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4746)))), &_td_OOC_SSA_Schedule__JumpBlockDesc);
      if (i1) goto l28;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4822)))), &_td_OOC_SSA_Schedule__DeadEndBlockDesc);
      if (i1) goto l33;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4894)))), &_td_OOC_SSA_Schedule__SwitchBlockDesc);
      if (i1) goto l17;
      _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4891)))), 4891);
      goto l33;
l17:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4952))+52);
      i = 0;
      i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 4958)), 0);
      i2 = 0<i1;
      if (!i2) goto l33;
      i2=0;
l20_loop:
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4992))+52);
      i3 = _check_pointer(i3, 4998);
      i4 = OOC_ARRAY_LENGTH(i3, 0);
      i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i2, i4, OOC_UINT32, 4998))*4);
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 5001))+4);
      OOC_SSA_Allocator__GetBlockList_ScanBlock((OOC_SSA_Schedule__Block)i3);
      i2 = i2+1;
      i = i2;
      i3 = i2<i1;
      if (i3) goto l20_loop;
      goto l33;
l28:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4794))+48);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4800))+4);
      OOC_SSA_Allocator__GetBlockList_ScanBlock((OOC_SSA_Schedule__Block)i0);
      goto l33;
l30:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4675))+60);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 4685))+4);
      OOC_SSA_Allocator__GetBlockList_ScanBlock((OOC_SSA_Schedule__Block)i1);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4718))+48);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4724))+4);
      OOC_SSA_Allocator__GetBlockList_ScanBlock((OOC_SSA_Schedule__Block)i0);
l33:
      return;
      ;
    }


  mark = (OOC_SSA_Schedule__Info)((OOC_INT32)RT0__NewObject(_td_OOC_SSA_Schedule__Info.baseTypes[0]));
  i0 = (OOC_INT32)ADT_ArrayList__New(16);
  al = (ADT_ArrayList__ArrayList)i0;
  i0 = (OOC_INT32)enterBlock;
  OOC_SSA_Allocator__GetBlockList_ScanBlock((OOC_SSA_Schedule__Block)i0);
  i0 = (OOC_INT32)al;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 5231))+4);
  i1 = (OOC_INT32)RT0__NewObject(_td_OOC_SSA_Allocator__BlockList.baseTypes[0], i1);
  bl = (OOC_SSA_Allocator__BlockList)i1;
  i = 0;
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i1, 5265)), 0);
  i3 = 0<i2;
  if (!i3) goto l8;
  i3=0;
l3_loop:
  i4 = _check_pointer(i1, 5281);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 5290));
  i6 = _check_pointer(i6, 5297);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)(i6+(_check_index(i3, i7, OOC_UINT32, 5297))*4);
  *(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 5281))*4) = (_type_guard(i6, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 5310)))), &_td_OOC_SSA_Schedule__BlockDesc, 5310));
  i4 = _check_pointer(i1, 5326);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 5326))*4);
  *(OOC_INT32*)((_check_pointer(i4, 5329))+44) = 0;
  i3 = i3+1;
  i = i3;
  i4 = i3<i2;
  if (i4) goto l3_loop;
l8:
  return (OOC_SSA_Allocator__BlockList)i1;
  ;
}

OOC_INT8 OOC_SSA_Allocator__SubclassToBasicType(OOC_INT8 subclass) {
  register OOC_INT32 i0;

  i0 = subclass;
  switch (i0) {
  case 0:
    return 0;
    goto l15;
  case 9:
    return 4;
    goto l15;
  case 5:
    return 6;
    goto l15;
  case 6:
    return 7;
    goto l15;
  case 7:
    return 8;
    goto l15;
  case 8:
    return 9;
    goto l15;
  case 1:
    return 2;
    goto l15;
  case 2:
    return 3;
    goto l15;
  case 3:
    return 4;
    goto l15;
  case 4:
    return 5;
    goto l15;
  case 10:
    return 13;
    goto l15;
  case 11:
    return 14;
    goto l15;
  default:
    _failed_case(i0, 5581);
    goto l15;
  }
l15:
  _failed_function(5432); return 0;
  ;
}

OOC_INT8 OOC_SSA_Allocator__RegisterType(OOC_INT8 ctype) {
  register OOC_INT32 i0;

  i0 = ctype;
  switch (i0) {
  case 1:
  case 2 ... 4:
  case 6 ... 8:
    return 4;
    goto l7;
  case 5:
  case 9:
    return 5;
    goto l7;
  case 13:
    return 13;
    goto l7;
  case 14:
    return 14;
    goto l7;
  default:
    _failed_case(i0, 6689);
    goto l7;
  }
l7:
  _failed_function(6347); return 0;
  ;
}

static OOC_SSA_Allocator__RegisterFiles OOC_SSA_Allocator__GetRegisterFiles(void) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_SSA_Allocator__RegisterFiles rfs;
  OOC_INT32 i;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_SSA_Allocator__RegisterFiles.baseTypes[0], 15);
  rfs = (OOC_SSA_Allocator__RegisterFiles)i0;
  i = 0;
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 7431)), 0);
  i2 = 0<i1;
  if (!i2) goto l8;
  i2=0;
l3_loop:
  i3 = _check_pointer(i0, 7448);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  *(OOC_INT32*)(i3+(_check_index(i2, i4, OOC_UINT32, 7448))*4) = (OOC_INT32)0;
  i2 = i2+1;
  i = i2;
  i3 = i2<i1;
  if (i3) goto l3_loop;
l8:
  i1 = _check_pointer(i0, 7527);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i3 = (OOC_INT32)OOC_SSA_Allocator__NewRegisterFile(4);
  *(OOC_INT32*)(i1+(_check_index(4, i2, OOC_UINT8, 7527))*4) = i3;
  i1 = _check_pointer(i0, 7594);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i3 = (OOC_INT32)OOC_SSA_Allocator__NewRegisterFile(5);
  *(OOC_INT32*)(i1+(_check_index(5, i2, OOC_UINT8, 7594))*4) = i3;
  i1 = _check_pointer(i0, 7826);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i3 = (OOC_INT32)OOC_SSA_Allocator__NewRegisterFile(13);
  *(OOC_INT32*)(i1+(_check_index(13, i2, OOC_UINT8, 7826))*4) = i3;
  i1 = _check_pointer(i0, 7893);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i3 = (OOC_INT32)OOC_SSA_Allocator__NewRegisterFile(14);
  *(OOC_INT32*)(i1+(_check_index(14, i2, OOC_UINT8, 7893))*4) = i3;
  return (OOC_SSA_Allocator__RegisterFiles)i0;
  ;
}

static OOC_SSA_Allocator__RegisterFiles OOC_SSA_Allocator__IdentifyResults(OOC_SSA_Allocator__BlockList blockList, ADT_Dictionary__Dictionary inPlaceEval) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_SSA_Allocator__RegisterFiles rfs;
  OOC_INT32 i;
  auto void OOC_SSA_Allocator__IdentifyResults_ScanBlock(OOC_SSA_Schedule__Block b);
    
    void OOC_SSA_Allocator__IdentifyResults_ScanBlock(OOC_SSA_Schedule__Block b) {
      register OOC_INT32 i0,i1;
      OOC_SSA_Schedule__InstrProxy proxy;
      OOC_SSA__Instr instr;
      OOC_INT8 type;
      OOC_SSA__Result res;
      auto OOC_CHAR8 OOC_SSA_Allocator__IdentifyResults_ScanBlock_PassedThroughRegister(OOC_SSA__Instr instr);
      auto void OOC_SSA_Allocator__IdentifyResults_ScanBlock_RegisterResult(OOC_SSA__Result result, OOC_INT8 ctype);
        
        OOC_CHAR8 OOC_SSA_Allocator__IdentifyResults_ScanBlock_PassedThroughRegister(OOC_SSA__Instr instr) {
          register OOC_INT32 i0,i1;

          i0 = (OOC_INT32)instr;
          i1 = OOC_SSA__InstrDesc_IsConst((OOC_SSA__Instr)i0);
          i1 = !i1;
          if (i1) goto l3;
          i1=0u;
          goto l5;
l3:
          i1 = *(OOC_INT8*)((_check_pointer(i0, 9301))+36);
          i1 = i1!=13;
          
l5:
          if (i1) goto l7;
          i0=0u;
          goto l8;
l7:
          i0 = *(OOC_INT8*)((_check_pointer(i0, 9343))+36);
          i0 = i0!=72;
          
l8:
          return i0;
          ;
        }

        
        void OOC_SSA_Allocator__IdentifyResults_ScanBlock_RegisterResult(OOC_SSA__Result result, OOC_INT8 ctype) {
          register OOC_INT32 i0,i1,i2,i3,i4;
          OOC_INT8 rtype;

          i0 = ctype;
          i0 = OOC_SSA_Allocator__RegisterType(i0);
          rtype = i0;
          i1 = (OOC_INT32)result;
          i2 = (OOC_INT32)rfs;
          i3 = _check_pointer(i2, 9644);
          i4 = OOC_ARRAY_LENGTH(i3, 0);
          i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i0, i4, OOC_UINT8, 9644))*4);
          *(OOC_INT32*)((_check_pointer(i1, 9631))+16) = i3;
          i3 = _check_pointer(i2, 9682);
          i4 = OOC_ARRAY_LENGTH(i3, 0);
          i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i0, i4, OOC_UINT8, 9682))*4);
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 9689))+4);
          i3 = *(OOC_INT32*)((_check_pointer(i3, 9701))+4);
          *(OOC_INT32*)((_check_pointer(i1, 9667))+20) = i3;
          i3 = _check_pointer(i2, 9720);
          i4 = OOC_ARRAY_LENGTH(i3, 0);
          i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i0, i4, OOC_UINT8, 9720))*4);
          i2 = _check_pointer(i2, 9720);
          i4 = OOC_ARRAY_LENGTH(i2, 0);
          i2 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(i0, i4, OOC_UINT8, 9720))*4);
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 9727))+4);
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 9727))+4);
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 9739)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i3, (Object__Object)i1);
          i1 = (OOC_INT32)rfs;
          i2 = _check_pointer(i1, 9769);
          i3 = OOC_ARRAY_LENGTH(i2, 0);
          i2 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(i0, i3, OOC_UINT8, 9769))*4);
          i1 = _check_pointer(i1, 9769);
          i3 = OOC_ARRAY_LENGTH(i1, 0);
          i0 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(i0, i3, OOC_UINT8, 9769))*4);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9776))+8);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 9776))+8);
          i2 = (OOC_INT32)b;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9787)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i1, (Object__Object)i2);
          return;
          ;
        }


      i0 = (OOC_INT32)b;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9858))+8);
      proxy = (OOC_SSA_Schedule__InstrProxy)i0;
      i1 = i0!=(OOC_INT32)0;
      if (!i1) goto l30;
l3_loop:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9922))+12);
      instr = (OOC_SSA__Instr)i0;
      i1 = OOC_SSA__InstrDesc_GetResultType((OOC_SSA__Instr)i0);
      type = i1;
      i1 = i1!=0;
      if (i1) goto l6;
      i0=0u;
      goto l8;
l6:
      i0 = OOC_SSA_Allocator__IdentifyResults_ScanBlock_PassedThroughRegister((OOC_SSA__Instr)i0);
      
l8:
      if (!i0) goto l14;
      i0 = (OOC_INT32)instr;
      i1 = (OOC_INT32)inPlaceEval;
      i1 = ADT_Dictionary__DictionaryDesc_HasKey((ADT_Dictionary__Dictionary)i1, (Object__Object)i0);
      if (i1) goto l12;
      i1 = type;
      i1 = OOC_SSA_Allocator__SubclassToBasicType(i1);
      OOC_SSA_Allocator__IdentifyResults_ScanBlock_RegisterResult((OOC_SSA__Result)i0, i1);
      goto l14;
l12:
      i1 = (OOC_INT32)OOC_SSA_Allocator__markInPlace;
      *(OOC_INT32*)((_check_pointer(i0, 10117))+16) = i1;
l14:
      i0 = (OOC_INT32)instr;
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 10267));
      res = (OOC_SSA__Result)i0;
      i1 = i0!=(OOC_INT32)0;
      if (!i1) goto l25;
l17_loop:
      i1 = *(OOC_INT8*)((_check_pointer(i0, 10327))+5);
      i1 = i1!=0;
      if (!i1) goto l20;
      i1 = *(OOC_INT8*)((_check_pointer(i0, 10417))+5);
      i1 = OOC_SSA_Allocator__SubclassToBasicType(i1);
      OOC_SSA_Allocator__IdentifyResults_ScanBlock_RegisterResult((OOC_SSA__Result)i0, i1);
l20:
      i0 = (OOC_INT32)res;
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 10465));
      res = (OOC_SSA__Result)i0;
      i1 = i0!=(OOC_INT32)0;
      if (i1) goto l17_loop;
l25:
      i0 = (OOC_INT32)proxy;
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 10513));
      proxy = (OOC_SSA_Schedule__InstrProxy)i0;
      i1 = i0!=(OOC_INT32)0;
      if (i1) goto l3_loop;
l30:
      return;
      ;
    }


  i0 = (OOC_INT32)OOC_SSA_Allocator__GetRegisterFiles();
  rfs = (OOC_SSA_Allocator__RegisterFiles)i0;
  i0 = (OOC_INT32)blockList;
  i = 0;
  i0 = OOC_ARRAY_LENGTH((_check_pointer(i0, 10629)), 0);
  i1 = 0<i0;
  if (!i1) goto l8;
  i1=0;
l3_loop:
  i2 = (OOC_INT32)blockList;
  i2 = _check_pointer(i2, 10663);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i1 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(i1, i3, OOC_UINT32, 10663))*4);
  OOC_SSA_Allocator__IdentifyResults_ScanBlock((OOC_SSA_Schedule__Block)i1);
  i1 = i;
  i1 = i1+1;
  i = i1;
  i2 = i1<i0;
  if (i2) goto l3_loop;
l8:
  i0 = (OOC_INT32)rfs;
  return (OOC_SSA_Allocator__RegisterFiles)i0;
  ;
}

static void OOC_SSA_Allocator__AddToCollect(OOC_SSA_Schedule__Block loopHead, OOC_SSA__Result res) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_SSA_Schedule__InstrProxy loopStart;
  OOC_SSA__Result backwardFeed;
  OOC_SSA__Instr collect;
  OOC_SSA__Opnd opnd;

  i0 = (OOC_INT32)loopHead;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10933))+8);
  loopStart = (OOC_SSA_Schedule__InstrProxy)i0;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10966))+12);
  i1 = *(OOC_INT8*)((_check_pointer(i1, 10973))+36);
  i1 = i1!=10;
  if (!i1) goto l9;
l4_loop:
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 11033));
  loopStart = (OOC_SSA_Schedule__InstrProxy)i0;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10966))+12);
  i1 = *(OOC_INT8*)((_check_pointer(i1, 10973))+36);
  i1 = i1!=10;
  if (i1) goto l4_loop;
l9:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11083))+12);
  i0 = (OOC_INT32)OOC_SSA__InstrDesc_GetBackwardFeed((OOC_SSA__Instr)i0);
  backwardFeed = (OOC_SSA__Result)i0;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11138))+8);
  collect = (OOC_SSA__Instr)i0;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11166))+24);
  opnd = (OOC_SSA__Opnd)i1;
  i2 = i1!=0;
  if (i2) goto l12;
  i2=0u;
  goto l14;
l12:
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 11208));
  i3 = (OOC_INT32)res;
  i2 = i2!=i3;
  
l14:
  if (!i2) goto l26;
  i2 = (OOC_INT32)res;
  
l17_loop:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 11242))+8);
  opnd = (OOC_SSA__Opnd)i1;
  i3 = i1!=0;
  if (i3) goto l20;
  i3=0u;
  goto l22;
l20:
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 11208));
  i3 = i3!=i2;
  
l22:
  if (i3) goto l17_loop;
l26:
  i1 = i1==0;
  if (!i1) goto l29;
  i1 = (OOC_INT32)res;
  OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i0, (OOC_SSA__Result)i1, 17);
l29:
  return;
  ;
}

static OOC_SSA_Schedule__Block OOC_SSA_Allocator__SweepLiveSet(OOC_SSA_Allocator__RegisterFile rf, OOC_SSA_Schedule__Block b, OOC_SSA_IGraph__Vector live) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7;
  OOC_SSA_IGraph__Graph iGraph;
  OOC_SSA_Schedule__InstrProxy loopEnd;
  OOC_SSA_Schedule__InstrProxy proxy;
  OOC_SSA__Result res;
  OOC_SSA_Schedule__Block loopBlock;
  OOC_INT32 i;
  auto OOC_SSA_Schedule__Block OOC_SSA_Allocator__SweepLiveSet_GetLoop(OOC_SSA_Schedule__Block b, OOC_SSA__Instr loopStart);
  auto void OOC_SSA_Allocator__SweepLiveSet_MarkOpndAsLive(OOC_SSA__Instr instr, OOC_SSA_IGraph__Vector live);
  auto void OOC_SSA_Allocator__SweepLiveSet_AddResToLive(OOC_SSA__Result res, OOC_SSA_IGraph__Vector live);
    
    OOC_SSA_Schedule__Block OOC_SSA_Allocator__SweepLiveSet_GetLoop(OOC_SSA_Schedule__Block b, OOC_SSA__Instr loopStart) {
      register OOC_INT32 i0,i1,i2,i3;
      OOC_SSA_Schedule__Block child;
      auto OOC_CHAR8 OOC_SSA_Allocator__SweepLiveSet_GetLoop_ContainsInstr(OOC_SSA_Schedule__InstrProxy proxy, OOC_SSA__Instr instr);
        
        OOC_CHAR8 OOC_SSA_Allocator__SweepLiveSet_GetLoop_ContainsInstr(OOC_SSA_Schedule__InstrProxy proxy, OOC_SSA__Instr instr) {
          register OOC_INT32 i0,i1,i2;

          i0 = (OOC_INT32)proxy;
          i1 = i0!=(OOC_INT32)0;
          if (i1) goto l3;
          i1=0u;
          goto l5;
l3:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12289))+12);
          i2 = (OOC_INT32)instr;
          i1 = i1!=i2;
          
l5:
          if (!i1) goto l17;
          i1 = (OOC_INT32)instr;
          
l8_loop:
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 12333));
          proxy = (OOC_SSA_Schedule__InstrProxy)i0;
          i2 = i0!=(OOC_INT32)0;
          if (i2) goto l11;
          i2=0u;
          goto l13;
l11:
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12289))+12);
          i2 = i2!=i1;
          
l13:
          if (i2) goto l8_loop;
l17:
          return (i0!=(OOC_INT32)0);
          ;
        }


      i0 = (OOC_INT32)b;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12445))+16);
      child = (OOC_SSA_Schedule__Block)i1;
      i2 = i1!=(OOC_INT32)0;
      if (i2) goto l3;
      i2=0u;
      goto l5;
l3:
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 12505))+8);
      i3 = (OOC_INT32)loopStart;
      i2 = OOC_SSA_Allocator__SweepLiveSet_GetLoop_ContainsInstr((OOC_SSA_Schedule__InstrProxy)i2, (OOC_SSA__Instr)i3);
      i2 = !i2;
      
l5:
      if (!i2) goto l17;
      i2 = (OOC_INT32)loopStart;
      
l8_loop:
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 12554));
      child = (OOC_SSA_Schedule__Block)i1;
      i3 = i1!=(OOC_INT32)0;
      if (i3) goto l11;
      i3=0u;
      goto l13;
l11:
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 12505))+8);
      i3 = OOC_SSA_Allocator__SweepLiveSet_GetLoop_ContainsInstr((OOC_SSA_Schedule__InstrProxy)i3, (OOC_SSA__Instr)i2);
      i3 = !i3;
      
l13:
      if (i3) goto l8_loop;
l17:
      i2 = i1==(OOC_INT32)0;
      if (i2) goto l20;
      return (OOC_SSA_Schedule__Block)i1;
      goto l21;
l20:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12629))+4);
      i1 = (OOC_INT32)loopStart;
      i0 = (OOC_INT32)OOC_SSA_Allocator__SweepLiveSet_GetLoop((OOC_SSA_Schedule__Block)i0, (OOC_SSA__Instr)i1);
      return (OOC_SSA_Schedule__Block)i0;
l21:
      _failed_function(12047); return 0;
      ;
    }

    
    void OOC_SSA_Allocator__SweepLiveSet_MarkOpndAsLive(OOC_SSA__Instr instr, OOC_SSA_IGraph__Vector live) {
      register OOC_INT32 i0,i1,i2,i3;
      OOC_SSA__Opnd opnd;

      i0 = (OOC_INT32)instr;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12840))+24);
      opnd = (OOC_SSA__Opnd)i0;
      i1 = i0!=(OOC_INT32)0;
      if (!i1) goto l22;
      i1 = (OOC_INT32)live;
      
l3_loop:
      i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 12896));
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 12901))+16);
      i3 = (OOC_INT32)OOC_SSA_Allocator__markInPlace;
      i2 = i2==i3;
      if (i2) goto l16;
      i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 12998));
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 13003))+16);
      i3 = (OOC_INT32)rf;
      i2 = i2==i3;
      if (i2) goto l8;
      i2=0u;
      goto l10;
l8:
      i2 = OOC_SSA__OpndDesc_IsValueOpndHere((OOC_SSA__Opnd)i0);
      
l10:
      if (!i2) goto l17;
      i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 13077));
      i2 = *(OOC_INT32*)((_check_pointer(i2, 13082))+20);
      i3 = (OOC_INT32)iGraph;
      i2 = OOC_SSA_IGraph__GraphDesc_In((OOC_SSA_IGraph__Graph)i3, i2, (OOC_SSA_IGraph__Vector)i1);
      i2 = !i2;
      if (!i2) goto l17;
      i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 13361));
      i2 = *(OOC_INT32*)((_check_pointer(i2, 13366))+20);
      OOC_SSA_IGraph__GraphDesc_AddToLive((OOC_SSA_IGraph__Graph)i3, i2, (OOC_SSA_IGraph__Vector)i1);
      goto l17;
l16:
      i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 12958));
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 12963))+8);
      OOC_SSA_Allocator__SweepLiveSet_MarkOpndAsLive((OOC_SSA__Instr)i2, (OOC_SSA_IGraph__Vector)i1);
l17:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13429))+8);
      opnd = (OOC_SSA__Opnd)i0;
      i2 = i0!=(OOC_INT32)0;
      if (i2) goto l3_loop;
l22:
      return;
      ;
    }

    
    void OOC_SSA_Allocator__SweepLiveSet_AddResToLive(OOC_SSA__Result res, OOC_SSA_IGraph__Vector live) {
      register OOC_INT32 i0,i1,i2,i3;

      i0 = (OOC_INT32)res;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13564))+16);
      i2 = (OOC_INT32)OOC_SSA_Allocator__markInPlace;
      i1 = i1==i2;
      if (i1) goto l10;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13650))+16);
      i2 = (OOC_INT32)rf;
      i1 = i1==i2;
      if (i1) goto l5;
      i1=0u;
      goto l7;
l5:
      i1 = *(OOC_INT32*)((_check_pointer(i0, 13681))+20);
      i2 = (OOC_INT32)live;
      i3 = (OOC_INT32)iGraph;
      i1 = OOC_SSA_IGraph__GraphDesc_In((OOC_SSA_IGraph__Graph)i3, i1, (OOC_SSA_IGraph__Vector)i2);
      i1 = !i1;
      
l7:
      if (!i1) goto l11;
      i0 = *(OOC_INT32*)((_check_pointer(i0, 13732))+20);
      i1 = (OOC_INT32)live;
      i2 = (OOC_INT32)iGraph;
      OOC_SSA_IGraph__GraphDesc_AddToLive((OOC_SSA_IGraph__Graph)i2, i0, (OOC_SSA_IGraph__Vector)i1);
      goto l11;
l10:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13618))+8);
      i1 = (OOC_INT32)live;
      OOC_SSA_Allocator__SweepLiveSet_MarkOpndAsLive((OOC_SSA__Instr)i0, (OOC_SSA_IGraph__Vector)i1);
l11:
      return;
      ;
    }


  i0 = (OOC_INT32)rf;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14347))+12);
  iGraph = (OOC_SSA_IGraph__Graph)i0;
  i0 = (OOC_INT32)b;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14447)))), &_td_OOC_SSA_Schedule__BranchBlockDesc);
  if (!i1) goto l3;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14613))+52);
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 14624));
  i1 = (OOC_INT32)live;
  OOC_SSA_Allocator__SweepLiveSet_AddResToLive((OOC_SSA__Result)i0, (OOC_SSA_IGraph__Vector)i1);
l3:
  loopEnd = (OOC_SSA_Schedule__InstrProxy)0;
  i0 = (OOC_INT32)b;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14712))+12);
  proxy = (OOC_SSA_Schedule__InstrProxy)i0;
  i1 = i0!=0;
  if (!i1) goto l43;
l6_loop:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14767))+12);
  i1 = *(OOC_INT8*)((_check_pointer(i1, 14774))+36);
  i1 = i1==11;
  if (!i1) goto l9;
  loopEnd = (OOC_SSA_Schedule__InstrProxy)i0;
l9:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14868))+12);
  res = (OOC_SSA__Result)i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 14890))+16);
  i3 = (OOC_INT32)OOC_SSA_Allocator__markInPlace;
  i2 = i2!=i3;
  if (!i2) goto l38;
  i2 = (OOC_INT32)live;
  i3 = i1!=0;
  if (!i3) goto l26;
  i3 = (OOC_INT32)iGraph;
  i4 = (OOC_INT32)rf;
  
l14_loop:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 14963))+16);
  i5 = i5==i4;
  if (i5) goto l17;
  i5=0u;
  goto l19;
l17:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 14982))+12);
  i5 = i5==0;
  
l19:
  if (!i5) goto l21;
  i5 = *(OOC_INT32*)((_check_pointer(i1, 15411))+20);
  OOC_SSA_IGraph__GraphDesc_AddToLive((OOC_SSA_IGraph__Graph)i3, i5, (OOC_SSA_IGraph__Vector)i2);
l21:
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 15463));
  res = (OOC_SSA__Result)i1;
  i5 = i1!=0;
  if (i5) goto l14_loop;
l26:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15599))+12);
  res = (OOC_SSA__Result)i1;
  i3 = i1!=0;
  if (!i3) goto l37;
  i3 = (OOC_INT32)iGraph;
  i4 = (OOC_INT32)rf;
  
l29_loop:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 15654))+16);
  i5 = i5==i4;
  if (!i5) goto l32;
  i5 = *(OOC_INT32*)((_check_pointer(i1, 15711))+20);
  OOC_SSA_IGraph__GraphDesc_RemoveFromLive((OOC_SSA_IGraph__Graph)i3, i5, (OOC_SSA_IGraph__Vector)i2);
l32:
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 15763));
  res = (OOC_SSA__Result)i1;
  i5 = i1!=0;
  if (i5) goto l29_loop;
l37:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16354))+12);
  OOC_SSA_Allocator__SweepLiveSet_MarkOpndAsLive((OOC_SSA__Instr)i0, (OOC_SSA_IGraph__Vector)i2);
l38:
  i0 = (OOC_INT32)proxy;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16408))+4);
  proxy = (OOC_SSA_Schedule__InstrProxy)i0;
  i1 = i0!=0;
  if (i1) goto l6_loop;
l43:
  i0 = (OOC_INT32)b;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 16440)))), &_td_OOC_SSA_Schedule__SwitchBlockDesc);
  if (!i1) goto l46;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16615))+48);
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 16621));
  i1 = (OOC_INT32)live;
  OOC_SSA_Allocator__SweepLiveSet_AddResToLive((OOC_SSA__Result)i0, (OOC_SSA_IGraph__Vector)i1);
l46:
  i0 = (OOC_INT32)loopEnd;
  i1 = i0!=0;
  if (i1) goto l49;
  return (OOC_SSA_Schedule__Block)0;
  goto l65;
l49:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16870))+12);
  i1 = (OOC_INT32)OOC_SSA__InstrDesc_GetLoopStart((OOC_SSA__Instr)i1);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16818))+8);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16825))+4);
  i0 = (OOC_INT32)OOC_SSA_Allocator__SweepLiveSet_GetLoop((OOC_SSA_Schedule__Block)i0, (OOC_SSA__Instr)i1);
  loopBlock = (OOC_SSA_Schedule__Block)i0;
  i1 = (OOC_INT32)rf;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 16918))+4);
  i = 0;
  i2 = *(OOC_INT32*)((_check_pointer(i2, 16930))+4);
  i3 = 0<i2;
  if (!i3) goto l64;
  i3 = (OOC_INT32)live;
  i4 = (OOC_INT32)iGraph;
  i5=0;
l52_loop:
  i6 = OOC_SSA_IGraph__GraphDesc_In((OOC_SSA_IGraph__Graph)i4, i5, (OOC_SSA_IGraph__Vector)i3);
  if (i6) goto l55;
  i6=0u;
  goto l57;
l55:
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 17021))+8);
  i6 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i6, 17032));
  i6 = _check_pointer(i6, 17039);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)(i6+(_check_index(i5, i7, OOC_UINT32, 17039))*4);
  i6 = OOC_SSA_Schedule__Dominates((OOC_SSA_Schedule__Block)i0, (OOC_SSA_Schedule__Block)(_type_guard(i6, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 17052)))), &_td_OOC_SSA_Schedule__BlockDesc, 17052)));
  i6 = !i6;
  
l57:
  if (!i6) goto l59;
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 17102))+4);
  i6 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i6, 17114));
  i6 = _check_pointer(i6, 17121);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)(i6+(_check_index(i5, i7, OOC_UINT32, 17121))*4);
  OOC_SSA_Allocator__AddToCollect((OOC_SSA_Schedule__Block)i0, (OOC_SSA__Result)(_type_guard(i6, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 17129)))), &_td_OOC_SSA__ResultDesc, 17129)));
l59:
  i5 = i5+1;
  i = i5;
  i6 = i5<i2;
  if (i6) goto l52_loop;
l64:
  return (OOC_SSA_Schedule__Block)i0;
l65:
  _failed_function(11671); return 0;
  ;
}

static void OOC_SSA_Allocator__AssignRegisterFile(OOC_SSA_Allocator__RegisterFile rf, OOC_SSA_Schedule__Block enterBlock, OOC_SSA_Schedule__Block exitBlock, ADT_Dictionary__Dictionary registerMap) {
  register OOC_INT32 i0,i1,i2;
  OOC_SSA_IGraph__Vector live;
  auto void OOC_SSA_Allocator__AssignRegisterFile_AssignRegisterNames(OOC_SSA_Allocator__RegisterFile rf, OOC_SSA_IGraph__ColorArray colors, ADT_Dictionary__Dictionary registerMap);
  auto void OOC_SSA_Allocator__AssignRegisterFile_TraverseBlocks(OOC_SSA_Allocator__RegisterFile rf, OOC_SSA_Schedule__Block b, OOC_SSA_IGraph__Vector live);
    
    void OOC_SSA_Allocator__AssignRegisterFile_AssignRegisterNames(OOC_SSA_Allocator__RegisterFile rf, OOC_SSA_IGraph__ColorArray colors, ADT_Dictionary__Dictionary registerMap) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8,i9,i10;
      OOC_INT32 maxColor;
      OOC_INT32 i;
      OOC_SSA_Allocator__NameArray names;
      OOC_CHAR8 str[16];

      maxColor = (-1);
      i0 = (OOC_INT32)colors;
      i = 0;
      i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 17873)), 0);
      i2 = 0<i1;
      if (i2) goto l3;
      i1=(-1);
      goto l13;
l3:
      i2=0;i3=(-1);
l4_loop:
      i4 = _check_pointer(i0, 17899);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      i4 = *(OOC_INT32*)(i4+(_check_index(i2, i5, OOC_UINT32, 17899))*4);
      i4 = i4>i3;
      if (!i4) goto l8;
      i3 = _check_pointer(i0, 17948);
      i4 = OOC_ARRAY_LENGTH(i3, 0);
      i3 = *(OOC_INT32*)(i3+(_check_index(i2, i4, OOC_UINT32, 17948))*4);
      maxColor = i3;
      
l8:
      i2 = i2+1;
      i = i2;
      i4 = i2<i1;
      if (i4) goto l4_loop;
l12:
      i1=i3;
l13:
      i2 = (OOC_INT32)rf;
      *(OOC_INT32*)((_check_pointer(i2, 17984))+16) = i1;
      i3 = (OOC_INT32)RT0__NewObject(_td_OOC_SSA_Allocator__NameArray.baseTypes[0], (i1+1));
      names = (OOC_SSA_Allocator__NameArray)i3;
      i = 0;
      i4 = 0<=i1;
      if (!i4) goto l28;
      i4=0;
l16_loop:
      IntStr__IntToStr(i4, (void*)(OOC_INT32)str, 16);
      i5 = *(OOC_INT8*)(_check_pointer(i2, 18261));
      switch (i5) {
      case 4:
        Strings__Insert("i", 2, 0, (void*)(OOC_INT32)str, 16);
        goto l23;
      case 5:
        Strings__Insert("w", 2, 0, (void*)(OOC_INT32)str, 16);
        goto l23;
      case 13:
        Strings__Insert("f", 2, 0, (void*)(OOC_INT32)str, 16);
        goto l23;
      case 14:
        Strings__Insert("d", 2, 0, (void*)(OOC_INT32)str, 16);
        goto l23;
      default:
        _failed_case(i5, 18254);
        goto l23;
      }
l23:
      i5 = _check_pointer(i3, 18727);
      i6 = OOC_ARRAY_LENGTH(i5, 0);
      i7 = (OOC_INT32)Object__NewLatin1((void*)(OOC_INT32)str, 16);
      *(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 18727))*4) = i7;
      i4 = i4+1;
      i = i4;
      i5 = i4<=i1;
      if (i5) goto l16_loop;
l28:
      *(OOC_INT32*)((_check_pointer(i2, 18776))+20) = i3;
      i = 0;
      i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 18890)), 0);
      i4 = 0<i1;
      if (!i4) goto l36;
      i4 = (OOC_INT32)registerMap;
      i5=0;
l31_loop:
      i6 = _check_pointer(i3, 18993);
      i7 = _check_pointer(i0, 19000);
      i8 = OOC_ARRAY_LENGTH(i7, 0);
      i7 = *(OOC_INT32*)(i7+(_check_index(i5, i8, OOC_UINT32, 19000))*4);
      i8 = OOC_ARRAY_LENGTH(i6, 0);
      i9 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 18926))+4);
      i9 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i9, 18938));
      i9 = _check_pointer(i9, 18945);
      i10 = OOC_ARRAY_LENGTH(i9, 0);
      i9 = (OOC_INT32)*(OOC_INT32*)(i9+(_check_index(i5, i10, OOC_UINT32, 18945))*4);
      i6 = (OOC_INT32)*(OOC_INT32*)(i6+(_check_index(i7, i8, OOC_UINT32, 18993))*4);
      ADT_Dictionary__DictionaryDesc_Set((ADT_Dictionary__Dictionary)i4, (Object__Object)(_type_guard(i9, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i9, 18953)))), &_td_OOC_SSA__ResultDesc, 18953)), (Object__Object)i6);
      i5 = i5+1;
      i = i5;
      i6 = i5<i1;
      if (i6) goto l31_loop;
l36:
      return;
      ;
    }

    
    void OOC_SSA_Allocator__AssignRegisterFile_TraverseBlocks(OOC_SSA_Allocator__RegisterFile rf, OOC_SSA_Schedule__Block b, OOC_SSA_IGraph__Vector live) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5;
      OOC_INT32 outgoingJumps;
      OOC_SSA_Allocator__LiveData ld;
      OOC_INT32 i;
      OOC_SSA_Schedule__Block loopBlock;
      auto void OOC_SSA_Allocator__AssignRegisterFile_TraverseBlocks_Propagate(OOC_SSA_Schedule__Jump jump, OOC_SSA_Schedule__Block loopBlock);
      auto OOC_CHAR8 OOC_SSA_Allocator__AssignRegisterFile_TraverseBlocks_BackedgeJump(OOC_SSA_Schedule__Jump jump);
      auto void OOC_SSA_Allocator__AssignRegisterFile_TraverseBlocks_Merge(OOC_SSA_Allocator__LiveData ld);
        
        void OOC_SSA_Allocator__AssignRegisterFile_TraverseBlocks_Propagate(OOC_SSA_Schedule__Jump jump, OOC_SSA_Schedule__Block loopBlock) {
          register OOC_INT32 i0,i1,i2,i3;
          OOC_SSA_Schedule__Jump loopTarget;

          i0 = (OOC_INT32)jump;
          i1 = i0!=(OOC_INT32)0;
          if (!i1) goto l11;
l3_loop:
          i1 = *(OOC_UINT8*)((_check_pointer(i0, 19907))+12);
          i1 = !i1;
          if (!i1) goto l6;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20004))+4);
          i2 = (OOC_INT32)b;
          _assert((i1==i2), 127, 19992);
          i1 = (OOC_INT32)rf;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 20062))+12);
          i2 = (OOC_INT32)live;
          i1 = (OOC_INT32)OOC_SSA_IGraph__GraphDesc_CopyVector((OOC_SSA_IGraph__Graph)i1, (OOC_SSA_IGraph__Vector)i2);
          i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 20053));
          i3 = (OOC_INT32)rf;
          OOC_SSA_Allocator__AssignRegisterFile_TraverseBlocks((OOC_SSA_Allocator__RegisterFile)i3, (OOC_SSA_Schedule__Block)i2, (OOC_SSA_IGraph__Vector)i1);
l6:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20129))+8);
          jump = (OOC_SSA_Schedule__Jump)i0;
          i1 = i0!=(OOC_INT32)0;
          if (i1) goto l3_loop;
l11:
          i0 = (OOC_INT32)loopBlock;
          i1 = i0!=(OOC_INT32)0;
          if (!i1) goto l34;
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20450))+32);
          loopTarget = (OOC_SSA_Schedule__Jump)i0;
          i1 = i0!=(OOC_INT32)0;
          if (i1) goto l16;
          i1=0u;
          goto l18;
l16:
          i1 = *(OOC_UINT8*)((_check_pointer(i0, 20515))+12);
          i1 = !i1;
          
l18:
          if (!i1) goto l30;
l21_loop:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20571))+8);
          loopTarget = (OOC_SSA_Schedule__Jump)i0;
          i1 = i0!=(OOC_INT32)0;
          if (i1) goto l24;
          i1=0u;
          goto l26;
l24:
          i1 = *(OOC_UINT8*)((_check_pointer(i0, 20515))+12);
          i1 = !i1;
          
l26:
          if (i1) goto l21_loop;
l30:
          i1 = i0!=(OOC_INT32)0;
          if (!i1) goto l34;
          i1 = (OOC_INT32)rf;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 20691))+12);
          i1 = (OOC_INT32)OOC_SSA_IGraph__GraphDesc_NewVector((OOC_SSA_IGraph__Graph)i1);
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 20682));
          i2 = (OOC_INT32)rf;
          OOC_SSA_Allocator__AssignRegisterFile_TraverseBlocks((OOC_SSA_Allocator__RegisterFile)i2, (OOC_SSA_Schedule__Block)i0, (OOC_SSA_IGraph__Vector)i1);
l34:
          return;
          ;
        }

        
        OOC_CHAR8 OOC_SSA_Allocator__AssignRegisterFile_TraverseBlocks_BackedgeJump(OOC_SSA_Schedule__Jump jump) {
          register OOC_INT32 i0,i1;

          i0 = (OOC_INT32)jump;
          i1 = i0==(OOC_INT32)0;
          if (i1) goto l7;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20896))+4);
          i1 = *(OOC_UINT8*)((_check_pointer(i1, 20902))+28);
          if (i1) goto l5;
          i0=0u;
          goto l8;
l5:
          i0 = *(OOC_UINT8*)((_check_pointer(i0, 20921))+12);
          
          goto l8;
l7:
          i0=1u;
l8:
          return i0;
          ;
        }

        
        void OOC_SSA_Allocator__AssignRegisterFile_TraverseBlocks_Merge(OOC_SSA_Allocator__LiveData ld) {
          register OOC_INT32 i0,i1,i2,i3;

          i0 = (OOC_INT32)ld;
          i1 = (OOC_INT32)rf;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 21022))+12);
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21053))+8);
          i3 = (OOC_INT32)live;
          OOC_SSA_IGraph__GraphDesc_MergeVector((OOC_SSA_IGraph__Graph)i1, (OOC_SSA_IGraph__Vector)i3, (OOC_SSA_IGraph__Vector)i2);
          i1 = *(OOC_INT32*)((_check_pointer(i0, 21077))+4);
          *(OOC_INT32*)((_check_pointer(i0, 21077))+4) = (i1+1);
          i1 = *(OOC_INT32*)(_check_pointer(i0, 21128));
          i2 = *(OOC_INT32*)((_check_pointer(i0, 21110))+4);
          _assert((i2<=i1), 127, 21100);
          i1 = *(OOC_INT32*)((_check_pointer(i0, 21169))+4);
          i2 = *(OOC_INT32*)(_check_pointer(i0, 21186));
          i1 = i1==i2;
          if (!i1) goto l6;
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21228))+8);
          live = (OOC_SSA_IGraph__Vector)i0;
          i1 = (OOC_INT32)b;
          i2 = (OOC_INT32)rf;
          i0 = (OOC_INT32)OOC_SSA_Allocator__SweepLiveSet((OOC_SSA_Allocator__RegisterFile)i2, (OOC_SSA_Schedule__Block)i1, (OOC_SSA_IGraph__Vector)i0);
          loopBlock = (OOC_SSA_Schedule__Block)i0;
          i1 = (OOC_INT32)enterBlock;
          i2 = (OOC_INT32)b;
          i1 = i2!=i1;
          if (!i1) goto l5;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 21346))+32);
          OOC_SSA_Allocator__AssignRegisterFile_TraverseBlocks_Propagate((OOC_SSA_Schedule__Jump)i1, (OOC_SSA_Schedule__Block)i0);
l5:
          i0 = (OOC_INT32)b;
          *(OOC_INT32*)((_check_pointer(i0, 21400))+44) = 0;
l6:
          return;
          ;
        }


      i0 = (OOC_INT32)b;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 21892)))), &_td_OOC_SSA_Schedule__BranchBlockDesc);
      if (i1) goto l27;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 22332)))), &_td_OOC_SSA_Schedule__SwitchBlockDesc);
      if (i1) goto l8;
      i1 = (OOC_INT32)live;
      i2 = (OOC_INT32)rf;
      i1 = (OOC_INT32)OOC_SSA_Allocator__SweepLiveSet((OOC_SSA_Allocator__RegisterFile)i2, (OOC_SSA_Schedule__Block)i0, (OOC_SSA_IGraph__Vector)i1);
      loopBlock = (OOC_SSA_Schedule__Block)i1;
      i2 = (OOC_INT32)enterBlock;
      i2 = i0!=i2;
      if (!i2) goto l40;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22910))+32);
      OOC_SSA_Allocator__AssignRegisterFile_TraverseBlocks_Propagate((OOC_SSA_Schedule__Jump)i0, (OOC_SSA_Schedule__Block)i1);
      goto l40;
l8:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22371))+44);
      i1 = i1==(OOC_INT32)0;
      if (i1) goto l11;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22701))+44);
      i0 = _type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 22708)))), &_td_OOC_SSA_Allocator__LiveDataDesc, 22708);
      ld = (OOC_SSA_Allocator__LiveData)i0;
      
      goto l25;
l11:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22423))+52);
      i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 22429)), 0);
      outgoingJumps = i1;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22463))+52);
      i = 0;
      i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 22469)), 0);
      i3 = 0<i2;
      if (!i3) goto l24;
      i3=i1;i1=0;
l15_loop:
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22507))+52);
      i4 = _check_pointer(i4, 22513);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i1, i5, OOC_UINT32, 22513))*4);
      i4 = OOC_SSA_Allocator__AssignRegisterFile_TraverseBlocks_BackedgeJump((OOC_SSA_Schedule__Jump)i4);
      if (!i4) goto l19;
      i3 = i3-1;
      outgoingJumps = i3;
      
l19:
      i1 = i1+1;
      i = i1;
      i4 = i1<i2;
      if (i4) goto l15_loop;
l23:
      i1=i3;
l24:
      i2 = (OOC_INT32)rf;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 22621))+12);
      i1 = (OOC_INT32)OOC_SSA_Allocator__NewLiveData((OOC_SSA_IGraph__Graph)i2, i1);
      ld = (OOC_SSA_Allocator__LiveData)i1;
      *(OOC_INT32*)((_check_pointer(i0, 22658))+44) = i1;
      i0=i1;
l25:
      OOC_SSA_Allocator__AssignRegisterFile_TraverseBlocks_Merge((OOC_SSA_Allocator__LiveData)i0);
      goto l40;
l27:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21931))+44);
      i1 = i1==(OOC_INT32)0;
      if (i1) goto l30;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22271))+44);
      i0 = _type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 22278)))), &_td_OOC_SSA_Allocator__LiveDataDesc, 22278);
      ld = (OOC_SSA_Allocator__LiveData)i0;
      
      goto l39;
l30:
      outgoingJumps = 2;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22008))+60);
      i1 = OOC_SSA_Allocator__AssignRegisterFile_TraverseBlocks_BackedgeJump((OOC_SSA_Schedule__Jump)i1);
      if (i1) goto l33;
      i1=2;
      goto l34;
l33:
      outgoingJumps = 1;
      i1=1;
l34:
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22100))+48);
      i2 = OOC_SSA_Allocator__AssignRegisterFile_TraverseBlocks_BackedgeJump((OOC_SSA_Schedule__Jump)i2);
      if (!i2) goto l38;
      i1 = i1-1;
      outgoingJumps = i1;
      
l38:
      i2 = (OOC_INT32)rf;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 22191))+12);
      i1 = (OOC_INT32)OOC_SSA_Allocator__NewLiveData((OOC_SSA_IGraph__Graph)i2, i1);
      ld = (OOC_SSA_Allocator__LiveData)i1;
      *(OOC_INT32*)((_check_pointer(i0, 22228))+44) = i1;
      i0=i1;
l39:
      OOC_SSA_Allocator__AssignRegisterFile_TraverseBlocks_Merge((OOC_SSA_Allocator__LiveData)i0);
l40:
      return;
      ;
    }


  i0 = (OOC_INT32)rf;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23649))+4);
  i1 = *(OOC_INT32*)((_check_pointer(i1, 23661))+4);
  i1 = (OOC_INT32)OOC_SSA_IGraph__NewGraph(i1);
  *(OOC_INT32*)((_check_pointer(i0, 23618))+12) = i1;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23974))+12);
  i1 = (OOC_INT32)OOC_SSA_IGraph__GraphDesc_NewVector((OOC_SSA_IGraph__Graph)i1);
  live = (OOC_SSA_IGraph__Vector)i1;
  i2 = (OOC_INT32)exitBlock;
  OOC_SSA_Allocator__AssignRegisterFile_TraverseBlocks((OOC_SSA_Allocator__RegisterFile)i0, (OOC_SSA_Schedule__Block)i2, (OOC_SSA_IGraph__Vector)i1);
  i0 = (OOC_INT32)rf;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24045))+12);
  OOC_SSA_IGraph__GraphDesc_SymmetricMatrix((OOC_SSA_IGraph__Graph)i1);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24277))+12);
  i1 = (OOC_INT32)OOC_SSA_IGraph__GraphDesc_ColorGraphSimple((OOC_SSA_IGraph__Graph)i1);
  i2 = (OOC_INT32)registerMap;
  OOC_SSA_Allocator__AssignRegisterFile_AssignRegisterNames((OOC_SSA_Allocator__RegisterFile)i0, (OOC_SSA_IGraph__ColorArray)i1, (ADT_Dictionary__Dictionary)i2);
  return;
  ;
}

static void OOC_SSA_Allocator__CollectCrossLoopResults(OOC_SSA_Allocator__RegisterFile rf, OOC_SSA_Schedule__Block b, OOC_SSA_Schedule__Block closestLoop) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8,i9;
  OOC_SSA_Schedule__InstrProxy proxy;
  OOC_SSA__Opnd opnd;
  OOC_SSA_Schedule__Block loop;
  OOC_SSA_Schedule__Block child;

  i0 = (OOC_INT32)b;
  i1 = *(OOC_UINT8*)((_check_pointer(i0, 24627))+28);
  if (!i1) goto l3;
  closestLoop = (OOC_SSA_Schedule__Block)i0;
l3:
  i1 = (OOC_INT32)closestLoop;
  i2 = i1!=(OOC_INT32)0;
  if (!i2) goto l54;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24726))+8);
  proxy = (OOC_SSA_Schedule__InstrProxy)i3;
  i4 = i3!=(OOC_INT32)0;
  if (!i4) goto l54;
  i4 = (OOC_INT32)rf;
  
l8_loop:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 24789))+12);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 24796))+24);
  opnd = (OOC_SSA__Opnd)i5;
  i6 = i5!=(OOC_INT32)0;
  if (!i6) goto l48;
l11_loop:
  i6 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i5, 24856));
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i6, 24861))+16);
  i6 = i6==i4;
  if (i6) goto l14;
  i6=0u;
  goto l16;
l14:
  i6 = OOC_SSA__OpndDesc_IsValueOpnd((OOC_SSA__Opnd)i5);
  
l16:
  if (!i6) goto l43;
  loop = (OOC_SSA_Schedule__Block)i1;
  if (i2) goto l20;
  i6=0u;
  goto l22;
l20:
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 25232))+8);
  i6 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i6, 25243));
  i6 = _check_pointer(i6, 25250);
  i7 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i5, 25255));
  i7 = *(OOC_INT32*)((_check_pointer(i7, 25260))+20);
  i8 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)(i6+(_check_index(i7, i8, OOC_UINT32, 25250))*4);
  i6 = OOC_SSA_Schedule__Dominates((OOC_SSA_Schedule__Block)i1, (OOC_SSA_Schedule__Block)(_type_guard(i6, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 25279)))), &_td_OOC_SSA_Schedule__BlockDesc, 25279)));
  i6 = !i6;
  
l22:
  if (!i6) goto l43;
  i6=i1;
l24_loop:
  i7 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i5, 25328));
  OOC_SSA_Allocator__AddToCollect((OOC_SSA_Schedule__Block)i6, (OOC_SSA__Result)i7);
  
l25_loop:
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i6, 25385))+4);
  loop = (OOC_SSA_Schedule__Block)i6;
  i7 = i6==(OOC_INT32)0;
  if (i7) goto l28;
  i7 = *(OOC_UINT8*)((_check_pointer(i6, 25435))+28);
  
  goto l30;
l28:
  i7=1u;
l30:
  if (!i7) goto l25_loop;
l33:
  i7 = i6!=(OOC_INT32)0;
  if (i7) goto l36;
  i7=0u;
  goto l38;
l36:
  i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 25232))+8);
  i7 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i7, 25243));
  i7 = _check_pointer(i7, 25250);
  i8 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i5, 25255));
  i8 = *(OOC_INT32*)((_check_pointer(i8, 25260))+20);
  i9 = OOC_ARRAY_LENGTH(i7, 0);
  i7 = (OOC_INT32)*(OOC_INT32*)(i7+(_check_index(i8, i9, OOC_UINT32, 25250))*4);
  i7 = OOC_SSA_Schedule__Dominates((OOC_SSA_Schedule__Block)i6, (OOC_SSA_Schedule__Block)(_type_guard(i7, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i7, 25279)))), &_td_OOC_SSA_Schedule__BlockDesc, 25279)));
  i7 = !i7;
  
l38:
  if (i7) goto l24_loop;
l43:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 25503))+8);
  opnd = (OOC_SSA__Opnd)i5;
  i6 = i5!=(OOC_INT32)0;
  if (i6) goto l11_loop;
l48:
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 25550));
  proxy = (OOC_SSA_Schedule__InstrProxy)i3;
  i5 = i3!=(OOC_INT32)0;
  if (i5) goto l8_loop;
l54:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25602))+16);
  child = (OOC_SSA_Schedule__Block)i0;
  i2 = i0!=(OOC_INT32)0;
  if (!i2) goto l62;
  i2 = (OOC_INT32)rf;
  
l57_loop:
  OOC_SSA_Allocator__CollectCrossLoopResults((OOC_SSA_Allocator__RegisterFile)i2, (OOC_SSA_Schedule__Block)i0, (OOC_SSA_Schedule__Block)i1);
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 25716));
  child = (OOC_SSA_Schedule__Block)i0;
  i3 = i0!=(OOC_INT32)0;
  if (i3) goto l57_loop;
l62:
  return;
  ;
}

ADT_Dictionary__Dictionary OOC_SSA_Allocator__AssignRegisters(OOC_SSA__ProcBlock pb, OOC_SSA_Schedule__Block domRoot, OOC_C_DeclWriter__Writer w) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
  ADT_Dictionary__Dictionary inPlaceEval;
  OOC_SSA_Schedule__Block exitBlock;
  OOC_SSA_Schedule__Block enterBlock;
  OOC_SSA_Allocator__BlockList blockList;
  OOC_SSA_Allocator__RegisterFiles rfs;
  OOC_INT32 i;
  ADT_Dictionary__Dictionary registerMap;
  Object__ObjectArrayPtr keys;
  auto void OOC_SSA_Allocator__AssignRegisters_WriteNames(OOC_C_DeclWriter__Writer w, OOC_INT8 registerType, OOC_SSA_Allocator__NameArray names);
  auto void OOC_SSA_Allocator__AssignRegisters_ClearBlockInfo(OOC_SSA_Allocator__BlockList blockList);
  auto void OOC_SSA_Allocator__AssignRegisters_CheckRegisters(OOC_SSA_Schedule__Block root, ADT_Dictionary__Dictionary registerMap);
  auto ADT_Dictionary__Dictionary OOC_SSA_Allocator__AssignRegisters_InPlaceEval(OOC_SSA__ProcBlock pb);
    
    void OOC_SSA_Allocator__AssignRegisters_WriteNames(OOC_C_DeclWriter__Writer w, OOC_INT8 registerType, OOC_SSA_Allocator__NameArray names) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5;
      OOC_INT32 i;

      i0 = (OOC_INT32)names;
      i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 26689)), 0);
      i1 = i1!=0;
      if (!i1) goto l14;
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 26711)))), OOC_C_DeclWriter__WriterDesc_Newline)),OOC_C_DeclWriter__WriterDesc_Newline)((OOC_C_DeclWriter__Writer)i1);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 26731)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "register ", 10);
      i2 = registerType;
      i2 = (OOC_INT32)*(OOC_INT32*)(((_check_pointer(i1, 26785))+24)+(_check_index(i2, 17, OOC_UINT8, 26796))*4);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 26769)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, (void*)((_check_pointer(i2, 26810))+1), 32);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 26828)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i1, 32u);
      i = 0;
      i2 = OOC_ARRAY_LENGTH((_check_pointer(i0, 26880)), 0);
      i3 = 0<i2;
      if (!i3) goto l13;
      i3=0;
l5_loop:
      i4 = i3!=0;
      if (!i4) goto l8;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 26927)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i1, 44u);
l8:
      i4 = _check_pointer(i0, 26992);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 26992))*4);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 26972)))), OOC_C_DeclWriter__WriterDesc_WriteObject)),OOC_C_DeclWriter__WriterDesc_WriteObject)((OOC_C_DeclWriter__Writer)i1, (Object__Object)i4);
      i3 = i3+1;
      i = i3;
      i4 = i3<i2;
      if (i4) goto l5_loop;
l13:
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 27020)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i1, 59u);
l14:
      return;
      ;
    }

    
    void OOC_SSA_Allocator__AssignRegisters_ClearBlockInfo(OOC_SSA_Allocator__BlockList blockList) {
      register OOC_INT32 i0,i1,i2,i3,i4;
      OOC_INT32 i;

      i0 = (OOC_INT32)blockList;
      i = 0;
      i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 27192)), 0);
      i2 = 0<i1;
      if (!i2) goto l8;
      i2=0;
l3_loop:
      i3 = _check_pointer(i0, 27217);
      i4 = OOC_ARRAY_LENGTH(i3, 0);
      i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i2, i4, OOC_UINT32, 27217))*4);
      *(OOC_INT32*)((_check_pointer(i3, 27220))+44) = (OOC_INT32)0;
      i2 = i2+1;
      i = i2;
      i3 = i2<i1;
      if (i3) goto l3_loop;
l8:
      return;
      ;
    }

    
    void OOC_SSA_Allocator__AssignRegisters_CheckRegisters(OOC_SSA_Schedule__Block root, ADT_Dictionary__Dictionary registerMap) {
      register OOC_INT32 i0,i1,i2;
      OOC_SSA__Result undefinedVar;
      OOC_SSA_Allocator__BlockInfo ready;
      OOC_SSA_Allocator__BlockInfo current;
      auto void OOC_SSA_Allocator__AssignRegisters_CheckRegisters_ScanBlock(OOC_SSA_Schedule__Block b);
      auto void OOC_SSA_Allocator__AssignRegisters_CheckRegisters_CheckBlock(OOC_SSA_Allocator__BlockInfo bi, ADT_Dictionary__Dictionary state);
        
        void OOC_SSA_Allocator__AssignRegisters_CheckRegisters_ScanBlock(OOC_SSA_Schedule__Block b) {
          register OOC_INT32 i0,i1,i2;
          OOC_SSA_Allocator__BlockInfo bi;
          OOC_SSA_Schedule__Block child;
          auto OOC_SSA__Instr OOC_SSA_Allocator__AssignRegisters_CheckRegisters_ScanBlock_MergeInstr(OOC_SSA_Schedule__InstrProxy proxy);
            
            OOC_SSA__Instr OOC_SSA_Allocator__AssignRegisters_CheckRegisters_ScanBlock_MergeInstr(OOC_SSA_Schedule__InstrProxy proxy) {
              register OOC_INT32 i0,i1;

              i0 = (OOC_INT32)proxy;
              i1 = i0!=(OOC_INT32)0;
              if (!i1) goto l12;
              
l3_loop:
              i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 27707))+12);
              i1 = *(OOC_INT8*)((_check_pointer(i1, 27714))+36);
              switch (i1) {
              case 5:
              case 10:
              case 11:
                i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 27815))+12);
                return (OOC_SSA__Instr)i1;
                goto l7;
              default:
                goto l7;
              }
l7:
              i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 27884));
              proxy = (OOC_SSA_Schedule__InstrProxy)i0;
              i1 = i0!=(OOC_INT32)0;
              if (i1) goto l3_loop;
l12:
              return (OOC_SSA__Instr)(OOC_INT32)0;
              ;
            }


          i0 = (OOC_INT32)RT0__NewObject(_td_OOC_SSA_Allocator__BlockInfo.baseTypes[0]);
          bi = (OOC_SSA_Allocator__BlockInfo)i0;
          OOC_SSA_Schedule__InitInfo((OOC_SSA_Schedule__Info)i0);
          *(OOC_INT32*)(_check_pointer(i0, 28037)) = 0;
          i1 = (OOC_INT32)b;
          *(OOC_INT32*)((_check_pointer(i0, 28066))+4) = i1;
          *(OOC_INT32*)((_check_pointer(i0, 28090))+12) = 0;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 28149))+8);
          i2 = (OOC_INT32)OOC_SSA_Allocator__AssignRegisters_CheckRegisters_ScanBlock_MergeInstr((OOC_SSA_Schedule__InstrProxy)i2);
          *(OOC_INT32*)((_check_pointer(i0, 28120))+8) = i2;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 28176))+4);
          i2 = i2==0;
          if (i2) goto l3;
          i2 = *(OOC_INT32*)((_check_pointer(i1, 28349))+36);
          *(OOC_INT32*)((_check_pointer(i0, 28336))+24) = i2;
          goto l4;
l3:
          i2 = (OOC_INT32)root;
          _assert((i1==i2), 127, 28253);
          i2 = *(OOC_INT32*)((_check_pointer(i1, 28297))+36);
          *(OOC_INT32*)((_check_pointer(i0, 28284))+24) = (i2-1);
l4:
          i2 = *(OOC_INT32*)((_check_pointer(i0, 28388))+24);
          i2 = i2>1;
          if (!i2) goto l7;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 28427))+8);
          _assert((i2!=0), 127, 28417);
l7:
          i2 = *(OOC_INT32*)((_check_pointer(i0, 28491))+24);
          *(OOC_INT32*)((_check_pointer(i0, 28476))+16) = ((OOC_INT32)RT0__NewObject(_td_OOC_SSA_Allocator__3150.baseTypes[0], i2));
          i2 = *(OOC_INT32*)((_check_pointer(i0, 28530))+24);
          *(OOC_INT32*)((_check_pointer(i0, 28517))+20) = ((OOC_INT32)RT0__NewObject(_td_OOC_SSA_Allocator__3194.baseTypes[0], i2));
          i2 = *(OOC_INT32*)((_check_pointer(i0, 28564))+24);
          i2 = i2==0;
          if (!i2) goto l18;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 28598))+4);
          i2 = i2==0;
          if (i2) goto l16;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 28962))+16);
          i2 = i2==0;
          if (i2) goto l14;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 29004))+16);
          i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 29014)))), &_td_OOC_SSA_Schedule__DeadEndBlockDesc);
          
          goto l15;
l14:
          i2=1u;
l15:
          _assert(i2, 127, 28952);
          goto l18;
l16:
          i2 = (OOC_INT32)ready;
          *(OOC_INT32*)(_check_pointer(i0, 28766)) = i2;
          ready = (OOC_SSA_Allocator__BlockInfo)i0;
          *(OOC_INT32*)((_check_pointer(i0, 28826))+16) = 0;
          *(OOC_INT32*)((_check_pointer(i0, 28860))+20) = 0;
          i2 = (OOC_INT32)ADT_Dictionary__New();
          *(OOC_INT32*)((_check_pointer(i0, 28892))+12) = i2;
l18:
          *(OOC_INT32*)((_check_pointer(i1, 29508))+44) = i0;
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 29541))+16);
          child = (OOC_SSA_Schedule__Block)i0;
          i1 = i0!=0;
          if (!i1) goto l26;
l21_loop:
          OOC_SSA_Allocator__AssignRegisters_CheckRegisters_ScanBlock((OOC_SSA_Schedule__Block)i0);
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 29636));
          child = (OOC_SSA_Schedule__Block)i0;
          i1 = i0!=0;
          if (i1) goto l21_loop;
l26:
          return;
          ;
        }

        
        void OOC_SSA_Allocator__AssignRegisters_CheckRegisters_CheckBlock(OOC_SSA_Allocator__BlockInfo bi, ADT_Dictionary__Dictionary state) {
          register OOC_INT32 i0,i1,i2,i3;
          OOC_SSA__Instr collect;
          OOC_SSA_Schedule__Block b;
          OOC_SSA_Schedule__InstrProxy proxy;
          OOC_SSA__Result res;
          OOC_INT32 i;
          auto void OOC_SSA_Allocator__AssignRegisters_CheckRegisters_CheckBlock_UpdateTarget(OOC_SSA_Schedule__Jump jump, ADT_Dictionary__Dictionary state, OOC_SSA__Instr collect);
          auto void OOC_SSA_Allocator__AssignRegisters_CheckRegisters_CheckBlock_CheckOpndList(OOC_SSA__Instr instr);
          auto void OOC_SSA_Allocator__AssignRegisters_CheckRegisters_CheckBlock_CheckOpnd(OOC_SSA__Opnd opnd);
          auto void OOC_SSA_Allocator__AssignRegisters_CheckRegisters_CheckBlock_CheckOpndList(OOC_SSA__Instr instr);
            
            void OOC_SSA_Allocator__AssignRegisters_CheckRegisters_CheckBlock_UpdateTarget(OOC_SSA_Schedule__Jump jump, ADT_Dictionary__Dictionary state, OOC_SSA__Instr collect) {
              register OOC_INT32 i0,i1,i2,i3,i4;
              OOC_SSA_Allocator__BlockInfo di;
              auto ADT_Dictionary__Dictionary OOC_SSA_Allocator__AssignRegisters_CheckRegisters_CheckBlock_UpdateTarget_MergeVariables(OOC_SSA_Allocator__BlockInfo di);
                
                ADT_Dictionary__Dictionary OOC_SSA_Allocator__AssignRegisters_CheckRegisters_CheckBlock_UpdateTarget_MergeVariables(OOC_SSA_Allocator__BlockInfo di) {
                  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8,i9,i10;
                  ADT_Dictionary__Dictionary allVarsMap;
                  OOC_INT32 i;
                  Object__ObjectArrayPtr vars;
                  OOC_INT32 j;
                  ADT_Dictionary__Dictionary outState;
                  Object__Object value;

                  i0 = (OOC_INT32)ADT_Dictionary__New();
                  allVarsMap = (ADT_Dictionary__Dictionary)i0;
                  i1 = (OOC_INT32)di;
                  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 30830))+20);
                  i = 0;
                  i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 30839)), 0);
                  i3 = 0<i2;
                  if (!i3) goto l16;
                  i3=0;
l3_loop:
                  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 30871))+20);
                  i4 = _check_pointer(i4, 30880);
                  i5 = OOC_ARRAY_LENGTH(i4, 0);
                  i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 30880))*4);
                  i4 = (OOC_INT32)ADT_Dictionary__DictionaryDesc_Keys((ADT_Dictionary__Dictionary)i4);
                  vars = (Object__ObjectArrayPtr)i4;
                  j = 0;
                  i5 = OOC_ARRAY_LENGTH((_check_pointer(i4, 30930)), 0);
                  i6 = 0<i5;
                  if (!i6) goto l11;
                  i6=0;
l6_loop:
                  i7 = _check_pointer(i4, 30975);
                  i8 = OOC_ARRAY_LENGTH(i7, 0);
                  i7 = (OOC_INT32)*(OOC_INT32*)(i7+(_check_index(i6, i8, OOC_UINT32, 30975))*4);
                  ADT_Dictionary__DictionaryDesc_Set((ADT_Dictionary__Dictionary)i0, (Object__Object)i7, (Object__Object)(OOC_INT32)0);
                  i6 = i6+1;
                  j = i6;
                  i7 = i6<i5;
                  if (i7) goto l6_loop;
l11:
                  i3 = i3+1;
                  i = i3;
                  i4 = i3<i2;
                  if (i4) goto l3_loop;
l16:
                  i0 = (OOC_INT32)ADT_Dictionary__DictionaryDesc_Keys((ADT_Dictionary__Dictionary)i0);
                  vars = (Object__ObjectArrayPtr)i0;
                  i2 = (OOC_INT32)ADT_Dictionary__New();
                  outState = (ADT_Dictionary__Dictionary)i2;
                  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 31150))+20);
                  i = 0;
                  i3 = OOC_ARRAY_LENGTH((_check_pointer(i3, 31159)), 0);
                  i4 = 0<i3;
                  if (!i4) goto l43;
                  i4=0;
l19_loop:
                  j = 0;
                  i5 = OOC_ARRAY_LENGTH((_check_pointer(i0, 31204)), 0);
                  i6 = 0<i5;
                  if (!i6) goto l38;
                  i6=0;
l22_loop:
                  i7 = _check_pointer(i0, 31259);
                  i8 = OOC_ARRAY_LENGTH(i7, 0);
                  i9 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 31233))+20);
                  i9 = _check_pointer(i9, 31242);
                  i10 = OOC_ARRAY_LENGTH(i9, 0);
                  i7 = (OOC_INT32)*(OOC_INT32*)(i7+(_check_index(i6, i8, OOC_UINT32, 31259))*4);
                  i8 = (OOC_INT32)*(OOC_INT32*)(i9+(_check_index(i4, i10, OOC_UINT32, 31242))*4);
                  i7 = ADT_Dictionary__DictionaryDesc_HasKey((ADT_Dictionary__Dictionary)i8, (Object__Object)i7);
                  if (i7) goto l25;
                  i7 = _check_pointer(i0, 32000);
                  i8 = OOC_ARRAY_LENGTH(i7, 0);
                  i7 = (OOC_INT32)*(OOC_INT32*)(i7+(_check_index(i6, i8, OOC_UINT32, 32000))*4);
                  i8 = (OOC_INT32)undefinedVar;
                  ADT_Dictionary__DictionaryDesc_Set((ADT_Dictionary__Dictionary)i2, (Object__Object)i7, (Object__Object)i8);
                  goto l33;
l25:
                  i7 = _check_pointer(i0, 31396);
                  i8 = OOC_ARRAY_LENGTH(i7, 0);
                  i9 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 31373))+20);
                  i9 = _check_pointer(i9, 31382);
                  i10 = OOC_ARRAY_LENGTH(i9, 0);
                  i7 = (OOC_INT32)*(OOC_INT32*)(i7+(_check_index(i6, i8, OOC_UINT32, 31396))*4);
                  i8 = (OOC_INT32)*(OOC_INT32*)(i9+(_check_index(i4, i10, OOC_UINT32, 31382))*4);
                  i7 = (OOC_INT32)ADT_Dictionary__DictionaryDesc_Get((ADT_Dictionary__Dictionary)i8, (Object__Object)i7);
                  value = (Object__Object)i7;
                  i8 = _check_pointer(i0, 31445);
                  i9 = OOC_ARRAY_LENGTH(i8, 0);
                  i8 = (OOC_INT32)*(OOC_INT32*)(i8+(_check_index(i6, i9, OOC_UINT32, 31445))*4);
                  i8 = ADT_Dictionary__DictionaryDesc_HasKey((ADT_Dictionary__Dictionary)i2, (Object__Object)i8);
                  if (i8) goto l28;
                  i8 = _check_pointer(i0, 31783);
                  i9 = OOC_ARRAY_LENGTH(i8, 0);
                  i8 = (OOC_INT32)*(OOC_INT32*)(i8+(_check_index(i6, i9, OOC_UINT32, 31783))*4);
                  ADT_Dictionary__DictionaryDesc_Set((ADT_Dictionary__Dictionary)i2, (Object__Object)i8, (Object__Object)i7);
                  goto l33;
l28:
                  i8 = _check_pointer(i0, 31498);
                  i9 = OOC_ARRAY_LENGTH(i8, 0);
                  i8 = (OOC_INT32)*(OOC_INT32*)(i8+(_check_index(i6, i9, OOC_UINT32, 31498))*4);
                  i8 = (OOC_INT32)ADT_Dictionary__DictionaryDesc_Get((ADT_Dictionary__Dictionary)i2, (Object__Object)i8);
                  i7 = i8!=i7;
                  if (!i7) goto l33;
                  i7 = _check_pointer(i0, 31636);
                  i8 = OOC_ARRAY_LENGTH(i7, 0);
                  i7 = (OOC_INT32)*(OOC_INT32*)(i7+(_check_index(i6, i8, OOC_UINT32, 31636))*4);
                  i8 = (OOC_INT32)undefinedVar;
                  ADT_Dictionary__DictionaryDesc_Set((ADT_Dictionary__Dictionary)i2, (Object__Object)i7, (Object__Object)i8);
l33:
                  i6 = i6+1;
                  j = i6;
                  i7 = i6<i5;
                  if (i7) goto l22_loop;
l38:
                  i4 = i4+1;
                  i = i4;
                  i5 = i4<i3;
                  if (i5) goto l19_loop;
l43:
                  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 32291))+8);
                  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 32303));
                  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 32315));
                  res = (OOC_SSA__Result)i0;
                  i1 = i0!=(OOC_INT32)0;
                  if (!i1) goto l54;
l46_loop:
                  i1 = *(OOC_INT8*)((_check_pointer(i0, 32387))+4);
                  _assert((i1==14), 127, 32376);
                  i1 = (OOC_INT32)registerMap;
                  i0 = ADT_Dictionary__DictionaryDesc_HasKey((ADT_Dictionary__Dictionary)i1, (Object__Object)i0);
                  if (!i0) goto l49;
                  i0 = (OOC_INT32)res;
                  i1 = (OOC_INT32)registerMap;
                  i1 = (OOC_INT32)ADT_Dictionary__DictionaryDesc_Get((ADT_Dictionary__Dictionary)i1, (Object__Object)i0);
                  ADT_Dictionary__DictionaryDesc_Set((ADT_Dictionary__Dictionary)i2, (Object__Object)i1, (Object__Object)i0);
l49:
                  i0 = (OOC_INT32)res;
                  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 32570));
                  res = (OOC_SSA__Result)i0;
                  i1 = i0!=(OOC_INT32)0;
                  if (i1) goto l46_loop;
l54:
                  return (ADT_Dictionary__Dictionary)i2;
                  ;
                }


              i0 = (OOC_INT32)jump;
              i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 32704))+4);
              i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 32710))+44);
              i0 = _type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 32717)))), &_td_OOC_SSA_Allocator__BlockInfoDesc, 32717);
              di = (OOC_SSA_Allocator__BlockInfo)i0;
              i1 = *(OOC_INT32*)((_check_pointer(i0, 32749))+24);
              _assert((i1>0), 127, 32739);
              i1 = *(OOC_INT32*)((_check_pointer(i0, 32781))+24);
              *(OOC_INT32*)((_check_pointer(i0, 32781))+24) = (i1-1);
              i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 32804))+16);
              i1 = _check_pointer(i1, 32815);
              i2 = OOC_ARRAY_LENGTH(i1, 0);
              i3 = *(OOC_INT32*)((_check_pointer(i0, 32818))+24);
              i4 = (OOC_INT32)collect;
              *(OOC_INT32*)(i1+(_check_index(i3, i2, OOC_UINT32, 32815))*4) = i4;
              i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 32852))+20);
              i1 = _check_pointer(i1, 32861);
              i2 = OOC_ARRAY_LENGTH(i1, 0);
              i3 = *(OOC_INT32*)((_check_pointer(i0, 32864))+24);
              i4 = (OOC_INT32)state;
              i4 = (OOC_INT32)ADT_Dictionary__DictionaryDesc_Copy((ADT_Dictionary__Dictionary)i4);
              *(OOC_INT32*)(i1+(_check_index(i3, i2, OOC_UINT32, 32861))*4) = i4;
              i1 = *(OOC_INT32*)((_check_pointer(i0, 32908))+24);
              i1 = i1==0;
              if (!i1) goto l7;
              i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 33024))+8);
              i1 = i1!=(OOC_INT32)0;
              if (i1) goto l5;
              i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 33147))+20);
              i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 33156)), 0);
              _assert((i1==1), 127, 33132);
              i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 33198))+20);
              i1 = _check_pointer(i1, 33207);
              i2 = OOC_ARRAY_LENGTH(i1, 0);
              i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 33207))*4);
              *(OOC_INT32*)((_check_pointer(i0, 33181))+12) = i1;
              goto l6;
l5:
              i1 = (OOC_INT32)OOC_SSA_Allocator__AssignRegisters_CheckRegisters_CheckBlock_UpdateTarget_MergeVariables((OOC_SSA_Allocator__BlockInfo)i0);
              *(OOC_INT32*)((_check_pointer(i0, 33065))+12) = i1;
l6:
              i0 = (OOC_INT32)di;
              i1 = (OOC_INT32)ready;
              *(OOC_INT32*)(_check_pointer(i0, 33295)) = i1;
              ready = (OOC_SSA_Allocator__BlockInfo)i0;
l7:
              return;
              ;
            }

            
            void OOC_SSA_Allocator__AssignRegisters_CheckRegisters_CheckBlock_CheckOpnd(OOC_SSA__Opnd opnd) {
              register OOC_INT32 i0,i1,i2;
              Object__Object obj;
              Object__String defVar;
              OOC_SSA__Result currentValue;

              i0 = (OOC_INT32)opnd;
              i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 33644));
              i2 = (OOC_INT32)registerMap;
              i1 = ADT_Dictionary__DictionaryDesc_HasKey((ADT_Dictionary__Dictionary)i2, (Object__Object)i1);
              if (!i1) goto l10;
              i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 33804));
              i2 = (OOC_INT32)registerMap;
              i1 = (OOC_INT32)ADT_Dictionary__DictionaryDesc_Get((ADT_Dictionary__Dictionary)i2, (Object__Object)i1);
              obj = (Object__Object)i1;
              i2 = (OOC_INT32)OOC_SSA_Allocator__markInPlace;
              i2 = i1==i2;
              if (i2) goto l8;
              i1 = _type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 33945)))), &_td_Object__StringDesc, 33945);
              defVar = (Object__String)i1;
              i2 = (OOC_INT32)state;
              i2 = ADT_Dictionary__DictionaryDesc_HasKey((ADT_Dictionary__Dictionary)i2, (Object__Object)i1);
              _assert(i2, 127, 33968);
              i2 = (OOC_INT32)state;
              i1 = (OOC_INT32)ADT_Dictionary__DictionaryDesc_Get((ADT_Dictionary__Dictionary)i2, (Object__Object)i1);
              obj = (Object__Object)i1;
              i1 = _type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 34195)))), &_td_OOC_SSA__ResultDesc, 34195);
              currentValue = (OOC_SSA__Result)i1;
              i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 34240));
              i2 = i1!=i2;
              if (!i2) goto l10;
              i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 34271))+12);
              OOC_SSA__ResultDesc_LogId((OOC_SSA__Result)i2, "using instruction", 18);
              i2 = OOC_SSA__OpndDesc_OpndIndex((OOC_SSA__Opnd)i0);
              Log__LongInt("  operand index", 16, i2);
              i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 34397));
              OOC_SSA__ResultDesc_LogId((OOC_SSA__Result)i0, "  expected value", 17);
              OOC_SSA__ResultDesc_LogId((OOC_SSA__Result)i1, "  actual value", 15);
              _assert(0u, 127, 34504);
              goto l10;
l8:
              i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 33885));
              i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 33890))+8);
              OOC_SSA_Allocator__AssignRegisters_CheckRegisters_CheckBlock_CheckOpndList((OOC_SSA__Instr)i0);
l10:
              return;
              ;
            }

            
            void OOC_SSA_Allocator__AssignRegisters_CheckRegisters_CheckBlock_CheckOpndList(OOC_SSA__Instr instr) {
              register OOC_INT32 i0,i1;
              OOC_SSA__Opnd opnd;

              i0 = (OOC_INT32)instr;
              i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 34932))+24);
              opnd = (OOC_SSA__Opnd)i1;
              i0 = *(OOC_INT8*)((_check_pointer(i0, 34963))+36);
              i0 = i0==5;
              if (i0) goto l3;
              i0=i1;
              goto l4;
l3:
              i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 35208))+8);
              opnd = (OOC_SSA__Opnd)i0;
              
l4:
              i1 = i0!=(OOC_INT32)0;
              if (!i1) goto l15;
l7_loop:
              i1 = OOC_SSA__OpndDesc_IsValueOpndHere((OOC_SSA__Opnd)i0);
              if (!i1) goto l10;
              OOC_SSA_Allocator__AssignRegisters_CheckRegisters_CheckBlock_CheckOpnd((OOC_SSA__Opnd)i0);
l10:
              i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 35384))+8);
              opnd = (OOC_SSA__Opnd)i0;
              i1 = i0!=(OOC_INT32)0;
              if (i1) goto l7_loop;
l15:
              return;
              ;
            }


          collect = (OOC_SSA__Instr)(OOC_INT32)0;
          i0 = (OOC_INT32)bi;
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 35497))+4);
          b = (OOC_SSA_Schedule__Block)i0;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 35520)))), &_td_OOC_SSA_Schedule__SwitchBlockDesc);
          if (!i1) goto l3;
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 35582)))), &_td_OOC_SSA_Schedule__SwitchBlockDesc, 35582)), 35594))+48);
          OOC_SSA_Allocator__AssignRegisters_CheckRegisters_CheckBlock_CheckOpnd((OOC_SSA__Opnd)i0);
l3:
          i0 = (OOC_INT32)b;
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 35643))+8);
          proxy = (OOC_SSA_Schedule__InstrProxy)i0;
          i1 = i0!=(OOC_INT32)0;
          if (!i1) goto l33;
l6_loop:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 35706))+12);
          i1 = *(OOC_INT8*)((_check_pointer(i1, 35713))+36);
          i1 = i1==6;
          if (i1) goto l12;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 35885))+12);
          i1 = *(OOC_INT8*)((_check_pointer(i1, 35892))+36);
          i1 = i1==5;
          if (!i1) goto l13;
          i1 = (OOC_INT32)b;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 35952))+8);
          _assert((i0==i1), 127, 35935);
          goto l13;
l12:
          i1 = (OOC_INT32)collect;
          _assert((i1==(OOC_INT32)0), 127, 35757);
          i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 35806));
          _assert((i1==(OOC_INT32)0), 127, 35793);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 35854))+12);
          collect = (OOC_SSA__Instr)i1;
l13:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 36001))+12);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 36008))+16);
          i2 = (OOC_INT32)OOC_SSA_Allocator__markInPlace;
          i1 = i1!=i2;
          if (!i1) goto l28;
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 36067))+12);
          OOC_SSA_Allocator__AssignRegisters_CheckRegisters_CheckBlock_CheckOpndList((OOC_SSA__Instr)i0);
          i0 = (OOC_INT32)proxy;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 36114))+12);
          res = (OOC_SSA__Result)i1;
          i2 = i1!=(OOC_INT32)0;
          if (!i2) goto l28;
          i2 = (OOC_INT32)state;
          
l19_loop:
          i3 = (OOC_INT32)registerMap;
          i3 = ADT_Dictionary__DictionaryDesc_HasKey((ADT_Dictionary__Dictionary)i3, (Object__Object)i1);
          if (!i3) goto l22;
          i3 = (OOC_INT32)registerMap;
          i3 = (OOC_INT32)ADT_Dictionary__DictionaryDesc_Get((ADT_Dictionary__Dictionary)i3, (Object__Object)i1);
          ADT_Dictionary__DictionaryDesc_Set((ADT_Dictionary__Dictionary)i2, (Object__Object)i3, (Object__Object)i1);
l22:
          i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 36475));
          res = (OOC_SSA__Result)i1;
          i3 = i1!=(OOC_INT32)0;
          if (i3) goto l19_loop;
l28:
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 36556));
          proxy = (OOC_SSA_Schedule__InstrProxy)i0;
          i1 = i0!=(OOC_INT32)0;
          if (i1) goto l6_loop;
l33:
          i0 = (OOC_INT32)b;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 36605)))), &_td_OOC_SSA_Schedule__BranchBlockDesc);
          if (!i1) goto l36;
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 36667)))), &_td_OOC_SSA_Schedule__BranchBlockDesc, 36667)), 36679))+52);
          OOC_SSA_Allocator__AssignRegisters_CheckRegisters_CheckBlock_CheckOpnd((OOC_SSA__Opnd)i0);
l36:
          i0 = (OOC_INT32)b;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 36729)))), &_td_OOC_SSA_Schedule__JumpBlockDesc);
          if (i1) goto l58;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 36814)))), &_td_OOC_SSA_Schedule__BranchBlockDesc);
          if (i1) goto l56;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 36955)))), &_td_OOC_SSA_Schedule__SwitchBlockDesc);
          if (i1) goto l46;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 37106)))), &_td_OOC_SSA_Schedule__DeadEndBlockDesc);
          if (i1) goto l59;
          _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 37103)))), 37103);
          goto l59;
l46:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 37011))+52);
          i = 0;
          i0 = OOC_ARRAY_LENGTH((_check_pointer(i0, 37017)), 0);
          i1 = 0<i0;
          if (!i1) goto l59;
          i1=0;
l49_loop:
          i2 = (OOC_INT32)b;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 37052))+52);
          i2 = _check_pointer(i2, 37058);
          i3 = OOC_ARRAY_LENGTH(i2, 0);
          i1 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(i1, i3, OOC_UINT32, 37058))*4);
          i2 = (OOC_INT32)collect;
          i3 = (OOC_INT32)state;
          OOC_SSA_Allocator__AssignRegisters_CheckRegisters_CheckBlock_UpdateTarget((OOC_SSA_Schedule__Jump)i1, (ADT_Dictionary__Dictionary)i3, (OOC_SSA__Instr)i2);
          i1 = i;
          i1 = i1+1;
          i = i1;
          i2 = i1<i0;
          if (i2) goto l49_loop;
          goto l59;
l56:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 36865))+48);
          i1 = (OOC_INT32)collect;
          i2 = (OOC_INT32)state;
          OOC_SSA_Allocator__AssignRegisters_CheckRegisters_CheckBlock_UpdateTarget((OOC_SSA_Schedule__Jump)i0, (ADT_Dictionary__Dictionary)i2, (OOC_SSA__Instr)i1);
          i0 = (OOC_INT32)b;
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 36915))+60);
          i1 = (OOC_INT32)collect;
          i2 = (OOC_INT32)state;
          OOC_SSA_Allocator__AssignRegisters_CheckRegisters_CheckBlock_UpdateTarget((OOC_SSA_Schedule__Jump)i0, (ADT_Dictionary__Dictionary)i2, (OOC_SSA__Instr)i1);
          goto l59;
l58:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 36778))+48);
          i1 = (OOC_INT32)collect;
          i2 = (OOC_INT32)state;
          OOC_SSA_Allocator__AssignRegisters_CheckRegisters_CheckBlock_UpdateTarget((OOC_SSA_Schedule__Jump)i0, (ADT_Dictionary__Dictionary)i2, (OOC_SSA__Instr)i1);
l59:
          return;
          ;
        }


      i0 = (OOC_INT32)OOC_SSA__NewResult((OOC_SSA__Instr)(OOC_INT32)0, (-1), (-1));
      undefinedVar = (OOC_SSA__Result)i0;
      ready = (OOC_SSA_Allocator__BlockInfo)(OOC_INT32)0;
      i0 = (OOC_INT32)root;
      OOC_SSA_Allocator__AssignRegisters_CheckRegisters_ScanBlock((OOC_SSA_Schedule__Block)i0);
      i0 = (OOC_INT32)ready;
      _assert((i0!=(OOC_INT32)0), 127, 37313);
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 37354));
      _assert((i1==(OOC_INT32)0), 127, 37341);
      if (!(i0!=(OOC_INT32)0)) goto l8;
      i1=i0;
l3_loop:
      current = (OOC_SSA_Allocator__BlockInfo)i1;
      i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 37584));
      ready = (OOC_SSA_Allocator__BlockInfo)i2;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 37632))+12);
      OOC_SSA_Allocator__AssignRegisters_CheckRegisters_CheckBlock((OOC_SSA_Allocator__BlockInfo)i1, (ADT_Dictionary__Dictionary)i2);
      i1 = (OOC_INT32)ready;
      i2 = i1!=(OOC_INT32)0;
      if (i2) goto l3_loop;
l8:
      return;
      ;
    }

    
    ADT_Dictionary__Dictionary OOC_SSA_Allocator__AssignRegisters_InPlaceEval(OOC_SSA__ProcBlock pb) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7;
      ADT_Dictionary__Dictionary inPlaceEval;
      OOC_SSA__Instr instr;
      OOC_SSA_Schedule__Block instrBlock;
      OOC_INT32 insideUse;
      OOC_INT32 outsideUse;
      OOC_SSA__Opnd use;
      OOC_SSA__Instr useInstr;
      auto OOC_CHAR8 OOC_SSA_Allocator__AssignRegisters_InPlaceEval_FoldedOpcode(OOC_INT8 opcode);
        
        OOC_CHAR8 OOC_SSA_Allocator__AssignRegisters_InPlaceEval_FoldedOpcode(OOC_INT8 opcode) {
          register OOC_INT32 i0;

          i0 = opcode;
          switch (i0) {
          case 55:
          case 12:
          case 58:
          case 0:
          case 3:
          case 56:
          case 57:
            return 0u;
            goto l4;
          default:
            return 1u;
            goto l4;
          }
l4:
          _failed_function(37942); return 0;
          ;
        }


      i0 = (OOC_INT32)ADT_Dictionary__New();
      inPlaceEval = (ADT_Dictionary__Dictionary)i0;
      i1 = (OOC_INT32)pb;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 38349))+12);
      instr = (OOC_SSA__Instr)i1;
      i2 = i1!=(OOC_INT32)0;
      if (!i2) goto l55;
l3_loop:
      i2 = *(OOC_INT8*)((_check_pointer(i1, 38408))+5);
      i2 = i2!=0;
      if (i2) goto l6;
      i2=0u;
      goto l8;
l6:
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 38455))+16);
      i2 = i2!=(OOC_INT32)0;
      
l8:
      if (i2) goto l10;
      i2=0u;
      goto l12;
l10:
      i2 = *(OOC_INT8*)((_check_pointer(i1, 38501))+36);
      i2 = OOC_SSA_Allocator__AssignRegisters_InPlaceEval_FoldedOpcode(i2);
      
l12:
      if (!i2) goto l50;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 38545))+16);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 38561)))), &_td_OOC_SSA_Schedule__InstrProxyDesc, 38561)), 38572))+8);
      instrBlock = (OOC_SSA_Schedule__Block)i2;
      insideUse = 0;
      outsideUse = 0;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 38647))+12);
      use = (OOC_SSA__Opnd)i3;
      i4 = i3!=(OOC_INT32)0;
      if (i4) goto l16;
      i3=0;i4=0;
      goto l34;
l16:
      i4=0;i5=0;
l17_loop:
      i6 = OOC_SSA__OpndDesc_IsValueOpndHere((OOC_SSA__Opnd)i3);
      if (!i6) goto l29;
      i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 38761))+12);
      useInstr = (OOC_SSA__Instr)i6;
      i7 = *(OOC_INT8*)((_check_pointer(i6, 38796))+36);
      i7 = i7!=6;
      if (i7) goto l23;
      i6=0u;
      goto l25;
l23:
      i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i6, 38851))+16);
      i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i6, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 38867)))), &_td_OOC_SSA_Schedule__InstrProxyDesc, 38867)), 38878))+8);
      i6 = i6==i2;
      
l25:
      if (i6) goto l27;
      i5 = i5+1;
      outsideUse = i5;
      
      goto l29;
l27:
      i4 = i4+1;
      insideUse = i4;
      
l29:
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 39049))+16);
      use = (OOC_SSA__Opnd)i3;
      i6 = i3!=(OOC_INT32)0;
      if (i6) goto l17_loop;
l33:
      i3=i4;i4=i5;
l34:
      i5 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 39100)))), &_td_OOC_SSA_Schedule__BranchBlockDesc);
      if (i5) goto l37;
      i2=0u;
      goto l39;
l37:
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 39161)))), &_td_OOC_SSA_Schedule__BranchBlockDesc, 39161)), 39173))+52);
      i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 39184));
      i2 = i2==i1;
      
l39:
      if (i2) goto l41;
      i2=i3;
      goto l42;
l41:
      i2 = i3+1;
      insideUse = i2;
      
l42:
      i3 = i4==0;
      if (i3) goto l45;
      i2=0u;
      goto l47;
l45:
      i2 = i2==1;
      
l47:
      if (!i2) goto l50;
      ADT_Dictionary__DictionaryDesc_Set((ADT_Dictionary__Dictionary)i0, (Object__Object)i1, (Object__Object)(OOC_INT32)0);
l50:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 39405))+28);
      instr = (OOC_SSA__Instr)i1;
      i2 = i1!=(OOC_INT32)0;
      if (i2) goto l3_loop;
l55:
      return (ADT_Dictionary__Dictionary)i0;
      ;
    }


  i0 = (OOC_INT32)pb;
  i0 = (OOC_INT32)OOC_SSA_Allocator__AssignRegisters_InPlaceEval((OOC_SSA__ProcBlock)i0);
  inPlaceEval = (ADT_Dictionary__Dictionary)i0;
  i1 = (OOC_INT32)pb;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 42256));
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 42270))+16);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 42286)))), &_td_OOC_SSA_Schedule__InstrProxyDesc, 42286)), 42297))+8);
  exitBlock = (OOC_SSA_Schedule__Block)i2;
  i3 = (OOC_INT32)domRoot;
  enterBlock = (OOC_SSA_Schedule__Block)i3;
  OOC_SSA__ProcBlockDesc_SetMarkers((OOC_SSA__ProcBlock)i1, (OOC_SSA__Node)0, (-1));
  OOC_SSA_Schedule__BlockDesc_SetInfo((OOC_SSA_Schedule__Block)i3, (OOC_SSA_Schedule__Info)0);
  i1 = (OOC_INT32)OOC_SSA_Allocator__GetBlockList((OOC_SSA_Schedule__Block)i3, (OOC_SSA_Schedule__Block)i2);
  blockList = (OOC_SSA_Allocator__BlockList)i1;
  i0 = (OOC_INT32)OOC_SSA_Allocator__IdentifyResults((OOC_SSA_Allocator__BlockList)i1, (ADT_Dictionary__Dictionary)i0);
  rfs = (OOC_SSA_Allocator__RegisterFiles)i0;
  i = 0;
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 42816)), 0);
  i2 = 0<i1;
  if (!i2) goto l11;
  i2=0;
l3_loop:
  i4 = _check_pointer(i0, 42837);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i2, i5, OOC_UINT32, 42837))*4);
  i4 = i4!=0;
  if (!i4) goto l6;
  i4 = _check_pointer(i0, 42889);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i2, i5, OOC_UINT32, 42889))*4);
  OOC_SSA_Allocator__CollectCrossLoopResults((OOC_SSA_Allocator__RegisterFile)i4, (OOC_SSA_Schedule__Block)i3, (OOC_SSA_Schedule__Block)0);
l6:
  i2 = i2+1;
  i = i2;
  i4 = i2<i1;
  if (i4) goto l3_loop;
l11:
  i1 = (OOC_INT32)ADT_Dictionary__New();
  registerMap = (ADT_Dictionary__Dictionary)i1;
  i = 0;
  i0 = OOC_ARRAY_LENGTH((_check_pointer(i0, 43180)), 0);
  i1 = 0<i0;
  if (!i1) goto l22;
  i1=0;
l14_loop:
  i2 = (OOC_INT32)rfs;
  i2 = _check_pointer(i2, 43201);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i1 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(i1, i3, OOC_UINT32, 43201))*4);
  i1 = i1!=0;
  if (!i1) goto l17;
  i1 = (OOC_INT32)blockList;
  OOC_SSA_Allocator__AssignRegisters_ClearBlockInfo((OOC_SSA_Allocator__BlockList)i1);
  i1 = (OOC_INT32)rfs;
  i2 = _check_pointer(i1, 43284);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i4 = i;
  i2 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(i4, i3, OOC_UINT32, 43284))*4);
  i3 = (OOC_INT32)registerMap;
  i5 = (OOC_INT32)exitBlock;
  i6 = (OOC_INT32)enterBlock;
  OOC_SSA_Allocator__AssignRegisterFile((OOC_SSA_Allocator__RegisterFile)i2, (OOC_SSA_Schedule__Block)i6, (OOC_SSA_Schedule__Block)i5, (ADT_Dictionary__Dictionary)i3);
  i2 = _check_pointer(i1, 43374);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i2 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(i4, i3, OOC_UINT32, 43374))*4);
  i1 = _check_pointer(i1, 43352);
  i3 = OOC_ARRAY_LENGTH(i1, 0);
  i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(i4, i3, OOC_UINT32, 43352))*4);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 43377))+20);
  i1 = *(OOC_INT8*)(_check_pointer(i1, 43355));
  i3 = (OOC_INT32)w;
  OOC_SSA_Allocator__AssignRegisters_WriteNames((OOC_C_DeclWriter__Writer)i3, i1, (OOC_SSA_Allocator__NameArray)i2);
l17:
  i1 = i;
  i1 = i1+1;
  i = i1;
  i2 = i1<i0;
  if (i2) goto l14_loop;
l22:
  i0 = (OOC_INT32)inPlaceEval;
  i0 = (OOC_INT32)ADT_Dictionary__DictionaryDesc_Keys((ADT_Dictionary__Dictionary)i0);
  keys = (Object__ObjectArrayPtr)i0;
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 43467)), 0);
  i = 0;
  i2 = (OOC_INT32)registerMap;
  i3 = 0<i1;
  if (!i3) goto l30;
  i3=0;
l25_loop:
  i4 = _check_pointer(i0, 43503);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 43503))*4);
  i5 = (OOC_INT32)OOC_SSA_Allocator__markInPlace;
  ADT_Dictionary__DictionaryDesc_Set((ADT_Dictionary__Dictionary)i2, (Object__Object)i4, (Object__Object)i5);
  i3 = i3+1;
  i = i3;
  i4 = i3<i1;
  if (i4) goto l25_loop;
l30:
  i0 = (OOC_INT32)domRoot;
  OOC_SSA_Allocator__AssignRegisters_CheckRegisters((OOC_SSA_Schedule__Block)i0, (ADT_Dictionary__Dictionary)i2);
  i0 = (OOC_INT32)registerMap;
  return (ADT_Dictionary__Dictionary)i0;
  ;
}

void OOC_OOC_SSA_Allocator_init(void) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)OOC_SSA__NewResult((OOC_SSA__Instr)(OOC_INT32)0, (-1), (-1));
  OOC_SSA_Allocator__markInPlace = (OOC_SSA__Result)i0;
  return;
  ;
}

void OOC_OOC_SSA_Allocator_destroy(void) {
}

/* --- */
