// Copyright Epic Games, Inc. All Rights Reserved.

#include "EmptyToolButtonCommands.h"

#define LOCTEXT_NAMESPACE "FEmptyToolButtonModule"

void FEmptyToolButtonCommands::RegisterCommands()
{
	UI_COMMAND(PluginAction, "EmptyToolButton", "Execute EmptyToolButton action", EUserInterfaceActionType::Button, FInputGesture());
}

#undef LOCTEXT_NAMESPACE
