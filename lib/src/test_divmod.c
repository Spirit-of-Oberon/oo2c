#include <stdio.h>
#include "__oo2c.h"

void p(int y) {
  int x;
  
  for (x=7; x>=-7; x--) {
    printf("%2i/%2i = %2i", x, y, x / y);
    printf("\t%2i%%%2i = %2i | %2i", x, y, x % y,
	   (x/y)*y + x%y - x);
    printf("\t\t%2i DIV %2i = %2i", x, y, _div(x,y));
    printf("\t%2i MOD %2i = %2i | %2i\n", x, y, _mod(x,y),
	   _div(x,y)*y + _mod(x,y) - x);
  }
}

int main() {
  p(3);
  printf("---------------------------------------------------------------------------\n");
  p(-3);
  return 0;
}
