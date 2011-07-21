#include <StringSearch/NoMatch.d>
#include <__oo2c.h>
#include <setjmp.h>

static void StringSearch_NoMatch__InitMatcher(StringSearch_NoMatch__Matcher matcher, Object__String8 pattern, OOC_UINT32 flags, OOC_INT32 groups) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = groups;
  i1 = flags;
  i2 = (OOC_INT32)pattern;
  i3 = (OOC_INT32)matcher;
  StringSearch__InitMatcher((StringSearch__Matcher)i3, (Object__String8)i2, i1, i0);
  return;
  ;
}

static StringSearch_NoMatch__Matcher StringSearch_NoMatch__NewMatcher(Object__String8 pattern, OOC_UINT32 flags, OOC_INT32 groups) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)RT0__NewObject(_td_StringSearch_NoMatch__Matcher.baseTypes[0]);
  i1 = flags;
  i2 = (OOC_INT32)pattern;
  StringSearch_NoMatch__InitMatcher((StringSearch_NoMatch__Matcher)i0, (Object__String8)i2, i1, 0);
  return (StringSearch_NoMatch__Matcher)i0;
  ;
}

StringSearch__MatchObject StringSearch_NoMatch__MatcherDesc_MatchChars(StringSearch_NoMatch__Matcher matcher, const OOC_CHAR8 string[], OOC_LEN string_0d, OOC_INT32 pos, OOC_INT32 endpos) {

  return (StringSearch__MatchObject)(OOC_INT32)0;
  ;
}

StringSearch__MatchObject StringSearch_NoMatch__MatcherDesc_Match(StringSearch_NoMatch__Matcher matcher, Object__String8 string, OOC_INT32 pos, OOC_INT32 endpos) {

  return (StringSearch__MatchObject)(OOC_INT32)0;
  ;
}

StringSearch__MatchObject StringSearch_NoMatch__MatcherDesc_SearchChars(StringSearch_NoMatch__Matcher matcher, const OOC_CHAR8 string[], OOC_LEN string_0d, OOC_INT32 pos, OOC_INT32 endpos) {

  return (StringSearch__MatchObject)(OOC_INT32)0;
  ;
}

StringSearch__MatchObject StringSearch_NoMatch__MatcherDesc_Search(StringSearch_NoMatch__Matcher matcher, Object__String8 string, OOC_INT32 pos, OOC_INT32 endpos) {

  return (StringSearch__MatchObject)(OOC_INT32)0;
  ;
}

static void StringSearch_NoMatch__InitFactory(StringSearch_NoMatch__Factory f) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)f;
  StringSearch__InitFactory((StringSearch__Factory)i0);
  return;
  ;
}

static StringSearch_NoMatch__Factory StringSearch_NoMatch__NewFactory(void) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)RT0__NewObject(_td_StringSearch_NoMatch__Factory.baseTypes[0]);
  StringSearch_NoMatch__InitFactory((StringSearch_NoMatch__Factory)i0);
  return (StringSearch_NoMatch__Factory)i0;
  ;
}

StringSearch_NoMatch__Matcher StringSearch_NoMatch__FactoryDesc_Compile(StringSearch_NoMatch__Factory f, Object__String8 pattern, OOC_UINT32 flags) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)StringSearch_NoMatch__matcher;
  return (StringSearch_NoMatch__Matcher)i0;
  ;
}

void OOC_StringSearch_NoMatch_init(void) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)StringSearch_NoMatch__NewFactory();
  StringSearch_NoMatch__factory = (StringSearch_NoMatch__Factory)i0;
  i0 = (OOC_INT32)Object__NewLatin1("", 1);
  i0 = (OOC_INT32)StringSearch_NoMatch__NewMatcher((Object__String8)i0, 0u, 0);
  StringSearch_NoMatch__matcher = (StringSearch_NoMatch__Matcher)i0;
  return;
  ;
}

void OOC_StringSearch_NoMatch_destroy(void) {
}

/* --- */
