
#include <binder/IServiceManager.h>  

#include "headers.h"
#include "IBinderTest.h"

class DeathNotifier : public IBinder::DeathRecipient
{
public:
	DeathNotifier(){};
	~DeathNotifier(){};

	virtual void binderDied(const wp<IBinder>& who) {
		GLogD("DeathNotifier  binderDied() 1 %p, tid %d", 
			who.unsafe_get(), gettid());  	
	};
};

int binder_main(char **token, int len){
	GLogD("binder_main enter");
	sp<IServiceManager> sm= defaultServiceManager();
	sp<IBinder> binder = sm->getService(String16("gtool.testbinder"));   
	if (len < 2) {
		GLogD("not avaliabel param");
		return -1;
	}
	if ( binder != NULL) {
		sp<DeathNotifier> deathNotifier = new DeathNotifier();
		binder->linkToDeath(deathNotifier);
		sp<IBinderTest> btService = interface_cast<IBinderTest>(binder);
		if ( !strcmp(token[1], "1")) {
			int32_t ret =  btService->processCmd(878, 3);	
			printf("%d\n", ret);
		} else if ( !strcmp(token[1], "2")){
			char *ret = btService->processCmdStr("test processCmdStr");
			printf("%s\n", ret);
		}
		binder->unlinkToDeath(deathNotifier);
	} else {
		printf("get binder test service fail\n");
	}
	return 1;
}