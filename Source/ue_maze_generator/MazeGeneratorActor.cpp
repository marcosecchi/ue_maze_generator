#include "MazeGeneratorActor.h"
#include "MazeGenerator.h"


AMazeGeneratorActor::AMazeGeneratorActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AMazeGeneratorActor::BeginPlay()
{
	Super::BeginPlay();
	
//	Map = FMazeGenerator::GenerateMaze(NumRows, NumColumns, MazeType, TypeSelectionPercentage, NumRandomlyRemovedTiles);
}

