#include <Exception.d>
#include <__oo2c.h>

#include <setjmp.h>
#include <stdio.h>
#include <stdlib.h>
#if HAVE_BACKTRACE_SYMBOLS
#  include <execinfo.h>
#endif

#define EXCEPTION_EXIT_CODE 126

static Exception__Exception current = NULL;
static Exception__ContextPtr contextStack = NULL;

void Exception__Init(Exception__Exception e, Object__String msg) {
  e->msg = msg;
  e->backtraceSize = -1;
}

Exception__Exception Exception__Current() {
  return current;
}

#define SIZE_BUFFER 1024
void Exception__ActivateContext() {
  if (contextStack) {
    longjmp(*(jmp_buf*)contextStack->jmpbuf, 1);
  } else {
    RT0__Struct td = OOC_TYPE_TAG(current);
    Object__String msg =
      OOC_TBCALL(OOC_TBPROC_ADR(td,Exception__ExceptionDesc_GetMessage),
		 Exception__ExceptionDesc_GetMessage)(current);
    /* if the type name ends with "Desc", then drop the last 4 characters */
    int len = strlen(td->name);
    if ((len >= 4) && (strcmp(td->name + (len-4), "Desc") == 0)) {
      len -= 4;
    }
    fprintf(stderr, "## Exception: %s.%.*s", td->module->name, len, td->name);
    
    if (msg) {
      char buffer[SIZE_BUFFER];
      int i, j = 4;
      _TBP_Object__StringDesc_CharAt charAt =
	OOC_TBPROC_ADR(OOC_TYPE_TAG(msg), Object__StringDesc_CharAt);
      
      strcpy(buffer, "\n## ");
      for (i=0; i != msg->length; i++) {
	OOC_INT32 c = OOC_TBCALL(charAt,Object__StringDesc_CharAt)(msg,i);
	buffer[j] = (c>0xff) ? '?' : (char)c;
	j++;
	if (j == SIZE_BUFFER) {
	  fwrite(buffer, sizeof(char), SIZE_BUFFER, stderr);
	  j = 0;
	}
      }
      fwrite(buffer, sizeof(char), j, stderr);
    }
    
    (void)fprintf(stderr, "\n\n");
    Exception__ExceptionDesc_WriteBacktrace(current);
    exit(EXCEPTION_EXIT_CODE);
  }
}

void Exception__Raise(Exception__Exception e) {
  if (e->backtraceSize < 0) {
#if HAVE_BACKTRACE_SYMBOLS
    e->backtraceSize = backtrace(e->backtrace, Exception__maxBacktraceSize);
#else
    e->backtraceSize = 0;
#endif
  }
  
  current = e;
  Exception__ActivateContext();
}

void Exception__Clear() {
  current = NULL;
}

void Exception__PushContext(struct Exception__Context *context,
			    OOC_PTR jmpbuf) {
  context->next = contextStack;
  context->jmpbuf = jmpbuf;
  contextStack = context;
}

void Exception__PopContext(OOC_INT32 n) {
  contextStack = contextStack->next;
}

void Exception__ExceptionDesc_WriteBacktrace(Exception__Exception e) {
#if HAVE_BACKTRACE_SYMBOLS
  int i;
  char** names;
  
  if (e->backtraceSize >= 0) {
    names = backtrace_symbols(e->backtrace, e->backtraceSize);
    for (i=0; i<e->backtraceSize; i++) {
      (void)fprintf(stderr, "%d: %s\n", i, names[i]);
    }
    free(names);
  }
#endif
}

Object__String Exception__ExceptionDesc_GetMessage(Exception__Exception e) {
  return e->msg;
}

void OOC_Exception_init(void) {
}
