/* 	$Id$	 */
#include <stdlib.h>

#include <__oo2c.h>
#include <OS/ProcessManagement.d>


int OS_ProcessManagement__system(const OOC_CHAR8* command, OOC_LEN command_0d) {
  return system((const char*)command);
}

void OOC_OS_ProcessManagement_init(void) {
}
