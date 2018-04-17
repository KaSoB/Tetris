#include <Windows.h>
#include <iostream>
#include "Console.h"
void Console::gotoxy(short x, short y) {
	COORD c{x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void Console::gotoMainLine() {
	gotoxy(CMDLineX, CMDLineY);
}
void Console::clear() {
	system("cls");
}
void Console::wait(int m) {
	Sleep(m);
}
void Console::printlnXY(short x, short y, const char * ch) {
	gotoxy(x, y);
	printf_s(ch);
}
