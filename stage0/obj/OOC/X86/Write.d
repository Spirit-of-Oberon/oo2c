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
#include <OOC/X86/Write.oh>
#include <Ascii.oh>
#include <Object/Boxed.oh>
#include <Object/BigInt.oh>
#include <OOC/SymbolTable/Predef.oh>
#include <OOC/C/Naming.oh>
#include <OOC/X86/RuntimeData.oh>
#define OOC_X86_Write__nl (OOC_CHAR8)'\012'
#define OOC_X86_Write__tab (OOC_CHAR8)'\011'
#define OOC_X86_Write__nlTab "\012\011"
#define OOC_X86_Write__padFunction "\012\011.p2align 4,,15"
static void OOC_X86_Write__AddToIncoming(OOC_X86_Write__Block block, OOC_X86_Write__Arc arc);
static void OOC_X86_Write__RemoveFromIncoming(OOC_X86_Write__Arc arc);
static void OOC_X86_Write__ClearArc(OOC_X86_Write__Arc *arc);
static OOC_INT8 OOC_X86_Write__NegateBranch(OOC_INT8 opcode);
static Object__String OOC_X86_Write__OpcodeCC(OOC_INT8 type, OOC_INT8 opcode);
static void OOC_X86_Write__WriteArc(IO_TextRider__Writer w, OOC_X86_Write__Arc arc);
static Object__String OOC_X86_Write__ToHex(OOC_INT32 n, OOC_INT32 digits);
typedef struct OOC_X86_Write__WriterDesc_WriteBlock_FixGatedValues_IO {
  OOC_X86_SSA__Opnd in;
  OOC_X86_SSA__Result out;
} OOC_X86_Write__WriterDesc_WriteBlock_FixGatedValues_IO;

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_OOC_X86_Write__Arc = { (RT0__Struct[]){&_td_OOC_X86_Write__ArcDesc}, NULL, NULL, &_mid, "Arc", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_X86_Write__Block = { (RT0__Struct[]){&_td_OOC_X86_Write__BlockDesc}, NULL, NULL, &_mid, "Block", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_X86_Write__ArcDesc = { (RT0__Struct[]){&_td_OOC_X86_Write__ArcDesc}, (void*[]){(void*)OOC_X86_Write__ArcDesc_ReplaceTo}, NULL, &_mid, "ArcDesc", 16, 0, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_X86_Write__BlockDesc = { (RT0__Struct[]){&_td_RT0__ObjectDesc,&_td_Object__ObjectDesc,&_td_OOC_X86_Write__BlockDesc}, (void*[]){(void*)RT0__ObjectDesc_Finalize,(void*)Object__ObjectDesc_ToString,(void*)Object__ObjectDesc_Equals,(void*)Object__ObjectDesc_HashCode,(void*)OOC_X86_Write__BlockDesc_INIT,(void*)OOC_X86_Write__BlockDesc_IsEmpty,(void*)OOC_X86_Write__BlockDesc_SetArc}, NULL, &_mid, "BlockDesc", 28, 2, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_X86_Write__623 = { (RT0__Struct[]){&_td_OOC_X86_Write__Arc}, NULL, NULL, &_mid, NULL, 4, 1, 0, RT0__strOpenArray };
RT0__StructDesc _td_OOC_X86_Write__612 = { (RT0__Struct[]){&_td_OOC_X86_Write__623}, NULL, NULL, &_mid, NULL, 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_X86_Write__Writer = { (RT0__Struct[]){&_td_OOC_X86_Write__WriterDesc}, NULL, NULL, &_mid, "Writer", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_X86_Write__WriterDesc = { (RT0__Struct[]){&_td_OOC_X86_Write__WriterDesc}, (void*[]){(void*)OOC_X86_Write__WriterDesc_INIT,(void*)OOC_X86_Write__WriterDesc_GetBlock,(void*)OOC_X86_Write__WriterDesc_RuntimeData,(void*)OOC_X86_Write__WriterDesc_ModuleVariables,(void*)OOC_X86_Write__WriterDesc_ConstSymbol,(void*)OOC_X86_Write__WriterDesc_Constants,(void*)OOC_X86_Write__WriterDesc_EndFile,(void*)OOC_X86_Write__WriterDesc_WriteBlock,(void*)OOC_X86_Write__WriterDesc_WriteFunction}, NULL, &_mid, "WriterDesc", 188, 0, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_X86_Write__1030 = { (RT0__Struct[]){&_td_ADT_Dictionary__Dictionary}, NULL, NULL, &_mid, NULL, 76, 19, 0, RT0__strArray };
RT0__StructDesc _td_OOC_X86_Write__1088 = { (RT0__Struct[]){&_td_ADT_ArrayList__ArrayList}, NULL, NULL, &_mid, NULL, 76, 19, 0, RT0__strArray };
RT0__StructDesc _td_OOC_X86_Write__6193 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 16, 16, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_OOC_X86_Write__6651 = { (RT0__Struct[]){&_td_OOC_X86_Write__6651}, (void*[]){}, NULL, &_mid, NULL, 8, 0, (1<<RT0__flagAtomic), RT0__strRecord };
RT0__StructDesc _td_OOC_X86_Write__10536 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_OOC_X86_Write__10650 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 3, 3, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_OOC_X86_Write__11586 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_OOC_X86_Write__11756 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_OOC_X86_Write__12236 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 8, 8, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_OOC_X86_Write__WriterDesc_WriteBlock_FixGatedValues_IO = { (RT0__Struct[]){&_td_OOC_X86_Write__WriterDesc_WriteBlock_FixGatedValues_IO}, (void*[]){}, NULL, &_mid, "IO", 8, 0, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_X86_Write__18429 = { (RT0__Struct[]){&_td_OOC_X86_Write__WriterDesc_WriteBlock_FixGatedValues_IO}, NULL, NULL, &_mid, NULL, 8, 1, 0, RT0__strOpenArray };
RT0__StructDesc _td_OOC_X86_Write__18418 = { (RT0__Struct[]){&_td_OOC_X86_Write__18429}, NULL, NULL, &_mid, NULL, 4, -1, 0, RT0__strPointer };
static RT0__StructDesc _td__qtd0 = { (RT0__Struct[]){&_td_RT0__ObjectDesc,&_td_Object__ObjectDesc,&_td_ADT_Storable__ObjectDesc,&_td__qtd0}, (void*[]){(void*)RT0__ObjectDesc_Finalize,(void*)Object__ObjectDesc_ToString,(void*)ADT_Dictionary__DictionaryDesc_Equals,(void*)ADT_Dictionary__DictionaryDesc_HashCode,(void*)ADT_Dictionary__DictionaryDesc_Store,(void*)ADT_Dictionary__DictionaryDesc_Load,(void*)ADT_Dictionary__DictionaryDesc_INIT,(void*)ADT_Dictionary__DictionaryDesc_Destroy,(void*)ADT_Dictionary__DictionaryDesc_Lookup,(void*)ADT_Dictionary__DictionaryDesc_Insert,(void*)ADT_Dictionary__DictionaryDesc_Resize,(void*)ADT_Dictionary__DictionaryDesc_HasKey,(void*)ADT_Dictionary__DictionaryDesc_Size,(void*)ADT_Dictionary__DictionaryDesc_Get,(void*)ADT_Dictionary__DictionaryDesc_Set,(void*)ADT_Dictionary__DictionaryDesc_Copy,(void*)ADT_Dictionary__DictionaryDesc_Delete,(void*)ADT_Dictionary__DictionaryDesc_Clear,(void*)ADT_Dictionary__DictionaryDesc_Keys,(void*)ADT_Dictionary__DictionaryDesc_Values,(void*)ADT_Dictionary__DictionaryDesc_Items}, (RT0__Struct[]){&_td_ADT_Dictionary__DictionaryDesc, &_td_Object__Object, &_td_Object__String, NULL}, &_mid, "ADT:Dictionary.DictionaryDesc(Object.Object,Object.String)", 20, 3, 0, RT0__strQualType };
static RT0__StructDesc _td__qtd1 = { (RT0__Struct[]){&_td__qtd0}, NULL, (RT0__Struct[]){&_td_ADT_Dictionary__Dictionary, &_td_Object__Object, &_td_Object__String, NULL}, &_mid, "ADT:Dictionary.Dictionary(Object.Object,Object.String)", 4, 0, 0, RT0__strQualType };
static RT0__StructDesc _td__qtd2 = { (RT0__Struct[]){&_td_RT0__ObjectDesc,&_td_Object__ObjectDesc,&_td_ADT_Storable__ObjectDesc,&_td__qtd2}, (void*[]){(void*)RT0__ObjectDesc_Finalize,(void*)Object__ObjectDesc_ToString,(void*)ADT_ArrayList__ArrayListDesc_Equals,(void*)ADT_ArrayList__ArrayListDesc_HashCode,(void*)ADT_ArrayList__ArrayListDesc_Store,(void*)ADT_ArrayList__ArrayListDesc_Load,(void*)ADT_ArrayList__ArrayListDesc_CreateArray,(void*)ADT_ArrayList__ArrayListDesc_INIT,(void*)ADT_ArrayList__ArrayListDesc_Destroy,(void*)ADT_ArrayList__ArrayListDesc_Copy,(void*)ADT_ArrayList__ArrayListDesc_EnsureCapacity,(void*)ADT_ArrayList__ArrayListDesc_Clear,(void*)ADT_ArrayList__ArrayListDesc_Append,(void*)ADT_ArrayList__ArrayListDesc_Insert,(void*)ADT_ArrayList__ArrayListDesc_Get,(void*)ADT_ArrayList__ArrayListDesc_Set,(void*)ADT_ArrayList__ArrayListDesc_RemoveRange,(void*)ADT_ArrayList__ArrayListDesc_Remove,(void*)ADT_ArrayList__ArrayListDesc_TrimToSize,(void*)ADT_ArrayList__ArrayListDesc_Size,(void*)ADT_ArrayList__ArrayListDesc_Contains,(void*)ADT_ArrayList__ArrayListDesc_IndexOf,(void*)ADT_ArrayList__ArrayListDesc_LastIndexOf,(void*)ADT_ArrayList__ArrayListDesc_IsEmpty,(void*)ADT_ArrayList__ArrayListDesc_Sort,(void*)ADT_ArrayList__ArrayListDesc_Elements}, (RT0__Struct[]){&_td_ADT_ArrayList__ArrayListDesc, &_td_Object__Object, NULL}, &_mid, "ADT:ArrayList.ArrayListDesc(Object.Object)", 8, 3, 0, RT0__strQualType };
static RT0__StructDesc _td__qtd3 = { (RT0__Struct[]){&_td__qtd2}, NULL, (RT0__Struct[]){&_td_ADT_ArrayList__ArrayList, &_td_Object__Object, NULL}, &_mid, "ADT:ArrayList.ArrayList(Object.Object)", 4, 0, 0, RT0__strQualType };
static RT0__StructDesc _td__qtd4 = { (RT0__Struct[]){&_td_RT0__ObjectDesc,&_td_Object__ObjectDesc,&_td_ADT_Storable__ObjectDesc,&_td__qtd4}, (void*[]){(void*)RT0__ObjectDesc_Finalize,(void*)Object__ObjectDesc_ToString,(void*)ADT_Dictionary__DictionaryDesc_Equals,(void*)ADT_Dictionary__DictionaryDesc_HashCode,(void*)ADT_Dictionary__DictionaryDesc_Store,(void*)ADT_Dictionary__DictionaryDesc_Load,(void*)ADT_Dictionary__DictionaryDesc_INIT,(void*)ADT_Dictionary__DictionaryDesc_Destroy,(void*)ADT_Dictionary__DictionaryDesc_Lookup,(void*)ADT_Dictionary__DictionaryDesc_Insert,(void*)ADT_Dictionary__DictionaryDesc_Resize,(void*)ADT_Dictionary__DictionaryDesc_HasKey,(void*)ADT_Dictionary__DictionaryDesc_Size,(void*)ADT_Dictionary__DictionaryDesc_Get,(void*)ADT_Dictionary__DictionaryDesc_Set,(void*)ADT_Dictionary__DictionaryDesc_Copy,(void*)ADT_Dictionary__DictionaryDesc_Delete,(void*)ADT_Dictionary__DictionaryDesc_Clear,(void*)ADT_Dictionary__DictionaryDesc_Keys,(void*)ADT_Dictionary__DictionaryDesc_Values,(void*)ADT_Dictionary__DictionaryDesc_Items}, (RT0__Struct[]){&_td_ADT_Dictionary__DictionaryDesc, &_td_OOC_X86_SSA__Block, &_td_OOC_X86_Write__Block, NULL}, &_mid, "ADT:Dictionary.DictionaryDesc(OOC:X86:SSA.Block,OOC:X86:Write.Block)", 20, 3, 0, RT0__strQualType };
static RT0__StructDesc _td__qtd5 = { (RT0__Struct[]){&_td__qtd4}, NULL, (RT0__Struct[]){&_td_ADT_Dictionary__Dictionary, &_td_OOC_X86_SSA__Block, &_td_OOC_X86_Write__Block, NULL}, &_mid, "ADT:Dictionary.Dictionary(OOC:X86:SSA.Block,OOC:X86:Write.Block)", 4, 0, 0, RT0__strQualType };
static RT0__StructDesc _td__qtd6 = { (RT0__Struct[]){&_td_RT0__ObjectDesc,&_td_Object__ObjectDesc,&_td_ADT_Storable__ObjectDesc,&_td__qtd6}, (void*[]){(void*)RT0__ObjectDesc_Finalize,(void*)Object__ObjectDesc_ToString,(void*)ADT_ArrayList__ArrayListDesc_Equals,(void*)ADT_ArrayList__ArrayListDesc_HashCode,(void*)ADT_ArrayList__ArrayListDesc_Store,(void*)ADT_ArrayList__ArrayListDesc_Load,(void*)ADT_ArrayList__ArrayListDesc_CreateArray,(void*)ADT_ArrayList__ArrayListDesc_INIT,(void*)ADT_ArrayList__ArrayListDesc_Destroy,(void*)ADT_ArrayList__ArrayListDesc_Copy,(void*)ADT_ArrayList__ArrayListDesc_EnsureCapacity,(void*)ADT_ArrayList__ArrayListDesc_Clear,(void*)ADT_ArrayList__ArrayListDesc_Append,(void*)ADT_ArrayList__ArrayListDesc_Insert,(void*)ADT_ArrayList__ArrayListDesc_Get,(void*)ADT_ArrayList__ArrayListDesc_Set,(void*)ADT_ArrayList__ArrayListDesc_RemoveRange,(void*)ADT_ArrayList__ArrayListDesc_Remove,(void*)ADT_ArrayList__ArrayListDesc_TrimToSize,(void*)ADT_ArrayList__ArrayListDesc_Size,(void*)ADT_ArrayList__ArrayListDesc_Contains,(void*)ADT_ArrayList__ArrayListDesc_IndexOf,(void*)ADT_ArrayList__ArrayListDesc_LastIndexOf,(void*)ADT_ArrayList__ArrayListDesc_IsEmpty,(void*)ADT_ArrayList__ArrayListDesc_Sort,(void*)ADT_ArrayList__ArrayListDesc_Elements}, (RT0__Struct[]){&_td_ADT_ArrayList__ArrayListDesc, &_td_OOC_X86_Write__Block, NULL}, &_mid, "ADT:ArrayList.ArrayListDesc(OOC:X86:Write.Block)", 8, 3, 0, RT0__strQualType };
static RT0__StructDesc _td__qtd7 = { (RT0__Struct[]){&_td__qtd6}, NULL, (RT0__Struct[]){&_td_ADT_ArrayList__ArrayList, &_td_OOC_X86_Write__Block, NULL}, &_mid, "ADT:ArrayList.ArrayList(OOC:X86:Write.Block)", 4, 0, 0, RT0__strQualType };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:X86:Write", (RT0__Struct[]) { &_td_OOC_X86_Write__Arc, &_td_OOC_X86_Write__Block, &_td_OOC_X86_Write__ArcDesc, &_td_OOC_X86_Write__BlockDesc, &_td_OOC_X86_Write__Writer, &_td_OOC_X86_Write__WriterDesc, &_td__qtd0, &_td__qtd1, &_td__qtd2, &_td__qtd3, &_td__qtd4, &_td__qtd5, &_td__qtd6, &_td__qtd7, NULL } };

extern void OOC_OOC_X86_Write_init0() {
  RT0__RegisterModule(&_mid);
  OOC_OOC_X86_Write_init();
}

/* --- */
