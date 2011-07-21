#include <ADT/Object/Storage.d>
#include <__oo2c.h>
#include <setjmp.h>

void ADT_Object_Storage__InitReader(ADT_Object_Storage__Reader r, IO__ByteChannel ch) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)ch;
  ADT_Storable__InitReader((ADT_Storable__Reader)i0, (IO__ByteChannel)i1);
  *(OOC_INT32*)((_check_pointer(i0, 3309))+12) = ((OOC_INT32)RT0__NewObject(_td_ADT_Object_Storage__ObjectArray.baseTypes[0], 124));
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3341))+12);
  i1 = _check_pointer(i1, 3349);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  *(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 3349))*4) = (OOC_INT32)0;
  *(OOC_INT32*)((_check_pointer(i0, 3366))+8) = 1;
  *(OOC_INT32*)((_check_pointer(i0, 3395))+20) = ((OOC_INT32)RT0__NewObject(_td_ADT_Object_Storage__TypeArray.baseTypes[0], 12));
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3427))+20);
  i1 = _check_pointer(i1, 3436);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  *(OOC_INT32*)(i1+((_check_index(0, i2, OOC_UINT8, 3436))*12)) = (OOC_INT32)0;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3459))+20);
  i1 = _check_pointer(i1, 3468);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  *(OOC_INT32*)((i1+((_check_index(0, i2, OOC_UINT8, 3468))*12))+4) = (OOC_INT32)0;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3497))+20);
  i1 = _check_pointer(i1, 3506);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  *(OOC_INT32*)((i1+((_check_index(0, i2, OOC_UINT8, 3506))*12))+8) = (OOC_INT32)0;
  *(OOC_INT32*)((_check_pointer(i0, 3533))+16) = 1;
  return;
  ;
}

void ADT_Object_Storage__InitWriter(ADT_Object_Storage__Writer w, IO__ByteChannel ch) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)ch;
  ADT_Storable__InitWriter((ADT_Storable__Writer)i0, (IO__ByteChannel)i1);
  *(OOC_INT32*)((_check_pointer(i0, 3672))+8) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 3701))+12) = ((OOC_INT32)RT0__NewObject(_td_ADT_Object_Storage__TypeRefMap.baseTypes[0], 12));
  *(OOC_INT32*)((_check_pointer(i0, 3736))+16) = 0;
  i1 = (OOC_INT32)ADT_Dictionary_AddressKey_IntValue__New();
  *(OOC_INT32*)((_check_pointer(i0, 3761))+20) = i1;
  return;
  ;
}

ADT_Object_Storage__Reader ADT_Object_Storage__ConnectReader(IO__ByteChannel ch) {
  register OOC_INT32 i0,i1;
  ADT_Object_Storage__Reader r;

  i0 = (OOC_INT32)RT0__NewObject(_td_ADT_Object_Storage__Reader.baseTypes[0]);
  r = (ADT_Object_Storage__Reader)i0;
  i1 = (OOC_INT32)ch;
  ADT_Object_Storage__InitReader((ADT_Object_Storage__Reader)i0, (IO__ByteChannel)i1);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4013))+4);
  i1 = i1==(OOC_INT32)0;
  if (i1) goto l3;
  return (ADT_Object_Storage__Reader)i0;
  goto l4;
l3:
  return (ADT_Object_Storage__Reader)(OOC_INT32)0;
l4:
  _failed_function(3822); return 0;
  ;
}

ADT_Object_Storage__Writer ADT_Object_Storage__ConnectWriter(IO__ByteChannel ch) {
  register OOC_INT32 i0,i1;
  ADT_Object_Storage__Writer w;

  i0 = (OOC_INT32)RT0__NewObject(_td_ADT_Object_Storage__Writer.baseTypes[0]);
  w = (ADT_Object_Storage__Writer)i0;
  i1 = (OOC_INT32)ch;
  ADT_Object_Storage__InitWriter((ADT_Object_Storage__Writer)i0, (IO__ByteChannel)i1);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4360))+4);
  i1 = i1==(OOC_INT32)0;
  if (i1) goto l3;
  return (ADT_Object_Storage__Writer)i0;
  goto l4;
l3:
  return (ADT_Object_Storage__Writer)(OOC_INT32)0;
l4:
  _failed_function(4169); return 0;
  ;
}

void ADT_Object_Storage__ReaderDesc_ReadObject(ADT_Object_Storage__Reader r, Object__Object *obj) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_INT32 ref;
  OOC_INT32 tref;
  RT0__Struct type;
  Object__String str;
  RT0__Module module;
  auto OOC_INT32 ADT_Object_Storage__ReaderDesc_ReadObject_ReadType(void);
  auto void ADT_Object_Storage__ReaderDesc_ReadObject_ExtendObjTab(ADT_Object_Storage__ObjectArray *tab);
    
    OOC_INT32 ADT_Object_Storage__ReaderDesc_ReadObject_ReadType(void) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
      OOC_INT32 tref;
      OOC_INT32 len;
      OOC_INT32 i;
      RT0__Struct tp;
      auto void ADT_Object_Storage__ReaderDesc_ReadObject_ReadType_ExtendTypeTab(ADT_Object_Storage__TypeArray *tab);
        
        void ADT_Object_Storage__ReaderDesc_ReadObject_ReadType_ExtendTypeTab(ADT_Object_Storage__TypeArray *tab) {
          register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
          ADT_Object_Storage__TypeArray _new;
          OOC_INT32 i;

          i0 = (OOC_INT32)*tab;
          i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 4942)), 0);
          i1 = (OOC_INT32)RT0__NewObject(_td_ADT_Object_Storage__TypeArray.baseTypes[0], (4+i1*2));
          _new = (ADT_Object_Storage__TypeArray)i1;
          i = 0;
          i0 = OOC_ARRAY_LENGTH((_check_pointer(i0, 4990)), 0);
          i2 = 0<i0;
          if (!i2) goto l8;
          i2=0;
l3_loop:
          i3 = (OOC_INT32)*tab;
          i3 = _check_pointer(i3, 5021);
          i4 = OOC_ARRAY_LENGTH(i3, 0);
          i5 = _check_pointer(i1, 5011);
          i6 = OOC_ARRAY_LENGTH(i5, 0);
          _copy_block((i3+((_check_index(i2, i4, OOC_UINT32, 5021))*12)),(i5+((_check_index(i2, i6, OOC_UINT32, 5011))*12)),12);
          i2 = i2+1;
          i = i2;
          i3 = i2<i0;
          if (i3) goto l3_loop;
l8:
          *tab = (ADT_Object_Storage__TypeArray)i1;
          return;
          ;
        }


      i0 = (OOC_INT32)r;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5100)))), IO_BinaryRider__ReaderDesc_ReadNum)),IO_BinaryRider__ReaderDesc_ReadNum)((IO_BinaryRider__Reader)i0, (void*)(OOC_INT32)&tref);
      i0 = tref;
      i1 = i0<0;
      if (i1) goto l33;
      i1 = (OOC_INT32)r;
      i2 = *(OOC_INT32*)((_check_pointer(i1, 5411))+16);
      i2 = i0!=i2;
      if (!i2) goto l5;
      IO__RaiseFormatError((Object__String)((OOC_INT32)_c0));
l5:
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 5523))+20);
      i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 5532)), 0);
      i0 = i0==i2;
      if (!i0) goto l8;
      ADT_Object_Storage__ReaderDesc_ReadObject_ReadType_ExtendTypeTab((void*)((_check_pointer(i1, 5567))+20));
l8:
      i0 = (OOC_INT32)r;
      i1 = *(OOC_INT32*)((_check_pointer(i0, 5605))+16);
      *(OOC_INT32*)((_check_pointer(i0, 5605))+16) = (i1+1);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5716)))), IO_BinaryRider__ReaderDesc_ReadString)),IO_BinaryRider__ReaderDesc_ReadString)((IO_BinaryRider__Reader)i0, (void*)((_check_pointer(i0, 5731))+24), 256);
      i0 = (OOC_INT32)r;
      i0 = (OOC_INT32)RT0__ThisModule((void*)((_check_pointer(i0, 5775))+24), 256);
      module = (RT0__Module)i0;
      i1 = i0==(OOC_INT32)0;
      if (i1) goto l11;
      i1 = (OOC_INT32)r;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 6094))+20);
      i2 = _check_pointer(i2, 6103);
      i3 = OOC_ARRAY_LENGTH(i2, 0);
      i4 = tref;
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 6131));
      *(OOC_INT32*)((i2+((_check_index(i4, i3, OOC_UINT32, 6103))*12))+4) = i0;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 6150)))), IO_BinaryRider__ReaderDesc_ReadString)),IO_BinaryRider__ReaderDesc_ReadString)((IO_BinaryRider__Reader)i1, (void*)((_check_pointer(i1, 6165))+24), 256);
      i0 = (OOC_INT32)r;
      i1 = (OOC_INT32)module;
      i0 = (OOC_INT32)RT0__ThisType((RT0__Module)i1, (void*)((_check_pointer(i0, 6213))+24), 256);
      tp = (RT0__Struct)i0;
      
      goto l20;
l11:
      i0 = (OOC_INT32)r;
      i1 = Strings__Length((void*)((_check_pointer(i0, 5849))+24), 256);
      i1 = i1+1;
      len = i1;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5876))+20);
      i2 = _check_pointer(i2, 5885);
      i3 = OOC_ARRAY_LENGTH(i2, 0);
      i4 = tref;
      *(OOC_INT32*)((i2+((_check_index(i4, i3, OOC_UINT32, 5885))*12))+4) = ((OOC_INT32)RT0__NewObject(_td_RT0__Name.baseTypes[0], i1));
      i = 0;
      i2 = 0<i1;
      if (!i2) goto l19;
      i2=0;
l14_loop:
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5957))+20);
      i3 = _check_pointer(i3, 5965);
      i5 = OOC_ARRAY_LENGTH(i3, 0);
      i3 = (OOC_INT32)*(OOC_INT32*)((i3+((_check_index(i4, i5, OOC_UINT32, 5965))*12))+4);
      i5 = *(OOC_UINT8*)(((_check_pointer(i0, 5990))+24)+(_check_index(i2, 256, OOC_UINT32, 5995)));
      *(OOC_UINT8*)((_check_pointer(i3, 5982))+i2) = i5;
      i2 = i2+1;
      i = i2;
      i3 = i2<i1;
      if (i3) goto l14_loop;
l19:
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6026)))), IO_BinaryRider__ReaderDesc_ReadString)),IO_BinaryRider__ReaderDesc_ReadString)((IO_BinaryRider__Reader)i0, (void*)((_check_pointer(i0, 6041))+24), 256);
      tp = (RT0__Struct)(OOC_INT32)0;
      i0=(OOC_INT32)0;
l20:
      i1 = (OOC_INT32)r;
      i2 = tref;
      i3 = i0==(OOC_INT32)0;
      if (i3) goto l23;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 6482))+20);
      i3 = _check_pointer(i3, 6491);
      i4 = OOC_ARRAY_LENGTH(i3, 0);
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6513))+16);
      *(OOC_INT32*)((i3+((_check_index(i2, i4, OOC_UINT32, 6491))*12))+8) = i5;
      goto l32;
l23:
      i3 = Strings__Length((void*)((_check_pointer(i1, 6296))+24), 256);
      i3 = i3+1;
      len = i3;
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 6323))+20);
      i4 = _check_pointer(i4, 6332);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      *(OOC_INT32*)((i4+((_check_index(i2, i5, OOC_UINT32, 6332))*12))+8) = ((OOC_INT32)RT0__NewObject(_td_RT0__Name.baseTypes[0], i3));
      i = 0;
      i4 = 0<i3;
      if (!i4) goto l32;
      i4=0;
l26_loop:
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 6402))+20);
      i5 = _check_pointer(i5, 6410);
      i6 = OOC_ARRAY_LENGTH(i5, 0);
      i5 = (OOC_INT32)*(OOC_INT32*)((i5+((_check_index(i2, i6, OOC_UINT32, 6410))*12))+8);
      i6 = *(OOC_UINT8*)(((_check_pointer(i1, 6433))+24)+(_check_index(i4, 256, OOC_UINT32, 6438)));
      *(OOC_UINT8*)((_check_pointer(i5, 6425))+i4) = i6;
      i4 = i4+1;
      i = i4;
      i5 = i4<i3;
      if (i5) goto l26_loop;
l32:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 6542))+20);
      i1 = _check_pointer(i1, 6551);
      i3 = OOC_ARRAY_LENGTH(i1, 0);
      *(OOC_INT32*)(i1+((_check_index(i2, i3, OOC_UINT32, 6551))*12)) = i0;
      return i2;
      goto l38;
l33:
      i1 = (OOC_INT32)r;
      i1 = *(OOC_INT32*)((_check_pointer(i1, 5212))+16);
      i0 = -i0;
      i1 = i0>=i1;
      if (i1) goto l36;
      return i0;
      goto l38;
l36:
      IO__RaiseFormatError((Object__String)((OOC_INT32)_c1));
l38:
      _failed_function(4697); return 0;
      ;
    }

    
    void ADT_Object_Storage__ReaderDesc_ReadObject_ExtendObjTab(ADT_Object_Storage__ObjectArray *tab) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
      ADT_Object_Storage__ObjectArray _new;
      OOC_INT32 i;

      i0 = (OOC_INT32)*tab;
      i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 6757)), 0);
      i1 = (OOC_INT32)RT0__NewObject(_td_ADT_Object_Storage__ObjectArray.baseTypes[0], (4+i1*2));
      _new = (ADT_Object_Storage__ObjectArray)i1;
      i = 0;
      i0 = OOC_ARRAY_LENGTH((_check_pointer(i0, 6803)), 0);
      i2 = 0<i0;
      if (!i2) goto l8;
      i2=0;
l3_loop:
      i3 = _check_pointer(i1, 6822);
      i4 = OOC_ARRAY_LENGTH(i3, 0);
      i5 = (OOC_INT32)*tab;
      i5 = _check_pointer(i5, 6832);
      i6 = OOC_ARRAY_LENGTH(i5, 0);
      i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i2, i6, OOC_UINT32, 6832))*4);
      *(OOC_INT32*)(i3+(_check_index(i2, i4, OOC_UINT32, 6822))*4) = i5;
      i2 = i2+1;
      i = i2;
      i3 = i2<i0;
      if (i3) goto l3_loop;
l8:
      *tab = (ADT_Object_Storage__ObjectArray)i1;
      return;
      ;
    }


  i0 = (OOC_INT32)r;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6902)))), IO_BinaryRider__ReaderDesc_ReadNum)),IO_BinaryRider__ReaderDesc_ReadNum)((IO_BinaryRider__Reader)i0, (void*)(OOC_INT32)&ref);
  i1 = ref;
  i2 = i1==0;
  if (i2) goto l29;
  i2 = i1<0;
  if (i2) goto l23;
  i0 = *(OOC_INT32*)((_check_pointer(i0, 7301))+8);
  i0 = i1!=i0;
  if (!i0) goto l7;
  IO__RaiseFormatError((Object__String)((OOC_INT32)_c2));
l7:
  i0 = ADT_Object_Storage__ReaderDesc_ReadObject_ReadType();
  tref = i0;
  i1 = (OOC_INT32)r;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 7462))+20);
  i2 = _check_pointer(i2, 7471);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i0 = (OOC_INT32)*(OOC_INT32*)(i2+((_check_index(i0, i3, OOC_UINT32, 7471))*12));
  type = (RT0__Struct)i0;
  i0 = i0==(OOC_INT32)0;
  if (i0) goto l21;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 7677))+12);
  i0 = OOC_ARRAY_LENGTH((_check_pointer(i0, 7684)), 0);
  i2 = ref;
  i0 = i2==i0;
  if (!i0) goto l12;
  ADT_Object_Storage__ReaderDesc_ReadObject_ExtendObjTab((void*)((_check_pointer(i1, 7719))+12));
l12:
  i0 = (OOC_INT32)r;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 7759))+8);
  *(OOC_INT32*)((_check_pointer(i0, 7759))+8) = (i1+1);
  i1 = (OOC_INT32)ADT_Object_Storage__string8;
  i2 = (OOC_INT32)type;
  i1 = i2==i1;
  if (i1) goto l15;
  i1 = (OOC_INT32)ADT_Object_Storage__string16;
  i1 = i2==i1;
  
  goto l17;
l15:
  i1=1u;
l17:
  if (i1) goto l19;
  i1 = (OOC_INT32)RT0__NewObject((RT0__Struct)i2);
  i1 = (OOC_INT32)_type_cast_fast(OOC_INT32, OOC_INT32, i1);
  *obj = (Object__Object)i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8010))+12);
  i2 = _check_pointer(i2, 8017);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i4 = ref;
  *(OOC_INT32*)(i2+(_check_index(i4, i3, OOC_UINT32, 8017))*4) = i1;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 8056)))), &_td_ADT_Storable__ObjectDesc, 8056)), 8063)))), ADT_Storable__ObjectDesc_Load)),ADT_Storable__ObjectDesc_Load)((ADT_Storable__Object)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 8056)))), &_td_ADT_Storable__ObjectDesc, 8056)), (ADT_Storable__Reader)i0);
  goto l30;
l19:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7842)))), IO_BinaryRider__ReaderDesc_ReadStr)),IO_BinaryRider__ReaderDesc_ReadStr)((IO_BinaryRider__Reader)i0, (void*)(OOC_INT32)&str);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7870))+12);
  i0 = _check_pointer(i0, 7877);
  i1 = OOC_ARRAY_LENGTH(i0, 0);
  i2 = ref;
  i3 = (OOC_INT32)str;
  *(OOC_INT32*)(i0+(_check_index(i2, i1, OOC_UINT32, 7877))*4) = i3;
  *obj = (Object__Object)i3;
  goto l30;
l21:
  ADT_Storable__RaiseTypeError((Object__String)((OOC_INT32)_c3));
  goto l30;
l23:
  i2 = *(OOC_INT32*)((_check_pointer(i0, 7069))+8);
  i1 = -i1;
  i2 = i1>=i2;
  if (i2) goto l26;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7206))+12);
  i0 = _check_pointer(i0, 7214);
  i2 = OOC_ARRAY_LENGTH(i0, 0);
  i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(i1, i2, OOC_UINT32, 7214))*4);
  *obj = (Object__Object)i0;
  goto l30;
l26:
  IO__RaiseFormatError((Object__String)((OOC_INT32)_c4));
  goto l30;
l29:
  *obj = (Object__Object)(OOC_INT32)0;
l30:
  return;
  ;
}

void ADT_Object_Storage__ReaderDesc_Disconnect(ADT_Object_Storage__Reader r) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_INT32 i;

  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8262))+12);
  i = 0;
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 8270)), 0);
  i2 = 0<i1;
  if (!i2) goto l8;
  i2=0;
l3_loop:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8285))+12);
  i3 = _check_pointer(i3, 8293);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  *(OOC_INT32*)(i3+(_check_index(i2, i4, OOC_UINT32, 8293))*4) = (OOC_INT32)0;
  i2 = i2+1;
  i = i2;
  i3 = i2<i1;
  if (i3) goto l3_loop;
l8:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8337))+20);
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 8346)), 0);
  i = 0;
  i2 = 0<i1;
  if (!i2) goto l16;
  i2=0;
l11_loop:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8361))+20);
  i3 = _check_pointer(i3, 8370);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  *(OOC_INT32*)(i3+((_check_index(i2, i4, OOC_UINT32, 8370))*12)) = (OOC_INT32)0;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8395))+20);
  i3 = _check_pointer(i3, 8404);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  *(OOC_INT32*)((i3+((_check_index(i2, i4, OOC_UINT32, 8404))*12))+4) = (OOC_INT32)0;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8435))+20);
  i3 = _check_pointer(i3, 8444);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  *(OOC_INT32*)((i3+((_check_index(i2, i4, OOC_UINT32, 8444))*12))+8) = (OOC_INT32)0;
  i2 = i2+1;
  i = i2;
  i3 = i2<i1;
  if (i3) goto l11_loop;
l16:
  *(OOC_INT32*)((_check_pointer(i0, 8479))+8) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 8503))+16) = 0;
  return;
  ;
}

void ADT_Object_Storage__WriterDesc_WriteObject(ADT_Object_Storage__Writer w, Object__Object obj) {
  register OOC_INT32 i0,i1,i2,i3;
  RT0__Struct type;
  OOC_INT32 tref;
  auto OOC_INT32 ADT_Object_Storage__WriterDesc_WriteObject_LookupType(ADT_Object_Storage__Writer w, RT0__Name module, RT0__Name type);
    
    OOC_INT32 ADT_Object_Storage__WriterDesc_WriteObject_LookupType(ADT_Object_Storage__Writer w, RT0__Name module, RT0__Name type) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8;
      OOC_INT32 i;
      OOC_INT32 j;
      OOC_INT32 e;
      ADT_Object_Storage__TypeRefMap _new;

      i = (-1);
      i0 = (OOC_INT32)w;
      i1 = *(OOC_INT32*)((_check_pointer(i0, 9075))+16);
      j = i1;
      i2 = 0!=i1;
      if (i2) goto l3;
      i2=i1;i1=(-1);
      goto l21;
l3:
      i2 = (OOC_INT32)type;
      i3 = (OOC_INT32)module;
      i4=i1;i1=(-1);
l4_loop:
      i5 = (i1+i4)>>1;
      e = i5;
      i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9154))+12);
      i6 = _check_pointer(i6, 9166);
      i7 = OOC_ARRAY_LENGTH(i6, 0);
      i6 = (OOC_INT32)*(OOC_INT32*)(i6+((_check_index(i5, i7, OOC_UINT32, 9166))*12));
      i6 = (
      _cmp8((const void*)(_check_pointer(i6, 9177)),(const void*)(_check_pointer(i3, 9187))))<0;
      if (i6) goto l11;
      i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9206))+12);
      i6 = _check_pointer(i6, 9218);
      i7 = OOC_ARRAY_LENGTH(i6, 0);
      i6 = (OOC_INT32)*(OOC_INT32*)(i6+((_check_index(i5, i7, OOC_UINT32, 9218))*12));
      i6 = (
      _cmp8((const void*)(_check_pointer(i6, 9229)),(const void*)(_check_pointer(i3, 9239))))==0;
      if (i6) goto l9;
      i6=0u;
      goto l13;
l9:
      i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9260))+12);
      i6 = _check_pointer(i6, 9272);
      i7 = OOC_ARRAY_LENGTH(i6, 0);
      i6 = (OOC_INT32)*(OOC_INT32*)((i6+((_check_index(i5, i7, OOC_UINT32, 9272))*12))+4);
      i6 = (
      _cmp8((const void*)(_check_pointer(i6, 9281)),(const void*)(_check_pointer(i2, 9290))))<=0;
      
      goto l13;
l11:
      i6=1u;
l13:
      if (i6) goto l15;
      j = i5;
      i4=i5;
      goto l16;
l15:
      i = i5;
      i1=i5;
l16:
      i5 = (i1+1)!=i4;
      if (i5) goto l4_loop;
l20:
      i2=i4;
l21:
      i3 = i1<0;
      if (i3) goto l24;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9400))+12);
      i3 = _check_pointer(i3, 9412);
      i4 = OOC_ARRAY_LENGTH(i3, 0);
      i3 = (OOC_INT32)*(OOC_INT32*)(i3+((_check_index(i1, i4, OOC_UINT32, 9412))*12));
      i4 = (OOC_INT32)module;
      i3 = (
      _cmp8((const void*)(_check_pointer(i3, 9423)),(const void*)(_check_pointer(i4, 9433))))!=0;
      
      goto l26;
l24:
      i3=1u;
l26:
      if (i3) goto l28;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9450))+12);
      i3 = _check_pointer(i3, 9462);
      i4 = OOC_ARRAY_LENGTH(i3, 0);
      i3 = (OOC_INT32)*(OOC_INT32*)((i3+((_check_index(i1, i4, OOC_UINT32, 9462))*12))+4);
      i4 = (OOC_INT32)type;
      i3 = (
      _cmp8((const void*)(_check_pointer(i3, 9471)),(const void*)(_check_pointer(i4, 9479))))!=0;
      
      goto l30;
l28:
      i3=1u;
l30:
      if (i3) goto l32;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10162))+12);
      i0 = _check_pointer(i0, 10174);
      i2 = OOC_ARRAY_LENGTH(i0, 0);
      i0 = *(OOC_INT32*)((i0+((_check_index(i1, i2, OOC_UINT32, 10174))*12))+8);
      return (-i0);
      goto l52;
l32:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9587))+12);
      i3 = *(OOC_INT32*)((_check_pointer(i0, 9565))+16);
      i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 9599)), 0);
      i1 = i3==i1;
      if (!i1) goto l43;
      i1 = *(OOC_INT32*)((_check_pointer(i0, 9629))+16);
      i1 = (OOC_INT32)RT0__NewObject(_td_ADT_Object_Storage__TypeRefMap.baseTypes[0], (4+i1*2));
      _new = (ADT_Object_Storage__TypeRefMap)i1;
      i3 = *(OOC_INT32*)((_check_pointer(i0, 9683))+16);
      i = 0;
      i4 = 0<i3;
      if (!i4) goto l42;
      i4=0;
l37_loop:
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9725))+12);
      i5 = _check_pointer(i5, 9737);
      i6 = OOC_ARRAY_LENGTH(i5, 0);
      i7 = _check_pointer(i1, 9717);
      i8 = OOC_ARRAY_LENGTH(i7, 0);
      _copy_block((i5+((_check_index(i4, i6, OOC_UINT32, 9737))*12)),(i7+((_check_index(i4, i8, OOC_UINT32, 9717))*12)),12);
      i4 = i4+1;
      i = i4;
      i5 = i4<i3;
      if (i5) goto l37_loop;
l42:
      *(OOC_INT32*)((_check_pointer(i0, 9767))+12) = i1;
l43:
      i1 = *(OOC_INT32*)((_check_pointer(i0, 9818))+16);
      i1 = i1-1;
      i = i1;
      i3 = i1>=i2;
      if (!i3) goto l51;
l46_loop:
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9881))+12);
      i3 = _check_pointer(i3, 9893);
      i4 = OOC_ARRAY_LENGTH(i3, 0);
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9859))+12);
      i5 = _check_pointer(i5, 9871);
      i6 = OOC_ARRAY_LENGTH(i5, 0);
      _copy_block((i3+((_check_index(i1, i4, OOC_UINT32, 9893))*12)),(i5+((_check_index((i1+1), i6, OOC_UINT32, 9871))*12)),12);
      i1 = i1+(-1);
      i = i1;
      i3 = i1>=i2;
      if (i3) goto l46_loop;
l51:
      i1 = *(OOC_INT32*)((_check_pointer(i0, 9924))+16);
      *(OOC_INT32*)((_check_pointer(i0, 9924))+16) = (i1+1);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9949))+12);
      i1 = _check_pointer(i1, 9961);
      i3 = OOC_ARRAY_LENGTH(i1, 0);
      i4 = (OOC_INT32)module;
      *(OOC_INT32*)(i1+((_check_index(i2, i3, OOC_UINT32, 9961))*12)) = i4;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9993))+12);
      i1 = _check_pointer(i1, 10005);
      i3 = OOC_ARRAY_LENGTH(i1, 0);
      i4 = (OOC_INT32)type;
      *(OOC_INT32*)((i1+((_check_index(i2, i3, OOC_UINT32, 10005))*12))+4) = i4;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10033))+12);
      i1 = _check_pointer(i1, 10045);
      i3 = OOC_ARRAY_LENGTH(i1, 0);
      i4 = *(OOC_INT32*)((_check_pointer(i0, 10058))+16);
      *(OOC_INT32*)((i1+((_check_index(i2, i3, OOC_UINT32, 10045))*12))+8) = i4;
      i0 = *(OOC_INT32*)((_check_pointer(i0, 10089))+16);
      return i0;
l52:
      _failed_function(8681); return 0;
      ;
    }


  i0 = (OOC_INT32)obj;
  i1 = i0==(OOC_INT32)0;
  if (i1) goto l14;
  i1 = (OOC_INT32)w;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 10339))+20);
  i2 = ADT_Dictionary_AddressKey_IntValue__DictionaryDesc_HasKey((ADT_Dictionary_AddressKey_IntValue__Dictionary)i2, (Object__Object)i0);
  if (i2) goto l12;
  i2 = *(OOC_INT32*)((_check_pointer(i1, 10502))+8);
  *(OOC_INT32*)((_check_pointer(i1, 10502))+8) = (i2+1);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 10526))+20);
  i3 = *(OOC_INT32*)((_check_pointer(i1, 10548))+8);
  ADT_Dictionary_AddressKey_IntValue__DictionaryDesc_Set((ADT_Dictionary_AddressKey_IntValue__Dictionary)i2, (Object__Object)i0, i3);
  i2 = *(OOC_INT32*)((_check_pointer(i1, 10585))+8);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 10572)))), IO_BinaryRider__WriterDesc_WriteNum)),IO_BinaryRider__WriterDesc_WriteNum)((IO_BinaryRider__Writer)i1, i2);
  i0 = (OOC_INT32)RT0__TypeOf((void*)i0);
  type = (RT0__Struct)i0;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10732))+12);
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 10740));
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10752))+16);
  i0 = ADT_Object_Storage__WriterDesc_WriteObject_LookupType((ADT_Object_Storage__Writer)i1, (RT0__Name)i2, (RT0__Name)i0);
  tref = i0;
  i1 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 10770)))), IO_BinaryRider__WriterDesc_WriteNum)),IO_BinaryRider__WriterDesc_WriteNum)((IO_BinaryRider__Writer)i1, i0);
  i0 = i0>0;
  if (!i0) goto l7;
  i0 = (OOC_INT32)type;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10836))+12);
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 10844));
  _copy_8((const void*)(_check_pointer(i2, 10850)),(void*)((_check_pointer(i1, 10854))+24),256);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 10880)))), IO_BinaryRider__WriterDesc_WriteString)),IO_BinaryRider__WriterDesc_WriteString)((IO_BinaryRider__Writer)i1, (void*)((_check_pointer(i1, 10896))+24), 256);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10931))+16);
  _copy_8((const void*)(_check_pointer(i0, 10937)),(void*)((_check_pointer(i1, 10941))+24),256);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 10967)))), IO_BinaryRider__WriterDesc_WriteString)),IO_BinaryRider__WriterDesc_WriteString)((IO_BinaryRider__Writer)i1, (void*)((_check_pointer(i1, 10983))+24), 256);
l7:
  i0 = (OOC_INT32)obj;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11027)))), &_td_Object__StringDesc);
  if (i2) goto l10;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11109)))), &_td_ADT_Storable__ObjectDesc, 11109)), 11116)))), ADT_Storable__ObjectDesc_Store)),ADT_Storable__ObjectDesc_Store)((ADT_Storable__Object)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11109)))), &_td_ADT_Storable__ObjectDesc, 11109)), (ADT_Storable__Writer)i1);
  goto l15;
l10:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 11057)))), IO_BinaryRider__WriterDesc_WriteStr)),IO_BinaryRider__WriterDesc_WriteStr)((IO_BinaryRider__Writer)i1, (Object__String)i0);
  goto l15;
l12:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 10417))+20);
  i0 = ADT_Dictionary_AddressKey_IntValue__DictionaryDesc_Get((ADT_Dictionary_AddressKey_IntValue__Dictionary)i2, (Object__Object)i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 10403)))), IO_BinaryRider__WriterDesc_WriteNum)),IO_BinaryRider__WriterDesc_WriteNum)((IO_BinaryRider__Writer)i1, (-i0));
  goto l15;
l14:
  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10255)))), IO_BinaryRider__WriterDesc_WriteNum)),IO_BinaryRider__WriterDesc_WriteNum)((IO_BinaryRider__Writer)i0, 0);
l15:
  return;
  ;
}

void ADT_Object_Storage__WriterDesc_Disconnect(ADT_Object_Storage__Writer w) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_INT32 i;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11305))+12);
  i = 0;
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 11317)), 0);
  i2 = 0<i1;
  if (!i2) goto l8;
  i2=0;
l3_loop:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11332))+12);
  i3 = _check_pointer(i3, 11344);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  *(OOC_INT32*)(i3+((_check_index(i2, i4, OOC_UINT32, 11344))*12)) = 0;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11371))+12);
  i3 = _check_pointer(i3, 11383);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  *(OOC_INT32*)((i3+((_check_index(i2, i4, OOC_UINT32, 11383))*12))+4) = 0;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11408))+12);
  i3 = _check_pointer(i3, 11420);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  *(OOC_INT32*)((i3+((_check_index(i2, i4, OOC_UINT32, 11420))*12))+8) = 0;
  i2 = i2+1;
  i = i2;
  i3 = i2<i1;
  if (i3) goto l3_loop;
l8:
  *(OOC_INT32*)((_check_pointer(i0, 11448))+12) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 11474))+16) = 0;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11499))+20);
  ADT_Dictionary_AddressKey_IntValue__DictionaryDesc_Destroy((ADT_Dictionary_AddressKey_IntValue__Dictionary)i1);
  *(OOC_INT32*)((_check_pointer(i0, 11526))+20) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 11549))+8) = 0;
  return;
  ;
}

void OOC_ADT_Object_Storage_init(void) {
  register OOC_INT32 i0;
  _c0 = Object__NewLatin1Region("Type count mismatch", 20, 0, 19);
  _c1 = Object__NewLatin1Region("Invalid type reference", 23, 0, 22);
  _c2 = Object__NewLatin1Region("Object count mismatch", 22, 0, 21);
  _c3 = Object__NewLatin1Region("Failed to resolve type name", 28, 0, 27);
  _c4 = Object__NewLatin1Region("Invalid object reference", 25, 0, 24);

  i0 = (OOC_INT32)RT0__ThisModule("Object", 7);
  ADT_Object_Storage__object = (RT0__Module)i0;
  i0 = (OOC_INT32)RT0__ThisType((RT0__Module)i0, "String8", 8);
  ADT_Object_Storage__string8 = (RT0__Struct)i0;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 11696));
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 11706));
  ADT_Object_Storage__string8 = (RT0__Struct)i0;
  i0 = (OOC_INT32)ADT_Object_Storage__object;
  i0 = (OOC_INT32)RT0__ThisType((RT0__Module)i0, "String16", 9);
  ADT_Object_Storage__string16 = (RT0__Struct)i0;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 11781));
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 11791));
  ADT_Object_Storage__string16 = (RT0__Struct)i0;
  return;
  ;
}

/* --- */
