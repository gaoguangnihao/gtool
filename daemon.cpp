


#include <unistd.h>
#include <binder/IPCThreadState.h>  
#include <binder/IServiceManager.h>  
#include <binder/ProcessState.h>

#include "headers.h"
#include "utils/RefBase.h"
#include "BinderTest.h"


int do_main() {
	GLogD("do main enter!");
	sp<ProcessState> process(ProcessState::self());  
	GLogD("defaultServiceManager");
	sp<IServiceManager> sm = defaultServiceManager(); 
	GLogD("BinderTest instantiate");
	BinderTest::instantiate();  
	GLogD("startThreadPool");
	ProcessState::self()->startThreadPool();    
	IPCThreadState::self()->joinThreadPool(); 

	GLogD("do main enter");
	return 1;
}


int daemon_main(char **token, int len) {
	GLogD("daemon_main");

	pid_t pid;

	pid = fork();
	if (pid < 0) {
		GLogD("fork failed");
		_exit(0);
	}

	if (pid > 0) {
		GLogD("parent process");
		return -1;
	}

	// child process
	if (setsid() < 0) {
		GLogD("setsid failed");
		return -1;
	}

	do_main();
	return 0;
}