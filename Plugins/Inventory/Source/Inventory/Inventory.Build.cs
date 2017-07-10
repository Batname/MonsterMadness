using UnrealBuildTool;

public class Inventory : ModuleRules
{
	public Inventory(ReadOnlyTargetRules Target) : base(Target)
	{

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "UMG" });
	
        PublicIncludePaths.AddRange( new string[] {
			"Inventory/Public",
        } );

        PrivateIncludePaths.AddRange( new string[] {
			"Inventory/Private",
        } );

	}
}
