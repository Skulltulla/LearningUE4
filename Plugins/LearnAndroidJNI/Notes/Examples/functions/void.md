# Examples | Functions | Void Method

## Method Definition

    // ModuleTitle_APL.xml
    // ...
    <gameActivityClassAdditions>
    <insert>
    <![CDATA[
    	public void AndroidThunkJava_VoidAlpha()
	{
	}
    ]]>
    </insert>
    </gameActivityClassAdditions>
    // ...

The function name was prefixed with `AndroidThunkJava_` to follow the same naming convention as what is
found in the Unreal Engine source files.

A `jmethodID` for `AndroidThunkJava_Alpha` will be retrieved for using `FJavaWrapper::FindMethod` and
it will be passed to `FJavaWrapper::CallVoidMethod`.

The game activity class is identified via `FJavaWrapper::GameActivityClassID`, which is of the type `jclass`,
see `AndroidJNI.h`.

The game activity object is identified via `FJavaWrapper::GameActivityThis`, which is of the type `jobject`.

https://en.wikipedia.org/wiki/Thunk

## Method Invokation via JNI

In this example a c++ blueprint function library class was created with a BlueprintCallable method that will
invoke the method via JNI.

    // ExampleBPFL.h

    #if PLATFORM_ANDROID
    #include "Android/AndroidJavaEnv.h
    #include "Android/AndroidApplicaion.h"
    #include "Android/AndroidJNI.h"
    #endif

    UFUNCTION(BlueprintCallable, Category="JNI")
    static void VoidAlpha()
    {
        #if PLATFORM_ANDROID
        JNIEnv* jni = FAndroidApplication::GetJavaEnv();
        // JNIEnv* jni = AndroidJavaEnv::GetJavaEnv(); // alternative 

        if( jni )
        {
            static jmethodID VoidAlphaID = FJavaWrapper::FindMethod(
                /** JNIEnv* */ jni, 
                /** jclass */ FJavaWrapper::GameActivityClassID, 
                /** const ANSICHAR* */ "AndroidThunkJava_VoidAlpha", 
                /** Method Signature */ "()V", 
                /** bOptional */ false);

            if( VoidAlphaID )
            {
                FJavaWrapper::CallVoidMethod(/** JNIEnv* */ jni, /** jobject */ FJavaWrapper::GameActivityThis, /** jmethodID */ VoidAlphaID);
            }
        }
        #endif
    }


