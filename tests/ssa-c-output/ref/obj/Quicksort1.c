#include "./Quicksort1.d"
#include "__oo2c.h"

void Quicksort1__Sort(OOC_INT32 a[], OOC_LEN a_0d, OOC_INT32 m, OOC_INT32 n) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8,i9,i10;

  i0 = n;
  i1 = m;
  i2 = i0>i1;
  if (!i2) goto l18;
  i2 = i0*4;
  i2 = (OOC_INT32)a+i2;
  i3 = i1-1;
  i4 = *(OOC_INT32*)i2;
  i5=i0;
l4_loop:
  i3 = i3+1;
  i6 = i3*4;
  i6 = (OOC_INT32)a+i6;
  i7 = *(OOC_INT32*)i6;
  i8 = i7>=i4;
  if (!i8) goto l4_loop;
l9_loop:
  i5 = i5-1;
  i8 = i5*4;
  i8 = (OOC_INT32)a+i8;
  i9 = *(OOC_INT32*)i8;
  i10 = i9<=i4;
  if (!i10) goto l9_loop;
l13:
  i10 = i3>=i5;
  if (i10) goto l17;
  *(OOC_INT32*)i6 = i9;
  *(OOC_INT32*)i8 = i7;
  
  goto l4_loop;
l17:
  i4 = *(OOC_INT32*)i2;
  *(OOC_INT32*)i6 = i4;
  *(OOC_INT32*)i2 = i7;
  Quicksort1__Sort((void*)(OOC_INT32)a, a_0d, i1, i5);
  i1 = i3+1;
  Quicksort1__Sort((void*)(OOC_INT32)a, a_0d, i1, i0);
l18:
  return;
}

void Quicksort1__Test() {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_INT32 a[64];

  i0 = 0<=63;
  if (!i0) goto l8;
  i1=0;
l3_loop:
  i2 = i1*4;
  i2 = (OOC_INT32)a+i2;
  i1 = i1+1;
  i3 = RandomNumbers__RND(64);
  *(OOC_INT32*)i2 = i3;
  i2 = i1<=63;
  if (i2) goto l3_loop;
l8:
  Quicksort1__Sort((void*)(OOC_INT32)a, 64, 0, 63);
  if (!i0) goto l16;
  i0=0;
l11_loop:
  i1 = i0*4;
  i1 = (OOC_INT32)a+i1;
  i1 = *(OOC_INT32*)i1;
  i0 = i0+1;
  Out0__Int(i1, 4);
  i1 = i0<=63;
  if (i1) goto l11_loop;
l16:
  Out0__Ln();
  return;
}

void Quicksort1_init(void) {

  return;
}

/* --- */
