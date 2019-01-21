

#ifndef IBINDERTEST_H
#define IBINDERTEST_H

#include <binder/IInterface.h>  
#include <binder/IBinder.h>
#include <binder/Parcel.h>  

#include "log.h"

using namespace android;

class IBinderTest : public IInterface
{
public:
	DECLARE_META_INTERFACE(BinderTest);  
	
	virtual int32_t processCmd(uint32_t cmdId,  uint32_t paramLen) = 0;  

	virtual char* processCmdStr(const char *str) = 0; 
};

class BnBinderTest : public BnInterface<IBinderTest>
{
public:
	virtual status_t onTransact(uint32_t code, const Parcel& data, Parcel* reply,  
                uint32_t flags = 0);  
	
};

#endif