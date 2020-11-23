# Learn Settings

**ULearnSettingsSettings**

Uses UCLASS and UPROPERTY specifiers to configure custom settings that will be stored in DefaultGame.ini

**FLearnSettingsModule**

The module registers `ULearnSettingsSettings` to the project settings so the properties may be edited in the editor.

**ULearnSettingsBPLibrary**

Contains a method that uses `GConfig` to read project settings at runtime.

