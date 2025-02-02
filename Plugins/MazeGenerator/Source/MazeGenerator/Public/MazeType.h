#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType, meta=(DisplayName="MazeType"))
enum class EMazeType: uint8
{
	Random,
	LongPassages,
	ShortPassages
};
