#include "__oo2c.h"
#include <stdio.h>

/* --- functions to handle exceptions and failed run-time checks: */
#define PREFIX "## "

void _assertion_failed(OOC_INT32 code, OOC_CHARPOS pos) {
  (void)fprintf(stderr, PREFIX "Assertion failed, code: " INT32_FORMAT "\n",
		code);
  exit(code);
}

