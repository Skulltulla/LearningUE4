# Logging

## JNI Logging

**Include**

    #if PLATFORM_ANDROID
        #include "Android/log.h"
    #endif

**Source**

    #if PLATFORM_ANDROID
    __android_log_print(PRIORITY, TAG, MESSAGE, ...);
    #endif

# References

1. Google. "Logging" [Online]. Available: https://developer.android.com/ndk/reference/group/logging

