using UnrealBuildTool;
/**
 ** SQLiteCore **
 * ..\Engine\Plugins\Runtime\Database\SQLiteCore
 * SQLiteTypes.h
 * SQLitePreparedStatement.h
 * SQLiteDatabase.h
 * 
 ** SQLiteSupport **
 * ..\Engine\Plugins\Runtime\Database\SQLiteSupport
 */

/**
 * 
 */
public class LearnSQLiteCore : ModuleRules
{
	public LearnSQLiteCore(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		bool IsTargetTypeEditor = Target.Type == TargetRules.TargetType.Editor;
		
		PublicIncludePaths.AddRange( new string[] 
		{
			"../Plugins/Runtime/Database/SQLiteCore/Source/SQLiteCore/Public",
        });
		PrivateIncludePaths.AddRange( new string[] 
		{
        });
		PublicDependencyModuleNames.AddRange( new string[] 
		{
            "Core",
            "SQLiteCore"
        });
		PrivateDependencyModuleNames.AddRange( new string[] 
		{
            "CoreUObject",
            "Engine",
            "Slate",
            "SlateCore",
        });
		
		DynamicallyLoadedModuleNames.AddRange( new string[] 
		{
        });
	}
}
