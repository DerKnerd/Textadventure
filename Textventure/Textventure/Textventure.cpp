// Textadventure.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include "Map.h"

int main(int argc, _TCHAR* argv[])
{
	cout << "Please input the path to your map" << endl;

	string path;
	Map map;
	getline(cin, path);

	cout << "Read in the file " << path << "..." << endl;

	map = Map(path);

#ifdef _DEBUG
	cout << "You put in the following map" << endl;
	cout << map.GetData() << endl;
#endif

	cout << "Parsing map, please wait..." << endl;
	map.Parse();

	cout << "Let the game begin" << endl;
	system("cls");

	map.DrawMap();

	auto exit = false;
	while (!exit) {
		auto key = _getch();
		switch (key) {
		case 27: exit = true;
			break;
		case 80:
			map.Move(::Down);
			break;
		case 72:
			map.Move(::Up);
			break;
		case 77:
			map.Move(::Right);
			break;
		case 75:
			map.Move(::Left);
			break;
		}
	}
	return 0;
}

