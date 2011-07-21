/* 	$Id: ProcessParameters.c,v 1.12 2005/08/31 11:57:24 mva Exp $	 */
#ifdef WIN32
#include <io.h>
#include <direct.h>
#else
#include <unistd.h>
#endif
#include <errno.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include <__oo2c.h>
#include <__config.h>
#include <OS/ProcessParameters.d>


#define SIZE_BUFFER 1024
Object__String OS_ProcessParameters__GetCwd() {
  char buffer[SIZE_BUFFER];
  if (getcwd(buffer, SIZE_BUFFER)) {
    return OS_Path__Decode((OOC_CHAR8*)buffer, SIZE_BUFFER);
  } else {
    IO_StdChannels__IOError(NULL);
  }
}

Object__String OS_ProcessParameters__GetEnv(Object__String name) {
  char *ptr = getenv((char*)OS_Path__Encode(name));
  if (ptr) {
    return OS_Path__Decode((OOC_CHAR8*)ptr, strlen(ptr)+1);
  } else {
    return NULL;
    return 0;
  }
}


void OOC_OS_ProcessParameters_init(void) {
}

void OOC_OS_ProcessParameters_destroy(void) {
}
