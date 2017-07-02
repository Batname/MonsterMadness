#pragma once

#include "CoreMinimal.h"
#include "Engine.h"
#include "ModuleManager.h"
#include "Public/MenuGameModeBase.h"
#include "Public/MenuWidget.h"

#include "Runtime/UMG/Public/UMG.h"
#include "Runtime/UMG/Public/UMGStyle.h"
#include "Runtime/UMG/Public/Blueprint/UserWidget.h"
#include "Runtime/UMG/Public/Slate/SObjectWidget.h"
#include "Runtime/UMG/Public/IUMGModule.h"

DECLARE_LOG_CATEGORY_EXTERN(MonsterMadnessMenu, All, All);

class FMonsterMadnessMenu : public IModuleInterface
{
public:
	virtual void StartupModule() override;

	virtual void ShutdownModule() override;
};