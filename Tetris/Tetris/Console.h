#pragma once
class Console {
private:
	static const short CMDLineX = 0;
	static const short CMDLineY = 24;
public:
	static void gotoxy(short x, short y);
	static void printlnXY(short x, short y, const char * ch);
	static void gotoMainLine();
	static void clear();
	static void wait(int m);
};