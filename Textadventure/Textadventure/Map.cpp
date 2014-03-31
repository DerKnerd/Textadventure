#include "stdafx.h"
#include "Map.h";
#include "Fight.h";

int random(int range_min, int range_max) {
	return (int)rand() / (RAND_MAX + 1) * (range_max - range_min) + range_min;
}

Map::~Map(void)
{
}

Map::Map(string path) {
	auto input = ifstream(path);
	auto datastream = stringstream();
	datastream << input.rdbuf();
	this->data = datastream.str();
	srand((unsigned)time(NULL));
	this->horizontalpos = random(0, WIDTH);
	this->verticalpos = random(0, HEIGHT);
}

string Map::GetData(void) {
	return this->data;
}

void Map::Parse(void) {
	auto data = this->data;
	auto datastream = stringstream(data);

	auto currentline = string();
	auto currentindex = 0;

	auto currentitem = string();

	for (int i = 0; i < WIDTH; i++) {
		getline(datastream, currentline);
		for (int j = 0; j < HEIGHT; j++) {
			currentitem = currentline.substr(0, currentline.find(";"));
			this->mapdata[i][j] = currentitem;
			currentline.erase(0, currentline.find(";") + 1);
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
		cout << ATTHEBORDER << endl;
#endif
	} else {
		if (mapdata[verticalpos][horizontalpos - 1] != "w") {
			horizontalpos--;
#if _DEBUG
			cout << MOVEDLEFT << endl;
#endif
		} else {
#if _DEBUG
			cout << CANTPASSWALLS << endl;
#endif
		}
	}
}

void Map::MoveUp() {
	if (verticalpos == 0) {
#if _DEBUG
		cout << ATTHEBORDER << endl;
#endif
	} else {
		if (mapdata[verticalpos - 1][horizontalpos] != "w") {
			verticalpos--;
#if _DEBUG
			cout << MOVEDUP << endl;
#endif
		} else {
#if _DEBUG
			cout << CANTPASSWALLS << endl;
#endif
		}
	}
}

void Map::MoveRight() {
	if (horizontalpos == WIDTH - 1) {
#if _DEBUG
		cout << ATTHEBORDER << endl;
#endif
	} else {
		if (mapdata[verticalpos][horizontalpos + 1] != "w") {
			horizontalpos++;
#if _DEBUG
			cout << MOVEDRIGHT << endl;
#endif
		} else {
#if _DEBUG
			cout << CANTPASSWALLS << endl;
#endif
		}
	}
}

void Map::MoveDown() {
	if (verticalpos == HEIGHT - 1) {
#if _DEBUG
		cout << ATTHEBORDER << endl;
#endif
	} else {
		if (mapdata[verticalpos + 1][horizontalpos] != "w") {
			verticalpos++;
#if _DEBUG
			cout << MOVEDDOWN << endl;
#endif
		} else {
#if _DEBUG
			cout << CANTPASSWALLS << endl;
#endif
		}
	}
}

void Map::DrawMap() {
	COORD cur = {0, 0};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
	cout << endl << endl;
	if (mapdata[verticalpos][horizontalpos] == "e") {
		auto fight = Fight(this);
		fight.Start();
		return;
	}
	for (int i = 0; i < WIDTH; i++) {
		for (int j = 0; j < HEIGHT; j++) {
			if (horizontalpos == j && verticalpos == i) {
				cout << "P";
			} else {
				cout << mapdata[i][j];
			}
		}
		if (i == 4) {
			cout << HOWTOMOVE;
		} else if (i == 5) {
			cout << HOWTOEXIT;
		} else if (i == 6) {
			cout << WHOAREYOU;
		} else if (i == 7) {
			cout << WHATAREWALLS;
		} else if (i == 8) {
			cout << WHATAREENEMIES;
		}
		cout << endl;
	}
}