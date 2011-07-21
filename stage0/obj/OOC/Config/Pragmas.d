static void* _c0;
static void* _c1;
static void* _c2;
static void* _c3;
#include <OOC/Config/Pragmas.oh>
#include <Config/Parser.oh>
static void OOC_Config_Pragmas__Init(OOC_Config_Pragmas__Section s, const Config_Parser__String id__ref, OOC_LEN id_0d, ADT_Dictionary__Dictionary prototypeMap);
static void OOC_Config_Pragmas__InitHistory(OOC_Config_Pragmas__History h, OOC_Config_Pragmas__Section startVariables);
static Config__Variable OOC_Config_Pragmas__GetValue(OOC_Config_Pragmas__History h, OOC_Config_Pragmas__Variable var, OOC_INT32 charPos);
static void OOC_Config_Pragmas__LastCharPos(OOC_Config_Pragmas__History h, OOC_INT32 charPos);
static void OOC_Config_Pragmas__SetValue(OOC_Config_Pragmas__Variable var, OOC_INT32 charPos, Config__Variable value);

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_OOC_Config_Pragmas__Section = { (RT0__Struct[]){&_td_OOC_Config_Pragmas__SectionDesc}, NULL, NULL, &_mid, "Section", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_Config_Pragmas__SectionDesc = { (RT0__Struct[]){&_td_Config_Section__SectionDesc,&_td_Config_Section_Options__SectionDesc,&_td_OOC_Config_Pragmas__SectionDesc}, (void*[]){(void*)Config_Section_Options__SectionDesc_ProcessElements,(void*)Config_Section_Options__SectionDesc_DumpContent,(void*)Config_Section_Options__SectionDesc_Get,(void*)Config_Section_Options__SectionDesc_Set,(void*)Config_Section_Options__SectionDesc_GetValue,(void*)OOC_Config_Pragmas__SectionDesc_Copy,(void*)OOC_Config_Pragmas__SectionDesc_Clone}, NULL, &_mid, "SectionDesc", 12, 2, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_Config_Pragmas__Variable = { (RT0__Struct[]){&_td_OOC_Config_Pragmas__VariableDesc}, NULL, NULL, &_mid, "Variable", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_Config_Pragmas__1172 = { (RT0__Struct[]){&_td_Config__Variable}, NULL, NULL, &_mid, NULL, 4, 1, 0, RT0__strOpenArray };
RT0__StructDesc _td_OOC_Config_Pragmas__ValueArray = { (RT0__Struct[]){&_td_OOC_Config_Pragmas__1172}, NULL, NULL, &_mid, "ValueArray", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_Config_Pragmas__1226 = { (RT0__Struct[]){&RT0__longint}, NULL, NULL, &_mid, NULL, 4, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_OOC_Config_Pragmas__CharPosArray = { (RT0__Struct[]){&_td_OOC_Config_Pragmas__1226}, NULL, NULL, &_mid, "CharPosArray", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_Config_Pragmas__VariableDesc = { (RT0__Struct[]){&_td_OOC_Config_Pragmas__VariableDesc}, (void*[]){}, NULL, &_mid, "VariableDesc", 20, 0, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_Config_Pragmas__History = { (RT0__Struct[]){&_td_OOC_Config_Pragmas__HistoryDesc}, NULL, NULL, &_mid, "History", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_Config_Pragmas__HistoryDesc = { (RT0__Struct[]){&_td_OOC_Config_Pragmas__HistoryDesc}, (void*[]){(void*)OOC_Config_Pragmas__HistoryDesc_GetValue,(void*)OOC_Config_Pragmas__HistoryDesc_SetValue,(void*)OOC_Config_Pragmas__HistoryDesc_Push,(void*)OOC_Config_Pragmas__HistoryDesc_Pop}, NULL, &_mid, "HistoryDesc", 20, 0, 0, RT0__strRecord };
static RT0__StructDesc _td__qtd0 = { (RT0__Struct[]){&_td_RT0__ObjectDesc,&_td_Object__ObjectDesc,&_td_ADT_Storable__ObjectDesc,&_td__qtd0}, (void*[]){(void*)RT0__ObjectDesc_Finalize,(void*)Object__ObjectDesc_ToString,(void*)ADT_Dictionary__DictionaryDesc_Equals,(void*)ADT_Dictionary__DictionaryDesc_HashCode,(void*)ADT_Dictionary__DictionaryDesc_Store,(void*)ADT_Dictionary__DictionaryDesc_Load,(void*)ADT_Dictionary__DictionaryDesc_INIT,(void*)ADT_Dictionary__DictionaryDesc_Destroy,(void*)ADT_Dictionary__DictionaryDesc_Lookup,(void*)ADT_Dictionary__DictionaryDesc_Insert,(void*)ADT_Dictionary__DictionaryDesc_Resize,(void*)ADT_Dictionary__DictionaryDesc_HasKey,(void*)ADT_Dictionary__DictionaryDesc_Size,(void*)ADT_Dictionary__DictionaryDesc_Get,(void*)ADT_Dictionary__DictionaryDesc_Set,(void*)ADT_Dictionary__DictionaryDesc_Copy,(void*)ADT_Dictionary__DictionaryDesc_Delete,(void*)ADT_Dictionary__DictionaryDesc_Clear,(void*)ADT_Dictionary__DictionaryDesc_Keys,(void*)ADT_Dictionary__DictionaryDesc_Values,(void*)ADT_Dictionary__DictionaryDesc_Items,(void*)ADT_Dictionary__DictionaryDesc_IterKeys,(void*)ADT_Dictionary__DictionaryDesc_IterValues}, (RT0__Struct[]){&_td_ADT_Dictionary__DictionaryDesc, &_td_Object__String, &_td_Config__Variable, NULL}, &_mid, "ADT:Dictionary.DictionaryDesc(Object.String,Config.Variable)", 20, 3, 0, RT0__strQualType };
static RT0__StructDesc _td__qtd1 = { (RT0__Struct[]){&_td__qtd0}, NULL, (RT0__Struct[]){&_td_ADT_Dictionary__Dictionary, &_td_Object__String, &_td_Config__Variable, NULL}, &_mid, "ADT:Dictionary.Dictionary(Object.String,Config.Variable)", 4, 0, 0, RT0__strQualType };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:Config:Pragmas", (RT0__Struct[]) { &_td_OOC_Config_Pragmas__Section, &_td_OOC_Config_Pragmas__SectionDesc, &_td_OOC_Config_Pragmas__Variable, &_td_OOC_Config_Pragmas__ValueArray, &_td_OOC_Config_Pragmas__CharPosArray, &_td_OOC_Config_Pragmas__VariableDesc, &_td_OOC_Config_Pragmas__History, &_td_OOC_Config_Pragmas__HistoryDesc, &_td__qtd0, &_td__qtd1, NULL } };

extern void OOC_OOC_Config_Pragmas_init0() {
  RT0__RegisterModule(&_mid);
  OOC_OOC_Config_Pragmas_init();
}

/* --- */
