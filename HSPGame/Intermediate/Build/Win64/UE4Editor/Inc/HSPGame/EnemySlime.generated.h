// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UPrimitiveComponent;
class AActor;
struct FVector;
struct FHitResult;
#ifdef HSPGAME_EnemySlime_generated_h
#error "EnemySlime.generated.h already included, missing '#pragma once' in EnemySlime.h"
#endif
#define HSPGAME_EnemySlime_generated_h

#define HSPGame_Source_HSPGame_EnemySlime_h_22_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execcharHit) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_HitComponent); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp); \
		P_GET_STRUCT(FVector,Z_Param_NormalImpulse); \
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_Hit); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->charHit(Z_Param_HitComponent,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_NormalImpulse,Z_Param_Out_Hit); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execinSight) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OverlappedComponent); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp); \
		P_GET_PROPERTY(UIntProperty,Z_Param_OtherBodyIndex); \
		P_GET_UBOOL(Z_Param_bFromSweep); \
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_SweepResult); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->inSight(Z_Param_OverlappedComponent,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_OtherBodyIndex,Z_Param_bFromSweep,Z_Param_Out_SweepResult); \
		P_NATIVE_END; \
	}


#define HSPGame_Source_HSPGame_EnemySlime_h_22_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execcharHit) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_HitComponent); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp); \
		P_GET_STRUCT(FVector,Z_Param_NormalImpulse); \
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_Hit); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->charHit(Z_Param_HitComponent,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_NormalImpulse,Z_Param_Out_Hit); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execinSight) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OverlappedComponent); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp); \
		P_GET_PROPERTY(UIntProperty,Z_Param_OtherBodyIndex); \
		P_GET_UBOOL(Z_Param_bFromSweep); \
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_SweepResult); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->inSight(Z_Param_OverlappedComponent,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_OtherBodyIndex,Z_Param_bFromSweep,Z_Param_Out_SweepResult); \
		P_NATIVE_END; \
	}


#define HSPGame_Source_HSPGame_EnemySlime_h_22_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAEnemySlime(); \
	friend struct Z_Construct_UClass_AEnemySlime_Statics; \
public: \
	DECLARE_CLASS(AEnemySlime, AEnemyClass, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/HSPGame"), NO_API) \
	DECLARE_SERIALIZER(AEnemySlime)


#define HSPGame_Source_HSPGame_EnemySlime_h_22_INCLASS \
private: \
	static void StaticRegisterNativesAEnemySlime(); \
	friend struct Z_Construct_UClass_AEnemySlime_Statics; \
public: \
	DECLARE_CLASS(AEnemySlime, AEnemyClass, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/HSPGame"), NO_API) \
	DECLARE_SERIALIZER(AEnemySlime)


#define HSPGame_Source_HSPGame_EnemySlime_h_22_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AEnemySlime(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AEnemySlime) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AEnemySlime); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AEnemySlime); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AEnemySlime(AEnemySlime&&); \
	NO_API AEnemySlime(const AEnemySlime&); \
public:


#define HSPGame_Source_HSPGame_EnemySlime_h_22_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AEnemySlime(AEnemySlime&&); \
	NO_API AEnemySlime(const AEnemySlime&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AEnemySlime); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AEnemySlime); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AEnemySlime)


#define HSPGame_Source_HSPGame_EnemySlime_h_22_PRIVATE_PROPERTY_OFFSET
#define HSPGame_Source_HSPGame_EnemySlime_h_19_PROLOG
#define HSPGame_Source_HSPGame_EnemySlime_h_22_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	HSPGame_Source_HSPGame_EnemySlime_h_22_PRIVATE_PROPERTY_OFFSET \
	HSPGame_Source_HSPGame_EnemySlime_h_22_RPC_WRAPPERS \
	HSPGame_Source_HSPGame_EnemySlime_h_22_INCLASS \
	HSPGame_Source_HSPGame_EnemySlime_h_22_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define HSPGame_Source_HSPGame_EnemySlime_h_22_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	HSPGame_Source_HSPGame_EnemySlime_h_22_PRIVATE_PROPERTY_OFFSET \
	HSPGame_Source_HSPGame_EnemySlime_h_22_RPC_WRAPPERS_NO_PURE_DECLS \
	HSPGame_Source_HSPGame_EnemySlime_h_22_INCLASS_NO_PURE_DECLS \
	HSPGame_Source_HSPGame_EnemySlime_h_22_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID HSPGame_Source_HSPGame_EnemySlime_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
