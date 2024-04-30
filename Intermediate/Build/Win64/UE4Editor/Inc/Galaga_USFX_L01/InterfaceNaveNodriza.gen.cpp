// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Galaga_USFX_L01/InterfaceNaveNodriza.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeInterfaceNaveNodriza() {}
// Cross Module References
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_UInterfaceNaveNodriza_NoRegister();
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_UInterfaceNaveNodriza();
	COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
	UPackage* Z_Construct_UPackage__Script_Galaga_USFX_L01();
// End Cross Module References
	void UInterfaceNaveNodriza::StaticRegisterNativesUInterfaceNaveNodriza()
	{
	}
	UClass* Z_Construct_UClass_UInterfaceNaveNodriza_NoRegister()
	{
		return UInterfaceNaveNodriza::StaticClass();
	}
	struct Z_Construct_UClass_UInterfaceNaveNodriza_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UInterfaceNaveNodriza_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UInterface,
		(UObject* (*)())Z_Construct_UPackage__Script_Galaga_USFX_L01,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInterfaceNaveNodriza_Statics::Class_MetaDataParams[] = {
		{ "ModuleRelativePath", "InterfaceNaveNodriza.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UInterfaceNaveNodriza_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<IInterfaceNaveNodriza>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UInterfaceNaveNodriza_Statics::ClassParams = {
		&UInterfaceNaveNodriza::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_UInterfaceNaveNodriza_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UInterfaceNaveNodriza_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UInterfaceNaveNodriza()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UInterfaceNaveNodriza_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UInterfaceNaveNodriza, 3946312086);
	template<> GALAGA_USFX_L01_API UClass* StaticClass<UInterfaceNaveNodriza>()
	{
		return UInterfaceNaveNodriza::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UInterfaceNaveNodriza(Z_Construct_UClass_UInterfaceNaveNodriza, &UInterfaceNaveNodriza::StaticClass, TEXT("/Script/Galaga_USFX_L01"), TEXT("UInterfaceNaveNodriza"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UInterfaceNaveNodriza);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
