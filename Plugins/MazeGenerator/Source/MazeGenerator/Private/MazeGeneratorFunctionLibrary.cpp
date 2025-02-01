// Fill out your copyright notice in the Description page of Project Settings.


#include "MazeGeneratorFunctionLibrary.h"

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

TMap<FIntVector, int32> UMazeGeneratorFunctionLibrary::GenerateMaze(const int32 Width, const int32 Height)
{
	TMap<FIntVector, int32> Map = GenerateEmptyMaze(Width, Height);

	// TODO
	
	return Map;
}
