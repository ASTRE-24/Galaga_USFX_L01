// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Galaga_USFX_L01/EnemigoCapsula.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEnemigoCapsula() {}
// Cross Module References
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_AEnemigoCapsula_NoRegister();
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_AEnemigoCapsula();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_Galaga_USFX_L01();
// End Cross Module References
	void AEnemigoCapsula::StaticRegisterNativesAEnemigoCapsula()
	{
	}
	UClass* Z_Construct_UClass_AEnemigoCapsula_NoRegister()
	{
		return AEnemigoCapsula::StaticClass();
	}
	struct Z_Construct_UClass_AEnemigoCapsula_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AEnemigoCapsula_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_Galaga_USFX_L01,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEnemigoCapsula_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "EnemigoCapsula.h" },
		{ "ModuleRelativePath", "EnemigoCapsula.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AEnemigoCapsula_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AEnemigoCapsula>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AEnemigoCapsula_Statics::ClassParams = {
		&AEnemigoCapsula::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AEnemigoCapsula_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AEnemigoCapsula_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AEnemigoCapsula()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AEnemigoCapsula_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AEnemigoCapsula, 1571544867);
	template<> GALAGA_USFX_L01_API UClass* StaticClass<AEnemigoCapsula>()
	{
		return AEnemigoCapsula::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AEnemigoCapsula(Z_Construct_UClass_AEnemigoCapsula, &AEnemigoCapsula::StaticClass, TEXT("/Script/Galaga_USFX_L01"), TEXT("AEnemigoCapsula"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AEnemigoCapsula);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
