#pragma once

#include "CoreMinimal.h"
#include "MazeGenerationData.generated.h"

enum class EMazeType : uint8;

USTRUCT(BlueprintType, meta=(DisplayName="MazeGenerationData"))
struct MAZEGENERATOR_API FMazeGenerationData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 NumRows;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 NumColumns;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EMazeType MazeType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MazeTypeSelectionPercentage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 NumRandomlyRemovedTiles;
};
