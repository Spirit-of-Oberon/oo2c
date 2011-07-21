static void* _c0;
static void* _c1;
static void* _c2;
static void* _c3;
static void* _c4;
static void* _c5;
static void* _c6;
static void* _c7;
static void* _c8;
static void* _c9;
static void* _c10;
static void* _c11;
static void* _c12;
static void* _c13;
static void* _c14;
static void* _c15;
static void* _c16;
static void* _c17;
static void* _c18;
static void* _c19;
static void* _c20;
static void* _c21;
static void* _c22;
static void* _c23;
static void* _c24;
static void* _c25;
static void* _c26;
static void* _c27;
static void* _c28;
static void* _c29;
static void* _c30;
static void* _c31;
static void* _c32;
static void* _c33;
static void* _c34;
static void* _c35;
static void* _c36;
static void* _c37;
static void* _c38;
static void* _c39;
static void* _c40;
static void* _c41;
static void* _c42;
static void* _c43;
static void* _c44;
static void* _c45;
static void* _c46;
static void* _c47;
static void* _c48;
static void* _c49;
static void* _c50;
static void* _c51;
static void* _c52;
static void* _c53;
static void* _c54;
static void* _c55;
static void* _c56;
static void* _c57;
static void* _c58;
static void* _c59;
static void* _c60;
static void* _c61;
static void* _c62;
static void* _c63;
static void* _c64;
static void* _c65;
static void* _c66;
static void* _c67;
static void* _c68;
static void* _c69;
static void* _c70;
static void* _c71;
static void* _c72;
static void* _c73;
static void* _c74;
static void* _c75;
static void* _c76;
static void* _c77;
static void* _c78;
static void* _c79;
static void* _c80;
static void* _c81;
static void* _c82;
static void* _c83;
static void* _c84;
static void* _c85;
static void* _c86;
static void* _c87;
static void* _c88;
static void* _c89;
static void* _c90;
static void* _c91;
static void* _c92;
static void* _c93;
static void* _c94;
static void* _c95;
static void* _c96;
static void* _c97;
static void* _c98;
static void* _c99;
static void* _c100;
static void* _c101;
static void* _c102;
static void* _c103;
static void* _c104;
static void* _c105;
static void* _c106;
static void* _c107;
static void* _c108;
static void* _c109;
static void* _c110;
static void* _c111;
static void* _c112;
static void* _c113;
static void* _c114;
static void* _c115;
static void* _c116;
static void* _c117;
static void* _c118;
#include <OOC/X86/Debug.oh>
#include <Object/Boxed.oh>
#include <IO/TextRider.oh>
#include <IO/StdChannels.oh>
#include <Out.oh>
#include <Log.oh>
#include <OOC/C/Naming.oh>
#include <OOC/X86/Machine.oh>
static OOC_X86_Debug__Output OOC_X86_Debug__out;
#define OOC_X86_Debug__writeAllInstructions OOC_FALSE
#define OOC_X86_Debug__writeDesignator OOC_TRUE
#define OOC_X86_Debug__resultPrefix (OOC_CHAR8)'('
#define OOC_X86_Debug__resultSuffix (OOC_CHAR8)')'
#define OOC_X86_Debug__instrPrefix (OOC_CHAR8)'{'
#define OOC_X86_Debug__instrSuffix (OOC_CHAR8)'}'
#define OOC_X86_Debug__depPrefix "   ["
#define OOC_X86_Debug__depSuffix (OOC_CHAR8)']'
static Object__String OOC_X86_Debug__Type(OOC_INT8 type);
static void OOC_X86_Debug__UndefState(OOC_X86_Debug__State s);

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_OOC_X86_Debug__Output = { (RT0__Struct[]){&_td_OOC_X86_Debug__OutputDesc}, NULL, NULL, &_mid, "Output", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_X86_Debug__OutputDesc = { (RT0__Struct[]){&_td_OOC_X86_Debug__OutputDesc}, (void*[]){(void*)OOC_X86_Debug__OutputDesc_INIT,(void*)OOC_X86_Debug__OutputDesc_GetInstrCode,(void*)OOC_X86_Debug__OutputDesc_Label,(void*)OOC_X86_Debug__OutputDesc_Result,(void*)OOC_X86_Debug__OutputDesc_Instr,(void*)OOC_X86_Debug__OutputDesc_WriteFunction}, NULL, &_mid, "OutputDesc", 16, 0, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_X86_Debug__State = { (RT0__Struct[]){&_td_OOC_X86_Debug__StateDesc}, NULL, NULL, &_mid, "State", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_X86_Debug__StateDesc = { (RT0__Struct[]){&_td_RT0__ObjectDesc,&_td_Object__ObjectDesc,&_td_OOC_X86_Debug__StateDesc}, (void*[]){(void*)RT0__ObjectDesc_Finalize,(void*)Object__ObjectDesc_ToString,(void*)Object__ObjectDesc_Equals,(void*)Object__ObjectDesc_HashCode,(void*)OOC_X86_Debug__StateDesc_INIT,(void*)OOC_X86_Debug__StateDesc_Copy}, NULL, &_mid, "StateDesc", 96, 2, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_X86_Debug__508 = { (RT0__Struct[]){&_td_OOC_X86_SSA__Result}, NULL, NULL, &_mid, NULL, 72, 18, 0, RT0__strArray };
RT0__StructDesc _td_OOC_X86_Debug__12596 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_OOC_X86_Debug__12700 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_OOC_X86_Debug__12752 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
static RT0__StructDesc _td__qtd0 = { (RT0__Struct[]){&_td_RT0__ObjectDesc,&_td_Object__ObjectDesc,&_td_ADT_Storable__ObjectDesc,&_td__qtd0}, (void*[]){(void*)RT0__ObjectDesc_Finalize,(void*)Object__ObjectDesc_ToString,(void*)ADT_Dictionary__DictionaryDesc_Equals,(void*)ADT_Dictionary__DictionaryDesc_HashCode,(void*)ADT_Dictionary__DictionaryDesc_Store,(void*)ADT_Dictionary__DictionaryDesc_Load,(void*)ADT_Dictionary__DictionaryDesc_INIT,(void*)ADT_Dictionary__DictionaryDesc_Destroy,(void*)ADT_Dictionary__DictionaryDesc_Lookup,(void*)ADT_Dictionary__DictionaryDesc_Insert,(void*)ADT_Dictionary__DictionaryDesc_Resize,(void*)ADT_Dictionary__DictionaryDesc_HasKey,(void*)ADT_Dictionary__DictionaryDesc_Size,(void*)ADT_Dictionary__DictionaryDesc_Get,(void*)ADT_Dictionary__DictionaryDesc_Set,(void*)ADT_Dictionary__DictionaryDesc_Copy,(void*)ADT_Dictionary__DictionaryDesc_Delete,(void*)ADT_Dictionary__DictionaryDesc_Clear,(void*)ADT_Dictionary__DictionaryDesc_Keys,(void*)ADT_Dictionary__DictionaryDesc_Values,(void*)ADT_Dictionary__DictionaryDesc_Items}, (RT0__Struct[]){&_td_ADT_Dictionary__DictionaryDesc, &_td_OOC_X86_SSA__Instr, &_td_Object__String, NULL}, &_mid, "ADT:Dictionary.DictionaryDesc(OOC:X86:SSA.Instr,Object.String)", 20, 3, 0, RT0__strQualType };
static RT0__StructDesc _td__qtd1 = { (RT0__Struct[]){&_td__qtd0}, NULL, (RT0__Struct[]){&_td_ADT_Dictionary__Dictionary, &_td_OOC_X86_SSA__Instr, &_td_Object__String, NULL}, &_mid, "ADT:Dictionary.Dictionary(OOC:X86:SSA.Instr,Object.String)", 4, 0, 0, RT0__strQualType };
static RT0__StructDesc _td__qtd2 = { (RT0__Struct[]){&_td_RT0__ObjectDesc,&_td_Object__ObjectDesc,&_td_ADT_Storable__ObjectDesc,&_td__qtd2}, (void*[]){(void*)RT0__ObjectDesc_Finalize,(void*)Object__ObjectDesc_ToString,(void*)ADT_Dictionary__DictionaryDesc_Equals,(void*)ADT_Dictionary__DictionaryDesc_HashCode,(void*)ADT_Dictionary__DictionaryDesc_Store,(void*)ADT_Dictionary__DictionaryDesc_Load,(void*)ADT_Dictionary__DictionaryDesc_INIT,(void*)ADT_Dictionary__DictionaryDesc_Destroy,(void*)ADT_Dictionary__DictionaryDesc_Lookup,(void*)ADT_Dictionary__DictionaryDesc_Insert,(void*)ADT_Dictionary__DictionaryDesc_Resize,(void*)ADT_Dictionary__DictionaryDesc_HasKey,(void*)ADT_Dictionary__DictionaryDesc_Size,(void*)ADT_Dictionary__DictionaryDesc_Get,(void*)ADT_Dictionary__DictionaryDesc_Set,(void*)ADT_Dictionary__DictionaryDesc_Copy,(void*)ADT_Dictionary__DictionaryDesc_Delete,(void*)ADT_Dictionary__DictionaryDesc_Clear,(void*)ADT_Dictionary__DictionaryDesc_Keys,(void*)ADT_Dictionary__DictionaryDesc_Values,(void*)ADT_Dictionary__DictionaryDesc_Items}, (RT0__Struct[]){&_td_ADT_Dictionary__DictionaryDesc, &_td_OOC_X86_SSA__Instr, &_td_OOC_X86_Debug__State, NULL}, &_mid, "ADT:Dictionary.DictionaryDesc(OOC:X86:SSA.Instr,OOC:X86:Debug.State)", 20, 3, 0, RT0__strQualType };
static RT0__StructDesc _td__qtd3 = { (RT0__Struct[]){&_td__qtd2}, NULL, (RT0__Struct[]){&_td_ADT_Dictionary__Dictionary, &_td_OOC_X86_SSA__Instr, &_td_OOC_X86_Debug__State, NULL}, &_mid, "ADT:Dictionary.Dictionary(OOC:X86:SSA.Instr,OOC:X86:Debug.State)", 4, 0, 0, RT0__strQualType };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:X86:Debug", (RT0__Struct[]) { &_td_OOC_X86_Debug__Output, &_td_OOC_X86_Debug__OutputDesc, &_td_OOC_X86_Debug__State, &_td_OOC_X86_Debug__StateDesc, &_td__qtd0, &_td__qtd1, &_td__qtd2, &_td__qtd3, NULL } };

extern void OOC_OOC_X86_Debug_init0() {
  RT0__RegisterModule(&_mid);
  OOC_OOC_X86_Debug_init();
}

/* --- */
