#include "stdafx.h"
#include "Map.h";
#include "Fight.h"

Fight::Fight(Map* map) {
	this->map = map;
}

Fight::~Fight(void) {
}

void Fight::Start() {
	this->myStrength = 100;
	auto null = NULL;

	std::mt19937 eng((std::random_device()()));

	// a distribution that takes randomness and produces values in specified range
	std::uniform_int_distribution<> distattack(1, 50);
	std::uniform_int_distribution<> diststrength(51, 200);

	this->myAttack = distattack(eng);
	this->enemyStrength = diststrength(eng);
	this->enemyAttack = distattack(eng);

	system("cls");
	DrawFightplace();
}

void Fight::DrawFightplace() {
}

void Fight::Exit() {
	map->DrawMap();
}