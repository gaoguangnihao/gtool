
#include <hardware/hardware.h>
#include <hardware/hwcomposer.h>

//#include "SkBitmap.h"

#include "headers.h"

// hw_module_t const* module;
// framebuffer_device_t* fbDev;
// alloc_device_t* grDev;
// buffer_handle_t handle;

// gralloc_module_t const *mAllocMod;

int stride;
int err;

//SkBitmap mBitmap = new SkBitmap();

int gralloc_main (char **token, int len) {
	GLogD("gralloc_main enter ");
/*	if (hw_get_module(GRALLOC_HARDWARE_MODULE_ID, &module) == 0) {
		err = framebuffer_open(module, &fbDev);  // 
		if (err) GLogE("couldn't open framebuffer HAL (%s)", strerror(-err));

		err = gralloc_open(module, &grDev); //打开gralloc设备
		if(err) GLogE("couldn't open gralloc HAL (%s)", strerror(-err));

		err = grDev->alloc(grDev, 240, 320, HAL_PIXEL_FORMAT_RGBA_8888, 
			GRALLOC_USAGE_HW_FB, &handle, &stride); //分配图形缓冲区

		mAllocMod = (gralloc_module_t const *)module;
		err = mAllocMod->registerBuffer(mAllocMod, handle); //映射内存到进程中

		err = mAllocMod->lock(mAllocMod, handle, HAL_PIXEL_FORMAT_RGBA_8888, 0, 0, 240, 320, &vaddr);
		GLogD("++++++++++++++++> vaddr = %p\n", vaddr);

	//	bitmap.lockPixels();

		err = mAllocMod->unlock(mAllocMod, handle);
		err = mAllocMod->unregisterBuffer(mAllocMod, handle); //解除映射内存

		grDev->free(grDev, handle);//释放图形缓冲区       
		gralloc_close(grDev);//关闭gralloc设备
		framebuffer_close(fbDev);//关闭fb设备 
	} */
	return 0;
}
