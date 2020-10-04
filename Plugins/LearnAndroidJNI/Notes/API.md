# API Components

## FAndroidApplication
- Module:	ApplicationCore
- Path:		`\Engine\Source\Runtime\ApplicationCore\Public\Android\AndroidApplication.h`
- Include:	`#include "Android/AndroidApplication.h"`
- Methods:
  - `FAndroidApplication::GetJavaEnv -> JNIEnv*`

**Remarks**

See `AndroidJavaEnv` for alternative way of getting `JNIEnv*`.

**.Build.cs**

    PrivateDependencyModuleNames.AddRange(new string[] {
        "ApplicationCore"
    });

**Include**

    #if PLATFORM_ANDROID
      #include "Android/AndroidApplication.h"
    #endif

**Source**

    #if PLATFORM_ANDROID
      JNIEnv* jni = FAndroidApplication::GetJavaEnv();
    #endif

## FJavaWrapper
- Module:	Launch
- Path:		`\Engine\Source\Runtime\Launch\Public\Android\AndroidJNI.h`
- Include:	`#include "Android/AndroidJNI.h`
- Some static members:
  - `::GameActivityClassID` may be passed to FJavaWrapper::FindMethod, etc
  - `::GameActivityThis` may be passed to FJavaWrapper::Call...Method, etc
- Some static methods:
  - `::FindClass`
  - `::FindClassGlobalRef`
  - `::FindMethod`
  - `::FindStaticMethod`
  - `::FindField`
  - `::CallVoidMethod`
  - `::CallObjectMethod`
  - `::CallIntMethod`
  - `::CallLongMethod`
  - `::CallFloatMethod`
  - `::CallDoubleMethod`
  - `::CallBooleanMethod`

**.Build.cs**

    if(Target.Platform == UnrealTargetPlatform.Android)
    {
        PrivateDependencyModuleNames.AddRange(new string[]{
            "Launch"
        });
        // ...
    }

**Include**

    #if PLATFORM_ANDROID
      #include "Android/AndroidJNI.h"
    #endif

**Source**

    #if PLATFORM_ANDROID
      // jni = ...GetJavaEnv();
      FJavaWrapper::CallVoidMethod(jni, FJavaWrapper::GameActivityThis, AndroidThunkJava_UntitledMethod);
    #endif

## AndroidJavaEnv
- Module: Core
- Include: `#include "Android/AndroidJavaEnv.h"`
- Location: `..\Engine\Source\Runtime\Core\Public\Android\AndroidJavaEnv.h`

**Remarks**

See `FAndroidApplication` for alternative way of getting `JNIEnv*`. The following method
of obtaining an instance of `JNIEnv*` was used in the following source files and it also worked
in a new project.

    ./Runtime/ApplicationCore/Private/Android/AndroidApplication.cpp
    ./Runtime/ApplicationCore/Public/Android/AndroidApplication.h
    ./Runtime/Core/Private/Android/AndroidJava.cpp
    ./Runtime/Core/Private/Android/AndroidJavaEnv.cpp
    ./Runtime/Core/Private/Android/AndroidPlatformMisc.cpp
    ./Runtime/Core/Private/Android/AndroidPlatformProcess.cpp

**Build.cs**

The `Core` module was automatically included in `PublicDependencyModuleNames` when a new project was made.

**Include**

    #if PLATFORM_ANDROID
        #include "Android/AndroidJavaEnv.h"
    #endif

**Source**

    #if PLATFORM_ANDROID
    JNIEnv* jni = AndroidJavaEnv::GetJavaEnv();
    #endif

## Types
- Module: Engine

**Build.cs**

    PublicDependencyModuleNames.AddRange( new string[]{
        // ...
        "Engine"
	// ...
    });

> NOTE: The `Engine` module was automatically added to a Project's Build.cs, but not to a new Plugin's Build.cs.

**Types**

- `jclass`
- `jobject`
- `jfieldID`
- `jmethodID`
- `jboolean`
- `jint`
- `jfloat`
- `jfloatArray`
- `jstring`

https://docs.oracle.com/javase/8/docs/technotes/guides/jni/spec/types.html


