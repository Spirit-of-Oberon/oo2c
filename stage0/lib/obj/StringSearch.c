#include <StringSearch.d>
#include <__oo2c.h>
#include <setjmp.h>

void StringSearch__InitMatchObject(StringSearch__MatchObject m, OOC_INT32 pos, OOC_INT32 endpos, StringSearch__Matcher matcher, Object__String8 string) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)m;
  i1 = pos;
  *(OOC_INT32*)(_check_pointer(i0, 3860)) = i1;
  i1 = endpos;
  *(OOC_INT32*)((_check_pointer(i0, 3879))+4) = i1;
  i1 = (OOC_INT32)matcher;
  *(OOC_INT32*)((_check_pointer(i0, 3904))+8) = i1;
  i1 = (OOC_INT32)string;
  *(OOC_INT32*)((_check_pointer(i0, 3931))+12) = i1;
  return;
  ;
}

void StringSearch__MatchObjectDesc_Destroy(StringSearch__MatchObject m) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)m;
  *(OOC_INT32*)(_check_pointer(i0, 4025)) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 4042))+4) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 4062))+8) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 4085))+12) = 0;
  return;
  ;
}

OOC_INT32 StringSearch__MatchObjectDesc_Start(StringSearch__MatchObject m, OOC_INT32 group) {

  _failed_function(4156); return 0;
  ;
}

OOC_INT32 StringSearch__MatchObjectDesc_End(StringSearch__MatchObject m, OOC_INT32 group) {

  _failed_function(4957); return 0;
  ;
}

void StringSearch__InitMatcher(StringSearch__Matcher matcher, Object__String8 pattern, OOC_UINT32 flags, OOC_INT32 groups) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)matcher;
  i1 = (OOC_INT32)pattern;
  *(OOC_INT32*)(_check_pointer(i0, 5234)) = i1;
  i1 = flags;
  *(OOC_UINT32*)((_check_pointer(i0, 5267))+4) = i1;
  i1 = groups;
  *(OOC_INT32*)((_check_pointer(i0, 5296))+8) = i1;
  return;
  ;
}

void StringSearch__MatcherDesc_Destroy(StringSearch__Matcher matcher) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)matcher;
  *(OOC_INT32*)(_check_pointer(i0, 5394)) = 0;
  *(OOC_UINT32*)((_check_pointer(i0, 5423))+4) = 0u;
  *(OOC_INT32*)((_check_pointer(i0, 5449))+8) = 0;
  return;
  ;
}

StringSearch__MatchObject StringSearch__MatcherDesc_MatchChars(StringSearch__Matcher matcher, const OOC_CHAR8 string[], OOC_LEN string_0d, OOC_INT32 pos, OOC_INT32 endpos) {

  _failed_function(5520); return 0;
  ;
}

StringSearch__MatchObject StringSearch__MatcherDesc_Match(StringSearch__Matcher matcher, Object__String8 string, OOC_INT32 pos, OOC_INT32 endpos) {

  _failed_function(6802); return 0;
  ;
}

StringSearch__MatchObject StringSearch__MatcherDesc_SearchChars(StringSearch__Matcher matcher, const OOC_CHAR8 string[], OOC_LEN string_0d, OOC_INT32 pos, OOC_INT32 endpos) {

  _failed_function(7023); return 0;
  ;
}

StringSearch__MatchObject StringSearch__MatcherDesc_Search(StringSearch__Matcher matcher, Object__String8 string, OOC_INT32 pos, OOC_INT32 endpos) {

  _failed_function(7613); return 0;
  ;
}

void StringSearch__InitFactory(StringSearch__Factory f) {

  return;
  ;
}

void StringSearch__FactoryDesc_Destroy(StringSearch__Factory f) {

  return;
  ;
}

StringSearch__Matcher StringSearch__FactoryDesc_Compile(StringSearch__Factory f, Object__String8 pattern, OOC_UINT32 flags) {

  _failed_function(7955); return 0;
  ;
}

void OOC_StringSearch_init(void) {

  return;
  ;
}

void OOC_StringSearch_destroy(void) {
}

/* --- */
