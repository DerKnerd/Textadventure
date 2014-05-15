#pragma once
#ifndef FightH
#define FightH
class Fight
{
private:
	Map* map;
	short enemyStrength;
  short enemyStrengthLeft;
	short enemyAttack;
	
  short myStrength;
  short myStrengthLeft;
	short myAttack;

public:
	void Start();
  virtual virtual void DrawFightplace();
	void Attack();
	void Exit();

	Fight(Map* map);
	~Fight(void);
};
#endif