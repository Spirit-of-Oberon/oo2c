#include <__oo2c.h>
#include <__config.h>

#if TIME_WITH_SYS_TIME
# include <sys/time.h>
# include <time.h>
#else
# if HAVE_SYS_TIME_H
#  include <sys/time.h>
# else
#  include <time.h>
# endif
#endif

#include <Logger/TimeStamp.d>

void Logger_TimeStamp__GmtNow(OOC_CHAR8 *str, OOC_LEN str_len,
			const OOC_CHAR8* template, OOC_LEN template_len) {
  time_t t = time(NULL);
  struct tm *now = gmtime(&t);  /* not reentrant... FIXME */
  strftime((char*)str, str_len, (char*)template, now);
}

void Logger_TimeStamp__LocalNow(OOC_CHAR8 *str, OOC_LEN str_len,
			  const OOC_CHAR8* template, OOC_LEN template_len) {
  time_t t = time(NULL);
  struct tm *now = localtime(&t);  /* not reentrant... FIXME */
  strftime((char*)str, str_len, (char*)template, now);
}

void OOC_Logger_TimeStamp_init() {
}

void OOC_Logger_TimeStamp_destroy() {
}
