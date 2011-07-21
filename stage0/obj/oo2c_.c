#include <RT0.oh>
int main (int argc, char *argv[]) {
  RT0__argc = (OOC_INT32)argc;
  RT0__argv = (OOC_CHAR8**)argv;
  OOC_oo2c_open(NULL);
  return 0;  /* _program_exit_code */
}
