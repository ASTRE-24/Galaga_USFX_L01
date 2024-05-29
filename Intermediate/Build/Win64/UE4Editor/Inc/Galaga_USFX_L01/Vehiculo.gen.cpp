// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Galaga_USFX_L01/Vehiculo.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVehiculo() {}
// Cross Module References
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_AVehiculo_NoRegister();
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_AVehiculo();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_Galaga_USFX_L01();
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_UActorComponentDisparo_NoRegister();
// End Cross Module References
	void AVehiculo::StaticRegisterNativesAVehiculo()
	{
	}
	UClass* Z_Construct_UClass_AVehiculo_NoRegister()
	{
		return AVehiculo::StaticClass();
	}
	struct Z_Construct_UClass_AVehiculo_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DisparoComponent_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_DisparoComponent;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AVehiculo_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_Galaga_USFX_L01,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVehiculo_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Vehiculo.h" },
		{ "ModuleRelativePath", "Vehiculo.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVehiculo_Statics::NewProp_DisparoComponent_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Disparo" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Vehiculo.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVehiculo_Statics::NewProp_DisparoComponent = { "DisparoComponent", nullptr, (EPropertyFlags)0x00200800000a001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AVehiculo, DisparoComponent), Z_Construct_UClass_UActorComponentDisparo_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AVehiculo_Statics::NewProp_DisparoComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AVehiculo_Statics::NewProp_DisparoComponent_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AVehiculo_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVehiculo_Statics::NewProp_DisparoComponent,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AVehiculo_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AVehiculo>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AVehiculo_Statics::ClassParams = {
		&AVehiculo::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AVehiculo_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AVehiculo_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AVehiculo_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AVehiculo_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AVehiculo()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AVehiculo_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AVehiculo, 1006688143);
	template<> GALAGA_USFX_L01_API UClass* StaticClass<AVehiculo>()
	{
		return AVehiculo::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AVehiculo(Z_Construct_UClass_AVehiculo, &AVehiculo::StaticClass, TEXT("/Script/Galaga_USFX_L01"), TEXT("AVehiculo"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AVehiculo);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
