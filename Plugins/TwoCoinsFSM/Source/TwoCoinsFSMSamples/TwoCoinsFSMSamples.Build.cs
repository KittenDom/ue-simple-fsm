using UnrealBuildTool;

public class TwoCoinsFSMSamples : ModuleRules
{
	public TwoCoinsFSMSamples(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(
			new string[]
			{
			}
		);

		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"CoreUObject",
				"Engine",
				"TwoCoinsFSM",
			}
		);
	}
}