#pragma once
#include "stdafx.h"
#include "Fight.h"
#include "Map.h"

enum AdventureSituation {
	Fighting,
	Walking,
	Losing,
	Victory
};

class Adventure {
private:
	short lives = 5;

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
	void AddLive();
	void RemoveLive();

	void Move(MoveDirection direction);
};
