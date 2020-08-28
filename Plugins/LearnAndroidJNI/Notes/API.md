# API Components

## FAndroidApplication
- Module:	ApplicationCore
- Path:		`\Engine\Source\Runtime\ApplicationCore\Public\Android\AndroidApplication.h`
- Include:	`#include "Android/AndroidApplication.h"`
- Methods:
  - `FAndroidApplication::GetJavaEnv -> JNIEnv*`

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


