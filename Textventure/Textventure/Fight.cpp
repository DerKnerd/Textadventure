#include "stdafx.h"
#include "Map.h"
#include "Fight.h"

Fight::Fight(Map* map) {
	this->map = map;
  map->IsFight = true;
}

Fight::~Fight(void) {
}

void Fight::Start() {
	this->myStrength = 100;
  this->myStrengthLeft = 100;
	auto null = NULL;

	mt19937 eng((random_device()()));

	// a distribution that takes randomness and produces values in specified range
	uniform_int_distribution<> distattack(1, 50);
	uniform_int_distribution<> diststrength(51, 200);

	this->myAttack = distattack(eng);
	this->enemyStrength = diststrength(eng);
  this->enemyStrengthLeft = this->enemyStrength;
	this->enemyAttack = distattack(eng);

	system("cls");
	DrawFightplace();
}

void Fight::DrawFightplace() {
  COORD cur = { 0, 0 };
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
  wcout << L"Enemy " << this->enemyStrengthLeft << L"/" << this->enemyStrength << endl;
  wcout << L"<"; //L"◄";
  for (int i = 0; i < 20; i++) {
    if (i % 2 == 0)
      wcout << "="; //L"■";
    else
      wcout << L" ";
  }
  wcout << /*L"►"*/ L">" << endl;
}

void Fight::Exit() {
	map->DrawMap();
}