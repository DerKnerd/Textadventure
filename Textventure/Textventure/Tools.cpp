#include "Tools.h"

void Console::WriteLine(wchar_t* message) {
	WriteConsoleW(GetStdHandle(STD_OUTPUT_HANDLE), message, wstring(message).length(), NULL, NULL);
}