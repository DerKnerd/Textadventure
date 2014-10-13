#include "Adventure.h"

Adventure::Adventure(wstring path) {
	this->CurrentMap = new Map(path);
}

Adventure::~Adventure() {
}

void Adventure::Move(MoveDirection direction) {
	switch (direction) {
	case ::Right: CurrentMap->MoveRight();
		break;
	case ::Left: CurrentMap->MoveLeft();
		break;
	case ::Up: CurrentMap->MoveUp();
		break;
	case ::Down: CurrentMap->MoveDown();
		break;
	}
	DrawMap();
}

void Adventure::StartFight() {
	CurrentFight = new Fight();
	CurrentFight->myStrength = 100;
	CurrentFight->myStrengthLeft = 100;
	auto null = NULL;

	mt19937 eng((random_device()()));

	// a distribution that takes randomness and produces values in specified range
	uniform_int_distribution<> distattack(1, 50);
	uniform_int_distribution<> diststrength(51, 200);

	CurrentFight->myAttack = distattack(eng);
	CurrentFight->enemyStrength = diststrength(eng);
	CurrentFight->enemyStrengthLeft = CurrentFight->enemyStrength;
	CurrentFight->enemyAttack = distattack(eng);

	system("cls");
	CurrentFight->DrawFightplace();
	CurrentSituation = ::Fighting;
}

void Adventure::LooseFight() {
	CurrentFight->won = false;
	ExitFight();
}

void Adventure::ExitFight() {
	system("cls");
	if (!CurrentFight->won) {
		CurrentMap->horizontalpos = CurrentMap->oldhorizontalpos;
		CurrentMap->verticalpos = CurrentMap->oldverticalpos;
	}
	DrawMap();
	CurrentSituation = ::Walking;
	delete CurrentFight;
}

void Adventure::DrawMap() {
	COORD cur = { 0, 0 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
	wcout << endl << endl;
	if (CurrentMap->mapdata[CurrentMap->verticalpos][CurrentMap->horizontalpos] == L"e") {
		StartFight();
		return;
	}
	else {
		CurrentMap->oldhorizontalpos = CurrentMap->horizontalpos;
		CurrentMap->oldverticalpos = CurrentMap->verticalpos;
	}
	for (int i = 0; i < WIDTH; i++) {
		for (int j = 0; j < HEIGHT; j++) {
			if (CurrentMap->horizontalpos == j && CurrentMap->verticalpos == i) {
				wcout << L"P";
			}
			else {
				wcout << CurrentMap->mapdata[i][j];
			}
		}
		if (i == 4) {
			wcout << HOWTOMOVE;
		}
		else if (i == 5) {
			wcout << HOWTOEXIT;
		}
		else if (i == 6) {
			wcout << WHOAREYOU;
		}
		else if (i == 7) {
			wcout << WHATAREWALLS;
		}
		else if (i == 8) {
			wcout << WHATAREENEMIES;
		}
		wcout << endl;
	}
	CurrentSituation = ::Walking;
}