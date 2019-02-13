// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef HSPGAME_EnemyClass_generated_h
#error "EnemyClass.generated.h already included, missing '#pragma once' in EnemyClass.h"
#endif
#define HSPGAME_EnemyClass_generated_h

#define HSPGame_Source_HSPGame_EnemyClass_h_16_RPC_WRAPPERS
#define HSPGame_Source_HSPGame_EnemyClass_h_16_RPC_WRAPPERS_NO_PURE_DECLS
#define HSPGame_Source_HSPGame_EnemyClass_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAEnemyClass(); \
	friend struct Z_Construct_UClass_AEnemyClass_Statics; \
public: \
	DECLARE_CLASS(AEnemyClass, ABase2DCharacter, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/HSPGame"), NO_API) \
	DECLARE_SERIALIZER(AEnemyClass)


#define HSPGame_Source_HSPGame_EnemyClass_h_16_INCLASS \
private: \
	static void StaticRegisterNativesAEnemyClass(); \
	friend struct Z_Construct_UClass_AEnemyClass_Statics; \
public: \
	DECLARE_CLASS(AEnemyClass, ABase2DCharacter, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/HSPGame"), NO_API) \
	DECLARE_SERIALIZER(AEnemyClass)


#define HSPGame_Source_HSPGame_EnemyClass_h_16_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AEnemyClass(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AEnemyClass) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AEnemyClass); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AEnemyClass); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AEnemyClass(AEnemyClass&&); \
	NO_API AEnemyClass(const AEnemyClass&); \
public:


#define HSPGame_Source_HSPGame_EnemyClass_h_16_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AEnemyClass(AEnemyClass&&); \
	NO_API AEnemyClass(const AEnemyClass&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AEnemyClass); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AEnemyClass); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AEnemyClass)


#define HSPGame_Source_HSPGame_EnemyClass_h_16_PRIVATE_PROPERTY_OFFSET
#define HSPGame_Source_HSPGame_EnemyClass_h_13_PROLOG
#define HSPGame_Source_HSPGame_EnemyClass_h_16_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	HSPGame_Source_HSPGame_EnemyClass_h_16_PRIVATE_PROPERTY_OFFSET \
	HSPGame_Source_HSPGame_EnemyClass_h_16_RPC_WRAPPERS \
	HSPGame_Source_HSPGame_EnemyClass_h_16_INCLASS \
	HSPGame_Source_HSPGame_EnemyClass_h_16_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define HSPGame_Source_HSPGame_EnemyClass_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	HSPGame_Source_HSPGame_EnemyClass_h_16_PRIVATE_PROPERTY_OFFSET \
	HSPGame_Source_HSPGame_EnemyClass_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	HSPGame_Source_HSPGame_EnemyClass_h_16_INCLASS_NO_PURE_DECLS \
	HSPGame_Source_HSPGame_EnemyClass_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID HSPGame_Source_HSPGame_EnemyClass_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
