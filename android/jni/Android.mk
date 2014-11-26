LOCAL_PATH := $(call my-dir)
 
include $(CLEAR_VARS)  

LOCAL_MODULE := ec8top 
LOCAL_SRC_FILES := jni_part.cpp ../../bateria.c ../../infomemoria.c ../../layout.c mongoose_changed.c ../../numprocessos.c ../../versaoso.c oc8top.c 
LOCAL_LDLIBS += -llog -ldl
 
include $(BUILD_SHARED_LIBRARY)



