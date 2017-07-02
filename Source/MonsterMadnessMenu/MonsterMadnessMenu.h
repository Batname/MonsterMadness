#pragma once

#include "CoreMinimal.h"
#include "Engine.h"
#include "ModuleManager.h"

DECLARE_LOG_CATEGORY_EXTERN(MonsterMadnessMenu, All, All);

class FMonsterMadnessMenu : public IModuleInterface
{
public:
	virtual void StartupModule() override;

	virtual void ShutdownModule() override;
};