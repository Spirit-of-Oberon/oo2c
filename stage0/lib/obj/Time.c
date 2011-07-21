#include <Time.d>
#include <__oo2c.h>
#include <setjmp.h>

void Time__InitTimeStamp(struct Time__TimeStamp *t, RT0__Struct t__tag, OOC_INT32 days, OOC_INT32 msecs) {
  register OOC_INT32 i0,i1;

  i0 = msecs;
  i1 = days;
  *(OOC_INT32*)((OOC_INT32)t+4) = (_mod(i0,86400000));
  *(OOC_INT32*)(OOC_INT32)t = (i1+(_div(i0,86400000)));
  return;
  ;
}

void Time__GetTime(struct Time__TimeStamp *t, RT0__Struct t__tag) {
  register OOC_INT32 i0,i1;
  OOC_INT32 usec;
  OOC_INT32 sec;

  i0 = SysClock__GetTimeOfDay((void*)(OOC_INT32)&sec, (void*)(OOC_INT32)&usec);
  i0 = sec;
  i1 = usec;
  *(OOC_INT32*)(OOC_INT32)t = (40587+(_div(i0,86400)));
  *(OOC_INT32*)((OOC_INT32)t+4) = (((_mod(i0,86400))*1000)+(_div(i1,1000)));
  return;
  ;
}

void Time__TimeStamp_Add(struct Time__TimeStamp *a, RT0__Struct a__tag, const struct Time__Interval *b__ref) {
  register OOC_INT32 i0,i1,i2;
  OOC_ALLOCATE_VPAR(b,Time__Interval ,1)

  OOC_INITIALIZE_VPAR(b__ref,b,Time__Interval ,8)
  i0 = (OOC_INT32)a+4;
  i1 = *(OOC_INT32*)((OOC_INT32)b+4);
  i2 = *(OOC_INT32*)i0;
  *(OOC_INT32*)i0 = (i2+i1);
  i1 = *(OOC_INT32*)(OOC_INT32)a;
  i2 = *(OOC_INT32*)(OOC_INT32)b;
  *(OOC_INT32*)(OOC_INT32)a = (i1+i2);
  i1 = *(OOC_INT32*)i0;
  i2 = i1>=86400000;
  if (!i2) goto l4;
  *(OOC_INT32*)i0 = (i1-86400000);
  i0 = *(OOC_INT32*)(OOC_INT32)a;
  *(OOC_INT32*)(OOC_INT32)a = (i0+1);
l4:
  return;
  ;
}

void Time__TimeStamp_Sub(struct Time__TimeStamp *a, RT0__Struct a__tag, const struct Time__Interval *b__ref) {
  register OOC_INT32 i0,i1,i2;
  OOC_ALLOCATE_VPAR(b,Time__Interval ,1)

  OOC_INITIALIZE_VPAR(b__ref,b,Time__Interval ,8)
  i0 = (OOC_INT32)a+4;
  i1 = *(OOC_INT32*)((OOC_INT32)b+4);
  i2 = *(OOC_INT32*)i0;
  *(OOC_INT32*)i0 = (i2-i1);
  i1 = *(OOC_INT32*)(OOC_INT32)a;
  i2 = *(OOC_INT32*)(OOC_INT32)b;
  *(OOC_INT32*)(OOC_INT32)a = (i1-i2);
  i1 = *(OOC_INT32*)i0;
  i2 = i1<0;
  if (!i2) goto l4;
  *(OOC_INT32*)i0 = (i1+86400000);
  i0 = *(OOC_INT32*)(OOC_INT32)a;
  *(OOC_INT32*)(OOC_INT32)a = (i0-1);
l4:
  return;
  ;
}

void Time__TimeStamp_Delta(struct Time__TimeStamp *a, RT0__Struct a__tag, const struct Time__TimeStamp *b__ref, struct Time__Interval *c, RT0__Struct c__tag) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_ALLOCATE_VPAR(b,Time__TimeStamp ,1)

  OOC_INITIALIZE_VPAR(b__ref,b,Time__TimeStamp ,8)
  i0 = *(OOC_INT32*)((OOC_INT32)b+4);
  i1 = *(OOC_INT32*)((OOC_INT32)a+4);
  i2 = (OOC_INT32)c+4;
  i3 = *(OOC_INT32*)(OOC_INT32)a;
  i4 = *(OOC_INT32*)(OOC_INT32)b;
  *(OOC_INT32*)i2 = (i1-i0);
  *(OOC_INT32*)(OOC_INT32)c = (i3-i4);
  i0 = *(OOC_INT32*)i2;
  i1 = i0<0;
  if (!i1) goto l4;
  *(OOC_INT32*)i2 = (i0+86400000);
  i0 = *(OOC_INT32*)(OOC_INT32)c;
  *(OOC_INT32*)(OOC_INT32)c = (i0-1);
l4:
  return;
  ;
}

OOC_INT8 Time__TimeStamp_Cmp(struct Time__TimeStamp *a, RT0__Struct a__tag, const struct Time__TimeStamp *b__ref) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_ALLOCATE_VPAR(b,Time__TimeStamp ,1)

  OOC_INITIALIZE_VPAR(b__ref,b,Time__TimeStamp ,8)
  i0 = *(OOC_INT32*)(OOC_INT32)a;
  i1 = *(OOC_INT32*)(OOC_INT32)b;
  i2 = i0>i1;
  if (i2) goto l7;
  i2 = i0==i1;
  if (i2) goto l5;
  i2=0u;
  goto l9;
l5:
  i2 = *(OOC_INT32*)((OOC_INT32)a+4);
  i3 = *(OOC_INT32*)((OOC_INT32)b+4);
  i2 = i2>i3;
  
  goto l9;
l7:
  i2=1u;
l9:
  if (i2) goto l19;
  i0 = i0==i1;
  if (i0) goto l13;
  i0=0u;
  goto l15;
l13:
  i0 = *(OOC_INT32*)((OOC_INT32)a+4);
  i1 = *(OOC_INT32*)((OOC_INT32)b+4);
  i0 = i0==i1;
  
l15:
  if (i0) goto l17;
  return (-1);
  goto l20;
l17:
  return 0;
  goto l20;
l19:
  return 1;
l20:
  _failed_function(4155); return 0;
  ;
}

void Time__InitInterval(struct Time__Interval *_int, RT0__Struct _int__tag, OOC_INT32 days, OOC_INT32 msecs) {
  register OOC_INT32 i0,i1;

  i0 = msecs;
  i1 = days;
  *(OOC_INT32*)(OOC_INT32)_int = (i1+(_div(i0,86400000)));
  *(OOC_INT32*)((OOC_INT32)_int+4) = (_mod(i0,86400000));
  return;
  ;
}

void Time__Interval_Add(struct Time__Interval *a, RT0__Struct a__tag, const struct Time__Interval *b__ref) {
  register OOC_INT32 i0,i1,i2;
  OOC_ALLOCATE_VPAR(b,Time__Interval ,1)

  OOC_INITIALIZE_VPAR(b__ref,b,Time__Interval ,8)
  i0 = (OOC_INT32)a+4;
  i1 = *(OOC_INT32*)((OOC_INT32)b+4);
  i2 = *(OOC_INT32*)i0;
  *(OOC_INT32*)i0 = (i2+i1);
  i1 = *(OOC_INT32*)(OOC_INT32)a;
  i2 = *(OOC_INT32*)(OOC_INT32)b;
  *(OOC_INT32*)(OOC_INT32)a = (i1+i2);
  i1 = *(OOC_INT32*)i0;
  i2 = i1>=86400000;
  if (!i2) goto l4;
  *(OOC_INT32*)i0 = (i1-86400000);
  i0 = *(OOC_INT32*)(OOC_INT32)a;
  *(OOC_INT32*)(OOC_INT32)a = (i0+1);
l4:
  return;
  ;
}

void Time__Interval_Sub(struct Time__Interval *a, RT0__Struct a__tag, const struct Time__Interval *b__ref) {
  register OOC_INT32 i0,i1,i2;
  OOC_ALLOCATE_VPAR(b,Time__Interval ,1)

  OOC_INITIALIZE_VPAR(b__ref,b,Time__Interval ,8)
  i0 = (OOC_INT32)a+4;
  i1 = *(OOC_INT32*)((OOC_INT32)b+4);
  i2 = *(OOC_INT32*)i0;
  *(OOC_INT32*)i0 = (i2-i1);
  i1 = *(OOC_INT32*)(OOC_INT32)a;
  i2 = *(OOC_INT32*)(OOC_INT32)b;
  *(OOC_INT32*)(OOC_INT32)a = (i1-i2);
  i1 = *(OOC_INT32*)i0;
  i2 = i1<0;
  if (!i2) goto l4;
  *(OOC_INT32*)i0 = (i1+86400000);
  i0 = *(OOC_INT32*)(OOC_INT32)a;
  *(OOC_INT32*)(OOC_INT32)a = (i0-1);
l4:
  return;
  ;
}

OOC_INT8 Time__Interval_Cmp(struct Time__Interval *a, RT0__Struct a__tag, const struct Time__Interval *b__ref) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_ALLOCATE_VPAR(b,Time__Interval ,1)

  OOC_INITIALIZE_VPAR(b__ref,b,Time__Interval ,8)
  i0 = *(OOC_INT32*)(OOC_INT32)a;
  i1 = *(OOC_INT32*)(OOC_INT32)b;
  i2 = i0>i1;
  if (i2) goto l7;
  i2 = i0==i1;
  if (i2) goto l5;
  i2=0u;
  goto l9;
l5:
  i2 = *(OOC_INT32*)((OOC_INT32)a+4);
  i3 = *(OOC_INT32*)((OOC_INT32)b+4);
  i2 = i2>i3;
  
  goto l9;
l7:
  i2=1u;
l9:
  if (i2) goto l19;
  i0 = i0==i1;
  if (i0) goto l13;
  i0=0u;
  goto l15;
l13:
  i0 = *(OOC_INT32*)((OOC_INT32)a+4);
  i1 = *(OOC_INT32*)((OOC_INT32)b+4);
  i0 = i0==i1;
  
l15:
  if (i0) goto l17;
  return (-1);
  goto l20;
l17:
  return 0;
  goto l20;
l19:
  return 1;
l20:
  _failed_function(5660); return 0;
  ;
}

void Time__Interval_Scale(struct Time__Interval *a, RT0__Struct a__tag, OOC_REAL64 b) {
  register OOC_INT32 i0,i1,i2;
  register OOC_REAL64 d0;

  i0 = (OOC_INT32)a+4;
  i1 = *(OOC_INT32*)i0;
  i2 = *(OOC_INT32*)(OOC_INT32)a;
  d0 = b;
  d0 = ((OOC_REAL64)(((OOC_REAL32)i2)+(((OOC_REAL32)i1)/8.6400000000000000E+7f)))*d0;
  i1 = _entier(d0);
  *(OOC_INT32*)(OOC_INT32)a = i1;
  *(OOC_INT32*)i0 = (_entier((((d0-((OOC_REAL64)i1))*8.6400000000000000E+7)+5.0000000000000000E-1)));
  return;
  ;
}

OOC_REAL64 Time__Interval_Fraction(struct Time__Interval *a, RT0__Struct a__tag, const struct Time__Interval *b__ref) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_ALLOCATE_VPAR(b,Time__Interval ,1)

  OOC_INITIALIZE_VPAR(b__ref,b,Time__Interval ,8)
  i0 = *(OOC_INT32*)((OOC_INT32)b+4);
  i1 = *(OOC_INT32*)((OOC_INT32)a+4);
  i2 = *(OOC_INT32*)(OOC_INT32)a;
  i3 = *(OOC_INT32*)(OOC_INT32)b;
  return ((OOC_REAL64)((((OOC_REAL32)i2)+(((OOC_REAL32)i1)/8.6400000000000000E+7f))/(((OOC_REAL32)i3)+(((OOC_REAL32)i0)/8.6400000000000000E+7f))));
  ;
}

void OOC_Time_init(void) {

  return;
  ;
}

/* --- */
