
# Design Notes

## .Plugin Configuration

`SQLiteCore` was added as a plugin to `LearnSQLiteCore.uplugin' to resolve the following compiler warning:

> Warning: Plugin 'LearnSQLiteCore' does not list plugin 'SQLiteCore' as dependency, but module 'LearnSQLiteCore' depends on 'SQLiteCore'.

Note that Rider for Unreal Engine highlighted the plugin and said that it is not available.

## Build.cs Configuration

'SQLiteCore' was added as a public dependency module name, but the path to its public source folder also needed to be added to the `PublicIncludePaths` (see [2]).

The base path of `PublicIncludePaths` that would be searched was `..\UE_XX\Engine\Source\` and the `..` prefix was used to go up one level so the Engine's `Plugins'
folder could be conveniently referenced.


## Regenerating the Project Files

After configuring the plugin's **.uplugin** and **.Build.cs** files for SQLiteCore, the automatically generated project files 
had to be deleted and regenerated before the code completion would find the SQLiteCore headers - just cleaning the project and recompiling was not enough.


# References

1. "Unreal Build Tool Dependency Warning" https://answers.unrealengine.com/questions/704619/unrealbuildtool-dependancy-warning.html?sort=oldest
2. "How to include the header files from a plugin" https://answers.unrealengine.com/questions/70019/how-to-include-the-header-file-from-a-plugin.html
