using UnrealBuildTool;

public class MonsterMadnessMenu : ModuleRules
{
	public MonsterMadnessMenu(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });
		PrivateDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });
	
        PublicIncludePaths.AddRange( new string[] {
			"MonsterMadnessMenu/Public",
        } );

        PrivateIncludePaths.AddRange( new string[] {
			"MonsterMadnessMenu/Private",
        } );

	}
}
