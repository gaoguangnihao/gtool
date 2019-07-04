#ifndef GRALLOCLIB_H
#define GRALLOCLIB_H 


#include <system/window.h>
#include <hardware/hardware.h>
#include <hardware/fb.h>
#include <hardware/gralloc.h>
#include "hardware/hwcomposer.h"

class GrallocLib
{
public:
	GrallocLib();
	~GrallocLib(){};
	
	void render();
private:
	hw_module_t const* module;
	framebuffer_device_t* fbDev;
	alloc_device_t* grDev;
	buffer_handle_t handle;

	gralloc_module_t const *mAllocMod;
};

#endif