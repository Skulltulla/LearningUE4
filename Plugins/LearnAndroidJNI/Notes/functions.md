# Void Method

A void method with no parameters.

## Method Definition | APL.xml

    <gameActivityClassAdditions>
    <insert>
    <![CDATA[
        // Method Signature: "()V"
        public void AndroidThunkJava_VoidAlpha()
        {
        }
    ]]>
    </insert>
    </gameActivityClassAdditions>

The function name was prefixed with `AndroidThunkJava_` to follow the same naming convention as what is
found in the Unreal Engine source files.

A `jmethodID` for `AndroidThunkJava_VoidAlpha` will be retrieved using `FJavaWrapper::FindMethod` and
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


# Bool Parameter

## Method Definition | APL.xml

    <gameActivityClassAdditions>
    <insert>
    <![CDATA[
        // Method Signature: "(Z)V"
        public void AndroidThunkJava_ParamBoolean(boolean b)
        {
        }
    ]]>
    </insert>
    </gameActivityClassAdditions>

## Method Invokation | JNI

    UFUNCTION(BlueprintCallable, Category = "JNI")
    static void ParamBoolean()
    {
    #if PLATFORM_ANDROID
        JNIEnv* jni = FAndroidApplication::GetJavaEnv();
        static jmethodID MethodID = FJavaWrapper::FindMethod(jni, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_ParamBoolean", "(Z)V", false);
        if( MethodID )
        {
            bool bContent = false;
            jboolean JBooleanContent = bContent ? JNI_TRUE : JNI_FALSE;
            FJavaWrapper::CallVoidMethod(jni, FJavaWrapper::GameActivityThis, MethodID, JBooleanContent);
        }
    #endif
    }

# Return Boolean

## Method Definition | APL.xml

    <gameActivityClassAdditions>
    <insert>
    <![CDATA[
        // Method Signature: "()Z"
        public boolean AndroidThunkJava_ReturnBoolean()
        {
            return false;
        }
    ]]>
    </insert>
    </gameActivityClassAdditions>

## Method Invokation

    UFUNCTION(BlueprintCallable, Category = "JNI")
    static void ReturnBoolean()
    {
    #if PLATFORM_ANDROID
        JNIEnv* jni = FAndroidApplication::GetJavaEnv();
        static jmethodID MethodID = FJavaWrapper::FindMethod(jni, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_ParamBoolean", "()Z", false);
        if( MethodID )
        {
            bool bResult = FJavaWrapper::CallBooleanMethod(jni, FJavaWrapper::GameActivityThis, MethodID);
        }
    #endif
    }

# Resources

1. Oracle. "JNI Types and Data Structures" [Online]. Available: https://docs.oracle.com/javase/8/docs/technotes/guides/jni/spec/types.html


