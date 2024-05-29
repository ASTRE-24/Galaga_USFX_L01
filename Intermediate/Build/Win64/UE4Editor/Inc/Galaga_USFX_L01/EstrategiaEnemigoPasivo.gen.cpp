// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Galaga_USFX_L01/EstrategiaEnemigoPasivo.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEstrategiaEnemigoPasivo() {}
// Cross Module References
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_AEstrategiaEnemigoPasivo_NoRegister();
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_AEstrategiaEnemigoPasivo();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_Galaga_USFX_L01();
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_UBatallaEstrategy_NoRegister();
// End Cross Module References
	void AEstrategiaEnemigoPasivo::StaticRegisterNativesAEstrategiaEnemigoPasivo()
	{
	}
	UClass* Z_Construct_UClass_AEstrategiaEnemigoPasivo_NoRegister()
	{
		return AEstrategiaEnemigoPasivo::StaticClass();
	}
	struct Z_Construct_UClass_AEstrategiaEnemigoPasivo_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AEstrategiaEnemigoPasivo_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_Galaga_USFX_L01,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEstrategiaEnemigoPasivo_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "EstrategiaEnemigoPasivo.h" },
		{ "ModuleRelativePath", "EstrategiaEnemigoPasivo.h" },
	};
#endif
		const UE4CodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_AEstrategiaEnemigoPasivo_Statics::InterfaceParams[] = {
			{ Z_Construct_UClass_UBatallaEstrategy_NoRegister, (int32)VTABLE_OFFSET(AEstrategiaEnemigoPasivo, IBatallaEstrategy), false },
		};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AEstrategiaEnemigoPasivo_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AEstrategiaEnemigoPasivo>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AEstrategiaEnemigoPasivo_Statics::ClassParams = {
		&AEstrategiaEnemigoPasivo::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_AEstrategiaEnemigoPasivo_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AEstrategiaEnemigoPasivo_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AEstrategiaEnemigoPasivo()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AEstrategiaEnemigoPasivo_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AEstrategiaEnemigoPasivo, 361021053);
	template<> GALAGA_USFX_L01_API UClass* StaticClass<AEstrategiaEnemigoPasivo>()
	{
		return AEstrategiaEnemigoPasivo::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AEstrategiaEnemigoPasivo(Z_Construct_UClass_AEstrategiaEnemigoPasivo, &AEstrategiaEnemigoPasivo::StaticClass, TEXT("/Script/Galaga_USFX_L01"), TEXT("AEstrategiaEnemigoPasivo"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AEstrategiaEnemigoPasivo);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
