// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Galaga_USFX_L01/MovimentoNavesEnemigas.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMovimentoNavesEnemigas() {}
// Cross Module References
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_UMovimentoNavesEnemigas_NoRegister();
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_UMovimentoNavesEnemigas();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	UPackage* Z_Construct_UPackage__Script_Galaga_USFX_L01();
// End Cross Module References
	void UMovimentoNavesEnemigas::StaticRegisterNativesUMovimentoNavesEnemigas()
	{
	}
	UClass* Z_Construct_UClass_UMovimentoNavesEnemigas_NoRegister()
	{
		return UMovimentoNavesEnemigas::StaticClass();
	}
	struct Z_Construct_UClass_UMovimentoNavesEnemigas_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UMovimentoNavesEnemigas_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_Galaga_USFX_L01,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMovimentoNavesEnemigas_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "MovimentoNavesEnemigas.h" },
		{ "ModuleRelativePath", "MovimentoNavesEnemigas.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UMovimentoNavesEnemigas_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMovimentoNavesEnemigas>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UMovimentoNavesEnemigas_Statics::ClassParams = {
		&UMovimentoNavesEnemigas::StaticClass,
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
		0x00B000A4u,
		METADATA_PARAMS(Z_Construct_UClass_UMovimentoNavesEnemigas_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UMovimentoNavesEnemigas_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UMovimentoNavesEnemigas()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UMovimentoNavesEnemigas_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UMovimentoNavesEnemigas, 3025556547);
	template<> GALAGA_USFX_L01_API UClass* StaticClass<UMovimentoNavesEnemigas>()
	{
		return UMovimentoNavesEnemigas::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UMovimentoNavesEnemigas(Z_Construct_UClass_UMovimentoNavesEnemigas, &UMovimentoNavesEnemigas::StaticClass, TEXT("/Script/Galaga_USFX_L01"), TEXT("UMovimentoNavesEnemigas"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UMovimentoNavesEnemigas);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
