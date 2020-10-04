# Examples | jtypes

After an instance is created, it may be passed as one of the variadic arguments to `FJavaWrapper::Call...`.

## jclass | jobject

    // TODO

## jfieldID

    // TODO

## jmethodID

    // TODO
    jmethodID MethodID = FJavaWrapper::FindMethod...

## jboolean | jbooleanArray

**jboolean**

    // initialization
    jboolean JBooleanTrue = JNI_TRUE;
    jboolean JBooleanFalse = JNI_FALSE;

    bool bBool;
    jboolean JBoolean = bBool ? JNI_TRUE : JNI_FALSE;

    // jboolean > bool
    (bool)JBool;

**jbooleanArray**

    // the array
    int32 Count = 1;
    jbooleanArray JBooleanArray = (jbooleanArray)jni->NewBooleanArray(Count);

    // used to access elements of JBooleanArray
    jboolean* JBooleanPtr = jni->GetBooleanArrayElements( JBooleanArray, 0 );

    int32 LastIndex = Count - 1;
    for(int32 index = 0; index < LastIndex; index++)
    {
        JBooleanPtr[index] = false;
    }

## jint

    // TODO

## jfloat

    // TODO

## jfloatArray

    // TODO

## jstring

**Conversion**

    // CString > jstring
    const char* CString
    jstring JString = jni->NewStringUTF( CString );

    // FString > jstring
    FString UnrealString;
    jstring JString = jni->NewStringUTF( TCHAR_TO_UTF8(*UnrealString) );

    // TODO
    // FString > jstring
    // @FJavaHelper : See AndroidJavaEnv.h
    // FString UnrealString;
    // jstring JString = FJavaHelper::ToJavaString(jni, UnrealString);

    // jstring > CString/FString
    const char* CString = jni->GetStringUTFChars(JString, 0);
    FString UnrealString = FString( UTF8_TO_TCHAR(CString) );

**Conditionals**

    jstring JString;
    if( !JString || jni->IsSameObject(JString, NULL) ){}

# References 

1. Epic Games, Inc. ..\Engine\Source\Runtime\Core\Private\Android\AndroidJavaEnv.cpp


