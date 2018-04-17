#include "Scene.h"
#include <string>
#include <iostream>
#include <stdio.h>
//	Scene class
void Scene::init(const int & score, Shape::Type & s) {
	displayScene();
	displayNextFigure(s);
	displayScore(score);
}
void Scene::displayScore(const int & score) {
	printlnXY(20, 13, std::to_string(score).c_str());
	gotoMainLine();
}
void Scene::displayScene() {
	using std::endl;
	using std::cout; 
	printlnXY(20, 12, "S C O R E");
	//Górna ramka mapy
	gotoxy(2, 1);
	for (int i = 0; i < Board::WIDTH + 2; i++) {
		cout << POS_FRAME; 
	}
	//Dolna ramka mapy
	gotoxy(2, 2 + Board::HEIGHT);
	for (int i = 0; i < Board::WIDTH + 2; i++) {
		cout << POS_FRAME; 
	}
	//Boczne ramki mapy
	for (int i = 0; i < Board::HEIGHT; i++) {
		gotoxy(2, i + 2);
		cout << POS_FRAME;
		gotoxy(3 + Board::WIDTH, i + 2);
		cout << POS_FRAME;
	}
	//Górna ramka pola "nastêpna figura"
	gotoxy(20, 1);
	for (int i = 0; i < 8; i++) { 
		cout << POS_FRAME;
	}
	//Dolna ramka pola "nastêpna figura"
	gotoxy(20, 8);
	for (int i = 0; i < 8; i++) { 
		cout << POS_FRAME;
	}
	//Boczne ramki pola "nastêpna figura"
	for (int i = 0; i < 6; i++) {
		gotoxy(20, i + 2);
		cout << POS_FRAME;
		gotoxy(27, i + 2);
		cout << POS_FRAME;
	}
}
void Scene::displayNextFigure(const Shape::Type & f) {
	switch (f) {
	case Shape::Type::RED:
		printlnXY(21, 2, "  &&  ");
		printlnXY(21, 3, "  &&  ");
		printlnXY(21, 4, "  &&  ");
		printlnXY(21, 5, "  &&  ");
		printlnXY(21, 6, "  &&  ");
		printlnXY(21, 7, "  &&  ");
		break;
	case Shape::Type::LIGHT_GREY:
		printlnXY(21, 2, "      ");
		printlnXY(21, 3, "&&&&&&");
		printlnXY(21, 4, "&&&&&&");
		printlnXY(21, 5, "  &&  ");
		printlnXY(21, 6, "  &&  ");
		printlnXY(21, 7, "      ");
		break;
	case Shape::Type::CYAN:
		printlnXY(21, 2, "      ");
		printlnXY(21, 3, " &&&& ");
		printlnXY(21, 4, " &&&& ");
		printlnXY(21, 5, " &&&& ");
		printlnXY(21, 6, " &&&& ");
		printlnXY(21, 7, "      ");
		break;
	case Shape::Type::YELLOW:
		printlnXY(21, 2, "&&    ");
		printlnXY(21, 3, "&&    ");
		printlnXY(21, 4, "&&    ");
		printlnXY(21, 5, "&&    ");
		printlnXY(21, 6, "&&&&&&");
		printlnXY(21, 7, "&&&&&&");
			break;
	case Shape::Type::MAGENTA:
		printlnXY(21, 2, "    &&");
		printlnXY(21, 3, "    &&");
		printlnXY(21, 4, "    &&");
		printlnXY(21, 5, "    &&");
		printlnXY(21, 6, "&&&&&&");
		printlnXY(21, 7, "&&&&&&");
		break;
	case Shape::Type::BLUE:
		printlnXY(21, 2, "      ");
		printlnXY(21, 3, "  &&&&");
		printlnXY(21, 4, "  &&&&");
		printlnXY(21, 5, "&&&&  ");
		printlnXY(21, 6, "&&&&  ");
		printlnXY(21, 7, "      ");
		break;
	case Shape::Type::GREEN:
		printlnXY(21, 2, "      ");
		printlnXY(21, 3, "&&&&  ");
		printlnXY(21, 4, "&&&&  ");
		printlnXY(21, 5, "  &&&&");
		printlnXY(21, 6, "  &&&&");
		printlnXY(21, 7, "      ");
		break;
	}
	gotoMainLine();
}


//   Board class
void Board::init() {
	clearMap();
	displayBoard();
}
void Board::displayShape(Shape * s) {
	char b = s->getBody();
	for (int i = 0; i < Shape::AMOUNT_OF_POINTS; i++) {
		Console::gotoxy(s->getPoint(i).getx() + Scene::START_POSITION_BOARD::X, s->getPoint(i).gety() + Scene::START_POSITION_BOARD::Y);
		printf("%c", b);
	}
	Console::gotoMainLine();
}
void Board::displayBoard() {
	for (int i = 0; i < Board::HEIGHT; i++) {
		Console::gotoxy(Scene::START_POSITION_BOARD::X, Scene::START_POSITION_BOARD::Y + i);
		for (int j = 0; j < Board::WIDTH; j++) {
			if (board[i][j])
				printf("%c", POS_FILLED);
			else
				printf("%c", POS_FREE);
		}
		printf("\n");
	}
	Console::gotoMainLine();
}
void Board::insertShape(Shape * s) {
	for (int i = 0; i < Shape::AMOUNT_OF_POINTS; i++)
		board[s->getPoint(i).gety()][s->getPoint(i).getx()] = true;
}
void Board::clearMap() {
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++)
			board[i][j] = false;
	}
}
void Board::dropLine(int n) {
	for (int i = n; i >= 1; i--) {
		for (int j = 0; j < WIDTH; j++)
			board[i][j] = board[i - 1][j];
	}
}
bool Board::isShapeInMap(Shape * s) {
	for (int i = 0; i < Shape::AMOUNT_OF_POINTS; i++) {
		if ((s->getPoint(i).getx() < 0) || // Czy punkt ma ujemne wspó³rzêdne?
			(s->getPoint(i).gety() < 0) ||
			(s->getPoint(i).getx() > Board::WIDTH - 1) || // Czy punkt znajduje siê poza obszarem mapy?
			(s->getPoint(i).gety() > Board::HEIGHT - 1))
			return false;
	}
	return true;
}
bool Board::isShapesNotColliding(Shape * s) {
	for (int i = 0; i < Shape::AMOUNT_OF_POINTS; i++) {
		if (board[s->getPoint(i).gety()][s->getPoint(i).getx()])
			return false;
	}
	return true;
}
bool Board::isFullLine(int n) {
	for (int i = 0; i < WIDTH; i++) {
		if (!board[n][i])
			return false;
	}
	return true;
}
bool Board::isEmptyLine(int n) {
	for (int i = 0; i < WIDTH; i++) {
		if (board[n][i])
			return false;
	}
	return true;
}
void Board::clearLine(int n) {
	for (int i = 0; i < WIDTH; i++)
		board[n][i] = false;
}