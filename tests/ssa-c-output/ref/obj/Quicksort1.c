#include "./Quicksort1.d"
#include "__oo2c.h"

void Quicksort1__Sort(OOC_INT32 a[], OOC_LEN a_0d, OOC_INT32 m, OOC_INT32 n) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8,i9,i10,i11;

  i0 = n;
  i1 = m;
  i2 = i0>i1;
  if (!i2) goto l25;
  i3 = i0*4;
  i3 = (OOC_INT32)a+i3;
  i4 = *(OOC_INT32*)i3;
  i5 = i1-1;
  i6=i0;
l5_loop:
  i5 = i5+1;
  i7 = i5*4;
  i7 = (OOC_INT32)a+i7;
  i8 = *(OOC_INT32*)i7;
  i9 = i8>=i4;
  if (!i9) goto l5_loop;
l12_loop:
  i6 = i6-1;
  i9 = i6*4;
  i9 = (OOC_INT32)a+i9;
  i10 = *(OOC_INT32*)i9;
  i11 = i10<=i4;
  if (!i11) goto l12_loop;
l18:
  i11 = i5>=i6;
  if (i11) goto l24;
l23:
  *(OOC_INT32*)i7 = i10;
  *(OOC_INT32*)i9 = i8;
  
  goto l5_loop;
l24:
  i4 = *(OOC_INT32*)i3;
  *(OOC_INT32*)i7 = i4;
  *(OOC_INT32*)i3 = i8;
  Quicksort1__Sort((void*)(OOC_INT32)a, a_0d, i1, i6);
  i1 = i5+1;
  Quicksort1__Sort((void*)(OOC_INT32)a, a_0d, i1, i0);
l25:
  return;
}

void Quicksort1__Test() {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_INT32 a[64];

  i0 = 0<=63;
  if (!i0) goto l11;
  i1=0;
l4_loop:
  i2 = i1*4;
  i2 = (OOC_INT32)a+i2;
  i3 = i1+1;
  i4 = RandomNumbers__RND(64);
  *(OOC_INT32*)i2 = i4;
  i1 = i3<=63;
  if (!i1) goto l11;
l9:
  i1=i3;
  goto l4_loop;
l11:
  Quicksort1__Sort((void*)(OOC_INT32)a, 64, 0, 63);
  if (!i0) goto l22;
  i1=0;
l15_loop:
  i2 = i1*4;
  i2 = (OOC_INT32)a+i2;
  i2 = *(OOC_INT32*)i2;
  i1 = i1+1;
  Out0__Int(i2, 4);
  i2 = i1<=63;
  if (i2) goto l15_loop;
l22:
  Out0__Ln();
  return;
}

void Quicksort1_init(void) {

  return;
}

/* --- */
