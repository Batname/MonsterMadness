using UnrealBuildTool;

public class MonsterMadnessMenu : ModuleRules
{
	public MonsterMadnessMenu(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "UMG" });
		PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
	
        PublicIncludePaths.AddRange( new string[] {
			"MonsterMadnessMenu/Public",
        } );

        PrivateIncludePaths.AddRange( new string[] {
			"MonsterMadnessMenu/Private",
        } );

	}
}
