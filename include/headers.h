
#ifndef __GTOOL_HEADER
#define __GTOOL_HEADER

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VERSION "2.0"

#ifdef __cplusplus
extern "C" {
#endif

#include "log.h"

int prop_main(char **token, int len);
int thread_main(char **token, int len);
int cpu_main(char **token, int len);
int daemon_main(char **token, int len);
int binder_main(char **token, int len);
int gralloc_main(char **token, int len);

#ifdef __cplusplus
}
#endif

#endif  // __GTOOL_HEADER