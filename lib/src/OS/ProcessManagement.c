/* 	$Id$	 */
#include <stdlib.h>
#include <stdio.h>
#include <__oo2c.h>
#include <OS/ProcessManagement.d>
#ifdef __MINGW32__
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
  result = system((const char*)buffer);
  free(buffer);
  return result;
}
#else
int OS_ProcessManagement__system(const OOC_CHAR8* command, OOC_LEN command_0d) {
  return system((const char*)command);
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
