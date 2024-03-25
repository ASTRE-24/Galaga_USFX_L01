// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Galaga_USFX_L01/MovimientoVertical.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMovimientoVertical() {}
// Cross Module References
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_UMovimientoVertical_NoRegister();
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_UMovimientoVertical();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	UPackage* Z_Construct_UPackage__Script_Galaga_USFX_L01();
// End Cross Module References
	void UMovimientoVertical::StaticRegisterNativesUMovimientoVertical()
	{
	}
	UClass* Z_Construct_UClass_UMovimientoVertical_NoRegister()
	{
		return UMovimientoVertical::StaticClass();
	}
	struct Z_Construct_UClass_UMovimientoVertical_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MovementRadius_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_MovementRadius;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UMovimientoVertical_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_Galaga_USFX_L01,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMovimientoVertical_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "MovimientoVertical.h" },
		{ "ModuleRelativePath", "MovimientoVertical.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMovimientoVertical_Statics::NewProp_MovementRadius_MetaData[] = {
		{ "ModuleRelativePath", "MovimientoVertical.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UMovimientoVertical_Statics::NewProp_MovementRadius = { "MovementRadius", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UMovimientoVertical, MovementRadius), METADATA_PARAMS(Z_Construct_UClass_UMovimientoVertical_Statics::NewProp_MovementRadius_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UMovimientoVertical_Statics::NewProp_MovementRadius_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UMovimientoVertical_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMovimientoVertical_Statics::NewProp_MovementRadius,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UMovimientoVertical_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMovimientoVertical>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UMovimientoVertical_Statics::ClassParams = {
		&UMovimientoVertical::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UMovimientoVertical_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UMovimientoVertical_Statics::PropPointers),
		0,
		0x00B000A4u,
		METADATA_PARAMS(Z_Construct_UClass_UMovimientoVertical_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UMovimientoVertical_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UMovimientoVertical()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UMovimientoVertical_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UMovimientoVertical, 1427800501);
	template<> GALAGA_USFX_L01_API UClass* StaticClass<UMovimientoVertical>()
	{
		return UMovimientoVertical::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UMovimientoVertical(Z_Construct_UClass_UMovimientoVertical, &UMovimientoVertical::StaticClass, TEXT("/Script/Galaga_USFX_L01"), TEXT("UMovimientoVertical"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UMovimientoVertical);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
