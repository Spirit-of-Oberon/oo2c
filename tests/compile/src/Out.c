#include <stdio.h>

#include "Out.d"

void Out__Open() {
}

void Out__Char(OOC_CHAR8 ch) {
  putc(ch, stdout);
}

void Out__String(OOC_CHAR8 s[], OOC_LEN s_0d) {
  fputs((const char*)s, stdout);
}

void Out__Int(OOC_INT32 i, OOC_INT32 n) {
  fprintf(stdout, "%*i", n, i);
}

void Out__Bool(OOC_BOOLEAN b) {
  fprintf(stdout, b ? "TRUE" : "FALSE");
}

void Out__Set(OOC_UINT32 set) {
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

void Out__Ln() {
  fputc('\n', stdout);
}

void Out_init() {
}
