#pragma once
#include "stdafx.h"

enum FightStatus {
	Won,
	Lost
};

class Fight {
	friend class Adventure;
private:
	mt19937 eng;

	short enemyStrength;
	short enemyStrengthLeft;
	short enemyAttack;

	short myStrength;
	short myStrengthLeft;
	short myAttack;

	bool won = false;
	bool block = false;
	bool enemyBlock = false;

	void EnemyAttack();
public:
	void DrawFightplace();
	void Attack();
	void Block();
	FightStatus GetStatus();

	Fight(void);
	~Fight(void);
};
