
#include <cutils/properties.h>

#include "prop.h"
#include "headers.h"


SystemProp::SystemProp() {
	GLogD("SystemProp constructor!");
}

SystemProp::~SystemProp() {
	GLogD("SystemProp destructor!");
}

char* SystemProp::GetProp(const char *key) {
	char buf[PROPERTY_VALUE_MAX];
	property_get(key, buf, "");
	return buf;
}

void SystemProp::SetProp(const char *key, char *value) {
	int ret;
	if (ret = property_set(key, value) < 0) {
		printf("set fail key : %s\n", key);
	} else {
		printf("set ok, key:%s value:%s\n", key, value);
	}
}


extern "C" int prop_main(char **token, int len)
{
	GLogD("prop main, len %d\n", len);
	int i;
	for (i =0; i < len; i ++) {
		GLogD("token[%d]: %s\n", i, token[i]);
	}
	char oprator[20], key[100], value[100];

	if (len > 1) {
		strncpy(oprator, token[1], 20);
	}

	GLogD("oprator = %s\n",  oprator);
	if (!strcmp("set", oprator)) {								// prop set
		if (len < 4) {
			GLogD("set cmd param is not avaliable!");
			return -1;
		}
		strcpy(key, token[2]);
		strcpy(value, token[3]);
		SystemProp::GetInstance()->SetProp(key, value);
	} else if (!strcmp("get", oprator)) {						// prop get
		if (len < 3) {
			GLogD("get cmd param is not avaliable!");
			return -1;	
		}
		strcpy(key, token[2]);
		char* value = (char *)SystemProp::GetInstance()->GetProp(key);
		printf("%s\n", value);
	} else {
		GLogD("error cmd!");
	}
	return 0;
}