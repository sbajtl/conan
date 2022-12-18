
LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

# Common definitions

LOCAL_SRC_FILES := \
  triangle.c \
  triexit.cpp

# triangle library modules.

LOCAL_CFLAGS := -DTRILIBRARY -DNO_TIMER -DANSI_DECLARATORS -DSINGLE -DREDUCED -std=c++11
LOCAL_MODULE := triangle
LOCAL_SRC_FILES := $(LOCAL_SRC_FILES)
include $(BUILD_STATIC_LIBRARY)

