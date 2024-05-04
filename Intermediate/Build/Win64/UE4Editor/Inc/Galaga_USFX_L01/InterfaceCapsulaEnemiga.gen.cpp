// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Galaga_USFX_L01/InterfaceCapsulaEnemiga.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeInterfaceCapsulaEnemiga() {}
// Cross Module References
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_UInterfaceCapsulaEnemiga_NoRegister();
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_UInterfaceCapsulaEnemiga();
	COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
	UPackage* Z_Construct_UPackage__Script_Galaga_USFX_L01();
// End Cross Module References
	void UInterfaceCapsulaEnemiga::StaticRegisterNativesUInterfaceCapsulaEnemiga()
	{
	}
	UClass* Z_Construct_UClass_UInterfaceCapsulaEnemiga_NoRegister()
	{
		return UInterfaceCapsulaEnemiga::StaticClass();
	}
	struct Z_Construct_UClass_UInterfaceCapsulaEnemiga_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UInterfaceCapsulaEnemiga_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UInterface,
		(UObject* (*)())Z_Construct_UPackage__Script_Galaga_USFX_L01,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInterfaceCapsulaEnemiga_Statics::Class_MetaDataParams[] = {
		{ "ModuleRelativePath", "InterfaceCapsulaEnemiga.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UInterfaceCapsulaEnemiga_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<IInterfaceCapsulaEnemiga>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UInterfaceCapsulaEnemiga_Statics::ClassParams = {
		&UInterfaceCapsulaEnemiga::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_UInterfaceCapsulaEnemiga_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UInterfaceCapsulaEnemiga_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UInterfaceCapsulaEnemiga()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UInterfaceCapsulaEnemiga_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UInterfaceCapsulaEnemiga, 879444153);
	template<> GALAGA_USFX_L01_API UClass* StaticClass<UInterfaceCapsulaEnemiga>()
	{
		return UInterfaceCapsulaEnemiga::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UInterfaceCapsulaEnemiga(Z_Construct_UClass_UInterfaceCapsulaEnemiga, &UInterfaceCapsulaEnemiga::StaticClass, TEXT("/Script/Galaga_USFX_L01"), TEXT("UInterfaceCapsulaEnemiga"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UInterfaceCapsulaEnemiga);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
