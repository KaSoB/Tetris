#pragma once
#include <iostream>
#include <conio.h>
class GetInput {
public:
	enum CodeKeys { KEY_UP = 72, KEY_DOWN = 80, KEY_LEFT = 75, KEY_RIGHT = 77, KEY_DEFAULT = 0 };
	static CodeKeys keyPressEvent();
	static std::string inputString();
	template <typename T>
	static T input() {
		T n;
		while (!(std::cin >> n)) { clearCin(); }
		clearCin();
		return n;
	}
	static unsigned char input();
	template <typename T>
	static T inputMenu() {
		unsigned char c = _getch();
		return int(c) - 48;
	}
	static unsigned char inputMenu();
	static bool inputYN();
	static bool inputTF();
	static void message(const char * msg);
	static bool question(const char * msg);
private:
	static CodeKeys keyPress();
	static inline bool truefalse(unsigned char * c) { return (*c == 't' || *c == 'T' || *c == '1'); }
	static inline bool yesno(unsigned char * c) { return (*c == 'y' || *c == 'Y' || *c == 't' || *c == 'T'); }
	static inline void clearCin();
};