// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Galaga_USFX_L01/EstrategiaEnemigoAgresivo.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEstrategiaEnemigoAgresivo() {}
// Cross Module References
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_AEstrategiaEnemigoAgresivo_NoRegister();
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_AEstrategiaEnemigoAgresivo();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_Galaga_USFX_L01();
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_UBatallaEstrategy_NoRegister();
// End Cross Module References
	void AEstrategiaEnemigoAgresivo::StaticRegisterNativesAEstrategiaEnemigoAgresivo()
	{
	}
	UClass* Z_Construct_UClass_AEstrategiaEnemigoAgresivo_NoRegister()
	{
		return AEstrategiaEnemigoAgresivo::StaticClass();
	}
	struct Z_Construct_UClass_AEstrategiaEnemigoAgresivo_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AEstrategiaEnemigoAgresivo_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_Galaga_USFX_L01,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEstrategiaEnemigoAgresivo_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "EstrategiaEnemigoAgresivo.h" },
		{ "ModuleRelativePath", "EstrategiaEnemigoAgresivo.h" },
	};
#endif
		const UE4CodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_AEstrategiaEnemigoAgresivo_Statics::InterfaceParams[] = {
			{ Z_Construct_UClass_UBatallaEstrategy_NoRegister, (int32)VTABLE_OFFSET(AEstrategiaEnemigoAgresivo, IBatallaEstrategy), false },
		};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AEstrategiaEnemigoAgresivo_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AEstrategiaEnemigoAgresivo>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AEstrategiaEnemigoAgresivo_Statics::ClassParams = {
		&AEstrategiaEnemigoAgresivo::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		InterfaceParams,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		UE_ARRAY_COUNT(InterfaceParams),
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AEstrategiaEnemigoAgresivo_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AEstrategiaEnemigoAgresivo_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AEstrategiaEnemigoAgresivo()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AEstrategiaEnemigoAgresivo_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AEstrategiaEnemigoAgresivo, 748910546);
	template<> GALAGA_USFX_L01_API UClass* StaticClass<AEstrategiaEnemigoAgresivo>()
	{
		return AEstrategiaEnemigoAgresivo::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AEstrategiaEnemigoAgresivo(Z_Construct_UClass_AEstrategiaEnemigoAgresivo, &AEstrategiaEnemigoAgresivo::StaticClass, TEXT("/Script/Galaga_USFX_L01"), TEXT("AEstrategiaEnemigoAgresivo"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AEstrategiaEnemigoAgresivo);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
