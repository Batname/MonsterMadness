// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class MonsterMadness : ModuleRules
{
	public MonsterMadness(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "UMG", "BatInventory" });
		PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
	
        PublicIncludePaths.AddRange( new string[] {
			"MonsterMadness/Public",
        } );

        PrivateIncludePaths.AddRange( new string[] {
			"MonsterMadness/Private",
        } );

	}
}
