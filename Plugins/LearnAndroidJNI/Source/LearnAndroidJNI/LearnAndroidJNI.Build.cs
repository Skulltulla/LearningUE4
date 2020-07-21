// Some copyright should be here...

using UnrealBuildTool;

public class LearnAndroidJNI : ModuleRules
{
	public LearnAndroidJNI(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicIncludePaths.AddRange( new string[] {
        });
		PrivateIncludePaths.AddRange( new string[] {
        });

		PublicIncludePathModuleNames.AddRange( new string[] {
            "Core"
        });
		PublicDependencyModuleNames.AddRange( new string[] {
            "Core",
        });
		PrivateDependencyModuleNames.AddRange( new string[] {
            "CoreUObject",
            "Engine",
            "Slate",
            "SlateCore",
            
            "ApplicationCore"
        });
		if( Target.Platform == UnrealTargetPlatform.Android ) 
		{
			PrivateDependencyModuleNames.AddRange( new string[] {
                "Launch"
            });
        }
		
		DynamicallyLoadedModuleNames.AddRange( new string[] {
        });
	}
}
