// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "HSPGame/Base2DCharacter.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBase2DCharacter() {}
// Cross Module References
	HSPGAME_API UClass* Z_Construct_UClass_ABase2DCharacter_NoRegister();
	HSPGAME_API UClass* Z_Construct_UClass_ABase2DCharacter();
	PAPER2D_API UClass* Z_Construct_UClass_APaperCharacter();
	UPackage* Z_Construct_UPackage__Script_HSPGame();
	ENGINE_API UClass* Z_Construct_UClass_UMaterial_NoRegister();
	PAPER2D_API UClass* Z_Construct_UClass_UPaperFlipbook_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USphereComponent_NoRegister();
// End Cross Module References
	void ABase2DCharacter::StaticRegisterNativesABase2DCharacter()
	{
	}
	UClass* Z_Construct_UClass_ABase2DCharacter_NoRegister()
	{
		return ABase2DCharacter::StaticClass();
	}
	struct Z_Construct_UClass_ABase2DCharacter_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_defaultMaterial_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_defaultMaterial;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_walkDownAnim_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_walkDownAnim;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_walkForwardAnim_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_walkForwardAnim;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_walkRightAnim_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_walkRightAnim;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_idleAnim_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_idleAnim;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_isTurn_MetaData[];
#endif
		static void NewProp_isTurn_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_isTurn;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_visionSphere_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_visionSphere;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ABase2DCharacter_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APaperCharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_HSPGame,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABase2DCharacter_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Base2DCharacter.h" },
		{ "ModuleRelativePath", "Base2DCharacter.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABase2DCharacter_Statics::NewProp_defaultMaterial_MetaData[] = {
		{ "Category", "SpriteMaterial" },
		{ "ModuleRelativePath", "Base2DCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABase2DCharacter_Statics::NewProp_defaultMaterial = { UE4CodeGen_Private::EPropertyClass::Object, "defaultMaterial", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(ABase2DCharacter, defaultMaterial), Z_Construct_UClass_UMaterial_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ABase2DCharacter_Statics::NewProp_defaultMaterial_MetaData, ARRAY_COUNT(Z_Construct_UClass_ABase2DCharacter_Statics::NewProp_defaultMaterial_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABase2DCharacter_Statics::NewProp_walkDownAnim_MetaData[] = {
		{ "Category", "Animations" },
		{ "ModuleRelativePath", "Base2DCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABase2DCharacter_Statics::NewProp_walkDownAnim = { UE4CodeGen_Private::EPropertyClass::Object, "walkDownAnim", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(ABase2DCharacter, walkDownAnim), Z_Construct_UClass_UPaperFlipbook_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ABase2DCharacter_Statics::NewProp_walkDownAnim_MetaData, ARRAY_COUNT(Z_Construct_UClass_ABase2DCharacter_Statics::NewProp_walkDownAnim_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABase2DCharacter_Statics::NewProp_walkForwardAnim_MetaData[] = {
		{ "Category", "Animations" },
		{ "ModuleRelativePath", "Base2DCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABase2DCharacter_Statics::NewProp_walkForwardAnim = { UE4CodeGen_Private::EPropertyClass::Object, "walkForwardAnim", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(ABase2DCharacter, walkForwardAnim), Z_Construct_UClass_UPaperFlipbook_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ABase2DCharacter_Statics::NewProp_walkForwardAnim_MetaData, ARRAY_COUNT(Z_Construct_UClass_ABase2DCharacter_Statics::NewProp_walkForwardAnim_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABase2DCharacter_Statics::NewProp_walkRightAnim_MetaData[] = {
		{ "Category", "Animations" },
		{ "ModuleRelativePath", "Base2DCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABase2DCharacter_Statics::NewProp_walkRightAnim = { UE4CodeGen_Private::EPropertyClass::Object, "walkRightAnim", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(ABase2DCharacter, walkRightAnim), Z_Construct_UClass_UPaperFlipbook_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ABase2DCharacter_Statics::NewProp_walkRightAnim_MetaData, ARRAY_COUNT(Z_Construct_UClass_ABase2DCharacter_Statics::NewProp_walkRightAnim_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABase2DCharacter_Statics::NewProp_idleAnim_MetaData[] = {
		{ "Category", "Animations" },
		{ "ModuleRelativePath", "Base2DCharacter.h" },
		{ "ToolTip", "Animations for the Class" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABase2DCharacter_Statics::NewProp_idleAnim = { UE4CodeGen_Private::EPropertyClass::Object, "idleAnim", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(ABase2DCharacter, idleAnim), Z_Construct_UClass_UPaperFlipbook_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ABase2DCharacter_Statics::NewProp_idleAnim_MetaData, ARRAY_COUNT(Z_Construct_UClass_ABase2DCharacter_Statics::NewProp_idleAnim_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABase2DCharacter_Statics::NewProp_isTurn_MetaData[] = {
		{ "Category", "Base2DCharacter" },
		{ "ModuleRelativePath", "Base2DCharacter.h" },
	};
#endif
	void Z_Construct_UClass_ABase2DCharacter_Statics::NewProp_isTurn_SetBit(void* Obj)
	{
		((ABase2DCharacter*)Obj)->isTurn = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ABase2DCharacter_Statics::NewProp_isTurn = { UE4CodeGen_Private::EPropertyClass::Bool, "isTurn", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000004, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(ABase2DCharacter), &Z_Construct_UClass_ABase2DCharacter_Statics::NewProp_isTurn_SetBit, METADATA_PARAMS(Z_Construct_UClass_ABase2DCharacter_Statics::NewProp_isTurn_MetaData, ARRAY_COUNT(Z_Construct_UClass_ABase2DCharacter_Statics::NewProp_isTurn_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABase2DCharacter_Statics::NewProp_visionSphere_MetaData[] = {
		{ "Category", "Base2DCharacter" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Base2DCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABase2DCharacter_Statics::NewProp_visionSphere = { UE4CodeGen_Private::EPropertyClass::Object, "visionSphere", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000080009, 1, nullptr, STRUCT_OFFSET(ABase2DCharacter, visionSphere), Z_Construct_UClass_USphereComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ABase2DCharacter_Statics::NewProp_visionSphere_MetaData, ARRAY_COUNT(Z_Construct_UClass_ABase2DCharacter_Statics::NewProp_visionSphere_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ABase2DCharacter_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABase2DCharacter_Statics::NewProp_defaultMaterial,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABase2DCharacter_Statics::NewProp_walkDownAnim,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABase2DCharacter_Statics::NewProp_walkForwardAnim,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABase2DCharacter_Statics::NewProp_walkRightAnim,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABase2DCharacter_Statics::NewProp_idleAnim,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABase2DCharacter_Statics::NewProp_isTurn,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABase2DCharacter_Statics::NewProp_visionSphere,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ABase2DCharacter_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABase2DCharacter>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ABase2DCharacter_Statics::ClassParams = {
		&ABase2DCharacter::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x009000A0u,
		nullptr, 0,
		Z_Construct_UClass_ABase2DCharacter_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_ABase2DCharacter_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_ABase2DCharacter_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_ABase2DCharacter_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ABase2DCharacter()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ABase2DCharacter_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ABase2DCharacter, 2045532878);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ABase2DCharacter(Z_Construct_UClass_ABase2DCharacter, &ABase2DCharacter::StaticClass, TEXT("/Script/HSPGame"), TEXT("ABase2DCharacter"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ABase2DCharacter);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
