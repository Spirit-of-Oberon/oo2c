#include "./Quicksort1.d"
#include "__oo2c.h"

void Quicksort1__Sort(OOC_INT32 a[], OOC_LEN a_0d, OOC_INT32 m, OOC_INT32 n) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7;

  i0 = n;
  i1 = m;
  i0 = i0>i1;
  if (i0) goto l3;
  goto l19;
l3:
  i1 = n;
  i2 = i1*4;
  i2 = (OOC_INT32)a+i2;
  i1 = *(OOC_INT32*)i2;
  i2 = n;
  i3 = m;
  i3 = i3-1;
  {register OOC_INT32 h0=i2;i2=i3;i3=h0;}
l4_loop:
  
l5_loop:
  i2 = i2+1;
  i4 = i2*4;
  i4 = (OOC_INT32)a+i4;
  i4 = *(OOC_INT32*)i4;
  i4 = i4>=i1;
  if (i4) goto l8;
  
  goto l5_loop;
l8:
  
l9_loop:
  i3 = i3-1;
  i4 = i3*4;
  i4 = (OOC_INT32)a+i4;
  i4 = *(OOC_INT32*)i4;
  i4 = i4<=i1;
  if (i4) goto l12;
  
  goto l9_loop;
l12:
  i5 = i2*4;
  i4 = i2>=i3;
  i6 = i3*4;
  i6 = (OOC_INT32)a+i6;
  if (i4) goto l15;
  goto l17;
l15:
  goto l18;
l17:
  i4 = *(OOC_INT32*)i6;
  i6 = i3*4;
  i6 = (OOC_INT32)a+i6;
  i5 = (OOC_INT32)a+i5;
  i5 = *(OOC_INT32*)i5;
  i7 = i2*4;
  i7 = (OOC_INT32)a+i7;
  *(OOC_INT32*)i7 = i4;
  *(OOC_INT32*)i6 = i5;
  
  goto l4_loop;
l18:
  i1 = n;
  i4 = i1*4;
  i4 = (OOC_INT32)a+i4;
  i1 = *(OOC_INT32*)i4;
  i4 = i2*4;
  i4 = (OOC_INT32)a+i4;
  i4 = *(OOC_INT32*)i4;
  i5 = i2*4;
  i5 = (OOC_INT32)a+i5;
  *(OOC_INT32*)i5 = i1;
  i1 = n;
  i5 = i1*4;
  i5 = (OOC_INT32)a+i5;
  *(OOC_INT32*)i5 = i4;
  i1 = m;
  Quicksort1__Sort((void*)(OOC_INT32)a, a_0d, i1, i3);
  i1 = n;
  i2 = i2+1;
  Quicksort1__Sort((void*)(OOC_INT32)a, a_0d, i2, i1);
l19:
  return;
}

void Quicksort1__Test() {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  OOC_INT32 a[64];

  i0 = 0<=63;
  if (i0) goto l3;
  goto l8;
l3:
  i1=0;
l4_loop:
  i2 = i1*4;
  i2 = (OOC_INT32)a+i2;
  i3 = i1+1;
  i4 = i3<=63;
  i5 = RandomNumbers__RND(64);
  *(OOC_INT32*)i2 = i5;
  if (!i4) goto l7;
  i1=i3;
  goto l4_loop;
l7:
l8:
  i0 = 0<=63;
  Quicksort1__Sort((void*)(OOC_INT32)a, 64, 0, 63);
  if (i0) goto l11;
  goto l16;
l11:
  i1=0;
l12_loop:
  i2 = i1*4;
  i2 = (OOC_INT32)a+i2;
  i2 = *(OOC_INT32*)i2;
  Out0__Int(i2, 4);
  i1 = i1+1;
  i2 = i1<=63;
  if (!i2) goto l15;
  
  goto l12_loop;
l15:
l16:
  Out0__Ln();
  return;
}

void Quicksort1_init(void) {

  return;
}

/* --- */
