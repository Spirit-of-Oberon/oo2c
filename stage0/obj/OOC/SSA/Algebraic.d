#include <OOC/SSA/Algebraic.oh>
#include <Object/Boxed.oh>
#include <Object/BigInt.oh>
#include <OOC/SSA/Opcode.oh>
#include <OOC/SSA/Opnd.oh>
typedef struct OOC_SSA_Algebraic__WorklistDesc *OOC_SSA_Algebraic__Worklist;
typedef struct OOC_SSA_Algebraic__WorklistDesc {
  OOC_SSA_Algebraic__Worklist next;
  OOC_SSA__Instr instr;
} OOC_SSA_Algebraic__WorklistDesc;
#define OOC_SSA_Algebraic__maxPower2 63
static Object_BigInt__BigInt OOC_SSA_Algebraic__intZero;
static Object_BigInt__BigInt OOC_SSA_Algebraic__intOne;
static Object_BigInt__BigInt OOC_SSA_Algebraic__intTwo;
static Object_BigInt__BigInt OOC_SSA_Algebraic__power2[64];
static OOC_INT32 OOC_SSA_Algebraic__IsPowerOf2(Object_BigInt__BigInt value);
static OOC_CHAR8 OOC_SSA_Algebraic__IsNMinus1(OOC_SSA__Result res);
static void OOC_SSA_Algebraic__Init(void);

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_OOC_SSA_Algebraic__Worklist = { (RT0__Struct[]){&_td_OOC_SSA_Algebraic__WorklistDesc}, NULL, NULL, &_mid, "Worklist", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_SSA_Algebraic__WorklistDesc = { (RT0__Struct[]){&_td_OOC_SSA_Algebraic__WorklistDesc}, (void*[]){}, NULL, &_mid, "WorklistDesc", 8, 0, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_SSA_Algebraic__1233 = { (RT0__Struct[]){&_td_Object_BigInt__BigInt}, NULL, NULL, &_mid, NULL, 256, 64, 0, RT0__strArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:SSA:Algebraic", (RT0__Struct[]) { &_td_OOC_SSA_Algebraic__Worklist, &_td_OOC_SSA_Algebraic__WorklistDesc, NULL }, 0 };

extern void OOC_OOC_SSA_Algebraic_open(RT0__Module client) {
  if (_mid.openCount == 0) {
    OOC_Object_Boxed_open(&_mid);
    OOC_Object_BigInt_open(&_mid);
    OOC_OOC_SSA_open(&_mid);
    OOC_OOC_SSA_Opcode_open(&_mid);
    OOC_OOC_SSA_Opnd_open(&_mid);
    OOC_RT0_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_Exception_open(&_mid);

    RT0__RegisterModule(&_mid);
    OOC_OOC_SSA_Algebraic_init();
  }
  _mid.openCount++;
}
extern void OOC_OOC_SSA_Algebraic_close(RT0__Module client) {
  _mid.openCount--;
  if (_mid.openCount == 0) { 
    OOC_OOC_SSA_Algebraic_destroy();
    RT0__UnregisterModule(&_mid);

    OOC_Object_Boxed_close(&_mid);
    OOC_Object_BigInt_close(&_mid);
    OOC_OOC_SSA_close(&_mid);
    OOC_OOC_SSA_Opcode_close(&_mid);
    OOC_OOC_SSA_Opnd_close(&_mid);
    OOC_RT0_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_Exception_close(&_mid);
  }
}

/* --- */
