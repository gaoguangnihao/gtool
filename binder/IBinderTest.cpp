

#include "IBinderTest.h"
#include "utils/String8.h"
#include "utils/String16.h"

enum {  
    TEST_CMD = IBinder::FIRST_CALL_TRANSACTION,   
    TEST_CMD_2,
};  

class BpBinderTest : public BpInterface<IBinderTest>
{
public:
	BpBinderTest(const sp<IBinder>& impl) :  
        BpInterface<IBinderTest>(impl) {  
    }

    int32_t processCmd(uint32_t cmdId,  uint32_t paramLen) {
    	GLogD("BpBinderTest processCmd cmdId %d, paramLen %d, descriptor:%s", cmdId, paramLen,
    		String8(descriptor).string());
    	Parcel data, reply;  
    	data.writeInterfaceToken(descriptor);  
    	data.writeInt32(cmdId);  
    //	data.writeInt32(paramLen);  
    	remote()->transact(TEST_CMD, data, &reply);  
    	reply.readExceptionCode();  
    	return reply.readInt32(); 
    }  

    char* processCmdStr(const char *str) {
    	Parcel data, reply;  
    	data.writeInterfaceToken(descriptor);  
    	data.writeCString(str);   
    	remote()->transact(TEST_CMD_2, data, &reply);  
    	reply.readExceptionCode();  
  //  	char * ret = const_cast<char *>(reply.readCString());
    //	GLogD("BpBinderTest processCmdStr reply = %s", reply.readCString());
    	char ret[100] = {0};
    	strcpy(ret, reply.readCString());
    	GLogD("BpBinderTest processCmdStr ret = %s", ret);
    	return  ret;
    } 
};


IMPLEMENT_META_INTERFACE(BinderTest, "android.gtool.BinderTestService");


status_t BnBinderTest::onTransact(uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags) {
	GLogD("BnBinderTest onTransact code: %d", code);
	switch(code) {
		case TEST_CMD: {
			CHECK_INTERFACE(IBinderTest, data, reply);  
			int32_t cmdId = data.readInt32();  
			int32_t paramLen = 0;//= data.readInt32();  
			// const uint8_t* param = static_cast<const uint8_t *>(data.readInplace(paramLen));  
			GLogD("%d, %d", cmdId,  paramLen);        
			const int32_t ret = processCmd(cmdId, paramLen);   
			reply->writeNoException();  
			reply->writeInt32(ret);  
		  	return NO_ERROR; 
		  }
		 case TEST_CMD_2: {
		 	CHECK_INTERFACE(IBinderTest, data, reply);  
		 	const char *str = data.readCString();    
		 	GLogD("%s", str);        
		 	char *ret = processCmdStr(str);   
		 	GLogD("ret = %s", ret);  
		 	reply->writeNoException();  
		 	reply->writeCString(ret);  
		 	return NO_ERROR; 
		 }
		default:
			return BBinder::onTransact(code, data, reply, flags);  
	}

}