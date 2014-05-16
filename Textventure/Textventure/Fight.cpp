#include "stdafx.h"
#include "Fight.h"
#include "Tools.h"

Fight::Fight(void) {
}

Fight::~Fight(void) {
}

void Fight::DrawFightplace() {
  COORD cur = { 0, 0 };
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
  wstring out = L"";
  wcout << L"Enemy " << this->enemyStrengthLeft << L"/" << this->enemyStrength << endl;
  Console::WriteLine(L"◄");
  for (int i = 0; i < 50; i++) {
    auto strength = ((double)this->enemyStrengthLeft / (double)this->enemyStrength) * 50.0;
    if (strength > i)
      Console::WriteLine(L"■");
    else
      wcout << L" ";
  }
  Console::WriteLine(L"►");
}

void Fight::Attack() {
  mt19937 eng((random_device()()));

  // a distribution that takes randomness and produces values in specified range
  uniform_int_distribution<> hit(1, 100);
  if (hit(eng) > 5 && hit(eng) < 95) {
    this->enemyStrengthLeft -= this->myAttack;
  }
  DrawFightplace();
}

void Fight::Block() {
  DrawFightplace();
}