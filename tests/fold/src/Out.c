#include <stdio.h>

#include "Out.d"

void Out__Open() {
}

void Out__Char(unsigned char ch) {
  putc(ch, stdout);
}

void Out__String(unsigned char s[]) {
  fputs(s, stdout);
}

void Out__Int(int i, int n) {
  fprintf(stdout, "%*i", n, i);
}

void Out__Ln() {
  fputc('\n', stdout);
}

void Out_init() {
}
