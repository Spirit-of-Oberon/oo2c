#include <XML/Parser.d>
#include <__oo2c.h>
#include <setjmp.h>

static OOC_CHAR8 XML_Parser__IsCharUCS4(OOC_INT32 ch) {
  register OOC_INT32 i0,i1;

  i0 = ch;
  i1 = 32<=i0;
  if (i1) goto l3;
  i1=0u;
  goto l5;
l3:
  i1 = i0<=55295;
  
l5:
  if (i1) goto l7;
  i1 = i0==9;
  
  goto l9;
l7:
  i1=1u;
l9:
  if (i1) goto l11;
  i1 = i0==10;
  
  goto l13;
l11:
  i1=1u;
l13:
  if (i1) goto l15;
  i1 = i0==13;
  
  goto l17;
l15:
  i1=1u;
l17:
  if (i1) goto l23;
  i1 = 57344<=i0;
  if (i1) goto l21;
  i1=0u;
  goto l25;
l21:
  i1 = i0<=65533;
  
  goto l25;
l23:
  i1=1u;
l25:
  if (i1) goto l31;
  i1 = 65536<=i0;
  if (i1) goto l29;
  i0=0u;
  goto l32;
l29:
  i0 = i0<=1114111;
  
  goto l32;
l31:
  i0=1u;
l32:
  return i0;
  ;
}

static OOC_CHAR8 XML_Parser__IsDigit(OOC_CHAR16 ch) {
  register OOC_INT32 i0,i1;

  i0 = ch;
  i1 = (OOC_UINT16)i0<(OOC_UINT16)256u;
  if (i1) goto l6;
  switch (i0) {
  case 1632u ... 1641u:
  case 1776u ... 1785u:
  case 2406u ... 2415u:
  case 2534u ... 2543u:
  case 2662u ... 2671u:
  case 2790u ... 2799u:
  case 2918u ... 2927u:
  case 3047u ... 3055u:
  case 3174u ... 3183u:
  case 3302u ... 3311u:
  case 3430u ... 3439u:
  case 3664u ... 3673u:
  case 3792u ... 3801u:
  case 3872u ... 3881u:
    return 1u;
    goto l11;
  default:
    return 0u;
    goto l11;
  }
l6:
  i1 = (OOC_UINT16)48u<=(OOC_UINT16)i0;
  if (i1) goto l9;
  i0=0u;
  goto l10;
l9:
  i0 = (OOC_UINT16)i0<=(OOC_UINT16)57u;
  
l10:
  return i0;
l11:
  _failed_function(9290); return 0;
  ;
}

static OOC_CHAR8 XML_Parser__IsBaseChar(OOC_CHAR16 ch) {
  register OOC_INT32 i0,i1;

  i0 = ch;
  i1 = (OOC_UINT16)i0<(OOC_UINT16)256u;
  if (i1) goto l41;
  i1 = (OOC_UINT16)i0<(OOC_UINT16)1024u;
  if (i1) goto l36;
  i1 = (OOC_UINT16)i0<(OOC_UINT16)2048u;
  if (i1) goto l31;
  i1 = (OOC_UINT16)i0<(OOC_UINT16)3072u;
  if (i1) goto l26;
  i1 = (OOC_UINT16)i0<(OOC_UINT16)4096u;
  if (i1) goto l21;
  i1 = (OOC_UINT16)i0<(OOC_UINT16)5120u;
  if (i1) goto l16;
  switch (i0) {
  case 7680u ... 7835u:
  case 7840u ... 7929u:
  case 7936u ... 7957u:
  case 7960u ... 7965u:
  case 7968u ... 8005u:
  case 8008u ... 8013u:
  case 8016u ... 8023u:
  case 8025u:
  case 8027u:
  case 8029u:
  case 8031u ... 8061u:
  case 8064u ... 8116u:
  case 8118u ... 8124u:
  case 8126u:
  case 8130u ... 8132u:
  case 8134u ... 8140u:
  case 8144u ... 8147u:
  case 8150u ... 8155u:
  case 8160u ... 8172u:
  case 8178u ... 8180u:
  case 8182u ... 8188u:
  case 8486u:
  case 8490u ... 8491u:
  case 8494u:
  case 8576u ... 8578u:
  case 12353u ... 12436u:
  case 12449u ... 12538u:
  case 12549u ... 12588u:
  case 44032u ... 55203u:
    return 1u;
    goto l45;
  default:
    return 0u;
    goto l45;
  }
l16:
  switch (i0) {
  case 4256u ... 4293u:
  case 4304u ... 4342u:
  case 4352u:
  case 4354u ... 4355u:
  case 4357u ... 4359u:
  case 4361u:
  case 4363u ... 4364u:
  case 4366u ... 4370u:
  case 4412u:
  case 4414u:
  case 4416u:
  case 4428u:
  case 4430u:
  case 4432u:
  case 4436u ... 4437u:
  case 4441u:
  case 4447u ... 4449u:
  case 4451u:
  case 4453u:
  case 4455u:
  case 4457u:
  case 4461u ... 4462u:
  case 4466u ... 4467u:
  case 4469u:
  case 4510u:
  case 4520u:
  case 4523u:
  case 4526u ... 4527u:
  case 4535u ... 4536u:
  case 4538u:
  case 4540u ... 4546u:
  case 4587u:
  case 4592u:
  case 4601u:
    return 1u;
    goto l45;
  default:
    return 0u;
    goto l45;
  }
l21:
  switch (i0) {
  case 3077u ... 3084u:
  case 3086u ... 3088u:
  case 3090u ... 3112u:
  case 3114u ... 3123u:
  case 3125u ... 3129u:
  case 3168u ... 3169u:
  case 3205u ... 3212u:
  case 3214u ... 3216u:
  case 3218u ... 3240u:
  case 3242u ... 3251u:
  case 3253u ... 3257u:
  case 3294u:
  case 3296u ... 3297u:
  case 3333u ... 3340u:
  case 3342u ... 3344u:
  case 3346u ... 3368u:
  case 3370u ... 3385u:
  case 3424u ... 3425u:
  case 3585u ... 3630u:
  case 3632u:
  case 3634u ... 3635u:
  case 3648u ... 3653u:
  case 3713u ... 3714u:
  case 3716u:
  case 3719u ... 3720u:
  case 3722u:
  case 3725u:
  case 3732u ... 3735u:
  case 3737u ... 3743u:
  case 3745u ... 3747u:
  case 3749u:
  case 3751u:
  case 3754u ... 3755u:
  case 3757u ... 3758u:
  case 3760u:
  case 3762u ... 3763u:
  case 3773u:
  case 3776u ... 3780u:
  case 3904u ... 3911u:
  case 3913u ... 3945u:
    return 1u;
    goto l45;
  default:
    return 0u;
    goto l45;
  }
l26:
  switch (i0) {
  case 2309u ... 2361u:
  case 2365u:
  case 2392u ... 2401u:
  case 2437u ... 2444u:
  case 2447u ... 2448u:
  case 2451u ... 2472u:
  case 2474u ... 2480u:
  case 2482u:
  case 2486u ... 2489u:
  case 2524u ... 2525u:
  case 2527u ... 2529u:
  case 2544u ... 2545u:
  case 2565u ... 2570u:
  case 2575u ... 2576u:
  case 2579u ... 2600u:
  case 2602u ... 2608u:
  case 2610u ... 2611u:
  case 2613u ... 2614u:
  case 2616u ... 2617u:
  case 2649u ... 2652u:
  case 2654u:
  case 2674u ... 2676u:
  case 2693u ... 2699u:
  case 2701u:
  case 2703u ... 2705u:
  case 2707u ... 2728u:
  case 2730u ... 2736u:
  case 2738u ... 2739u:
  case 2741u ... 2745u:
  case 2749u:
  case 2784u:
  case 2821u ... 2828u:
  case 2831u ... 2832u:
  case 2835u ... 2856u:
  case 2858u ... 2864u:
  case 2866u ... 2867u:
  case 2870u ... 2873u:
  case 2877u:
  case 2908u ... 2909u:
  case 2911u ... 2913u:
  case 2949u ... 2954u:
  case 2958u ... 2960u:
  case 2962u ... 2965u:
  case 2969u ... 2970u:
  case 2972u:
  case 2974u ... 2975u:
  case 2979u ... 2980u:
  case 2984u ... 2986u:
  case 2990u ... 2997u:
  case 2999u ... 3001u:
    return 1u;
    goto l45;
  default:
    return 0u;
    goto l45;
  }
l31:
  switch (i0) {
  case 1025u ... 1036u:
  case 1038u ... 1103u:
  case 1105u ... 1116u:
  case 1118u ... 1153u:
  case 1168u ... 1220u:
  case 1223u ... 1224u:
  case 1227u ... 1228u:
  case 1232u ... 1259u:
  case 1262u ... 1269u:
  case 1272u ... 1273u:
  case 1329u ... 1366u:
  case 1369u:
  case 1377u ... 1414u:
  case 1488u ... 1514u:
  case 1520u ... 1522u:
  case 1569u ... 1594u:
  case 1601u ... 1610u:
  case 1649u ... 1719u:
  case 1722u ... 1726u:
  case 1728u ... 1742u:
  case 1744u ... 1747u:
  case 1749u:
  case 1765u ... 1766u:
    return 1u;
    goto l45;
  default:
    return 0u;
    goto l45;
  }
l36:
  switch (i0) {
  case 256u ... 305u:
  case 308u ... 318u:
  case 321u ... 328u:
  case 330u ... 382u:
  case 384u ... 451u:
  case 461u ... 496u:
  case 500u ... 501u:
  case 506u ... 535u:
  case 592u ... 680u:
  case 699u ... 705u:
  case 902u:
  case 904u ... 906u:
  case 908u:
  case 910u ... 929u:
  case 931u ... 974u:
  case 976u ... 982u:
  case 986u:
  case 988u:
  case 990u:
  case 992u:
  case 994u ... 1011u:
    return 1u;
    goto l45;
  default:
    return 0u;
    goto l45;
  }
l41:
  switch (i0) {
  case 65u ... 90u:
  case 97u ... 122u:
  case 192u ... 214u:
  case 216u ... 246u:
  case 248u ... 255u:
    return 1u;
    goto l45;
  default:
    return 0u;
    goto l45;
  }
l45:
  _failed_function(9776); return 0;
  ;
}

static OOC_CHAR8 XML_Parser__IsIdeographic(OOC_CHAR16 ch) {
  register OOC_INT32 i0,i1;

  i0 = ch;
  i1 = (OOC_UINT16)19968u<=(OOC_UINT16)i0;
  if (i1) goto l3;
  i1=0u;
  goto l5;
l3:
  i1 = (OOC_UINT16)i0<=(OOC_UINT16)40869u;
  
l5:
  if (i1) goto l7;
  i1 = i0==12295u;
  
  goto l9;
l7:
  i1=1u;
l9:
  if (i1) goto l15;
  i1 = (OOC_UINT16)12321u<=(OOC_UINT16)i0;
  if (i1) goto l13;
  i0=0u;
  goto l16;
l13:
  i0 = (OOC_UINT16)i0<=(OOC_UINT16)12329u;
  
  goto l16;
l15:
  i0=1u;
l16:
  return i0;
  ;
}

static OOC_CHAR8 XML_Parser__IsCombiningChar(OOC_CHAR16 ch) {
  register OOC_INT32 i0,i1;

  i0 = ch;
  i1 = (OOC_UINT16)i0<(OOC_UINT16)768u;
  if (i1) goto l31;
  i1 = (OOC_UINT16)i0<(OOC_UINT16)2560u;
  if (i1) goto l26;
  i1 = (OOC_UINT16)i0<(OOC_UINT16)3328u;
  if (i1) goto l21;
  i1 = (OOC_UINT16)i0<(OOC_UINT16)4096u;
  if (i1) goto l16;
  i1 = (OOC_UINT16)i0<(OOC_UINT16)8192u;
  if (i1) goto l14;
  switch (i0) {
  case 8400u ... 8412u:
  case 8417u:
  case 12330u ... 12335u:
  case 12441u:
  case 12442u:
    return 1u;
    goto l32;
  default:
    return 0u;
    goto l32;
  }
l14:
  return 0u;
  goto l32;
l16:
  switch (i0) {
  case 3330u ... 3331u:
  case 3390u ... 3395u:
  case 3398u ... 3400u:
  case 3402u ... 3405u:
  case 3415u:
  case 3633u:
  case 3636u ... 3642u:
  case 3655u ... 3662u:
  case 3761u:
  case 3764u ... 3769u:
  case 3771u ... 3772u:
  case 3784u ... 3789u:
  case 3864u ... 3865u:
  case 3893u:
  case 3895u:
  case 3897u:
  case 3902u:
  case 3903u:
  case 3953u ... 3972u:
  case 3974u ... 3979u:
  case 3984u ... 3989u:
  case 3991u:
  case 3993u ... 4013u:
  case 4017u ... 4023u:
  case 4025u:
    return 1u;
    goto l32;
  default:
    return 0u;
    goto l32;
  }
l21:
  switch (i0) {
  case 2562u:
  case 2620u:
  case 2622u:
  case 2623u:
  case 2624u ... 2626u:
  case 2631u ... 2632u:
  case 2635u ... 2637u:
  case 2672u ... 2673u:
  case 2689u ... 2691u:
  case 2748u:
  case 2750u ... 2757u:
  case 2759u ... 2761u:
  case 2763u ... 2765u:
  case 2817u ... 2819u:
  case 2876u:
  case 2878u ... 2883u:
  case 2887u ... 2888u:
  case 2891u ... 2893u:
  case 2902u ... 2903u:
  case 2946u ... 2947u:
  case 3006u ... 3010u:
  case 3014u ... 3016u:
  case 3018u ... 3021u:
  case 3031u:
  case 3073u ... 3075u:
  case 3134u ... 3140u:
  case 3142u ... 3144u:
  case 3146u ... 3149u:
  case 3157u ... 3158u:
  case 3202u ... 3203u:
  case 3262u ... 3268u:
  case 3270u ... 3272u:
  case 3274u ... 3277u:
  case 3285u ... 3286u:
    return 1u;
    goto l32;
  default:
    return 0u;
    goto l32;
  }
l26:
  switch (i0) {
  case 768u ... 837u:
  case 864u ... 865u:
  case 1155u ... 1158u:
  case 1425u ... 1441u:
  case 1443u ... 1465u:
  case 1467u ... 1469u:
  case 1471u:
  case 1473u ... 1474u:
  case 1476u:
  case 1611u ... 1618u:
  case 1648u:
  case 1750u ... 1756u:
  case 1757u ... 1759u:
  case 1760u ... 1764u:
  case 1767u ... 1768u:
  case 1770u ... 1773u:
  case 2305u ... 2307u:
  case 2364u:
  case 2366u ... 2380u:
  case 2381u:
  case 2385u ... 2388u:
  case 2402u ... 2403u:
  case 2433u ... 2435u:
  case 2492u:
  case 2494u:
  case 2495u:
  case 2496u ... 2500u:
  case 2503u ... 2504u:
  case 2507u ... 2509u:
  case 2519u:
  case 2530u ... 2531u:
    return 1u;
    goto l32;
  default:
    return 0u;
    goto l32;
  }
l31:
  return 0u;
l32:
  _failed_function(13952); return 0;
  ;
}

static OOC_CHAR8 XML_Parser__IsExtender(OOC_CHAR16 ch) {
  register OOC_INT32 i0,i1;

  i0 = ch;
  i1 = i0==183u;
  if (i1) goto l10;
  i1 = (OOC_UINT16)i0>=(OOC_UINT16)720u;
  if (i1) goto l5;
  return 0u;
  goto l11;
l5:
  switch (i0) {
  case 720u:
  case 721u:
  case 903u:
  case 1600u:
  case 3654u:
  case 3782u:
  case 12293u:
  case 12337u ... 12341u:
  case 12445u ... 12446u:
  case 12540u ... 12542u:
    return 1u;
    goto l11;
  default:
    return 0u;
    goto l11;
  }
l10:
  return 1u;
l11:
  _failed_function(15990); return 0;
  ;
}

static OOC_CHAR8 XML_Parser__IsLetter(OOC_CHAR16 ch) {
  register OOC_INT32 i0,i1;

  i0 = ch;
  i1 = XML_Parser__IsBaseChar(i0);
  if (i1) goto l3;
  i0 = XML_Parser__IsIdeographic(i0);
  
  goto l4;
l3:
  i0=1u;
l4:
  return i0;
  ;
}

OOC_CHAR8 XML_Parser__IsNameChar(OOC_CHAR16 ch) {
  register OOC_INT32 i0,i1;

  i0 = ch;
  i1 = XML_Parser__IsLetter(i0);
  if (i1) goto l3;
  i1 = XML_Parser__IsDigit(i0);
  
  goto l5;
l3:
  i1=1u;
l5:
  if (i1) goto l7;
  i1 = i0==46u;
  
  goto l9;
l7:
  i1=1u;
l9:
  if (i1) goto l11;
  i1 = i0==45u;
  
  goto l13;
l11:
  i1=1u;
l13:
  if (i1) goto l15;
  i1 = i0==95u;
  
  goto l17;
l15:
  i1=1u;
l17:
  if (i1) goto l19;
  i1 = i0==58u;
  
  goto l21;
l19:
  i1=1u;
l21:
  if (i1) goto l23;
  i1 = XML_Parser__IsCombiningChar(i0);
  
  goto l25;
l23:
  i1=1u;
l25:
  if (i1) goto l27;
  i0 = XML_Parser__IsExtender(i0);
  
  goto l28;
l27:
  i0=1u;
l28:
  return i0;
  ;
}

OOC_CHAR8 XML_Parser__IsNameChar0(OOC_CHAR16 ch) {
  register OOC_INT32 i0,i1;

  i0 = ch;
  i1 = XML_Parser__IsLetter(i0);
  if (i1) goto l3;
  i1 = i0==95u;
  
  goto l5;
l3:
  i1=1u;
l5:
  if (i1) goto l7;
  i0 = i0==58u;
  
  goto l8;
l7:
  i0=1u;
l8:
  return i0;
  ;
}

static OOC_CHAR8 XML_Parser__IsPubidChar(OOC_CHAR16 ch) {
  register OOC_INT32 i0,i1,i2;

  i0 = ch;
  i1 = _cap(i0);
  i2 = (OOC_UINT16)65u<=(OOC_UINT16)i1;
  if (i2) goto l3;
  i1=0u;
  goto l5;
l3:
  i1 = (OOC_UINT16)i1<=(OOC_UINT16)90u;
  
l5:
  if (i1) goto l11;
  i1 = (OOC_UINT16)48u<=(OOC_UINT16)i0;
  if (i1) goto l9;
  i1=0u;
  goto l13;
l9:
  i1 = (OOC_UINT16)i0<=(OOC_UINT16)57u;
  
  goto l13;
l11:
  i1=1u;
l13:
  if (i1) goto l15;
  i1 = i0==32u;
  
  goto l17;
l15:
  i1=1u;
l17:
  if (i1) goto l19;
  i1 = i0==13u;
  
  goto l21;
l19:
  i1=1u;
l21:
  if (i1) goto l23;
  i1 = i0==10u;
  
  goto l25;
l23:
  i1=1u;
l25:
  if (i1) goto l44;
  i1 = *(OOC_UINT16*)((OOC_INT32)XML_Parser__suplPubidChar+(_check_index(0, 32, OOC_UINT32, 17141))*2);
  i1 = i1!=0u;
  if (i1) goto l29;
  i1=0u;
  goto l31;
l29:
  i1 = *(OOC_UINT16*)((OOC_INT32)XML_Parser__suplPubidChar+(_check_index(0, 32, OOC_UINT32, 17167))*2);
  i1 = i1!=i0;
  
l31:
  if (i1) goto l33;
  i0=0;
  goto l43;
l33:
  i1=0;
l34_loop:
  i1 = i1+1;
  i2 = *(OOC_UINT16*)((OOC_INT32)XML_Parser__suplPubidChar+(_check_index(i1, 32, OOC_UINT32, 17141))*2);
  i2 = i2!=0u;
  if (i2) goto l37;
  i2=0u;
  goto l39;
l37:
  i2 = *(OOC_UINT16*)((OOC_INT32)XML_Parser__suplPubidChar+(_check_index(i1, 32, OOC_UINT32, 17167))*2);
  i2 = i2!=i0;
  
l39:
  if (i2) goto l34_loop;
l42:
  i0=i1;
l43:
  i0 = *(OOC_UINT16*)((OOC_INT32)XML_Parser__suplPubidChar+(_check_index(i0, 32, OOC_UINT32, 17234))*2);
  return (i0!=0u);
  goto l45;
l44:
  return 1u;
l45:
  _failed_function(16859); return 0;
  ;
}

static OOC_CHAR8 XML_Parser__IsVersionNumChar(OOC_CHAR16 ch) {
  register OOC_INT32 i0,i1,i2;

  i0 = ch;
  i1 = _cap(i0);
  i2 = (OOC_UINT16)65u<=(OOC_UINT16)i1;
  if (i2) goto l3;
  i1=0u;
  goto l5;
l3:
  i1 = (OOC_UINT16)i1<=(OOC_UINT16)90u;
  
l5:
  if (i1) goto l11;
  i1 = (OOC_UINT16)48u<=(OOC_UINT16)i0;
  if (i1) goto l9;
  i1=0u;
  goto l13;
l9:
  i1 = (OOC_UINT16)i0<=(OOC_UINT16)57u;
  
  goto l13;
l11:
  i1=1u;
l13:
  if (i1) goto l15;
  i1 = i0==95u;
  
  goto l17;
l15:
  i1=1u;
l17:
  if (i1) goto l19;
  i1 = i0==46u;
  
  goto l21;
l19:
  i1=1u;
l21:
  if (i1) goto l23;
  i1 = i0==58u;
  
  goto l25;
l23:
  i1=1u;
l25:
  if (i1) goto l27;
  i0 = i0==45u;
  
  goto l28;
l27:
  i0=1u;
l28:
  return i0;
  ;
}

static OOC_CHAR8 XML_Parser__IsEncNameChar(OOC_CHAR16 ch, OOC_CHAR8 first) {
  register OOC_INT32 i0,i1,i2;

  i0 = ch;
  i1 = _cap(i0);
  i2 = (OOC_UINT16)65u<=(OOC_UINT16)i1;
  if (i2) goto l3;
  i1=0u;
  goto l5;
l3:
  i1 = (OOC_UINT16)i1<=(OOC_UINT16)90u;
  
l5:
  if (i1) goto l27;
  i1 = first;
  i1 = !i1;
  if (i1) goto l9;
  return 0u;
  goto l28;
l9:
  i1 = (OOC_UINT16)48u<=(OOC_UINT16)i0;
  if (i1) goto l12;
  i1=0u;
  goto l14;
l12:
  i1 = (OOC_UINT16)i0<=(OOC_UINT16)57u;
  
l14:
  if (i1) goto l16;
  i1 = i0==46u;
  
  goto l18;
l16:
  i1=1u;
l18:
  if (i1) goto l20;
  i1 = i0==95u;
  
  goto l22;
l20:
  i1=1u;
l22:
  if (i1) goto l24;
  i0 = i0==45u;
  
  goto l25;
l24:
  i0=1u;
l25:
  return i0;
  goto l28;
l27:
  return 1u;
l28:
  _failed_function(17526); return 0;
  ;
}

static void XML_Parser__SetBaseURI(Msg__Msg err, const OOC_CHAR8 name__ref[], OOC_LEN name_0d, URI__URI uri) {
  register OOC_INT32 i0,i1;
  OOC_ALLOCATE_VPAR(name,OOC_CHAR8 ,name_0d)
  Object__String str;
  Object__String8 str8;
  Object__CharsLatin1 chars;

  OOC_INITIALIZE_VPAR(name__ref,name,OOC_CHAR8 ,name_0d)
  i0 = (OOC_INT32)uri;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 18090)))), URI__URIDesc_ToString)),URI__URIDesc_ToString)((URI__URI)i0);
  str = (Object__String)i0;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 18118)))), Object__StringDesc_ToString8)),Object__StringDesc_ToString8)((Object__String)i0, 63u);
  str8 = (Object__String8)i0;
  i0 = (OOC_INT32)Object__String8Desc_CharsLatin1((Object__String8)i0);
  chars = (Object__CharsLatin1)i0;
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 18220)), 0);
  i0 = (OOC_INT32)Msg__GetStringPtr((void*)(_check_pointer(i0, 18220)), i1);
  i1 = (OOC_INT32)err;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 18175)))), Msg__MsgDesc_SetStringAttrib)),Msg__MsgDesc_SetStringAttrib)((Msg__Msg)i1, (void*)(OOC_INT32)name, name_0d, (Msg__StringPtr)i0);
  return;
  ;
}

Msg__Msg XML_Parser__ErrorListenerDesc_Error(XML_Parser__ErrorListener el, XML_Error__Context context, OOC_INT32 code, OOC_CHAR8 fatalError, const struct XML_Locator__Position *pos__ref) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_ALLOCATE_VPAR(pos,XML_Locator__Position ,1)
  XML_Parser__Parser p;
  Msg__Msg err;

  OOC_INITIALIZE_VPAR(pos__ref,pos,XML_Locator__Position ,20)
  i0 = (OOC_INT32)el;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 18516));
  p = (XML_Parser__Parser)i0;
  i1 = (OOC_INT32)context;
  i2 = code;
  i1 = (OOC_INT32)XML_Error__New((XML_Error__Context)i1, i2);
  err = (Msg__Msg)i1;
  i2 = *(OOC_INT32*)(OOC_INT32)pos;
  i3 = XML_Error__errMsgCharPosBase;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 18566)))), Msg__MsgDesc_SetIntAttrib)),Msg__MsgDesc_SetIntAttrib)((Msg__Msg)i1, "char", 5, (i2+i3));
  i2 = *(OOC_INT32*)((OOC_INT32)pos+4);
  i3 = XML_Error__errMsgLineBase;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 18638)))), Msg__MsgDesc_SetIntAttrib)),Msg__MsgDesc_SetIntAttrib)((Msg__Msg)i1, "line", 5, (i2+i3));
  i2 = *(OOC_INT32*)((OOC_INT32)pos+8);
  i3 = XML_Error__errMsgColumnBase;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 18702)))), Msg__MsgDesc_SetIntAttrib)),Msg__MsgDesc_SetIntAttrib)((Msg__Msg)i1, "column", 7, (i2+i3));
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18797))+56);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 18808))+36);
  XML_Parser__SetBaseURI((Msg__Msg)i1, "baseURI", 8, (URI__URI)i2);
  i2 = (OOC_INT32)*(OOC_INT32*)((OOC_INT32)pos+16);
  i3 = i2!=0;
  if (!i3) goto l3;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 18974))+4);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 18974))+4);
  i3 = OOC_ARRAY_LENGTH((_check_pointer(i3, 18980)), 0);
  i2 = (OOC_INT32)Msg__GetLStringPtr((void*)(_check_pointer(i2, 18980)), i3);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 18870)))), Msg__MsgDesc_SetLStringAttrib)),Msg__MsgDesc_SetLStringAttrib)((Msg__Msg)i1, "entity_name", 12, (Msg__LStringPtr)i2);
l3:
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 18998));
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 18998));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 19007)))), Msg__MsgListDesc_Append)),Msg__MsgListDesc_Append)((Msg__MsgList)i3, (Msg__Msg)i1);
  i2 = fatalError;
  if (i2) goto l6;
  i2=0u;
  goto l8;
l6:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19058))+40);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19045))+44);
  i2 = i3==i2;
  
l8:
  if (!i2) goto l10;
  i2 = (OOC_INT32)XML_Builder__New();
  *(OOC_INT32*)((_check_pointer(i0, 19088))+44) = i2;
l10:
  return (Msg__Msg)i1;
  ;
}

void XML_Parser__ParserDesc_ParseDocument(XML_Parser__Parser p) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  XML_UnicodeBuffer__CharArray chars;
  XML_DTD__Builder dtd;
  OOC_INT32 cpos;
  OOC_INT32 cstart;
  OOC_INT32 cdelta;
  auto void XML_Parser__ParserDesc_ParseDocument_DecLength(struct XML_Locator__Position *pos, RT0__Struct pos__tag, OOC_INT32 len);
  auto void XML_Parser__ParserDesc_ParseDocument_StorePosition(struct XML_Locator__Position *pos, RT0__Struct pos__tag);
  auto void XML_Parser__ParserDesc_ParseDocument_ResetLocator(void);
  auto void XML_Parser__ParserDesc_ParseDocument_SetFileEntity(XML_DTD__ExternalEntity _new);
  auto void XML_Parser__ParserDesc_ParseDocument_ErrPosNF(OOC_INT32 code, struct XML_Locator__Position *pos, RT0__Struct pos__tag);
  auto void XML_Parser__ParserDesc_ParseDocument_ErrPos(OOC_INT32 code, struct XML_Locator__Position *pos, RT0__Struct pos__tag);
  auto void XML_Parser__ParserDesc_ParseDocument_WriteBuffer(const OOC_CHAR8 msg__ref[], OOC_LEN msg_0d);
  auto void XML_Parser__ParserDesc_ParseDocument_ErrNF(OOC_INT32 code);
  auto void XML_Parser__ParserDesc_ParseDocument_Err(OOC_INT32 code);
  auto XML_UnicodeBuffer__CharArray XML_Parser__ParserDesc_ParseDocument_Clone(XML_UnicodeBuffer__CharArray string);
  auto XML_UnicodeBuffer__CharArray XML_Parser__ParserDesc_ParseDocument_GetString(OOC_INT32 start, OOC_INT32 end);
  auto XML_UnicodeBuffer__Input XML_Parser__ParserDesc_ParseDocument_GetBuffer(XML_DTD__ExternalEntity entity);
  auto void XML_Parser__ParserDesc_ParseDocument_CheckInvalidChars(void);
  auto XML_UnicodeBuffer__CharArray XML_Parser__ParserDesc_ParseDocument_Internalize(XML_DTD__ExternalEntity entity);
  auto void XML_Parser__ParserDesc_ParseDocument_PushEntity(XML_DTD__Entity entity, OOC_CHAR8 syncEntity);
  auto void XML_Parser__ParserDesc_ParseDocument_PopEntity(void);
  auto void XML_Parser__ParserDesc_ParseDocument_NextBlock(void);
  auto void XML_Parser__ParserDesc_ParseDocument_DiscardPreviousInput(void);
  auto void XML_Parser__ParserDesc_ParseDocument_EndOfLine(void);
  auto void XML_Parser__ParserDesc_ParseDocument_Tab(void);
  auto OOC_CHAR8 XML_Parser__ParserDesc_ParseDocument_LookingAtS(void);
  auto OOC_CHAR8 XML_Parser__ParserDesc_ParseDocument_LookingAtSnoPE(void);
  auto OOC_CHAR8 XML_Parser__ParserDesc_ParseDocument_LookingAt(const OOC_CHAR8 str__ref[], OOC_LEN str_0d, OOC_INT8 followedBy);
  auto void XML_Parser__ParserDesc_ParseDocument_NextChar(void);
  auto XML_UnicodeBuffer__CharArray XML_Parser__ParserDesc_ParseDocument_Nmtoken(OOC_CHAR8 checkForQName, OOC_CHAR8 noColon);
  auto XML_UnicodeBuffer__CharArray XML_Parser__ParserDesc_ParseDocument_Name(OOC_CHAR8 noColon);
  auto void XML_Parser__ParserDesc_ParseDocument_CheckChar(OOC_CHAR8 ch);
  auto void XML_Parser__ParserDesc_ParseDocument_XMLDecl(XML_DTD__ExternalEntity entity);
  auto void XML_Parser__ParserDesc_ParseDocument_extSubsetDecl(void);
  auto void XML_Parser__ParserDesc_ParseDocument_SkippedEntity(XML_UnicodeBuffer__CharArray name);
  auto void XML_Parser__ParserDesc_ParseDocument_PEReference(OOC_CHAR8 declSep);
  auto void XML_Parser__ParserDesc_ParseDocument_OptS(OOC_CHAR8 noPE);
  auto void XML_Parser__ParserDesc_ParseDocument_S(void);
  auto void XML_Parser__ParserDesc_ParseDocument_SnoPE(void);
  auto void XML_Parser__ParserDesc_ParseDocument_ControlChar(OOC_CHAR16 eolReplacement);
  auto XML_UnicodeBuffer__CharArray XML_Parser__ParserDesc_ParseDocument_String(OOC_INT8 type);
  auto void XML_Parser__ParserDesc_ParseDocument_Eq(void);
  auto void XML_Parser__ParserDesc_ParseDocument_XMLDecl(XML_DTD__ExternalEntity entity);
  auto XML_DTD__Entity XML_Parser__ParserDesc_ParseDocument_CurrentEntity(void);
  auto void XML_Parser__ParserDesc_ParseDocument_CheckCurrentEntity(XML_DTD__Entity reference);
  auto void XML_Parser__ParserDesc_ParseDocument_PI(void);
  auto void XML_Parser__ParserDesc_ParseDocument_Comment(void);
  auto void XML_Parser__ParserDesc_ParseDocument_CDSect(void);
  auto void XML_Parser__ParserDesc_ParseDocument_CharRef(void);
  auto XML_DTD__EntityRef XML_Parser__ParserDesc_ParseDocument_EntityRef(OOC_CHAR8 enforceDecl, OOC_CHAR8 permitExternal);
  auto XML_DTD__AttValue XML_Parser__ParserDesc_ParseDocument_AttValue(OOC_CHAR8 isAttDecl);
  auto void XML_Parser__ParserDesc_ParseDocument_Expand(XML_DTD__AttValue attValue);
  auto void XML_Parser__ParserDesc_ParseDocument_element(void);
  auto void XML_Parser__ParserDesc_ParseDocument_content(void);
  auto void XML_Parser__ParserDesc_ParseDocument_element(void);
  auto void XML_Parser__ParserDesc_ParseDocument_MiscRep(void);
  auto void XML_Parser__ParserDesc_ParseDocument_ExternalID(OOC_CHAR8 optionJustPubid, XML_UnicodeBuffer__CharArray *_public, XML_UnicodeBuffer__CharArray *system, URI__URI *baseURI);
  auto void XML_Parser__ParserDesc_ParseDocument_markupdecl(void);
  auto void XML_Parser__ParserDesc_ParseDocument_extSubsetDecl(void);
  auto void XML_Parser__ParserDesc_ParseDocument_prolog(void);
    
    void XML_Parser__ParserDesc_ParseDocument_DecLength(struct XML_Locator__Position *pos, RT0__Struct pos__tag, OOC_INT32 len) {
      register OOC_INT32 i0,i1,i2;

      i0 = *(OOC_INT32*)(OOC_INT32)pos;
      i1 = len;
      *(OOC_INT32*)(OOC_INT32)pos = (i0-i1);
      i0 = (OOC_INT32)pos+8;
      i2 = *(OOC_INT32*)i0;
      *(OOC_INT32*)i0 = (i2-i1);
      return;
      ;
    }

    
    void XML_Parser__ParserDesc_ParseDocument_StorePosition(struct XML_Locator__Position *pos, RT0__Struct pos__tag) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5;
      OOC_INT32 i;

      i0 = (OOC_INT32)p;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21555))+36);
      i1 = i1!=(OOC_INT32)0;
      if (i1) goto l3;
      i1=0u;
      goto l5;
l3:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21579))+36);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 21583))+20);
      i2 = (OOC_INT32)chars;
      i1 = i2==i1;
      
l5:
      if (i1) goto l23;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21911))+36);
      i1 = i1==(OOC_INT32)0;
      if (i1) goto l18;
      i1 = *(OOC_INT32*)((_check_pointer(i0, 21974))+88);
      i1 = i1-1;
      i = i1;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22008))+84);
      i2 = _check_pointer(i2, 22017);
      i3 = OOC_ARRAY_LENGTH(i2, 0);
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22034))+36);
      i2 = (OOC_INT32)*(OOC_INT32*)(i2+((_check_index(i1, i3, OOC_UINT32, 22017))*28));
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 22038))+20);
      i2 = i2!=i3;
      if (!i2) goto l19;
l12_loop:
      i1 = i1-1;
      i = i1;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22008))+84);
      i2 = _check_pointer(i2, 22017);
      i3 = OOC_ARRAY_LENGTH(i2, 0);
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22034))+36);
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 22038))+20);
      i2 = (OOC_INT32)*(OOC_INT32*)(i2+((_check_index(i1, i3, OOC_UINT32, 22017))*28));
      i2 = i2!=i4;
      if (i2) goto l12_loop;
      goto l19;
l18:
      i = 0;
      i1=0;
l19:
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22124))+84);
      i2 = _check_pointer(i2, 22133);
      i3 = OOC_ARRAY_LENGTH(i2, 0);
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22147))+84);
      i4 = _check_pointer(i4, 22156);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      i4 = (OOC_INT32)*(OOC_INT32*)((i4+((_check_index(i1, i5, OOC_UINT32, 22156))*28))+24);
      i2 = *(OOC_INT32*)((i2+((_check_index(i1, i3, OOC_UINT32, 22133))*28))+4);
      i3 = *(OOC_INT32*)((_check_pointer(i4, 22163))+24);
      *(OOC_INT32*)(OOC_INT32)pos = (i2+i3);
      i2 = *(OOC_INT32*)((_check_pointer(i0, 22203))+92);
      *(OOC_INT32*)((OOC_INT32)pos+4) = i2;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22239))+84);
      i2 = _check_pointer(i2, 22248);
      i3 = OOC_ARRAY_LENGTH(i2, 0);
      i2 = *(OOC_INT32*)((i2+((_check_index(i1, i3, OOC_UINT32, 22248))*28))+4);
      i3 = *(OOC_INT32*)((_check_pointer(i0, 22288))+96);
      i4 = *(OOC_INT32*)((_check_pointer(i0, 22303))+100);
      *(OOC_INT32*)((OOC_INT32)pos+8) = ((i2-i3)+i4);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22331))+84);
      i2 = _check_pointer(i2, 22340);
      i3 = OOC_ARRAY_LENGTH(i2, 0);
      i2 = (OOC_INT32)*(OOC_INT32*)((i2+((_check_index(i1, i3, OOC_UINT32, 22340))*28))+20);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 22351))+4);
      i2 = i2!=(OOC_INT32)0;
      if (!i2) goto l24;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22417))+84);
      i2 = _check_pointer(i2, 22426);
      i3 = OOC_ARRAY_LENGTH(i2, 0);
      i2 = (OOC_INT32)*(OOC_INT32*)((i2+((_check_index(i1, i3, OOC_UINT32, 22426))*28))+20);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 22437))+4);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22417))+84);
      i0 = _check_pointer(i0, 22426);
      i3 = OOC_ARRAY_LENGTH(i0, 0);
      i0 = (OOC_INT32)*(OOC_INT32*)((i0+((_check_index(i1, i3, OOC_UINT32, 22426))*28))+20);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22437))+4);
      i1 = OOC_ARRAY_LENGTH((_check_pointer(i2, 22443)), 0);
      i0 = LongStrings__Length((void*)(_check_pointer(i0, 22443)), i1);
      XML_Parser__ParserDesc_ParseDocument_DecLength((void*)(OOC_INT32)pos, (RT0__Struct)((OOC_INT32)pos__tag), (i0+2));
      goto l24;
l23:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21629))+36);
      i1 = *(OOC_INT32*)((_check_pointer(i1, 21633))+24);
      i2 = cpos;
      *(OOC_INT32*)(OOC_INT32)pos = (i2+i1);
      i1 = *(OOC_INT32*)((_check_pointer(i0, 21673))+92);
      *(OOC_INT32*)((OOC_INT32)pos+4) = i1;
      i1 = *(OOC_INT32*)((_check_pointer(i0, 21714))+96);
      i0 = *(OOC_INT32*)((_check_pointer(i0, 21729))+100);
      *(OOC_INT32*)((OOC_INT32)pos+8) = ((i2-i1)+i0);
l24:
      return;
      ;
    }

    
    void XML_Parser__ParserDesc_ParseDocument_ResetLocator(void) {
      register OOC_INT32 i0;

      i0 = (OOC_INT32)p;
      *(OOC_INT32*)((_check_pointer(i0, 22540))+92) = 0;
      *(OOC_INT32*)((_check_pointer(i0, 22564))+96) = 0;
      *(OOC_INT32*)((_check_pointer(i0, 22591))+100) = 0;
      cpos = 0;
      cdelta = 0;
      cstart = 0;
      return;
      ;
    }

    
    void XML_Parser__ParserDesc_ParseDocument_SetFileEntity(XML_DTD__ExternalEntity _new) {
      register OOC_INT32 i0,i1;

      i0 = (OOC_INT32)p;
      i1 = (OOC_INT32)_new;
      *(OOC_INT32*)((_check_pointer(i0, 22760))+56) = i1;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22788))+4);
      *(OOC_INT32*)((_check_pointer(i0, 22791))+12) = i1;
      return;
      ;
    }

    
    void XML_Parser__ParserDesc_ParseDocument_ErrPosNF(OOC_INT32 code, struct XML_Locator__Position *pos, RT0__Struct pos__tag) {
      register OOC_INT32 i0,i1,i2,i3;
      OOC_INT32 i;

      i0 = (OOC_INT32)p;
      i1 = (OOC_INT32)XML_Parser__parserContext;
      i2 = code;
      i1 = (OOC_INT32)XML_Error__New((XML_Error__Context)i1, i2);
      *(OOC_INT32*)((_check_pointer(i0, 22948))+104) = i1;
      i0 = (OOC_INT32)p;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23003))+104);
      i2 = *(OOC_INT32*)(OOC_INT32)pos;
      i3 = XML_Error__errMsgCharPosBase;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23003))+104);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 23014)))), Msg__MsgDesc_SetIntAttrib)),Msg__MsgDesc_SetIntAttrib)((Msg__Msg)i0, "char", 5, (i2+i3));
      i0 = (OOC_INT32)p;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23086))+104);
      i2 = *(OOC_INT32*)((OOC_INT32)pos+4);
      i3 = XML_Error__errMsgLineBase;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23086))+104);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 23097)))), Msg__MsgDesc_SetIntAttrib)),Msg__MsgDesc_SetIntAttrib)((Msg__Msg)i0, "line", 5, (i2+i3));
      i0 = (OOC_INT32)p;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23161))+104);
      i2 = *(OOC_INT32*)((OOC_INT32)pos+8);
      i3 = XML_Error__errMsgColumnBase;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23161))+104);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 23172)))), Msg__MsgDesc_SetIntAttrib)),Msg__MsgDesc_SetIntAttrib)((Msg__Msg)i0, "column", 7, (i2+i3));
      i0 = (OOC_INT32)p;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23277))+56);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 23288))+36);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23253))+104);
      XML_Parser__SetBaseURI((Msg__Msg)i0, "baseURI", 8, (URI__URI)i1);
      i0 = (OOC_INT32)p;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23318))+36);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 23322))+20);
      i2 = (OOC_INT32)chars;
      i1 = i2!=i1;
      if (!i1) goto l4;
      i1 = *(OOC_INT32*)((_check_pointer(i0, 23350))+88);
      i1 = i1-1;
      i = i1;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23472))+84);
      i2 = _check_pointer(i2, 23481);
      i3 = OOC_ARRAY_LENGTH(i2, 0);
      i2 = (OOC_INT32)*(OOC_INT32*)((i2+((_check_index(i1, i3, OOC_UINT32, 23481))*28))+20);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 23492))+4);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23472))+84);
      i0 = _check_pointer(i0, 23481);
      i3 = OOC_ARRAY_LENGTH(i0, 0);
      i0 = (OOC_INT32)*(OOC_INT32*)((i0+((_check_index(i1, i3, OOC_UINT32, 23481))*28))+20);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23492))+4);
      i1 = OOC_ARRAY_LENGTH((_check_pointer(i2, 23498)), 0);
      i0 = (OOC_INT32)Msg__GetLStringPtr((void*)(_check_pointer(i0, 23498)), i1);
      i1 = (OOC_INT32)p;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 23375))+104);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 23375))+104);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 23386)))), Msg__MsgDesc_SetLStringAttrib)),Msg__MsgDesc_SetLStringAttrib)((Msg__Msg)i1, "entity_name", 12, (Msg__LStringPtr)i0);
l4:
      i0 = (OOC_INT32)p;
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 23520));
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23540))+104);
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 23520));
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 23529)))), Msg__MsgListDesc_Append)),Msg__MsgListDesc_Append)((Msg__MsgList)i0, (Msg__Msg)i2);
      return;
      ;
    }

    
    void XML_Parser__ParserDesc_ParseDocument_ErrPos(OOC_INT32 code, struct XML_Locator__Position *pos, RT0__Struct pos__tag) {
      register OOC_INT32 i0,i1,i2;

      i0 = code;
      XML_Parser__ParserDesc_ParseDocument_ErrPosNF(i0, (void*)(OOC_INT32)pos, (RT0__Struct)((OOC_INT32)pos__tag));
      i0 = (OOC_INT32)p;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23689))+44);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23702))+40);
      i1 = i1==i2;
      if (!i1) goto l4;
      i1 = (OOC_INT32)XML_Builder__New();
      *(OOC_INT32*)((_check_pointer(i0, 23734))+44) = i1;
l4:
      return;
      ;
    }

    
    void XML_Parser__ParserDesc_ParseDocument_WriteBuffer(const OOC_CHAR8 msg__ref[], OOC_LEN msg_0d) {
      register OOC_INT32 i0,i1,i2,i3,i4;
      OOC_ALLOCATE_VPAR(msg,OOC_CHAR8 ,msg_0d)
      OOC_INT32 end;
      OOC_INT32 i;

      i0 = cpos;
      i1 = i0+80;
      OOC_INITIALIZE_VPAR(msg__ref,msg,OOC_CHAR8 ,msg_0d)
      end = i1;
      i = i0;
      Out__Ln();
      Out__String("### buffer contents ", 21);
      Out__String((void*)(OOC_INT32)msg, msg_0d);
      Out__String(" ###", 5);
      Out__Ln();
      i2 = (OOC_INT32)chars;
      i2 = _check_pointer(i2, 24063);
      i3 = OOC_ARRAY_LENGTH(i2, 0);
      i2 = *(OOC_UINT16*)(i2+(_check_index(i0, i3, OOC_UINT32, 24063))*2);
      i2 = (OOC_UINT16)i2<(OOC_UINT16)65534u;
      if (i2) goto l3;
      i2=0u;
      goto l5;
l3:
      i2 = i0<=i1;
      
l5:
      if (!i2) goto l20;
l7_loop:
      i2 = (OOC_INT32)chars;
      i3 = _check_pointer(i2, 24120);
      i4 = OOC_ARRAY_LENGTH(i3, 0);
      i3 = *(OOC_UINT16*)(i3+(_check_index(i0, i4, OOC_UINT32, 24120))*2);
      i3 = (OOC_UINT16)i3>(OOC_UINT16)255u;
      if (i3) goto l10;
      i2 = _check_pointer(i2, 24205);
      i3 = OOC_ARRAY_LENGTH(i2, 0);
      i2 = *(OOC_UINT16*)(i2+(_check_index(i0, i3, OOC_UINT32, 24205))*2);
      Out__Char(i2);
      goto l11;
l10:
      Out__Char(63u);
l11:
      i0 = i0+1;
      i = i0;
      i2 = (OOC_INT32)chars;
      i2 = _check_pointer(i2, 24063);
      i3 = OOC_ARRAY_LENGTH(i2, 0);
      i2 = *(OOC_UINT16*)(i2+(_check_index(i0, i3, OOC_UINT32, 24063))*2);
      i2 = (OOC_UINT16)i2<(OOC_UINT16)65534u;
      if (i2) goto l14;
      i2=0u;
      goto l16;
l14:
      i2 = i0<=i1;
      
l16:
      if (i2) goto l7_loop;
l20:
      Out__Ln();
      return;
      ;
    }

    
    void XML_Parser__ParserDesc_ParseDocument_ErrNF(OOC_INT32 code) {
      register OOC_INT32 i0,i1,i2;

      i0 = (OOC_INT32)p;
      i1 = _check_pointer(i0, 24423);
      i1 = (OOC_INT32)&_td_XML_Locator__Position;
      XML_Parser__ParserDesc_ParseDocument_StorePosition((void*)((_check_pointer(i0, 24423))+12), (RT0__Struct)i1);
      i0 = (OOC_INT32)p;
      i2 = _check_pointer(i0, 24459);
      i2 = code;
      XML_Parser__ParserDesc_ParseDocument_ErrPosNF(i2, (void*)((_check_pointer(i0, 24459))+12), (RT0__Struct)i1);
      return;
      ;
    }

    
    void XML_Parser__ParserDesc_ParseDocument_Err(OOC_INT32 code) {
      register OOC_INT32 i0,i1,i2;

      i0 = code;
      XML_Parser__ParserDesc_ParseDocument_ErrNF(i0);
      i0 = (OOC_INT32)p;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24566))+44);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24579))+40);
      i1 = i1==i2;
      if (!i1) goto l4;
      i1 = (OOC_INT32)XML_Builder__New();
      *(OOC_INT32*)((_check_pointer(i0, 24611))+44) = i1;
l4:
      return;
      ;
    }

    
    XML_UnicodeBuffer__CharArray XML_Parser__ParserDesc_ParseDocument_Clone(XML_UnicodeBuffer__CharArray string) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7;
      XML_UnicodeBuffer__CharArray clone;
      OOC_INT32 i;

      i0 = (OOC_INT32)string;
      i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 24888)), 0);
      i1 = (OOC_INT32)RT0__NewObject(_td_XML_UnicodeBuffer__CharArray.baseTypes[0], i1);
      clone = (XML_UnicodeBuffer__CharArray)i1;
      i = 0;
      i2 = OOC_ARRAY_LENGTH((_check_pointer(i0, 24924)), 0);
      i3 = 0<i2;
      if (!i3) goto l8;
      i3=0;
l3_loop:
      i4 = _check_pointer(i1, 24945);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      i6 = _check_pointer(i0, 24958);
      i7 = OOC_ARRAY_LENGTH(i6, 0);
      i6 = *(OOC_UINT16*)(i6+(_check_index(i3, i7, OOC_UINT32, 24958))*2);
      *(OOC_UINT16*)(i4+(_check_index(i3, i5, OOC_UINT32, 24945))*2) = i6;
      i3 = i3+1;
      i = i3;
      i4 = i3<i2;
      if (i4) goto l3_loop;
l8:
      return (XML_UnicodeBuffer__CharArray)i1;
      ;
    }

    
    XML_UnicodeBuffer__CharArray XML_Parser__ParserDesc_ParseDocument_GetString(OOC_INT32 start, OOC_INT32 end) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8;
      XML_UnicodeBuffer__CharArray string;
      OOC_INT32 i;

      i0 = end;
      i1 = start;
      i2 = (OOC_INT32)RT0__NewObject(_td_XML_UnicodeBuffer__CharArray.baseTypes[0], ((i0-i1)+1));
      string = (XML_UnicodeBuffer__CharArray)i2;
      i = 0;
      i3 = i1!=i0;
      if (i3) goto l3;
      i0=0;
      goto l9;
l3:
      i3 = (OOC_INT32)chars;
      i4=i1;i1=0;
l4_loop:
      i5 = _check_pointer(i2, 25227);
      i6 = OOC_ARRAY_LENGTH(i5, 0);
      i7 = _check_pointer(i3, 25239);
      i8 = OOC_ARRAY_LENGTH(i7, 0);
      i7 = *(OOC_UINT16*)(i7+(_check_index(i4, i8, OOC_UINT32, 25239))*2);
      *(OOC_UINT16*)(i5+(_check_index(i1, i6, OOC_UINT32, 25227))*2) = i7;
      i4 = i4+1;
      start = i4;
      i1 = i1+1;
      i = i1;
      i5 = i4!=i0;
      if (i5) goto l4_loop;
l8:
      i0=i1;
l9:
      i1 = _check_pointer(i2, 25300);
      i3 = OOC_ARRAY_LENGTH(i1, 0);
      *(OOC_UINT16*)(i1+(_check_index(i0, i3, OOC_UINT32, 25300))*2) = 0u;
      return (XML_UnicodeBuffer__CharArray)i2;
      ;
    }

    
    XML_UnicodeBuffer__Input XML_Parser__ParserDesc_ParseDocument_GetBuffer(XML_DTD__ExternalEntity entity) {
      register OOC_INT32 i0,i1,i2;
      IO__ByteChannel ch;
      XML_UnicodeBuffer__Input in;

      i0 = (OOC_INT32)entity;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25521))+36);
      i1 = i1==(OOC_INT32)0;
      if (i1) goto l3;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25593))+36);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25593))+36);
      i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 25602)))), URI__URIDesc_GetChannel)),URI__URIDesc_GetChannel)((URI__URI)i2, 2);
      ch = (IO__ByteChannel)i1;
      i2 = (OOC_INT32)p;
      i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 25674));
      i1 = (OOC_INT32)XML_UnicodeBuffer__NewInput((IO__ByteChannel)i1, (XML_UnicodeCodec__Factory)(OOC_INT32)0, (Msg__MsgList)i2);
      in = (XML_UnicodeBuffer__Input)i1;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 25721))+8);
      XML_DTD__ExternalEntityDesc_SetCodecFactory((XML_DTD__ExternalEntity)i0, (XML_UnicodeCodec__Factory)i2);
      return (XML_UnicodeBuffer__Input)i1;
      goto l4;
l3:
      return (XML_UnicodeBuffer__Input)(OOC_INT32)0;
l4:
      _failed_function(25365); return 0;
      ;
    }

    
    void XML_Parser__ParserDesc_ParseDocument_CheckInvalidChars(void) {
      register OOC_INT32 i0,i1,i2;

      i0 = (OOC_INT32)p;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25840))+36);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25844))+12);
      i0 = *(OOC_INT32*)(_check_pointer(i0, 25851));
      i0 = i0!=0;
      if (!i0) goto l4;
      XML_Parser__ParserDesc_ParseDocument_Err(27);
      i0 = (OOC_INT32)p;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25957))+56);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25937))+104);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 25968))+36);
      XML_Parser__SetBaseURI((Msg__Msg)i0, "uri", 4, (URI__URI)i1);
      i0 = (OOC_INT32)p;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 26029))+36);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 26033))+12);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25988))+104);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25988))+104);
      i1 = *(OOC_INT32*)(_check_pointer(i1, 26040));
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 25999)))), Msg__MsgDesc_SetIntAttrib)),Msg__MsgDesc_SetIntAttrib)((Msg__Msg)i0, "encodings", 10, i1);
l4:
      return;
      ;
    }

    
    XML_UnicodeBuffer__CharArray XML_Parser__ParserDesc_ParseDocument_Internalize(XML_DTD__ExternalEntity entity) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8;
      XML_UnicodeBuffer__Input in;
      OOC_INT32 len;
      OOC_INT32 i;
      OOC_INT32 delta;
      XML_UnicodeBuffer__CharArray str;

      i0 = (OOC_INT32)entity;
      i1 = (OOC_INT32)XML_Parser__ParserDesc_ParseDocument_GetBuffer((XML_DTD__ExternalEntity)i0);
      in = (XML_UnicodeBuffer__Input)i1;
      i2 = i1!=(OOC_INT32)0;
      if (i2) goto l3;
      i1 = (OOC_INT32)RT0__NewObject(_td_XML_UnicodeBuffer__CharArray.baseTypes[0], 2);
      str = (XML_UnicodeBuffer__CharArray)i1;
      len = 0;
      i2=0;
      goto l36;
l3:
      i2 = XML_UnicodeBuffer__InputDesc_NextBlock((XML_UnicodeBuffer__Input)i1);
      if (!i2) goto l10;
l5_loop:
      i2 = XML_UnicodeBuffer__InputDesc_NextBlock((XML_UnicodeBuffer__Input)i1);
      if (i2) goto l5_loop;
l10:
      i2 = *(OOC_INT32*)((_check_pointer(i1, 26434))+28);
      len = i2;
      i = 0;
      delta = 0;
      i3 = 0!=i2;
      if (i3) goto l13;
      i3=0;
      goto l27;
l13:
      i3=0;i4=0;
l14_loop:
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 26521))+20);
      i5 = _check_pointer(i5, 26528);
      i6 = OOC_ARRAY_LENGTH(i5, 0);
      i5 = *(OOC_UINT16*)(i5+(_check_index(i3, i6, OOC_UINT32, 26528))*2);
      switch (i5) {
      case 13u:
        i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 26571))+20);
        i5 = _check_pointer(i5, 26578);
        i6 = OOC_ARRAY_LENGTH(i5, 0);
        *(OOC_UINT16*)(i5+(_check_index((i3-i4), i6, OOC_UINT32, 26578))*2) = 10u;
        i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 26619))+20);
        i5 = _check_pointer(i5, 26626);
        i6 = OOC_ARRAY_LENGTH(i5, 0);
        i7 = i3+1;
        i5 = *(OOC_UINT16*)(i5+(_check_index(i7, i6, OOC_UINT32, 26626))*2);
        i5 = i5==10u;
        if (i5) goto l19;
        {register OOC_INT32 h0=i3;i3=i4;i4=h0;}
        goto l22;
l19:
        i3 = i4+1;
        delta = i3;
        i4=i7;
        goto l22;
      default:
        i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 26729))+20);
        i5 = _check_pointer(i5, 26736);
        i6 = OOC_ARRAY_LENGTH(i5, 0);
        i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 26751))+20);
        i7 = _check_pointer(i7, 26758);
        i8 = OOC_ARRAY_LENGTH(i7, 0);
        i7 = *(OOC_UINT16*)(i7+(_check_index(i3, i8, OOC_UINT32, 26758))*2);
        *(OOC_UINT16*)(i5+(_check_index((i3-i4), i6, OOC_UINT32, 26736))*2) = i7;
        {register OOC_INT32 h0=i3;i3=i4;i4=h0;}
        goto l22;
      }
l22:
      i4 = i4+1;
      i = i4;
      i5 = i4!=i2;
      if (!i5) goto l27;
      {register OOC_INT32 h0=i3;i3=i4;i4=h0;}
      goto l14_loop;
l27:
      i2 = i2-i3;
      len = i2;
      i3 = (OOC_INT32)RT0__NewObject(_td_XML_UnicodeBuffer__CharArray.baseTypes[0], (i2+2));
      str = (XML_UnicodeBuffer__CharArray)i3;
      i = 0;
      i4 = 0<i2;
      if (!i4) goto l35;
      i4=0;
l30_loop:
      i5 = _check_pointer(i3, 26905);
      i6 = OOC_ARRAY_LENGTH(i5, 0);
      i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 26914))+20);
      i7 = _check_pointer(i7, 26921);
      i8 = OOC_ARRAY_LENGTH(i7, 0);
      i7 = *(OOC_UINT16*)(i7+(_check_index(i4, i8, OOC_UINT32, 26921))*2);
      *(OOC_UINT16*)(i5+(_check_index(i4, i6, OOC_UINT32, 26905))*2) = i7;
      i4 = i4+1;
      i = i4;
      i5 = i4<i2;
      if (i5) goto l30_loop;
l35:
      XML_Parser__ParserDesc_ParseDocument_CheckInvalidChars();
      XML_UnicodeBuffer__InputDesc_Close((XML_UnicodeBuffer__Input)i1);
      i1=i3;
l36:
      i0 = *(OOC_INT8*)((_check_pointer(i0, 27061))+8);
      switch (i0) {
      case 2:
        i0 = _check_pointer(i1, 27117);
        i3 = OOC_ARRAY_LENGTH(i0, 0);
        *(OOC_UINT16*)(i0+(_check_index(i2, i3, OOC_UINT32, 27117))*2) = 65535u;
        goto l41;
      case 3:
        i0 = _check_pointer(i1, 27191);
        i3 = OOC_ARRAY_LENGTH(i0, 0);
        *(OOC_UINT16*)(i0+(_check_index(i2, i3, OOC_UINT32, 27191))*2) = 65534u;
        goto l41;
      default:
        _failed_case(i0, 27050);
        goto l41;
      }
l41:
      return (XML_UnicodeBuffer__CharArray)i1;
      ;
    }

    
    void XML_Parser__ParserDesc_ParseDocument_PushEntity(XML_DTD__Entity entity, OOC_CHAR8 syncEntity) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8;
      XML_Parser__PEInfoList newList;
      OOC_INT32 i;

      i0 = (OOC_INT32)entity;
      i1 = i0!=(OOC_INT32)0;
      if (!i1) goto l3;
      *(OOC_UINT8*)((_check_pointer(i0, 27685))+17) = 1u;
l3:
      i1 = (OOC_INT32)p;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 27755))+84);
      i3 = *(OOC_INT32*)((_check_pointer(i1, 27734))+88);
      i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 27764)), 0);
      i2 = i3==i2;
      if (!i2) goto l14;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 27801))+84);
      i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 27810)), 0);
      i2 = (OOC_INT32)RT0__NewObject(_td_XML_Parser__PEInfoList.baseTypes[0], (i2+4));
      newList = (XML_Parser__PEInfoList)i2;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 27855))+84);
      i = 0;
      i3 = OOC_ARRAY_LENGTH((_check_pointer(i3, 27864)), 0);
      i4 = 0<i3;
      if (!i4) goto l13;
      i4=0;
l8_loop:
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 27897))+84);
      i5 = _check_pointer(i5, 27906);
      i6 = OOC_ARRAY_LENGTH(i5, 0);
      i7 = _check_pointer(i2, 27889);
      i8 = OOC_ARRAY_LENGTH(i7, 0);
      _copy_block((i5+((_check_index(i4, i6, OOC_UINT32, 27906))*28)),(i7+((_check_index(i4, i8, OOC_UINT32, 27889))*28)),28);
      i4 = i4+1;
      i = i4;
      i5 = i4<i3;
      if (i5) goto l8_loop;
l13:
      *(OOC_INT32*)((_check_pointer(i1, 27932))+84) = i2;
l14:
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 27971))+84);
      i2 = _check_pointer(i2, 27980);
      i3 = *(OOC_INT32*)((_check_pointer(i1, 27982))+88);
      i4 = OOC_ARRAY_LENGTH(i2, 0);
      *(OOC_INT32*)((i2+((_check_index(i3, i4, OOC_UINT32, 27980))*28))+20) = i0;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 28022))+84);
      i2 = _check_pointer(i2, 28031);
      i3 = *(OOC_INT32*)((_check_pointer(i1, 28033))+88);
      i4 = OOC_ARRAY_LENGTH(i2, 0);
      i5 = (OOC_INT32)chars;
      *(OOC_INT32*)(i2+((_check_index(i3, i4, OOC_UINT32, 28031))*28)) = i5;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 28074))+84);
      i2 = _check_pointer(i2, 28083);
      i3 = *(OOC_INT32*)((_check_pointer(i1, 28085))+88);
      i4 = OOC_ARRAY_LENGTH(i2, 0);
      i5 = cpos;
      *(OOC_INT32*)((i2+((_check_index(i3, i4, OOC_UINT32, 28083))*28))+4) = i5;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 28124))+84);
      i2 = _check_pointer(i2, 28133);
      i3 = *(OOC_INT32*)((_check_pointer(i1, 28135))+88);
      i4 = OOC_ARRAY_LENGTH(i2, 0);
      i5 = *(OOC_INT32*)((_check_pointer(i1, 28166))+92);
      *(OOC_INT32*)((i2+((_check_index(i3, i4, OOC_UINT32, 28133))*28))+8) = i5;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 28185))+84);
      i2 = _check_pointer(i2, 28194);
      i3 = *(OOC_INT32*)((_check_pointer(i1, 28196))+88);
      i4 = OOC_ARRAY_LENGTH(i2, 0);
      i5 = *(OOC_INT32*)((_check_pointer(i1, 28230))+96);
      *(OOC_INT32*)((i2+((_check_index(i3, i4, OOC_UINT32, 28194))*28))+12) = i5;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 28252))+84);
      i2 = _check_pointer(i2, 28261);
      i3 = *(OOC_INT32*)((_check_pointer(i1, 28263))+88);
      i4 = OOC_ARRAY_LENGTH(i2, 0);
      i5 = *(OOC_INT32*)((_check_pointer(i1, 28297))+100);
      *(OOC_INT32*)((i2+((_check_index(i3, i4, OOC_UINT32, 28261))*28))+16) = i5;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 28319))+84);
      i2 = _check_pointer(i2, 28328);
      i3 = *(OOC_INT32*)((_check_pointer(i1, 28330))+88);
      i4 = OOC_ARRAY_LENGTH(i2, 0);
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 28352))+36);
      *(OOC_INT32*)((i2+((_check_index(i3, i4, OOC_UINT32, 28328))*28))+24) = i5;
      i2 = *(OOC_INT32*)((_check_pointer(i1, 28370))+88);
      *(OOC_INT32*)((_check_pointer(i1, 28370))+88) = (i2+1);
      i2 = syncEntity;
      if (i2) goto l17;
      i3=0u;
      goto l19;
l17:
      i3 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 28422)))), &_td_XML_DTD__ExternalEntityDesc);
      
l19:
      if (i3) goto l47;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 29081)))), &_td_XML_DTD__ExternalEntityDesc);
      if (i1) goto l23;
      i1=0u;
      goto l25;
l23:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 29113))+12);
      i1 = i1==(OOC_INT32)0;
      
l25:
      if (!i1) goto l27;
      i1 = (OOC_INT32)XML_Parser__ParserDesc_ParseDocument_Internalize((XML_DTD__ExternalEntity)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 29197)))), &_td_XML_DTD__ExternalEntityDesc, 29197)));
      XML_DTD__EntityDesc_SetEntityValue((XML_DTD__Entity)i0, (XML_UnicodeBuffer__CharArray)i1);
l27:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 29258))+12);
      i1 = (OOC_INT32)XML_Parser__ParserDesc_ParseDocument_Clone((XML_UnicodeBuffer__CharArray)i1);
      chars = (XML_UnicodeBuffer__CharArray)i1;
      i3 = *(OOC_INT8*)((_check_pointer(i0, 29302))+8);
      switch (i3) {
      case 0:
      case 2:
        i2 = _check_pointer(i1, 29391);
        i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 29402)), 0);
        i3 = OOC_ARRAY_LENGTH(i2, 0);
        *(OOC_UINT16*)(i2+(_check_index((i1-2), i3, OOC_UINT32, 29391))*2) = 65535u;
        goto l39;
      case 1:
      case 3:
        i3 = _check_pointer(i1, 29511);
        i4 = OOC_ARRAY_LENGTH((_check_pointer(i1, 29522)), 0);
        i5 = OOC_ARRAY_LENGTH(i3, 0);
        *(OOC_UINT16*)(i3+(_check_index((i4-2), i5, OOC_UINT32, 29511))*2) = 65534u;
        i3 = (OOC_INT32)p;
        i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 29916))+72);
        i3 = i3==(OOC_INT32)0;
        if (!i3) goto l39;
        i3 = _check_pointer(i1, 29963);
        i4 = OOC_ARRAY_LENGTH((_check_pointer(i1, 29974)), 0);
        i5 = OOC_ARRAY_LENGTH(i3, 0);
        *(OOC_UINT16*)(i3+(_check_index((i4-2), i5, OOC_UINT32, 29963))*2) = 32u;
        if (i2) goto l35;
        i2 = _check_pointer(i1, 30111);
        i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 30122)), 0);
        i3 = OOC_ARRAY_LENGTH(i2, 0);
        *(OOC_UINT16*)(i2+(_check_index((i1-1), i3, OOC_UINT32, 30111))*2) = 65534u;
        goto l39;
l35:
        i2 = _check_pointer(i1, 30038);
        i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 30049)), 0);
        i3 = OOC_ARRAY_LENGTH(i2, 0);
        *(OOC_UINT16*)(i2+(_check_index((i1-1), i3, OOC_UINT32, 30038))*2) = 65535u;
        goto l39;
      default:
        _failed_case(i3, 29291);
        goto l39;
      }
l39:
      i1 = *(OOC_INT8*)((_check_pointer(i0, 30218))+8);
      i1 = i1==0;
      if (i1) goto l42;
      i1 = *(OOC_INT8*)((_check_pointer(i0, 30275))+8);
      i1 = i1==1;
      
      goto l44;
l42:
      i1=1u;
l44:
      if (!i1) goto l52;
      i1 = (OOC_INT32)p;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 30329))+4);
      *(OOC_INT32*)((_check_pointer(i1, 30332))+16) = (_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 30365)))), &_td_XML_DTD__InternalEntityDesc, 30365));
      goto l52;
l47:
      i2 = (OOC_INT32)XML_Parser__ParserDesc_ParseDocument_GetBuffer((XML_DTD__ExternalEntity)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 28534)))), &_td_XML_DTD__ExternalEntityDesc, 28534)));
      *(OOC_INT32*)((_check_pointer(i1, 28504))+36) = i2;
      XML_Parser__ParserDesc_ParseDocument_SetFileEntity((XML_DTD__ExternalEntity)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 28586)))), &_td_XML_DTD__ExternalEntityDesc, 28586)));
      XML_Parser__ParserDesc_ParseDocument_ResetLocator();
      i0 = (OOC_INT32)p;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 28639))+36);
      i1 = i1==(OOC_INT32)0;
      if (i1) goto l50;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 28803))+36);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 28807))+20);
      chars = (XML_UnicodeBuffer__CharArray)i0;
      goto l52;
l50:
      i0 = (OOC_INT32)RT0__NewObject(_td_XML_UnicodeBuffer__CharArray.baseTypes[0], 2);
      chars = (XML_UnicodeBuffer__CharArray)i0;
      i0 = _check_pointer(i0, 28746);
      i1 = OOC_ARRAY_LENGTH(i0, 0);
      *(OOC_UINT16*)(i0+(_check_index(0, i1, OOC_UINT8, 28746))*2) = 65535u;
l52:
      cpos = 0;
      cdelta = 0;
      cstart = 0;
      return;
      ;
    }

    
    void XML_Parser__ParserDesc_ParseDocument_PopEntity(void) {
      register OOC_INT32 i0,i1,i2,i3,i4;
      OOC_INT32 i;

      i0 = (OOC_INT32)p;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 30557))+72);
      i0 = i0!=(OOC_INT32)0;
      if (!i0) goto l3;
      i0 = (OOC_INT32)dtd;
      i1 = cdelta;
      i2 = cpos;
      i3 = cstart;
      i4 = (OOC_INT32)chars;
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 30759)))), XML_DTD__BuilderDesc_NewCharacters)),XML_DTD__BuilderDesc_NewCharacters)((XML_DTD__Builder)i0, (XML_UnicodeBuffer__CharArray)i4, i3, (i2-i1), 1u);
      i1 = (OOC_INT32)p;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 30729))+72);
      XML_DTD__AttValueDesc_Append((XML_DTD__AttValue)i1, (XML_DTD__Fragment)i0);
l3:
      i0 = (OOC_INT32)p;
      i1 = *(OOC_INT32*)((_check_pointer(i0, 30841))+88);
      *(OOC_INT32*)((_check_pointer(i0, 30841))+88) = (i1-1);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 30867))+36);
      i1 = i1!=(OOC_INT32)0;
      if (i1) goto l6;
      i0=0u;
      goto l8;
l6:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 30891))+84);
      i1 = _check_pointer(i1, 30900);
      i2 = *(OOC_INT32*)((_check_pointer(i0, 30902))+88);
      i3 = OOC_ARRAY_LENGTH(i1, 0);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 30883))+36);
      i1 = (OOC_INT32)*(OOC_INT32*)((i1+((_check_index(i2, i3, OOC_UINT32, 30900))*28))+24);
      i0 = i0!=i1;
      
l8:
      if (!i0) goto l10;
      XML_Parser__ParserDesc_ParseDocument_CheckInvalidChars();
      i0 = (OOC_INT32)p;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 30962))+36);
      XML_UnicodeBuffer__InputDesc_Close((XML_UnicodeBuffer__Input)i0);
l10:
      i0 = (OOC_INT32)p;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 31056))+84);
      i1 = _check_pointer(i1, 31065);
      i2 = *(OOC_INT32*)((_check_pointer(i0, 31067))+88);
      i3 = OOC_ARRAY_LENGTH(i1, 0);
      i1 = (OOC_INT32)*(OOC_INT32*)(i1+((_check_index(i2, i3, OOC_UINT32, 31065))*28));
      chars = (XML_UnicodeBuffer__CharArray)i1;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 31107))+84);
      i1 = _check_pointer(i1, 31116);
      i2 = *(OOC_INT32*)((_check_pointer(i0, 31118))+88);
      i3 = OOC_ARRAY_LENGTH(i1, 0);
      i1 = *(OOC_INT32*)((i1+((_check_index(i2, i3, OOC_UINT32, 31116))*28))+4);
      cpos = i1;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 31164))+84);
      i1 = _check_pointer(i1, 31173);
      i2 = *(OOC_INT32*)((_check_pointer(i0, 31175))+88);
      i3 = OOC_ARRAY_LENGTH(i1, 0);
      i1 = *(OOC_INT32*)((i1+((_check_index(i2, i3, OOC_UINT32, 31173))*28))+8);
      *(OOC_INT32*)((_check_pointer(i0, 31149))+92) = i1;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 31228))+84);
      i1 = _check_pointer(i1, 31237);
      i2 = *(OOC_INT32*)((_check_pointer(i0, 31239))+88);
      i3 = OOC_ARRAY_LENGTH(i1, 0);
      i1 = *(OOC_INT32*)((i1+((_check_index(i2, i3, OOC_UINT32, 31237))*28))+12);
      *(OOC_INT32*)((_check_pointer(i0, 31210))+96) = i1;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 31295))+84);
      i1 = _check_pointer(i1, 31304);
      i2 = *(OOC_INT32*)((_check_pointer(i0, 31306))+88);
      i3 = OOC_ARRAY_LENGTH(i1, 0);
      i1 = *(OOC_INT32*)((i1+((_check_index(i2, i3, OOC_UINT32, 31304))*28))+16);
      *(OOC_INT32*)((_check_pointer(i0, 31277))+100) = i1;
      i1 = *(OOC_INT32*)((_check_pointer(i0, 31349))+88);
      i1 = i1-1;
      i = i1;
      i2 = i1>=0;
      if (i2) goto l13;
      i2=0u;
      goto l15;
l13:
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 31391))+84);
      i2 = _check_pointer(i2, 31400);
      i3 = OOC_ARRAY_LENGTH(i2, 0);
      i2 = (OOC_INT32)*(OOC_INT32*)((i2+((_check_index(i1, i3, OOC_UINT32, 31400))*28))+20);
      i2 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 31412)))), &_td_XML_DTD__ExternalEntityDesc));
      
l15:
      if (!i2) goto l27;
l18_loop:
      i1 = i1-1;
      i = i1;
      i2 = i1>=0;
      if (i2) goto l21;
      i2=0u;
      goto l23;
l21:
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 31391))+84);
      i2 = _check_pointer(i2, 31400);
      i3 = OOC_ARRAY_LENGTH(i2, 0);
      i2 = (OOC_INT32)*(OOC_INT32*)((i2+((_check_index(i1, i3, OOC_UINT32, 31400))*28))+20);
      i2 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 31412)))), &_td_XML_DTD__ExternalEntityDesc));
      
l23:
      if (i2) goto l18_loop;
l27:
      i2 = i1>=0;
      if (i2) goto l30;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 31589))+52);
      XML_Parser__ParserDesc_ParseDocument_SetFileEntity((XML_DTD__ExternalEntity)i0);
      goto l31;
l30:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 31512))+84);
      i0 = _check_pointer(i0, 31521);
      i2 = OOC_ARRAY_LENGTH(i0, 0);
      i0 = (OOC_INT32)*(OOC_INT32*)((i0+((_check_index(i1, i2, OOC_UINT32, 31521))*28))+20);
      XML_Parser__ParserDesc_ParseDocument_SetFileEntity((XML_DTD__ExternalEntity)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 31537)))), &_td_XML_DTD__ExternalEntityDesc, 31537)));
l31:
      i0 = (OOC_INT32)p;
      i2 = *(OOC_INT32*)((_check_pointer(i0, 31640))+88);
      i1 = i1!=(i2-1);
      if (i1) goto l34;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 31881))+4);
      *(OOC_INT32*)((_check_pointer(i1, 31884))+16) = (OOC_INT32)0;
      goto l35;
l34:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 31741))+4);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 31767))+84);
      i2 = _check_pointer(i2, 31776);
      i3 = *(OOC_INT32*)((_check_pointer(i0, 31778))+88);
      i4 = OOC_ARRAY_LENGTH(i2, 0);
      i2 = (OOC_INT32)*(OOC_INT32*)((i2+((_check_index((i3-1), i4, OOC_UINT32, 31776))*28))+20);
      *(OOC_INT32*)((_check_pointer(i1, 31744))+16) = (_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 31806)))), &_td_XML_DTD__InternalEntityDesc, 31806));
l35:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 31944))+84);
      i1 = _check_pointer(i1, 31953);
      i2 = *(OOC_INT32*)((_check_pointer(i0, 31955))+88);
      i3 = OOC_ARRAY_LENGTH(i1, 0);
      i1 = (OOC_INT32)*(OOC_INT32*)((i1+((_check_index(i2, i3, OOC_UINT32, 31953))*28))+24);
      *(OOC_INT32*)((_check_pointer(i0, 31935))+36) = i1;
      i1 = cpos;
      cstart = i1;
      cdelta = 0;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 32027))+84);
      i1 = _check_pointer(i1, 32036);
      i2 = *(OOC_INT32*)((_check_pointer(i0, 32038))+88);
      i3 = OOC_ARRAY_LENGTH(i1, 0);
      i1 = (OOC_INT32)*(OOC_INT32*)((i1+((_check_index(i2, i3, OOC_UINT32, 32036))*28))+20);
      i1 = i1!=(OOC_INT32)0;
      if (!i1) goto l38;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 32081))+84);
      i1 = _check_pointer(i1, 32090);
      i0 = *(OOC_INT32*)((_check_pointer(i0, 32092))+88);
      i2 = OOC_ARRAY_LENGTH(i1, 0);
      i0 = (OOC_INT32)*(OOC_INT32*)((i1+((_check_index(i0, i2, OOC_UINT32, 32090))*28))+20);
      *(OOC_UINT8*)((_check_pointer(i0, 32113))+17) = 0u;
l38:
      return;
      ;
    }

    
    void XML_Parser__ParserDesc_ParseDocument_NextBlock(void) {
      register OOC_INT32 i0,i1,i2,i3;
      OOC_INT32 oldOffset;
      OOC_CHAR8 res;

      i0 = (OOC_INT32)chars;
      i1 = _check_pointer(i0, 32297);
      i2 = OOC_ARRAY_LENGTH(i1, 0);
      i3 = cpos;
      i1 = *(OOC_UINT16*)(i1+(_check_index(i3, i2, OOC_UINT32, 32297))*2);
      _assert((i1==65534u), 127, 32284);
      i1 = (OOC_INT32)p;
      i2 = *(OOC_INT32*)((_check_pointer(i1, 32336))+88);
      i2 = i2!=0;
      if (i2) goto l3;
      i2=0u;
      goto l5;
l3:
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 32358))+36);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 32362))+20);
      i2 = i2!=i0;
      
l5:
      if (i2) goto l7;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 32884))+36);
      i0 = *(OOC_INT32*)((_check_pointer(i0, 32888))+24);
      oldOffset = i0;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 32922))+36);
      i1 = XML_UnicodeBuffer__InputDesc_NextBlock((XML_UnicodeBuffer__Input)i1);
      res = i1;
      i1 = (OOC_INT32)p;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 32959))+36);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 32963))+20);
      chars = (XML_UnicodeBuffer__CharArray)i2;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 32992))+36);
      i2 = *(OOC_INT32*)((_check_pointer(i2, 32996))+24);
      i3 = cpos;
      cpos = (i3-(i2-i0));
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 33047))+36);
      i2 = *(OOC_INT32*)((_check_pointer(i2, 33051))+24);
      i3 = cstart;
      cstart = (i3-(i2-i0));
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 33110))+36);
      i2 = *(OOC_INT32*)((_check_pointer(i2, 33114))+24);
      i3 = *(OOC_INT32*)((_check_pointer(i1, 33094))+96);
      *(OOC_INT32*)((_check_pointer(i1, 33094))+96) = (i3-(i2-i0));
      goto l11;
l7:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 32500))+72);
      i1 = i1==(OOC_INT32)0;
      if (!i1) goto l10;
      i1 = _check_pointer(i0, 32553);
      i2 = OOC_ARRAY_LENGTH((_check_pointer(i0, 32564)), 0);
      i3 = OOC_ARRAY_LENGTH(i1, 0);
      i1 = *(OOC_UINT16*)(i1+(_check_index((i2-2), i3, OOC_UINT32, 32553))*2);
      _assert((i1==32u), 127, 32540);
      i1 = _check_pointer(i0, 32593);
      i0 = OOC_ARRAY_LENGTH((_check_pointer(i0, 32604)), 0);
      i2 = OOC_ARRAY_LENGTH(i1, 0);
      *(OOC_UINT16*)(i1+(_check_index((i0-2), i2, OOC_UINT32, 32593))*2) = 65534u;
l10:
      XML_Parser__ParserDesc_ParseDocument_PopEntity();
l11:
      return;
      ;
    }

    
    void XML_Parser__ParserDesc_ParseDocument_DiscardPreviousInput(void) {
      register OOC_INT32 i0,i1,i2;

      i0 = (OOC_INT32)p;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 33230))+36);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 33234))+20);
      i2 = (OOC_INT32)chars;
      i1 = i1==i2;
      if (!i1) goto l4;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 33265))+36);
      i1 = cpos;
      *(OOC_INT32*)((_check_pointer(i0, 33269))+32) = i1;
      cstart = i1;
l4:
      return;
      ;
    }

    
    void XML_Parser__ParserDesc_ParseDocument_EndOfLine(void) {
      register OOC_INT32 i0,i1,i2;

      i0 = (OOC_INT32)p;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 33508))+36);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 33512))+20);
      i2 = (OOC_INT32)chars;
      i1 = i2==i1;
      if (!i1) goto l4;
      i1 = *(OOC_INT32*)((_check_pointer(i0, 33540))+92);
      *(OOC_INT32*)((_check_pointer(i0, 33540))+92) = (i1+1);
      i1 = cpos;
      *(OOC_INT32*)((_check_pointer(i0, 33562))+96) = i1;
      *(OOC_INT32*)((_check_pointer(i0, 33594))+100) = 0;
l4:
      return;
      ;
    }

    
    void XML_Parser__ParserDesc_ParseDocument_Tab(void) {
      register OOC_INT32 i0,i1,i2,i3;
      OOC_INT32 currColumn;

      i0 = (OOC_INT32)p;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 33813))+36);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 33817))+20);
      i2 = (OOC_INT32)chars;
      i1 = i2==i1;
      if (!i1) goto l4;
      i1 = *(OOC_INT32*)((_check_pointer(i0, 33859))+96);
      i2 = cpos;
      i3 = *(OOC_INT32*)((_check_pointer(i0, 33874))+100);
      i1 = (i2-i1)+i3;
      currColumn = i1;
      i2 = *(OOC_INT32*)((_check_pointer(i0, 33903))+100);
      *(OOC_INT32*)((_check_pointer(i0, 33903))+100) = (i2+((8-(_mod(i1,8)))-1));
l4:
      return;
      ;
    }

    
    OOC_CHAR8 XML_Parser__ParserDesc_ParseDocument_LookingAtS(void) {
      register OOC_INT32 i0,i1,i2,i3,i4;

      i0 = (OOC_INT32)chars;
      i1 = _check_pointer(i0, 34090);
      i2 = OOC_ARRAY_LENGTH(i1, 0);
      i3 = cpos;
      i1 = *(OOC_UINT16*)(i1+(_check_index(i3, i2, OOC_UINT32, 34090))*2);
      i1 = (OOC_UINT16)i1<=(OOC_UINT16)32u;
      if (i1) goto l23;
      i1 = (OOC_INT32)p;
      i2 = *(OOC_UINT8*)((_check_pointer(i1, 34144))+67);
      if (i2) goto l5;
      i2 = *(OOC_UINT8*)((_check_pointer(i1, 34167))+68);
      
      goto l7;
l5:
      i2=1u;
l7:
      if (i2) goto l9;
      i2=0u;
      goto l11;
l9:
      i2 = _check_pointer(i0, 34207);
      i4 = OOC_ARRAY_LENGTH(i2, 0);
      i2 = *(OOC_UINT16*)(i2+(_check_index(i3, i4, OOC_UINT32, 34207))*2);
      i2 = i2==37u;
      
l11:
      if (i2) goto l13;
      return 0u;
      goto l24;
l13:
      i2 = _check_pointer(i0, 34242);
      i3 = i3+1;
      i4 = OOC_ARRAY_LENGTH(i2, 0);
      i2 = *(OOC_UINT16*)(i2+(_check_index(i3, i4, OOC_UINT32, 34242))*2);
      i2 = i2==65534u;
      if (i2) goto l16;
      i0 = _check_pointer(i0, 34584);
      i1 = OOC_ARRAY_LENGTH(i0, 0);
      i0 = *(OOC_UINT16*)(i0+(_check_index(i3, i1, OOC_UINT32, 34584))*2);
      i0 = XML_Parser__IsNameChar(i0);
      return i0;
      goto l24;
l16:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 34298))+36);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 34302))+20);
      i0 = i0==i1;
      if (i0) goto l19;
      return 0u;
      goto l24;
l19:
      cpos = i3;
      XML_Parser__ParserDesc_ParseDocument_NextBlock();
      i0 = cpos;
      i0 = i0-1;
      cpos = i0;
      i1 = (OOC_INT32)chars;
      i1 = _check_pointer(i1, 34478);
      i2 = OOC_ARRAY_LENGTH(i1, 0);
      i0 = *(OOC_UINT16*)(i1+(_check_index((i0+1), i2, OOC_UINT32, 34478))*2);
      i0 = XML_Parser__IsNameChar(i0);
      return i0;
      goto l24;
l23:
      return 1u;
l24:
      _failed_function(33992); return 0;
      ;
    }

    
    OOC_CHAR8 XML_Parser__ParserDesc_ParseDocument_LookingAtSnoPE(void) {
      register OOC_INT32 i0,i1,i2;

      i0 = (OOC_INT32)chars;
      i0 = _check_pointer(i0, 34772);
      i1 = OOC_ARRAY_LENGTH(i0, 0);
      i2 = cpos;
      i0 = *(OOC_UINT16*)(i0+(_check_index(i2, i1, OOC_UINT32, 34772))*2);
      return ((OOC_UINT16)i0<=(OOC_UINT16)32u);
      ;
    }

    
    OOC_CHAR8 XML_Parser__ParserDesc_ParseDocument_LookingAt(const OOC_CHAR8 str__ref[], OOC_LEN str_0d, OOC_INT8 followedBy) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5;
      OOC_ALLOCATE_VPAR(str,OOC_CHAR8 ,str_0d)
      OOC_INT32 i;

      OOC_INITIALIZE_VPAR(str__ref,str,OOC_CHAR8 ,str_0d)
      i = 0;
      i0 = followedBy;
      i1=0;
l1_loop:
      i2 = (OOC_INT32)chars;
      i3 = _check_pointer(i2, 35663);
      i4 = OOC_ARRAY_LENGTH(i3, 0);
      i5 = cpos;
      i3 = *(OOC_UINT16*)(i3+(_check_index(i5, i4, OOC_UINT32, 35663))*2);
      i3 = i3==65534u;
      if (i3) goto l17;
      i3 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i1, str_0d, OOC_UINT32, 35973)));
      i3 = i3==0u;
      if (i3) goto l10;
      i2 = _check_pointer(i2, 36214);
      i3 = OOC_ARRAY_LENGTH(i2, 0);
      i4 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i1, str_0d, OOC_UINT32, 36203)));
      i2 = *(OOC_UINT16*)(i2+(_check_index(i5, i3, OOC_UINT32, 36214))*2);
      i2 = i4==i2;
      if (!i2) goto l7;
      goto l8;
l7:
      cpos = (i5-i1);
      return 0u;
      
      goto l1_loop;
l8:
      i1 = i1+1;
      i = i1;
      cpos = (i5+1);
      
      goto l1_loop;
l10:
      i3 = i5-i1;
      cpos = i3;
      switch (i0) {
      case 1:
        i2 = _check_pointer(i2, 36110);
        i4 = OOC_ARRAY_LENGTH(i2, 0);
        i2 = *(OOC_UINT16*)(i2+(_check_index((i3+i1), i4, OOC_UINT32, 36110))*2);
        i2 = XML_Parser__IsNameChar(i2);
        return (!i2);
        goto l1_loop;
      case 0:
        return 1u;
        goto l1_loop;
      default:
        _failed_case(i0, 36023);
        goto l1_loop;
      }
l17:
      i3 = (OOC_INT32)p;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 35718))+36);
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 35722))+20);
      i2 = i2==i3;
      if (!i2) goto l19;
      goto l20;
l19:
      cpos = (i5-i1);
      i2 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i1, str_0d, OOC_UINT32, 35931)));
      return (i2==0u);
      goto l1_loop;
l20:
      XML_Parser__ParserDesc_ParseDocument_NextBlock();
      goto l1_loop;
l24:
      ;
    }

    
    void XML_Parser__ParserDesc_ParseDocument_NextChar(void) {
      register OOC_INT32 i0,i1,i2,i3;

      i0 = (OOC_INT32)chars;
      i1 = _check_pointer(i0, 36427);
      i2 = OOC_ARRAY_LENGTH(i1, 0);
      i3 = cpos;
      i1 = *(OOC_UINT16*)(i1+(_check_index(i3, i2, OOC_UINT32, 36427))*2);
      i1 = i1!=65535u;
      if (!i1) goto l6;
      i1 = i3+1;
      cpos = i1;
      i0 = _check_pointer(i0, 36496);
      i2 = OOC_ARRAY_LENGTH(i0, 0);
      i0 = *(OOC_UINT16*)(i0+(_check_index(i1, i2, OOC_UINT32, 36496))*2);
      i0 = i0==65534u;
      if (!i0) goto l6;
      XML_Parser__ParserDesc_ParseDocument_NextBlock();
l6:
      return;
      ;
    }

    
    XML_UnicodeBuffer__CharArray XML_Parser__ParserDesc_ParseDocument_Nmtoken(OOC_CHAR8 checkForQName, OOC_CHAR8 noColon) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
      OOC_INT32 colon;
      XML_UnicodeBuffer__CharArray string;

      i0 = (OOC_INT32)chars;
      i0 = _check_pointer(i0, 36816);
      i1 = OOC_ARRAY_LENGTH(i0, 0);
      i2 = cpos;
      i0 = *(OOC_UINT16*)(i0+(_check_index(i2, i1, OOC_UINT32, 36816))*2);
      i0 = XML_Parser__IsNameChar(i0);
      if (i0) goto l3;
      XML_Parser__ParserDesc_ParseDocument_Err(11);
      XML_Parser__ParserDesc_ParseDocument_NextChar();
      i0 = (OOC_INT32)XML_Parser__noName;
      return (XML_UnicodeBuffer__CharArray)i0;
      goto l50;
l3:
      i0 = cpos;
      cstart = i0;
      i1 = (OOC_INT32)chars;
      i1 = _check_pointer(i1, 36870);
      i2 = OOC_ARRAY_LENGTH(i1, 0);
      i1 = *(OOC_UINT16*)(i1+(_check_index(i0, i2, OOC_UINT32, 36870))*2);
      i1 = i1==58u;
      if (i1) goto l6;
      colon = (-1);
      i0=(-1);
      goto l14;
l6:
      colon = i0;
      i1 = checkForQName;
      if (!i1) goto l14;
      i1 = noColon;
      if (i1) goto l11;
      XML_Parser__ParserDesc_ParseDocument_Err(31);
      goto l14;
l11:
      XML_Parser__ParserDesc_ParseDocument_Err(30);
l14:
      i1 = cpos;
      cpos = (i1+1);
      i1 = noColon;
      i2 = checkForQName;
      
l15_loop:
      i3 = (OOC_INT32)chars;
      i4 = _check_pointer(i3, 37277);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      i6 = cpos;
      i4 = *(OOC_UINT16*)(i4+(_check_index(i6, i5, OOC_UINT32, 37277))*2);
      i4 = i4==65534u;
      if (i4) goto l36;
      i4 = _check_pointer(i3, 37556);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      i4 = *(OOC_UINT16*)(i4+(_check_index(i6, i5, OOC_UINT32, 37556))*2);
      i4 = i4==58u;
      if (i4) goto l20;
      i4=0u;
      goto l22;
l20:
      i4=i2;
l22:
      if (i4) goto l28;
      i3 = _check_pointer(i3, 37895);
      i4 = OOC_ARRAY_LENGTH(i3, 0);
      i3 = *(OOC_UINT16*)(i3+(_check_index(i6, i4, OOC_UINT32, 37895))*2);
      i3 = XML_Parser__IsNameChar(i3);
      if (!i3) goto l25;
      goto l26;
l25:
      i0 = cpos;
      i1 = cstart;
      i0 = (OOC_INT32)XML_Parser__ParserDesc_ParseDocument_GetString(i1, i0);
      string = (XML_UnicodeBuffer__CharArray)i0;
      
      goto l43;
l26:
      i3 = cpos;
      cpos = (i3+1);
      goto l15_loop;
l28:
      if (i1) goto l33;
      i0 = i0>=0;
      if (i0) goto l31;
      goto l34;
l31:
      XML_Parser__ParserDesc_ParseDocument_Err(31);
      goto l34;
l33:
      XML_Parser__ParserDesc_ParseDocument_Err(30);
l34:
      i0 = cpos;
      colon = i0;
      cpos = (i0+1);
      
      goto l15_loop;
l36:
      i4 = (OOC_INT32)p;
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 37334))+36);
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 37338))+20);
      i3 = i3!=i4;
      if (i3) goto l40;
      XML_Parser__ParserDesc_ParseDocument_NextBlock();
      goto l15_loop;
l40:
      i0 = cstart;
      i0 = (OOC_INT32)XML_Parser__ParserDesc_ParseDocument_GetString(i0, i6);
      string = (XML_UnicodeBuffer__CharArray)i0;
      XML_Parser__ParserDesc_ParseDocument_NextBlock();
      
l43:
      if (i2) goto l45;
      i1=0u;
      goto l47;
l45:
      i1 = _check_pointer(i0, 38072);
      i2 = OOC_ARRAY_LENGTH((_check_pointer(i0, 38084)), 0);
      i3 = OOC_ARRAY_LENGTH(i1, 0);
      i1 = *(OOC_UINT16*)(i1+(_check_index((i2-2), i3, OOC_UINT32, 38072))*2);
      i1 = i1==58u;
      
l47:
      if (!i1) goto l49;
      XML_Parser__ParserDesc_ParseDocument_Err(31);
l49:
      return (XML_UnicodeBuffer__CharArray)i0;
l50:
      _failed_function(36603); return 0;
      ;
    }

    
    XML_UnicodeBuffer__CharArray XML_Parser__ParserDesc_ParseDocument_Name(OOC_CHAR8 noColon) {
      register OOC_INT32 i0,i1,i2;

      i0 = (OOC_INT32)chars;
      i0 = _check_pointer(i0, 38474);
      i1 = OOC_ARRAY_LENGTH(i0, 0);
      i2 = cpos;
      i0 = *(OOC_UINT16*)(i0+(_check_index(i2, i1, OOC_UINT32, 38474))*2);
      i0 = XML_Parser__IsNameChar0(i0);
      if (i0) goto l3;
      XML_Parser__ParserDesc_ParseDocument_Err(10);
      XML_Parser__ParserDesc_ParseDocument_NextChar();
      i0 = (OOC_INT32)XML_Parser__noName;
      return (XML_UnicodeBuffer__CharArray)i0;
      goto l4;
l3:
      i0 = (OOC_INT32)p;
      i0 = *(OOC_UINT8*)((_check_pointer(i0, 38512))+61);
      i1 = noColon;
      i0 = (OOC_INT32)XML_Parser__ParserDesc_ParseDocument_Nmtoken(i0, i1);
      return (XML_UnicodeBuffer__CharArray)i0;
l4:
      _failed_function(38338); return 0;
      ;
    }

    
    void XML_Parser__ParserDesc_ParseDocument_CheckChar(OOC_CHAR8 ch) {
      register OOC_INT32 i0,i1,i2,i3;
      OOC_CHAR8 str[2];

      i0 = (OOC_INT32)chars;
      i0 = _check_pointer(i0, 38858);
      i1 = OOC_ARRAY_LENGTH(i0, 0);
      i2 = cpos;
      i0 = *(OOC_UINT16*)(i0+(_check_index(i2, i1, OOC_UINT32, 38858))*2);
      i1 = ch;
      i0 = i0!=i1;
      if (!i0) goto l3;
      XML_Parser__ParserDesc_ParseDocument_Err(12);
      _copy_8((const void*)"X",(void*)(OOC_INT32)str,2);
      *(OOC_UINT8*)((OOC_INT32)str+(_check_index(0, 2, OOC_UINT8, 38935))) = i1;
      i0 = (OOC_INT32)Msg__GetStringPtr((void*)(OOC_INT32)str, 2);
      i1 = (OOC_INT32)p;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 38955))+104);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 38955))+104);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 38966)))), Msg__MsgDesc_SetStringAttrib)),Msg__MsgDesc_SetStringAttrib)((Msg__Msg)i1, "symbol", 7, (Msg__StringPtr)i0);
l3:
      i0 = (OOC_INT32)chars;
      i1 = _check_pointer(i0, 39045);
      i2 = OOC_ARRAY_LENGTH(i1, 0);
      i3 = cpos;
      i1 = *(OOC_UINT16*)(i1+(_check_index(i3, i2, OOC_UINT32, 39045))*2);
      i1 = i1!=65535u;
      if (!i1) goto l9;
      i1 = i3+1;
      cpos = i1;
      i0 = _check_pointer(i0, 39114);
      i2 = OOC_ARRAY_LENGTH(i0, 0);
      i0 = *(OOC_UINT16*)(i0+(_check_index(i1, i2, OOC_UINT32, 39114))*2);
      i0 = i0==65534u;
      if (!i0) goto l9;
      XML_Parser__ParserDesc_ParseDocument_NextBlock();
l9:
      return;
      ;
    }

    
    void XML_Parser__ParserDesc_ParseDocument_SkippedEntity(XML_UnicodeBuffer__CharArray name) {
      register OOC_INT32 i0,i1;

      i0 = (OOC_INT32)p;
      *(OOC_UINT8*)((_check_pointer(i0, 39459))+64) = 0u;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 39498))+52);
      i1 = *(OOC_INT8*)((_check_pointer(i1, 39514))+48);
      i1 = i1!=0;
      if (!i1) goto l3;
      *(OOC_UINT8*)((_check_pointer(i0, 39562))+63) = 0u;
l3:
      return;
      ;
    }

    
    void XML_Parser__ParserDesc_ParseDocument_PEReference(OOC_CHAR8 declSep) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5;
      OOC_INT32 oldCStart;
      XML_UnicodeBuffer__CharArray name;
      XML_DTD__Declaration decl;
      XML_DTD__Entity entity;
      OOC_CHAR8 inInternalSubset;
      OOC_CHAR8 oldFlag;

      i0 = declSep;
      i1 = !i0;
      if (i1) goto l3;
      i1=0u;
      goto l9;
l3:
      i1 = (OOC_INT32)p;
      i2 = *(OOC_UINT8*)((_check_pointer(i1, 39923))+67);
      i2 = !i2;
      if (i2) goto l6;
      i1=0u;
      goto l9;
l6:
      i1 = *(OOC_UINT8*)((_check_pointer(i1, 39946))+68);
      i1 = !i1;
      
l9:
      if (!i1) goto l11;
      XML_Parser__ParserDesc_ParseDocument_Err(115);
l11:
      XML_Parser__ParserDesc_ParseDocument_CheckChar(37u);
      i1 = (OOC_INT32)p;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 40065))+36);
      i1 = *(OOC_INT32*)((_check_pointer(i1, 40069))+24);
      i2 = cstart;
      i1 = i2+i1;
      oldCStart = i1;
      i2 = (OOC_INT32)XML_Parser__ParserDesc_ParseDocument_Name(1u);
      name = (XML_UnicodeBuffer__CharArray)i2;
      i3 = (OOC_INT32)p;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 40141))+36);
      i3 = *(OOC_INT32*)((_check_pointer(i3, 40145))+24);
      cstart = (i1-i3);
      XML_Parser__ParserDesc_ParseDocument_CheckChar(59u);
      i1 = (OOC_INT32)dtd;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 40203))+8);
      i1 = (OOC_INT32)XML_DTD__NamespaceDesc_Get((XML_DTD__Namespace)i1, (XML_UnicodeBuffer__CharArray)i2);
      decl = (XML_DTD__Declaration)i1;
      i3 = i1==(OOC_INT32)0;
      if (i3) goto l48;
      i1 = _type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 40608)))), &_td_XML_DTD__EntityDesc, 40608);
      entity = (XML_DTD__Entity)i1;
      if (i0) goto l19;
      i0 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 41950)))), &_td_XML_DTD__ExternalEntityDesc);
      if (!i0) goto l18;
      i0 = (OOC_INT32)XML_Parser__ParserDesc_ParseDocument_Internalize((XML_DTD__ExternalEntity)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 42038)))), &_td_XML_DTD__ExternalEntityDesc, 42038)));
      XML_DTD__EntityDesc_SetEntityValue((XML_DTD__Entity)i1, (XML_UnicodeBuffer__CharArray)i0);
l18:
      XML_Parser__ParserDesc_ParseDocument_PushEntity((XML_DTD__Entity)i1, 0u);
      goto l61;
l19:
      i0 = (OOC_INT32)p;
      i3 = *(OOC_UINT8*)((_check_pointer(i0, 40808))+60);
      if (i3) goto l22;
      i3 = *(OOC_INT8*)((_check_pointer(i1, 40851))+8);
      i3 = i3==1;
      
      goto l24;
l22:
      i3=1u;
l24:
      if (i3) goto l26;
      XML_Parser__ParserDesc_ParseDocument_SkippedEntity((XML_UnicodeBuffer__CharArray)i2);
      goto l61;
l26:
      i2 = *(OOC_UINT8*)((_check_pointer(i0, 40929))+67);
      if (i2) goto l29;
      i0 = *(OOC_UINT8*)((_check_pointer(i0, 40952))+68);
      
      goto l30;
l29:
      i0=1u;
l30:
      i0 = !i0;
      inInternalSubset = i0;
      XML_Parser__ParserDesc_ParseDocument_PushEntity((XML_DTD__Entity)i1, i0);
      i2 = (OOC_INT32)p;
      i3 = *(OOC_UINT8*)((_check_pointer(i2, 41127))+68);
      oldFlag = i3;
      i4 = *(OOC_INT8*)((_check_pointer(i1, 41169))+8);
      i4 = i4==3;
      if (!i4) goto l36;
      *(OOC_UINT8*)((_check_pointer(i2, 41227))+68) = 1u;
      i2 = XML_Parser__ParserDesc_ParseDocument_LookingAt("<?xml", 6, 1);
      if (!i2) goto l36;
      XML_Parser__ParserDesc_ParseDocument_XMLDecl((XML_DTD__ExternalEntity)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 41352)))), &_td_XML_DTD__ExternalEntityDesc, 41352)));
l36:
      XML_Parser__ParserDesc_ParseDocument_extSubsetDecl();
      i2 = (OOC_INT32)chars;
      i2 = _check_pointer(i2, 41465);
      i4 = OOC_ARRAY_LENGTH(i2, 0);
      i5 = cpos;
      i2 = *(OOC_UINT16*)(i2+(_check_index(i5, i4, OOC_UINT32, 41465))*2);
      i2 = i2!=65535u;
      if (!i2) goto l39;
      XML_Parser__ParserDesc_ParseDocument_Err(28);
l39:
      i1 = *(OOC_INT8*)((_check_pointer(i1, 41588))+8);
      i1 = i1==3;
      if (!i1) goto l43;
      i1 = (OOC_INT32)p;
      *(OOC_UINT8*)((_check_pointer(i1, 41646))+68) = i3;
l43:
      if (!i0) goto l61;
      XML_Parser__ParserDesc_ParseDocument_PopEntity();
      goto l61;
l48:
      i0 = (OOC_INT32)p;
      i1 = *(OOC_UINT8*)((_check_pointer(i0, 40318))+62);
      if (i1) goto l55;
      i1 = *(OOC_UINT8*)((_check_pointer(i0, 40347))+63);
      if (i1) goto l53;
      i0=0u;
      goto l57;
l53:
      i0 = *(OOC_UINT8*)((_check_pointer(i0, 40372))+60);
      
      goto l57;
l55:
      i0=1u;
l57:
      if (i0) goto l59;
      XML_Parser__ParserDesc_ParseDocument_SkippedEntity((XML_UnicodeBuffer__CharArray)i2);
      goto l61;
l59:
      XML_Parser__ParserDesc_ParseDocument_Err(211);
      i0 = OOC_ARRAY_LENGTH((_check_pointer(i2, 40510)), 0);
      i0 = (OOC_INT32)Msg__GetLStringPtr((void*)(_check_pointer(i2, 40510)), i0);
      i1 = (OOC_INT32)p;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 40448))+104);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 40448))+104);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 40459)))), Msg__MsgDesc_SetLStringAttrib)),Msg__MsgDesc_SetLStringAttrib)((Msg__Msg)i1, "name", 5, (Msg__LStringPtr)i0);
l61:
      return;
      ;
    }

    
    void XML_Parser__ParserDesc_ParseDocument_OptS(OOC_CHAR8 noPE) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5;

      i0 = noPE;
      i1 = !i0;
l1_loop:
      i2 = (OOC_INT32)chars;
      i3 = _check_pointer(i2, 42601);
      i4 = OOC_ARRAY_LENGTH(i3, 0);
      i5 = cpos;
      i3 = *(OOC_UINT16*)(i3+(_check_index(i5, i4, OOC_UINT32, 42601))*2);
      switch (i3) {
      case 65534u:
        XML_Parser__ParserDesc_ParseDocument_NextBlock();
        goto l1_loop;
      case 32u:
        cpos = (i5+1);
        goto l1_loop;
      case 10u:
        cpos = (i5+1);
        XML_Parser__ParserDesc_ParseDocument_EndOfLine();
        goto l1_loop;
      case 13u:
        i3 = i5+1;
        cpos = i3;
        i2 = _check_pointer(i2, 42808);
        i4 = OOC_ARRAY_LENGTH(i2, 0);
        i2 = *(OOC_UINT16*)(i2+(_check_index(i3, i4, OOC_UINT32, 42808))*2);
        i2 = i2==65534u;
        if (!i2) goto l9;
        XML_Parser__ParserDesc_ParseDocument_NextBlock();
l9:
        i2 = (OOC_INT32)chars;
        i2 = _check_pointer(i2, 42896);
        i3 = OOC_ARRAY_LENGTH(i2, 0);
        i4 = cpos;
        i2 = *(OOC_UINT16*)(i2+(_check_index(i4, i3, OOC_UINT32, 42896))*2);
        i2 = i2==10u;
        if (i2) goto l11;
        goto l12;
l11:
        cpos = (i4+1);
l12:
        XML_Parser__ParserDesc_ParseDocument_EndOfLine();
        goto l1_loop;
      case 9u:
        XML_Parser__ParserDesc_ParseDocument_Tab();
        i2 = cpos;
        cpos = (i2+1);
        goto l1_loop;
      case 37u:
        if (!i1) goto l25;
        XML_Parser__ParserDesc_ParseDocument_PEReference(0u);
        XML_Parser__ParserDesc_ParseDocument_OptS(i0);
        goto l1_loop;
      default:
        i2 = _check_pointer(i2, 43198);
        i3 = OOC_ARRAY_LENGTH(i2, 0);
        i2 = *(OOC_UINT16*)(i2+(_check_index(i5, i3, OOC_UINT32, 43198))*2);
        i2 = (OOC_UINT16)i2<(OOC_UINT16)32u;
        if (!i2) goto l25;
        XML_Parser__ParserDesc_ParseDocument_Err(1);
        i2 = cpos;
        cpos = (i2+1);
        goto l1_loop;
      }
l25:
      return;
      ;
    }

    
    void XML_Parser__ParserDesc_ParseDocument_S(void) {
      register OOC_INT32 i0;

      i0 = XML_Parser__ParserDesc_ParseDocument_LookingAtS();
      if (i0) goto l3;
      XML_Parser__ParserDesc_ParseDocument_Err(9);
      goto l4;
l3:
      XML_Parser__ParserDesc_ParseDocument_OptS(0u);
l4:
      return;
      ;
    }

    
    void XML_Parser__ParserDesc_ParseDocument_SnoPE(void) {
      register OOC_INT32 i0;

      i0 = XML_Parser__ParserDesc_ParseDocument_LookingAtSnoPE();
      if (i0) goto l3;
      XML_Parser__ParserDesc_ParseDocument_Err(9);
      goto l4;
l3:
      XML_Parser__ParserDesc_ParseDocument_OptS(1u);
l4:
      return;
      ;
    }

    
    void XML_Parser__ParserDesc_ParseDocument_ControlChar(OOC_CHAR16 eolReplacement) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5;
      OOC_INT32 cend;

      i0 = (OOC_INT32)chars;
      i1 = _check_pointer(i0, 44240);
      i2 = OOC_ARRAY_LENGTH(i1, 0);
      i3 = cpos;
      i1 = *(OOC_UINT16*)(i1+(_check_index(i3, i2, OOC_UINT32, 44240))*2);
      i1 = (OOC_UINT16)i1<(OOC_UINT16)32u;
      if (i1) goto l3;
      i1 = _check_pointer(i0, 44263);
      i2 = OOC_ARRAY_LENGTH(i1, 0);
      i1 = *(OOC_UINT16*)(i1+(_check_index(i3, i2, OOC_UINT32, 44263))*2);
      i1 = i1==65534u;
      
      goto l4;
l3:
      i1=1u;
l4:
      i2 = cdelta;
      i2 = i3-i2;
      _assert(i1, 127, 44226);
      cend = i2;
      i1 = _check_pointer(i0, 44335);
      i4 = OOC_ARRAY_LENGTH(i1, 0);
      i1 = *(OOC_UINT16*)(i1+(_check_index(i3, i4, OOC_UINT32, 44335))*2);
      switch (i1) {
      case 65534u:
        XML_Parser__ParserDesc_ParseDocument_NextBlock();
        goto l30;
      case 32u:
        i0 = _check_pointer(i0, 44415);
        i1 = OOC_ARRAY_LENGTH(i0, 0);
        *(OOC_UINT16*)(i0+(_check_index(i2, i1, OOC_UINT32, 44415))*2) = 32u;
        cpos = (i3+1);
        goto l30;
      case 10u:
        i1 = (OOC_INT32)p;
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 44480))+36);
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 44484))+20);
        i1 = i0==i1;
        if (i1) goto l11;
        i1 = _check_pointer(i0, 44705);
        i4 = OOC_ARRAY_LENGTH(i1, 0);
        i0 = _check_pointer(i0, 44720);
        i5 = OOC_ARRAY_LENGTH(i0, 0);
        i0 = *(OOC_UINT16*)(i0+(_check_index(i3, i5, OOC_UINT32, 44720))*2);
        *(OOC_UINT16*)(i1+(_check_index(i2, i4, OOC_UINT32, 44705))*2) = i0;
        cpos = (i3+1);
        goto l30;
l11:
        i0 = _check_pointer(i0, 44513);
        i1 = OOC_ARRAY_LENGTH(i0, 0);
        i4 = eolReplacement;
        *(OOC_UINT16*)(i0+(_check_index(i2, i1, OOC_UINT32, 44513))*2) = i4;
        cpos = (i3+1);
        XML_Parser__ParserDesc_ParseDocument_EndOfLine();
        goto l30;
      case 13u:
        i1 = (OOC_INT32)p;
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 44790))+36);
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 44794))+20);
        i1 = i0==i1;
        if (i1) goto l16;
        i1 = _check_pointer(i0, 45218);
        i4 = OOC_ARRAY_LENGTH(i1, 0);
        i0 = _check_pointer(i0, 45233);
        i5 = OOC_ARRAY_LENGTH(i0, 0);
        i0 = *(OOC_UINT16*)(i0+(_check_index(i3, i5, OOC_UINT32, 45233))*2);
        *(OOC_UINT16*)(i1+(_check_index(i2, i4, OOC_UINT32, 45218))*2) = i0;
        cpos = (i3+1);
        goto l30;
l16:
        i1 = _check_pointer(i0, 44823);
        i4 = OOC_ARRAY_LENGTH(i1, 0);
        i5 = eolReplacement;
        *(OOC_UINT16*)(i1+(_check_index(i2, i4, OOC_UINT32, 44823))*2) = i5;
        i1 = i3+1;
        cpos = i1;
        i0 = _check_pointer(i0, 44890);
        i2 = OOC_ARRAY_LENGTH(i0, 0);
        i0 = *(OOC_UINT16*)(i0+(_check_index(i1, i2, OOC_UINT32, 44890))*2);
        i0 = i0==65534u;
        if (!i0) goto l19;
        XML_Parser__ParserDesc_ParseDocument_NextBlock();
l19:
        i0 = (OOC_INT32)chars;
        i0 = _check_pointer(i0, 44978);
        i1 = OOC_ARRAY_LENGTH(i0, 0);
        i2 = cpos;
        i0 = *(OOC_UINT16*)(i0+(_check_index(i2, i1, OOC_UINT32, 44978))*2);
        i0 = i0==10u;
        if (!i0) goto l22;
        i0 = cdelta;
        cpos = (i2+1);
        cdelta = (i0+1);
l22:
        XML_Parser__ParserDesc_ParseDocument_EndOfLine();
        goto l30;
      case 9u:
        i1 = eolReplacement;
        i1 = i1==32u;
        if (i1) goto l27;
        i0 = _check_pointer(i0, 45378);
        i1 = OOC_ARRAY_LENGTH(i0, 0);
        *(OOC_UINT16*)(i0+(_check_index(i2, i1, OOC_UINT32, 45378))*2) = 9u;
        goto l28;
l27:
        i0 = _check_pointer(i0, 45336);
        i1 = OOC_ARRAY_LENGTH(i0, 0);
        *(OOC_UINT16*)(i0+(_check_index(i2, i1, OOC_UINT32, 45336))*2) = 32u;
l28:
        XML_Parser__ParserDesc_ParseDocument_Tab();
        i0 = cpos;
        cpos = (i0+1);
        goto l30;
      default:
        i0 = _check_pointer(i0, 45458);
        i1 = OOC_ARRAY_LENGTH(i0, 0);
        *(OOC_UINT16*)(i0+(_check_index(i2, i1, OOC_UINT32, 45458))*2) = 65533u;
        XML_Parser__ParserDesc_ParseDocument_Err(1);
        i0 = cpos;
        cpos = (i0+1);
        goto l30;
      }
l30:
      return;
      ;
    }

    
    XML_UnicodeBuffer__CharArray XML_Parser__ParserDesc_ParseDocument_String(OOC_INT8 type) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
      struct XML_Locator__Position pos;
      OOC_CHAR16 endChar;
      XML_UnicodeBuffer__CharArray string;
      auto void XML_Parser__ParserDesc_ParseDocument_String_NormalizeWhitespace(void);
        
        void XML_Parser__ParserDesc_ParseDocument_String_NormalizeWhitespace(void) {
          register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8,i9,i10;
          OOC_INT32 i;
          OOC_INT32 delta;

          i0 = cpos;
          i1 = cdelta;
          i2 = i0-i1;
          i3 = cstart;
          i4 = i3!=i2;
          if (i4) goto l3;
          i4=0u;
          goto l5;
l3:
          i4 = (OOC_INT32)chars;
          i4 = _check_pointer(i4, 46081);
          i5 = OOC_ARRAY_LENGTH(i4, 0);
          i4 = *(OOC_UINT16*)(i4+(_check_index(i3, i5, OOC_UINT32, 46081))*2);
          i4 = (OOC_UINT16)i4<=(OOC_UINT16)32u;
          
l5:
          if (!i4) goto l17;
          i4 = (OOC_INT32)chars;
          
l8_loop:
          i3 = i3+1;
          cstart = i3;
          i5 = i3!=i2;
          if (i5) goto l11;
          i5=0u;
          goto l13;
l11:
          i5 = _check_pointer(i4, 46081);
          i6 = OOC_ARRAY_LENGTH(i5, 0);
          i5 = *(OOC_UINT16*)(i5+(_check_index(i3, i6, OOC_UINT32, 46081))*2);
          i5 = (OOC_UINT16)i5<=(OOC_UINT16)32u;
          
l13:
          if (i5) goto l8_loop;
l17:
          i = i3;
          delta = 0;
          i4 = i3!=i2;
          if (i4) goto l20;
          i2=0;
          goto l47;
l20:
          i4 = (OOC_INT32)chars;
          i5=i3;i6=0;
l21_loop:
          i7 = _check_pointer(i4, 46224);
          i8 = OOC_ARRAY_LENGTH(i7, 0);
          i7 = *(OOC_UINT16*)(i7+(_check_index(i5, i8, OOC_UINT32, 46224))*2);
          i7 = (OOC_UINT16)i7<=(OOC_UINT16)32u;
          if (i7) goto l24;
          i7 = _check_pointer(i4, 46486);
          i8 = OOC_ARRAY_LENGTH(i7, 0);
          i9 = _check_pointer(i4, 46504);
          i10 = OOC_ARRAY_LENGTH(i9, 0);
          i9 = *(OOC_UINT16*)(i9+(_check_index(i5, i10, OOC_UINT32, 46504))*2);
          *(OOC_UINT16*)(i7+(_check_index((i5-i6), i8, OOC_UINT32, 46486))*2) = i9;
          {register OOC_INT32 h0=i5;i5=i6;i6=h0;}
          goto l42;
l24:
          i7 = _check_pointer(i4, 46322);
          i8 = OOC_ARRAY_LENGTH(i7, 0);
          *(OOC_UINT16*)(i7+(_check_index((i5-i6), i8, OOC_UINT32, 46322))*2) = 32u;
          i7 = i5+1;
          i8 = i7!=i2;
          if (i8) goto l27;
          i8=0u;
          goto l29;
l27:
          i8 = _check_pointer(i4, 46386);
          i9 = OOC_ARRAY_LENGTH(i8, 0);
          i8 = *(OOC_UINT16*)(i8+(_check_index(i7, i9, OOC_UINT32, 46386))*2);
          i8 = (OOC_UINT16)i8<=(OOC_UINT16)32u;
          
l29:
          if (i8) goto l31;
          {register OOC_INT32 h0=i5;i5=i6;i6=h0;}
          goto l42;
l31:
          i5=i6;i6=i7;
l32_loop:
          i = i6;
          i5 = i5+1;
          delta = i5;
          i7 = i6+1;
          i8 = i7!=i2;
          if (i8) goto l35;
          i8=0u;
          goto l37;
l35:
          i8 = _check_pointer(i4, 46386);
          i9 = OOC_ARRAY_LENGTH(i8, 0);
          i8 = *(OOC_UINT16*)(i8+(_check_index(i7, i9, OOC_UINT32, 46386))*2);
          i8 = (OOC_UINT16)i8<=(OOC_UINT16)32u;
          
l37:
          if (!i8) goto l42;
          i6=i7;
          goto l32_loop;
l42:
          i6 = i6+1;
          i = i6;
          i7 = i6!=i2;
          if (!i7) goto l46;
          {register OOC_INT32 h0=i5;i5=i6;i6=h0;}
          goto l21_loop;
l46:
          i2=i5;
l47:
          i1 = i1+i2;
          cdelta = i1;
          i0 = i0-i1;
          i2 = i0!=i3;
          if (i2) goto l50;
          i0=0u;
          goto l52;
l50:
          i2 = (OOC_INT32)chars;
          i2 = _check_pointer(i2, 46698);
          i3 = OOC_ARRAY_LENGTH(i2, 0);
          i0 = *(OOC_UINT16*)(i2+(_check_index((i0-1), i3, OOC_UINT32, 46698))*2);
          i0 = i0==32u;
          
l52:
          if (!i0) goto l54;
          cdelta = (i1+1);
l54:
          return;
          ;
        }


      i0 = (OOC_INT32)chars;
      i1 = _check_pointer(i0, 46822);
      i2 = OOC_ARRAY_LENGTH(i1, 0);
      i3 = cpos;
      i1 = *(OOC_UINT16*)(i1+(_check_index(i3, i2, OOC_UINT32, 46822))*2);
      i1 = i1==39u;
      if (i1) goto l3;
      i0 = _check_pointer(i0, 46845);
      i1 = OOC_ARRAY_LENGTH(i0, 0);
      i0 = *(OOC_UINT16*)(i0+(_check_index(i3, i1, OOC_UINT32, 46845))*2);
      i0 = i0==34u;
      
      goto l5;
l3:
      i0=1u;
l5:
      if (i0) goto l7;
      XML_Parser__ParserDesc_ParseDocument_Err(16);
      i0 = cpos;
      i0 = (OOC_INT32)XML_Parser__ParserDesc_ParseDocument_GetString(i0, i0);
      return (XML_UnicodeBuffer__CharArray)i0;
      goto l59;
l7:
      i0 = (OOC_INT32)&_td_XML_Locator__Position;
      XML_Parser__ParserDesc_ParseDocument_StorePosition((void*)(OOC_INT32)&pos, (RT0__Struct)i0);
      i1 = (OOC_INT32)chars;
      i1 = _check_pointer(i1, 46917);
      i2 = OOC_ARRAY_LENGTH(i1, 0);
      i3 = cpos;
      i1 = *(OOC_UINT16*)(i1+(_check_index(i3, i2, OOC_UINT32, 46917))*2);
      endChar = i1;
      i1 = i3+1;
      cpos = i1;
      cstart = i1;
      cdelta = 0;
l8_loop:
      i1 = (OOC_INT32)chars;
      i2 = _check_pointer(i1, 47015);
      i3 = OOC_ARRAY_LENGTH(i2, 0);
      i4 = cpos;
      i2 = *(OOC_UINT16*)(i2+(_check_index(i4, i3, OOC_UINT32, 47015))*2);
      switch (i2) {
      case 0u ... 31u:
      case 65534u:
        i2 = type;
        i2 = i2==2;
        if (i2) goto l13;
        i1=0u;
        goto l15;
l13:
        i1 = _check_pointer(i1, 47116);
        i2 = OOC_ARRAY_LENGTH(i1, 0);
        i1 = *(OOC_UINT16*)(i1+(_check_index(i4, i2, OOC_UINT32, 47116))*2);
        i1 = i1==9u;
        
l15:
        if (i1) goto l16;
        goto l17;
l16:
        XML_Parser__ParserDesc_ParseDocument_Err(20);
l17:
        XML_Parser__ParserDesc_ParseDocument_ControlChar(10u);
        goto l8_loop;
      case 65535u:
        XML_Parser__ParserDesc_ParseDocument_ErrPos(6, (void*)(OOC_INT32)&pos, (RT0__Struct)i0);
        i1 = cpos;
        i2 = cdelta;
        i3 = cstart;
        i1 = (OOC_INT32)XML_Parser__ParserDesc_ParseDocument_GetString(i3, (i1-i2));
        return (XML_UnicodeBuffer__CharArray)i1;
        goto l8_loop;
      default:
        i2 = _check_pointer(i1, 47389);
        i3 = OOC_ARRAY_LENGTH(i2, 0);
        i2 = *(OOC_UINT16*)(i2+(_check_index(i4, i3, OOC_UINT32, 47389))*2);
        i3 = endChar;
        i2 = i2==i3;
        if (i2) goto l37;
        i2 = type;
        switch (i2) {
        case 2:
          i1 = _check_pointer(i1, 48193);
          i2 = OOC_ARRAY_LENGTH(i1, 0);
          i1 = *(OOC_UINT16*)(i1+(_check_index(i4, i2, OOC_UINT32, 48193))*2);
          i1 = XML_Parser__IsPubidChar(i1);
          i1 = !i1;
          if (i1) goto l25;
          goto l36;
l25:
          XML_Parser__ParserDesc_ParseDocument_Err(20);
          goto l36;
        case 4:
          i1 = _check_pointer(i1, 48339);
          i2 = OOC_ARRAY_LENGTH(i1, 0);
          i3 = cstart;
          i1 = *(OOC_UINT16*)(i1+(_check_index(i4, i2, OOC_UINT32, 48339))*2);
          i1 = XML_Parser__IsEncNameChar(i1, (i4==i3));
          i1 = !i1;
          if (i1) goto l29;
          goto l36;
l29:
          XML_Parser__ParserDesc_ParseDocument_Err(21);
          goto l36;
        case 3:
          i1 = _check_pointer(i1, 48504);
          i2 = OOC_ARRAY_LENGTH(i1, 0);
          i1 = *(OOC_UINT16*)(i1+(_check_index(i4, i2, OOC_UINT32, 48504))*2);
          i1 = XML_Parser__IsVersionNumChar(i1);
          i1 = !i1;
          if (i1) goto l33;
          goto l36;
l33:
          XML_Parser__ParserDesc_ParseDocument_Err(22);
          goto l36;
        default:
          goto l36;
        }
l36:
        i1 = (OOC_INT32)chars;
        i2 = _check_pointer(i1, 48653);
        i3 = cdelta;
        i4 = cpos;
        i5 = OOC_ARRAY_LENGTH(i2, 0);
        i1 = _check_pointer(i1, 48675);
        i6 = OOC_ARRAY_LENGTH(i1, 0);
        i1 = *(OOC_UINT16*)(i1+(_check_index(i4, i6, OOC_UINT32, 48675))*2);
        *(OOC_UINT16*)(i2+(_check_index((i4-i3), i5, OOC_UINT32, 48653))*2) = i1;
        cpos = (i4+1);
        goto l8_loop;
l37:
        i1 = type;
        i1 = i1==2;
        if (!i1) goto l40;
        XML_Parser__ParserDesc_ParseDocument_String_NormalizeWhitespace();
l40:
        i1 = cpos;
        i2 = cdelta;
        i3 = cstart;
        i1 = (OOC_INT32)XML_Parser__ParserDesc_ParseDocument_GetString(i3, (i1-i2));
        string = (XML_UnicodeBuffer__CharArray)i1;
        i2 = endChar;
        XML_Parser__ParserDesc_ParseDocument_CheckChar(i2);
        i2 = type;
        switch (i2) {
        case 5:
          i2 = (
          _cmp16((const void*)(_check_pointer(i1, 47719)),(const void*)((OOC_CHAR16[]){121,101,115,0})))!=0;
          if (i2) goto l45;
          i2=0u;
          goto l47;
l45:
          i2 = (
          _cmp16((const void*)(_check_pointer(i1, 47739)),(const void*)((OOC_CHAR16[]){110,111,0})))!=0;
          
l47:
          if (i2) goto l48;
          goto l55;
l48:
          XML_Parser__ParserDesc_ParseDocument_ErrPos(24, (void*)(OOC_INT32)&pos, (RT0__Struct)i0);
          goto l55;
        case 4:
        case 3:
          i2 = (
          _cmp16((const void*)(_check_pointer(i1, 47893)),(const void*)((OOC_CHAR16[]){0})))==0;
          if (i2) goto l52;
          goto l55;
l52:
          XML_Parser__ParserDesc_ParseDocument_ErrPos(23, (void*)(OOC_INT32)&pos, (RT0__Struct)i0);
          goto l55;
        default:
          goto l55;
        }
l55:
        return (XML_UnicodeBuffer__CharArray)i1;
        goto l8_loop;
      }
l59:
      _failed_function(45583); return 0;
      ;
    }

    
    void XML_Parser__ParserDesc_ParseDocument_Eq(void) {

      XML_Parser__ParserDesc_ParseDocument_OptS(1u);
      XML_Parser__ParserDesc_ParseDocument_CheckChar(61u);
      XML_Parser__ParserDesc_ParseDocument_OptS(1u);
      return;
      ;
    }

    
    void XML_Parser__ParserDesc_ParseDocument_XMLDecl(XML_DTD__ExternalEntity entity) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8;
      XML_UnicodeBuffer__CharArray string;
      OOC_CHAR8 *encoding;
      OOC_INT32 i;
      XML_UnicodeCodec__Factory codecFactory;

      i0 = cpos;
      i1 = (OOC_INT32)entity;
      _assert((i0==0), 127, 49256);
      _assert((i1!=(OOC_INT32)0), 127, 49281);
      i0 = i0+5;
      cpos = i0;
      i2 = (OOC_INT32)chars;
      i2 = _check_pointer(i2, 49382);
      i3 = OOC_ARRAY_LENGTH(i2, 0);
      i0 = *(OOC_UINT16*)(i2+(_check_index(i0, i3, OOC_UINT32, 49382))*2);
      i0 = i0!=63u;
      if (!i0) goto l3;
      XML_Parser__ParserDesc_ParseDocument_S();
l3:
      i0 = XML_Parser__ParserDesc_ParseDocument_LookingAt("version", 8, 1);
      if (i0) goto l9;
      i0 = *(OOC_INT8*)((_check_pointer(i1, 49654))+8);
      i0 = i0==5;
      if (!i0) goto l13;
      XML_Parser__ParserDesc_ParseDocument_Err(111);
      goto l13;
l9:
      i0 = cpos;
      cpos = (i0+7);
      XML_Parser__ParserDesc_ParseDocument_Eq();
      i0 = (OOC_INT32)XML_Parser__ParserDesc_ParseDocument_String(3);
      XML_DTD__ExternalEntityDesc_SetVersion((XML_DTD__ExternalEntity)i1, (XML_UnicodeBuffer__CharArray)i0);
      i0 = (OOC_INT32)chars;
      i0 = _check_pointer(i0, 49610);
      i2 = OOC_ARRAY_LENGTH(i0, 0);
      i3 = cpos;
      i0 = *(OOC_UINT16*)(i0+(_check_index(i3, i2, OOC_UINT32, 49610))*2);
      i0 = i0!=63u;
      if (!i0) goto l13;
      XML_Parser__ParserDesc_ParseDocument_S();
l13:
      i0 = XML_Parser__ParserDesc_ParseDocument_LookingAt("encoding", 9, 1);
      if (i0) goto l19;
      i0 = *(OOC_INT8*)((_check_pointer(i1, 50817))+8);
      i0 = i0!=5;
      if (!i0) goto l46;
      XML_Parser__ParserDesc_ParseDocument_Err(116);
      goto l46;
l19:
      i0 = cpos;
      cpos = (i0+8);
      XML_Parser__ParserDesc_ParseDocument_Eq();
      i0 = (OOC_INT32)XML_Parser__ParserDesc_ParseDocument_String(4);
      string = (XML_UnicodeBuffer__CharArray)i0;
      i2 = (OOC_INT32)p;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 49927))+36);
      i2 = *(OOC_UINT8*)((_check_pointer(i2, 49931))+16);
      if (i2) goto l22;
      i2=0u;
      goto l24;
l22:
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 49960))+44);
      i2 = i2==(OOC_INT32)0;
      
l24:
      if (!i2) goto l42;
      i2 = OOC_ARRAY_LENGTH((_check_pointer(i0, 50178)), 0);
      i2 = LongStrings__Length((void*)(_check_pointer(i0, 50178)), i2);
      i2 = (OOC_INT32)RT0__NewObject(_td_XML_Parser__49161.baseTypes[0], (i2+1));
      encoding = (void*)i2;
      i = 0;
      i3 = OOC_ARRAY_LENGTH((_check_pointer(i2, 50222)), 0);
      i4 = 0<i3;
      if (!i4) goto l37;
      i4=0;
l28_loop:
      i5 = _check_pointer(i0, 50252);
      i6 = OOC_ARRAY_LENGTH(i5, 0);
      i5 = *(OOC_UINT16*)(i5+(_check_index(i4, i6, OOC_UINT32, 50252))*2);
      i5 = (OOC_UINT16)i5>(OOC_UINT16)255u;
      if (i5) goto l31;
      i5 = _check_pointer(i2, 50347);
      i6 = OOC_ARRAY_LENGTH(i5, 0);
      i7 = _check_pointer(i0, 50367);
      i8 = OOC_ARRAY_LENGTH(i7, 0);
      i7 = *(OOC_UINT16*)(i7+(_check_index(i4, i8, OOC_UINT32, 50367))*2);
      *(OOC_UINT8*)(i5+(_check_index(i4, i6, OOC_UINT32, 50347))) = i7;
      goto l32;
l31:
      i5 = _check_pointer(i2, 50297);
      i6 = OOC_ARRAY_LENGTH(i5, 0);
      *(OOC_UINT8*)(i5+(_check_index(i4, i6, OOC_UINT32, 50297))) = 63u;
l32:
      i4 = i4+1;
      i = i4;
      i5 = i4<i3;
      if (i5) goto l28_loop;
l37:
      i3 = OOC_ARRAY_LENGTH((_check_pointer(i2, 50455)), 0);
      i2 = (OOC_INT32)XML_UnicodeCodec__GetFactory((void*)(_check_pointer(i2, 50455)), i3);
      codecFactory = (XML_UnicodeCodec__Factory)i2;
      i3 = i2==(OOC_INT32)0;
      if (i3) goto l40;
      i3 = (OOC_INT32)p;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 50569))+36);
      XML_UnicodeBuffer__InputDesc_SetCodec((XML_UnicodeBuffer__Input)i3, (XML_UnicodeCodec__Factory)i2, 0u);
      XML_Parser__ParserDesc_ParseDocument_ResetLocator();
      XML_Parser__ParserDesc_ParseDocument_XMLDecl((XML_DTD__ExternalEntity)i1);
      return;
      goto l42;
l40:
      XML_Parser__ParserDesc_ParseDocument_Err(29);
l42:
      XML_DTD__ExternalEntityDesc_SetEncoding((XML_DTD__ExternalEntity)i1, (XML_UnicodeBuffer__CharArray)i0);
      i0 = (OOC_INT32)chars;
      i0 = _check_pointer(i0, 50773);
      i2 = OOC_ARRAY_LENGTH(i0, 0);
      i3 = cpos;
      i0 = *(OOC_UINT16*)(i0+(_check_index(i3, i2, OOC_UINT32, 50773))*2);
      i0 = i0!=63u;
      if (!i0) goto l46;
      XML_Parser__ParserDesc_ParseDocument_S();
l46:
      i0 = *(OOC_INT8*)((_check_pointer(i1, 50913))+8);
      i0 = i0==5;
      if (i0) goto l49;
      i0=0u;
      goto l51;
l49:
      i0 = XML_Parser__ParserDesc_ParseDocument_LookingAt("standalone", 11, 1);
      
l51:
      if (!i0) goto l57;
      i0 = cpos;
      cpos = (i0+10);
      XML_Parser__ParserDesc_ParseDocument_Eq();
      i0 = (OOC_INT32)XML_Parser__ParserDesc_ParseDocument_String(5);
      string = (XML_UnicodeBuffer__CharArray)i0;
      i0 = (
      _cmp16((const void*)(_check_pointer(i0, 51143)),(const void*)((OOC_CHAR16[]){121,101,115,0})))==0;
      if (i0) goto l55;
      XML_DTD__ExternalEntityDesc_SetStandalone((XML_DTD__ExternalEntity)i1, 1);
      goto l57;
l55:
      XML_DTD__ExternalEntityDesc_SetStandalone((XML_DTD__ExternalEntity)i1, 0);
l57:
      XML_Parser__ParserDesc_ParseDocument_OptS(1u);
      i0 = XML_Parser__ParserDesc_ParseDocument_LookingAt("?>", 3, 0);
      if (i0) goto l60;
      XML_Parser__ParserDesc_ParseDocument_Err(114);
      goto l61;
l60:
      i0 = cpos;
      cpos = (i0+2);
l61:
      return;
      ;
    }

    
    XML_DTD__Entity XML_Parser__ParserDesc_ParseDocument_CurrentEntity(void) {
      register OOC_INT32 i0,i1,i2,i3;

      i0 = (OOC_INT32)p;
      i1 = *(OOC_INT32*)((_check_pointer(i0, 51516))+88);
      i1 = i1==0;
      if (i1) goto l3;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 51642))+84);
      i1 = _check_pointer(i1, 51651);
      i2 = *(OOC_INT32*)((_check_pointer(i0, 51653))+88);
      i3 = OOC_ARRAY_LENGTH(i1, 0);
      i1 = (OOC_INT32)*(OOC_INT32*)((i1+((_check_index((i2-1), i3, OOC_UINT32, 51651))*28))+20);
      _assert((i1!=(OOC_INT32)0), 127, 51633);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 51701))+84);
      i1 = _check_pointer(i1, 51710);
      i0 = *(OOC_INT32*)((_check_pointer(i0, 51712))+88);
      i2 = OOC_ARRAY_LENGTH(i1, 0);
      i0 = (OOC_INT32)*(OOC_INT32*)((i1+((_check_index((i0-1), i2, OOC_UINT32, 51710))*28))+20);
      return (XML_DTD__Entity)i0;
      goto l4;
l3:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 51556))+52);
      _assert((i1!=(OOC_INT32)0), 127, 51547);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 51597))+52);
      return (XML_DTD__Entity)i0;
l4:
      _failed_function(51465); return 0;
      ;
    }

    
    void XML_Parser__ParserDesc_ParseDocument_CheckCurrentEntity(XML_DTD__Entity reference) {
      register OOC_INT32 i0,i1;

      i0 = (OOC_INT32)p;
      i0 = *(OOC_UINT8*)((_check_pointer(i0, 51848))+62);
      if (i0) goto l3;
      i0=0u;
      goto l5;
l3:
      i0 = (OOC_INT32)XML_Parser__ParserDesc_ParseDocument_CurrentEntity();
      i1 = (OOC_INT32)reference;
      i0 = i1!=i0;
      
l5:
      if (!i0) goto l7;
      XML_Parser__ParserDesc_ParseDocument_ErrNF(306);
l7:
      return;
      ;
    }

    
    void XML_Parser__ParserDesc_ParseDocument_PI(void) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8;
      XML_DTD__Entity currentEntity;
      XML_UnicodeBuffer__CharArray target;
      auto OOC_CHAR8 XML_Parser__ParserDesc_ParseDocument_PI_IsReserved(const OOC_CHAR16 name__ref[], OOC_LEN name_0d);
        
        OOC_CHAR8 XML_Parser__ParserDesc_ParseDocument_PI_IsReserved(const OOC_CHAR16 name__ref[], OOC_LEN name_0d) {
          register OOC_INT32 i0;
          OOC_ALLOCATE_VPAR(name,OOC_CHAR16 ,name_0d)

          OOC_INITIALIZE_VPAR(name__ref,name,OOC_CHAR16 ,(name_0d*2))
          i0 = *(OOC_UINT16*)((OOC_INT32)name+(_check_index(0, name_0d, OOC_UINT8, 52208))*2);
          i0 = (_cap(i0))==88u;
          if (i0) goto l3;
          i0=0u;
          goto l5;
l3:
          i0 = *(OOC_UINT16*)((OOC_INT32)name+(_check_index(1, name_0d, OOC_UINT8, 52247))*2);
          i0 = (_cap(i0))==77u;
          
l5:
          if (i0) goto l7;
          i0=0u;
          goto l8;
l7:
          i0 = *(OOC_UINT16*)((OOC_INT32)name+(_check_index(2, name_0d, OOC_UINT8, 52286))*2);
          i0 = (_cap(i0))==76u;
          
l8:
          return i0;
          ;
        }


      i0 = (OOC_INT32)p;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 52357))+4);
      i1 = _check_pointer(i1, 52360);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 52357))+4);
      i1 = (OOC_INT32)&_td_XML_Locator__Position;
      XML_Parser__ParserDesc_ParseDocument_StorePosition((void*)(_check_pointer(i0, 52360)), (RT0__Struct)i1);
      i0 = (OOC_INT32)XML_Parser__ParserDesc_ParseDocument_CurrentEntity();
      i2 = cpos;
      currentEntity = (XML_DTD__Entity)i0;
      cpos = (i2+2);
      i2 = (OOC_INT32)XML_Parser__ParserDesc_ParseDocument_Name(1u);
      target = (XML_UnicodeBuffer__CharArray)i2;
      i3 = (
      _cmp16((const void*)(_check_pointer(i2, 52511)),(const void*)((OOC_CHAR16[]){120,109,108,0})))==0;
      if (i3) goto l6;
      i3 = OOC_ARRAY_LENGTH((_check_pointer(i2, 52603)), 0);
      i3 = XML_Parser__ParserDesc_ParseDocument_PI_IsReserved((void*)(_check_pointer(i2, 52603)), i3);
      if (!i3) goto l7;
      i3 = (OOC_INT32)p;
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 52646))+4);
      i4 = _check_pointer(i4, 52649);
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 52646))+4);
      XML_Parser__ParserDesc_ParseDocument_ErrPos(26, (void*)(_check_pointer(i3, 52649)), (RT0__Struct)i1);
      goto l7;
l6:
      i3 = (OOC_INT32)p;
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 52567))+4);
      i4 = _check_pointer(i4, 52570);
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 52567))+4);
      XML_Parser__ParserDesc_ParseDocument_ErrPos(25, (void*)(_check_pointer(i3, 52570)), (RT0__Struct)i1);
l7:
      i3 = XML_Parser__ParserDesc_ParseDocument_LookingAt("?>", 3, 0);
      if (i3) goto l22;
      XML_Parser__ParserDesc_ParseDocument_S();
      i3 = cpos;
      cstart = i3;
      cdelta = 0;
l10_loop:
      i3 = (OOC_INT32)chars;
      i4 = _check_pointer(i3, 52978);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      i6 = cpos;
      i4 = *(OOC_UINT16*)(i4+(_check_index(i6, i5, OOC_UINT32, 52978))*2);
      switch (i4) {
      case 0u ... 31u:
      case 65534u:
        XML_Parser__ParserDesc_ParseDocument_ControlChar(10u);
        goto l10_loop;
      case 65535u:
        i0 = (OOC_INT32)p;
        i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 53127))+4);
        i2 = _check_pointer(i2, 53130);
        i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 53127))+4);
        XML_Parser__ParserDesc_ParseDocument_ErrPos(7, (void*)(_check_pointer(i0, 53130)), (RT0__Struct)i1);
        goto l23;
      case 63u:
        i3 = XML_Parser__ParserDesc_ParseDocument_LookingAt("?>", 3, 0);
        if (i3) goto l18;
        i3 = (OOC_INT32)chars;
        i4 = _check_pointer(i3, 53578);
        i5 = cdelta;
        i6 = cpos;
        i7 = OOC_ARRAY_LENGTH(i4, 0);
        i3 = _check_pointer(i3, 53600);
        i8 = OOC_ARRAY_LENGTH(i3, 0);
        i3 = *(OOC_UINT16*)(i3+(_check_index(i6, i8, OOC_UINT32, 53600))*2);
        *(OOC_UINT16*)(i4+(_check_index((i6-i5), i7, OOC_UINT32, 53578))*2) = i3;
        cpos = (i6+1);
        
        goto l10_loop;
l18:
        XML_Parser__ParserDesc_ParseDocument_CheckCurrentEntity((XML_DTD__Entity)i0);
        i0 = (OOC_INT32)p;
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 53470))+56);
        i3 = (OOC_INT32)chars;
        i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 53285))+44);
        i5 = cpos;
        i6 = cdelta;
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 53482))+36);
        i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 53285))+44);
        i7 = OOC_ARRAY_LENGTH((_check_pointer(i3, 53332)), 0);
        i8 = cstart;
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 53294)))), XML_Builder__BuilderDesc_ProcessingInstruction)),XML_Builder__BuilderDesc_ProcessingInstruction)((XML_Builder__Builder)i0, (XML_UnicodeBuffer__CharArray)i2, (void*)(_check_pointer(i3, 53332)), i7, i8, (i5-i6), (URI__URI)i1);
        i0 = cpos;
        cpos = (i0+2);
        goto l23;
      default:
        i4 = _check_pointer(i3, 53667);
        i5 = cdelta;
        i7 = OOC_ARRAY_LENGTH(i4, 0);
        i3 = _check_pointer(i3, 53689);
        i8 = OOC_ARRAY_LENGTH(i3, 0);
        i3 = *(OOC_UINT16*)(i3+(_check_index(i6, i8, OOC_UINT32, 53689))*2);
        *(OOC_UINT16*)(i4+(_check_index((i6-i5), i7, OOC_UINT32, 53667))*2) = i3;
        cpos = (i6+1);
        goto l10_loop;
      }
l22:
      i0 = (OOC_INT32)p;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 52840))+56);
      i3 = (OOC_INT32)chars;
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 52725))+44);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 52852))+36);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 52725))+44);
      i5 = OOC_ARRAY_LENGTH((_check_pointer(i3, 52772)), 0);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 52734)))), XML_Builder__BuilderDesc_ProcessingInstruction)),XML_Builder__BuilderDesc_ProcessingInstruction)((XML_Builder__Builder)i0, (XML_UnicodeBuffer__CharArray)i2, (void*)(_check_pointer(i3, 52772)), i5, 0, 0, (URI__URI)i1);
      i0 = cpos;
      cpos = (i0+2);
l23:
      return;
      ;
    }

    
    void XML_Parser__ParserDesc_ParseDocument_Comment(void) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7;
      XML_DTD__Entity currentEntity;

      i0 = (OOC_INT32)p;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 53900))+4);
      i1 = _check_pointer(i1, 53903);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 53900))+4);
      i1 = (OOC_INT32)&_td_XML_Locator__Position;
      XML_Parser__ParserDesc_ParseDocument_StorePosition((void*)(_check_pointer(i0, 53903)), (RT0__Struct)i1);
      i0 = (OOC_INT32)XML_Parser__ParserDesc_ParseDocument_CurrentEntity();
      i2 = cpos;
      currentEntity = (XML_DTD__Entity)i0;
      i2 = i2+4;
      cpos = i2;
      cstart = i2;
      cdelta = 0;
l1_loop:
      i2 = (OOC_INT32)chars;
      i3 = _check_pointer(i2, 54075);
      i4 = OOC_ARRAY_LENGTH(i3, 0);
      i5 = cpos;
      i3 = *(OOC_UINT16*)(i3+(_check_index(i5, i4, OOC_UINT32, 54075))*2);
      switch (i3) {
      case 0u ... 31u:
      case 65534u:
        XML_Parser__ParserDesc_ParseDocument_ControlChar(10u);
        goto l1_loop;
      case 65535u:
        i0 = (OOC_INT32)p;
        i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 54221))+4);
        i2 = _check_pointer(i2, 54224);
        i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 54221))+4);
        XML_Parser__ParserDesc_ParseDocument_ErrPos(5, (void*)(_check_pointer(i0, 54224)), (RT0__Struct)i1);
        goto l15;
      case 45u:
        i2 = XML_Parser__ParserDesc_ParseDocument_LookingAt("-->", 4, 0);
        if (i2) goto l12;
        i2 = XML_Parser__ParserDesc_ParseDocument_LookingAt("--", 3, 0);
        if (i2) goto l9;
        goto l11;
l9:
        XML_Parser__ParserDesc_ParseDocument_Err(4);
l11:
        i2 = (OOC_INT32)chars;
        i3 = _check_pointer(i2, 54603);
        i4 = cpos;
        i5 = cdelta;
        i6 = OOC_ARRAY_LENGTH(i3, 0);
        i2 = _check_pointer(i2, 54625);
        i7 = OOC_ARRAY_LENGTH(i2, 0);
        i2 = *(OOC_UINT16*)(i2+(_check_index(i4, i7, OOC_UINT32, 54625))*2);
        *(OOC_UINT16*)(i3+(_check_index((i4-i5), i6, OOC_UINT32, 54603))*2) = i2;
        cpos = (i4+1);
        goto l1_loop;
l12:
        XML_Parser__ParserDesc_ParseDocument_CheckCurrentEntity((XML_DTD__Entity)i0);
        i0 = (OOC_INT32)chars;
        i1 = (OOC_INT32)p;
        i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 54370))+44);
        i3 = cpos;
        i4 = cdelta;
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 54370))+44);
        i5 = OOC_ARRAY_LENGTH((_check_pointer(i0, 54395)), 0);
        i6 = cstart;
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 54379)))), XML_Builder__BuilderDesc_Comment)),XML_Builder__BuilderDesc_Comment)((XML_Builder__Builder)i1, (void*)(_check_pointer(i0, 54395)), i5, i6, (i3-i4));
        i0 = cpos;
        cpos = (i0+3);
        goto l15;
      default:
        i3 = _check_pointer(i2, 54673);
        i4 = cdelta;
        i6 = OOC_ARRAY_LENGTH(i3, 0);
        i2 = _check_pointer(i2, 54695);
        i7 = OOC_ARRAY_LENGTH(i2, 0);
        i2 = *(OOC_UINT16*)(i2+(_check_index(i5, i7, OOC_UINT32, 54695))*2);
        *(OOC_UINT16*)(i3+(_check_index((i5-i4), i6, OOC_UINT32, 54673))*2) = i2;
        cpos = (i5+1);
        goto l1_loop;
      }
l15:
      XML_Parser__ParserDesc_ParseDocument_DiscardPreviousInput();
      return;
      ;
    }

    
    void XML_Parser__ParserDesc_ParseDocument_CDSect(void) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7;

      i0 = (OOC_INT32)p;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 54888))+4);
      i1 = _check_pointer(i1, 54891);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 54888))+4);
      i1 = (OOC_INT32)&_td_XML_Locator__Position;
      XML_Parser__ParserDesc_ParseDocument_StorePosition((void*)(_check_pointer(i0, 54891)), (RT0__Struct)i1);
      i0 = (OOC_INT32)p;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 54902))+44);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 54902))+44);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 54911)))), XML_Builder__BuilderDesc_StartCDATA)),XML_Builder__BuilderDesc_StartCDATA)((XML_Builder__Builder)i0);
      i0 = cpos;
      i0 = i0+9;
      cpos = i0;
      cstart = i0;
      cdelta = 0;
l1_loop:
      i0 = (OOC_INT32)chars;
      i2 = _check_pointer(i0, 55084);
      i3 = OOC_ARRAY_LENGTH(i2, 0);
      i4 = cpos;
      i2 = *(OOC_UINT16*)(i2+(_check_index(i4, i3, OOC_UINT32, 55084))*2);
      switch (i2) {
      case 0u ... 31u:
      case 65534u:
        XML_Parser__ParserDesc_ParseDocument_ControlChar(10u);
        goto l1_loop;
      case 65535u:
        i0 = (OOC_INT32)p;
        i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 55228))+4);
        i2 = _check_pointer(i2, 55231);
        i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 55228))+4);
        XML_Parser__ParserDesc_ParseDocument_ErrPos(8, (void*)(_check_pointer(i0, 55231)), (RT0__Struct)i1);
        goto l12;
      case 93u:
        i0 = XML_Parser__ParserDesc_ParseDocument_LookingAt("]]>", 4, 0);
        if (i0) goto l9;
        i0 = (OOC_INT32)chars;
        i2 = _check_pointer(i0, 55660);
        i3 = cdelta;
        i4 = cpos;
        i5 = OOC_ARRAY_LENGTH(i2, 0);
        i0 = _check_pointer(i0, 55682);
        i6 = OOC_ARRAY_LENGTH(i0, 0);
        i0 = *(OOC_UINT16*)(i0+(_check_index(i4, i6, OOC_UINT32, 55682))*2);
        *(OOC_UINT16*)(i2+(_check_index((i4-i3), i5, OOC_UINT32, 55660))*2) = i0;
        cpos = (i4+1);
        goto l1_loop;
l9:
        i0 = (OOC_INT32)p;
        i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 55340))+4);
        i2 = _check_pointer(i2, 55343);
        i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 55340))+4);
        XML_Parser__ParserDesc_ParseDocument_DecLength((void*)(_check_pointer(i0, 55343)), (RT0__Struct)i1, (-9));
        i0 = (OOC_INT32)chars;
        i2 = (OOC_INT32)p;
        i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 55364))+44);
        i4 = cpos;
        i5 = cdelta;
        i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 55364))+44);
        i6 = OOC_ARRAY_LENGTH((_check_pointer(i0, 55392)), 0);
        i7 = cstart;
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 55373)))), XML_Builder__BuilderDesc_Characters)),XML_Builder__BuilderDesc_Characters)((XML_Builder__Builder)i2, (void*)(_check_pointer(i0, 55392)), i6, i7, (i4-i5), 1);
        i0 = cpos;
        cpos = (i0+3);
        i0 = (OOC_INT32)p;
        i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 55548))+4);
        i2 = _check_pointer(i2, 55551);
        i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 55548))+4);
        XML_Parser__ParserDesc_ParseDocument_StorePosition((void*)(_check_pointer(i0, 55551)), (RT0__Struct)i1);
        i0 = (OOC_INT32)p;
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 55568))+44);
        i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 55568))+44);
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 55577)))), XML_Builder__BuilderDesc_EndCDATA)),XML_Builder__BuilderDesc_EndCDATA)((XML_Builder__Builder)i0);
        goto l12;
      default:
        i2 = _check_pointer(i0, 55743);
        i3 = cdelta;
        i5 = OOC_ARRAY_LENGTH(i2, 0);
        i0 = _check_pointer(i0, 55765);
        i6 = OOC_ARRAY_LENGTH(i0, 0);
        i0 = *(OOC_UINT16*)(i0+(_check_index(i4, i6, OOC_UINT32, 55765))*2);
        *(OOC_UINT16*)(i2+(_check_index((i4-i3), i5, OOC_UINT32, 55743))*2) = i0;
        cpos = (i4+1);
        goto l1_loop;
      }
l12:
      return;
      ;
    }

    
    void XML_Parser__ParserDesc_ParseDocument_CharRef(void) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5;
      struct XML_Locator__Position pos;
      OOC_INT32 cval;
      auto OOC_INT32 XML_Parser__ParserDesc_ParseDocument_CharRef_ToUnicode(OOC_INT32 cval);
        
        OOC_INT32 XML_Parser__ParserDesc_ParseDocument_CharRef_ToUnicode(OOC_INT32 cval) {
          register OOC_INT32 i0,i1,i2,i3,i4;

          i0 = cval;
          i1 = i0<=65535;
          if (i1) goto l3;
          i0 = i0-65536;
          cval = i0;
          i1 = (OOC_INT32)chars;
          i2 = _check_pointer(i1, 56523);
          i3 = cdelta;
          i4 = cpos;
          i3 = i4-i3;
          i4 = OOC_ARRAY_LENGTH(i2, 0);
          *(OOC_UINT16*)(i2+(_check_index(i3, i4, OOC_UINT32, 56523))*2) = (55296+(i0>>10));
          i1 = _check_pointer(i1, 56589);
          i2 = OOC_ARRAY_LENGTH(i1, 0);
          *(OOC_UINT16*)(i1+(_check_index((i3+1), i2, OOC_UINT32, 56589))*2) = (56320+(_mod(i0,1024)));
          return 2;
          goto l4;
l3:
          i1 = (OOC_INT32)chars;
          i1 = _check_pointer(i1, 56413);
          i2 = cdelta;
          i3 = cpos;
          i4 = OOC_ARRAY_LENGTH(i1, 0);
          *(OOC_UINT16*)(i1+(_check_index((i3-i2), i4, OOC_UINT32, 56413))*2) = i0;
          return 1;
l4:
          _failed_function(56313); return 0;
          ;
        }


      i0 = (OOC_INT32)&_td_XML_Locator__Position;
      XML_Parser__ParserDesc_ParseDocument_StorePosition((void*)(OOC_INT32)&pos, (RT0__Struct)i0);
      cval = 0;
      i1 = XML_Parser__ParserDesc_ParseDocument_LookingAt("&#x", 4, 0);
      if (i1) goto l15;
      i1 = cpos;
      i2 = cdelta;
      cpos = (i1+2);
      cdelta = (i2+2);
      i1=0;
l3_loop:
      i2 = (OOC_INT32)chars;
      i3 = _check_pointer(i2, 57555);
      i4 = OOC_ARRAY_LENGTH(i3, 0);
      i5 = cpos;
      i3 = *(OOC_UINT16*)(i3+(_check_index(i5, i4, OOC_UINT32, 57555))*2);
      switch (i3) {
      case 65534u:
        XML_Parser__ParserDesc_ParseDocument_NextBlock();
        
        goto l3_loop;
      case 59u:
      case 65535u:
        
        goto l33;
      case 48u ... 57u:
        i3 = i1<=131072;
        if (i3) goto l10;
        goto l11;
l10:
        i2 = _check_pointer(i2, 57772);
        i3 = OOC_ARRAY_LENGTH(i2, 0);
        i2 = *(OOC_UINT16*)(i2+(_check_index(i5, i3, OOC_UINT32, 57772))*2);
        i1 = ((i1*10)+i2)-48;
        cval = i1;
        
l11:
        i2 = cdelta;
        cpos = (i5+1);
        cdelta = (i2+1);
        
        goto l3_loop;
      default:
        XML_Parser__ParserDesc_ParseDocument_Err(14);
        cval = 32;
        i1=32;
        goto l33;
      }
l15:
      i1 = cpos;
      i2 = cdelta;
      cpos = (i1+3);
      cdelta = (i2+3);
      i1=0;
l16_loop:
      i2 = (OOC_INT32)chars;
      i3 = _check_pointer(i2, 56873);
      i4 = OOC_ARRAY_LENGTH(i3, 0);
      i5 = cpos;
      i3 = *(OOC_UINT16*)(i3+(_check_index(i5, i4, OOC_UINT32, 56873))*2);
      switch (i3) {
      case 65534u:
        XML_Parser__ParserDesc_ParseDocument_NextBlock();
        
        goto l16_loop;
      case 59u:
      case 65535u:
        
        goto l33;
      case 48u ... 57u:
        i3 = i1<=131072;
        if (i3) goto l23;
        goto l24;
l23:
        i2 = _check_pointer(i2, 57090);
        i3 = OOC_ARRAY_LENGTH(i2, 0);
        i2 = *(OOC_UINT16*)(i2+(_check_index(i5, i3, OOC_UINT32, 57090))*2);
        i1 = ((i1*16)+i2)-48;
        cval = i1;
        
l24:
        i2 = cdelta;
        cpos = (i5+1);
        cdelta = (i2+1);
        
        goto l16_loop;
      case 97u ... 102u:
      case 65u ... 70u:
        i3 = i1<=131072;
        if (i3) goto l28;
        goto l29;
l28:
        i2 = _check_pointer(i2, 57283);
        i3 = OOC_ARRAY_LENGTH(i2, 0);
        i2 = *(OOC_UINT16*)(i2+(_check_index(i5, i3, OOC_UINT32, 57283))*2);
        i1 = ((i1*16)+((_cap(i2))+10))-65;
        cval = i1;
        
l29:
        i2 = cdelta;
        cpos = (i5+1);
        cdelta = (i2+1);
        
        goto l16_loop;
      default:
        XML_Parser__ParserDesc_ParseDocument_Err(15);
        cval = 32;
        i1=32;
        goto l33;
      }
l33:
      i2 = (OOC_INT32)chars;
      i2 = _check_pointer(i2, 57979);
      i3 = OOC_ARRAY_LENGTH(i2, 0);
      i4 = cpos;
      i2 = *(OOC_UINT16*)(i2+(_check_index(i4, i3, OOC_UINT32, 57979))*2);
      i2 = i2==59u;
      if (!i2) goto l36;
      i2 = cdelta;
      cdelta = (i2+1);
l36:
      XML_Parser__ParserDesc_ParseDocument_CheckChar(59u);
      i2 = XML_Parser__IsCharUCS4(i1);
      i2 = !i2;
      if (i2) goto l39;
      i0=i1;
      goto l40;
l39:
      XML_Parser__ParserDesc_ParseDocument_ErrPos(17, (void*)(OOC_INT32)&pos, (RT0__Struct)i0);
      cval = 32;
      i0=32;
l40:
      i1 = cdelta;
      i0 = XML_Parser__ParserDesc_ParseDocument_CharRef_ToUnicode(i0);
      cdelta = (i1-i0);
      return;
      ;
    }

    
    XML_DTD__EntityRef XML_Parser__ParserDesc_ParseDocument_EntityRef(OOC_CHAR8 enforceDecl, OOC_CHAR8 permitExternal) {
      register OOC_INT32 i0,i1,i2,i3;
      struct XML_Locator__Position pos;
      OOC_INT32 localCStart;
      XML_UnicodeBuffer__CharArray name;
      XML_DTD__Declaration decl;
      XML_DTD__Entity entity;

      i0 = (OOC_INT32)&_td_XML_Locator__Position;
      XML_Parser__ParserDesc_ParseDocument_StorePosition((void*)(OOC_INT32)&pos, (RT0__Struct)i0);
      XML_Parser__ParserDesc_ParseDocument_CheckChar(38u);
      i1 = (OOC_INT32)p;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 58621))+36);
      i1 = *(OOC_INT32*)((_check_pointer(i1, 58625))+24);
      i2 = cstart;
      i1 = i1+i2;
      localCStart = i1;
      i2 = (OOC_INT32)XML_Parser__ParserDesc_ParseDocument_Name(1u);
      name = (XML_UnicodeBuffer__CharArray)i2;
      i3 = (OOC_INT32)p;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 58706))+36);
      i3 = *(OOC_INT32*)((_check_pointer(i3, 58710))+24);
      cstart = (i1-i3);
      XML_Parser__ParserDesc_ParseDocument_CheckChar(59u);
      i1 = (OOC_INT32)dtd;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 58775))+4);
      i1 = (OOC_INT32)XML_DTD__NamespaceDesc_Get((XML_DTD__Namespace)i1, (XML_UnicodeBuffer__CharArray)i2);
      decl = (XML_DTD__Declaration)i1;
      i3 = i1==(OOC_INT32)0;
      if (i3) goto l15;
      i1 = _type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 59095)))), &_td_XML_DTD__EntityDesc, 59095);
      entity = (XML_DTD__Entity)i1;
      i3 = *(OOC_INT8*)((_check_pointer(i1, 59122))+8);
      i3 = i3==4;
      if (i3) goto l13;
      i3 = permitExternal;
      i3 = !i3;
      if (i3) goto l7;
      i3=0u;
      goto l9;
l7:
      i3 = *(OOC_INT8*)((_check_pointer(i1, 59343))+8);
      i3 = i3==2;
      
l9:
      if (i3) goto l11;
      i0=i2;
      goto l14;
l11:
      XML_Parser__ParserDesc_ParseDocument_ErrPos(305, (void*)(OOC_INT32)&pos, (RT0__Struct)i0);
      i0 = OOC_ARRAY_LENGTH((_check_pointer(i2, 59506)), 0);
      i0 = (OOC_INT32)Msg__GetLStringPtr((void*)(_check_pointer(i2, 59506)), i0);
      i2 = (OOC_INT32)p;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 59444))+104);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 59444))+104);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 59455)))), Msg__MsgDesc_SetLStringAttrib)),Msg__MsgDesc_SetLStringAttrib)((Msg__Msg)i2, "name", 5, (Msg__LStringPtr)i0);
      i0 = (OOC_INT32)XML_Parser__noName;
      name = (XML_UnicodeBuffer__CharArray)i0;
      
      goto l14;
l13:
      XML_Parser__ParserDesc_ParseDocument_ErrPos(304, (void*)(OOC_INT32)&pos, (RT0__Struct)i0);
      i0 = OOC_ARRAY_LENGTH((_check_pointer(i2, 59274)), 0);
      i0 = (OOC_INT32)Msg__GetLStringPtr((void*)(_check_pointer(i2, 59274)), i0);
      i2 = (OOC_INT32)p;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 59212))+104);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 59212))+104);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 59223)))), Msg__MsgDesc_SetLStringAttrib)),Msg__MsgDesc_SetLStringAttrib)((Msg__Msg)i2, "name", 5, (Msg__LStringPtr)i0);
      i0 = (OOC_INT32)XML_Parser__noName;
      name = (XML_UnicodeBuffer__CharArray)i0;
      
l14:
      {register OOC_INT32 h0=i0;i0=i1;i1=h0;}
      goto l27;
l15:
      entity = (XML_DTD__Entity)(OOC_INT32)0;
      i1 = enforceDecl;
      if (i1) goto l18;
      i1=0u;
      goto l20;
l18:
      i1 = (OOC_INT32)p;
      i1 = *(OOC_UINT8*)((_check_pointer(i1, 58878))+63);
      
l20:
      if (i1) goto l22;
      i1=0u;
      goto l24;
l22:
      i1 = (OOC_INT32)XML_Parser__noName;
      i1 = i2!=i1;
      
l24:
      if (!i1) goto l26;
      XML_Parser__ParserDesc_ParseDocument_ErrPos(210, (void*)(OOC_INT32)&pos, (RT0__Struct)i0);
      i0 = OOC_ARRAY_LENGTH((_check_pointer(i2, 59041)), 0);
      i0 = (OOC_INT32)Msg__GetLStringPtr((void*)(_check_pointer(i2, 59041)), i0);
      i1 = (OOC_INT32)p;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 58979))+104);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 58979))+104);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 58990)))), Msg__MsgDesc_SetLStringAttrib)),Msg__MsgDesc_SetLStringAttrib)((Msg__Msg)i1, "name", 5, (Msg__LStringPtr)i0);
l26:
      i1=i2;i0=(OOC_INT32)0;
l27:
      i2 = (OOC_INT32)dtd;
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 59575)))), XML_DTD__BuilderDesc_NewEntityRef)),XML_DTD__BuilderDesc_NewEntityRef)((XML_DTD__Builder)i2, (XML_UnicodeBuffer__CharArray)i1, (XML_DTD__Entity)i0);
      return (XML_DTD__EntityRef)i0;
      ;
    }

    
    XML_DTD__AttValue XML_Parser__ParserDesc_ParseDocument_AttValue(OOC_CHAR8 isAttDecl) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
      XML_DTD__AttValue attValue;
      struct XML_Locator__Position pos;
      OOC_CHAR16 endChar;
      auto void XML_Parser__ParserDesc_ParseDocument_AttValue_Flush(void);
        
        void XML_Parser__ParserDesc_ParseDocument_AttValue_Flush(void) {
          register OOC_INT32 i0,i1,i2,i3,i4;

          i0 = cpos;
          i1 = cdelta;
          i0 = i0-i1;
          i1 = cstart;
          i2 = i0!=i1;
          if (!i2) goto l4;
          i2 = (OOC_INT32)dtd;
          i3 = (OOC_INT32)chars;
          i4 = isAttDecl;
          i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 60206)))), XML_DTD__BuilderDesc_NewCharacters)),XML_DTD__BuilderDesc_NewCharacters)((XML_DTD__Builder)i2, (XML_UnicodeBuffer__CharArray)i3, i1, i0, i4);
          i1 = (OOC_INT32)attValue;
          XML_DTD__AttValueDesc_Append((XML_DTD__AttValue)i1, (XML_DTD__Fragment)i0);
l4:
          return;
          ;
        }


      i0 = (OOC_INT32)dtd;
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 60329)))), XML_DTD__BuilderDesc_NewAttValue)),XML_DTD__BuilderDesc_NewAttValue)((XML_DTD__Builder)i0);
      attValue = (XML_DTD__AttValue)i0;
      i0 = (OOC_INT32)chars;
      i1 = _check_pointer(i0, 60361);
      i2 = OOC_ARRAY_LENGTH(i1, 0);
      i3 = cpos;
      i1 = *(OOC_UINT16*)(i1+(_check_index(i3, i2, OOC_UINT32, 60361))*2);
      i1 = i1==39u;
      if (i1) goto l3;
      i0 = _check_pointer(i0, 60384);
      i1 = OOC_ARRAY_LENGTH(i0, 0);
      i0 = *(OOC_UINT16*)(i0+(_check_index(i3, i1, OOC_UINT32, 60384))*2);
      i0 = i0==34u;
      
      goto l5;
l3:
      i0=1u;
l5:
      if (i0) goto l7;
      XML_Parser__ParserDesc_ParseDocument_Err(108);
      XML_Parser__ParserDesc_ParseDocument_NextChar();
      goto l25;
l7:
      i0 = (OOC_INT32)&_td_XML_Locator__Position;
      XML_Parser__ParserDesc_ParseDocument_StorePosition((void*)(OOC_INT32)&pos, (RT0__Struct)i0);
      i1 = (OOC_INT32)chars;
      i1 = _check_pointer(i1, 60456);
      i2 = OOC_ARRAY_LENGTH(i1, 0);
      i3 = cpos;
      i1 = *(OOC_UINT16*)(i1+(_check_index(i3, i2, OOC_UINT32, 60456))*2);
      endChar = i1;
      i1 = i3+1;
      cpos = i1;
      cstart = i1;
      cdelta = 0;
l8_loop:
      i1 = (OOC_INT32)chars;
      i2 = _check_pointer(i1, 60553);
      i3 = OOC_ARRAY_LENGTH(i2, 0);
      i4 = cpos;
      i2 = *(OOC_UINT16*)(i2+(_check_index(i4, i3, OOC_UINT32, 60553))*2);
      switch (i2) {
      case 0u ... 31u:
      case 65534u:
        XML_Parser__ParserDesc_ParseDocument_ControlChar(32u);
        goto l8_loop;
      case 65535u:
        XML_Parser__ParserDesc_ParseDocument_ErrPos(6, (void*)(OOC_INT32)&pos, (RT0__Struct)i0);
        XML_Parser__ParserDesc_ParseDocument_AttValue_Flush();
        goto l25;
      case 60u:
        XML_Parser__ParserDesc_ParseDocument_Err(13);
        i1 = (OOC_INT32)chars;
        i1 = _check_pointer(i1, 60812);
        i2 = cpos;
        i3 = cdelta;
        i4 = OOC_ARRAY_LENGTH(i1, 0);
        *(OOC_UINT16*)(i1+(_check_index((i2-i3), i4, OOC_UINT32, 60812))*2) = 32u;
        cpos = (i2+1);
        goto l8_loop;
      case 38u:
        i1 = XML_Parser__ParserDesc_ParseDocument_LookingAt("&#", 3, 0);
        if (!i1) goto l15;
        goto l16;
l15:
        XML_Parser__ParserDesc_ParseDocument_AttValue_Flush();
        i1 = (OOC_INT32)XML_Parser__ParserDesc_ParseDocument_EntityRef(1u, 0u);
        i2 = (OOC_INT32)attValue;
        XML_DTD__AttValueDesc_Append((XML_DTD__AttValue)i2, (XML_DTD__Fragment)i1);
        i1 = cpos;
        cstart = i1;
        cdelta = 0;
        goto l8_loop;
l16:
        XML_Parser__ParserDesc_ParseDocument_CharRef();
        goto l8_loop;
      default:
        i2 = _check_pointer(i1, 61201);
        i3 = OOC_ARRAY_LENGTH(i2, 0);
        i2 = *(OOC_UINT16*)(i2+(_check_index(i4, i3, OOC_UINT32, 61201))*2);
        i3 = endChar;
        i2 = i2==i3;
        if (i2) goto l22;
        i2 = _check_pointer(i1, 61566);
        i3 = cdelta;
        i5 = OOC_ARRAY_LENGTH(i2, 0);
        i1 = _check_pointer(i1, 61588);
        i6 = OOC_ARRAY_LENGTH(i1, 0);
        i1 = *(OOC_UINT16*)(i1+(_check_index(i4, i6, OOC_UINT32, 61588))*2);
        *(OOC_UINT16*)(i2+(_check_index((i4-i3), i5, OOC_UINT32, 61566))*2) = i1;
        cpos = (i4+1);
        goto l8_loop;
l22:
        XML_Parser__ParserDesc_ParseDocument_AttValue_Flush();
        i0 = endChar;
        XML_Parser__ParserDesc_ParseDocument_CheckChar(i0);
        goto l25;
      }
l25:
      i0 = (OOC_INT32)attValue;
      return (XML_DTD__AttValue)i0;
      ;
    }

    
    void XML_Parser__ParserDesc_ParseDocument_Expand(XML_DTD__AttValue attValue) {
      register OOC_INT32 i0,i1,i2;
      XML_DTD__Fragment fragment;
      XML_DTD__Declaration decl;
      XML_DTD__Entity entity;
      auto XML_DTD__AttValue XML_Parser__ParserDesc_ParseDocument_Expand_ExpandAttValue(XML_DTD__Entity entity);
      auto OOC_CHAR8 XML_Parser__ParserDesc_ParseDocument_Expand_IsRecursive(XML_DTD__Entity entity);
      auto XML_DTD__AttValue XML_Parser__ParserDesc_ParseDocument_Expand_ExpandAttValue(XML_DTD__Entity entity);
        
        OOC_CHAR8 XML_Parser__ParserDesc_ParseDocument_Expand_IsRecursive(XML_DTD__Entity entity) {
          register OOC_INT32 i0,i1,i2;
          XML_DTD__Fragment fragment;

          i0 = (OOC_INT32)entity;
          i1 = *(OOC_UINT8*)((_check_pointer(i0, 62143))+17);
          if (i1) goto l24;
          *(OOC_UINT8*)((_check_pointer(i0, 62211))+17) = 1u;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 62252))+20);
          i1 = i1==(OOC_INT32)0;
          if (!i1) goto l5;
          i1 = (OOC_INT32)XML_Parser__ParserDesc_ParseDocument_Expand_ExpandAttValue((XML_DTD__Entity)i0);
          *(OOC_INT32*)((_check_pointer(i0, 62293))+20) = i1;
l5:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 62374))+20);
          i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 62384));
          fragment = (XML_DTD__Fragment)i1;
          i2 = i1!=(OOC_INT32)0;
          if (!i2) goto l23;
l8_loop:
          i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 62461)))), &_td_XML_DTD__EntityRefDesc);
          if (!i2) goto l18;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 62506))+8);
          i2 = i2!=(OOC_INT32)0;
          if (i2) goto l13;
          i2=0u;
          goto l15;
l13:
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 62562))+8);
          i2 = XML_Parser__ParserDesc_ParseDocument_Expand_IsRecursive((XML_DTD__Entity)i2);
          
l15:
          if (!i2) goto l18;
          *(OOC_UINT8*)((_check_pointer(i0, 62599))+17) = 0u;
          return 1u;
l18:
          i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 62772));
          fragment = (XML_DTD__Fragment)i1;
          i2 = i1!=(OOC_INT32)0;
          if (i2) goto l8_loop;
l23:
          *(OOC_UINT8*)((_check_pointer(i0, 62810))+17) = 0u;
          return 0u;
          goto l25;
l24:
          return 1u;
l25:
          _failed_function(62013); return 0;
          ;
        }

        
        XML_DTD__AttValue XML_Parser__ParserDesc_ParseDocument_Expand_ExpandAttValue(XML_DTD__Entity entity) {
          register OOC_INT32 i0,i1,i2,i3,i4;
          XML_DTD__AttValue attValue;
          auto void XML_Parser__ParserDesc_ParseDocument_Expand_ExpandAttValue_Flush(void);
            
            void XML_Parser__ParserDesc_ParseDocument_Expand_ExpandAttValue_Flush(void) {
              register OOC_INT32 i0,i1,i2,i3;

              i0 = cpos;
              i1 = cstart;
              i2 = i0!=i1;
              if (!i2) goto l3;
              i2 = (OOC_INT32)dtd;
              i3 = (OOC_INT32)chars;
              i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 63123)))), XML_DTD__BuilderDesc_NewCharacters)),XML_DTD__BuilderDesc_NewCharacters)((XML_DTD__Builder)i2, (XML_UnicodeBuffer__CharArray)i3, i1, i0, 0u);
              i1 = (OOC_INT32)attValue;
              XML_DTD__AttValueDesc_Append((XML_DTD__AttValue)i1, (XML_DTD__Fragment)i0);
l3:
              return;
              ;
            }


          i0 = (OOC_INT32)entity;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 63234)))), &_td_XML_DTD__ExternalEntityDesc);
          if (!i1) goto l3;
          i1 = (OOC_INT32)XML_Parser__ParserDesc_ParseDocument_Internalize((XML_DTD__ExternalEntity)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 63320)))), &_td_XML_DTD__ExternalEntityDesc, 63320)));
          XML_DTD__EntityDesc_SetEntityValue((XML_DTD__Entity)i0, (XML_UnicodeBuffer__CharArray)i1);
l3:
          XML_Parser__ParserDesc_ParseDocument_PushEntity((XML_DTD__Entity)i0, 0u);
          i0 = (OOC_INT32)dtd;
          i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 63411)))), XML_DTD__BuilderDesc_NewAttValue)),XML_DTD__BuilderDesc_NewAttValue)((XML_DTD__Builder)i0);
          attValue = (XML_DTD__AttValue)i0;
          i0 = cpos;
          cstart = i0;
l4_loop:
          i0 = (OOC_INT32)chars;
          i1 = _check_pointer(i0, 63485);
          i2 = OOC_ARRAY_LENGTH(i1, 0);
          i3 = cpos;
          i1 = *(OOC_UINT16*)(i1+(_check_index(i3, i2, OOC_UINT32, 63485))*2);
          switch (i1) {
          case 65535u:
            XML_Parser__ParserDesc_ParseDocument_Expand_ExpandAttValue_Flush();
            goto l19;
          case 0u ... 31u:
            i1 = _check_pointer(i0, 63789);
            i2 = OOC_ARRAY_LENGTH(i1, 0);
            i1 = *(OOC_UINT16*)(i1+(_check_index(i3, i2, OOC_UINT32, 63789))*2);
            i1 = i1!=9u;
            if (!i1) goto l4_loop;
            i0 = _check_pointer(i0, 63832);
            i1 = OOC_ARRAY_LENGTH(i0, 0);
            *(OOC_UINT16*)(i0+(_check_index(i3, i1, OOC_UINT32, 63832))*2) = 32u;
            goto l4_loop;
          case 60u:
            XML_Parser__ParserDesc_ParseDocument_Err(13);
            i0 = cpos;
            cpos = (i0+1);
            goto l4_loop;
          case 38u:
            XML_Parser__ParserDesc_ParseDocument_Expand_ExpandAttValue_Flush();
            i0 = XML_Parser__ParserDesc_ParseDocument_LookingAt("&#", 3, 0);
            if (i0) goto l15;
            i0 = (OOC_INT32)XML_Parser__ParserDesc_ParseDocument_EntityRef(1u, 0u);
            i1 = (OOC_INT32)attValue;
            XML_DTD__AttValueDesc_Append((XML_DTD__AttValue)i1, (XML_DTD__Fragment)i0);
            goto l16;
l15:
            i0 = cpos;
            cstart = i0;
            cdelta = 0;
            XML_Parser__ParserDesc_ParseDocument_CharRef();
            i0 = (OOC_INT32)dtd;
            i1 = cpos;
            i2 = cdelta;
            i3 = cstart;
            i4 = (OOC_INT32)chars;
            i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 64201)))), XML_DTD__BuilderDesc_NewCharacters)),XML_DTD__BuilderDesc_NewCharacters)((XML_DTD__Builder)i0, (XML_UnicodeBuffer__CharArray)i4, i3, (i1-i2), 0u);
            i1 = (OOC_INT32)attValue;
            XML_DTD__AttValueDesc_Append((XML_DTD__AttValue)i1, (XML_DTD__Fragment)i0);
l16:
            i0 = cpos;
            cstart = i0;
            goto l4_loop;
          default:
            cpos = (i3+1);
            goto l4_loop;
          }
l19:
          XML_Parser__ParserDesc_ParseDocument_PopEntity();
          i0 = (OOC_INT32)attValue;
          return (XML_DTD__AttValue)i0;
          ;
        }


      i0 = (OOC_INT32)attValue;
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 64543));
      fragment = (XML_DTD__Fragment)i0;
      i1 = i0!=0;
      if (!i1) goto l22;
l3_loop:
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 64612)))), &_td_XML_DTD__EntityRefDesc);
      if (!i1) goto l17;
      i1 = (OOC_INT32)dtd;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 64680))+4);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 64652))+4);
      i1 = (OOC_INT32)XML_DTD__NamespaceDesc_Get((XML_DTD__Namespace)i1, (XML_UnicodeBuffer__CharArray)i2);
      decl = (XML_DTD__Declaration)i1;
      i2 = i1==0;
      if (i2) goto l15;
      i1 = _type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 64894)))), &_td_XML_DTD__EntityDesc, 64894);
      entity = (XML_DTD__Entity)i1;
      *(OOC_INT32*)((_check_pointer(i0, 64923))+8) = i1;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 64965))+20);
      i0 = i0==0;
      if (i0) goto l10;
      i0=i1;
      goto l11;
l10:
      i0 = (OOC_INT32)XML_Parser__ParserDesc_ParseDocument_Expand_ExpandAttValue((XML_DTD__Entity)i1);
      *(OOC_INT32*)((_check_pointer(i1, 65008))+20) = i0;
      i0 = (OOC_INT32)entity;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 65075))+20);
      XML_Parser__ParserDesc_ParseDocument_Expand((XML_DTD__AttValue)i1);
      
l11:
      i0 = XML_Parser__ParserDesc_ParseDocument_Expand_IsRecursive((XML_DTD__Entity)i0);
      if (!i0) goto l17;
      XML_Parser__ParserDesc_ParseDocument_Err(213);
      i0 = (OOC_INT32)entity;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 65269))+4);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 65269))+4);
      i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 65275)), 0);
      i0 = (OOC_INT32)Msg__GetLStringPtr((void*)(_check_pointer(i0, 65275)), i1);
      i1 = (OOC_INT32)p;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 65205))+104);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 65205))+104);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 65216)))), Msg__MsgDesc_SetLStringAttrib)),Msg__MsgDesc_SetLStringAttrib)((Msg__Msg)i1, "name", 5, (Msg__LStringPtr)i0);
      i0 = (OOC_INT32)fragment;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 65302))+8);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 65310))+20);
      XML_DTD__AttValueDesc_Clear((XML_DTD__AttValue)i0);
      goto l17;
l15:
      XML_Parser__ParserDesc_ParseDocument_Err(210);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 64838))+4);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 64838))+4);
      i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 64844)), 0);
      i0 = (OOC_INT32)Msg__GetLStringPtr((void*)(_check_pointer(i0, 64844)), i1);
      i1 = (OOC_INT32)p;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 64772))+104);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 64772))+104);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 64783)))), Msg__MsgDesc_SetLStringAttrib)),Msg__MsgDesc_SetLStringAttrib)((Msg__Msg)i1, "name", 5, (Msg__LStringPtr)i0);
l17:
      i0 = (OOC_INT32)fragment;
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 65467));
      fragment = (XML_DTD__Fragment)i0;
      i1 = i0!=0;
      if (i1) goto l3_loop;
l22:
      return;
      ;
    }

    
    void XML_Parser__ParserDesc_ParseDocument_content(void) {
      register OOC_INT32 i0,i1,i2;
      auto void XML_Parser__ParserDesc_ParseDocument_content_CharData(void);
      auto void XML_Parser__ParserDesc_ParseDocument_content_FollowEntityRef(XML_DTD__EntityRef entityRef);
        
        void XML_Parser__ParserDesc_ParseDocument_content_CharData(void) {
          register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
          OOC_INT8 elementWhitespace;

          i0 = (OOC_INT32)p;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 66008))+4);
          i1 = _check_pointer(i1, 66011);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 66008))+4);
          XML_Parser__ParserDesc_ParseDocument_StorePosition((void*)(_check_pointer(i0, 66011)), (RT0__Struct)((OOC_INT32)&_td_XML_Locator__Position));
          i0 = cpos;
          cstart = i0;
          cdelta = 0;
          elementWhitespace = 2;
          i0=2;
l1_loop:
          i1 = (OOC_INT32)chars;
          i2 = _check_pointer(i1, 66372);
          i3 = OOC_ARRAY_LENGTH(i2, 0);
          i4 = cpos;
          i2 = *(OOC_UINT16*)(i2+(_check_index(i4, i3, OOC_UINT32, 66372))*2);
          switch (i2) {
          case 0u ... 31u:
          case 65534u:
            i2 = (OOC_INT32)p;
            i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 66447))+36);
            i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 66451))+20);
            i1 = i1!=i2;
            if (!i1) goto l5;
            goto l9;
l5:
            XML_Parser__ParserDesc_ParseDocument_ControlChar(10u);
            i1 = cdelta;
            i1 = i1!=0;
            if (!i1) goto l1_loop;
            goto l21_loop;
l9:
            cpos = (i4+1);
            goto l1_loop;
          case 32u:
            cpos = (i4+1);
            
            goto l1_loop;
          case 60u:
          case 38u:
          case 65535u:
            goto l21_loop;
          case 93u:
            i1 = XML_Parser__ParserDesc_ParseDocument_LookingAt("]]>", 4, 0);
            if (i1) goto l21_loop;
            i0 = cpos;
            elementWhitespace = 1;
            cpos = (i0+1);
            i0=1;
            goto l1_loop;
          default:
            elementWhitespace = 1;
            cpos = (i4+1);
            i0=1;
            goto l1_loop;
          }
l21_loop:
          i1 = (OOC_INT32)chars;
          i2 = _check_pointer(i1, 67096);
          i3 = OOC_ARRAY_LENGTH(i2, 0);
          i4 = cpos;
          i2 = *(OOC_UINT16*)(i2+(_check_index(i4, i3, OOC_UINT32, 67096))*2);
          switch (i2) {
          case 0u ... 31u:
          case 65534u:
            i2 = (OOC_INT32)p;
            i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 67171))+36);
            i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 67175))+20);
            i2 = i1!=i2;
            if (!i2) goto l25;
            goto l26;
l25:
            XML_Parser__ParserDesc_ParseDocument_ControlChar(10u);
            goto l21_loop;
l26:
            i2 = _check_pointer(i1, 67571);
            i3 = cdelta;
            i5 = OOC_ARRAY_LENGTH(i2, 0);
            i1 = _check_pointer(i1, 67593);
            i6 = OOC_ARRAY_LENGTH(i1, 0);
            i1 = *(OOC_UINT16*)(i1+(_check_index(i4, i6, OOC_UINT32, 67593))*2);
            *(OOC_UINT16*)(i2+(_check_index((i4-i3), i5, OOC_UINT32, 67571))*2) = i1;
            cpos = (i4+1);
            goto l21_loop;
          case 32u:
            i2 = _check_pointer(i1, 67716);
            i3 = cdelta;
            i5 = OOC_ARRAY_LENGTH(i2, 0);
            i1 = _check_pointer(i1, 67738);
            i6 = OOC_ARRAY_LENGTH(i1, 0);
            i1 = *(OOC_UINT16*)(i1+(_check_index(i4, i6, OOC_UINT32, 67738))*2);
            *(OOC_UINT16*)(i2+(_check_index((i4-i3), i5, OOC_UINT32, 67716))*2) = i1;
            cpos = (i4+1);
            
            goto l21_loop;
          case 60u:
          case 65535u:
            goto l41;
          case 38u:
            i1 = XML_Parser__ParserDesc_ParseDocument_LookingAt("&#", 3, 0);
            if (!i1) goto l41;
            elementWhitespace = 1;
            XML_Parser__ParserDesc_ParseDocument_CharRef();
            i0=1;
            goto l21_loop;
          case 93u:
            i0 = XML_Parser__ParserDesc_ParseDocument_LookingAt("]]>", 4, 0);
            if (i0) goto l37;
            goto l38;
l37:
            XML_Parser__ParserDesc_ParseDocument_Err(3);
l38:
            elementWhitespace = 1;
            i0 = (OOC_INT32)chars;
            i1 = _check_pointer(i0, 68240);
            i2 = cdelta;
            i3 = cpos;
            i4 = OOC_ARRAY_LENGTH(i1, 0);
            i0 = _check_pointer(i0, 68262);
            i5 = OOC_ARRAY_LENGTH(i0, 0);
            i0 = *(OOC_UINT16*)(i0+(_check_index(i3, i5, OOC_UINT32, 68262))*2);
            *(OOC_UINT16*)(i1+(_check_index((i3-i2), i4, OOC_UINT32, 68240))*2) = i0;
            cpos = (i3+1);
            i0=1;
            goto l21_loop;
          default:
            elementWhitespace = 1;
            i0 = _check_pointer(i1, 68371);
            i2 = cdelta;
            i3 = OOC_ARRAY_LENGTH(i0, 0);
            i1 = _check_pointer(i1, 68393);
            i5 = OOC_ARRAY_LENGTH(i1, 0);
            i1 = *(OOC_UINT16*)(i1+(_check_index(i4, i5, OOC_UINT32, 68393))*2);
            *(OOC_UINT16*)(i0+(_check_index((i4-i2), i3, OOC_UINT32, 68371))*2) = i1;
            cpos = (i4+1);
            i0=1;
            goto l21_loop;
          }
l41:
          i1 = cdelta;
          i2 = cpos;
          i1 = i2-i1;
          i2 = cstart;
          i3 = i1!=i2;
          if (!i3) goto l44;
          i3 = (OOC_INT32)chars;
          i4 = (OOC_INT32)p;
          i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 68490))+44);
          i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 68490))+44);
          i6 = OOC_ARRAY_LENGTH((_check_pointer(i3, 68518)), 0);
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 68499)))), XML_Builder__BuilderDesc_Characters)),XML_Builder__BuilderDesc_Characters)((XML_Builder__Builder)i4, (void*)(_check_pointer(i3, 68518)), i6, i2, i1, i0);
l44:
          return;
          ;
        }

        
        void XML_Parser__ParserDesc_ParseDocument_content_FollowEntityRef(XML_DTD__EntityRef entityRef) {
          register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
          XML_DTD__Declaration decl;
          XML_DTD__Entity entity;
          struct XML_Locator__Position pos;

          i0 = (OOC_INT32)entityRef;
          i1 = (OOC_INT32)dtd;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 68848))+4);
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 68877))+4);
          i1 = (OOC_INT32)XML_DTD__NamespaceDesc_Get((XML_DTD__Namespace)i1, (XML_UnicodeBuffer__CharArray)i2);
          decl = (XML_DTD__Declaration)i1;
          entity = (XML_DTD__Entity)(OOC_INT32)0;
          i2 = i1!=(OOC_INT32)0;
          if (i2) goto l3;
          i2=(OOC_INT32)0;
          goto l4;
l3:
          i2 = _type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 68967)))), &_td_XML_DTD__EntityDesc, 68967);
          entity = (XML_DTD__Entity)i2;
          
l4:
          i3 = (OOC_INT32)p;
          i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 69012))+4);
          i4 = _check_pointer(i4, 69015);
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 69012))+4);
          i4 = (OOC_INT32)&_td_XML_Locator__Position;
          XML_Parser__ParserDesc_ParseDocument_StorePosition((void*)(_check_pointer(i3, 69015)), (RT0__Struct)i4);
          i3 = (OOC_INT32)p;
          i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 69040))+36);
          i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 69044))+20);
          i6 = (OOC_INT32)chars;
          i5 = i6==i5;
          if (!i5) goto l7;
          i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 69115))+4);
          i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 69115))+4);
          i5 = OOC_ARRAY_LENGTH((_check_pointer(i5, 69121)), 0);
          i5 = LongStrings__Length((void*)(_check_pointer(i6, 69121)), i5);
          i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 69080))+4);
          i6 = _check_pointer(i6, 69083);
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 69080))+4);
          XML_Parser__ParserDesc_ParseDocument_DecLength((void*)(_check_pointer(i3, 69083)), (RT0__Struct)i4, (i5+2));
l7:
          i3 = i2==(OOC_INT32)0;
          if (i3) goto l32;
          i3 = *(OOC_UINT8*)((_check_pointer(i2, 69366))+17);
          if (i3) goto l30;
          i3 = *(OOC_INT8*)((_check_pointer(i2, 69571))+8);
          i3 = i3==2;
          if (i3) goto l14;
          i3=0u;
          goto l16;
l14:
          i3 = (OOC_INT32)p;
          i3 = *(OOC_UINT8*)((_check_pointer(i3, 69625))+60);
          i3 = !i3;
          
l16:
          if (i3) goto l28;
          i3 = (OOC_INT32)p;
          i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 69751))+44);
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 69751))+44);
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 69760)))), XML_Builder__BuilderDesc_StartEntity)),XML_Builder__BuilderDesc_StartEntity)((XML_Builder__Builder)i3, (XML_DTD__Entity)i2);
          XML_Parser__ParserDesc_ParseDocument_PushEntity((XML_DTD__Entity)i2, 1u);
          XML_Parser__ParserDesc_ParseDocument_StorePosition((void*)(OOC_INT32)&pos, (RT0__Struct)i4);
          i3 = *(OOC_INT8*)((_check_pointer(i2, 69954))+8);
          i3 = i3==2;
          if (i3) goto l20;
          i3=0u;
          goto l22;
l20:
          i3 = XML_Parser__ParserDesc_ParseDocument_LookingAt("<?xml", 6, 1);
          
l22:
          if (!i3) goto l24;
          XML_Parser__ParserDesc_ParseDocument_XMLDecl((XML_DTD__ExternalEntity)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 70079)))), &_td_XML_DTD__ExternalEntityDesc, 70079)));
l24:
          XML_Parser__ParserDesc_ParseDocument_content();
          i1 = (OOC_INT32)chars;
          i1 = _check_pointer(i1, 70149);
          i3 = OOC_ARRAY_LENGTH(i1, 0);
          i5 = cpos;
          i1 = *(OOC_UINT16*)(i1+(_check_index(i5, i3, OOC_UINT32, 70149))*2);
          i1 = i1!=65535u;
          if (!i1) goto l27;
          XML_Parser__ParserDesc_ParseDocument_ErrPos(302, (void*)(OOC_INT32)&pos, (RT0__Struct)i4);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 70349))+4);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 70349))+4);
          i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 70355)), 0);
          i0 = (OOC_INT32)Msg__GetLStringPtr((void*)(_check_pointer(i0, 70355)), i1);
          i1 = (OOC_INT32)p;
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 70242))+104);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 70242))+104);
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 70253)))), Msg__MsgDesc_SetLStringAttrib)),Msg__MsgDesc_SetLStringAttrib)((Msg__Msg)i1, "name", 5, (Msg__LStringPtr)i0);
l27:
          XML_Parser__ParserDesc_ParseDocument_PopEntity();
          i0 = (OOC_INT32)p;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 70421))+4);
          i1 = _check_pointer(i1, 70424);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 70421))+4);
          XML_Parser__ParserDesc_ParseDocument_StorePosition((void*)(_check_pointer(i0, 70424)), (RT0__Struct)i4);
          i0 = (OOC_INT32)p;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 70439))+44);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 70439))+44);
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 70448)))), XML_Builder__BuilderDesc_EndEntity)),XML_Builder__BuilderDesc_EndEntity)((XML_Builder__Builder)i0, (XML_DTD__Entity)i2);
          goto l33;
l28:
          i1 = (OOC_INT32)p;
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 69661))+44);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 69696))+4);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 69661))+44);
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 69670)))), XML_Builder__BuilderDesc_SkippedEntity)),XML_Builder__BuilderDesc_SkippedEntity)((XML_Builder__Builder)i1, (XML_UnicodeBuffer__CharArray)i0, (XML_DTD__Entity)i2);
          goto l33;
l30:
          XML_Parser__ParserDesc_ParseDocument_Err(213);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 69540))+4);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 69540))+4);
          i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 69546)), 0);
          i0 = (OOC_INT32)Msg__GetLStringPtr((void*)(_check_pointer(i0, 69546)), i1);
          i1 = (OOC_INT32)p;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 69434))+104);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 69434))+104);
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 69445)))), Msg__MsgDesc_SetLStringAttrib)),Msg__MsgDesc_SetLStringAttrib)((Msg__Msg)i1, "name", 5, (Msg__LStringPtr)i0);
          goto l33;
l32:
          i1 = (OOC_INT32)p;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 69212))+4);
          i2 = _check_pointer(i2, 69215);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 69212))+4);
          XML_Parser__ParserDesc_ParseDocument_ErrPos(210, (void*)(_check_pointer(i1, 69215)), (RT0__Struct)i4);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 69336))+4);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 69336))+4);
          i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 69342)), 0);
          i0 = (OOC_INT32)Msg__GetLStringPtr((void*)(_check_pointer(i0, 69342)), i1);
          i1 = (OOC_INT32)p;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 69230))+104);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 69230))+104);
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 69241)))), Msg__MsgDesc_SetLStringAttrib)),Msg__MsgDesc_SetLStringAttrib)((Msg__Msg)i1, "name", 5, (Msg__LStringPtr)i0);
l33:
          return;
          ;
        }


l1_loop:
      i0 = (OOC_INT32)chars;
      i0 = _check_pointer(i0, 70564);
      i1 = OOC_ARRAY_LENGTH(i0, 0);
      i2 = cpos;
      i0 = *(OOC_UINT16*)(i0+(_check_index(i2, i1, OOC_UINT32, 70564))*2);
      switch (i0) {
      case 65535u:
        goto l28;
      case 60u:
        i0 = XML_Parser__ParserDesc_ParseDocument_LookingAt("<!--", 5, 0);
        if (!i0) goto l6;
        goto l19;
l6:
        i0 = XML_Parser__ParserDesc_ParseDocument_LookingAt("<![CDATA[", 10, 0);
        if (!i0) goto l8;
        goto l17;
l8:
        i0 = XML_Parser__ParserDesc_ParseDocument_LookingAt("<?", 3, 0);
        if (!i0) goto l10;
        goto l15;
l10:
        i0 = (OOC_INT32)chars;
        i0 = _check_pointer(i0, 70873);
        i1 = cpos;
        i2 = OOC_ARRAY_LENGTH(i0, 0);
        i0 = *(OOC_UINT16*)(i0+(_check_index((i1+1), i2, OOC_UINT32, 70873))*2);
        i0 = i0!=47u;
        if (!i0) goto l28;
        XML_Parser__ParserDesc_ParseDocument_element();
        goto l1_loop;
l15:
        XML_Parser__ParserDesc_ParseDocument_PI();
        goto l1_loop;
l17:
        XML_Parser__ParserDesc_ParseDocument_CDSect();
        goto l1_loop;
l19:
        XML_Parser__ParserDesc_ParseDocument_Comment();
        goto l1_loop;
      case 38u:
        i0 = XML_Parser__ParserDesc_ParseDocument_LookingAt("&#", 3, 0);
        if (!i0) goto l23;
        goto l24;
l23:
        i0 = (OOC_INT32)XML_Parser__ParserDesc_ParseDocument_EntityRef(0u, 1u);
        XML_Parser__ParserDesc_ParseDocument_content_FollowEntityRef((XML_DTD__EntityRef)i0);
        goto l1_loop;
l24:
        XML_Parser__ParserDesc_ParseDocument_content_CharData();
        goto l1_loop;
      default:
        XML_Parser__ParserDesc_ParseDocument_content_CharData();
        goto l1_loop;
      }
l28:
      return;
      ;
    }

    
    void XML_Parser__ParserDesc_ParseDocument_element(void) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7;
      OOC_CHAR8 emptyElementTag;
      XML_UnicodeBuffer__CharArray startName;
      XML_DTD__Declaration decl;
      XML_UnicodeBuffer__CharArray attrName;
      XML_DTD__AttrDecl attrDecl;
      XML_DTD__Declaration decl0;
      XML_DTD__AttValue attrValue;
      struct XML_Locator__Position pos;
      XML_UnicodeBuffer__CharArray endName;
      auto void XML_Parser__ParserDesc_ParseDocument_element_NoteName(XML_UnicodeBuffer__CharArray name);
      auto OOC_CHAR8 XML_Parser__ParserDesc_ParseDocument_element_AttributeNameUsed(XML_UnicodeBuffer__CharArray name);
      auto void XML_Parser__ParserDesc_ParseDocument_element_AddDefaultAttributes(XML_DTD__ElementDecl elemDecl);
      auto void XML_Parser__ParserDesc_ParseDocument_element_ErrEndTag(void);
        
        void XML_Parser__ParserDesc_ParseDocument_element_NoteName(XML_UnicodeBuffer__CharArray name) {
          register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7;
          XML_Parser__NameList newList;
          OOC_INT32 i;

          i0 = (OOC_INT32)p;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 71653))+76);
          i2 = *(OOC_INT32*)((_check_pointer(i0, 71631))+80);
          i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 71663)), 0);
          i1 = i2==i1;
          if (!i1) goto l11;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 71702))+76);
          i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 71712)), 0);
          i1 = (OOC_INT32)RT0__NewObject(_td_XML_Parser__NameList.baseTypes[0], (i1+8));
          newList = (XML_Parser__NameList)i1;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 71760))+76);
          i = 0;
          i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 71770)), 0);
          i3 = 0<i2;
          if (!i3) goto l10;
          i3=0;
l5_loop:
          i4 = _check_pointer(i1, 71797);
          i5 = OOC_ARRAY_LENGTH(i4, 0);
          i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 71805))+76);
          i6 = _check_pointer(i6, 71815);
          i7 = OOC_ARRAY_LENGTH(i6, 0);
          i6 = (OOC_INT32)*(OOC_INT32*)(i6+(_check_index(i3, i7, OOC_UINT32, 71815))*4);
          *(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 71797))*4) = i6;
          i3 = i3+1;
          i = i3;
          i4 = i3<i2;
          if (i4) goto l5_loop;
l10:
          *(OOC_INT32*)((_check_pointer(i0, 71845))+76) = i1;
l11:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 71889))+76);
          i1 = _check_pointer(i1, 71899);
          i2 = *(OOC_INT32*)((_check_pointer(i0, 71901))+80);
          i3 = OOC_ARRAY_LENGTH(i1, 0);
          i4 = (OOC_INT32)name;
          *(OOC_INT32*)(i1+(_check_index(i2, i3, OOC_UINT32, 71899))*4) = i4;
          i1 = *(OOC_INT32*)((_check_pointer(i0, 71939))+80);
          *(OOC_INT32*)((_check_pointer(i0, 71939))+80) = (i1+1);
          return;
          ;
        }

        
        OOC_CHAR8 XML_Parser__ParserDesc_ParseDocument_element_AttributeNameUsed(XML_UnicodeBuffer__CharArray name) {
          register OOC_INT32 i0,i1,i2,i3,i4,i5;
          OOC_INT32 i;

          i0 = (OOC_INT32)p;
          i = 0;
          i1 = *(OOC_INT32*)((_check_pointer(i0, 72105))+80);
          i2 = 0<i1;
          if (!i2) goto l11;
          i2 = (OOC_INT32)name;
          i3=0;
l3_loop:
          i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 72147))+76);
          i4 = _check_pointer(i4, 72157);
          i5 = OOC_ARRAY_LENGTH(i4, 0);
          i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 72157))*4);
          i4 = (
          _cmp16((const void*)(_check_pointer(i2, 72142)),(const void*)(_check_pointer(i4, 72160))))==0;
          if (!i4) goto l6;
          return 1u;
l6:
          i3 = i3+1;
          i = i3;
          i4 = i3<i1;
          if (i4) goto l3_loop;
l11:
          return 0u;
          ;
        }

        
        void XML_Parser__ParserDesc_ParseDocument_element_AddDefaultAttributes(XML_DTD__ElementDecl elemDecl) {
          register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
          XML_DTD__Declaration decl;
          XML_DTD__AttrDecl attrDecl;
          auto OOC_CHAR8 XML_Parser__ParserDesc_ParseDocument_element_AddDefaultAttributes_AttributeDefined(XML_UnicodeBuffer__CharArray name);
            
            OOC_CHAR8 XML_Parser__ParserDesc_ParseDocument_element_AddDefaultAttributes_AttributeDefined(XML_UnicodeBuffer__CharArray name) {
              register OOC_INT32 i0,i1,i2,i3,i4;
              OOC_INT32 i;

              i = 0;
              i0 = (OOC_INT32)p;
              i1 = *(OOC_INT32*)((_check_pointer(i0, 72588))+80);
              i1 = 0!=i1;
              if (!i1) goto l11;
              i1 = (OOC_INT32)name;
              i2=0;
l3_loop:
              i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 72623))+76);
              i3 = _check_pointer(i3, 72633);
              i4 = OOC_ARRAY_LENGTH(i3, 0);
              i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i2, i4, OOC_UINT32, 72633))*4);
              i3 = (
              _cmp16((const void*)(_check_pointer(i3, 72636)),(const void*)(_check_pointer(i1, 72644))))==0;
              if (!i3) goto l6;
              return 1u;
l6:
              i2 = i2+1;
              i = i2;
              i3 = *(OOC_INT32*)((_check_pointer(i0, 72588))+80);
              i3 = i2!=i3;
              if (i3) goto l3_loop;
l11:
              return 0u;
              ;
            }


          i0 = (OOC_INT32)elemDecl;
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 72826))+20);
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 72841));
          decl = (XML_DTD__Declaration)i0;
          i1 = i0!=0;
          if (!i1) goto l22;
          i1 = (OOC_INT32)&_td_XML_Locator__Position;
          
l3_loop:
          i2 = _type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 72914)))), &_td_XML_DTD__AttrDeclDesc, 72914);
          attrDecl = (XML_DTD__AttrDecl)i2;
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 72965))+4);
          i3 = XML_Parser__ParserDesc_ParseDocument_element_AddDefaultAttributes_AttributeDefined((XML_UnicodeBuffer__CharArray)i3);
          i3 = !i3;
          if (!i3) goto l17;
          i3 = *(OOC_INT8*)((_check_pointer(i2, 73002))+20);
          i3 = i3>=2;
          if (i3) goto l15;
          i3 = (OOC_INT32)p;
          i4 = *(OOC_UINT8*)((_check_pointer(i3, 73235))+62);
          if (i4) goto l10;
          i4=0u;
          goto l12;
l10:
          i4 = *(OOC_INT8*)((_check_pointer(i2, 73277))+20);
          i4 = i4==0;
          
l12:
          if (!i4) goto l17;
          i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 73358))+4);
          i4 = _check_pointer(i4, 73361);
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 73358))+4);
          XML_Parser__ParserDesc_ParseDocument_ErrPosNF(214, (void*)(_check_pointer(i3, 73361)), (RT0__Struct)i1);
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 73446))+4);
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 73446))+4);
          i3 = OOC_ARRAY_LENGTH((_check_pointer(i3, 73452)), 0);
          i2 = (OOC_INT32)Msg__GetLStringPtr((void*)(_check_pointer(i2, 73452)), i3);
          i3 = (OOC_INT32)p;
          i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 73380))+104);
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 73380))+104);
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 73391)))), Msg__MsgDesc_SetLStringAttrib)),Msg__MsgDesc_SetLStringAttrib)((Msg__Msg)i3, "name", 5, (Msg__LStringPtr)i2);
          goto l17;
l15:
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 73067))+24);
          XML_Parser__ParserDesc_ParseDocument_Expand((XML_DTD__AttValue)i3);
          i3 = (OOC_INT32)p;
          i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 73099))+44);
          i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 73193))+24);
          i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 73130))+4);
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 73099))+44);
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 73108)))), XML_Builder__BuilderDesc_Attribute)),XML_Builder__BuilderDesc_Attribute)((XML_Builder__Builder)i3, (XML_DTD__NamespaceDeclaration)0, (XML_UnicodeBuffer__CharArray)i6, (XML_DTD__AttrDecl)i2, (XML_DTD__AttValue)i5, 0u);
l17:
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 73509));
          decl = (XML_DTD__Declaration)i0;
          i2 = i0!=0;
          if (i2) goto l3_loop;
l22:
          return;
          ;
        }

        
        void XML_Parser__ParserDesc_ParseDocument_element_ErrEndTag(void) {
          register OOC_INT32 i0,i1,i2;

          i0 = (OOC_INT32)startName;
          i1 = (OOC_INT32)XML_Parser__noName;
          i0 = i0!=i1;
          if (!i0) goto l4;
          XML_Parser__ParserDesc_ParseDocument_ErrPos(209, (void*)(OOC_INT32)&pos, (RT0__Struct)((OOC_INT32)&_td_XML_Locator__Position));
          i0 = (OOC_INT32)startName;
          i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 73757)), 0);
          i0 = (OOC_INT32)Msg__GetLStringPtr((void*)(_check_pointer(i0, 73757)), i1);
          i1 = (OOC_INT32)p;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 73690))+104);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 73690))+104);
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 73701)))), Msg__MsgDesc_SetLStringAttrib)),Msg__MsgDesc_SetLStringAttrib)((Msg__Msg)i1, "name", 5, (Msg__LStringPtr)i0);
l4:
          return;
          ;
        }


      i0 = (OOC_INT32)chars;
      i0 = _check_pointer(i0, 73824);
      i1 = OOC_ARRAY_LENGTH(i0, 0);
      i2 = cpos;
      i0 = *(OOC_UINT16*)(i0+(_check_index(i2, i1, OOC_UINT32, 73824))*2);
      i0 = i0==60u;
      if (i0) goto l3;
      XML_Parser__ParserDesc_ParseDocument_Err(208);
      goto l51;
l3:
      XML_Parser__ParserDesc_ParseDocument_CheckChar(60u);
      i0 = (OOC_INT32)p;
      *(OOC_INT32*)((_check_pointer(i0, 73877))+80) = 0;
      emptyElementTag = 0u;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 73955))+4);
      i1 = _check_pointer(i1, 73958);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 73955))+4);
      i1 = (OOC_INT32)&_td_XML_Locator__Position;
      XML_Parser__ParserDesc_ParseDocument_StorePosition((void*)(_check_pointer(i0, 73958)), (RT0__Struct)i1);
      i0 = (OOC_INT32)XML_Parser__ParserDesc_ParseDocument_Name(0u);
      startName = (XML_UnicodeBuffer__CharArray)i0;
      i2 = (OOC_INT32)dtd;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 74016))+12);
      i2 = (OOC_INT32)XML_DTD__NamespaceDesc_Get((XML_DTD__Namespace)i2, (XML_UnicodeBuffer__CharArray)i0);
      decl = (XML_DTD__Declaration)i2;
      i3 = (OOC_INT32)p;
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 74062))+44);
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 74062))+44);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 74071)))), XML_Builder__BuilderDesc_StartElement)),XML_Builder__BuilderDesc_StartElement)((XML_Builder__Builder)i3, (XML_DTD__NamespaceDeclaration)(OOC_INT32)0, (XML_UnicodeBuffer__CharArray)i0);
      i0 = i2!=(OOC_INT32)0;
      {register OOC_INT32 h0=i0;i0=i2;i2=h0;}
l4_loop:
      i3 = (OOC_INT32)chars;
      i4 = _check_pointer(i3, 74151);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      i6 = cpos;
      i4 = *(OOC_UINT16*)(i4+(_check_index(i6, i5, OOC_UINT32, 74151))*2);
      i4 = i4==65535u;
      if (i4) goto l34;
      i4 = _check_pointer(i3, 74222);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      i4 = *(OOC_UINT16*)(i4+(_check_index(i6, i5, OOC_UINT32, 74222))*2);
      i4 = i4!=62u;
      if (i4) goto l9;
      i3=0u;
      goto l11;
l9:
      i3 = _check_pointer(i3, 74244);
      i4 = OOC_ARRAY_LENGTH(i3, 0);
      i3 = *(OOC_UINT16*)(i3+(_check_index(i6, i4, OOC_UINT32, 74244))*2);
      i3 = i3!=47u;
      
l11:
      if (!i3) goto l14;
      XML_Parser__ParserDesc_ParseDocument_S();
l14:
      i3 = (OOC_INT32)chars;
      i4 = _check_pointer(i3, 74311);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      i6 = cpos;
      i4 = *(OOC_UINT16*)(i4+(_check_index(i6, i5, OOC_UINT32, 74311))*2);
      i4 = i4==47u;
      if (i4) goto l32;
      i3 = _check_pointer(i3, 74435);
      i4 = OOC_ARRAY_LENGTH(i3, 0);
      i3 = *(OOC_UINT16*)(i3+(_check_index(i6, i4, OOC_UINT32, 74435))*2);
      i3 = i3==62u;
      if (i3) goto l34;
l20:
      i0 = (OOC_INT32)p;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 74523))+4);
      i2 = _check_pointer(i2, 74526);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 74523))+4);
      XML_Parser__ParserDesc_ParseDocument_StorePosition((void*)(_check_pointer(i0, 74526)), (RT0__Struct)i1);
      i0 = (OOC_INT32)XML_Parser__ParserDesc_ParseDocument_Name(0u);
      attrName = (XML_UnicodeBuffer__CharArray)i0;
      i2 = XML_Parser__ParserDesc_ParseDocument_element_AttributeNameUsed((XML_UnicodeBuffer__CharArray)i0);
      if (!i2) goto l23;
      i2 = (OOC_INT32)p;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 74652))+4);
      i3 = _check_pointer(i3, 74655);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 74652))+4);
      XML_Parser__ParserDesc_ParseDocument_ErrPos(212, (void*)(_check_pointer(i2, 74655)), (RT0__Struct)i1);
      i2 = OOC_ARRAY_LENGTH((_check_pointer(i0, 74738)), 0);
      i2 = (OOC_INT32)Msg__GetLStringPtr((void*)(_check_pointer(i0, 74738)), i2);
      i3 = (OOC_INT32)p;
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 74672))+104);
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 74672))+104);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 74683)))), Msg__MsgDesc_SetLStringAttrib)),Msg__MsgDesc_SetLStringAttrib)((Msg__Msg)i3, "name", 5, (Msg__LStringPtr)i2);
l23:
      XML_Parser__ParserDesc_ParseDocument_element_NoteName((XML_UnicodeBuffer__CharArray)i0);
      XML_Parser__ParserDesc_ParseDocument_Eq();
      attrDecl = (XML_DTD__AttrDecl)(OOC_INT32)0;
      i0 = (OOC_INT32)decl;
      i2 = i0!=(OOC_INT32)0;
      if (i2) goto l26;
      i3=(OOC_INT32)0;
      goto l31;
l26:
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 74890)))), &_td_XML_DTD__ElementDeclDesc, 74890)), 74902))+20);
      i4 = (OOC_INT32)attrName;
      i3 = (OOC_INT32)XML_DTD__NamespaceDesc_Get((XML_DTD__Namespace)i3, (XML_UnicodeBuffer__CharArray)i4);
      decl0 = (XML_DTD__Declaration)i3;
      i4 = i3!=(OOC_INT32)0;
      if (i4) goto l29;
      i3=(OOC_INT32)0;
      goto l31;
l29:
      i3 = _type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 75005)))), &_td_XML_DTD__AttrDeclDesc, 75005);
      attrDecl = (XML_DTD__AttrDecl)i3;
      
l31:
      i4 = (OOC_INT32)XML_Parser__ParserDesc_ParseDocument_AttValue(1u);
      attrValue = (XML_DTD__AttValue)i4;
      XML_Parser__ParserDesc_ParseDocument_Expand((XML_DTD__AttValue)i4);
      i5 = (OOC_INT32)p;
      i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 75127))+44);
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 75127))+44);
      i7 = (OOC_INT32)attrName;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 75136)))), XML_Builder__BuilderDesc_Attribute)),XML_Builder__BuilderDesc_Attribute)((XML_Builder__Builder)i5, (XML_DTD__NamespaceDeclaration)(OOC_INT32)0, (XML_UnicodeBuffer__CharArray)i7, (XML_DTD__AttrDecl)i3, (XML_DTD__AttValue)i4, 1u);
      
      goto l4_loop;
l32:
      XML_Parser__ParserDesc_ParseDocument_CheckChar(47u);
      emptyElementTag = 1u;
l34:
      i3 = (OOC_INT32)p;
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 75252))+4);
      i4 = _check_pointer(i4, 75255);
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 75252))+4);
      XML_Parser__ParserDesc_ParseDocument_StorePosition((void*)(_check_pointer(i3, 75255)), (RT0__Struct)i1);
      if (!i2) goto l37;
      XML_Parser__ParserDesc_ParseDocument_element_AddDefaultAttributes((XML_DTD__ElementDecl)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 75329)))), &_td_XML_DTD__ElementDeclDesc, 75329)));
l37:
      XML_Parser__ParserDesc_ParseDocument_CheckChar(62u);
      i0 = (OOC_INT32)p;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 75390))+44);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 75390))+44);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 75399)))), XML_Builder__BuilderDesc_AttributesDone)),XML_Builder__BuilderDesc_AttributesDone)((XML_Builder__Builder)i0);
      XML_Parser__ParserDesc_ParseDocument_DiscardPreviousInput();
      i0 = emptyElementTag;
      if (i0) goto l49;
      XML_Parser__ParserDesc_ParseDocument_content();
      XML_Parser__ParserDesc_ParseDocument_StorePosition((void*)(OOC_INT32)&pos, (RT0__Struct)i1);
      i0 = (OOC_INT32)chars;
      i0 = _check_pointer(i0, 75688);
      i2 = OOC_ARRAY_LENGTH(i0, 0);
      i3 = cpos;
      i0 = *(OOC_UINT16*)(i0+(_check_index(i3, i2, OOC_UINT32, 75688))*2);
      i0 = i0!=60u;
      if (!i0) goto l42;
      XML_Parser__ParserDesc_ParseDocument_element_ErrEndTag();
l42:
      XML_Parser__ParserDesc_ParseDocument_CheckChar(60u);
      i0 = (OOC_INT32)chars;
      i0 = _check_pointer(i0, 75768);
      i2 = OOC_ARRAY_LENGTH(i0, 0);
      i3 = cpos;
      i0 = *(OOC_UINT16*)(i0+(_check_index(i3, i2, OOC_UINT32, 75768))*2);
      i0 = i0!=47u;
      if (!i0) goto l45;
      XML_Parser__ParserDesc_ParseDocument_element_ErrEndTag();
l45:
      XML_Parser__ParserDesc_ParseDocument_CheckChar(47u);
      i0 = (OOC_INT32)p;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 75855))+4);
      i2 = _check_pointer(i2, 75858);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 75855))+4);
      XML_Parser__ParserDesc_ParseDocument_StorePosition((void*)(_check_pointer(i0, 75858)), (RT0__Struct)i1);
      i0 = (OOC_INT32)XML_Parser__ParserDesc_ParseDocument_Name(0u);
      endName = (XML_UnicodeBuffer__CharArray)i0;
      i1 = (OOC_INT32)startName;
      i0 = (
      _cmp16((const void*)(_check_pointer(i0, 75918)),(const void*)(_check_pointer(i1, 75931))))!=0;
      if (!i0) goto l48;
      XML_Parser__ParserDesc_ParseDocument_element_ErrEndTag();
l48:
      i0 = (OOC_INT32)p;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 75965))+44);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 75965))+44);
      i2 = (OOC_INT32)startName;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 75974)))), XML_Builder__BuilderDesc_EndElement)),XML_Builder__BuilderDesc_EndElement)((XML_Builder__Builder)i0, (XML_DTD__NamespaceDeclaration)(OOC_INT32)0, (XML_UnicodeBuffer__CharArray)i2);
      XML_Parser__ParserDesc_ParseDocument_OptS(1u);
      XML_Parser__ParserDesc_ParseDocument_CheckChar(62u);
      goto l51;
l49:
      i0 = (OOC_INT32)p;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 75534))+4);
      i2 = _check_pointer(i2, 75537);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 75534))+4);
      XML_Parser__ParserDesc_ParseDocument_StorePosition((void*)(_check_pointer(i0, 75537)), (RT0__Struct)i1);
      i0 = (OOC_INT32)p;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 75552))+44);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 75552))+44);
      i2 = (OOC_INT32)startName;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 75561)))), XML_Builder__BuilderDesc_EndElement)),XML_Builder__BuilderDesc_EndElement)((XML_Builder__Builder)i0, (XML_DTD__NamespaceDeclaration)(OOC_INT32)0, (XML_UnicodeBuffer__CharArray)i2);
l51:
      return;
      ;
    }

    
    void XML_Parser__ParserDesc_ParseDocument_MiscRep(void) {
      register OOC_INT32 i0,i1,i2;

l1_loop:
      i0 = (OOC_INT32)chars;
      i0 = _check_pointer(i0, 76275);
      i1 = OOC_ARRAY_LENGTH(i0, 0);
      i2 = cpos;
      i0 = *(OOC_UINT16*)(i0+(_check_index(i2, i1, OOC_UINT32, 76275))*2);
      switch (i0) {
      case 65534u:
        XML_Parser__ParserDesc_ParseDocument_NextBlock();
        goto l1_loop;
      case 60u:
        i0 = XML_Parser__ParserDesc_ParseDocument_LookingAt("<!--", 5, 0);
        if (!i0) goto l6;
        goto l11;
l6:
        i0 = XML_Parser__ParserDesc_ParseDocument_LookingAt("<?", 3, 0);
        if (!i0) goto l16;
        XML_Parser__ParserDesc_ParseDocument_PI();
        goto l1_loop;
l11:
        XML_Parser__ParserDesc_ParseDocument_Comment();
        goto l1_loop;
      case 0u ... 32u:
        XML_Parser__ParserDesc_ParseDocument_S();
        goto l1_loop;
      default:
        goto l16;
      }
l16:
      return;
      ;
    }

    
    void XML_Parser__ParserDesc_ParseDocument_ExternalID(OOC_CHAR8 optionJustPubid, XML_UnicodeBuffer__CharArray *_public, XML_UnicodeBuffer__CharArray *system, URI__URI *baseURI) {
      register OOC_INT32 i0,i1,i2,i3,i4;
      Msg__Msg res;

      *_public = (XML_UnicodeBuffer__CharArray)(OOC_INT32)0;
      *system = (XML_UnicodeBuffer__CharArray)(OOC_INT32)0;
      *baseURI = (URI__URI)(OOC_INT32)0;
      i0 = XML_Parser__ParserDesc_ParseDocument_LookingAt("SYSTEM", 7, 1);
      if (i0) goto l28;
      i0 = XML_Parser__ParserDesc_ParseDocument_LookingAt("PUBLIC", 7, 1);
      if (i0) goto l5;
      XML_Parser__ParserDesc_ParseDocument_Err(112);
      goto l32;
l5:
      i0 = cpos;
      cpos = (i0+6);
      XML_Parser__ParserDesc_ParseDocument_S();
      i0 = (OOC_INT32)XML_Parser__ParserDesc_ParseDocument_String(2);
      *_public = (XML_UnicodeBuffer__CharArray)i0;
      i0 = optionJustPubid;
      i0 = !i0;
      if (i0) goto l8;
      i1 = XML_Parser__ParserDesc_ParseDocument_LookingAtS();
      
      goto l10;
l8:
      i1=1u;
l10:
      if (!i1) goto l23;
      XML_Parser__ParserDesc_ParseDocument_S();
      if (i0) goto l14;
      i0 = (OOC_INT32)chars;
      i0 = _check_pointer(i0, 77604);
      i1 = OOC_ARRAY_LENGTH(i0, 0);
      i2 = cpos;
      i0 = *(OOC_UINT16*)(i0+(_check_index(i2, i1, OOC_UINT32, 77604))*2);
      i0 = i0==39u;
      
      goto l16;
l14:
      i0=1u;
l16:
      if (i0) goto l18;
      i0 = (OOC_INT32)chars;
      i0 = _check_pointer(i0, 77627);
      i1 = OOC_ARRAY_LENGTH(i0, 0);
      i2 = cpos;
      i0 = *(OOC_UINT16*)(i0+(_check_index(i2, i1, OOC_UINT32, 77627))*2);
      i0 = i0==34u;
      
      goto l20;
l18:
      i0=1u;
l20:
      if (!i0) goto l23;
      i0 = (OOC_INT32)XML_Parser__ParserDesc_ParseDocument_String(2);
      *system = (XML_UnicodeBuffer__CharArray)i0;
l23:
      i0 = (OOC_INT32)p;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 77763))+56);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 77732))+32);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 77774))+36);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 77732))+32);
      i3 = (OOC_INT32)*system;
      i4 = (OOC_INT32)*_public;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 77736)))), XML_EntityResolver__ResolverDesc_GetURI)),XML_EntityResolver__ResolverDesc_GetURI)((XML_EntityResolver__Resolver)i0, (XML_UnicodeBuffer__CharArray)i4, (XML_UnicodeBuffer__CharArray)i3, (URI__URI)i1, (void*)(OOC_INT32)baseURI, (void*)(OOC_INT32)&res);
      i0 = (OOC_INT32)res;
      i0 = i0!=(OOC_INT32)0;
      if (!i0) goto l32;
      XML_Parser__ParserDesc_ParseDocument_Err(117);
      i0 = (OOC_INT32)p;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 77868))+104);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 77868))+104);
      i2 = (OOC_INT32)res;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 77879)))), Msg__MsgDesc_SetMsgAttrib)),Msg__MsgDesc_SetMsgAttrib)((Msg__Msg)i0, "uri_error", 10, (Msg__Msg)i2);
      goto l32;
l28:
      i0 = cpos;
      cpos = (i0+6);
      XML_Parser__ParserDesc_ParseDocument_S();
      i0 = (OOC_INT32)XML_Parser__ParserDesc_ParseDocument_String(1);
      *system = (XML_UnicodeBuffer__CharArray)i0;
      i1 = (OOC_INT32)p;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 77149))+56);
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 77121))+32);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 77161))+36);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 77121))+32);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 77125)))), XML_EntityResolver__ResolverDesc_GetURI)),XML_EntityResolver__ResolverDesc_GetURI)((XML_EntityResolver__Resolver)i1, (XML_UnicodeBuffer__CharArray)(OOC_INT32)0, (XML_UnicodeBuffer__CharArray)i0, (URI__URI)i2, (void*)(OOC_INT32)baseURI, (void*)(OOC_INT32)&res);
      i0 = (OOC_INT32)res;
      i0 = i0!=(OOC_INT32)0;
      if (!i0) goto l32;
      XML_Parser__ParserDesc_ParseDocument_Err(117);
      i0 = (OOC_INT32)p;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 77256))+104);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 77256))+104);
      i2 = (OOC_INT32)res;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 77267)))), Msg__MsgDesc_SetMsgAttrib)),Msg__MsgDesc_SetMsgAttrib)((Msg__Msg)i0, "uri_error", 10, (Msg__Msg)i2);
l32:
      return;
      ;
    }

    
    void XML_Parser__ParserDesc_ParseDocument_markupdecl(void) {
      register OOC_INT32 i0;
      auto void XML_Parser__ParserDesc_ParseDocument_markupdecl_elementdecl(XML_DTD__Entity currentEntity);
      auto void XML_Parser__ParserDesc_ParseDocument_markupdecl_AttListDecl(XML_DTD__Entity currentEntity);
      auto void XML_Parser__ParserDesc_ParseDocument_markupdecl_EntityDecl(XML_DTD__Entity currentEntity);
      auto void XML_Parser__ParserDesc_ParseDocument_markupdecl_NotationDecl(XML_DTD__Entity currentEntity);
        
        void XML_Parser__ParserDesc_ParseDocument_markupdecl_elementdecl(XML_DTD__Entity currentEntity) {
          register OOC_INT32 i0,i1,i2,i3,i4;
          XML_UnicodeBuffer__CharArray elementName;
          XML_DTD__CP cp;
          XML_DTD__ElementDecl elementDecl;
          XML_DTD__Declaration decl;
          auto XML_DTD__CP XML_Parser__ParserDesc_ParseDocument_markupdecl_elementdecl_contentspec(void);
            
            XML_DTD__CP XML_Parser__ParserDesc_ParseDocument_markupdecl_elementdecl_contentspec(void) {
              register OOC_INT32 i0,i1,i2;
              XML_DTD__Entity currentEntity;
              auto XML_DTD__CP XML_Parser__ParserDesc_ParseDocument_markupdecl_elementdecl_contentspec_Mixed(XML_DTD__Entity currentEntity);
              auto XML_DTD__CP XML_Parser__ParserDesc_ParseDocument_markupdecl_elementdecl_contentspec_children(XML_DTD__Entity currentEntity);
                
                XML_DTD__CP XML_Parser__ParserDesc_ParseDocument_markupdecl_elementdecl_contentspec_Mixed(XML_DTD__Entity currentEntity) {
                  register OOC_INT32 i0,i1,i2,i3,i4,i5;
                  XML_DTD__CP first;
                  XML_DTD__CP last;
                  OOC_CHAR8 hasAlternative;

                  i0 = cpos;
                  i0 = (OOC_INT32)XML_Parser__ParserDesc_ParseDocument_GetString(i0, (i0+7));
                  i1 = (OOC_INT32)dtd;
                  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 78686)))), XML_DTD__BuilderDesc_NewNameCP)),XML_DTD__BuilderDesc_NewNameCP)((XML_DTD__Builder)i1, 0, (XML_UnicodeBuffer__CharArray)i0);
                  i1 = cpos;
                  first = (XML_DTD__CP)i0;
                  i1 = i1+7;
                  cpos = i1;
                  last = (XML_DTD__CP)i0;
                  XML_Parser__ParserDesc_ParseDocument_OptS(0u);
                  hasAlternative = 0u;
                  i2 = (OOC_INT32)chars;
                  i2 = _check_pointer(i2, 78917);
                  i3 = OOC_ARRAY_LENGTH(i2, 0);
                  i1 = *(OOC_UINT16*)(i2+(_check_index(i1, i3, OOC_UINT32, 78917))*2);
                  i2 = (OOC_INT32)currentEntity;
                  i1 = i1==124u;
                  if (i1) goto l3;
                  i1=0u;
                  goto l9;
l3:
                  i1=i0;
l4_loop:
                  hasAlternative = 1u;
                  XML_Parser__ParserDesc_ParseDocument_CheckChar(124u);
                  XML_Parser__ParserDesc_ParseDocument_OptS(0u);
                  i3 = (OOC_INT32)XML_Parser__ParserDesc_ParseDocument_Name(0u);
                  i4 = (OOC_INT32)dtd;
                  i3 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 79063)))), XML_DTD__BuilderDesc_NewNameCP)),XML_DTD__BuilderDesc_NewNameCP)((XML_DTD__Builder)i4, 0, (XML_UnicodeBuffer__CharArray)i3);
                  XML_DTD__CPDesc_SetNext((XML_DTD__CP)i1, (XML_DTD__CP)i3);
                  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 79130))+4);
                  last = (XML_DTD__CP)i1;
                  XML_Parser__ParserDesc_ParseDocument_OptS(0u);
                  i3 = (OOC_INT32)chars;
                  i3 = _check_pointer(i3, 78917);
                  i4 = OOC_ARRAY_LENGTH(i3, 0);
                  i5 = cpos;
                  i3 = *(OOC_UINT16*)(i3+(_check_index(i5, i4, OOC_UINT32, 78917))*2);
                  i3 = i3==124u;
                  if (i3) goto l4_loop;
l8:
                  i1=1u;
l9:
                  XML_Parser__ParserDesc_ParseDocument_CheckCurrentEntity((XML_DTD__Entity)i2);
                  XML_Parser__ParserDesc_ParseDocument_CheckChar(41u);
                  if (i1) goto l12;
                  i1 = (OOC_INT32)chars;
                  i1 = _check_pointer(i1, 79298);
                  i2 = OOC_ARRAY_LENGTH(i1, 0);
                  i3 = cpos;
                  i1 = *(OOC_UINT16*)(i1+(_check_index(i3, i2, OOC_UINT32, 79298))*2);
                  i1 = i1==42u;
                  
                  goto l14;
l12:
                  i1=1u;
l14:
                  if (i1) goto l16;
                  i1 = (OOC_INT32)dtd;
                  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 79450)))), XML_DTD__BuilderDesc_NewChoiceCP)),XML_DTD__BuilderDesc_NewChoiceCP)((XML_DTD__Builder)i1, 0, (XML_DTD__CP)i0);
                  return (XML_DTD__CP)i0;
                  goto l17;
l16:
                  XML_Parser__ParserDesc_ParseDocument_CheckChar(42u);
                  i1 = (OOC_INT32)dtd;
                  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 79372)))), XML_DTD__BuilderDesc_NewChoiceCP)),XML_DTD__BuilderDesc_NewChoiceCP)((XML_DTD__Builder)i1, 2, (XML_DTD__CP)i0);
                  return (XML_DTD__CP)i0;
l17:
                  _failed_function(78443); return 0;
                  ;
                }

                
                XML_DTD__CP XML_Parser__ParserDesc_ParseDocument_markupdecl_elementdecl_contentspec_children(XML_DTD__Entity currentEntity) {
                  register OOC_INT32 i0,i1;
                  XML_DTD__CP cp;
                  auto OOC_INT8 XML_Parser__ParserDesc_ParseDocument_markupdecl_elementdecl_contentspec_children_Quantifier(void);
                  auto XML_DTD__CP XML_Parser__ParserDesc_ParseDocument_markupdecl_elementdecl_contentspec_children_choiceseq(XML_DTD__Entity currentEntity);
                    
                    OOC_INT8 XML_Parser__ParserDesc_ParseDocument_markupdecl_elementdecl_contentspec_children_Quantifier(void) {
                      register OOC_INT32 i0,i1,i2;

                      i0 = (OOC_INT32)chars;
                      i0 = _check_pointer(i0, 79861);
                      i1 = OOC_ARRAY_LENGTH(i0, 0);
                      i2 = cpos;
                      i0 = *(OOC_UINT16*)(i0+(_check_index(i2, i1, OOC_UINT32, 79861))*2);
                      switch (i0) {
                      case 42u:
                        XML_Parser__ParserDesc_ParseDocument_CheckChar(42u);
                        return 2;
                        goto l6;
                      case 43u:
                        XML_Parser__ParserDesc_ParseDocument_CheckChar(43u);
                        return 3;
                        goto l6;
                      case 63u:
                        XML_Parser__ParserDesc_ParseDocument_CheckChar(63u);
                        return 1;
                        goto l6;
                      default:
                        return 0;
                        goto l6;
                      }
l6:
                      _failed_function(79728); return 0;
                      ;
                    }

                    
                    XML_DTD__CP XML_Parser__ParserDesc_ParseDocument_markupdecl_elementdecl_contentspec_children_choiceseq(XML_DTD__Entity currentEntity) {
                      register OOC_INT32 i0,i1,i2,i3;
                      OOC_CHAR16 _class;
                      XML_DTD__CP first;
                      XML_DTD__CP last;
                      auto XML_DTD__CP XML_Parser__ParserDesc_ParseDocument_markupdecl_elementdecl_contentspec_children_choiceseq_cp(void);
                        
                        XML_DTD__CP XML_Parser__ParserDesc_ParseDocument_markupdecl_elementdecl_contentspec_children_choiceseq_cp(void) {
                          register OOC_INT32 i0,i1,i2,i3;

                          i0 = (OOC_INT32)chars;
                          i1 = _check_pointer(i0, 80619);
                          i2 = OOC_ARRAY_LENGTH(i1, 0);
                          i3 = cpos;
                          i1 = *(OOC_UINT16*)(i1+(_check_index(i3, i2, OOC_UINT32, 80619))*2);
                          i1 = i1==40u;
                          if (i1) goto l7;
                          i0 = _check_pointer(i0, 80847);
                          i1 = OOC_ARRAY_LENGTH(i0, 0);
                          i0 = *(OOC_UINT16*)(i0+(_check_index(i3, i1, OOC_UINT32, 80847))*2);
                          i0 = XML_Parser__IsNameChar0(i0);
                          if (i0) goto l5;
                          XML_Parser__ParserDesc_ParseDocument_Err(110);
                          i0 = (OOC_INT32)dtd;
                          i1 = (OOC_INT32)XML_Parser__noName;
                          i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 81010)))), XML_DTD__BuilderDesc_NewNameCP)),XML_DTD__BuilderDesc_NewNameCP)((XML_DTD__Builder)i0, 0, (XML_UnicodeBuffer__CharArray)i1);
                          
                          goto l8;
l5:
                          i0 = (OOC_INT32)XML_Parser__ParserDesc_ParseDocument_Name(0u);
                          i1 = (OOC_INT32)dtd;
                          i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 80887)))), XML_DTD__BuilderDesc_NewNameCP)),XML_DTD__BuilderDesc_NewNameCP)((XML_DTD__Builder)i1, 0, (XML_UnicodeBuffer__CharArray)i0);
                          
                          goto l8;
l7:
                          i0 = (OOC_INT32)XML_Parser__ParserDesc_ParseDocument_CurrentEntity();
                          XML_Parser__ParserDesc_ParseDocument_CheckChar(40u);
                          XML_Parser__ParserDesc_ParseDocument_OptS(0u);
                          i0 = (OOC_INT32)XML_Parser__ParserDesc_ParseDocument_markupdecl_elementdecl_contentspec_children_choiceseq((XML_DTD__Entity)i0);
                          
l8:
                          i1 = XML_Parser__ParserDesc_ParseDocument_markupdecl_elementdecl_contentspec_children_Quantifier();
                          XML_DTD__CPDesc_SetMode((XML_DTD__CP)i0, i1);
                          return (XML_DTD__CP)i0;
                          ;
                        }


                      _class = 0u;
                      i0 = (OOC_INT32)XML_Parser__ParserDesc_ParseDocument_markupdecl_elementdecl_contentspec_children_choiceseq_cp();
                      first = (XML_DTD__CP)i0;
                      XML_Parser__ParserDesc_ParseDocument_OptS(0u);
                      last = (XML_DTD__CP)i0;
l1_loop:
                      i0 = (OOC_INT32)chars;
                      i1 = _check_pointer(i0, 81333);
                      i2 = OOC_ARRAY_LENGTH(i1, 0);
                      i3 = cpos;
                      i1 = *(OOC_UINT16*)(i1+(_check_index(i3, i2, OOC_UINT32, 81333))*2);
                      switch (i1) {
                      case 65534u:
                        XML_Parser__ParserDesc_ParseDocument_NextBlock();
                        goto l1_loop;
                      case 44u:
                      case 124u:
                        i1 = _class;
                        i1 = i1==0u;
                        if (i1) goto l6;
                        goto l7;
l6:
                        i0 = _check_pointer(i0, 81508);
                        i1 = OOC_ARRAY_LENGTH(i0, 0);
                        i0 = *(OOC_UINT16*)(i0+(_check_index(i3, i1, OOC_UINT32, 81508))*2);
                        _class = i0;
l7:
                        i0 = _class;
                        XML_Parser__ParserDesc_ParseDocument_CheckChar(i0);
                        XML_Parser__ParserDesc_ParseDocument_OptS(0u);
                        i0 = (OOC_INT32)XML_Parser__ParserDesc_ParseDocument_markupdecl_elementdecl_contentspec_children_choiceseq_cp();
                        i1 = (OOC_INT32)last;
                        XML_DTD__CPDesc_SetNext((XML_DTD__CP)i1, (XML_DTD__CP)i0);
                        i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 81685))+4);
                        last = (XML_DTD__CP)i0;
                        XML_Parser__ParserDesc_ParseDocument_OptS(0u);
                        goto l1_loop;
                      default:
                        goto l10;
                      }
l10:
                      XML_Parser__ParserDesc_ParseDocument_CheckChar(41u);
                      i0 = (OOC_INT32)currentEntity;
                      XML_Parser__ParserDesc_ParseDocument_CheckCurrentEntity((XML_DTD__Entity)i0);
                      i0 = _class;
                      i0 = i0==44u;
                      if (i0) goto l13;
                      i0 = (OOC_INT32)dtd;
                      i1 = (OOC_INT32)first;
                      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 82096)))), XML_DTD__BuilderDesc_NewChoiceCP)),XML_DTD__BuilderDesc_NewChoiceCP)((XML_DTD__Builder)i0, 0, (XML_DTD__CP)i1);
                      return (XML_DTD__CP)i0;
                      goto l14;
l13:
                      i0 = (OOC_INT32)dtd;
                      i1 = (OOC_INT32)first;
                      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 82020)))), XML_DTD__BuilderDesc_NewSeqCP)),XML_DTD__BuilderDesc_NewSeqCP)((XML_DTD__Builder)i0, 0, (XML_DTD__CP)i1);
                      return (XML_DTD__CP)i0;
l14:
                      _failed_function(80169); return 0;
                      ;
                    }


                  i0 = (OOC_INT32)currentEntity;
                  i0 = (OOC_INT32)XML_Parser__ParserDesc_ParseDocument_markupdecl_elementdecl_contentspec_children_choiceseq((XML_DTD__Entity)i0);
                  cp = (XML_DTD__CP)i0;
                  i0 = XML_Parser__ParserDesc_ParseDocument_markupdecl_elementdecl_contentspec_children_Quantifier();
                  i1 = (OOC_INT32)cp;
                  XML_DTD__CPDesc_SetMode((XML_DTD__CP)i1, i0);
                  return (XML_DTD__CP)i1;
                  ;
                }


              i0 = XML_Parser__ParserDesc_ParseDocument_LookingAt("EMPTY", 6, 1);
              if (i0) goto l15;
              i0 = XML_Parser__ParserDesc_ParseDocument_LookingAt("ANY", 4, 1);
              if (i0) goto l13;
              i0 = (OOC_INT32)chars;
              i0 = _check_pointer(i0, 82597);
              i1 = OOC_ARRAY_LENGTH(i0, 0);
              i2 = cpos;
              i0 = *(OOC_UINT16*)(i0+(_check_index(i2, i1, OOC_UINT32, 82597))*2);
              i0 = i0==40u;
              if (i0) goto l7;
              XML_Parser__ParserDesc_ParseDocument_Err(106);
              i0 = (OOC_INT32)dtd;
              i1 = (OOC_INT32)XML_Parser__noName;
              i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 82976)))), XML_DTD__BuilderDesc_NewNameCP)),XML_DTD__BuilderDesc_NewNameCP)((XML_DTD__Builder)i0, 0, (XML_UnicodeBuffer__CharArray)i1);
              return (XML_DTD__CP)i0;
              goto l16;
l7:
              i0 = (OOC_INT32)XML_Parser__ParserDesc_ParseDocument_CurrentEntity();
              currentEntity = (XML_DTD__Entity)i0;
              XML_Parser__ParserDesc_ParseDocument_CheckChar(40u);
              XML_Parser__ParserDesc_ParseDocument_OptS(0u);
              i1 = XML_Parser__ParserDesc_ParseDocument_LookingAt("#PCDATA", 8, 1);
              if (i1) goto l10;
              i0 = (OOC_INT32)XML_Parser__ParserDesc_ParseDocument_markupdecl_elementdecl_contentspec_children((XML_DTD__Entity)i0);
              return (XML_DTD__CP)i0;
              goto l16;
l10:
              i0 = (OOC_INT32)XML_Parser__ParserDesc_ParseDocument_markupdecl_elementdecl_contentspec_Mixed((XML_DTD__Entity)i0);
              return (XML_DTD__CP)i0;
              goto l16;
l13:
              i0 = (OOC_INT32)XML_Parser__ParserDesc_ParseDocument_Name(0u);
              i1 = (OOC_INT32)dtd;
              i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 82536)))), XML_DTD__BuilderDesc_NewNameCP)),XML_DTD__BuilderDesc_NewNameCP)((XML_DTD__Builder)i1, 0, (XML_UnicodeBuffer__CharArray)i0);
              return (XML_DTD__CP)i0;
              goto l16;
l15:
              i0 = (OOC_INT32)XML_Parser__ParserDesc_ParseDocument_Name(0u);
              i1 = (OOC_INT32)dtd;
              i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 82417)))), XML_DTD__BuilderDesc_NewNameCP)),XML_DTD__BuilderDesc_NewNameCP)((XML_DTD__Builder)i1, 0, (XML_UnicodeBuffer__CharArray)i0);
              return (XML_DTD__CP)i0;
l16:
              _failed_function(78320); return 0;
              ;
            }


          i0 = cpos;
          cpos = (i0+9);
          XML_Parser__ParserDesc_ParseDocument_S();
          i0 = (OOC_INT32)XML_Parser__ParserDesc_ParseDocument_Name(0u);
          elementName = (XML_UnicodeBuffer__CharArray)i0;
          XML_Parser__ParserDesc_ParseDocument_S();
          i0 = (OOC_INT32)XML_Parser__ParserDesc_ParseDocument_markupdecl_elementdecl_contentspec();
          cp = (XML_DTD__CP)i0;
          XML_Parser__ParserDesc_ParseDocument_OptS(0u);
          i1 = (OOC_INT32)currentEntity;
          i2 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 83314)))), XML_DTD__EntityDesc_IsDocumentEntity)),XML_DTD__EntityDesc_IsDocumentEntity)((XML_DTD__Entity)i1);
          i3 = (OOC_INT32)dtd;
          i4 = (OOC_INT32)elementName;
          i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 83265)))), XML_DTD__BuilderDesc_NewElementDecl)),XML_DTD__BuilderDesc_NewElementDecl)((XML_DTD__Builder)i3, (XML_UnicodeBuffer__CharArray)i4, (XML_DTD__CP)i0, (!i2));
          elementDecl = (XML_DTD__ElementDecl)i0;
          i2 = (OOC_INT32)dtd;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 83352))+12);
          i0 = XML_DTD__NamespaceDesc_Add((XML_DTD__Namespace)i2, (XML_DTD__Declaration)i0);
          i0 = !i0;
          if (!i0) goto l3;
          i0 = (OOC_INT32)dtd;
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 83416))+12);
          i0 = (OOC_INT32)XML_DTD__NamespaceDesc_Get((XML_DTD__Namespace)i0, (XML_UnicodeBuffer__CharArray)i4);
          decl = (XML_DTD__Declaration)i0;
          XML_DTD__ElementDeclDesc_SetMultipleDecl((XML_DTD__ElementDecl)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 83474)))), &_td_XML_DTD__ElementDeclDesc, 83474)));
l3:
          XML_Parser__ParserDesc_ParseDocument_CheckCurrentEntity((XML_DTD__Entity)i1);
          XML_Parser__ParserDesc_ParseDocument_CheckChar(62u);
          return;
          ;
        }

        
        void XML_Parser__ParserDesc_ParseDocument_markupdecl_AttListDecl(XML_DTD__Entity currentEntity) {
          register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7;
          XML_UnicodeBuffer__CharArray elementName;
          XML_UnicodeBuffer__CharArray attrName;
          XML_DTD__Enumeration attrEnumeration;
          OOC_INT8 attrType;
          XML_DTD__AttValue defaultValue;
          OOC_INT8 _default;
          XML_DTD__AttrDecl attrDecl;
          auto void XML_Parser__ParserDesc_ParseDocument_markupdecl_AttListDecl_AttType(OOC_INT8 *attrType, XML_DTD__Enumeration *_enum);
          auto void XML_Parser__ParserDesc_ParseDocument_markupdecl_AttListDecl_DefaultDecl(OOC_INT8 attrType, OOC_INT8 *_default, XML_DTD__AttValue *defaultValue);
            
            void XML_Parser__ParserDesc_ParseDocument_markupdecl_AttListDecl_AttType(OOC_INT8 *attrType, XML_DTD__Enumeration *_enum) {
              register OOC_INT32 i0,i1,i2;
              auto XML_DTD__Enumeration XML_Parser__ParserDesc_ParseDocument_markupdecl_AttListDecl_AttType_Enumeration(OOC_INT8 attrType);
                
                XML_DTD__Enumeration XML_Parser__ParserDesc_ParseDocument_markupdecl_AttListDecl_AttType_Enumeration(OOC_INT8 attrType) {
                  register OOC_INT32 i0,i1,i2,i3;

                  i0 = (OOC_INT32)dtd;
                  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 84290)))), XML_DTD__BuilderDesc_NewEnumeration)),XML_DTD__BuilderDesc_NewEnumeration)((XML_DTD__Builder)i0);
                  *_enum = (XML_DTD__Enumeration)i0;
                  XML_Parser__ParserDesc_ParseDocument_CheckChar(40u);
                  i0 = attrType;
l1_loop:
                  XML_Parser__ParserDesc_ParseDocument_OptS(0u);
                  switch (i0) {
                  case 7:
                    i1 = (OOC_INT32)XML_Parser__ParserDesc_ParseDocument_Name(1u);
                    i2 = (OOC_INT32)*_enum;
                    XML_DTD__EnumerationDesc_Append((XML_DTD__Enumeration)i2, (XML_UnicodeBuffer__CharArray)i1);
                    goto l6;
                  case 8:
                    i1 = (OOC_INT32)XML_Parser__ParserDesc_ParseDocument_Nmtoken(0u, 0u);
                    i2 = (OOC_INT32)*_enum;
                    XML_DTD__EnumerationDesc_Append((XML_DTD__Enumeration)i2, (XML_UnicodeBuffer__CharArray)i1);
                    goto l6;
                  default:
                    _failed_case(i0, 84398);
                    goto l6;
                  }
l6:
                  XML_Parser__ParserDesc_ParseDocument_OptS(0u);
                  i1 = (OOC_INT32)chars;
                  i1 = _check_pointer(i1, 84652);
                  i2 = OOC_ARRAY_LENGTH(i1, 0);
                  i3 = cpos;
                  i1 = *(OOC_UINT16*)(i1+(_check_index(i3, i2, OOC_UINT32, 84652))*2);
                  i1 = i1==124u;
                  if (!i1) goto l11;
                  XML_Parser__ParserDesc_ParseDocument_CheckChar(124u);
                  goto l1_loop;
l11:
                  XML_Parser__ParserDesc_ParseDocument_CheckChar(41u);
                  i0 = (OOC_INT32)*_enum;
                  return (XML_DTD__Enumeration)i0;
                  ;
                }


              *_enum = (XML_DTD__Enumeration)(OOC_INT32)0;
              i0 = XML_Parser__ParserDesc_ParseDocument_LookingAt("CDATA", 6, 1);
              if (i0) goto l43;
              i0 = XML_Parser__ParserDesc_ParseDocument_LookingAt("ID", 3, 1);
              if (i0) goto l41;
              i0 = XML_Parser__ParserDesc_ParseDocument_LookingAt("IDREF", 6, 1);
              if (i0) goto l39;
              i0 = XML_Parser__ParserDesc_ParseDocument_LookingAt("IDREFS", 7, 1);
              if (i0) goto l37;
              i0 = XML_Parser__ParserDesc_ParseDocument_LookingAt("ENTITY", 7, 1);
              if (i0) goto l35;
              i0 = XML_Parser__ParserDesc_ParseDocument_LookingAt("ENTITIES", 9, 1);
              if (i0) goto l33;
              i0 = XML_Parser__ParserDesc_ParseDocument_LookingAt("NMTOKEN", 8, 1);
              if (i0) goto l31;
              i0 = XML_Parser__ParserDesc_ParseDocument_LookingAt("NMTOKENS", 9, 1);
              if (i0) goto l29;
              i0 = XML_Parser__ParserDesc_ParseDocument_LookingAt("NOTATION", 9, 1);
              if (i0) goto l19;
              i0 = (OOC_INT32)chars;
              i0 = _check_pointer(i0, 85990);
              i1 = OOC_ARRAY_LENGTH(i0, 0);
              i2 = cpos;
              i0 = *(OOC_UINT16*)(i0+(_check_index(i2, i1, OOC_UINT32, 85990))*2);
              i0 = i0==40u;
              
              goto l21;
l19:
              i0=1u;
l21:
              if (i0) goto l23;
              XML_Parser__ParserDesc_ParseDocument_Err(107);
              XML_Parser__ParserDesc_ParseDocument_NextChar();
              *attrType = 9;
              goto l44;
l23:
              i0 = (OOC_INT32)chars;
              i0 = _check_pointer(i0, 86030);
              i1 = OOC_ARRAY_LENGTH(i0, 0);
              i2 = cpos;
              i0 = *(OOC_UINT16*)(i0+(_check_index(i2, i1, OOC_UINT32, 86030))*2);
              i0 = i0==40u;
              if (i0) goto l26;
              *attrType = 7;
              cpos = (i2+8);
              XML_Parser__ParserDesc_ParseDocument_S();
              i0=7;
              goto l27;
l26:
              *attrType = 8;
              i0=8;
l27:
              i0 = (OOC_INT32)XML_Parser__ParserDesc_ParseDocument_markupdecl_AttListDecl_AttType_Enumeration(i0);
              *_enum = (XML_DTD__Enumeration)i0;
              goto l44;
l29:
              i0 = cpos;
              cpos = (i0+8);
              *attrType = 6;
              goto l44;
l31:
              i0 = cpos;
              cpos = (i0+7);
              *attrType = 5;
              goto l44;
l33:
              i0 = cpos;
              cpos = (i0+8);
              *attrType = 4;
              goto l44;
l35:
              i0 = cpos;
              cpos = (i0+6);
              *attrType = 3;
              goto l44;
l37:
              i0 = cpos;
              cpos = (i0+6);
              *attrType = 2;
              goto l44;
l39:
              i0 = cpos;
              cpos = (i0+5);
              *attrType = 1;
              goto l44;
l41:
              i0 = cpos;
              cpos = (i0+2);
              *attrType = 0;
              goto l44;
l43:
              i0 = cpos;
              cpos = (i0+5);
              *attrType = 9;
l44:
              return;
              ;
            }

            
            void XML_Parser__ParserDesc_ParseDocument_markupdecl_AttListDecl_DefaultDecl(OOC_INT8 attrType, OOC_INT8 *_default, XML_DTD__AttValue *defaultValue) {
              register OOC_INT32 i0;

              *defaultValue = (XML_DTD__AttValue)(OOC_INT32)0;
              i0 = XML_Parser__ParserDesc_ParseDocument_LookingAt("#REQUIRED", 10, 1);
              if (i0) goto l11;
              i0 = XML_Parser__ParserDesc_ParseDocument_LookingAt("#IMPLIED", 9, 1);
              if (i0) goto l9;
              i0 = XML_Parser__ParserDesc_ParseDocument_LookingAt("#FIXED", 7, 1);
              if (i0) goto l7;
              *_default = 2;
              goto l8;
l7:
              i0 = cpos;
              cpos = (i0+6);
              XML_Parser__ParserDesc_ParseDocument_S();
              *_default = 3;
l8:
              i0 = (OOC_INT32)XML_Parser__ParserDesc_ParseDocument_AttValue(1u);
              *defaultValue = (XML_DTD__AttValue)i0;
              goto l12;
l9:
              i0 = cpos;
              cpos = (i0+8);
              *_default = 1;
              goto l12;
l11:
              i0 = cpos;
              cpos = (i0+9);
              *_default = 0;
l12:
              return;
              ;
            }


          i0 = cpos;
          cpos = (i0+9);
          XML_Parser__ParserDesc_ParseDocument_S();
          i0 = (OOC_INT32)XML_Parser__ParserDesc_ParseDocument_Name(0u);
          elementName = (XML_UnicodeBuffer__CharArray)i0;
l1_loop:
          i0 = (OOC_INT32)chars;
          i0 = _check_pointer(i0, 87459);
          i1 = OOC_ARRAY_LENGTH(i0, 0);
          i2 = cpos;
          i0 = *(OOC_UINT16*)(i0+(_check_index(i2, i1, OOC_UINT32, 87459))*2);
          i0 = i0!=62u;
          if (!i0) goto l4;
          XML_Parser__ParserDesc_ParseDocument_S();
l4:
          i0 = (OOC_INT32)chars;
          i1 = _check_pointer(i0, 87526);
          i2 = OOC_ARRAY_LENGTH(i1, 0);
          i3 = cpos;
          i1 = *(OOC_UINT16*)(i1+(_check_index(i3, i2, OOC_UINT32, 87526))*2);
          i1 = i1==62u;
          if (i1) goto l7;
          i0 = _check_pointer(i0, 87549);
          i1 = OOC_ARRAY_LENGTH(i0, 0);
          i0 = *(OOC_UINT16*)(i0+(_check_index(i3, i1, OOC_UINT32, 87549))*2);
          i0 = i0==65535u;
          
          goto l9;
l7:
          i0=1u;
l9:
          if (i0) goto l15;
          i0 = (OOC_INT32)XML_Parser__ParserDesc_ParseDocument_Name(0u);
          attrName = (XML_UnicodeBuffer__CharArray)i0;
          XML_Parser__ParserDesc_ParseDocument_S();
          XML_Parser__ParserDesc_ParseDocument_markupdecl_AttListDecl_AttType((void*)(OOC_INT32)&attrType, (void*)(OOC_INT32)&attrEnumeration);
          XML_Parser__ParserDesc_ParseDocument_S();
          i0 = attrType;
          XML_Parser__ParserDesc_ParseDocument_markupdecl_AttListDecl_DefaultDecl(i0, (void*)(OOC_INT32)&_default, (void*)(OOC_INT32)&defaultValue);
          i0 = (OOC_INT32)p;
          i0 = *(OOC_UINT8*)((_check_pointer(i0, 87794))+63);
          if (!i0) goto l1_loop;
          i0 = (OOC_INT32)currentEntity;
          i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 87978)))), XML_DTD__EntityDesc_IsDocumentEntity)),XML_DTD__EntityDesc_IsDocumentEntity)((XML_DTD__Entity)i0);
          i1 = (OOC_INT32)dtd;
          i2 = (OOC_INT32)defaultValue;
          i3 = _default;
          i4 = (OOC_INT32)attrEnumeration;
          i5 = attrType;
          i6 = (OOC_INT32)attrName;
          i7 = (OOC_INT32)elementName;
          i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 87848)))), XML_DTD__BuilderDesc_NewAttrDecl)),XML_DTD__BuilderDesc_NewAttrDecl)((XML_DTD__Builder)i1, (XML_UnicodeBuffer__CharArray)i7, (XML_UnicodeBuffer__CharArray)i6, i5, (XML_DTD__Enumeration)i4, i3, (XML_DTD__AttValue)i2, (!i0));
          attrDecl = (XML_DTD__AttrDecl)i0;
          i1 = (OOC_INT32)dtd;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 88016)))), XML_DTD__BuilderDesc_AddAttribute)),XML_DTD__BuilderDesc_AddAttribute)((XML_DTD__Builder)i1, (XML_DTD__AttrDecl)i0);
          goto l1_loop;
l15:
          i0 = (OOC_INT32)currentEntity;
          XML_Parser__ParserDesc_ParseDocument_CheckCurrentEntity((XML_DTD__Entity)i0);
          XML_Parser__ParserDesc_ParseDocument_CheckChar(62u);
          return;
          ;
        }

        
        void XML_Parser__ParserDesc_ParseDocument_markupdecl_EntityDecl(XML_DTD__Entity currentEntity) {
          register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8;
          OOC_CHAR8 isPEntity;
          XML_UnicodeBuffer__CharArray name;
          XML_UnicodeBuffer__CharArray _public;
          XML_UnicodeBuffer__CharArray system;
          XML_UnicodeBuffer__CharArray ndata;
          XML_UnicodeBuffer__CharArray entityValue;
          OOC_INT8 entityType;
          XML_DTD__Entity entity;
          URI__URI baseURI;
          auto XML_UnicodeBuffer__CharArray XML_Parser__ParserDesc_ParseDocument_markupdecl_EntityDecl_EntityValue(OOC_CHAR8 isPEntity);
            
            XML_UnicodeBuffer__CharArray XML_Parser__ParserDesc_ParseDocument_markupdecl_EntityDecl_EntityValue(OOC_CHAR8 isPEntity) {
              register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
              XML_UnicodeBuffer__CharArray string;
              struct XML_Locator__Position pos;
              OOC_INT32 startLevel;
              OOC_CHAR16 endChar;
              OOC_INT32 storedPos;
              XML_DTD__Fragment fragment;
              auto void XML_Parser__ParserDesc_ParseDocument_markupdecl_EntityDecl_EntityValue_Copy(OOC_INT32 start, OOC_INT32 end);
                
                void XML_Parser__ParserDesc_ParseDocument_markupdecl_EntityDecl_EntityValue_Copy(OOC_INT32 start, OOC_INT32 end) {
                  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7;

                  i0 = start;
                  i1 = end;
                  i2 = i0!=i1;
                  if (!i2) goto l8;
                  i2 = cdelta;
                  i3 = (OOC_INT32)chars;
                  i2 = (i2*(-1))+i0;
                  
l3_loop:
                  i4 = _check_pointer(i3, 88971);
                  i5 = OOC_ARRAY_LENGTH(i4, 0);
                  i6 = _check_pointer(i3, 88994);
                  i7 = OOC_ARRAY_LENGTH(i6, 0);
                  i6 = *(OOC_UINT16*)(i6+(_check_index(i0, i7, OOC_UINT32, 88994))*2);
                  *(OOC_UINT16*)(i4+(_check_index(i2, i5, OOC_UINT32, 88971))*2) = i6;
                  i0 = i0+1;
                  start = i0;
                  i2 = i2+1;
                  i4 = i0!=i1;
                  if (i4) goto l3_loop;
l8:
                  return;
                  ;
                }


              i0 = (OOC_INT32)XML_Parser__noName;
              string = (XML_UnicodeBuffer__CharArray)i0;
              i1 = (OOC_INT32)chars;
              i2 = _check_pointer(i1, 89127);
              i3 = OOC_ARRAY_LENGTH(i2, 0);
              i4 = cpos;
              i2 = *(OOC_UINT16*)(i2+(_check_index(i4, i3, OOC_UINT32, 89127))*2);
              i2 = i2==39u;
              if (i2) goto l3;
              i1 = _check_pointer(i1, 89150);
              i2 = OOC_ARRAY_LENGTH(i1, 0);
              i1 = *(OOC_UINT16*)(i1+(_check_index(i4, i2, OOC_UINT32, 89150))*2);
              i1 = i1==34u;
              
              goto l5;
l3:
              i1=1u;
l5:
              if (i1) goto l7;
              XML_Parser__ParserDesc_ParseDocument_Err(109);
              XML_Parser__ParserDesc_ParseDocument_NextChar();
              
              goto l32;
l7:
              i0 = (OOC_INT32)p;
              i1 = (OOC_INT32)dtd;
              i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 89435)))), XML_DTD__BuilderDesc_NewAttValue)),XML_DTD__BuilderDesc_NewAttValue)((XML_DTD__Builder)i1);
              *(OOC_INT32*)((_check_pointer(i0, 89411))+72) = i1;
              i0 = (OOC_INT32)&_td_XML_Locator__Position;
              XML_Parser__ParserDesc_ParseDocument_StorePosition((void*)(OOC_INT32)&pos, (RT0__Struct)i0);
              i1 = (OOC_INT32)p;
              i1 = *(OOC_INT32*)((_check_pointer(i1, 89525))+88);
              startLevel = i1;
              i1 = (OOC_INT32)chars;
              i1 = _check_pointer(i1, 89567);
              i2 = OOC_ARRAY_LENGTH(i1, 0);
              i3 = cpos;
              i1 = *(OOC_UINT16*)(i1+(_check_index(i3, i2, OOC_UINT32, 89567))*2);
              endChar = i1;
              i1 = i3+1;
              cpos = i1;
              cstart = i1;
              cdelta = 0;
l8_loop:
              i1 = (OOC_INT32)chars;
              i2 = _check_pointer(i1, 89681);
              i3 = OOC_ARRAY_LENGTH(i2, 0);
              i4 = cpos;
              i2 = *(OOC_UINT16*)(i2+(_check_index(i4, i3, OOC_UINT32, 89681))*2);
              switch (i2) {
              case 0u ... 31u:
              case 65534u:
                XML_Parser__ParserDesc_ParseDocument_ControlChar(10u);
                goto l8_loop;
              case 65535u:
                XML_Parser__ParserDesc_ParseDocument_ErrPos(6, (void*)(OOC_INT32)&pos, (RT0__Struct)i0);
                i0 = (OOC_INT32)dtd;
                i1 = cpos;
                i2 = cdelta;
                i3 = cstart;
                i4 = (OOC_INT32)chars;
                i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 89902)))), XML_DTD__BuilderDesc_NewCharacters)),XML_DTD__BuilderDesc_NewCharacters)((XML_DTD__Builder)i0, (XML_UnicodeBuffer__CharArray)i4, i3, (i1-i2), 1u);
                i1 = (OOC_INT32)p;
                i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 89872))+72);
                XML_DTD__AttValueDesc_Append((XML_DTD__AttValue)i1, (XML_DTD__Fragment)i0);
                goto l31;
              case 37u:
                i2 = cdelta;
                i2 = i4-i2;
                i3 = cstart;
                i4 = i3!=i2;
                if (i4) goto l14;
                goto l15;
l14:
                i4 = (OOC_INT32)dtd;
                i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 90209)))), XML_DTD__BuilderDesc_NewCharacters)),XML_DTD__BuilderDesc_NewCharacters)((XML_DTD__Builder)i4, (XML_UnicodeBuffer__CharArray)i1, i3, i2, 1u);
                i2 = (OOC_INT32)p;
                i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 90179))+72);
                XML_DTD__AttValueDesc_Append((XML_DTD__AttValue)i2, (XML_DTD__Fragment)i1);
l15:
                XML_Parser__ParserDesc_ParseDocument_PEReference(0u);
                goto l8_loop;
              case 38u:
                i1 = XML_Parser__ParserDesc_ParseDocument_LookingAt("&#", 3, 0);
                if (!i1) goto l18;
                goto l19;
l18:
                i1 = (OOC_INT32)p;
                i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 90750))+36);
                i1 = *(OOC_INT32*)((_check_pointer(i1, 90754))+24);
                i2 = cpos;
                i1 = i2+i1;
                storedPos = i1;
                i2 = (OOC_INT32)XML_Parser__ParserDesc_ParseDocument_EntityRef(0u, 1u);
                fragment = (XML_DTD__Fragment)i2;
                i2 = (OOC_INT32)p;
                i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 90862))+36);
                i2 = *(OOC_INT32*)((_check_pointer(i2, 90866))+24);
                i3 = cpos;
                XML_Parser__ParserDesc_ParseDocument_markupdecl_EntityDecl_EntityValue_Copy((i1-i2), i3);
                goto l8_loop;
l19:
                XML_Parser__ParserDesc_ParseDocument_CharRef();
                goto l8_loop;
              default:
                i2 = _check_pointer(i1, 90954);
                i3 = OOC_ARRAY_LENGTH(i2, 0);
                i2 = *(OOC_UINT16*)(i2+(_check_index(i4, i3, OOC_UINT32, 90954))*2);
                i3 = endChar;
                i2 = i2==i3;
                if (i2) goto l24;
                i2=0u;
                goto l26;
l24:
                i2 = (OOC_INT32)p;
                i2 = *(OOC_INT32*)((_check_pointer(i2, 90976))+88);
                i5 = startLevel;
                i2 = i2==i5;
                
l26:
                if (i2) goto l29;
                i2 = _check_pointer(i1, 91355);
                i3 = cdelta;
                i5 = OOC_ARRAY_LENGTH(i2, 0);
                i1 = _check_pointer(i1, 91377);
                i6 = OOC_ARRAY_LENGTH(i1, 0);
                i1 = *(OOC_UINT16*)(i1+(_check_index(i4, i6, OOC_UINT32, 91377))*2);
                *(OOC_UINT16*)(i2+(_check_index((i4-i3), i5, OOC_UINT32, 91355))*2) = i1;
                cpos = (i4+1);
                goto l8_loop;
l29:
                i0 = (OOC_INT32)dtd;
                i2 = cdelta;
                i5 = cstart;
                i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 91188)))), XML_DTD__BuilderDesc_NewCharacters)),XML_DTD__BuilderDesc_NewCharacters)((XML_DTD__Builder)i0, (XML_UnicodeBuffer__CharArray)i1, i5, (i4-i2), 1u);
                i1 = (OOC_INT32)p;
                i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 91158))+72);
                XML_DTD__AttValueDesc_Append((XML_DTD__AttValue)i1, (XML_DTD__Fragment)i0);
                XML_Parser__ParserDesc_ParseDocument_CheckChar(i3);
                goto l31;
              }
l31:
              i0 = (OOC_INT32)p;
              i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 91474))+72);
              i0 = (OOC_INT32)XML_DTD__AttValueDesc_Flatten((XML_DTD__AttValue)i0, (XML_DTD__AttrDecl)(OOC_INT32)0);
              string = (XML_UnicodeBuffer__CharArray)i0;
              i1 = (OOC_INT32)p;
              *(OOC_INT32*)((_check_pointer(i1, 91521))+72) = (OOC_INT32)0;
              
l32:
              return (XML_UnicodeBuffer__CharArray)i0;
              ;
            }


          i0 = cpos;
          cpos = (i0+8);
          XML_Parser__ParserDesc_ParseDocument_SnoPE();
          i0 = (OOC_INT32)chars;
          i0 = _check_pointer(i0, 91790);
          i1 = OOC_ARRAY_LENGTH(i0, 0);
          i2 = cpos;
          i0 = *(OOC_UINT16*)(i0+(_check_index(i2, i1, OOC_UINT32, 91790))*2);
          i0 = i0==37u;
          isPEntity = i0;
          if (!i0) goto l3;
          XML_Parser__ParserDesc_ParseDocument_CheckChar(37u);
          XML_Parser__ParserDesc_ParseDocument_S();
l3:
          i1 = (OOC_INT32)p;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 91907))+4);
          i2 = _check_pointer(i2, 91910);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 91907))+4);
          i2 = (OOC_INT32)&_td_XML_Locator__Position;
          XML_Parser__ParserDesc_ParseDocument_StorePosition((void*)(_check_pointer(i1, 91910)), (RT0__Struct)i2);
          i1 = (OOC_INT32)XML_Parser__ParserDesc_ParseDocument_Name(1u);
          name = (XML_UnicodeBuffer__CharArray)i1;
          XML_Parser__ParserDesc_ParseDocument_S();
          i3 = (OOC_INT32)chars;
          i4 = _check_pointer(i3, 91971);
          i5 = OOC_ARRAY_LENGTH(i4, 0);
          i6 = cpos;
          i4 = *(OOC_UINT16*)(i4+(_check_index(i6, i5, OOC_UINT32, 91971))*2);
          i4 = i4==39u;
          if (i4) goto l6;
          i3 = _check_pointer(i3, 91994);
          i4 = OOC_ARRAY_LENGTH(i3, 0);
          i3 = *(OOC_UINT16*)(i3+(_check_index(i6, i4, OOC_UINT32, 91994))*2);
          i3 = i3==34u;
          
          goto l8;
l6:
          i3=1u;
l8:
          if (i3) goto l26;
          entityValue = (XML_UnicodeBuffer__CharArray)(OOC_INT32)0;
          if (i0) goto l12;
          entityType = 2;
          i2=2;
          goto l13;
l12:
          entityType = 3;
          i2=3;
l13:
          XML_Parser__ParserDesc_ParseDocument_ExternalID(0u, (void*)(OOC_INT32)&_public, (void*)(OOC_INT32)&system, (void*)(OOC_INT32)&baseURI);
          ndata = (XML_UnicodeBuffer__CharArray)(OOC_INT32)0;
          i3 = !i0;
          if (i3) goto l16;
          i3=0u;
          goto l18;
l16:
          i3 = XML_Parser__ParserDesc_ParseDocument_LookingAtS();
          
l18:
          if (i3) goto l20;
          i3=i2;i2=(OOC_INT32)0;
          goto l25;
l20:
          XML_Parser__ParserDesc_ParseDocument_S();
          i3 = XML_Parser__ParserDesc_ParseDocument_LookingAt("NDATA", 6, 1);
          if (i3) goto l23;
          i3=i2;i2=(OOC_INT32)0;
          goto l25;
l23:
          i2 = cpos;
          entityType = 4;
          cpos = (i2+5);
          XML_Parser__ParserDesc_ParseDocument_S();
          i2 = (OOC_INT32)XML_Parser__ParserDesc_ParseDocument_Name(0u);
          ndata = (XML_UnicodeBuffer__CharArray)i2;
          i3=4;
l25:
          i4 = (OOC_INT32)currentEntity;
          i4 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 93317)))), XML_DTD__EntityDesc_IsDocumentEntity)),XML_DTD__EntityDesc_IsDocumentEntity)((XML_DTD__Entity)i4);
          i5 = (OOC_INT32)dtd;
          i6 = (OOC_INT32)baseURI;
          i7 = (OOC_INT32)system;
          i8 = (OOC_INT32)_public;
          i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 93203)))), XML_DTD__BuilderDesc_NewExternalEntity)),XML_DTD__BuilderDesc_NewExternalEntity)((XML_DTD__Builder)i5, (XML_UnicodeBuffer__CharArray)i1, i3, (XML_UnicodeBuffer__CharArray)i8, (XML_UnicodeBuffer__CharArray)i7, (XML_UnicodeBuffer__CharArray)i2, (URI__URI)i6, (!i4));
          entity = (XML_DTD__Entity)i1;
          
          goto l38;
l26:
          _public = (XML_UnicodeBuffer__CharArray)(OOC_INT32)0;
          system = (XML_UnicodeBuffer__CharArray)(OOC_INT32)0;
          ndata = (XML_UnicodeBuffer__CharArray)(OOC_INT32)0;
          i0 = (OOC_INT32)XML_Parser__ParserDesc_ParseDocument_markupdecl_EntityDecl_EntityValue(i0);
          entityValue = (XML_UnicodeBuffer__CharArray)i0;
          i1 = isPEntity;
          if (i1) goto l29;
          entityType = 0;
          i3=0;
          goto l30;
l29:
          entityType = 1;
          i3=1;
l30:
          i4 = (OOC_INT32)name;
          i5 = !i1;
          if (i5) goto l33;
          i5=0u;
          goto l35;
l33:
          i5 = (OOC_INT32)dtd;
          i5 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 92312)))), XML_DTD__BuilderDesc_IsValidEntityDecl)),XML_DTD__BuilderDesc_IsValidEntityDecl)((XML_DTD__Builder)i5, (XML_UnicodeBuffer__CharArray)i4, (XML_UnicodeBuffer__CharArray)i0);
          i5 = !i5;
          
l35:
          if (!i5) goto l37;
          i5 = (OOC_INT32)p;
          i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 92403))+4);
          i6 = _check_pointer(i6, 92406);
          i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 92403))+4);
          XML_Parser__ParserDesc_ParseDocument_ErrPos(118, (void*)(_check_pointer(i5, 92406)), (RT0__Struct)i2);
l37:
          i2 = (OOC_INT32)currentEntity;
          i2 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 92557)))), XML_DTD__EntityDesc_IsDocumentEntity)),XML_DTD__EntityDesc_IsDocumentEntity)((XML_DTD__Entity)i2);
          i5 = (OOC_INT32)dtd;
          i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 92447)))), XML_DTD__BuilderDesc_NewInternalEntity)),XML_DTD__BuilderDesc_NewInternalEntity)((XML_DTD__Builder)i5, (XML_UnicodeBuffer__CharArray)i4, i3, (XML_UnicodeBuffer__CharArray)i0, (!i2));
          entity = (XML_DTD__Entity)i0;
          {register OOC_INT32 h0=i0;i0=i1;i1=h0;}
l38:
          XML_Parser__ParserDesc_ParseDocument_OptS(0u);
          i2 = (OOC_INT32)currentEntity;
          XML_Parser__ParserDesc_ParseDocument_CheckCurrentEntity((XML_DTD__Entity)i2);
          XML_Parser__ParserDesc_ParseDocument_CheckChar(62u);
          i2 = (OOC_INT32)p;
          i2 = *(OOC_UINT8*)((_check_pointer(i2, 93456))+63);
          if (!i2) goto l48;
l41:
          if (i0) goto l46;
          i0 = (OOC_INT32)dtd;
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 93582))+4);
          i0 = XML_DTD__NamespaceDesc_Add((XML_DTD__Namespace)i0, (XML_DTD__Declaration)i1);
          if (!i0) goto l48;
          i0 = (OOC_INT32)p;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 93628))+44);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 93628))+44);
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 93637)))), XML_Builder__BuilderDesc_EntityDecl)),XML_Builder__BuilderDesc_EntityDecl)((XML_Builder__Builder)i0, (XML_DTD__Entity)i1);
          goto l48;
l46:
          i0 = (OOC_INT32)dtd;
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 93535))+8);
          i0 = XML_DTD__NamespaceDesc_Add((XML_DTD__Namespace)i0, (XML_DTD__Declaration)i1);
l48:
          return;
          ;
        }

        
        void XML_Parser__ParserDesc_ParseDocument_markupdecl_NotationDecl(XML_DTD__Entity currentEntity) {
          register OOC_INT32 i0,i1,i2,i3,i4;
          XML_UnicodeBuffer__CharArray name;
          URI__URI baseURI;
          XML_UnicodeBuffer__CharArray system;
          XML_UnicodeBuffer__CharArray _public;

          i0 = cpos;
          cpos = (i0+10);
          XML_Parser__ParserDesc_ParseDocument_S();
          i0 = (OOC_INT32)p;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 94040))+4);
          i1 = _check_pointer(i1, 94043);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 94040))+4);
          XML_Parser__ParserDesc_ParseDocument_StorePosition((void*)(_check_pointer(i0, 94043)), (RT0__Struct)((OOC_INT32)&_td_XML_Locator__Position));
          i0 = (OOC_INT32)XML_Parser__ParserDesc_ParseDocument_Name(1u);
          name = (XML_UnicodeBuffer__CharArray)i0;
          XML_Parser__ParserDesc_ParseDocument_S();
          XML_Parser__ParserDesc_ParseDocument_ExternalID(1u, (void*)(OOC_INT32)&_public, (void*)(OOC_INT32)&system, (void*)(OOC_INT32)&baseURI);
          XML_Parser__ParserDesc_ParseDocument_OptS(0u);
          i1 = (OOC_INT32)dtd;
          i2 = (OOC_INT32)_public;
          i3 = (OOC_INT32)system;
          i4 = (OOC_INT32)baseURI;
          i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 94364)))), XML_DTD__BuilderDesc_NewNotation)),XML_DTD__BuilderDesc_NewNotation)((XML_DTD__Builder)i1, (XML_UnicodeBuffer__CharArray)i0, (XML_UnicodeBuffer__CharArray)i2, (XML_UnicodeBuffer__CharArray)i3, (URI__URI)i4);
          i1 = (OOC_INT32)p;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 94340))+44);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 94340))+44);
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 94349)))), XML_Builder__BuilderDesc_Notation)),XML_Builder__BuilderDesc_Notation)((XML_Builder__Builder)i1, (XML_DTD__Notation)i0);
          i0 = (OOC_INT32)currentEntity;
          XML_Parser__ParserDesc_ParseDocument_CheckCurrentEntity((XML_DTD__Entity)i0);
          XML_Parser__ParserDesc_ParseDocument_CheckChar(62u);
          return;
          ;
        }


      i0 = XML_Parser__ParserDesc_ParseDocument_LookingAt("<!ELEMENT", 10, 1);
      if (i0) goto l23;
      i0 = XML_Parser__ParserDesc_ParseDocument_LookingAt("<!ATTLIST", 10, 1);
      if (i0) goto l21;
      i0 = XML_Parser__ParserDesc_ParseDocument_LookingAt("<!ENTITY", 9, 1);
      if (i0) goto l19;
      i0 = XML_Parser__ParserDesc_ParseDocument_LookingAt("<!NOTATION", 11, 1);
      if (i0) goto l17;
      i0 = XML_Parser__ParserDesc_ParseDocument_LookingAt("<?", 3, 0);
      if (i0) goto l15;
      i0 = XML_Parser__ParserDesc_ParseDocument_LookingAt("<!--", 5, 0);
      if (i0) goto l13;
      XML_Parser__ParserDesc_ParseDocument_Err(105);
      XML_Parser__ParserDesc_ParseDocument_NextChar();
      goto l24;
l13:
      XML_Parser__ParserDesc_ParseDocument_Comment();
      goto l24;
l15:
      XML_Parser__ParserDesc_ParseDocument_PI();
      goto l24;
l17:
      i0 = (OOC_INT32)XML_Parser__ParserDesc_ParseDocument_CurrentEntity();
      XML_Parser__ParserDesc_ParseDocument_markupdecl_NotationDecl((XML_DTD__Entity)i0);
      goto l24;
l19:
      i0 = (OOC_INT32)XML_Parser__ParserDesc_ParseDocument_CurrentEntity();
      XML_Parser__ParserDesc_ParseDocument_markupdecl_EntityDecl((XML_DTD__Entity)i0);
      goto l24;
l21:
      i0 = (OOC_INT32)XML_Parser__ParserDesc_ParseDocument_CurrentEntity();
      XML_Parser__ParserDesc_ParseDocument_markupdecl_AttListDecl((XML_DTD__Entity)i0);
      goto l24;
l23:
      i0 = (OOC_INT32)XML_Parser__ParserDesc_ParseDocument_CurrentEntity();
      XML_Parser__ParserDesc_ParseDocument_markupdecl_elementdecl((XML_DTD__Entity)i0);
l24:
      XML_Parser__ParserDesc_ParseDocument_DiscardPreviousInput();
      return;
      ;
    }

    
    void XML_Parser__ParserDesc_ParseDocument_extSubsetDecl(void) {
      register OOC_INT32 i0,i1,i2,i3,i4;
      XML_DTD__Entity currentEntity;
      struct XML_Locator__Position pos;
      auto void XML_Parser__ParserDesc_ParseDocument_extSubsetDecl_ignoreSectContents(void);
        
        void XML_Parser__ParserDesc_ParseDocument_extSubsetDecl_ignoreSectContents(void) {
          register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7;
          OOC_INT32 level;

          level = 1;
          i0 = cpos;
          cstart = i0;
          i0 = (OOC_INT32)&_td_XML_Locator__Position;
          cdelta = 0;
          i1=1;
l1_loop:
          i2 = (OOC_INT32)chars;
          i3 = _check_pointer(i2, 95469);
          i4 = OOC_ARRAY_LENGTH(i3, 0);
          i5 = cpos;
          i3 = *(OOC_UINT16*)(i3+(_check_index(i5, i4, OOC_UINT32, 95469))*2);
          switch (i3) {
          case 0u ... 31u:
          case 65534u:
            XML_Parser__ParserDesc_ParseDocument_ControlChar(10u);
            
            goto l1_loop;
          case 65535u:
            XML_Parser__ParserDesc_ParseDocument_ErrPos(19, (void*)(OOC_INT32)&pos, (RT0__Struct)i0);
            goto l23;
          case 93u:
            i2 = XML_Parser__ParserDesc_ParseDocument_LookingAt("]]>", 4, 0);
            if (i2) goto l8;
            i2 = (OOC_INT32)chars;
            i3 = _check_pointer(i2, 96017);
            i4 = cdelta;
            i5 = cpos;
            i6 = OOC_ARRAY_LENGTH(i3, 0);
            i2 = _check_pointer(i2, 96039);
            i7 = OOC_ARRAY_LENGTH(i2, 0);
            i2 = *(OOC_UINT16*)(i2+(_check_index(i5, i7, OOC_UINT32, 96039))*2);
            *(OOC_UINT16*)(i3+(_check_index((i5-i4), i6, OOC_UINT32, 96017))*2) = i2;
            cpos = (i5+1);
            
            goto l1_loop;
l8:
            i2 = i1==1;
            if (!i2) goto l11;
            i2 = (OOC_INT32)currentEntity;
            XML_Parser__ParserDesc_ParseDocument_CheckCurrentEntity((XML_DTD__Entity)i2);
l11:
            i2 = cpos;
            cpos = (i2+3);
            i1 = i1-1;
            level = i1;
            i2 = i1==0;
            if (!i2) goto l1_loop;
            goto l23;
          case 60u:
            i2 = XML_Parser__ParserDesc_ParseDocument_LookingAt("<![", 4, 0);
            if (!i2) goto l18;
            goto l19;
l18:
            i2 = (OOC_INT32)chars;
            i3 = _check_pointer(i2, 96269);
            i4 = cdelta;
            i5 = cpos;
            i6 = OOC_ARRAY_LENGTH(i3, 0);
            i2 = _check_pointer(i2, 96291);
            i7 = OOC_ARRAY_LENGTH(i2, 0);
            i2 = *(OOC_UINT16*)(i2+(_check_index(i5, i7, OOC_UINT32, 96291))*2);
            *(OOC_UINT16*)(i3+(_check_index((i5-i4), i6, OOC_UINT32, 96269))*2) = i2;
            cpos = (i5+1);
            
            goto l1_loop;
l19:
            i2 = cpos;
            cpos = (i2+3);
            i1 = i1+1;
            level = i1;
            
            goto l1_loop;
          default:
            i3 = _check_pointer(i2, 96358);
            i4 = cdelta;
            i6 = OOC_ARRAY_LENGTH(i3, 0);
            i2 = _check_pointer(i2, 96380);
            i7 = OOC_ARRAY_LENGTH(i2, 0);
            i2 = *(OOC_UINT16*)(i2+(_check_index(i5, i7, OOC_UINT32, 96380))*2);
            *(OOC_UINT16*)(i3+(_check_index((i5-i4), i6, OOC_UINT32, 96358))*2) = i2;
            cpos = (i5+1);
            
            goto l1_loop;
          }
l23:
          return;
          ;
        }


      i0 = (OOC_INT32)&_td_XML_Locator__Position;
l1_loop:
      i1 = (OOC_INT32)chars;
      i2 = _check_pointer(i1, 96498);
      i3 = OOC_ARRAY_LENGTH(i2, 0);
      i4 = cpos;
      i2 = *(OOC_UINT16*)(i2+(_check_index(i4, i3, OOC_UINT32, 96498))*2);
      i2 = i2==60u;
      if (i2) goto l12;
      i1 = _check_pointer(i1, 97637);
      i2 = OOC_ARRAY_LENGTH(i1, 0);
      i1 = *(OOC_UINT16*)(i1+(_check_index(i4, i2, OOC_UINT32, 97637))*2);
      i1 = i1==37u;
      if (!i1) goto l5;
      goto l10;
l5:
      i1 = XML_Parser__ParserDesc_ParseDocument_LookingAtSnoPE();
      if (!i1) goto l30;
      XML_Parser__ParserDesc_ParseDocument_SnoPE();
      goto l1_loop;
l10:
      XML_Parser__ParserDesc_ParseDocument_PEReference(1u);
      goto l1_loop;
l12:
      i1 = (OOC_INT32)XML_Parser__ParserDesc_ParseDocument_CurrentEntity();
      currentEntity = (XML_DTD__Entity)i1;
      XML_Parser__ParserDesc_ParseDocument_StorePosition((void*)(OOC_INT32)&pos, (RT0__Struct)i0);
      i2 = XML_Parser__ParserDesc_ParseDocument_LookingAt("<![", 4, 0);
      if (i2) goto l15;
      XML_Parser__ParserDesc_ParseDocument_markupdecl();
      goto l1_loop;
l15:
      i2 = cpos;
      cpos = (i2+3);
      XML_Parser__ParserDesc_ParseDocument_OptS(0u);
      i2 = XML_Parser__ParserDesc_ParseDocument_LookingAt("INCLUDE", 8, 1);
      if (i2) goto l22;
      i2 = XML_Parser__ParserDesc_ParseDocument_LookingAt("IGNORE", 7, 1);
      if (!i2) goto l19;
      goto l20;
l19:
      XML_Parser__ParserDesc_ParseDocument_Err(113);
      goto l1_loop;
l20:
      i2 = cpos;
      cpos = (i2+6);
      XML_Parser__ParserDesc_ParseDocument_OptS(0u);
      XML_Parser__ParserDesc_ParseDocument_CheckCurrentEntity((XML_DTD__Entity)i1);
      XML_Parser__ParserDesc_ParseDocument_CheckChar(91u);
      XML_Parser__ParserDesc_ParseDocument_extSubsetDecl_ignoreSectContents();
      goto l1_loop;
l22:
      i2 = cpos;
      cpos = (i2+7);
      XML_Parser__ParserDesc_ParseDocument_OptS(0u);
      XML_Parser__ParserDesc_ParseDocument_CheckCurrentEntity((XML_DTD__Entity)i1);
      XML_Parser__ParserDesc_ParseDocument_CheckChar(91u);
      XML_Parser__ParserDesc_ParseDocument_extSubsetDecl();
      XML_Parser__ParserDesc_ParseDocument_CheckCurrentEntity((XML_DTD__Entity)i1);
      i1 = XML_Parser__ParserDesc_ParseDocument_LookingAt("]]>", 4, 0);
      if (!i1) goto l24;
      goto l25;
l24:
      XML_Parser__ParserDesc_ParseDocument_Err(18);
      goto l1_loop;
l25:
      i1 = cpos;
      cpos = (i1+3);
      goto l1_loop;
l30:
      return;
      ;
    }

    
    void XML_Parser__ParserDesc_ParseDocument_prolog(void) {
      register OOC_INT32 i0;
      auto void XML_Parser__ParserDesc_ParseDocument_prolog_doctypedecl(void);
        
        void XML_Parser__ParserDesc_ParseDocument_prolog_doctypedecl(void) {
          register OOC_INT32 i0,i1,i2,i3,i4;
          XML_UnicodeBuffer__CharArray rootName;
          URI__URI baseURI;
          XML_UnicodeBuffer__CharArray system;
          XML_UnicodeBuffer__CharArray _public;
          XML_DTD__ExternalEntity externalSubset;
          XML_DTD__Declaration decl;
          XML_DTD__AttrDecl attr;
          auto void XML_Parser__ParserDesc_ParseDocument_prolog_doctypedecl_CheckGeneralEntities(void);
            
            void XML_Parser__ParserDesc_ParseDocument_prolog_doctypedecl_CheckGeneralEntities(void) {
              register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8;
              XML_Builder__Builder oldBuilder;
              OOC_INT32 oldErrCount;
              OOC_CHAR8 oldValidating;
              struct XML_Locator__Position pos;
              XML_DTD__Declaration decl;
              OOC_INT32 len;

              i0 = (OOC_INT32)p;
              i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 98552))+44);
              oldBuilder = (XML_Builder__Builder)i1;
              i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 98589));
              i2 = *(OOC_INT32*)(_check_pointer(i2, 98598));
              oldErrCount = i2;
              i0 = *(OOC_UINT8*)((_check_pointer(i0, 98638))+62);
              oldValidating = i0;
              i3 = (OOC_INT32)&_td_XML_Locator__Position;
              XML_Parser__ParserDesc_ParseDocument_StorePosition((void*)(OOC_INT32)&pos, (RT0__Struct)i3);
              i4 = (OOC_INT32)p;
              i5 = (OOC_INT32)XML_Builder__New();
              *(OOC_INT32*)((_check_pointer(i4, 98705))+44) = i5;
              i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 98752))+48);
              i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 98757))+4);
              i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 98770));
              decl = (XML_DTD__Declaration)i4;
              i5 = i4!=0;
              if (!i5) goto l14;
l3_loop:
              i5 = *(OOC_INT8*)((_check_pointer((_type_guard(i4, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 98839)))), &_td_XML_DTD__EntityDesc, 98839)), 98846))+8);
              i5 = i5==0;
              if (!i5) goto l9;
              i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 98932))+4);
              i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 98932))+4);
              i5 = OOC_ARRAY_LENGTH((_check_pointer(i5, 98938)), 0);
              i5 = LongStrings__Length((void*)(_check_pointer(i6, 98938)), i5);
              i5 = i5+2;
              i6 = cpos;
              len = i5;
              cpos = (i6+i5);
              XML_Parser__ParserDesc_ParseDocument_PushEntity((XML_DTD__Entity)(_type_guard(i4, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 98996)))), &_td_XML_DTD__EntityDesc, 98996)), 1u);
              XML_Parser__ParserDesc_ParseDocument_content();
              i6 = (OOC_INT32)chars;
              i6 = _check_pointer(i6, 99073);
              i7 = OOC_ARRAY_LENGTH(i6, 0);
              i8 = cpos;
              i6 = *(OOC_UINT16*)(i6+(_check_index(i8, i7, OOC_UINT32, 99073))*2);
              i6 = i6!=65535u;
              if (!i6) goto l8;
              XML_Parser__ParserDesc_ParseDocument_ErrPos(302, (void*)(OOC_INT32)&pos, (RT0__Struct)i3);
              i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 99283))+4);
              i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 99283))+4);
              i6 = OOC_ARRAY_LENGTH((_check_pointer(i6, 99289)), 0);
              i6 = (OOC_INT32)Msg__GetLStringPtr((void*)(_check_pointer(i7, 99289)), i6);
              i7 = (OOC_INT32)p;
              i8 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i7, 99174))+104);
              i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i7, 99174))+104);
              OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i8, 99185)))), Msg__MsgDesc_SetLStringAttrib)),Msg__MsgDesc_SetLStringAttrib)((Msg__Msg)i7, "name", 5, (Msg__LStringPtr)i6);
l8:
              XML_Parser__ParserDesc_ParseDocument_PopEntity();
              i6 = cpos;
              cpos = (i6-i5);
l9:
              i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 99410));
              decl = (XML_DTD__Declaration)i4;
              i5 = i4!=0;
              if (i5) goto l3_loop;
l14:
              i3 = (OOC_INT32)p;
              *(OOC_UINT8*)((_check_pointer(i3, 99517))+62) = i0;
              i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 99563));
              i0 = *(OOC_INT32*)(_check_pointer(i0, 99572));
              i0 = i0==i2;
              if (i0) goto l17;
              i0 = (OOC_INT32)XML_Builder__New();
              *(OOC_INT32*)((_check_pointer(i3, 99744))+44) = i0;
              goto l18;
l17:
              *(OOC_INT32*)((_check_pointer(i3, 99638))+44) = i1;
l18:
              return;
              ;
            }


          i0 = (OOC_INT32)p;
          *(OOC_UINT8*)((_check_pointer(i0, 99890))+66) = 1u;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 99940))+4);
          i1 = _check_pointer(i1, 99943);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 99940))+4);
          i1 = (OOC_INT32)&_td_XML_Locator__Position;
          XML_Parser__ParserDesc_ParseDocument_StorePosition((void*)(_check_pointer(i0, 99943)), (RT0__Struct)i1);
          i0 = (OOC_INT32)p;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 99956))+44);
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 99978))+48);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 99956))+44);
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 99965)))), XML_Builder__BuilderDesc_StartDTD)),XML_Builder__BuilderDesc_StartDTD)((XML_Builder__Builder)i0, (XML_DTD__Builder)i3);
          i0 = cpos;
          cpos = (i0+9);
          XML_Parser__ParserDesc_ParseDocument_S();
          i0 = (OOC_INT32)XML_Parser__ParserDesc_ParseDocument_Name(0u);
          rootName = (XML_UnicodeBuffer__CharArray)i0;
          i2 = (OOC_INT32)p;
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 100135))+48);
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 100135))+48);
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 100140)))), XML_DTD__BuilderDesc_SetRootName)),XML_DTD__BuilderDesc_SetRootName)((XML_DTD__Builder)i2, (XML_UnicodeBuffer__CharArray)i0);
          XML_Parser__ParserDesc_ParseDocument_OptS(0u);
          i0 = XML_Parser__ParserDesc_ParseDocument_LookingAt("SYSTEM", 7, 0);
          if (i0) goto l3;
          i0 = XML_Parser__ParserDesc_ParseDocument_LookingAt("PUBLIC", 7, 0);
          
          goto l5;
l3:
          i0=1u;
l5:
          if (i0) goto l7;
          system = (XML_UnicodeBuffer__CharArray)(OOC_INT32)0;
          _public = (XML_UnicodeBuffer__CharArray)(OOC_INT32)0;
          baseURI = (URI__URI)(OOC_INT32)0;
          goto l8;
l7:
          XML_Parser__ParserDesc_ParseDocument_ExternalID(0u, (void*)(OOC_INT32)&_public, (void*)(OOC_INT32)&system, (void*)(OOC_INT32)&baseURI);
          XML_Parser__ParserDesc_ParseDocument_OptS(0u);
l8:
          i0 = (OOC_INT32)chars;
          i0 = _check_pointer(i0, 100583);
          i2 = OOC_ARRAY_LENGTH(i0, 0);
          i3 = cpos;
          i0 = *(OOC_UINT16*)(i0+(_check_index(i3, i2, OOC_UINT32, 100583))*2);
          i0 = i0==91u;
          if (!i0) goto l28;
          XML_Parser__ParserDesc_ParseDocument_CheckChar(91u);
l11_loop:
          i0 = (OOC_INT32)chars;
          i2 = _check_pointer(i0, 100665);
          i3 = OOC_ARRAY_LENGTH(i2, 0);
          i4 = cpos;
          i2 = *(OOC_UINT16*)(i2+(_check_index(i4, i3, OOC_UINT32, 100665))*2);
          i2 = i2==60u;
          if (!i2) goto l13;
          goto l22;
l13:
          i0 = _check_pointer(i0, 100733);
          i2 = OOC_ARRAY_LENGTH(i0, 0);
          i0 = *(OOC_UINT16*)(i0+(_check_index(i4, i2, OOC_UINT32, 100733))*2);
          i0 = i0==37u;
          if (!i0) goto l15;
          goto l20;
l15:
          i0 = XML_Parser__ParserDesc_ParseDocument_LookingAtSnoPE();
          if (!i0) goto l24;
          XML_Parser__ParserDesc_ParseDocument_SnoPE();
          goto l11_loop;
l20:
          XML_Parser__ParserDesc_ParseDocument_PEReference(1u);
          goto l11_loop;
l22:
          XML_Parser__ParserDesc_ParseDocument_markupdecl();
          goto l11_loop;
l24:
          i0 = (OOC_INT32)p;
          i0 = *(OOC_INT32*)((_check_pointer(i0, 100927))+88);
          i0 = i0!=0;
          if (!i0) goto l27;
          XML_Parser__ParserDesc_ParseDocument_Err(300);
l27:
          XML_Parser__ParserDesc_ParseDocument_CheckChar(93u);
          XML_Parser__ParserDesc_ParseDocument_OptS(0u);
l28:
          XML_Parser__ParserDesc_ParseDocument_CheckChar(62u);
          externalSubset = (XML_DTD__ExternalEntity)(OOC_INT32)0;
          i0 = (OOC_INT32)_public;
          i2 = i0!=(OOC_INT32)0;
          if (i2) goto l31;
          i2 = (OOC_INT32)system;
          i2 = i2!=(OOC_INT32)0;
          
          goto l33;
l31:
          i2=1u;
l33:
          if (!i2) goto l45;
          i2 = (OOC_INT32)p;
          i2 = *(OOC_UINT8*)((_check_pointer(i2, 101190))+60);
          if (i2) goto l37;
          XML_Parser__ParserDesc_ParseDocument_SkippedEntity((XML_UnicodeBuffer__CharArray)(OOC_INT32)0);
          goto l45;
l37:
          i2 = (OOC_INT32)dtd;
          i3 = (OOC_INT32)baseURI;
          i4 = (OOC_INT32)system;
          i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 101248)))), XML_DTD__BuilderDesc_NewExternalDTD)),XML_DTD__BuilderDesc_NewExternalDTD)((XML_DTD__Builder)i2, (XML_UnicodeBuffer__CharArray)i0, (XML_UnicodeBuffer__CharArray)i4, (URI__URI)i3);
          externalSubset = (XML_DTD__ExternalEntity)i0;
          XML_Parser__ParserDesc_ParseDocument_PushEntity((XML_DTD__Entity)i0, 1u);
          i2 = (OOC_INT32)p;
          *(OOC_UINT8*)((_check_pointer(i2, 101352))+67) = 1u;
          i2 = XML_Parser__ParserDesc_ParseDocument_LookingAt("<?xml", 6, 1);
          if (!i2) goto l40;
          XML_Parser__ParserDesc_ParseDocument_XMLDecl((XML_DTD__ExternalEntity)i0);
l40:
          XML_Parser__ParserDesc_ParseDocument_extSubsetDecl();
          i0 = (OOC_INT32)p;
          *(OOC_UINT8*)((_check_pointer(i0, 101535))+67) = 0u;
          i0 = (OOC_INT32)chars;
          i0 = _check_pointer(i0, 101585);
          i2 = OOC_ARRAY_LENGTH(i0, 0);
          i3 = cpos;
          i0 = *(OOC_UINT16*)(i0+(_check_index(i3, i2, OOC_UINT32, 101585))*2);
          i0 = i0!=65535u;
          if (!i0) goto l43;
          XML_Parser__ParserDesc_ParseDocument_Err(28);
l43:
          XML_Parser__ParserDesc_ParseDocument_PopEntity();
l45:
          i0 = (OOC_INT32)dtd;
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 101869))+16);
          decl = (XML_DTD__Declaration)i0;
          i2 = i0!=(OOC_INT32)0;
          if (!i2) goto l56;
l48_loop:
          i2 = _type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 101943)))), &_td_XML_DTD__AttrDeclDesc, 101943);
          attr = (XML_DTD__AttrDecl)i2;
          i3 = *(OOC_INT8*)((_check_pointer(i2, 101972))+20);
          i3 = i3>=2;
          if (!i3) goto l51;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 102031))+24);
          XML_Parser__ParserDesc_ParseDocument_Expand((XML_DTD__AttValue)i2);
l51:
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 102084));
          decl = (XML_DTD__Declaration)i0;
          i2 = i0!=(OOC_INT32)0;
          if (i2) goto l48_loop;
l56:
          i0 = (OOC_INT32)dtd;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 102124)))), XML_DTD__BuilderDesc_AttachAttributes)),XML_DTD__BuilderDesc_AttachAttributes)((XML_DTD__Builder)i0);
          XML_Parser__ParserDesc_ParseDocument_prolog_doctypedecl_CheckGeneralEntities();
          i0 = (OOC_INT32)p;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 102198))+4);
          i2 = _check_pointer(i2, 102201);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 102198))+4);
          XML_Parser__ParserDesc_ParseDocument_StorePosition((void*)(_check_pointer(i0, 102201)), (RT0__Struct)i1);
          i0 = (OOC_INT32)p;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 102214))+44);
          i2 = *(OOC_UINT8*)((_check_pointer(i0, 102250))+64);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 102214))+44);
          i3 = (OOC_INT32)externalSubset;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 102223)))), XML_Builder__BuilderDesc_EndDTD)),XML_Builder__BuilderDesc_EndDTD)((XML_Builder__Builder)i0, (XML_DTD__ExternalEntity)i3, i2);
          i0 = (OOC_INT32)p;
          *(OOC_UINT8*)((_check_pointer(i0, 102294))+66) = 0u;
          return;
          ;
        }


      i0 = XML_Parser__ParserDesc_ParseDocument_LookingAt("<?xml", 6, 1);
      if (!i0) goto l3;
      i0 = (OOC_INT32)p;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 102420))+52);
      XML_Parser__ParserDesc_ParseDocument_XMLDecl((XML_DTD__ExternalEntity)i0);
l3:
      XML_Parser__ParserDesc_ParseDocument_MiscRep();
      i0 = XML_Parser__ParserDesc_ParseDocument_LookingAt("<!DOCTYPE", 10, 1);
      if (!i0) goto l6;
      XML_Parser__ParserDesc_ParseDocument_prolog_doctypedecl();
      XML_Parser__ParserDesc_ParseDocument_MiscRep();
l6:
      return;
      ;
    }


  i0 = (OOC_INT32)p;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 102615))+52);
  XML_Parser__ParserDesc_ParseDocument_SetFileEntity((XML_DTD__ExternalEntity)i0);
  XML_Parser__ParserDesc_ParseDocument_ResetLocator();
  i0 = (OOC_INT32)p;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 102666))+36);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 102670))+20);
  chars = (XML_UnicodeBuffer__CharArray)i1;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 102691))+48);
  dtd = (XML_DTD__Builder)i1;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 102723))+4);
  i1 = _check_pointer(i1, 102726);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 102723))+4);
  i1 = (OOC_INT32)&_td_XML_Locator__Position;
  XML_Parser__ParserDesc_ParseDocument_StorePosition((void*)(_check_pointer(i0, 102726)), (RT0__Struct)i1);
  i0 = (OOC_INT32)p;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 102735))+44);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 102759))+4);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 102735))+44);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 102744)))), XML_Builder__BuilderDesc_SetLocator)),XML_Builder__BuilderDesc_SetLocator)((XML_Builder__Builder)i4, (XML_Locator__Locator)i3);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 102770))+44);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 102800))+8);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 102770))+44);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 102779)))), XML_Builder__BuilderDesc_SetErrorListener)),XML_Builder__BuilderDesc_SetErrorListener)((XML_Builder__Builder)i4, (XML_Locator__ErrorListener)i3);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 102823))+44);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 102850))+52);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 102823))+44);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 102832)))), XML_Builder__BuilderDesc_StartDocument)),XML_Builder__BuilderDesc_StartDocument)((XML_Builder__Builder)i0, (XML_DTD__ExternalEntity)i3);
  XML_Parser__ParserDesc_ParseDocument_prolog();
  i0 = (OOC_INT32)p;
  *(OOC_UINT8*)((_check_pointer(i0, 102906))+65) = 1u;
  XML_Parser__ParserDesc_ParseDocument_element();
  i0 = (OOC_INT32)p;
  i0 = *(OOC_INT32*)((_check_pointer(i0, 102957))+88);
  i0 = i0!=0;
  if (!i0) goto l3;
  XML_Parser__ParserDesc_ParseDocument_Err(301);
l3:
  i0 = (OOC_INT32)p;
  *(OOC_UINT8*)((_check_pointer(i0, 103022))+65) = 0u;
  XML_Parser__ParserDesc_ParseDocument_MiscRep();
  i0 = (OOC_INT32)chars;
  i0 = _check_pointer(i0, 103078);
  i2 = OOC_ARRAY_LENGTH(i0, 0);
  i3 = cpos;
  i0 = *(OOC_UINT16*)(i0+(_check_index(i3, i2, OOC_UINT32, 103078))*2);
  i0 = i0!=65535u;
  if (!i0) goto l6;
  XML_Parser__ParserDesc_ParseDocument_Err(2);
l6:
  XML_Parser__ParserDesc_ParseDocument_CheckInvalidChars();
  i0 = (OOC_INT32)p;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 103197))+4);
  i2 = _check_pointer(i2, 103200);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 103197))+4);
  XML_Parser__ParserDesc_ParseDocument_StorePosition((void*)(_check_pointer(i0, 103200)), (RT0__Struct)i1);
  i0 = (OOC_INT32)p;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 103209))+40);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 103209))+40);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 103225)))), XML_Builder__BuilderDesc_EndDocument)),XML_Builder__BuilderDesc_EndDocument)((XML_Builder__Builder)i0);
  return;
  ;
}

static void XML_Parser__Init(XML_Parser__Parser p, OOC_CHAR8 _new, IO__ByteChannel reader, URI__URI baseURI, XML_UnicodeCodec__Factory codecFactory, XML_EntityResolver__Resolver entityResolver, XML_Builder__Builder builder) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)p;
  i1 = (OOC_INT32)XML_Error__NewList();
  *(OOC_INT32*)(_check_pointer(i0, 103572)) = i1;
  i1 = _new;
  if (i1) goto l3;
  _assert(0u, 127, 103824);
  goto l4;
l3:
  *(OOC_INT32*)((_check_pointer(i0, 103630))+4) = ((OOC_INT32)RT0__NewObject(_td_XML_Locator__Locator.baseTypes[0]));
  *(OOC_INT32*)((_check_pointer(i0, 103648))+8) = ((OOC_INT32)RT0__NewObject(_td_XML_Parser__ErrorListener.baseTypes[0]));
  *(OOC_INT32*)((_check_pointer(i0, 103678))+76) = ((OOC_INT32)RT0__NewObject(_td_XML_Parser__NameList.baseTypes[0], 8));
  *(OOC_INT32*)((_check_pointer(i0, 103717))+84) = ((OOC_INT32)RT0__NewObject(_td_XML_Parser__PEInfoList.baseTypes[0], 4));
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 103797));
  i2 = (OOC_INT32)reader;
  i3 = (OOC_INT32)codecFactory;
  i1 = (OOC_INT32)XML_UnicodeBuffer__NewInput((IO__ByteChannel)i2, (XML_UnicodeCodec__Factory)i3, (Msg__MsgList)i1);
  *(OOC_INT32*)((_check_pointer(i0, 103749))+36) = i1;
l4:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 103917))+4);
  *(OOC_INT32*)((_check_pointer(i1, 103920))+16) = 0;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 103952))+8);
  *(OOC_INT32*)(_check_pointer(i1, 103967)) = i0;
  i1 = (OOC_INT32)XML_DTD__New();
  *(OOC_INT32*)((_check_pointer(i0, 103987))+48) = i1;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 104033))+48);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 104033))+48);
  i3 = (OOC_INT32)baseURI;
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 104038)))), XML_DTD__BuilderDesc_NewDocumentEntity)),XML_DTD__BuilderDesc_NewDocumentEntity)((XML_DTD__Builder)i2, (URI__URI)i3);
  *(OOC_INT32*)((_check_pointer(i0, 104012))+52) = i1;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 104110))+36);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 104114))+8);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 104074))+52);
  XML_DTD__ExternalEntityDesc_SetCodecFactory((XML_DTD__ExternalEntity)i2, (XML_UnicodeCodec__Factory)i1);
  i1 = (OOC_INT32)builder;
  *(OOC_INT32*)((_check_pointer(i0, 104136))+44) = i1;
  *(OOC_INT32*)((_check_pointer(i0, 104163))+40) = i1;
  i1 = (OOC_INT32)entityResolver;
  i1 = i1==0;
  if (!i1) goto l7;
  i1 = (OOC_INT32)XML_EntityResolver__New();
  entityResolver = (XML_EntityResolver__Resolver)i1;
l7:
  i1 = (OOC_INT32)entityResolver;
  *(OOC_INT32*)((_check_pointer(i0, 104286))+32) = i1;
  *(OOC_UINT8*)((_check_pointer(i0, 104325))+60) = 1u;
  *(OOC_UINT8*)((_check_pointer(i0, 104359))+61) = 0u;
  *(OOC_UINT8*)((_check_pointer(i0, 104390))+62) = 0u;
  *(OOC_UINT8*)((_check_pointer(i0, 104418))+63) = 1u;
  *(OOC_UINT8*)((_check_pointer(i0, 104454))+64) = 1u;
  *(OOC_UINT8*)((_check_pointer(i0, 104491))+65) = 0u;
  *(OOC_UINT8*)((_check_pointer(i0, 104526))+66) = 0u;
  *(OOC_UINT8*)((_check_pointer(i0, 104549))+67) = 0u;
  *(OOC_UINT8*)((_check_pointer(i0, 104583))+68) = 0u;
  *(OOC_INT32*)((_check_pointer(i0, 104622))+72) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 104653))+80) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 104678))+88) = 0;
  return;
  ;
}

XML_Parser__Parser XML_Parser__NewChannel(IO__ByteChannel ch, URI__URI baseURI, XML_UnicodeCodec__Factory codecFactory, XML_EntityResolver__Resolver entityResolver, XML_Builder__Builder builder) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;

  i0 = (OOC_INT32)RT0__NewObject(_td_XML_Parser__Parser.baseTypes[0]);
  i1 = (OOC_INT32)builder;
  i2 = (OOC_INT32)entityResolver;
  i3 = (OOC_INT32)codecFactory;
  i4 = (OOC_INT32)baseURI;
  i5 = (OOC_INT32)ch;
  XML_Parser__Init((XML_Parser__Parser)i0, 1u, (IO__ByteChannel)i5, (URI__URI)i4, (XML_UnicodeCodec__Factory)i3, (XML_EntityResolver__Resolver)i2, (XML_Builder__Builder)i1);
  return (XML_Parser__Parser)i0;
  ;
}

XML_Parser__Parser XML_Parser__NewURI(URI__URI uri, URI__URI baseURI, XML_UnicodeCodec__Factory codecFactory, XML_EntityResolver__Resolver entityResolver, XML_Builder__Builder builder) {
  register OOC_INT32 i0,i1,i2,i3,i4;

  i0 = (OOC_INT32)uri;
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 107258)))), URI__URIDesc_GetChannel)),URI__URIDesc_GetChannel)((URI__URI)i0, 2);
  i2 = (OOC_INT32)codecFactory;
  i3 = (OOC_INT32)entityResolver;
  i4 = (OOC_INT32)builder;
  i0 = (OOC_INT32)XML_Parser__NewChannel((IO__ByteChannel)i1, (URI__URI)i0, (XML_UnicodeCodec__Factory)i2, (XML_EntityResolver__Resolver)i3, (XML_Builder__Builder)i4);
  return (XML_Parser__Parser)i0;
  ;
}

XML_Parser__Parser XML_Parser__NewFile(const OOC_CHAR8 filePath__ref[], OOC_LEN filePath_0d, URI__URI baseURI, XML_UnicodeCodec__Factory codecFactory, XML_EntityResolver__Resolver entityResolver, XML_Builder__Builder builder) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_ALLOCATE_VPAR(filePath,OOC_CHAR8 ,filePath_0d)

  OOC_INITIALIZE_VPAR(filePath__ref,filePath,OOC_CHAR8 ,filePath_0d)
  i0 = (OOC_INT32)URI_Scheme_File__ToURI((void*)(OOC_INT32)filePath, filePath_0d);
  i1 = (OOC_INT32)baseURI;
  i2 = (OOC_INT32)codecFactory;
  i3 = (OOC_INT32)entityResolver;
  i4 = (OOC_INT32)builder;
  i0 = (OOC_INT32)XML_Parser__NewURI((URI__URI)i0, (URI__URI)i1, (XML_UnicodeCodec__Factory)i2, (XML_EntityResolver__Resolver)i3, (XML_Builder__Builder)i4);
  return (XML_Parser__Parser)i0;
  ;
}

XML_Parser__Parser XML_Parser__NewExternalID(const OOC_CHAR16 _public__ref[], OOC_LEN _public_0d, const OOC_CHAR16 system__ref[], OOC_LEN system_0d, URI__URI systemBaseURI, XML_UnicodeCodec__Factory codecFactory, XML_EntityResolver__Resolver entityResolver, XML_Builder__Builder builder, Msg__Msg *res) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_ALLOCATE_VPAR(_public,OOC_CHAR16 ,_public_0d)
  OOC_ALLOCATE_VPAR(system,OOC_CHAR16 ,system_0d)
  URI__URI uri;
  auto XML_UnicodeBuffer__CharArray XML_Parser__NewExternalID_ToString(OOC_CHAR16 s[], OOC_LEN s_0d);
    
    XML_UnicodeBuffer__CharArray XML_Parser__NewExternalID_ToString(OOC_CHAR16 s[], OOC_LEN s_0d) {
      register OOC_INT32 i0,i1;
      XML_UnicodeBuffer__CharArray str;

      i0 = (
      _cmp16((const void*)(OOC_INT32)s,(const void*)((OOC_CHAR16[]){0})))==0;
      if (i0) goto l3;
      i0 = LongStrings__Length((void*)(OOC_INT32)s, s_0d);
      i0 = (OOC_INT32)RT0__NewObject(_td_XML_UnicodeBuffer__CharArray.baseTypes[0], (i0+1));
      str = (XML_UnicodeBuffer__CharArray)i0;
      i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 108560)), 0);
      _copy_16((const void*)(OOC_INT32)s,(void*)(_check_pointer(i0, 108560)),i1);
      return (XML_UnicodeBuffer__CharArray)i0;
      goto l4;
l3:
      return (XML_UnicodeBuffer__CharArray)(OOC_INT32)0;
l4:
      _failed_function(108352); return 0;
      ;
    }


  OOC_INITIALIZE_VPAR(_public__ref,_public,OOC_CHAR16 ,(_public_0d*2))
  OOC_INITIALIZE_VPAR(system__ref,system,OOC_CHAR16 ,(system_0d*2))
  i0 = (OOC_INT32)XML_Parser__NewExternalID_ToString((void*)(OOC_INT32)system, system_0d);
  i1 = (OOC_INT32)XML_Parser__NewExternalID_ToString((void*)(OOC_INT32)_public, _public_0d);
  i2 = (OOC_INT32)entityResolver;
  i3 = (OOC_INT32)systemBaseURI;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 108640)))), XML_EntityResolver__ResolverDesc_GetURI)),XML_EntityResolver__ResolverDesc_GetURI)((XML_EntityResolver__Resolver)i2, (XML_UnicodeBuffer__CharArray)i1, (XML_UnicodeBuffer__CharArray)i0, (URI__URI)i3, (void*)(OOC_INT32)&uri, (void*)(OOC_INT32)res);
  i0 = (OOC_INT32)uri;
  i1 = i0==(OOC_INT32)0;
  if (i1) goto l3;
  i1 = (OOC_INT32)codecFactory;
  i3 = (OOC_INT32)builder;
  i0 = (OOC_INT32)XML_Parser__NewURI((URI__URI)i0, (URI__URI)(OOC_INT32)0, (XML_UnicodeCodec__Factory)i1, (XML_EntityResolver__Resolver)i2, (XML_Builder__Builder)i3);
  return (XML_Parser__Parser)i0;
  goto l4;
l3:
  return (XML_Parser__Parser)(OOC_INT32)0;
l4:
  _failed_function(107826); return 0;
  ;
}

static void XML_Parser__SetErrorMessages(void) {
  register OOC_INT32 i0,i1;
  OOC_INT16 i;
  OOC_CHAR8 t[128];

  i = 0;
  i0=0;
l1_loop:
  switch (i0) {
  case 1:
    _copy_8((const void*)"Invalid character in document",(void*)(OOC_INT32)t,128);
    goto l63;
  case 2:
    _copy_8((const void*)"Junk after document element",(void*)(OOC_INT32)t,128);
    goto l63;
  case 3:
    _copy_8((const void*)"String `]]>\047 not allowed in character data",(void*)(OOC_INT32)t,128);
    goto l63;
  case 4:
    _copy_8((const void*)"String `--\047 not allowed in comment",(void*)(OOC_INT32)t,128);
    goto l63;
  case 5:
    _copy_8((const void*)"Comment not closed",(void*)(OOC_INT32)t,128);
    goto l63;
  case 6:
    _copy_8((const void*)"String not closed",(void*)(OOC_INT32)t,128);
    goto l63;
  case 7:
    _copy_8((const void*)"Processing instruction not closed",(void*)(OOC_INT32)t,128);
    goto l63;
  case 8:
    _copy_8((const void*)"CDATA section not closed",(void*)(OOC_INT32)t,128);
    goto l63;
  case 9:
    _copy_8((const void*)"Expected whitespace",(void*)(OOC_INT32)t,128);
    goto l63;
  case 10:
    _copy_8((const void*)"Expected name token",(void*)(OOC_INT32)t,128);
    goto l63;
  case 11:
    _copy_8((const void*)"Expected Nmtoken",(void*)(OOC_INT32)t,128);
    goto l63;
  case 12:
    _copy_8((const void*)"Expected character `${symbol}\047",(void*)(OOC_INT32)t,128);
    goto l63;
  case 13:
    _copy_8((const void*)"Character `<\047 not allowed in attribute value",(void*)(OOC_INT32)t,128);
    goto l63;
  case 14:
    _copy_8((const void*)"Expected digit [0-9]",(void*)(OOC_INT32)t,128);
    goto l63;
  case 15:
    _copy_8((const void*)"Expected digit [0-9a-fA-F]",(void*)(OOC_INT32)t,128);
    goto l63;
  case 16:
    _copy_8((const void*)"Expected string",(void*)(OOC_INT32)t,128);
    goto l63;
  case 17:
    _copy_8((const void*)"Character reference designates illegal character",(void*)(OOC_INT32)t,128);
    goto l63;
  case 18:
    _copy_8((const void*)"Exepcted `]]>\047",(void*)(OOC_INT32)t,128);
    goto l63;
  case 19:
    _copy_8((const void*)"Ignored section not closed",(void*)(OOC_INT32)t,128);
    goto l63;
  case 20:
    _copy_8((const void*)"Invalid character in public ID string",(void*)(OOC_INT32)t,128);
    goto l63;
  case 21:
    _copy_8((const void*)"Invalid character in encoding name",(void*)(OOC_INT32)t,128);
    goto l63;
  case 22:
    _copy_8((const void*)"Invalid character in version number",(void*)(OOC_INT32)t,128);
    goto l63;
  case 23:
    _copy_8((const void*)"Expected non-empty string",(void*)(OOC_INT32)t,128);
    goto l63;
  case 24:
    _copy_8((const void*)"Expected \047yes\047 or \047no\047",(void*)(OOC_INT32)t,128);
    goto l63;
  case 25:
    _copy_8((const void*)"XML declaration must be at beginning of file",(void*)(OOC_INT32)t,128);
    goto l63;
  case 26:
    _copy_8((const void*)"This target name is reserved",(void*)(OOC_INT32)t,128);
    goto l63;
  case 27:
    _copy_8((const void*)"Document `${uri}\047 had ${encodings} character encoding errors",(void*)(OOC_INT32)t,128);
    goto l63;
  case 28:
    _copy_8((const void*)"Junk after external DTD subset",(void*)(OOC_INT32)t,128);
    goto l63;
  case 29:
    _copy_8((const void*)"Unknown character encoding",(void*)(OOC_INT32)t,128);
    goto l63;
  case 30:
    _copy_8((const void*)"This name must not contain a colon character `:\047",(void*)(OOC_INT32)t,128);
    goto l63;
  case 31:
    _copy_8((const void*)"Invalid use of colon in a qualified name",(void*)(OOC_INT32)t,128);
    goto l63;
  case 105:
    _copy_8((const void*)"Expected markup declaration",(void*)(OOC_INT32)t,128);
    goto l63;
  case 106:
    _copy_8((const void*)"Expected content specification: `EMPTY\047, `ANY\047, or `(\047",(void*)(OOC_INT32)t,128);
    goto l63;
  case 107:
    _copy_8((const void*)"Expected attribute type (type name, `NOTATION\047, or enumeration)",(void*)(OOC_INT32)t,128);
    goto l63;
  case 108:
    _copy_8((const void*)"Expected attribute value",(void*)(OOC_INT32)t,128);
    goto l63;
  case 109:
    _copy_8((const void*)"Expected entity value",(void*)(OOC_INT32)t,128);
    goto l63;
  case 110:
    _copy_8((const void*)"Expected content particle (name or `(\047)",(void*)(OOC_INT32)t,128);
    goto l63;
  case 111:
    _copy_8((const void*)"Expected token `version\047",(void*)(OOC_INT32)t,128);
    goto l63;
  case 112:
    _copy_8((const void*)"Expected `PUBLIC\047 or `SYSTEM\047",(void*)(OOC_INT32)t,128);
    goto l63;
  case 113:
    _copy_8((const void*)"Expected `INCLUDE\047 or `IGNORE\047",(void*)(OOC_INT32)t,128);
    goto l63;
  case 114:
    _copy_8((const void*)"Expected `?>\047",(void*)(OOC_INT32)t,128);
    goto l63;
  case 115:
    _copy_8((const void*)"Parameter entity references are restricted to markup declarations in the internal subset of the DTD",(void*)(OOC_INT32)t,128);
    goto l63;
  case 116:
    _copy_8((const void*)"Expected token `encoding\047",(void*)(OOC_INT32)t,128);
    goto l63;
  case 117:
    _copy_8((const void*)"Malformed URI: ${uri_error}",(void*)(OOC_INT32)t,128);
    goto l63;
  case 118:
    _copy_8((const void*)"Invalid redefinition of a predefined internal entity",(void*)(OOC_INT32)t,128);
    goto l63;
  case 208:
    _copy_8((const void*)"Expected element",(void*)(OOC_INT32)t,128);
    goto l63;
  case 209:
    _copy_8((const void*)"Expected end tag </${name}>",(void*)(OOC_INT32)t,128);
    goto l63;
  case 210:
    _copy_8((const void*)"General entity `${name}\047 not defined",(void*)(OOC_INT32)t,128);
    goto l63;
  case 211:
    _copy_8((const void*)"Parameter entity `${name}\047 not defined",(void*)(OOC_INT32)t,128);
    goto l63;
  case 212:
    _copy_8((const void*)"Attribute `${name}\047 is already defined",(void*)(OOC_INT32)t,128);
    goto l63;
  case 213:
    _copy_8((const void*)"General entity `${name}\047 is defined recursively",(void*)(OOC_INT32)t,128);
    goto l63;
  case 214:
    _copy_8((const void*)"Required attribute `${name}\047 is not set",(void*)(OOC_INT32)t,128);
    goto l63;
  case 300:
    _copy_8((const void*)"End tag `${name}\047 comes from a different entity than its start tag",(void*)(OOC_INT32)t,128);
    goto l63;
  case 301:
    _copy_8((const void*)"Unbalanced general entity reference",(void*)(OOC_INT32)t,128);
    goto l63;
  case 302:
    _copy_8((const void*)"Replacement text of general entity `${name}\047 is not valid content",(void*)(OOC_INT32)t,128);
    goto l63;
  case 303:
    _copy_8((const void*)"Could not access URL `${uri}\047: ${channel_error}",(void*)(OOC_INT32)t,128);
    goto l63;
  case 304:
    _copy_8((const void*)"Reference to unparsed entity `${name}\047 not allowed",(void*)(OOC_INT32)t,128);
    goto l63;
  case 305:
    _copy_8((const void*)"Attribute value contains reference to external entity `${name}\047",(void*)(OOC_INT32)t,128);
    goto l63;
  case 306:
    _copy_8((const void*)"Nesting violation: Opening and closing parenthesis not in same entity",(void*)(OOC_INT32)t,128);
    goto l63;
  default:
    _copy_8((const void*)"",(void*)(OOC_INT32)t,128);
    goto l63;
  }
l63:
  i1 = (
  _cmp8((const void*)(OOC_INT32)t,(const void*)""))!=0;
  if (!i1) goto l66;
  i1 = (OOC_INT32)XML_Parser__parserContext;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 113731)))), XML_Error__ContextDesc_SetString)),XML_Error__ContextDesc_SetString)((XML_Error__Context)i1, i0, (void*)(OOC_INT32)t, 128);
l66:
  i0 = i0+1;
  i = i0;
  i1 = i0<=999;
  if (i1) goto l1_loop;
l70:
  return;
  ;
}

void OOC_XML_Parser_init(void) {
  register OOC_INT32 i0,i1;

  _copy_16((const void*)((OOC_CHAR16[]){45,39,40,41,43,44,46,47,58,61,63,59,33,42,35,64,36,95,37,0}),(void*)(OOC_INT32)XML_Parser__suplPubidChar,32);
  i0 = (OOC_INT32)RT0__NewObject(_td_XML_UnicodeBuffer__CharArray.baseTypes[0], 8);
  XML_Parser__noName = (XML_UnicodeBuffer__CharArray)i0;
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 113886)), 0);
  _copy_16((const void*)((OOC_CHAR16[]){35,110,111,95,110,97,109,101,0}),(void*)(_check_pointer(i0, 113886)),i1);
  i0 = (OOC_INT32)XML_Error__NewContext("XML:Parser", 11);
  XML_Parser__parserContext = (XML_Error__Context)i0;
  XML_Parser__SetErrorMessages();
  return;
  ;
}

/* --- */
