#include <OOC/X86/ConstProp.oh>
#include <Object/Boxed.oh>
#include <Object/BigInt.oh>
typedef struct OOC_X86_ConstProp__WorklistDesc *OOC_X86_ConstProp__Worklist;
typedef struct OOC_X86_ConstProp__WorklistDesc {
  OOC_X86_ConstProp__Worklist next;
  OOC_X86_SSA__Instr instr;
} OOC_X86_ConstProp__WorklistDesc;
#define OOC_X86_ConstProp__unclassified  0
static OOC_X86_SSA__Result OOC_X86_ConstProp__notConstant;
static OOC_X86_SSA__Result OOC_X86_ConstProp__ComputeConst(OOC_X86_SSA__FunctionBlock pb, OOC_X86_SSA__Instr instr);

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_OOC_X86_ConstProp__Worklist = { (RT0__Struct[]){&_td_OOC_X86_ConstProp__WorklistDesc}, NULL, NULL, &_mid, "Worklist", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_X86_ConstProp__WorklistDesc = { (RT0__Struct[]){&_td_OOC_X86_ConstProp__WorklistDesc}, (void*[]){}, NULL, &_mid, "WorklistDesc", 8, 0, 0, RT0__strRecord };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:X86:ConstProp", (RT0__Struct[]) { &_td_OOC_X86_ConstProp__Worklist, &_td_OOC_X86_ConstProp__WorklistDesc, NULL } };

extern void OOC_OOC_X86_ConstProp_init0() {
  RT0__RegisterModule(&_mid);
  OOC_OOC_X86_ConstProp_init();
}

/* --- */
