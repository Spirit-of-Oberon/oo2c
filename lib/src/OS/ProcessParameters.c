/* 	$Id$	 */
#include <unistd.h>
#include <errno.h>
#include <stddef.h>
#include <stdlib.h>

#include "__oo2c.h"
#include "__config.h"
#include "OS/ProcessParameters.d"


void OS_ProcessParameters__ErrorContextDesc_GetTemplate(OS_ProcessParameters__ErrorContext context, Msg__Msg msg, Msg__LString templ, OOC_LEN templ_0d) {
  char *str;
  OOC_INT32 res = msg->code;
  
  if (res == OS_ProcessParameters__invalidBuffer) {
    str = "Internal error: Buffer for `getcwd' is empty";
  } else if (res == OS_ProcessParameters__cwdTooLong) {
    str = "Current working directory does not fit into buffer";
  } else if (res == OS_ProcessParameters__accessDenied) {
    str = "Access denied to component of current working directory";
  } else {
    str = "Unknown error code";
  }

  _copy_8to16(str, templ, templ_0d);
  if (msg->attribList) {
    Msg__Attribute attr;
    OOC_CHAR16 eol[2] = {(OOC_CHAR16)CharClass__eol[0], (OOC_CHAR16)0};
    OOC_CHAR16 str16[Msg__sizeAttrName+1];
    
    attr = msg->attribList;
    while (attr) {
      LongStrings__Append(eol, 2, templ, templ_0d);
      _copy_8to16((char*)attr->name, str16, strlen((char*)attr->name)+1);
      LongStrings__Append(str16, Msg__sizeAttrName+1, templ, templ_0d);
      _copy_8to16("=${", str16, Msg__sizeAttrName+1);
      LongStrings__Append(str16, Msg__sizeAttrName+1, templ, templ_0d);
      _copy_8to16((char*)attr->name, str16, Msg__sizeAttrName+1);
      LongStrings__Append(str16, Msg__sizeAttrName+1, templ, templ_0d);
      _copy_8to16("}", str16, Msg__sizeAttrName+1);
      LongStrings__Append(str16, Msg__sizeAttrName+1, templ, templ_0d);
      attr = attr->nextAttrib;
    }
  }
}


static Msg__Msg get_error() {
  Msg__Msg msg;
  OOC_INT32 code;
  
  switch (errno) {
  case EINVAL: code = OS_ProcessParameters__invalidBuffer; break;
  case ERANGE: code = OS_ProcessParameters__cwdTooLong; break;
  case EACCES: code = OS_ProcessParameters__accessDenied; break;
  default    : code = -1;
  }
  
  msg = Msg__New((Msg__Context)OS_ProcessParameters__errorContext, code);
#if HAVE_STRERROR
  DYN_TBCALL(Msg,MsgDesc,SetStringAttrib,msg,
	     (msg, (const OOC_CHAR8*)"errstr", 7, (OOC_CHAR8*)strerror(errno)));
#endif
  DYN_TBCALL(Msg,MsgDesc,SetIntAttrib,msg,
	     (msg, (const OOC_CHAR8*)"errno", 6, (OOC_INT32)errno));
  return msg;
}


void OS_ProcessParameters__getcwd(OS_ProcessParameters__Path buffer, OOC_LEN buffer_0d, Msg__Msg *res) {
  if (getcwd((char*)buffer, buffer_0d)) {
    *res = OS_ProcessParameters__done;
  } else {
    *res = get_error();
  }
}


void OS_ProcessParameters_init(void) {
  OS_ProcessParameters__errorContext =
    RT0__NewObject(OOC_TYPE_DESCR(OS_ProcessParameters,ErrorContextDesc));
  Msg__InitContext((Msg__Context)OS_ProcessParameters__errorContext, 
		   (const OOC_CHAR8*)"OS:ProcessParameters", 21);
}
