#include <OOC/IA32/Writer.oh>
#include <Ascii.oh>
#include <IntStr.oh>
#include <Strings.oh>
#include <Object.oh>
static void OOC_IA32_Writer__InitWriter(OOC_IA32_Writer__Writer w, IO__ByteChannel ch);

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_OOC_IA32_Writer__Writer = { (RT0__Struct[]){&_td_OOC_IA32_Writer__WriterDesc}, NULL, NULL, &_mid, "Writer", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_IA32_Writer__WriterDesc = { (RT0__Struct[]){&_td_OOC_IA32_Writer__WriterDesc}, (void*[]){(void*)OOC_IA32_Writer__WriterDesc_Newline,(void*)OOC_IA32_Writer__WriterDesc_Write,(void*)OOC_IA32_Writer__WriterDesc_WriteObject,(void*)OOC_IA32_Writer__WriterDesc_Label,(void*)OOC_IA32_Writer__WriterDesc_Section,(void*)OOC_IA32_Writer__WriterDesc_Directive,(void*)OOC_IA32_Writer__WriterDesc_Instr,(void*)OOC_IA32_Writer__WriterDesc_StringLiteral,(void*)OOC_IA32_Writer__WriterDesc_GetStringLabel,(void*)OOC_IA32_Writer__WriterDesc_PushInt,(void*)OOC_IA32_Writer__WriterDesc_PushLabel,(void*)OOC_IA32_Writer__WriterDesc_PopBytes,(void*)OOC_IA32_Writer__WriterDesc_WriteStringData,(void*)OOC_IA32_Writer__WriterDesc_Close}, NULL, &_mid, "WriterDesc", 16, 0, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_IA32_Writer__1951 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_OOC_IA32_Writer__2356 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_OOC_IA32_Writer__2505 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_OOC_IA32_Writer__2691 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_OOC_IA32_Writer__2881 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_OOC_IA32_Writer__3243 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 32, 32, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_OOC_IA32_Writer__3859 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:IA32:Writer", (RT0__Struct[]) { &_td_OOC_IA32_Writer__Writer, &_td_OOC_IA32_Writer__WriterDesc, NULL } };

extern void OOC_OOC_IA32_Writer_init0() {
  RT0__RegisterModule(&_mid);
  OOC_OOC_IA32_Writer_init();
}

/* --- */
