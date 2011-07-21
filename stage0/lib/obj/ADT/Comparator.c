#include <ADT/Comparator.d>
#include <__oo2c.h>
#include <setjmp.h>

OOC_INT32 ADT_Comparator__ComparatorDesc_Compare(ADT_Comparator__Comparator cmp, Object__Object o1, Object__Object o2) {

  _failed_function(1362); return 0;
  ;
}

OOC_INT32 ADT_Comparator__StringDesc_Compare(ADT_Comparator__String cmp, Object__Object o1, Object__Object o2) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)o2;
  i1 = (OOC_INT32)o1;
  i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 2582)))), &_td_Object__StringDesc, 2582)), 2589)))), Object__StringDesc_Compare)),Object__StringDesc_Compare)((Object__String)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 2582)))), &_td_Object__StringDesc, 2582)), (Object__Object)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2608)))), &_td_Object__StringDesc, 2608)));
  return i0;
  ;
}

void OOC_ADT_Comparator_init(void) {

  return;
  ;
}

/* --- */
