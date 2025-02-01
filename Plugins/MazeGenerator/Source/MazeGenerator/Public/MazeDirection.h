#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType, meta=(DisplayName="MazeDirection"))
enum class EMazeDirection: uint8
{
	North,
	East,
	South,
	West
};
