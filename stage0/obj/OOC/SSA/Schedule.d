#include <OOC/SSA/Schedule.oh>
#include <OOC/SSA/Opcode.oh>
#include <OOC/SSA/Opnd.oh>
#include <OOC/SSA/Blocker.oh>
static void OOC_SSA_Schedule__InitBlock(OOC_SSA_Schedule__Block b, OOC_SSA_Schedule__Block dominator);
static void OOC_SSA_Schedule__RevertDomList(OOC_SSA_Schedule__Block b);
static void OOC_SSA_Schedule__ClearJump(OOC_SSA_Schedule__Jump reference);
static void OOC_SSA_Schedule__SetJump(OOC_SSA_Schedule__Jump *reference, OOC_SSA_Schedule__Block src, OOC_SSA_Schedule__Block dest);
static void OOC_SSA_Schedule__ChangeTargets(OOC_SSA_Schedule__Block oldTarget, OOC_SSA_Schedule__Block newTarget);
static void OOC_SSA_Schedule__InitBranchBlock(OOC_SSA_Schedule__BranchBlock b, OOC_SSA_Schedule__Block dominator, OOC_SSA__Opnd predicate, OOC_CHAR8 branchOnTrue);
static OOC_SSA_Schedule__BranchBlock OOC_SSA_Schedule__NewBranchBlock(OOC_SSA_Schedule__Block dominator, OOC_SSA__Opnd predicate, OOC_CHAR8 branchOnTrue);
static void OOC_SSA_Schedule__InitJumpBlock(OOC_SSA_Schedule__JumpBlock b, OOC_SSA_Schedule__Block dominator);
static OOC_SSA_Schedule__JumpBlock OOC_SSA_Schedule__NewJumpBlock(OOC_SSA_Schedule__Block dominator);
static void OOC_SSA_Schedule__InitDeadEndBlock(OOC_SSA_Schedule__DeadEndBlock b, OOC_SSA_Schedule__Block dominator);
static OOC_SSA_Schedule__DeadEndBlock OOC_SSA_Schedule__NewDeadEndBlock(OOC_SSA_Schedule__Block dominator);
static void OOC_SSA_Schedule__InitSwitchBlock(OOC_SSA_Schedule__SwitchBlock b, OOC_SSA_Schedule__Block dominator, OOC_SSA__Opnd expr, OOC_INT32 paths);
static OOC_SSA_Schedule__SwitchBlock OOC_SSA_Schedule__NewSwitchBlock(OOC_SSA_Schedule__Block dominator, OOC_SSA__Opnd expr, OOC_INT32 paths);
static void OOC_SSA_Schedule__InitInstrProxy(OOC_SSA_Schedule__InstrProxy proxy, OOC_SSA__Instr instr);
static OOC_SSA_Schedule__InstrProxy OOC_SSA_Schedule__NewInstrProxy(OOC_SSA__Instr instr);
static void OOC_SSA_Schedule__AppendProxy(OOC_SSA_Schedule__Block b, OOC_SSA_Schedule__InstrProxy proxy);
static OOC_SSA_Schedule__JumpBlock OOC_SSA_Schedule__TransferInstructions(OOC_SSA_Blocker__Region region, OOC_SSA_Schedule__JumpBlock block);

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_OOC_SSA_Schedule__Block = { (RT0__Struct[]){&_td_OOC_SSA_Schedule__BlockDesc}, NULL, NULL, &_mid, (OOC_CHAR8*)"Block", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_SSA_Schedule__InstrProxy = { (RT0__Struct[]){&_td_OOC_SSA_Schedule__InstrProxyDesc}, NULL, NULL, &_mid, (OOC_CHAR8*)"InstrProxy", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_SSA_Schedule__BranchBlock = { (RT0__Struct[]){&_td_OOC_SSA_Schedule__BranchBlockDesc}, NULL, NULL, &_mid, (OOC_CHAR8*)"BranchBlock", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_SSA_Schedule__JumpBlock = { (RT0__Struct[]){&_td_OOC_SSA_Schedule__JumpBlockDesc}, NULL, NULL, &_mid, (OOC_CHAR8*)"JumpBlock", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_SSA_Schedule__DeadEndBlock = { (RT0__Struct[]){&_td_OOC_SSA_Schedule__DeadEndBlockDesc}, NULL, NULL, &_mid, (OOC_CHAR8*)"DeadEndBlock", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_SSA_Schedule__SwitchBlock = { (RT0__Struct[]){&_td_OOC_SSA_Schedule__SwitchBlockDesc}, NULL, NULL, &_mid, (OOC_CHAR8*)"SwitchBlock", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_SSA_Schedule__Info = { (RT0__Struct[]){&_td_OOC_SSA_Schedule__InfoDesc}, NULL, NULL, &_mid, (OOC_CHAR8*)"Info", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_SSA_Schedule__InfoDesc = { (RT0__Struct[]){&_td_OOC_SSA_Schedule__InfoDesc}, (void*[]){}, NULL, &_mid, (OOC_CHAR8*)"InfoDesc", 0, 0, (1<<RT0__flagAtomic), RT0__strRecord };
RT0__StructDesc _td_OOC_SSA_Schedule__Dependent = { (RT0__Struct[]){&_td_OOC_SSA_Schedule__DependentDesc}, NULL, NULL, &_mid, (OOC_CHAR8*)"Dependent", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_SSA_Schedule__DependentDesc = { (RT0__Struct[]){&_td_OOC_SSA_Schedule__DependentDesc}, (void*[]){}, NULL, &_mid, (OOC_CHAR8*)"DependentDesc", 8, 0, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_SSA_Schedule__Jump = { (RT0__Struct[]){&_td_OOC_SSA_Schedule__JumpDesc}, NULL, NULL, &_mid, (OOC_CHAR8*)"Jump", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_SSA_Schedule__JumpDesc = { (RT0__Struct[]){&_td_OOC_SSA_Schedule__JumpDesc}, (void*[]){}, NULL, &_mid, (OOC_CHAR8*)"JumpDesc", 16, 0, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_SSA_Schedule__BlockDesc = { (RT0__Struct[]){&_td_RT0__ObjectDesc,&_td_Object__ObjectDesc,&_td_OOC_SSA_Schedule__BlockDesc}, (void*[]){(void*)RT0__ObjectDesc_Finalize,(void*)Object__ObjectDesc_ToString,(void*)Object__ObjectDesc_Equals,(void*)Object__ObjectDesc_HashCode,(void*)OOC_SSA_Schedule__BlockDesc_SetInfo,(void*)OOC_SSA_Schedule__BlockDesc_DefaultTarget}, NULL, &_mid, (OOC_CHAR8*)"BlockDesc", 48, 2, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_SSA_Schedule__BranchBlockDesc = { (RT0__Struct[]){&_td_RT0__ObjectDesc,&_td_Object__ObjectDesc,&_td_OOC_SSA_Schedule__BlockDesc,&_td_OOC_SSA_Schedule__BranchBlockDesc}, (void*[]){(void*)RT0__ObjectDesc_Finalize,(void*)Object__ObjectDesc_ToString,(void*)Object__ObjectDesc_Equals,(void*)Object__ObjectDesc_HashCode,(void*)OOC_SSA_Schedule__BlockDesc_SetInfo,(void*)OOC_SSA_Schedule__BranchBlockDesc_DefaultTarget}, NULL, &_mid, (OOC_CHAR8*)"BranchBlockDesc", 64, 3, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_SSA_Schedule__JumpBlockDesc = { (RT0__Struct[]){&_td_RT0__ObjectDesc,&_td_Object__ObjectDesc,&_td_OOC_SSA_Schedule__BlockDesc,&_td_OOC_SSA_Schedule__JumpBlockDesc}, (void*[]){(void*)RT0__ObjectDesc_Finalize,(void*)Object__ObjectDesc_ToString,(void*)Object__ObjectDesc_Equals,(void*)Object__ObjectDesc_HashCode,(void*)OOC_SSA_Schedule__BlockDesc_SetInfo,(void*)OOC_SSA_Schedule__JumpBlockDesc_DefaultTarget}, NULL, &_mid, (OOC_CHAR8*)"JumpBlockDesc", 52, 3, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_SSA_Schedule__DeadEndBlockDesc = { (RT0__Struct[]){&_td_RT0__ObjectDesc,&_td_Object__ObjectDesc,&_td_OOC_SSA_Schedule__BlockDesc,&_td_OOC_SSA_Schedule__DeadEndBlockDesc}, (void*[]){(void*)RT0__ObjectDesc_Finalize,(void*)Object__ObjectDesc_ToString,(void*)Object__ObjectDesc_Equals,(void*)Object__ObjectDesc_HashCode,(void*)OOC_SSA_Schedule__BlockDesc_SetInfo,(void*)OOC_SSA_Schedule__DeadEndBlockDesc_DefaultTarget}, NULL, &_mid, (OOC_CHAR8*)"DeadEndBlockDesc", 48, 3, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_SSA_Schedule__SwitchBlockDesc = { (RT0__Struct[]){&_td_RT0__ObjectDesc,&_td_Object__ObjectDesc,&_td_OOC_SSA_Schedule__BlockDesc,&_td_OOC_SSA_Schedule__SwitchBlockDesc}, (void*[]){(void*)RT0__ObjectDesc_Finalize,(void*)Object__ObjectDesc_ToString,(void*)Object__ObjectDesc_Equals,(void*)Object__ObjectDesc_HashCode,(void*)OOC_SSA_Schedule__BlockDesc_SetInfo,(void*)OOC_SSA_Schedule__SwitchBlockDesc_DefaultTarget}, NULL, &_mid, (OOC_CHAR8*)"SwitchBlockDesc", 64, 3, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_SSA_Schedule__5423 = { (RT0__Struct[]){&_td_OOC_SSA_Schedule__Jump}, NULL, NULL, &_mid, NULL, 4, 1, 0, RT0__strOpenArray };
RT0__StructDesc _td_OOC_SSA_Schedule__5412 = { (RT0__Struct[]){&_td_OOC_SSA_Schedule__5423}, NULL, NULL, &_mid, NULL, 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_SSA_Schedule__5464 = { (RT0__Struct[]){&_td_OOC_SSA_Schedule__JumpBlock}, NULL, NULL, &_mid, NULL, 4, 1, 0, RT0__strOpenArray };
RT0__StructDesc _td_OOC_SSA_Schedule__5453 = { (RT0__Struct[]){&_td_OOC_SSA_Schedule__5464}, NULL, NULL, &_mid, NULL, 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_SSA_Schedule__5512 = { (RT0__Struct[]){&_td_OOC_SSA__Opnd}, NULL, NULL, &_mid, NULL, 4, 1, 0, RT0__strOpenArray };
RT0__StructDesc _td_OOC_SSA_Schedule__5501 = { (RT0__Struct[]){&_td_OOC_SSA_Schedule__5512}, NULL, NULL, &_mid, NULL, 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_SSA_Schedule__InstrProxyDesc = { (RT0__Struct[]){&_td_RT0__ObjectDesc,&_td_Object__ObjectDesc,&_td_OOC_SSA__NodeDesc,&_td_OOC_SSA_Schedule__InstrProxyDesc}, (void*[]){(void*)RT0__ObjectDesc_Finalize,(void*)Object__ObjectDesc_ToString,(void*)Object__ObjectDesc_Equals,(void*)Object__ObjectDesc_HashCode}, NULL, &_mid, (OOC_CHAR8*)"InstrProxyDesc", 16, 3, 0, RT0__strRecord };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:SSA:Schedule", (RT0__Struct[]) { &_td_OOC_SSA_Schedule__Block, &_td_OOC_SSA_Schedule__InstrProxy, &_td_OOC_SSA_Schedule__BranchBlock, &_td_OOC_SSA_Schedule__JumpBlock, &_td_OOC_SSA_Schedule__DeadEndBlock, &_td_OOC_SSA_Schedule__SwitchBlock, &_td_OOC_SSA_Schedule__Info, &_td_OOC_SSA_Schedule__InfoDesc, &_td_OOC_SSA_Schedule__Dependent, &_td_OOC_SSA_Schedule__DependentDesc, &_td_OOC_SSA_Schedule__Jump, &_td_OOC_SSA_Schedule__JumpDesc, &_td_OOC_SSA_Schedule__BlockDesc, &_td_OOC_SSA_Schedule__BranchBlockDesc, &_td_OOC_SSA_Schedule__JumpBlockDesc, &_td_OOC_SSA_Schedule__DeadEndBlockDesc, &_td_OOC_SSA_Schedule__SwitchBlockDesc, &_td_OOC_SSA_Schedule__InstrProxyDesc, NULL }, 0 };

extern void OOC_OOC_SSA_Schedule_open(RT0__Module client) {
  if (_mid.openCount == 0) {
    OOC_Object_open(&_mid);
    OOC_OOC_SSA_open(&_mid);
    OOC_OOC_SSA_Opcode_open(&_mid);
    OOC_OOC_SSA_Opnd_open(&_mid);
    OOC_OOC_SSA_Blocker_open(&_mid);
    OOC_RT0_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_Exception_open(&_mid);

    RT0__RegisterModule(&_mid);
    OOC_OOC_SSA_Schedule_init();
  }
  _mid.openCount++;
}
extern void OOC_OOC_SSA_Schedule_close(RT0__Module client) {
  _mid.openCount--;
  if (_mid.openCount == 0) { 
    OOC_OOC_SSA_Schedule_destroy();
    RT0__UnregisterModule(&_mid);

    OOC_Object_close(&_mid);
    OOC_OOC_SSA_close(&_mid);
    OOC_OOC_SSA_Opcode_close(&_mid);
    OOC_OOC_SSA_Opnd_close(&_mid);
    OOC_OOC_SSA_Blocker_close(&_mid);
    OOC_RT0_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_Exception_close(&_mid);
  }
}

/* --- */
