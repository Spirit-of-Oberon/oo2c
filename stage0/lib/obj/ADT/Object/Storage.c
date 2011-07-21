#include <ADT/Object/Storage.d>
#include <__oo2c.h>
#include <setjmp.h>

void ADT_Object_Storage__ReaderDesc_INIT(ADT_Object_Storage__Reader r, IO__ByteChannel ch) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)ch;
  i1 = (OOC_INT32)r;
  ADT_Storable__ReaderDesc_INIT((ADT_Storable__Reader)i1, (IO__ByteChannel)i0);
  *(OOC_INT32*)((_check_pointer(i1, 3294))+12) = ((OOC_INT32)RT0__NewObject(_td_ADT_Object_Storage__ObjectArray.baseTypes[0], 124));
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 3326))+12);
  i0 = _check_pointer(i0, 3334);
  i2 = OOC_ARRAY_LENGTH(i0, 0);
  *(OOC_INT32*)(i0+(_check_index(0, i2, OOC_UINT8, 3334))*4) = (OOC_INT32)0;
  *(OOC_INT32*)((_check_pointer(i1, 3351))+8) = 1;
  *(OOC_INT32*)((_check_pointer(i1, 3380))+20) = ((OOC_INT32)RT0__NewObject(_td_ADT_Object_Storage__TypeArray.baseTypes[0], 12));
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 3412))+20);
  i0 = _check_pointer(i0, 3421);
  i2 = OOC_ARRAY_LENGTH(i0, 0);
  *(OOC_INT32*)(i0+((_check_index(0, i2, OOC_UINT8, 3421))*12)) = (OOC_INT32)0;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 3444))+20);
  i0 = _check_pointer(i0, 3453);
  i2 = OOC_ARRAY_LENGTH(i0, 0);
  *(OOC_INT32*)((i0+((_check_index(0, i2, OOC_UINT8, 3453))*12))+4) = (OOC_INT32)0;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 3482))+20);
  i0 = _check_pointer(i0, 3491);
  i2 = OOC_ARRAY_LENGTH(i0, 0);
  *(OOC_INT32*)((i0+((_check_index(0, i2, OOC_UINT8, 3491))*12))+8) = (OOC_INT32)0;
  *(OOC_INT32*)((_check_pointer(i1, 3518))+16) = 1;
  return;
  ;
}

void ADT_Object_Storage__WriterDesc_INIT(ADT_Object_Storage__Writer w, IO__ByteChannel ch) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)ch;
  i1 = (OOC_INT32)w;
  ADT_Storable__WriterDesc_INIT((ADT_Storable__Writer)i1, (IO__ByteChannel)i0);
  *(OOC_INT32*)((_check_pointer(i1, 3630))+8) = 0;
  *(OOC_INT32*)((_check_pointer(i1, 3659))+12) = ((OOC_INT32)RT0__NewObject(_td_ADT_Object_Storage__TypeRefMap.baseTypes[0], 12));
  *(OOC_INT32*)((_check_pointer(i1, 3694))+16) = 0;
  i0 = (OOC_INT32)ADT_Dictionary_AddressKey_IntValue__New();
  *(OOC_INT32*)((_check_pointer(i1, 3719))+20) = i0;
  return;
  ;
}

ADT_Object_Storage__Reader ADT_Object_Storage__ConnectReader(IO__ByteChannel ch) {
  register OOC_INT32 i0,i1;
  ADT_Object_Storage__Reader r;

  i0 = (OOC_INT32)RT0__NewObject(_td_ADT_Object_Storage__Reader.baseTypes[0]);
  r = (ADT_Object_Storage__Reader)i0;
  i1 = (OOC_INT32)ch;
  ADT_Object_Storage__ReaderDesc_INIT((ADT_Object_Storage__Reader)i0, (IO__ByteChannel)i1);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3957))+4);
  i1 = i1==(OOC_INT32)0;
  if (i1) goto l3;
  return (ADT_Object_Storage__Reader)i0;
  goto l4;
l3:
  return (ADT_Object_Storage__Reader)(OOC_INT32)0;
l4:
  _failed_function(3774); return 0;
  ;
}

ADT_Object_Storage__Writer ADT_Object_Storage__ConnectWriter(IO__ByteChannel ch) {
  register OOC_INT32 i0,i1;
  ADT_Object_Storage__Writer w;

  i0 = (OOC_INT32)RT0__NewObject(_td_ADT_Object_Storage__Writer.baseTypes[0]);
  w = (ADT_Object_Storage__Writer)i0;
  i1 = (OOC_INT32)ch;
  ADT_Object_Storage__WriterDesc_INIT((ADT_Object_Storage__Writer)i0, (IO__ByteChannel)i1);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4296))+4);
  i1 = i1==(OOC_INT32)0;
  if (i1) goto l3;
  return (ADT_Object_Storage__Writer)i0;
  goto l4;
l3:
  return (ADT_Object_Storage__Writer)(OOC_INT32)0;
l4:
  _failed_function(4113); return 0;
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
          i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 4878)), 0);
          i1 = (OOC_INT32)RT0__NewObject(_td_ADT_Object_Storage__TypeArray.baseTypes[0], (4+i1*2));
          _new = (ADT_Object_Storage__TypeArray)i1;
          i = 0;
          i0 = OOC_ARRAY_LENGTH((_check_pointer(i0, 4926)), 0);
          i2 = 0<i0;
          if (!i2) goto l8;
          i2=0;
l3_loop:
          i3 = (OOC_INT32)*tab;
          i3 = _check_pointer(i3, 4957);
          i4 = OOC_ARRAY_LENGTH(i3, 0);
          i5 = _check_pointer(i1, 4947);
          i6 = OOC_ARRAY_LENGTH(i5, 0);
          _copy_block((i3+((_check_index(i2, i4, OOC_UINT32, 4957))*12)),(i5+((_check_index(i2, i6, OOC_UINT32, 4947))*12)),12);
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
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5036)))), IO_BinaryRider__ReaderDesc_ReadNum)),IO_BinaryRider__ReaderDesc_ReadNum)((IO_BinaryRider__Reader)i0, (void*)(OOC_INT32)&tref);
      i0 = tref;
      i1 = i0<0;
      if (i1) goto l33;
      i1 = (OOC_INT32)r;
      i2 = *(OOC_INT32*)((_check_pointer(i1, 5347))+16);
      i2 = i0!=i2;
      if (!i2) goto l5;
      IO__RaiseFormatError((Object__String)((OOC_INT32)_c0));
l5:
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 5459))+20);
      i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 5468)), 0);
      i0 = i0==i2;
      if (!i0) goto l8;
      ADT_Object_Storage__ReaderDesc_ReadObject_ReadType_ExtendTypeTab((void*)((_check_pointer(i1, 5503))+20));
l8:
      i0 = (OOC_INT32)r;
      i1 = *(OOC_INT32*)((_check_pointer(i0, 5541))+16);
      *(OOC_INT32*)((_check_pointer(i0, 5541))+16) = (i1+1);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5652)))), IO_BinaryRider__ReaderDesc_ReadString)),IO_BinaryRider__ReaderDesc_ReadString)((IO_BinaryRider__Reader)i0, (void*)((_check_pointer(i0, 5667))+24), 256);
      i0 = (OOC_INT32)r;
      i0 = (OOC_INT32)RT0__ThisModule((void*)((_check_pointer(i0, 5711))+24), 256);
      module = (RT0__Module)i0;
      i1 = i0==(OOC_INT32)0;
      if (i1) goto l11;
      i1 = (OOC_INT32)r;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 6030))+20);
      i2 = _check_pointer(i2, 6039);
      i3 = OOC_ARRAY_LENGTH(i2, 0);
      i4 = tref;
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 6067));
      *(OOC_INT32*)((i2+((_check_index(i4, i3, OOC_UINT32, 6039))*12))+4) = i0;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 6086)))), IO_BinaryRider__ReaderDesc_ReadString)),IO_BinaryRider__ReaderDesc_ReadString)((IO_BinaryRider__Reader)i1, (void*)((_check_pointer(i1, 6101))+24), 256);
      i0 = (OOC_INT32)r;
      i1 = (OOC_INT32)module;
      i0 = (OOC_INT32)RT0__ThisType((RT0__Module)i1, (void*)((_check_pointer(i0, 6149))+24), 256);
      tp = (RT0__Struct)i0;
      
      goto l20;
l11:
      i0 = (OOC_INT32)r;
      i1 = Strings__Length((void*)((_check_pointer(i0, 5785))+24), 256);
      i1 = i1+1;
      len = i1;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5812))+20);
      i2 = _check_pointer(i2, 5821);
      i3 = OOC_ARRAY_LENGTH(i2, 0);
      i4 = tref;
      *(OOC_INT32*)((i2+((_check_index(i4, i3, OOC_UINT32, 5821))*12))+4) = ((OOC_INT32)RT0__NewObject(_td_RT0__Name.baseTypes[0], i1));
      i = 0;
      i2 = 0<i1;
      if (!i2) goto l19;
      i2=0;
l14_loop:
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5893))+20);
      i3 = _check_pointer(i3, 5901);
      i5 = OOC_ARRAY_LENGTH(i3, 0);
      i3 = (OOC_INT32)*(OOC_INT32*)((i3+((_check_index(i4, i5, OOC_UINT32, 5901))*12))+4);
      i5 = *(OOC_UINT8*)(((_check_pointer(i0, 5926))+24)+(_check_index(i2, 256, OOC_UINT32, 5931)));
      *(OOC_UINT8*)((_check_pointer(i3, 5918))+i2) = i5;
      i2 = i2+1;
      i = i2;
      i3 = i2<i1;
      if (i3) goto l14_loop;
l19:
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5962)))), IO_BinaryRider__ReaderDesc_ReadString)),IO_BinaryRider__ReaderDesc_ReadString)((IO_BinaryRider__Reader)i0, (void*)((_check_pointer(i0, 5977))+24), 256);
      tp = (RT0__Struct)(OOC_INT32)0;
      i0=(OOC_INT32)0;
l20:
      i1 = (OOC_INT32)r;
      i2 = tref;
      i3 = i0==(OOC_INT32)0;
      if (i3) goto l23;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 6418))+20);
      i3 = _check_pointer(i3, 6427);
      i4 = OOC_ARRAY_LENGTH(i3, 0);
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6449))+16);
      *(OOC_INT32*)((i3+((_check_index(i2, i4, OOC_UINT32, 6427))*12))+8) = i5;
      goto l32;
l23:
      i3 = Strings__Length((void*)((_check_pointer(i1, 6232))+24), 256);
      i3 = i3+1;
      len = i3;
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 6259))+20);
      i4 = _check_pointer(i4, 6268);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      *(OOC_INT32*)((i4+((_check_index(i2, i5, OOC_UINT32, 6268))*12))+8) = ((OOC_INT32)RT0__NewObject(_td_RT0__Name.baseTypes[0], i3));
      i = 0;
      i4 = 0<i3;
      if (!i4) goto l32;
      i4=0;
l26_loop:
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 6338))+20);
      i5 = _check_pointer(i5, 6346);
      i6 = OOC_ARRAY_LENGTH(i5, 0);
      i5 = (OOC_INT32)*(OOC_INT32*)((i5+((_check_index(i2, i6, OOC_UINT32, 6346))*12))+8);
      i6 = *(OOC_UINT8*)(((_check_pointer(i1, 6369))+24)+(_check_index(i4, 256, OOC_UINT32, 6374)));
      *(OOC_UINT8*)((_check_pointer(i5, 6361))+i4) = i6;
      i4 = i4+1;
      i = i4;
      i5 = i4<i3;
      if (i5) goto l26_loop;
l32:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 6478))+20);
      i1 = _check_pointer(i1, 6487);
      i3 = OOC_ARRAY_LENGTH(i1, 0);
      *(OOC_INT32*)(i1+((_check_index(i2, i3, OOC_UINT32, 6487))*12)) = i0;
      return i2;
      goto l38;
l33:
      i1 = (OOC_INT32)r;
      i1 = *(OOC_INT32*)((_check_pointer(i1, 5148))+16);
      i0 = -i0;
      i1 = i0>=i1;
      if (i1) goto l36;
      return i0;
      goto l38;
l36:
      IO__RaiseFormatError((Object__String)((OOC_INT32)_c1));
l38:
      _failed_function(4633); return 0;
      ;
    }

    
    void ADT_Object_Storage__ReaderDesc_ReadObject_ExtendObjTab(ADT_Object_Storage__ObjectArray *tab) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
      ADT_Object_Storage__ObjectArray _new;
      OOC_INT32 i;

      i0 = (OOC_INT32)*tab;
      i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 6693)), 0);
      i1 = (OOC_INT32)RT0__NewObject(_td_ADT_Object_Storage__ObjectArray.baseTypes[0], (4+i1*2));
      _new = (ADT_Object_Storage__ObjectArray)i1;
      i = 0;
      i0 = OOC_ARRAY_LENGTH((_check_pointer(i0, 6739)), 0);
      i2 = 0<i0;
      if (!i2) goto l8;
      i2=0;
l3_loop:
      i3 = _check_pointer(i1, 6758);
      i4 = OOC_ARRAY_LENGTH(i3, 0);
      i5 = (OOC_INT32)*tab;
      i5 = _check_pointer(i5, 6768);
      i6 = OOC_ARRAY_LENGTH(i5, 0);
      i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i2, i6, OOC_UINT32, 6768))*4);
      *(OOC_INT32*)(i3+(_check_index(i2, i4, OOC_UINT32, 6758))*4) = i5;
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6838)))), IO_BinaryRider__ReaderDesc_ReadNum)),IO_BinaryRider__ReaderDesc_ReadNum)((IO_BinaryRider__Reader)i0, (void*)(OOC_INT32)&ref);
  i1 = ref;
  i2 = i1==0;
  if (i2) goto l29;
  i2 = i1<0;
  if (i2) goto l23;
  i0 = *(OOC_INT32*)((_check_pointer(i0, 7237))+8);
  i0 = i1!=i0;
  if (!i0) goto l7;
  IO__RaiseFormatError((Object__String)((OOC_INT32)_c2));
l7:
  i0 = ADT_Object_Storage__ReaderDesc_ReadObject_ReadType();
  tref = i0;
  i1 = (OOC_INT32)r;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 7398))+20);
  i2 = _check_pointer(i2, 7407);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i0 = (OOC_INT32)*(OOC_INT32*)(i2+((_check_index(i0, i3, OOC_UINT32, 7407))*12));
  type = (RT0__Struct)i0;
  i0 = i0==(OOC_INT32)0;
  if (i0) goto l21;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 7613))+12);
  i0 = OOC_ARRAY_LENGTH((_check_pointer(i0, 7620)), 0);
  i2 = ref;
  i0 = i2==i0;
  if (!i0) goto l12;
  ADT_Object_Storage__ReaderDesc_ReadObject_ExtendObjTab((void*)((_check_pointer(i1, 7655))+12));
l12:
  i0 = (OOC_INT32)r;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 7695))+8);
  *(OOC_INT32*)((_check_pointer(i0, 7695))+8) = (i1+1);
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
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7946))+12);
  i2 = _check_pointer(i2, 7953);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i4 = ref;
  *(OOC_INT32*)(i2+(_check_index(i4, i3, OOC_UINT32, 7953))*4) = i1;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 7992)))), &_td_ADT_Storable__ObjectDesc, 7992)), 7999)))), ADT_Storable__ObjectDesc_Load)),ADT_Storable__ObjectDesc_Load)((ADT_Storable__Object)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 7992)))), &_td_ADT_Storable__ObjectDesc, 7992)), (ADT_Storable__Reader)i0);
  goto l30;
l19:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7778)))), IO_BinaryRider__ReaderDesc_ReadStr)),IO_BinaryRider__ReaderDesc_ReadStr)((IO_BinaryRider__Reader)i0, (void*)(OOC_INT32)&str);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7806))+12);
  i0 = _check_pointer(i0, 7813);
  i1 = OOC_ARRAY_LENGTH(i0, 0);
  i2 = ref;
  i3 = (OOC_INT32)str;
  *(OOC_INT32*)(i0+(_check_index(i2, i1, OOC_UINT32, 7813))*4) = i3;
  *obj = (Object__Object)i3;
  goto l30;
l21:
  ADT_Storable__RaiseTypeError((Object__String)((OOC_INT32)_c3));
  goto l30;
l23:
  i2 = *(OOC_INT32*)((_check_pointer(i0, 7005))+8);
  i1 = -i1;
  i2 = i1>=i2;
  if (i2) goto l26;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7142))+12);
  i0 = _check_pointer(i0, 7150);
  i2 = OOC_ARRAY_LENGTH(i0, 0);
  i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(i1, i2, OOC_UINT32, 7150))*4);
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
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8198))+12);
  i = 0;
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 8206)), 0);
  i2 = 0<i1;
  if (!i2) goto l8;
  i2=0;
l3_loop:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8221))+12);
  i3 = _check_pointer(i3, 8229);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  *(OOC_INT32*)(i3+(_check_index(i2, i4, OOC_UINT32, 8229))*4) = (OOC_INT32)0;
  i2 = i2+1;
  i = i2;
  i3 = i2<i1;
  if (i3) goto l3_loop;
l8:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8273))+20);
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 8282)), 0);
  i = 0;
  i2 = 0<i1;
  if (!i2) goto l16;
  i2=0;
l11_loop:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8297))+20);
  i3 = _check_pointer(i3, 8306);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  *(OOC_INT32*)(i3+((_check_index(i2, i4, OOC_UINT32, 8306))*12)) = (OOC_INT32)0;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8331))+20);
  i3 = _check_pointer(i3, 8340);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  *(OOC_INT32*)((i3+((_check_index(i2, i4, OOC_UINT32, 8340))*12))+4) = (OOC_INT32)0;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8371))+20);
  i3 = _check_pointer(i3, 8380);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  *(OOC_INT32*)((i3+((_check_index(i2, i4, OOC_UINT32, 8380))*12))+8) = (OOC_INT32)0;
  i2 = i2+1;
  i = i2;
  i3 = i2<i1;
  if (i3) goto l11_loop;
l16:
  *(OOC_INT32*)((_check_pointer(i0, 8415))+8) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 8439))+16) = 0;
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
      i1 = *(OOC_INT32*)((_check_pointer(i0, 9011))+16);
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
      i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9090))+12);
      i6 = _check_pointer(i6, 9102);
      i7 = OOC_ARRAY_LENGTH(i6, 0);
      i6 = (OOC_INT32)*(OOC_INT32*)(i6+((_check_index(i5, i7, OOC_UINT32, 9102))*12));
      i6 = (
      _cmp8((const void*)(_check_pointer(i6, 9113)),(const void*)(_check_pointer(i3, 9123))))<0;
      if (i6) goto l11;
      i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9142))+12);
      i6 = _check_pointer(i6, 9154);
      i7 = OOC_ARRAY_LENGTH(i6, 0);
      i6 = (OOC_INT32)*(OOC_INT32*)(i6+((_check_index(i5, i7, OOC_UINT32, 9154))*12));
      i6 = (
      _cmp8((const void*)(_check_pointer(i6, 9165)),(const void*)(_check_pointer(i3, 9175))))==0;
      if (i6) goto l9;
      i6=0u;
      goto l13;
l9:
      i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9196))+12);
      i6 = _check_pointer(i6, 9208);
      i7 = OOC_ARRAY_LENGTH(i6, 0);
      i6 = (OOC_INT32)*(OOC_INT32*)((i6+((_check_index(i5, i7, OOC_UINT32, 9208))*12))+4);
      i6 = (
      _cmp8((const void*)(_check_pointer(i6, 9217)),(const void*)(_check_pointer(i2, 9226))))<=0;
      
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
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9336))+12);
      i3 = _check_pointer(i3, 9348);
      i4 = OOC_ARRAY_LENGTH(i3, 0);
      i3 = (OOC_INT32)*(OOC_INT32*)(i3+((_check_index(i1, i4, OOC_UINT32, 9348))*12));
      i4 = (OOC_INT32)module;
      i3 = (
      _cmp8((const void*)(_check_pointer(i3, 9359)),(const void*)(_check_pointer(i4, 9369))))!=0;
      
      goto l26;
l24:
      i3=1u;
l26:
      if (i3) goto l28;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9386))+12);
      i3 = _check_pointer(i3, 9398);
      i4 = OOC_ARRAY_LENGTH(i3, 0);
      i3 = (OOC_INT32)*(OOC_INT32*)((i3+((_check_index(i1, i4, OOC_UINT32, 9398))*12))+4);
      i4 = (OOC_INT32)type;
      i3 = (
      _cmp8((const void*)(_check_pointer(i3, 9407)),(const void*)(_check_pointer(i4, 9415))))!=0;
      
      goto l30;
l28:
      i3=1u;
l30:
      if (i3) goto l32;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10098))+12);
      i0 = _check_pointer(i0, 10110);
      i2 = OOC_ARRAY_LENGTH(i0, 0);
      i0 = *(OOC_INT32*)((i0+((_check_index(i1, i2, OOC_UINT32, 10110))*12))+8);
      return (-i0);
      goto l52;
l32:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9523))+12);
      i3 = *(OOC_INT32*)((_check_pointer(i0, 9501))+16);
      i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 9535)), 0);
      i1 = i3==i1;
      if (!i1) goto l43;
      i1 = *(OOC_INT32*)((_check_pointer(i0, 9565))+16);
      i1 = (OOC_INT32)RT0__NewObject(_td_ADT_Object_Storage__TypeRefMap.baseTypes[0], (4+i1*2));
      _new = (ADT_Object_Storage__TypeRefMap)i1;
      i3 = *(OOC_INT32*)((_check_pointer(i0, 9619))+16);
      i = 0;
      i4 = 0<i3;
      if (!i4) goto l42;
      i4=0;
l37_loop:
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9661))+12);
      i5 = _check_pointer(i5, 9673);
      i6 = OOC_ARRAY_LENGTH(i5, 0);
      i7 = _check_pointer(i1, 9653);
      i8 = OOC_ARRAY_LENGTH(i7, 0);
      _copy_block((i5+((_check_index(i4, i6, OOC_UINT32, 9673))*12)),(i7+((_check_index(i4, i8, OOC_UINT32, 9653))*12)),12);
      i4 = i4+1;
      i = i4;
      i5 = i4<i3;
      if (i5) goto l37_loop;
l42:
      *(OOC_INT32*)((_check_pointer(i0, 9703))+12) = i1;
l43:
      i1 = *(OOC_INT32*)((_check_pointer(i0, 9754))+16);
      i1 = i1-1;
      i = i1;
      i3 = i1>=i2;
      if (!i3) goto l51;
l46_loop:
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9817))+12);
      i3 = _check_pointer(i3, 9829);
      i4 = OOC_ARRAY_LENGTH(i3, 0);
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9795))+12);
      i5 = _check_pointer(i5, 9807);
      i6 = OOC_ARRAY_LENGTH(i5, 0);
      _copy_block((i3+((_check_index(i1, i4, OOC_UINT32, 9829))*12)),(i5+((_check_index((i1+1), i6, OOC_UINT32, 9807))*12)),12);
      i1 = i1+(-1);
      i = i1;
      i3 = i1>=i2;
      if (i3) goto l46_loop;
l51:
      i1 = *(OOC_INT32*)((_check_pointer(i0, 9860))+16);
      *(OOC_INT32*)((_check_pointer(i0, 9860))+16) = (i1+1);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9885))+12);
      i1 = _check_pointer(i1, 9897);
      i3 = OOC_ARRAY_LENGTH(i1, 0);
      i4 = (OOC_INT32)module;
      *(OOC_INT32*)(i1+((_check_index(i2, i3, OOC_UINT32, 9897))*12)) = i4;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9929))+12);
      i1 = _check_pointer(i1, 9941);
      i3 = OOC_ARRAY_LENGTH(i1, 0);
      i4 = (OOC_INT32)type;
      *(OOC_INT32*)((i1+((_check_index(i2, i3, OOC_UINT32, 9941))*12))+4) = i4;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9969))+12);
      i1 = _check_pointer(i1, 9981);
      i3 = OOC_ARRAY_LENGTH(i1, 0);
      i4 = *(OOC_INT32*)((_check_pointer(i0, 9994))+16);
      *(OOC_INT32*)((i1+((_check_index(i2, i3, OOC_UINT32, 9981))*12))+8) = i4;
      i0 = *(OOC_INT32*)((_check_pointer(i0, 10025))+16);
      return i0;
l52:
      _failed_function(8617); return 0;
      ;
    }


  i0 = (OOC_INT32)obj;
  i1 = i0==(OOC_INT32)0;
  if (i1) goto l14;
  i1 = (OOC_INT32)w;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 10275))+20);
  i2 = ADT_Dictionary_AddressKey_IntValue__DictionaryDesc_HasKey((ADT_Dictionary_AddressKey_IntValue__Dictionary)i2, (Object__Object)i0);
  if (i2) goto l12;
  i2 = *(OOC_INT32*)((_check_pointer(i1, 10438))+8);
  *(OOC_INT32*)((_check_pointer(i1, 10438))+8) = (i2+1);
  i2 = *(OOC_INT32*)((_check_pointer(i1, 10484))+8);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 10462))+20);
  ADT_Dictionary_AddressKey_IntValue__DictionaryDesc_Set((ADT_Dictionary_AddressKey_IntValue__Dictionary)i3, (Object__Object)i0, i2);
  i2 = *(OOC_INT32*)((_check_pointer(i1, 10521))+8);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 10508)))), IO_BinaryRider__WriterDesc_WriteNum)),IO_BinaryRider__WriterDesc_WriteNum)((IO_BinaryRider__Writer)i1, i2);
  i0 = (OOC_INT32)RT0__TypeOf((void*)i0);
  type = (RT0__Struct)i0;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10668))+12);
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 10676));
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10688))+16);
  i0 = ADT_Object_Storage__WriterDesc_WriteObject_LookupType((ADT_Object_Storage__Writer)i1, (RT0__Name)i2, (RT0__Name)i0);
  tref = i0;
  i1 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 10706)))), IO_BinaryRider__WriterDesc_WriteNum)),IO_BinaryRider__WriterDesc_WriteNum)((IO_BinaryRider__Writer)i1, i0);
  i0 = i0>0;
  if (!i0) goto l7;
  i0 = (OOC_INT32)type;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10772))+12);
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 10780));
  _copy_8((const void*)(_check_pointer(i2, 10786)),(void*)((_check_pointer(i1, 10790))+24),256);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 10816)))), IO_BinaryRider__WriterDesc_WriteString)),IO_BinaryRider__WriterDesc_WriteString)((IO_BinaryRider__Writer)i1, (void*)((_check_pointer(i1, 10832))+24), 256);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10867))+16);
  _copy_8((const void*)(_check_pointer(i0, 10873)),(void*)((_check_pointer(i1, 10877))+24),256);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 10903)))), IO_BinaryRider__WriterDesc_WriteString)),IO_BinaryRider__WriterDesc_WriteString)((IO_BinaryRider__Writer)i1, (void*)((_check_pointer(i1, 10919))+24), 256);
l7:
  i0 = (OOC_INT32)obj;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10963)))), &_td_Object__StringDesc);
  if (i2) goto l10;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11045)))), &_td_ADT_Storable__ObjectDesc, 11045)), 11052)))), ADT_Storable__ObjectDesc_Store)),ADT_Storable__ObjectDesc_Store)((ADT_Storable__Object)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11045)))), &_td_ADT_Storable__ObjectDesc, 11045)), (ADT_Storable__Writer)i1);
  goto l15;
l10:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 10993)))), IO_BinaryRider__WriterDesc_WriteStr)),IO_BinaryRider__WriterDesc_WriteStr)((IO_BinaryRider__Writer)i1, (Object__String)i0);
  goto l15;
l12:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 10353))+20);
  i0 = ADT_Dictionary_AddressKey_IntValue__DictionaryDesc_Get((ADT_Dictionary_AddressKey_IntValue__Dictionary)i2, (Object__Object)i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 10339)))), IO_BinaryRider__WriterDesc_WriteNum)),IO_BinaryRider__WriterDesc_WriteNum)((IO_BinaryRider__Writer)i1, (-i0));
  goto l15;
l14:
  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10191)))), IO_BinaryRider__WriterDesc_WriteNum)),IO_BinaryRider__WriterDesc_WriteNum)((IO_BinaryRider__Writer)i0, 0);
l15:
  return;
  ;
}

void ADT_Object_Storage__WriterDesc_Disconnect(ADT_Object_Storage__Writer w) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_INT32 i;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11241))+12);
  i = 0;
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 11253)), 0);
  i2 = 0<i1;
  if (!i2) goto l8;
  i2=0;
l3_loop:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11268))+12);
  i3 = _check_pointer(i3, 11280);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  *(OOC_INT32*)(i3+((_check_index(i2, i4, OOC_UINT32, 11280))*12)) = 0;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11307))+12);
  i3 = _check_pointer(i3, 11319);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  *(OOC_INT32*)((i3+((_check_index(i2, i4, OOC_UINT32, 11319))*12))+4) = 0;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11344))+12);
  i3 = _check_pointer(i3, 11356);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  *(OOC_INT32*)((i3+((_check_index(i2, i4, OOC_UINT32, 11356))*12))+8) = 0;
  i2 = i2+1;
  i = i2;
  i3 = i2<i1;
  if (i3) goto l3_loop;
l8:
  *(OOC_INT32*)((_check_pointer(i0, 11384))+12) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 11410))+16) = 0;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11435))+20);
  ADT_Dictionary_AddressKey_IntValue__DictionaryDesc_Destroy((ADT_Dictionary_AddressKey_IntValue__Dictionary)i1);
  *(OOC_INT32*)((_check_pointer(i0, 11462))+20) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 11485))+8) = 0;
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
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 11632));
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 11642));
  ADT_Object_Storage__string8 = (RT0__Struct)i0;
  i0 = (OOC_INT32)ADT_Object_Storage__object;
  i0 = (OOC_INT32)RT0__ThisType((RT0__Module)i0, "String16", 9);
  ADT_Object_Storage__string16 = (RT0__Struct)i0;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 11717));
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 11727));
  ADT_Object_Storage__string16 = (RT0__Struct)i0;
  return;
  ;
}

void OOC_ADT_Object_Storage_destroy(void) {
}

/* --- */
