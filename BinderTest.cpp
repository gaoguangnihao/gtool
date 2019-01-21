

#include <sys/types.h>
#include <unistd.h>
#include <binder/IServiceManager.h>  
#include <binder/IPCThreadState.h>

#include "BinderTest.h"


BinderTest* BinderTest::mInstance = NULL;

BinderTest::BinderTest() {
	GLogD("BinderTest pid : %d", getpid());
}

BinderTest::~BinderTest() {
	GLogD("~BinderTest");
}

int32_t BinderTest::processCmd(uint32_t cmdId,  uint32_t paramLen) {
	GLogD("BinderTest processCmd cmdId = %d, paramLen = %d", cmdId, paramLen);
	sleep(10);
	return 333;
}

char* BinderTest::processCmdStr(const char *str) {
	GLogD("BinderTest processCmdStr str = %s", str);
	sleep(10);
	char ret[100] = {0};
	strcpy(ret, str);
	GLogD("const_cast %s", ret);
	return ret;
} 

void BinderTest::instantiate() {
	//GLogD("instantiate func:%s, line:%s, file:%s", __func__, __LINE__, __FILE__);
	GLogD("instantiate 123");
	GLogD("instantiate func:%s, line:%d, file:%s", __func__, __LINE__, __FILE__);
	if (mInstance == NULL) {
		mInstance = new BinderTest();
		status_t st = defaultServiceManager()->addService(    
		                          String16("gtool.testbinder"), mInstance);    
		GLogD("addService ret = %d", st);
	}
}
void BinderTest::binderDied(const wp<IBinder>& who) {
	GLogD("binderDied() 1 %p, tid %d, calling tid %d", 
		who.unsafe_get(), gettid(),IPCThreadState::self()->getCallingPid());  	
}
