#pragma once

class Fight
{
private:
	Map* map;
	short enemyStrength;
	short enemyAttack;
	
	short myStrength;
	short myAttack;

public:
	void Start();
	void DrawFightplace();
	void Attack();
	void Exit();

	Fight(Map* map);
	~Fight(void);
};

