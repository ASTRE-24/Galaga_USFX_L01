// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Galaga_USFX_L01/EstrategiaEnemigoViolento.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEstrategiaEnemigoViolento() {}
// Cross Module References
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_AEstrategiaEnemigoViolento_NoRegister();
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_AEstrategiaEnemigoViolento();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_Galaga_USFX_L01();
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_UBatallaEstrategy_NoRegister();
// End Cross Module References
	void AEstrategiaEnemigoViolento::StaticRegisterNativesAEstrategiaEnemigoViolento()
	{
	}
	UClass* Z_Construct_UClass_AEstrategiaEnemigoViolento_NoRegister()
	{
		return AEstrategiaEnemigoViolento::StaticClass();
	}
	struct Z_Construct_UClass_AEstrategiaEnemigoViolento_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AEstrategiaEnemigoViolento_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_Galaga_USFX_L01,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEstrategiaEnemigoViolento_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "EstrategiaEnemigoViolento.h" },
		{ "ModuleRelativePath", "EstrategiaEnemigoViolento.h" },
	};
#endif
		const UE4CodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_AEstrategiaEnemigoViolento_Statics::InterfaceParams[] = {
			{ Z_Construct_UClass_UBatallaEstrategy_NoRegister, (int32)VTABLE_OFFSET(AEstrategiaEnemigoViolento, IBatallaEstrategy), false },
		};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AEstrategiaEnemigoViolento_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AEstrategiaEnemigoViolento>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AEstrategiaEnemigoViolento_Statics::ClassParams = {
		&AEstrategiaEnemigoViolento::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_AEstrategiaEnemigoViolento_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AEstrategiaEnemigoViolento_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AEstrategiaEnemigoViolento()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AEstrategiaEnemigoViolento_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AEstrategiaEnemigoViolento, 4171298100);
	template<> GALAGA_USFX_L01_API UClass* StaticClass<AEstrategiaEnemigoViolento>()
	{
		return AEstrategiaEnemigoViolento::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AEstrategiaEnemigoViolento(Z_Construct_UClass_AEstrategiaEnemigoViolento, &AEstrategiaEnemigoViolento::StaticClass, TEXT("/Script/Galaga_USFX_L01"), TEXT("AEstrategiaEnemigoViolento"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AEstrategiaEnemigoViolento);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
