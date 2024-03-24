// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Galaga_USFX_L01/InventoryActorEnergia.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeInventoryActorEnergia() {}
// Cross Module References
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_AInventoryActorEnergia_NoRegister();
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_AInventoryActorEnergia();
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_AInventoryActor();
	UPackage* Z_Construct_UPackage__Script_Galaga_USFX_L01();
// End Cross Module References
	void AInventoryActorEnergia::StaticRegisterNativesAInventoryActorEnergia()
	{
	}
	UClass* Z_Construct_UClass_AInventoryActorEnergia_NoRegister()
	{
		return AInventoryActorEnergia::StaticClass();
	}
	struct Z_Construct_UClass_AInventoryActorEnergia_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AInventoryActorEnergia_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AInventoryActor,
		(UObject* (*)())Z_Construct_UPackage__Script_Galaga_USFX_L01,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AInventoryActorEnergia_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Input" },
		{ "IncludePath", "InventoryActorEnergia.h" },
		{ "ModuleRelativePath", "InventoryActorEnergia.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AInventoryActorEnergia_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AInventoryActorEnergia>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AInventoryActorEnergia_Statics::ClassParams = {
		&AInventoryActorEnergia::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_AInventoryActorEnergia_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AInventoryActorEnergia_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AInventoryActorEnergia()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AInventoryActorEnergia_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AInventoryActorEnergia, 2230059851);
	template<> GALAGA_USFX_L01_API UClass* StaticClass<AInventoryActorEnergia>()
	{
		return AInventoryActorEnergia::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AInventoryActorEnergia(Z_Construct_UClass_AInventoryActorEnergia, &AInventoryActorEnergia::StaticClass, TEXT("/Script/Galaga_USFX_L01"), TEXT("AInventoryActorEnergia"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AInventoryActorEnergia);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
