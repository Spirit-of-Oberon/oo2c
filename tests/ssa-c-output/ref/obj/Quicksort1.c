#include <Quicksort1.d>
#include <__oo2c.h>
#include <setjmp.h>

void Quicksort1__Sort(OOC_INT32 a[], OOC_LEN a_0d, OOC_INT32 m, OOC_INT32 n) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8,i9,i10;

  i0 = n;
  i1 = m;
  i2 = i0>i1;
  if (!i2) goto l18;
  i2 = (OOC_INT32)a+i0*4;
  i3 = *(OOC_INT32*)i2;
  i4 = i1-1;
  i5=i0;
l3_loop:
  i4 = 4+((OOC_INT32)a+(4*i4));
  
l4_loop:
  i6 = i4+4;
  i7 = *(OOC_INT32*)i4;
  i8 = i7>=i3;
  if (i8) goto l8;
  i4=i6;
  goto l4_loop;
l8:
  i5 = (-4)+((OOC_INT32)a+(4*i5));
  
l9_loop:
  i8 = i5-4;
  i9 = *(OOC_INT32*)i5;
  i10 = i9<=i3;
  if (i10) goto l13;
  i5=i8;
  goto l9_loop;
l13:
  i6 = ((i6-4)-(OOC_INT32)a)>>2;
  i10 = ((i8-(-4))-(OOC_INT32)a)>>2;
  i8 = (OOC_UINT32)((-4)+((OOC_INT32)a+(4*i6)))>=(OOC_UINT32)i8;
  if (i8) goto l17;
  *(OOC_INT32*)i4 = i9;
  *(OOC_INT32*)i5 = i7;
  i4=i6;i5=i10;
  goto l3_loop;
l17:
  i3 = *(OOC_INT32*)i2;
  *(OOC_INT32*)i4 = i3;
  *(OOC_INT32*)i2 = i7;
  Quicksort1__Sort((void*)(OOC_INT32)a, a_0d, i1, i10);
  Quicksort1__Sort((void*)(OOC_INT32)a, a_0d, (i6+1), i0);
l18:
  return;
  ;
}

void Quicksort1__Test() {
  register OOC_INT32 i0,i1,i2;
  OOC_INT32 a[64];

  i0 = (OOC_INT32)a+252;
  i1=(OOC_INT32)a;
l1_loop:
  i2 = RandomNumbers__RND(64);
  *(OOC_INT32*)i1 = i2;
  i1 = i1+4;
  i2 = (OOC_UINT32)i1<=(OOC_UINT32)i0;
  if (i2) goto l1_loop;
l5:
  Quicksort1__Sort((void*)(OOC_INT32)a, 64, 0, 63);
  i1=(OOC_INT32)a;
l6_loop:
  i2 = *(OOC_INT32*)i1;
  Out0__Int(i2, 4);
  i1 = i1+4;
  i2 = (OOC_UINT32)i1<=(OOC_UINT32)i0;
  if (i2) goto l6_loop;
l10:
  Out0__Ln();
  return;
  ;
}

void OOC_Quicksort1_init(void) {

  return;
  ;
}

/* --- */
