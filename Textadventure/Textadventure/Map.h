#include "stdafx.h";
#define HEIGHT 16
#define WIDTH 16

#pragma once
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
	string mapdata[HEIGHT][WIDTH];

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

	void Move(MoveDirection direction);
};