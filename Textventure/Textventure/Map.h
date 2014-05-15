#pragma once
#ifndef MapH
#define MapH
#include "stdafx.h"
#define HEIGHT 16
#define WIDTH 16

enum MoveDirection {
	Up,
	Down,
	Left,
	Right
};

class Map
{
private:
	wstring data;
	wstring mapdata[WIDTH][HEIGHT];

	int verticalpos;
	int horizontalpos;

	void MoveLeft();
	void MoveRight();
	void MoveUp();
	void MoveDown();
public:
	Map(wstring path = L"");
	~Map(void);

	wstring GetData(void);
	void Parse(void);
	void DrawMap();
  bool IsFight = false;

	void Move(MoveDirection direction);
};
#endif