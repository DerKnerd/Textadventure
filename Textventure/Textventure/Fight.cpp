#include "stdafx.h"
#include "Fight.h"
#include "Tools.h"

Fight::Fight(void) {
	eng = mt19937((random_device()()));
}

Fight::~Fight(void) {
}

void Fight::DrawFightplace() {
	if (this->enemyStrengthLeft <= 0) {
		system("cls");
		wcout << L"\r\n";
		wcout << L"Congrats, you won :)" << endl;
	}
	else if (this->myStrengthLeft <= 0) {
		system("cls");
		wcout << L"\r\n";
		wcout << L"Sorry, you lost :(" << endl;
	}
	else {
		COORD cur = { 0, 0 };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
		wcout << L"[enemy " << (enemyBlock ? L"blocks" : L"attacks") << L"]             ";
		wcout << endl;
		wcout << L"Enemy " << this->enemyStrengthLeft << L"/" << this->enemyStrength << "                 " << endl;
		Console::WriteLine(L"◄");
		for (int i = 0; i < 50; i++) {
			auto strength = ((double)this->enemyStrengthLeft / (double)this->enemyStrength) * 50.0;
			if (strength > i)
				Console::WriteLine(L"■");
			else
				wcout << L" ";
		}
		Console::WriteLine(L"►");
		wcout << endl << endl;
		wcout << L"                    __" << endl;
		wcout << L"                   / _)" << endl;
		wcout << L"            .-^^^-/ /  " << endl;
		wcout << L"         __/       /   " << endl;
		wcout << L"        <__.|_|-|_|    " << endl;
		wcout << endl << endl << endl << endl;
		wcout << L"                                      __" << endl;
		wcout << L"                                     (_ \\" << endl;
		wcout << L"                                       \\ \\-^^^-." << endl;
		wcout << L"                                        \\       \\__" << endl;
		wcout << L"                                         |_|-|_|.__>    " << endl << endl;
		wcout << L"Me " << this->myStrengthLeft << L"/" << this->myStrength << "                 " << endl;
		Console::WriteLine(L"◄");
		for (int i = 0; i < 50; i++) {
			auto strength = ((double)this->myStrengthLeft / (double)this->myStrength) * 50.0;
			if (strength > i)
				Console::WriteLine(L"■");
			else
				wcout << L" ";
		}
		Console::WriteLine(L"►");
		wcout << endl;
	}
}

void Fight::EnemyAttack() {
	enemyBlock = false;
	uniform_int_distribution<> attack(1, 100);
	auto att = attack(eng);
	if (att > 50) {
		if (!block) {
			uniform_int_distribution<> hit(1, 100);
			if (hit(eng) > 5 && hit(eng) < 95) {
				this->myStrengthLeft -= this->enemyAttack;
			}
		}
	}
	else {
		enemyBlock = true;
	}
	DrawFightplace();
}

void Fight::Attack() {
	block = false;
	if (!enemyBlock) {
		uniform_int_distribution<> hit(1, 100);
		if (hit(eng) > 5 && hit(eng) < 95) {
			this->enemyStrengthLeft -= this->myAttack;
		}
	}
	DrawFightplace();
	EnemyAttack();
}

void Fight::Block() {
	block = true;
	DrawFightplace();
	EnemyAttack();
}