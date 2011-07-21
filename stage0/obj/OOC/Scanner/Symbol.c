#include <OOC/Scanner/Symbol.d>
#include <__oo2c.h>
#include <setjmp.h>

OOC_CHAR8 OOC_Scanner_Symbol__IsKeyword(OOC_INT8 id) {
  register OOC_INT32 i0,i1;

  i0 = id;
  i1 = i0==3;
  if (i1) goto l3;
  i1 = i0==4;
  
  goto l5;
l3:
  i1=1u;
l5:
  if (i1) goto l7;
  i1 = i0==15;
  
  goto l9;
l7:
  i1=1u;
l9:
  if (i1) goto l11;
  i1 = i0==16;
  
  goto l13;
l11:
  i1=1u;
l13:
  if (i1) goto l15;
  i1 = i0==42;
  
  goto l17;
l15:
  i1=1u;
l17:
  if (i1) goto l19;
  i1 = i0==8;
  
  goto l21;
l19:
  i1=1u;
l21:
  if (i1) goto l27;
  i1 = 25<=i0;
  if (i1) goto l25;
  i1=0u;
  goto l29;
l25:
  i1 = i0<=31;
  
  goto l29;
l27:
  i1=1u;
l29:
  if (i1) goto l35;
  i1 = 48<=i0;
  if (i1) goto l33;
  i0=0u;
  goto l36;
l33:
  i0 = i0<=71;
  
  goto l36;
l35:
  i0=1u;
l36:
  return i0;
  ;
}

OOC_CHAR8 OOC_Scanner_Symbol__IsWhitespace(OOC_INT8 id) {
  register OOC_INT32 i0,i1;

  i0 = id;
  i1 = i0>=77;
  if (i1) goto l3;
  i0=0u;
  goto l4;
l3:
  i0 = i0<81;
  
l4:
  return i0;
  ;
}

void OOC_OOC_Scanner_Symbol_init(void) {
  register OOC_INT32 i0,i1;

  OOC_Scanner_Symbol__i = 0;
  i0=0;
l1_loop:
  _copy_8((const void*)"",(void*)((OOC_INT32)OOC_Scanner_Symbol__name+((_check_index(i0, 81, OOC_UINT16, 3407))*13)),13);
  _copy_8((const void*)"",(void*)((OOC_INT32)OOC_Scanner_Symbol__representation+((_check_index(i0, 81, OOC_UINT16, 3432))*10)),10);
  i0 = i0+1;
  OOC_Scanner_Symbol__i = i0;
  i1 = i0<=80;
  if (i1) goto l1_loop;
l5:
  _copy_8((const void*)"times",(void*)((OOC_INT32)OOC_Scanner_Symbol__name+((_check_index(1, 81, OOC_UINT8, 3455))*13)),13);
  _copy_8((const void*)"*",(void*)((OOC_INT32)OOC_Scanner_Symbol__representation+((_check_index(1, 81, OOC_UINT8, 3489))*10)),10);
  _copy_8((const void*)"slash",(void*)((OOC_INT32)OOC_Scanner_Symbol__name+((_check_index(2, 81, OOC_UINT8, 3511))*13)),13);
  _copy_8((const void*)"/",(void*)((OOC_INT32)OOC_Scanner_Symbol__representation+((_check_index(2, 81, OOC_UINT8, 3545))*10)),10);
  _copy_8((const void*)"div",(void*)((OOC_INT32)OOC_Scanner_Symbol__name+((_check_index(3, 81, OOC_UINT8, 3567))*13)),13);
  _copy_8((const void*)"DIV",(void*)((OOC_INT32)OOC_Scanner_Symbol__representation+((_check_index(3, 81, OOC_UINT8, 3597))*10)),10);
  _copy_8((const void*)"mod",(void*)((OOC_INT32)OOC_Scanner_Symbol__name+((_check_index(4, 81, OOC_UINT8, 3619))*13)),13);
  _copy_8((const void*)"MOD",(void*)((OOC_INT32)OOC_Scanner_Symbol__representation+((_check_index(4, 81, OOC_UINT8, 3649))*10)),10);
  _copy_8((const void*)"and",(void*)((OOC_INT32)OOC_Scanner_Symbol__name+((_check_index(5, 81, OOC_UINT8, 3671))*13)),13);
  _copy_8((const void*)"&",(void*)((OOC_INT32)OOC_Scanner_Symbol__representation+((_check_index(5, 81, OOC_UINT8, 3701))*10)),10);
  _copy_8((const void*)"plus",(void*)((OOC_INT32)OOC_Scanner_Symbol__name+((_check_index(6, 81, OOC_UINT8, 3721))*13)),13);
  _copy_8((const void*)"+",(void*)((OOC_INT32)OOC_Scanner_Symbol__representation+((_check_index(6, 81, OOC_UINT8, 3753))*10)),10);
  _copy_8((const void*)"minus",(void*)((OOC_INT32)OOC_Scanner_Symbol__name+((_check_index(7, 81, OOC_UINT8, 3774))*13)),13);
  _copy_8((const void*)"-",(void*)((OOC_INT32)OOC_Scanner_Symbol__representation+((_check_index(7, 81, OOC_UINT8, 3808))*10)),10);
  _copy_8((const void*)"or",(void*)((OOC_INT32)OOC_Scanner_Symbol__name+((_check_index(8, 81, OOC_UINT8, 3830))*13)),13);
  _copy_8((const void*)"OR",(void*)((OOC_INT32)OOC_Scanner_Symbol__representation+((_check_index(8, 81, OOC_UINT8, 3858))*10)),10);
  _copy_8((const void*)"eql",(void*)((OOC_INT32)OOC_Scanner_Symbol__name+((_check_index(9, 81, OOC_UINT8, 3878))*13)),13);
  _copy_8((const void*)"=",(void*)((OOC_INT32)OOC_Scanner_Symbol__representation+((_check_index(9, 81, OOC_UINT8, 3908))*10)),10);
  _copy_8((const void*)"neq",(void*)((OOC_INT32)OOC_Scanner_Symbol__name+((_check_index(10, 81, OOC_UINT8, 3928))*13)),13);
  _copy_8((const void*)"#",(void*)((OOC_INT32)OOC_Scanner_Symbol__representation+((_check_index(10, 81, OOC_UINT8, 3958))*10)),10);
  _copy_8((const void*)"lss",(void*)((OOC_INT32)OOC_Scanner_Symbol__name+((_check_index(11, 81, OOC_UINT8, 3978))*13)),13);
  _copy_8((const void*)"<",(void*)((OOC_INT32)OOC_Scanner_Symbol__representation+((_check_index(11, 81, OOC_UINT8, 4008))*10)),10);
  _copy_8((const void*)"leq",(void*)((OOC_INT32)OOC_Scanner_Symbol__name+((_check_index(12, 81, OOC_UINT8, 4028))*13)),13);
  _copy_8((const void*)"<=",(void*)((OOC_INT32)OOC_Scanner_Symbol__representation+((_check_index(12, 81, OOC_UINT8, 4058))*10)),10);
  _copy_8((const void*)"gtr",(void*)((OOC_INT32)OOC_Scanner_Symbol__name+((_check_index(13, 81, OOC_UINT8, 4079))*13)),13);
  _copy_8((const void*)">",(void*)((OOC_INT32)OOC_Scanner_Symbol__representation+((_check_index(13, 81, OOC_UINT8, 4109))*10)),10);
  _copy_8((const void*)"geq",(void*)((OOC_INT32)OOC_Scanner_Symbol__name+((_check_index(14, 81, OOC_UINT8, 4129))*13)),13);
  _copy_8((const void*)">=",(void*)((OOC_INT32)OOC_Scanner_Symbol__representation+((_check_index(14, 81, OOC_UINT8, 4159))*10)),10);
  _copy_8((const void*)"in",(void*)((OOC_INT32)OOC_Scanner_Symbol__name+((_check_index(15, 81, OOC_UINT8, 4180))*13)),13);
  _copy_8((const void*)"IN",(void*)((OOC_INT32)OOC_Scanner_Symbol__representation+((_check_index(15, 81, OOC_UINT8, 4208))*10)),10);
  _copy_8((const void*)"is",(void*)((OOC_INT32)OOC_Scanner_Symbol__name+((_check_index(16, 81, OOC_UINT8, 4228))*13)),13);
  _copy_8((const void*)"IS",(void*)((OOC_INT32)OOC_Scanner_Symbol__representation+((_check_index(16, 81, OOC_UINT8, 4256))*10)),10);
  _copy_8((const void*)"arrow",(void*)((OOC_INT32)OOC_Scanner_Symbol__name+((_check_index(17, 81, OOC_UINT8, 4276))*13)),13);
  _copy_8((const void*)"^",(void*)((OOC_INT32)OOC_Scanner_Symbol__representation+((_check_index(17, 81, OOC_UINT8, 4310))*10)),10);
  _copy_8((const void*)"period",(void*)((OOC_INT32)OOC_Scanner_Symbol__name+((_check_index(18, 81, OOC_UINT8, 4332))*13)),13);
  _copy_8((const void*)".",(void*)((OOC_INT32)OOC_Scanner_Symbol__representation+((_check_index(18, 81, OOC_UINT8, 4368))*10)),10);
  _copy_8((const void*)"comma",(void*)((OOC_INT32)OOC_Scanner_Symbol__name+((_check_index(19, 81, OOC_UINT8, 4391))*13)),13);
  _copy_8((const void*)",",(void*)((OOC_INT32)OOC_Scanner_Symbol__representation+((_check_index(19, 81, OOC_UINT8, 4425))*10)),10);
  _copy_8((const void*)"colon",(void*)((OOC_INT32)OOC_Scanner_Symbol__name+((_check_index(20, 81, OOC_UINT8, 4447))*13)),13);
  _copy_8((const void*)":",(void*)((OOC_INT32)OOC_Scanner_Symbol__representation+((_check_index(20, 81, OOC_UINT8, 4481))*10)),10);
  _copy_8((const void*)"upto",(void*)((OOC_INT32)OOC_Scanner_Symbol__name+((_check_index(21, 81, OOC_UINT8, 4503))*13)),13);
  _copy_8((const void*)"..",(void*)((OOC_INT32)OOC_Scanner_Symbol__representation+((_check_index(21, 81, OOC_UINT8, 4535))*10)),10);
  _copy_8((const void*)"rParen",(void*)((OOC_INT32)OOC_Scanner_Symbol__name+((_check_index(22, 81, OOC_UINT8, 4557))*13)),13);
  _copy_8((const void*)")",(void*)((OOC_INT32)OOC_Scanner_Symbol__representation+((_check_index(22, 81, OOC_UINT8, 4593))*10)),10);
  _copy_8((const void*)"rBrak",(void*)((OOC_INT32)OOC_Scanner_Symbol__name+((_check_index(23, 81, OOC_UINT8, 4616))*13)),13);
  _copy_8((const void*)"]",(void*)((OOC_INT32)OOC_Scanner_Symbol__representation+((_check_index(23, 81, OOC_UINT8, 4650))*10)),10);
  _copy_8((const void*)"rBrace",(void*)((OOC_INT32)OOC_Scanner_Symbol__name+((_check_index(24, 81, OOC_UINT8, 4672))*13)),13);
  _copy_8((const void*)"}",(void*)((OOC_INT32)OOC_Scanner_Symbol__representation+((_check_index(24, 81, OOC_UINT8, 4708))*10)),10);
  _copy_8((const void*)"of",(void*)((OOC_INT32)OOC_Scanner_Symbol__name+((_check_index(25, 81, OOC_UINT8, 4731))*13)),13);
  _copy_8((const void*)"OF",(void*)((OOC_INT32)OOC_Scanner_Symbol__representation+((_check_index(25, 81, OOC_UINT8, 4759))*10)),10);
  _copy_8((const void*)"catch",(void*)((OOC_INT32)OOC_Scanner_Symbol__name+((_check_index(26, 81, OOC_UINT8, 4779))*13)),13);
  _copy_8((const void*)"CATCH",(void*)((OOC_INT32)OOC_Scanner_Symbol__representation+((_check_index(26, 81, OOC_UINT8, 4813))*10)),10);
  _copy_8((const void*)"raises",(void*)((OOC_INT32)OOC_Scanner_Symbol__name+((_check_index(27, 81, OOC_UINT8, 4839))*13)),13);
  _copy_8((const void*)"RAISES",(void*)((OOC_INT32)OOC_Scanner_Symbol__representation+((_check_index(27, 81, OOC_UINT8, 4875))*10)),10);
  _copy_8((const void*)"then",(void*)((OOC_INT32)OOC_Scanner_Symbol__name+((_check_index(28, 81, OOC_UINT8, 4903))*13)),13);
  _copy_8((const void*)"THEN",(void*)((OOC_INT32)OOC_Scanner_Symbol__representation+((_check_index(28, 81, OOC_UINT8, 4935))*10)),10);
  _copy_8((const void*)"do",(void*)((OOC_INT32)OOC_Scanner_Symbol__name+((_check_index(29, 81, OOC_UINT8, 4959))*13)),13);
  _copy_8((const void*)"DO",(void*)((OOC_INT32)OOC_Scanner_Symbol__representation+((_check_index(29, 81, OOC_UINT8, 4987))*10)),10);
  _copy_8((const void*)"to",(void*)((OOC_INT32)OOC_Scanner_Symbol__name+((_check_index(30, 81, OOC_UINT8, 5007))*13)),13);
  _copy_8((const void*)"TO",(void*)((OOC_INT32)OOC_Scanner_Symbol__representation+((_check_index(30, 81, OOC_UINT8, 5035))*10)),10);
  _copy_8((const void*)"by",(void*)((OOC_INT32)OOC_Scanner_Symbol__name+((_check_index(31, 81, OOC_UINT8, 5055))*13)),13);
  _copy_8((const void*)"BY",(void*)((OOC_INT32)OOC_Scanner_Symbol__representation+((_check_index(31, 81, OOC_UINT8, 5083))*10)),10);
  _copy_8((const void*)"lParen",(void*)((OOC_INT32)OOC_Scanner_Symbol__name+((_check_index(32, 81, OOC_UINT8, 5103))*13)),13);
  _copy_8((const void*)"(",(void*)((OOC_INT32)OOC_Scanner_Symbol__representation+((_check_index(32, 81, OOC_UINT8, 5139))*10)),10);
  _copy_8((const void*)"lBrak",(void*)((OOC_INT32)OOC_Scanner_Symbol__name+((_check_index(33, 81, OOC_UINT8, 5162))*13)),13);
  _copy_8((const void*)"[",(void*)((OOC_INT32)OOC_Scanner_Symbol__representation+((_check_index(33, 81, OOC_UINT8, 5196))*10)),10);
  _copy_8((const void*)"lBrace",(void*)((OOC_INT32)OOC_Scanner_Symbol__name+((_check_index(34, 81, OOC_UINT8, 5218))*13)),13);
  _copy_8((const void*)"{",(void*)((OOC_INT32)OOC_Scanner_Symbol__representation+((_check_index(34, 81, OOC_UINT8, 5254))*10)),10);
  _copy_8((const void*)"not",(void*)((OOC_INT32)OOC_Scanner_Symbol__name+((_check_index(35, 81, OOC_UINT8, 5277))*13)),13);
  _copy_8((const void*)"~",(void*)((OOC_INT32)OOC_Scanner_Symbol__representation+((_check_index(35, 81, OOC_UINT8, 5307))*10)),10);
  _copy_8((const void*)"becomes",(void*)((OOC_INT32)OOC_Scanner_Symbol__name+((_check_index(36, 81, OOC_UINT8, 5327))*13)),13);
  _copy_8((const void*)":=",(void*)((OOC_INT32)OOC_Scanner_Symbol__representation+((_check_index(36, 81, OOC_UINT8, 5365))*10)),10);
  _copy_8((const void*)"number10",(void*)((OOC_INT32)OOC_Scanner_Symbol__name+((_check_index(37, 81, OOC_UINT8, 5390))*13)),13);
  _copy_8((const void*)"number16",(void*)((OOC_INT32)OOC_Scanner_Symbol__name+((_check_index(38, 81, OOC_UINT8, 5422))*13)),13);
  _copy_8((const void*)"number16X",(void*)((OOC_INT32)OOC_Scanner_Symbol__name+((_check_index(39, 81, OOC_UINT8, 5454))*13)),13);
  _copy_8((const void*)"numberExpE",(void*)((OOC_INT32)OOC_Scanner_Symbol__name+((_check_index(40, 81, OOC_UINT8, 5488))*13)),13);
  _copy_8((const void*)"numberExpD",(void*)((OOC_INT32)OOC_Scanner_Symbol__name+((_check_index(41, 81, OOC_UINT8, 5524))*13)),13);
  _copy_8((const void*)"nil",(void*)((OOC_INT32)OOC_Scanner_Symbol__name+((_check_index(42, 81, OOC_UINT8, 5560))*13)),13);
  _copy_8((const void*)"NIL",(void*)((OOC_INT32)OOC_Scanner_Symbol__representation+((_check_index(42, 81, OOC_UINT8, 5590))*10)),10);
  _copy_8((const void*)"stringSingle",(void*)((OOC_INT32)OOC_Scanner_Symbol__name+((_check_index(43, 81, OOC_UINT8, 5612))*13)),13);
  _copy_8((const void*)"stringDouble",(void*)((OOC_INT32)OOC_Scanner_Symbol__name+((_check_index(44, 81, OOC_UINT8, 5652))*13)),13);
  _copy_8((const void*)"ident",(void*)((OOC_INT32)OOC_Scanner_Symbol__name+((_check_index(45, 81, OOC_UINT8, 5692))*13)),13);
  _copy_8((const void*)"semicolon",(void*)((OOC_INT32)OOC_Scanner_Symbol__name+((_check_index(46, 81, OOC_UINT8, 5718))*13)),13);
  _copy_8((const void*)";",(void*)((OOC_INT32)OOC_Scanner_Symbol__representation+((_check_index(46, 81, OOC_UINT8, 5760))*10)),10);
  _copy_8((const void*)"bar",(void*)((OOC_INT32)OOC_Scanner_Symbol__name+((_check_index(47, 81, OOC_UINT8, 5786))*13)),13);
  _copy_8((const void*)"|",(void*)((OOC_INT32)OOC_Scanner_Symbol__representation+((_check_index(47, 81, OOC_UINT8, 5816))*10)),10);
  _copy_8((const void*)"end",(void*)((OOC_INT32)OOC_Scanner_Symbol__name+((_check_index(48, 81, OOC_UINT8, 5836))*13)),13);
  _copy_8((const void*)"END",(void*)((OOC_INT32)OOC_Scanner_Symbol__representation+((_check_index(48, 81, OOC_UINT8, 5866))*10)),10);
  _copy_8((const void*)"else",(void*)((OOC_INT32)OOC_Scanner_Symbol__name+((_check_index(49, 81, OOC_UINT8, 5888))*13)),13);
  _copy_8((const void*)"ELSE",(void*)((OOC_INT32)OOC_Scanner_Symbol__representation+((_check_index(49, 81, OOC_UINT8, 5920))*10)),10);
  _copy_8((const void*)"elsif",(void*)((OOC_INT32)OOC_Scanner_Symbol__name+((_check_index(50, 81, OOC_UINT8, 5944))*13)),13);
  _copy_8((const void*)"ELSIF",(void*)((OOC_INT32)OOC_Scanner_Symbol__representation+((_check_index(50, 81, OOC_UINT8, 5978))*10)),10);
  _copy_8((const void*)"until",(void*)((OOC_INT32)OOC_Scanner_Symbol__name+((_check_index(51, 81, OOC_UINT8, 6004))*13)),13);
  _copy_8((const void*)"UNTIL",(void*)((OOC_INT32)OOC_Scanner_Symbol__representation+((_check_index(51, 81, OOC_UINT8, 6038))*10)),10);
  _copy_8((const void*)"if",(void*)((OOC_INT32)OOC_Scanner_Symbol__name+((_check_index(52, 81, OOC_UINT8, 6064))*13)),13);
  _copy_8((const void*)"IF",(void*)((OOC_INT32)OOC_Scanner_Symbol__representation+((_check_index(52, 81, OOC_UINT8, 6092))*10)),10);
  _copy_8((const void*)"case",(void*)((OOC_INT32)OOC_Scanner_Symbol__name+((_check_index(53, 81, OOC_UINT8, 6112))*13)),13);
  _copy_8((const void*)"CASE",(void*)((OOC_INT32)OOC_Scanner_Symbol__representation+((_check_index(53, 81, OOC_UINT8, 6144))*10)),10);
  _copy_8((const void*)"while",(void*)((OOC_INT32)OOC_Scanner_Symbol__name+((_check_index(54, 81, OOC_UINT8, 6168))*13)),13);
  _copy_8((const void*)"WHILE",(void*)((OOC_INT32)OOC_Scanner_Symbol__representation+((_check_index(54, 81, OOC_UINT8, 6202))*10)),10);
  _copy_8((const void*)"repeat",(void*)((OOC_INT32)OOC_Scanner_Symbol__name+((_check_index(55, 81, OOC_UINT8, 6228))*13)),13);
  _copy_8((const void*)"REPEAT",(void*)((OOC_INT32)OOC_Scanner_Symbol__representation+((_check_index(55, 81, OOC_UINT8, 6264))*10)),10);
  _copy_8((const void*)"loop",(void*)((OOC_INT32)OOC_Scanner_Symbol__name+((_check_index(56, 81, OOC_UINT8, 6292))*13)),13);
  _copy_8((const void*)"LOOP",(void*)((OOC_INT32)OOC_Scanner_Symbol__representation+((_check_index(56, 81, OOC_UINT8, 6324))*10)),10);
  _copy_8((const void*)"for",(void*)((OOC_INT32)OOC_Scanner_Symbol__name+((_check_index(57, 81, OOC_UINT8, 6348))*13)),13);
  _copy_8((const void*)"FOR",(void*)((OOC_INT32)OOC_Scanner_Symbol__representation+((_check_index(57, 81, OOC_UINT8, 6378))*10)),10);
  _copy_8((const void*)"with",(void*)((OOC_INT32)OOC_Scanner_Symbol__name+((_check_index(58, 81, OOC_UINT8, 6400))*13)),13);
  _copy_8((const void*)"WITH",(void*)((OOC_INT32)OOC_Scanner_Symbol__representation+((_check_index(58, 81, OOC_UINT8, 6432))*10)),10);
  _copy_8((const void*)"try",(void*)((OOC_INT32)OOC_Scanner_Symbol__name+((_check_index(59, 81, OOC_UINT8, 6456))*13)),13);
  _copy_8((const void*)"TRY",(void*)((OOC_INT32)OOC_Scanner_Symbol__representation+((_check_index(59, 81, OOC_UINT8, 6486))*10)),10);
  _copy_8((const void*)"exit",(void*)((OOC_INT32)OOC_Scanner_Symbol__name+((_check_index(60, 81, OOC_UINT8, 6508))*13)),13);
  _copy_8((const void*)"EXIT",(void*)((OOC_INT32)OOC_Scanner_Symbol__representation+((_check_index(60, 81, OOC_UINT8, 6540))*10)),10);
  _copy_8((const void*)"return",(void*)((OOC_INT32)OOC_Scanner_Symbol__name+((_check_index(61, 81, OOC_UINT8, 6564))*13)),13);
  _copy_8((const void*)"RETURN",(void*)((OOC_INT32)OOC_Scanner_Symbol__representation+((_check_index(61, 81, OOC_UINT8, 6600))*10)),10);
  _copy_8((const void*)"array",(void*)((OOC_INT32)OOC_Scanner_Symbol__name+((_check_index(62, 81, OOC_UINT8, 6628))*13)),13);
  _copy_8((const void*)"ARRAY",(void*)((OOC_INT32)OOC_Scanner_Symbol__representation+((_check_index(62, 81, OOC_UINT8, 6662))*10)),10);
  _copy_8((const void*)"record",(void*)((OOC_INT32)OOC_Scanner_Symbol__name+((_check_index(63, 81, OOC_UINT8, 6688))*13)),13);
  _copy_8((const void*)"RECORD",(void*)((OOC_INT32)OOC_Scanner_Symbol__representation+((_check_index(63, 81, OOC_UINT8, 6724))*10)),10);
  _copy_8((const void*)"pointer",(void*)((OOC_INT32)OOC_Scanner_Symbol__name+((_check_index(64, 81, OOC_UINT8, 6752))*13)),13);
  _copy_8((const void*)"POINTER",(void*)((OOC_INT32)OOC_Scanner_Symbol__representation+((_check_index(64, 81, OOC_UINT8, 6790))*10)),10);
  _copy_8((const void*)"begin",(void*)((OOC_INT32)OOC_Scanner_Symbol__name+((_check_index(65, 81, OOC_UINT8, 6820))*13)),13);
  _copy_8((const void*)"BEGIN",(void*)((OOC_INT32)OOC_Scanner_Symbol__representation+((_check_index(65, 81, OOC_UINT8, 6854))*10)),10);
  _copy_8((const void*)"const",(void*)((OOC_INT32)OOC_Scanner_Symbol__name+((_check_index(66, 81, OOC_UINT8, 6880))*13)),13);
  _copy_8((const void*)"CONST",(void*)((OOC_INT32)OOC_Scanner_Symbol__representation+((_check_index(66, 81, OOC_UINT8, 6914))*10)),10);
  _copy_8((const void*)"type",(void*)((OOC_INT32)OOC_Scanner_Symbol__name+((_check_index(67, 81, OOC_UINT8, 6940))*13)),13);
  _copy_8((const void*)"TYPE",(void*)((OOC_INT32)OOC_Scanner_Symbol__representation+((_check_index(67, 81, OOC_UINT8, 6972))*10)),10);
  _copy_8((const void*)"var",(void*)((OOC_INT32)OOC_Scanner_Symbol__name+((_check_index(68, 81, OOC_UINT8, 6996))*13)),13);
  _copy_8((const void*)"VAR",(void*)((OOC_INT32)OOC_Scanner_Symbol__representation+((_check_index(68, 81, OOC_UINT8, 7026))*10)),10);
  _copy_8((const void*)"procedure",(void*)((OOC_INT32)OOC_Scanner_Symbol__name+((_check_index(69, 81, OOC_UINT8, 7048))*13)),13);
  _copy_8((const void*)"PROCEDURE",(void*)((OOC_INT32)OOC_Scanner_Symbol__representation+((_check_index(69, 81, OOC_UINT8, 7090))*10)),10);
  _copy_8((const void*)"import",(void*)((OOC_INT32)OOC_Scanner_Symbol__name+((_check_index(70, 81, OOC_UINT8, 7124))*13)),13);
  _copy_8((const void*)"IMPORT",(void*)((OOC_INT32)OOC_Scanner_Symbol__representation+((_check_index(70, 81, OOC_UINT8, 7160))*10)),10);
  _copy_8((const void*)"module",(void*)((OOC_INT32)OOC_Scanner_Symbol__name+((_check_index(71, 81, OOC_UINT8, 7188))*13)),13);
  _copy_8((const void*)"MODULE",(void*)((OOC_INT32)OOC_Scanner_Symbol__representation+((_check_index(71, 81, OOC_UINT8, 7224))*10)),10);
  _copy_8((const void*)"endOfFile",(void*)((OOC_INT32)OOC_Scanner_Symbol__name+((_check_index(72, 81, OOC_UINT8, 7252))*13)),13);
  _copy_8((const void*)"invalid",(void*)((OOC_INT32)OOC_Scanner_Symbol__name+((_check_index(73, 81, OOC_UINT8, 7286))*13)),13);
  _copy_8((const void*)"threeDots",(void*)((OOC_INT32)OOC_Scanner_Symbol__name+((_check_index(76, 81, OOC_UINT8, 7316))*13)),13);
  _copy_8((const void*)"...",(void*)((OOC_INT32)OOC_Scanner_Symbol__representation+((_check_index(76, 81, OOC_UINT8, 7358))*10)),10);
  _copy_8((const void*)"pragmaStart",(void*)((OOC_INT32)OOC_Scanner_Symbol__name+((_check_index(74, 81, OOC_UINT8, 7386))*13)),13);
  _copy_8((const void*)"<*",(void*)((OOC_INT32)OOC_Scanner_Symbol__representation+((_check_index(74, 81, OOC_UINT8, 7432))*10)),10);
  _copy_8((const void*)"pragmaEnd",(void*)((OOC_INT32)OOC_Scanner_Symbol__name+((_check_index(75, 81, OOC_UINT8, 7461))*13)),13);
  _copy_8((const void*)"*>",(void*)((OOC_INT32)OOC_Scanner_Symbol__representation+((_check_index(75, 81, OOC_UINT8, 7503))*10)),10);
  _copy_8((const void*)"comment",(void*)((OOC_INT32)OOC_Scanner_Symbol__name+((_check_index(77, 81, OOC_UINT8, 7530))*13)),13);
  _copy_8((const void*)"docComment",(void*)((OOC_INT32)OOC_Scanner_Symbol__name+((_check_index(78, 81, OOC_UINT8, 7560))*13)),13);
  _copy_8((const void*)"pragma",(void*)((OOC_INT32)OOC_Scanner_Symbol__name+((_check_index(79, 81, OOC_UINT8, 7596))*13)),13);
  _copy_8((const void*)"whitespace",(void*)((OOC_INT32)OOC_Scanner_Symbol__name+((_check_index(80, 81, OOC_UINT8, 7624))*13)),13);
  return;
  ;
}

/* --- */
