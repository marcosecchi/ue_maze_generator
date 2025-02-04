#pragma once

#include "CoreMinimal.h"

/* **
 * Used to handle the way tiles are selected - and thus, how the maze is generated -
 * during generation phase
 */
UENUM(BlueprintType, meta=(DisplayName="MazeType"))
enum class EMazeType: uint8
{
	Random,
	LongPassages,
	ShortPassages
};
