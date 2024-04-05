// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Galaga_USFX_L01/ActorSpawnerComponent.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeActorSpawnerComponent() {}
// Cross Module References
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_UActorSpawnerComponent_NoRegister();
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_UActorSpawnerComponent();
	ENGINE_API UClass* Z_Construct_UClass_USceneComponent();
	UPackage* Z_Construct_UPackage__Script_Galaga_USFX_L01();
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_AEscudo_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(UActorSpawnerComponent::execSpawnEscudo)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SpawnEscudo();
		P_NATIVE_END;
	}
	void UActorSpawnerComponent::StaticRegisterNativesUActorSpawnerComponent()
	{
		UClass* Class = UActorSpawnerComponent::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "SpawnEscudo", &UActorSpawnerComponent::execSpawnEscudo },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UActorSpawnerComponent_SpawnEscudo_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UActorSpawnerComponent_SpawnEscudo_Statics::Function_MetaDataParams[] = {
		{ "Category", "Cookbook" },
		{ "Comment", "//Generar? un actor cuando se lo llame\n" },
		{ "ModuleRelativePath", "ActorSpawnerComponent.h" },
		{ "ToolTip", "Generar? un actor cuando se lo llame" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UActorSpawnerComponent_SpawnEscudo_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UActorSpawnerComponent, nullptr, "SpawnEscudo", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UActorSpawnerComponent_SpawnEscudo_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UActorSpawnerComponent_SpawnEscudo_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UActorSpawnerComponent_SpawnEscudo()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UActorSpawnerComponent_SpawnEscudo_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UActorSpawnerComponent_NoRegister()
	{
		return UActorSpawnerComponent::StaticClass();
	}
	struct Z_Construct_UClass_UActorSpawnerComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ActorToSpawn_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ActorToSpawn;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UActorSpawnerComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_USceneComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_Galaga_USFX_L01,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UActorSpawnerComponent_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UActorSpawnerComponent_SpawnEscudo, "SpawnEscudo" }, // 2416950101
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UActorSpawnerComponent_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "HideCategories", "Trigger PhysicsVolume" },
		{ "IncludePath", "ActorSpawnerComponent.h" },
		{ "ModuleRelativePath", "ActorSpawnerComponent.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UActorSpawnerComponent_Statics::NewProp_ActorToSpawn_MetaData[] = {
		{ "Category", "ActorSpawnerComponent" },
		{ "ModuleRelativePath", "ActorSpawnerComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UActorSpawnerComponent_Statics::NewProp_ActorToSpawn = { "ActorToSpawn", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UActorSpawnerComponent, ActorToSpawn), Z_Construct_UClass_AEscudo_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UActorSpawnerComponent_Statics::NewProp_ActorToSpawn_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UActorSpawnerComponent_Statics::NewProp_ActorToSpawn_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UActorSpawnerComponent_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UActorSpawnerComponent_Statics::NewProp_ActorToSpawn,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UActorSpawnerComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UActorSpawnerComponent>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UActorSpawnerComponent_Statics::ClassParams = {
		&UActorSpawnerComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UActorSpawnerComponent_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UActorSpawnerComponent_Statics::PropPointers),
		0,
		0x00B000A4u,
		METADATA_PARAMS(Z_Construct_UClass_UActorSpawnerComponent_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UActorSpawnerComponent_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UActorSpawnerComponent()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UActorSpawnerComponent_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UActorSpawnerComponent, 1978334852);
	template<> GALAGA_USFX_L01_API UClass* StaticClass<UActorSpawnerComponent>()
	{
		return UActorSpawnerComponent::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UActorSpawnerComponent(Z_Construct_UClass_UActorSpawnerComponent, &UActorSpawnerComponent::StaticClass, TEXT("/Script/Galaga_USFX_L01"), TEXT("UActorSpawnerComponent"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UActorSpawnerComponent);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
