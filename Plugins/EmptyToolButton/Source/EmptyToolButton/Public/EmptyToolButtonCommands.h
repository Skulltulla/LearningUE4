// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"
#include "EmptyToolButtonStyle.h"

class FEmptyToolButtonCommands : public TCommands<FEmptyToolButtonCommands>
{
public:

	FEmptyToolButtonCommands()
		: TCommands<FEmptyToolButtonCommands>(TEXT("EmptyToolButton"), NSLOCTEXT("Contexts", "EmptyToolButton", "EmptyToolButton Plugin"), NAME_None, FEmptyToolButtonStyle::GetStyleSetName())
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

public:
	TSharedPtr< FUICommandInfo > PluginAction;
};
