#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MazeGeneratorFunctionLibrary.generated.h"

enum class EMazeDirection : uint8;

UCLASS()
class MAZEGENERATOR_API UMazeGeneratorFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Maze Generation")
	static TMap<FIntVector, int32> GenerateEmptyMaze(int32 Width, int32 Height);

	UFUNCTION(BlueprintCallable, Category="Maze Generation")
	static TMap<FIntVector, int32> GenerateMaze(int32 Width, int32 Height);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Maze Generation")
	static FIntVector GetMazeSize(const TMap<FIntVector, int32> Map);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Maze Generation")
	static int32 AddDirection(int32 TileId, EMazeDirection Direction);
};
