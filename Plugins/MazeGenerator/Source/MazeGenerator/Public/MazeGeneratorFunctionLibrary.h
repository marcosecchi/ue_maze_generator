#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MazeGeneratorFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class MAZEGENERATOR_API UMazeGeneratorFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Maze Generation")
	static TMap<FIntVector, int32> GenerateEmptyMaze(int32 Width, int32 Height);

	UFUNCTION(BlueprintCallable, Category="Maze Generation")
	static TMap<FIntVector, int32> GenerateMaze(int32 Width, int32 Height);
};
