#include "Inventory.h"
#include "InventoryPrivatePCH.h"

DEFINE_LOG_CATEGORY(LogUTInventory);

IMPLEMENT_MODULE(FDefaultGameModuleImpl, Inventory)

void FInventoryPlugin::StartupModule()
{
	UE_LOG(LogUTInventory, Warning, TEXT("FInventoryPlugin::StartupModule!"));
}


void FInventoryPlugin::ShutdownModule()
{

}
