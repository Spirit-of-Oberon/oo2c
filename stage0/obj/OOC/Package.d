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
#include <OOC/Package.oh>
#include <IntStr.oh>
#include <LongStrings.oh>
#include <Strings.oh>
#include <IO/FileChannel.oh>
#include <IO/StdChannels.oh>
#include <Exception.oh>
#include <ADT/StringBuffer.oh>
#include <OS/Files.oh>
#include <OS/ProcessManagement.oh>
#include <OS/Path.oh>
#include <URI.oh>
#include <URI/Scheme/File.oh>
#include <XML/UnicodeCodec/Latin1.oh>
#include <XML/Locator.oh>
#include <XML/DTD.oh>
#include <XML/Builder.oh>
#include <XML/Writer.oh>
#include <Config/Parser.oh>
#include <OOC/Logger.oh>
#include <OOC/Config.oh>
#define OOC_Package__rootPackage "package"
#define OOC_Package__rootRepository "repository"
#define OOC_Package__pkgInfoSubdir "/pkginfo"
#define OOC_Package__pkgInfoFile "/pkginfo.xml"
#define OOC_Package__packageData "pkginfo.xml"
static Object__String OOC_Package__stringType;
#define OOC_Package__invalidContent 0
#define OOC_Package__invalidRootName 1
#define OOC_Package__invalidCharData 2
#define OOC_Package__invalidAttribute 3
#define OOC_Package__junkAtEndOfElement 4
#define OOC_Package__requireNameAttribute 5
#define OOC_Package__requireVersionChild 6
#define OOC_Package__requireCurrentAttribute 7
#define OOC_Package__requireRevisionAttribute 8
#define OOC_Package__requireMainModuleAttribute 9
#define OOC_Package__requireSourceDirAttribute 10
#define OOC_Package__requireTypeAttribute 11
#define OOC_Package__requireFileOrFileSet 12
#define OOC_Package__requireDefine 13
#define OOC_Package__notUnsignedInteger 14
#define OOC_Package__requireCharacterData 15
#define OOC_Package__unknownType 16
#define OOC_Package__invalidValue 17
static OOC_Package__ErrorContext OOC_Package__packageContext;
static OOC_Package__Version OOC_Package__NewVersion(void);
static OOC_Package__Executable OOC_Package__NewExecutable(void);
static OOC_Package__Library OOC_Package__NewLibrary(void);
static void OOC_Package__InitFileData(OOC_Package__FileData fdata);
static OOC_Package__FileSet OOC_Package__NewFileSet(void);
static void OOC_Package__MergeConfig(OOC_Repository__PkgInfo pkg, Config_Section_Options__Section options, Config_Section_Options__Section pragmas);
static OOC_Package__Package OOC_Package__NewPackage(void);
static OOC_Package__Repository OOC_Package__NewRepository(void);
static Object__String OOC_Package__StringAttr(XML_Builder__Attribute att);
static OOC_CHAR8 OOC_Package__AtElement(Config_Parser__Node node, const OOC_CHAR16 elementName__ref[], OOC_LEN elementName_0d);
static void OOC_Package__ParseKeyValue(Config_Parser__Element elem, ADT_ArrayList__ArrayList list, Config_Section_Options__Section options, Object__String defaultType, XML_Locator__ErrorListener errorListener, OOC_Error__List errList);
static OOC_Package__Package OOC_Package__ProcessPackage(Config_Parser__Element root, XML_Locator__ErrorListener errorListener, OOC_Error__List errList);
static OOC_Package__Repository OOC_Package__ProcessRepository(Config_Parser__Element root, XML_Locator__ErrorListener errorListener, OOC_Error__List errList);
static OOC_Repository__PkgInfo OOC_Package__ParseFile(volatile Object__String fileName, volatile OOC_CHAR8 requirePackage, volatile OOC_Error__List *errList);
static void OOC_Package__WriteKeyValue(XML_Writer__Writer w, const OOC_CHAR8 tag__ref[], OOC_LEN tag_0d, ADT_ArrayList__ArrayList list);

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_OOC_Package__Version = { (RT0__Struct[]){&_td_OOC_Package__VersionDesc}, NULL, NULL, &_mid, "Version", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_Package__VersionDesc = { (RT0__Struct[]){&_td_OOC_Package__VersionDesc}, (void*[]){}, NULL, &_mid, "VersionDesc", 44, 0, (1<<RT0__flagAtomic), RT0__strRecord };
RT0__StructDesc _td_OOC_Package__730 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 32, 32, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_OOC_Package__Executable = { (RT0__Struct[]){&_td_OOC_Package__ExecutableDesc}, NULL, NULL, &_mid, "Executable", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_Package__ExecutableDesc = { (RT0__Struct[]){&_td_RT0__ObjectDesc,&_td_Object__ObjectDesc,&_td_OOC_Package__ExecutableDesc}, (void*[]){(void*)RT0__ObjectDesc_Finalize,(void*)Object__ObjectDesc_ToString,(void*)Object__ObjectDesc_Equals,(void*)Object__ObjectDesc_HashCode}, NULL, &_mid, "ExecutableDesc", 4, 2, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_Package__Library = { (RT0__Struct[]){&_td_OOC_Package__LibraryDesc}, NULL, NULL, &_mid, "Library", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_Package__LibraryDesc = { (RT0__Struct[]){&_td_RT0__ObjectDesc,&_td_Object__ObjectDesc,&_td_OOC_Package__LibraryDesc}, (void*[]){(void*)RT0__ObjectDesc_Finalize,(void*)Object__ObjectDesc_ToString,(void*)Object__ObjectDesc_Equals,(void*)Object__ObjectDesc_HashCode}, NULL, &_mid, "LibraryDesc", 12, 2, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_Package__FileData = { (RT0__Struct[]){&_td_OOC_Package__FileDataDesc}, NULL, NULL, &_mid, "FileData", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_Package__FileDataDesc = { (RT0__Struct[]){&_td_OOC_Package__FileDataDesc}, (void*[]){}, NULL, &_mid, "FileDataDesc", 4, 0, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_Package__File = { (RT0__Struct[]){&_td_OOC_Package__FileDesc}, NULL, NULL, &_mid, "File", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_Package__FileDesc = { (RT0__Struct[]){&_td_OOC_Package__FileDataDesc,&_td_OOC_Package__FileDesc}, (void*[]){}, NULL, &_mid, "FileDesc", 12, 1, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_Package__FileSet = { (RT0__Struct[]){&_td_OOC_Package__FileSetDesc}, NULL, NULL, &_mid, "FileSet", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_Package__FileSetDesc = { (RT0__Struct[]){&_td_OOC_Package__FileDataDesc,&_td_OOC_Package__FileSetDesc}, (void*[]){(void*)OOC_Package__FileSetDesc_Append}, NULL, &_mid, "FileSetDesc", 20, 1, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_Package__KeyValue = { (RT0__Struct[]){&_td_OOC_Package__KeyValueDesc}, NULL, NULL, &_mid, "KeyValue", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_Package__KeyValueDesc = { (RT0__Struct[]){&_td_RT0__ObjectDesc,&_td_Object__ObjectDesc,&_td_OOC_Package__KeyValueDesc}, (void*[]){(void*)RT0__ObjectDesc_Finalize,(void*)Object__ObjectDesc_ToString,(void*)Object__ObjectDesc_Equals,(void*)Object__ObjectDesc_HashCode}, NULL, &_mid, "KeyValueDesc", 8, 2, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_Package__Package = { (RT0__Struct[]){&_td_OOC_Package__PackageDesc}, NULL, NULL, &_mid, "Package", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_Package__PackageDesc = { (RT0__Struct[]){&_td_OOC_Repository__PkgInfoDesc,&_td_OOC_Package__PackageDesc}, (void*[]){}, NULL, &_mid, "PackageDesc", 28, 1, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_Package__Repository = { (RT0__Struct[]){&_td_OOC_Package__RepositoryDesc}, NULL, NULL, &_mid, "Repository", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_Package__RepositoryDesc = { (RT0__Struct[]){&_td_OOC_Repository__PkgInfoDesc,&_td_OOC_Package__RepositoryDesc}, (void*[]){(void*)OOC_Package__RepositoryDesc_MergePackage,(void*)OOC_Package__RepositoryDesc_PackageInstalled}, NULL, &_mid, "RepositoryDesc", 12, 1, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_Package__ErrorContext = { (RT0__Struct[]){&_td_OOC_Package__ErrorContextDesc}, NULL, NULL, &_mid, "ErrorContext", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_Package__ErrorContextDesc = { (RT0__Struct[]){&_td_Msg__ContextDesc,&_td_XML_Error__ContextDesc,&_td_OOC_Package__ErrorContextDesc}, (void*[]){(void*)OOC_Package__ErrorContextDesc_GetTemplate,(void*)XML_Error__ContextDesc_WriteTemplate,(void*)XML_Error__ContextDesc_SetString}, NULL, &_mid, "ErrorContextDesc", 8, 2, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_Package__3008 = { (RT0__Struct[]){&RT0__longchar}, NULL, NULL, &_mid, NULL, 256, 128, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_OOC_Package__8680 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_OOC_Package__8669 = { (RT0__Struct[]){&_td_OOC_Package__8680}, NULL, NULL, &_mid, NULL, 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_Package__14056 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_OOC_Package__14045 = { (RT0__Struct[]){&_td_OOC_Package__14056}, NULL, NULL, &_mid, NULL, 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_Package__14323 = { (RT0__Struct[]){&RT0__longchar}, NULL, NULL, &_mid, NULL, 2, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_OOC_Package__15886 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1024, 1024, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_OOC_Package__19021 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 32, 32, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_OOC_Package__19223 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 128, 128, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_OOC_Package__32131 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_OOC_Package__32249 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 32, 32, (1<<RT0__flagAtomic), RT0__strArray };
static RT0__StructDesc _td__qtd0 = { (RT0__Struct[]){&_td_RT0__ObjectDesc,&_td_Object__ObjectDesc,&_td_ADT_Storable__ObjectDesc,&_td__qtd0}, (void*[]){(void*)RT0__ObjectDesc_Finalize,(void*)Object__ObjectDesc_ToString,(void*)ADT_ArrayList__ArrayListDesc_Equals,(void*)ADT_ArrayList__ArrayListDesc_HashCode,(void*)ADT_ArrayList__ArrayListDesc_Store,(void*)ADT_ArrayList__ArrayListDesc_Load,(void*)ADT_ArrayList__ArrayListDesc_CreateArray,(void*)ADT_ArrayList__ArrayListDesc_INIT,(void*)ADT_ArrayList__ArrayListDesc_Destroy,(void*)ADT_ArrayList__ArrayListDesc_Copy,(void*)ADT_ArrayList__ArrayListDesc_EnsureCapacity,(void*)ADT_ArrayList__ArrayListDesc_Clear,(void*)ADT_ArrayList__ArrayListDesc_Append,(void*)ADT_ArrayList__ArrayListDesc_Insert,(void*)ADT_ArrayList__ArrayListDesc_Get,(void*)ADT_ArrayList__ArrayListDesc_Set,(void*)ADT_ArrayList__ArrayListDesc_RemoveRange,(void*)ADT_ArrayList__ArrayListDesc_Remove,(void*)ADT_ArrayList__ArrayListDesc_TrimToSize,(void*)ADT_ArrayList__ArrayListDesc_Size,(void*)ADT_ArrayList__ArrayListDesc_Contains,(void*)ADT_ArrayList__ArrayListDesc_IndexOf,(void*)ADT_ArrayList__ArrayListDesc_LastIndexOf,(void*)ADT_ArrayList__ArrayListDesc_IsEmpty,(void*)ADT_ArrayList__ArrayListDesc_Sort,(void*)ADT_ArrayList__ArrayListDesc_Elements,(void*)ADT_ArrayList__ArrayListDesc_IterElements}, (RT0__Struct[]){&_td_ADT_ArrayList__ArrayListDesc, &_td_OOC_Package__Library, NULL}, &_mid, "ADT:ArrayList.ArrayListDesc(OOC:Package.Library)", 8, 3, 0, RT0__strQualType };
static RT0__StructDesc _td__qtd1 = { (RT0__Struct[]){&_td__qtd0}, NULL, (RT0__Struct[]){&_td_ADT_ArrayList__ArrayList, &_td_OOC_Package__Library, NULL}, &_mid, "ADT:ArrayList.ArrayList(OOC:Package.Library)", 4, 0, 0, RT0__strQualType };
static RT0__StructDesc _td__qtd2 = { (RT0__Struct[]){&_td_RT0__ObjectDesc,&_td_Object__ObjectDesc,&_td_ADT_Storable__ObjectDesc,&_td__qtd2}, (void*[]){(void*)RT0__ObjectDesc_Finalize,(void*)Object__ObjectDesc_ToString,(void*)ADT_ArrayList__ArrayListDesc_Equals,(void*)ADT_ArrayList__ArrayListDesc_HashCode,(void*)ADT_ArrayList__ArrayListDesc_Store,(void*)ADT_ArrayList__ArrayListDesc_Load,(void*)ADT_ArrayList__ArrayListDesc_CreateArray,(void*)ADT_ArrayList__ArrayListDesc_INIT,(void*)ADT_ArrayList__ArrayListDesc_Destroy,(void*)ADT_ArrayList__ArrayListDesc_Copy,(void*)ADT_ArrayList__ArrayListDesc_EnsureCapacity,(void*)ADT_ArrayList__ArrayListDesc_Clear,(void*)ADT_ArrayList__ArrayListDesc_Append,(void*)ADT_ArrayList__ArrayListDesc_Insert,(void*)ADT_ArrayList__ArrayListDesc_Get,(void*)ADT_ArrayList__ArrayListDesc_Set,(void*)ADT_ArrayList__ArrayListDesc_RemoveRange,(void*)ADT_ArrayList__ArrayListDesc_Remove,(void*)ADT_ArrayList__ArrayListDesc_TrimToSize,(void*)ADT_ArrayList__ArrayListDesc_Size,(void*)ADT_ArrayList__ArrayListDesc_Contains,(void*)ADT_ArrayList__ArrayListDesc_IndexOf,(void*)ADT_ArrayList__ArrayListDesc_LastIndexOf,(void*)ADT_ArrayList__ArrayListDesc_IsEmpty,(void*)ADT_ArrayList__ArrayListDesc_Sort,(void*)ADT_ArrayList__ArrayListDesc_Elements,(void*)ADT_ArrayList__ArrayListDesc_IterElements}, (RT0__Struct[]){&_td_ADT_ArrayList__ArrayListDesc, &_td_OOC_Package__Executable, NULL}, &_mid, "ADT:ArrayList.ArrayListDesc(OOC:Package.Executable)", 8, 3, 0, RT0__strQualType };
static RT0__StructDesc _td__qtd3 = { (RT0__Struct[]){&_td__qtd2}, NULL, (RT0__Struct[]){&_td_ADT_ArrayList__ArrayList, &_td_OOC_Package__Executable, NULL}, &_mid, "ADT:ArrayList.ArrayList(OOC:Package.Executable)", 4, 0, 0, RT0__strQualType };
static RT0__StructDesc _td__qtd4 = { (RT0__Struct[]){&_td_RT0__ObjectDesc,&_td_Object__ObjectDesc,&_td_ADT_Storable__ObjectDesc,&_td__qtd4}, (void*[]){(void*)RT0__ObjectDesc_Finalize,(void*)Object__ObjectDesc_ToString,(void*)ADT_ArrayList__ArrayListDesc_Equals,(void*)ADT_ArrayList__ArrayListDesc_HashCode,(void*)ADT_ArrayList__ArrayListDesc_Store,(void*)ADT_ArrayList__ArrayListDesc_Load,(void*)ADT_ArrayList__ArrayListDesc_CreateArray,(void*)ADT_ArrayList__ArrayListDesc_INIT,(void*)ADT_ArrayList__ArrayListDesc_Destroy,(void*)ADT_ArrayList__ArrayListDesc_Copy,(void*)ADT_ArrayList__ArrayListDesc_EnsureCapacity,(void*)ADT_ArrayList__ArrayListDesc_Clear,(void*)ADT_ArrayList__ArrayListDesc_Append,(void*)ADT_ArrayList__ArrayListDesc_Insert,(void*)ADT_ArrayList__ArrayListDesc_Get,(void*)ADT_ArrayList__ArrayListDesc_Set,(void*)ADT_ArrayList__ArrayListDesc_RemoveRange,(void*)ADT_ArrayList__ArrayListDesc_Remove,(void*)ADT_ArrayList__ArrayListDesc_TrimToSize,(void*)ADT_ArrayList__ArrayListDesc_Size,(void*)ADT_ArrayList__ArrayListDesc_Contains,(void*)ADT_ArrayList__ArrayListDesc_IndexOf,(void*)ADT_ArrayList__ArrayListDesc_LastIndexOf,(void*)ADT_ArrayList__ArrayListDesc_IsEmpty,(void*)ADT_ArrayList__ArrayListDesc_Sort,(void*)ADT_ArrayList__ArrayListDesc_Elements,(void*)ADT_ArrayList__ArrayListDesc_IterElements}, (RT0__Struct[]){&_td_ADT_ArrayList__ArrayListDesc, &_td_Object__String, NULL}, &_mid, "ADT:ArrayList.ArrayListDesc(Object.String)", 8, 3, 0, RT0__strQualType };
static RT0__StructDesc _td__qtd5 = { (RT0__Struct[]){&_td__qtd4}, NULL, (RT0__Struct[]){&_td_ADT_ArrayList__ArrayList, &_td_Object__String, NULL}, &_mid, "ADT:ArrayList.ArrayList(Object.String)", 4, 0, 0, RT0__strQualType };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:Package", (RT0__Struct[]) { &_td_OOC_Package__Version, &_td_OOC_Package__VersionDesc, &_td_OOC_Package__Executable, &_td_OOC_Package__ExecutableDesc, &_td_OOC_Package__Library, &_td_OOC_Package__LibraryDesc, &_td_OOC_Package__FileData, &_td_OOC_Package__FileDataDesc, &_td_OOC_Package__File, &_td_OOC_Package__FileDesc, &_td_OOC_Package__FileSet, &_td_OOC_Package__FileSetDesc, &_td_OOC_Package__KeyValue, &_td_OOC_Package__KeyValueDesc, &_td_OOC_Package__Package, &_td_OOC_Package__PackageDesc, &_td_OOC_Package__Repository, &_td_OOC_Package__RepositoryDesc, &_td_OOC_Package__ErrorContext, &_td_OOC_Package__ErrorContextDesc, &_td__qtd0, &_td__qtd1, &_td__qtd2, &_td__qtd3, &_td__qtd4, &_td__qtd5, NULL } };

extern void OOC_OOC_Package_init0() {
  RT0__RegisterModule(&_mid);
  OOC_OOC_Package_init();
}

/* --- */
