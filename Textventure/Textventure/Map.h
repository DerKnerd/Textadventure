#pragma once

#include "stdafx.h"

#define HEIGHT 16
#define WIDTH 16

enum MoveDirection {
	Up,
	Down,
	Left,
	Right
};

class Map {
	friend class Adventure;

private:
	wstring data;

	wstring mapdata[WIDTH][HEIGHT];

	int verticalpos;
	int horizontalpos;
	int oldverticalpos;
	int oldhorizontalpos;

protected:
	void MoveLeft();
	void MoveRight();
	void MoveUp();
	void MoveDown();
public:
	Map(wstring path = L"");
	~Map(void);

	wstring GetData(void);

	void Parse(void);
	void DefeatEnemy();
};