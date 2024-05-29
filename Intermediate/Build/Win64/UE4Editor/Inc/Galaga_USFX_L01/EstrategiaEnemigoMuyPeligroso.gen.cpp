// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Galaga_USFX_L01/EstrategiaEnemigoMuyPeligroso.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEstrategiaEnemigoMuyPeligroso() {}
// Cross Module References
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_AEstrategiaEnemigoMuyPeligroso_NoRegister();
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_AEstrategiaEnemigoMuyPeligroso();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_Galaga_USFX_L01();
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_UBatallaEstrategy_NoRegister();
// End Cross Module References
	void AEstrategiaEnemigoMuyPeligroso::StaticRegisterNativesAEstrategiaEnemigoMuyPeligroso()
	{
	}
	UClass* Z_Construct_UClass_AEstrategiaEnemigoMuyPeligroso_NoRegister()
	{
		return AEstrategiaEnemigoMuyPeligroso::StaticClass();
	}
	struct Z_Construct_UClass_AEstrategiaEnemigoMuyPeligroso_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AEstrategiaEnemigoMuyPeligroso_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_Galaga_USFX_L01,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEstrategiaEnemigoMuyPeligroso_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "EstrategiaEnemigoMuyPeligroso.h" },
		{ "ModuleRelativePath", "EstrategiaEnemigoMuyPeligroso.h" },
	};
#endif
		const UE4CodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_AEstrategiaEnemigoMuyPeligroso_Statics::InterfaceParams[] = {
			{ Z_Construct_UClass_UBatallaEstrategy_NoRegister, (int32)VTABLE_OFFSET(AEstrategiaEnemigoMuyPeligroso, IBatallaEstrategy), false },
		};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AEstrategiaEnemigoMuyPeligroso_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AEstrategiaEnemigoMuyPeligroso>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AEstrategiaEnemigoMuyPeligroso_Statics::ClassParams = {
		&AEstrategiaEnemigoMuyPeligroso::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_AEstrategiaEnemigoMuyPeligroso_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AEstrategiaEnemigoMuyPeligroso_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AEstrategiaEnemigoMuyPeligroso()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AEstrategiaEnemigoMuyPeligroso_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AEstrategiaEnemigoMuyPeligroso, 1051133593);
	template<> GALAGA_USFX_L01_API UClass* StaticClass<AEstrategiaEnemigoMuyPeligroso>()
	{
		return AEstrategiaEnemigoMuyPeligroso::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AEstrategiaEnemigoMuyPeligroso(Z_Construct_UClass_AEstrategiaEnemigoMuyPeligroso, &AEstrategiaEnemigoMuyPeligroso::StaticClass, TEXT("/Script/Galaga_USFX_L01"), TEXT("AEstrategiaEnemigoMuyPeligroso"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AEstrategiaEnemigoMuyPeligroso);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
