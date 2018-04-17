#pragma once
#include "Shape.h"
#include "Console.h"
class Scene : protected Console {
public:
	enum START_POSITION_BOARD { X = 3, Y = 2 };
private:
	static const char POS_FRAME = '#';
public:
	void init(const int & score, Shape::Type & s);
	void displayScene();
	void displayScore(const int & score);
	void displayNextFigure(const Shape::Type & s);
};
class Board {
public:
	enum { WIDTH = 10, HEIGHT = 20 };
	enum START_POSITION_SHAPE { X = 5, Y = 0 };
private:
	static const char POS_FILLED = '&';
	static const char POS_FREE = ' ';
	bool board[HEIGHT][WIDTH];
public:
	void init();
	void displayShape(Shape * s);
	void insertShape(Shape * s);
	bool isShapeInMap(Shape * s);
	bool isShapesNotColliding(Shape * s);
	void clearLine(int n);
	void dropLine(int n);
	void clearMap();
	bool isEmptyLine(int n);
	void displayBoard();
	bool isFullLine(int n);

};