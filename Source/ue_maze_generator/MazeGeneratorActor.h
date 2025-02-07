#pragma once

#include "CoreMinimal.h"
#include "MazeType.h"
#include "GameFramework/Actor.h"
#include "MazeGeneratorActor.generated.h"

UCLASS()
class UE_MAZE_GENERATOR_API AMazeGeneratorActor : public AActor
{
	GENERATED_BODY()

public:
	AMazeGeneratorActor();

	UPROPERTY(EditAnywhere, Category="Tile Generation")
	float NumRows = 1;

	UPROPERTY(EditAnywhere, Category="Tile Generation")
	float NumColumns = 1;

	UPROPERTY(EditAnywhere, Category="Tile Generation")
	EMazeType MazeType = EMazeType::Random;

	UPROPERTY(EditAnywhere, Category="Tile Generation")
	float TypeSelectionPercentage = 1;

	UPROPERTY(EditAnywhere, Category="Tile Generation")
	float NumRandomlyRemovedTiles = 0;
	
protected:
	TMap<FIntVector, int32> Map;

	virtual void BeginPlay() override;

public:
};
