// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Galaga_USFX_L01/GameControlAdapter.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGameControlAdapter() {}
// Cross Module References
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_UGameControlAdapter_NoRegister();
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_UGameControlAdapter();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_Galaga_USFX_L01();
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_ULogisticaJuego_NoRegister();
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_UControlLogisticaJuego_NoRegister();
// End Cross Module References
	void UGameControlAdapter::StaticRegisterNativesUGameControlAdapter()
	{
	}
	UClass* Z_Construct_UClass_UGameControlAdapter_NoRegister()
	{
		return UGameControlAdapter::StaticClass();
	}
	struct Z_Construct_UClass_UGameControlAdapter_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ClaseExternaInstance_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ClaseExternaInstance;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UGameControlAdapter_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_Galaga_USFX_L01,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGameControlAdapter_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "GameControlAdapter.h" },
		{ "ModuleRelativePath", "GameControlAdapter.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGameControlAdapter_Statics::NewProp_ClaseExternaInstance_MetaData[] = {
		{ "Comment", "// Variable para almacenar una referencia a la clase externa del controlador de juego\n" },
		{ "ModuleRelativePath", "GameControlAdapter.h" },
		{ "ToolTip", "Variable para almacenar una referencia a la clase externa del controlador de juego" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UGameControlAdapter_Statics::NewProp_ClaseExternaInstance = { "ClaseExternaInstance", nullptr, (EPropertyFlags)0x0040000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UGameControlAdapter, ClaseExternaInstance), Z_Construct_UClass_ULogisticaJuego_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UGameControlAdapter_Statics::NewProp_ClaseExternaInstance_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UGameControlAdapter_Statics::NewProp_ClaseExternaInstance_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UGameControlAdapter_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGameControlAdapter_Statics::NewProp_ClaseExternaInstance,
	};
		const UE4CodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_UGameControlAdapter_Statics::InterfaceParams[] = {
			{ Z_Construct_UClass_UControlLogisticaJuego_NoRegister, (int32)VTABLE_OFFSET(UGameControlAdapter, IControlLogisticaJuego), false },
		};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UGameControlAdapter_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGameControlAdapter>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UGameControlAdapter_Statics::ClassParams = {
		&UGameControlAdapter::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UGameControlAdapter_Statics::PropPointers,
		InterfaceParams,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UGameControlAdapter_Statics::PropPointers),
		UE_ARRAY_COUNT(InterfaceParams),
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UGameControlAdapter_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UGameControlAdapter_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UGameControlAdapter()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UGameControlAdapter_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UGameControlAdapter, 2462746526);
	template<> GALAGA_USFX_L01_API UClass* StaticClass<UGameControlAdapter>()
	{
		return UGameControlAdapter::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UGameControlAdapter(Z_Construct_UClass_UGameControlAdapter, &UGameControlAdapter::StaticClass, TEXT("/Script/Galaga_USFX_L01"), TEXT("UGameControlAdapter"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UGameControlAdapter);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
