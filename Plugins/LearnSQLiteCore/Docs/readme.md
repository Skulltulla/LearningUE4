# LearnSQLite Core

**SQLiteCore** is an official plugin provided by Epic Games that was introduced in version 4.22 and **SQLiteCore** and **SQLiteSupport**
can be found under the following folder [1].

    ..\Epic Games\UE_XY\Engine\Plugins\Runtime\Database\


# Design Notes

## Packaging

Database files need to be included in a folder that is under "Additional non-asset directories to copy" that will "not [be] included in PAK file" [2].

That folder must be under the projects Content directory and its path was prefixed with the path to the project's content directory:

    #include "Misc/Paths.h"
    const FString DatabaseFilename = FPaths::ProjectContentDir() + FString(TEXT("Data/database.sqlite3"));

On Android, the Content folder will be located at:

    /storage/emulated/0/UE4Game/ProjectTitle/ProjectTitle/Content/

## .Plugin Configuration

`SQLiteCore` was added as a plugin to `LearnSQLiteCore.uplugin' to resolve the following compiler warning:

> Warning: Plugin 'LearnSQLiteCore' does not list plugin 'SQLiteCore' as dependency, but module 'LearnSQLiteCore' depends on 'SQLiteCore'.

Note that Rider for Unreal Engine highlighted the plugin and said that it is not available.

## Build.cs Configuration

'SQLiteCore' was added as a public dependency module name, but the path to its public source folder also needed to be added to the `PublicIncludePaths` (see [3]).

The base path of `PublicIncludePaths` that would be searched was `..\UE_XX\Engine\Source\` and the `..` prefix was used to go up one level so the Engine's `Plugins'
folder could be conveniently referenced.


## Regenerating the Project Files

After configuring the plugin's **.uplugin** and **.Build.cs** files for SQLiteCore, the automatically generated project files 
had to be deleted and regenerated before the code completion would find the SQLiteCore headers - just cleaning the project and recompiling was not enough.


# Issues

## Non-Asset Copied is empty [Resolved]

The database file was added to a subfolder in Content and was added to the Additional non-asset folders to copy, but it was an empty file on the
Android device.

See issue #3

https://github.com/Skulltulla/LearningUE4/issues/3

# References

1. Epic Games, Inc. "Unreal Engine 4.22 Release Notes" [Online] Available: https://docs.unrealengine.com/en-US/WhatsNew/Builds/ReleaseNotes/4_22/index.html
2. Setiawan, Anton. "Using SQLite as Data Store in Unreal" [Online]. Available: http://www.antonsetiawan.com/archives/2016/05/using-sqlite-as-datastore-in-unreal/
2. "Unreal Build Tool Dependency Warning" https://answers.unrealengine.com/questions/704619/unrealbuildtool-dependancy-warning.html?sort=oldest
3. "How to include the header files from a plugin" https://answers.unrealengine.com/questions/70019/how-to-include-the-header-file-from-a-plugin.html
