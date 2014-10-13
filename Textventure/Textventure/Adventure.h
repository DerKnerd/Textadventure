#pragma once
#include "stdafx.h"
#include "Fight.h"
#include "Map.h"

enum AdventureSituation {
	Fighting,
	Walking
};

class Adventure {
private:

public:
	Adventure(wstring path);
	~Adventure();

	Map* CurrentMap;
	Fight* CurrentFight;

	AdventureSituation CurrentSituation;

	void StartFight();
	void ExitFight();
	void LooseFight();
	void DrawMap();

	void Move(MoveDirection direction);
};
