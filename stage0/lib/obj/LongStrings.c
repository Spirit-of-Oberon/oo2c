#include <LongStrings.d>
#include <__oo2c.h>
#include <setjmp.h>

OOC_INT16 LongStrings__Length(const OOC_CHAR16 stringVal__ref[], OOC_LEN stringVal_0d) {
  register OOC_INT32 i0,i1;
  OOC_ALLOCATE_VPAR(stringVal,OOC_CHAR16 ,stringVal_0d)

  OOC_INITIALIZE_VPAR(stringVal__ref,stringVal,OOC_CHAR16 ,(stringVal_0d*2))
  i0 = *(OOC_UINT16*)((OOC_INT32)stringVal+(_check_index(0, stringVal_0d, OOC_UINT16, 2275))*2);
  i0 = i0!=0u;
  if (i0) goto l3;
  i0=0;
  goto l9;
l3:
  i0=0;
l4_loop:
  i0 = i0+1;
  i1 = *(OOC_UINT16*)((OOC_INT32)stringVal+(_check_index(i0, stringVal_0d, OOC_UINT16, 2275))*2);
  i1 = i1!=0u;
  if (i1) goto l4_loop;
l9:
  return i0;
  ;
}

void LongStrings__Assign(const OOC_CHAR16 source__ref[], OOC_LEN source_0d, OOC_CHAR16 destination[], OOC_LEN destination_0d) {
  register OOC_INT32 i0,i1,i2;
  OOC_ALLOCATE_VPAR(source,OOC_CHAR16 ,source_0d)

  OOC_INITIALIZE_VPAR(source__ref,source,OOC_CHAR16 ,(source_0d*2))
  i0 = destination_0d-1;
  i1=(-1);
l1_loop:
  i1 = i1+1;
  i2 = *(OOC_UINT16*)((OOC_INT32)source+(_check_index(i1, source_0d, OOC_UINT16, 2716))*2);
  *(OOC_UINT16*)((OOC_INT32)destination+(_check_index(i1, destination_0d, OOC_UINT16, 2703))*2) = i2;
  i2 = *(OOC_UINT16*)((OOC_INT32)destination+(_check_index(i1, destination_0d, OOC_UINT16, 2742))*2);
  i2 = i2==0u;
  if (i2) goto l4;
  i2 = i1==i0;
  
  goto l6;
l4:
  i2=1u;
l6:
  if (!i2) goto l1_loop;
l9:
  *(OOC_UINT16*)((OOC_INT32)destination+(_check_index(i1, destination_0d, OOC_UINT16, 2797))*2) = 0u;
  return;
  ;
}

void LongStrings__Extract(const OOC_CHAR16 source__ref[], OOC_LEN source_0d, OOC_INT16 startPos, OOC_INT16 numberToExtract, OOC_CHAR16 destination[], OOC_LEN destination_0d) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_ALLOCATE_VPAR(source,OOC_CHAR16 ,source_0d)

  OOC_INITIALIZE_VPAR(source__ref,source,OOC_CHAR16 ,(source_0d*2))
  i0 = LongStrings__Length((void*)(OOC_INT32)source, source_0d);
  i1 = startPos;
  i2 = i1>i0;
  if (i2) goto l4;
  i0=i1;
l4:
  i1 = numberToExtract;
  i1 = i1>=destination_0d;
  if (!i1) goto l7;
  numberToExtract = (destination_0d-1);
l7:
  i1 = numberToExtract;
  i2 = 0<i1;
  if (i2) goto l10;
  i2=0u;
  goto l12;
l10:
  i2 = *(OOC_UINT16*)((OOC_INT32)source+(_check_index(i0, source_0d, OOC_UINT16, 3964))*2);
  i2 = i2!=0u;
  
l12:
  if (i2) goto l14;
  i0=0;
  goto l24;
l14:
  i2=0;
l15_loop:
  i3 = *(OOC_UINT16*)((OOC_INT32)source+(_check_index((i0+i2), source_0d, OOC_UINT16, 4016))*2);
  *(OOC_UINT16*)((OOC_INT32)destination+(_check_index(i2, destination_0d, OOC_UINT16, 4003))*2) = i3;
  i2 = i2+1;
  i3 = i2<i1;
  if (i3) goto l18;
  i3=0u;
  goto l20;
l18:
  i3 = *(OOC_UINT16*)((OOC_INT32)source+(_check_index((i0+i2), source_0d, OOC_UINT16, 3964))*2);
  i3 = i3!=0u;
  
l20:
  if (i3) goto l15_loop;
l23:
  i0=i2;
l24:
  *(OOC_UINT16*)((OOC_INT32)destination+(_check_index(i0, destination_0d, OOC_UINT16, 4068))*2) = 0u;
  return;
  ;
}

void LongStrings__Delete(OOC_CHAR16 stringVar[], OOC_LEN stringVar_0d, OOC_INT16 startPos, OOC_INT16 numberToDelete) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = LongStrings__Length((void*)(OOC_INT32)stringVar, stringVar_0d);
  i1 = startPos;
  i2 = numberToDelete;
  i3 = (i1+i2)<i0;
  if (i3) goto l6;
  i0 = i1<i0;
  if (!i0) goto l15;
  *(OOC_UINT16*)((OOC_INT32)stringVar+(_check_index(i1, stringVar_0d, OOC_UINT16, 5023))*2) = 0u;
  goto l15;
l6:
  i0 = i0-i2;
  i3 = i1<=i0;
  if (!i3) goto l15;
  i2 = i2+i1;
  
l9_loop:
  i3 = *(OOC_UINT16*)((OOC_INT32)stringVar+(_check_index(i2, stringVar_0d, OOC_UINT16, 4938))*2);
  *(OOC_UINT16*)((OOC_INT32)stringVar+(_check_index(i1, stringVar_0d, OOC_UINT16, 4922))*2) = i3;
  i2 = i2+1;
  i1 = i1+1;
  i3 = i1<=i0;
  if (i3) goto l9_loop;
l15:
  return;
  ;
}

void LongStrings__Insert(const OOC_CHAR16 source__ref[], OOC_LEN source_0d, OOC_INT16 startPos, OOC_CHAR16 destination[], OOC_LEN destination_0d) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_ALLOCATE_VPAR(source,OOC_CHAR16 ,source_0d)

  OOC_INITIALIZE_VPAR(source__ref,source,OOC_CHAR16 ,(source_0d*2))
  i0 = LongStrings__Length((void*)(OOC_INT32)destination, destination_0d);
  i1 = LongStrings__Length((void*)(OOC_INT32)source, source_0d);
  i2 = startPos;
  i3 = destination_0d-1;
  i4 = (i2+i1)<i3;
  if (i4) goto l7;
  i0 = i2<=i0;
  if (i0) goto l5;
  i0=0;
  goto l20;
l5:
  *(OOC_UINT16*)((OOC_INT32)destination+(_check_index(i3, destination_0d, OOC_UINT16, 6568))*2) = 0u;
  i0 = i3-i2;
  
  goto l20;
l7:
  i4 = (i0+i1)>=destination_0d;
  if (!i4) goto l11;
  i0 = i3-i1;
  *(OOC_UINT16*)((OOC_INT32)destination+(_check_index(i0, destination_0d, OOC_UINT16, 6253))*2) = 0u;
  
l11:
  i3 = i0>=i2;
  if (!i3) goto l19;
  i3 = i1+i0;
  
l14_loop:
  i4 = *(OOC_UINT16*)((OOC_INT32)destination+(_check_index(i0, destination_0d, OOC_UINT16, 6434))*2);
  *(OOC_UINT16*)((OOC_INT32)destination+(_check_index(i3, destination_0d, OOC_UINT16, 6403))*2) = i4;
  i3 = i3+(-1);
  i0 = i0+(-1);
  i4 = i0>=i2;
  if (i4) goto l14_loop;
l19:
  i0=i1;
l20:
  i1 = 0<i0;
  if (!i1) goto l28;
  i1=0;
l23_loop:
  i3 = *(OOC_UINT16*)((OOC_INT32)source+(_check_index(i1, source_0d, OOC_UINT16, 6916))*2);
  *(OOC_UINT16*)((OOC_INT32)destination+(_check_index(i2, destination_0d, OOC_UINT16, 6894))*2) = i3;
  i2 = i2+1;
  i1 = i1+1;
  i3 = i1<i0;
  if (i3) goto l23_loop;
l28:
  return;
  ;
}

void LongStrings__Replace(const OOC_CHAR16 source__ref[], OOC_LEN source_0d, OOC_INT16 startPos, OOC_CHAR16 destination[], OOC_LEN destination_0d) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_ALLOCATE_VPAR(source,OOC_CHAR16 ,source_0d)

  OOC_INITIALIZE_VPAR(source__ref,source,OOC_CHAR16 ,(source_0d*2))
  i0 = LongStrings__Length((void*)(OOC_INT32)destination, destination_0d);
  i1 = startPos;
  i2 = i1<i0;
  if (!i2) goto l19;
  i2 = i1!=i0;
  if (i2) goto l5;
  i2=0u;
  goto l7;
l5:
  i2 = *(OOC_UINT16*)((OOC_INT32)source+(_check_index(0, source_0d, OOC_UINT16, 7840))*2);
  i2 = i2!=0u;
  
l7:
  if (!i2) goto l19;
  i2=0;
l9_loop:
  i3 = *(OOC_UINT16*)((OOC_INT32)source+(_check_index(i2, source_0d, OOC_UINT16, 7892))*2);
  *(OOC_UINT16*)((OOC_INT32)destination+(_check_index(i1, destination_0d, OOC_UINT16, 7872))*2) = i3;
  i2 = i2+1;
  i1 = i1+1;
  i3 = i1!=i0;
  if (i3) goto l12;
  i3=0u;
  goto l14;
l12:
  i3 = *(OOC_UINT16*)((OOC_INT32)source+(_check_index(i2, source_0d, OOC_UINT16, 7840))*2);
  i3 = i3!=0u;
  
l14:
  if (i3) goto l9_loop;
l19:
  return;
  ;
}

void LongStrings__Append(const OOC_CHAR16 source__ref[], OOC_LEN source_0d, OOC_CHAR16 destination[], OOC_LEN destination_0d) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_ALLOCATE_VPAR(source,OOC_CHAR16 ,source_0d)

  OOC_INITIALIZE_VPAR(source__ref,source,OOC_CHAR16 ,(source_0d*2))
  i0 = LongStrings__Length((void*)(OOC_INT32)destination, destination_0d);
  i1 = destination_0d-1;
  i2 = i0<i1;
  if (i2) goto l3;
  i2=0u;
  goto l5;
l3:
  i2 = *(OOC_UINT16*)((OOC_INT32)source+(_check_index(0, source_0d, OOC_UINT16, 8258))*2);
  i2 = i2!=0u;
  
l5:
  if (!i2) goto l17;
  i2=0;
l8_loop:
  i3 = *(OOC_UINT16*)((OOC_INT32)source+(_check_index(i2, source_0d, OOC_UINT16, 8310))*2);
  *(OOC_UINT16*)((OOC_INT32)destination+(_check_index(i0, destination_0d, OOC_UINT16, 8288))*2) = i3;
  i2 = i2+1;
  i0 = i0+1;
  i3 = i0<i1;
  if (i3) goto l11;
  i3=0u;
  goto l13;
l11:
  i3 = *(OOC_UINT16*)((OOC_INT32)source+(_check_index(i2, source_0d, OOC_UINT16, 8258))*2);
  i3 = i3!=0u;
  
l13:
  if (i3) goto l8_loop;
l17:
  *(OOC_UINT16*)((OOC_INT32)destination+(_check_index(i0, destination_0d, OOC_UINT16, 8377))*2) = 0u;
  return;
  ;
}

void LongStrings__Concat(const OOC_CHAR16 source1__ref[], OOC_LEN source1_0d, const OOC_CHAR16 source2__ref[], OOC_LEN source2_0d, OOC_CHAR16 destination[], OOC_LEN destination_0d) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_ALLOCATE_VPAR(source1,OOC_CHAR16 ,source1_0d)
  OOC_ALLOCATE_VPAR(source2,OOC_CHAR16 ,source2_0d)

  OOC_INITIALIZE_VPAR(source1__ref,source1,OOC_CHAR16 ,(source1_0d*2))
  OOC_INITIALIZE_VPAR(source2__ref,source2,OOC_CHAR16 ,(source2_0d*2))
  i0 = *(OOC_UINT16*)((OOC_INT32)source1+(_check_index(0, source1_0d, OOC_UINT16, 8744))*2);
  i0 = i0!=0u;
  if (i0) goto l3;
  i0=0u;
  goto l5;
l3:
  i0 = 0<(destination_0d-1);
  
l5:
  if (i0) goto l7;
  i0=0;
  goto l17;
l7:
  i0 = destination_0d-1;
  i1=0;
l8_loop:
  i2 = *(OOC_UINT16*)((OOC_INT32)source1+(_check_index(i1, source1_0d, OOC_UINT16, 8815))*2);
  *(OOC_UINT16*)((OOC_INT32)destination+(_check_index(i1, destination_0d, OOC_UINT16, 8801))*2) = i2;
  i1 = i1+1;
  i2 = *(OOC_UINT16*)((OOC_INT32)source1+(_check_index(i1, source1_0d, OOC_UINT16, 8744))*2);
  i2 = i2!=0u;
  if (i2) goto l11;
  i2=0u;
  goto l13;
l11:
  i2 = i1<i0;
  
l13:
  if (i2) goto l8_loop;
l16:
  i0=i1;
l17:
  i1 = *(OOC_UINT16*)((OOC_INT32)source2+(_check_index(0, source2_0d, OOC_UINT16, 8922))*2);
  i1 = i1!=0u;
  if (i1) goto l20;
  i1=0u;
  goto l22;
l20:
  i1 = i0<(destination_0d-1);
  
l22:
  if (!i1) goto l34;
  i1 = destination_0d-1;
  i2=0;
l25_loop:
  i3 = *(OOC_UINT16*)((OOC_INT32)source2+(_check_index(i2, source2_0d, OOC_UINT16, 8994))*2);
  *(OOC_UINT16*)((OOC_INT32)destination+(_check_index(i0, destination_0d, OOC_UINT16, 8980))*2) = i3;
  i2 = i2+1;
  i3 = *(OOC_UINT16*)((OOC_INT32)source2+(_check_index(i2, source2_0d, OOC_UINT16, 8922))*2);
  i0 = i0+1;
  i3 = i3!=0u;
  if (i3) goto l28;
  i3=0u;
  goto l30;
l28:
  i3 = i0<i1;
  
l30:
  if (i3) goto l25_loop;
l34:
  *(OOC_UINT16*)((OOC_INT32)destination+(_check_index(i0, destination_0d, OOC_UINT16, 9046))*2) = 0u;
  return;
  ;
}

OOC_CHAR8 LongStrings__CanAssignAll(OOC_INT16 sourceLength, OOC_CHAR16 destination[], OOC_LEN destination_0d) {
  register OOC_INT32 i0;

  i0 = sourceLength;
  return (i0<destination_0d);
  ;
}

OOC_CHAR8 LongStrings__CanExtractAll(OOC_INT16 sourceLength, OOC_INT16 startPos, OOC_INT16 numberToExtract, OOC_CHAR16 destination[], OOC_LEN destination_0d) {
  register OOC_INT32 i0,i1,i2;

  i0 = startPos;
  i1 = numberToExtract;
  i2 = sourceLength;
  i0 = (i0+i1)<=i2;
  if (i0) goto l3;
  i0=0u;
  goto l4;
l3:
  i0 = i1<destination_0d;
  
l4:
  return i0;
  ;
}

OOC_CHAR8 LongStrings__CanDeleteAll(OOC_INT16 stringLength, OOC_INT16 startPos, OOC_INT16 numberToDelete) {
  register OOC_INT32 i0,i1,i2;

  i0 = startPos;
  i1 = numberToDelete;
  i2 = stringLength;
  return ((i0+i1)<=i2);
  ;
}

OOC_CHAR8 LongStrings__CanInsertAll(OOC_INT16 sourceLength, OOC_INT16 startPos, OOC_CHAR16 destination[], OOC_LEN destination_0d) {
  register OOC_INT32 i0,i1;

  i0 = LongStrings__Length((void*)(OOC_INT32)destination, destination_0d);
  i1 = startPos;
  i1 = i1<=i0;
  if (i1) goto l3;
  i0=0u;
  goto l4;
l3:
  i1 = sourceLength;
  i0 = (i1+i0)<destination_0d;
  
l4:
  return i0;
  ;
}

OOC_CHAR8 LongStrings__CanReplaceAll(OOC_INT16 sourceLength, OOC_INT16 startPos, OOC_CHAR16 destination[], OOC_LEN destination_0d) {
  register OOC_INT32 i0,i1,i2;

  i0 = LongStrings__Length((void*)(OOC_INT32)destination, destination_0d);
  i1 = sourceLength;
  i2 = startPos;
  return ((i1+i2)<=i0);
  ;
}

OOC_CHAR8 LongStrings__CanAppendAll(OOC_INT16 sourceLength, OOC_CHAR16 destination[], OOC_LEN destination_0d) {
  register OOC_INT32 i0,i1;

  i0 = LongStrings__Length((void*)(OOC_INT32)destination, destination_0d);
  i1 = sourceLength;
  return ((i0+i1)<destination_0d);
  ;
}

OOC_CHAR8 LongStrings__CanConcatAll(OOC_INT16 source1Length, OOC_INT16 source2Length, OOC_CHAR16 destination[], OOC_LEN destination_0d) {
  register OOC_INT32 i0,i1;

  i0 = source1Length;
  i1 = source2Length;
  return ((i0+i1)<destination_0d);
  ;
}

OOC_INT8 LongStrings__Compare(const OOC_CHAR16 stringVal1__ref[], OOC_LEN stringVal1_0d, const OOC_CHAR16 stringVal2__ref[], OOC_LEN stringVal2_0d) {
  register OOC_INT32 i0,i1,i2;
  OOC_ALLOCATE_VPAR(stringVal1,OOC_CHAR16 ,stringVal1_0d)
  OOC_ALLOCATE_VPAR(stringVal2,OOC_CHAR16 ,stringVal2_0d)

  OOC_INITIALIZE_VPAR(stringVal1__ref,stringVal1,OOC_CHAR16 ,(stringVal1_0d*2))
  OOC_INITIALIZE_VPAR(stringVal2__ref,stringVal2,OOC_CHAR16 ,(stringVal2_0d*2))
  i0 = *(OOC_UINT16*)((OOC_INT32)stringVal1+(_check_index(0, stringVal1_0d, OOC_UINT16, 13278))*2);
  i0 = i0!=0u;
  if (i0) goto l3;
  i0=0u;
  goto l5;
l3:
  i0 = *(OOC_UINT16*)((OOC_INT32)stringVal1+(_check_index(0, stringVal1_0d, OOC_UINT16, 13301))*2);
  i1 = *(OOC_UINT16*)((OOC_INT32)stringVal2+(_check_index(0, stringVal2_0d, OOC_UINT16, 13317))*2);
  i0 = i0==i1;
  
l5:
  if (i0) goto l7;
  i0=0;
  goto l17;
l7:
  i0=0;
l8_loop:
  i0 = i0+1;
  i1 = *(OOC_UINT16*)((OOC_INT32)stringVal1+(_check_index(i0, stringVal1_0d, OOC_UINT16, 13278))*2);
  i1 = i1!=0u;
  if (i1) goto l11;
  i1=0u;
  goto l13;
l11:
  i1 = *(OOC_UINT16*)((OOC_INT32)stringVal1+(_check_index(i0, stringVal1_0d, OOC_UINT16, 13301))*2);
  i2 = *(OOC_UINT16*)((OOC_INT32)stringVal2+(_check_index(i0, stringVal2_0d, OOC_UINT16, 13317))*2);
  i1 = i1==i2;
  
l13:
  if (i1) goto l8_loop;
l17:
  i1 = *(OOC_UINT16*)((OOC_INT32)stringVal1+(_check_index(i0, stringVal1_0d, OOC_UINT16, 13366))*2);
  i2 = *(OOC_UINT16*)((OOC_INT32)stringVal2+(_check_index(i0, stringVal2_0d, OOC_UINT16, 13382))*2);
  i1 = (OOC_UINT16)i1<(OOC_UINT16)i2;
  if (i1) goto l24;
  i1 = *(OOC_UINT16*)((OOC_INT32)stringVal1+(_check_index(i0, stringVal1_0d, OOC_UINT16, 13432))*2);
  i0 = *(OOC_UINT16*)((OOC_INT32)stringVal2+(_check_index(i0, stringVal2_0d, OOC_UINT16, 13448))*2);
  i0 = (OOC_UINT16)i1>(OOC_UINT16)i0;
  if (i0) goto l22;
  return 0;
  goto l25;
l22:
  return 1;
  goto l25;
l24:
  return (-1);
l25:
  _failed_function(12884); return 0;
  ;
}

OOC_CHAR8 LongStrings__Equal(const OOC_CHAR16 stringVal1__ref[], OOC_LEN stringVal1_0d, const OOC_CHAR16 stringVal2__ref[], OOC_LEN stringVal2_0d) {
  register OOC_INT32 i0,i1,i2;
  OOC_ALLOCATE_VPAR(stringVal1,OOC_CHAR16 ,stringVal1_0d)
  OOC_ALLOCATE_VPAR(stringVal2,OOC_CHAR16 ,stringVal2_0d)

  OOC_INITIALIZE_VPAR(stringVal1__ref,stringVal1,OOC_CHAR16 ,(stringVal1_0d*2))
  OOC_INITIALIZE_VPAR(stringVal2__ref,stringVal2,OOC_CHAR16 ,(stringVal2_0d*2))
  i0 = *(OOC_UINT16*)((OOC_INT32)stringVal1+(_check_index(0, stringVal1_0d, OOC_UINT16, 13814))*2);
  i0 = i0!=0u;
  if (i0) goto l3;
  i0=0u;
  goto l5;
l3:
  i0 = *(OOC_UINT16*)((OOC_INT32)stringVal1+(_check_index(0, stringVal1_0d, OOC_UINT16, 13837))*2);
  i1 = *(OOC_UINT16*)((OOC_INT32)stringVal2+(_check_index(0, stringVal2_0d, OOC_UINT16, 13853))*2);
  i0 = i0==i1;
  
l5:
  if (i0) goto l7;
  i0=0;
  goto l17;
l7:
  i0=0;
l8_loop:
  i0 = i0+1;
  i1 = *(OOC_UINT16*)((OOC_INT32)stringVal1+(_check_index(i0, stringVal1_0d, OOC_UINT16, 13814))*2);
  i1 = i1!=0u;
  if (i1) goto l11;
  i1=0u;
  goto l13;
l11:
  i1 = *(OOC_UINT16*)((OOC_INT32)stringVal1+(_check_index(i0, stringVal1_0d, OOC_UINT16, 13837))*2);
  i2 = *(OOC_UINT16*)((OOC_INT32)stringVal2+(_check_index(i0, stringVal2_0d, OOC_UINT16, 13853))*2);
  i1 = i1==i2;
  
l13:
  if (i1) goto l8_loop;
l17:
  i1 = *(OOC_UINT16*)((OOC_INT32)stringVal1+(_check_index(i0, stringVal1_0d, OOC_UINT16, 13906))*2);
  i1 = i1==0u;
  if (i1) goto l20;
  i0=0u;
  goto l21;
l20:
  i0 = *(OOC_UINT16*)((OOC_INT32)stringVal2+(_check_index(i0, stringVal2_0d, OOC_UINT16, 13929))*2);
  i0 = i0==0u;
  
l21:
  return i0;
  ;
}

void LongStrings__FindNext(const OOC_CHAR16 pattern__ref[], OOC_LEN pattern_0d, const OOC_CHAR16 stringToSearch__ref[], OOC_LEN stringToSearch_0d, OOC_INT16 startPos, OOC_CHAR8 *patternFound, OOC_INT16 *posOfPattern) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_ALLOCATE_VPAR(pattern,OOC_CHAR16 ,pattern_0d)
  OOC_ALLOCATE_VPAR(stringToSearch,OOC_CHAR16 ,stringToSearch_0d)

  OOC_INITIALIZE_VPAR(pattern__ref,pattern,OOC_CHAR16 ,(pattern_0d*2))
  OOC_INITIALIZE_VPAR(stringToSearch__ref,stringToSearch,OOC_CHAR16 ,(stringToSearch_0d*2))
  i0 = LongStrings__Length((void*)(OOC_INT32)stringToSearch, stringToSearch_0d);
  i1 = startPos;
  i0 = i1<i0;
  if (i0) goto l3;
  *patternFound = 0u;
  goto l18;
l3:
  i2=i1;i0=0;
l4_loop:
  i3 = *(OOC_UINT16*)((OOC_INT32)pattern+(_check_index(i0, pattern_0d, OOC_UINT16, 15009))*2);
  i3 = i3==0u;
  if (i3) goto l16;
  i3 = *(OOC_UINT16*)((OOC_INT32)stringToSearch+(_check_index(i1, stringToSearch_0d, OOC_UINT16, 15200))*2);
  i3 = i3==0u;
  if (i3) goto l14;
  i3 = *(OOC_UINT16*)((OOC_INT32)stringToSearch+(_check_index(i1, stringToSearch_0d, OOC_UINT16, 15351))*2);
  i4 = *(OOC_UINT16*)((OOC_INT32)pattern+(_check_index(i0, pattern_0d, OOC_UINT16, 15371))*2);
  i3 = i3==i4;
  if (i3) goto l11;
  i0 = i2+1;
  i1=i0;i0=0;
  goto l13;
l11:
  i1 = i1+1;
  i0 = i0+1;
  
l13:
  i2 = i1-i0;
  
  goto l4_loop;
l14:
  *patternFound = 0u;
  goto l18;
l16:
  *patternFound = 1u;
  *posOfPattern = i2;
l18:
  return;
  ;
}

void LongStrings__FindPrev(const OOC_CHAR16 pattern__ref[], OOC_LEN pattern_0d, const OOC_CHAR16 stringToSearch__ref[], OOC_LEN stringToSearch_0d, OOC_INT16 startPos, OOC_CHAR8 *patternFound, OOC_INT16 *posOfPattern) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_ALLOCATE_VPAR(pattern,OOC_CHAR16 ,pattern_0d)
  OOC_ALLOCATE_VPAR(stringToSearch,OOC_CHAR16 ,stringToSearch_0d)

  OOC_INITIALIZE_VPAR(pattern__ref,pattern,OOC_CHAR16 ,(pattern_0d*2))
  OOC_INITIALIZE_VPAR(stringToSearch__ref,stringToSearch,OOC_CHAR16 ,(stringToSearch_0d*2))
  i0 = LongStrings__Length((void*)(OOC_INT32)stringToSearch, stringToSearch_0d);
  i1 = LongStrings__Length((void*)(OOC_INT32)pattern, pattern_0d);
  i0 = i0-i1;
  i1 = startPos;
  i2 = i1>i0;
  if (i2) goto l4;
  i0=i1;
l4:
  i1 = i0>=0;
  if (i1) goto l7;
  *patternFound = 0u;
  goto l22;
l7:
  i1=i0;i2=i0;i0=0;
l8_loop:
  i3 = *(OOC_UINT16*)((OOC_INT32)pattern+(_check_index(i0, pattern_0d, OOC_UINT16, 17134))*2);
  i3 = i3==0u;
  if (i3) goto l20;
  i3 = *(OOC_UINT16*)((OOC_INT32)stringToSearch+(_check_index(i1, stringToSearch_0d, OOC_UINT16, 17325))*2);
  i4 = *(OOC_UINT16*)((OOC_INT32)pattern+(_check_index(i0, pattern_0d, OOC_UINT16, 17345))*2);
  i3 = i3!=i4;
  if (i3) goto l13;
  i1 = i1+1;
  i0 = i0+1;
  
  goto l18;
l13:
  i0 = i1>i0;
  if (i0) goto l16;
  *patternFound = 0u;
  goto l22;
l16:
  i0 = i2-1;
  i1=i0;i0=0;
l18:
  i2 = i1-i0;
  
  goto l8_loop;
l20:
  *patternFound = 1u;
  *posOfPattern = i2;
l22:
  return;
  ;
}

void LongStrings__FindDiff(const OOC_CHAR16 stringVal1__ref[], OOC_LEN stringVal1_0d, const OOC_CHAR16 stringVal2__ref[], OOC_LEN stringVal2_0d, OOC_CHAR8 *differenceFound, OOC_INT16 *posOfDifference) {
  register OOC_INT32 i0,i1,i2;
  OOC_ALLOCATE_VPAR(stringVal1,OOC_CHAR16 ,stringVal1_0d)
  OOC_ALLOCATE_VPAR(stringVal2,OOC_CHAR16 ,stringVal2_0d)

  OOC_INITIALIZE_VPAR(stringVal1__ref,stringVal1,OOC_CHAR16 ,(stringVal1_0d*2))
  OOC_INITIALIZE_VPAR(stringVal2__ref,stringVal2,OOC_CHAR16 ,(stringVal2_0d*2))
  i0 = *(OOC_UINT16*)((OOC_INT32)stringVal1+(_check_index(0, stringVal1_0d, OOC_UINT16, 18508))*2);
  i0 = i0!=0u;
  if (i0) goto l3;
  i0=0u;
  goto l5;
l3:
  i0 = *(OOC_UINT16*)((OOC_INT32)stringVal1+(_check_index(0, stringVal1_0d, OOC_UINT16, 18531))*2);
  i1 = *(OOC_UINT16*)((OOC_INT32)stringVal2+(_check_index(0, stringVal2_0d, OOC_UINT16, 18547))*2);
  i0 = i0==i1;
  
l5:
  if (i0) goto l7;
  i0=0;
  goto l17;
l7:
  i0=0;
l8_loop:
  i0 = i0+1;
  i1 = *(OOC_UINT16*)((OOC_INT32)stringVal1+(_check_index(i0, stringVal1_0d, OOC_UINT16, 18508))*2);
  i1 = i1!=0u;
  if (i1) goto l11;
  i1=0u;
  goto l13;
l11:
  i1 = *(OOC_UINT16*)((OOC_INT32)stringVal1+(_check_index(i0, stringVal1_0d, OOC_UINT16, 18531))*2);
  i2 = *(OOC_UINT16*)((OOC_INT32)stringVal2+(_check_index(i0, stringVal2_0d, OOC_UINT16, 18547))*2);
  i1 = i1==i2;
  
l13:
  if (i1) goto l8_loop;
l17:
  i1 = *(OOC_UINT16*)((OOC_INT32)stringVal1+(_check_index(i0, stringVal1_0d, OOC_UINT16, 18612))*2);
  i1 = i1!=0u;
  if (i1) goto l20;
  i1 = *(OOC_UINT16*)((OOC_INT32)stringVal2+(_check_index(i0, stringVal2_0d, OOC_UINT16, 18636))*2);
  i1 = i1!=0u;
  
  goto l21;
l20:
  i1=1u;
l21:
  *differenceFound = i1;
  if (!i1) goto l24;
  *posOfDifference = i0;
l24:
  return;
  ;
}

void LongStrings__Capitalize(OOC_CHAR16 stringVar[], OOC_LEN stringVar_0d) {
  register OOC_INT32 i0,i1;

  i0 = *(OOC_UINT16*)((OOC_INT32)stringVar+(_check_index(0, stringVar_0d, OOC_UINT16, 18953))*2);
  i0 = i0!=0u;
  if (!i0) goto l8;
  i0=0;
l3_loop:
  i1 = *(OOC_UINT16*)((OOC_INT32)stringVar+(_check_index(i0, stringVar_0d, OOC_UINT16, 19002))*2);
  *(OOC_UINT16*)((OOC_INT32)stringVar+(_check_index(i0, stringVar_0d, OOC_UINT16, 18981))*2) = (_cap(i1));
  i0 = i0+1;
  i1 = *(OOC_UINT16*)((OOC_INT32)stringVar+(_check_index(i0, stringVar_0d, OOC_UINT16, 18953))*2);
  i1 = i1!=0u;
  if (i1) goto l3_loop;
l8:
  return;
  ;
}

void LongStrings__Long(const OOC_CHAR8 source__ref[], OOC_LEN source_0d, OOC_CHAR16 destination[], OOC_LEN destination_0d) {
  OOC_ALLOCATE_VPAR(source,OOC_CHAR8 ,source_0d)

  OOC_INITIALIZE_VPAR(source__ref,source,OOC_CHAR8 ,source_0d)
  _copy_8to16((const void*)(OOC_INT32)source,(void*)(OOC_INT32)destination,destination_0d);
  return;
  ;
}

void LongStrings__Short(const OOC_CHAR16 source__ref[], OOC_LEN source_0d, OOC_CHAR8 repl, OOC_CHAR8 destination[], OOC_LEN destination_0d) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_ALLOCATE_VPAR(source,OOC_CHAR16 ,source_0d)

  OOC_INITIALIZE_VPAR(source__ref,source,OOC_CHAR16 ,(source_0d*2))
  i0 = *(OOC_UINT16*)((OOC_INT32)source+(_check_index(0, source_0d, OOC_UINT16, 19846))*2);
  i1 = destination_0d-1;
  i0 = i0!=0u;
  if (i0) goto l3;
  i0=0u;
  goto l5;
l3:
  i0 = 0!=i1;
  
l5:
  if (i0) goto l7;
  i0=0;
  goto l21;
l7:
  i0 = repl;
  i2=0;
l8_loop:
  i3 = *(OOC_UINT16*)((OOC_INT32)source+(_check_index(i2, source_0d, OOC_UINT16, 19887))*2);
  i3 = (OOC_UINT16)i3<=(OOC_UINT16)255u;
  if (i3) goto l11;
  *(OOC_UINT8*)((OOC_INT32)destination+(_check_index(i2, destination_0d, OOC_UINT16, 19985))) = i0;
  goto l12;
l11:
  i3 = *(OOC_UINT16*)((OOC_INT32)source+(_check_index(i2, source_0d, OOC_UINT16, 19950))*2);
  *(OOC_UINT8*)((OOC_INT32)destination+(_check_index(i2, destination_0d, OOC_UINT16, 19930))) = i3;
l12:
  i2 = i2+1;
  i3 = *(OOC_UINT16*)((OOC_INT32)source+(_check_index(i2, source_0d, OOC_UINT16, 19846))*2);
  i3 = i3!=0u;
  if (i3) goto l15;
  i3=0u;
  goto l17;
l15:
  i3 = i2!=i1;
  
l17:
  if (i3) goto l8_loop;
l20:
  i0=i2;
l21:
  *(OOC_UINT8*)((OOC_INT32)destination+(_check_index(i0, destination_0d, OOC_UINT16, 20046))) = 0u;
  return;
  ;
}

void OOC_LongStrings_init(void) {

  return;
  ;
}

/* --- */
