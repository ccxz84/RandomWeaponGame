// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class RWMain : ModuleRules
{
	public RWMain(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "RWBase", "RWFramework" });
	}
}
