// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "ModuleManager.h"

class FLicenseKeyPluginModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	static bool UpdateLicense();
	static FString GetBaseDirPath();
	void copyDllToContentFolder();
	void addDllToPackage();
private:
	/* Handle to the dll we will load */
	void*	KeyManagerLibraryHandle;

	/* relative location of the third party dll and load it */
	FString KeyManagerLibraryPath;
};