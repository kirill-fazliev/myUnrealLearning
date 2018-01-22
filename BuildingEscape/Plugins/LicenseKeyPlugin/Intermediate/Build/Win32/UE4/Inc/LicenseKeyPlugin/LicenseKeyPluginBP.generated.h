// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef LICENSEKEYPLUGIN_LicenseKeyPluginBP_generated_h
#error "LicenseKeyPluginBP.generated.h already included, missing '#pragma once' in LicenseKeyPluginBP.h"
#endif
#define LICENSEKEYPLUGIN_LicenseKeyPluginBP_generated_h

#define HostProject_Plugins_LicenseKeyPlugin_Source_LicenseKeyPlugin_Public_LicenseKeyPluginBP_h_10_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGetBaseDir) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=ULicenseKeyPluginBP::GetBaseDir(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execUpdateLicense) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULicenseKeyPluginBP::UpdateLicense(); \
		P_NATIVE_END; \
	}


#define HostProject_Plugins_LicenseKeyPlugin_Source_LicenseKeyPlugin_Public_LicenseKeyPluginBP_h_10_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetBaseDir) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=ULicenseKeyPluginBP::GetBaseDir(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execUpdateLicense) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULicenseKeyPluginBP::UpdateLicense(); \
		P_NATIVE_END; \
	}


#define HostProject_Plugins_LicenseKeyPlugin_Source_LicenseKeyPlugin_Public_LicenseKeyPluginBP_h_10_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesULicenseKeyPluginBP(); \
	friend LICENSEKEYPLUGIN_API class UClass* Z_Construct_UClass_ULicenseKeyPluginBP(); \
public: \
	DECLARE_CLASS(ULicenseKeyPluginBP, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/LicenseKeyPlugin"), NO_API) \
	DECLARE_SERIALIZER(ULicenseKeyPluginBP) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define HostProject_Plugins_LicenseKeyPlugin_Source_LicenseKeyPlugin_Public_LicenseKeyPluginBP_h_10_INCLASS \
private: \
	static void StaticRegisterNativesULicenseKeyPluginBP(); \
	friend LICENSEKEYPLUGIN_API class UClass* Z_Construct_UClass_ULicenseKeyPluginBP(); \
public: \
	DECLARE_CLASS(ULicenseKeyPluginBP, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/LicenseKeyPlugin"), NO_API) \
	DECLARE_SERIALIZER(ULicenseKeyPluginBP) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define HostProject_Plugins_LicenseKeyPlugin_Source_LicenseKeyPlugin_Public_LicenseKeyPluginBP_h_10_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ULicenseKeyPluginBP(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ULicenseKeyPluginBP) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ULicenseKeyPluginBP); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ULicenseKeyPluginBP); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ULicenseKeyPluginBP(ULicenseKeyPluginBP&&); \
	NO_API ULicenseKeyPluginBP(const ULicenseKeyPluginBP&); \
public:


#define HostProject_Plugins_LicenseKeyPlugin_Source_LicenseKeyPlugin_Public_LicenseKeyPluginBP_h_10_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ULicenseKeyPluginBP(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ULicenseKeyPluginBP(ULicenseKeyPluginBP&&); \
	NO_API ULicenseKeyPluginBP(const ULicenseKeyPluginBP&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ULicenseKeyPluginBP); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ULicenseKeyPluginBP); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ULicenseKeyPluginBP)


#define HostProject_Plugins_LicenseKeyPlugin_Source_LicenseKeyPlugin_Public_LicenseKeyPluginBP_h_10_PRIVATE_PROPERTY_OFFSET
#define HostProject_Plugins_LicenseKeyPlugin_Source_LicenseKeyPlugin_Public_LicenseKeyPluginBP_h_7_PROLOG
#define HostProject_Plugins_LicenseKeyPlugin_Source_LicenseKeyPlugin_Public_LicenseKeyPluginBP_h_10_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	HostProject_Plugins_LicenseKeyPlugin_Source_LicenseKeyPlugin_Public_LicenseKeyPluginBP_h_10_PRIVATE_PROPERTY_OFFSET \
	HostProject_Plugins_LicenseKeyPlugin_Source_LicenseKeyPlugin_Public_LicenseKeyPluginBP_h_10_RPC_WRAPPERS \
	HostProject_Plugins_LicenseKeyPlugin_Source_LicenseKeyPlugin_Public_LicenseKeyPluginBP_h_10_INCLASS \
	HostProject_Plugins_LicenseKeyPlugin_Source_LicenseKeyPlugin_Public_LicenseKeyPluginBP_h_10_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define HostProject_Plugins_LicenseKeyPlugin_Source_LicenseKeyPlugin_Public_LicenseKeyPluginBP_h_10_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	HostProject_Plugins_LicenseKeyPlugin_Source_LicenseKeyPlugin_Public_LicenseKeyPluginBP_h_10_PRIVATE_PROPERTY_OFFSET \
	HostProject_Plugins_LicenseKeyPlugin_Source_LicenseKeyPlugin_Public_LicenseKeyPluginBP_h_10_RPC_WRAPPERS_NO_PURE_DECLS \
	HostProject_Plugins_LicenseKeyPlugin_Source_LicenseKeyPlugin_Public_LicenseKeyPluginBP_h_10_INCLASS_NO_PURE_DECLS \
	HostProject_Plugins_LicenseKeyPlugin_Source_LicenseKeyPlugin_Public_LicenseKeyPluginBP_h_10_ENHANCED_CONSTRUCTORS \
static_assert(false, "Unknown access specifier for GENERATED_BODY() macro in class LicenseKeyPluginBP."); \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID HostProject_Plugins_LicenseKeyPlugin_Source_LicenseKeyPlugin_Public_LicenseKeyPluginBP_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
