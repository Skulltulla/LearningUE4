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

# Content

## xml version

The first line of an XML file:

    <?xml version="1.0" encoding="utf-8"?>
    
## root

    <root xmlns:android="https://schemas.android.com/apk/res/android">
    </root>

### init

    <root xmlns:android="https://schemas.android.com/apk/res/android">
      <init>
      </init>
    </root>
    
### androidManifestUpdates

    <root xmlns:android="https://schemas.android.com/apk/res/android">
        ...
        <androidManifestUpdates>
            <addPermission android:name="android.permission." />
            ...
            <addFeature android:name="android." android:required="false" />
	    ...
	    <addAttribute tag="manifest" name="android:" value="" />
	    ...
	    <addElements tag="application">
                <meta-data android:name="com.example.package" android:value="optional" />
                <meta-data android:name="com.example.package" android:value="required" />
            </addElements>
            ...
        </androidManifestUpdate>
        ...
    </root>

### prebuildCopies

    <root xmlns:android="https://schemas.android.com/apk/res/android">
      <prebuildCopies>
          // copyFile, copyDir
      </prebuildCopies>
    </root>

### proguardAdditions

    <root xmlns:android="https://schemas.android.com/apk/res/android">
        <proguardAdditions>
	    <insert>
	    </insert>
	</proguardAdditions>
    </root>

### resourceCopies

    <root xmlns="android"https:schemas.android.com/apk/res/android">
      <resourceCopies>
          // copyFile, copyDir
      </resourceCopies>
    </root>

## Gradle

### gradleCopies

    <root xmlns:android="https://schemas.android.com/apk/res/android">
      <gradleCopies>
          // copyFile, copyDir
      </gradleCopies>
    </root>

### gradleProperties

    <root xmlns:android="https://schemas.android.com/apk/res/android">
      <gradleProperties>
      </gradleProperties>
    </root>

### baseBuildGradleAdditions

    <root xmlns:android="https://schemas.android.com/apk/res/android">
      <baseBuildGradleAdditions>
        // insert, insertValue, etc
      </baseBuildGradleAdditions>
    </root>

### buildGradleAdditions

    <root xmlns:android="https://schemas.android.com/apk/res/android">
      <buildGradleAdditions>
        <insert>
          dependencies {
             implementation('...')
          }
	</insert>
        <insert>
             dependencies.implementation(name: '', ext: '')
        </insert>
      </buildGradleAdditions>
    </root>

### settingsGradleAdditions

    <root xmlns:android="https://schemas.android.com/apk/res/android">
      <settingsGradleAdditions>
        <insert>
        </insert>
      </settingsGradleAdditions>
    </root>
 
## gameActivity

### gameActivityBeforeConfigRulesAppliedAdditions

    <root xmlns="android"https:schemas.android.com/apk/res/android">
      <gameActivityBeforeConfigRulesAppliedAdditions>
      </gameActivityBeforeConfigRulesAppliedAdditions>
    </root>

### gameActivityImportAdditions

    <root xmlns="android"https:schemas.android.com/apk/res/android">
      <gameActivityImportAdditions>
      </gameActivityImportAdditions>
    </root>

### gameActivityClassAdditions

    <root xmlns="android"https:schemas.android.com/apk/res/android">
      <gameActivityClassAdditions>
      </gameActivityClassAdditions>
    </root>

### gameActivityReadMetadataAdditions

    <root xmlns="android"https:schemas.android.com/apk/res/android">
      <gameActivityReadMetadataAdditions>
      </gameActivityReadMetadataAdditions>
    </root>

### gameActivityOnCreateAdditions

    <root xmlns="android"https:schemas.android.com/apk/res/android">
      <gameActivityOnCreateAdditions>
      </gameActivityOnCreateAdditions>
    </root>

### gameActivityOnStartAdditions

    <root xmlns="android"https:schemas.android.com/apk/res/android">
      <gameActivityOnStartAdditions>
      </gameActivityOnStartAdditions>
    </root>

    
### gameActivityOnResumeAdditions

    <root xmlns="android"https:schemas.android.com/apk/res/android">
      <gameActivityOnResumeAdditions>
      </gameActivityOnResumeAdditions>
    </root>

### gameActivityOnPauseAdditions

    <root xmlns="android"https:schemas.android.com/apk/res/android">
      <gameActivityOnPauseAdditions>
      </gameActivityOnPauseAdditions>
    </root>

### gameActivityOnStopAdditions

    <root xmlns="android"https:schemas.android.com/apk/res/android">
      <gameActivityOnStopAdditions>
      </gameActivityOnStopAdditions>
    </root>

### gameActivityOnDestroyAdditions

    <root xmlns="android"https:schemas.android.com/apk/res/android">
      <gameActivityOnDestroyAdditions>
      </gameActivityOnDestroyAdditions>
    </root>

### gameActivityOnActivityResultAdditions

    <root xmlns="android"https:schemas.android.com/apk/res/android">
      <gameActivityOnActivityResultAdditions>
      </gameActivityOnActivityResultAdditions>
    </root>

### gameActivityOverrideAPKOBBPackaging

    <root xmlns="android"https:schemas.android.com/apk/res/android">
      <gameActivityOverrideAPKOBBPackaging>
      </gameActivityOverrideAPKOBBPackaging>
    </root>

## Other

### soLoadLibrary

    <root xmlns="android"https:schemas.android.com/apk/res/android">
      <soLoadLibrary>
        <loadLibrary name="" failmsg="" />
      </soLoadLibrary>
    </root>

<hr />
 
## Conditionals

    <if condition="">
      <true>
      </true>
      
      <false>
      </false>
    </if>

## Attributes

    <addAttribute tag="" name="" value="" />

## Elements

### Add Element

    <addElement tag="" name="">

### Add Elements

    <addElements tag="application">
        <meta-data android:name="com.example.package" android:value="optional" />
        <meta-data android:name="com.example.package" android:value="required" />
    </addElements>

### Set Element

    <setElement result="" value="" />

### Remove Elements

    <removeElement tag="" />

## Bools

    <setBool result="bAlpha" value="true" />
    <setBool result="bBeta" value="false" />
    <setBoolNot result="bNot" source="" />
    <setBoolAnd result="bAnd" arg1="" arg2="" />
    <setBoolOr result="bOr" arg1="" arg2="" />
    <setBoolIsEqual result="bIsEqual" arg1="" arg2="" />
    <setBoolFromProperty result="bAlpha" ini="" section="" property="" default="" />
    <setBoolFromPropertyContains result="bAlpha" ini="" section="" property="" contains=""/>

## Strings

    <setStringFromAttribute result="" tag="" name="">

    <setStringFromProperty result="" ini="" section="" property="" default="" />

## Elements

    <setElement result="" value="" />
        
## Loops

    <loopElements tag="">
    </loopElements>

## Uncategorized
 
### Log

Log

     <log text=""/>
     
## Files

Copy File

    <copyFile src="" dst="" />

Copy Directory

    <copyDir src="" dst="" />

Delete Files

    <deleteFiles filespec="path/to/files_*" />

### Is

Is Architecture

    <isArch arch="">
    </isArch>

Is Distribution

    <isDistribution>
    </isDistribution>

### Insert

Insert

    <insert>
    </insert>

Newline

    <insertNewLine />
    
Value

    <insertValue value="KEY=VALUE" />

# Combined

    <?xml version="1.0" encoding="utf-8"?>
    <root xmlns:android="https://schemas.android.com/apk/res/android">
        <init>
        </init>

        <androidManifestUpdates>
            <addPermission android:name="android.permission." />
            <addFeature android:name="android." android:required="false" />
            <addAttribute tag="manifest" name="android:" value="" />
            <addElements tag="application">
                <meta-data android:name="com.example.package" android:value="optional" />
                <meta-data android:name="com.example.package" android:value="required" />
            </addElements>
        </androidManifestUpdate>

        <prebuildCopies>
            // copyFile, copyDir
        </prebuildCopies>

        <proguardAdditions>
            <insert>
            </insert>
        </proguardAdditions>

        <resourceCopies>
            // copyFile, copyDir
        </resourceCopies>

        <!-- GRADLE -->

        <gradleCopies>
            // copyFile, copyDir
        </gradleCopies>

        <gradleProperties>
        </gradleProperties>

        <baseBuildGradleAdditions>
            // insert, insertValue, etc
        </baseBuildGradleAdditions>

        <buildGradleAdditions>
            <insert>
                dependencies {
                    implementation('...')
                }
            </insert>
            <insert>
                dependencies.implementation(name: '', ext: '')
            </insert>
        </buildGradleAdditions>

        <settingsGradleAdditions>
            <insert>
            </insert>
        </settingsGradleAdditions>

        <!-- GAME ACTIVITY -->

        <gameActivityBeforeConfigRulesAppliedAdditions>
        </gameActivityBeforeConfigRulesAppliedAdditions>

        <gameActivityImportAdditions>
        </gameActivityImportAdditions>

        <gameActivityClassAdditions>
        </gameActivityClassAdditions>

        <gameActivityReadMetadataAdditions>
        </gameActivityReadMetadataAdditions>

        <gameActivityOnCreateAdditions>
        </gameActivityOnCreateAdditions>

        <gameActivityOnStartAdditions>
        </gameActivityOnStartAdditions>

        <gameActivityOnResumeAdditions>
        </gameActivityOnResumeAdditions>

        <gameActivityOnPauseAdditions>
        </gameActivityOnPauseAdditions>

        <gameActivityOnStopAdditions>
        </gameActivityOnStopAdditions>

        <gameActivityOnDestroyAdditions>
        </gameActivityOnDestroyAdditions>

        <gameActivityOnActivityResultAdditions>
        </gameActivityOnActivityResultAdditions>

        <gameActivityOverrideAPKOBBPackaging>
        </gameActivityOverrideAPKOBBPackaging>

        <soLoadLibrary>
            <loadLibrary name="" failmsg="" />
        </soLoadLibrary>
    </root>

# References

[1] Epic Games, Inc. "Android Configuration Rules System" [Online]. Available: https://docs.unrealengine.com/en-US/Platforms/Mobile/Android/AndroidConfigRulesSystem/index.html

