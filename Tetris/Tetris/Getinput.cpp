#include"GetInput.h"
#include <string>
inline void GetInput::clearCin() {
	std::cin.clear();
	while (std::cin.get() != '\n')
		continue;
}
unsigned char GetInput::input() {
	unsigned char c;
	std::cin >> c;
	clearCin();
	return c;
}
unsigned char GetInput::inputMenu() {
	unsigned char c = _getch();
	return c;
}
std::string GetInput::inputString() {
	std::string temp;
	std::cin >> temp;
	clearCin();
	return temp;
}
void GetInput::message(const char * msg) {
	std::cout << msg << std::endl;
	_getch();
}
bool GetInput::question(const char * msg) {
	std::cout << msg << std::endl;
	return inputYN();
}
bool GetInput::inputYN() {
	unsigned char c = _getch();
	return yesno(&c);
}
bool GetInput::inputTF() {
	unsigned char c = _getch();
	return truefalse(&c);
}
GetInput::CodeKeys GetInput::keyPressEvent() {
	GetInput::CodeKeys code = CodeKeys::KEY_DEFAULT;
	if (_kbhit()) { // keyboard hit. Funkcja systemowa sprawdza czy u¿ytkownik wcisn¹³ klawisz
		while (_kbhit()) { // Konieczne! poprawia sterowanie
			code = keyPress();
		}
	}
	return code;
}
GetInput::CodeKeys GetInput::keyPress() {
	switch (tolower(_getch())) {
	case 'w':
		return CodeKeys::KEY_UP;
	case 's':
		return CodeKeys::KEY_DOWN;
	case 'a':
		return CodeKeys::KEY_LEFT;
	case 'd':
		return CodeKeys::KEY_RIGHT;
	default:
		return CodeKeys::KEY_DEFAULT;
	}
}
