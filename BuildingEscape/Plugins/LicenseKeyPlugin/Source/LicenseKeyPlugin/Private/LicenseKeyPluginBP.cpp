#include "LicenseKeyPluginBP.h"
#include "LicenseKeyPlugin.h"


ULicenseKeyPluginBP::ULicenseKeyPluginBP(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{

}

bool ULicenseKeyPluginBP::UpdateLicense()
{
	return FLicenseKeyPluginModule::UpdateLicense();
}

FString ULicenseKeyPluginBP::GetBaseDir()
{
	return FLicenseKeyPluginModule::GetBaseDirPath();
}
