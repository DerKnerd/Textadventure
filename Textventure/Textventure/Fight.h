#pragma once

class Fight
{
  friend class Adventure;
private:
  short enemyStrength;
  short enemyStrengthLeft;
  short enemyAttack;

  short myStrength;
  short myStrengthLeft;
  short myAttack;

  bool won = false;
public:
  void DrawFightplace();
  void Attack();
  void Block();

  Fight(void);
  ~Fight(void);
};