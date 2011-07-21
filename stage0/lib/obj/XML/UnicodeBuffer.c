#include <XML/UnicodeBuffer.d>
#include <__oo2c.h>
#include <setjmp.h>

static OOC_INT32 XML_UnicodeBuffer__AutodetectEnc(XML_UnicodeBuffer__Input input, OOC_CHAR8 enc[], OOC_LEN enc_0d) {
  register OOC_INT32 i0,i1,i2;
  OOC_CHAR8 str[16];
  OOC_INT32 skip;
  XML_InputBuffer__CharArray x;

  i0 = (OOC_INT32)input;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 4797));
  i1 = *(OOC_INT32*)((_check_pointer(i1, 4809))+8);
  _assert((i1==0), 127, 4784);
  _copy_8((const void*)"UTF-8",(void*)(OOC_INT32)str,16);
  skip = 0;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 4878));
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 4890))+4);
  x = (XML_InputBuffer__CharArray)i1;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 4912));
  i0 = *(OOC_INT32*)((_check_pointer(i0, 4924))+12);
  i0 = i0>=4;
  if (i0) goto l3;
  i0=0;
  goto l161;
l3:
  i0 = _check_pointer(i1, 4961);
  i2 = OOC_ARRAY_LENGTH(i0, 0);
  i0 = *(OOC_UINT8*)(i0+(_check_index(0, i2, OOC_UINT8, 4961)));
  switch (i0) {
  case 0u:
    i0 = _check_pointer(i1, 4995);
    i2 = OOC_ARRAY_LENGTH(i0, 0);
    i0 = *(OOC_UINT8*)(i0+(_check_index(1, i2, OOC_UINT8, 4995)));
    i0 = i0==0u;
    if (i0) goto l31;
    i0 = _check_pointer(i1, 5491);
    i2 = OOC_ARRAY_LENGTH(i0, 0);
    i0 = *(OOC_UINT8*)(i0+(_check_index(1, i2, OOC_UINT8, 5491)));
    i0 = i0==60u;
    if (i0) goto l10;
    i0=0u;
    goto l12;
l10:
    i0 = _check_pointer(i1, 5506);
    i2 = OOC_ARRAY_LENGTH(i0, 0);
    i0 = *(OOC_UINT8*)(i0+(_check_index(2, i2, OOC_UINT8, 5506)));
    i0 = i0==0u;
    
l12:
    if (i0) goto l14;
    i0=0u;
    goto l16;
l14:
    i0 = _check_pointer(i1, 5520);
    i2 = OOC_ARRAY_LENGTH(i0, 0);
    i0 = *(OOC_UINT8*)(i0+(_check_index(3, i2, OOC_UINT8, 5520)));
    i0 = i0==0u;
    
l16:
    if (i0) goto l29;
    i0 = _check_pointer(i1, 5615);
    i2 = OOC_ARRAY_LENGTH(i0, 0);
    i0 = *(OOC_UINT8*)(i0+(_check_index(1, i2, OOC_UINT8, 5615)));
    i0 = i0==60u;
    if (i0) goto l20;
    i0=0u;
    goto l22;
l20:
    i0 = _check_pointer(i1, 5630);
    i2 = OOC_ARRAY_LENGTH(i0, 0);
    i0 = *(OOC_UINT8*)(i0+(_check_index(2, i2, OOC_UINT8, 5630)));
    i0 = i0==0u;
    
l22:
    if (i0) goto l24;
    i0=0u;
    goto l26;
l24:
    i0 = _check_pointer(i1, 5644);
    i1 = OOC_ARRAY_LENGTH(i0, 0);
    i0 = *(OOC_UINT8*)(i0+(_check_index(3, i1, OOC_UINT8, 5644)));
    i0 = i0==63u;
    
l26:
    if (!i0) goto l30;
    _copy_8((const void*)"UTF16-LE",(void*)(OOC_INT32)str,16);
    goto l30;
l29:
    _copy_8((const void*)"UCS-4-3412",(void*)(OOC_INT32)str,16);
l30:
    i0=0;
    goto l161;
l31:
    i0 = _check_pointer(i1, 5025);
    i2 = OOC_ARRAY_LENGTH(i0, 0);
    i0 = *(OOC_UINT8*)(i0+(_check_index(2, i2, OOC_UINT8, 5025)));
    i0 = i0==0u;
    if (i0) goto l34;
    i0=0u;
    goto l36;
l34:
    i0 = _check_pointer(i1, 5039);
    i2 = OOC_ARRAY_LENGTH(i0, 0);
    i0 = *(OOC_UINT8*)(i0+(_check_index(3, i2, OOC_UINT8, 5039)));
    i0 = i0==60u;
    
l36:
    if (i0) goto l62;
    i0 = _check_pointer(i1, 5130);
    i2 = OOC_ARRAY_LENGTH(i0, 0);
    i0 = *(OOC_UINT8*)(i0+(_check_index(2, i2, OOC_UINT8, 5130)));
    i0 = i0==60u;
    if (i0) goto l40;
    i0=0u;
    goto l42;
l40:
    i0 = _check_pointer(i1, 5145);
    i2 = OOC_ARRAY_LENGTH(i0, 0);
    i0 = *(OOC_UINT8*)(i0+(_check_index(3, i2, OOC_UINT8, 5145)));
    i0 = i0==0u;
    
l42:
    if (i0) goto l60;
    i0 = _check_pointer(i1, 5235);
    i2 = OOC_ARRAY_LENGTH(i0, 0);
    i0 = *(OOC_UINT8*)(i0+(_check_index(2, i2, OOC_UINT8, 5235)));
    i0 = i0==254u;
    if (i0) goto l46;
    i0=0u;
    goto l48;
l46:
    i0 = _check_pointer(i1, 5251);
    i2 = OOC_ARRAY_LENGTH(i0, 0);
    i0 = *(OOC_UINT8*)(i0+(_check_index(3, i2, OOC_UINT8, 5251)));
    i0 = i0==255u;
    
l48:
    if (i0) goto l58;
    i0 = _check_pointer(i1, 5357);
    i2 = OOC_ARRAY_LENGTH(i0, 0);
    i0 = *(OOC_UINT8*)(i0+(_check_index(2, i2, OOC_UINT8, 5357)));
    i0 = i0==255u;
    if (i0) goto l52;
    i0=0u;
    goto l54;
l52:
    i0 = _check_pointer(i1, 5373);
    i1 = OOC_ARRAY_LENGTH(i0, 0);
    i0 = *(OOC_UINT8*)(i0+(_check_index(3, i1, OOC_UINT8, 5373)));
    i0 = i0==254u;
    
l54:
    if (i0) goto l56;
    i0=0;
    goto l161;
l56:
    _copy_8((const void*)"UCS-4-2143",(void*)(OOC_INT32)str,16);
    i0=4;
    goto l161;
l58:
    _copy_8((const void*)"UCS-4-1234",(void*)(OOC_INT32)str,16);
    i0=4;
    goto l161;
l60:
    _copy_8((const void*)"UCS-4-2143",(void*)(OOC_INT32)str,16);
    i0=0;
    goto l161;
l62:
    _copy_8((const void*)"UCS-4-1234",(void*)(OOC_INT32)str,16);
    i0=0;
    goto l161;
  case 60u:
    i0 = _check_pointer(i1, 5743);
    i2 = OOC_ARRAY_LENGTH(i0, 0);
    i0 = *(OOC_UINT8*)(i0+(_check_index(1, i2, OOC_UINT8, 5743)));
    i0 = i0==0u;
    if (i0) goto l79;
    i0 = _check_pointer(i1, 5997);
    i2 = OOC_ARRAY_LENGTH(i0, 0);
    i0 = *(OOC_UINT8*)(i0+(_check_index(1, i2, OOC_UINT8, 5997)));
    i0 = i0==63u;
    if (i0) goto l70;
    i0=0u;
    goto l72;
l70:
    i0 = _check_pointer(i1, 6012);
    i2 = OOC_ARRAY_LENGTH(i0, 0);
    i0 = *(OOC_UINT8*)(i0+(_check_index(2, i2, OOC_UINT8, 6012)));
    i0 = i0==120u;
    
l72:
    if (i0) goto l74;
    i0=0u;
    goto l76;
l74:
    i0 = _check_pointer(i1, 6027);
    i1 = OOC_ARRAY_LENGTH(i0, 0);
    i0 = *(OOC_UINT8*)(i0+(_check_index(3, i1, OOC_UINT8, 6027)));
    i0 = i0==109u;
    
l76:
    if (!i0) goto l95;
    _copy_8((const void*)"UTF-8",(void*)(OOC_INT32)str,16);
    goto l95;
l79:
    i0 = _check_pointer(i1, 5773);
    i2 = OOC_ARRAY_LENGTH(i0, 0);
    i0 = *(OOC_UINT8*)(i0+(_check_index(2, i2, OOC_UINT8, 5773)));
    i0 = i0==0u;
    if (i0) goto l82;
    i0=0u;
    goto l84;
l82:
    i0 = _check_pointer(i1, 5787);
    i2 = OOC_ARRAY_LENGTH(i0, 0);
    i0 = *(OOC_UINT8*)(i0+(_check_index(3, i2, OOC_UINT8, 5787)));
    i0 = i0==0u;
    
l84:
    if (i0) goto l93;
    i0 = _check_pointer(i1, 5878);
    i2 = OOC_ARRAY_LENGTH(i0, 0);
    i0 = *(OOC_UINT8*)(i0+(_check_index(2, i2, OOC_UINT8, 5878)));
    i0 = i0==63u;
    if (i0) goto l88;
    i0=0u;
    goto l90;
l88:
    i0 = _check_pointer(i1, 5893);
    i1 = OOC_ARRAY_LENGTH(i0, 0);
    i0 = *(OOC_UINT8*)(i0+(_check_index(3, i1, OOC_UINT8, 5893)));
    i0 = i0==0u;
    
l90:
    if (!i0) goto l95;
    _copy_8((const void*)"UTF-16LE",(void*)(OOC_INT32)str,16);
    goto l95;
l93:
    _copy_8((const void*)"UCS-4-4321",(void*)(OOC_INT32)str,16);
l95:
    i0=0;
    goto l161;
  case 76u:
    i0 = _check_pointer(i1, 6107);
    i2 = OOC_ARRAY_LENGTH(i0, 0);
    i0 = *(OOC_UINT8*)(i0+(_check_index(1, i2, OOC_UINT8, 6107)));
    i0 = i0==111u;
    if (i0) goto l99;
    i0=0u;
    goto l101;
l99:
    i0 = _check_pointer(i1, 6122);
    i2 = OOC_ARRAY_LENGTH(i0, 0);
    i0 = *(OOC_UINT8*)(i0+(_check_index(2, i2, OOC_UINT8, 6122)));
    i0 = i0==167u;
    
l101:
    if (i0) goto l103;
    i0=0u;
    goto l105;
l103:
    i0 = _check_pointer(i1, 6138);
    i1 = OOC_ARRAY_LENGTH(i0, 0);
    i0 = *(OOC_UINT8*)(i0+(_check_index(3, i1, OOC_UINT8, 6138)));
    i0 = i0==148u;
    
l105:
    if (!i0) goto l107;
    _copy_8((const void*)"EBCDIC",(void*)(OOC_INT32)str,16);
l107:
    i0=0;
    goto l161;
  case 239u:
    i0 = _check_pointer(i1, 6331);
    i2 = OOC_ARRAY_LENGTH(i0, 0);
    i0 = *(OOC_UINT8*)(i0+(_check_index(1, i2, OOC_UINT8, 6331)));
    i0 = i0==187u;
    if (i0) goto l111;
    i0=0u;
    goto l113;
l111:
    i0 = _check_pointer(i1, 6347);
    i1 = OOC_ARRAY_LENGTH(i0, 0);
    i0 = *(OOC_UINT8*)(i0+(_check_index(2, i1, OOC_UINT8, 6347)));
    i0 = i0==191u;
    
l113:
    if (i0) goto l115;
    i0=0;
    goto l161;
l115:
    _copy_8((const void*)"UTF-8",(void*)(OOC_INT32)str,16);
    i0=3;
    goto l161;
  case 254u:
    i0 = _check_pointer(i1, 6483);
    i2 = OOC_ARRAY_LENGTH(i0, 0);
    i0 = *(OOC_UINT8*)(i0+(_check_index(1, i2, OOC_UINT8, 6483)));
    i0 = i0==255u;
    if (i0) goto l120;
    i0=0;
    goto l161;
l120:
    i0 = _check_pointer(i1, 6515);
    i2 = OOC_ARRAY_LENGTH(i0, 0);
    i0 = *(OOC_UINT8*)(i0+(_check_index(2, i2, OOC_UINT8, 6515)));
    i0 = i0!=0u;
    if (i0) goto l123;
    i0 = _check_pointer(i1, 6530);
    i2 = OOC_ARRAY_LENGTH(i0, 0);
    i0 = *(OOC_UINT8*)(i0+(_check_index(3, i2, OOC_UINT8, 6530)));
    i0 = i0!=0u;
    
    goto l125;
l123:
    i0=1u;
l125:
    if (i0) goto l135;
    i0 = _check_pointer(i1, 6662);
    i2 = OOC_ARRAY_LENGTH(i0, 0);
    i0 = *(OOC_UINT8*)(i0+(_check_index(2, i2, OOC_UINT8, 6662)));
    i0 = i0==0u;
    if (i0) goto l129;
    i0=0u;
    goto l131;
l129:
    i0 = _check_pointer(i1, 6676);
    i1 = OOC_ARRAY_LENGTH(i0, 0);
    i0 = *(OOC_UINT8*)(i0+(_check_index(3, i1, OOC_UINT8, 6676)));
    i0 = i0==0u;
    
l131:
    if (i0) goto l133;
    i0=0;
    goto l161;
l133:
    _copy_8((const void*)"UCS-4-3412",(void*)(OOC_INT32)str,16);
    i0=4;
    goto l161;
l135:
    _copy_8((const void*)"UTF-16BE",(void*)(OOC_INT32)str,16);
    i0=2;
    goto l161;
  case 255u:
    i0 = _check_pointer(i1, 6815);
    i2 = OOC_ARRAY_LENGTH(i0, 0);
    i0 = *(OOC_UINT8*)(i0+(_check_index(1, i2, OOC_UINT8, 6815)));
    i0 = i0==254u;
    if (i0) goto l141;
    i0=0;
    goto l161;
l141:
    i0 = _check_pointer(i1, 6847);
    i2 = OOC_ARRAY_LENGTH(i0, 0);
    i0 = *(OOC_UINT8*)(i0+(_check_index(2, i2, OOC_UINT8, 6847)));
    i0 = i0!=0u;
    if (i0) goto l144;
    i0 = _check_pointer(i1, 6862);
    i2 = OOC_ARRAY_LENGTH(i0, 0);
    i0 = *(OOC_UINT8*)(i0+(_check_index(3, i2, OOC_UINT8, 6862)));
    i0 = i0!=0u;
    
    goto l146;
l144:
    i0=1u;
l146:
    if (i0) goto l156;
    i0 = _check_pointer(i1, 6997);
    i2 = OOC_ARRAY_LENGTH(i0, 0);
    i0 = *(OOC_UINT8*)(i0+(_check_index(2, i2, OOC_UINT8, 6997)));
    i0 = i0==0u;
    if (i0) goto l150;
    i0=0u;
    goto l152;
l150:
    i0 = _check_pointer(i1, 7011);
    i1 = OOC_ARRAY_LENGTH(i0, 0);
    i0 = *(OOC_UINT8*)(i0+(_check_index(3, i1, OOC_UINT8, 7011)));
    i0 = i0==0u;
    
l152:
    if (i0) goto l154;
    i0=0;
    goto l161;
l154:
    _copy_8((const void*)"UCS-4-4321",(void*)(OOC_INT32)str,16);
    i0=4;
    goto l161;
l156:
    _copy_8((const void*)"UTF-16LE",(void*)(OOC_INT32)str,16);
    i0=2;
    goto l161;
  default:
    i0=0;
    goto l161;
  }
l161:
  _copy_8((const void*)(OOC_INT32)str,(void*)(OOC_INT32)enc,enc_0d);
  return i0;
  ;
}

OOC_CHAR8 XML_UnicodeBuffer__InputDesc_NextBlock(XML_UnicodeBuffer__Input in) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8,i9,i10,i11;
  OOC_INT32 len;
  XML_UnicodeBuffer__CharArray nChars;

  i0 = (OOC_INT32)in;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8284))+20);
  i1 = _check_pointer(i1, 8291);
  i2 = *(OOC_INT32*)((_check_pointer(i0, 8294))+28);
  i3 = OOC_ARRAY_LENGTH(i1, 0);
  i1 = *(OOC_UINT16*)(i1+(_check_index(i2, i3, OOC_UINT32, 8291))*2);
  i1 = i1==65535u;
  if (i1) goto l10;
  i1 = *(OOC_UINT8*)((_check_pointer(i0, 8359))+4);
  i1 = !i1;
  if (i1) goto l5;
  i1=0u;
  goto l7;
l5:
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 8387));
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 8423));
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 8435))+4);
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 8442)), 0);
  i1 = *(OOC_INT32*)((_check_pointer(i1, 8399))+16);
  i1 = i1>=(i2>>1);
  
l7:
  if (!i1) goto l11;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 8487));
  i1 = XML_InputBuffer__BufferDesc_NextBlock((XML_InputBuffer__Buffer)i1);
  *(OOC_UINT8*)((_check_pointer(i0, 8465))+4) = (!i1);
  goto l11;
l10:
  return 0u;
l11:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8541))+20);
  i1 = _check_pointer(i1, 8548);
  i2 = *(OOC_INT32*)((_check_pointer(i0, 8551))+28);
  i3 = OOC_ARRAY_LENGTH(i1, 0);
  i1 = *(OOC_UINT16*)(i1+(_check_index(i2, i3, OOC_UINT32, 8548))*2);
  _assert((i1==65534u), 127, 8531);
  i1 = *(OOC_INT32*)((_check_pointer(i0, 8590))+32);
  i1 = i1>=4096;
  if (!i1) goto l19;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 8686))+28);
  i2 = *(OOC_INT32*)((_check_pointer(i0, 8704))+32);
  i1 = i1-i2;
  len = i1;
  i2 = *(OOC_INT32*)((_check_pointer(i0, 8737))+32);
  i2 = i1<i2;
  if (!i2) goto l19;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9017))+20);
  i2 = _check_pointer(i2, 9024);
  i3 = *(OOC_INT32*)((_check_pointer(i0, 9027))+32);
  i4 = OOC_ARRAY_LENGTH(i2, 0);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9080))+20);
  _move_block((i2+(_check_index(i3, i4, OOC_UINT32, 9024))*2),(_check_pointer(i0, 9087)),((i1+1)*2));
  i0 = (OOC_INT32)in;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 9149))+24);
  i2 = *(OOC_INT32*)((_check_pointer(i0, 9169))+32);
  *(OOC_INT32*)((_check_pointer(i0, 9149))+24) = (i1+i2);
  i1 = len;
  *(OOC_INT32*)((_check_pointer(i0, 9195))+28) = i1;
  *(OOC_INT32*)((_check_pointer(i0, 9227))+32) = 0;
  
l19:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9279))+20);
  i1 = _check_pointer(i1, 9286);
  i2 = *(OOC_INT32*)((_check_pointer(i0, 9289))+28);
  i3 = OOC_ARRAY_LENGTH(i1, 0);
  i1 = *(OOC_UINT16*)(i1+(_check_index(i2, i3, OOC_UINT32, 9286))*2);
  _assert((i1==65534u), 127, 9269);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9366))+20);
  i2 = *(OOC_INT32*)((_check_pointer(i0, 9329))+28);
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 9373)), 0);
  i1 = (i2+4096)>=i1;
  if (!i1) goto l28;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9495))+20);
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 9502)), 0);
  
l23_loop:
  i1 = i1+4096;
  len = i1;
  i2 = *(OOC_INT32*)((_check_pointer(i0, 9566))+28);
  i2 = (i2+4096)<i1;
  if (!i2) goto l23_loop;
l27:
  i1 = (OOC_INT32)RT0__NewObject(_td_XML_UnicodeBuffer__CharArray.baseTypes[0], i1);
  nChars = (XML_UnicodeBuffer__CharArray)i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9659))+20);
  i0 = *(OOC_INT32*)((_check_pointer(i0, 9733))+28);
  _move_block((_check_pointer(i2, 9666)),(_check_pointer(i1, 9707)),((i0+1)*2));
  i0 = (OOC_INT32)in;
  i1 = (OOC_INT32)nChars;
  *(OOC_INT32*)((_check_pointer(i0, 9772))+20) = i1;
  
l28:
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 9814));
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 9844));
  i2 = *(OOC_INT32*)((_check_pointer(i2, 9856))+12);
  i1 = *(OOC_INT32*)((_check_pointer(i1, 9826))+16);
  i1 = i1!=i2;
  if (i1) goto l31;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10394))+20);
  i1 = _check_pointer(i1, 10401);
  i0 = *(OOC_INT32*)((_check_pointer(i0, 10404))+28);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  *(OOC_UINT16*)(i1+(_check_index(i0, i2, OOC_UINT32, 10401))*2) = 65535u;
  return 0u;
  goto l32;
l31:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9978))+12);
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 9997));
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 10009))+4);
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 9997));
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 10009))+4);
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 10042));
  i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 10071));
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10121))+20);
  i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10121))+20);
  i8 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10176))+20);
  i9 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 10212));
  i8 = OOC_ARRAY_LENGTH((_check_pointer(i8, 10183)), 0);
  i10 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9978))+12);
  i4 = *(OOC_INT32*)((_check_pointer(i4, 10054))+16);
  i5 = *(OOC_INT32*)((_check_pointer(i5, 10083))+12);
  i11 = *(OOC_INT32*)((_check_pointer(i0, 10154))+28);
  i7 = OOC_ARRAY_LENGTH((_check_pointer(i7, 10128)), 0);
  i3 = OOC_ARRAY_LENGTH((_check_pointer(i3, 10016)), 0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 9985)))), XML_UnicodeCodec__CodecDesc_Decode)),XML_UnicodeCodec__CodecDesc_Decode)((XML_UnicodeCodec__Codec)i10, (void*)(_check_pointer(i2, 10016)), i3, i4, i5, (void*)(_check_pointer(i6, 10128)), i7, i11, (i8-1), (void*)((_check_pointer(i9, 10224))+16), (void*)((_check_pointer(i0, 10241))+28));
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10265))+20);
  i1 = _check_pointer(i1, 10272);
  i0 = *(OOC_INT32*)((_check_pointer(i0, 10275))+28);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  *(OOC_UINT16*)(i1+(_check_index(i0, i2, OOC_UINT32, 10272))*2) = 65534u;
  return 1u;
l32:
  _failed_function(7592); return 0;
  ;
}

void XML_UnicodeBuffer__InputDesc_Close(XML_UnicodeBuffer__Input in) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)in;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 10726));
  XML_InputBuffer__BufferDesc_Close((XML_InputBuffer__Buffer)i1);
  *(OOC_INT32*)(_check_pointer(i0, 10753)) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 10780))+12) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 10802))+20) = 0;
  return;
  ;
}

void XML_UnicodeBuffer__InputDesc_SetCodec(XML_UnicodeBuffer__Input in, XML_UnicodeCodec__Factory cf, OOC_CHAR8 autoDetect) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  OOC_CHAR8 dummy;

  i0 = (OOC_INT32)in;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 11012));
  i1 = *(OOC_INT32*)((_check_pointer(i1, 11024))+8);
  _assert((i1==0), 127, 11002);
  i1 = (OOC_INT32)cf;
  *(OOC_INT32*)((_check_pointer(i0, 11053))+8) = i1;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 11117));
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 11129))+4);
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 11117));
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 11129))+4);
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 11144));
  i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 11180));
  i3 = OOC_ARRAY_LENGTH((_check_pointer(i3, 11136)), 0);
  i4 = *(OOC_INT32*)((_check_pointer(i4, 11156))+12);
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 11094)))), XML_UnicodeCodec__FactoryDesc_NewCodecBOM)),XML_UnicodeCodec__FactoryDesc_NewCodecBOM)((XML_UnicodeCodec__Factory)i1, (void*)(_check_pointer(i2, 11136)), i3, 0, i4, (void*)((_check_pointer(i5, 11192))+16));
  *(OOC_INT32*)((_check_pointer(i0, 11081))+12) = i1;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11214))+20);
  i1 = _check_pointer(i1, 11221);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  *(OOC_UINT16*)(i1+(_check_index(0, i2, OOC_UINT8, 11221))*2) = 65534u;
  *(OOC_INT32*)((_check_pointer(i0, 11245))+32) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 11271))+24) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 11300))+28) = 0;
  i1 = XML_UnicodeBuffer__InputDesc_NextBlock((XML_UnicodeBuffer__Input)i0);
  dummy = i1;
  i1 = autoDetect;
  *(OOC_UINT8*)((_check_pointer(i0, 11356))+16) = i1;
  return;
  ;
}

void XML_UnicodeBuffer__InitInput(XML_UnicodeBuffer__Input input, OOC_CHAR8 _new, IO__ByteChannel reader, XML_UnicodeCodec__Factory codecFactory, Msg__MsgList errList) {
  register OOC_INT32 i0,i1,i2;
  OOC_CHAR8 encoding[256];

  i0 = _new;
  if (i0) goto l3;
  _assert(0u, 127, 11822);
  goto l4;
l3:
  i0 = (OOC_INT32)input;
  i1 = (OOC_INT32)reader;
  i2 = (OOC_INT32)errList;
  i1 = (OOC_INT32)XML_InputBuffer__New((IO__ByteChannel)i1, (Msg__MsgList)i2);
  *(OOC_INT32*)(_check_pointer(i0, 11711)) = i1;
  *(OOC_INT32*)((_check_pointer(i0, 11778))+20) = ((OOC_INT32)RT0__NewObject(_td_XML_UnicodeBuffer__CharArray.baseTypes[0], 16352));
l4:
  i0 = (OOC_INT32)input;
  *(OOC_UINT8*)((_check_pointer(i0, 11914))+4) = 0u;
  i1 = (OOC_INT32)errList;
  *(OOC_INT32*)((_check_pointer(i0, 11949))+36) = i1;
  i1 = (OOC_INT32)codecFactory;
  i1 = i1==0;
  if (i1) goto l7;
  i1=0u;
  goto l8;
l7:
  i1 = XML_UnicodeBuffer__AutodetectEnc((XML_UnicodeBuffer__Input)i0, (void*)(OOC_INT32)encoding, 256);
  i1 = (OOC_INT32)XML_UnicodeCodec__GetFactory((void*)(OOC_INT32)encoding, 256);
  codecFactory = (XML_UnicodeCodec__Factory)i1;
  _assert((i1!=0), 127, 12138);
  i1=1u;
l8:
  i2 = (OOC_INT32)codecFactory;
  XML_UnicodeBuffer__InputDesc_SetCodec((XML_UnicodeBuffer__Input)i0, (XML_UnicodeCodec__Factory)i2, i1);
  return;
  ;
}

XML_UnicodeBuffer__Input XML_UnicodeBuffer__NewInput(IO__ByteChannel reader, XML_UnicodeCodec__Factory codecFactory, Msg__MsgList errList) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)RT0__NewObject(_td_XML_UnicodeBuffer__Input.baseTypes[0]);
  i1 = (OOC_INT32)reader;
  i2 = (OOC_INT32)codecFactory;
  i3 = (OOC_INT32)errList;
  XML_UnicodeBuffer__InitInput((XML_UnicodeBuffer__Input)i0, 1u, (IO__ByteChannel)i1, (XML_UnicodeCodec__Factory)i2, (Msg__MsgList)i3);
  return (XML_UnicodeBuffer__Input)i0;
  ;
}

static void XML_UnicodeBuffer__FlushBytes(volatile XML_UnicodeBuffer__Output out) {
  register OOC_INT32 i0,i1,i2,i3;
  volatile OOC_INT32 d;
  volatile Exception__Exception e;
  jmp_buf _target0;
  Exception__Context _context0;

  {
    Exception__PushContext(&_context0, &_target0);
    if (!setjmp(_target0)) goto l7;
    Exception__PopContext(1);
    i0 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG(((OOC_INT32)Exception__Current()))), &_td_IO__ErrorDesc);
    if (i0) goto l5;
    Exception__ActivateContext();
    goto l6;
l5:
    i0 = (OOC_INT32)Exception__Current();
    e = (Exception__Exception)i0;
    i1 = (OOC_INT32)out;
    *(OOC_INT32*)((_check_pointer(i1, 13786))+12) = (_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13801)))), &_td_IO__ErrorDesc, 13801));
l6:
    Exception__Clear();
    goto l8;
l7:
    i0 = (OOC_INT32)out;
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13672))+8);
    i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13692))+16);
    i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13672))+8);
    i0 = *(OOC_INT32*)((_check_pointer(i0, 13713))+24);
    i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 13680)))), IO__ByteChannelDesc_Write)),IO__ByteChannelDesc_Write)((IO__ByteChannel)i3, (void*)(_check_pointer(i2, 13704)), 8192, 0, i0);
    d = i0;
    Exception__PopContext(1);
l8:;
  }
  i0 = (OOC_INT32)out;
  *(OOC_INT32*)((_check_pointer(i0, 13825))+24) = 0;
  return;
  ;
}

static void XML_UnicodeBuffer__Encode(XML_UnicodeBuffer__Output out, OOC_CHAR8 all) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8,i9;
  OOC_INT32 start;
  OOC_INT32 limit;
  OOC_INT32 len;
  OOC_INT32 i;

  start = 0;
  i0 = all;
  if (i0) goto l3;
  i1 = (OOC_INT32)out;
  i2 = *(OOC_INT32*)((_check_pointer(i1, 14072))+32);
  i2 = i2-1024;
  limit = i2;
  {register OOC_INT32 h0=i1;i1=i2;i2=h0;}
  goto l4;
l3:
  i1 = (OOC_INT32)out;
  i2 = *(OOC_INT32*)((_check_pointer(i1, 14004))+32);
  i2 = i2-2;
  limit = i2;
  {register OOC_INT32 h0=i1;i1=i2;i2=h0;}
l4:
  i3 = 0<=i1;
  if (i3) goto l8_loop;
  i1=0;
  goto l17;
l8_loop:
  i3 = *(OOC_INT32*)((_check_pointer(i2, 14189))+24);
  i3 = (8192-i3)<6;
  if (!i3) goto l11;
  XML_UnicodeBuffer__FlushBytes((XML_UnicodeBuffer__Output)i2);
l11:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 14280))+4);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 14300))+28);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 14369))+16);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 14280))+4);
  i7 = *(OOC_INT32*)((_check_pointer(i2, 14328))+32);
  i8 = *(OOC_INT32*)((_check_pointer(i2, 14387))+24);
  i9 = start;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 14287)))), XML_UnicodeCodec__CodecDesc_Encode)),XML_UnicodeCodec__CodecDesc_Encode)((XML_UnicodeCodec__Codec)i6, (void*)(_check_pointer(i4, 14315)), 8192, i9, i7, (void*)(_check_pointer(i5, 14381)), 8192, i8, 8192, (void*)(OOC_INT32)&start, (void*)((_check_pointer(i2, 14456))+24));
  i3 = start;
  i4 = i3<=i1;
  if (i4) goto l8_loop;
l15:
  i1=i3;
l17:
  if (i0) goto l19;
  i0=0u;
  goto l21;
l19:
  i0 = *(OOC_INT32*)((_check_pointer(i2, 14506))+32);
  i0 = i1!=i0;
  
l21:
  if (i0) goto l31;
  i0 = *(OOC_INT32*)((_check_pointer(i2, 14904))+32);
  i0 = i0-i1;
  len = i0;
  i = 0;
  i3 = 0<i0;
  if (!i3) goto l30;
  i3=0;
l25_loop:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 14964))+28);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 14989))+28);
  i5 = *(OOC_UINT16*)((_check_pointer(i5, 15004))+(_check_index((i1+i3), 8192, OOC_UINT32, 15004))*2);
  *(OOC_UINT16*)((_check_pointer(i4, 14979))+(_check_index(i3, 8192, OOC_UINT32, 14979))*2) = i5;
  i3 = i3+1;
  i = i3;
  i4 = i3<i0;
  if (i4) goto l25_loop;
l30:
  *(OOC_INT32*)((_check_pointer(i2, 15034))+32) = i0;
  goto l35;
l31:
  i0 = *(OOC_INT32*)((_check_pointer(i2, 14561))+24);
  i0 = (8192-i0)<6;
  if (!i0) goto l34;
  XML_UnicodeBuffer__FlushBytes((XML_UnicodeBuffer__Output)i2);
l34:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 14652))+4);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 14672))+28);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 14741))+16);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 14652))+4);
  i5 = *(OOC_INT32*)((_check_pointer(i2, 14700))+32);
  i6 = *(OOC_INT32*)((_check_pointer(i2, 14759))+24);
  i7 = start;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14659)))), XML_UnicodeCodec__CodecDesc_Encode)),XML_UnicodeCodec__CodecDesc_Encode)((XML_UnicodeCodec__Codec)i4, (void*)(_check_pointer(i1, 14687)), 8192, i7, i5, (void*)(_check_pointer(i3, 14753)), 8192, i6, 8192, (void*)(OOC_INT32)&start, (void*)((_check_pointer(i2, 14828))+24));
  i0 = *(OOC_INT32*)((_check_pointer(i2, 14865))+32);
  i1 = start;
  _assert((i1==i0), 127, 14846);
l35:
  return;
  ;
}

void XML_UnicodeBuffer__OutputDesc_Write16I(XML_UnicodeBuffer__Output out, const OOC_CHAR16 str[], OOC_LEN str_0d, OOC_INT32 start, OOC_INT32 end) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  OOC_INT32 len;

  i0 = end;
  i1 = start;
  i2 = i0-i1;
  len = i2;
  i3 = i2!=0;
  if (i3) goto l3;
  i3=0u;
  goto l5;
l3:
  i3 = (OOC_INT32)out;
  i3 = *(OOC_INT32*)((_check_pointer(i3, 15281))+32);
  i3 = (i3+i2)<=8192;
  
l5:
  if (i3) goto l22;
  i2 = i1!=i0;
  if (!i2) goto l23;
  i2 = (OOC_INT32)out;
  
l9_loop:
  i3 = *(OOC_INT32*)((_check_pointer(i2, 15569))+32);
  i3 = i3==8192;
  if (!i3) goto l12;
  XML_UnicodeBuffer__Encode((XML_UnicodeBuffer__Output)i2, 0u);
l12:
  i3 = *(OOC_INT32*)((_check_pointer(i2, 15703))+32);
  i3 = 8192-i3;
  len = i3;
  i4 = i0-i1;
  i5 = i3>i4;
  if (!i5) goto l16;
  len = i4;
  i3=i4;
l16:
  i3 = i1+i3;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 15802)))), XML_UnicodeBuffer__OutputDesc_Write16I)),XML_UnicodeBuffer__OutputDesc_Write16I)((XML_UnicodeBuffer__Output)i2, (void*)(OOC_INT32)str, str_0d, i1, i3);
  start = i3;
  i1 = i3!=i0;
  if (!i1) goto l23;
  i1=i3;
  goto l9_loop;
l22:
  i0 = (OOC_INT32)out;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15411))+28);
  i0 = *(OOC_INT32*)((_check_pointer(i0, 15430))+32);
  _move_block(((OOC_INT32)str+(_check_index(i1, str_0d, OOC_UINT32, 15367))*2),((_check_pointer(i3, 15426))+(_check_index(i0, 8192, OOC_UINT32, 15426))*2),(i2*2));
  i0 = (OOC_INT32)out;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 15497))+32);
  i2 = len;
  *(OOC_INT32*)((_check_pointer(i0, 15497))+32) = (i1+i2);
l23:
  return;
  ;
}

void XML_UnicodeBuffer__OutputDesc_Write8I(XML_UnicodeBuffer__Output out, const OOC_CHAR8 str[], OOC_LEN str_0d, OOC_INT32 start, OOC_INT32 end) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
  OOC_INT32 len;
  OOC_INT32 pos;

  i0 = end;
  i1 = start;
  i2 = i0-i1;
  len = i2;
  i3 = i2!=0;
  if (i3) goto l3;
  i3=0u;
  goto l5;
l3:
  i3 = (OOC_INT32)out;
  i3 = *(OOC_INT32*)((_check_pointer(i3, 16099))+32);
  i3 = (i3+i2)<=8192;
  
l5:
  if (i3) goto l22;
  i2 = i1!=i0;
  if (!i2) goto l31;
  i2 = (OOC_INT32)out;
  
l9_loop:
  i3 = *(OOC_INT32*)((_check_pointer(i2, 16386))+32);
  i3 = i3==8192;
  if (!i3) goto l12;
  XML_UnicodeBuffer__Encode((XML_UnicodeBuffer__Output)i2, 0u);
l12:
  i3 = *(OOC_INT32*)((_check_pointer(i2, 16520))+32);
  i3 = 8192-i3;
  len = i3;
  i4 = i0-i1;
  i5 = i3>i4;
  if (!i5) goto l16;
  len = i4;
  i3=i4;
l16:
  i3 = i1+i3;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 16619)))), XML_UnicodeBuffer__OutputDesc_Write8I)),XML_UnicodeBuffer__OutputDesc_Write8I)((XML_UnicodeBuffer__Output)i2, (void*)(OOC_INT32)str, str_0d, i1, i3);
  start = i3;
  i1 = i3!=i0;
  if (!i1) goto l31;
  i1=i3;
  goto l9_loop;
l22:
  i3 = (OOC_INT32)out;
  i4 = *(OOC_INT32*)((_check_pointer(i3, 16167))+32);
  i4 = i4-i1;
  pos = i4;
  i5 = i1!=i0;
  if (!i5) goto l30;
  i4 = i4+i1;
  
l25_loop:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 16227))+28);
  i6 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i1, str_0d, OOC_UINT32, 16260)));
  *(OOC_UINT16*)((_check_pointer(i5, 16242))+(_check_index(i4, 8192, OOC_UINT32, 16242))*2) = i6;
  i1 = i1+1;
  start = i1;
  i4 = i4+1;
  i5 = i1!=i0;
  if (i5) goto l25_loop;
l30:
  i0 = *(OOC_INT32*)((_check_pointer(i3, 16314))+32);
  *(OOC_INT32*)((_check_pointer(i3, 16314))+32) = (i0+i2);
l31:
  return;
  ;
}

void XML_UnicodeBuffer__OutputDesc_Write16(XML_UnicodeBuffer__Output out, const OOC_CHAR16 str[], OOC_LEN str_0d) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)out;
  i1 = LongStrings__Length((void*)(OOC_INT32)str, str_0d);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 16792)))), XML_UnicodeBuffer__OutputDesc_Write16I)),XML_UnicodeBuffer__OutputDesc_Write16I)((XML_UnicodeBuffer__Output)i0, (void*)(OOC_INT32)str, str_0d, 0, i1);
  return;
  ;
}

void XML_UnicodeBuffer__OutputDesc_Write8(XML_UnicodeBuffer__Output out, const OOC_CHAR8 str[], OOC_LEN str_0d) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)out;
  i1 = Strings__Length((void*)(OOC_INT32)str, str_0d);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 16932)))), XML_UnicodeBuffer__OutputDesc_Write8I)),XML_UnicodeBuffer__OutputDesc_Write8I)((XML_UnicodeBuffer__Output)i0, (void*)(OOC_INT32)str, str_0d, 0, i1);
  return;
  ;
}

void XML_UnicodeBuffer__OutputDesc_Flush(XML_UnicodeBuffer__Output out) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)out;
  XML_UnicodeBuffer__Encode((XML_UnicodeBuffer__Output)i0, 1u);
  XML_UnicodeBuffer__FlushBytes((XML_UnicodeBuffer__Output)i0);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17213))+8);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17213))+8);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 17221)))), IO__ByteChannelDesc_Flush)),IO__ByteChannelDesc_Flush)((IO__ByteChannel)i0);
  return;
  ;
}

void XML_UnicodeBuffer__InitOutput(XML_UnicodeBuffer__Output out, OOC_CHAR8 _new, IO__ByteChannel writer, XML_UnicodeCodec__Factory codecFactory, OOC_CHAR8 createBOM) {
  register OOC_INT32 i0,i1,i2,i3,i4;

  i0 = _new;
  if (!i0) goto l3;
  i0 = (OOC_INT32)out;
  *(OOC_INT32*)((_check_pointer(i0, 17451))+16) = ((OOC_INT32)RT0__NewObject(_td_XML_UnicodeBuffer__3519.baseTypes[0]));
  *(OOC_INT32*)((_check_pointer(i0, 17480))+28) = ((OOC_INT32)RT0__NewObject(_td_XML_UnicodeBuffer__3618.baseTypes[0]));
l3:
  i0 = (OOC_INT32)out;
  i1 = (OOC_INT32)codecFactory;
  *(OOC_INT32*)(_check_pointer(i0, 17519)) = i1;
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 17581)))), XML_UnicodeCodec__FactoryDesc_NewCodec)),XML_UnicodeCodec__FactoryDesc_NewCodec)((XML_UnicodeCodec__Factory)i1);
  *(OOC_INT32*)((_check_pointer(i0, 17558))+4) = i1;
  i1 = (OOC_INT32)writer;
  *(OOC_INT32*)((_check_pointer(i0, 17602))+8) = i1;
  *(OOC_INT32*)((_check_pointer(i0, 17629))+12) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 17652))+20) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 17673))+24) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 17696))+32) = 0;
  i1 = createBOM;
  if (!i1) goto l6;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17751))+4);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17774))+16);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17751))+4);
  i4 = *(OOC_INT32*)((_check_pointer(i0, 17792))+24);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 17758)))), XML_UnicodeCodec__CodecDesc_EncodeBOM)),XML_UnicodeCodec__CodecDesc_EncodeBOM)((XML_UnicodeCodec__Codec)i3, (void*)(_check_pointer(i2, 17786)), 8192, i4, 8192, (void*)((_check_pointer(i0, 17859))+24));
l6:
  return;
  ;
}

XML_UnicodeBuffer__Output XML_UnicodeBuffer__NewOutput(IO__ByteChannel writer, XML_UnicodeCodec__Factory codecFactory, OOC_CHAR8 createBOM) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)RT0__NewObject(_td_XML_UnicodeBuffer__Output.baseTypes[0]);
  i1 = (OOC_INT32)writer;
  i2 = (OOC_INT32)codecFactory;
  i3 = createBOM;
  XML_UnicodeBuffer__InitOutput((XML_UnicodeBuffer__Output)i0, 1u, (IO__ByteChannel)i1, (XML_UnicodeCodec__Factory)i2, i3);
  return (XML_UnicodeBuffer__Output)i0;
  ;
}

void OOC_XML_UnicodeBuffer_init(void) {

  _assert(1u, 127, 18969);
  return;
  ;
}

/* --- */
