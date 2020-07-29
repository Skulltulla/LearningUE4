# Design Notes

## Files
### PLUGINTITLE_APL.xml
A file that exists in the same location as the plugin's Build.cs.

To use the file, Build.cs is updated by adding it as a receipt property.

todo:
- minimal content required
- GameActivity.java additions, etc

    <gameActivityImportAdditions>
        <insert></insert>
    </gameActivityImportAdditions>

    <gameActivityClassAdditions>
        <insert></insert>
    </gameActivityClassAdditions>


references:
- https://stackoverflow.com/questions/40153299/use-apl-android-programming-language-to-make-android-plugin-to-unreal-engine-4

## API Components
### FAndroidApplication
- Module:	ApplicationCore
- Path:		\Engine\Source\Runtime\ApplicationCore\Public\Android\AndroidApplication.h
- Include:	#include "Android/AndroidApplication.h"
- Methods:
  - FAndroidApplication::GetJavaEnv -> JNIEnv*

### FJavaWrapper
- Module:	Launch
- Path:		\Engine\Source\Runtime\Launch\Public\Android\AndroidJNI.h
- Include:	#include "Android/AndroidJNI.h
- Members:
  - FJavaWrapper::GameActivityThis
- Some static methods:
  - ::FindClass
  - ::FindClassGlobalRef
  - ::FindMethod
  - ::FindStaticMethod
  - ::FindField
  - ::CallVoidMethod
  - ::CallObjectMethod
  - ::CallIntMethod
  - ::CallLongMethod
  - ::CallFloatMethod
  - ::CallDoubleMethod

## TODO
- #include "jni.h"
- \Engine\Source\Runtime\Core\Public\Android\AndroidJavaEnv.h

## Types
- jclass
- jobject
- jfieldID
- jmethodID
- ...

- jboolean
- ...

- jint
- ...

- jfloat
- jfloatArray
- ...

- jstring
- ...


