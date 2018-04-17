#include "Shape.h"
#include <iostream>
// DIRECTION CLASS
Direction::GlobalDirection Direction::getOppositeDirection(const GlobalDirection & d) {
	return GlobalDirection(-d);
}
// POINT CLASS
void Point::setPoint(short x, short y) {
	this->x = x;
	this->y = y;
}
void Point::movePoint(const gDirection & d) {
	switch (d) {
	case Direction::N:
		--y;
		break;
	case Direction::E:
		++x;
		break;
	case Direction::S:
		++y;
		break;
	case Direction::W:
		--x;
		break;
	}
}
// SHAPE CLASS
void Shape::movePoints(const gDirection & d) {
	for (int i = 0; i < AMOUNT_OF_POINTS; i++)
		points[i].movePoint(d);
}
void Shape::rotate(Rotation r) {
	short sin;
	short cos;

	switch (r) {
	case Rotation::RIGHT:
		sin = -1;
		cos = 0;
		break;
	case Rotation::LEFT:
		sin = 1;
		cos = 0;
		break;
	}
		
	short Tx = points[0].getx();
	short Ty = points[0].gety();
	// 1
	movePoints(-Tx, -Ty);
	// 2
	for (int i = 1; i < AMOUNT_OF_POINTS; i++) {
		points[i].setPoint(
			points[i].getx() * cos - points[i].gety() * sin,
			points[i].getx() * sin + points[i].gety() * cos
		);
	}
	// 3
	movePoints(Tx, Ty);

}
void Shape::movePoints(short x, short y) {
	for (int i = 0; i < AMOUNT_OF_POINTS; ++i) {
		points[i].setPoint(points[i].getx() + x, points[i].gety() + y);
	}
}


Shape::Shape(Type type, char body, short x, short y, short x1, short y1, short x2, short y2, short x3, short y3) :
	type(type), body(body), points(new Point[AMOUNT_OF_POINTS]) {
	points[0].setPoint(x, y);
	points[1].setPoint(x + x1, y + y1);
	points[2].setPoint(x + x2, y + y2);
	points[3].setPoint(x + x3, y + y3);
}
Shape::Type Shape::getRandomType() {
	return static_cast<Type>(rand() % AMOUNT_OF_TYPES);
}


Shape * ShapeFactory::getShape(short x, short y, Shape::Type type) {
	using namespace ConcreteShapes;
	switch (type) {
	case Shape::RED:
		return new RedShape(x, y);
	case Shape::LIGHT_GREY:
		return new LightGreyShape(x, y);
	case Shape::CYAN:
		return new CyanShape(x, y);
	case Shape::YELLOW:
		return new YellowShape(x, y);
	case Shape::MAGENTA:
		return new MagentaShape(x, y);
	case Shape::BLUE:
		return new BlueShape(x, y);
	case Shape::GREEN:
		return new GreenShape(x, y);
	default:
		return new RedShape(x, y);
	}
}
Shape * ShapeFactory::getRandomShape(short x, short y) {
	return getShape(x, y, Shape::getRandomType());
}
