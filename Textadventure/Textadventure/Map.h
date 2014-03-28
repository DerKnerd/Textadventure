#pragma once
#include "stdafx.h";
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
	string data;
	string mapdata[WIDTH][HEIGHT];

	int verticalpos;
	int horizontalpos;

	void MoveLeft();
	void MoveRight();
	void MoveUp();
	void MoveDown();
public:
	Map(string path = "");
	~Map(void);

	string GetData(void);
	void Parse(void);
	void DrawMap();

	void Move(MoveDirection direction);
};