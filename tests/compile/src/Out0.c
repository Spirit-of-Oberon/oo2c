#include <stdio.h>

#include "Out0.d"

void Out0__Open() {
}

void Out0__Char(OOC_CHAR8 ch) {
  putc(ch, stdout);
}

void Out0__String(const OOC_CHAR8 s[], OOC_LEN s_0d) {
  fputs((const char*)s, stdout);
}

void Out0__LString(const OOC_CHAR16 s[], OOC_LEN s_0d) {
  const OOC_CHAR16* c = s;
  while (*c) {
    putc((*c < 256) ? (OOC_CHAR8)*c : '?', stdout);
    c++;
  }
}

void Out0__Int(OOC_INT32 i, OOC_INT32 n) {
  fprintf(stdout, "%*i", n, i);
}

void Out0__Real(OOC_REAL32 r, OOC_INT32 n) {
  fprintf(stdout, "%.*E", n, r);
}

void Out0__LongReal(OOC_REAL64 r, OOC_INT32 n) {
  fprintf(stdout, "%.*E", n, r);
}

void Out0__Bool(OOC_BOOLEAN b) {
  fprintf(stdout, b ? "TRUE" : "FALSE");
}

void Out0__Set(OOC_UINT32 set) {
#define MAXSET 31
  int bit, comma, begin;

  comma = 0; bit = 0;

  putc('{', stdout);

  while (bit <= MAXSET) { 
    if ((1<<bit) & set) {
      begin = bit;
      while ((bit<MAXSET) && (set & (1<<(bit+1)))) ++bit;
      if (comma) putc(',', stdout); else comma = 1;
      fprintf(stdout, "%d", begin);
      if (begin+1==bit) 
	fprintf(stdout,",%d", bit);
      else if (begin<bit)
	fprintf(stdout,"..%d", bit);
    }
    ++bit;
  }

  putc('}', stdout);
}

void Out0__Ln() {
  fputc('\n', stdout);
}

void Out0_init() {
}