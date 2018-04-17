#include <string>
#include <iostream>
#include "Menu.h"
#include "Ranking.h"
#include "Getinput.h"
#include "File.h"
#include "Console.h"
// UWAGA: ZMIENIONO KODOWANIE TEKSTU.
void Menu::displatTitle() {
	using std::cout;
	using std::endl;
	Console::clear();
	cout << "  ___   __   ___    _        __  " << endl;
	cout << "   |   |__    |    |_|   |  |__  " << endl;
	cout << "   |   |__    |    | \\   |   __|" << endl;
	cout << endl << endl;
}
void Menu::println(const int & value, const char * msg) {
	std::cout << "    " << value << " - " << msg << std::endl;
}
void Menu::showMenuList() {
	displatTitle();
	println(1, "NOWA GRA");
	println(2, "RANKING");
	println(3, "ZRESETUJ RANKING");
	println(4, "JAK GRA");
	println(5, "WYJD Z GRY");
}
Menu::Event Menu::mainMenu() {
	Event event;
	do {
		showMenuList();
		event = selectMenuOption();
	} while (event == Event::CONTINUE);
	return event;
}
Menu::Event Menu::selectMenuOption() {
	switch (GetInput::inputMenu<int>()) {
	case 1:
		return Event::STARTGAME;
	case 2:
		displatTitle();
		Ranking::getRanking()->showScoreboard();
		GetInput::message("Nacisnij dowolny klawisz, aby wr¢ci†.");
		break;
	case 3:
		displatTitle();
		if (GetInput::question("Czy napewno chcesz zresetowa† ranking? [T/N]"))
			Ranking::getRanking()->clear();
		break;
	case 4:
		displatTitle();
		File::DisplayTextFile("howToPlay.txt");
		GetInput::message("Nacisnij dowolny klawisz, aby wr¢ci†.");
		break;
	case 5:
		displatTitle();
		if (GetInput::question("Czy napewno chcesz wyj˜† z gry? [T/N]"))
			return Event::EXIT;
		break;
	}
	return Event::CONTINUE;
}