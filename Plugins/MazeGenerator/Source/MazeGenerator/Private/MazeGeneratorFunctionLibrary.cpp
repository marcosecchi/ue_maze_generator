#include "MazeGeneratorFunctionLibrary.h"

#include "MazeDirection.h"
#include "MazeType.h"

TMap<FIntVector, int32> UMazeGeneratorFunctionLibrary::GenerateEmptyMaze(const int32 NumRows, const int32 NumColumns)
{
	TMap<FIntVector, int32> Map;
	for (int32 X = 0; X < NumRows; X++)
	{
		for (int32 Y = 0; Y < NumColumns; Y++)
		{
			Map.Add(FIntVector(X, Y, 0), -1);
		}
	}

	return Map;
}

TMap<FIntVector, int32> UMazeGeneratorFunctionLibrary::GenerateMaze(const int32 NumRows, const int32 NumColumns, const EMazeType MazeType = EMazeType::Random, const float TypeSelectionPercentage = 1.f)
{
	const auto ClampedSelectionPercentage = FMath::Clamp(TypeSelectionPercentage, 0.f, 1.f);
	
	TMap<FIntVector, int32> Map = GenerateEmptyMaze(NumRows, NumColumns);
	TArray<FIntVector> KeyList;
	Map.GetKeys(KeyList);

	// Select the first random tile
	auto SelectedIndex = FMath::RandRange(0, KeyList.Num() - 1);
	TArray<FIntVector> VisitedList = {};
	VisitedList.Add(KeyList[SelectedIndex]);

    while (VisitedList.Num() > 0)
    {
	    if (const auto RandomPercentage = FMath::RandRange(0.f, ClampedSelectionPercentage); MazeType == EMazeType::LongPassages && RandomPercentage < TypeSelectionPercentage)
    	{
    		SelectedIndex = VisitedList.Num() - 1;
    	}
    	else if (MazeType == EMazeType::ShortPassages && RandomPercentage < ClampedSelectionPercentage)
    	{
    		SelectedIndex = 0;
    	}
	    else
	    {
		    SelectedIndex = FMath::RandRange(0, VisitedList.Num() - 1);
	    }
    	
        FIntVector CurrentTile = VisitedList[SelectedIndex];
	 	TArray<EMazeDirection> AvailableDirections;
	
    	// Check if there are any unvisited neighbors
		if (Map.Contains(FIntVector(CurrentTile.X, CurrentTile.Y - 1, 0)) && !VisitedList.Contains(FIntVector(CurrentTile.X, CurrentTile.Y - 1, 0)))
		{
			AvailableDirections.Add(EMazeDirection::North);
		}
		if (Map.Contains(FIntVector(CurrentTile.X + 1, CurrentTile.Y, 0)) && !VisitedList.Contains(FIntVector(CurrentTile.X + 1, CurrentTile.Y, 0)))
		{
			AvailableDirections.Add(EMazeDirection::East);
		}
    	if (Map.Contains(FIntVector(CurrentTile.X, CurrentTile.Y + 1, 0)) && !VisitedList.Contains(FIntVector(CurrentTile.X, CurrentTile.Y + 1, 0)))
    	{
    		AvailableDirections.Add(EMazeDirection::South);
    	}
    	if (Map.Contains(FIntVector(CurrentTile.X - 1, CurrentTile.Y, 0)) && !VisitedList.Contains(FIntVector(CurrentTile.X - 1, CurrentTile.Y, 0)))
    	{
    		AvailableDirections.Add(EMazeDirection::West);
    	}

    	// If no opening is possible, remove tile from the visited list
    	if (AvailableDirections.Num() == 0)
    	{
			VisitedList.Remove(CurrentTile);
    		continue;;
    	}
    	const EMazeDirection SelectedDirection = AvailableDirections[FMath::RandRange(0, AvailableDirections.Num() - 1)];
    	auto CurrentTileId = Map.FindRef(CurrentTile);
    	CurrentTileId = AddDirection(CurrentTileId, SelectedDirection);
    	Map.Add(CurrentTile, CurrentTileId);
    	
    	auto Tile = FIntVector(0, 0, 0);
    	auto TileId = 0;
    	switch (SelectedDirection)
    	{
    	case EMazeDirection::North:
    		Tile = FIntVector(CurrentTile.X, CurrentTile.Y - 1, 0);
    		TileId = Map.FindRef(Tile);
    		TileId = AddDirection(TileId, EMazeDirection::South);
    		Map.Add(Tile, TileId);
    	case EMazeDirection::East:
    		Tile = FIntVector(CurrentTile.X + 1, CurrentTile.Y, 0);
    		TileId = Map.FindRef(Tile);
    		TileId = AddDirection(TileId, EMazeDirection::West);
    		Map.Add(Tile, TileId);
    	case EMazeDirection::South:
    		Tile = FIntVector(CurrentTile.X, CurrentTile.Y - 1, 0);
    		TileId = Map.FindRef(Tile);
    		TileId = AddDirection(TileId, EMazeDirection::South);
    		Map.Add(Tile, TileId);
    	case EMazeDirection::West:
    		Tile = FIntVector(CurrentTile.X - 1, CurrentTile.Y, 0);
    		TileId = Map.FindRef(Tile);
    		TileId = AddDirection(TileId, EMazeDirection::East);
    		Map.Add(Tile, TileId);
    	default:
    		break;
    	}
    	VisitedList.Add(Tile);
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

bool UMazeGeneratorFunctionLibrary::HasDoor(const int32 TileId, EMazeDirection const Direction)
{
	switch (Direction)
	{
		case EMazeDirection::North:
			return (TileId & 1) == 1;
		case EMazeDirection::East:
			return (TileId & 2) == 2;
		case EMazeDirection::South:
			return (TileId & 4) == 4;
		case EMazeDirection::West:
			return (TileId & 8) == 8;
		default:
			return false;
	}
}
