#include <OOC/SSA/IGraph.d>
#include <__oo2c.h>
#include <setjmp.h>

void OOC_SSA_IGraph__GraphDesc_Clear(OOC_SSA_IGraph__Graph g) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7;
  OOC_INT32 i;
  OOC_INT32 j;

  i0 = (OOC_INT32)g;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 2524));
  i = 0;
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 2527)), 0);
  i2 = 0<i1;
  if (!i2) goto l16;
  i2=0;
l3_loop:
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 2564));
  j = 0;
  i3 = OOC_ARRAY_LENGTH((_check_pointer(i3, 2567)), 1);
  i4 = 0<i3;
  if (!i4) goto l11;
  i4=0;
l6_loop:
  i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 2587));
  i5 = _check_pointer(i5, 2590);
  i6 = OOC_ARRAY_LENGTH(i5, 1);
  i7 = OOC_ARRAY_LENGTH(i5, 0);
  *(OOC_UINT32*)((i5+((_check_index(i2, i7, OOC_UINT32, 2590))*(4*i6)))+(_check_index(i4, i6, OOC_UINT32, 2592))*4) = 0u;
  i4 = i4+1;
  j = i4;
  i5 = i4<i3;
  if (i5) goto l6_loop;
l11:
  i2 = i2+1;
  i = i2;
  i3 = i2<i1;
  if (i3) goto l3_loop;
l16:
  return;
  ;
}

static void OOC_SSA_IGraph__InitGraph(OOC_SSA_IGraph__Graph g, OOC_INT32 size) {
  register OOC_INT32 i0,i1;

  i0 = size;
  i1 = (OOC_INT32)g;
  *(OOC_INT32*)(_check_pointer(i1, 2708)) = ((OOC_INT32)RT0__NewObject(_td_OOC_SSA_IGraph__BitMatrix.baseTypes[0], i0, (((i0+32)-1)>>5)));
  *(OOC_INT32*)((_check_pointer(i1, 2761))+4) = i0;
  OOC_SSA_IGraph__GraphDesc_Clear((OOC_SSA_IGraph__Graph)i1);
  return;
  ;
}

OOC_SSA_IGraph__Graph OOC_SSA_IGraph__NewGraph(OOC_INT32 size) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_SSA_IGraph__Graph.baseTypes[0]);
  i1 = size;
  OOC_SSA_IGraph__InitGraph((OOC_SSA_IGraph__Graph)i0, i1);
  return (OOC_SSA_IGraph__Graph)i0;
  ;
}

OOC_SSA_IGraph__Vector OOC_SSA_IGraph__GraphDesc_NewVector(OOC_SSA_IGraph__Graph g) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_SSA_IGraph__Vector v;
  OOC_INT32 i;

  i0 = (OOC_INT32)g;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 3177));
  i0 = OOC_ARRAY_LENGTH((_check_pointer(i0, 3180)), 1);
  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_SSA_IGraph__Vector.baseTypes[0], i0);
  v = (OOC_SSA_IGraph__Vector)i0;
  i = 0;
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 3212)), 0);
  i2 = 0<i1;
  if (!i2) goto l8;
  i2=0;
l3_loop:
  i3 = _check_pointer(i0, 3227);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  *(OOC_UINT32*)(i3+(_check_index(i2, i4, OOC_UINT32, 3227))*4) = 0u;
  i2 = i2+1;
  i = i2;
  i3 = i2<i1;
  if (i3) goto l3_loop;
l8:
  return (OOC_SSA_IGraph__Vector)i0;
  ;
}

OOC_SSA_IGraph__Vector OOC_SSA_IGraph__GraphDesc_CopyVector(OOC_SSA_IGraph__Graph g, OOC_SSA_IGraph__Vector v) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7;
  OOC_SSA_IGraph__Vector w;
  OOC_INT32 i;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)g;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 3473));
  i3 = OOC_ARRAY_LENGTH((_check_pointer(i0, 3462)), 0);
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 3476)), 1);
  _assert((i3==i2), 127, 3448);
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 3502));
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 3505)), 1);
  i1 = (OOC_INT32)RT0__NewObject(_td_OOC_SSA_IGraph__Vector.baseTypes[0], i1);
  w = (OOC_SSA_IGraph__Vector)i1;
  i = 0;
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i1, 3537)), 0);
  i3 = 0<i2;
  if (!i3) goto l8;
  i3=0;
l3_loop:
  i4 = _check_pointer(i1, 3552);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i6 = _check_pointer(i0, 3560);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = *(OOC_UINT32*)(i6+(_check_index(i3, i7, OOC_UINT32, 3560))*4);
  *(OOC_UINT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 3552))*4) = i6;
  i3 = i3+1;
  i = i3;
  i4 = i3<i2;
  if (i4) goto l3_loop;
l8:
  return (OOC_SSA_IGraph__Vector)i1;
  ;
}

void OOC_SSA_IGraph__GraphDesc_Interfere(OOC_SSA_IGraph__Graph g, OOC_INT32 res, OOC_SSA_IGraph__Vector live) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8,i9,i10,i11,i12;
  OOC_SSA_IGraph__BitMatrix m;
  OOC_INT32 i;

  i0 = (OOC_INT32)g;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 3920));
  m = (OOC_SSA_IGraph__BitMatrix)i0;
  i = 0;
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 3949)), 1);
  i2 = 0<i1;
  if (!i2) goto l8;
  i2 = res;
  i3 = (OOC_INT32)live;
  i4=0;
l3_loop:
  i5 = _check_pointer(i0, 3967);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i7 = OOC_ARRAY_LENGTH(i5, 1);
  i8 = _check_pointer(i0, 3980);
  i9 = OOC_ARRAY_LENGTH(i8, 0);
  i10 = OOC_ARRAY_LENGTH(i8, 1);
  i11 = _check_pointer(i3, 3993);
  i12 = OOC_ARRAY_LENGTH(i11, 0);
  i11 = *(OOC_UINT32*)(i11+(_check_index(i4, i12, OOC_UINT32, 3993))*4);
  i8 = *(OOC_UINT32*)((i8+((_check_index(i2, i9, OOC_UINT32, 3980))*(4*i10)))+(_check_index(i4, i10, OOC_UINT32, 3984))*4);
  *(OOC_UINT32*)((i5+((_check_index(i2, i6, OOC_UINT32, 3967))*(4*i7)))+(_check_index(i4, i7, OOC_UINT32, 3971))*4) = (i8|i11);
  i4 = i4+1;
  i = i4;
  i5 = i4<i1;
  if (i5) goto l3_loop;
l8:
  return;
  ;
}

void OOC_SSA_IGraph__GraphDesc_MergeRowColumn(OOC_SSA_IGraph__Graph g, OOC_INT32 source, OOC_INT32 target) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8,i9,i10,i11,i12,i13,i14,i15;
  OOC_SSA_IGraph__BitMatrix m;
  OOC_INT32 i;

  i0 = (OOC_INT32)g;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 4145));
  m = (OOC_SSA_IGraph__BitMatrix)i0;
  i1 = _check_pointer(i0, 4161);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i3 = source;
  i4 = i3>>5;
  i5 = OOC_ARRAY_LENGTH(i1, 1);
  i6 = _check_pointer(i0, 4161);
  i7 = OOC_ARRAY_LENGTH(i6, 1);
  i8 = OOC_ARRAY_LENGTH(i6, 0);
  i9 = _mod(i3,32);
  i6 = *(OOC_UINT32*)((i6+((_check_index(i3, i8, OOC_UINT32, 4161))*(4*i7)))+(_check_index(i4, i7, OOC_UINT32, 4168))*4);
  *(OOC_UINT32*)((i1+((_check_index(i3, i2, OOC_UINT32, 4161))*(4*i5)))+(_check_index(i4, i5, OOC_UINT32, 4168))*4) = (_clear_bit(i6,i9));
  i = 0;
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 4241)), 1);
  i2 = 0<i1;
  if (!i2) goto l8;
  i2 = target;
  i5=0;
l3_loop:
  i6 = _check_pointer(i0, 4259);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i8 = OOC_ARRAY_LENGTH(i6, 1);
  i10 = _check_pointer(i0, 4275);
  i11 = OOC_ARRAY_LENGTH(i10, 0);
  i12 = OOC_ARRAY_LENGTH(i10, 1);
  i13 = _check_pointer(i0, 4288);
  i14 = OOC_ARRAY_LENGTH(i13, 1);
  i15 = OOC_ARRAY_LENGTH(i13, 0);
  i10 = *(OOC_UINT32*)((i10+((_check_index(i2, i11, OOC_UINT32, 4275))*(4*i12)))+(_check_index(i5, i12, OOC_UINT32, 4282))*4);
  i11 = *(OOC_UINT32*)((i13+((_check_index(i3, i15, OOC_UINT32, 4288))*(4*i14)))+(_check_index(i5, i14, OOC_UINT32, 4295))*4);
  *(OOC_UINT32*)((i6+((_check_index(i2, i7, OOC_UINT32, 4259))*(4*i8)))+(_check_index(i5, i8, OOC_UINT32, 4266))*4) = (i10|i11);
  i6 = _check_pointer(i0, 4308);
  i7 = OOC_ARRAY_LENGTH(i6, 1);
  i8 = OOC_ARRAY_LENGTH(i6, 0);
  *(OOC_UINT32*)((i6+((_check_index(i3, i8, OOC_UINT32, 4308))*(4*i7)))+(_check_index(i5, i7, OOC_UINT32, 4315))*4) = 0u;
  i5 = i5+1;
  i = i5;
  i6 = i5<i1;
  if (i6) goto l3_loop;
l8:
  i = 0;
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 4365)), 0);
  i2 = 0<i1;
  if (!i2) goto l19;
  i2 = target;
  i3 = _mod(i2,32);
  i2 = i2>>5;
  i5=0;
l11_loop:
  i6 = _check_pointer(i0, 4413);
  i7 = OOC_ARRAY_LENGTH(i6, 1);
  i8 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = *(OOC_UINT32*)((i6+((_check_index(i5, i8, OOC_UINT32, 4413))*(4*i7)))+(_check_index(i4, i7, OOC_UINT32, 4415))*4);
  i6 = _in(i9,i6);
  if (!i6) goto l14;
  i6 = _check_pointer(i0, 4459);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i8 = OOC_ARRAY_LENGTH(i6, 1);
  i10 = _check_pointer(i0, 4459);
  i11 = OOC_ARRAY_LENGTH(i10, 1);
  i12 = OOC_ARRAY_LENGTH(i10, 0);
  i10 = *(OOC_UINT32*)((i10+((_check_index(i5, i12, OOC_UINT32, 4459))*(4*i11)))+(_check_index(i2, i11, OOC_UINT32, 4461))*4);
  *(OOC_UINT32*)((i6+((_check_index(i5, i7, OOC_UINT32, 4459))*(4*i8)))+(_check_index(i2, i8, OOC_UINT32, 4461))*4) = (_set_bit(i10,i3));
l14:
  i6 = _check_pointer(i0, 4534);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i8 = OOC_ARRAY_LENGTH(i6, 1);
  i10 = _check_pointer(i0, 4534);
  i11 = OOC_ARRAY_LENGTH(i10, 1);
  i12 = OOC_ARRAY_LENGTH(i10, 0);
  i10 = *(OOC_UINT32*)((i10+((_check_index(i5, i12, OOC_UINT32, 4534))*(4*i11)))+(_check_index(i4, i11, OOC_UINT32, 4536))*4);
  *(OOC_UINT32*)((i6+((_check_index(i5, i7, OOC_UINT32, 4534))*(4*i8)))+(_check_index(i4, i8, OOC_UINT32, 4536))*4) = (_clear_bit(i10,i9));
  i5 = i5+1;
  i = i5;
  i6 = i5<i1;
  if (i6) goto l11_loop;
l19:
  return;
  ;
}

void OOC_SSA_IGraph__GraphDesc_AddToLive(OOC_SSA_IGraph__Graph g, OOC_INT32 res, OOC_SSA_IGraph__Vector live) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;

  i0 = (OOC_INT32)live;
  i1 = res;
  i2 = (OOC_INT32)g;
  OOC_SSA_IGraph__GraphDesc_Interfere((OOC_SSA_IGraph__Graph)i2, i1, (OOC_SSA_IGraph__Vector)i0);
  i2 = _check_pointer(i0, 4878);
  i3 = i1>>5;
  i4 = OOC_ARRAY_LENGTH(i2, 0);
  i0 = _check_pointer(i0, 4878);
  i5 = OOC_ARRAY_LENGTH(i0, 0);
  i0 = *(OOC_UINT32*)(i0+(_check_index(i3, i5, OOC_UINT32, 4878))*4);
  *(OOC_UINT32*)(i2+(_check_index(i3, i4, OOC_UINT32, 4878))*4) = (_set_bit(i0,(_mod(i1,32))));
  return;
  ;
}

void OOC_SSA_IGraph__GraphDesc_RemoveFromLive(OOC_SSA_IGraph__Graph g, OOC_INT32 res, OOC_SSA_IGraph__Vector live) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;

  i0 = (OOC_INT32)live;
  i1 = _check_pointer(i0, 5086);
  i2 = res;
  i3 = i2>>5;
  i4 = OOC_ARRAY_LENGTH(i1, 0);
  i0 = _check_pointer(i0, 5086);
  i5 = OOC_ARRAY_LENGTH(i0, 0);
  i0 = *(OOC_UINT32*)(i0+(_check_index(i3, i5, OOC_UINT32, 5086))*4);
  *(OOC_UINT32*)(i1+(_check_index(i3, i4, OOC_UINT32, 5086))*4) = (_clear_bit(i0,(_mod(i2,32))));
  return;
  ;
}

OOC_CHAR8 OOC_SSA_IGraph__GraphDesc_In(OOC_SSA_IGraph__Graph g, OOC_INT32 res, OOC_SSA_IGraph__Vector live) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)live;
  i0 = _check_pointer(i0, 5347);
  i1 = res;
  i2 = OOC_ARRAY_LENGTH(i0, 0);
  i0 = *(OOC_UINT32*)(i0+(_check_index((i1>>5), i2, OOC_UINT32, 5347))*4);
  return (_in((_mod(i1,32)),i0));
  ;
}

OOC_CHAR8 OOC_SSA_IGraph__GraphDesc_Conflicts(OOC_SSA_IGraph__Graph g, OOC_INT32 i, OOC_INT32 j) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_SSA_IGraph__BitMatrix m;

  i0 = (OOC_INT32)g;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 5547));
  m = (OOC_SSA_IGraph__BitMatrix)i0;
  i0 = _check_pointer(i0, 5585);
  i1 = OOC_ARRAY_LENGTH(i0, 0);
  i2 = OOC_ARRAY_LENGTH(i0, 1);
  i3 = i;
  i4 = j;
  i0 = *(OOC_UINT32*)((i0+((_check_index(i3, i1, OOC_UINT32, 5585))*(4*i2)))+(_check_index((i4>>5), i2, OOC_UINT32, 5587))*4);
  return (_in((_mod(i4,32)),i0));
  ;
}

OOC_INT32 OOC_SSA_IGraph__GraphDesc_NumberOfConflicts(OOC_SSA_IGraph__Graph g, OOC_INT32 i) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  OOC_SSA_IGraph__BitMatrix m;
  OOC_INT32 c;

  i0 = (OOC_INT32)g;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 5751));
  m = (OOC_SSA_IGraph__BitMatrix)i1;
  c = 0;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 5786))+4);
  i2 = 0<i1;
  if (i2) goto l3;
  i0=0;
  goto l13;
l3:
  i2 = i;
  i3=0;i4=0;
l4_loop:
  i5 = OOC_SSA_IGraph__GraphDesc_Conflicts((OOC_SSA_IGraph__Graph)i0, i2, i3);
  if (!i5) goto l8;
  i4 = i4+1;
  
l8:
  i3 = i3+1;
  i5 = i3<i1;
  if (i5) goto l4_loop;
l12:
  i0=i4;
l13:
  return i0;
  ;
}

void OOC_SSA_IGraph__GraphDesc_MergeVector(OOC_SSA_IGraph__Graph g, OOC_SSA_IGraph__Vector source, OOC_SSA_IGraph__Vector dest) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;

  i0 = (OOC_INT32)source;
  i1 = (OOC_INT32)dest;
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i0, 6114)), 0);
  i3 = OOC_ARRAY_LENGTH((_check_pointer(i1, 6128)), 0);
  _assert((i2==i3), 127, 6095);
  i2 = (OOC_INT32)g;
  i3 = *(OOC_INT32*)((_check_pointer(i2, 6152))+4);
  i4 = 0<i3;
  if (!i4) goto l11;
  i4=0;
l3_loop:
  i5 = OOC_SSA_IGraph__GraphDesc_In((OOC_SSA_IGraph__Graph)i2, i4, (OOC_SSA_IGraph__Vector)i0);
  if (!i5) goto l6;
  OOC_SSA_IGraph__GraphDesc_AddToLive((OOC_SSA_IGraph__Graph)i2, i4, (OOC_SSA_IGraph__Vector)i1);
l6:
  i4 = i4+1;
  i5 = i4<i3;
  if (i5) goto l3_loop;
l11:
  return;
  ;
}

void OOC_SSA_IGraph__GraphDesc_SymmetricMatrix(OOC_SSA_IGraph__Graph g) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8,i9,i10,i11,i12,i13,i14;
  OOC_SSA_IGraph__BitMatrix m;
  OOC_INT32 y;
  OOC_INT32 x;

  i0 = (OOC_INT32)g;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 6673));
  m = (OOC_SSA_IGraph__BitMatrix)i0;
  y = 0;
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 6702)), 0);
  i2 = 0<i1;
  if (!i2) goto l23;
  i2=0;
l3_loop:
  x = 0;
  i3 = OOC_ARRAY_LENGTH((_check_pointer(i0, 6736)), 0);
  i4 = _mod(i2,32);
  i5 = i2>>5;
  i6 = 0<i3;
  if (!i6) goto l18;
  i6=0;
l6_loop:
  i7 = _check_pointer(i0, 6777);
  i8 = OOC_ARRAY_LENGTH(i7, 1);
  i9 = OOC_ARRAY_LENGTH(i7, 0);
  i10 = i6>>5;
  i7 = *(OOC_UINT32*)((i7+((_check_index(i2, i9, OOC_UINT32, 6777))*(4*i8)))+(_check_index(i10, i8, OOC_UINT32, 6779))*4);
  i8 = _mod(i6,32);
  i7 = _in(i8,i7);
  if (i7) goto l12;
  i7 = _check_pointer(i0, 6899);
  i9 = OOC_ARRAY_LENGTH(i7, 1);
  i11 = OOC_ARRAY_LENGTH(i7, 0);
  i7 = *(OOC_UINT32*)((i7+((_check_index(i6, i11, OOC_UINT32, 6899))*(4*i9)))+(_check_index(i5, i9, OOC_UINT32, 6901))*4);
  i7 = _in(i4,i7);
  if (!i7) goto l13;
  i7 = _check_pointer(i0, 6991);
  i9 = OOC_ARRAY_LENGTH(i7, 0);
  i11 = OOC_ARRAY_LENGTH(i7, 1);
  i12 = _check_pointer(i0, 6991);
  i13 = OOC_ARRAY_LENGTH(i12, 1);
  i14 = OOC_ARRAY_LENGTH(i12, 0);
  i12 = *(OOC_UINT32*)((i12+((_check_index(i2, i14, OOC_UINT32, 6991))*(4*i13)))+(_check_index(i10, i13, OOC_UINT32, 6993))*4);
  *(OOC_UINT32*)((i7+((_check_index(i2, i9, OOC_UINT32, 6991))*(4*i11)))+(_check_index(i10, i11, OOC_UINT32, 6993))*4) = (_set_bit(i12,i8));
  goto l13;
l12:
  i7 = _check_pointer(i0, 6822);
  i8 = OOC_ARRAY_LENGTH(i7, 0);
  i9 = OOC_ARRAY_LENGTH(i7, 1);
  i10 = _check_pointer(i0, 6822);
  i11 = OOC_ARRAY_LENGTH(i10, 1);
  i12 = OOC_ARRAY_LENGTH(i10, 0);
  i10 = *(OOC_UINT32*)((i10+((_check_index(i6, i12, OOC_UINT32, 6822))*(4*i11)))+(_check_index(i5, i11, OOC_UINT32, 6824))*4);
  *(OOC_UINT32*)((i7+((_check_index(i6, i8, OOC_UINT32, 6822))*(4*i9)))+(_check_index(i5, i9, OOC_UINT32, 6824))*4) = (_set_bit(i10,i4));
l13:
  i6 = i6+1;
  x = i6;
  i7 = i6<i3;
  if (i7) goto l6_loop;
l18:
  i3 = _check_pointer(i0, 7095);
  i6 = OOC_ARRAY_LENGTH(i3, 0);
  i7 = OOC_ARRAY_LENGTH(i3, 1);
  i8 = _check_pointer(i0, 7095);
  i9 = OOC_ARRAY_LENGTH(i8, 1);
  i10 = OOC_ARRAY_LENGTH(i8, 0);
  i8 = *(OOC_UINT32*)((i8+((_check_index(i2, i10, OOC_UINT32, 7095))*(4*i9)))+(_check_index(i5, i9, OOC_UINT32, 7097))*4);
  *(OOC_UINT32*)((i3+((_check_index(i2, i6, OOC_UINT32, 7095))*(4*i7)))+(_check_index(i5, i7, OOC_UINT32, 7097))*4) = (_clear_bit(i8,i4));
  i2 = i2+1;
  y = i2;
  i3 = i2<i1;
  if (i3) goto l3_loop;
l23:
  return;
  ;
}

void OOC_SSA_IGraph__GraphDesc_AssertSymmetricMatrix(OOC_SSA_IGraph__Graph g) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8,i9;
  OOC_SSA_IGraph__BitMatrix m;
  OOC_INT32 y;
  OOC_INT32 x;

  i0 = (OOC_INT32)g;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 7275));
  m = (OOC_SSA_IGraph__BitMatrix)i0;
  y = 0;
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 7302)), 0);
  i2 = 0<i1;
  if (!i2) goto l20;
  i2=0;
l3_loop:
  x = 0;
  i3 = OOC_ARRAY_LENGTH((_check_pointer(i0, 7335)), 0);
  i4 = 0<i3;
  if (!i4) goto l15;
  i4 = _mod(i2,32);
  i5 = i2>>5;
  i6=0;
l6_loop:
  i7 = _check_pointer(i0, 7376);
  i8 = OOC_ARRAY_LENGTH(i7, 1);
  i9 = OOC_ARRAY_LENGTH(i7, 0);
  i7 = *(OOC_UINT32*)((i7+((_check_index(i2, i9, OOC_UINT32, 7376))*(4*i8)))+(_check_index((i6>>5), i8, OOC_UINT32, 7378))*4);
  i7 = _in((_mod(i6,32)),i7);
  if (i7) goto l9;
  i7 = _check_pointer(i0, 7523);
  i8 = OOC_ARRAY_LENGTH(i7, 1);
  i9 = OOC_ARRAY_LENGTH(i7, 0);
  i7 = *(OOC_UINT32*)((i7+((_check_index(i6, i9, OOC_UINT32, 7523))*(4*i8)))+(_check_index(i5, i8, OOC_UINT32, 7525))*4);
  _assert((!(_in(i4,i7))), 127, 7491);
  goto l10;
l9:
  i7 = _check_pointer(i0, 7444);
  i8 = OOC_ARRAY_LENGTH(i7, 1);
  i9 = OOC_ARRAY_LENGTH(i7, 0);
  i7 = *(OOC_UINT32*)((i7+((_check_index(i6, i9, OOC_UINT32, 7444))*(4*i8)))+(_check_index(i5, i8, OOC_UINT32, 7446))*4);
  _assert((_in(i4,i7)), 127, 7414);
l10:
  i6 = i6+1;
  x = i6;
  i7 = i6<i3;
  if (i7) goto l6_loop;
l15:
  i2 = i2+1;
  y = i2;
  i3 = i2<i1;
  if (i3) goto l3_loop;
l20:
  return;
  ;
}

OOC_SSA_IGraph__ColorArray OOC_SSA_IGraph__GraphDesc_ColorGraphTrivial(OOC_SSA_IGraph__Graph g) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_SSA_IGraph__ColorArray ca;
  OOC_INT32 i;

  i0 = (OOC_INT32)g;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 7874))+4);
  i1 = (OOC_INT32)RT0__NewObject(_td_OOC_SSA_IGraph__ColorArray.baseTypes[0], i1);
  ca = (OOC_SSA_IGraph__ColorArray)i1;
  i = 0;
  i0 = *(OOC_INT32*)((_check_pointer(i0, 7902))+4);
  i2 = 0<i0;
  if (!i2) goto l8;
  i2=0;
l3_loop:
  i3 = _check_pointer(i1, 7922);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  *(OOC_INT32*)(i3+(_check_index(i2, i4, OOC_UINT32, 7922))*4) = i2;
  i2 = i2+1;
  i = i2;
  i3 = i2<i0;
  if (i3) goto l3_loop;
l8:
  return (OOC_SSA_IGraph__ColorArray)i1;
  ;
}

OOC_SSA_IGraph__ColorArray OOC_SSA_IGraph__GraphDesc_ColorGraphSimple(OOC_SSA_IGraph__Graph g) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8,i9,i10;
  OOC_SSA_IGraph__ColorArray ca;
  OOC_SSA_IGraph__BitMatrix m;
  OOC_INT32 i;
  OOC_INT32 color;
  OOC_INT32 clashes;
  OOC_INT32 j;

  i0 = (OOC_INT32)g;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 8370))+4);
  i1 = (OOC_INT32)RT0__NewObject(_td_OOC_SSA_IGraph__ColorArray.baseTypes[0], i1);
  ca = (OOC_SSA_IGraph__ColorArray)i1;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 8389));
  m = (OOC_SSA_IGraph__BitMatrix)i2;
  i = 0;
  i0 = *(OOC_INT32*)((_check_pointer(i0, 8413))+4);
  i3 = 0<i0;
  if (!i3) goto l30;
  i3=0;
l3_loop:
  i4 = 0<i3;
  color = 0;
  i5=0;
l4_loop:
  clashes = 0;
  j = 0;
  if (i4) goto l7;
  i6=0;
  goto l21;
l7:
  i6=i5;i5=0;i7=0;
l8_loop:
  i8 = _check_pointer(i2, 8544);
  i9 = OOC_ARRAY_LENGTH(i8, 1);
  i10 = OOC_ARRAY_LENGTH(i8, 0);
  i8 = *(OOC_UINT32*)((i8+((_check_index(i3, i10, OOC_UINT32, 8544))*(4*i9)))+(_check_index((i5>>5), i9, OOC_UINT32, 8546))*4);
  i8 = _in((_mod(i5,32)),i8);
  if (i8) goto l11;
  i8=0u;
  goto l13;
l11:
  i8 = _check_pointer(i1, 8585);
  i9 = OOC_ARRAY_LENGTH(i8, 0);
  i8 = *(OOC_INT32*)(i8+(_check_index(i5, i9, OOC_UINT32, 8585))*4);
  i8 = i8==i6;
  
l13:
  if (!i8) goto l16;
  i6 = i6+1;
  color = i6;
  i7 = i7+1;
  clashes = i7;
  
l16:
  i5 = i5+1;
  j = i5;
  i8 = i5<i3;
  if (i8) goto l8_loop;
l20:
  i5=i6;i6=i7;
l21:
  i6 = i6==0;
  if (!i6) goto l4_loop;
l25:
  i4 = _check_pointer(i1, 8717);
  i6 = OOC_ARRAY_LENGTH(i4, 0);
  *(OOC_INT32*)(i4+(_check_index(i3, i6, OOC_UINT32, 8717))*4) = i5;
  i3 = i3+1;
  i = i3;
  i4 = i3<i0;
  if (i4) goto l3_loop;
l30:
  return (OOC_SSA_IGraph__ColorArray)i1;
  ;
}

OOC_SSA_IGraph__ColorArray OOC_SSA_IGraph__GraphDesc_ColorGraphCombinatorial(volatile OOC_SSA_IGraph__Graph g) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8,i9;
  volatile OOC_INT32 *p;
  volatile OOC_INT32 i;
  volatile OOC_INT32 best;
  volatile OOC_INT32 j;
  volatile OOC_INT32 size;
  volatile OOC_UINT32 m[32];
  volatile OOC_SSA_IGraph__ColorArray ca;
  volatile OOC_INT32 k;
  volatile OOC_CHAR8 done;
  volatile OOC_UINT32 colorAvailableFor[32];
  auto void OOC_SSA_IGraph__GraphDesc_ColorGraphCombinatorial_Try(OOC_INT32 index);
  auto void OOC_SSA_IGraph__GraphDesc_ColorGraphCombinatorial_Swap(OOC_INT32 i, OOC_INT32 j);
  auto void OOC_SSA_IGraph__GraphDesc_ColorGraphCombinatorial_Invert(const OOC_INT32 caInverted__ref[], OOC_LEN caInverted_0d);
  jmp_buf _target0;
  Exception__Context _context0;
    
    void OOC_SSA_IGraph__GraphDesc_ColorGraphCombinatorial_Try(OOC_INT32 index) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8;
      OOC_INT32 color;
      OOC_INT32 i;
      OOC_UINT32 oldAvail;

      i0 = index;
      i1 = size;
      i1 = i0==i1;
      if (i1) goto l25;
      color = 0;
      i1 = k;
      i2 = 0<i1;
      if (!i2) goto l26;
      i2 = i0+1;
      i3 = 0<i0;
      i4=0;
l5_loop:
      i5 = *(OOC_UINT32*)((OOC_INT32)colorAvailableFor+(_check_index(i4, 32, OOC_UINT32, 9666))*4);
      i5 = _in(i0,i5);
      if (!i5) goto l19;
      i5 = (OOC_INT32)ca;
      i6 = _check_pointer(i5, 9694);
      i7 = OOC_ARRAY_LENGTH(i6, 0);
      *(OOC_INT32*)(i6+(_check_index(i0, i7, OOC_UINT32, 9694))*4) = i4;
      i = 0;
      if (!i3) goto l18;
      i6=0;
l10_loop:
      i7 = *(OOC_UINT32*)((OOC_INT32)m+(_check_index(i6, 32, OOC_UINT32, 9777))*4);
      i7 = _in(i0,i7);
      if (!i7) goto l13;
      i7 = _check_pointer(i5, 9812);
      i8 = OOC_ARRAY_LENGTH(i7, 0);
      i7 = *(OOC_INT32*)(i7+(_check_index(i6, i8, OOC_UINT32, 9812))*4);
      _assert((i7!=i4), 127, 9803);
l13:
      i6 = i6+1;
      i = i6;
      i7 = i6<i0;
      if (i7) goto l10_loop;
l18:
      i5 = *(OOC_UINT32*)((OOC_INT32)colorAvailableFor+(_check_index(i4, 32, OOC_UINT32, 9903))*4);
      oldAvail = i5;
      i6 = *(OOC_UINT32*)((OOC_INT32)colorAvailableFor+(_check_index(i4, 32, OOC_UINT32, 9969))*4);
      i7 = *(OOC_UINT32*)((OOC_INT32)m+(_check_index(i0, 32, OOC_UINT32, 9980))*4);
      *(OOC_UINT32*)((OOC_INT32)colorAvailableFor+(_check_index(i4, 32, OOC_UINT32, 9941))*4) = (_logical_subtr(i6,i7));
      OOC_SSA_IGraph__GraphDesc_ColorGraphCombinatorial_Try(i2);
      *(OOC_UINT32*)((OOC_INT32)colorAvailableFor+(_check_index(i4, 32, OOC_UINT32, 10044))*4) = i5;
l19:
      i4 = i4+1;
      color = i4;
      i5 = i4<i1;
      if (i5) goto l5_loop;
      goto l26;
l25:
      i0 = (OOC_INT32)RT0__NewObject(_td_Exception__Checked.baseTypes[0]);
      Exception__ExceptionDesc_INIT((Exception__Exception)i0, (Object__String)((OOC_INT32)_c0));
      Exception__Raise((void*)i0);
l26:
      return;
      ;
    }

    
    void OOC_SSA_IGraph__GraphDesc_ColorGraphCombinatorial_Swap(OOC_INT32 i, OOC_INT32 j) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7;
      OOC_INT32 x;

      i0 = (OOC_INT32)p;
      i1 = _check_pointer(i0, 10199);
      i2 = OOC_ARRAY_LENGTH(i1, 0);
      i3 = i;
      i1 = *(OOC_INT32*)(i1+(_check_index(i3, i2, OOC_UINT32, 10199))*4);
      x = i1;
      i2 = _check_pointer(i0, 10205);
      i4 = OOC_ARRAY_LENGTH(i2, 0);
      i5 = _check_pointer(i0, 10213);
      i6 = OOC_ARRAY_LENGTH(i5, 0);
      i7 = j;
      i5 = *(OOC_INT32*)(i5+(_check_index(i7, i6, OOC_UINT32, 10213))*4);
      *(OOC_INT32*)(i2+(_check_index(i3, i4, OOC_UINT32, 10205))*4) = i5;
      i0 = _check_pointer(i0, 10219);
      i2 = OOC_ARRAY_LENGTH(i0, 0);
      *(OOC_INT32*)(i0+(_check_index(i7, i2, OOC_UINT32, 10219))*4) = i1;
      return;
      ;
    }

    
    void OOC_SSA_IGraph__GraphDesc_ColorGraphCombinatorial_Invert(const OOC_INT32 caInverted__ref[], OOC_LEN caInverted_0d) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7;
      OOC_ALLOCATE_VPAR(caInverted,OOC_INT32 ,caInverted_0d)
      OOC_INT32 i;

      OOC_INITIALIZE_VPAR(caInverted__ref,caInverted,OOC_INT32 ,(caInverted_0d*4))
      i0 = (OOC_INT32)g;
      i = 0;
      i0 = *(OOC_INT32*)((_check_pointer(i0, 10349))+4);
      i1 = 0<i0;
      if (!i1) goto l8;
      i1 = (OOC_INT32)ca;
      i2 = (OOC_INT32)p;
      i3=0;
l3_loop:
      i4 = _check_pointer(i1, 10370);
      i5 = _check_pointer(i2, 10372);
      i6 = OOC_ARRAY_LENGTH(i5, 0);
      i5 = *(OOC_INT32*)(i5+(_check_index(i3, i6, OOC_UINT32, 10372))*4);
      i6 = OOC_ARRAY_LENGTH(i4, 0);
      i7 = *(OOC_INT32*)((OOC_INT32)caInverted+(_check_index(i3, caInverted_0d, OOC_UINT32, 10390))*4);
      *(OOC_INT32*)(i4+(_check_index(i5, i6, OOC_UINT32, 10370))*4) = i7;
      i3 = i3+1;
      i = i3;
      i4 = i3<i0;
      if (i4) goto l3_loop;
l8:
      return;
      ;
    }


  i0 = (OOC_INT32)g;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 10520))+4);
  i1 = (OOC_INT32)RT0__NewObject(_td_OOC_SSA_IGraph__9265.baseTypes[0], i1);
  p = (void*)i1;
  i = 0;
  i2 = *(OOC_INT32*)((_check_pointer(i0, 10547))+4);
  i3 = 0<i2;
  if (!i3) goto l8;
  i3=0;
l3_loop:
  i4 = _check_pointer(i1, 10565);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  *(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 10565))*4) = i3;
  i3 = i3+1;
  i = i3;
  i4 = i3<i2;
  if (i4) goto l3_loop;
l8:
  i0 = *(OOC_INT32*)((_check_pointer(i0, 10603))+4);
  i = 0;
  i1 = 0<i0;
  if (!i1) goto l29;
  i1=0;
l11_loop:
  best = i1;
  i2 = (OOC_INT32)g;
  i3 = i1+1;
  j = i3;
  i4 = *(OOC_INT32*)((_check_pointer(i2, 10654))+4);
  i5 = i3<i4;
  if (i5) goto l14;
  i2=i1;
  goto l24;
l14:
  i5 = (OOC_INT32)p;
  i6=i1;
l15_loop:
  i7 = _check_pointer(i5, 10697);
  i8 = OOC_ARRAY_LENGTH(i7, 0);
  i7 = *(OOC_INT32*)(i7+(_check_index(i3, i8, OOC_UINT32, 10697))*4);
  i7 = OOC_SSA_IGraph__GraphDesc_NumberOfConflicts((OOC_SSA_IGraph__Graph)i2, i7);
  i8 = _check_pointer(i5, 10725);
  i9 = OOC_ARRAY_LENGTH(i8, 0);
  i8 = *(OOC_INT32*)(i8+(_check_index(i6, i9, OOC_UINT32, 10725))*4);
  i8 = OOC_SSA_IGraph__GraphDesc_NumberOfConflicts((OOC_SSA_IGraph__Graph)i2, i8);
  i7 = i7>i8;
  if (!i7) goto l19;
  best = i3;
  i6=i3;
l19:
  i3 = i3+1;
  j = i3;
  i7 = i3<i4;
  if (i7) goto l15_loop;
l23:
  i2=i6;
l24:
  OOC_SSA_IGraph__GraphDesc_ColorGraphCombinatorial_Swap(i1, i2);
  i1 = i;
  i1 = i1+1;
  i = i1;
  i2 = i1<i0;
  if (i2) goto l11_loop;
l29:
  size = 0;
  i0 = (OOC_INT32)g;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 10912))+4);
  i1 = 0!=i1;
  if (i1) goto l32;
  i1=0u;
  goto l34;
l32:
  i1 = (OOC_INT32)p;
  i1 = _check_pointer(i1, 10943);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i1 = *(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT32, 10943))*4);
  i1 = OOC_SSA_IGraph__GraphDesc_NumberOfConflicts((OOC_SSA_IGraph__Graph)i0, i1);
  i1 = i1>0;
  
l34:
  if (i1) goto l36;
  i1=0;
  goto l46;
l36:
  i1 = (OOC_INT32)p;
  i2=0;
l37_loop:
  i2 = i2+1;
  size = i2;
  i3 = *(OOC_INT32*)((_check_pointer(i0, 10912))+4);
  i3 = i2!=i3;
  if (i3) goto l40;
  i3=0u;
  goto l42;
l40:
  i3 = _check_pointer(i1, 10943);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i3 = *(OOC_INT32*)(i3+(_check_index(i2, i4, OOC_UINT32, 10943))*4);
  i3 = OOC_SSA_IGraph__GraphDesc_NumberOfConflicts((OOC_SSA_IGraph__Graph)i0, i3);
  i3 = i3>0;
  
l42:
  if (i3) goto l37_loop;
l45:
  i1=i2;
l46:
  OOC_SSA_IGraph__GraphDesc_AssertSymmetricMatrix((OOC_SSA_IGraph__Graph)i0);
  i2=0;
l47_loop:
  *(OOC_UINT32*)((OOC_INT32)m+(_check_index(i2, 32, OOC_UINT32, 11125))*4) = 0u;
  i2 = i2+1;
  i3 = i2<=31;
  if (i3) goto l47_loop;
l51:
  i = 0;
  i2 = 0<i1;
  if (!i2) goto l70;
  i3 = (OOC_INT32)p;
  i4=0;
l54_loop:
  j = 0;
  if (!i2) goto l65;
  i5=0;
l57_loop:
  i6 = _check_pointer(i3, 11233);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i8 = _check_pointer(i3, 11227);
  i9 = OOC_ARRAY_LENGTH(i8, 0);
  i6 = *(OOC_INT32*)(i6+(_check_index(i5, i7, OOC_UINT32, 11233))*4);
  i7 = *(OOC_INT32*)(i8+(_check_index(i4, i9, OOC_UINT32, 11227))*4);
  i6 = OOC_SSA_IGraph__GraphDesc_Conflicts((OOC_SSA_IGraph__Graph)i0, i7, i6);
  if (!i6) goto l60;
  i6 = *(OOC_UINT32*)((OOC_INT32)m+(_check_index(i5, 32, OOC_UINT32, 11259))*4);
  *(OOC_UINT32*)((OOC_INT32)m+(_check_index(i5, 32, OOC_UINT32, 11259))*4) = (_set_bit(i6,i4));
l60:
  i5 = i5+1;
  j = i5;
  i6 = i5<i1;
  if (i6) goto l57_loop;
l65:
  i4 = i4+1;
  i = i4;
  i5 = i4<i1;
  if (i5) goto l54_loop;
l70:
  i2 = *(OOC_INT32*)((_check_pointer(i0, 11329))+4);
  Log__Int("### g.size", 11, i2);
  Log__Int("### size", 9, i1);
  _assert((i1<=32), 127, 11372);
  i0 = *(OOC_INT32*)((_check_pointer(i0, 11416))+4);
  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_SSA_IGraph__ColorArray.baseTypes[0], i0);
  ca = (OOC_SSA_IGraph__ColorArray)i0;
  i1 = i1!=0;
  if (!i1) goto l94;
  i0 = _check_pointer(i0, 11507);
  i1 = OOC_ARRAY_LENGTH(i0, 0);
  *(OOC_INT32*)(i0+(_check_index(0, i1, OOC_UINT8, 11507))*4) = 0;
  k = 3;
  done = 0u;
  i0=3;
l73_loop:
  i = 0;
  i1 = 0<i0;
  if (!i1) goto l81;
  i1 = size;
  i1 = _bit_range(0,(i1-1));
  i2=0;
l76_loop:
  *(OOC_UINT32*)((OOC_INT32)colorAvailableFor+(_check_index(i2, 32, OOC_UINT32, 11674))*4) = i1;
  i2 = i2+1;
  i = i2;
  i3 = i2<i0;
  if (i3) goto l76_loop;
l81:
  i0 = *(OOC_UINT32*)((OOC_INT32)colorAvailableFor+(_check_index(0, 32, OOC_UINT8, 11758))*4);
  i1 = *(OOC_UINT32*)((OOC_INT32)m+(_check_index(0, 32, OOC_UINT8, 11765))*4);
  *(OOC_UINT32*)((OOC_INT32)colorAvailableFor+(_check_index(0, 32, OOC_UINT8, 11734))*4) = (_logical_subtr(i0,i1));
  {
    Exception__PushContext(&_context0, &_target0);
    if (!setjmp(_target0)) goto l88;
    Exception__PopContext(1);
    i0 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG(((OOC_INT32)Exception__Current()))), &_td_Exception__CheckedDesc);
    if (i0) goto l86;
    Exception__ActivateContext();
    goto l87;
l86:
    done = 1u;
l87:
    Exception__Clear();
    goto l89;
l88:
    OOC_SSA_IGraph__GraphDesc_ColorGraphCombinatorial_Try(1);
    Exception__PopContext(1);
l89:;
  }
  i0 = k;
  i0 = i0+1;
  k = i0;
  i1 = done;
  if (!i1) goto l73_loop;
l94:
  i = 0;
  i0 = size;
  i1 = (OOC_INT32)ca;
  i2 = 0<i0;
  if (!i2) goto l113;
  i3=0;
l97_loop:
  j = 0;
  if (!i2) goto l108;
  i4=0;
l100_loop:
  i5 = *(OOC_UINT32*)((OOC_INT32)m+(_check_index(i4, 32, OOC_UINT32, 12097))*4);
  i5 = _in(i3,i5);
  if (!i5) goto l103;
  i5 = _check_pointer(i1, 12125);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i7 = _check_pointer(i1, 12133);
  i8 = OOC_ARRAY_LENGTH(i7, 0);
  i5 = *(OOC_INT32*)(i5+(_check_index(i3, i6, OOC_UINT32, 12125))*4);
  i6 = *(OOC_INT32*)(i7+(_check_index(i4, i8, OOC_UINT32, 12133))*4);
  _assert((i5!=i6), 127, 12116);
l103:
  i4 = i4+1;
  j = i4;
  i5 = i4<i0;
  if (i5) goto l100_loop;
l108:
  i3 = i3+1;
  i = i3;
  i4 = i3<i0;
  if (i4) goto l97_loop;
l113:
  i2 = (OOC_INT32)g;
  i = i0;
  i2 = *(OOC_INT32*)((_check_pointer(i2, 12199))+4);
  i3 = i0<i2;
  if (!i3) goto l121;
l116_loop:
  i3 = _check_pointer(i1, 12262);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  *(OOC_INT32*)(i3+(_check_index(i0, i4, OOC_UINT32, 12262))*4) = 0;
  i0 = i0+1;
  i = i0;
  i3 = i0<i2;
  if (i3) goto l116_loop;
l121:
  i0 = OOC_ARRAY_LENGTH((_check_pointer(i1, 12294)), 0);
  OOC_SSA_IGraph__GraphDesc_ColorGraphCombinatorial_Invert((void*)(_check_pointer(i1, 12294)), i0);
  i0 = (OOC_INT32)g;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 12344))+4);
  i = 0;
  i2 = (OOC_INT32)ca;
  i3 = 0<i1;
  if (!i3) goto l140;
  i3=0;
l124_loop:
  i4 = *(OOC_INT32*)((_check_pointer(i0, 12376))+4);
  j = 0;
  i5 = 0<i4;
  if (!i5) goto l135;
  i5=0;
l127_loop:
  i6 = OOC_SSA_IGraph__GraphDesc_Conflicts((OOC_SSA_IGraph__Graph)i0, i3, i5);
  if (!i6) goto l130;
  i6 = _check_pointer(i2, 12440);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i8 = _check_pointer(i2, 12448);
  i9 = OOC_ARRAY_LENGTH(i8, 0);
  i6 = *(OOC_INT32*)(i6+(_check_index(i3, i7, OOC_UINT32, 12440))*4);
  i7 = *(OOC_INT32*)(i8+(_check_index(i5, i9, OOC_UINT32, 12448))*4);
  _assert((i6!=i7), 127, 12431);
l130:
  i5 = i5+1;
  j = i5;
  i6 = i5<i4;
  if (i6) goto l127_loop;
l135:
  i3 = i3+1;
  i = i3;
  i4 = i3<i1;
  if (i4) goto l124_loop;
l140:
  return (OOC_SSA_IGraph__ColorArray)i2;
  ;
}

void OOC_OOC_SSA_IGraph_init(void) {
  _c0 = Object__NewLatin1Region("", 1, 0, 0);

  return;
  ;
}

/* --- */
