/* 	$Id: ProcessManagement.c,v 1.11 2005/08/31 11:57:24 mva Exp $	 */
#include <stdlib.h>
#include <stdio.h>
#include <__oo2c.h>
#include <OS/ProcessManagement.d>
#ifdef __MINGW32__
#include <windows.h>
#  define WIFEXITED(x) (((x) & 0xffff0000) == 0)
#  define WEXITSTATUS(x) ((x) & 0x0000ffff)
#  define WTERMSIG(x) (x)
#else
#include <sys/wait.h>
#endif

#ifdef __MINGW32__
/* 
To run a command with "shell" syntax, we need to invoke an external shell
which is assumed to be in /bin/sh. The command passed to system() must be
quoted so that it can be passed through the Windows shell AND through the
microsoft C run-time startup to /bin/sh. These processes use different quoting
rules.

According to "The Windows NT Command Shell" (Tim Hill):
- If a double-quoted argument itself contains a double quote character, the
  double quote must be doubled. For example, enter "Quoted" Argument as
  """Quoted"" Argument". 

Also:

Microsoft C startup code uses the following rules when interpreting arguments
given on the operating system command line:  
- Arguments are delimited by white space, which is either a space or a tab.
- A string surrounded by double quotation marks is interpreted as a single
  argument, regardless of white space contained within. A quoted string can be
  embedded in an argument. Note that the caret (^) is not recognized as an
  escape character or delimiter. 
- A double quotation mark preceded by a backslash, \", is interpreted as a
  literal double quotation mark (").
- Backslashes are interpreted literally, unless they immediately precede a
  double quotation mark.
- If an even number of backslashes is followed by a double quotation mark,
  then one backslash (\) is placed in the argv array for every pair of
  backslashes (\\), and the double quotation mark (") is interpreted as a
  string delimiter.
- If an odd number of backslashes is followed by a double quotation mark, then
  one backslash (\) is placed in the argv array for every pair of backslashes
  (\\) and the double quotation mark is interpreted as an escape sequence by
  the remaining backslash, causing a literal double quotation mark (") to be
  placed in argv.

The following implementation appears to work, although it required a some
trial and error to sort out the inconsistencies above.

*/

/* The default system() used in the MS run-time appears to call the Windows
 * shell, which has limitations on the length of the command line. This causes
 * problems for oo2c which can generate long command-lines during linking.
 *
 * This replacement system() uses Kernel functions to manage the process.
 */

static int new_system(const char * args) {
  PROCESS_INFORMATION info;
  STARTUPINFO si;
  HANDLE handles[1];
  DWORD res;

  si.cb = sizeof(STARTUPINFO);
  si.lpReserved = NULL;
  si.lpDesktop = NULL;
  si.lpTitle = NULL;
  si.dwFlags = 0;
  si.cbReserved2 = 0;
  si.lpReserved2 = NULL;

  if (CreateProcess(NULL, args, NULL, NULL, TRUE, 0, NULL, NULL, &si, &info)) {
    handles[0] = info.hProcess;
    res = WaitForMultipleObjects(1, handles, FALSE, INFINITE); 
    if (res == WAIT_OBJECT_0) {
      if (GetExitCodeProcess(info.hProcess, &res)) {
        return res;
      } 
    }
  }
  return GetLastError();
}

#ifdef USE_SHELL
char * prefix = "/bin/sh -c \"";

int OS_ProcessManagement__system(const OOC_CHAR8* command, OOC_LEN command_0d) {
  int length, src, dest, result, slashes;
  char * buffer;

/* Compute required length of string. We need 2 bytes to escape a quote. */

  length = strlen(command) + strlen(prefix) + 2; 
  src = 0;
  while (command[src] != 0) {
    char c = command[src];
    if ((c=='"') || (c=='\\')) {
      length += 1;
	}
    ++src;
  }

/* Allocate result string, and copy prefix */

  buffer = (char *) malloc(length);
  strcpy(buffer, prefix);

/* Now append command, escaping all double quotes */

  dest = strlen(buffer);
  src = 0;
  while (command[src]) {
    char c = command[src++];
    slashes = 0;
    while (c=='\\') {
      ++slashes;
      buffer[dest++] = '\\';
      c = command[src++];
    }
    if (c=='\"') {
      if (slashes > 0) {
        while (slashes >= 0) {
          buffer[dest++] = '\\';
          --slashes;
        }
      } else {
        buffer[dest++] = '"';
      }
    }
    buffer[dest++] = c;
  }

  buffer[dest++] = '"';
  buffer[dest] = 0;
  result = new_system((const char*)buffer);
  free(buffer);
  return result;
}

#else
int OS_ProcessManagement__system(Object__String command) {
  if (command == NULL) {
    return new_system(NULL);
  } else {
    return new_system(OS_Path__Encode(command));
  }
}
#endif
#else
int OS_ProcessManagement__system(Object__String command) {
  if (command == NULL) {
    return system(NULL);
  } else {
    return system((char*)OS_Path__Encode(command));
  }
}
#endif

int OS_ProcessManagement__ExitStatus(int status) {
  if (WIFEXITED(status))
    return WEXITSTATUS(status);
  else
    return -1;
}

int OS_ProcessManagement__TermSignal(int status) {
  if (!WIFEXITED(status))
    return WTERMSIG(status);
  else
    return 0;
}

void OOC_OS_ProcessManagement_init(void) {
}

void OOC_OS_ProcessManagement_destroy(void) {
}
