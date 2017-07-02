#include "MonsterMadnessMenu.h"
#include "Modules/ModuleManager.h"

DEFINE_LOG_CATEGORY(MonsterMadnessMenu);

#define LOCTEXT_NAMESPACE "FMonsterMadnessMenu"

void FMonsterMadnessMenu::StartupModule()
{
	UE_LOG(MonsterMadnessMenu, Warning, TEXT("MonsterMadnessMenu has started!!"));
}

void FMonsterMadnessMenu::ShutdownModule()
{
	UE_LOG(MonsterMadnessMenu, Warning, TEXT("MonsterMadnessMenu has shut down!!"));
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE( FDefaultGameModuleImpl, MonsterMadnessMenu );
