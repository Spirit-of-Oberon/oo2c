#include <OOC/Config/StdPragmas.d>
#include <__oo2c.h>
#include <setjmp.h>

void OOC_Config_StdPragmas__CreateVariables(OOC_Config_Pragmas__Section s) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)Config__NewBooleanVar(1u);
  i1 = (OOC_INT32)s;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 2655)))), Config_Section_Options__SectionDesc_Set)),Config_Section_Options__SectionDesc_Set)((Config_Section_Options__Section)i1, (Object__String)((OOC_INT32)_c0), (Config__Variable)i0);
  OOC_Config_StdPragmas__warnings = (Config_Section_Options__Option)i0;
  i0 = (OOC_INT32)Config__NewBooleanVar(1u);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 2733)))), Config_Section_Options__SectionDesc_Set)),Config_Section_Options__SectionDesc_Set)((Config_Section_Options__Section)i1, (Object__String)((OOC_INT32)_c1), (Config__Variable)i0);
  OOC_Config_StdPragmas__assertions = (Config_Section_Options__Option)i0;
  i0 = (OOC_INT32)Config__NewBooleanVar(0u);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 2901)))), Config_Section_Options__SectionDesc_Set)),Config_Section_Options__SectionDesc_Set)((Config_Section_Options__Section)i1, (Object__String)((OOC_INT32)_c2), (Config__Variable)i0);
  OOC_Config_StdPragmas__stackCheck = (Config_Section_Options__Option)i0;
  i0 = (OOC_INT32)Config__NewBooleanVar(0u);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 2987)))), Config_Section_Options__SectionDesc_Set)),Config_Section_Options__SectionDesc_Set)((Config_Section_Options__Section)i1, (Object__String)((OOC_INT32)_c3), (Config__Variable)i0);
  OOC_Config_StdPragmas__conformantMode = (Config_Section_Options__Option)i0;
  i0 = (OOC_INT32)Config__NewBooleanVar(1u);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3082)))), Config_Section_Options__SectionDesc_Set)),Config_Section_Options__SectionDesc_Set)((Config_Section_Options__Section)i1, (Object__String)((OOC_INT32)_c4), (Config__Variable)i0);
  OOC_Config_StdPragmas__indexCheck = (Config_Section_Options__Option)i0;
  i0 = (OOC_INT32)Config__NewBooleanVar(1u);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3164)))), Config_Section_Options__SectionDesc_Set)),Config_Section_Options__SectionDesc_Set)((Config_Section_Options__Section)i1, (Object__String)((OOC_INT32)_c5), (Config__Variable)i0);
  OOC_Config_StdPragmas__derefCheck = (Config_Section_Options__Option)i0;
  i0 = (OOC_INT32)Config__NewBooleanVar(0u);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3249)))), Config_Section_Options__SectionDesc_Set)),Config_Section_Options__SectionDesc_Set)((Config_Section_Options__Section)i1, (Object__String)((OOC_INT32)_c6), (Config__Variable)i0);
  OOC_Config_StdPragmas__overflowCheck = (Config_Section_Options__Option)i0;
  i0 = (OOC_INT32)Config__NewBooleanVar(1u);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3342)))), Config_Section_Options__SectionDesc_Set)),Config_Section_Options__SectionDesc_Set)((Config_Section_Options__Section)i1, (Object__String)((OOC_INT32)_c7), (Config__Variable)i0);
  OOC_Config_StdPragmas__caseSelectCheck = (Config_Section_Options__Option)i0;
  i0 = (OOC_INT32)Config__NewBooleanVar(1u);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3443)))), Config_Section_Options__SectionDesc_Set)),Config_Section_Options__SectionDesc_Set)((Config_Section_Options__Section)i1, (Object__String)((OOC_INT32)_c8), (Config__Variable)i0);
  OOC_Config_StdPragmas__functionResultCheck = (Config_Section_Options__Option)i0;
  i0 = (OOC_INT32)Config__NewBooleanVar(1u);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3534)))), Config_Section_Options__SectionDesc_Set)),Config_Section_Options__SectionDesc_Set)((Config_Section_Options__Section)i1, (Object__String)((OOC_INT32)_c9), (Config__Variable)i0);
  OOC_Config_StdPragmas__typeGuard = (Config_Section_Options__Option)i0;
  i0 = (OOC_INT32)Config__NewBooleanVar(0u);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3614)))), Config_Section_Options__SectionDesc_Set)),Config_Section_Options__SectionDesc_Set)((Config_Section_Options__Section)i1, (Object__String)((OOC_INT32)_c10), (Config__Variable)i0);
  OOC_Config_StdPragmas__rangeCheck = (Config_Section_Options__Option)i0;
  i0 = (OOC_INT32)Config__NewStringVar((Object__String8)((OOC_INT32)_c11));
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3699)))), Config_Section_Options__SectionDesc_Set)),Config_Section_Options__SectionDesc_Set)((Config_Section_Options__Section)i1, (Object__String)((OOC_INT32)_c12), (Config__Variable)i0);
  OOC_Config_StdPragmas__compiler = (Config_Section_Options__Option)i0;
  i0 = (OOC_INT32)Config__NewStringVar((Object__String8)((OOC_INT32)_c13));
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3781)))), Config_Section_Options__SectionDesc_Set)),Config_Section_Options__SectionDesc_Set)((Config_Section_Options__Section)i1, (Object__String)((OOC_INT32)_c14), (Config__Variable)i0);
  OOC_Config_StdPragmas__compilerVersion = (Config_Section_Options__Option)i0;
  i0 = (OOC_INT32)Config__NewIntegerVar(2);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3876)))), Config_Section_Options__SectionDesc_Set)),Config_Section_Options__SectionDesc_Set)((Config_Section_Options__Section)i1, (Object__String)((OOC_INT32)_c15), (Config__Variable)i0);
  OOC_Config_StdPragmas__compilerMajor = (Config_Section_Options__Option)i0;
  i0 = (OOC_INT32)Config__NewIntegerVar(1);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3968)))), Config_Section_Options__SectionDesc_Set)),Config_Section_Options__SectionDesc_Set)((Config_Section_Options__Section)i1, (Object__String)((OOC_INT32)_c16), (Config__Variable)i0);
  OOC_Config_StdPragmas__compilerMinor = (Config_Section_Options__Option)i0;
  i0 = (OOC_INT32)Config__NewStringVar((Object__String8)((OOC_INT32)_c17));
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 4060)))), Config_Section_Options__SectionDesc_Set)),Config_Section_Options__SectionDesc_Set)((Config_Section_Options__Section)i1, (Object__String)((OOC_INT32)_c18), (Config__Variable)i0);
  OOC_Config_StdPragmas__targetOS = (Config_Section_Options__Option)i0;
  i0 = (OOC_INT32)Config__NewStringVar((Object__String8)((OOC_INT32)_c19));
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 4138)))), Config_Section_Options__SectionDesc_Set)),Config_Section_Options__SectionDesc_Set)((Config_Section_Options__Section)i1, (Object__String)((OOC_INT32)_c20), (Config__Variable)i0);
  OOC_Config_StdPragmas__targetArch = (Config_Section_Options__Option)i0;
  i0 = (OOC_INT32)Config__NewStringVar((Object__String8)((OOC_INT32)_c21));
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 4225)))), Config_Section_Options__SectionDesc_Set)),Config_Section_Options__SectionDesc_Set)((Config_Section_Options__Section)i1, (Object__String)((OOC_INT32)_c22), (Config__Variable)i0);
  OOC_Config_StdPragmas__targetArchMinor = (Config_Section_Options__Option)i0;
  i0 = (OOC_INT32)Config__NewIntegerVar(64);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 4321)))), Config_Section_Options__SectionDesc_Set)),Config_Section_Options__SectionDesc_Set)((Config_Section_Options__Section)i1, (Object__String)((OOC_INT32)_c23), (Config__Variable)i0);
  OOC_Config_StdPragmas__targetInteger = (Config_Section_Options__Option)i0;
  i0 = (OOC_INT32)Config__NewIntegerVar(32);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 4413)))), Config_Section_Options__SectionDesc_Set)),Config_Section_Options__SectionDesc_Set)((Config_Section_Options__Section)i1, (Object__String)((OOC_INT32)_c24), (Config__Variable)i0);
  OOC_Config_StdPragmas__targetAddress = (Config_Section_Options__Option)i0;
  i0 = (OOC_INT32)Config__NewStringVar((Object__String8)((OOC_INT32)_c25));
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 4507)))), Config_Section_Options__SectionDesc_Set)),Config_Section_Options__SectionDesc_Set)((Config_Section_Options__Section)i1, (Object__String)((OOC_INT32)_c26), (Config__Variable)i0);
  OOC_Config_StdPragmas__targetByteOrder = (Config_Section_Options__Option)i0;
  return;
  ;
}

void OOC_OOC_Config_StdPragmas_init(void) {
  _c0 = Object__NewLatin1Region("Warnings", 9, 0, 8);
  _c1 = Object__NewLatin1Region("Assertions", 11, 0, 10);
  _c2 = Object__NewLatin1Region("StackCheck", 11, 0, 10);
  _c3 = Object__NewLatin1Region("ConformantMode", 15, 0, 14);
  _c4 = Object__NewLatin1Region("IndexCheck", 11, 0, 10);
  _c5 = Object__NewLatin1Region("DerefCheck", 11, 0, 10);
  _c6 = Object__NewLatin1Region("OverflowCheck", 14, 0, 13);
  _c7 = Object__NewLatin1Region("CaseSelectCheck", 16, 0, 15);
  _c8 = Object__NewLatin1Region("FunctResult", 12, 0, 11);
  _c9 = Object__NewLatin1Region("TypeGuard", 10, 0, 9);
  _c10 = Object__NewLatin1Region("RangeCheck", 11, 0, 10);
  _c11 = Object__NewLatin1Region("OOC", 4, 0, 3);
  _c12 = Object__NewLatin1Region("COMPILER", 9, 0, 8);
  _c13 = Object__NewLatin1Region("2.1.4", 6, 0, 5);
  _c14 = Object__NewLatin1Region("COMPILER_VERSION", 17, 0, 16);
  _c15 = Object__NewLatin1Region("COMPILER_MAJOR", 15, 0, 14);
  _c16 = Object__NewLatin1Region("COMPILER_MINOR", 15, 0, 14);
  _c17 = Object__NewLatin1Region("Unix", 5, 0, 4);
  _c18 = Object__NewLatin1Region("TARGET_OS", 10, 0, 9);
  _c19 = Object__NewLatin1Region("gcc", 4, 0, 3);
  _c20 = Object__NewLatin1Region("TARGET_ARCH", 12, 0, 11);
  _c21 = Object__NewLatin1Region("", 1, 0, 0);
  _c22 = Object__NewLatin1Region("TARGET_ARCH_MINOR", 18, 0, 17);
  _c23 = Object__NewLatin1Region("TARGET_INTEGER", 15, 0, 14);
  _c24 = Object__NewLatin1Region("TARGET_ADDRESS", 15, 0, 14);
  _c25 = Object__NewLatin1Region("unknown", 8, 0, 7);
  _c26 = Object__NewLatin1Region("TARGET_BYTE_ORDER", 18, 0, 17);

  return;
  ;
}

/* --- */
