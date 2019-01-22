

LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

LOCAL_C_INCLUDES := $(TARGET_OUT_HEADERS)/common/inc
LOCAL_C_INCLUDES += $(TARGET_OUT_INTERMEDIATES)/KERNEL_OBJ/usr/include
LOCAL_C_INCLUDES += $(LOCAL_PATH)/include
#LOCAL_C_INCLUDES += frameworks/base/include

LOCAL_ADDITIONAL_DEPENDENCIES := $(TARGET_OUT_INTERMEDIATES)/KERNEL_OBJ/usr

LOCAL_SRC_FILES:= \
	gtool.c 	\
	prop.cpp	\
	GtoolThread.cpp	\
	Cpu.cpp	\
	daemon.cpp \
	IBinderTest.cpp \
	BinderTest.cpp	\
	binder_client.cpp
	
LOCAL_MODULE:= gtool
LOCAL_MODULE_TAGS := optional
LOCAL_SHARED_LIBRARIES  += libcutils \
	libutils \
	libbinder \

include $(BUILD_EXECUTABLE)

include $(CLEAR_VARS)

LOCAL_C_INCLUDES := $(TARGET_OUT_HEADERS)/common/inc
LOCAL_C_INCLUDES += $(TARGET_OUT_INTERMEDIATES)/KERNEL_OBJ/usr/include
LOCAL_C_INCLUDES += $(LOCAL_PATH)/include
#LOCAL_C_INCLUDES += frameworks/base/include

LOCAL_ADDITIONAL_DEPENDENCIES := $(TARGET_OUT_INTERMEDIATES)/KERNEL_OBJ/usr

LOCAL_SRC_FILES:= \
	IBinderTest.cpp \
	BinderTest.cpp	\
	
LOCAL_MODULE:= libgtool
LOCAL_MODULE_TAGS := optional
LOCAL_SHARED_LIBRARIES  += libcutils \
	libutils \
	libbinder \

include $(BUILD_SHARED_LIBRARY)


# GtoolCommand
# include $(CLEAR_VARS)
# LOCAL_SRC_FILES := $(call all-subdir-java-files)
# LOCAL_MODULE := gtoolCmd
# include $(BUILD_JAVA_LIBRARY)

# include $(CLEAR_VARS)
# LOCAL_MODULE := gtoolCmd
# LOCAL_SRC_FILES := gtoolCmd
# LOCAL_MODULE_CLASS := EXECUTABLES
# LOCAL_MODULE_TAGS := optional
# include $(BUILD_PREBUILT)