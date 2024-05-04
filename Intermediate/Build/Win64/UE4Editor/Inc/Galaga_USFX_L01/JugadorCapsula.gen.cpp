// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Galaga_USFX_L01/JugadorCapsula.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeJugadorCapsula() {}
// Cross Module References
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_AJugadorCapsula_NoRegister();
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_AJugadorCapsula();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_Galaga_USFX_L01();
// End Cross Module References
	void AJugadorCapsula::StaticRegisterNativesAJugadorCapsula()
	{
	}
	UClass* Z_Construct_UClass_AJugadorCapsula_NoRegister()
	{
		return AJugadorCapsula::StaticClass();
	}
	struct Z_Construct_UClass_AJugadorCapsula_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AJugadorCapsula_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_Galaga_USFX_L01,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AJugadorCapsula_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "JugadorCapsula.h" },
		{ "ModuleRelativePath", "JugadorCapsula.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AJugadorCapsula_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AJugadorCapsula>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AJugadorCapsula_Statics::ClassParams = {
		&AJugadorCapsula::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_AJugadorCapsula_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AJugadorCapsula_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AJugadorCapsula()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AJugadorCapsula_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AJugadorCapsula, 36282172);
	template<> GALAGA_USFX_L01_API UClass* StaticClass<AJugadorCapsula>()
	{
		return AJugadorCapsula::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AJugadorCapsula(Z_Construct_UClass_AJugadorCapsula, &AJugadorCapsula::StaticClass, TEXT("/Script/Galaga_USFX_L01"), TEXT("AJugadorCapsula"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AJugadorCapsula);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
