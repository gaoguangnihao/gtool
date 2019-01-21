

#include "IBinderTest.h"

using namespace android;
using namespace std;

class BinderTest : public BnBinderTest, public IBinder::DeathRecipient
{
private:
	BinderTest();
	~BinderTest();
	
	static BinderTest *mInstance;
public:
	int32_t processCmd(uint32_t cmdId,  uint32_t paramLen);  

	char* processCmdStr(const char *str); 

	static void instantiate();

	virtual void binderDied(const wp<IBinder>& who);  
	
};
