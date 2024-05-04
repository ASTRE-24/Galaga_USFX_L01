// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Galaga_USFX_L01/CapsulaEnemigaArma.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCapsulaEnemigaArma() {}
// Cross Module References
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_ACapsulaEnemigaArma_NoRegister();
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_ACapsulaEnemigaArma();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_Galaga_USFX_L01();
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_UMovimientoVertical_NoRegister();
// End Cross Module References
	void ACapsulaEnemigaArma::StaticRegisterNativesACapsulaEnemigaArma()
	{
	}
	UClass* Z_Construct_UClass_ACapsulaEnemigaArma_NoRegister()
	{
		return ACapsulaEnemigaArma::StaticClass();
	}
	struct Z_Construct_UClass_ACapsulaEnemigaArma_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MovementComponent_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_MovementComponent;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ACapsulaEnemigaArma_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_Galaga_USFX_L01,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACapsulaEnemigaArma_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "CapsulaEnemigaArma.h" },
		{ "ModuleRelativePath", "CapsulaEnemigaArma.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACapsulaEnemigaArma_Statics::NewProp_MovementComponent_MetaData[] = {
		{ "Category", "Movimiento" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "CapsulaEnemigaArma.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACapsulaEnemigaArma_Statics::NewProp_MovementComponent = { "MovementComponent", nullptr, (EPropertyFlags)0x00100000000a001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ACapsulaEnemigaArma, MovementComponent), Z_Construct_UClass_UMovimientoVertical_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ACapsulaEnemigaArma_Statics::NewProp_MovementComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ACapsulaEnemigaArma_Statics::NewProp_MovementComponent_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ACapsulaEnemigaArma_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACapsulaEnemigaArma_Statics::NewProp_MovementComponent,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ACapsulaEnemigaArma_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACapsulaEnemigaArma>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ACapsulaEnemigaArma_Statics::ClassParams = {
		&ACapsulaEnemigaArma::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ACapsulaEnemigaArma_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_ACapsulaEnemigaArma_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ACapsulaEnemigaArma_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ACapsulaEnemigaArma_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ACapsulaEnemigaArma()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ACapsulaEnemigaArma_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ACapsulaEnemigaArma, 2938412729);
	template<> GALAGA_USFX_L01_API UClass* StaticClass<ACapsulaEnemigaArma>()
	{
		return ACapsulaEnemigaArma::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ACapsulaEnemigaArma(Z_Construct_UClass_ACapsulaEnemigaArma, &ACapsulaEnemigaArma::StaticClass, TEXT("/Script/Galaga_USFX_L01"), TEXT("ACapsulaEnemigaArma"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ACapsulaEnemigaArma);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
