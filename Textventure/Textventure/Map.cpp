#include "stdafx.h"
#include "Map.h"
#include "Fight.h"

int random(int range_min, int range_max) {
	return (int)rand() / (RAND_MAX + 1) * (range_max - range_min) + range_min;
}

Map::~Map(void)
{
}

Map::Map(wstring path) {
	auto input = wifstream(path);
	auto datastream = wstringstream();
	datastream << input.rdbuf();
	this->data = datastream.str();
	srand((unsigned)time(NULL));
	this->horizontalpos = random(0, WIDTH);
	this->verticalpos = random(0, HEIGHT);
}

wstring Map::GetData(void) {
	return this->data;
}

void Map::Parse(void) {
	auto data = this->data;
	auto datastream = wstringstream(data);

	auto currentline = wstring();
	auto currentindex = 0;

	auto currentitem = wstring();

	for (int i = 0; i < WIDTH; i++) {
		getline(datastream, currentline);
		for (int j = 0; j < HEIGHT; j++) {
			currentitem = currentline.substr(0, currentline.find(L";"));
			this->mapdata[i][j] = currentitem;
			currentline.erase(0, currentline.find(L";") + 1);
		}
	}
}

void Map::Move(MoveDirection direction) {
	switch (direction) {
	case ::Right: MoveRight();
		break;
	case ::Left: MoveLeft();
		break;
	case ::Up: MoveUp();
		break;
	case ::Down: MoveDown();
		break;
	}
	DrawMap();
}

void Map::MoveLeft() {
	if (horizontalpos == 0) {
#if _DEBUG
		wcout << ATTHEBORDER << endl;
#endif
	} else {
		if (mapdata[verticalpos][horizontalpos - 1] != L"w") {
			horizontalpos--;
#if _DEBUG
			wcout << MOVEDLEFT << endl;
#endif
		} else {
#if _DEBUG
			wcout << CANTPASSWALLS << endl;
#endif
		}
	}
}

void Map::MoveUp() {
	if (verticalpos == 0) {
#if _DEBUG
		wcout << ATTHEBORDER << endl;
#endif
	} else {
		if (mapdata[verticalpos - 1][horizontalpos] != L"w") {
			verticalpos--;
#if _DEBUG
			wcout << MOVEDUP << endl;
#endif
		} else {
#if _DEBUG
			wcout << CANTPASSWALLS << endl;
#endif
		}
	}
}

void Map::MoveRight() {
	if (horizontalpos == WIDTH - 1) {
#if _DEBUG
		wcout << ATTHEBORDER << endl;
#endif
	} else {
		if (mapdata[verticalpos][horizontalpos + 1] != L"w") {
			horizontalpos++;
#if _DEBUG
			wcout << MOVEDRIGHT << endl;
#endif
		} else {
#if _DEBUG
			wcout << CANTPASSWALLS << endl;
#endif
		}
	}
}

void Map::MoveDown() {
	if (verticalpos == HEIGHT - 1) {
#if _DEBUG
		wcout << ATTHEBORDER << endl;
#endif
	} else {
		if (mapdata[verticalpos + 1][horizontalpos] != L"w") {
			verticalpos++;
#if _DEBUG
			wcout << MOVEDDOWN << endl;
#endif
		} else {
#if _DEBUG
			wcout << CANTPASSWALLS << endl;
#endif
		}
	}
}

void Map::DrawMap() {
	COORD cur = {0, 0};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
	wcout << endl << endl;
	if (mapdata[verticalpos][horizontalpos] == L"e") {
		auto fight = Fight(this);
		fight.Start();
		return;
	}
	for (int i = 0; i < WIDTH; i++) {
		for (int j = 0; j < HEIGHT; j++) {
			if (horizontalpos == j && verticalpos == i) {
				wcout << L"P";
			} else {
				wcout << mapdata[i][j];
			}
		}
		if (i == 4) {
			wcout << HOWTOMOVE;
		} else if (i == 5) {
			wcout << HOWTOEXIT;
		} else if (i == 6) {
			wcout << WHOAREYOU;
		} else if (i == 7) {
			wcout << WHATAREWALLS;
		} else if (i == 8) {
			wcout << WHATAREENEMIES;
		}
		wcout << endl;
	}
}