#pragma once
#include <iostream>
#include "Getinput.h"
#include "Scene.h"
#include "Shape.h"
class Game {
public:
	static const short GAME_OVER_LINE = 2;
	static const short GAME_SPEED_CHANGE = 5;
	static const short DEFAULT_GAME_SPEED = 25;
	static const short START_GAME_SPEED = 525;
private:
	bool isGameOver;
	int gameSpeed;

	Shape * tetrimino;
	Shape::Type tetriminoNext;
	Board board;
	Scene scene;
	int score = 0;

	void initGame();
	void closeGame();
	void changeGameSpeed();
	void addPoints();
	void gameController();
	void dropTetrimino();
	void rotateTetrimino();
	void moveTetrimino(gDirection d);
	bool checkEndgame();
	bool isShapeColliding();
	void wait();
	void rankAdd();
	void nextTetrimino();
public:
	void run();
	virtual ~Game() {
		tetrimino = nullptr;
	}
};
