// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "LicenseKeyPlugin.h"
#include "Core.h"
#include "ModuleManager.h"
#include "IPluginManager.h"

#define LOCTEXT_NAMESPACE "FLicenseKeyPluginModule"

typedef bool(*LoadLicenseKeyImported)(char*);
LoadLicenseKeyImported loadLicenseKey;

typedef bool(*GetMachineGUIDImported)();
GetMachineGUIDImported getMachineGUID;

typedef bool(*CheckKeyImported)();
CheckKeyImported checkKey;

typedef bool(*UpdateLicenseImported)(char*);
UpdateLicenseImported updateLicense;

typedef void(*CreateRequestFileImported)(char*);
CreateRequestFileImported createRequestFile;

/* is key loaded */
static bool keyLoaded = false;
/* is key verified*/
static bool keyVerified = false;

static FString BaseDir = "";

void FLicenseKeyPluginModule::StartupModule()
{
#if PLATFORM_WINDOWS

	BaseDir = FPaths::ProjectContentDir();

	copyDllToContentFolder();
	addDllToPackage();

	KeyManagerLibraryPath = FPaths::Combine(BaseDir, TEXT("dll") , TEXT("KeyManager.dll"));

	KeyManagerLibraryHandle = !KeyManagerLibraryPath.IsEmpty() ? FPlatformProcess::GetDllHandle(*KeyManagerLibraryPath) : nullptr;
	if (KeyManagerLibraryHandle == nullptr)
	{
		FString text = "Erorr! ";
		text.Append("Failed to load KeyManager.dll from path: ");
		text.Append(KeyManagerLibraryPath);
		FMessageDialog::Open(EAppMsgType::Ok, FText::FromString(text));
		FGenericPlatformMisc::RequestExit(false);
		return;
	}

	getMachineGUID = (GetMachineGUIDImported)FPlatformProcess::GetDllExport(KeyManagerLibraryHandle, TEXT("GetMachineGUID"));
	loadLicenseKey = (LoadLicenseKeyImported)FPlatformProcess::GetDllExport(KeyManagerLibraryHandle, TEXT("LoadLicenseKey"));
	checkKey = (CheckKeyImported)FPlatformProcess::GetDllExport(KeyManagerLibraryHandle, TEXT("CheckKey"));
	updateLicense = (UpdateLicenseImported)FPlatformProcess::GetDllExport(KeyManagerLibraryHandle, TEXT("UpdateLicense"));
	createRequestFile = (CreateRequestFileImported)FPlatformProcess::GetDllExport(KeyManagerLibraryHandle, TEXT("CreateRequestFile"));

	getMachineGUID();
	ANSICHAR* keyPath = TCHAR_TO_ANSI(*FPaths::Combine(*BaseDir, TEXT("License.lkey")));

	keyLoaded = false;
	keyVerified = false;

	keyLoaded = loadLicenseKey(keyPath);
	if (!keyLoaded)
	{
		FMessageDialog::Open(EAppMsgType::Ok, LOCTEXT("Error", "Failed to load license key. Creating request file ReqestKeyFile.rkey. Exiting..."));
		createRequestFile(TCHAR_TO_ANSI(*FPaths::Combine(*BaseDir, TEXT("ReqestKeyFile.rkey"))));
		FGenericPlatformMisc::RequestExit(false);
		return;
	}
	keyVerified = checkKey();
	if (!keyVerified)
	{
		FMessageDialog::Open(EAppMsgType::Ok, LOCTEXT("Erorr", "Failed to check license key. Creating request file ReqestKeyFile.rkey. Exiting..."));
		createRequestFile(TCHAR_TO_ANSI(*FPaths::Combine(*BaseDir, TEXT("ReqestKeyFile.rkey"))));
		UpdateLicense();
		FGenericPlatformMisc::RequestExit(false);
		return;
	}
	UpdateLicense();
#endif // PLATFORM_WINDOWS
}

void FLicenseKeyPluginModule::ShutdownModule()
{
#if PLATFORM_WINDOWS

	if (keyLoaded)
	{
		ANSICHAR* keyPath = TCHAR_TO_ANSI(*FPaths::Combine(*BaseDir, TEXT("License.lkey")));
		updateLicense(keyPath);
	}
	if (KeyManagerLibraryHandle != nullptr)
	{
		getMachineGUID = nullptr;
		loadLicenseKey = nullptr;
		checkKey = nullptr;
		updateLicense = nullptr;
		createRequestFile = nullptr;
		FPlatformProcess::FreeDllHandle(KeyManagerLibraryHandle);
		KeyManagerLibraryHandle = nullptr;
	}
#endif
}
bool FLicenseKeyPluginModule::UpdateLicense()
{
#if PLATFORM_WINDOWS

	if (keyLoaded)
	{
		ANSICHAR* keyPath = TCHAR_TO_ANSI(*FPaths::Combine(*BaseDir, TEXT("License.lkey")));
		return updateLicense(keyPath);
	}
	return false;
#else
	return false;
#endif
}


FString FLicenseKeyPluginModule::GetBaseDirPath()
{
	return BaseDir;
}

void FLicenseKeyPluginModule::copyDllToContentFolder()
{
	IPlatformFile& platformFile = FPlatformFileManager::Get().GetPlatformFile();


	FString dllDirectory = FPaths::Combine(*BaseDir, TEXT("dll"));

	FString destinationFilePath = dllDirectory + "/KeyManager.dll";

	FString sourceFilePath = FPaths::Combine(*FPaths::ProjectPluginsDir(), TEXT("LicenseKeyPlugin/Content/KeyManager.dll"));
	if (!FPlatformFileManager::Get().GetPlatformFile().FileExists(*sourceFilePath))
	{
		sourceFilePath = FPaths::Combine(*FPaths::ProjectPluginsDir(), TEXT("Runtime/LicenseKeyPlugin/Content/KeyManager.dll"));
		if (!FPlatformFileManager::Get().GetPlatformFile().FileExists(*sourceFilePath))
		{
			sourceFilePath = FPaths::Combine(*FPaths::EnginePluginsDir(), TEXT("Runtime/LicenseKeyPlugin/Content/KeyManager.dll"));
			if (!FPlatformFileManager::Get().GetPlatformFile().FileExists(*sourceFilePath))
			{
				FMessageDialog::Open(EAppMsgType::Ok, LOCTEXT("Error", " Missing KeyManager.dll"));
			}
		}
	}

	if (!platformFile.DirectoryExists(*dllDirectory))
	{
		platformFile.CreateDirectory(*dllDirectory);
	}
	if (!platformFile.FileExists(*destinationFilePath))
	{
		platformFile.CopyFile(*destinationFilePath, *sourceFilePath);
	}

}

void FLicenseKeyPluginModule::addDllToPackage()
{
	IPlatformFile& platformFile = FPlatformFileManager::Get().GetPlatformFile();
	FString iniFilePath = FPaths::Combine(FPaths::ProjectConfigDir(), TEXT("DefaultGame.ini"));
	TArray<FString> arrayString;
	if (!FFileHelper::LoadFileToStringArray(arrayString, *iniFilePath))
	{
		FMessageDialog::Open(EAppMsgType::Ok, LOCTEXT("Error! ", "Failed to open DefaultGame.ini"));
		return;
	}
	int32 bStartsPackagingSettings = -1;
	FString stringProjectPackagingSettings = TEXT("[/Script/UnrealEd.ProjectPackagingSettings]");
	FString stringPathToDLL = TEXT("+DirectoriesToAlwaysStageAsNonUFS=(Path=\"dll\")");
	for (int32 i = 0; i < arrayString.Num(); ++i)
	{
		if (arrayString[i] == stringProjectPackagingSettings)
		{
			bStartsPackagingSettings = i;
		}
		if (arrayString[i] == stringPathToDLL)
		{
			return;
		}
	}
	if (bStartsPackagingSettings == -1)
	{
		arrayString.Add(stringProjectPackagingSettings);
		arrayString.Add(stringPathToDLL);
		FFileHelper::SaveStringArrayToFile(arrayString, *iniFilePath);
		FMessageDialog::Open(EAppMsgType::Ok, LOCTEXT("Warinig", " Please, restart editor to apply new config"));
		FGenericPlatformMisc::RequestExit(false);
	}
	else
	{
		arrayString.Insert(stringPathToDLL, bStartsPackagingSettings + 1);
		FFileHelper::SaveStringArrayToFile(arrayString, *iniFilePath);
		FMessageDialog::Open(EAppMsgType::Ok, LOCTEXT("Warinig", " Please, restart editor to apply new config"));
		FGenericPlatformMisc::RequestExit(false);

	}
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FLicenseKeyPluginModule, LicenseKeyPlugin)