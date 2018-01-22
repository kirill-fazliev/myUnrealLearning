#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "LicenseKeyPluginBP.generated.h"


UCLASS()
class ULicenseKeyPluginBP : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()
	UFUNCTION(BlueprintCallable)
	static bool UpdateLicense();
	UFUNCTION(BlueprintCallable)
	static FString GetBaseDir();
};
