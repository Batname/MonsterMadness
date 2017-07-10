// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Public/Inventory.h"
#include "Inventory.generated.dep.h"
PRAGMA_DISABLE_OPTIMIZATION
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCode1Inventory() {}
#if USE_COMPILED_IN_NATIVES
// Cross Module References
	UMG_API class UClass* Z_Construct_UClass_UUserWidget();
	ENGINE_API class UClass* Z_Construct_UClass_AActor();
	ENGINE_API class UClass* Z_Construct_UClass_ACharacter();
	ENGINE_API class UClass* Z_Construct_UClass_UActorComponent();

	INVENTORY_API class UClass* Z_Construct_UClass_UInventoryWidget_NoRegister();
	INVENTORY_API class UClass* Z_Construct_UClass_UInventoryWidget();
	INVENTORY_API class UClass* Z_Construct_UClass_APickup_NoRegister();
	INVENTORY_API class UClass* Z_Construct_UClass_APickup();
	INVENTORY_API class UClass* Z_Construct_UClass_ATrader_NoRegister();
	INVENTORY_API class UClass* Z_Construct_UClass_ATrader();
	INVENTORY_API class UClass* Z_Construct_UClass_UTraderComponent_NoRegister();
	INVENTORY_API class UClass* Z_Construct_UClass_UTraderComponent();
	INVENTORY_API class UPackage* Z_Construct_UPackage__Script_Inventory();
	void UInventoryWidget::StaticRegisterNativesUInventoryWidget()
	{
	}
	UClass* Z_Construct_UClass_UInventoryWidget_NoRegister()
	{
		return UInventoryWidget::StaticClass();
	}
	UClass* Z_Construct_UClass_UInventoryWidget()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_UUserWidget();
			Z_Construct_UPackage__Script_Inventory();
			OuterClass = UInventoryWidget::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20B01080;


				static TCppClassTypeInfo<TCppClassTypeTraits<UInventoryWidget> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("InventoryWidget.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("Public/InventoryWidget.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(UInventoryWidget, 916141706);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UInventoryWidget(Z_Construct_UClass_UInventoryWidget, &UInventoryWidget::StaticClass, TEXT("/Script/Inventory"), TEXT("UInventoryWidget"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UInventoryWidget);
	void APickup::StaticRegisterNativesAPickup()
	{
	}
	UClass* Z_Construct_UClass_APickup_NoRegister()
	{
		return APickup::StaticClass();
	}
	UClass* Z_Construct_UClass_APickup()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_AActor();
			Z_Construct_UPackage__Script_Inventory();
			OuterClass = APickup::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20900080;


				static TCppClassTypeInfo<TCppClassTypeTraits<APickup> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("Pickup.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("Public/Pickup.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(APickup, 840443137);
	static FCompiledInDefer Z_CompiledInDefer_UClass_APickup(Z_Construct_UClass_APickup, &APickup::StaticClass, TEXT("/Script/Inventory"), TEXT("APickup"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(APickup);
	void ATrader::StaticRegisterNativesATrader()
	{
	}
	UClass* Z_Construct_UClass_ATrader_NoRegister()
	{
		return ATrader::StaticClass();
	}
	UClass* Z_Construct_UClass_ATrader()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_ACharacter();
			Z_Construct_UPackage__Script_Inventory();
			OuterClass = ATrader::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20900080;


				static TCppClassTypeInfo<TCppClassTypeTraits<ATrader> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("HideCategories"), TEXT("Navigation"));
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("Trader.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("Public/Trader.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(ATrader, 1375689822);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ATrader(Z_Construct_UClass_ATrader, &ATrader::StaticClass, TEXT("/Script/Inventory"), TEXT("ATrader"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ATrader);
	void UTraderComponent::StaticRegisterNativesUTraderComponent()
	{
	}
	UClass* Z_Construct_UClass_UTraderComponent_NoRegister()
	{
		return UTraderComponent::StaticClass();
	}
	UClass* Z_Construct_UClass_UTraderComponent()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_UActorComponent();
			Z_Construct_UPackage__Script_Inventory();
			OuterClass = UTraderComponent::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20B00080;


				static TCppClassTypeInfo<TCppClassTypeTraits<UTraderComponent> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("BlueprintSpawnableComponent"), TEXT(""));
				MetaData->SetValue(OuterClass, TEXT("ClassGroupNames"), TEXT("Custom"));
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("TraderComponent.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("Public/TraderComponent.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(UTraderComponent, 1556821983);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UTraderComponent(Z_Construct_UClass_UTraderComponent, &UTraderComponent::StaticClass, TEXT("/Script/Inventory"), TEXT("UTraderComponent"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UTraderComponent);
	UPackage* Z_Construct_UPackage__Script_Inventory()
	{
		static UPackage* ReturnPackage = nullptr;
		if (!ReturnPackage)
		{
			ReturnPackage = CastChecked<UPackage>(StaticFindObjectFast(UPackage::StaticClass(), nullptr, FName(TEXT("/Script/Inventory")), false, false));
			ReturnPackage->SetPackageFlags(PKG_CompiledIn | 0x00000000);
			FGuid Guid;
			Guid.A = 0xBAF03F3B;
			Guid.B = 0x54858F05;
			Guid.C = 0x00000000;
			Guid.D = 0x00000000;
			ReturnPackage->SetGuid(Guid);

		}
		return ReturnPackage;
	}
#endif
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
PRAGMA_ENABLE_OPTIMIZATION
