// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Galaga_USFX_L01/SolicitudDeNavesInformante.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSolicitudDeNavesInformante() {}
// Cross Module References
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_ASolicitudDeNavesInformante_NoRegister();
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_ASolicitudDeNavesInformante();
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_ASolicitudDeNaves();
	UPackage* Z_Construct_UPackage__Script_Galaga_USFX_L01();
// End Cross Module References
	void ASolicitudDeNavesInformante::StaticRegisterNativesASolicitudDeNavesInformante()
	{
	}
	UClass* Z_Construct_UClass_ASolicitudDeNavesInformante_NoRegister()
	{
		return ASolicitudDeNavesInformante::StaticClass();
	}
	struct Z_Construct_UClass_ASolicitudDeNavesInformante_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ASolicitudDeNavesInformante_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ASolicitudDeNaves,
		(UObject* (*)())Z_Construct_UPackage__Script_Galaga_USFX_L01,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASolicitudDeNavesInformante_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "SolicitudDeNavesInformante.h" },
		{ "ModuleRelativePath", "SolicitudDeNavesInformante.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASolicitudDeNavesInformante_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASolicitudDeNavesInformante>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ASolicitudDeNavesInformante_Statics::ClassParams = {
		&ASolicitudDeNavesInformante::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_ASolicitudDeNavesInformante_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ASolicitudDeNavesInformante_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ASolicitudDeNavesInformante()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ASolicitudDeNavesInformante_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ASolicitudDeNavesInformante, 26882754);
	template<> GALAGA_USFX_L01_API UClass* StaticClass<ASolicitudDeNavesInformante>()
	{
		return ASolicitudDeNavesInformante::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ASolicitudDeNavesInformante(Z_Construct_UClass_ASolicitudDeNavesInformante, &ASolicitudDeNavesInformante::StaticClass, TEXT("/Script/Galaga_USFX_L01"), TEXT("ASolicitudDeNavesInformante"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASolicitudDeNavesInformante);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
