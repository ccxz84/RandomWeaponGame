// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class RandomWeaponGameEditorTarget : TargetRules
{
	public RandomWeaponGameEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.Add("RWMain");
		ExtraModuleNames.Add("RWBase");
		ExtraModuleNames.Add("RWFramework");
		ExtraModuleNames.Add("RWUI");
	}
}
