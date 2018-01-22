// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Public/LicenseKeyPluginBP.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeLicenseKeyPluginBP() {}
// Cross Module References
	LICENSEKEYPLUGIN_API UClass* Z_Construct_UClass_ULicenseKeyPluginBP_NoRegister();
	LICENSEKEYPLUGIN_API UClass* Z_Construct_UClass_ULicenseKeyPluginBP();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	UPackage* Z_Construct_UPackage__Script_LicenseKeyPlugin();
	LICENSEKEYPLUGIN_API UFunction* Z_Construct_UFunction_ULicenseKeyPluginBP_GetBaseDir();
	LICENSEKEYPLUGIN_API UFunction* Z_Construct_UFunction_ULicenseKeyPluginBP_UpdateLicense();
// End Cross Module References
	void ULicenseKeyPluginBP::StaticRegisterNativesULicenseKeyPluginBP()
	{
		UClass* Class = ULicenseKeyPluginBP::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetBaseDir", (Native)&ULicenseKeyPluginBP::execGetBaseDir },
			{ "UpdateLicense", (Native)&ULicenseKeyPluginBP::execUpdateLicense },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	UFunction* Z_Construct_UFunction_ULicenseKeyPluginBP_GetBaseDir()
	{
		struct LicenseKeyPluginBP_eventGetBaseDir_Parms
		{
			FString ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FStrPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Str, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, STRUCT_OFFSET(LicenseKeyPluginBP_eventGetBaseDir_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "Public/LicenseKeyPluginBP.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ULicenseKeyPluginBP, "GetBaseDir", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04022401, sizeof(LicenseKeyPluginBP_eventGetBaseDir_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ULicenseKeyPluginBP_UpdateLicense()
	{
		struct LicenseKeyPluginBP_eventUpdateLicense_Parms
		{
			bool ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			auto NewProp_ReturnValue_SetBit = [](void* Obj){ ((LicenseKeyPluginBP_eventUpdateLicense_Parms*)Obj)->ReturnValue = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Bool, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(LicenseKeyPluginBP_eventUpdateLicense_Parms), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_ReturnValue_SetBit)>::SetBit, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "Public/LicenseKeyPluginBP.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ULicenseKeyPluginBP, "UpdateLicense", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04022401, sizeof(LicenseKeyPluginBP_eventUpdateLicense_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_ULicenseKeyPluginBP_NoRegister()
	{
		return ULicenseKeyPluginBP::StaticClass();
	}
	UClass* Z_Construct_UClass_ULicenseKeyPluginBP()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
				(UObject* (*)())Z_Construct_UPackage__Script_LicenseKeyPlugin,
			};
			static const FClassFunctionLinkInfo FuncInfo[] = {
				{ &Z_Construct_UFunction_ULicenseKeyPluginBP_GetBaseDir, "GetBaseDir" }, // 3165336777
				{ &Z_Construct_UFunction_ULicenseKeyPluginBP_UpdateLicense, "UpdateLicense" }, // 126668442
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "IncludePath", "LicenseKeyPluginBP.h" },
				{ "ModuleRelativePath", "Public/LicenseKeyPluginBP.h" },
			};
#endif
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<ULicenseKeyPluginBP>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&ULicenseKeyPluginBP::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00000080u,
				FuncInfo, ARRAY_COUNT(FuncInfo),
				nullptr, 0,
				nullptr,
				&StaticCppClassTypeInfo,
				nullptr, 0,
				METADATA_PARAMS(Class_MetaDataParams, ARRAY_COUNT(Class_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUClass(OuterClass, ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ULicenseKeyPluginBP, 2898476048);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ULicenseKeyPluginBP(Z_Construct_UClass_ULicenseKeyPluginBP, &ULicenseKeyPluginBP::StaticClass, TEXT("/Script/LicenseKeyPlugin"), TEXT("ULicenseKeyPluginBP"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ULicenseKeyPluginBP);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
