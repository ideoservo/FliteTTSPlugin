// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.
using System.IO;
namespace UnrealBuildTool.Rules
{
    using System.IO;
	public class FliteTTSPlugin : ModuleRules
	{
		public FliteTTSPlugin(TargetInfo Target)
		{
			PublicIncludePaths.AddRange(
				new string[] {
					"FliteTTSPlugin/Private",
                    "FliteTTSPlugin/ThirdParty/flite",
					// ... add public include paths required here ...
				}
				);

			PrivateIncludePaths.AddRange(
				new string[] {
					// ... add other private include paths required here ...
				}
				);

			PublicDependencyModuleNames.AddRange(
				new string[]
				{
					"Core",
					// ... add other public dependencies that you statically link with here ...
				}
				);

			PrivateDependencyModuleNames.AddRange(
				new string[]
				{
					// ... add private dependencies that you statically link with here ...
				}
				);

			DynamicallyLoadedModuleNames.AddRange(
				new string[]
				{
					// ... add any modules that your module loads dynamically here ...
				}
				);
				
			// add Flite TTS libraries
            string BaseDirectory = Path.GetFullPath(Path.Combine(ModuleDirectory, "..", ".."));         
			
			if (Target.Platform == UnrealTargetPlatform.Win32)
            {
                string FliteDirectory = Path.Combine(BaseDirectory, "ThirdParty", "flite", "lib", "Win32");
				RuntimeDependencies.Add(new RuntimeDependency(Path.Combine(FliteDirectory, "fliteDll.dll")));
				RuntimeDependencies.Add(new RuntimeDependency(Path.Combine(FliteDirectory, "cmu_us_rms.dll")));
                RuntimeDependencies.Add(new RuntimeDependency(Path.Combine(FliteDirectory, "cmu_us_slt.dll")));
            }
            else if (Target.Platform == UnrealTargetPlatform.Win64)
            {               
                string FliteDirectory = Path.Combine(BaseDirectory, "ThirdParty", "flite", "lib", "x64");
				RuntimeDependencies.Add(new RuntimeDependency(Path.Combine(FliteDirectory, "fliteDll.dll")));
				RuntimeDependencies.Add(new RuntimeDependency(Path.Combine(FliteDirectory, "cmu_us_rms.dll")));
                RuntimeDependencies.Add(new RuntimeDependency(Path.Combine(FliteDirectory, "cmu_us_slt.dll")));
            }
			else
			{
				// Linux, Mac, WinRT: not supported
			}
			
		}
	}
}