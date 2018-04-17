#pragma once
class Menu {
public:
	enum Event {EXIT, STARTGAME, CONTINUE};
	Event mainMenu();
private:
	void displatTitle();
	Menu::Event selectMenuOption();
	void println(const int & value, const char * msg);
	void showMenuList();
};