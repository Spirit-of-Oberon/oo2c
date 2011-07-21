static void* _c0;
static void* _c1;
static void* _c2;
static void* _c3;
#include <OOC/SSA/XML.oh>
#include <Object.oh>
#include <IO/StdChannels.oh>
#include <XML/UnicodeCodec/Latin1.oh>
#include <OOC/SSA/Opcode.oh>
#include <OOC/SSA/Result.oh>
#include <OOC/SSA/Opnd.oh>
static OOC_CHAR8 OOC_SSA_XML__Omit(OOC_SSA__Instr instr);

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_OOC_SSA_XML__Writer = { (RT0__Struct[]){&_td_OOC_SSA_XML__WriterDesc}, NULL, NULL, &_mid, "Writer", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_SSA_XML__WriterDesc = { (RT0__Struct[]){&_td_XML_UnicodeBuffer__OutputDesc,&_td_XML_Writer__WriterDesc,&_td_OOC_SSA_XML__WriterDesc}, (void*[]){(void*)XML_UnicodeBuffer__OutputDesc_Write16I,(void*)XML_UnicodeBuffer__OutputDesc_Write8I,(void*)XML_UnicodeBuffer__OutputDesc_Write16,(void*)XML_UnicodeBuffer__OutputDesc_Write8,(void*)XML_UnicodeBuffer__OutputDesc_Flush,(void*)XML_Writer__WriterDesc_SetBaseURI,(void*)XML_Writer__WriterDesc_SetEmptyElementHTML,(void*)XML_Writer__WriterDesc_WriteTextDecl,(void*)XML_Writer__WriterDesc_NewLine,(void*)XML_Writer__WriterDesc_CloseStartTag,(void*)XML_Writer__WriterDesc_WriteI,(void*)XML_Writer__WriterDesc_WriteLatin1I,(void*)XML_Writer__WriterDesc_Write,(void*)XML_Writer__WriterDesc_WriteObject,(void*)XML_Writer__WriterDesc_WriteLatin1,(void*)XML_Writer__WriterDesc_WriteURI,(void*)XML_Writer__WriterDesc_WriteLInt,(void*)XML_Writer__WriterDesc_WriteRealFix,(void*)XML_Writer__WriterDesc_StartTag,(void*)XML_Writer__WriterDesc_StartTagLatin1,(void*)XML_Writer__WriterDesc_EmptyTag,(void*)XML_Writer__WriterDesc_EmptyTagLatin1,(void*)XML_Writer__WriterDesc_AttrString,(void*)XML_Writer__WriterDesc_AttrStringLatin1,(void*)XML_Writer__WriterDesc_AttrObject,(void*)XML_Writer__WriterDesc_AttrInt,(void*)XML_Writer__WriterDesc_AttrBool,(void*)XML_Writer__WriterDesc_AttrURI,(void*)XML_Writer__WriterDesc_EndTag,(void*)XML_Writer__WriterDesc_EndOfText,(void*)OOC_SSA_XML__WriterDesc_WriteInstrAttr,(void*)OOC_SSA_XML__WriterDesc_WriteInstrChildren,(void*)OOC_SSA_XML__WriterDesc_GetId,(void*)OOC_SSA_XML__WriterDesc_AttrId,(void*)OOC_SSA_XML__WriterDesc_AttrRef,(void*)OOC_SSA_XML__WriterDesc_WriteInstr,(void*)OOC_SSA_XML__WriterDesc_WriteProcBody,(void*)OOC_SSA_XML__WriterDesc_WriteSchedule}, NULL, &_mid, "WriterDesc", 80, 2, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_SSA_XML__2193 = { (RT0__Struct[]){&RT0__longchar}, NULL, NULL, &_mid, NULL, 2, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_OOC_SSA_XML__2248 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 64, 64, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_OOC_SSA_XML__4192 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 64, 64, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_OOC_SSA_XML__4406 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 64, 64, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_OOC_SSA_XML__4869 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 64, 64, (1<<RT0__flagAtomic), RT0__strArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:SSA:XML", (RT0__Struct[]) { &_td_OOC_SSA_XML__Writer, &_td_OOC_SSA_XML__WriterDesc, NULL } };

extern void OOC_OOC_SSA_XML_init0() {
  RT0__RegisterModule(&_mid);
  OOC_OOC_SSA_XML_init();
}

/* --- */
