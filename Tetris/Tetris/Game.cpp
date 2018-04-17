#include "Game.h"
#include "Menu.h"
#include "Ranking.h"
#include "Console.h"
#include <ctime>
// UWAGA ZMIENIONO KODOWANIE
void Game::run() {
	srand((int)time(NULL));
	Menu menu;
	while (Menu::Event::STARTGAME == menu.mainMenu()) {
		initGame();
		while (!isGameOver) {
			gameController();
			board.displayShape(tetrimino);
			moveTetrimino(Direction::S);
			wait();
			board.displayBoard();
		}
		closeGame();
	}
}
void Game::initGame() {
	Console::clear();
	gameSpeed = START_GAME_SPEED;
	isGameOver = false;
	tetrimino = ShapeFactory::getInstance()->getRandomShape(Board::START_POSITION_SHAPE::X, Board::START_POSITION_SHAPE::Y);
	tetriminoNext = Shape::getRandomType();
	scene.init(score, tetriminoNext);
	board.init();
}
void Game::closeGame() {
	delete tetrimino;
	rankAdd();
	score = 0;
}
void Game::rankAdd() {
	std::cout << "Brawo! Uzyskaˆe˜ " << score << " punkt¢w." << std::endl;
	std::cout << "Podaj imi©: ";
	Player player(GetInput::inputString().substr(0, 10), score);
	Ranking::getRanking()->addPlayer(player);
}
void Game::addPoints() {
	for (int i = Board::HEIGHT - 1; i >= 0; --i) {
		if (board.isFullLine(i)) {
			score += i * 2;
			changeGameSpeed();
			board.clearLine(i);
			board.dropLine(i);
		}
	}
	scene.displayScore(score);
}
void Game::gameController() {
	switch (GetInput::keyPressEvent()) {
	case GetInput::CodeKeys::KEY_LEFT:
		moveTetrimino(Direction::W);
		break;
	case GetInput::CodeKeys::KEY_RIGHT:
		moveTetrimino(Direction::E);
		break;
	case GetInput::CodeKeys::KEY_DOWN:
		dropTetrimino();
		break;
	case GetInput::CodeKeys::KEY_UP:
		rotateTetrimino();
		break;
	}
}

bool Game::checkEndgame() {
	return !board.isEmptyLine(GAME_OVER_LINE);
}
void Game::wait() {
	(gameSpeed > 0) ? Console::wait(gameSpeed) : Console::wait(1);
}
void Game::changeGameSpeed() {
	gameSpeed -= GAME_SPEED_CHANGE;
}
void Game::nextTetrimino() {
	board.insertShape(tetrimino);
	isGameOver = checkEndgame();
	addPoints();
	delete tetrimino;
	tetrimino = ShapeFactory::getInstance()->getShape(Board::START_POSITION_SHAPE::X, Board::START_POSITION_SHAPE::Y, tetriminoNext);
	tetriminoNext = Shape::getRandomType();
	scene.displayNextFigure(tetriminoNext);
}
void Game::dropTetrimino() {
	while (!isShapeColliding())
		tetrimino->movePoints(Direction::S);
	tetrimino->movePoints(Direction::N);
	nextTetrimino();
}
void Game::rotateTetrimino() {
	tetrimino->rotate(); // Left
	if (isShapeColliding())
		tetrimino->rotate(Shape::Rotation::RIGHT);
}
void Game::moveTetrimino(gDirection d) {
	tetrimino->movePoints(d);
	if (isShapeColliding()) {
		if (d == Direction::S) {
			tetrimino->movePoints(Direction::getOppositeDirection(d));
			nextTetrimino();
		} else {
			tetrimino->movePoints(Direction::getOppositeDirection(d));
		}
	}
}
bool Game::isShapeColliding() {
	return !(board.isShapeInMap(tetrimino) && board.isShapesNotColliding(tetrimino));
}