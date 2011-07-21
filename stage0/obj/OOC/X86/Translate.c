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
  auto void OOC_X86_Translate__Translate_Memcpy(OOC_X86_SSA__Result from, OOC_X86_SSA__Result to, OOC_X86_SSA__Result size);
  auto void OOC_X86_Translate__Translate_StatmSeq(OOC_IR__StatementSeq statmSeq);
  auto void OOC_X86_Translate__Translate_FctProlog(OOC_X86_SSA__FunctionBlock b, OOC_IR__StatementSeq statmSeq);
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
      i0 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr2((OOC_X86_SSA__Block)i2, 29, (OOC_X86_SSA__Result)i1, (OOC_X86_SSA__Result)i0);
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

    
    void OOC_X86_Translate__Translate_Memcpy(OOC_X86_SSA__Result from, OOC_X86_SSA__Result to, OOC_X86_SSA__Result size) {
      register OOC_INT32 i0,i1,i2;

      i0 = (OOC_INT32)sp;
      i1 = (OOC_INT32)b;
      i1 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddAdrRT((OOC_X86_SSA__Block)i1, (Object__String)((OOC_INT32)_c0));
      i2 = (OOC_INT32)b;
      i0 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr2((OOC_X86_SSA__Block)i2, 29, (OOC_X86_SSA__Result)i1, (OOC_X86_SSA__Result)i0);
      i1 = (OOC_INT32)to;
      OOC_X86_SSA__InstrDesc_AddOpnd((OOC_X86_SSA__Instr)i0, (OOC_X86_SSA__Result)i1);
      i1 = (OOC_INT32)from;
      OOC_X86_SSA__InstrDesc_AddOpnd((OOC_X86_SSA__Instr)i0, (OOC_X86_SSA__Result)i1);
      i1 = (OOC_INT32)size;
      OOC_X86_SSA__InstrDesc_AddOpnd((OOC_X86_SSA__Instr)i0, (OOC_X86_SSA__Result)i1);
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
      ADT_ArrayList__ArrayList oldLoopExits;
      auto OOC_X86_SSA__Result OOC_X86_Translate__Translate_StatmSeq_SetCC(OOC_X86_SSA__Result res);
      auto OOC_X86_SSA__Result OOC_X86_Translate__Translate_StatmSeq_SetBool(OOC_X86_SSA__Result res);
      auto OOC_X86_SSA__Instr OOC_X86_Translate__Translate_StatmSeq_AddJump(void);
      auto void OOC_X86_Translate__Translate_StatmSeq_SplitPaths(OOC_X86_SSA__Result _bool, OOC_X86_SSA__Instr controlCP, OOC_X86_SSA__Instr memoryCP, OOC_X86_SSA__Instr *controlTrue, OOC_X86_SSA__Instr *memoryTrue, OOC_X86_SSA__Instr *controlFalse, OOC_X86_SSA__Instr *memoryFalse);
      auto OOC_X86_SSA__LoopStartInstr OOC_X86_Translate__Translate_StatmSeq_LoopStart(void);
      auto void OOC_X86_Translate__Translate_StatmSeq_LoopEnd(OOC_X86_SSA__LoopStartInstr loopStart);
      auto OOC_X86_SSA__Result OOC_X86_Translate__Translate_StatmSeq_Expression(OOC_IR__Expression expr);
      auto OOC_X86_SSA__Result OOC_X86_Translate__Translate_StatmSeq_Call(OOC_IR__Call call);
      auto OOC_X86_SSA__Result OOC_X86_Translate__Translate_StatmSeq_Designator2Address(OOC_X86_SSA__Result resultOfGet);
      auto OOC_X86_SSA__Result OOC_X86_Translate__Translate_StatmSeq_TypeTag(OOC_IR__Expression design, OOC_CHAR8 checkDerefOfNil, OOC_Scanner_SymList__Symbol derefSym);
      auto void OOC_X86_Translate__Translate_StatmSeq_Copy(OOC_IR__Copy copy);
      auto void OOC_X86_Translate__Translate_StatmSeq_MoveBlock(OOC_IR__MoveBlock move);
      auto OOC_X86_SSA__Result OOC_X86_Translate__Translate_StatmSeq_Expression(OOC_IR__Expression expr);
      auto void OOC_X86_Translate__Translate_StatmSeq_Assign(OOC_X86_SSA__Result getInstr, OOC_X86_SSA__Result newValue);
      auto void OOC_X86_Translate__Translate_StatmSeq_ForStatm(OOC_IR__ForStatm statm);
      auto void OOC_X86_Translate__Translate_StatmSeq_CaseStatm(OOC_IR__CaseStatm statm);
        
        OOC_X86_SSA__Result OOC_X86_Translate__Translate_StatmSeq_SetCC(OOC_X86_SSA__Result res) {
          register OOC_INT32 i0,i1,i2;

          i0 = (OOC_INT32)res;
          i1 = *(OOC_INT8*)((_check_pointer(i0, 2612))+13);
          i1 = i1==2;
          if (i1) goto l3;
          i1 = (OOC_INT32)b;
          i1 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddConstBool((OOC_X86_SSA__Block)i1, 0u);
          i2 = (OOC_INT32)b;
          i0 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr2((OOC_X86_SSA__Block)i2, 14, (OOC_X86_SSA__Result)i0, (OOC_X86_SSA__Result)i1);
          i0 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AddResultReg((OOC_X86_SSA__Instr)i0, 0, 2);
          return (OOC_X86_SSA__Result)i0;
          goto l4;
l3:
          return (OOC_X86_SSA__Result)i0;
l4:
          _failed_function(2519); return 0;
          ;
        }

        
        OOC_X86_SSA__Result OOC_X86_Translate__Translate_StatmSeq_SetBool(OOC_X86_SSA__Result res) {
          register OOC_INT32 i0,i1;

          i0 = (OOC_INT32)res;
          i1 = *(OOC_INT8*)((_check_pointer(i0, 2930))+13);
          i1 = i1==2;
          if (i1) goto l3;
          return (OOC_X86_SSA__Result)i0;
          goto l4;
l3:
          i1 = (OOC_INT32)b;
          i0 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr1((OOC_X86_SSA__Block)i1, 19, (OOC_X86_SSA__Result)i0);
          i0 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AddResult((OOC_X86_SSA__Instr)i0, 5);
          return (OOC_X86_SSA__Result)i0;
l4:
          _failed_function(2835); return 0;
          ;
        }

        
        OOC_X86_SSA__Instr OOC_X86_Translate__Translate_StatmSeq_AddJump(void) {
          register OOC_INT32 i0;

          i0 = (OOC_INT32)b;
          i0 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr0((OOC_X86_SSA__Block)i0, 49);
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
              i0 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddBranch((OOC_X86_SSA__Block)i1, (OOC_X86_SSA__Result)i0, 0u);
              i1 = (OOC_INT32)controlCP;
              OOC_X86_SSA__InstrDesc_AddDep((OOC_X86_SSA__Instr)i0, 0, (OOC_X86_SSA__Instr)i1);
              i1 = (OOC_INT32)b;
              i1 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddConstBool((OOC_X86_SSA__Block)i1, 1u);
              i2 = (OOC_INT32)b;
              i1 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddMerge0((OOC_X86_SSA__Block)i2, 47, (OOC_X86_SSA__Result)i1);
              OOC_X86_SSA__InstrDesc_AddDep((OOC_X86_SSA__Instr)i1, 0, (OOC_X86_SSA__Instr)i0);
              *controlTrue = (OOC_X86_SSA__Instr)i1;
              i2 = (OOC_INT32)memoryCP;
              *memoryTrue = (OOC_X86_SSA__Instr)i2;
              i2 = (OOC_INT32)b;
              i2 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddConstBool((OOC_X86_SSA__Block)i2, 0u);
              i3 = (OOC_INT32)b;
              i2 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddMerge0((OOC_X86_SSA__Block)i3, 47, (OOC_X86_SSA__Result)i2);
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
              i3 = *(OOC_INT8*)((_check_pointer(i2, 5310))+20);
              _assert((i3==47), 127, 5298);
              i2 = (OOC_INT32)OOC_X86_SSA__InstrDesc_GetBranchBeforeInstr((OOC_X86_SSA__Instr)i2, 0);
              branch = (OOC_X86_SSA__Instr)i2;
              i2 = *(OOC_INT8*)((_check_pointer(i2, 5415))+20);
              _assert((i2==46), 127, 5402);
              i2 = (OOC_INT32)ct;
              *controlTrue = (OOC_X86_SSA__Instr)i2;
              i2 = (OOC_INT32)mt;
              *memoryTrue = (OOC_X86_SSA__Instr)i2;
              i2 = (OOC_INT32)b;
              i2 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr0((OOC_X86_SSA__Block)i2, 49);
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
              OOC_X86_SSA__MergeInstrDesc_AddJump((OOC_X86_SSA__MergeInstr)(_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 5766)))), &_td_OOC_X86_SSA__MergeInstrDesc, 5766)), (OOC_X86_SSA__Instr)i2);
              i2 = (OOC_INT32)gate;
              i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 5893))+48);
              OOC_X86_SSA__InstrDesc_Delete((OOC_X86_SSA__Instr)i2);
              OOC_X86_SSA__InstrDesc_Delete((OOC_X86_SSA__Instr)(_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 5902)))), &_td_OOC_X86_SSA__MergeInstrDesc, 5902)));
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
              i3 = *(OOC_INT8*)((_check_pointer(i2, 6576))+20);
              _assert((i3==47), 127, 6564);
              i2 = (OOC_INT32)OOC_X86_SSA__InstrDesc_GetBranchBeforeInstr((OOC_X86_SSA__Instr)i2, 0);
              branch = (OOC_X86_SSA__Instr)i2;
              i2 = *(OOC_INT8*)((_check_pointer(i2, 6681))+20);
              _assert((i2==46), 127, 6668);
              i2 = (OOC_INT32)cf;
              *controlFalse = (OOC_X86_SSA__Instr)i2;
              i2 = (OOC_INT32)mf;
              *memoryFalse = (OOC_X86_SSA__Instr)i2;
              i2 = (OOC_INT32)b;
              i2 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr0((OOC_X86_SSA__Block)i2, 49);
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
              OOC_X86_SSA__MergeInstrDesc_AddJump((OOC_X86_SSA__MergeInstr)(_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 7031)))), &_td_OOC_X86_SSA__MergeInstrDesc, 7031)), (OOC_X86_SSA__Instr)i2);
              i2 = (OOC_INT32)gate;
              i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 7158))+48);
              OOC_X86_SSA__InstrDesc_Delete((OOC_X86_SSA__Instr)i2);
              OOC_X86_SSA__InstrDesc_Delete((OOC_X86_SSA__Instr)(_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 7167)))), &_td_OOC_X86_SSA__MergeInstrDesc, 7167)));
              OOC_X86_SSA__InstrDesc_Delete((OOC_X86_SSA__Instr)i1);
              OOC_X86_SSA__InstrDesc_Delete((OOC_X86_SSA__Instr)i0);
              return;
              ;
            }


          i0 = (OOC_INT32)_bool;
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7357))+4);
          instr = (OOC_X86_SSA__Instr)i0;
          i1 = *(OOC_INT8*)((_check_pointer(i0, 7382))+20);
          i1 = i1==50;
          if (!i1) goto l18;
          i1 = _type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7431)))), &_td_OOC_X86_SSA__GateInstrDesc, 7431);
          gate = (OOC_X86_SSA__GateInstr)i1;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7470)))), &_td_OOC_X86_SSA__GateInstrDesc, 7470)), 7480))+48);
          i2 = _type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 7489)))), &_td_OOC_X86_SSA__MergeInstrDesc, 7489);
          merge = (OOC_X86_SSA__MergeInstr)i2;
          i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 7520));
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 7529))+4);
          i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 7538));
          i3 = OOC_X86_SSA__ResultDesc_IsFalse((OOC_X86_SSA__Result)i3);
          if (i3) goto l16;
          i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 7708));
          i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 7717));
          i3 = OOC_X86_SSA__ResultDesc_IsFalse((OOC_X86_SSA__Result)i3);
          if (i3) goto l14;
          i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 7896));
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 7905))+4);
          i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 7914));
          i3 = OOC_X86_SSA__ResultDesc_IsTrue((OOC_X86_SSA__Result)i3);
          if (i3) goto l12;
          i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 8081));
          i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 8090));
          i3 = OOC_X86_SSA__ResultDesc_IsTrue((OOC_X86_SSA__Result)i3);
          if (!i3) goto l18;
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 8213))+56);
          i3 = _check_pointer(i3, 8219);
          i4 = OOC_ARRAY_LENGTH(i3, 0);
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 8197))+56);
          i2 = _check_pointer(i2, 8203);
          i5 = OOC_ARRAY_LENGTH(i2, 0);
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 8144));
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8153))+4);
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 8162));
          i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(1, i4, OOC_UINT8, 8219))*4);
          i2 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(0, i5, OOC_UINT8, 8203))*4);
          OOC_X86_Translate__Translate_StatmSeq_SplitPaths_SplitOrGate((OOC_X86_SSA__GateInstr)i1, (OOC_X86_SSA__Result)i0, (OOC_X86_SSA__Instr)i2, (OOC_X86_SSA__Instr)i3);
          return;
          goto l18;
l12:
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 8028))+56);
          i3 = _check_pointer(i3, 8034);
          i4 = OOC_ARRAY_LENGTH(i3, 0);
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 8012))+56);
          i2 = _check_pointer(i2, 8018);
          i5 = OOC_ARRAY_LENGTH(i2, 0);
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 7968));
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 7977));
          i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(0, i4, OOC_UINT8, 8034))*4);
          i2 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(1, i5, OOC_UINT8, 8018))*4);
          OOC_X86_Translate__Translate_StatmSeq_SplitPaths_SplitOrGate((OOC_X86_SSA__GateInstr)i1, (OOC_X86_SSA__Result)i0, (OOC_X86_SSA__Instr)i2, (OOC_X86_SSA__Instr)i3);
          return;
          goto l18;
l14:
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 7843))+56);
          i3 = _check_pointer(i3, 7849);
          i4 = OOC_ARRAY_LENGTH(i3, 0);
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 7827))+56);
          i2 = _check_pointer(i2, 7833);
          i5 = OOC_ARRAY_LENGTH(i2, 0);
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 7773));
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7782))+4);
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 7791));
          i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(1, i4, OOC_UINT8, 7849))*4);
          i2 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(0, i5, OOC_UINT8, 7833))*4);
          OOC_X86_Translate__Translate_StatmSeq_SplitPaths_SplitAndGate((OOC_X86_SSA__GateInstr)i1, (OOC_X86_SSA__Result)i0, (OOC_X86_SSA__Instr)i2, (OOC_X86_SSA__Instr)i3);
          return;
          goto l18;
l16:
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 7655))+56);
          i3 = _check_pointer(i3, 7661);
          i4 = OOC_ARRAY_LENGTH(i3, 0);
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 7639))+56);
          i2 = _check_pointer(i2, 7645);
          i5 = OOC_ARRAY_LENGTH(i2, 0);
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 7594));
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 7603));
          i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(0, i4, OOC_UINT8, 7661))*4);
          i2 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(1, i5, OOC_UINT8, 7645))*4);
          OOC_X86_Translate__Translate_StatmSeq_SplitPaths_SplitAndGate((OOC_X86_SSA__GateInstr)i1, (OOC_X86_SSA__Result)i0, (OOC_X86_SSA__Instr)i2, (OOC_X86_SSA__Instr)i3);
          return;
l18:
          OOC_X86_Translate__Translate_StatmSeq_SplitPaths_SplitValue();
          return;
          ;
        }

        
        OOC_X86_SSA__LoopStartInstr OOC_X86_Translate__Translate_StatmSeq_LoopStart(void) {
          register OOC_INT32 i0,i1;

          i0 = (OOC_INT32)b;
          i0 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddLoopStart((OOC_X86_SSA__Block)i0);
          OOC_X86_Translate__Translate_ControlCP((OOC_X86_SSA__Instr)i0);
          OOC_X86_Translate__Translate_MemoryCP((OOC_X86_SSA__Instr)i0);
          i1 = (OOC_INT32)loopExits;
          oldLoopExits = (ADT_ArrayList__ArrayList)i1;
          i1 = (OOC_INT32)RT0__NewObject(_td__qtd1.baseTypes[0]);
          ADT_ArrayList__ArrayListDesc_INIT((ADT_ArrayList__ArrayList)i1, 4);
          loopExits = (ADT_ArrayList__ArrayList)i1;
          return (OOC_X86_SSA__LoopStartInstr)i0;
          ;
        }

        
        void OOC_X86_Translate__Translate_StatmSeq_LoopEnd(OOC_X86_SSA__LoopStartInstr loopStart) {
          register OOC_INT32 i0,i1,i2;
          OOC_X86_SSA__Instr instr;

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
          i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 9096)))), ADT_ArrayList__ArrayListDesc_Elements)),ADT_ArrayList__ArrayListDesc_Elements)((ADT_ArrayList__ArrayList)i1);
          i2 = (OOC_INT32)b;
          i1 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddMerge((OOC_X86_SSA__Block)i2, 53, (Object__ObjectArrayPtr)i1);
          OOC_X86_SSA__InstrDesc_AddDep((OOC_X86_SSA__Instr)i1, 0, (OOC_X86_SSA__Instr)i0);
          OOC_X86_SSA__LoopStartInstrDesc_SetEnd((OOC_X86_SSA__LoopStartInstr)i0, (OOC_X86_SSA__MergeInstr)i1);
          controlCP = (OOC_X86_SSA__Instr)i1;
          memoryCP = (OOC_X86_SSA__Instr)i1;
          i0 = (OOC_INT32)oldLoopExits;
          loopExits = (ADT_ArrayList__ArrayList)i0;
          return;
          ;
        }

        
        OOC_X86_SSA__Result OOC_X86_Translate__Translate_StatmSeq_Call(OOC_IR__Call call) {
          register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
          OOC_X86_SSA__Result *args;
          OOC_INT32 i;
          OOC_X86_SSA__Instr instr;

          i0 = (OOC_INT32)call;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9633))+12);
          i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 9643)), 0);
          i1 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_Translate__9487.baseTypes[0], i1);
          args = (void*)i1;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9673))+12);
          i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 9683)), 0);
          i2 = i2-1;
          i = i2;
          i3 = i2>=0;
          if (!i3) goto l8;
l3_loop:
          i3 = _check_pointer(i1, 9716);
          i4 = OOC_ARRAY_LENGTH(i3, 0);
          i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9738))+12);
          i5 = _check_pointer(i5, 9748);
          i6 = OOC_ARRAY_LENGTH(i5, 0);
          i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i2, i6, OOC_UINT32, 9748))*4);
          i5 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression((OOC_IR__Expression)i5);
          *(OOC_INT32*)(i3+(_check_index(i2, i4, OOC_UINT32, 9716))*4) = i5;
          i2 = i2+(-1);
          i = i2;
          i3 = i2>=0;
          if (i3) goto l3_loop;
l8:
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9828))+8);
          i3 = (OOC_INT32)sp;
          i2 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression((OOC_IR__Expression)i2);
          i4 = (OOC_INT32)b;
          i2 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr2((OOC_X86_SSA__Block)i4, 29, (OOC_X86_SSA__Result)i2, (OOC_X86_SSA__Result)i3);
          instr = (OOC_X86_SSA__Instr)i2;
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9873))+12);
          i = 0;
          i3 = OOC_ARRAY_LENGTH((_check_pointer(i3, 9883)), 0);
          i4 = 0<i3;
          if (!i4) goto l16;
          i4=0;
l11_loop:
          i5 = _check_pointer(i1, 9919);
          i6 = OOC_ARRAY_LENGTH(i5, 0);
          i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 9919))*4);
          OOC_X86_SSA__InstrDesc_AddOpnd((OOC_X86_SSA__Instr)i2, (OOC_X86_SSA__Result)i5);
          i4 = i4+1;
          i = i4;
          i5 = i4<i3;
          if (i5) goto l11_loop;
l16:
          OOC_X86_Translate__Translate_MemoryCP((OOC_X86_SSA__Instr)i2);
          OOC_X86_Translate__Translate_ControlCP((OOC_X86_SSA__Instr)i2);
          i1 = (OOC_INT32)OOC_SymbolTable_Predef__GetType(17);
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10014))+4);
          i1 = i3==i1;
          if (i1) goto l19;
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10132))+4);
          i0 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AddResultExpr((OOC_X86_SSA__Instr)i2, (OOC_SymbolTable__Type)i0);
          return (OOC_X86_SSA__Result)i0;
          goto l20;
l19:
          return (OOC_X86_SSA__Result)(OOC_INT32)0;
l20:
          _failed_function(9388); return 0;
          ;
        }

        
        OOC_X86_SSA__Result OOC_X86_Translate__Translate_StatmSeq_Designator2Address(OOC_X86_SSA__Result resultOfGet) {
          register OOC_INT32 i0,i1;

          i0 = (OOC_INT32)resultOfGet;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10275))+4);
          i1 = *(OOC_INT8*)((_check_pointer(i1, 10281))+20);
          _assert((i1==34), 127, 10257);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10330))+4);
          i1 = (OOC_INT32)OOC_X86_SSA__InstrDesc_GetBeforeInstr((OOC_X86_SSA__Instr)i1, 1);
          memoryCP = (OOC_X86_SSA__Instr)i1;
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10392))+4);
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 10398));
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 10407));
          return (OOC_X86_SSA__Result)i0;
          ;
        }

        
        OOC_X86_SSA__Result OOC_X86_Translate__Translate_StatmSeq_TypeTag(OOC_IR__Expression design, OOC_CHAR8 checkDerefOfNil, OOC_Scanner_SymList__Symbol derefSym) {
          register OOC_INT32 i0,i1,i2,i3;
          OOC_X86_SSA__Result value;
          OOC_SymbolTable__Type type;

          i0 = (OOC_INT32)design;
          i1 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression((OOC_IR__Expression)i0);
          value = (OOC_X86_SSA__Result)i1;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10937))+4);
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10937))+4);
          i2 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 10942)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i3);
          type = (OOC_SymbolTable__Type)i2;
          i2 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 10974)))), OOC_SymbolTable__TypeDesc_Bound)),OOC_SymbolTable__TypeDesc_Bound)((OOC_SymbolTable__Type)i2);
          type = (OOC_SymbolTable__Type)i2;
          i3 = checkDerefOfNil;
          if (i3) goto l3;
          i3=0u;
          goto l5;
l3:
          i3 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 11067)))), &_td_OOC_SymbolTable__PointerDesc);
          
l5:
          if (i3) goto l6;
l6:
          i3 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 11310)))), &_td_OOC_SymbolTable__PointerDesc);
          if (i3) goto l21;
          i3 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11448)))), &_td_OOC_IR__VarDesc);
          if (i3) goto l11;
          i3=0u;
          goto l13;
l11:
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11485)))), &_td_OOC_IR__VarDesc, 11485)), 11489))+8);
          i3 = *(OOC_UINT8*)((_check_pointer((_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 11499)))), &_td_OOC_SymbolTable__VarDeclDesc, 11499)), 11507))+59);
          
l13:
          if (i3) goto l15;
          i3=0u;
          goto l17;
l15:
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11557)))), &_td_OOC_IR__VarDesc, 11557)), 11561))+8);
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 11571)))), &_td_OOC_SymbolTable__VarDeclDesc, 11571)), 11579))+48);
          i3 = OOC_SymbolTable_TypeRules__IsRecord((OOC_SymbolTable__Type)i3);
          
l17:
          if (i3) goto l19;
          i0 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Designator2Address((OOC_X86_SSA__Result)i1);
          i0 = (OOC_INT32)b;
          i0 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddAdrTypeDescr((OOC_X86_SSA__Block)i0, (OOC_SymbolTable__Type)i2);
          return (OOC_X86_SSA__Result)i0;
          goto l22;
l19:
          i1 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Designator2Address((OOC_X86_SSA__Result)i1);
          value = (OOC_X86_SSA__Result)i1;
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11729)))), &_td_OOC_IR__VarDesc, 11729)), 11733))+8);
          i1 = (OOC_INT32)fp;
          i2 = (OOC_INT32)b;
          i0 = (OOC_INT32)OOC_X86_SSA__FunctionBlockDesc_AddGetParamTypeTag((OOC_X86_SSA__FunctionBlock)i2, (OOC_SymbolTable__VarDecl)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11743)))), &_td_OOC_SymbolTable__VarDeclDesc, 11743)), (OOC_X86_SSA__Result)i1);
          return (OOC_X86_SSA__Result)i0;
          goto l22;
l21:
          i0 = (OOC_INT32)b;
          i0 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr1((OOC_X86_SSA__Block)i0, 44, (OOC_X86_SSA__Result)i1);
          i0 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AddResult((OOC_X86_SSA__Instr)i0, 9);
          return (OOC_X86_SSA__Result)i0;
l22:
          _failed_function(10462); return 0;
          ;
        }

        
        void OOC_X86_Translate__Translate_StatmSeq_Copy(OOC_IR__Copy copy) {
          register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8;
          OOC_X86_SSA__Result size;
          OOC_X86_SSA__Result from;
          OOC_X86_SSA__Result to;
          OOC_X86_SSA__Result dynTag;
          OOC_X86_SSA__Result staticTag;
          OOC_X86_SSA__Instr eql;
          OOC_X86_SSA__BranchInstr branch;
          OOC_X86_SSA__Block pathTrue;
          OOC_X86_SSA__Instr endTrue;
          OOC_X86_SSA__Block pathFalse;

          i0 = (OOC_INT32)copy;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12241))+12);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 12246))+4);
          i1 = *(OOC_INT32*)((_check_pointer(i1, 12251))+32);
          i2 = (OOC_INT32)b;
          i1 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddConstLength((OOC_X86_SSA__Block)i2, i1);
          size = (OOC_X86_SSA__Result)i1;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12309))+8);
          i2 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression((OOC_IR__Expression)i2);
          i2 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Designator2Address((OOC_X86_SSA__Result)i2);
          from = (OOC_X86_SSA__Result)i2;
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12368))+12);
          i3 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression((OOC_IR__Expression)i3);
          i3 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Designator2Address((OOC_X86_SSA__Result)i3);
          to = (OOC_X86_SSA__Result)i3;
          i4 = *(OOC_UINT8*)((_check_pointer(i0, 12401))+16);
          if (!i4) goto l3;
          i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12456))+12);
          i4 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_TypeTag((OOC_IR__Expression)i4, 0u, (OOC_Scanner_SymList__Symbol)(OOC_INT32)0);
          dynTag = (OOC_X86_SSA__Result)i4;
          i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12521))+12);
          i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 12526))+4);
          i6 = (OOC_INT32)b;
          i5 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddAdrTypeDescr((OOC_X86_SSA__Block)i6, (OOC_SymbolTable__Type)i5);
          staticTag = (OOC_X86_SSA__Result)i5;
          i6 = (OOC_INT32)b;
          i4 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr2((OOC_X86_SSA__Block)i6, 13, (OOC_X86_SSA__Result)i5, (OOC_X86_SSA__Result)i4);
          eql = (OOC_X86_SSA__Instr)i4;
          i4 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AddResultReg((OOC_X86_SSA__Instr)i4, 0, 2);
          i4 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_SetCC((OOC_X86_SSA__Result)i4);
          i5 = (OOC_INT32)b;
          i4 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddBranch((OOC_X86_SSA__Block)i5, (OOC_X86_SSA__Result)i4, 0u);
          branch = (OOC_X86_SSA__BranchInstr)i4;
          i5 = (OOC_INT32)controlCP;
          OOC_X86_SSA__InstrDesc_AddDep((OOC_X86_SSA__Instr)i4, 0, (OOC_X86_SSA__Instr)i5);
          i5 = (OOC_INT32)b;
          i5 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddConstBool((OOC_X86_SSA__Block)i5, 1u);
          i6 = (OOC_INT32)b;
          i5 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddMerge0((OOC_X86_SSA__Block)i6, 47, (OOC_X86_SSA__Result)i5);
          pathTrue = (OOC_X86_SSA__Block)i5;
          OOC_X86_SSA__InstrDesc_AddDep((OOC_X86_SSA__Instr)i5, 0, (OOC_X86_SSA__Instr)i4);
          i6 = (OOC_INT32)b;
          i6 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr0((OOC_X86_SSA__Block)i6, 49);
          endTrue = (OOC_X86_SSA__Instr)i6;
          i7 = (OOC_INT32)memoryCP;
          OOC_X86_SSA__InstrDesc_AddDep((OOC_X86_SSA__Instr)i6, 1, (OOC_X86_SSA__Instr)i7);
          OOC_X86_SSA__InstrDesc_AddDep((OOC_X86_SSA__Instr)i6, 0, (OOC_X86_SSA__Instr)i5);
          i7 = (OOC_INT32)b;
          i7 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddConstBool((OOC_X86_SSA__Block)i7, 0u);
          i8 = (OOC_INT32)b;
          i7 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddMerge0((OOC_X86_SSA__Block)i8, 47, (OOC_X86_SSA__Result)i7);
          pathFalse = (OOC_X86_SSA__Block)i7;
          OOC_X86_SSA__InstrDesc_AddDep((OOC_X86_SSA__Instr)i7, 0, (OOC_X86_SSA__Instr)i4);
          controlCP = (OOC_X86_SSA__Instr)i7;
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 13376));
          i0 = *(OOC_INT32*)((_check_pointer(i0, 13380))+16);
          OOC_X86_Translate__Translate_FailedCheck((Object__String)((OOC_INT32)_c1), i0, (OOC_X86_SSA__Result)(OOC_INT32)0);
          i0 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_AddJump();
          OOC_X86_SSA__BranchInstrDesc_SetPaths2((OOC_X86_SSA__BranchInstr)i4, (OOC_X86_SSA__Block)i5, (OOC_X86_SSA__Block)i7);
          i4 = (OOC_INT32)b;
          i0 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddMerge2((OOC_X86_SSA__Block)i4, 48, (OOC_X86_SSA__Instr)i6, (OOC_X86_SSA__Instr)i0);
          controlCP = (OOC_X86_SSA__Instr)i0;
          memoryCP = (OOC_X86_SSA__Instr)i0;
l3:
          OOC_X86_Translate__Translate_Memcpy((OOC_X86_SSA__Result)i2, (OOC_X86_SSA__Result)i3, (OOC_X86_SSA__Result)i1);
          return;
          ;
        }

        
        void OOC_X86_Translate__Translate_StatmSeq_MoveBlock(OOC_IR__MoveBlock move) {
          register OOC_INT32 i0,i1,i2,i3,i4,i5;
          OOC_X86_SSA__Result size;
          OOC_X86_SSA__Result from;

          i0 = (OOC_INT32)move;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13873))+16);
          i1 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression((OOC_IR__Expression)i1);
          size = (OOC_X86_SSA__Result)i1;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13912))+8);
          i2 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression((OOC_IR__Expression)i2);
          from = (OOC_X86_SSA__Result)i2;
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13951))+12);
          i0 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression((OOC_IR__Expression)i0);
          i3 = (OOC_INT32)sp;
          i4 = (OOC_INT32)b;
          i4 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddAdrRT((OOC_X86_SSA__Block)i4, (Object__String)((OOC_INT32)_c2));
          i5 = (OOC_INT32)b;
          i3 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr2((OOC_X86_SSA__Block)i5, 29, (OOC_X86_SSA__Result)i4, (OOC_X86_SSA__Result)i3);
          OOC_X86_SSA__InstrDesc_AddOpnd((OOC_X86_SSA__Instr)i3, (OOC_X86_SSA__Result)i0);
          OOC_X86_SSA__InstrDesc_AddOpnd((OOC_X86_SSA__Instr)i3, (OOC_X86_SSA__Result)i2);
          OOC_X86_SSA__InstrDesc_AddOpnd((OOC_X86_SSA__Instr)i3, (OOC_X86_SSA__Result)i1);
          OOC_X86_Translate__Translate_MemoryCP((OOC_X86_SSA__Instr)i3);
          OOC_X86_Translate__Translate_ControlCP((OOC_X86_SSA__Instr)i3);
          return;
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
          auto OOC_X86_SSA__Result OOC_X86_Translate__Translate_StatmSeq_Expression_Negate(OOC_X86_SSA__Result arg, OOC_SymbolTable__Type type);
          auto OOC_X86_SSA__Result OOC_X86_Translate__Translate_StatmSeq_Expression_LeftRight(OOC_X86_SSA__Result arg, OOC_SymbolTable__Type argType, OOC_X86_SSA__Result x, OOC_SymbolTable__Type xType, OOC_INT8 ifNeg, OOC_INT8 ifNotNeg);
          auto OOC_X86_SSA__Result OOC_X86_Translate__Translate_StatmSeq_Expression_NewObject(OOC_IR__NewObject _new);
            
            OOC_X86_SSA__Result OOC_X86_Translate__Translate_StatmSeq_Expression_GetIndexBaseArray(OOC_IR__Expression indexOp, OOC_INT32 *dim) {
              register OOC_INT32 i0,i1;

              i0 = (OOC_INT32)indexOp;
              i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14856)))), &_td_OOC_IR__IndexDesc);
              if (i1) goto l3;
              *dim = (-1);
              i0 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression((OOC_IR__Expression)i0);
              return (OOC_X86_SSA__Result)i0;
              goto l4;
l3:
              i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14914))+8);
              i0 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression_GetIndexBaseArray((OOC_IR__Expression)i0, (void*)(OOC_INT32)dim);
              i1 = *dim;
              *dim = (i1+1);
              return (OOC_X86_SSA__Result)i0;
l4:
              _failed_function(14678); return 0;
              ;
            }

            
            OOC_X86_SSA__Result OOC_X86_Translate__Translate_StatmSeq_Expression_CalculateLength(OOC_X86_SSA__FunctionBlock pb, OOC_IR__Expression value, OOC_INT32 dim, OOC_X86_SSA__Result baseArray) {
              register OOC_INT32 i0,i1,i2,i3;
              OOC_SymbolTable__Type type;
              OOC_INT32 i;
              auto OOC_X86_SSA__Result OOC_X86_Translate__Translate_StatmSeq_Expression_CalculateLength_RecursiveGetLength(OOC_SymbolTable__Type type, OOC_INT32 dim);
                
                OOC_X86_SSA__Result OOC_X86_Translate__Translate_StatmSeq_Expression_CalculateLength_RecursiveGetLength(OOC_SymbolTable__Type type, OOC_INT32 dim) {
                  register OOC_INT32 i0,i1,i2,i3,i4;
                  OOC_X86_SSA__Result len;

                  i0 = (OOC_INT32)type;
                  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 15931)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
                  type = (OOC_SymbolTable__Type)i0;
                  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 15964)))), &_td_OOC_SymbolTable__ArrayDesc);
                  if (i1) goto l3;
                  i0 = (OOC_INT32)pb;
                  i0 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddConstLength((OOC_X86_SSA__Block)i0, 1);
                  return (OOC_X86_SSA__Result)i0;
                  goto l12;
l3:
                  i1 = *(OOC_UINT8*)((_check_pointer(i0, 16000))+40);
                  if (i1) goto l6;
                  i1 = *(OOC_INT32*)((_check_pointer(i0, 16162))+52);
                  i2 = (OOC_INT32)pb;
                  i1 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddConstLength((OOC_X86_SSA__Block)i2, i1);
                  
                  goto l7;
l6:
                  i1 = (OOC_INT32)baseArray;
                  i2 = dim;
                  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 16072))+4);
                  i3 = (OOC_INT32)fp;
                  i4 = (OOC_INT32)pb;
                  i1 = (OOC_INT32)OOC_X86_SSA__FunctionBlockDesc_AddGetLengthInstr((OOC_X86_SSA__FunctionBlock)i4, (OOC_X86_SSA__Instr)i1, (i2+1), (OOC_SymbolTable__Array)i0, (OOC_X86_SSA__Result)i3);
                  
l7:
                  i1 = (OOC_INT32)OOC_X86_Translate__Translate_FixLength((OOC_X86_SSA__Result)i1);
                  len = (OOC_X86_SSA__Result)i1;
                  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16275))+44);
                  i2 = OOC_SymbolTable_TypeRules__IsArray((OOC_SymbolTable__Type)i2);
                  if (i2) goto l10;
                  return (OOC_X86_SSA__Result)i1;
                  goto l12;
l10:
                  i2 = dim;
                  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16403))+44);
                  i0 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression_CalculateLength_RecursiveGetLength((OOC_SymbolTable__Type)i0, (i2+1));
                  i2 = (OOC_INT32)b;
                  i0 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr2((OOC_X86_SSA__Block)i2, 3, (OOC_X86_SSA__Result)i1, (OOC_X86_SSA__Result)i0);
                  i0 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AddResult((OOC_X86_SSA__Instr)i0, 3);
                  return (OOC_X86_SSA__Result)i0;
l12:
                  _failed_function(15762); return 0;
                  ;
                }


              i0 = (OOC_INT32)value;
              i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 16798)))), &_td_OOC_IR__IndexDesc);
              if (!i1) goto l9;
l4_loop:
              i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 16844)))), &_td_OOC_IR__IndexDesc, 16844)), 16850))+8);
              i1 = dim;
              value = (OOC_IR__Expression)i0;
              dim = (i1+1);
              i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 16798)))), &_td_OOC_IR__IndexDesc);
              if (i1) goto l4_loop;
l9:
              i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16990))+4);
              type = (OOC_SymbolTable__Type)i0;
              i = 0;
              i1 = dim;
              i2 = 0<=i1;
              if (!i2) goto l18;
              i2=0;
l13_loop:
              i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 17053)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
              type = (OOC_SymbolTable__Type)i0;
              i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 17094)))), &_td_OOC_SymbolTable__ArrayDesc, 17094)), 17100))+44);
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
              i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 17737)))), &_td_OOC_IR__IndexDesc);
              if (!i1) goto l9;
l4_loop:
              i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 17783)))), &_td_OOC_IR__IndexDesc, 17783)), 17789))+8);
              value = (OOC_IR__Expression)i0;
              i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 17737)))), &_td_OOC_IR__IndexDesc);
              if (i1) goto l4_loop;
l9:
              i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17905))+4);
              type = (OOC_SymbolTable__Type)i0;
              i1 = OOC_SymbolTable_TypeRules__IsArrayType((OOC_SymbolTable__Type)i0);
              if (!i1) goto l18;
l13_loop:
              i0 = (OOC_INT32)OOC_SymbolTable_TypeRules__ArrayElementType((OOC_SymbolTable__Type)i0);
              type = (OOC_SymbolTable__Type)i0;
              i1 = OOC_SymbolTable_TypeRules__IsArrayType((OOC_SymbolTable__Type)i0);
              if (i1) goto l13_loop;
l18:
              i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 18036)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
              type = (OOC_SymbolTable__Type)i0;
              i0 = *(OOC_INT32*)((_check_pointer(i0, 18212))+32);
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
              i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19184))+8);
              i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19184))+8);
              i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 19190))+4);
              i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 19190))+4);
              i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 19195)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i1);
              arrayType = (OOC_SymbolTable__Type)i1;
              i2 = (OOC_INT32)baseArray;
              i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 19256))+4);
              i4 = (OOC_INT32)b;
              i5 = dim;
              i6 = (OOC_INT32)fp;
              i1 = (OOC_INT32)OOC_X86_SSA__FunctionBlockDesc_AddGetLengthInstr((OOC_X86_SSA__FunctionBlock)i4, (OOC_X86_SSA__Instr)i3, i5, (OOC_SymbolTable__Array)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 19323)))), &_td_OOC_SymbolTable__ArrayDesc, 19323)), (OOC_X86_SSA__Result)i6);
              length = (OOC_X86_SSA__Result)i1;
              i1 = (OOC_INT32)OOC_X86_Translate__Translate_FixAddress((OOC_X86_SSA__Result)i1);
              i3 = (OOC_INT32)elementSize;
              i4 = (OOC_INT32)b;
              i1 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr2((OOC_X86_SSA__Block)i4, 3, (OOC_X86_SSA__Result)i3, (OOC_X86_SSA__Result)i1);
              instr = (OOC_X86_SSA__Instr)i1;
              i1 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AddResult((OOC_X86_SSA__Instr)i1, 9);
              newSize = (OOC_X86_SSA__Result)i1;
              i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19489))+8);
              i4 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 19496)))), &_td_OOC_IR__IndexDesc);
              if (i4) goto l3;
              baseResult = (OOC_X86_SSA__Result)i2;
              _assert((i5==0), 127, 19695);
              i1=i2;
              goto l4;
l3:
              i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19553))+8);
              i1 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression_Index((OOC_IR__Index)(_type_guard(i4, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 19563)))), &_td_OOC_IR__IndexDesc, 19563)), (OOC_X86_SSA__Result)i2, (OOC_X86_SSA__Result)i1, (i5-1));
              baseResult = (OOC_X86_SSA__Result)i1;
              
l4:
              dim = (i5+1);
              i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 19774))+4);
              i2 = *(OOC_INT8*)((_check_pointer(i2, 19780))+20);
              _assert((i2==34), 127, 19757);
              i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 20174))+4);
              instr = (OOC_X86_SSA__Instr)i1;
              i2 = (OOC_INT32)OOC_X86_SSA__InstrDesc_GetBeforeInstr((OOC_X86_SSA__Instr)i1, 1);
              memoryCP = (OOC_X86_SSA__Instr)i2;
              i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20339))+12);
              i2 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression((OOC_IR__Expression)i2);
              index = (OOC_X86_SSA__Result)i2;
              OOC_X86_SSA__InstrDesc_DeleteDep((OOC_X86_SSA__Instr)i1, 1);
              OOC_X86_Translate__Translate_MemoryCP((OOC_X86_SSA__Instr)i1);
              i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20773))+4);
              elementType = (OOC_SymbolTable__Type)i4;
              i4 = (OOC_INT32)OOC_X86_Translate__Translate_FixAddress((OOC_X86_SSA__Result)i2);
              i5 = (OOC_INT32)b;
              i3 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr2((OOC_X86_SSA__Block)i5, 3, (OOC_X86_SSA__Result)i4, (OOC_X86_SSA__Result)i3);
              instr1 = (OOC_X86_SSA__Instr)i3;
              i3 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AddResult((OOC_X86_SSA__Instr)i3, 9);
              scaledIndex = (OOC_X86_SSA__Result)i3;
              i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 20943));
              adrOpnd = (OOC_X86_SSA__Opnd)i4;
              i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 21000));
              i6 = (OOC_INT32)b;
              i3 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr2((OOC_X86_SSA__Block)i6, 1, (OOC_X86_SSA__Result)i5, (OOC_X86_SSA__Result)i3);
              instr1 = (OOC_X86_SSA__Instr)i3;
              i3 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AddResult((OOC_X86_SSA__Instr)i3, 9);
              elementAdr = (OOC_X86_SSA__Result)i3;
              OOC_X86_SSA__OpndDesc_ReplaceArg((OOC_X86_SSA__Opnd)i4, (OOC_X86_SSA__Result)i3);
              i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21167))+4);
              i0 = OOC_X86_SSA__MapType((OOC_SymbolTable__Type)i0);
              i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 21130))+4);
              OOC_X86_SSA__ResultDesc_SetType((OOC_X86_SSA__Result)i3, i0);
              i0 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_SSA__Index.baseTypes[0]);
              i3 = (OOC_INT32)b;
              OOC_X86_SSA__IndexDesc_INIT((OOC_X86_SSA__Index)i0, (OOC_X86_SSA__FunctionBlock)i3, (OOC_X86_SSA__Result)i2);
              OOC_X86_SSA__InstrDesc_ExtendDesignator((OOC_X86_SSA__Instr)i1, (OOC_X86_SSA__Selector)i0);
              i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 21278))+4);
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
              i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21749))+8);
              i1 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression((OOC_IR__Expression)i1);
              baseResult = (OOC_X86_SSA__Result)i1;
              i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 21787))+4);
              i2 = *(OOC_INT8*)((_check_pointer(i2, 21793))+20);
              _assert((i2==34), 127, 21769);
              i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 21840))+4);
              instr = (OOC_X86_SSA__Instr)i1;
              i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 21885));
              adrOpnd = (OOC_X86_SSA__Opnd)i2;
              i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22009))+12);
              i3 = *(OOC_INT32*)((_check_pointer(i3, 22015))+56);
              i4 = (OOC_INT32)b;
              i3 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddConstLength((OOC_X86_SSA__Block)i4, i3);
              i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 21944));
              i5 = (OOC_INT32)b;
              i3 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr2((OOC_X86_SSA__Block)i5, 1, (OOC_X86_SSA__Result)i4, (OOC_X86_SSA__Result)i3);
              fieldAdr = (OOC_X86_SSA__Instr)i3;
              i3 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AddResult((OOC_X86_SSA__Instr)i3, 9);
              OOC_X86_SSA__OpndDesc_ReplaceArg((OOC_X86_SSA__Opnd)i2, (OOC_X86_SSA__Result)i3);
              i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22140))+4);
              i2 = OOC_X86_SSA__MapType((OOC_SymbolTable__Type)i2);
              i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 22102))+4);
              OOC_X86_SSA__ResultDesc_SetType((OOC_X86_SSA__Result)i3, i2);
              i2 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_SSA__Field.baseTypes[0]);
              i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22214))+12);
              OOC_X86_SSA__FieldDesc_INIT((OOC_X86_SSA__Field)i2, (OOC_SymbolTable__FieldDecl)i0);
              OOC_X86_SSA__InstrDesc_ExtendDesignator((OOC_X86_SSA__Instr)i1, (OOC_X86_SSA__Selector)i2);
              i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 22257))+4);
              return (OOC_X86_SSA__Result)i0;
              ;
            }

            
            OOC_X86_SSA__Result OOC_X86_Translate__Translate_StatmSeq_Expression_TypeGuard(OOC_IR__TypeGuard guard) {
              register OOC_INT32 i0;

              i0 = (OOC_INT32)guard;
              i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22423))+8);
              i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22428))+20);
              i0 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression((OOC_IR__Expression)i0);
              return (OOC_X86_SSA__Result)i0;
              ;
            }

            
            OOC_X86_SSA__Result OOC_X86_Translate__Translate_StatmSeq_Expression_TypeConv(OOC_IR__TypeConv conv) {
              register OOC_INT32 i0,i1,i2;
              OOC_INT8 typeDest;
              OOC_INT8 typeSource;

              i0 = (OOC_INT32)conv;
              i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22718))+4);
              i1 = OOC_SymbolTable_TypeRules__IsSTRING((OOC_SymbolTable__Type)i1);
              if (i1) goto l7;
              i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24380))+4);
              i1 = OOC_X86_SSA__MapType((OOC_SymbolTable__Type)i1);
              typeDest = i1;
              i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24428))+8);
              i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 24433))+4);
              i2 = OOC_X86_SSA__MapType((OOC_SymbolTable__Type)i2);
              typeSource = i2;
              i2 = i1!=i2;
              if (i2) goto l5;
              i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24657))+8);
              i0 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression((OOC_IR__Expression)i0);
              return (OOC_X86_SSA__Result)i0;
              goto l8;
l5:
              i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24547))+8);
              i0 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression((OOC_IR__Expression)i0);
              i2 = (OOC_INT32)b;
              i0 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr1((OOC_X86_SSA__Block)i2, 22, (OOC_X86_SSA__Result)i0);
              i0 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AddResult((OOC_X86_SSA__Instr)i0, i1);
              return (OOC_X86_SSA__Result)i0;
              goto l8;
l7:
              return (OOC_X86_SSA__Result)(OOC_INT32)0;
l8:
              _failed_function(22480); return 0;
              ;
            }

            
            OOC_X86_SSA__Result OOC_X86_Translate__Translate_StatmSeq_Expression_Negate(OOC_X86_SSA__Result arg, OOC_SymbolTable__Type type) {
              register OOC_INT32 i0,i1,i2;

              i0 = (OOC_INT32)type;
              i1 = OOC_SymbolTable_TypeRules__IsRealType((OOC_SymbolTable__Type)i0);
              if (i1) goto l3;
              i0 = (OOC_INT32)arg;
              i1 = (OOC_INT32)b;
              i1 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr1((OOC_X86_SSA__Block)i1, 5, (OOC_X86_SSA__Result)i0);
              instr = (OOC_X86_SSA__Instr)i1;
              
              goto l4;
l3:
              i1 = (OOC_INT32)b;
              i0 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddConstZero((OOC_X86_SSA__Block)i1, (OOC_SymbolTable__Type)i0);
              i1 = (OOC_INT32)b;
              i2 = (OOC_INT32)arg;
              i0 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr2((OOC_X86_SSA__Block)i1, 2, (OOC_X86_SSA__Result)i0, (OOC_X86_SSA__Result)i2);
              instr = (OOC_X86_SSA__Instr)i0;
              i1=i0;i0=i2;
l4:
              i0 = *(OOC_INT8*)((_check_pointer(i0, 25041))+12);
              i0 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AddResult((OOC_X86_SSA__Instr)i1, i0);
              return (OOC_X86_SSA__Result)i0;
              ;
            }

            
            OOC_X86_SSA__Result OOC_X86_Translate__Translate_StatmSeq_Expression_LeftRight(OOC_X86_SSA__Result arg, OOC_SymbolTable__Type argType, OOC_X86_SSA__Result x, OOC_SymbolTable__Type xType, OOC_INT8 ifNeg, OOC_INT8 ifNotNeg) {
              register OOC_INT32 i0,i1,i2,i3,i4;
              OOC_X86_SSA__Instr cmp;
              OOC_X86_SSA__BranchInstr branch;
              OOC_X86_SSA__Block pathTrue;
              OOC_X86_SSA__Instr endTrue;
              OOC_X86_SSA__Result xNegate;
              OOC_X86_SSA__Result valueTrue;
              OOC_X86_SSA__Block pathFalse;
              OOC_X86_SSA__Instr endFalse;
              auto OOC_X86_SSA__Result OOC_X86_Translate__Translate_StatmSeq_Expression_LeftRight_Op(OOC_INT8 opc, OOC_X86_SSA__Result y);
                
                OOC_X86_SSA__Result OOC_X86_Translate__Translate_StatmSeq_Expression_LeftRight_Op(OOC_INT8 opc, OOC_X86_SSA__Result y) {
                  register OOC_INT32 i0,i1,i2,i3;

                  i0 = opc;
                  i1 = i0==(-1);
                  if (i1) goto l3;
                  i1 = (OOC_INT32)b;
                  i2 = (OOC_INT32)arg;
                  i3 = (OOC_INT32)y;
                  i0 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr2((OOC_X86_SSA__Block)i1, i0, (OOC_X86_SSA__Result)i2, (OOC_X86_SSA__Result)i3);
                  i1 = (OOC_INT32)argType;
                  i0 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AddResultExpr((OOC_X86_SSA__Instr)i0, (OOC_SymbolTable__Type)i1);
                  return (OOC_X86_SSA__Result)i0;
                  goto l4;
l3:
                  i0 = (OOC_INT32)y;
                  return (OOC_X86_SSA__Result)i0;
l4:
                  _failed_function(25515); return 0;
                  ;
                }


              i0 = (OOC_INT32)xType;
              i1 = (OOC_INT32)b;
              i1 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddConstZero((OOC_X86_SSA__Block)i1, (OOC_SymbolTable__Type)i0);
              i2 = (OOC_INT32)x;
              i3 = (OOC_INT32)b;
              i1 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr2((OOC_X86_SSA__Block)i3, 15, (OOC_X86_SSA__Result)i2, (OOC_X86_SSA__Result)i1);
              cmp = (OOC_X86_SSA__Instr)i1;
              i1 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AddResultReg((OOC_X86_SSA__Instr)i1, 0, 2);
              i1 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_SetCC((OOC_X86_SSA__Result)i1);
              i3 = (OOC_INT32)b;
              i1 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddBranch((OOC_X86_SSA__Block)i3, (OOC_X86_SSA__Result)i1, 0u);
              branch = (OOC_X86_SSA__BranchInstr)i1;
              i3 = (OOC_INT32)controlCP;
              OOC_X86_SSA__InstrDesc_AddDep((OOC_X86_SSA__Instr)i1, 0, (OOC_X86_SSA__Instr)i3);
              i3 = (OOC_INT32)b;
              i3 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddConstBool((OOC_X86_SSA__Block)i3, 1u);
              i4 = (OOC_INT32)b;
              i3 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddMerge0((OOC_X86_SSA__Block)i4, 47, (OOC_X86_SSA__Result)i3);
              pathTrue = (OOC_X86_SSA__Block)i3;
              OOC_X86_SSA__InstrDesc_AddDep((OOC_X86_SSA__Instr)i3, 0, (OOC_X86_SSA__Instr)i1);
              i1 = (OOC_INT32)b;
              i1 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr0((OOC_X86_SSA__Block)i1, 49);
              endTrue = (OOC_X86_SSA__Instr)i1;
              i4 = (OOC_INT32)memoryCP;
              OOC_X86_SSA__InstrDesc_AddDep((OOC_X86_SSA__Instr)i1, 1, (OOC_X86_SSA__Instr)i4);
              OOC_X86_SSA__InstrDesc_AddDep((OOC_X86_SSA__Instr)i1, 0, (OOC_X86_SSA__Instr)i3);
              i0 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression_Negate((OOC_X86_SSA__Result)i2, (OOC_SymbolTable__Type)i0);
              xNegate = (OOC_X86_SSA__Result)i0;
              i1 = ifNeg;
              i0 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression_LeftRight_Op(i1, (OOC_X86_SSA__Result)i0);
              valueTrue = (OOC_X86_SSA__Result)i0;
              i0 = (OOC_INT32)b;
              i0 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddConstBool((OOC_X86_SSA__Block)i0, 0u);
              i1 = (OOC_INT32)b;
              i0 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddMerge0((OOC_X86_SSA__Block)i1, 47, (OOC_X86_SSA__Result)i0);
              pathFalse = (OOC_X86_SSA__Block)i0;
              i1 = (OOC_INT32)branch;
              OOC_X86_SSA__InstrDesc_AddDep((OOC_X86_SSA__Instr)i0, 0, (OOC_X86_SSA__Instr)i1);
              i1 = (OOC_INT32)b;
              i1 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr0((OOC_X86_SSA__Block)i1, 49);
              endFalse = (OOC_X86_SSA__Instr)i1;
              i2 = (OOC_INT32)memoryCP;
              OOC_X86_SSA__InstrDesc_AddDep((OOC_X86_SSA__Instr)i1, 1, (OOC_X86_SSA__Instr)i2);
              OOC_X86_SSA__InstrDesc_AddDep((OOC_X86_SSA__Instr)i1, 0, (OOC_X86_SSA__Instr)i0);
              i0 = ifNotNeg;
              i1 = (OOC_INT32)x;
              i0 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression_LeftRight_Op(i0, (OOC_X86_SSA__Result)i1);
              i1 = (OOC_INT32)pathFalse;
              i2 = (OOC_INT32)pathTrue;
              i3 = (OOC_INT32)branch;
              OOC_X86_SSA__BranchInstrDesc_SetPaths2((OOC_X86_SSA__BranchInstr)i3, (OOC_X86_SSA__Block)i2, (OOC_X86_SSA__Block)i1);
              i1 = (OOC_INT32)b;
              i2 = (OOC_INT32)endFalse;
              i3 = (OOC_INT32)endTrue;
              i1 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddMerge2((OOC_X86_SSA__Block)i1, 48, (OOC_X86_SSA__Instr)i3, (OOC_X86_SSA__Instr)i2);
              i2 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddGate((OOC_X86_SSA__Block)i1, 50);
              i3 = (OOC_INT32)valueTrue;
              OOC_X86_SSA__InstrDesc_AddOpnd((OOC_X86_SSA__Instr)i2, (OOC_X86_SSA__Result)i3);
              OOC_X86_SSA__InstrDesc_AddOpnd((OOC_X86_SSA__Instr)i2, (OOC_X86_SSA__Result)i0);
              controlCP = (OOC_X86_SSA__Instr)i1;
              memoryCP = (OOC_X86_SSA__Instr)i1;
              i0 = (OOC_INT32)argType;
              i0 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AddResultExpr((OOC_X86_SSA__Instr)i2, (OOC_SymbolTable__Type)i0);
              return (OOC_X86_SSA__Result)i0;
              ;
            }

            
            OOC_X86_SSA__Result OOC_X86_Translate__Translate_StatmSeq_Expression_NewObject(OOC_IR__NewObject _new) {
              register OOC_INT32 i0,i1,i2,i3;

              i0 = (OOC_INT32)_new;
              i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 27562))+4);
              i1 = (OOC_INT32)b;
              i0 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddAdrTypeDescr((OOC_X86_SSA__Block)i1, (OOC_SymbolTable__Type)i0);
              i1 = (OOC_INT32)b;
              i0 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr1((OOC_X86_SSA__Block)i1, 34, (OOC_X86_SSA__Result)i0);
              i0 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AddResult((OOC_X86_SSA__Instr)i0, 9);
              i1 = (OOC_INT32)b;
              i0 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr1((OOC_X86_SSA__Block)i1, 34, (OOC_X86_SSA__Result)i0);
              i0 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AddResult((OOC_X86_SSA__Instr)i0, 9);
              i1 = (OOC_INT32)sp;
              i2 = (OOC_INT32)b;
              i2 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddAdrRT((OOC_X86_SSA__Block)i2, (Object__String)((OOC_INT32)_c3));
              i3 = (OOC_INT32)b;
              i0 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr3((OOC_X86_SSA__Block)i3, 29, (OOC_X86_SSA__Result)i2, (OOC_X86_SSA__Result)i1, (OOC_X86_SSA__Result)i0);
              OOC_X86_Translate__Translate_MemoryCP((OOC_X86_SSA__Instr)i0);
              OOC_X86_Translate__Translate_ControlCP((OOC_X86_SSA__Instr)i0);
              i0 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AddResult((OOC_X86_SSA__Instr)i0, 9);
              return (OOC_X86_SSA__Result)i0;
              ;
            }


          i0 = (OOC_INT32)expr;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 28234)))), &_td_OOC_IR__ConstDesc);
          if (i1) goto l152;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 28676)))), &_td_OOC_IR__ProcedureRefDesc);
          if (i1) goto l150;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 28787)))), &_td_OOC_IR__VarDesc);
          if (i1) goto l129;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 29896)))), &_td_OOC_IR__IndexDesc);
          if (i1) goto l127;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 30183)))), &_td_OOC_IR__SelectFieldDesc);
          if (i1) goto l125;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 30264)))), &_td_OOC_IR__DerefDesc);
          if (i1) goto l121;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 31081)))), &_td_OOC_IR__AdrDesc);
          if (i1) goto l115;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 31505)))), &_td_OOC_IR__LenDesc);
          if (i1) goto l109;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 32141)))), &_td_OOC_IR__TypeTagDesc);
          if (i1) goto l107;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 32242)))), &_td_OOC_IR__TypeTestDesc);
          if (i1) goto l105;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 32596)))), &_td_OOC_IR__TypeGuardDesc);
          if (i1) goto l103;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 32677)))), &_td_OOC_IR__TypeConvDesc);
          if (i1) goto l101;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 32741)))), &_td_OOC_IR__TypeCastDesc);
          if (i1) goto l99;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 32899)))), &_td_OOC_IR__BinaryArithDesc);
          if (i1) goto l91;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 33679)))), &_td_OOC_IR__ChangeElementDesc);
          if (i1) goto l84;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 34069)))), &_td_OOC_IR__NegateDesc);
          if (i1) goto l82;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 34161)))), &_td_OOC_IR__CompareDesc);
          if (i1) goto l71;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 34685)))), &_td_OOC_IR__BooleanOpDesc);
          if (i1) goto l61;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 36120)))), &_td_OOC_IR__AbsDesc);
          if (i1) goto l59;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 36262)))), &_td_OOC_IR__AshDesc);
          if (i1) goto l57;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 36500)))), &_td_OOC_IR__ShiftDesc);
          if (i1) goto l51;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 36898)))), &_td_OOC_IR__CallDesc);
          if (i1) goto l49;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 36954)))), &_td_OOC_IR__NewObjectDesc);
          if (i1) goto l47;
          _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 36948)))), 36948);
          goto l158;
l47:
          i0 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression_NewObject((OOC_IR__NewObject)i0);
          return (OOC_X86_SSA__Result)i0;
          goto l158;
l49:
          i0 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Call((OOC_IR__Call)i0);
          return (OOC_X86_SSA__Result)i0;
          goto l158;
l51:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 36547))+8);
          i1 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression((OOC_IR__Expression)i1);
          arg1 = (OOC_X86_SSA__Result)i1;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 36589))+12);
          i2 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression((OOC_IR__Expression)i2);
          arg2 = (OOC_X86_SSA__Result)i2;
          i3 = *(OOC_UINT8*)((_check_pointer(i0, 36612))+16);
          if (i3) goto l54;
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 36833))+12);
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 36836))+4);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 36787))+4);
          i0 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression_LeftRight((OOC_X86_SSA__Result)i1, (OOC_SymbolTable__Type)i0, (OOC_X86_SSA__Result)i2, (OOC_SymbolTable__Type)i3, 8, 9);
          return (OOC_X86_SSA__Result)i0;
          goto l158;
l54:
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 36710))+12);
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 36713))+4);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 36664))+4);
          i0 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression_LeftRight((OOC_X86_SSA__Result)i1, (OOC_SymbolTable__Type)i0, (OOC_X86_SSA__Result)i2, (OOC_SymbolTable__Type)i3, 10, 11);
          return (OOC_X86_SSA__Result)i0;
          goto l158;
l57:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 36307))+8);
          i1 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression((OOC_IR__Expression)i1);
          arg1 = (OOC_X86_SSA__Result)i1;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 36349))+12);
          i2 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression((OOC_IR__Expression)i2);
          arg2 = (OOC_X86_SSA__Result)i2;
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 36460))+12);
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 36464))+4);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 36416))+4);
          i4 = (OOC_INT32)b;
          i1 = (OOC_INT32)OOC_X86_SSA__FunctionBlockDesc_FixType((OOC_X86_SSA__FunctionBlock)i4, (OOC_X86_SSA__Result)i1, 3);
          i0 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression_LeftRight((OOC_X86_SSA__Result)i1, (OOC_SymbolTable__Type)i0, (OOC_X86_SSA__Result)i2, (OOC_SymbolTable__Type)i3, 6, 7);
          return (OOC_X86_SSA__Result)i0;
          goto l158;
l59:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 36232))+4);
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 36217))+8);
          i2 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression((OOC_IR__Expression)i2);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 36168))+4);
          i0 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression_LeftRight((OOC_X86_SSA__Result)0, (OOC_SymbolTable__Type)i0, (OOC_X86_SSA__Result)i2, (OOC_SymbolTable__Type)i1, (-1), (-1));
          return (OOC_X86_SSA__Result)i0;
          goto l158;
l61:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 34774))+12);
          i1 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression((OOC_IR__Expression)i1);
          res = (OOC_X86_SSA__Result)i1;
          i2 = (OOC_INT32)controlCP;
          i3 = (OOC_INT32)memoryCP;
          OOC_X86_Translate__Translate_StatmSeq_SplitPaths((OOC_X86_SSA__Result)i1, (OOC_X86_SSA__Instr)i2, (OOC_X86_SSA__Instr)i3, (void*)(OOC_INT32)&controlTrue, (void*)(OOC_INT32)&memoryTrue, (void*)(OOC_INT32)&controlFalse, (void*)(OOC_INT32)&memoryFalse);
          i1 = (OOC_INT32)memoryTrue;
          memoryCP = (OOC_X86_SSA__Instr)i1;
          i1 = (OOC_INT32)controlTrue;
          controlCP = (OOC_X86_SSA__Instr)i1;
          i1 = *(OOC_INT8*)((_check_pointer(i0, 35041))+8);
          i1 = i1==20;
          if (i1) goto l64;
          i1 = (OOC_INT32)b;
          i1 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddConstBool((OOC_X86_SSA__Block)i1, 1u);
          arg1 = (OOC_X86_SSA__Result)i1;
          
          goto l65;
l64:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 35136))+16);
          i1 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression((OOC_IR__Expression)i1);
          i1 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_SetBool((OOC_X86_SSA__Result)i1);
          arg1 = (OOC_X86_SSA__Result)i1;
          
l65:
          i2 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_AddJump();
          endTrue = (OOC_X86_SSA__Instr)i2;
          i3 = (OOC_INT32)memoryFalse;
          memoryCP = (OOC_X86_SSA__Instr)i3;
          i3 = (OOC_INT32)controlFalse;
          controlCP = (OOC_X86_SSA__Instr)i3;
          i3 = *(OOC_INT8*)((_check_pointer(i0, 35427))+8);
          i3 = i3==20;
          if (i3) goto l68;
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 35637))+16);
          i3 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression((OOC_IR__Expression)i3);
          i3 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_SetBool((OOC_X86_SSA__Result)i3);
          arg2 = (OOC_X86_SSA__Result)i3;
          
          goto l69;
l68:
          i3 = (OOC_INT32)b;
          i3 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddConstBool((OOC_X86_SSA__Block)i3, 0u);
          arg2 = (OOC_X86_SSA__Result)i3;
          
l69:
          i4 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_AddJump();
          endFalse = (OOC_X86_SSA__Instr)i4;
          i5 = (OOC_INT32)b;
          i2 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddMerge2((OOC_X86_SSA__Block)i5, 48, (OOC_X86_SSA__Instr)i2, (OOC_X86_SSA__Instr)i4);
          merge = (OOC_X86_SSA__MergeInstr)i2;
          controlCP = (OOC_X86_SSA__Instr)i2;
          memoryCP = (OOC_X86_SSA__Instr)i2;
          i2 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddGate((OOC_X86_SSA__Block)i2, 50);
          instr = (OOC_X86_SSA__Instr)i2;
          OOC_X86_SSA__InstrDesc_AddOpnd((OOC_X86_SSA__Instr)i2, (OOC_X86_SSA__Result)i1);
          OOC_X86_SSA__InstrDesc_AddOpnd((OOC_X86_SSA__Instr)i2, (OOC_X86_SSA__Result)i3);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 36097))+4);
          i0 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AddResultExpr((OOC_X86_SSA__Instr)i2, (OOC_SymbolTable__Type)i0);
          return (OOC_X86_SSA__Result)i0;
          goto l158;
l71:
          i1 = *(OOC_INT8*)((_check_pointer(i0, 34196))+8);
          switch (i1) {
          case 10:
            opcode = 13;
            goto l80;
          case 11:
            opcode = 14;
            goto l80;
          case 12:
            opcode = 15;
            goto l80;
          case 13:
            opcode = 16;
            goto l80;
          case 14:
            opcode = 17;
            goto l80;
          case 15:
            opcode = 18;
            goto l80;
          default:
            _failed_case(i1, 34187);
            goto l80;
          }
l80:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 34505))+12);
          i1 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression((OOC_IR__Expression)i1);
          arg1 = (OOC_X86_SSA__Result)i1;
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 34546))+16);
          i0 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression((OOC_IR__Expression)i0);
          i2 = (OOC_INT32)b;
          i3 = opcode;
          i0 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr2((OOC_X86_SSA__Block)i2, i3, (OOC_X86_SSA__Result)i1, (OOC_X86_SSA__Result)i0);
          i0 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AddResultReg((OOC_X86_SSA__Instr)i0, 0, 2);
          return (OOC_X86_SSA__Result)i0;
          goto l158;
l82:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 34138))+4);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 34123))+8);
          i0 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression((OOC_IR__Expression)i0);
          i0 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression_Negate((OOC_X86_SSA__Result)i0, (OOC_SymbolTable__Type)i1);
          return (OOC_X86_SSA__Result)i0;
          goto l158;
l84:
          i1 = *(OOC_INT8*)((_check_pointer(i0, 33720))+8);
          switch (i1) {
          case 22:
            opcode = 20;
            goto l89;
          case 23:
            opcode = 21;
            goto l89;
          default:
            _failed_case(i1, 33711);
            goto l89;
          }
l89:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 33892))+12);
          i1 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression((OOC_IR__Expression)i1);
          arg1 = (OOC_X86_SSA__Result)i1;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 33932))+16);
          i2 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression((OOC_IR__Expression)i2);
          arg2 = (OOC_X86_SSA__Result)i2;
          i3 = (OOC_INT32)b;
          i4 = opcode;
          i1 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr2((OOC_X86_SSA__Block)i3, i4, (OOC_X86_SSA__Result)i1, (OOC_X86_SSA__Result)i2);
          instr = (OOC_X86_SSA__Instr)i1;
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 34036))+4);
          i0 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AddResultExpr((OOC_X86_SSA__Instr)i1, (OOC_SymbolTable__Type)i0);
          return (OOC_X86_SSA__Result)i0;
          goto l158;
l91:
          i1 = *(OOC_INT8*)((_check_pointer(i0, 32938))+8);
          switch (i1) {
          case 0:
            opcode = 1;
            goto l97;
          case 1:
            opcode = 2;
            goto l97;
          case 4:
            opcode = 3;
            goto l97;
          default:
            _failed_case(i1, 32929);
            goto l97;
          }
l97:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 33503))+12);
          i1 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression((OOC_IR__Expression)i1);
          arg1 = (OOC_X86_SSA__Result)i1;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 33544))+16);
          i2 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression((OOC_IR__Expression)i2);
          arg2 = (OOC_X86_SSA__Result)i2;
          i3 = (OOC_INT32)b;
          i4 = opcode;
          i1 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr2((OOC_X86_SSA__Block)i3, i4, (OOC_X86_SSA__Result)i1, (OOC_X86_SSA__Result)i2);
          instr = (OOC_X86_SSA__Instr)i1;
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 33646))+4);
          i0 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AddResultExpr((OOC_X86_SSA__Instr)i1, (OOC_SymbolTable__Type)i0);
          return (OOC_X86_SSA__Result)i0;
          goto l158;
l99:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 32816))+8);
          i1 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression((OOC_IR__Expression)i1);
          i2 = (OOC_INT32)b;
          i1 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr1((OOC_X86_SSA__Block)i2, 37, (OOC_X86_SSA__Result)i1);
          instr = (OOC_X86_SSA__Instr)i1;
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 32866))+4);
          i0 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AddResultExpr((OOC_X86_SSA__Instr)i1, (OOC_SymbolTable__Type)i0);
          return (OOC_X86_SSA__Result)i0;
          goto l158;
l101:
          i0 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression_TypeConv((OOC_IR__TypeConv)i0);
          return (OOC_X86_SSA__Result)i0;
          goto l158;
l103:
          i0 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression_TypeGuard((OOC_IR__TypeGuard)i0);
          return (OOC_X86_SSA__Result)i0;
          goto l158;
l105:
          i1 = (OOC_INT32)sp;
          i2 = (OOC_INT32)b;
          i2 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddAdrRT((OOC_X86_SSA__Block)i2, (Object__String)((OOC_INT32)_c4));
          i3 = (OOC_INT32)b;
          i1 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr2((OOC_X86_SSA__Block)i3, 29, (OOC_X86_SSA__Result)i2, (OOC_X86_SSA__Result)i1);
          instr = (OOC_X86_SSA__Instr)i1;
          i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 32399));
          i3 = *(OOC_UINT8*)((_check_pointer(i0, 32380))+16);
          i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 32369))+8);
          i2 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_TypeTag((OOC_IR__Expression)i4, i3, (OOC_Scanner_SymList__Symbol)i2);
          OOC_X86_SSA__InstrDesc_AddOpnd((OOC_X86_SSA__Instr)i1, (OOC_X86_SSA__Result)i2);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 32453))+12);
          i2 = (OOC_INT32)b;
          i0 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddAdrTypeDescr((OOC_X86_SSA__Block)i2, (OOC_SymbolTable__Type)i0);
          OOC_X86_SSA__InstrDesc_AddOpnd((OOC_X86_SSA__Instr)i1, (OOC_X86_SSA__Result)i0);
          OOC_X86_Translate__Translate_MemoryCP((OOC_X86_SSA__Instr)i1);
          OOC_X86_Translate__Translate_ControlCP((OOC_X86_SSA__Instr)i1);
          i0 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AddResult((OOC_X86_SSA__Instr)i1, 5);
          return (OOC_X86_SSA__Result)i0;
          goto l158;
l107:
          i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 32206));
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 32186))+8);
          i0 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_TypeTag((OOC_IR__Expression)i0, 0u, (OOC_Scanner_SymList__Symbol)i1);
          return (OOC_X86_SSA__Result)i0;
          goto l158;
l109:
          i1 = *(OOC_INT8*)((_check_pointer(i0, 31535))+8);
          i1 = i1==16;
          if (i1) goto l112;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 31764))+20);
          i1 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression((OOC_IR__Expression)i1);
          baseArray = (OOC_X86_SSA__Result)i1;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 31814))+4);
          i2 = (OOC_INT32)OOC_X86_SSA__InstrDesc_GetBeforeInstr((OOC_X86_SSA__Instr)i2, 1);
          memoryCP = (OOC_X86_SSA__Instr)i2;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 31874))+20);
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 31874))+20);
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 31888))+4);
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 31888))+4);
          i2 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 31893)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i2);
          type = (OOC_SymbolTable__Type)i2;
          i3 = *(OOC_INT32*)((_check_pointer(i0, 31963))+16);
          i2 = (OOC_INT32)OOC_SymbolTable__ArrayDesc_GetNthElementType((OOC_SymbolTable__Array)(_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 31934)))), &_td_OOC_SymbolTable__ArrayDesc, 31934)), i3);
          type = (OOC_SymbolTable__Type)i2;
          i0 = *(OOC_INT32*)((_check_pointer(i0, 32030))+16);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 32018))+4);
          i3 = (OOC_INT32)fp;
          i4 = (OOC_INT32)b;
          i0 = (OOC_INT32)OOC_X86_SSA__FunctionBlockDesc_AddGetLengthInstr((OOC_X86_SSA__FunctionBlock)i4, (OOC_X86_SSA__Instr)i1, i0, (OOC_SymbolTable__Array)(_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 32084)))), &_td_OOC_SymbolTable__ArrayDesc, 32084)), (OOC_X86_SSA__Result)i3);
          return (OOC_X86_SSA__Result)i0;
          goto l158;
l112:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 31610))+20);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 31628)))), &_td_OOC_IR__ConstDesc, 31628)), 31634))+8);
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 31684)))), &_td_Object_Boxed__StringDesc, 31684)), 31691));
          i0 = *(OOC_INT32*)(_check_pointer(i0, 31697));
          i1 = (OOC_INT32)b;
          i0 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddConstLength((OOC_X86_SSA__Block)i1, (i0+1));
          return (OOC_X86_SSA__Result)i0;
          goto l158;
l115:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 31125))+8);
          i0 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression((OOC_IR__Expression)i0);
          res = (OOC_X86_SSA__Result)i0;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 31152))+4);
          i1 = *(OOC_INT8*)((_check_pointer(i1, 31158))+20);
          i1 = i1==34;
          if (i1) goto l118;
          return (OOC_X86_SSA__Result)i0;
          goto l158;
l118:
          i0 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Designator2Address((OOC_X86_SSA__Result)i0);
          i1 = (OOC_INT32)b;
          i0 = (OOC_INT32)OOC_X86_SSA__FunctionBlockDesc_FixType((OOC_X86_SSA__FunctionBlock)i1, (OOC_X86_SSA__Result)i0, 9);
          return (OOC_X86_SSA__Result)i0;
          goto l158;
l121:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 30413))+8);
          i1 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression((OOC_IR__Expression)i1);
          adr = (OOC_X86_SSA__Result)i1;
          i2 = *(OOC_UINT8*)((_check_pointer(i0, 30441))+12);
          if (i2) goto l123;
l123:
          i2 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_SSA__Designator.baseTypes[0], 1);
          designator = (OOC_X86_SSA__Designator)i2;
          i3 = _check_pointer(i2, 30754);
          i4 = OOC_ARRAY_LENGTH(i3, 0);
          i5 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_SSA__HeapObj.baseTypes[0]);
          i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 30783))+4);
          i7 = (OOC_INT32)b;
          OOC_X86_SSA__HeapObjDesc_INIT((OOC_X86_SSA__HeapObj)i5, (OOC_X86_SSA__FunctionBlock)i7, (OOC_SymbolTable__Type)i6, (OOC_X86_SSA__Result)i1);
          *(OOC_INT32*)(i3+(_check_index(0, i4, OOC_UINT8, 30754))*4) = i5;
          i3 = (OOC_INT32)b;
          i1 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr1((OOC_X86_SSA__Block)i3, 34, (OOC_X86_SSA__Result)i1);
          instr = (OOC_X86_SSA__Instr)i1;
          OOC_X86_SSA__InstrDesc_SetDesignator((OOC_X86_SSA__Instr)i1, (OOC_X86_SSA__Designator)i2);
          OOC_X86_Translate__Translate_MemoryCP((OOC_X86_SSA__Instr)i1);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 31048))+4);
          i0 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AddResultExpr((OOC_X86_SSA__Instr)i1, (OOC_SymbolTable__Type)i0);
          return (OOC_X86_SSA__Result)i0;
          goto l158;
l125:
          i0 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression_SelectField((OOC_IR__SelectField)i0);
          return (OOC_X86_SSA__Result)i0;
          goto l158;
l127:
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
          goto l158;
l129:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 28824))+8);
          i1 = _type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 28834)))), &_td_OOC_SymbolTable__VarDeclDesc, 28834);
          varDecl = (OOC_SymbolTable__VarDecl)i1;
          i2 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_SSA__Var.baseTypes[0]);
          OOC_X86_SSA__VarDesc_INIT((OOC_X86_SSA__Var)i2, (OOC_SymbolTable__VarDecl)i1);
          var = (OOC_X86_SSA__Var)i2;
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 28903))+4);
          i3 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 28911)))), &_td_OOC_SymbolTable__ModuleDesc);
          if (i3) goto l147;
          i3 = *(OOC_UINT8*)((_check_pointer(i1, 29081))+56);
          i3 = !i3;
          if (!i3) goto l134;
          i3 = (OOC_INT32)b;
          OOC_X86_SSA__FunctionBlockDesc_AllocateLocalVar((OOC_X86_SSA__FunctionBlock)i3, (OOC_SymbolTable__VarDecl)i1);
l134:
          i3 = (OOC_INT32)b;
          i3 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddFramePointerOffset((OOC_X86_SSA__Block)i3, (OOC_SymbolTable__VarDecl)i1);
          i4 = (OOC_INT32)fp;
          i5 = (OOC_INT32)b;
          i3 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr2((OOC_X86_SSA__Block)i5, 1, (OOC_X86_SSA__Result)i4, (OOC_X86_SSA__Result)i3);
          instr = (OOC_X86_SSA__Instr)i3;
          i3 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AddResult((OOC_X86_SSA__Instr)i3, 9);
          adr = (OOC_X86_SSA__Result)i3;
          i4 = *(OOC_UINT8*)((_check_pointer(i1, 29320))+60);
          if (i4) goto l137;
          i1=0u;
          goto l143;
l137:
          i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 29398))+48);
          i4 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 29404)))), &_td_OOC_SymbolTable__ArrayDesc);
          if (i4) goto l140;
          i1 = *(OOC_UINT8*)((_check_pointer(i1, 29445))+61);
          i1 = !i1;
          
          goto l143;
l140:
          i1=1u;
l143:
          if (i1) goto l145;
          i1=i3;
          goto l148;
l145:
          i1 = (OOC_INT32)b;
          i1 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr1((OOC_X86_SSA__Block)i1, 34, (OOC_X86_SSA__Result)i3);
          instr = (OOC_X86_SSA__Instr)i1;
          i1 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AddResult((OOC_X86_SSA__Instr)i1, 9);
          adr = (OOC_X86_SSA__Result)i1;
          
          goto l148;
l147:
          i1 = (OOC_INT32)b;
          i1 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddAdr((OOC_X86_SSA__Block)i1, (OOC_X86_SSA__Global)i2);
          adr = (OOC_X86_SSA__Result)i1;
          
l148:
          i3 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_SSA__Designator.baseTypes[0], 1);
          designator = (OOC_X86_SSA__Designator)i3;
          i4 = _check_pointer(i3, 29706);
          i5 = OOC_ARRAY_LENGTH(i4, 0);
          *(OOC_INT32*)(i4+(_check_index(0, i5, OOC_UINT8, 29706))*4) = i2;
          i2 = (OOC_INT32)b;
          i1 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr1((OOC_X86_SSA__Block)i2, 34, (OOC_X86_SSA__Result)i1);
          instr = (OOC_X86_SSA__Instr)i1;
          OOC_X86_SSA__InstrDesc_SetDesignator((OOC_X86_SSA__Instr)i1, (OOC_X86_SSA__Designator)i3);
          OOC_X86_Translate__Translate_MemoryCP((OOC_X86_SSA__Instr)i1);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 29873))+4);
          i0 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AddResultExpr((OOC_X86_SSA__Instr)i1, (OOC_SymbolTable__Type)i0);
          return (OOC_X86_SSA__Result)i0;
          goto l158;
l150:
          i1 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_SSA__Proc.baseTypes[0]);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 28739))+8);
          OOC_X86_SSA__ProcDesc_INIT((OOC_X86_SSA__Proc)i1, (OOC_SymbolTable__ProcDecl)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 28749)))), &_td_OOC_SymbolTable__ProcDeclDesc, 28749)));
          i0 = (OOC_INT32)b;
          i0 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddAdr((OOC_X86_SSA__Block)i0, (OOC_X86_SSA__Global)i1);
          return (OOC_X86_SSA__Result)i0;
          goto l158;
l152:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 28272))+4);
          i1 = *(OOC_INT16*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 28282)))), &_td_OOC_SymbolTable__PredefTypeDesc, 28282)), 28293))+40);
          typeId = i1;
          switch (i1) {
          case 0:
            i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 28389))+8);
            i0 = *(OOC_UINT8*)(_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 28402)))), &_td_Object_Boxed__BooleanDesc, 28402)), 28410));
            i1 = (OOC_INT32)b;
            i0 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddConstBool((OOC_X86_SSA__Block)i1, i0);
            return (OOC_X86_SSA__Result)i0;
            goto l158;
          case 13 ... 15:
            i2 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_SSA__Const.baseTypes[0]);
            i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 28541))+4);
            i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 28520))+8);
            OOC_X86_SSA__ConstDesc_INIT((OOC_X86_SSA__Const)i2, (Object__Object)i0, i1);
            i0 = (OOC_INT32)b;
            i0 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddConst((OOC_X86_SSA__Block)i0, (OOC_X86_SSA__Const)i2, (OOC_SymbolTable__Type)i3);
            return (OOC_X86_SSA__Result)i0;
            goto l158;
          default:
            i1 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_SSA__Const.baseTypes[0]);
            i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 28628))+4);
            i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 28611))+8);
            OOC_X86_SSA__ConstDesc_INIT((OOC_X86_SSA__Const)i1, (Object__Object)i0, (-1));
            i0 = (OOC_INT32)b;
            i0 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddConst((OOC_X86_SSA__Block)i0, (OOC_X86_SSA__Const)i1, (OOC_SymbolTable__Type)i2);
            return (OOC_X86_SSA__Result)i0;
            goto l158;
          }
l158:
          _failed_function(14213); return 0;
          ;
        }

        
        void OOC_X86_Translate__Translate_StatmSeq_Assign(OOC_X86_SSA__Result getInstr, OOC_X86_SSA__Result newValue) {
          register OOC_INT32 i0,i1,i2;

          i0 = (OOC_INT32)getInstr;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 37150))+4);
          i2 = (OOC_INT32)memoryCP;
          _assert((i2==i1), 127, 37124);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 37175))+4);
          OOC_X86_SSA__InstrDesc_SetOpcode((OOC_X86_SSA__Instr)i1, 35);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 37216))+4);
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
              cmpClass = 18;
              i0=18;
              goto l4;
l3:
              cmpClass = 16;
              i0=16;
l4:
              i1 = (OOC_INT32)statm;
              i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 37874))+8);
              i1 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression((OOC_IR__Expression)i1);
              i2 = (OOC_INT32)b;
              i3 = (OOC_INT32)bound;
              i0 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr2((OOC_X86_SSA__Block)i2, i0, (OOC_X86_SSA__Result)i1, (OOC_X86_SSA__Result)i3);
              i0 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AddResultReg((OOC_X86_SSA__Instr)i0, 0, 2);
              return (OOC_X86_SSA__Result)i0;
              ;
            }


          i0 = (OOC_INT32)statm;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 38370))+16);
          i1 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression((OOC_IR__Expression)i1);
          endValue = (OOC_X86_SSA__Result)i1;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 38414))+20);
          i2 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression((OOC_IR__Expression)i2);
          stepValue = (OOC_X86_SSA__Result)i2;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 38451))+8);
          i2 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression((OOC_IR__Expression)i2);
          v = (OOC_X86_SSA__Result)i2;
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 38492))+12);
          i0 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression((OOC_IR__Expression)i0);
          OOC_X86_Translate__Translate_StatmSeq_Assign((OOC_X86_SSA__Result)i2, (OOC_X86_SSA__Result)i0);
          i0 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_LoopStart();
          loopStart = (OOC_X86_SSA__LoopStartInstr)i0;
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
          i1 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr0((OOC_X86_SSA__Block)i1, 54);
          instr = (OOC_X86_SSA__Instr)i1;
          OOC_X86_Translate__Translate_ControlCP((OOC_X86_SSA__Instr)i1);
          OOC_X86_Translate__Translate_MemoryCP((OOC_X86_SSA__Instr)i1);
          i2 = (OOC_INT32)loopExits;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 39050)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i2, (Object__Object)i1);
          i1 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_AddJump();
          endFalse = (OOC_X86_SSA__Instr)i1;
          i2 = (OOC_INT32)b;
          i0 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddMerge2((OOC_X86_SSA__Block)i2, 48, (OOC_X86_SSA__Instr)i0, (OOC_X86_SSA__Instr)i1);
          merge = (OOC_X86_SSA__MergeInstr)i0;
          controlCP = (OOC_X86_SSA__Instr)i0;
          memoryCP = (OOC_X86_SSA__Instr)i0;
          i0 = (OOC_INT32)statm;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 39292))+24);
          OOC_X86_Translate__Translate_StatmSeq((OOC_IR__StatementSeq)i1);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 39329))+8);
          i1 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression((OOC_IR__Expression)i1);
          v = (OOC_X86_SSA__Result)i1;
          i2 = (OOC_INT32)b;
          i3 = (OOC_INT32)stepValue;
          i2 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr2((OOC_X86_SSA__Block)i2, 1, (OOC_X86_SSA__Result)i1, (OOC_X86_SSA__Result)i3);
          instr = (OOC_X86_SSA__Instr)i2;
          i1 = *(OOC_INT8*)((_check_pointer(i1, 39442))+12);
          i1 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AddResult((OOC_X86_SSA__Instr)i2, i1);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 39418))+8);
          i0 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression((OOC_IR__Expression)i0);
          OOC_X86_Translate__Translate_StatmSeq_Assign((OOC_X86_SSA__Result)i0, (OOC_X86_SSA__Result)i1);
          i0 = (OOC_INT32)loopStart;
          OOC_X86_Translate__Translate_StatmSeq_LoopEnd((OOC_X86_SSA__LoopStartInstr)i0);
          return;
          ;
        }

        
        void OOC_X86_Translate__Translate_StatmSeq_CaseStatm(OOC_IR__CaseStatm statm) {
          register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7;
          OOC_X86_SSA__Result select;
          OOC_X86_SSA__Instr jump;
          OOC_X86_SSA__BranchInstr branch;
          OOC_X86_SSA__Instr branchControl;
          OOC_X86_SSA__Instr branchMemory;
          ADT_ArrayList__ArrayList jumps;
          ADT_ArrayList__ArrayList paths;
          OOC_INT32 i;
          OOC_X86_SSA__Block guard;
          OOC_X86_SSA__MergeInstr merge;
          auto void OOC_X86_Translate__Translate_StatmSeq_CaseStatm_Labels(OOC_X86_SSA__Instr guard, OOC_IR__CaseLabels labels);
            
            void OOC_X86_Translate__Translate_StatmSeq_CaseStatm_Labels(OOC_X86_SSA__Instr guard, OOC_IR__CaseLabels labels) {
              register OOC_INT32 i0,i1,i2,i3,i4,i5;
              OOC_INT32 i;
              OOC_IR__Expression l;
              OOC_X86_SSA__Result value;

              i0 = (OOC_INT32)labels;
              i = 0;
              i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 40046)), 0);
              i2 = 0<i1;
              if (!i2) goto l12;
              i2 = (OOC_INT32)guard;
              i3=0;
l3_loop:
              i4 = _check_pointer(i0, 40077);
              i5 = OOC_ARRAY_LENGTH(i4, 0);
              i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 40077))*4);
              l = (OOC_IR__Expression)i4;
              i5 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 40100)))), &_td_OOC_IR__SetRangeDesc);
              if (i5) goto l6;
              i4 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression((OOC_IR__Expression)i4);
              value = (OOC_X86_SSA__Result)i4;
              OOC_X86_SSA__InstrDesc_AddOpnd((OOC_X86_SSA__Instr)i2, (OOC_X86_SSA__Result)i4);
              OOC_X86_SSA__InstrDesc_AddOpnd((OOC_X86_SSA__Instr)i2, (OOC_X86_SSA__Result)i4);
              goto l7;
l6:
              i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 40158))+8);
              i5 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression((OOC_IR__Expression)i5);
              OOC_X86_SSA__InstrDesc_AddOpnd((OOC_X86_SSA__Instr)i2, (OOC_X86_SSA__Result)i5);
              i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 40208))+12);
              i4 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression((OOC_IR__Expression)i4);
              OOC_X86_SSA__InstrDesc_AddOpnd((OOC_X86_SSA__Instr)i2, (OOC_X86_SSA__Result)i4);
l7:
              i3 = i3+1;
              i = i3;
              i4 = i3<i1;
              if (i4) goto l3_loop;
l12:
              return;
              ;
            }


          i0 = (OOC_INT32)statm;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 40447))+8);
          i1 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression((OOC_IR__Expression)i1);
          select = (OOC_X86_SSA__Result)i1;
          i2 = (OOC_INT32)sp;
          i3 = (OOC_INT32)b;
          i3 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddAdrRT((OOC_X86_SSA__Block)i3, (Object__String)((OOC_INT32)_c5));
          i4 = (OOC_INT32)b;
          i2 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr2((OOC_X86_SSA__Block)i4, 29, (OOC_X86_SSA__Result)i3, (OOC_X86_SSA__Result)i2);
          jump = (OOC_X86_SSA__Instr)i2;
          OOC_X86_Translate__Translate_MemoryCP((OOC_X86_SSA__Instr)i2);
          i3 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AddResult((OOC_X86_SSA__Instr)i2, 9);
          i4 = (OOC_INT32)b;
          i3 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddBranch((OOC_X86_SSA__Block)i4, (OOC_X86_SSA__Result)i3, 1u);
          branch = (OOC_X86_SSA__BranchInstr)i3;
          i4 = (OOC_INT32)controlCP;
          OOC_X86_SSA__InstrDesc_AddDep((OOC_X86_SSA__Instr)i3, 0, (OOC_X86_SSA__Instr)i4);
          branchControl = (OOC_X86_SSA__Instr)i3;
          i4 = (OOC_INT32)memoryCP;
          branchMemory = (OOC_X86_SSA__Instr)i4;
          i5 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_SSA__Const.baseTypes[0]);
          OOC_X86_SSA__ConstDesc_INIT((OOC_X86_SSA__Const)i5, (Object__Object)i3, 6);
          i3 = (OOC_INT32)b;
          i3 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddConstType((OOC_X86_SSA__Block)i3, (OOC_X86_SSA__Const)i5, 9);
          OOC_X86_SSA__InstrDesc_AddOpnd((OOC_X86_SSA__Instr)i2, (OOC_X86_SSA__Result)i3);
          OOC_X86_SSA__InstrDesc_AddOpnd((OOC_X86_SSA__Instr)i2, (OOC_X86_SSA__Result)i1);
          i1 = (OOC_INT32)RT0__NewObject(_td__qtd1.baseTypes[0]);
          ADT_ArrayList__ArrayListDesc_INIT((ADT_ArrayList__ArrayList)i1, 8);
          jumps = (ADT_ArrayList__ArrayList)i1;
          i2 = (OOC_INT32)RT0__NewObject(_td__qtd3.baseTypes[0]);
          ADT_ArrayList__ArrayListDesc_INIT((ADT_ArrayList__ArrayList)i2, 8);
          paths = (ADT_ArrayList__ArrayList)i2;
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 41054))+12);
          i = 0;
          i3 = OOC_ARRAY_LENGTH((_check_pointer(i3, 41063)), 0);
          i5 = 0<i3;
          if (i5) goto l3;
          i3=i1;i1=i2;i2=i4;
          goto l13;
l3:
          i5=i1;i1=0;
l4_loop:
          i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 41094))+12);
          i6 = _check_pointer(i6, 41103);
          i7 = OOC_ARRAY_LENGTH(i6, 0);
          i6 = (OOC_INT32)*(OOC_INT32*)(i6+(_check_index(i1, i7, OOC_UINT32, 41103))*4);
          i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i6, 41106))+8);
          i6 = OOC_ARRAY_LENGTH((_check_pointer(i6, 41113)), 0);
          i6 = i6!=0;
          if (!i6) goto l8;
          i2 = (OOC_INT32)b;
          i2 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddMerge0((OOC_X86_SSA__Block)i2, 47, (OOC_X86_SSA__Result)(OOC_INT32)0);
          guard = (OOC_X86_SSA__Block)i2;
          i4 = (OOC_INT32)branch;
          OOC_X86_SSA__InstrDesc_AddDep((OOC_X86_SSA__Instr)i2, 0, (OOC_X86_SSA__Instr)i4);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 41323))+12);
          i0 = _check_pointer(i0, 41332);
          i4 = OOC_ARRAY_LENGTH(i0, 0);
          i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(i1, i4, OOC_UINT32, 41332))*4);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 41335))+8);
          OOC_X86_Translate__Translate_StatmSeq_CaseStatm_Labels((OOC_X86_SSA__Instr)i2, (OOC_IR__CaseLabels)i0);
          i0 = (OOC_INT32)paths;
          i1 = (OOC_INT32)guard;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 41362)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i0, (Object__Object)i1);
          controlCP = (OOC_X86_SSA__Instr)i1;
          i1 = (OOC_INT32)branchMemory;
          memoryCP = (OOC_X86_SSA__Instr)i1;
          i2 = (OOC_INT32)statm;
          i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 41475))+12);
          i4 = _check_pointer(i4, 41484);
          i5 = OOC_ARRAY_LENGTH(i4, 0);
          i6 = i;
          i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i6, i5, OOC_UINT32, 41484))*4);
          i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 41487))+12);
          OOC_X86_Translate__Translate_StatmSeq((OOC_IR__StatementSeq)i4);
          i4 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_AddJump();
          i5 = (OOC_INT32)jumps;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 41516)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i5, (Object__Object)i4);
          i4=i1;i1=i6;{register OOC_INT32 h0=i0;i0=i2;i2=h0;}
l8:
          i1 = i1+1;
          i = i1;
          i6 = i1<i3;
          if (i6) goto l4_loop;
l12:
          i1=i2;i3=i5;i2=i4;
l13:
          i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 41582))+16);
          i5 = (OOC_INT32)branch;
          i4 = i4!=(OOC_INT32)0;
          if (i4) goto l19;
          i4 = *(OOC_UINT8*)((_check_pointer(i0, 41889))+20);
          if (!i4) goto l20;
          i4 = (OOC_INT32)b;
          i4 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddMerge0((OOC_X86_SSA__Block)i4, 47, (OOC_X86_SSA__Result)(OOC_INT32)0);
          guard = (OOC_X86_SSA__Block)i4;
          OOC_X86_SSA__InstrDesc_AddDep((OOC_X86_SSA__Instr)i4, 0, (OOC_X86_SSA__Instr)i5);
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 42013)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i1, (Object__Object)i4);
          controlCP = (OOC_X86_SSA__Instr)i4;
          memoryCP = (OOC_X86_SSA__Instr)i2;
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 42154));
          i0 = *(OOC_INT32*)((_check_pointer(i0, 42158))+16);
          i2 = (OOC_INT32)select;
          OOC_X86_Translate__Translate_FailedCheck((Object__String)((OOC_INT32)_c6), i0, (OOC_X86_SSA__Result)i2);
          i0 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_AddJump();
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 42188)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i3, (Object__Object)i0);
          goto l20;
l19:
          i4 = (OOC_INT32)b;
          i4 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddMerge0((OOC_X86_SSA__Block)i4, 47, (OOC_X86_SSA__Result)(OOC_INT32)0);
          guard = (OOC_X86_SSA__Block)i4;
          OOC_X86_SSA__InstrDesc_AddDep((OOC_X86_SSA__Instr)i4, 0, (OOC_X86_SSA__Instr)i5);
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 41710)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i1, (Object__Object)i4);
          controlCP = (OOC_X86_SSA__Instr)i4;
          memoryCP = (OOC_X86_SSA__Instr)i2;
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 41824))+16);
          OOC_X86_Translate__Translate_StatmSeq((OOC_IR__StatementSeq)i0);
          i0 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_AddJump();
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 41850)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i3, (Object__Object)i0);
l20:
          i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 42331)))), ADT_ArrayList__ArrayListDesc_Elements)),ADT_ArrayList__ArrayListDesc_Elements)((ADT_ArrayList__ArrayList)i3);
          i2 = (OOC_INT32)b;
          i0 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddMerge((OOC_X86_SSA__Block)i2, 48, (Object__ObjectArrayPtr)i0);
          merge = (OOC_X86_SSA__MergeInstr)i0;
          i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 42374)))), ADT_ArrayList__ArrayListDesc_Elements)),ADT_ArrayList__ArrayListDesc_Elements)((ADT_ArrayList__ArrayList)i1);
          OOC_X86_SSA__BranchInstrDesc_SetPaths((OOC_X86_SSA__BranchInstr)i5, (Object__ObjectArrayPtr)i1);
          controlCP = (OOC_X86_SSA__Instr)i0;
          memoryCP = (OOC_X86_SSA__Instr)i0;
          return;
          ;
        }


      i0 = (OOC_INT32)statmSeq;
      i0 = _check_pointer(i0, 42498);
      i1 = OOC_ARRAY_LENGTH(i0, 0);
      i1 = i0+i1*4;
      i2 = i1!=i0;
      if (!i2) goto l93;
      i2 = (OOC_INT32)_c7;
      i3 = (OOC_INT32)_c8;
      i4 = (OOC_INT32)_c9;
      
l3_loop:
      i5 = (OOC_INT32)*(OOC_INT32*)i0;
      statm = (OOC_IR__Statement)i5;
      i6 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 42521)))), &_td_OOC_IR__AssignmentDesc);
      if (i6) goto l87;
      i6 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 42731)))), &_td_OOC_IR__CopyDesc);
      if (i6) goto l85;
      i6 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 42782)))), &_td_OOC_IR__MoveBlockDesc);
      if (i6) goto l83;
      i6 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 42854)))), &_td_OOC_IR__IfStatmDesc);
      if (i6) goto l78;
      i6 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 43641)))), &_td_OOC_IR__WithStatmDesc);
      if (i6) goto l69;
      i6 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 44633)))), &_td_OOC_IR__CaseStatmDesc);
      if (i6) goto l67;
      i6 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 44705)))), &_td_OOC_IR__ReturnDesc);
      if (i6) goto l56;
      i6 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 45436)))), &_td_OOC_IR__LoopStatmDesc);
      if (i6) goto l54;
      i6 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 45578)))), &_td_OOC_IR__RepeatStatmDesc);
      if (i6) goto l52;
      i6 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 46598)))), &_td_OOC_IR__WhileStatmDesc);
      if (i6) goto l50;
      i6 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 47637)))), &_td_OOC_IR__ForStatmDesc);
      if (i6) goto l48;
      i6 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 47707)))), &_td_OOC_IR__ExitDesc);
      if (i6) goto l46;
      i6 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 47870)))), &_td_OOC_IR__CallDesc);
      if (i6) goto l44;
      i6 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 47929)))), &_td_OOC_IR__AssertDesc);
      if (i6) goto l35;
      i6 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 49027)))), &_td_OOC_IR__CopyParameterDesc);
      if (i6) goto l88;
      _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 49020)))), 49020);
      goto l88;
l35:
      i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 47963))+8);
      i6 = i6==(OOC_INT32)0;
      if (i6) goto l41;
      i6 = *(OOC_UINT8*)((_check_pointer(i5, 48195))+16);
      i6 = !i6;
      if (!i6) goto l88;
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 48245))+8);
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
      i6 = *(OOC_INT32*)((_check_pointer(i5, 48766))+12);
      i7 = (OOC_INT32)b;
      i6 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddConstLength((OOC_X86_SSA__Block)i7, i6);
      i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i5, 48710));
      i5 = *(OOC_INT32*)((_check_pointer(i5, 48714))+16);
      OOC_X86_Translate__Translate_FailedCheck((Object__String)i2, i5, (OOC_X86_SSA__Result)i6);
      i5 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_AddJump();
      endFalse = (OOC_X86_SSA__Instr)i5;
      i6 = (OOC_INT32)endTrue;
      i7 = (OOC_INT32)b;
      i5 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddMerge2((OOC_X86_SSA__Block)i7, 48, (OOC_X86_SSA__Instr)i6, (OOC_X86_SSA__Instr)i5);
      merge = (OOC_X86_SSA__MergeInstr)i5;
      controlCP = (OOC_X86_SSA__Instr)i5;
      memoryCP = (OOC_X86_SSA__Instr)i5;
      goto l88;
l41:
      i6 = (OOC_INT32)b;
      i7 = (OOC_INT32)sp;
      i6 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddAdrRT((OOC_X86_SSA__Block)i6, (Object__String)i3);
      i8 = (OOC_INT32)b;
      i6 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr2((OOC_X86_SSA__Block)i8, 29, (OOC_X86_SSA__Result)i6, (OOC_X86_SSA__Result)i7);
      instr = (OOC_X86_SSA__Instr)i6;
      i5 = *(OOC_INT32*)((_check_pointer(i5, 48105))+12);
      i7 = (OOC_INT32)b;
      i5 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddConstLength((OOC_X86_SSA__Block)i7, i5);
      OOC_X86_SSA__InstrDesc_AddOpnd((OOC_X86_SSA__Instr)i6, (OOC_X86_SSA__Result)i5);
      OOC_X86_Translate__Translate_MemoryCP((OOC_X86_SSA__Instr)i6);
      OOC_X86_Translate__Translate_ControlCP((OOC_X86_SSA__Instr)i6);
      goto l88;
l44:
      i5 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Call((OOC_IR__Call)i5);
      res = (OOC_X86_SSA__Result)i5;
      goto l88;
l46:
      i5 = (OOC_INT32)b;
      i5 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr0((OOC_X86_SSA__Block)i5, 54);
      instr = (OOC_X86_SSA__Instr)i5;
      OOC_X86_Translate__Translate_ControlCP((OOC_X86_SSA__Instr)i5);
      OOC_X86_Translate__Translate_MemoryCP((OOC_X86_SSA__Instr)i5);
      i6 = (OOC_INT32)loopExits;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 47828)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i6, (Object__Object)i5);
      goto l88;
l48:
      OOC_X86_Translate__Translate_StatmSeq_ForStatm((OOC_IR__ForStatm)i5);
      goto l88;
l50:
      i5 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_LoopStart();
      loopStart = (OOC_X86_SSA__LoopStartInstr)i5;
      i5 = (OOC_INT32)statm;
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 46834))+8);
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
      i5 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr0((OOC_X86_SSA__Block)i5, 54);
      instr = (OOC_X86_SSA__Instr)i5;
      OOC_X86_Translate__Translate_ControlCP((OOC_X86_SSA__Instr)i5);
      OOC_X86_Translate__Translate_MemoryCP((OOC_X86_SSA__Instr)i5);
      i6 = (OOC_INT32)loopExits;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 47329)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i6, (Object__Object)i5);
      i5 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_AddJump();
      endFalse = (OOC_X86_SSA__Instr)i5;
      i6 = (OOC_INT32)endTrue;
      i7 = (OOC_INT32)b;
      i5 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddMerge2((OOC_X86_SSA__Block)i7, 48, (OOC_X86_SSA__Instr)i6, (OOC_X86_SSA__Instr)i5);
      merge = (OOC_X86_SSA__MergeInstr)i5;
      controlCP = (OOC_X86_SSA__Instr)i5;
      memoryCP = (OOC_X86_SSA__Instr)i5;
      i5 = (OOC_INT32)statm;
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 47583))+12);
      OOC_X86_Translate__Translate_StatmSeq((OOC_IR__StatementSeq)i5);
      i5 = (OOC_INT32)loopStart;
      OOC_X86_Translate__Translate_StatmSeq_LoopEnd((OOC_X86_SSA__LoopStartInstr)i5);
      goto l88;
l52:
      i5 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_LoopStart();
      loopStart = (OOC_X86_SSA__LoopStartInstr)i5;
      i5 = (OOC_INT32)statm;
      i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 45757))+8);
      OOC_X86_Translate__Translate_StatmSeq((OOC_IR__StatementSeq)i6);
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 45809))+12);
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
      i5 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr0((OOC_X86_SSA__Block)i5, 54);
      instr = (OOC_X86_SSA__Instr)i5;
      OOC_X86_Translate__Translate_ControlCP((OOC_X86_SSA__Instr)i5);
      OOC_X86_Translate__Translate_MemoryCP((OOC_X86_SSA__Instr)i5);
      i6 = (OOC_INT32)loopExits;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 46175)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i6, (Object__Object)i5);
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
      i5 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddMerge2((OOC_X86_SSA__Block)i7, 48, (OOC_X86_SSA__Instr)i6, (OOC_X86_SSA__Instr)i5);
      merge = (OOC_X86_SSA__MergeInstr)i5;
      controlCP = (OOC_X86_SSA__Instr)i5;
      memoryCP = (OOC_X86_SSA__Instr)i5;
      i5 = (OOC_INT32)loopStart;
      OOC_X86_Translate__Translate_StatmSeq_LoopEnd((OOC_X86_SSA__LoopStartInstr)i5);
      goto l88;
l54:
      i5 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_LoopStart();
      loopStart = (OOC_X86_SSA__LoopStartInstr)i5;
      i6 = (OOC_INT32)statm;
      i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i6, 45514))+8);
      OOC_X86_Translate__Translate_StatmSeq((OOC_IR__StatementSeq)i6);
      OOC_X86_Translate__Translate_StatmSeq_LoopEnd((OOC_X86_SSA__LoopStartInstr)i5);
      goto l88;
l56:
      i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 44753))+8);
      i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i6, 44760))+4);
      i6 = OOC_X86_SSA__MapType((OOC_SymbolTable__Type)i6);
      type = i6;
      switch (i6) {
      case 10:
      case 11:
        
        goto l61;
      case 5 ... 8:
        type = 7;
        i6=7;
        goto l61;
      default:
        type = 3;
        i6=3;
        goto l61;
      }
l61:
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 45040))+8);
      i5 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression((OOC_IR__Expression)i5);
      i7 = (OOC_INT32)b;
      i5 = (OOC_INT32)OOC_X86_SSA__FunctionBlockDesc_FixType((OOC_X86_SSA__FunctionBlock)i7, (OOC_X86_SSA__Result)i5, i6);
      i6 = (OOC_INT32)b;
      i5 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr1((OOC_X86_SSA__Block)i6, 28, (OOC_X86_SSA__Result)i5);
      instr = (OOC_X86_SSA__Instr)i5;
      OOC_X86_Translate__Translate_ControlCP((OOC_X86_SSA__Instr)i5);
      OOC_X86_Translate__Translate_MemoryCP((OOC_X86_SSA__Instr)i5);
      i6 = type;
      i7 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AddResult((OOC_X86_SSA__Instr)i5, i6);
      res = (OOC_X86_SSA__Result)i7;
      *(OOC_INT8*)((_check_pointer(i7, 45202))+14) = 0;
      i6 = i6>=10;
      if (i6) goto l64;
      *(OOC_INT8*)((_check_pointer(i7, 45341))+13) = 3;
      goto l65;
l64:
      *(OOC_INT8*)((_check_pointer(i7, 45278))+13) = 9;
l65:
      i6 = (OOC_INT32)returns;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 45404)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i6, (Object__Object)i5);
      goto l88;
l67:
      OOC_X86_Translate__Translate_StatmSeq_CaseStatm((OOC_IR__CaseStatm)i5);
      goto l88;
l69:
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 43692))+8);
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
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 43966))+12);
      OOC_X86_Translate__Translate_StatmSeq((OOC_IR__StatementSeq)i5);
      i5 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_AddJump();
      endTrue = (OOC_X86_SSA__Instr)i5;
      i5 = (OOC_INT32)memoryFalse;
      memoryCP = (OOC_X86_SSA__Instr)i5;
      i5 = (OOC_INT32)controlFalse;
      controlCP = (OOC_X86_SSA__Instr)i5;
      i5 = (OOC_INT32)statm;
      i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 44124))+16);
      i6 = i6!=(OOC_INT32)0;
      if (i6) goto l75;
      i6 = *(OOC_UINT8*)((_check_pointer(i5, 44207))+20);
      if (!i6) goto l76;
      i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 44251))+8);
      i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i6, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 44261)))), &_td_OOC_IR__TypeTestDesc, 44261)), 44270))+8);
      irExpr = (OOC_IR__Expression)i6;
      i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i5, 44323));
      i5 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_TypeTag((OOC_IR__Expression)i6, 1u, (OOC_Scanner_SymList__Symbol)i5);
      res = (OOC_X86_SSA__Result)i5;
      i6 = (OOC_INT32)statm;
      i6 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i6, 44383));
      i6 = *(OOC_INT32*)((_check_pointer(i6, 44387))+16);
      OOC_X86_Translate__Translate_FailedCheck((Object__String)i4, i6, (OOC_X86_SSA__Result)i5);
      goto l76;
l75:
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 44173))+16);
      OOC_X86_Translate__Translate_StatmSeq((OOC_IR__StatementSeq)i5);
l76:
      i5 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_AddJump();
      endFalse = (OOC_X86_SSA__Instr)i5;
      i6 = (OOC_INT32)endTrue;
      i7 = (OOC_INT32)b;
      i5 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddMerge2((OOC_X86_SSA__Block)i7, 48, (OOC_X86_SSA__Instr)i6, (OOC_X86_SSA__Instr)i5);
      merge = (OOC_X86_SSA__MergeInstr)i5;
      controlCP = (OOC_X86_SSA__Instr)i5;
      memoryCP = (OOC_X86_SSA__Instr)i5;
      goto l88;
l78:
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 42903))+8);
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
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 43177))+12);
      OOC_X86_Translate__Translate_StatmSeq((OOC_IR__StatementSeq)i5);
      i5 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_AddJump();
      endTrue = (OOC_X86_SSA__Instr)i5;
      i5 = (OOC_INT32)memoryFalse;
      memoryCP = (OOC_X86_SSA__Instr)i5;
      i5 = (OOC_INT32)controlFalse;
      controlCP = (OOC_X86_SSA__Instr)i5;
      i5 = (OOC_INT32)statm;
      i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 43335))+16);
      i6 = i6!=(OOC_INT32)0;
      if (!i6) goto l81;
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 43384))+16);
      OOC_X86_Translate__Translate_StatmSeq((OOC_IR__StatementSeq)i5);
l81:
      i5 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_AddJump();
      endFalse = (OOC_X86_SSA__Instr)i5;
      i6 = (OOC_INT32)endTrue;
      i7 = (OOC_INT32)b;
      i5 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddMerge2((OOC_X86_SSA__Block)i7, 48, (OOC_X86_SSA__Instr)i6, (OOC_X86_SSA__Instr)i5);
      merge = (OOC_X86_SSA__MergeInstr)i5;
      controlCP = (OOC_X86_SSA__Instr)i5;
      memoryCP = (OOC_X86_SSA__Instr)i5;
      goto l88;
l83:
      OOC_X86_Translate__Translate_StatmSeq_MoveBlock((OOC_IR__MoveBlock)i5);
      goto l88;
l85:
      OOC_X86_Translate__Translate_StatmSeq_Copy((OOC_IR__Copy)i5);
      goto l88;
l87:
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 42634))+12);
      i5 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression((OOC_IR__Expression)i5);
      res = (OOC_X86_SSA__Result)i5;
      i5 = (OOC_INT32)statm;
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 42676))+8);
      i5 = (OOC_INT32)OOC_X86_Translate__Translate_StatmSeq_Expression((OOC_IR__Expression)i5);
      var = (OOC_X86_SSA__Result)i5;
      i6 = (OOC_INT32)res;
      OOC_X86_Translate__Translate_StatmSeq_Assign((OOC_X86_SSA__Result)i5, (OOC_X86_SSA__Result)i6);
l88:
      i0 = i0+4;
      i5 = i1!=i0;
      if (i5) goto l3_loop;
l93:
      return;
      ;
    }

    
    void OOC_X86_Translate__Translate_FctProlog(OOC_X86_SSA__FunctionBlock b, OOC_IR__StatementSeq statmSeq) {
      register OOC_INT32 i0,i1,i2,i3;
      OOC_X86_SSA__Instr enter;
      OOC_X86_SSA__Instr pushFp;
      OOC_X86_SSA__Instr setFp;
      OOC_X86_SSA__Instr localVars;
      OOC_INT32 i;
      auto void OOC_X86_Translate__Translate_FctProlog_CopyParameter(OOC_IR__CopyParameter cp);
        
        void OOC_X86_Translate__Translate_FctProlog_CopyParameter(OOC_IR__CopyParameter cp) {
          register OOC_INT32 i0,i1,i2,i3,i4;
          OOC_SymbolTable__VarDecl var;
          OOC_SymbolTable__Type type;
          OOC_X86_SSA__Instr paramAdr;
          OOC_X86_SSA__Instr getAdr;
          OOC_X86_SSA__Result from;
          OOC_X86_SSA__Instr varAdr;
          OOC_X86_SSA__Result to;

          i0 = (OOC_INT32)cp;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 49499))+8);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 49505))+8);
          i1 = _type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 49515)))), &_td_OOC_SymbolTable__VarDeclDesc, 49515);
          var = (OOC_SymbolTable__VarDecl)i1;
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 49543))+8);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 49549))+4);
          type = (OOC_SymbolTable__Type)i0;
          i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 49573)))), &_td_OOC_SymbolTable__RecordDesc);
          if (i2) goto l6;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 50113)))), &_td_OOC_SymbolTable__ArrayDesc);
          if (i1) goto l7;
          _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 50107)))), 50107);
          goto l7;
l6:
          i2 = (OOC_INT32)b;
          i2 = OOC_X86_SSA__FunctionBlockDesc_Offset((OOC_X86_SSA__FunctionBlock)i2, (OOC_SymbolTable__VarDecl)i1, (-1));
          i3 = (OOC_INT32)b;
          i2 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddConstLength((OOC_X86_SSA__Block)i3, i2);
          i3 = (OOC_INT32)fp;
          i4 = (OOC_INT32)b;
          i2 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr2((OOC_X86_SSA__Block)i4, 1, (OOC_X86_SSA__Result)i3, (OOC_X86_SSA__Result)i2);
          paramAdr = (OOC_X86_SSA__Instr)i2;
          i2 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AddResult((OOC_X86_SSA__Instr)i2, 9);
          i3 = (OOC_INT32)b;
          i2 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr1((OOC_X86_SSA__Block)i3, 34, (OOC_X86_SSA__Result)i2);
          getAdr = (OOC_X86_SSA__Instr)i2;
          i2 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AddResult((OOC_X86_SSA__Instr)i2, 9);
          from = (OOC_X86_SSA__Result)i2;
          i3 = (OOC_INT32)b;
          OOC_X86_SSA__FunctionBlockDesc_AllocateLocalVar((OOC_X86_SSA__FunctionBlock)i3, (OOC_SymbolTable__VarDecl)i1);
          i3 = (OOC_INT32)b;
          i1 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddFramePointerOffset((OOC_X86_SSA__Block)i3, (OOC_SymbolTable__VarDecl)i1);
          i3 = (OOC_INT32)fp;
          i4 = (OOC_INT32)b;
          i1 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr2((OOC_X86_SSA__Block)i4, 1, (OOC_X86_SSA__Result)i3, (OOC_X86_SSA__Result)i1);
          varAdr = (OOC_X86_SSA__Instr)i1;
          i1 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AddResult((OOC_X86_SSA__Instr)i1, 9);
          to = (OOC_X86_SSA__Result)i1;
          i0 = *(OOC_INT32*)((_check_pointer(i0, 50057))+32);
          i3 = (OOC_INT32)b;
          i0 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddConstLength((OOC_X86_SSA__Block)i3, i0);
          OOC_X86_Translate__Translate_Memcpy((OOC_X86_SSA__Result)i2, (OOC_X86_SSA__Result)i1, (OOC_X86_SSA__Result)i0);
l7:
          return;
          ;
        }


      i0 = (OOC_INT32)b;
      i1 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr0((OOC_X86_SSA__Block)i0, 26);
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
      i1 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr2((OOC_X86_SSA__Block)i0, 39, (OOC_X86_SSA__Result)i2, (OOC_X86_SSA__Result)i1);
      pushFp = (OOC_X86_SSA__Instr)i1;
      i1 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AddResultReg((OOC_X86_SSA__Instr)i1, 9, 0);
      sp = (OOC_X86_SSA__Result)i1;
      i2 = *(OOC_INT8*)((_check_pointer(i1, 50531))+13);
      _assert((i2==0), 127, 50522);
      i1 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr1((OOC_X86_SSA__Block)i0, 36, (OOC_X86_SSA__Result)i1);
      setFp = (OOC_X86_SSA__Instr)i1;
      i2 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AddResultReg((OOC_X86_SSA__Instr)i1, 9, 1);
      fp = (OOC_X86_SSA__Result)i2;
      OOC_X86_Translate__Translate_MemoryCP((OOC_X86_SSA__Instr)i1);
      i1 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddFramePointerOffset((OOC_X86_SSA__Block)i0, (OOC_SymbolTable__VarDecl)(OOC_INT32)0);
      i2 = (OOC_INT32)sp;
      i0 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr2((OOC_X86_SSA__Block)i0, 32, (OOC_X86_SSA__Result)i2, (OOC_X86_SSA__Result)i1);
      localVars = (OOC_X86_SSA__Instr)i0;
      OOC_X86_Translate__Translate_ControlCP((OOC_X86_SSA__Instr)i0);
      OOC_X86_Translate__Translate_MemoryCP((OOC_X86_SSA__Instr)i0);
      i0 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AddResultReg((OOC_X86_SSA__Instr)i0, 9, 0);
      sp = (OOC_X86_SSA__Result)i0;
      i0 = *(OOC_INT8*)((_check_pointer(i0, 51079))+13);
      _assert((i0==0), 127, 51070);
      i = 0;
      i0 = (OOC_INT32)statmSeq;
      i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 51191)), 0);
      i1 = 0!=i1;
      if (i1) goto l3;
      i1=0u;
      goto l5;
l3:
      i1 = _check_pointer(i0, 51206);
      i2 = OOC_ARRAY_LENGTH(i1, 0);
      i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT32, 51206))*4);
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 51210)))), &_td_OOC_IR__CopyParameterDesc);
      
l5:
      if (!i1) goto l16;
      i1=0;
l7_loop:
      i0 = _check_pointer(i0, 51264);
      i2 = OOC_ARRAY_LENGTH(i0, 0);
      i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(i1, i2, OOC_UINT32, 51264))*4);
      OOC_X86_Translate__Translate_FctProlog_CopyParameter((OOC_IR__CopyParameter)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 51271)))), &_td_OOC_IR__CopyParameterDesc, 51271)));
      i0 = i;
      i0 = i0+1;
      i = i0;
      i1 = (OOC_INT32)statmSeq;
      i2 = OOC_ARRAY_LENGTH((_check_pointer(i1, 51191)), 0);
      i2 = i0!=i2;
      if (i2) goto l10;
      i2=0u;
      goto l12;
l10:
      i2 = _check_pointer(i1, 51206);
      i3 = OOC_ARRAY_LENGTH(i2, 0);
      i2 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(i0, i3, OOC_UINT32, 51206))*4);
      i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 51210)))), &_td_OOC_IR__CopyParameterDesc);
      
l12:
      if (!i2) goto l16;
      {register OOC_INT32 h0=i0;i0=i1;i1=h0;}
      goto l7_loop;
l16:
      return;
      ;
    }

    
    void OOC_X86_Translate__Translate_FctEpilog(OOC_X86_SSA__FunctionBlock b) {
      register OOC_INT32 i0,i1,i2,i3;
      OOC_X86_SSA__Instr leave;

      i0 = (OOC_INT32)b;
      i1 = *(OOC_UINT8*)((_check_pointer(i0, 51455))+80);
      if (!i1) goto l4;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 51530))+56);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 51539))+20);
      i1 = *(OOC_INT32*)(_check_pointer(i1, 51544));
      OOC_X86_Translate__Translate_FailedCheck((Object__String)((OOC_INT32)_c10), i1, (OOC_X86_SSA__Result)(OOC_INT32)0);
l4:
      i1 = (OOC_INT32)sp;
      i2 = (OOC_INT32)fp;
      i1 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr2((OOC_X86_SSA__Block)i0, 41, (OOC_X86_SSA__Result)i1, (OOC_X86_SSA__Result)i2);
      leave = (OOC_X86_SSA__Instr)i1;
      i2 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AddResultReg((OOC_X86_SSA__Instr)i1, 9, 0);
      sp = (OOC_X86_SSA__Result)i2;
      i1 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AddResultReg((OOC_X86_SSA__Instr)i1, 9, 1);
      fp = (OOC_X86_SSA__Result)i1;
      i1 = (OOC_INT32)returns;
      i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 51757)))), ADT_ArrayList__ArrayListDesc_Elements)),ADT_ArrayList__ArrayListDesc_Elements)((ADT_ArrayList__ArrayList)i1);
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
      i2 = *(OOC_UINT8*)((_check_pointer(i1, 51950))+12);
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 51942))+4);
      OOC_X86_SSA__FunctionBlockDesc_INIT((OOC_X86_SSA__FunctionBlock)i0, (OOC_SymbolTable__ProcDecl)i3, i2);
      b = (OOC_X86_SSA__FunctionBlock)i0;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 51993))+8);
      OOC_X86_Translate__Translate_FctProlog((OOC_X86_SSA__FunctionBlock)i0, (OOC_IR__StatementSeq)i2);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 52021))+8);
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
  loopExits = (ADT_ArrayList__ArrayList)(OOC_INT32)0;
  i0 = (OOC_INT32)symTab;
  i1 = (OOC_INT32)ch;
  i2 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_Write__Writer.baseTypes[0]);
  OOC_X86_Write__WriterDesc_INIT((OOC_X86_Write__Writer)i2, (OOC_SymbolTable__Module)i0, (IO__ByteChannel)i1);
  w = (OOC_X86_Write__Writer)i2;
  i0 = (OOC_INT32)moduleIR;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 52533))+8);
  i0 = _check_pointer(i0, 52542);
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
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 52598))+12);
  OOC_X86_Translate__Translate_Procedure((OOC_IR__Procedure)i0);
  i0 = (OOC_INT32)w;
  OOC_X86_Write__WriterDesc_EndFile((OOC_X86_Write__Writer)i0);
  return;
  ;
}

void OOC_OOC_X86_Translate_init(void) {
  _c0 = Object__NewLatin1Region("memcpy", 7, 0, 6);
  _c1 = Object__NewLatin1Region("RT0__ErrorFailedTypeAssert", 27, 0, 26);
  _c2 = Object__NewLatin1Region("memcpy", 7, 0, 6);
  _c3 = Object__NewLatin1Region("RT0__NewObject", 15, 0, 14);
  _c4 = Object__NewLatin1Region("RT0__TypeTest", 14, 0, 13);
  _c5 = Object__NewLatin1Region("RT0__ScanCaseRanges", 20, 0, 19);
  _c6 = Object__NewLatin1Region("RT0__ErrorFailedCase", 21, 0, 20);
  _c7 = Object__NewLatin1Region("RT0__ErrorAssertionFailed", 26, 0, 25);
  _c8 = Object__NewLatin1Region("RT0__Halt", 10, 0, 9);
  _c9 = Object__NewLatin1Region("RT0__ErrorFailedWith", 21, 0, 20);
  _c10 = Object__NewLatin1Region("RT0__ErrorFailedFunction", 25, 0, 24);

  return;
  ;
}

void OOC_OOC_X86_Translate_destroy(void) {
}

/* --- */
