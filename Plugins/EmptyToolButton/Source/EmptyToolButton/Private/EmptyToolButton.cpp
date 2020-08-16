// Copyright Epic Games, Inc. All Rights Reserved.

#include "EmptyToolButton.h"
#include "EmptyToolButtonStyle.h"
#include "EmptyToolButtonCommands.h"
#include "Misc/MessageDialog.h"
#include "ToolMenus.h"

static const FName EmptyToolButtonTabName("EmptyToolButton");

#define LOCTEXT_NAMESPACE "FEmptyToolButtonModule"

void FEmptyToolButtonModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	
	FEmptyToolButtonStyle::Initialize();
	FEmptyToolButtonStyle::ReloadTextures();

	FEmptyToolButtonCommands::Register();
	
	PluginCommands = MakeShareable(new FUICommandList);

	PluginCommands->MapAction(
		FEmptyToolButtonCommands::Get().PluginAction,
		FExecuteAction::CreateRaw(this, &FEmptyToolButtonModule::PluginButtonClicked),
		FCanExecuteAction());

	UToolMenus::RegisterStartupCallback(FSimpleMulticastDelegate::FDelegate::CreateRaw(this, &FEmptyToolButtonModule::RegisterMenus));
}

void FEmptyToolButtonModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	UToolMenus::UnRegisterStartupCallback(this);

	UToolMenus::UnregisterOwner(this);

	FEmptyToolButtonStyle::Shutdown();

	FEmptyToolButtonCommands::Unregister();
}

void FEmptyToolButtonModule::PluginButtonClicked()
{
	// Put your "OnButtonClicked" stuff here
	FText DialogText = FText::Format(
							LOCTEXT("PluginButtonDialogText", "Add code to {0} in {1} to override this button's actions"),
							FText::FromString(TEXT("FEmptyToolButtonModule::PluginButtonClicked()")),
							FText::FromString(TEXT("EmptyToolButton.cpp"))
					   );
	FMessageDialog::Open(EAppMsgType::Ok, DialogText);
}

void FEmptyToolButtonModule::RegisterMenus()
{
	// Owner will be used for cleanup in call to UToolMenus::UnregisterOwner
	FToolMenuOwnerScoped OwnerScoped(this);

	{
		UToolMenu* Menu = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu.Window");
		{
			FToolMenuSection& Section = Menu->FindOrAddSection("WindowLayout");
			Section.AddMenuEntryWithCommandList(FEmptyToolButtonCommands::Get().PluginAction, PluginCommands);
		}
	}

	{
		UToolMenu* ToolbarMenu = UToolMenus::Get()->ExtendMenu("LevelEditor.LevelEditorToolBar");
		{
			FToolMenuSection& Section = ToolbarMenu->FindOrAddSection("Settings");
			{
				FToolMenuEntry& Entry = Section.AddEntry(FToolMenuEntry::InitToolBarButton(FEmptyToolButtonCommands::Get().PluginAction));
				Entry.SetCommandList(PluginCommands);
			}
		}
	}
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FEmptyToolButtonModule, EmptyToolButton)