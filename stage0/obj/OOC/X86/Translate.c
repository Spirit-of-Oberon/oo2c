#include <OOC/X86/Translate.d>
#include <__oo2c.h>
#include <setjmp.h>

void OOC_X86_Translate__Translate(OOC_Repository__Module m, OOC_SymbolTable__Module symTab, OOC_IR__Module moduleIR, IO__ByteChannel ch) {
  register OOC_INT32 i0,i1,i2;
  ADT_ArrayList__ArrayList returns;
  ADT_ArrayList__ArrayList loopExits;
  OOC_X86_Write__Writer w;
  OOC_IR__Procedure p;
  OOC_X86_SSA__FunctionBlock b;
  OOC_X86_SSA__Result sp;
  OOC_X86_SSA__Result fp;
  OOC_X86_SSA__Instr controlCP;
  OOC_X86_SSA__Instr memoryCP;
  auto void OOC_X86_Translate__Translate_ControlCP(OOC_X86_SSA__Instr instr);
  auto void OOC_X86_Translate__Translate_MemoryCP(OOC_X86_SSA__Instr instr);
  auto OOC_X86_SSA__Result OOC_X86_Translate__Translate_FixAddress(OOC_X86_SSA__Result arg);
  auto OOC_X86_SSA__Result OOC_X86_Translate__Translate_FixLength(OOC_X86_SSA__Result arg);
  auto void OOC_X86_Translate__Translate_FailedCheck(Object__String fctName, OOC_INT32 pos, OOC_X86_SSA__Result arg);
  auto void OOC_X86_Translate__Translate_StatmSeq(OOC_IR__StatementSeq statmSeq);
  auto void OOC_X86_Translate__Translate_FctProlog(OOC_X86_SSA__FunctionBlock b);
  auto void OOC_X86_Translate__Translate_FctEpilog(OOC_X86_SSA__FunctionBlock b);
  auto void OOC_X86_Translate__Translate_Procedure(OOC_IR__Procedure p);
    
    void OOC_X86_Translate__Translate_ControlCP(OOC_X86_SSA__Instr instr) {
      register OOC_INT32 i0,i1;

      i0 = (OOC_INT32)controlCP;
      i1 = (OOC_INT32)instr;
      OOC_X86_SSA__InstrDesc_AddDep((OOC_X86_SSA__Instr)i1, 0, (OOC_X86_SSA__Instr)i0);
      controlCP = (OOC_X86_SSA__Instr)i1;
      return;
      ;
    }

    
    void OOC_X86_Translate__Translate_MemoryCP(OOC_X86_SSA__Instr instr) {
      register OOC_INT32 i0,i1;

      i0 = (OOC_INT32)memoryCP;
      i1 = (OOC_INT32)instr;
      OOC_X86_SSA__InstrDesc_AddDep((OOC_X86_SSA__Instr)i1, 1, (OOC_X86_SSA__Instr)i0);
      memoryCP = (OOC_X86_SSA__Instr)i1;
      return;
      ;
    }

    
    OOC_X86_SSA__Result OOC_X86_Translate__Translate_FixAddress(OOC_X86_SSA__Result arg) {
      register OOC_INT32 i0,i1;

      i0 = (OOC_INT32)arg;
      i1 = (OOC_INT32)b;
      i0 = (OOC_INT32)OOC_X86_SSA__FunctionBlockDesc_FixType((OOC_X86_SSA__FunctionBlock)i1, (OOC_X86_SSA__Result)i0, 9);
      return (OOC_X86_SSA__Result)i0;
      ;
    }

    
    OOC_X86_SSA__Result OOC_X86_Translate__Translate_FixLength(OOC_X86_SSA__Result arg) {
      register OOC_INT32 i0,i1;

      i0 = (OOC_INT32)arg;
      i1 = (OOC_INT32)b;
      i0 = (OOC_INT32)OOC_X86_SSA__FunctionBlockDesc_FixType((OOC_X86_SSA__FunctionBlock)i1, (OOC_X86_SSA__Result)i0, 3);
      return (OOC_X86_SSA__Result)i0;
      ;
    }

    
    void OOC_X86_Translate__Translate_FailedCheck(Object__String fctName, OOC_INT32 pos, OOC_X86_SSA__Result arg) {
      register OOC_INT32 i0,i1,i2;

      i0 = (OOC_INT32)sp;
      i1 = (OOC_INT32)fctName;
      i2 = (OOC_INT32)b;
      i1 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddAdrRT((OOC_X86_SSA__Block)i2, (Object__String)i1);
      i2 = (OOC_INT32)b;
      i0 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr2((OOC_X86_SSA__Block)i2, 20, (OOC_X86_SSA__Result)i1, (OOC_X86_SSA__Result)i0);
      i1 = (OOC_INT32)b;
      i1 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddAdrModuleDescr((OOC_X86_SSA__Block)i1);
      OOC_X86_SSA__InstrDesc_AddOpnd((OOC_X86_SSA__Instr)i0, (OOC_X86_SSA__Result)i1);
      i1 = pos;
      i2 = (OOC_INT32)b;
      i1 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddConstLength((OOC_X86_SSA__Block)i2, i1);
      OOC_X86_SSA__InstrDesc_AddOpnd((OOC_X86_SSA__Instr)i0, (OOC_X86_SSA__Result)i1);
      i1 = (OOC_INT32)arg;
      i2 = i1!=(OOC_INT32)0;
      if (!i2) goto l4;
      OOC_X86_SSA__InstrDesc_AddOpnd((OOC_X86_SSA__Instr)i0, (OOC_X86_SSA__Result)i1);
l4:
      OOC_X86_Translate__Translate_MemoryCP((OOC_X86_SSA__Instr)i0);
      OOC_X86_Translate__Translate_ControlCP((OOC_X86_SSA__Instr)i0);
      return;
      ;
    }

    
    void OOC_X86_Translate__Translate_StatmSeq(OOC_IR__StatementSeq statmSeq) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8;
      OOC_IR__Statement statm;
      OOC_X86_SSA__Result res;
      OOC_X86_SSA__Result var;
      OOC_X86_SSA__Instr memoryFalse;
      OOC_X86_SSA__Instr controlFalse;
      OOC_X86_SSA__Instr memoryTrue;
      OOC_X86_SSA__Instr controlTrue;
      OOC_X86_SSA__Instr endTrue;
      OOC_X86_SSA__Instr endFalse;
      OOC_X86_SSA__MergeInstr merge;
      OOC_IR__Expression irExpr;
      OOC_INT8 type;
      OOC_X86_SSA__Instr instr;
      OOC_X86_SSA__LoopStartInstr loopStart;
      auto OOC_X86_SSA__Result OOC_X86_Translate__Translate_StatmSeq_SetCC(OOC_X86_SSA__Result res);
      auto OOC_X86_SSA__Result OOC_X86_Translate__Translate_StatmSeq_SetBool(OOC_X86_SSA__Result res);
      auto OOC_X86_SSA__Instr OOC_X86_Translate__Translate_StatmSeq_AddJump(void);
      auto void OOC_X86_Translate__Translate_StatmSeq_SplitPaths(OOC_X86_SSA__Result _bool, OOC_X86_SSA__Instr controlCP, OOC_X86_SSA__Instr memoryCP, OOC_X86_SSA__Instr *controlTrue, OOC_X86_SSA__Instr *memoryTrue, OOC_X86_SSA__Instr *controlFalse, OOC_X86_SSA__Instr *memoryFalse);
      auto void OOC_X86_Translate__Translate_StatmSeq_LoopEnd(OOC_X86_SSA__LoopStartInstr loopStart);
      auto OOC_X86_SSA__Result OOC_X86_Translate__Translate_StatmSeq_Expression(OOC_IR__Expression expr);
      auto OOC_X86_SSA__Result OOC_X86_Translate__Translate_StatmSeq_Call(OOC_IR__Call call);
      auto void OOC_X86_Translate__Translate_StatmSeq_Copy(OOC_IR__Copy copy);
      auto void OOC_X86_Translate__Translate_StatmSeq_MoveBlock(OOC_IR__MoveBlock move);
      auto OOC_X86_SSA__Result OOC_X86_Translate__Translate_StatmSeq_TypeTag(OOC_IR__Expression design, OOC_X86_SSA__Result value, OOC_CHAR8 checkDerefOfNil, OOC_Scanner_SymList__Symbol derefSym);
      auto OOC_X86_SSA__Result OOC_X86_Translate__Translate_StatmSeq_Expression(OOC_IR__Expression expr);
      auto void OOC_X86_Translate__Translate_StatmSeq_Assign(OOC_X86_SSA__Result getInstr, OOC_X86_SSA__Result newValue);
      auto void OOC_X86_Translate__Translate_StatmSeq_ForStatm(OOC_IR__ForStatm statm);
        
        OOC_X86_SSA__Result OOC_X86_Translate__Translate_StatmSeq_SetCC(OOC_X86_SSA__Result res) {
          register OOC_INT32 i0,i1,i2;

          i0 = (OOC_INT32)res;
          i1 = *(OOC_INT8*)((_check_pointer(i0, 2262))+13);
          i1 = i1==2;
          if (i1) goto l3;
          i1 = (OOC_INT32)b;
          i1 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddConstBool((OOC_X86_SSA__Block)i1, 0u);
          i2 = (OOC_INT32)b;
          i0 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr2((OOC_X86_SSA__Block)i2, 10, (OOC_X86_SSA__Result)i0, (OOC_X86_SSA__Result)i1);
          i0 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AddResultReg((OOC_X86_SSA__Instr)i0, 0, 2);
          return (OOC_X86_SSA__Result)i0;
          goto l4;
l3:
          return (OOC_X86_SSA__Result)i0;
l4:
          _failed_function(2169); return 0;
          ;
        }

        
        OOC_X86_SSA__Result OOC_X86_Translate__Translate_StatmSeq_SetBool(OOC_X86_SSA__Result res) {
          register OOC_INT32 i0,i1;

          i0 = (OOC_INT32)res;
          i1 = *(OOC_INT8*)((_check_pointer(i0, 2580))+13);
          i1 = i1==2;
          if (i1) goto l3;
          return (OOC_X86_SSA__Result)i0;
          goto l4;
l3:
          i1 = (OOC_INT32)b;
          i0 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr1((OOC_X86_SSA__Block)i1, 15, (OOC_X86_SSA__Result)i0);
          i0 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AddResult((OOC_X86_SSA__Instr)i0, 5);
          return (OOC_X86_SSA__Result)i0;
l4:
          _failed_function(2485); return 0;
          ;
        }

        
        OOC_X86_SSA__Instr OOC_X86_Translate__Translate_StatmSeq_AddJump(void) {
          register OOC_INT32 i0;

          i0 = (OOC_INT32)b;
          i0 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr0((OOC_X86_SSA__Block)i0, 37);
          OOC_X86_Translate__Translate_ControlCP((OOC_X86_SSA__Instr)i0);
          OOC_X86_Translate__Translate_MemoryCP((OOC_X86_SSA__Instr)i0);
          return (OOC_X86_SSA__Instr)i0;
          ;
        }

        
        void OOC_X86_Translate__Translate_StatmSeq_SplitPaths(OOC_X86_SSA__Result _bool, OOC_X86_SSA__Instr controlCP, OOC_X86_SSA__Instr memoryCP, OOC_X86_SSA__Instr *controlTrue, OOC_X86_SSA__Instr *memoryTrue, OOC_X86_SSA__Instr *controlFalse, OOC_X86_SSA__Instr *memoryFalse) {
          register OOC_INT32 i0,i1,i2,i3,i4,i5;
          OOC_X86_SSA__Instr instr;
          OOC_X86_SSA__GateInstr gate;
          OOC_X86_SSA__MergeInstr merge;
          auto void OOC_X86_Translate__Translate_StatmSeq_SplitPaths_SplitValue(void);
          auto void OOC_X86_Translate__Translate_StatmSeq_SplitPaths_SplitAndGate(OOC_X86_SSA__GateInstr gate, OOC_X86_SSA__Result testValue, OOC_X86_SSA__Instr bailOutPath, OOC_X86_SSA__Instr testPath);
          auto void OOC_X86_Translate__Translate_StatmSeq_SplitPaths_SplitOrGate(OOC_X86_SSA__GateInstr gate, OOC_X86_SSA__Result testValue, OOC_X86_SSA__Instr bailOutPath, OOC_X86_SSA__Instr testPath);
            
            void OOC_X86_Translate__Translate_StatmSeq_SplitPaths_SplitValue(void) {
              register OOC_INT32 i0,i1,i2,i3;

              i0 = (OOC_INT32)_bool;
              i0 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_SetCC((OOC_X86_SSA__Result)i0);
              i1 = (OOC_INT32)b;
              i0 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddBranch((OOC_X86_SSA__Block)i1, (OOC_X86_SSA__Result)i0);
              i1 = (OOC_INT32)controlCP;
              OOC_X86_SSA__InstrDesc_AddDep((OOC_X86_SSA__Instr)i0, 0, (OOC_X86_SSA__Instr)i1);
              i1 = (OOC_INT32)b;
              i1 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddConstBool((OOC_X86_SSA__Block)i1, 1u);
              i2 = (OOC_INT32)b;
              i1 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddMerge0((OOC_X86_SSA__Block)i2, 35, (OOC_X86_SSA__Result)i1);
              OOC_X86_SSA__InstrDesc_AddDep((OOC_X86_SSA__Instr)i1, 0, (OOC_X86_SSA__Instr)i0);
              *controlTrue = (OOC_X86_SSA__Instr)i1;
              i2 = (OOC_INT32)memoryCP;
              *memoryTrue = (OOC_X86_SSA__Instr)i2;
              i2 = (OOC_INT32)b;
              i2 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddConstBool((OOC_X86_SSA__Block)i2, 0u);
              i3 = (OOC_INT32)b;
              i2 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddMerge0((OOC_X86_SSA__Block)i3, 35, (OOC_X86_SSA__Result)i2);
              OOC_X86_SSA__InstrDesc_AddDep((OOC_X86_SSA__Instr)i2, 0, (OOC_X86_SSA__Instr)i0);
              *controlFalse = (OOC_X86_SSA__Instr)i2;
              i3 = (OOC_INT32)memoryCP;
              *memoryFalse = (OOC_X86_SSA__Instr)i3;
              OOC_X86_SSA__BranchInstrDesc_SetPaths2((OOC_X86_SSA__BranchInstr)i0, (OOC_X86_SSA__Block)i1, (OOC_X86_SSA__Block)i2);
              return;
              ;
            }

            
            void OOC_X86_Translate__Translate_StatmSeq_SplitPaths_SplitAndGate(OOC_X86_SSA__GateInstr gate, OOC_X86_SSA__Result testValue, OOC_X86_SSA__Instr bailOutPath, OOC_X86_SSA__Instr testPath) {
              register OOC_INT32 i0,i1,i2,i3;
              OOC_X86_SSA__Instr mf;
              OOC_X86_SSA__Instr cf;
              OOC_X86_SSA__Instr mt;
              OOC_X86_SSA__Instr ct;
              OOC_X86_SSA__Instr guard;
              OOC_X86_SSA__Instr branch;
              OOC_X86_SSA__Instr instr;

              i0 = (OOC_INT32)testPath;
              i1 = (OOC_INT32)OOC_X86_SSA__InstrDesc_GetBeforeInstr((OOC_X86_SSA__Instr)i0, 1);
              i2 = (OOC_INT32)OOC_X86_SSA__InstrDesc_GetBeforeInstr((OOC_X86_SSA__Instr)i0, 0);
              i3 = (OOC_INT32)testValue;
              OOC_X86_Translate__Translate_StatmSeq_SplitPaths((OOC_X86_SSA__Result)i3, (OOC_X86_SSA__Instr)i2, (OOC_X86_SSA__Instr)i1, (void*)(OOC_INT32)&ct, (void*)(OOC_INT32)&mt, (void*)(OOC_INT32)&cf, (void*)(OOC_INT32)&mf);
              i1 = (OOC_INT32)bailOutPath;
              i2 = (OOC_INT32)OOC_X86_SSA__InstrDesc_GetBeforeInstr((OOC_X86_SSA__Instr)i1, 0);
              guard = (OOC_X86_SSA__Instr)i2;
              i3 = *(OOC_INT8*)((_check_pointer(i2, 4953))+20);
              _assert((i3==35), 127, 4941);
              i2 = (OOC_INT32)OOC_X86_SSA__InstrDesc_GetBranchBeforeInstr((OOC_X86_SSA__Instr)i2, 0);
              branch = (OOC_X86_SSA__Instr)i2;
              i2 = *(OOC_INT8*)((_check_pointer(i2, 5058))+20);
              _assert((i2==34), 127, 5045);
              i2 = (OOC_INT32)ct;
              *controlTrue = (OOC_X86_SSA__Instr)i2;
              i2 = (OOC_INT32)mt;
              *memoryTrue = (OOC_X86_SSA__Instr)i2;
              i2 = (OOC_INT32)b;
              i2 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr0((OOC_X86_SSA__Block)i2, 37);
              instr = (OOC_X86_SSA__Instr)i2;
              i3 = (OOC_INT32)cf;
              OOC_X86_SSA__InstrDesc_AddDep((OOC_X86_SSA__Instr)i2, 0, (OOC_X86_SSA__Instr)i3);
              i3 = (OOC_INT32)mf;
              OOC_X86_SSA__InstrDesc_AddDep((OOC_X86_SSA__Instr)i2, 1, (OOC_X86_SSA__Instr)i3);
              i3 = (OOC_INT32)OOC_X86_SSA__InstrDesc_GetBeforeInstr((OOC_X86_SSA__Instr)i1, 0);
              *controlFalse = (OOC_X86_SSA__Instr)i3;
              i3 = (OOC_INT32)OOC_X86_SSA__InstrDesc_GetBeforeInstr((OOC_X86_SSA__Instr)i1, 1);
              *memoryFalse = (OOC_X86_SSA__Instr)i3;
              i3 = (OOC_INT32)*controlFalse;
              OOC_X86_SSA__MergeInstrDesc_AddJump((OOC_X86_SSA__MergeInstr)(_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 5409)))), &_td_OOC_X86_SSA__MergeInstrDesc, 5409)), (OOC_X86_SSA__Instr)i2);
              i2 = (OOC_INT32)gate;
              i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 5536))+48);
              OOC_X86_SSA__InstrDesc_Delete((OOC_X86_SSA__Instr)i2);
              OOC_X86_SSA__InstrDesc_Delete((OOC_X86_SSA__Instr)(_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 5545)))), &_td_OOC_X86_SSA__MergeInstrDesc, 5545)));
              OOC_X86_SSA__InstrDesc_Delete((OOC_X86_SSA__Instr)i1);
              OOC_X86_SSA__InstrDesc_Delete((OOC_X86_SSA__Instr)i0);
              return;
              ;
            }

            
            void OOC_X86_Translate__Translate_StatmSeq_SplitPaths_SplitOrGate(OOC_X86_SSA__GateInstr gate, OOC_X86_SSA__Result testValue, OOC_X86_SSA__Instr bailOutPath, OOC_X86_SSA__Instr testPath) {
              register OOC_INT32 i0,i1,i2,i3;
              OOC_X86_SSA__Instr mf;
              OOC_X86_SSA__Instr cf;
              OOC_X86_SSA__Instr mt;
              OOC_X86_SSA__Instr ct;
              OOC_X86_SSA__Instr guard;
              OOC_X86_SSA__Instr branch;
              OOC_X86_SSA__Instr instr;

              i0 = (OOC_INT32)testPath;
              i1 = (OOC_INT32)OOC_X86_SSA__InstrDesc_GetBeforeInstr((OOC_X86_SSA__Instr)i0, 1);
              i2 = (OOC_INT32)OOC_X86_SSA__InstrDesc_GetBeforeInstr((OOC_X86_SSA__Instr)i0, 0);
              i3 = (OOC_INT32)testValue;
              OOC_X86_Translate__Translate_StatmSeq_SplitPaths((OOC_X86_SSA__Result)i3, (OOC_X86_SSA__Instr)i2, (OOC_X86_SSA__Instr)i1, (void*)(OOC_INT32)&ct, (void*)(OOC_INT32)&mt, (void*)(OOC_INT32)&cf, (void*)(OOC_INT32)&mf);
              i1 = (OOC_INT32)bailOutPath;
              i2 = (OOC_INT32)OOC_X86_SSA__InstrDesc_GetBeforeInstr((OOC_X86_SSA__Instr)i1, 0);
              guard = (OOC_X86_SSA__Instr)i2;
              i3 = *(OOC_INT8*)((_check_pointer(i2, 6219))+20);
              _assert((i3==35), 127, 6207);
              i2 = (OOC_INT32)OOC_X86_SSA__InstrDesc_GetBranchBeforeInstr((OOC_X86_SSA__Instr)i2, 0);
              branch = (OOC_X86_SSA__Instr)i2;
              i2 = *(OOC_INT8*)((_check_pointer(i2, 6324))+20);
              _assert((i2==34), 127, 6311);
              i2 = (OOC_INT32)cf;
              *controlFalse = (OOC_X86_SSA__Instr)i2;
              i2 = (OOC_INT32)mf;
              *memoryFalse = (OOC_X86_SSA__Instr)i2;
              i2 = (OOC_INT32)b;
              i2 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr0((OOC_X86_SSA__Block)i2, 37);
              instr = (OOC_X86_SSA__Instr)i2;
              i3 = (OOC_INT32)ct;
              OOC_X86_SSA__InstrDesc_AddDep((OOC_X86_SSA__Instr)i2, 0, (OOC_X86_SSA__Instr)i3);
              i3 = (OOC_INT32)mt;
              OOC_X86_SSA__InstrDesc_AddDep((OOC_X86_SSA__Instr)i2, 1, (OOC_X86_SSA__Instr)i3);
              i3 = (OOC_INT32)OOC_X86_SSA__InstrDesc_GetBeforeInstr((OOC_X86_SSA__Instr)i1, 0);
              *controlTrue = (OOC_X86_SSA__Instr)i3;
              i3 = (OOC_INT32)OOC_X86_SSA__InstrDesc_GetBeforeInstr((OOC_X86_SSA__Instr)i1, 1);
              *memoryTrue = (OOC_X86_SSA__Instr)i3;
              i3 = (OOC_INT32)*controlTrue;
              OOC_X86_SSA__MergeInstrDesc_AddJump((OOC_X86_SSA__MergeInstr)(_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 6674)))), &_td_OOC_X86_SSA__MergeInstrDesc, 6674)), (OOC_X86_SSA__Instr)i2);
              i2 = (OOC_INT32)gate;
              i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 6801))+48);
              OOC_X86_SSA__InstrDesc_Delete((OOC_X86_SSA__Instr)i2);
              OOC_X86_SSA__InstrDesc_Delete((OOC_X86_SSA__Instr)(_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 6810)))), &_td_OOC_X86_SSA__MergeInstrDesc, 6810)));
              OOC_X86_SSA__InstrDesc_Delete((OOC_X86_SSA__Instr)i1);
              OOC_X86_SSA__InstrDesc_Delete((OOC_X86_SSA__Instr)i0);
              return;
              ;
            }


          i0 = (OOC_INT32)_bool;
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7000))+4);
          instr = (OOC_X86_SSA__Instr)i0;
          i1 = *(OOC_INT8*)((_check_pointer(i0, 7025))+20);
          i1 = i1==38;
          if (!i1) goto l18;
          i1 = _type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7074)))), &_td_OOC_X86_SSA__GateInstrDesc, 7074);
          gate = (OOC_X86_SSA__GateInstr)i1;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7113)))), &_td_OOC_X86_SSA__GateInstrDesc, 7113)), 7123))+48);
          i2 = _type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 7132)))), &_td_OOC_X86_SSA__MergeInstrDesc, 7132);
          merge = (OOC_X86_SSA__MergeInstr)i2;
          i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 7163));
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 7172))+4);
          i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 7181));
          i3 = OOC_X86_SSA__ResultDesc_IsFalse((OOC_X86_SSA__Result)i3);
          if (i3) goto l16;
          i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 7351));
          i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 7360));
          i3 = OOC_X86_SSA__ResultDesc_IsFalse((OOC_X86_SSA__Result)i3);
          if (i3) goto l14;
          i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 7539));
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 7548))+4);
          i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 7557));
          i3 = OOC_X86_SSA__ResultDesc_IsTrue((OOC_X86_SSA__Result)i3);
          if (i3) goto l12;
          i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 7724));
          i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 7733));
          i3 = OOC_X86_SSA__ResultDesc_IsTrue((OOC_X86_SSA__Result)i3);
          if (!i3) goto l18;
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 7856))+56);
          i3 = _check_pointer(i3, 7862);
          i4 = OOC_ARRAY_LENGTH(i3, 0);
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 7840))+56);
          i2 = _check_pointer(i2, 7846);
          i5 = OOC_ARRAY_LENGTH(i2, 0);
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 7787));
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7796))+4);
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 7805));
          i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(1, i4, OOC_UINT8, 7862))*4);
          i2 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(0, i5, OOC_UINT8, 7846))*4);
          OOC_X86_Translate__Translate_StatmSeq_SplitPaths_SplitOrGate((OOC_X86_SSA__GateInstr)i1, (OOC_X86_SSA__Result)i0, (OOC_X86_SSA__Instr)i2, (OOC_X86_SSA__Instr)i3);
          return;
          goto l18;
l12:
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 7671))+56);
          i3 = _check_pointer(i3, 7677);
          i4 = OOC_ARRAY_LENGTH(i3, 0);
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 7655))+56);
          i2 = _check_pointer(i2, 7661);
          i5 = OOC_ARRAY_LENGTH(i2, 0);
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 7611));
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 7620));
          i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(0, i4, OOC_UINT8, 7677))*4);
          i2 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(1, i5, OOC_UINT8, 7661))*4);
          OOC_X86_Translate__Translate_StatmSeq_SplitPaths_SplitOrGate((OOC_X86_SSA__GateInstr)i1, (OOC_X86_SSA__Result)i0, (OOC_X86_SSA__Instr)i2, (OOC_X86_SSA__Instr)i3);
          return;
          goto l18;
l14:
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 7486))+56);
          i3 = _check_pointer(i3, 7492);
          i4 = OOC_ARRAY_LENGTH(i3, 0);
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 7470))+56);
          i2 = _check_pointer(i2, 7476);
          i5 = OOC_ARRAY_LENGTH(i2, 0);
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 7416));
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7425))+4);
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 7434));
          i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(1, i4, OOC_UINT8, 7492))*4);
          i2 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(0, i5, OOC_UINT8, 7476))*4);
          OOC_X86_Translate__Translate_StatmSeq_SplitPaths_SplitAndGate((OOC_X86_SSA__GateInstr)i1, (OOC_X86_SSA__Result)i0, (OOC_X86_SSA__Instr)i2, (OOC_X86_SSA__Instr)i3);
          return;
          goto l18;
l16:
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 7298))+56);
          i3 = _check_pointer(i3, 7304);
          i4 = OOC_ARRAY_LENGTH(i3, 0);
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 7282))+56);
          i2 = _check_pointer(i2, 7288);
          i5 = OOC_ARRAY_LENGTH(i2, 0);
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 7237));
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 7246));
          i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(0, i4, OOC_UINT8, 7304))*4);
          i2 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(1, i5, OOC_UINT8, 7288))*4);
          OOC_X86_Translate__Translate_StatmSeq_SplitPaths_SplitAndGate((OOC_X86_SSA__GateInstr)i1, (OOC_X86_SSA__Result)i0, (OOC_X86_SSA__Instr)i2, (OOC_X86_SSA__Instr)i3);
          return;
l18:
          OOC_X86_Translate__Translate_StatmSeq_SplitPaths_SplitValue();
          return;
          ;
        }

        
        void OOC_X86_Translate__Translate_StatmSeq_LoopEnd(OOC_X86_SSA__LoopStartInstr loopStart) {
          register OOC_INT32 i0,i1,i2;
          OOC_X86_SSA__Instr instr;
          OOC_X86_SSA__Instr loopEnd;

          i0 = (OOC_INT32)loopStart;
          i1 = (OOC_INT32)b;
          i1 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddLoopBackedge((OOC_X86_SSA__Block)i1, (OOC_X86_SSA__LoopStartInstr)i0);
          instr = (OOC_X86_SSA__Instr)i1;
          i2 = (OOC_INT32)memoryCP;
          OOC_X86_SSA__InstrDesc_AddDep((OOC_X86_SSA__Instr)i1, 1, (OOC_X86_SSA__Instr)i2);
          i2 = (OOC_INT32)controlCP;
          OOC_X86_SSA__InstrDesc_AddDep((OOC_X86_SSA__Instr)i1, 0, (OOC_X86_SSA__Instr)i2);
          OOC_X86_SSA__LoopStartInstrDesc_SetBackedge((OOC_X86_SSA__LoopStartInstr)i0, (OOC_X86_SSA__Instr)i1);
          i1 = (OOC_INT32)loopExits;
          i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 8363)))), ADT_ArrayList__ArrayListDesc_Elements)),ADT_ArrayList__ArrayListDesc_Elements)((ADT_ArrayList__ArrayList)i1);
          i2 = (OOC_INT32)b;
          i1 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddMerge((OOC_X86_SSA__Block)i2, 41, (Object__ObjectArrayPtr)i1);
          loopEnd = (OOC_X86_SSA__Instr)i1;
          OOC_X86_SSA__LoopStartInstrDesc_SetEnd((OOC_X86_SSA__LoopStartInstr)i0, (OOC_X86_SSA__Instr)i1);
          controlCP = (OOC_X86_SSA__Instr)i1;
          memoryCP = (OOC_X86_SSA__Instr)i1;
          i0 = (OOC_INT32)loopExits;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8480)))), ADT_ArrayList__ArrayListDesc_Clear)),ADT_ArrayList__ArrayListDesc_Clear)((ADT_ArrayList__ArrayList)i0);
          return;
          ;
        }

        
        OOC_X86_SSA__Result OOC_X86_Translate__Translate_StatmSeq_Call(OOC_IR__Call call) {
          register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
          OOC_X86_SSA__Result *args;
          OOC_INT32 i;
          OOC_X86_SSA__Instr instr;

          i0 = (OOC_INT32)call;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8843))+12);
          i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 8853)), 0);
          i1 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_Translate__8697.baseTypes[0], i1);
          args = (void*)i1;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8883))+12);
          i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 8893)), 0);
          i2 = i2-1;
          i = i2;
          i3 = i2>=0;
          if (!i3) goto l8;
l3_loop:
          i3 = _check_pointer(i1, 8926);
          i4 = OOC_ARRAY_LENGTH(i3, 0);
          i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8948))+12);
          i5 = _check_pointer(i5, 8958);
          i6 = OOC_ARRAY_LENGTH(i5, 0);
          i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i2, i6, OOC_UINT32, 8958))*4);
          i5 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression((OOC_IR__Expression)i5);
          *(OOC_INT32*)(i3+(_check_index(i2, i4, OOC_UINT32, 8926))*4) = i5;
          i2 = i2+(-1);
          i = i2;
          i3 = i2>=0;
          if (i3) goto l3_loop;
l8:
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9038))+8);
          i3 = (OOC_INT32)sp;
          i2 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression((OOC_IR__Expression)i2);
          i4 = (OOC_INT32)b;
          i2 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr2((OOC_X86_SSA__Block)i4, 20, (OOC_X86_SSA__Result)i2, (OOC_X86_SSA__Result)i3);
          instr = (OOC_X86_SSA__Instr)i2;
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9083))+12);
          i = 0;
          i3 = OOC_ARRAY_LENGTH((_check_pointer(i3, 9093)), 0);
          i4 = 0<i3;
          if (!i4) goto l16;
          i4=0;
l11_loop:
          i5 = _check_pointer(i1, 9129);
          i6 = OOC_ARRAY_LENGTH(i5, 0);
          i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 9129))*4);
          OOC_X86_SSA__InstrDesc_AddOpnd((OOC_X86_SSA__Instr)i2, (OOC_X86_SSA__Result)i5);
          i4 = i4+1;
          i = i4;
          i5 = i4<i3;
          if (i5) goto l11_loop;
l16:
          OOC_X86_Translate__Translate_MemoryCP((OOC_X86_SSA__Instr)i2);
          OOC_X86_Translate__Translate_ControlCP((OOC_X86_SSA__Instr)i2);
          i1 = (OOC_INT32)OOC_SymbolTable_Predef__GetType(17);
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9224))+4);
          i1 = i3==i1;
          if (i1) goto l19;
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9342))+4);
          i0 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AddResultExpr((OOC_X86_SSA__Instr)i2, (OOC_SymbolTable__Type)i0);
          return (OOC_X86_SSA__Result)i0;
          goto l20;
l19:
          return (OOC_X86_SSA__Result)(OOC_INT32)0;
l20:
          _failed_function(8598); return 0;
          ;
        }

        
        void OOC_X86_Translate__Translate_StatmSeq_Copy(OOC_IR__Copy copy) {
          register OOC_INT32 i0,i1,i2,i3,i4,i5;
          OOC_X86_SSA__Result size;
          OOC_X86_SSA__Result from;
          OOC_X86_SSA__Result to;
          OOC_X86_SSA__Instr instr;

          i0 = (OOC_INT32)copy;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9536))+12);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 9541))+4);
          i1 = *(OOC_INT32*)((_check_pointer(i1, 9546))+32);
          i2 = (OOC_INT32)b;
          i1 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddConstLength((OOC_X86_SSA__Block)i2, i1);
          size = (OOC_X86_SSA__Result)i1;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9585))+8);
          i2 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression((OOC_IR__Expression)i2);
          from = (OOC_X86_SSA__Result)i2;
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9624))+12);
          i3 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression((OOC_IR__Expression)i3);
          to = (OOC_X86_SSA__Result)i3;
          i0 = *(OOC_UINT8*)((_check_pointer(i0, 9656))+16);
          if (i0) goto l4;
l4:
          i0 = (OOC_INT32)sp;
          i4 = (OOC_INT32)b;
          i4 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddAdrRT((OOC_X86_SSA__Block)i4, (Object__String)((OOC_INT32)_c0));
          i5 = (OOC_INT32)b;
          i0 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr2((OOC_X86_SSA__Block)i5, 20, (OOC_X86_SSA__Result)i4, (OOC_X86_SSA__Result)i0);
          instr = (OOC_X86_SSA__Instr)i0;
          i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 9807))+4);
          i4 = *(OOC_INT8*)((_check_pointer(i4, 9813))+20);
          _assert((i4==24), 127, 9798);
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 9855))+4);
          i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 9861));
          i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 9870));
          OOC_X86_SSA__InstrDesc_AddOpnd((OOC_X86_SSA__Instr)i0, (OOC_X86_SSA__Result)i3);
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 9896))+4);
          i3 = *(OOC_INT8*)((_check_pointer(i3, 9902))+20);
          _assert((i3==24), 127, 9885);
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 9946))+4);
          i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 9952));
          i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 9961));
          OOC_X86_SSA__InstrDesc_AddOpnd((OOC_X86_SSA__Instr)i0, (OOC_X86_SSA__Result)i2);
          OOC_X86_SSA__InstrDesc_AddOpnd((OOC_X86_SSA__Instr)i0, (OOC_X86_SSA__Result)i1);
          OOC_X86_Translate__Translate_MemoryCP((OOC_X86_SSA__Instr)i0);
          OOC_X86_Translate__Translate_ControlCP((OOC_X86_SSA__Instr)i0);
          return;
          ;
        }

        
        void OOC_X86_Translate__Translate_StatmSeq_MoveBlock(OOC_IR__MoveBlock move) {
          register OOC_INT32 i0,i1,i2,i3,i4,i5;
          OOC_X86_SSA__Result size;
          OOC_X86_SSA__Result from;

          i0 = (OOC_INT32)move;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10230))+16);
          i1 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression((OOC_IR__Expression)i1);
          size = (OOC_X86_SSA__Result)i1;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10269))+8);
          i2 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression((OOC_IR__Expression)i2);
          from = (OOC_X86_SSA__Result)i2;
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10308))+12);
          i0 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression((OOC_IR__Expression)i0);
          i3 = (OOC_INT32)sp;
          i4 = (OOC_INT32)b;
          i4 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddAdrRT((OOC_X86_SSA__Block)i4, (Object__String)((OOC_INT32)_c1));
          i5 = (OOC_INT32)b;
          i3 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr2((OOC_X86_SSA__Block)i5, 20, (OOC_X86_SSA__Result)i4, (OOC_X86_SSA__Result)i3);
          OOC_X86_SSA__InstrDesc_AddOpnd((OOC_X86_SSA__Instr)i3, (OOC_X86_SSA__Result)i0);
          OOC_X86_SSA__InstrDesc_AddOpnd((OOC_X86_SSA__Instr)i3, (OOC_X86_SSA__Result)i2);
          OOC_X86_SSA__InstrDesc_AddOpnd((OOC_X86_SSA__Instr)i3, (OOC_X86_SSA__Result)i1);
          OOC_X86_Translate__Translate_MemoryCP((OOC_X86_SSA__Instr)i3);
          OOC_X86_Translate__Translate_ControlCP((OOC_X86_SSA__Instr)i3);
          return;
          ;
        }

        
        OOC_X86_SSA__Result OOC_X86_Translate__Translate_StatmSeq_TypeTag(OOC_IR__Expression design, OOC_X86_SSA__Result value, OOC_CHAR8 checkDerefOfNil, OOC_Scanner_SymList__Symbol derefSym) {
          register OOC_INT32 i0,i1,i2;
          OOC_SymbolTable__Type type;

          i0 = (OOC_INT32)design;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10894))+4);
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10894))+4);
          i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 10899)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i2);
          type = (OOC_SymbolTable__Type)i1;
          i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 10931)))), OOC_SymbolTable__TypeDesc_Bound)),OOC_SymbolTable__TypeDesc_Bound)((OOC_SymbolTable__Type)i1);
          type = (OOC_SymbolTable__Type)i1;
          i2 = checkDerefOfNil;
          if (i2) goto l3;
          i2=0u;
          goto l5;
l3:
          i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 11024)))), &_td_OOC_SymbolTable__PointerDesc);
          
l5:
          if (i2) goto l6;
l6:
          i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 11267)))), &_td_OOC_SymbolTable__PointerDesc);
          if (i2) goto l21;
          i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11405)))), &_td_OOC_IR__VarDesc);
          if (i2) goto l11;
          i2=0u;
          goto l13;
l11:
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11442)))), &_td_OOC_IR__VarDesc, 11442)), 11446))+8);
          i2 = *(OOC_UINT8*)((_check_pointer((_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 11456)))), &_td_OOC_SymbolTable__VarDeclDesc, 11456)), 11464))+59);
          
l13:
          if (i2) goto l15;
          i0=0u;
          goto l17;
l15:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11514)))), &_td_OOC_IR__VarDesc, 11514)), 11518))+8);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11528)))), &_td_OOC_SymbolTable__VarDeclDesc, 11528)), 11536))+48);
          i0 = OOC_SymbolTable_TypeRules__IsRecord((OOC_SymbolTable__Type)i0);
          
l17:
          if (i0) goto l19;
          i0 = (OOC_INT32)b;
          i0 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddAdrTypeDescr((OOC_X86_SSA__Block)i0, (OOC_SymbolTable__Type)i1);
          return (OOC_X86_SSA__Result)i0;
          goto l22;
l19:
          _assert(0u, 127, 11602);
          goto l22;
l21:
          i0 = (OOC_INT32)value;
          i1 = (OOC_INT32)b;
          i0 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr1((OOC_X86_SSA__Block)i1, 33, (OOC_X86_SSA__Result)i0);
          i0 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AddResult((OOC_X86_SSA__Instr)i0, 9);
          return (OOC_X86_SSA__Result)i0;
l22:
          _failed_function(10570); return 0;
          ;
        }

        
        OOC_X86_SSA__Result OOC_X86_Translate__Translate_StatmSeq_Expression(OOC_IR__Expression expr) {
          register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7;
          OOC_INT16 typeId;
          OOC_SymbolTable__VarDecl varDecl;
          OOC_X86_SSA__Var var;
          OOC_X86_SSA__Result adr;
          OOC_X86_SSA__Instr instr;
          OOC_X86_SSA__Designator designator;
          OOC_X86_SSA__Result baseArray;
          OOC_INT32 dim;
          OOC_X86_SSA__Result res;
          OOC_SymbolTable__Type type;
          OOC_INT8 opcode;
          OOC_X86_SSA__Result arg1;
          OOC_X86_SSA__Result arg2;
          OOC_X86_SSA__Instr memoryFalse;
          OOC_X86_SSA__Instr controlFalse;
          OOC_X86_SSA__Instr memoryTrue;
          OOC_X86_SSA__Instr controlTrue;
          OOC_X86_SSA__Instr endTrue;
          OOC_X86_SSA__Instr endFalse;
          OOC_X86_SSA__MergeInstr merge;
          auto OOC_X86_SSA__Result OOC_X86_Translate__Translate_StatmSeq_Expression_GetIndexBaseArray(OOC_IR__Expression indexOp, OOC_INT32 *dim);
          auto OOC_X86_SSA__Result OOC_X86_Translate__Translate_StatmSeq_Expression_CalculateLength(OOC_X86_SSA__FunctionBlock pb, OOC_IR__Expression value, OOC_INT32 dim, OOC_X86_SSA__Result baseArray);
          auto OOC_X86_SSA__Result OOC_X86_Translate__Translate_StatmSeq_Expression_CalculateSize(OOC_X86_SSA__FunctionBlock pb, OOC_IR__Expression value, OOC_X86_SSA__Result length);
          auto OOC_X86_SSA__Result OOC_X86_Translate__Translate_StatmSeq_Expression_Index(OOC_IR__Index indexOp, OOC_X86_SSA__Result baseArray, OOC_X86_SSA__Result elementSize, OOC_INT32 dim);
          auto OOC_X86_SSA__Result OOC_X86_Translate__Translate_StatmSeq_Expression_SelectField(OOC_IR__SelectField selectOp);
          auto OOC_X86_SSA__Result OOC_X86_Translate__Translate_StatmSeq_Expression_TypeGuard(OOC_IR__TypeGuard guard);
          auto OOC_X86_SSA__Result OOC_X86_Translate__Translate_StatmSeq_Expression_TypeConv(OOC_IR__TypeConv conv);
          auto OOC_X86_SSA__Result OOC_X86_Translate__Translate_StatmSeq_Expression_NewObject(OOC_IR__NewObject _new);
            
            OOC_X86_SSA__Result OOC_X86_Translate__Translate_StatmSeq_Expression_GetIndexBaseArray(OOC_IR__Expression indexOp, OOC_INT32 *dim) {
              register OOC_INT32 i0,i1;

              i0 = (OOC_INT32)indexOp;
              i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12497)))), &_td_OOC_IR__IndexDesc);
              if (i1) goto l3;
              *dim = (-1);
              i0 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression((OOC_IR__Expression)i0);
              return (OOC_X86_SSA__Result)i0;
              goto l4;
l3:
              i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12555))+8);
              i0 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression_GetIndexBaseArray((OOC_IR__Expression)i0, (void*)(OOC_INT32)dim);
              i1 = *dim;
              *dim = (i1+1);
              return (OOC_X86_SSA__Result)i0;
l4:
              _failed_function(12319); return 0;
              ;
            }

            
            OOC_X86_SSA__Result OOC_X86_Translate__Translate_StatmSeq_Expression_CalculateLength(OOC_X86_SSA__FunctionBlock pb, OOC_IR__Expression value, OOC_INT32 dim, OOC_X86_SSA__Result baseArray) {
              register OOC_INT32 i0,i1,i2,i3;
              OOC_SymbolTable__Type type;
              OOC_INT32 i;
              auto OOC_X86_SSA__Result OOC_X86_Translate__Translate_StatmSeq_Expression_CalculateLength_RecursiveGetLength(OOC_SymbolTable__Type type, OOC_INT32 dim);
                
                OOC_X86_SSA__Result OOC_X86_Translate__Translate_StatmSeq_Expression_CalculateLength_RecursiveGetLength(OOC_SymbolTable__Type type, OOC_INT32 dim) {
                  register OOC_INT32 i0,i1,i2,i3;
                  OOC_X86_SSA__Result len;

                  i0 = (OOC_INT32)type;
                  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13572)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
                  type = (OOC_SymbolTable__Type)i0;
                  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13605)))), &_td_OOC_SymbolTable__ArrayDesc);
                  if (i1) goto l3;
                  i0 = (OOC_INT32)pb;
                  i0 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddConstLength((OOC_X86_SSA__Block)i0, 1);
                  return (OOC_X86_SSA__Result)i0;
                  goto l12;
l3:
                  i1 = *(OOC_UINT8*)((_check_pointer(i0, 13641))+40);
                  if (i1) goto l6;
                  i1 = *(OOC_INT32*)((_check_pointer(i0, 13799))+52);
                  i2 = (OOC_INT32)pb;
                  i1 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddConstLength((OOC_X86_SSA__Block)i2, i1);
                  
                  goto l7;
l6:
                  i1 = (OOC_INT32)baseArray;
                  i2 = dim;
                  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 13713))+4);
                  i3 = (OOC_INT32)pb;
                  i1 = (OOC_INT32)OOC_X86_SSA__FunctionBlockDesc_AddGetLengthInstr((OOC_X86_SSA__FunctionBlock)i3, (OOC_X86_SSA__Instr)i1, (i2+1), (OOC_SymbolTable__Array)i0);
                  
l7:
                  i1 = (OOC_INT32)OOC_X86_Translate__Translate_FixLength((OOC_X86_SSA__Result)i1);
                  len = (OOC_X86_SSA__Result)i1;
                  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13912))+44);
                  i2 = OOC_SymbolTable_TypeRules__IsArray((OOC_SymbolTable__Type)i2);
                  if (i2) goto l10;
                  return (OOC_X86_SSA__Result)i1;
                  goto l12;
l10:
                  i2 = dim;
                  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14040))+44);
                  i0 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression_CalculateLength_RecursiveGetLength((OOC_SymbolTable__Type)i0, (i2+1));
                  i2 = (OOC_INT32)b;
                  i0 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr2((OOC_X86_SSA__Block)i2, 3, (OOC_X86_SSA__Result)i1, (OOC_X86_SSA__Result)i0);
                  i0 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AddResult((OOC_X86_SSA__Instr)i0, 3);
                  return (OOC_X86_SSA__Result)i0;
l12:
                  _failed_function(13403); return 0;
                  ;
                }


              i0 = (OOC_INT32)value;
              i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14435)))), &_td_OOC_IR__IndexDesc);
              if (!i1) goto l9;
l4_loop:
              i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14481)))), &_td_OOC_IR__IndexDesc, 14481)), 14487))+8);
              i1 = dim;
              value = (OOC_IR__Expression)i0;
              dim = (i1+1);
              i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14435)))), &_td_OOC_IR__IndexDesc);
              if (i1) goto l4_loop;
l9:
              i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14627))+4);
              type = (OOC_SymbolTable__Type)i0;
              i = 0;
              i1 = dim;
              i2 = 0<=i1;
              if (!i2) goto l18;
              i2=0;
l13_loop:
              i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14690)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
              type = (OOC_SymbolTable__Type)i0;
              i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14731)))), &_td_OOC_SymbolTable__ArrayDesc, 14731)), 14737))+44);
              type = (OOC_SymbolTable__Type)i0;
              i2 = i2+1;
              i = i2;
              i3 = i2<=i1;
              if (i3) goto l13_loop;
l18:
              i0 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression_CalculateLength_RecursiveGetLength((OOC_SymbolTable__Type)i0, i1);
              return (OOC_X86_SSA__Result)i0;
              ;
            }

            
            OOC_X86_SSA__Result OOC_X86_Translate__Translate_StatmSeq_Expression_CalculateSize(OOC_X86_SSA__FunctionBlock pb, OOC_IR__Expression value, OOC_X86_SSA__Result length) {
              register OOC_INT32 i0,i1,i2;
              OOC_SymbolTable__Type type;

              i0 = (OOC_INT32)value;
              i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 15374)))), &_td_OOC_IR__IndexDesc);
              if (!i1) goto l9;
l4_loop:
              i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 15420)))), &_td_OOC_IR__IndexDesc, 15420)), 15426))+8);
              value = (OOC_IR__Expression)i0;
              i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 15374)))), &_td_OOC_IR__IndexDesc);
              if (i1) goto l4_loop;
l9:
              i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15542))+4);
              type = (OOC_SymbolTable__Type)i0;
              i1 = OOC_SymbolTable_TypeRules__IsArrayType((OOC_SymbolTable__Type)i0);
              if (!i1) goto l18;
l13_loop:
              i0 = (OOC_INT32)OOC_SymbolTable_TypeRules__ArrayElementType((OOC_SymbolTable__Type)i0);
              type = (OOC_SymbolTable__Type)i0;
              i1 = OOC_SymbolTable_TypeRules__IsArrayType((OOC_SymbolTable__Type)i0);
              if (i1) goto l13_loop;
l18:
              i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 15673)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
              type = (OOC_SymbolTable__Type)i0;
              i0 = *(OOC_INT32*)((_check_pointer(i0, 15849))+32);
              i1 = (OOC_INT32)pb;
              i0 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddConstLength((OOC_X86_SSA__Block)i1, i0);
              i0 = (OOC_INT32)OOC_X86_Translate__Translate_FixAddress((OOC_X86_SSA__Result)i0);
              i2 = (OOC_INT32)length;
              i2 = (OOC_INT32)OOC_X86_Translate__Translate_FixAddress((OOC_X86_SSA__Result)i2);
              i0 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr2((OOC_X86_SSA__Block)i1, 3, (OOC_X86_SSA__Result)i2, (OOC_X86_SSA__Result)i0);
              i0 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AddResult((OOC_X86_SSA__Instr)i0, 3);
              return (OOC_X86_SSA__Result)i0;
              ;
            }

            
            OOC_X86_SSA__Result OOC_X86_Translate__Translate_StatmSeq_Expression_Index(OOC_IR__Index indexOp, OOC_X86_SSA__Result baseArray, OOC_X86_SSA__Result elementSize, OOC_INT32 dim) {
              register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
              OOC_SymbolTable__Type arrayType;
              OOC_X86_SSA__Result length;
              OOC_X86_SSA__Instr instr;
              OOC_X86_SSA__Result newSize;
              OOC_X86_SSA__Result baseResult;
              OOC_X86_SSA__Result index;
              OOC_SymbolTable__Type elementType;
              OOC_X86_SSA__Instr instr1;
              OOC_X86_SSA__Result scaledIndex;
              OOC_X86_SSA__Opnd adrOpnd;
              OOC_X86_SSA__Result elementAdr;

              i0 = (OOC_INT32)indexOp;
              i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16869))+8);
              i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16869))+8);
              i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 16875))+4);
              i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 16875))+4);
              i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 16880)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i1);
              arrayType = (OOC_SymbolTable__Type)i1;
              i2 = (OOC_INT32)baseArray;
              i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 16941))+4);
              i4 = (OOC_INT32)b;
              i5 = dim;
              i1 = (OOC_INT32)OOC_X86_SSA__FunctionBlockDesc_AddGetLengthInstr((OOC_X86_SSA__FunctionBlock)i4, (OOC_X86_SSA__Instr)i3, i5, (OOC_SymbolTable__Array)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 17008)))), &_td_OOC_SymbolTable__ArrayDesc, 17008)));
              length = (OOC_X86_SSA__Result)i1;
              i1 = (OOC_INT32)OOC_X86_Translate__Translate_FixAddress((OOC_X86_SSA__Result)i1);
              i3 = (OOC_INT32)elementSize;
              i4 = (OOC_INT32)b;
              i1 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr2((OOC_X86_SSA__Block)i4, 3, (OOC_X86_SSA__Result)i3, (OOC_X86_SSA__Result)i1);
              instr = (OOC_X86_SSA__Instr)i1;
              i1 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AddResult((OOC_X86_SSA__Instr)i1, 9);
              newSize = (OOC_X86_SSA__Result)i1;
              i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17170))+8);
              i4 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 17177)))), &_td_OOC_IR__IndexDesc);
              if (i4) goto l3;
              baseResult = (OOC_X86_SSA__Result)i2;
              _assert((i5==0), 127, 17376);
              i1=i2;
              goto l4;
l3:
              i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17234))+8);
              i1 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression_Index((OOC_IR__Index)(_type_guard(i4, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 17244)))), &_td_OOC_IR__IndexDesc, 17244)), (OOC_X86_SSA__Result)i2, (OOC_X86_SSA__Result)i1, (i5-1));
              baseResult = (OOC_X86_SSA__Result)i1;
              
l4:
              dim = (i5+1);
              i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 17455))+4);
              i2 = *(OOC_INT8*)((_check_pointer(i2, 17461))+20);
              _assert((i2==24), 127, 17438);
              i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 17855))+4);
              instr = (OOC_X86_SSA__Instr)i1;
              i2 = (OOC_INT32)OOC_X86_SSA__InstrDesc_GetBeforeInstr((OOC_X86_SSA__Instr)i1, 1);
              memoryCP = (OOC_X86_SSA__Instr)i2;
              i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18020))+12);
              i2 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression((OOC_IR__Expression)i2);
              index = (OOC_X86_SSA__Result)i2;
              OOC_X86_SSA__InstrDesc_DeleteDep((OOC_X86_SSA__Instr)i1, 1);
              OOC_X86_Translate__Translate_MemoryCP((OOC_X86_SSA__Instr)i1);
              i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18454))+4);
              elementType = (OOC_SymbolTable__Type)i4;
              i4 = (OOC_INT32)OOC_X86_Translate__Translate_FixAddress((OOC_X86_SSA__Result)i2);
              i5 = (OOC_INT32)b;
              i3 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr2((OOC_X86_SSA__Block)i5, 3, (OOC_X86_SSA__Result)i4, (OOC_X86_SSA__Result)i3);
              instr1 = (OOC_X86_SSA__Instr)i3;
              i3 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AddResult((OOC_X86_SSA__Instr)i3, 9);
              scaledIndex = (OOC_X86_SSA__Result)i3;
              i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 18624));
              adrOpnd = (OOC_X86_SSA__Opnd)i4;
              i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 18681));
              i6 = (OOC_INT32)b;
              i3 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr2((OOC_X86_SSA__Block)i6, 1, (OOC_X86_SSA__Result)i5, (OOC_X86_SSA__Result)i3);
              instr1 = (OOC_X86_SSA__Instr)i3;
              i3 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AddResult((OOC_X86_SSA__Instr)i3, 9);
              elementAdr = (OOC_X86_SSA__Result)i3;
              OOC_X86_SSA__OpndDesc_ReplaceArg((OOC_X86_SSA__Opnd)i4, (OOC_X86_SSA__Result)i3);
              i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18848))+4);
              i0 = OOC_X86_SSA__MapType((OOC_SymbolTable__Type)i0);
              i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 18811))+4);
              OOC_X86_SSA__ResultDesc_SetType((OOC_X86_SSA__Result)i3, i0);
              i0 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_SSA__Index.baseTypes[0]);
              i3 = (OOC_INT32)b;
              OOC_X86_SSA__IndexDesc_INIT((OOC_X86_SSA__Index)i0, (OOC_X86_SSA__FunctionBlock)i3, (OOC_X86_SSA__Result)i2);
              OOC_X86_SSA__InstrDesc_ExtendDesignator((OOC_X86_SSA__Instr)i1, (OOC_X86_SSA__Selector)i0);
              i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 18959))+4);
              return (OOC_X86_SSA__Result)i0;
              ;
            }

            
            OOC_X86_SSA__Result OOC_X86_Translate__Translate_StatmSeq_Expression_SelectField(OOC_IR__SelectField selectOp) {
              register OOC_INT32 i0,i1,i2,i3,i4,i5;
              OOC_X86_SSA__Result baseResult;
              OOC_X86_SSA__Instr instr;
              OOC_X86_SSA__Opnd adrOpnd;
              OOC_X86_SSA__Instr fieldAdr;

              i0 = (OOC_INT32)selectOp;
              i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19352))+8);
              i1 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression((OOC_IR__Expression)i1);
              baseResult = (OOC_X86_SSA__Result)i1;
              i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 19390))+4);
              i2 = *(OOC_INT8*)((_check_pointer(i2, 19396))+20);
              _assert((i2==24), 127, 19372);
              i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 19443))+4);
              instr = (OOC_X86_SSA__Instr)i1;
              i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 19488));
              adrOpnd = (OOC_X86_SSA__Opnd)i2;
              i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19612))+12);
              i3 = *(OOC_INT32*)((_check_pointer(i3, 19618))+56);
              i4 = (OOC_INT32)b;
              i3 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddConstLength((OOC_X86_SSA__Block)i4, i3);
              i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 19547));
              i5 = (OOC_INT32)b;
              i3 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr2((OOC_X86_SSA__Block)i5, 1, (OOC_X86_SSA__Result)i4, (OOC_X86_SSA__Result)i3);
              fieldAdr = (OOC_X86_SSA__Instr)i3;
              i3 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AddResult((OOC_X86_SSA__Instr)i3, 9);
              OOC_X86_SSA__OpndDesc_ReplaceArg((OOC_X86_SSA__Opnd)i2, (OOC_X86_SSA__Result)i3);
              i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19743))+4);
              i2 = OOC_X86_SSA__MapType((OOC_SymbolTable__Type)i2);
              i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 19705))+4);
              OOC_X86_SSA__ResultDesc_SetType((OOC_X86_SSA__Result)i3, i2);
              i2 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_SSA__Field.baseTypes[0]);
              i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19817))+12);
              OOC_X86_SSA__FieldDesc_INIT((OOC_X86_SSA__Field)i2, (OOC_SymbolTable__FieldDecl)i0);
              OOC_X86_SSA__InstrDesc_ExtendDesignator((OOC_X86_SSA__Instr)i1, (OOC_X86_SSA__Selector)i2);
              i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 19860))+4);
              return (OOC_X86_SSA__Result)i0;
              ;
            }

            
            OOC_X86_SSA__Result OOC_X86_Translate__Translate_StatmSeq_Expression_TypeGuard(OOC_IR__TypeGuard guard) {
              register OOC_INT32 i0;

              i0 = (OOC_INT32)guard;
              i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20026))+8);
              i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20031))+20);
              i0 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression((OOC_IR__Expression)i0);
              return (OOC_X86_SSA__Result)i0;
              ;
            }

            
            OOC_X86_SSA__Result OOC_X86_Translate__Translate_StatmSeq_Expression_TypeConv(OOC_IR__TypeConv conv) {
              register OOC_INT32 i0,i1,i2;
              OOC_INT8 typeDest;
              OOC_INT8 typeSource;

              i0 = (OOC_INT32)conv;
              i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20321))+4);
              i1 = OOC_SymbolTable_TypeRules__IsSTRING((OOC_SymbolTable__Type)i1);
              if (i1) goto l7;
              i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21983))+4);
              i1 = OOC_X86_SSA__MapType((OOC_SymbolTable__Type)i1);
              typeDest = i1;
              i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22031))+8);
              i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 22036))+4);
              i2 = OOC_X86_SSA__MapType((OOC_SymbolTable__Type)i2);
              typeSource = i2;
              i2 = i1!=i2;
              if (i2) goto l5;
              i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22260))+8);
              i0 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression((OOC_IR__Expression)i0);
              return (OOC_X86_SSA__Result)i0;
              goto l8;
l5:
              i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22150))+8);
              i0 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression((OOC_IR__Expression)i0);
              i2 = (OOC_INT32)b;
              i0 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr1((OOC_X86_SSA__Block)i2, 16, (OOC_X86_SSA__Result)i0);
              i0 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AddResult((OOC_X86_SSA__Instr)i0, i1);
              return (OOC_X86_SSA__Result)i0;
              goto l8;
l7:
              return (OOC_X86_SSA__Result)(OOC_INT32)0;
l8:
              _failed_function(20083); return 0;
              ;
            }

            
            OOC_X86_SSA__Result OOC_X86_Translate__Translate_StatmSeq_Expression_NewObject(OOC_IR__NewObject _new) {
              register OOC_INT32 i0,i1,i2,i3;

              i0 = (OOC_INT32)_new;
              i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22593))+4);
              i1 = (OOC_INT32)b;
              i0 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddAdrTypeDescr((OOC_X86_SSA__Block)i1, (OOC_SymbolTable__Type)i0);
              i1 = (OOC_INT32)b;
              i0 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr1((OOC_X86_SSA__Block)i1, 24, (OOC_X86_SSA__Result)i0);
              i0 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AddResult((OOC_X86_SSA__Instr)i0, 9);
              i1 = (OOC_INT32)b;
              i0 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr1((OOC_X86_SSA__Block)i1, 24, (OOC_X86_SSA__Result)i0);
              i0 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AddResult((OOC_X86_SSA__Instr)i0, 9);
              i1 = (OOC_INT32)sp;
              i2 = (OOC_INT32)b;
              i2 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddAdrRT((OOC_X86_SSA__Block)i2, (Object__String)((OOC_INT32)_c2));
              i3 = (OOC_INT32)b;
              i0 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr3((OOC_X86_SSA__Block)i3, 20, (OOC_X86_SSA__Result)i2, (OOC_X86_SSA__Result)i1, (OOC_X86_SSA__Result)i0);
              OOC_X86_Translate__Translate_MemoryCP((OOC_X86_SSA__Instr)i0);
              OOC_X86_Translate__Translate_ControlCP((OOC_X86_SSA__Instr)i0);
              i0 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AddResult((OOC_X86_SSA__Instr)i0, 9);
              return (OOC_X86_SSA__Result)i0;
              ;
            }


          i0 = (OOC_INT32)expr;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 23265)))), &_td_OOC_IR__ConstDesc);
          if (i1) goto l114;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 23707)))), &_td_OOC_IR__ProcedureRefDesc);
          if (i1) goto l112;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 23818)))), &_td_OOC_IR__VarDesc);
          if (i1) goto l99;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 24807)))), &_td_OOC_IR__IndexDesc);
          if (i1) goto l97;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 25094)))), &_td_OOC_IR__SelectFieldDesc);
          if (i1) goto l95;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 25175)))), &_td_OOC_IR__DerefDesc);
          if (i1) goto l91;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 25923)))), &_td_OOC_IR__AdrDesc);
          if (i1) goto l85;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 26322)))), &_td_OOC_IR__LenDesc);
          if (i1) goto l79;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 26885)))), &_td_OOC_IR__TypeTagDesc);
          if (i1) goto l77;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 27036)))), &_td_OOC_IR__TypeTestDesc);
          if (i1) goto l75;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 27446)))), &_td_OOC_IR__TypeGuardDesc);
          if (i1) goto l73;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 27527)))), &_td_OOC_IR__TypeConvDesc);
          if (i1) goto l71;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 27606)))), &_td_OOC_IR__BinaryArithDesc);
          if (i1) goto l64;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 28393)))), &_td_OOC_IR__NegateDesc);
          if (i1) goto l62;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 28537)))), &_td_OOC_IR__CompareDesc);
          if (i1) goto l51;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 29061)))), &_td_OOC_IR__BooleanOpDesc);
          if (i1) goto l41;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 30496)))), &_td_OOC_IR__CallDesc);
          if (i1) goto l39;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 30552)))), &_td_OOC_IR__NewObjectDesc);
          if (i1) goto l37;
          _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 30546)))), 30546);
          goto l120;
l37:
          i0 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression_NewObject((OOC_IR__NewObject)i0);
          return (OOC_X86_SSA__Result)i0;
          goto l120;
l39:
          i0 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Call((OOC_IR__Call)i0);
          return (OOC_X86_SSA__Result)i0;
          goto l120;
l41:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 29150))+12);
          i1 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression((OOC_IR__Expression)i1);
          res = (OOC_X86_SSA__Result)i1;
          i2 = (OOC_INT32)memoryCP;
          i3 = (OOC_INT32)controlCP;
          OOC_X86_Translate__Translate_StatmSeq_SplitPaths((OOC_X86_SSA__Result)i1, (OOC_X86_SSA__Instr)i3, (OOC_X86_SSA__Instr)i2, (void*)(OOC_INT32)&controlTrue, (void*)(OOC_INT32)&memoryTrue, (void*)(OOC_INT32)&controlFalse, (void*)(OOC_INT32)&memoryFalse);
          i1 = (OOC_INT32)memoryTrue;
          memoryCP = (OOC_X86_SSA__Instr)i1;
          i1 = (OOC_INT32)controlTrue;
          controlCP = (OOC_X86_SSA__Instr)i1;
          i1 = *(OOC_INT8*)((_check_pointer(i0, 29417))+8);
          i1 = i1==20;
          if (i1) goto l44;
          i1 = (OOC_INT32)b;
          i1 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddConstBool((OOC_X86_SSA__Block)i1, 1u);
          arg1 = (OOC_X86_SSA__Result)i1;
          
          goto l45;
l44:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 29512))+16);
          i1 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression((OOC_IR__Expression)i1);
          i1 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_SetBool((OOC_X86_SSA__Result)i1);
          arg1 = (OOC_X86_SSA__Result)i1;
          
l45:
          i2 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_AddJump();
          endTrue = (OOC_X86_SSA__Instr)i2;
          i3 = (OOC_INT32)memoryFalse;
          memoryCP = (OOC_X86_SSA__Instr)i3;
          i3 = (OOC_INT32)controlFalse;
          controlCP = (OOC_X86_SSA__Instr)i3;
          i3 = *(OOC_INT8*)((_check_pointer(i0, 29803))+8);
          i3 = i3==20;
          if (i3) goto l48;
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 30013))+16);
          i3 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression((OOC_IR__Expression)i3);
          i3 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_SetBool((OOC_X86_SSA__Result)i3);
          arg2 = (OOC_X86_SSA__Result)i3;
          
          goto l49;
l48:
          i3 = (OOC_INT32)b;
          i3 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddConstBool((OOC_X86_SSA__Block)i3, 0u);
          arg2 = (OOC_X86_SSA__Result)i3;
          
l49:
          i4 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_AddJump();
          endFalse = (OOC_X86_SSA__Instr)i4;
          i5 = (OOC_INT32)b;
          i2 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddMerge2((OOC_X86_SSA__Block)i5, 36, (OOC_X86_SSA__Instr)i2, (OOC_X86_SSA__Instr)i4);
          merge = (OOC_X86_SSA__MergeInstr)i2;
          controlCP = (OOC_X86_SSA__Instr)i2;
          memoryCP = (OOC_X86_SSA__Instr)i2;
          i2 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddGate((OOC_X86_SSA__Block)i2, 38);
          instr = (OOC_X86_SSA__Instr)i2;
          OOC_X86_SSA__InstrDesc_AddOpnd((OOC_X86_SSA__Instr)i2, (OOC_X86_SSA__Result)i1);
          OOC_X86_SSA__InstrDesc_AddOpnd((OOC_X86_SSA__Instr)i2, (OOC_X86_SSA__Result)i3);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 30473))+4);
          i0 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AddResultExpr((OOC_X86_SSA__Instr)i2, (OOC_SymbolTable__Type)i0);
          return (OOC_X86_SSA__Result)i0;
          goto l120;
l51:
          i1 = *(OOC_INT8*)((_check_pointer(i0, 28572))+8);
          switch (i1) {
          case 10:
            opcode = 9;
            goto l60;
          case 11:
            opcode = 10;
            goto l60;
          case 12:
            opcode = 11;
            goto l60;
          case 13:
            opcode = 12;
            goto l60;
          case 14:
            opcode = 13;
            goto l60;
          case 15:
            opcode = 14;
            goto l60;
          default:
            _failed_case(i1, 28563);
            goto l60;
          }
l60:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 28881))+12);
          i1 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression((OOC_IR__Expression)i1);
          arg1 = (OOC_X86_SSA__Result)i1;
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 28922))+16);
          i0 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression((OOC_IR__Expression)i0);
          i2 = (OOC_INT32)b;
          i3 = opcode;
          i0 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr2((OOC_X86_SSA__Block)i2, i3, (OOC_X86_SSA__Result)i1, (OOC_X86_SSA__Result)i0);
          i0 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AddResultReg((OOC_X86_SSA__Instr)i0, 0, 2);
          return (OOC_X86_SSA__Result)i0;
          goto l120;
l62:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 28461))+8);
          i1 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression((OOC_IR__Expression)i1);
          i2 = (OOC_INT32)b;
          i1 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr1((OOC_X86_SSA__Block)i2, 5, (OOC_X86_SSA__Result)i1);
          instr = (OOC_X86_SSA__Instr)i1;
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 28514))+4);
          i0 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AddResultExpr((OOC_X86_SSA__Instr)i1, (OOC_SymbolTable__Type)i0);
          return (OOC_X86_SSA__Result)i0;
          goto l120;
l64:
          i1 = *(OOC_INT8*)((_check_pointer(i0, 27645))+8);
          switch (i1) {
          case 0:
            opcode = 1;
            goto l69;
          case 1:
            opcode = 2;
            goto l69;
          default:
            _failed_case(i1, 27636);
            goto l69;
          }
l69:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 28217))+12);
          i1 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression((OOC_IR__Expression)i1);
          arg1 = (OOC_X86_SSA__Result)i1;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 28258))+16);
          i2 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression((OOC_IR__Expression)i2);
          arg2 = (OOC_X86_SSA__Result)i2;
          i3 = (OOC_INT32)b;
          i4 = opcode;
          i1 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr2((OOC_X86_SSA__Block)i3, i4, (OOC_X86_SSA__Result)i1, (OOC_X86_SSA__Result)i2);
          instr = (OOC_X86_SSA__Instr)i1;
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 28360))+4);
          i0 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AddResultExpr((OOC_X86_SSA__Instr)i1, (OOC_SymbolTable__Type)i0);
          return (OOC_X86_SSA__Result)i0;
          goto l120;
l71:
          i0 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression_TypeConv((OOC_IR__TypeConv)i0);
          return (OOC_X86_SSA__Result)i0;
          goto l120;
l73:
          i0 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression_TypeGuard((OOC_IR__TypeGuard)i0);
          return (OOC_X86_SSA__Result)i0;
          goto l120;
l75:
          i1 = (OOC_INT32)sp;
          i2 = (OOC_INT32)b;
          i2 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddAdrRT((OOC_X86_SSA__Block)i2, (Object__String)((OOC_INT32)_c3));
          i3 = (OOC_INT32)b;
          i1 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr2((OOC_X86_SSA__Block)i3, 20, (OOC_X86_SSA__Result)i2, (OOC_X86_SSA__Result)i1);
          instr = (OOC_X86_SSA__Instr)i1;
          i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 27249));
          i3 = *(OOC_UINT8*)((_check_pointer(i0, 27230))+16);
          i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 27185))+8);
          i4 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression((OOC_IR__Expression)i4);
          i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 27163))+8);
          i2 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_TypeTag((OOC_IR__Expression)i5, (OOC_X86_SSA__Result)i4, i3, (OOC_Scanner_SymList__Symbol)i2);
          OOC_X86_SSA__InstrDesc_AddOpnd((OOC_X86_SSA__Instr)i1, (OOC_X86_SSA__Result)i2);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 27303))+12);
          i2 = (OOC_INT32)b;
          i0 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddAdrTypeDescr((OOC_X86_SSA__Block)i2, (OOC_SymbolTable__Type)i0);
          OOC_X86_SSA__InstrDesc_AddOpnd((OOC_X86_SSA__Instr)i1, (OOC_X86_SSA__Result)i0);
          OOC_X86_Translate__Translate_MemoryCP((OOC_X86_SSA__Instr)i1);
          OOC_X86_Translate__Translate_ControlCP((OOC_X86_SSA__Instr)i1);
          i0 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AddResult((OOC_X86_SSA__Instr)i1, 5);
          return (OOC_X86_SSA__Result)i0;
          goto l120;
l77:
          i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 27000));
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 26954))+8);
          i2 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression((OOC_IR__Expression)i2);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 26930))+8);
          i0 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_TypeTag((OOC_IR__Expression)i0, (OOC_X86_SSA__Result)i2, 0u, (OOC_Scanner_SymList__Symbol)i1);
          return (OOC_X86_SSA__Result)i0;
          goto l120;
l79:
          i1 = *(OOC_INT8*)((_check_pointer(i0, 26352))+8);
          i1 = i1==16;
          if (i1) goto l82;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 26581))+20);
          i1 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression((OOC_IR__Expression)i1);
          baseArray = (OOC_X86_SSA__Result)i1;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 26622))+20);
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 26622))+20);
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 26636))+4);
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 26636))+4);
          i2 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 26641)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i2);
          type = (OOC_SymbolTable__Type)i2;
          i3 = *(OOC_INT32*)((_check_pointer(i0, 26711))+16);
          i2 = (OOC_INT32)OOC_SymbolTable__ArrayDesc_GetNthElementType((OOC_SymbolTable__Array)(_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 26682)))), &_td_OOC_SymbolTable__ArrayDesc, 26682)), i3);
          type = (OOC_SymbolTable__Type)i2;
          i0 = *(OOC_INT32*)((_check_pointer(i0, 26778))+16);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 26766))+4);
          i3 = (OOC_INT32)b;
          i0 = (OOC_INT32)OOC_X86_SSA__FunctionBlockDesc_AddGetLengthInstr((OOC_X86_SSA__FunctionBlock)i3, (OOC_X86_SSA__Instr)i1, i0, (OOC_SymbolTable__Array)(_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 26832)))), &_td_OOC_SymbolTable__ArrayDesc, 26832)));
          return (OOC_X86_SSA__Result)i0;
          goto l120;
l82:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 26427))+20);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 26445)))), &_td_OOC_IR__ConstDesc, 26445)), 26451))+8);
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 26501)))), &_td_Object_Boxed__StringDesc, 26501)), 26508));
          i0 = *(OOC_INT32*)(_check_pointer(i0, 26514));
          i1 = (OOC_INT32)b;
          i0 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddConstLength((OOC_X86_SSA__Block)i1, (i0+1));
          return (OOC_X86_SSA__Result)i0;
          goto l120;
l85:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25967))+8);
          i0 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression((OOC_IR__Expression)i0);
          res = (OOC_X86_SSA__Result)i0;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25994))+4);
          i1 = *(OOC_INT8*)((_check_pointer(i1, 26000))+20);
          i1 = i1==24;
          if (i1) goto l88;
          return (OOC_X86_SSA__Result)i0;
          goto l120;
l88:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 26054))+4);
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 26060));
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 26069));
          i1 = (OOC_INT32)b;
          i0 = (OOC_INT32)OOC_X86_SSA__FunctionBlockDesc_FixType((OOC_X86_SSA__FunctionBlock)i1, (OOC_X86_SSA__Result)i0, 9);
          return (OOC_X86_SSA__Result)i0;
          goto l120;
l91:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25324))+8);
          i1 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression((OOC_IR__Expression)i1);
          adr = (OOC_X86_SSA__Result)i1;
          i2 = *(OOC_UINT8*)((_check_pointer(i0, 25352))+12);
          if (i2) goto l93;
l93:
          i2 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_SSA__Designator.baseTypes[0], 1);
          designator = (OOC_X86_SSA__Designator)i2;
          i3 = _check_pointer(i2, 25665);
          i4 = OOC_ARRAY_LENGTH(i3, 0);
          i5 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_SSA__HeapObj.baseTypes[0]);
          i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25694))+4);
          i7 = (OOC_INT32)b;
          OOC_X86_SSA__HeapObjDesc_INIT((OOC_X86_SSA__HeapObj)i5, (OOC_X86_SSA__FunctionBlock)i7, (OOC_SymbolTable__Type)i6, (OOC_X86_SSA__Result)i1);
          *(OOC_INT32*)(i3+(_check_index(0, i4, OOC_UINT8, 25665))*4) = i5;
          i3 = (OOC_INT32)b;
          i1 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr1((OOC_X86_SSA__Block)i3, 24, (OOC_X86_SSA__Result)i1);
          instr = (OOC_X86_SSA__Instr)i1;
          OOC_X86_SSA__InstrDesc_SetDesignator((OOC_X86_SSA__Instr)i1, (OOC_X86_SSA__Designator)i2);
          OOC_X86_Translate__Translate_MemoryCP((OOC_X86_SSA__Instr)i1);
          OOC_X86_Translate__Translate_ControlCP((OOC_X86_SSA__Instr)i1);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25890))+4);
          i0 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AddResultExpr((OOC_X86_SSA__Instr)i1, (OOC_SymbolTable__Type)i0);
          return (OOC_X86_SSA__Result)i0;
          goto l120;
l95:
          i0 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression_SelectField((OOC_IR__SelectField)i0);
          return (OOC_X86_SSA__Result)i0;
          goto l120;
l97:
          i0 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression_GetIndexBaseArray((OOC_IR__Expression)i0, (void*)(OOC_INT32)&dim);
          baseArray = (OOC_X86_SSA__Result)i0;
          i1 = dim;
          i2 = (OOC_INT32)expr;
          i3 = (OOC_INT32)b;
          i0 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression_CalculateLength((OOC_X86_SSA__FunctionBlock)i3, (OOC_IR__Expression)i2, (-1), (OOC_X86_SSA__Result)i0);
          i2 = (OOC_INT32)expr;
          i3 = (OOC_INT32)b;
          i0 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression_CalculateSize((OOC_X86_SSA__FunctionBlock)i3, (OOC_IR__Expression)i2, (OOC_X86_SSA__Result)i0);
          i2 = (OOC_INT32)baseArray;
          i3 = (OOC_INT32)expr;
          i0 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression_Index((OOC_IR__Index)i3, (OOC_X86_SSA__Result)i2, (OOC_X86_SSA__Result)i0, i1);
          return (OOC_X86_SSA__Result)i0;
          goto l120;
l99:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23855))+8);
          i1 = _type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 23865)))), &_td_OOC_SymbolTable__VarDeclDesc, 23865);
          varDecl = (OOC_SymbolTable__VarDecl)i1;
          i2 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_SSA__Var.baseTypes[0]);
          OOC_X86_SSA__VarDesc_INIT((OOC_X86_SSA__Var)i2, (OOC_SymbolTable__VarDecl)i1);
          var = (OOC_X86_SSA__Var)i2;
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 23934))+4);
          i3 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 23942)))), &_td_OOC_SymbolTable__ModuleDesc);
          if (i3) goto l109;
          i3 = *(OOC_UINT8*)((_check_pointer(i1, 24112))+56);
          i3 = !i3;
          if (!i3) goto l104;
          i3 = (OOC_INT32)b;
          OOC_X86_SSA__FunctionBlockDesc_AllocateLocalVar((OOC_X86_SSA__FunctionBlock)i3, (OOC_SymbolTable__VarDecl)i1);
l104:
          i3 = (OOC_INT32)b;
          i3 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddFramePointerOffset((OOC_X86_SSA__Block)i3, (OOC_SymbolTable__VarDecl)i1);
          i4 = (OOC_INT32)fp;
          i5 = (OOC_INT32)b;
          i3 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr2((OOC_X86_SSA__Block)i5, 1, (OOC_X86_SSA__Result)i4, (OOC_X86_SSA__Result)i3);
          instr = (OOC_X86_SSA__Instr)i3;
          i3 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AddResult((OOC_X86_SSA__Instr)i3, 9);
          adr = (OOC_X86_SSA__Result)i3;
          i1 = *(OOC_UINT8*)((_check_pointer(i1, 24351))+60);
          if (i1) goto l107;
          i1=i3;
          goto l110;
l107:
          i1 = (OOC_INT32)b;
          i1 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr1((OOC_X86_SSA__Block)i1, 24, (OOC_X86_SSA__Result)i3);
          instr = (OOC_X86_SSA__Instr)i1;
          i1 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AddResult((OOC_X86_SSA__Instr)i1, 9);
          adr = (OOC_X86_SSA__Result)i1;
          
          goto l110;
l109:
          i1 = (OOC_INT32)b;
          i1 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddAdr((OOC_X86_SSA__Block)i1, (OOC_X86_SSA__Global)i2);
          adr = (OOC_X86_SSA__Result)i1;
          
l110:
          i3 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_SSA__Designator.baseTypes[0], 1);
          designator = (OOC_X86_SSA__Designator)i3;
          i4 = _check_pointer(i3, 24617);
          i5 = OOC_ARRAY_LENGTH(i4, 0);
          *(OOC_INT32*)(i4+(_check_index(0, i5, OOC_UINT8, 24617))*4) = i2;
          i2 = (OOC_INT32)b;
          i1 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr1((OOC_X86_SSA__Block)i2, 24, (OOC_X86_SSA__Result)i1);
          instr = (OOC_X86_SSA__Instr)i1;
          OOC_X86_SSA__InstrDesc_SetDesignator((OOC_X86_SSA__Instr)i1, (OOC_X86_SSA__Designator)i3);
          OOC_X86_Translate__Translate_MemoryCP((OOC_X86_SSA__Instr)i1);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24784))+4);
          i0 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AddResultExpr((OOC_X86_SSA__Instr)i1, (OOC_SymbolTable__Type)i0);
          return (OOC_X86_SSA__Result)i0;
          goto l120;
l112:
          i1 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_SSA__Proc.baseTypes[0]);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23770))+8);
          OOC_X86_SSA__ProcDesc_INIT((OOC_X86_SSA__Proc)i1, (OOC_SymbolTable__ProcDecl)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 23780)))), &_td_OOC_SymbolTable__ProcDeclDesc, 23780)));
          i0 = (OOC_INT32)b;
          i0 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddAdr((OOC_X86_SSA__Block)i0, (OOC_X86_SSA__Global)i1);
          return (OOC_X86_SSA__Result)i0;
          goto l120;
l114:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23303))+4);
          i1 = *(OOC_INT16*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 23313)))), &_td_OOC_SymbolTable__PredefTypeDesc, 23313)), 23324))+40);
          typeId = i1;
          switch (i1) {
          case 0:
            i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23420))+8);
            i0 = *(OOC_UINT8*)(_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 23433)))), &_td_Object_Boxed__BooleanDesc, 23433)), 23441));
            i1 = (OOC_INT32)b;
            i0 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddConstBool((OOC_X86_SSA__Block)i1, i0);
            return (OOC_X86_SSA__Result)i0;
            goto l120;
          case 13 ... 15:
            i2 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_SSA__Const.baseTypes[0]);
            i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23572))+4);
            i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23551))+8);
            OOC_X86_SSA__ConstDesc_INIT((OOC_X86_SSA__Const)i2, (Object_Boxed__Object)i0, i1);
            i0 = (OOC_INT32)b;
            i0 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddConst((OOC_X86_SSA__Block)i0, (OOC_X86_SSA__Const)i2, (OOC_SymbolTable__Type)i3);
            return (OOC_X86_SSA__Result)i0;
            goto l120;
          default:
            i1 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_SSA__Const.baseTypes[0]);
            i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23659))+4);
            i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23642))+8);
            OOC_X86_SSA__ConstDesc_INIT((OOC_X86_SSA__Const)i1, (Object_Boxed__Object)i0, (-1));
            i0 = (OOC_INT32)b;
            i0 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddConst((OOC_X86_SSA__Block)i0, (OOC_X86_SSA__Const)i1, (OOC_SymbolTable__Type)i2);
            return (OOC_X86_SSA__Result)i0;
            goto l120;
          }
l120:
          _failed_function(11854); return 0;
          ;
        }

        
        void OOC_X86_Translate__Translate_StatmSeq_Assign(OOC_X86_SSA__Result getInstr, OOC_X86_SSA__Result newValue) {
          register OOC_INT32 i0,i1,i2;

          i0 = (OOC_INT32)getInstr;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 30730))+4);
          OOC_X86_SSA__InstrDesc_SetOpcode((OOC_X86_SSA__Instr)i1, 25);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 30771))+4);
          i2 = (OOC_INT32)newValue;
          OOC_X86_SSA__InstrDesc_AddOpnd((OOC_X86_SSA__Instr)i1, (OOC_X86_SSA__Result)i2);
          OOC_X86_SSA__ResultDesc_DeleteResult((OOC_X86_SSA__Result)i0);
          return;
          ;
        }

        
        void OOC_X86_Translate__Translate_StatmSeq_ForStatm(OOC_IR__ForStatm statm) {
          register OOC_INT32 i0,i1,i2,i3;
          OOC_X86_SSA__Result endValue;
          OOC_X86_SSA__Result stepValue;
          OOC_X86_SSA__Result v;
          OOC_X86_SSA__LoopStartInstr loopStart;
          OOC_X86_SSA__Result res;
          OOC_X86_SSA__Instr memoryFalse;
          OOC_X86_SSA__Instr controlFalse;
          OOC_X86_SSA__Instr memoryTrue;
          OOC_X86_SSA__Instr controlTrue;
          OOC_X86_SSA__Instr endTrue;
          OOC_X86_SSA__Instr instr;
          OOC_X86_SSA__Instr endFalse;
          auto OOC_X86_SSA__Result OOC_X86_Translate__Translate_StatmSeq_ForStatm_Guard(OOC_X86_SSA__Result bound);
            
            OOC_X86_SSA__Result OOC_X86_Translate__Translate_StatmSeq_ForStatm_Guard(OOC_X86_SSA__Result bound) {
              register OOC_INT32 i0,i1,i2,i3;
              OOC_INT8 cmpClass;

              i0 = (OOC_INT32)statm;
              i0 = OOC_IR__ForStatmDesc_PositiveStep((OOC_IR__ForStatm)i0);
              if (i0) goto l3;
              cmpClass = 14;
              i0=14;
              goto l4;
l3:
              cmpClass = 12;
              i0=12;
l4:
              i1 = (OOC_INT32)statm;
              i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 31429))+8);
              i1 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression((OOC_IR__Expression)i1);
              i2 = (OOC_INT32)b;
              i3 = (OOC_INT32)bound;
              i0 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr2((OOC_X86_SSA__Block)i2, i0, (OOC_X86_SSA__Result)i1, (OOC_X86_SSA__Result)i3);
              i0 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AddResultReg((OOC_X86_SSA__Instr)i0, 0, 2);
              return (OOC_X86_SSA__Result)i0;
              ;
            }


          i0 = (OOC_INT32)statm;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 31925))+16);
          i1 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression((OOC_IR__Expression)i1);
          endValue = (OOC_X86_SSA__Result)i1;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 31969))+20);
          i2 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression((OOC_IR__Expression)i2);
          stepValue = (OOC_X86_SSA__Result)i2;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 32006))+8);
          i2 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression((OOC_IR__Expression)i2);
          v = (OOC_X86_SSA__Result)i2;
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 32047))+12);
          i0 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression((OOC_IR__Expression)i0);
          OOC_X86_Translate__Translate_StatmSeq_Assign((OOC_X86_SSA__Result)i2, (OOC_X86_SSA__Result)i0);
          i0 = (OOC_INT32)b;
          i0 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddLoopStart((OOC_X86_SSA__Block)i0);
          loopStart = (OOC_X86_SSA__LoopStartInstr)i0;
          OOC_X86_Translate__Translate_ControlCP((OOC_X86_SSA__Instr)i0);
          OOC_X86_Translate__Translate_MemoryCP((OOC_X86_SSA__Instr)i0);
          i0 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_ForStatm_Guard((OOC_X86_SSA__Result)i1);
          res = (OOC_X86_SSA__Result)i0;
          i1 = (OOC_INT32)controlCP;
          i2 = (OOC_INT32)memoryCP;
          OOC_X86_Translate__Translate_StatmSeq_SplitPaths((OOC_X86_SSA__Result)i0, (OOC_X86_SSA__Instr)i1, (OOC_X86_SSA__Instr)i2, (void*)(OOC_INT32)&controlTrue, (void*)(OOC_INT32)&memoryTrue, (void*)(OOC_INT32)&controlFalse, (void*)(OOC_INT32)&memoryFalse);
          i0 = (OOC_INT32)memoryTrue;
          memoryCP = (OOC_X86_SSA__Instr)i0;
          i0 = (OOC_INT32)controlTrue;
          controlCP = (OOC_X86_SSA__Instr)i0;
          i0 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_AddJump();
          endTrue = (OOC_X86_SSA__Instr)i0;
          i1 = (OOC_INT32)memoryFalse;
          memoryCP = (OOC_X86_SSA__Instr)i1;
          i1 = (OOC_INT32)controlFalse;
          controlCP = (OOC_X86_SSA__Instr)i1;
          i1 = (OOC_INT32)b;
          i1 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr0((OOC_X86_SSA__Block)i1, 42);
          instr = (OOC_X86_SSA__Instr)i1;
          OOC_X86_Translate__Translate_ControlCP((OOC_X86_SSA__Instr)i1);
          OOC_X86_Translate__Translate_MemoryCP((OOC_X86_SSA__Instr)i1);
          i2 = (OOC_INT32)loopExits;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 32661)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i2, (Object__Object)i1);
          i1 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_AddJump();
          endFalse = (OOC_X86_SSA__Instr)i1;
          i2 = (OOC_INT32)b;
          i0 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddMerge2((OOC_X86_SSA__Block)i2, 36, (OOC_X86_SSA__Instr)i0, (OOC_X86_SSA__Instr)i1);
          merge = (OOC_X86_SSA__MergeInstr)i0;
          controlCP = (OOC_X86_SSA__Instr)i0;
          memoryCP = (OOC_X86_SSA__Instr)i0;
          i0 = (OOC_INT32)statm;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 32903))+24);
          OOC_X86_Translate__Translate_StatmSeq((OOC_IR__StatementSeq)i1);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 32940))+8);
          i1 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression((OOC_IR__Expression)i1);
          v = (OOC_X86_SSA__Result)i1;
          i2 = (OOC_INT32)b;
          i3 = (OOC_INT32)stepValue;
          i2 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr2((OOC_X86_SSA__Block)i2, 1, (OOC_X86_SSA__Result)i1, (OOC_X86_SSA__Result)i3);
          instr = (OOC_X86_SSA__Instr)i2;
          i1 = *(OOC_INT8*)((_check_pointer(i1, 33053))+12);
          i1 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AddResult((OOC_X86_SSA__Instr)i2, i1);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 33029))+8);
          i0 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression((OOC_IR__Expression)i0);
          OOC_X86_Translate__Translate_StatmSeq_Assign((OOC_X86_SSA__Result)i0, (OOC_X86_SSA__Result)i1);
          i0 = (OOC_INT32)loopStart;
          OOC_X86_Translate__Translate_StatmSeq_LoopEnd((OOC_X86_SSA__LoopStartInstr)i0);
          return;
          ;
        }


      i0 = (OOC_INT32)statmSeq;
      i0 = _check_pointer(i0, 33165);
      i1 = OOC_ARRAY_LENGTH(i0, 0);
      i1 = i0+i1*4;
      i2 = i1!=i0;
      if (!i2) goto l84;
      i2 = (OOC_INT32)_c4;
      i3 = (OOC_INT32)_c5;
      i4 = (OOC_INT32)_c6;
      
l3_loop:
      i5 = (OOC_INT32)*(OOC_INT32*)i0;
      statm = (OOC_IR__Statement)i5;
      i6 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 33188)))), &_td_OOC_IR__AssignmentDesc);
      if (i6) goto l78;
      i6 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 33398)))), &_td_OOC_IR__CopyDesc);
      if (i6) goto l76;
      i6 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 33449)))), &_td_OOC_IR__MoveBlockDesc);
      if (i6) goto l74;
      i6 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 33521)))), &_td_OOC_IR__IfStatmDesc);
      if (i6) goto l69;
      i6 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 34308)))), &_td_OOC_IR__WithStatmDesc);
      if (i6) goto l60;
      i6 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 35330)))), &_td_OOC_IR__ReturnDesc);
      if (i6) goto l54;
      i6 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 35824)))), &_td_OOC_IR__LoopStatmDesc);
      if (i6) goto l52;
      i6 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 36024)))), &_td_OOC_IR__RepeatStatmDesc);
      if (i6) goto l50;
      i6 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 37102)))), &_td_OOC_IR__WhileStatmDesc);
      if (i6) goto l48;
      i6 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 38199)))), &_td_OOC_IR__ForStatmDesc);
      if (i6) goto l46;
      i6 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 38269)))), &_td_OOC_IR__ExitDesc);
      if (i6) goto l44;
      i6 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 38432)))), &_td_OOC_IR__CallDesc);
      if (i6) goto l42;
      i6 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 38491)))), &_td_OOC_IR__AssertDesc);
      if (i6) goto l33;
      i6 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 39589)))), &_td_OOC_IR__CopyParameterDesc);
      if (i6) goto l79;
      _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 39582)))), 39582);
      goto l79;
l33:
      i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 38525))+8);
      i6 = i6==(OOC_INT32)0;
      if (i6) goto l39;
      i6 = *(OOC_UINT8*)((_check_pointer(i5, 38757))+16);
      i6 = !i6;
      if (!i6) goto l79;
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 38807))+8);
      i5 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression((OOC_IR__Expression)i5);
      res = (OOC_X86_SSA__Result)i5;
      i6 = (OOC_INT32)memoryCP;
      i7 = (OOC_INT32)controlCP;
      OOC_X86_Translate__Translate_StatmSeq_SplitPaths((OOC_X86_SSA__Result)i5, (OOC_X86_SSA__Instr)i7, (OOC_X86_SSA__Instr)i6, (void*)(OOC_INT32)&controlTrue, (void*)(OOC_INT32)&memoryTrue, (void*)(OOC_INT32)&controlFalse, (void*)(OOC_INT32)&memoryFalse);
      i5 = (OOC_INT32)memoryTrue;
      memoryCP = (OOC_X86_SSA__Instr)i5;
      i5 = (OOC_INT32)controlTrue;
      controlCP = (OOC_X86_SSA__Instr)i5;
      i5 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_AddJump();
      endTrue = (OOC_X86_SSA__Instr)i5;
      i5 = (OOC_INT32)memoryFalse;
      memoryCP = (OOC_X86_SSA__Instr)i5;
      i5 = (OOC_INT32)controlFalse;
      controlCP = (OOC_X86_SSA__Instr)i5;
      i5 = (OOC_INT32)statm;
      i6 = *(OOC_INT32*)((_check_pointer(i5, 39328))+12);
      i7 = (OOC_INT32)b;
      i6 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddConstLength((OOC_X86_SSA__Block)i7, i6);
      i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i5, 39272));
      i5 = *(OOC_INT32*)((_check_pointer(i5, 39276))+16);
      OOC_X86_Translate__Translate_FailedCheck((Object__String)i2, i5, (OOC_X86_SSA__Result)i6);
      i5 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_AddJump();
      endFalse = (OOC_X86_SSA__Instr)i5;
      i6 = (OOC_INT32)endTrue;
      i7 = (OOC_INT32)b;
      i5 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddMerge2((OOC_X86_SSA__Block)i7, 36, (OOC_X86_SSA__Instr)i6, (OOC_X86_SSA__Instr)i5);
      merge = (OOC_X86_SSA__MergeInstr)i5;
      controlCP = (OOC_X86_SSA__Instr)i5;
      memoryCP = (OOC_X86_SSA__Instr)i5;
      goto l79;
l39:
      i6 = (OOC_INT32)b;
      i7 = (OOC_INT32)sp;
      i6 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddAdrRT((OOC_X86_SSA__Block)i6, (Object__String)i3);
      i8 = (OOC_INT32)b;
      i6 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr2((OOC_X86_SSA__Block)i8, 20, (OOC_X86_SSA__Result)i6, (OOC_X86_SSA__Result)i7);
      instr = (OOC_X86_SSA__Instr)i6;
      i5 = *(OOC_INT32*)((_check_pointer(i5, 38667))+12);
      i7 = (OOC_INT32)b;
      i5 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddConstLength((OOC_X86_SSA__Block)i7, i5);
      OOC_X86_SSA__InstrDesc_AddOpnd((OOC_X86_SSA__Instr)i6, (OOC_X86_SSA__Result)i5);
      OOC_X86_Translate__Translate_MemoryCP((OOC_X86_SSA__Instr)i6);
      OOC_X86_Translate__Translate_ControlCP((OOC_X86_SSA__Instr)i6);
      goto l79;
l42:
      i5 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Call((OOC_IR__Call)i5);
      res = (OOC_X86_SSA__Result)i5;
      goto l79;
l44:
      i5 = (OOC_INT32)b;
      i5 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr0((OOC_X86_SSA__Block)i5, 42);
      instr = (OOC_X86_SSA__Instr)i5;
      OOC_X86_Translate__Translate_ControlCP((OOC_X86_SSA__Instr)i5);
      OOC_X86_Translate__Translate_MemoryCP((OOC_X86_SSA__Instr)i5);
      i6 = (OOC_INT32)loopExits;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 38390)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i6, (Object__Object)i5);
      goto l79;
l46:
      OOC_X86_Translate__Translate_StatmSeq_ForStatm((OOC_IR__ForStatm)i5);
      goto l79;
l48:
      i6 = (OOC_INT32)b;
      i6 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddLoopStart((OOC_X86_SSA__Block)i6);
      loopStart = (OOC_X86_SSA__LoopStartInstr)i6;
      OOC_X86_Translate__Translate_ControlCP((OOC_X86_SSA__Instr)i6);
      OOC_X86_Translate__Translate_MemoryCP((OOC_X86_SSA__Instr)i6);
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 37396))+8);
      i5 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression((OOC_IR__Expression)i5);
      res = (OOC_X86_SSA__Result)i5;
      i6 = (OOC_INT32)memoryCP;
      i7 = (OOC_INT32)controlCP;
      OOC_X86_Translate__Translate_StatmSeq_SplitPaths((OOC_X86_SSA__Result)i5, (OOC_X86_SSA__Instr)i7, (OOC_X86_SSA__Instr)i6, (void*)(OOC_INT32)&controlTrue, (void*)(OOC_INT32)&memoryTrue, (void*)(OOC_INT32)&controlFalse, (void*)(OOC_INT32)&memoryFalse);
      i5 = (OOC_INT32)memoryTrue;
      memoryCP = (OOC_X86_SSA__Instr)i5;
      i5 = (OOC_INT32)controlTrue;
      controlCP = (OOC_X86_SSA__Instr)i5;
      i5 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_AddJump();
      endTrue = (OOC_X86_SSA__Instr)i5;
      i5 = (OOC_INT32)memoryFalse;
      memoryCP = (OOC_X86_SSA__Instr)i5;
      i5 = (OOC_INT32)controlFalse;
      controlCP = (OOC_X86_SSA__Instr)i5;
      i5 = (OOC_INT32)b;
      i5 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr0((OOC_X86_SSA__Block)i5, 42);
      instr = (OOC_X86_SSA__Instr)i5;
      OOC_X86_Translate__Translate_ControlCP((OOC_X86_SSA__Instr)i5);
      OOC_X86_Translate__Translate_MemoryCP((OOC_X86_SSA__Instr)i5);
      i6 = (OOC_INT32)loopExits;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 37891)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i6, (Object__Object)i5);
      i5 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_AddJump();
      endFalse = (OOC_X86_SSA__Instr)i5;
      i6 = (OOC_INT32)endTrue;
      i7 = (OOC_INT32)b;
      i5 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddMerge2((OOC_X86_SSA__Block)i7, 36, (OOC_X86_SSA__Instr)i6, (OOC_X86_SSA__Instr)i5);
      merge = (OOC_X86_SSA__MergeInstr)i5;
      controlCP = (OOC_X86_SSA__Instr)i5;
      memoryCP = (OOC_X86_SSA__Instr)i5;
      i5 = (OOC_INT32)statm;
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 38145))+12);
      OOC_X86_Translate__Translate_StatmSeq((OOC_IR__StatementSeq)i5);
      i5 = (OOC_INT32)loopStart;
      OOC_X86_Translate__Translate_StatmSeq_LoopEnd((OOC_X86_SSA__LoopStartInstr)i5);
      goto l79;
l50:
      i6 = (OOC_INT32)b;
      i6 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddLoopStart((OOC_X86_SSA__Block)i6);
      loopStart = (OOC_X86_SSA__LoopStartInstr)i6;
      OOC_X86_Translate__Translate_ControlCP((OOC_X86_SSA__Instr)i6);
      OOC_X86_Translate__Translate_MemoryCP((OOC_X86_SSA__Instr)i6);
      i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 36261))+8);
      OOC_X86_Translate__Translate_StatmSeq((OOC_IR__StatementSeq)i6);
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 36313))+12);
      i5 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression((OOC_IR__Expression)i5);
      res = (OOC_X86_SSA__Result)i5;
      i6 = (OOC_INT32)memoryCP;
      i7 = (OOC_INT32)controlCP;
      OOC_X86_Translate__Translate_StatmSeq_SplitPaths((OOC_X86_SSA__Result)i5, (OOC_X86_SSA__Instr)i7, (OOC_X86_SSA__Instr)i6, (void*)(OOC_INT32)&controlTrue, (void*)(OOC_INT32)&memoryTrue, (void*)(OOC_INT32)&controlFalse, (void*)(OOC_INT32)&memoryFalse);
      i5 = (OOC_INT32)memoryTrue;
      memoryCP = (OOC_X86_SSA__Instr)i5;
      i5 = (OOC_INT32)controlTrue;
      controlCP = (OOC_X86_SSA__Instr)i5;
      i5 = (OOC_INT32)b;
      i5 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr0((OOC_X86_SSA__Block)i5, 42);
      instr = (OOC_X86_SSA__Instr)i5;
      OOC_X86_Translate__Translate_ControlCP((OOC_X86_SSA__Instr)i5);
      OOC_X86_Translate__Translate_MemoryCP((OOC_X86_SSA__Instr)i5);
      i6 = (OOC_INT32)loopExits;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 36679)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i6, (Object__Object)i5);
      i5 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_AddJump();
      endTrue = (OOC_X86_SSA__Instr)i5;
      i5 = (OOC_INT32)memoryFalse;
      memoryCP = (OOC_X86_SSA__Instr)i5;
      i5 = (OOC_INT32)controlFalse;
      controlCP = (OOC_X86_SSA__Instr)i5;
      i5 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_AddJump();
      endFalse = (OOC_X86_SSA__Instr)i5;
      i6 = (OOC_INT32)endTrue;
      i7 = (OOC_INT32)b;
      i5 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddMerge2((OOC_X86_SSA__Block)i7, 36, (OOC_X86_SSA__Instr)i6, (OOC_X86_SSA__Instr)i5);
      merge = (OOC_X86_SSA__MergeInstr)i5;
      controlCP = (OOC_X86_SSA__Instr)i5;
      memoryCP = (OOC_X86_SSA__Instr)i5;
      i5 = (OOC_INT32)loopStart;
      OOC_X86_Translate__Translate_StatmSeq_LoopEnd((OOC_X86_SSA__LoopStartInstr)i5);
      goto l79;
l52:
      i6 = (OOC_INT32)b;
      i6 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddLoopStart((OOC_X86_SSA__Block)i6);
      loopStart = (OOC_X86_SSA__LoopStartInstr)i6;
      OOC_X86_Translate__Translate_ControlCP((OOC_X86_SSA__Instr)i6);
      OOC_X86_Translate__Translate_MemoryCP((OOC_X86_SSA__Instr)i6);
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 35960))+8);
      OOC_X86_Translate__Translate_StatmSeq((OOC_IR__StatementSeq)i5);
      OOC_X86_Translate__Translate_StatmSeq_LoopEnd((OOC_X86_SSA__LoopStartInstr)i6);
      goto l79;
l54:
      i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 35386))+8);
      i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i6, 35393))+4);
      i6 = OOC_X86_SSA__MapType((OOC_SymbolTable__Type)i6);
      i6 = OOC_X86_SSA__IsUnsigned(i6);
      if (i6) goto l57;
      type = 3;
      i6=3;
      goto l58;
l57:
      type = 7;
      i6=7;
l58:
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 35545))+8);
      i5 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression((OOC_IR__Expression)i5);
      i7 = (OOC_INT32)b;
      i5 = (OOC_INT32)OOC_X86_SSA__FunctionBlockDesc_FixType((OOC_X86_SSA__FunctionBlock)i7, (OOC_X86_SSA__Result)i5, i6);
      i6 = (OOC_INT32)b;
      i5 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr1((OOC_X86_SSA__Block)i6, 19, (OOC_X86_SSA__Result)i5);
      instr = (OOC_X86_SSA__Instr)i5;
      OOC_X86_Translate__Translate_ControlCP((OOC_X86_SSA__Instr)i5);
      OOC_X86_Translate__Translate_MemoryCP((OOC_X86_SSA__Instr)i5);
      i6 = type;
      i6 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AddResult((OOC_X86_SSA__Instr)i5, i6);
      res = (OOC_X86_SSA__Result)i6;
      *(OOC_INT8*)((_check_pointer(i6, 35707))+14) = 0;
      *(OOC_INT8*)((_check_pointer(i6, 35744))+13) = 3;
      i6 = (OOC_INT32)returns;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 35792)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i6, (Object__Object)i5);
      goto l79;
l60:
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 34359))+8);
      i5 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression((OOC_IR__Expression)i5);
      res = (OOC_X86_SSA__Result)i5;
      i6 = (OOC_INT32)memoryCP;
      i7 = (OOC_INT32)controlCP;
      OOC_X86_Translate__Translate_StatmSeq_SplitPaths((OOC_X86_SSA__Result)i5, (OOC_X86_SSA__Instr)i7, (OOC_X86_SSA__Instr)i6, (void*)(OOC_INT32)&controlTrue, (void*)(OOC_INT32)&memoryTrue, (void*)(OOC_INT32)&controlFalse, (void*)(OOC_INT32)&memoryFalse);
      i5 = (OOC_INT32)memoryTrue;
      memoryCP = (OOC_X86_SSA__Instr)i5;
      i5 = (OOC_INT32)controlTrue;
      controlCP = (OOC_X86_SSA__Instr)i5;
      i5 = (OOC_INT32)statm;
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 34633))+12);
      OOC_X86_Translate__Translate_StatmSeq((OOC_IR__StatementSeq)i5);
      i5 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_AddJump();
      endTrue = (OOC_X86_SSA__Instr)i5;
      i5 = (OOC_INT32)memoryFalse;
      memoryCP = (OOC_X86_SSA__Instr)i5;
      i5 = (OOC_INT32)controlFalse;
      controlCP = (OOC_X86_SSA__Instr)i5;
      i5 = (OOC_INT32)statm;
      i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 34791))+16);
      i6 = i6!=(OOC_INT32)0;
      if (i6) goto l66;
      i6 = *(OOC_UINT8*)((_check_pointer(i5, 34874))+20);
      if (!i6) goto l67;
      i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 34918))+8);
      i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i6, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 34928)))), &_td_OOC_IR__TypeTestDesc, 34928)), 34937))+8);
      irExpr = (OOC_IR__Expression)i6;
      i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i5, 35010));
      i6 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression((OOC_IR__Expression)i6);
      i7 = (OOC_INT32)irExpr;
      i5 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_TypeTag((OOC_IR__Expression)i7, (OOC_X86_SSA__Result)i6, 1u, (OOC_Scanner_SymList__Symbol)i5);
      res = (OOC_X86_SSA__Result)i5;
      i6 = (OOC_INT32)statm;
      i6 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i6, 35070));
      i6 = *(OOC_INT32*)((_check_pointer(i6, 35074))+16);
      OOC_X86_Translate__Translate_FailedCheck((Object__String)i4, i6, (OOC_X86_SSA__Result)i5);
      goto l67;
l66:
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 34840))+16);
      OOC_X86_Translate__Translate_StatmSeq((OOC_IR__StatementSeq)i5);
l67:
      i5 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_AddJump();
      endFalse = (OOC_X86_SSA__Instr)i5;
      i6 = (OOC_INT32)endTrue;
      i7 = (OOC_INT32)b;
      i5 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddMerge2((OOC_X86_SSA__Block)i7, 36, (OOC_X86_SSA__Instr)i6, (OOC_X86_SSA__Instr)i5);
      merge = (OOC_X86_SSA__MergeInstr)i5;
      controlCP = (OOC_X86_SSA__Instr)i5;
      memoryCP = (OOC_X86_SSA__Instr)i5;
      goto l79;
l69:
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 33570))+8);
      i5 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression((OOC_IR__Expression)i5);
      res = (OOC_X86_SSA__Result)i5;
      i6 = (OOC_INT32)memoryCP;
      i7 = (OOC_INT32)controlCP;
      OOC_X86_Translate__Translate_StatmSeq_SplitPaths((OOC_X86_SSA__Result)i5, (OOC_X86_SSA__Instr)i7, (OOC_X86_SSA__Instr)i6, (void*)(OOC_INT32)&controlTrue, (void*)(OOC_INT32)&memoryTrue, (void*)(OOC_INT32)&controlFalse, (void*)(OOC_INT32)&memoryFalse);
      i5 = (OOC_INT32)memoryTrue;
      memoryCP = (OOC_X86_SSA__Instr)i5;
      i5 = (OOC_INT32)controlTrue;
      controlCP = (OOC_X86_SSA__Instr)i5;
      i5 = (OOC_INT32)statm;
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 33844))+12);
      OOC_X86_Translate__Translate_StatmSeq((OOC_IR__StatementSeq)i5);
      i5 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_AddJump();
      endTrue = (OOC_X86_SSA__Instr)i5;
      i5 = (OOC_INT32)memoryFalse;
      memoryCP = (OOC_X86_SSA__Instr)i5;
      i5 = (OOC_INT32)controlFalse;
      controlCP = (OOC_X86_SSA__Instr)i5;
      i5 = (OOC_INT32)statm;
      i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 34002))+16);
      i6 = i6!=(OOC_INT32)0;
      if (!i6) goto l72;
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 34051))+16);
      OOC_X86_Translate__Translate_StatmSeq((OOC_IR__StatementSeq)i5);
l72:
      i5 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_AddJump();
      endFalse = (OOC_X86_SSA__Instr)i5;
      i6 = (OOC_INT32)endTrue;
      i7 = (OOC_INT32)b;
      i5 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddMerge2((OOC_X86_SSA__Block)i7, 36, (OOC_X86_SSA__Instr)i6, (OOC_X86_SSA__Instr)i5);
      merge = (OOC_X86_SSA__MergeInstr)i5;
      controlCP = (OOC_X86_SSA__Instr)i5;
      memoryCP = (OOC_X86_SSA__Instr)i5;
      goto l79;
l74:
      OOC_X86_Translate__Translate_StatmSeq_MoveBlock((OOC_IR__MoveBlock)i5);
      goto l79;
l76:
      OOC_X86_Translate__Translate_StatmSeq_Copy((OOC_IR__Copy)i5);
      goto l79;
l78:
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 33301))+12);
      i5 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression((OOC_IR__Expression)i5);
      res = (OOC_X86_SSA__Result)i5;
      i5 = (OOC_INT32)statm;
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 33343))+8);
      i5 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression((OOC_IR__Expression)i5);
      var = (OOC_X86_SSA__Result)i5;
      i6 = (OOC_INT32)res;
      OOC_X86_Translate__Translate_StatmSeq_Assign((OOC_X86_SSA__Result)i5, (OOC_X86_SSA__Result)i6);
l79:
      i0 = i0+4;
      i5 = i1!=i0;
      if (i5) goto l3_loop;
l84:
      return;
      ;
    }

    
    void OOC_X86_Translate__Translate_FctProlog(OOC_X86_SSA__FunctionBlock b) {
      register OOC_INT32 i0,i1,i2;
      OOC_X86_SSA__Instr enter;
      OOC_X86_SSA__Instr pushFp;
      OOC_X86_SSA__Instr setFp;
      OOC_X86_SSA__Instr localVars;

      i0 = (OOC_INT32)b;
      i1 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr0((OOC_X86_SSA__Block)i0, 17);
      enter = (OOC_X86_SSA__Instr)i1;
      i2 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AddResultReg((OOC_X86_SSA__Instr)i1, 9, 0);
      sp = (OOC_X86_SSA__Result)i2;
      i2 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AddResultReg((OOC_X86_SSA__Instr)i1, 9, 1);
      fp = (OOC_X86_SSA__Result)i2;
      controlCP = (OOC_X86_SSA__Instr)i1;
      memoryCP = (OOC_X86_SSA__Instr)i1;
      OOC_X86_SSA__FunctionBlockDesc_SetEnter((OOC_X86_SSA__FunctionBlock)i0, (OOC_X86_SSA__Instr)i1);
      i1 = (OOC_INT32)fp;
      i2 = (OOC_INT32)sp;
      i1 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr2((OOC_X86_SSA__Block)i0, 27, (OOC_X86_SSA__Result)i2, (OOC_X86_SSA__Result)i1);
      pushFp = (OOC_X86_SSA__Instr)i1;
      i1 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AddResultReg((OOC_X86_SSA__Instr)i1, 9, 0);
      sp = (OOC_X86_SSA__Result)i1;
      i2 = *(OOC_INT8*)((_check_pointer(i1, 40130))+13);
      _assert((i2==0), 127, 40121);
      i1 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr1((OOC_X86_SSA__Block)i0, 26, (OOC_X86_SSA__Result)i1);
      setFp = (OOC_X86_SSA__Instr)i1;
      i2 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AddResultReg((OOC_X86_SSA__Instr)i1, 9, 1);
      fp = (OOC_X86_SSA__Result)i2;
      OOC_X86_Translate__Translate_MemoryCP((OOC_X86_SSA__Instr)i1);
      i1 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddFramePointerOffset((OOC_X86_SSA__Block)i0, (OOC_SymbolTable__VarDecl)(OOC_INT32)0);
      i2 = (OOC_INT32)sp;
      i0 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr2((OOC_X86_SSA__Block)i0, 22, (OOC_X86_SSA__Result)i2, (OOC_X86_SSA__Result)i1);
      localVars = (OOC_X86_SSA__Instr)i0;
      OOC_X86_Translate__Translate_ControlCP((OOC_X86_SSA__Instr)i0);
      OOC_X86_Translate__Translate_MemoryCP((OOC_X86_SSA__Instr)i0);
      i0 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AddResultReg((OOC_X86_SSA__Instr)i0, 9, 0);
      sp = (OOC_X86_SSA__Result)i0;
      i0 = *(OOC_INT8*)((_check_pointer(i0, 40678))+13);
      _assert((i0==0), 127, 40669);
      return;
      ;
    }

    
    void OOC_X86_Translate__Translate_FctEpilog(OOC_X86_SSA__FunctionBlock b) {
      register OOC_INT32 i0,i1,i2,i3;
      OOC_X86_SSA__Instr leave;

      i0 = (OOC_INT32)b;
      i1 = *(OOC_UINT8*)((_check_pointer(i0, 40883))+80);
      if (!i1) goto l4;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 40958))+56);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 40967))+20);
      i1 = *(OOC_INT32*)(_check_pointer(i1, 40972));
      OOC_X86_Translate__Translate_FailedCheck((Object__String)((OOC_INT32)_c7), i1, (OOC_X86_SSA__Result)(OOC_INT32)0);
l4:
      i1 = (OOC_INT32)sp;
      i2 = (OOC_INT32)fp;
      i1 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr2((OOC_X86_SSA__Block)i0, 29, (OOC_X86_SSA__Result)i1, (OOC_X86_SSA__Result)i2);
      leave = (OOC_X86_SSA__Instr)i1;
      i2 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AddResultReg((OOC_X86_SSA__Instr)i1, 9, 0);
      sp = (OOC_X86_SSA__Result)i2;
      i1 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AddResultReg((OOC_X86_SSA__Instr)i1, 9, 1);
      fp = (OOC_X86_SSA__Result)i1;
      i1 = (OOC_INT32)returns;
      i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 41185)))), ADT_ArrayList__ArrayListDesc_Elements)),ADT_ArrayList__ArrayListDesc_Elements)((ADT_ArrayList__ArrayList)i1);
      i2 = (OOC_INT32)fp;
      i3 = (OOC_INT32)sp;
      i1 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddExit((OOC_X86_SSA__Block)i0, (OOC_X86_SSA__Result)i3, (OOC_X86_SSA__Result)i2, (Object__ObjectArrayPtr)i1);
      OOC_X86_Translate__Translate_ControlCP((OOC_X86_SSA__Instr)i1);
      OOC_X86_Translate__Translate_MemoryCP((OOC_X86_SSA__Instr)i1);
      OOC_X86_SSA__FunctionBlockDesc_SetExit((OOC_X86_SSA__FunctionBlock)i0, (OOC_X86_SSA__ExitInstr)i1);
      return;
      ;
    }

    
    void OOC_X86_Translate__Translate_Procedure(OOC_IR__Procedure p) {
      register OOC_INT32 i0,i1,i2,i3;

      i0 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_SSA__FunctionBlock.baseTypes[0]);
      i1 = (OOC_INT32)p;
      i2 = *(OOC_UINT8*)((_check_pointer(i1, 41378))+12);
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 41370))+4);
      OOC_X86_SSA__FunctionBlockDesc_INIT((OOC_X86_SSA__FunctionBlock)i0, (OOC_SymbolTable__ProcDecl)i3, i2);
      b = (OOC_X86_SSA__FunctionBlock)i0;
      OOC_X86_Translate__Translate_FctProlog((OOC_X86_SSA__FunctionBlock)i0);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 41437))+8);
      OOC_X86_Translate__Translate_StatmSeq((OOC_IR__StatementSeq)i0);
      i0 = (OOC_INT32)b;
      OOC_X86_Translate__Translate_FctEpilog((OOC_X86_SSA__FunctionBlock)i0);
      i0 = (OOC_INT32)b;
      OOC_X86_Destore__Transform((OOC_X86_SSA__FunctionBlock)i0);
      i0 = (OOC_INT32)b;
      OOC_X86_Algebraic__Transform((OOC_X86_SSA__FunctionBlock)i0, 0u);
      i0 = (OOC_INT32)b;
      OOC_X86_ConstProp__Transform((OOC_X86_SSA__FunctionBlock)i0);
      i0 = (OOC_INT32)b;
      OOC_X86_SSA__FunctionBlockDesc_DeadCodeElimination((OOC_X86_SSA__FunctionBlock)i0);
      i0 = (OOC_INT32)b;
      OOC_X86_Machine__ApplyMachineModel((OOC_X86_SSA__FunctionBlock)i0);
      i0 = (OOC_INT32)b;
      OOC_X86_Block__ArrangeInstructions((OOC_X86_SSA__FunctionBlock)i0);
      i0 = (OOC_INT32)b;
      OOC_X86_Register__AssignRegisters((OOC_X86_SSA__FunctionBlock)i0);
      i0 = (OOC_INT32)b;
      OOC_X86_Debug__ValidateAllocation((OOC_X86_SSA__FunctionBlock)i0);
      i0 = (OOC_INT32)b;
      OOC_X86_Debug__WriteFunction((OOC_X86_SSA__FunctionBlock)i0);
      i0 = (OOC_INT32)w;
      i1 = (OOC_INT32)b;
      OOC_X86_Write__WriterDesc_WriteFunction((OOC_X86_Write__Writer)i0, (OOC_X86_SSA__FunctionBlock)i1);
      return;
      ;
    }


  i0 = (OOC_INT32)RT0__NewObject(_td__qtd1.baseTypes[0]);
  ADT_ArrayList__ArrayListDesc_INIT((ADT_ArrayList__ArrayList)i0, 4);
  returns = (ADT_ArrayList__ArrayList)i0;
  i0 = (OOC_INT32)RT0__NewObject(_td__qtd1.baseTypes[0]);
  ADT_ArrayList__ArrayListDesc_INIT((ADT_ArrayList__ArrayList)i0, 4);
  loopExits = (ADT_ArrayList__ArrayList)i0;
  i0 = (OOC_INT32)symTab;
  i1 = (OOC_INT32)ch;
  i2 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_Write__Writer.baseTypes[0]);
  OOC_X86_Write__WriterDesc_INIT((OOC_X86_Write__Writer)i2, (OOC_SymbolTable__Module)i0, (IO__ByteChannel)i1);
  w = (OOC_X86_Write__Writer)i2;
  i0 = (OOC_INT32)moduleIR;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 41982))+8);
  i0 = _check_pointer(i0, 41991);
  i1 = OOC_ARRAY_LENGTH(i0, 0);
  i1 = i0+i1*4;
  i2 = i1!=i0;
  if (!i2) goto l8;
l3_loop:
  i2 = (OOC_INT32)*(OOC_INT32*)i0;
  p = (OOC_IR__Procedure)i2;
  OOC_X86_Translate__Translate_Procedure((OOC_IR__Procedure)i2);
  i0 = i0+4;
  i2 = i1!=i0;
  if (i2) goto l3_loop;
l8:
  i0 = (OOC_INT32)moduleIR;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 42047))+12);
  OOC_X86_Translate__Translate_Procedure((OOC_IR__Procedure)i0);
  i0 = (OOC_INT32)w;
  OOC_X86_Write__WriterDesc_EndFile((OOC_X86_Write__Writer)i0);
  return;
  ;
}

void OOC_OOC_X86_Translate_init(void) {
  _c0 = Object__NewLatin1Region("memcpy", 7, 0, 6);
  _c1 = Object__NewLatin1Region("memcpy", 7, 0, 6);
  _c2 = Object__NewLatin1Region("RT0__NewObject", 15, 0, 14);
  _c3 = Object__NewLatin1Region("RT0__TypeTest", 14, 0, 13);
  _c4 = Object__NewLatin1Region("RT0__ErrorAssertionFailed", 26, 0, 25);
  _c5 = Object__NewLatin1Region("RT0__Halt", 10, 0, 9);
  _c6 = Object__NewLatin1Region("RT0__ErrorFailedWith", 21, 0, 20);
  _c7 = Object__NewLatin1Region("RT0__ErrorFailedFunction", 25, 0, 24);

  return;
  ;
}

/* --- */
