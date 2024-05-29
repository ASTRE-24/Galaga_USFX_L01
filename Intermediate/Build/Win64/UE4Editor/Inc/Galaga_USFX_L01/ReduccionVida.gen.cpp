// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Galaga_USFX_L01/ReduccionVida.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeReduccionVida() {}
// Cross Module References
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_AReduccionVida_NoRegister();
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_AReduccionVida();
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_ANotificador();
	UPackage* Z_Construct_UPackage__Script_Galaga_USFX_L01();
// End Cross Module References
	void AReduccionVida::StaticRegisterNativesAReduccionVida()
	{
	}
	UClass* Z_Construct_UClass_AReduccionVida_NoRegister()
	{
		return AReduccionVida::StaticClass();
	}
	struct Z_Construct_UClass_AReduccionVida_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AReduccionVida_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ANotificador,
		(UObject* (*)())Z_Construct_UPackage__Script_Galaga_USFX_L01,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AReduccionVida_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "ReduccionVida.h" },
		{ "ModuleRelativePath", "ReduccionVida.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AReduccionVida_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AReduccionVida>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AReduccionVida_Statics::ClassParams = {
		&AReduccionVida::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_AReduccionVida_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AReduccionVida_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AReduccionVida()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AReduccionVida_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AReduccionVida, 3408298475);
	template<> GALAGA_USFX_L01_API UClass* StaticClass<AReduccionVida>()
	{
		return AReduccionVida::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AReduccionVida(Z_Construct_UClass_AReduccionVida, &AReduccionVida::StaticClass, TEXT("/Script/Galaga_USFX_L01"), TEXT("AReduccionVida"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AReduccionVida);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
