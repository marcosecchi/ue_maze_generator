#include "MazeGeneratorFunctionLibrary.h"

#include "MazeDirection.h"

TMap<FIntVector, int32> UMazeGeneratorFunctionLibrary::GenerateEmptyMaze(const int32 Width, const int32 Height)
{
	TMap<FIntVector, int32> map;
	for (int32 X = 0; X < Width; X++)
	{
		for (int32 Y = 0; Y < Height; Y++)
		{
			map.Add(FIntVector(X, Y, 0), -1);
		}
	}

	return map;
}

TMap<FIntVector, int32> UMazeGeneratorFunctionLibrary::GenerateMaze(const int32 Width, const int32 Height)
{
	TMap<FIntVector, int32> map = GenerateEmptyMaze(Width, Height);

	// TODO
	
	return map;
}

FIntVector UMazeGeneratorFunctionLibrary::GetMazeSize(const TMap<FIntVector, int32> Map)
{
	TArray<FIntVector> KeyList;
	Map.GetKeys(KeyList);
	auto result = FIntVector(0, 0, 0);
	for (const auto list : KeyList)
	{
		if (result.X < list.X) { result.X = list.X; };
		if (result.Y < list.Y) { result.Y = list.Y; };
	}
	return result;
}

int32 UMazeGeneratorFunctionLibrary::AddDirection(int32 TileId, EMazeDirection Direction)
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
