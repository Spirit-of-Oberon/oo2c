#include <stdio.h>

#include "Out.d"

void Out__Open() {
}

void Out__Char(OOC_CHAR8 ch) {
  putc(ch, stdout);
}

void Out__String(OOC_CHAR8 s[], OOC_LEN s_0d) {
  fputs(s, stdout);
}

void Out__Int(OOC_INT32 i, OOC_INT32 n) {
  fprintf(stdout, "%*i", n, i);
}

void Out__Ln() {
  fputc('\n', stdout);
}

void Out_init() {
}
