#pragma once

#include "Core.h"
#include "Engine.h"
#include "ModuleInterface.h"

class FInventoryPlugin : public IModuleInterface
{
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

};


DECLARE_LOG_CATEGORY_EXTERN(LogUTInventory, Warning, All);
