#include "stdafx.h"
#include "Map.h"

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
