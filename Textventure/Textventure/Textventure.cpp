// Textadventure.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include "Adventure.h"

int main(int argc, char* argv[])
{
	char* locale = setlocale(LC_ALL, "German"); // Get the CRT's current locale.
	std::locale lollocale(locale);
	setlocale(LC_ALL, locale); // Restore the CRT.
	wcout.imbue(lollocale); // Now set the std::wcout to have the locale that we got from the CRT.

	wcout << L"Please input the path to your currentAdventure" << endl;

	wstring path;
	getline(wcin, path);

	wcout << L"Read in the file " << path << "..." << endl;

	auto currentAdventure = Adventure(path);

#ifdef _DEBUG
	wcout << L"You put in the following map" << endl;
	wcout << currentAdventure.CurrentMap->GetData() << endl;
#endif

	wcout << L"Parsing currentAdventure, please wait..." << endl;
	currentAdventure.CurrentMap->Parse();

	wcout << L"Let the game begin" << endl;
	system("cls");

	currentAdventure.DrawMap();

	auto exit = false;
	while (!exit) {
		auto key = _getch();

		switch (currentAdventure.CurrentSituation) {
		case ::Walking:
			switch (key) {
			case 27:
				exit = true;
				break;
			case 80:
				currentAdventure.Move(::Down);
				break;
			case 72:
				currentAdventure.Move(::Up);
				break;
			case 77:
				currentAdventure.Move(::Right);
				break;
			case 75:
				currentAdventure.Move(::Left);
				break;
			}
			break;
		case ::Fighting:
			switch (key) {
			case 27:
				currentAdventure.LooseFight();
				break;
			case 97:
				currentAdventure.CurrentFight->Attack();
				break;
			case 98:
				currentAdventure.CurrentFight->Block();
				break;
			}
			break;
		}
	}
	return 0;
}