// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Galaga_USFX_L01/CapsulaEnemigaMunicion.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCapsulaEnemigaMunicion() {}
// Cross Module References
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_ACapsulaEnemigaMunicion_NoRegister();
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_ACapsulaEnemigaMunicion();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_Galaga_USFX_L01();
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_UMovimientoVertical_NoRegister();
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_UInterfaceCapsulaEnemiga_NoRegister();
// End Cross Module References
	void ACapsulaEnemigaMunicion::StaticRegisterNativesACapsulaEnemigaMunicion()
	{
	}
	UClass* Z_Construct_UClass_ACapsulaEnemigaMunicion_NoRegister()
	{
		return ACapsulaEnemigaMunicion::StaticClass();
	}
	struct Z_Construct_UClass_ACapsulaEnemigaMunicion_Statics
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
		static const UE4CodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ACapsulaEnemigaMunicion_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_Galaga_USFX_L01,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACapsulaEnemigaMunicion_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "CapsulaEnemigaMunicion.h" },
		{ "ModuleRelativePath", "CapsulaEnemigaMunicion.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACapsulaEnemigaMunicion_Statics::NewProp_MovementComponent_MetaData[] = {
		{ "Category", "Movimiento" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "CapsulaEnemigaMunicion.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACapsulaEnemigaMunicion_Statics::NewProp_MovementComponent = { "MovementComponent", nullptr, (EPropertyFlags)0x00100000000a001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ACapsulaEnemigaMunicion, MovementComponent), Z_Construct_UClass_UMovimientoVertical_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ACapsulaEnemigaMunicion_Statics::NewProp_MovementComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ACapsulaEnemigaMunicion_Statics::NewProp_MovementComponent_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ACapsulaEnemigaMunicion_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACapsulaEnemigaMunicion_Statics::NewProp_MovementComponent,
	};
		const UE4CodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_ACapsulaEnemigaMunicion_Statics::InterfaceParams[] = {
			{ Z_Construct_UClass_UInterfaceCapsulaEnemiga_NoRegister, (int32)VTABLE_OFFSET(ACapsulaEnemigaMunicion, IInterfaceCapsulaEnemiga), false },
		};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ACapsulaEnemigaMunicion_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACapsulaEnemigaMunicion>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ACapsulaEnemigaMunicion_Statics::ClassParams = {
		&ACapsulaEnemigaMunicion::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ACapsulaEnemigaMunicion_Statics::PropPointers,
		InterfaceParams,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_ACapsulaEnemigaMunicion_Statics::PropPointers),
		UE_ARRAY_COUNT(InterfaceParams),
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ACapsulaEnemigaMunicion_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ACapsulaEnemigaMunicion_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ACapsulaEnemigaMunicion()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ACapsulaEnemigaMunicion_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ACapsulaEnemigaMunicion, 1559078405);
	template<> GALAGA_USFX_L01_API UClass* StaticClass<ACapsulaEnemigaMunicion>()
	{
		return ACapsulaEnemigaMunicion::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ACapsulaEnemigaMunicion(Z_Construct_UClass_ACapsulaEnemigaMunicion, &ACapsulaEnemigaMunicion::StaticClass, TEXT("/Script/Galaga_USFX_L01"), TEXT("ACapsulaEnemigaMunicion"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ACapsulaEnemigaMunicion);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
