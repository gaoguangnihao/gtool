
#include "headers.h"
#include "GrallocLib.h"

extern "C" int gralloc_main (char **token, int len) {
	GLogD("gralloc_main enter ");

	GrallocLib* pGralloc = new GrallocLib();
	pGralloc->render();
	return 0;
}
