
#include "stdio.h"

#include "GrallocLib.h"
#include "SkBitmap.h"
#include "log.h"

// using namespace std;

// int readPng(string filename, char* buf, size_t size) {
// 	ifstream streampng;
// 	streampng.open(filename.c_str(), ios_base::binary);
// 	streampng.seekg(0, ios::end);
// 	size = streampng.tellg();

// 	buf = new char[size + 1];
// 	streampng.seekg(0, ios::beg);
// 	streampng.read(buf, size);
// 	return 1;   
// }

// static void
// writetofile(const char * fname,const void* buffer, size_t bytes) {
//     static FILE *fp=NULL;
//     if(fp==NULL || access( fname, F_OK )==-1){
//         fp = fopen(fname, "ab+" );
//         if(fp==NULL){
//             GLOG("can't open file!");
//             fp=NULL;
//             return;
//         }
//     }
//     if(fp!=NULL){
//         fwrite(buffer , 1 , bytes , fp );
//     }
// }

GrallocLib::GrallocLib()
:fbDev(NULL),
grDev(NULL) {

}

void GrallocLib::render() {
	int stride;
	int err;
	void* vaddr;

	SkBitmap* pBitmap;

	GLogD("render");
	if (hw_get_module(GRALLOC_HARDWARE_MODULE_ID, &module) == 0) {
		GLogD("get gralloc module ok");

		err = framebuffer_open(module, &fbDev);  
		if (err) GLogD("couldn't open framebuffer HAL (%s)", strerror(-err));

		err = gralloc_open(module, &grDev); //打开gralloc设备
		if(err) GLogD("couldn't open gralloc HAL (%s)", strerror(-err));

		err = grDev->alloc(grDev, 240, 320, HAL_PIXEL_FORMAT_RGBA_8888, 
			GRALLOC_USAGE_HW_FB, &handle, &stride); //分配图形缓冲区

		mAllocMod = (gralloc_module_t const *)module;
		err = mAllocMod->registerBuffer(mAllocMod, handle); //映射内存到进程中

		err = mAllocMod->lock(mAllocMod, handle, HAL_PIXEL_FORMAT_RGBA_8888, 0, 0, 240, 320, &vaddr);

		GLogD("Create skBitmap here");
		SkBitmap bitmap;
    	bitmap.setInfo(SkImageInfo::Make(240, 320, kN32_SkColorType, kPremul_SkAlphaType));
    	bitmap.allocPixels();
        bitmap.eraseColor(0x0000ff00);
       	memcpy(vaddr, bitmap.getPixels(), bitmap.getSize()); 

		// char* data;
		// size_t size;
		// if (readPng("data/logo.png", data, size) != 1) {
		// 	GLOG("readpng fail");
		// }
		
		// GLogD("readpng ok, size = %d", size);
		// memcpy(vaddr, data, size);

		// writetofile("data/out.txt", data, size);

		err = mAllocMod->unlock(mAllocMod, handle);

		if(fbDev) {
			fbDev->post(fbDev, handle);    // 图形缓冲区的渲染 
		}

		err = mAllocMod->unregisterBuffer(mAllocMod, handle); //解除映射内存
		grDev->free(grDev, handle);//释放图形缓冲区       
		gralloc_close(grDev);//关闭gralloc设备
		if (fbDev) {
			framebuffer_close(fbDev);//关闭fb设备  
		}
	} 
}