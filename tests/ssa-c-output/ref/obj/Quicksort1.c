#include <Quicksort1.d>
#include <__oo2c.h>

void Quicksort1__Sort(OOC_INT32 a[], OOC_LEN a_0d, OOC_INT32 m, OOC_INT32 n) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;

  i0 = n;
  i1 = m;
  i2 = i0>i1;
  if (!i2) goto l18;
  i2 = i1-1;
  i3 = *(OOC_INT32*)((OOC_INT32)a+i0*4);
  i4=i0;
l3_loop:
  
l4_loop:
  i2 = i2+1;
  i5 = *(OOC_INT32*)((OOC_INT32)a+i2*4);
  i5 = i5>=i3;
  if (!i5) goto l4_loop;
l9_loop:
  i4 = i4-1;
  i5 = *(OOC_INT32*)((OOC_INT32)a+i4*4);
  i5 = i5<=i3;
  if (!i5) goto l9_loop;
l13:
  i5 = i2>=i4;
  if (i5) goto l17;
  i5 = *(OOC_INT32*)((OOC_INT32)a+i2*4);
  i6 = *(OOC_INT32*)((OOC_INT32)a+i4*4);
  *(OOC_INT32*)((OOC_INT32)a+i2*4) = i6;
  *(OOC_INT32*)((OOC_INT32)a+i4*4) = i5;
  
  goto l3_loop;
l17:
  i3 = *(OOC_INT32*)((OOC_INT32)a+i0*4);
  i5 = *(OOC_INT32*)((OOC_INT32)a+i2*4);
  *(OOC_INT32*)((OOC_INT32)a+i2*4) = i3;
  *(OOC_INT32*)((OOC_INT32)a+i0*4) = i5;
  Quicksort1__Sort((void*)(OOC_INT32)a, a_0d, i1, i4);
  Quicksort1__Sort((void*)(OOC_INT32)a, a_0d, (i2+1), i0);
l18:
  return;
  ;
}

void Quicksort1__Test() {
  register OOC_INT32 i0,i1,i2;
  OOC_INT32 a[64];

  i0=0;
l1_loop:
  i1 = RandomNumbers__RND(64);
  i2 = i0+1;
  *(OOC_INT32*)((OOC_INT32)a+i0*4) = i1;
  i0 = i2<=63;
  if (!i0) goto l5;
  i0=i2;
  goto l1_loop;
l5:
  Quicksort1__Sort((void*)(OOC_INT32)a, 64, 0, 63);
  i0=0;
l6_loop:
  i1 = *(OOC_INT32*)((OOC_INT32)a+i0*4);
  Out0__Int(i1, 4);
  i0 = i0+1;
  i1 = i0<=63;
  if (i1) goto l6_loop;
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
