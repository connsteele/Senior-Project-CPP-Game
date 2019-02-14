// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "HSPGame/EnemyClass.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEnemyClass() {}
// Cross Module References
	HSPGAME_API UClass* Z_Construct_UClass_AEnemyClass_NoRegister();
	HSPGAME_API UClass* Z_Construct_UClass_AEnemyClass();
	HSPGAME_API UClass* Z_Construct_UClass_ABase2DCharacter();
	UPackage* Z_Construct_UPackage__Script_HSPGame();
// End Cross Module References
	void AEnemyClass::StaticRegisterNativesAEnemyClass()
	{
	}
	UClass* Z_Construct_UClass_AEnemyClass_NoRegister()
	{
		return AEnemyClass::StaticClass();
	}
	struct Z_Construct_UClass_AEnemyClass_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AEnemyClass_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ABase2DCharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_HSPGame,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEnemyClass_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "EnemyClass.h" },
		{ "ModuleRelativePath", "EnemyClass.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AEnemyClass_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AEnemyClass>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AEnemyClass_Statics::ClassParams = {
		&AEnemyClass::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x009000A0u,
		nullptr, 0,
		nullptr, 0,
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_AEnemyClass_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AEnemyClass_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AEnemyClass()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AEnemyClass_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AEnemyClass, 1350490064);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AEnemyClass(Z_Construct_UClass_AEnemyClass, &AEnemyClass::StaticClass, TEXT("/Script/HSPGame"), TEXT("AEnemyClass"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AEnemyClass);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
