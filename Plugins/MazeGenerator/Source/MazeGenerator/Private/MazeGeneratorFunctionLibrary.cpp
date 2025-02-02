#include "MazeGeneratorFunctionLibrary.h"

#include "MazeDirection.h"
#include "MazeType.h"

TMap<FIntVector, int32> UMazeGeneratorFunctionLibrary::GenerateEmptyMaze(const int32 Width, const int32 Height)
{
	TMap<FIntVector, int32> Map;
	for (int32 X = 0; X < Width; X++)
	{
		for (int32 Y = 0; Y < Height; Y++)
		{
			Map.Add(FIntVector(X, Y, 0), -1);
		}
	}

	return Map;
}

TMap<FIntVector, int32> UMazeGeneratorFunctionLibrary::GenerateMaze(const int32 Width, const int32 Height, const EMazeType MazeType = EMazeType::Random, const float TypeSelectionPercentage = 1.f)
{
	const auto ClampedSelectionPercentage = FMath::Clamp(TypeSelectionPercentage, 0.f, 1.f);
	
	TMap<FIntVector, int32> Map = GenerateEmptyMaze(Width, Height);
	TArray<FIntVector> KeyList;
	Map.GetKeys(KeyList);

	auto SelectedIndex = FMath::RandRange(0, KeyList.Num() - 1);
	TArray<FIntVector> VisitedList = { KeyList[SelectedIndex]};

    while (VisitedList.Num() > 0)
    {
	    if (const auto RandomPercentage = FMath::RandRange(0.f, ClampedSelectionPercentage); MazeType == EMazeType::LongPassages && RandomPercentage < TypeSelectionPercentage)
    	{
    		SelectedIndex = VisitedList.Num() - 1;
    	} else if (MazeType == EMazeType::ShortPassages && RandomPercentage < ClampedSelectionPercentage)
    	{
    		SelectedIndex = 0;
    	}
        auto CurrentTile = VisitedList[SelectedIndex];

    	// TODO: Check if there are any unvisited neighbors

    	// TODO: Generate a random direction from available directions
    	// TODO: If none is available, remove tile from the visited list

    	// TODO: Open doors between current tile and neighbor
    	// TODO: Generate tile and add it to the visited list
    	
    	
    }
	
	return Map;
}

FIntVector UMazeGeneratorFunctionLibrary::GetMazeSize(const TMap<FIntVector, int32> Map)
{
	TArray<FIntVector> KeyList;
	Map.GetKeys(KeyList);
	auto Result = FIntVector(0, 0, 0);
	for (const auto List : KeyList)
	{
		if (Result.X < List.X) { Result.X = List.X; };
		if (Result.Y < List.Y) { Result.Y = List.Y; };
	}
	return Result;
}

int32 UMazeGeneratorFunctionLibrary::AddDirection(const int32 TileId, const EMazeDirection Direction)
{
	switch (Direction)
	{
		case EMazeDirection::North:
			return TileId | 1;
		case EMazeDirection::East:
			return TileId | 2;
	case EMazeDirection::South:
			return TileId | 4;
		case EMazeDirection::West:
			return TileId | 8;
		default:
			return TileId;
	}
}
