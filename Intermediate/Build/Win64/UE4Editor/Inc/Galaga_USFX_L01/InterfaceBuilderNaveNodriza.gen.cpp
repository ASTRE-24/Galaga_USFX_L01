// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Galaga_USFX_L01/InterfaceBuilderNaveNodriza.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeInterfaceBuilderNaveNodriza() {}
// Cross Module References
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_UInterfaceBuilderNaveNodriza_NoRegister();
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_UInterfaceBuilderNaveNodriza();
	COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
	UPackage* Z_Construct_UPackage__Script_Galaga_USFX_L01();
// End Cross Module References
	void UInterfaceBuilderNaveNodriza::StaticRegisterNativesUInterfaceBuilderNaveNodriza()
	{
	}
	UClass* Z_Construct_UClass_UInterfaceBuilderNaveNodriza_NoRegister()
	{
		return UInterfaceBuilderNaveNodriza::StaticClass();
	}
	struct Z_Construct_UClass_UInterfaceBuilderNaveNodriza_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UInterfaceBuilderNaveNodriza_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UInterface,
		(UObject* (*)())Z_Construct_UPackage__Script_Galaga_USFX_L01,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInterfaceBuilderNaveNodriza_Statics::Class_MetaDataParams[] = {
		{ "ModuleRelativePath", "InterfaceBuilderNaveNodriza.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UInterfaceBuilderNaveNodriza_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<IInterfaceBuilderNaveNodriza>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UInterfaceBuilderNaveNodriza_Statics::ClassParams = {
		&UInterfaceBuilderNaveNodriza::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x000840A1u,
		METADATA_PARAMS(Z_Construct_UClass_UInterfaceBuilderNaveNodriza_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UInterfaceBuilderNaveNodriza_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UInterfaceBuilderNaveNodriza()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UInterfaceBuilderNaveNodriza_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UInterfaceBuilderNaveNodriza, 76287437);
	template<> GALAGA_USFX_L01_API UClass* StaticClass<UInterfaceBuilderNaveNodriza>()
	{
		return UInterfaceBuilderNaveNodriza::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UInterfaceBuilderNaveNodriza(Z_Construct_UClass_UInterfaceBuilderNaveNodriza, &UInterfaceBuilderNaveNodriza::StaticClass, TEXT("/Script/Galaga_USFX_L01"), TEXT("UInterfaceBuilderNaveNodriza"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UInterfaceBuilderNaveNodriza);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
