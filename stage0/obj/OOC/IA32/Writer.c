#include <OOC/IA32/Writer.d>
#include <__oo2c.h>
#include <setjmp.h>

static void OOC_IA32_Writer__InitWriter(OOC_IA32_Writer__Writer w, IO__ByteChannel ch) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)ch;
  *(OOC_INT32*)(_check_pointer(i0, 1534)) = i1;
  i1 = (OOC_INT32)IO_TextRider__ConnectWriter((IO__ByteChannel)i1);
  *(OOC_INT32*)((_check_pointer(i0, 1551))+4) = i1;
  i1 = (OOC_INT32)ADT_Dictionary__New();
  *(OOC_INT32*)((_check_pointer(i0, 1602))+8) = i1;
  *(OOC_INT32*)((_check_pointer(i0, 1641))+12) = 1;
  return;
  ;
}

OOC_IA32_Writer__Writer OOC_IA32_Writer__NewWriter(IO__ByteChannel ch) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_IA32_Writer__Writer.baseTypes[0]);
  i1 = (OOC_INT32)ch;
  OOC_IA32_Writer__InitWriter((OOC_IA32_Writer__Writer)i0, (IO__ByteChannel)i1);
  return (OOC_IA32_Writer__Writer)i0;
  ;
}

void OOC_IA32_Writer__WriterDesc_Newline(OOC_IA32_Writer__Writer w) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 1877))+4);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 1877))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 1889)))), IO_TextRider__WriterDesc_WriteLn)),IO_TextRider__WriterDesc_WriteLn)((IO_TextRider__Writer)i0);
  return;
  ;
}

void OOC_IA32_Writer__WriterDesc_Write(OOC_IA32_Writer__Writer w, const OOC_CHAR8 str__ref[], OOC_LEN str_0d) {
  register OOC_INT32 i0,i1;
  OOC_ALLOCATE_VPAR(str,OOC_CHAR8 ,str_0d)

  OOC_INITIALIZE_VPAR(str__ref,str,OOC_CHAR8 ,str_0d)
  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 1980))+4);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 1980))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 1992)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, (void*)(OOC_INT32)str, str_0d);
  return;
  ;
}

void OOC_IA32_Writer__WriterDesc_WriteObject(OOC_IA32_Writer__Writer w, Object__String str) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2090))+4);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2090))+4);
  i2 = (OOC_INT32)str;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 2102)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i0, (Object__Object)i2);
  return;
  ;
}

void OOC_IA32_Writer__WriterDesc_Label(OOC_IA32_Writer__Writer w, Object__String label) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2202))+4);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2202))+4);
  i3 = (OOC_INT32)label;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 2214)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i2, (Object__Object)i3);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2242))+4);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2242))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 2254)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i2, 58u);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2278))+4);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2278))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 2290)))), IO_TextRider__WriterDesc_WriteLn)),IO_TextRider__WriterDesc_WriteLn)((IO_TextRider__Writer)i0);
  return;
  ;
}

void OOC_IA32_Writer__WriterDesc_Section(OOC_IA32_Writer__Writer w, const OOC_CHAR8 section__ref[], OOC_LEN section_0d) {
  register OOC_INT32 i0,i1,i2;
  OOC_ALLOCATE_VPAR(section,OOC_CHAR8 ,section_0d)

  OOC_INITIALIZE_VPAR(section__ref,section,OOC_CHAR8 ,section_0d)
  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2385))+4);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2385))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 2397)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i2, (void*)(OOC_INT32)section, section_0d);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2427))+4);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2427))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 2439)))), IO_TextRider__WriterDesc_WriteLn)),IO_TextRider__WriterDesc_WriteLn)((IO_TextRider__Writer)i0);
  return;
  ;
}

void OOC_IA32_Writer__WriterDesc_Directive(OOC_IA32_Writer__Writer w, const OOC_CHAR8 dir__ref[], OOC_LEN dir_0d) {
  register OOC_INT32 i0,i1,i2;
  OOC_ALLOCATE_VPAR(dir,OOC_CHAR8 ,dir_0d)

  OOC_INITIALIZE_VPAR(dir__ref,dir,OOC_CHAR8 ,dir_0d)
  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2534))+4);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2534))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 2546)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i2, 9u);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2575))+4);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2575))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 2587)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i2, (void*)(OOC_INT32)dir, dir_0d);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2613))+4);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2613))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 2625)))), IO_TextRider__WriterDesc_WriteLn)),IO_TextRider__WriterDesc_WriteLn)((IO_TextRider__Writer)i0);
  return;
  ;
}

void OOC_IA32_Writer__WriterDesc_Instr(OOC_IA32_Writer__Writer w, const OOC_CHAR8 instr__ref[], OOC_LEN instr_0d) {
  register OOC_INT32 i0,i1,i2;
  OOC_ALLOCATE_VPAR(instr,OOC_CHAR8 ,instr_0d)

  OOC_INITIALIZE_VPAR(instr__ref,instr,OOC_CHAR8 ,instr_0d)
  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2720))+4);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2720))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 2732)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i2, 9u);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2761))+4);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2761))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 2773)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i2, (void*)(OOC_INT32)instr, instr_0d);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2801))+4);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2801))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 2813)))), IO_TextRider__WriterDesc_WriteLn)),IO_TextRider__WriterDesc_WriteLn)((IO_TextRider__Writer)i0);
  return;
  ;
}

void OOC_IA32_Writer__WriterDesc_StringLiteral(OOC_IA32_Writer__Writer w, const OOC_CHAR8 str__ref[], OOC_LEN str_0d) {
  register OOC_INT32 i0,i1,i2;
  OOC_ALLOCATE_VPAR(str,OOC_CHAR8 ,str_0d)

  OOC_INITIALIZE_VPAR(str__ref,str,OOC_CHAR8 ,str_0d)
  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2910))+4);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2910))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 2922)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i2, 9u);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2951))+4);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2951))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 2963)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i2, ".string \"", 10);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2997))+4);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2997))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3009)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i2, (void*)(OOC_INT32)str, str_0d);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3035))+4);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3035))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3047)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i2, "\"", 2);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3073))+4);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3073))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3085)))), IO_TextRider__WriterDesc_WriteLn)),IO_TextRider__WriterDesc_WriteLn)((IO_TextRider__Writer)i0);
  return;
  ;
}

Object__String OOC_IA32_Writer__WriterDesc_GetStringLabel(OOC_IA32_Writer__Writer w, Object_Boxed__String value) {
  register OOC_INT32 i0,i1,i2;
  Object__Object obj;
  OOC_CHAR8 label[32];
  Object__String s;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3277))+8);
  i2 = (OOC_INT32)value;
  i1 = ADT_Dictionary__DictionaryDesc_HasKey((ADT_Dictionary__Dictionary)i1, (Object__Object)i2);
  if (i1) goto l3;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 3411))+12);
  IntStr__IntToStr(i1, (void*)(OOC_INT32)label, 32);
  i1 = *(OOC_INT32*)((_check_pointer(i0, 3450))+12);
  *(OOC_INT32*)((_check_pointer(i0, 3450))+12) = (i1+1);
  Strings__Insert(".LC", 4, 0, (void*)(OOC_INT32)label, 32);
  i1 = (OOC_INT32)Object__NewLatin1((void*)(OOC_INT32)label, 32);
  s = (Object__String)i1;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3553))+8);
  ADT_Dictionary__DictionaryDesc_Set((ADT_Dictionary__Dictionary)i0, (Object__Object)i2, (Object__Object)i1);
  return (Object__String)i1;
  goto l4;
l3:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3325))+8);
  i0 = (OOC_INT32)ADT_Dictionary__DictionaryDesc_Get((ADT_Dictionary__Dictionary)i0, (Object__Object)i2);
  obj = (Object__Object)i0;
  return (Object__String)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3369)))), &_td_Object__StringDesc, 3369));
l4:
  _failed_function(3140); return 0;
  ;
}

void OOC_IA32_Writer__WriterDesc_PushInt(OOC_IA32_Writer__Writer w, OOC_INT32 i) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3689))+4);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3689))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3701)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i2, "\011pushl $", 9);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3742))+4);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3742))+4);
  i3 = i;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3754)))), IO_TextRider__WriterDesc_WriteLInt)),IO_TextRider__WriterDesc_WriteLInt)((IO_TextRider__Writer)i2, i3, 0);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3779))+4);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3779))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3791)))), IO_TextRider__WriterDesc_WriteLn)),IO_TextRider__WriterDesc_WriteLn)((IO_TextRider__Writer)i0);
  return;
  ;
}

void OOC_IA32_Writer__WriterDesc_PushLabel(OOC_IA32_Writer__Writer w, const OOC_CHAR8 label__ref[], OOC_LEN label_0d) {
  register OOC_INT32 i0,i1,i2;
  OOC_ALLOCATE_VPAR(label,OOC_CHAR8 ,label_0d)

  OOC_INITIALIZE_VPAR(label__ref,label,OOC_CHAR8 ,label_0d)
  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3888))+4);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3888))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3900)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i2, "\011pushl $", 9);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3941))+4);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3941))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3953)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i2, (void*)(OOC_INT32)label, label_0d);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3981))+4);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3981))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3993)))), IO_TextRider__WriterDesc_WriteLn)),IO_TextRider__WriterDesc_WriteLn)((IO_TextRider__Writer)i0);
  return;
  ;
}

void OOC_IA32_Writer__WriterDesc_PopBytes(OOC_IA32_Writer__Writer w, OOC_INT32 bytes) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4085))+4);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4085))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 4097)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i2, "\011addl $", 8);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4137))+4);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4137))+4);
  i3 = bytes;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 4149)))), IO_TextRider__WriterDesc_WriteLInt)),IO_TextRider__WriterDesc_WriteLInt)((IO_TextRider__Writer)i2, i3, 0);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4178))+4);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4178))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 4190)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i2, ",%esp", 6);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4220))+4);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4220))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 4232)))), IO_TextRider__WriterDesc_WriteLn)),IO_TextRider__WriterDesc_WriteLn)((IO_TextRider__Writer)i0);
  return;
  ;
}

void OOC_IA32_Writer__WriterDesc_WriteStringData(OOC_IA32_Writer__Writer w) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
  Object__ObjectArrayPtr strings;
  OOC_INT32 i;
  Object__Object label;
  Object__CharsLatin1 chars;

  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4431)))), OOC_IA32_Writer__WriterDesc_Section)),OOC_IA32_Writer__WriterDesc_Section)((OOC_IA32_Writer__Writer)i0, ".data", 6);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4457)))), OOC_IA32_Writer__WriterDesc_Section)),OOC_IA32_Writer__WriterDesc_Section)((OOC_IA32_Writer__Writer)i0, ".section .rodata", 17);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4505))+8);
  i1 = (OOC_INT32)ADT_Dictionary__DictionaryDesc_Keys((ADT_Dictionary__Dictionary)i1);
  strings = (Object__ObjectArrayPtr)i1;
  i = 0;
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i1, 4557)), 0);
  i3 = 0<i2;
  if (!i3) goto l8;
  i3=0;
l3_loop:
  i4 = _check_pointer(i1, 4607);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4581))+8);
  i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 4607))*4);
  i4 = (OOC_INT32)ADT_Dictionary__DictionaryDesc_Get((ADT_Dictionary__Dictionary)i6, (Object__Object)i4);
  label = (Object__Object)i4;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4620)))), OOC_IA32_Writer__WriterDesc_Label)),OOC_IA32_Writer__WriterDesc_Label)((OOC_IA32_Writer__Writer)i0, (Object__String)(_type_guard(i4, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 4635)))), &_td_Object__StringDesc, 4635)));
  i4 = _check_pointer(i1, 4667);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 4667))*4);
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i4, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 4677)))), &_td_Object_Boxed__StringDesc, 4677)), 4684));
  i4 = (OOC_INT32)Object__String8Desc_CharsLatin1((Object__String8)(_type_guard(i4, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 4698)))), &_td_Object__String8Desc, 4698)));
  chars = (Object__CharsLatin1)i4;
  i5 = OOC_ARRAY_LENGTH((_check_pointer(i4, 4751)), 0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4729)))), OOC_IA32_Writer__WriterDesc_StringLiteral)),OOC_IA32_Writer__WriterDesc_StringLiteral)((OOC_IA32_Writer__Writer)i0, (void*)(_check_pointer(i4, 4751)), i5);
  i3 = i3+1;
  i = i3;
  i4 = i3<i2;
  if (i4) goto l3_loop;
l8:
  return;
  ;
}

void OOC_IA32_Writer__WriterDesc_Close(OOC_IA32_Writer__Writer w) {
  register OOC_INT32 i0,i1;
  IO__ByteChannel ch;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4927))+4);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 4938))+4);
  i1 = i1!=(OOC_INT32)0;
  if (!i1) goto l4;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4970))+4);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 4981))+4);
  Exception__Raise((void*)i1);
l4:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5011))+4);
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 5022));
  ch = (IO__ByteChannel)i0;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5038)))), IO__ChannelDesc_CloseAndRegister)),IO__ChannelDesc_CloseAndRegister)((IO__Channel)i0);
  return;
  ;
}

void OOC_OOC_IA32_Writer_init(void) {

  return;
  ;
}

/* --- */
