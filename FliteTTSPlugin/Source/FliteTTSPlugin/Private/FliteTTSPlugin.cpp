// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

//#include "Runtime/Projects/Public/Interfaces/IPluginManager.h"
//#include "IPluginManager.h"
#pragma once
#include "FliteTTSPluginPrivatePCH.h"

#include "../../../ThirdParty/flite/include/flite.h"

extern "C" {
	cst_voice *register_cmu_us_rms(const char *voxdir);
	void unregister_cmu_us_rms(cst_voice *v);
	cst_voice *register_cmu_us_slt(const char *voxdir);
	void unregister_cmu_us_slt(cst_voice *v);
}

#pragma comment(lib, "fliteDll.lib")
#pragma comment(lib, "cmu_us_rms.lib")
#pragma comment(lib, "cmu_us_slt.lib")



class FFliteTTSPlugin : public IFliteTTSPlugin
{
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

protected:
	static void FreeDependency(void*& Handle);
	static bool LoadDependency(const FString& Dir, const FString& Name, void*& Handle);
	static void* LibFlite;
	static void* LibUsRms;
	static void* LibUsSlt;
	static FString PluginDir;
};

IMPLEMENT_MODULE( FFliteTTSPlugin, FliteTTSPlugin )

//FLITETTS_DEFINE(flite_init);

void* FFliteTTSPlugin::LibFlite = nullptr;
void* FFliteTTSPlugin::LibUsRms = nullptr;
void* FFliteTTSPlugin::LibUsSlt = nullptr;

void FFliteTTSPlugin::StartupModule()
{
	// This code will execute after your module is loaded into memory (but after global variables are initialized, of course.)
	const FString BaseDir = ".";// IPluginManager::Get().FindPlugin("FliteTTSPlugin")->GetBaseDir();
	const FString FliteDir = FPaths::Combine(*BaseDir, TEXT("ThirdParty"), TEXT("flite"));

	


#if PLATFORM_64BITS
	const FString LibDir = FPaths::Combine(*FliteDir, TEXT("Win64"));

	if (!LoadDependency(LibDir, TEXT("fliteDll"), LibFlite) ||
		!LoadDependency(LibDir, TEXT("cmu_us_rms"), LibUsRms) ||
		!LoadDependency(LibDir, TEXT("cmu_us_slt"), LibUsSlt))
	{
		ShutdownModule();
		return;// false;
	}
#else
	const FString LibDir = FPaths::Combine(*FliteDir, TEXT("Win32"));

	if (!LoadDependency(LibDir, TEXT("fliteDll"), LibFlite) ||
		!LoadDependency(LibDir, TEXT("cmu_us_rms"), LibUsRms) ||
		!LoadDependency(LibDir, TEXT("cmu_us_slt"), LibUsSlt))
	{
		ShutdownModule();
		return;// false;
}
#endif
	
	flite_init();
    cst_voice *v1 = register_cmu_us_rms(NULL);
    cst_voice *v2 = register_cmu_us_slt(NULL);
    flite_text_to_speech("FLITE is a great Talk to Speech library", v1, "play");
	flite_text_to_speech("FLITE is a great Talk to Speech library", v2, "play");
	
}


void FFliteTTSPlugin::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	FreeDependency(LibUsSlt);
	FreeDependency(LibUsRms);
	FreeDependency(LibFlite);

}

void FFliteTTSPlugin::FreeDependency(void*& Handle)
{
	if (Handle != nullptr)
	{
		FPlatformProcess::FreeDllHandle(Handle);
		Handle = nullptr;
	}
}


bool FFliteTTSPlugin::LoadDependency(const FString& Dir, const FString& Name, void*& Handle)
{
	FString Lib = Name + TEXT(".") + FPlatformProcess::GetModuleExtension();
	FString Path = Dir.IsEmpty() ? *Lib : FPaths::Combine(*Dir, *Lib);

	Handle = FPlatformProcess::GetDllHandle(*Path);

	if (Handle == nullptr)
	{
		GLog->Logf(ELogVerbosity::Warning, TEXT("FliteTTSPlugin: Failed to load required library %s. Plug-in will not be functional."), *Lib);
		return false;
	}

	return true;
}

