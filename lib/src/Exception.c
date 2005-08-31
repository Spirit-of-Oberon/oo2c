#include <Exception.d>
#include <__oo2c.h>

#include <setjmp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#if HAVE_BACKTRACE_SYMBOLS
#  include <execinfo.h>
#endif

#define EXCEPTION_EXIT_CODE 126

static Exception__ThreadState local_state;

void Exception__ExceptionDesc_INIT(Exception__Exception e,
				   Object__String msg) {
  e->msg = msg;
  e->backtraceSize = -1;
}

Exception__Exception Exception__Current() {
  return Exception__GetThreadState()->currentException;
}

#define SIZE_BUFFER 1024
void Exception__Abort(Exception__Exception e) {
  RT0__Struct td = OOC_TYPE_TAG(e);
  Object__String msg =
    OOC_TBCALL(OOC_TBPROC_ADR(td,Exception__ExceptionDesc_GetMessage),
	       Exception__ExceptionDesc_GetMessage)(e);
  /* if the type name ends with "Desc", then drop the last 4 characters */
  int len = strlen((char*)td->name);
  if ((len >= 4) && (strcmp((char*)td->name + (len-4), "Desc") == 0)) {
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
  Exception__ExceptionDesc_WriteBacktrace(e);
  exit(EXCEPTION_EXIT_CODE);
}

void Exception__ActivateContext() {
  Exception__ContextPtr cs = Exception__GetThreadState()->contextStack;
  
  if (cs) {
    longjmp(*(jmp_buf*)cs->jmpbuf, 1);
  } else {
    Exception__Abort(Exception__Current());
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
  
  Exception__GetThreadState()->currentException = e;
  Exception__ActivateContext();
}

void Exception__FatalError(Object__String msg) {
  Exception__Exception e =
    RT0__NewObject(OOC_TYPE_DESCR(Exception,ExceptionDesc));
  
  Exception__ExceptionDesc_INIT(e, msg);
#if HAVE_BACKTRACE_SYMBOLS
  e->backtraceSize = backtrace(e->backtrace, Exception__maxBacktraceSize);
#else
  e->backtraceSize = 0;
#endif
  Exception__Abort(e);
}

void Exception__Clear() {
  Exception__GetThreadState()->currentException = NULL;
}

void Exception__PushContext(struct Exception__Context *context,
			    OOC_PTR jmpbuf) {
  Exception__ThreadStatePtr ts = Exception__GetThreadState();
  
  context->next = ts->contextStack;
  context->jmpbuf = jmpbuf;
  ts->contextStack = context;
}

void Exception__PopContext(OOC_INT32 n) {
  Exception__ThreadStatePtr ts = Exception__GetThreadState();
  
  while (n > 0) {
    ts->contextStack = ts->contextStack->next;
    n--;
  }
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

#define B 256
Object__String8 Exception__ExceptionDesc_Name(Exception__Exception e) {
  RT0__Struct td = OOC_TYPE_TAG(e);
  Object__String msg =
    OOC_TBCALL(OOC_TBPROC_ADR(td,Exception__ExceptionDesc_GetMessage),
	       Exception__ExceptionDesc_GetMessage)(e);
  char b[B];
  
  /* if the type name ends with "Desc", then drop the last 4 characters */
  int len = strlen((char*)td->name);
  if ((len >= 4) && (strcmp((char*)td->name + (len-4), "Desc") == 0)) {
    len -= 4;
  }
  /* this may cause a buffer overflow for _very_ long module/type names */
  sprintf(b, "%s.%.*s", td->module->name, len, td->name);
  return Object__NewLatin1Region((OOC_CHAR8*)b, B, 0, strlen(b));
}


void Exception__ParseErrorDesc_INIT(Exception__ParseError e,
				    Object__String msg, OOC_INT32 offset) {
  Exception__ExceptionDesc_INIT((Exception__Exception)e, msg);
  e->offset = offset;
}

void Exception__InitThreadState(Exception__ThreadState *ts) {
  ts->contextStack = NULL;
  ts->currentException = NULL;
}

static Exception__ThreadStatePtr local_GetThreadState() {
  return &local_state;
}

void OOC_Exception_init(void) {
  Exception__InitThreadState(&local_state);
  Exception__GetThreadState = local_GetThreadState;
}

void OOC_Exception_destroy(void) {
  /* FIXME... if we ever to module unloading  */
}
