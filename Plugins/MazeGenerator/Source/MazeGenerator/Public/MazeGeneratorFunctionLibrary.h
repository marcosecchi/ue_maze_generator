#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MazeGeneratorFunctionLibrary.generated.h"

enum class EMazeDirection : uint8;
enum class EMazeType : uint8;


UCLASS()
class MAZEGENERATOR_API UMazeGeneratorFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/**
	 * Generate an empty grid, used for creating a new maze
	 * */
	UFUNCTION(BlueprintCallable, Category="Maze Generation")
	static TMap<FIntVector, int32> GenerateEmptyMaze(int32 NumRows, int32 NumColumns);

	/**
	 * Generate a maze by using Wang Tiles
	 */
	UFUNCTION(BlueprintCallable, Category="Maze Generation")
	static TMap<FIntVector, int32> GenerateMaze(const int32 NumRows, const int32 NumColumns, EMazeType MazeType, float TypeSelectionPercentage, int32 NumRandomlyRemovedTiles);

	/**
	 * Returns the size of the maze (number of rows and columns)
	 */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Maze Generation")
	static FIntVector GetMazeSize(const TMap<FIntVector, int32> Map);

	/**
	 * Adds a direction to a tile
	 */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Maze Generation")
	static int32 AddDirection(int32 TileId, EMazeDirection Direction);

	/**
	 * Checks if a tile has a door by its id
	 */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Maze Generation")
	static bool HasDoor(int32 TileId, EMazeDirection Direction);
};
