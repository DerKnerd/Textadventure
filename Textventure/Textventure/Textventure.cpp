// Textadventure.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include "Map.h"

int main(int argc, char* argv[])
{
  char* locale = setlocale(LC_ALL, "German"); // Get the CRT's current locale.
  std::locale lollocale(locale);
  setlocale(LC_ALL, locale); // Restore the CRT.
  wcout.imbue(lollocale); // Now set the std::wcout to have the locale that we got from the CRT.
  
  wcout << L"Please input the path to your map" << endl;

  wstring path;
  Map map;
  getline(wcin, path);

  wcout << L"Read in the file " << path << "..." << endl;

  map = Map(path);

#ifdef _DEBUG
  wcout << L"You put in the following map" << endl;
  wcout << map.GetData() << endl;
#endif

  wcout << L"Parsing map, please wait..." << endl;
  map.Parse();

  wcout << L"Let the game begin" << endl;
  system("cls");

  map.DrawMap();

  auto exit = false;
  while (!exit) {
    auto key = _getch();
    if (key == 27)
      exit = true;

    else if (!map.IsFight) {
      switch (key) {
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
    else {

    }
  }
  return 0;
}

