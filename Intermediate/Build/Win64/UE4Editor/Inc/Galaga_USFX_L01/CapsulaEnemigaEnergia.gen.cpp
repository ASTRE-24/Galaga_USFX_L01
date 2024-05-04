// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Galaga_USFX_L01/CapsulaEnemigaEnergia.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCapsulaEnemigaEnergia() {}
// Cross Module References
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_ACapsulaEnemigaEnergia_NoRegister();
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_ACapsulaEnemigaEnergia();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_Galaga_USFX_L01();
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_UMovimientoVertical_NoRegister();
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_UInterfaceCapsulaEnemiga_NoRegister();
// End Cross Module References
	void ACapsulaEnemigaEnergia::StaticRegisterNativesACapsulaEnemigaEnergia()
	{
	}
	UClass* Z_Construct_UClass_ACapsulaEnemigaEnergia_NoRegister()
	{
		return ACapsulaEnemigaEnergia::StaticClass();
	}
	struct Z_Construct_UClass_ACapsulaEnemigaEnergia_Statics
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
	UObject* (*const Z_Construct_UClass_ACapsulaEnemigaEnergia_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_Galaga_USFX_L01,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACapsulaEnemigaEnergia_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "CapsulaEnemigaEnergia.h" },
		{ "ModuleRelativePath", "CapsulaEnemigaEnergia.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACapsulaEnemigaEnergia_Statics::NewProp_MovementComponent_MetaData[] = {
		{ "Category", "Movimiento" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "CapsulaEnemigaEnergia.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACapsulaEnemigaEnergia_Statics::NewProp_MovementComponent = { "MovementComponent", nullptr, (EPropertyFlags)0x00100000000a001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ACapsulaEnemigaEnergia, MovementComponent), Z_Construct_UClass_UMovimientoVertical_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ACapsulaEnemigaEnergia_Statics::NewProp_MovementComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ACapsulaEnemigaEnergia_Statics::NewProp_MovementComponent_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ACapsulaEnemigaEnergia_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACapsulaEnemigaEnergia_Statics::NewProp_MovementComponent,
	};
		const UE4CodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_ACapsulaEnemigaEnergia_Statics::InterfaceParams[] = {
			{ Z_Construct_UClass_UInterfaceCapsulaEnemiga_NoRegister, (int32)VTABLE_OFFSET(ACapsulaEnemigaEnergia, IInterfaceCapsulaEnemiga), false },
		};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ACapsulaEnemigaEnergia_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACapsulaEnemigaEnergia>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ACapsulaEnemigaEnergia_Statics::ClassParams = {
		&ACapsulaEnemigaEnergia::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ACapsulaEnemigaEnergia_Statics::PropPointers,
		InterfaceParams,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_ACapsulaEnemigaEnergia_Statics::PropPointers),
		UE_ARRAY_COUNT(InterfaceParams),
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ACapsulaEnemigaEnergia_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ACapsulaEnemigaEnergia_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ACapsulaEnemigaEnergia()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ACapsulaEnemigaEnergia_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ACapsulaEnemigaEnergia, 1263747454);
	template<> GALAGA_USFX_L01_API UClass* StaticClass<ACapsulaEnemigaEnergia>()
	{
		return ACapsulaEnemigaEnergia::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ACapsulaEnemigaEnergia(Z_Construct_UClass_ACapsulaEnemigaEnergia, &ACapsulaEnemigaEnergia::StaticClass, TEXT("/Script/Galaga_USFX_L01"), TEXT("ACapsulaEnemigaEnergia"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ACapsulaEnemigaEnergia);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
