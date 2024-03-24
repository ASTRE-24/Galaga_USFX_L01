// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Galaga_USFX_L01/InventoryActorMunicion.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeInventoryActorMunicion() {}
// Cross Module References
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_AInventoryActorMunicion_NoRegister();
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_AInventoryActorMunicion();
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_AInventoryActor();
	UPackage* Z_Construct_UPackage__Script_Galaga_USFX_L01();
// End Cross Module References
	void AInventoryActorMunicion::StaticRegisterNativesAInventoryActorMunicion()
	{
	}
	UClass* Z_Construct_UClass_AInventoryActorMunicion_NoRegister()
	{
		return AInventoryActorMunicion::StaticClass();
	}
	struct Z_Construct_UClass_AInventoryActorMunicion_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AInventoryActorMunicion_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AInventoryActor,
		(UObject* (*)())Z_Construct_UPackage__Script_Galaga_USFX_L01,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AInventoryActorMunicion_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Input" },
		{ "IncludePath", "InventoryActorMunicion.h" },
		{ "ModuleRelativePath", "InventoryActorMunicion.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AInventoryActorMunicion_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AInventoryActorMunicion>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AInventoryActorMunicion_Statics::ClassParams = {
		&AInventoryActorMunicion::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_AInventoryActorMunicion_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AInventoryActorMunicion_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AInventoryActorMunicion()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AInventoryActorMunicion_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AInventoryActorMunicion, 1681205322);
	template<> GALAGA_USFX_L01_API UClass* StaticClass<AInventoryActorMunicion>()
	{
		return AInventoryActorMunicion::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AInventoryActorMunicion(Z_Construct_UClass_AInventoryActorMunicion, &AInventoryActorMunicion::StaticClass, TEXT("/Script/Galaga_USFX_L01"), TEXT("AInventoryActorMunicion"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AInventoryActorMunicion);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
