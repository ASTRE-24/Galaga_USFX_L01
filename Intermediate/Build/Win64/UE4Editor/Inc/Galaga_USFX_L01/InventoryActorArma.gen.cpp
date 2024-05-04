// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Galaga_USFX_L01/InventoryActorArma.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeInventoryActorArma() {}
// Cross Module References
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_AInventoryActorArma_NoRegister();
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_AInventoryActorArma();
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_AInventoryActor();
	UPackage* Z_Construct_UPackage__Script_Galaga_USFX_L01();
// End Cross Module References
	void AInventoryActorArma::StaticRegisterNativesAInventoryActorArma()
	{
	}
	UClass* Z_Construct_UClass_AInventoryActorArma_NoRegister()
	{
		return AInventoryActorArma::StaticClass();
	}
	struct Z_Construct_UClass_AInventoryActorArma_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AInventoryActorArma_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AInventoryActor,
		(UObject* (*)())Z_Construct_UPackage__Script_Galaga_USFX_L01,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AInventoryActorArma_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Input" },
		{ "IncludePath", "InventoryActorArma.h" },
		{ "ModuleRelativePath", "InventoryActorArma.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AInventoryActorArma_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AInventoryActorArma>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AInventoryActorArma_Statics::ClassParams = {
		&AInventoryActorArma::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_AInventoryActorArma_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AInventoryActorArma_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AInventoryActorArma()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AInventoryActorArma_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AInventoryActorArma, 4096043394);
	template<> GALAGA_USFX_L01_API UClass* StaticClass<AInventoryActorArma>()
	{
		return AInventoryActorArma::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AInventoryActorArma(Z_Construct_UClass_AInventoryActorArma, &AInventoryActorArma::StaticClass, TEXT("/Script/Galaga_USFX_L01"), TEXT("AInventoryActorArma"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AInventoryActorArma);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
