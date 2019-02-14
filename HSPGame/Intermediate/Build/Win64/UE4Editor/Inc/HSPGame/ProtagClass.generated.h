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
struct FHitResult;
struct FVector;
#ifdef HSPGAME_ProtagClass_generated_h
#error "ProtagClass.generated.h already included, missing '#pragma once' in ProtagClass.h"
#endif
#define HSPGAME_ProtagClass_generated_h

#define HSPGame_Source_HSPGame_ProtagClass_h_24_RPC_WRAPPERS \
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
	} \
 \
	DECLARE_FUNCTION(execprotagHit) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_HitComponent); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp); \
		P_GET_STRUCT(FVector,Z_Param_NormalImpulse); \
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_Hit); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->protagHit(Z_Param_HitComponent,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_NormalImpulse,Z_Param_Out_Hit); \
		P_NATIVE_END; \
	}


#define HSPGame_Source_HSPGame_ProtagClass_h_24_RPC_WRAPPERS_NO_PURE_DECLS \
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
	} \
 \
	DECLARE_FUNCTION(execprotagHit) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_HitComponent); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp); \
		P_GET_STRUCT(FVector,Z_Param_NormalImpulse); \
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_Hit); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->protagHit(Z_Param_HitComponent,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_NormalImpulse,Z_Param_Out_Hit); \
		P_NATIVE_END; \
	}


#define HSPGame_Source_HSPGame_ProtagClass_h_24_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAProtagClass(); \
	friend struct Z_Construct_UClass_AProtagClass_Statics; \
public: \
	DECLARE_CLASS(AProtagClass, ABase2DCharacter, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/HSPGame"), NO_API) \
	DECLARE_SERIALIZER(AProtagClass)


#define HSPGame_Source_HSPGame_ProtagClass_h_24_INCLASS \
private: \
	static void StaticRegisterNativesAProtagClass(); \
	friend struct Z_Construct_UClass_AProtagClass_Statics; \
public: \
	DECLARE_CLASS(AProtagClass, ABase2DCharacter, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/HSPGame"), NO_API) \
	DECLARE_SERIALIZER(AProtagClass)


#define HSPGame_Source_HSPGame_ProtagClass_h_24_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AProtagClass(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AProtagClass) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AProtagClass); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AProtagClass); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AProtagClass(AProtagClass&&); \
	NO_API AProtagClass(const AProtagClass&); \
public:


#define HSPGame_Source_HSPGame_ProtagClass_h_24_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AProtagClass(AProtagClass&&); \
	NO_API AProtagClass(const AProtagClass&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AProtagClass); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AProtagClass); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AProtagClass)


#define HSPGame_Source_HSPGame_ProtagClass_h_24_PRIVATE_PROPERTY_OFFSET
#define HSPGame_Source_HSPGame_ProtagClass_h_21_PROLOG
#define HSPGame_Source_HSPGame_ProtagClass_h_24_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	HSPGame_Source_HSPGame_ProtagClass_h_24_PRIVATE_PROPERTY_OFFSET \
	HSPGame_Source_HSPGame_ProtagClass_h_24_RPC_WRAPPERS \
	HSPGame_Source_HSPGame_ProtagClass_h_24_INCLASS \
	HSPGame_Source_HSPGame_ProtagClass_h_24_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define HSPGame_Source_HSPGame_ProtagClass_h_24_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	HSPGame_Source_HSPGame_ProtagClass_h_24_PRIVATE_PROPERTY_OFFSET \
	HSPGame_Source_HSPGame_ProtagClass_h_24_RPC_WRAPPERS_NO_PURE_DECLS \
	HSPGame_Source_HSPGame_ProtagClass_h_24_INCLASS_NO_PURE_DECLS \
	HSPGame_Source_HSPGame_ProtagClass_h_24_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID HSPGame_Source_HSPGame_ProtagClass_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
