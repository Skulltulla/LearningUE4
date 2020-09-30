# API Components

## FAndroidApplication
- Module:	ApplicationCore
- Path:		`\Engine\Source\Runtime\ApplicationCore\Public\Android\AndroidApplication.h`
- Include:	`#include "Android/AndroidApplication.h"`
- Methods:
  - `FAndroidApplication::GetJavaEnv -> JNIEnv*`


**.Build.cs**

    PrivateDependencyModuleNames.AddRange(new string[] {
        "ApplicationCore"
    });

**.h**

    #if PLATFORM_ANDROID
      #include "Android/AndroidApplication.h"
    #endif

**.cpp**

    #if PLATFORM_ANDROID
      JNIEnv* jni = FAndroidApplication::GetJavaEnv();
    #endif

## FJavaWrapper
- Module:	Launch
- Path:		`\Engine\Source\Runtime\Launch\Public\Android\AndroidJNI.h`
- Include:	`#include "Android/AndroidJNI.h`
- Members:
  - `FJavaWrapper::GameActivityThis`
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

**.Build.cs**

    if(Target.Platform == UnrealTargetPlatform.Android)
    {
        "Launch"
    }

**.h**

    #if PLATFORM_ANDROID
      #include "Android/AndroidJNI.h"
    #endif

**.cpp**

    #if PLATFORM_ANDROID
      // jni = FAndroidApplication::GetJavaEnv(true);
      FJavaWrapper::CallVoidMethod(jni, FJavaWrapper::GameActivityThis, AndroidThunkJava_UntitledMethod);
    #endif

## TODO
- `#include "jni.h"`
- `\Engine\Source\Runtime\Core\Public\Android\AndroidJavaEnv.h`

## Types
- `jclass`
- `jobject`
- `jfieldID`
- `jmethodID`
- ...

- `jboolean`
- ...

- `jint`
- ...

- `jfloat`
- `jfloatArray`
- ...

- `jstring`
- ...


