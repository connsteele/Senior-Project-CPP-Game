// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "HSPGame/ProtagClass.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeProtagClass() {}
// Cross Module References
	HSPGAME_API UClass* Z_Construct_UClass_AProtagClass_NoRegister();
	HSPGAME_API UClass* Z_Construct_UClass_AProtagClass();
	HSPGAME_API UClass* Z_Construct_UClass_ABase2DCharacter();
	UPackage* Z_Construct_UPackage__Script_HSPGame();
	ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
// End Cross Module References
	void AProtagClass::StaticRegisterNativesAProtagClass()
	{
	}
	UClass* Z_Construct_UClass_AProtagClass_NoRegister()
	{
		return AProtagClass::StaticClass();
	}
	struct Z_Construct_UClass_AProtagClass_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Camera_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Camera;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CamBoom_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_CamBoom;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AProtagClass_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ABase2DCharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_HSPGame,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AProtagClass_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "ProtagClass.h" },
		{ "ModuleRelativePath", "ProtagClass.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AProtagClass_Statics::NewProp_Camera_MetaData[] = {
		{ "Category", "ProtagClass" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "ProtagClass.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AProtagClass_Statics::NewProp_Camera = { UE4CodeGen_Private::EPropertyClass::Object, "Camera", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000080009, 1, nullptr, STRUCT_OFFSET(AProtagClass, Camera), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AProtagClass_Statics::NewProp_Camera_MetaData, ARRAY_COUNT(Z_Construct_UClass_AProtagClass_Statics::NewProp_Camera_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AProtagClass_Statics::NewProp_CamBoom_MetaData[] = {
		{ "Category", "ProtagClass" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "ProtagClass.h" },
		{ "ToolTip", "UPROPERTY(EditAnywhere)\n               UStaticMeshComponent * MyMesh;" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AProtagClass_Statics::NewProp_CamBoom = { UE4CodeGen_Private::EPropertyClass::Object, "CamBoom", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000080009, 1, nullptr, STRUCT_OFFSET(AProtagClass, CamBoom), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AProtagClass_Statics::NewProp_CamBoom_MetaData, ARRAY_COUNT(Z_Construct_UClass_AProtagClass_Statics::NewProp_CamBoom_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AProtagClass_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AProtagClass_Statics::NewProp_Camera,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AProtagClass_Statics::NewProp_CamBoom,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AProtagClass_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AProtagClass>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AProtagClass_Statics::ClassParams = {
		&AProtagClass::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x009000A0u,
		nullptr, 0,
		Z_Construct_UClass_AProtagClass_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_AProtagClass_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_AProtagClass_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AProtagClass_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AProtagClass()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AProtagClass_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AProtagClass, 3641658110);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AProtagClass(Z_Construct_UClass_AProtagClass, &AProtagClass::StaticClass, TEXT("/Script/HSPGame"), TEXT("AProtagClass"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AProtagClass);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
