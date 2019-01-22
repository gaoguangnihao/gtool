
#ifndef _GTOOL_LOG_H
#define _GTOOL_LOG_H 

#include <android/log.h>

#undef LOG_TAG
#define LOG_TAG "gtool>>"

#define DEBUG 1

#define GLogD(args...)  if(DEBUG) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, args); 

//#define Log_Position  if(DEBUG) do {__android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, "%s(%d){%s}",__FILE__,__LINE__,__func__);}while(0)


#endif


