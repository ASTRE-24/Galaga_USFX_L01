// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Galaga_USFX_L01/Movimientocapsulasvehiculo.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMovimientocapsulasvehiculo() {}
// Cross Module References
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_UMovimientocapsulasvehiculo_NoRegister();
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_UMovimientocapsulasvehiculo();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	UPackage* Z_Construct_UPackage__Script_Galaga_USFX_L01();
// End Cross Module References
	void UMovimientocapsulasvehiculo::StaticRegisterNativesUMovimientocapsulasvehiculo()
	{
	}
	UClass* Z_Construct_UClass_UMovimientocapsulasvehiculo_NoRegister()
	{
		return UMovimientocapsulasvehiculo::StaticClass();
	}
	struct Z_Construct_UClass_UMovimientocapsulasvehiculo_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UMovimientocapsulasvehiculo_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_Galaga_USFX_L01,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMovimientocapsulasvehiculo_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "Movimientocapsulasvehiculo.h" },
		{ "ModuleRelativePath", "Movimientocapsulasvehiculo.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UMovimientocapsulasvehiculo_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMovimientocapsulasvehiculo>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UMovimientocapsulasvehiculo_Statics::ClassParams = {
		&UMovimientocapsulasvehiculo::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_UMovimientocapsulasvehiculo_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UMovimientocapsulasvehiculo_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UMovimientocapsulasvehiculo()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UMovimientocapsulasvehiculo_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UMovimientocapsulasvehiculo, 4076749208);
	template<> GALAGA_USFX_L01_API UClass* StaticClass<UMovimientocapsulasvehiculo>()
	{
		return UMovimientocapsulasvehiculo::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UMovimientocapsulasvehiculo(Z_Construct_UClass_UMovimientocapsulasvehiculo, &UMovimientocapsulasvehiculo::StaticClass, TEXT("/Script/Galaga_USFX_L01"), TEXT("UMovimientocapsulasvehiculo"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UMovimientocapsulasvehiculo);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
