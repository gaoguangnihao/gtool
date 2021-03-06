

LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

LOCAL_C_INCLUDES := $(TARGET_OUT_HEADERS)/common/inc
LOCAL_C_INCLUDES += $(TARGET_OUT_INTERMEDIATES)/KERNEL_OBJ/usr/include
LOCAL_C_INCLUDES += $(LOCAL_PATH)/include
#LOCAL_C_INCLUDES += frameworks/base/include
LOCAL_C_INCLUDES += hardware/libhardware/include
LOCAL_C_INCLUDES +=	hardware/libhardware_legacy/include
LOCAL_C_INCLUDES +=	system/core/include
LOCAL_C_INCLUDES +=	external/skia/include/core

LOCAL_ADDITIONAL_DEPENDENCIES := $(TARGET_OUT_INTERMEDIATES)/KERNEL_OBJ/usr

LOCAL_SRC_FILES:= \
	gtool.c 	\
	test.cpp	\
	tool/prop.cpp	\
	tool/thread.cpp	\
	tool/cpu.cpp	\
	tool/daemon.cpp \
	binder/IBinderTest.cpp \
	binder/BinderTest.cpp	\
	binder/binder_client.cpp \
	render/Gralloc.cpp	\
	render/GrallocLib.cpp \
	
LOCAL_MODULE:= gtool
LOCAL_MODULE_TAGS := optional
LOCAL_SHARED_LIBRARIES  += libcutils \
	libutils \
	libbinder \
	libskia \
	libhardware \

include $(BUILD_EXECUTABLE)

include $(CLEAR_VARS)
LOCAL_C_INCLUDES := $(TARGET_OUT_HEADERS)/common/inc
LOCAL_C_INCLUDES += $(TARGET_OUT_INTERMEDIATES)/KERNEL_OBJ/usr/include
LOCAL_C_INCLUDES += $(LOCAL_PATH)/include
LOCAL_C_INCLUDES += hardware/libhardware/include
LOCAL_C_INCLUDES +=	hardware/libhardware_legacy/include
LOCAL_C_INCLUDES +=	system/core/include
LOCAL_C_INCLUDES +=	external/skia/include/core

LOCAL_ADDITIONAL_DEPENDENCIES := $(TARGET_OUT_INTERMEDIATES)/KERNEL_OBJ/usr

LOCAL_SRC_FILES:= \
	binder/IBinderTest.cpp \
	binder/BinderTest.cpp	\
	render/GrallocLib.cpp	\
	
LOCAL_MODULE:= libgtool
LOCAL_MODULE_TAGS := optional
LOCAL_SHARED_LIBRARIES  += libcutils \
	libutils \
	libbinder \
	libskia \
	libhardware \

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

include $(CLEAR_VARS)
LOCAL_MODULE       := logo
LOCAL_MODULE_TAGS  := optional
LOCAL_MODULE_CLASS := ETC
LOCAL_SRC_FILES    := res/logo.png
LOCAL_MODULE_PATH  := $(TARGET_ROOT_OUT)/data
include $(BUILD_PREBUILT)