# _APL.xml | _UPL.xml

## Resources

UnrealPluginLanguage.cs has a block comment with plenty of details and it contains the code
that parses these files.

    ...\UE_VERSION\Engine\Source\Programs\UnrealBuildTool\System\UnrealPluginLanguage.cs

## About

A file that may exist in the same location as the plugin's Build.cs. To use the file, Build.cs is updated by adding it as a receipt property.

## Build.cs | Config Rules 

    public Title(ReadOnlyTargetRules Target) : base(Target)
    {
        // ...

        if( Target.Platform == UnrealTargetPlatform.Android )
        {
            string name = "Untitled"
            string TitleAplPath = ModuleDirectory + "/TITLE_APL.xml";
                AdditionalPropertiesForReceipt.Add("Untitled", TitleAplPath);
        }
    }

> NOTE: The other `Add` method which takes a new ReceiptProperty object was deprecated.

> NOTE: If the file path is invalid, then a package error will occur to indicate it.

> NOTE: Other source files used the Name "AndroidPlugin".

> NOTE: If this is a Plugin's Builds.cs file, then `ModuleDirectory` will refer to its module directory.

# Content

## CDATA

Some data is encapsulated in a CDATA block, which prevents its content from being parsed.

    <![CDATA[
    // java code
    ]]>

- https://en.wikipedia.org/wiki/CDATA

## Content

    <?xml version="1.0" encoding="utf-8"?>

    <root xmlns:android="https://schemas.android.com/apk/res/android">
        <!-- once per architecture -->
        <init>
            <log text="MyAndroidPlugin Init" />
        </init>

        <!-- #################### Android Archive Library #################### -->
        <!--
        <AARImports>
        </AARImports>
        -->
        
        <!-- #################### PROGUARD #################### -->
        <!--
        <proguardAdditions>
        </proguardAdditions>
        -->
        
        <!-- #################### Manifest #################### -->
        <androidManifestUpdates>
            <!--
            <addPermission android:name="android.permission." />
            -->
            
            <!--
            <addFeature android:name="android." android:required="false" />
            -->
            
            <!--
            <addAttribute tag="manifest" name="android:" value="" />
            -->
            
            <!--
            <addElements tag="application">
                <meta-data android:name="com.example.package" android:value="optional" />
                <meta-data android:name="com.example.package" android:value="required" />
            </addElements>
            -->
        </androidManifestUpdates>
        
        <!-- #################### Gradle ####################  -->
        <!--
        <gradleCopies>
            <log text="copyFile, copyDir, etc" />
        </gradleCopies>
        -->
        
        <!--
        <gradleProperties>
        </gradleProperties>
        -->
        
        <!--
        <gradleParameters>
        </gradleParameters>
        -->
        
        <!--
        <baseBuildGradleAdditions>
            <log text="insert, insertValue, etc" />
        </baseBuildGradleAdditions>
        -->

        <!--
        <buildGradleAdditions>
        <insert>
            dependencies{
                implementation('...')
            }
        </insert>
        <insert>
            dependencies.implementation(name: '', ext: '')
        </insert>
        </buildGradleAdditions>
        -->

        <!--
        <buildscriptGradleAdditions>
        </buildscriptGradleAdditions>
        -->
        
        <!--
        <buildXmlPropertyAdditions>
        </buildXmlPropertyAdditions>
        -->
        
        <!--
        <prebuildCopies>
            <log text="copyFile, copyDir, etc" />
        </prebuildCopies>
        -->
        
        <!--
        <resourceCopies>
            <log text="copyFile, copyDir, etc" />
        </resourceCopies>
        -->
        
        <!--
        <minimumSDKAPI>
        </minimumSDKAPI>
        -->
        
        <!-- #################### GAME ACTIVITY #################### -->
        <!--
        <gameActivityReadMetadata>
        </gameActivityReadMetadata>
        -->
        
        <gameActivityImportAdditions>
        <insert>
            <!-- import android.util.Log; -->
        </insert>
        </gameActivityImportAdditions>
        
        <!--
        <gameActivityPostImportAdditions>
        </gameActivityPostImportAdditions>
        -->
        
        <!--
        <gameActivityImplementsAdditions>
        </gameActivityImplementsAdditions>
        -->
        
        <!--
        <gameActivityClassAdditions>
        <insert>
        <![CDATA[
            // Java Code
        ]]>
        </insert>
        </gameActivityOnClassAdditions>
        -->
        
        <!--
        <gameActivityOnCreateAdditions>
        </gameActivityOnCreateAdditions>
        -->
        
        <!--
        <gameActivityOnDestroyAdditions>
        </gameActivityOnDestroyAdditions>
        -->
        
        <!--
        <gameActivityOnStartAdditions>
        </gameActivityOnStartAdditions>
        -->
        
        <!--
        <gameActivityOnStopAdditions>
        </gameActivityOnStopAdditions>
        -->
        
        <!--
        <gameActivityOnPauseAdditions>
        </gameActivityOnPauseAdditions>
        -->
        
        <!--
        <gameActivityOnResumeAdditions>
        </gameActivityOnResumeAdditions>
        -->
        
        <!--
        <gameActivityOnNewIntentAdditions>
        </gameActivityOnNewIntentAdditions>
        -->
        
        <!--
        <gameActivityOnActivityResultAdditions>
        </gameActivityOnActivityResultAdditions>
        -->

        <!--
        <gameActivityOverrideAPKOBBPackaging>
        </gameActivityOverrideAPKOBBPackaging>
        -->
        
        <!-- #################### SO LIBRARY #################### -->
        <!--
        <soLoadLibrary>
            <loadLibrary name="" failmsg="" />
        </soLoadLibrary>
        -->
    </root>

# References

[1] Epic Games, Inc. "Android Configuration Rules System" [Online]. Available: https://docs.unrealengine.com/en-US/Platforms/Mobile/Android/AndroidConfigRulesSystem/index.html

